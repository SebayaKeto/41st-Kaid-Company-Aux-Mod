// FST_HCSpawn_fnc_debugDraw
// Client-side. Toggles Draw3D event handler showing ownership icons above AI leaders.
//
// Colors:
//   Green  — on HC
//   Blue   — held by Zeus (your groups)
//   Yellow — held by another Zeus
//   Orange — on server (no HC / untransferred)
//   Red    — untracked
//
// Arguments:
//   0: BOOL — enable/disable

params [["_enable", false]];

FST_HC_Debugging = _enable;

if (_enable) then {
    systemChat "[FST] Debug draw ON";

    FST_HC_DebugDrawHandle = addMissionEventHandler ["Draw3D", {
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

            // Check HC assignment via tracked variable (set by server in trackGroup)
            if (_color isEqualTo []) then {
                private _hcIdx = _x getVariable ["FST_HC_onHC", -1];
                if (_hcIdx >= 0) then {
                    _color = [0.2, 0.8, 0.2, 0.7];
                    _text = format ["HC%1", _hcIdx + 1];
                } else {
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
} else {
    systemChat "[FST] Debug draw OFF";

    if (!isNil "FST_HC_DebugDrawHandle") then {
        removeMissionEventHandler ["Draw3D", FST_HC_DebugDrawHandle];
        FST_HC_DebugDrawHandle = nil;
    };
};
