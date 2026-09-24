// Stable short bounds; a whole squad shares the same frozen front and bearing.
// A firing solution takes precedence over correcting an individual formation slot.
params ["_group","_destination"];
if (isNull _group || {!local _group}) exitWith {false};
if !([_group] call FST_HCSpawn_fnc_burnsB1Eligible) exitWith {[_group] call FST_HCSpawn_fnc_burnsReleaseAdvance;false};
private _leader=leader _group;
private _units=units _group select {alive _x};
private _ordered=[_leader]+(_units-[_leader]);
private _old=_group getVariable ["BURNS_advanceRoster",[]];
{[_x,true,_group] call FST_HCSpawn_fnc_burnsReleaseAdvanceUnit} forEach (_old-_ordered);
private _changed=!(_old isEqualTo _ordered);
_group setVariable ["BURNS_advanceRoster",_ordered];
private _formation=[_group] call FST_HCSpawn_fnc_burnsB1Formation;
private _line=_formation=="LINE";
private _previous=_group getVariable ["BURNS_localAdvanceFormation",""];
_changed=_changed || {_previous!=_formation};
_group setVariable ["BURNS_localAdvanceFormation",_formation];
private _origin=getPosATL _leader;
private _direction=_origin getDir _destination;
private _frame=_group getVariable ["BURNS_bound",[]];
private _contact=_leader findNearestEnemy _leader;
private _engaging=!isNull _contact && {alive _contact} && {_leader distance2D _contact<250} && {([_leader,"FIRE",vehicle _contact] checkVisibility [eyePos _leader,aimPos vehicle _contact])>0.5};
// Frames survive owner handoff. Only a replacement destination, changed roster,
// completed bound or timed-out obstructed bound creates new movement orders.
private _new=count _frame!=4 || {_changed};
if (!_new) then {
    _frame params ["_front","_bearing","_deadline","_dest"];
    private _arrived={private _slot=_x getVariable ["BURNS_formationGoal",[]];count _slot>=2 && {_x distance2D _slot<4}} count _ordered;
    _new=_dest distance2D _destination>25 || {!_engaging && {time>_deadline || {_arrived>=ceil(count _ordered*0.75)}}};
};
if (_new) then {
    _frame=[_origin getPos [(if (_line) then {6} else {18}) min (_origin distance2D _destination),_direction],_direction,time+20,+_destination];
    _group setVariable ["BURNS_bound",_frame,true];
};
_frame params ["_front","_bearing"];
private _columns=if (_line) then {6 min count _ordered} else {1};
private _spacing=if (_line) then {4.5} else {3.5};
private _march=missionNamespace getVariable ["BURNS_B1MarchSpeed",2.5];
private _maxLag=0;
{private _delta=_origin vectorDiff getPosATL _x;_maxLag=_maxLag max ((_delta select 0)*sin _bearing+(_delta select 1)*cos _bearing-floor(_forEachIndex/_columns)*_spacing)} forEach _ordered;
{
    private _u=_x;
    private _lease=_u getVariable ["BURNS_pointFireLease",[]];
    if (count _lease==4 && {time<(_lease select 1)}) then {continue};
    private _column=_forEachIndex mod _columns;
    private _offset=if (_column==0) then {0} else {ceil(_column/2)*3.5*([-1,1] select (_column mod 2))};
    private _goal=(_front getPos [abs _offset,_bearing+([90,-90] select (_offset<0))]) getPos [floor(_forEachIndex/_columns)*_spacing,_bearing+180];
    if (surfaceIsWater _goal) then {continue};
    private _target=assignedTarget _u;
    if (isNull _target) then {_target=_contact};
    private _hasShot=!isNull _target && {alive _target} && {_u knowsAbout _target>=1} && {_u distance2D _target<250} && {([_u,"FIRE",vehicle _target] checkVisibility [eyePos _u,aimPos vehicle _target])>0.5};
    private _hold=_hasShot || {_line && {_u distance2D _goal<3}} || {_u==_leader && {_maxLag>8}};
    private _speed=if (_hold) then {0} else {if (_u==_leader) then {_march} else {(_march+1.5) min 4.5}};
    private _owned=_u getVariable ["BURNS_advanceSpeed",[]];
    if (count _owned==0) then {_owned=[getForcedSpeed _u,_speed]};
    _u setVariable ["BURNS_advanceController",_group,true];
    if (abs (getForcedSpeed _u-_speed)>0.05) then {_u forceSpeed _speed};
    if !(_owned isEqualTo [_owned select 0,_speed]) then {_owned=[_owned select 0,_speed]};
    if !((_u getVariable ["BURNS_advanceSpeed",[]]) isEqualTo _owned) then {_u setVariable ["BURNS_advanceSpeed",_owned,true]};
    private _last=_u getVariable ["BURNS_formationGoal",[]];
    if (!_hasShot && {_new || {count _last==0}}) then {
        _u doMove _goal;_u setVariable ["BURNS_moveCleanupToken",nil];_u setVariable ["BURNS_formationGoal",_goal];
        _u setVariable ["BURNS_formationOrderCount",(_u getVariable ["BURNS_formationOrderCount",0])+1];
    };
} forEach _ordered;
private _orders=_ordered apply {[_x,_x getVariable ["BURNS_formationGoal",[]]]};
if !(_orders isEqualTo (_group getVariable ["BURNS_advanceOrders",[]])) then {_group setVariable ["BURNS_advanceOrders",_orders,true]};
if (speedMode _group!="NORMAL") then {_group setSpeedMode "NORMAL"};
_group setVariable ["BURNS_lastRoleSpeed","NORMAL",true];
true
