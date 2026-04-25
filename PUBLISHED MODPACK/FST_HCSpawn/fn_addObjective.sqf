// FST_HCSpawn_fnc_addObjective
// Server-side. Define a proximity-triggered baseline garrison.
// Call from mission init.sqf.
//
// Arguments:
//   0: STRING — marker name
//   1: NUMBER — garrison radius
//   2: ARRAY  — [[templateKey, behavior], ...]
//
// Example — full garrison (8-12 squads):
//   ["obj_fortress", 200, [
//       ["b1_squad","garrison"], ["b1_squad","garrison"],
//       ["b1_squad_at","garrison"], ["b1_squad_aa","garrison"],
//       ["b1_squad","garrison"], ["b1_squad","garrison"],
//       ["b2_team","garrison"], ["b2_team","garrison"],
//       ["b1_squad","patrol"], ["b1_squad_ataa","patrol"],
//       ["bx_killteam","patrol"], ["bx_sniper_team","static"]
//   ]] call FST_HCSpawn_fnc_addObjective;

if (!isServer) exitWith {};

params ["_marker", "_radius", "_spawnDefs"];

if (getMarkerPos _marker isEqualTo [0,0,0]) exitWith {
    diag_log format ["[FST_HCSpawn] addObjective: marker '%1' not found", _marker];
};

FST_HC_Objectives pushBack [_marker, _radius, _spawnDefs];
diag_log format ["[FST_HCSpawn] Objective '%1': radius %2, %3 groups", _marker, _radius, count _spawnDefs];
