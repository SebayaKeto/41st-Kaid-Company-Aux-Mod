// fst_droidstance_fnc_init
// B1/B2 stance enforcement for FST droids.
// Server/HC only. Normal player clients exit immediately.
// Designed to coexist with FST_HCSpawns and locality changes.

if (hasInterface && {!isServer}) exitWith {};

if (missionNamespace getVariable ["FST_DROID_STANCE_INIT_DONE", false]) exitWith {};
missionNamespace setVariable ["FST_DROID_STANCE_INIT_DONE", true];

FST_DROID_STAND_CLASSES = [
    // B1 variants
    "FST_Droid_B1_E5",
    "FST_Droid_B1_Sniper",
    "FST_Droid_B1_Commander",
    "FST_Droid_B1_AT",
    "FST_Droid_B1_GAT",
    "FST_Droid_B1_AR",
    "FST_Droid_B1_AA",
    "FST_Droid_B1_OOM",
    "FST_Droid_B1_BMO",
    "FST_Droid_B1_Rodger",
    "FST_Droid_B1_Tumble",
    "FST_Droid_B1_PLAD",
    "FST_Droid_B1_Scorch",
    "FST_CIS_TS_F",

    // B2 variants
    "FST_B2",
    "FST_B2_TL",
    "FST_B2_Flame"
];

FST_DROID_B2_CLASSES = [
    "FST_B2",
    "FST_B2_TL",
    "FST_B2_Flame"
];

FST_DROID_STAND_CLASS_SET = createHashMap;
{
    FST_DROID_STAND_CLASS_SET set [_x, true];
} forEach FST_DROID_STAND_CLASSES;

FST_DROID_B2_CLASS_SET = createHashMap;
{
    FST_DROID_B2_CLASS_SET set [_x, true];
} forEach FST_DROID_B2_CLASSES;

FST_DROID_STAND_UNITS = [];
FST_DROID_STAND_INDEX = 0;
FST_DROID_STAND_CHUNK = 75;

// How often the server/HC does a slow safety pass to catch units created or transferred by HC spawn systems.
FST_DROID_STANCE_CATCHUP_INTERVAL = 10;

fst_droidstance_fnc_isTrackedClass = {
    params ["_entity"];
    if (isNull _entity) exitWith { false };
    if (!(_entity isKindOf "CAManBase")) exitWith { false };
    FST_DROID_STAND_CLASS_SET getOrDefault [typeOf _entity, false]
};

fst_droidstance_fnc_isB2Class = {
    params ["_entity"];
    if (isNull _entity) exitWith { false };
    FST_DROID_B2_CLASS_SET getOrDefault [typeOf _entity, false]
};

fst_droidstance_fnc_applyB2LAMBSGuards = {
    params ["_unit"];
    if (isNull _unit) exitWith {};

    // LAMBS compatibility layer. These variables are used by LAMBS compatibility patches/modules
    // to opt custom units out of LAMBS' unit/group AI routines. Set once publicly so owner changes
    // from FST_HCSpawns keep the intent attached to the object/group.
    if (!(_unit getVariable ["FST_DROID_B2_LAMBS_UNIT_SET", false])) then {
        _unit setVariable ["lambs_danger_disableAI", true, true];
        _unit setVariable ["FST_DROID_B2_LAMBS_UNIT_SET", true, true];
    };

    private _grp = group _unit;
    if (!isNull _grp && {!(_grp getVariable ["FST_DROID_B2_LAMBS_GROUP_SET", false])}) then {
        // Some LAMBS behavior is group-driven. This intentionally suppresses the group layer for
        // squads containing B2s so the script is not constantly fighting group cover/prone logic.
        _grp setVariable ["lambs_danger_disablegroupAI", true, true];
        _grp setVariable ["lambs_danger_disableGroupAI", true, true];
        _grp setVariable ["FST_DROID_B2_LAMBS_GROUP_SET", true, true];
    };
};

fst_droidstance_fnc_forceStandLocal = {
    params ["_unit", ["_isB2", false], ["_force", false]];

    if (isNull _unit) exitWith {};
    if (!alive _unit) exitWith {};
    if (!local _unit) exitWith {};

    if (_isB2) then {
        // These are local AI-feature changes, so redo them whenever the unit becomes local.
        // Do not disable MOVE, PATH, TARGET, AUTOTARGET, ANIM, or FSM here; those can break combat/movement.
        _unit disableAI "AUTOCOMBAT";
        _unit disableAI "COVER";
        _unit disableAI "SUPPRESSION";
    };

    if (_force || { stance _unit != "STAND" }) then {
        _unit setUnitPos "UP";
        _unit setUnitPosWeak "UP";
    };
};

