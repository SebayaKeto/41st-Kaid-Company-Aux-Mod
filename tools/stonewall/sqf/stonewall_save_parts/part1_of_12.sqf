localNamespace setVariable ["stonewall_code", "" + "if (!isServer) exitWith { systemChat ""Stonewall: run this on the SERVER (SERVER EXEC).""; };
private _req = if (isRemoteExecuted) then { remoteExecutedOwner } else { 2 };
private _reply = {
params [""_msg""];
private _viaCba = isClass (configFile >> ""CfgPatches"" >> ""FST_Stonewall"") && {!isNil ""CBA_fnc_ownerEvent""};
if (_req > 2) then {
if (_viaCba) then { [""FST_stonewall_done"", [_msg], _req] call CBA_fnc_ownerEvent; } else { [_msg] remoteExec [""systemChat"", _req]; };
} else {
if (hasInterface) then {
if (_viaCba) then { [""FST_stonewall_done"", [_msg]] call CBA_fnc_localEvent; } else { systemChat _msg; };
};
};
};
if (_req > 2 && {!((admin _req) == 2
|| {(allCurators findIf { private _u = getAssignedCuratorUnit _x; !isNull _u && {owner _u == _req} }) >= 0})}) exitWith {
diag_log format [""STONEWALL: rejected save request from owner %1 (not a curator or admin)"", _req];
"];
