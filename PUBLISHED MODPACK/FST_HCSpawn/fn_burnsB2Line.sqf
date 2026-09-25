// Native B2 formation intent only. The installed WebKnight controller keeps
// its gestures, animation speed, health, damage, targeting and firing handlers.
params ["_g"];
if (isNull _g || {!local _g}) exitWith {};
private _units=units _g select {alive _x};
private _saved=+(_g getVariable ["BURNS_b2Line",[]]);
private _intent=_g getVariable ["BURNS_b2TaskIntent",""];
private _wp=currentWaypoint _g;
private _manual=_wp>0 && {_wp<count waypoints _g} && {!(waypointDescription [_g,_wp] in ["FST HC combat","BURNS patrol"])};
private _allowed=(missionNamespace getVariable ["BURNS_B2LineEnabled",true]) && {count _units>=2} && {
    [_g] call FST_HCSpawn_fnc_burnsEngagementAllowed
} && {!_manual} && {_intent in ["","hunt","assault","rush","cqb"]} && {
    (_units findIf {!local _x || {vehicle _x!=_x} || {_x getVariable ["BURNS_exempt",false]} || {
        !(_x isKindOf "FST_B2" || {_x isKindOf "FST_B2_TL"})
    } || {primaryWeapon _x==""} || {!isNull attachedTo _x} || {!(_x checkAIFeature "PATH")} || {!(_x checkAIFeature "MOVE")} || {!(_x checkAIFeature "TARGET")} || {
        !(_x checkAIFeature "FIREWEAPON")
    } || {[_x] call FST_HCSpawn_fnc_burnsIsDown}})<0
};
if (!_allowed) exitWith {[_g] call FST_HCSpawn_fnc_burnsReleaseB2Line};
private _lead=leader _g;
// Native leadership promotion can lag the WebKnight death animation.
if (!alive _lead) exitWith {};
private _original=[];
if (count _saved>0 && {_lead!=(_saved select 5)}) then {
    _original=_saved select [0,3];
    [_g] call FST_HCSpawn_fnc_burnsReleaseB2Line;
    _saved=[];
};
private _enemy=objNull;
private _best=350;
{
    _x params ["_pos","","_side","","_obj"];
    if (isNull _obj || {!alive _obj} || {captive _obj} || {isObjectHidden _obj} || {_side in [civilian,sideUnknown,sideLogic]} || {
        (side _g) getFriend _side>=0.6
    } || {(side _g) getFriend (side _obj)>=0.6} || {!(_obj isKindOf "CAManBase" || {_obj isKindOf "LandVehicle"})} || {
        [_obj] call FST_HCSpawn_fnc_burnsIsDown
    }) then {continue};
    private _distance=_lead distance2D _obj;
    if (_distance<_best && {_lead knowsAbout _obj>=1.5} && {([_lead,"VIEW",vehicle _obj] checkVisibility [eyePos _lead,aimPos vehicle _obj])>0.5}) then {_enemy=_obj;_best=_distance};
} forEach (_lead nearTargets 350);
if (isNull _enemy) exitWith {
    if (count _saved>0 && {time>(_saved select 6)+10}) then {[_g] call FST_HCSpawn_fnc_burnsReleaseB2Line};
};
private _bearing=_lead getDir _enemy;
if (count _saved==0) then {
    // setFormation is asynchronous; retain the pre-combat baseline on handover.
    if (count _original==0) then {_original=[formation _g,combatMode _g,formationDirection _lead]};
    _saved=_original+[_bearing,[],_lead,time];
    _g setFormation "LINE";
    _lead setFormDir _bearing;
    // YELLOW keeps native firing enabled while retaining formation membership.
    _g setCombatMode "YELLOW";
    {_x doFollow _lead} forEach (_units-[_lead]);
};
if (formation _g!="LINE") then {_g setFormation "LINE"};
if (abs((_bearing-(_saved select 3)+540)%360-180)>20) then {_lead setFormDir _bearing;_saved set [3,_bearing]};
_saved set [6,time];
private _standOff=45;
private _ordered=[_lead]+(_units-[_lead]);
private _frame=_g getVariable ["BURNS_b2Frame",[]];
private _orders=_saved select 4;
private _arrived={_x params ["_u","_goal"];alive _u && {_u distance2D _goal<3}} count _orders;
private _new=count _frame==0 || {!((_frame select 3) isEqualTo _ordered)};
if (!_new && {_best>_standOff+8} && {_arrived>=ceil(count _ordered*0.75)} && {time>(_frame select 2)}) then {
    private _lag=0;
    {private _delta=(getPosATL _lead) vectorDiff getPosATL _x;_lag=_lag max ((_delta select 0)*sin _bearing+(_delta select 1)*cos _bearing)} forEach _units;
    _new=_lag<8;
};
if (_new) then {
    private _front=_lead getPos [6 min ((_best-_standOff) max 0),_bearing];
    _frame=[_front,_bearing,time+8,_ordered];
    _orders=[];
    {
        private _offset=if (_forEachIndex==0) then {0} else {ceil(_forEachIndex/2)*5*([-1,1] select (_forEachIndex mod 2))};
        private _goal=_front getPos [abs _offset,_bearing+([90,-90] select (_offset<0))];
        if (!surfaceIsWater _goal) then {_x doMove _goal;_orders pushBack [_x,_goal]};
    } forEach _ordered;
    _saved set [4,_orders];
    _g setVariable ["BURNS_b2Frame",_frame,true];
    _g setVariable ["BURNS_b2BoundNext",time+20];
} else {
    // Reissue only unfinished slots after a long timeout, not continuous orders
    // that would interrupt native aiming. Native pathfinding handles obstacles.
    if (time>=(_g getVariable ["BURNS_b2BoundNext",-1])) then {
        {_x params ["_u","_goal"];if (_u distance2D _goal>=3) then {_u doMove _goal}} forEach _orders;
        _g setVariable ["BURNS_b2BoundNext",time+20];
    };
};
if !((_g getVariable ["BURNS_b2Line",[]]) isEqualTo _saved) then {_g setVariable ["BURNS_b2Line",_saved,true]};
