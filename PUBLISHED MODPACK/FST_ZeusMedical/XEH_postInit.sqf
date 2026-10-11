// FST_ZeusMedical postInit
// Every machine: handle effects for units local to it (Zeus -> CBA target event -> unit owner), and keep Plot Armor
// running for its local units (survives HC transfer / player reconnect, since the flag lives on the unit, public).

["FST_zeusMed_apply", { _this call FST_zeusMed_fnc_applyLocal }] call CBA_fnc_addEventHandler;
["FST_zeusMed_plotArmor", { _this call FST_zeusMed_fnc_plotArmorLocal }] call CBA_fnc_addEventHandler;

if (isServer) then {
    ["FST_zeusMed_spawn", { _this call FST_zeusMed_fnc_spawnCasualty }] call CBA_fnc_addEventHandler;
};

// Plot Armor blood floor: 3.7 L, just above ACE's Class IV line (3.6 L), below which ACE triggers cardiac arrest
FST_zeusMed_bloodFloor = 3.7;
FST_zeusMed_armoredLocal = [];
[{ [] call FST_zeusMed_fnc_plotArmorTick }, 1] call CBA_fnc_addPerFrameHandler;
// ...and heart rate held in 45-190 while down (ACE fatal vitals: < 20 or > 220, and < 30 by chance)
[{
    {
        if (alive _x && {local _x}) then {
            if ((_x getVariable ["ace_medical_bloodVolume", 6]) < FST_zeusMed_bloodFloor) then {
                _x setVariable ["ace_medical_bloodVolume", FST_zeusMed_bloodFloor, true];
            };
            if (_x getVariable ["ACE_isUnconscious", false] && {!(_x getVariable ["ace_medical_inCardiacArrest", false])}) then {
                private _hr = _x getVariable ["ace_medical_heartRate", 80];
                if (_hr < 45 || {_hr > 190}) then { _x setVariable ["ace_medical_heartRate", (_hr max 45) min 190, true]; };
            };
        };
    } forEach FST_zeusMed_armoredLocal;
}, 0.2] call CBA_fnc_addPerFrameHandler;

if (hasInterface) then {
    ["FST_zeusMed_feedback", {
        params ["_msg"];
        systemChat _msg;
        if (!isNull (findDisplay 312)) then { [objNull, _msg] call BIS_fnc_showCuratorFeedbackMessage; };
    }] call CBA_fnc_addEventHandler;
    [] call FST_zeusMed_fnc_registerModules;
};
