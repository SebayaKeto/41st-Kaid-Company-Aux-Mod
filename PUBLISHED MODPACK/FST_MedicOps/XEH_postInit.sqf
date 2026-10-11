// FST_MedicOps postInit

// --- server: stats store, revive attribution, report requests, end-of-mission log
if (isServer) then {
    FST_medOps_stats = createHashMap;
    ["FST_medOps_stat", { _this call FST_medOps_fnc_serverStat }] call CBA_fnc_addEventHandler;
    ["FST_medOps_reportReq", {
        ([] call FST_medOps_fnc_buildReport) params ["_lines", "_best"];
        diag_log text format ["FST_medOps REPORT | best %1 | %2", _best, _lines];
        ["FST_medOps_reportShow", [_lines, _best]] call CBA_fnc_globalEvent;
    }] call CBA_fnc_addEventHandler;
    addMissionEventHandler ["Ended", {
        ([] call FST_medOps_fnc_buildReport) params ["_lines", "_best"];
        diag_log text format ["FST_medOps REPORT (mission end) | best %1 | %2", _best, _lines];
    }];
};

// --- every machine: casualty side (auto-call on going down) and CPR revive credit (patient's machine)
["ace_unconscious", {
    params ["_unit", "_down"];
    if (!local _unit || {!isPlayer _unit}) exitWith {};
    if (_down) then {
        if (missionNamespace getVariable ["FST_medOps_autoCall", true]) then { [_unit, true, "down"] call FST_medOps_fnc_setCall; };
    };
}] call CBA_fnc_addEventHandler;

["ace_medical_CPRSucceeded", {
    params ["_patient"];
    if (!local _patient || {!(missionNamespace getVariable ["FST_medOps_report", true])}) exitWith {};
    private _medic = _patient getVariable ["ace_medical_CPR_provider", objNull];
    if (isNull _medic || {!isPlayer _medic} || {_medic == _patient}) exitWith {};
    ["FST_medOps_stat", [getPlayerUID _medic, name _medic, ["revive"], getPlayerUID _patient]] call CBA_fnc_serverEvent;
}] call CBA_fnc_addEventHandler;

