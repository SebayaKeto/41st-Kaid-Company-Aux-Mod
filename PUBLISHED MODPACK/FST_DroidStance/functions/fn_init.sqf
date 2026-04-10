// fst_droidstance_fnc_init
// Just For B1s and B2s
// For Rubenus: Animchanged EH tries to counteract LAMBS
// PFH catches anything that misses
// Works with or without HCs

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

FST_DROID_STAND_UNITS = [];
FST_DROID_STAND_INDEX = 0;
FST_DROID_STAND_CHUNK = 75;

fst_droidstance_fnc_applyToUnit = {
    params ["_unit"];

    // Safety First
    FST_DROID_STAND_UNITS pushBackUnique _unit;

    if (local _unit) then {
        _unit setUnitPos "UP";
        _unit setUnitPosWeak "UP";
    };

    // LAMB WARRS
    _unit addEventHandler ["AnimChanged", {
        params ["_unit"];
        if (local _unit && { stance _unit != "STAND" }) then {
            _unit setUnitPos "UP";
            _unit setUnitPosWeak "UP";
        };
    }];
};

// Look for any droids preplaced on map
{
    if (typeOf _x in FST_DROID_STAND_CLASSES) then {
        [_x] call fst_droidstance_fnc_applyToUnit;
    };
} forEach allUnits;

// Spawn Catcheroo
addMissionEventHandler ["EntityCreated", {
    params ["_entity"];
    if (typeOf _entity in FST_DROID_STAND_CLASSES) then {
        [_entity] call fst_droidstance_fnc_applyToUnit;
    };
}];

// PFH
if (isServer) then {

    // Cleanup
    [{
        FST_DROID_STAND_UNITS = FST_DROID_STAND_UNITS select { alive _x };
        FST_DROID_STAND_INDEX = FST_DROID_STAND_INDEX min
            ((count FST_DROID_STAND_UNITS - 1) max 0);
    }, 15, []] call CBA_fnc_addPerFrameHandler;

    [{
        private _units = FST_DROID_STAND_UNITS;
        private _count = count _units;
        if (_count == 0) exitWith {};

        if (FST_DROID_STAND_INDEX >= _count) then { FST_DROID_STAND_INDEX = 0 };

        private _end = (FST_DROID_STAND_INDEX + FST_DROID_STAND_CHUNK - 1) min (_count - 1);

        for "_i" from FST_DROID_STAND_INDEX to _end do {
            private _unit = _units select _i;
            if (alive _unit && { stance _unit != "STAND" }) then {
                _unit setUnitPos "UP";
                _unit setUnitPosWeak "UP";
            };
        };

        FST_DROID_STAND_INDEX = _end + 1;

    }, 0.5, []] call CBA_fnc_addPerFrameHandler;

};
