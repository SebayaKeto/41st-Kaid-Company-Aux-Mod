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
// Stun on tactical droids (Miran 17 Oct: "Stun rounds need to work on tactical droids but not other droids"). JLTS_fnc_onHitStun
// refuses every uniform with JLTS_isDroid = 1. A uniform with FST_stunnable = 1 (41st_Droids: FST_U_CIS_TS, the T-series tactical
// droid) is stunned by FST_fnc_onHitStunDroid instead, run where the droid is local (droids usually live on an HC; allowDamage and
// ACE unconsciousness must run there). Every other droid still goes to JLTS and stays immune. The duration comes from the shooter's
// magazine, as in JLTS.
if (_flags select 1) then {
	if (getNumber (configFile >> "CfgWeapons" >> uniform _target >> "FST_stunnable") == 1) then {
		if (_target != _shooter && {!(_target getVariable ["JLTS_isStunned",false])}) then {
			[_target, getNumber (configFile >> "CfgMagazines" >> currentMagazine _shooter >> "JLTS_stunDuration")] remoteExecCall ["FST_fnc_onHitStunDroid", _target];
		};
	} else {
		[_target,_shooter,_ammoUsed] call JLTS_fnc_onHitStun;
	};
};