// --- every machine: Bacta Mist. The thrower's machine sees the throw, waits for the grenade to settle, then tells
// everyone where the cloud is; each machine treats only its own local units (mistTick).
FST_medOps_mists = [];
["FST_medOps_mistAt", {
    params ["_pos", "_until"];
    FST_medOps_mists pushBack [_pos, _until];
}] call CBA_fnc_addEventHandler;
["CAManBase", "fired", {
    params ["_unit", "", "", "", "_ammo", "", "_projectile"];
    if (_ammo != "FST_BactaMist_Ammo" || {!local _unit}) exitWith {};
    [{
        params ["_p"];
        isNull _p || {vectorMagnitude velocity _p < 0.3}
    }, {
        params ["_p", "_unit"];
        if (isNull _p) exitWith {};
        ["FST_medOps_mistAt", [getPosATL _p, CBA_missionTime + 30]] call CBA_fnc_globalEvent;
        if (isPlayer _unit) then {
            ["FST_medOps_stat", [getPlayerUID _unit, name _unit, ["mist"], ""]] call CBA_fnc_serverEvent;
        };
    }, [_projectile, _unit], 15, {}] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addClassEventHandler;
[{ [] call FST_medOps_fnc_mistTick }, 2] call CBA_fnc_addPerFrameHandler;

// --- every machine: internal bleeding (start on heavy torso hits; drain local units every 2 s)
["ace_medical_woundReceived", { _this call FST_medOps_fnc_internalWound }] call CBA_fnc_addEventHandler;
[{ [] call FST_medOps_fnc_internalTick }, 2] call CBA_fnc_addPerFrameHandler;

// --- player machines: call/cancel actions, beacon housekeeping, medic HUD, treatment stats, report display
if (hasInterface) then {
    ["ace_treatmentSucceded", { _this call FST_medOps_fnc_onTreatment }] call CBA_fnc_addEventHandler;

    // Medscanner: interact with a casualty (or yourself) while carrying one
    private _scanIcon = "\FST_MedicOps\ui\medscanner_ca.paa";
    private _scan = ["FST_medOps_medscan", "Medscan", _scanIcon,
        { [_target, true] call FST_medOps_fnc_medscan },
        { "FST_Medscanner" in items _player && {alive _target} && {_target != _player} }
    ] call ace_interact_menu_fnc_createAction;
    ["CAManBase", 0, ["ACE_MainActions"], _scan, true] call ace_interact_menu_fnc_addActionToClass;
    private _scanSelf = ["FST_medOps_medscanSelf", "Medscan (self)", _scanIcon,
        { [_player, true] call FST_medOps_fnc_medscan },
        { "FST_Medscanner" in items _player }
    ] call ace_interact_menu_fnc_createAction;
    ["CAManBase", 1, ["ACE_SelfActions"], _scanSelf, true] call ace_interact_menu_fnc_addActionToClass;

    private _icon = "\a3\ui_f\data\igui\cfg\simpletasks\types\heal_ca.paa";
    private _call = ["FST_medOps_call", "Call Medic", _icon,
        { [_player, true, "called"] call FST_medOps_fnc_setCall },
        { (missionNamespace getVariable ["FST_medOps_beacons", true]) && {isNil { _player getVariable "FST_medOps_call" }} }
    ] call ace_interact_menu_fnc_createAction;
    ["CAManBase", 1, ["ACE_SelfActions"], _call, true] call ace_interact_menu_fnc_addActionToClass;
    private _cancel = ["FST_medOps_cancel", "Cancel Medic Call", _icon,
        { [_player, false] call FST_medOps_fnc_setCall; hint "Medic call cancelled."; },
        { !isNil { _player getVariable "FST_medOps_call" } }
    ] call ace_interact_menu_fnc_createAction;
    ["CAManBase", 1, ["ACE_SelfActions"], _cancel, true] call ace_interact_menu_fnc_addActionToClass;

    // consumable bacta: only shown while charges are on and the player carries a tank
    private _cartIcon = "\FST_MedicOps\ui\bactaCartridge_ca.paa";
    private _check = ["FST_medOps_bactaCheck", "Check Bacta Tank", _cartIcon,
        { hint format ["Bacta tank: %1 of %2 charges", [_player, "left"] call FST_medOps_fnc_bactaCharge, missionNamespace getVariable ["FST_medOps_bactaCharges", 0]]; },
        { (missionNamespace getVariable ["FST_medOps_bactaCharges", 0]) > 0 && {"FST_Bacta_Tank" in items _player} }
    ] call ace_interact_menu_fnc_createAction;
    ["CAManBase", 1, ["ACE_SelfActions"], _check, true] call ace_interact_menu_fnc_addActionToClass;
    private _reload = ["FST_medOps_bactaReload", "Reload Bacta Tank", _cartIcon,
        { [_player, "reload"] call FST_medOps_fnc_bactaCharge; },
        { (missionNamespace getVariable ["FST_medOps_bactaCharges", 0]) > 0 && {"FST_Bacta_Tank" in items _player}
            && {"FST_BactaCartridge" in items _player}
            && {([_player, "left"] call FST_medOps_fnc_bactaCharge) < (missionNamespace getVariable ["FST_medOps_bactaCharges", 0])} }
    ] call ace_interact_menu_fnc_createAction;
    ["CAManBase", 1, ["ACE_SelfActions"], _reload, true] call ace_interact_menu_fnc_addActionToClass;

    FST_medOps_cache = [];
    [{ [] call FST_medOps_fnc_casualtyTick }, 3] call CBA_fnc_addPerFrameHandler;
    [{ [] call FST_medOps_fnc_medicTick }, 1] call CBA_fnc_addPerFrameHandler;

    addMissionEventHandler ["Draw3D", {
        if (FST_medOps_cache isEqualTo []) exitWith {};
        private _icon = "\a3\ui_f\data\igui\cfg\simpletasks\types\heal_ca.paa";
        {
            _x params ["_u", "_sev"];
            if (!isNull _u && {alive _u}) then {
                private _d = round (_u distance player);
                drawIcon3D [_icon, _sev select 2, (ASLToAGL getPosASLVisual _u) vectorAdd [0, 0, 1.6], 0.8, 0.8, 0,
                    format ["%1  %2 m  %3", name _u, _d, _sev select 1], 2, 0.033, "RobotoCondensed", "center", true];
            };
        } forEach FST_medOps_cache;
    }];

    ["FST_medOps_reportShow", {
        params ["_lines", "_best"];
        if (_lines isEqualTo []) exitWith { systemChat "Medic report: no treatments recorded yet."; };
        private _text = format ["<t size='1.2'>Medic Report</t><br/>%1<br/><br/>%2",
            if (_best != "") then { format ["Medic of the Op: <t color='#7fd8ff'>%1</t>", _best] } else { "" },
            _lines joinString "<br/>"];
        hint parseText _text;
        { systemChat _x } forEach _lines;
    }] call CBA_fnc_addEventHandler;

    // Zeus module (Zen, same category as the 41st medical tools)
    if (!isNil "zen_custom_modules_fnc_register") then {
        ["41st Medical", "Medic Report", {
            ["FST_medOps_reportReq", []] call CBA_fnc_serverEvent;
        }, _icon] call zen_custom_modules_fnc_register;
    };
};
