/*
    FST_fnc_serverSpawnVehicle
    Runs on the server only, via remoteExec target 2 from FST_fnc_spawnVehicle.
    params ["_className", "_pos", "_dir", "_storeKey"]
*/
params ["_className", "_pos", "_dir", "_storeKey"];
private _vehicle = _className createVehicle _pos;
_vehicle setDir _dir;
_vehicle setPosATL _pos;
missionNamespace setVariable [_storeKey, _vehicle, true];
