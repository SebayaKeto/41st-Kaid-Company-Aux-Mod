/*
    FST_fnc_removePreviewVehicle
*/
private _prev = uiNamespace getVariable ["GUI_PreviewVehicle", objNull];
if (!isNull _prev) then {
    deleteVehicle _prev;
    uiNamespace setVariable ["GUI_PreviewVehicle", objNull];
};
