if (missionNamespace getVariable ["DI_booted",false]) exitWith {};
DI_booted = true;
call compile preprocessFileLineNumbers "DI\config.sqf";
call compile preprocessFileLineNumbers "DI\objectives.sqf";
{
    call compile preprocessFileLineNumbers ("DI\" + _x + ".sqf");
} forEach ["common","map_intent","pressure","admission","worker","server","client","objective_picker"];
DI_fnc_createGroupLocal = compile preprocessFileLineNumbers "DI\vendor_createGroupLocal.sqf";
if (isServer) then {[] spawn DI_fnc_serverStart};
if (!hasInterface && {!isServer}) then {[] spawn DI_fnc_workerHeartbeat;[] spawn DI_fnc_workerHooks};
if (hasInterface) then {[] spawn DI_fnc_clientStart;[] spawn DI_fnc_mapReporter};
diag_log format ["[DAARA] BOOT version=%1 owner=%2 server=%3 interface=%4",DI_version,clientOwner,isServer,hasInterface];
