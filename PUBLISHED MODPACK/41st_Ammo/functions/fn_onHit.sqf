/*
 * Author: MrClock
 * HitPart XEH function
 *
 *
 * Arguments:
 * Inherited from HitPart XEH
 *
 * Example:
 * (_this select 0) call JLTS_fnc_onHit;
 *
 * Return Value:
 * None
 *
 */

params["_target", "_shooter", "_projectile", "_position", "_velocity", "_selection", "_ammo", "_vector", "_radius", "_surfaceType", "_isDirect"];

if (isNil{_ammo select 4}) exitWith {/*systemChat "Fall damage"*/};

if (!alive _target) exitWith {};

private _ammoUsed = _ammo select 4;

// Perf fix (2026-09-20): HitPart fires on the shooter's machine for every
// impact, so during a droid firefight the HCs were doing two config reads per
// bullet hit. The EMP/stun flags depend only on the ammo class; cache them.
private _cache = missionNamespace getVariable "FST_OnHitAmmoFlagCache";
if (isNil "_cache") then {
	_cache = createHashMap;
	missionNamespace setVariable ["FST_OnHitAmmoFlagCache", _cache];
};
private _flags = _cache get _ammoUsed;
if (isNil "_flags") then {
	private _cfg = configFile >> "CfgAmmo" >> _ammoUsed;
	_flags = [getNumber (_cfg >> "JLTS_isEMPAmmo") == 1, getNumber (_cfg >> "JLTS_isStunAmmo") == 1];
	_cache set [_ammoUsed, _flags];
};

if (_flags select 0) then {[_target,_shooter,_ammoUsed,getPosATL _projectile] spawn FST_fnc_onHitEMP};
if (_flags select 1) then {[_target,_shooter,_ammoUsed] call JLTS_fnc_onHitStun};