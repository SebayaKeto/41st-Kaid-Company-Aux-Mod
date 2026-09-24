DI_fnc_sendCommand = {
    params ["_command",["_argument",""]];
    [player,_command,_argument] remoteExecCall ["DI_fnc_command",2];
};
DI_fnc_openPanel = {
    if (!hasInterface || {isNull player}) exitWith {};
    // owner/admin are server commands; authorization is rechecked on the server.
    if !((allCurators findIf {getAssignedCuratorUnit _x == player}) >= 0 || {serverCommandAvailable "#kick"}) exitWith {systemChat "Daara controls are for Zeus/admin."};
    disableSerialization;
    private _display = findDisplay 46 createDisplay "RscDisplayEmpty";
    private _back = _display ctrlCreate ["RscText",8900];
    _back ctrlSetPosition [0.1,0.13,0.8,0.85];_back ctrlSetBackgroundColor [0.025,0.035,0.04,0.97];_back ctrlCommit 0;
    private _title = _display ctrlCreate ["RscText",8901];
    _title ctrlSetPosition [0.12,0.14,0.76,0.05];_title ctrlSetText "DAARA INFERIOR - Tactical director";_title ctrlCommit 0;
    private _status = _display ctrlCreate ["RscStructuredText",8902];
    _status ctrlSetPosition [0.12,0.21,0.76,0.22];_status ctrlCommit 0;
    private _labels = [
        ["Enable infantry autonomy","active"], ["Shadow / stop new actions","shadow"],
        ["HOLD director","hold"], ["Resume from HOLD","resume"],
        ["Confirm step-off","stepoff"], ["Refresh status","status"],
        ["END operation","end"]
    ];
    {
        private _button = _display ctrlCreate ["RscButton",8910+_forEachIndex];
        _button ctrlSetPosition [0.12+0.39*(_forEachIndex mod 2),0.46+0.075*floor(_forEachIndex/2),0.36,0.06];
        _button ctrlSetText (_x select 0);
        _button setVariable ["DI_command",_x select 1];
        _button ctrlAddEventHandler ["ButtonClick",{params ["_control"];private _command = _control getVariable "DI_command";
            if (_command == "end" && {diag_tickTime > (_control getVariable ["DI_confirmUntil",-1])}) exitWith {
                _control setVariable ["DI_confirmUntil",diag_tickTime+5];_control ctrlSetText "Click again to END";
                [_control] spawn {params ["_b"];sleep 5;if (!isNull _b) then {_b ctrlSetText "END operation"}};
            };
            [_command] call DI_fnc_sendCommand}];
        _button ctrlCommit 0;
    } forEach _labels;
    private _complete = _display ctrlCreate ["RscButton",8921];
    _complete ctrlSetPosition [0.12,0.77,0.76,0.05];_complete ctrlSetText "Choose captured objective on map";_complete ctrlCommit 0;
    _complete ctrlAddEventHandler ["ButtonClick",{
        (ctrlParent (_this select 0)) closeDisplay 1;
        [] spawn {uiSleep 0.1;[] call DI_fnc_objectiveMapPicker};
    }];
    private _note = _display ctrlCreate ["RscStructuredText",8922];
    _note ctrlSetPosition [0.12,0.84,0.76,0.10];
    _note ctrlSetStructuredText parseText "Infantry only. Air, armor, Munificent/HMP, artillery and sabotage remain manual. HOLD stops director tasks; existing AI can still defend itself. Choose the captured objective on the map; wait for mission confirmation. END stops the director for this session; existing AI can still defend itself. ESC closes this panel.";
    _note ctrlCommit 0;
    [_display] spawn {
        disableSerialization;
        params ["_display"];
        while {!isNull _display} do {
            (_display displayCtrl 8902) ctrlSetStructuredText parseText (missionNamespace getVariable ["DI_statusText","Waiting for server..."]);
            sleep 1;
        };
    };
};
DI_fnc_possessionReporter = {
    // Only this client's real player/control link is sampled. No global scan,
    // synthesized control, AI order or direct ownership mutation.
    private _previousGroup=grpNull;
    private _nextRefresh=0;
    while {true} do {
        private _group=grpNull;
        if (!isNull player && {local player} && {isRemoteControlling player}) then {
            private _unit=remoteControlled player;
            if (!isNull _unit) then {
                private _candidate=group _unit;
                if (!isNull _candidate && {_candidate getVariable ["DI_operation",""] == (missionNamespace getVariable ["DI_operation","unset"])}) then {_group=_candidate};
            };
        };
        if (_group!=_previousGroup) then {
            if (!isNull _previousGroup) then {
                ["POSSESSION_TAKEOVER_REPORT",["end",netId _previousGroup]] call DI_fnc_log;
                ["manual",_previousGroup] call DI_fnc_sendCommand;
            };
            if (!isNull _group) then {
                ["POSSESSION_TAKEOVER_REPORT",["start",netId _group]] call DI_fnc_log;
                ["manual",_group] call DI_fnc_sendCommand;
                _nextRefresh=diag_tickTime+60;
            };
            _previousGroup=_group;
        } else {
            if (!isNull _group && {diag_tickTime>=_nextRefresh}) then {
                ["POSSESSION_TAKEOVER_REPORT",["refresh",netId _group]] call DI_fnc_log;
                ["manual",_group] call DI_fnc_sendCommand;
                _nextRefresh=diag_tickTime+60;
            };
        };
        sleep 0.25;
    };
};
DI_fnc_clientStart = {
    waitUntil {sleep 1;!isNull player && {!isNull findDisplay 46}};
    if (!isNil "CBA_fnc_addKeybind") then {
        ["Daara Inferior","DI_panel",["Open Daara director","Zeus/admin rehearsal controls"],
            {[] call DI_fnc_openPanel;true},{},[66,[true,true,false]]] call CBA_fnc_addKeybind;
    };
    [] spawn DI_fnc_possessionReporter;
    // Curator events affect only DI-owned groups, without adding ZEN module slots.
    while {true} do {
        {
            if (getAssignedCuratorUnit _x != player || {_x getVariable ["DI_hooks",false]}) then {continue};
            _x setVariable ["DI_hooks",true];
            // Engine event name and signature: CuratorWaypointPlaced.
            // Keep cancellation in the shared BURNS broker; DI only leases control.
            private _waypointHook = _x addEventHandler ["CuratorWaypointPlaced",{
                params ["_curator","_group","_waypointID"];
                if (isNull _group || {_group getVariable ["DI_operation",""] != (missionNamespace getVariable ["DI_operation","unset"])}) exitWith {};
                ["CURATOR_WAYPOINT_PLACED",[netId _group,_waypointID]] call DI_fnc_log;
                ["manual",_group] call DI_fnc_sendCommand;
            }];
            _x setVariable ["DI_waypointHookId",_waypointHook];
            ["CURATOR_HOOK_REGISTERED",["CuratorWaypointPlaced",_waypointHook]] call DI_fnc_log;
            _x addEventHandler ["CuratorObjectEdited",{
                params ["_curator","_object"];
                if (_object isKindOf "CAManBase") then {["manual",group _object] call DI_fnc_sendCommand};
            }];
        } forEach allCurators;
        sleep 3;
    };
};
