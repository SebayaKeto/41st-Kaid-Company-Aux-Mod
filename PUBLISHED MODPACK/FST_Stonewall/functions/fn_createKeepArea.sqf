// FST_stonewall_fnc_createKeepArea
// Server-side. Marks a base to carry over: a global area marker "stonewall_keep_*" (read by the save) plus a label.
// Created on the SERVER so the markers survive the Zeus disconnecting or relogging.
// Zeus module: [pos, name, radius, square, dir] remoteExecCall ["FST_stonewall_fnc_createKeepArea", 2]
// Arguments: 0: position <ARRAY>, 1: name <STRING>, 2: radius / half-size m <NUMBER>,
//            3: square <BOOL> (default false), 4: direction deg <NUMBER> (default 0)
// Returns: area marker name <STRING> ("" if refused)

if (!isServer) exitWith { "" };
(["keep area"] call FST_stonewall_fnc_isAuthorized) params ["_ok", "_req"];
if (!_ok) exitWith { "" };

params [["_pos", [0, 0, 0], [[]]], ["_name", "Base", [""]], ["_radius", 60, [0]], ["_square", false, [false]], ["_dir", 0, [0]]];
_radius = (_radius max 5) min 2000;
if (_name isEqualTo "") then { _name = "Base"; };

private _n = localNamespace getVariable ["FST_stonewall_keepCounter", 0];
localNamespace setVariable ["FST_stonewall_keepCounter", _n + 1];
private _id = format ["%1_%2", _req, _n];

private _m = createMarker ["stonewall_keep_" + _id, _pos];
_m setMarkerShape (["ELLIPSE", "RECTANGLE"] select _square);
_m setMarkerSize [_radius, _radius];
_m setMarkerDir _dir;
_m setMarkerBrush "Border";
_m setMarkerColor "ColorGreen";
_m setMarkerText _name;

private _l = createMarker ["stonewall_label_" + _id, _pos];
_l setMarkerType "mil_flag";
_l setMarkerColor "ColorGreen";
_l setMarkerText format ["Stonewall: %1", _name];

private _msg = format ["Stonewall: keep area '%1' (%2 m)", _name, round _radius];
if (_req > 2) then { ["FST_stonewall_done", [_msg], _req] call CBA_fnc_ownerEvent; }
else { if (hasInterface) then { ["FST_stonewall_done", [_msg]] call CBA_fnc_localEvent; }; };   // listen-server host
_m