fst_droidstance_fnc_startPFHs = {
    if (missionNamespace getVariable ["FST_DROID_STANCE_PFHS_STARTED", false]) exitWith {};
    missionNamespace setVariable ["FST_DROID_STANCE_PFHS_STARTED", true];

    // Cleanup: keep only local living units on this machine. Local EH / catchup will re-add later if needed.
    [{
        FST_DROID_STAND_UNITS = FST_DROID_STAND_UNITS select { !isNull _x && { alive _x } && { local _x } };
        FST_DROID_STAND_INDEX = FST_DROID_STAND_INDEX min ((count FST_DROID_STAND_UNITS - 1) max 0);
    }, 15, []] call CBA_fnc_addPerFrameHandler;

    // Backup stance enforcement. AnimChanged should catch most LAMBS stance changes immediately;
    // this catches misses without scanning every tracked droid every frame.
    [{
        private _units = FST_DROID_STAND_UNITS;
        private _count = count _units;
        if (_count == 0) exitWith {};

        if (FST_DROID_STAND_INDEX >= _count) then {
            FST_DROID_STAND_INDEX = 0;
        };

        private _end = (FST_DROID_STAND_INDEX + FST_DROID_STAND_CHUNK - 1) min (_count - 1);

        for "_i" from FST_DROID_STAND_INDEX to _end do {
            private _unit = _units select _i;
            if (!isNull _unit && { alive _unit } && { local _unit }) then {
                private _isB2 = _unit getVariable ["FST_DROID_STANCE_IS_B2", false];
                if (_isB2 || { stance _unit != "STAND" }) then {
                    [_unit, _isB2, true] call fst_droidstance_fnc_forceStandLocal;
                };
            };
        };

        FST_DROID_STAND_INDEX = _end + 1;
    }, 0.5, []] call CBA_fnc_addPerFrameHandler;
};

fst_droidstance_fnc_applyToUnit = {
    params ["_unit"];

    if (isNull _unit) exitWith {};
    if (!alive _unit) exitWith {};
    if (!([_unit] call fst_droidstance_fnc_isTrackedClass)) exitWith {};

    private _isB2 = [_unit] call fst_droidstance_fnc_isB2Class;
    _unit setVariable ["FST_DROID_STANCE_IS_B2", _isB2, false];

    if (_isB2) then {
        [_unit] call fst_droidstance_fnc_applyB2LAMBSGuards;
    };

    if (local _unit) then {
        FST_DROID_STAND_UNITS pushBackUnique _unit;
        [] call fst_droidstance_fnc_startPFHs;
        [_unit, _isB2, true] call fst_droidstance_fnc_forceStandLocal;
    };

    if (_unit getVariable ["FST_DROID_STANCE_TRACKED", false]) exitWith {};
    _unit setVariable ["FST_DROID_STANCE_TRACKED", true, false];

    // LAMBS/vanilla stance changes usually show up as animation changes.
    _unit addEventHandler ["AnimChanged", {
        params ["_unit"];
        if (!local _unit) exitWith {};

        private _isB2 = _unit getVariable ["FST_DROID_STANCE_IS_B2", false];
        if (_isB2 || { stance _unit != "STAND" }) then {
            [_unit, _isB2, true] call fst_droidstance_fnc_forceStandLocal;
        };
    }];

    // FST_HCSpawns / owner changes: local AI-feature disables need to be re-applied after locality moves.
    _unit addEventHandler ["Local", {
        params ["_unit", "_isLocal"];
        if (!_isLocal) exitWith {};

        private _isB2 = _unit getVariable ["FST_DROID_STANCE_IS_B2", ([_unit] call fst_droidstance_fnc_isB2Class)];
        _unit setVariable ["FST_DROID_STANCE_IS_B2", _isB2, false];

        if (_isB2) then {
            [_unit] call fst_droidstance_fnc_applyB2LAMBSGuards;
        };

        FST_DROID_STAND_UNITS pushBackUnique _unit;
        [] call fst_droidstance_fnc_startPFHs;
        [_unit, _isB2, true] call fst_droidstance_fnc_forceStandLocal;
    }];
};

// Preplaced/editor units already present on this machine.
{
    if (local _x && { [_x] call fst_droidstance_fnc_isTrackedClass }) then {
        [_x] call fst_droidstance_fnc_applyToUnit;
    };
} forEach allUnits;

// Zeus/runtime/FST_HCSpawns creation catcher.
addMissionEventHandler ["EntityCreated", {
    params ["_entity"];
    if ([_entity] call fst_droidstance_fnc_isTrackedClass) then {
        [_entity] call fst_droidstance_fnc_applyToUnit;
    };
}];

// Slow locality catchup. This is deliberately low-frequency and server/HC-only to avoid player-client cost.
// It protects against any spawn/owner edge case where EntityCreated or Local EH timing misses a unit.
[{
    {
        if (local _x && { [_x] call fst_droidstance_fnc_isTrackedClass }) then {
            [_x] call fst_droidstance_fnc_applyToUnit;
        };
    } forEach allUnits;
}, FST_DROID_STANCE_CATCHUP_INTERVAL, []] call CBA_fnc_addPerFrameHandler;
