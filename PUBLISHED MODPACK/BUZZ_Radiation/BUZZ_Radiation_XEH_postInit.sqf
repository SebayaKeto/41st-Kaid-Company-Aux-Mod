// Radiation - runtime
// One loop per machine handles the units local to it (players on their own client;
// AI on the server / headless client when "Affect AI" is on).
[{call BUZZ_Radiation_fnc_tick}, 1] call CBA_fnc_addPerFrameHandler;

// Iodine is given on the medic's machine; apply it where the patient is local.
["BUZZ_Radiation_iodineLocal", {
    params ["_unit"];
    _unit setVariable ["BUZZ_Radiation_treatedUntil", CBA_missionTime + 60 * BUZZ_Radiation_iodineDuration, true];
}] call CBA_fnc_addEventHandler;

// Radiation Flush IV is given on the medic's machine; start it where the patient is local.
// A new flush replaces one still running (its unused part is lost), so flushes do not stack.
["BUZZ_Radiation_flushLocal", {
    params ["_unit"];
    private _mult = [1, BUZZ_Radiation_flushFatalEffect] select ((_unit getVariable ["BUZZ_Radiation_dose", 0]) > BUZZ_Radiation_menuFatal);
    _unit setVariable ["BUZZ_Radiation_flush", [
        CBA_missionTime,
        BUZZ_Radiation_flushFastAmount * _mult, BUZZ_Radiation_flushFastSeconds,
        BUZZ_Radiation_flushSlowAmount * _mult, 60 * BUZZ_Radiation_flushSlowMinutes
    ], true];
    if (BUZZ_Radiation_flushPain > 0 && {!isNil "ace_medical_fnc_adjustPainLevel"}) then {
        [_unit, BUZZ_Radiation_flushPain] call ace_medical_fnc_adjustPainLevel;
    };
}] call CBA_fnc_addEventHandler;

// ACE full heal (e.g. Personal Aid Kit / Zeus heal) also clears radiation.
["ace_medical_treatment_fullHealLocalMod", {
    params ["_unit"];
    [_unit, 0] call BUZZ_Radiation_fnc_setDose;
}] call CBA_fnc_addEventHandler;


// Radiation Monitor direction ring, refreshed 5 times a second while a panel is open.
if (hasInterface) then {
    [{call BUZZ_Radiation_fnc_updateRadar}, 0.2] call CBA_fnc_addPerFrameHandler;
};

// "Radiation Sickness" line in the ACE medical menu overview (detection device holders only).
if (hasInterface) then {
    ["ace_medical_gui_updateInjuryListGeneral", {_this call BUZZ_Radiation_fnc_medicalMenuEntry}] call CBA_fnc_addEventHandler;
};

// 3D sounds (detector clicks, coughs) for nearby players. CBA events instead of remoteExec,
// so servers with a CfgRemoteExec whitelist don't block them.
["BUZZ_Radiation_say3D", {
    params ["_source", "_class", "_range", ["_pitch", 1]];
    if (isNull _source) exitWith {};
    _source say3D [_class, _range, _pitch];
}] call CBA_fnc_addEventHandler;

// setDose from another machine lands here, where the unit is local.
["BUZZ_Radiation_setDoseLocal", {_this call BUZZ_Radiation_fnc_setDose}] call CBA_fnc_addEventHandler;

// Disconnecting must not cure radiation: the server keeps a leaving player's dose by UID
// and hands it back when they rejoin. Dying still resets it (a respawned unit starts clean).
if (isServer) then {
    BUZZ_Radiation_savedDoses = createHashMap;
    addMissionEventHandler ["HandleDisconnect", {
        params ["_unit", "", "_uid"];
        if (alive _unit && {_uid != ""}) then {
            private _dose = _unit getVariable ["BUZZ_Radiation_dose", 0];
            if (_dose > 0) then {
                BUZZ_Radiation_savedDoses set [_uid, [_dose, _unit getVariable ["BUZZ_Radiation_sickRate", 0]]];
            };
        };
        false
    }];
    ["BUZZ_Radiation_requestDose", {
        params ["_unit", "_uid"];
        private _saved = BUZZ_Radiation_savedDoses getOrDefault [_uid, []];
        if (_saved isEqualTo []) exitWith {};
        BUZZ_Radiation_savedDoses deleteAt _uid;
        _saved params ["_dose", "_sickRate"];
        [_unit, _dose, _sickRate] call BUZZ_Radiation_fnc_setDose;
    }] call CBA_fnc_addEventHandler;
};
if (hasInterface && {isMultiplayer}) then {
    [{!isNull player && {getPlayerUID player != ""}}, {
        ["BUZZ_Radiation_requestDose", [player, getPlayerUID player]] call CBA_fnc_serverEvent;
    }] call CBA_fnc_waitUntilAndExecute;
};

