// Owner-local scheduling only. Never changes simulation, movement or AI features.
// Player positions are cached once per scan by initCombatTasks; no enemy scans
// across allUnits and no revealed targets. Native group knowledge keeps combat fast.
params ["_group", ["_playerPositions", []]];
private _base = (missionNamespace getVariable ["FST_HC_CombatTaskInterval", 15]) max 5;
if !(missionNamespace getVariable ["BURNS_DistanceScheduling", true]) exitWith {_base};
private _leader = leader _group;
if (isNull _leader || {!local _group}) exitWith {_base};
private _near = (missionNamespace getVariable ["BURNS_NearDistance", 1200]) max 100;
if ((_playerPositions findIf {_leader distance2D _x <= _near}) >= 0) exitWith {_base};
if (!isNull (_leader findNearestEnemy _leader)) exitWith {_base};
(missionNamespace getVariable ["BURNS_DistantInterval", 45]) max _base
