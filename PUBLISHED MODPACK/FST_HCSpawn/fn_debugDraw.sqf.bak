// FST_HCSpawn_fnc_debugDraw
// Client-side. Toggles Draw3D showing HC ownership icons above AI leaders.
// Queries server for HC data on enable to guarantee freshness.

params [["_enable", false]];

FST_HC_Debugging = _enable;

if (_enable) then {
    systemChat "[FST] Debug draw ON";

    // Snapshot HC IDs from server (publicVariable should have them but be safe)
    private _hcIds = missionNamespace getVariable ["FST_HC_Ids", []];
    missionNamespace setVariable ["FST_HC_DebugIds", +_hcIds];

    FST_HC_DebugDrawHandle = addMissionEventHandler ["Draw3D", {
        private _hcIds = missionNamespace getVariable ["FST_HC_DebugIds", []];

        {
            if (isNull _x || {units _x isEqualTo []} || {isPlayer leader _x}) then { continue };

            private _leader = leader _x;
            private _color = [];
            private _text = "";

            // Check Zeus held
            private _heldBy = _x getVariable ["FST_HC_heldBy", -1];
            if (_heldBy != -1) then {
                if (_heldBy == clientOwner) then {
                    _color = [0.2, 0.5, 1, 0.7];
                    _text = "Zeus (You)";
                } else {
                    _color = [1, 1, 0, 0.7];
                    _text = "Zeus (Other)";
                };
            };

            if (_color isEqualTo []) then {
                private _ownerID = owner _leader;
                private _found = false;
                {
                    if (_x == _ownerID) exitWith {
                        _color = [0.2, 0.8, 0.2, 0.7];
                        _text = format ["HC%1", _forEachIndex + 1];
                        _found = true;
                    };
                } forEach _hcIds;

                if (!_found) then {
                    _color = [1, 0.5, 0, 0.5];
                    _text = "Server";
                };
            };

            drawIcon3D [
                "\a3\ui_f\data\map\vehicleicons\iconvirtual_ca.paa",
                _color,
                getPosATL _leader vectorAdd [0, 0, 2],
                1, 1, 0,
                format ["%1 (%2)", _text, count units _x],
                0.5, 0.025, "EtelkaNarrowMediumPro", "center", false
            ];
        } forEach allGroups;
    }];

    // Refresh HC IDs every 10s in case HCs connect/disconnect
    FST_HC_DebugRefreshHandle = [{
        missionNamespace setVariable ["FST_HC_DebugIds", +(missionNamespace getVariable ["FST_HC_Ids", []])];
    }, 10, []] call CBA_fnc_addPerFrameHandler;

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
};
