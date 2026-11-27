// Bacta Tank probe (Aux Updater, 25 Nov 2026). No input needed. Logs BACTAPROBE lines to the client RPT, then "BACTAPROBE done".
// Case 1: a bleeding, unconscious unit -> canTreat FST_Bacta_Tank must be FALSE.
// Case 2: the same unit, every wound bandaged, still unconscious -> canTreat TRUE; then the real treatment -> full heal (awake, blood 6).
[] spawn {
    waitUntil {!isNull player && {alive player} && {time > 5}};
    sleep 10;
    private _cfg = configFile >> "ACE_medical_treatment_actions" >> "FST_Bacta_Tank";
    diag_log text format ["BACTAPROBE cfg condition=%1 | locations isText=%2 num=%3 | medicRequired=%4 | callback=%5 | src=%6",
        getText (_cfg >> "condition"), isText (_cfg >> "treatmentLocations"), getNumber (_cfg >> "treatmentLocations"),
        getText (_cfg >> "medicRequired"), getText (_cfg >> "callbackSuccess"), configSourceAddonList _cfg];
    diag_log text format ["BACTAPROBE settings locationPAK=%1 medicPAK=%2 consumePAK=%3 allowSelfPAK=%4 holsterRequired=%5 PAK condition=%6",
        missionNamespace getVariable ["ace_medical_treatment_locationPAK", "nil"], missionNamespace getVariable ["ace_medical_treatment_medicPAK", "nil"],
        missionNamespace getVariable ["ace_medical_treatment_consumePAK", "nil"], missionNamespace getVariable ["ace_medical_treatment_allowSelfPAK", "nil"],
        missionNamespace getVariable ["ace_medical_treatment_holsterRequired", "nil"],
        getText (configFile >> "ACE_medical_treatment_actions" >> "PersonalAidKit" >> "condition")];

    player setVariable ["ace_medical_medicClass", 2, true];
    // run 1 (21:42): addItem failed silently (full inventory) -> 0 bacta tanks. Give an empty carryall first.
    removeBackpack player; player addBackpack "B_Carryall_mcamo";
    for "_k" from 1 to 3 do {player addItemToBackpack "FST_Bacta_Tank"};
    private _wc = {private _n = 0; {_n = _n + count _y} forEach (_u getVariable ["ace_medical_openWounds", createHashMap]); {_n = _n + count _y} forEach (_u getVariable ["ace_medical_bandagedWounds", createHashMap]); _n};
    private _grp = createGroup [west, true];
    private _u = _grp createUnit ["B_Soldier_F", player modelToWorld [0, 1.5, 0], [], 0, "CAN_COLLIDE"];
    {_u disableAI _x} forEach ["MOVE", "PATH", "FSM", "AUTOTARGET", "TARGET"];
    sleep 2;
    [_u, 0.5, "leftleg", "bullet"] call ace_medical_fnc_addDamageToUnit;
    [_u, 0.5, "body", "bullet"] call ace_medical_fnc_addDamageToUnit;
    [_u, true] call ace_medical_fnc_setUnconscious;
    sleep 3;

    private _st = {
        format ["alive=%1 uncon=%2 bleeding=%3 stableVitals=%4 isInStable=%5 hr=%6 blood=%7 medicSpeed=%8 dist=%9",
            alive _u, _u getVariable ["ACE_isUnconscious", false], _u getVariable ["ace_medical_woundBleeding", -1],
            _u call ace_medical_status_fnc_hasStableVitals, [_u] call ace_medical_status_fnc_isInStableCondition,
            _u getVariable ["ace_medical_heartRate", -1], _u getVariable ["ace_medical_bloodVolume", -1], speed player, player distance _u]
    };
    private _can = {[player, _u, "body", "FST_Bacta_Tank"] call ace_medical_treatment_fnc_canTreat};
    diag_log text format ["BACTAPROBE kit bacta_in_inventory=%1 hasItem=%2 isMedic=%3", {_x == "FST_Bacta_Tank"} count items player, [player, _u, ["FST_Bacta_Tank"]] call ace_medical_treatment_fnc_hasItem, [player, 1] call ace_medical_treatment_fnc_isMedic];
    private _canPAK = {[player, _u, "body", "PersonalAidKit"] call ace_medical_treatment_fnc_canTreat};
    diag_log text format ["BACTAPROBE case1 bleeding | %1 | bacta canTreat=%2 (want false) | PAK canTreat=%3", call _st, call _can, call _canPAK];

    private _parts = ["head", "body", "leftarm", "rightarm", "leftleg", "rightleg"];
    for "_i" from 1 to 40 do {
        if ((_u getVariable ["ace_medical_woundBleeding", 0]) == 0) exitWith {};
        {[_u, _x, "FieldDressing"] call ace_medical_treatment_fnc_bandageLocal} forEach _parts;
        sleep 0.2;
    };
    sleep 2;
    diag_log text format ["BACTAPROBE case2 bandaged | %1 | bacta canTreat=%2 (want true) | PAK canTreat=%3", call _st, call _can, call _canPAK];

    private _n0 = {_x == "FST_Bacta_Tank"} count items player; private _w0 = call _wc;
    private _started = [player, _u, "body", "FST_Bacta_Tank"] call ace_medical_treatment_fnc_treatment;
    diag_log text format ["BACTAPROBE treatment started=%1 healTime=%2", _started, [player, _u] call ace_medical_treatment_fnc_getHealTime];
    private _t0 = time;
    waitUntil {sleep 1; (!(_u getVariable ["ACE_isUnconscious", false]) && {(_u getVariable ["ace_medical_bloodVolume", 0]) >= 5.99}) || {time - _t0 > 90}};
    sleep 3;
    diag_log text format ["BACTAPROBE after | %1 | secs=%2 | bacta items %3 -> %4 | wounds %5 -> %6",
        call _st, round (time - _t0), _n0, {_x == "FST_Bacta_Tank"} count items player, _w0, call _wc];
    deleteVehicle _u;
    sleep 2;

    // Case 3 (Omnibus 25 Nov): bandaged + AWAKE -> bacta must still work (canTreat true, then the real treatment heals).
    _u = _grp createUnit ["B_Soldier_F", player modelToWorld [0, 1.5, 0], [], 0, "CAN_COLLIDE"];
    {_u disableAI _x} forEach ["MOVE", "PATH", "FSM", "AUTOTARGET", "TARGET"];
    sleep 2;
    [_u, 0.3, "leftleg", "bullet"] call ace_medical_fnc_addDamageToUnit;
    sleep 2;
    if (_u getVariable ["ACE_isUnconscious", false]) then {[_u, false] call ace_medical_fnc_setUnconscious; sleep 2};
    for "_i" from 1 to 40 do {
        if ((_u getVariable ["ace_medical_woundBleeding", 0]) == 0) exitWith {};
        {[_u, _x, "FieldDressing"] call ace_medical_treatment_fnc_bandageLocal} forEach _parts;
        sleep 0.2;
    };
    sleep 2;
    diag_log text format ["BACTAPROBE case3 awake | %1 | bacta canTreat=%2 (want true) | PAK canTreat=%3", call _st, call _can, call _canPAK];
    private _started3 = [player, _u, "body", "FST_Bacta_Tank"] call ace_medical_treatment_fnc_treatment;
    _t0 = time;
    private _bw0 = call _wc;
    waitUntil {sleep 1; ((call _wc) == 0) || {time - _t0 > 90}};
    sleep 3;
    diag_log text format ["BACTAPROBE case3after started=%1 | %2 | secs=%3 | wounds %4 -> %5", _started3, call _st, round (time - _t0), _bw0, call _wc];
    deleteVehicle _u;
    diag_log text "BACTAPROBE done";
};
