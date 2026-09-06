/*
    FST_fnc_destroyPadCamera
*/
call FST_fnc_removePreviewVehicle;
private _cam = uiNamespace getVariable ["GUI_PadCam", objNull];
if (!isNull _cam) then {
    _cam cameraEffect ["TERMINATE", "BACK"];
    camDestroy _cam;
    uiNamespace setVariable ["GUI_PadCam", objNull];
};
private _script = uiNamespace getVariable ["GUI_PadCamScript", scriptNull];
if (!isNull _script) then {
    terminate _script;
    uiNamespace setVariable ["GUI_PadCamScript", scriptNull];
};
private _light = uiNamespace getVariable ["GUI_PreviewLight", objNull];
if (!isNull _light) then {
    deleteVehicle _light;
    uiNamespace setVariable ["GUI_PreviewLight", objNull];
};
private _display = uiNamespace getVariable ["GUI_Display", displayNull];
if (!isNull _display) then {
    (_display displayCtrl 9811) ctrlSetText "NO PAD SELECTED";
    (_display displayCtrl 9812) ctrlSetText "FEED OFFLINE";
    (_display displayCtrl 9812) ctrlSetTextColor [0.55, 0.30, 0.30, 1.0];
};
