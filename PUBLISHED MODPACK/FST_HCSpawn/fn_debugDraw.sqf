// FST_HCSpawn_fnc_debugDraw
// Client-side. Toggles Draw3D showing server-confirmed HC ownership above AI leaders.
// Shift+F3 calls this locally. The client periodically requests a server snapshot;
// the Draw3D handler only renders that snapshot, so it does not guess locality.

params [["_enable", false]];

FST_HC_Debugging = _enable;
missionNamespace setVariable ["FST_HC_Debugging", _enable];

if (_enable) then {
    systemChat "[FST] Debug draw ON — requesting server ownership snapshot.";

    // Avoid duplicate handlers if the keybind is spammed.
    if (!isNil "FST_HC_DebugDrawHandle") then {
        removeMissionEventHandler ["Draw3D", FST_HC_DebugDrawHandle];
        FST_HC_DebugDrawHandle = nil;
    };
    if (!isNil "FST_HC_DebugRefreshHandle") then {
        [FST_HC_DebugRefreshHandle] call CBA_fnc_removePerFrameHandler;
        FST_HC_DebugRefreshHandle = nil;
    };

    missionNamespace setVariable ["FST_HC_DebugSnapshot", []];

    // Immediate request, then refresh frequently while debug is enabled.
    ["FST_HC_evt_debugSnapshotRequest", [clientOwner]] call CBA_fnc_serverEvent;

    FST_HC_DebugDrawHandle = addMissionEventHandler ["Draw3D", {
        private _snapshot = missionNamespace getVariable ["FST_HC_DebugSnapshot", []];

        {
            _x params ["_grp", "_label", "_state", "_ownerID", "_unitCount", "_tracked", "_pending", "_heldBy"];
            if (isNull _grp || {count units _grp == 0}) then { continue };

            private _leader = leader _grp;
            if (isNull _leader || {isPlayer _leader}) then { continue };

            private _color = switch (_state) do {
                case "hc":      { [0.20, 0.85, 0.25, 0.75] };
                case "pending": { [1.00, 0.85, 0.20, 0.85] };
                case "zeus":    { [0.25, 0.55, 1.00, 0.80] };
                default          { [1.00, 0.45, 0.15, 0.70] };
            };

            private _suffix = if (_tracked) then { "tracked" } else { "untracked" };
            drawIcon3D [
                "\a3\ui_f\data\map\vehicleicons\iconvirtual_ca.paa",
                _color,
                getPosATL _leader vectorAdd [0, 0, 2.2],
                1,
                1,
                0,
                format ["%1 | %2u | owner %3 | %4", _label, _unitCount, _ownerID, _suffix],
                0.5,
                0.025,
                "EtelkaNarrowMediumPro",
                "center",
                false
            ];
        } forEach _snapshot;
    }];

    FST_HC_DebugRefreshHandle = [{
        if !(missionNamespace getVariable ["FST_HC_Debugging", false]) exitWith {};
        ["FST_HC_evt_debugSnapshotRequest", [clientOwner]] call CBA_fnc_serverEvent;
    }, 2, []] call CBA_fnc_addPerFrameHandler;

} else {
    systemChat "[FST] Debug draw OFF";
    if (!isNil "FST_HC_DebugDrawHandle") then {
        removeMissionEventHandler ["Draw3D", FST_HC_DebugDrawHandle];
        FST_HC_DebugDrawHandle = nil;
    };
    if (!isNil "FST_HC_DebugRefreshHandle") then {
        [FST_HC_DebugRefreshHandle] call CBA_fnc_removePerFrameHandler;
        FST_HC_DebugRefreshHandle = nil;
    };
    missionNamespace setVariable ["FST_HC_DebugSnapshot", []];
};
