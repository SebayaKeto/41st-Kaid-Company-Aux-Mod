// BURNS: original group tactics above Arma's native combat AI.
// nearTargets supplies perceived contact positions, not an allUnits enemy scan.
params ["_group"];
if (isNull _group || {!local _group}) exitWith {};
if ([_group] call FST_HCSpawn_fnc_isProtectedVehicleGroup) exitWith {};
if (_group getVariable ["BURNS_exempt", false]) exitWith {};
private _task = _group getVariable ["FST_HC_combatTask", []];
if (count _task != 3) exitWith {};
if ((units _group findIf {isPlayer _x}) >= 0) exitWith {};
if ((_group getVariable ["FST_HC_heldBy", -1]) != -1) exitWith {};
private _leader = leader _group;
if (isNull _leader || {!alive _leader} || {!simulationEnabled _leader}) exitWith {};
if ((units _group findIf {([_x] call FST_HCSpawn_fnc_burnsRole) == "webknight"}) >= 0) exitWith {};
// This records the owner actually servicing the task even if a valid waypoint
// needs no new order after a handoff.
if ((_group getVariable ["FST_HC_taskLastOwner", -1]) != clientOwner) then {
    _group setVariable ["FST_HC_taskLastOwner", clientOwner, true];
};
_task params ["_mode", "_objective", "_radius"];
private _wpIndex = _group getVariable ["FST_HC_taskWaypoint", -1];
private _current = currentWaypoint _group;
// Check this before issuing suppression or movement orders.
if (_wpIndex >= 0 && {_current != _wpIndex} && {_current < count waypoints _group} && {waypointDescription [_group, _current] != "FST HC combat"}) exitWith {
    [_group,"stop"] call FST_HCSpawn_fnc_setCombatTask;
};
if ([_group,_mode,_objective,_radius] call FST_HCSpawn_fnc_burnsSpecialTick) exitWith {};
if !(_leader checkAIFeature "PATH") exitWith {}; // Respect externally scripted holds.
private _destination = +_objective;
private _nearest = 1e12;
private _contact = objNull;
{
    _x params ["_knownPos", "_type", "_side", "_cost", "_object"];
    if (isNull _object || {!alive _object} || {_side in [civilian, sideUnknown, sideLogic]} || {(side _group) getFriend _side >= 0.6}) then {continue};
    if ((_knownPos distance2D _objective) > _radius) then {continue};
    private _distance = _leader distance2D _knownPos;
    if (_distance < _nearest) then { _nearest = _distance; _destination = +_knownPos; _contact = _object; };
} forEach (_leader nearTargets _radius);
// Explicit Zeus search orders may track players' positions, matching that
// mission-making workflow. No target is revealed to the AI's firing knowledge.
// Normal HCSpawn assaults continue to use only perceived contacts.
if (_mode in ["rush","hunt","creep"] && {(_group getVariable ["BURNS_taskOptions",[]]) param [2,false]}) then {
    {
        if ((side _group) getFriend (side group _x)>=0.6 || {!alive _x}) then {continue};
        private _p=BURNS_PlayerPositions select _forEachIndex;
        private _d=_leader distance2D _p;
        if (_d<_nearest && {_p distance2D _objective<=_radius}) then {_nearest=_d;_destination=ASLToATL _p};
    } forEach BURNS_Players;
};
if (_mode=="retreat") then {_destination=+_objective;_nearest=1e12};
private _contactPos = +_destination;
if (!isNull _contact && {_group getVariable ["BURNS_hasRadio",false]} && {time>=(_group getVariable ["BURNS_nextRadio",-1])}) then {
    _group setVariable ["BURNS_nextRadio",time+90];
    ["BURNS_support",[_group,_contactPos]] call CBA_fnc_serverEvent;
};
// Hunt approaches from the group's current side and leaves room for cover.
// Assault closes directly. Neither mode forces droids prone or disables FSMs.
if (_mode in ["hunt","creep"] && {_nearest < 1e12} && {_nearest > 80}) then {
    _destination = _destination getPos [60, _destination getDir (getPosATL _leader)];
};
// Human squads approach a known contact from a flank while one rifleman
// suppresses its perceived position. B1s keep the direct line of advance.
private _human = ([_leader] call FST_HCSpawn_fnc_burnsRole) == "human";
if (_human && {!isNull _contact} && {_mode in ["hunt","assault"]}) then {
    [_group,_contactPos] call FST_HCSpawn_fnc_burnsUseCover;
};
private _tactic = if (_human) then {"advance"} else {"line-advance"};
if (_human && {_mode!="rush"} && {_nearest > 100} && {_nearest < 600} && {vehicle _leader == _leader}) then {
    private _flank = _group getVariable ["BURNS_flankSide", 0];
    if (_flank == 0) then {
        _flank = selectRandom [-1,1];
        _group setVariable ["BURNS_flankSide", _flank, true];
    };
    private _approach = _contactPos getPos [80, (_contactPos getDir (getPosATL _leader)) + 60 * _flank];
    if !(surfaceIsWater _approach) then {_destination = _approach};
    private _coverUnit = (units _group) findIf {local _x && {alive _x} && {!(_x getVariable ["BURNS_exempt",false])} && {_x != _leader} && {vehicle _x == _x} && {([_x] call FST_HCSpawn_fnc_burnsRole) == "human"}};
    if (_coverUnit >= 0) then {
        (units _group select _coverUnit) doSuppressiveFire ATLToASL _contactPos;
    };
    _tactic = "flank-and-suppress";
};
// At 100-150 players, unchanged diagnostics must not broadcast every AI tick.
if ((_group getVariable ["BURNS_lastTactic", ""]) != _tactic) then {
    _group setVariable ["BURNS_lastTactic", _tactic, true];
};
private _last = _group getVariable ["FST_HC_taskLastOrder", []];
if (_mode=="creep") then {
    private _combatMode=if (_nearest<80) then {"RED"} else {"GREEN"};
    _group setCombatMode _combatMode;
    if (_wpIndex>=0 && {_wpIndex<count waypoints _group}) then {[_group,_wpIndex] setWaypointCombatMode _combatMode};
};
if (count _last > 0 && {(_last distance2D _destination) < 25} && {_wpIndex >= 0} && {_wpIndex < count waypoints _group}) exitWith {};
if (!local _group) exitWith {};
private _wp = [_group, _wpIndex];
if (_wpIndex < 0 || {_wpIndex >= count waypoints _group} || {waypointDescription _wp != "FST HC combat"}) then {
    _wp = _group addWaypoint [_destination, 0];
    _wpIndex = _wp select 1;
    _group setVariable ["FST_HC_taskWaypoint", _wpIndex, true];
};
_wp setWaypointDescription "FST HC combat";
_wp setWaypointPosition [_destination, 0];
_wp setWaypointType "MOVE";
_wp setWaypointCompletionRadius (if (_mode == "hunt") then {30} else {15});
_wp setWaypointSpeed (if (([_leader] call FST_HCSpawn_fnc_burnsRole) == "b1") then {"LIMITED"} else {if (_mode == "hunt") then {"NORMAL"} else {"FULL"}});
_wp setWaypointBehaviour "AWARE";
_wp setWaypointCombatMode "RED";
if (_mode=="creep") then {
    _wp setWaypointSpeed "LIMITED";
    _wp setWaypointCombatMode (if (_nearest<80) then {"RED"} else {"GREEN"});
    if (_human) then {_wp setWaypointBehaviour "STEALTH"};
};
if (_mode=="retreat") then {_wp setWaypointCombatMode "GREEN";_wp setWaypointSpeed "FULL"};
_group setCurrentWaypoint _wp;
_group setVariable ["FST_HC_taskLastOrder", +_destination, true];
