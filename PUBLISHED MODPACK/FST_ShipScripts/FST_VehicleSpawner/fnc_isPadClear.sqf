/*
    FST_fnc_isPadClear
    params ["_pad", "_statusLbl"]
*/
params ["_pad", "_statusLbl"];
private _preview = uiNamespace getVariable ["GUI_PreviewVehicle", objNull];
private _nearVehicles = (getPosASL _pad) nearEntities [["LandVehicle", "Air", "Ship"], 10];
_nearVehicles = _nearVehicles select { alive _x && _x != _preview };
if (count _nearVehicles > 0) then {
    _statusLbl ctrlSetText format ["> DEPLOY REJECTED — %1 UNIT(S) OBSTRUCTING LANDING ZONE.", count _nearVehicles];
    _statusLbl ctrlSetTextColor [0.95, 0.30, 0.30, 1.0];
    _statusLbl ctrlCommit 0;
    false
} else {
    true
}
