// FST_stonewall_fnc_removeKeepArea
// Server-side. Deletes the Stonewall keep area covering a position (the one whose centre is nearest) and its label.
// Zen area markers are removed with Zen's own marker tools.
// Zeus module: [pos] remoteExecCall ["FST_stonewall_fnc_removeKeepArea", 2]
// Arguments: 0: position <ARRAY>
// Returns: name of the removed area, "" if none or refused <STRING>

if (!isServer) exitWith { "" };
(["remove keep area"] call FST_stonewall_fnc_isAuthorized) params ["_ok", "_req"];
if (!_ok) exitWith { "" };

params [["_pos", [0, 0, 0], [[]]]];

private _best = "";
private _bestD = 1e10;
{
    if ((toLower _x) find "stonewall_keep_" == 0) then {
        private _size = markerSize _x;
        if (_pos inArea [markerPos _x, _size select 0, _size select 1, markerDir _x, markerShape _x == "RECTANGLE"]) then {
            private _d = _pos distance2D (markerPos _x);
            if (_d < _bestD) then { _bestD = _d; _best = _x; };
        };
    };
} forEach allMapMarkers;

private _name = "";
if (_best != "") then {
    _name = markerText _best;
    deleteMarker ("stonewall_label_" + (_best select [15]));
    deleteMarker _best;
};
private _msg = [format ["Stonewall: removed keep area '%1'", _name], "Stonewall: place this inside a Stonewall keep area"] select (_best == "");
if (_req > 2) then { ["FST_stonewall_done", [_msg], _req] call CBA_fnc_ownerEvent; }
else { if (hasInterface) then { ["FST_stonewall_done", [_msg]] call CBA_fnc_localEvent; }; };   // listen-server host
_name
