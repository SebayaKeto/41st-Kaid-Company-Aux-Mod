// B1 travel column at 3.5m; danger line at most six abreast, 3.5m / 4.5m.
// Serviced by the bounded group scheduler, never a per-unit loop/PFH.
// Native pathfinding remains responsible for obstacles; no teleport or prop scan.
params ["_group","_destination"];
if (isNull _group || {!local _group}) exitWith {false};
private _units=units _group select {alive _x};
if !([_group] call FST_HCSpawn_fnc_burnsB1Eligible) exitWith {[_group] call FST_HCSpawn_fnc_burnsReleaseAdvance;false};
private _leader=leader _group;
private _origin=getPosATL _leader;
private _direction=_origin getDir _destination;
private _march=missionNamespace getVariable ["BURNS_B1MarchSpeed",2.5];
private _formation=[_group] call FST_HCSpawn_fnc_burnsB1Formation;
private _line=_formation=="LINE";
// Track orders actually sent by this function, independently of the native
// formation flag set by the role/danger checks earlier in this scheduler visit.
private _previous=_group getVariable ["BURNS_localAdvanceFormation",""];
private _formationChanged=_previous!=_formation;
_group setVariable ["BURNS_localAdvanceFormation",_formation];
private _deployUntil=_group getVariable ["BURNS_deployUntil",-1];
private _deploying=_line && {time<_deployUntil};
// Freeze a nearby deployment front and bearing. Recomputing these from the
// moving leader makes rear ranks chase a moving line instead of assembling.
private _frame=_group getVariable ["BURNS_localDeployFrame",[]];
if (_deploying) then {
    if (count _frame!=3 || {(_frame select 0)!=_deployUntil}) then {
        _frame=[_deployUntil,_origin getPos [6 min (_origin distance2D _destination),_direction],_direction];
        _group setVariable ["BURNS_localDeployFrame",_frame];
    };
    _direction=_frame select 2;
} else {
    _group setVariable ["BURNS_localDeployFrame",nil];
};
private _ordered=[_leader]+(_units-[_leader]);
// Membership/leader changes invalidate ALL cached slots together. Otherwise a
// survivor can keep a slot newly assigned to another member after a casualty.
private _oldRoster=_group getVariable ["BURNS_advanceRoster",[]];
private _rosterChanged=!(_oldRoster isEqualTo _ordered);
{[_x,true,_group] call FST_HCSpawn_fnc_burnsReleaseAdvanceUnit} forEach (_oldRoster-_ordered);
_group setVariable ["BURNS_advanceRoster",+_ordered];
private _columns=if (_line) then {6 min count _ordered} else {1};
private _rowSpacing=if (_line) then {4.5} else {3.5};
private _lagging=0;
{
    private _delta=_origin vectorDiff (getPosATL _x);
    private _expectedBack=floor (_forEachIndex/_columns)*_rowSpacing;
    if ((_delta select 0)*sin _direction+(_delta select 1)*cos _direction>_expectedBack+18) then {_lagging=_lagging+1};
} forEach _ordered;
private _leaderSpeed=if (_lagging>0 || {_deploying}) then {_march min 1.2} else {_march};
// Twenty-four seconds is a ceiling, not a mandatory halt. Release once
// every current member reaches its slot; obstacles cannot hold the task forever.
private _front=if (_deploying) then {+(_frame select 1)} else {_origin getPos [30 min (_origin distance2D _destination),_direction]};
private _settled=0;
// Stable unit order survives ordinary updates; new owner rebuilds local goals.
{
    // A bounded point-fire job owns this unit's temporary halt. The other
    // squad members retain their normal slots and native obstacle handling.
    private _lease=_x getVariable ["BURNS_pointFireLease",[]];
    if (count _lease==4 && {(_lease select 0)==clientOwner} && {time<(_lease select 1)}) then {_settled=_settled+1;continue};
    private _column=_forEachIndex mod _columns;
    // Leader occupies the centre; alternating slots spread left/right.
    private _offset=if (_column==0) then {0} else {(ceil (_column/2))*3.5*([-1,1] select (_column mod 2))};
    private _row=floor (_forEachIndex/_columns);
    private _goal=(_front getPos [abs _offset,_direction+([90,-90] select (_offset<0))]) getPos [_row*_rowSpacing,_direction+180];
    if (surfaceIsWater _goal) then {[_x] call FST_HCSpawn_fnc_burnsReleaseAdvanceUnit;continue};
    private _slotDistance=_x distance2D _goal;
    if (_slotDistance<=3) then {_settled=_settled+1};
    private _behind=(_origin vectorDiff (getPosATL _x));
    private _lag=(_behind select 0)*sin _direction+(_behind select 1)*cos _direction-_row*_rowSpacing;
    private _speed=if (_x==_leader) then {_leaderSpeed} else {if (_lag>8 || {_deploying && {_slotDistance>3}}) then {(_march+1.5) min 4.5} else {_march}};
    private _ownedSpeed=_x getVariable ["BURNS_advanceSpeed",[]];
    if ((_x getVariable ["BURNS_advanceController",grpNull])!=_group) then {
        [_x,false] call FST_HCSpawn_fnc_burnsReleaseAdvanceUnit;
        _x setVariable ["BURNS_advanceController",_group,true];
        _ownedSpeed=[];
    };
    if (count _ownedSpeed==0) then {_ownedSpeed=[getForcedSpeed _x,_speed];_x setVariable ["BURNS_advanceSpeed",_ownedSpeed,true]};
    if (abs ((getForcedSpeed _x)-_speed)>0.05) then {
        _x forceSpeed _speed;
        if ((_ownedSpeed select 1)!=_speed) then {_x setVariable ["BURNS_advanceSpeed",[_ownedSpeed select 0,_speed],true]};
    };
    private _last=_x getVariable ["BURNS_formationGoal",[]];
    if (_formationChanged || {_rosterChanged} || {count _last==0} || {_last distance2D _goal>8} || {unitReady _x && {_x distance2D _goal>4}}) then {
        _x doMove _goal;
        _x setVariable ["BURNS_moveCleanupToken",nil];
        _x setVariable ["BURNS_formationGoal",_goal];
    };
} forEach _ordered;
if (_deploying && {_settled==count _ordered}) then {
    _group setVariable ["BURNS_deployUntil",-1,true];
    _group setVariable ["BURNS_localDeployFrame",nil];
    // Resume promptly through the existing bounded queue, without another PFH.
    _group setVariable ["FST_HC_taskNext",time+1];
};
// One group snapshot only when issued orders change. This lets a new owner
// distinguish our old doMove from a later external order during early cleanup.
// Never broadcast per-unit goals from the scheduler's inspection loop.
private _orders=_ordered apply {[_x,_x getVariable ["BURNS_formationGoal",[]]]};
if !(_orders isEqualTo (_group getVariable ["BURNS_advanceOrders",[]])) then {_group setVariable ["BURNS_advanceOrders",_orders,true]};
if (speedMode _group!="NORMAL") then {_group setSpeedMode "NORMAL"};
if ((_group getVariable ["BURNS_lastRoleSpeed",""])!="NORMAL") then {_group setVariable ["BURNS_lastRoleSpeed","NORMAL",true]};
true
