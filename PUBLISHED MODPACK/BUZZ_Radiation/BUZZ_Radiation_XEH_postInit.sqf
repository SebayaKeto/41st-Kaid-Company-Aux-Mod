// BUZZ_Radiation post-init
[{call BUZZ_Radiation_fnc_tick}, 1] call CBA_fnc_addPerFrameHandler;

// Iodine treatment
["BUZZ_Radiation_iodineLocal", {
    params ["_unit"];
    _unit setVariable ["BUZZ_Radiation_treatedUntil", CBA_missionTime + 60 * BUZZ_Radiation_iodineDuration, true];
}] call CBA_fnc_addEventHandler;

// Radiation Flush IV treatment
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

// ACE full heal
["ace_medical_treatment_fullHealLocalMod", {
    params ["_unit"];
    [_unit, 0] call BUZZ_Radiation_fnc_setDose;
}] call CBA_fnc_addEventHandler;

// Radiation Monitor direction ring
if (hasInterface) then {
    [{call BUZZ_Radiation_fnc_updateRadar}, 0.2] call CBA_fnc_addPerFrameHandler;
};

// ACE medical menu entry
if (hasInterface) then {
    ["ace_medical_gui_updateInjuryListGeneral", {_this call BUZZ_Radiation_fnc_medicalMenuEntry}] call CBA_fnc_addEventHandler;
};

// 3D sounds
["BUZZ_Radiation_say3D", {
    params ["_source", "_class", "_range", ["_pitch", 1]];
    if (isNull _source || {!hasInterface}) exitWith {};
    private _host = vehicle _source;
    private _emitter = "Land_HelipadEmpty_F" createVehicleLocal [0, 0, 0];
    _emitter attachTo [_host, if (_host == _source) then {[0, 0, 1.5]} else {[0, 0, 1]}];
    _emitter say3D [_class, _range, _pitch];
    [{deleteVehicle _this}, _emitter, 8] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addEventHandler;

// Zeus-placed zones
["BUZZ_Radiation_zeusZoneAdd", {
    params ["_obj", "_tier", "_radius"];
    if (isNull _obj) exitWith {};
    _obj setVariable ["BUZZ_Radiation_radius", _radius];
    [_obj, _tier, [[getPosATL _obj, _radius, _radius, 0, false, -1]]] call BUZZ_Radiation_fnc_addZone;
}] call CBA_fnc_addEventHandler;
if (isServer) then {
    ["BUZZ_Radiation_zeusZoneCreated", {
        params ["_obj", "_tier", "_radius"];
        if (isNull _obj) exitWith {};
        {_x addCuratorEditableObjects [[_obj], false]} forEach allCurators;
        private _jip = ["BUZZ_Radiation_zeusZoneAdd", [_obj, _tier, _radius]] call CBA_fnc_globalEventJIP;
        [_jip, _obj] call CBA_fnc_removeGlobalEventJIP;
    }] call CBA_fnc_addEventHandler;
};
if (hasInterface && {isClass (configFile >> "CfgPatches" >> "zen_custom_modules")}) then {
    ["BUZZ Radiation", "Radiation Zone", {_this call BUZZ_Radiation_fnc_zeusZone}, "\BUZZ_Radiation\data\BUZZ_Radiation_monitor_ca.paa"] call zen_custom_modules_fnc_register;
};

// Reset on respawn
["CAManBase", "Respawn", {
    params ["_unit"];
    if (!local _unit) exitWith {};
    {
        if ("buzz_radiation_" in toLower _x) then {_unit setVariable [_x, nil, true]};
    } forEach allVariables _unit;
    [_unit, 0] call BUZZ_Radiation_fnc_setDose;
}] call CBA_fnc_addClassEventHandler;

// Clear dose on death
["CAManBase", "Killed", {
    params ["_unit"];
    if (!local _unit) exitWith {};
    _unit setVariable ["BUZZ_Radiation_flush", nil, true];
    [_unit, 0] call BUZZ_Radiation_fnc_setDose;
}] call CBA_fnc_addClassEventHandler;

// Remote setDose
["BUZZ_Radiation_setDoseLocal", {_this call BUZZ_Radiation_fnc_setDose}] call CBA_fnc_addEventHandler;

// Reset on join
if (hasInterface && {isMultiplayer}) then {
    [{!isNull player}, {
        {
            if ("buzz_radiation_" in toLower _x) then {player setVariable [_x, nil, true]};
        } forEach allVariables player;
        [player, 0] call BUZZ_Radiation_fnc_setDose;
    }] call CBA_fnc_waitUntilAndExecute;
};

