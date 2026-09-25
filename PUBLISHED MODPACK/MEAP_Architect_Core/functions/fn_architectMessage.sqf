params [["_message", "", [""]]];

if (isRemoteExecuted && {remoteExecutedOwner != 2}) exitWith {};
if (!hasInterface || {_message isEqualTo ""}) exitWith {};

[format ["MEAP Daidalos: %1", _message]] call CBA_fnc_notify;