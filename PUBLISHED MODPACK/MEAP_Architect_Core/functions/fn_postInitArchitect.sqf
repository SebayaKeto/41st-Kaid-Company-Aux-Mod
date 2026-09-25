if (hasInterface && {!isNil "ace_interact_menu_fnc_createAction"} && {!isNil "ace_interact_menu_fnc_addActionToClass"}) then
{
    private _action =
    [
        "MEAP_Architect_openAction",
        "Open Daidalos Mode",
        "",
        {
            if (missionNamespace getVariable ["MEAP_Architect_cameraOpen", false]) then
            {
                [] call MEAP_fnc_closeArchitectCamera;
            }
            else
            {
                [player] remoteExecCall ["MEAP_fnc_requestArchitectMode", 2];
            };
        },
        {
            ([_player] call MEAP_fnc_isArchitectKit)
            || ((missionNamespace getVariable ["MEAP_Architect_allowAdvancedEngineers", true])
                && {!isNil "ace_common_fnc_isEngineer"}
                && {[_player, 2] call ace_common_fnc_isEngineer})
            || {_player getVariable ["MEAP_isArchitect", false]}
        }
    ] call ace_interact_menu_fnc_createAction;

    ["CAManBase", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

    private _fobDepositAction =
    [
        "MEAP_Architect_fobDeposit",
        "Deposit FOB Currency",
        "",
        { ["DEPOSIT", player, _target] remoteExecCall ["MEAP_fnc_architectFobAction", 2]; },
        { _target isEqualType objNull && {typeOf _target isEqualTo (missionNamespace getVariable ["MEAP_Architect_fobHeartClass", ""])} }
    ] call ace_interact_menu_fnc_createAction;
    private _fobStatusAction =
    [
        "MEAP_Architect_fobStatus",
        "View FOB Funds",
        "",
        { ["STATUS", player, _target] remoteExecCall ["MEAP_fnc_architectFobAction", 2]; },
        { _target isEqualType objNull && {typeOf _target isEqualTo (missionNamespace getVariable ["MEAP_Architect_fobHeartClass", ""])} }
    ] call ace_interact_menu_fnc_createAction;
    private _fobProcessAction =
    [
        "MEAP_Architect_fobProcess",
        "Process FOB Materials",
        "",
        { ["PROCESS", player, _target] remoteExecCall ["MEAP_fnc_architectFobAction", 2]; },
        { _target isEqualType objNull && {typeOf _target isEqualTo (missionNamespace getVariable ["MEAP_Architect_fobHeartClass", ""])} }
    ] call ace_interact_menu_fnc_createAction;
    { ["All", 0, ["ACE_MainActions"], _x, true] call ace_interact_menu_fnc_addActionToClass; } forEach [_fobDepositAction, _fobStatusAction, _fobProcessAction];
};

if (hasInterface && {isNil "ace_interact_menu_fnc_createAction"}) then
{
    [{
        private _heartClass = missionNamespace getVariable ["MEAP_Architect_fobHeartClass", ""];
        if (_heartClass isEqualTo "") exitWith {};
        {
            if (typeOf _x isEqualTo _heartClass && {!(_x getVariable ["MEAP_Architect_vanillaFobActions", false])}) then
            {
                _x setVariable ["MEAP_Architect_vanillaFobActions", true];
                _x addAction
                [
                    "Deposit FOB Currency",
                    {params ["_target", "_caller"]; ["DEPOSIT", _caller, _target] remoteExecCall ["MEAP_fnc_architectFobAction", 2];},
                    nil,
                    1.5,
                    true,
                    true,
                    "",
                    "true",
                    5,
                    false
                ];
                _x addAction
                [
                    "View FOB Funds",
                    {params ["_target", "_caller"]; ["STATUS", _caller, _target] remoteExecCall ["MEAP_fnc_architectFobAction", 2];},
                    nil,
                    1.5,
                    true,
                    true,
                    "",
                    "true",
                    5,
                    false
                ];
                _x addAction
                [
                    "Process FOB Materials",
                    {params ["_target", "_caller"]; ["PROCESS", _caller, _target] remoteExecCall ["MEAP_fnc_architectFobAction", 2];},
                    nil,
                    1.5,
                    true,
                    true,
                    "",
                    "true",
                    5,
                    false
                ];
            };
        } forEach (allMissionObjects "All");
    }, 5] call CBA_fnc_addPerFrameHandler;
};

if (!isServer) exitWith {};

call MEAP_fnc_initializeArchitectState;
call MEAP_fnc_parseArchitectCompositions;

["CBA_settingsInitialized", {
    call MEAP_fnc_parseArchitectClassList;
}] call CBA_fnc_addEventHandler;

call MEAP_fnc_parseArchitectClassList;
[] call MEAP_fnc_architectFobTick;

addMissionEventHandler ["HandleDisconnect", {
    params ["_unit"];
    [_unit, true, _unit getVariable ["MEAP_Architect_serverCloseToken", ""]] call MEAP_fnc_closeArchitectMode;
    false
}];

addMissionEventHandler ["EntityKilled", {
    params ["_unit"];
    if (isPlayer _unit) then
    {
        [_unit, true, _unit getVariable ["MEAP_Architect_serverCloseToken", ""]] call MEAP_fnc_closeArchitectMode;
    };
}];

addMissionEventHandler ["EntityRespawned", {
    params ["_newUnit"];
    if (isPlayer _newUnit) then
    {
        private _key = [_newUnit] call MEAP_fnc_getArchitectKey;
        private _grants = missionNamespace getVariable ["MEAP_Architect_grants", createHashMap];
        private _granted = _grants getOrDefault [_key, false];
        _newUnit setVariable ["MEAP_isArchitect", _granted, true];
    };
}];

[{ 
    private _expiredUnits = [];
    {
        _y params ["_unit"];
        if (
            isNull _unit
            || {!alive _unit}
            || {!([_unit] call MEAP_fnc_isArchitectEligible)}
            || {!(missionNamespace getVariable ["MEAP_Architect_enabled", true])}
        ) then
        {
            _expiredUnits pushBack _unit;
        };
    } forEach MEAP_Architect_sessions;
    {
        [_x, true, _x getVariable ["MEAP_Architect_serverCloseToken", ""]] call MEAP_fnc_closeArchitectMode;
    } forEach _expiredUnits;

    private _expiredLocks = [];
    {
        _y params ["_unit", "_token"];
        private _session = MEAP_Architect_sessions getOrDefault [str owner _unit, []];
        if (
            isNull _unit
            || {!(_session isEqualTypeParams [objNull, ""])}
            || {(_session select 0) isNotEqualTo _unit}
            || {(_session select 1) isNotEqualTo _token}
        ) then
        {
            _expiredLocks pushBack _x;
        };
    } forEach MEAP_Architect_editLocks;
    {
        MEAP_Architect_editLocks deleteAt _x;
    } forEach _expiredLocks;
}, 2] call CBA_fnc_addPerFrameHandler;

[{[] call MEAP_fnc_architectFobTick;}, 5] call CBA_fnc_addPerFrameHandler;