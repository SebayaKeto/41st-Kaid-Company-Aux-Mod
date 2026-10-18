/*
 * FST stun for droids whose uniform has FST_stunnable = 1 (e.g. FST_U_CIS_TS, the T-series tactical droid).
 * JLTS_fnc_onHitStun refuses every uniform marked JLTS_isDroid; this gives those droids the same stun: knocked out, invulnerable,
 * weapon dropped, back up when the time runs out. Called by FST_fnc_onHit via remoteExecCall where the droid is local.
 *
 * Arguments: 0: droid <OBJECT>, 1: stun duration in seconds from the shooter's magazine <NUMBER> (0 or missing = 10)
 */
params ["_target", ["_duration", 10]];
if (isNull _target || {!local _target} || {!alive _target}) exitWith {};
if (_target getVariable ["ACE_isUnconscious", false] || {_target getVariable ["JLTS_isStunned", false]}) exitWith {};
if (!(missionNamespace getVariable ["JLTS_settings_Stun_worksInVehicles", true]) && {vehicle _target != _target}) exitWith {};
if (_duration <= 0) then {_duration = 10};

// The timer runs on this machine's own clock (diag_tickTime): probe stF2, on a freshly joined HC CBA_missionTime jumped forward while it
// synced and a 5 s stun lasted 2 s. JLTS_isStunnedUntil is still set for anything that reads it.
private _end = diag_tickTime + _duration;
_target setVariable ["JLTS_isStunnedUntil", CBA_missionTime + _duration, true];
_target setVariable ["JLTS_isStunned", true, true];
_target allowDamage false;
if (vehicle _target != _target) then {moveOut _target};

// ACE unconsciousness when the server lets AI go unconscious, otherwise the JLTS fallback: AI off and the dead pose.
private _ace = !isNil "ace_medical_fnc_setUnconscious" && {missionNamespace getVariable ["ace_medical_statemachine_AIUnconsciousness", false]};
if (_ace) then {
	[_target, true] call ace_medical_fnc_setUnconscious;
} else {
	_target disableAI "all";
	_target stop true;
	[_target, "DeadState"] remoteExecCall ["switchMove", 0];
};
private _holder = if (isNil "JLTS_fnc_dropWeapon") then {objNull} else {[_target] call JLTS_fnc_dropWeapon};
diag_log format ["[FST_STUN] %1 (%2) stunned for %3 s at %4, ACE %5", _target, typeOf _target, _duration, CBA_missionTime, _ace];

[
	{diag_tickTime > (_this select 3) || {!alive (_this select 0)}},
	{
		params ["_target", "_ace", "_holder"];
		diag_log format ["[FST_STUN] %1 up at %2 (until %3, alive %4, lifeState %5)", _target, CBA_missionTime, _target getVariable ["JLTS_isStunnedUntil", -1], alive _target, lifeState _target];
		if (alive _target) then {
			if (_ace) then {[_target, false] call ace_medical_fnc_setUnconscious} else {
				[_target, "AmovPpneMstpSnonWnonDnon"] remoteExecCall ["switchMove", 0];
				_target enableAI "all";
				_target stop false;
			};
			if (!isNull _holder && {_target distance _holder < 4} && {count weaponCargo _holder > 0}) then {
				[{params ["_t", "_h"]; if (alive _t && {!isNull _h}) then {_t action ["TakeWeapon", _h, (weaponCargo _h) select 0]}}, [_target, _holder], 2] call CBA_fnc_waitAndExecute;
			};
		};
		_target allowDamage true;
		_target setVariable ["JLTS_isStunned", false, true];
	},
	[_target, _ace, _holder, _end]
] call CBA_fnc_waitUntilAndExecute;
