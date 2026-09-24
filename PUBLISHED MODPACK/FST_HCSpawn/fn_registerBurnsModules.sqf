if (!hasInterface) exitWith {};
if (missionNamespace getVariable ["BURNS_modulesRegistered",false]) exitWith {};
BURNS_modulesRegistered=true;
// Independent of HC management, including curator assignment after mission start.
// This runs once per second per Zeus client; it never walks AI or terrain objects.
[{
    if (isNull player) exitWith {};
    {
        if (getAssignedCuratorUnit _x==player && {!(_x getVariable ["BURNS_waypointHook",false])}) then {
            _x setVariable ["BURNS_waypointHook",true];
            _x addEventHandler ["CuratorWaypointPlaced",{_this call FST_HCSpawn_fnc_burnsCuratorWaypoint}];
        };
    } forEach allCurators;
},1,[]] call CBA_fnc_addPerFrameHandler;
private _icon="\a3\Modules_F_Curator\Data\iconCurator_ca.paa";
// BURNS task modules: same handler as the unit/group right-click actions.
["BURNS", "Task Rush", {
    params ["_pos",["_object",objNull]];
    ["rush",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,false] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Task Hunt", {
    params ["_pos",["_object",objNull]];
    ["hunt",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,false] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Task Ambush (BX)", {
    params ["_pos",["_object",objNull]];
    ["ambush",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,false] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Task Creep", {
    params ["_pos",["_object",objNull]];
    ["creep",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,false] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Task AAT Section Assault (Test)", {
    params ["_pos",["_object",objNull]];
    ["armor_assault",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,true] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Task Assault", {
    params ["_pos",["_object",objNull]];
    ["assault",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,!isNull _object] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Task Retreat", {
    params ["_pos",["_object",objNull]];
    ["retreat",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,!isNull _object] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Task CQB", {
    params ["_pos",["_object",objNull]];
    ["cqb",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,false] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Task Garrison", {
    params ["_pos",["_object",objNull]];
    ["garrison",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,false] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Task Camp", {
    params ["_pos",["_object",objNull]];
    ["camp",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,false] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Task Defend", {
    params ["_pos",["_object",objNull]];
    ["defend",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,false] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Task Patrol", {
    params ["_pos",["_object",objNull]];
    ["patrol",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,false] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Task Reset", {
    params ["_pos",["_object",objNull]];
    ["reset",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,!isNull _object] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Set Task Target", {
    params ["_pos",["_object",objNull]];
    ["target",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,!isNull _object] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Register Artillery", {
    params ["_pos",["_object",objNull]];
    ["artillery_register",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,!isNull _object] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Unregister Artillery", {
    params ["_pos",["_object",objNull]];
    ["artillery_remove",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,!isNull _object] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Artillery Fire Mission", {
    params ["_pos",["_object",objNull]];
    ["artillery_fire",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,!isNull _object] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Enable Unit AI", {
    params ["_pos",["_object",objNull]];
    ["enable_unit",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,!isNull _object] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Disable Unit AI", {
    params ["_pos",["_object",objNull]];
    ["disable_unit",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,!isNull _object] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Enable Group AI", {
    params ["_pos",["_object",objNull]];
    ["enable_group",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,!isNull _object] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Disable Group AI", {
    params ["_pos",["_object",objNull]];
    ["disable_group",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,!isNull _object] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Enable Radio", {
    params ["_pos",["_object",objNull]];
    ["radio_on",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,!isNull _object] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Disable Radio", {
    params ["_pos",["_object",objNull]];
    ["radio_off",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,!isNull _object] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Enable Reinforcement", {
    params ["_pos",["_object",objNull]];
    ["reinforce_on",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,!isNull _object] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
["BURNS", "Disable Reinforcement", {
    params ["_pos",["_object",objNull]];
    ["reinforce_off",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,!isNull _object] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;

["BURNS", "Configure Group AI", {
    params ["_pos",["_object",objNull]];
    ["configure",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,!isNull _object] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;

["BURNS", "Set Radio", {
    params ["_pos",["_object",objNull]];
    ["set_radio",curatorSelected select 1,([_object]+(curatorSelected select 0)),ASLToATL _pos,!isNull _object] call FST_HCSpawn_fnc_burnsDialog;
}, _icon] call FST_HCSpawn_fnc_registerNativeModule;
