// WebKnightsRobotics AI locality hook (41st, 2026-09-20)
//
// Called from XEH InitPost on EVERY machine for the B1 / B2 / BX droid classes:
//   [_unit, "\WebKnightsRobotics\AI\AI_WBK_B2_BattleDroid.sqf"] execVM "\WebKnightsRobotics\AI\AI_localityHook.sqf";
//
// Why: the AI scripts start on whichever machine the droid is local to when it
// spawns and used to keep running there forever. When FST_HCSpawn moved the
// group to a headless client (setGroupOwner path: lone units, crewed vehicles,
// Zeus hold/release), the script stayed on the Zeus client while the unit lived
// on the HC, and every local-only command in it (disableAI, allowDamage,
// setBehaviour, playActionNow, melee logic) stopped landing.
//
// Now:
//  - the script starts on the machine where the unit is local,
//  - a "Local" event handler restarts it on the new owner after each transfer,
//  - the per-frame handlers and loops inside the scripts exit as soon as the
//    unit is no longer local to them,
//  - event handlers added by a run are recorded (WBK_fnc_addAIEH) and removed
//    before the next run on the same machine, so a droid that comes back to a
//    machine (hold, then release) never ends up with two HandleDamage handlers
//    decrementing its hit counter twice per hit.

params ["_unit", "_script"];
if (isNull _unit) exitWith {};

if (isNil "WBK_fnc_addAIEH") then {
	// Add an object event handler and remember it on the unit (machine-local).
	WBK_fnc_addAIEH = {
		params ["_unit", "_type", "_code"];
		private _id = _unit addEventHandler [_type, _code];
		private _list = _unit getVariable ["WBK_aiEHs", []];
		_list pushBack [_type, _id];
		_unit setVariable ["WBK_aiEHs", _list];
		_id
	};

	// Remove only the handlers a previous run of the AI script added here.
	WBK_fnc_removeAIEHs = {
		params ["_unit"];
		{ _unit removeEventHandler _x; } forEach (_unit getVariable ["WBK_aiEHs", []]);
		_unit setVariable ["WBK_aiEHs", []];
	};

	WBK_fnc_startAI = {
		params ["_unit", "_script"];
		if (isNull _unit || {!alive _unit} || {!local _unit} || {_script isEqualTo ""}) exitWith {};
		[_unit] call WBK_fnc_removeAIEHs;
		_unit execVM _script;
	};
};

_unit setVariable ["WBK_aiScript", _script];

if !(_unit getVariable ["WBK_localityHooked", false]) then {
	_unit setVariable ["WBK_localityHooked", true];
	_unit addEventHandler ["Local", {
		params ["_unit", "_isLocal"];
		// Losing locality needs no action here: the AI script's own loops stop
		// themselves once the unit is not local to them.
		if (!_isLocal) exitWith {};
		[_unit, _unit getVariable ["WBK_aiScript", ""]] call WBK_fnc_startAI;
	}];
};

[_unit, _script] call WBK_fnc_startAI;
