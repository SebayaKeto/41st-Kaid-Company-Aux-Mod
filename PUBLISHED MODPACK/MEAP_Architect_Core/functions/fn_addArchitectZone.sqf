private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
if (count _state == 0 || {!(_state getOrDefault ["previewValid", false])}) exitWith
{
    ["Aim at a valid position before adding a private zone."] call MEAP_fnc_architectMessage;
};

private _zones = _state getOrDefault ["zones", []];
if (count _zones >= 8) exitWith
{
    ["A maximum of eight private zones can be displayed."] call MEAP_fnc_architectMessage;
};

private _zoneNumber = (_state getOrDefault ["zoneCounter", 0]) + 1;
_state set ["zoneCounter", _zoneNumber];
_zones pushBack
[
    +(_state get "previewPosition"),
    missionNamespace getVariable ["MEAP_Architect_zoneRadius", 15],
    format ["ZONE %1", _zoneNumber]
];
_state set ["zones", _zones];
[format ["Private construction zone %1 added.", _zoneNumber]] call MEAP_fnc_architectMessage;