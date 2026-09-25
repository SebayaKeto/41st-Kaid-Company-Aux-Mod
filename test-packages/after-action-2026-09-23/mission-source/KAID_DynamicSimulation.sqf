// Server-owned enrollment. Active BURNS/QRF and mounted groups stay awake.
if (!isServer) exitWith {};
if (missionNamespace getVariable ["KAID_DynSimStarted", false]) exitWith {};
KAID_DynSimStarted = true;
KAID_DynSim = true;
[] spawn {
    sleep 30;
    enableDynamicSimulationSystem true;
    "Group" setDynamicSimulationDistance 800;
    while {true} do {
        {
            private _group = _x;
            if (isNull _group || {count units _group == 0} || {side _group == sideLogic}) then {continue};
            private _managed = _group getVariable ["KAID_dynManaged", false];
            private _active = (_group getVariable ["FST_HC_keepActive", false])
                || {(!isNil "FST_HCSpawn_fnc_burnsRole") && {(units _group findIf {([_x] call FST_HCSpawn_fnc_burnsRole) == "webknight"}) >= 0}}
                || {(units _group findIf {isPlayer _x || {vehicle _x != _x}}) >= 0}
                || {(_group getVariable ["FST_HC_heldBy", -1]) != -1};
            if (_active) then {
                if (dynamicSimulationEnabled _group) then {_group enableDynamicSimulation false};
                _group setVariable ["KAID_dynManaged", false];
                continue;
            };
            if (!KAID_DynSim) then {
                if (_managed) then {
                    _group enableDynamicSimulation false;
                    _group setVariable ["KAID_dynManaged", false];
                };
                continue;
            };
            // Existing manual KAID_dyn=true exemptions remain supported.
            if (!(_group getVariable ["KAID_dyn", false]) && {!dynamicSimulationEnabled _group}) then {
                _group enableDynamicSimulation true;
                _group setVariable ["KAID_dynManaged", true];
            };
        } forEach allGroups;
        sleep 10;
    };
};
