// Travel in column; deploy to line only for an actually known nearby enemy.
// Rush's seek target does not by itself grant knowledge or trigger danger.
params ["_group"];
if !([_group] call FST_HCSpawn_fnc_burnsB1Eligible) exitWith {""};
private _leader=leader _group;
private _enemy=_leader findNearestEnemy _leader;
// The engine's nearest-enemy list can lag fresh group knowledge. Check only
// the existing task target, with real knowledge required; never scan terrain
// or turn an unknown seek target into a perceived contact.
if (isNull _enemy) then {
    private _knownTarget=([_group,["BURNS_rushTarget",objNull]] call FST_HCSpawn_fnc_burnsStateGet);
    if (!isNull _knownTarget && {alive _knownTarget} && {!captive _knownTarget} && {side _knownTarget!=civilian} && {(side _group getFriend side _knownTarget)<0.6} && {_leader knowsAbout _knownTarget>=1.5}) then {
        _enemy=_knownTarget;
    };
};
if (!isNull _enemy && {_leader distance2D _enemy<500} && {time>=(_group getVariable ["BURNS_b1DangerUntil",-1])-19}) then {
    _group setVariable ["BURNS_b1DangerUntil",time+20,true];
};
private _formation=if (time<(_group getVariable ["BURNS_b1DangerUntil",-1])) then {"LINE"} else {"COLUMN"};
// Shared transition intent survives HC handoff; publish only on transition.
private _previous=_group getVariable ["BURNS_advanceFormation",""];
if (_previous!=_formation) then {
    _group setVariable ["BURNS_advanceFormation",_formation,true];
    _group setVariable ["BURNS_deployUntil",if (_formation=="LINE") then {time+24} else {-1},true];
    _group setVariable ["FST_HC_taskNext",-1];
};
if (isNil {_group getVariable "BURNS_originalFormation"}) then {_group setVariable ["BURNS_originalFormation",formation _group,true]};
if (formation _group!=_formation) then {_group setFormation _formation};
if ((_group getVariable ["BURNS_lastRoleFormation",""])!=_formation) then {_group setVariable ["BURNS_lastRoleFormation",_formation,true]};
private _wp=([_group,["FST_HC_taskWaypoint",-1]] call FST_HCSpawn_fnc_burnsStateGet);
if (_wp>=0 && {_wp<count waypoints _group} && {waypointDescription [_group,_wp]=="FST HC combat"} && {waypointFormation [_group,_wp]!=_formation}) then {
    [_group,_wp] setWaypointFormation _formation;
};
_formation
