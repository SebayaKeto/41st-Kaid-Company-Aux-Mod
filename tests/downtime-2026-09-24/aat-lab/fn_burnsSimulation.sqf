// Only explicit tasks opt a group out of dynamic sleep; Reset restores it.
params ["_group",["_active",true]];
if (isNull _group) exitWith {};
if (!isServer) exitWith {["BURNS_simulation",[_group,_active]] call CBA_fnc_serverEvent};
if ([_group] call FST_HCSpawn_fnc_isProtectedVehicleGroup) exitWith {};
if (_active) then {
    if (isNil {_group getVariable "BURNS_dynamicRestore"}) then {
        _group setVariable ["BURNS_dynamicRestore",dynamicSimulationEnabled _group,true];
    };
    if (dynamicSimulationEnabled _group) then {_group enableDynamicSimulation false};
} else {
    if (_group getVariable ["BURNS_dynamicRestore",false] && {!(_group getVariable ["FST_HC_keepActive",false])}) then {_group enableDynamicSimulation true};
    _group setVariable ["BURNS_dynamicRestore",nil,true];
};
