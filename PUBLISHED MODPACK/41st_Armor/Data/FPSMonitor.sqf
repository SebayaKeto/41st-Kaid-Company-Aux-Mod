#define PREFIX fst
#define COMPONENT stat
#include "\x\cba\addons\main\script_macros_common.hpp"

params [
    ["_clientName", "", [""]],
    ["_refreshDelay", 10, [0]],
    ["_position", 0, [0]]
];

GVAR(MapFpsPos) = 0;
private _markerSpacing = worldSize * 0.016276;
GVAR(fpsMarker) = createMarker [format ["fpsmarker%1", _clientName], [_markerSpacing + worldSize, _markerSpacing + (_markerSpacing * _position)]];
if (GVAR(MapFpsPos) == 1) then {
    GVAR(fpsMarker) setMarkerPos [_markerSpacing, _markerSpacing + (_markerSpacing * _position)];
};
GVAR(fpsMarker) setMarkerType "mil_start";
GVAR(fpsMarker) setMarkerSize [0.7, 0.7];
GVAR(clientName) = _clientName;

[{
    private _curFps = diag_fps;
    private _localUnits = count (allUnits select { local _x });
    GVAR(fpsMarker) setMarkerColor "ColorGREEN";
    if (_curFps < 30) then {
        GVAR(fpsMarker) setMarkerColor "ColorYELLOW";
    };
    if (_curFps < 20) then {
        GVAR(fpsMarker) setMarkerColor "ColorORANGE";
    };
    if (_curFps < 10) then {
        GVAR(fpsMarker) setMarkerColor "ColorRED";
    };
    private _roundedFps = (round (_curFps * 100)) / 100;
    GVAR(fpsMarker) setMarkerText format ["%1: %2 fps, %3 local units", GVAR(clientName), _roundedFps, _localUnits];
}, _refreshDelay] call CBA_fnc_addPerFrameHandler;
