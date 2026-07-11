// FST_HCSpawn_fnc_applyUnitLoadoutSafe
// Local helper. Applies a captured loadout only when it is safe to do so.
// Some modded units, especially droids, finish weapon assignment shortly after
// CuratorGroupPlaced/createUnit. Capturing/applying an empty early loadout can
// wipe their weapons. If the unit class has configured weapons but the captured
// loadout has none, skip the bad loadout and allow/restore class defaults.

params ["_unit", "_loadout", ["_class", ""], ["_context", ""]];

if (isNull _unit) exitWith { false };
if (!local _unit) exitWith { false };
if (count _loadout == 0) exitWith { false };
if (_class isEqualTo "") then { _class = typeOf _unit; };

private _ignoredWeapons = [
    "", "Throw", "Put", "Binocular", "Rangefinder",
    "Laserdesignator", "Laserdesignator_02", "Laserdesignator_03",
    "NVGoggles", "NVGoggles_OPFOR", "NVGoggles_INDEP"
];

private _cfgWeapons = getArray (configFile >> "CfgVehicles" >> _class >> "weapons");
private _cfgRealWeapons = _cfgWeapons select {
    !(_x in _ignoredWeapons) && { isClass (configFile >> "CfgWeapons" >> _x) }
};

private _capturedWeapons = [];
for "_i" from 0 to 2 do {
    if (count _loadout > _i) then {
        private _entry = _loadout select _i;
        if (_entry isEqualType [] && {count _entry > 0}) then {
            private _weapon = _entry select 0;
            if (_weapon isEqualType "" && {_weapon != ""}) then {
                _capturedWeapons pushBackUnique _weapon;
            };
        };
    };
};

private _hasClassWeapon = count _cfgRealWeapons > 0;
private _capturedHasWeapon = count _capturedWeapons > 0;

// Guard against the critical race: class should have weapons, captured snapshot
// has none. Do NOT apply it, because that strips default/scripted droid weapons.
if (_hasClassWeapon && {!_capturedHasWeapon}) exitWith {
    if (missionNamespace getVariable ["FST_HC_DebugLogging", false]) then {
        diag_log format [
            "[FST_HCSpawn] Skipped suspicious empty captured loadout for %1 (%2). Context=%3 cfgWeapons=%4 loadout=%5",
            _unit, _class, _context, _cfgRealWeapons, _loadout
        ];
    };

    // Let class/event-handler loadout settle first. If the unit is still fully
    // unarmed after that, force the class default loadout as a last resort.
    [{
        params ["_unit", "_class", "_context", "_cfgRealWeapons"];
        if (isNull _unit || {!local _unit}) exitWith {};
        if ((primaryWeapon _unit isEqualTo "") && {secondaryWeapon _unit isEqualTo ""} && {handgunWeapon _unit isEqualTo ""}) then {
            _unit setUnitLoadout _class;
            if (missionNamespace getVariable ["FST_HC_DebugLogging", false]) then {
                diag_log format [
                    "[FST_HCSpawn] Reapplied class default loadout to unarmed %1 (%2). Context=%3 cfgWeapons=%4",
                    _unit, _class, _context, _cfgRealWeapons
                ];
            };
        };
    }, [_unit, _class, _context, _cfgRealWeapons], 0.75] call CBA_fnc_waitAndExecute;

    false
};

_unit setUnitLoadout _loadout;
[_unit] call FST_HCSpawn_fnc_emergencyStabilizeDroid;

// Post-apply guard: if a malformed captured loadout still leaves a class that
// should be armed completely unarmed, restore class defaults after settle.
if (_hasClassWeapon) then {
    [{
        params ["_unit", "_class", "_context", "_cfgRealWeapons"];
        if (isNull _unit || {!local _unit}) exitWith {};
        if ((primaryWeapon _unit isEqualTo "") && {secondaryWeapon _unit isEqualTo ""} && {handgunWeapon _unit isEqualTo ""}) then {
            _unit setUnitLoadout _class;
            if (missionNamespace getVariable ["FST_HC_DebugLogging", false]) then {
                diag_log format [
                    "[FST_HCSpawn] Corrected unarmed unit after loadout apply: %1 (%2). Context=%3 cfgWeapons=%4",
                    _unit, _class, _context, _cfgRealWeapons
                ];
            };
        };
    }, [_unit, _class, _context, _cfgRealWeapons], 0.75] call CBA_fnc_waitAndExecute;
};

true
