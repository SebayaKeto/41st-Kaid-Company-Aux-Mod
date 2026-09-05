/*
    FST_fnc_updatePadCamera
*/
call FST_fnc_destroyPadCamera;

private _display  = uiNamespace getVariable ["GUI_Display", displayNull];
private _combo    = _display displayCtrl 9951;
private _selIdx   = lbCurSel _combo;
private _padList  = uiNamespace getVariable ["GUI_PadList", []];
private _padCache = uiNamespace getVariable ["GUI_PadCache", []];

if (_selIdx < 0 || _selIdx >= count _padCache) exitWith {};
private _pad = _padCache select _selIdx;
if (isNull _pad) exitWith {};

private _padName = (_padList select _selIdx) select 0;
private _padPos  = getPosASL _pad;

private _light = "#lightpoint" createVehicleLocal [(_padPos select 0), (_padPos select 1), (_padPos select 2) + 8];
_light setLightBrightness 8;
_light setLightDaylight true;
_light setLightColor [1.0, 1.0, 1.0];
_light setLightAmbient [0.1, 0.1, 0.1];
uiNamespace setVariable ["GUI_PreviewLight", _light];

private _cam = "camera" camCreate _padPos;
_cam camSetFOV 0.7;
_cam camSetTarget _padPos;
_cam cameraEffect ["INTERNAL", "BACK", "PadCamRT"];
_cam camCommit 0;

uiNamespace setVariable ["GUI_PadCam", _cam];

(_display displayCtrl 9811) ctrlSetText format ["// %1", toUpper _padName];
(_display displayCtrl 9812) ctrlSetText "FEED ACTIVE";
(_display displayCtrl 9812) ctrlSetTextColor [0.20, 0.90, 0.30, 1.0];

private _script = [_cam, _padPos] spawn {
    params ["_cam", "_padPos"];
    private _angle = 0;
    _cam camSetTarget _padPos;
    while {!isNull _cam && {!isNull (findDisplay 9900)}} do {
        _angle = (_angle + 0.63) % 360;
        private _x = (_padPos select 0) + (20 * sin _angle);
        private _y = (_padPos select 1) + (20 * cos _angle);
        private _z = (_padPos select 2) + 15;
        _cam setPosASL [_x, _y, _z];
        _cam camCommit 0;
        sleep 0.07;
    };
};

uiNamespace setVariable ["GUI_PadCamScript", _script];
call FST_fnc_spawnPreviewVehicle;
