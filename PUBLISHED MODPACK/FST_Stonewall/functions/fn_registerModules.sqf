// FST_stonewall_fnc_registerModules
// Client-side. Zen custom modules under "41st Stonewall".

if (!hasInterface) exitWith {};
if (isNil "zen_custom_modules_fnc_register") exitWith {};
if (missionNamespace getVariable ["FST_stonewall_modulesRegistered", false]) exitWith {};
FST_stonewall_modulesRegistered = true;

private _cat = "41st Stonewall";

[_cat, "Keep Area (carry base over)", {
    params ["_posASL"];
    private _pos = ASLToAGL _posASL;
    ["Stonewall: keep this base", [
        ["EDIT", ["Base name", "Shown on the map and used as the Eden layer name in the next mission"], ["FOB"]],
        ["TOOLBOX", "Shape", [0, 1, 2, ["Circle", "Square"]]],
        ["SLIDER:RADIUS", ["Radius / half-width (m)", "Everything built inside is carried over"], [10, 400, 60, 0, _pos, [0, 0.8, 0, 0.7]]],
        ["SLIDER", ["Rotation (square only)", "Degrees clockwise"], [0, 359, 0, 0]]
    ], {
        params ["_values", "_pos"];
        _values params ["_name", "_shape", "_radius", "_dir"];
        if (_name isEqualTo "") then { _name = "Base"; };
        // created on the server, so the area survives this Zeus disconnecting; the server confirms by message
        ["Keep Area", 20, "If this mission whitelists remoteExec, mark the base with a map marker 'KEEP <radius> <name>' instead."]
            call FST_stonewall_fnc_awaitReply;
        [_pos, _name, _radius, _shape == 1, _dir] remoteExecCall ["FST_stonewall_fnc_createKeepArea", 2];
    }, {}, _pos] call zen_dialog_fnc_create;
}, "\a3\ui_f\data\map\markers\military\flag_ca.paa"] call zen_custom_modules_fnc_register;

[_cat, "Remove Keep Area", {
    params ["_posASL"];
    ["Remove Keep Area", 20, "If this mission whitelists remoteExec, delete the keep marker from the map instead."]
        call FST_stonewall_fnc_awaitReply;
    [ASLToAGL _posASL] remoteExecCall ["FST_stonewall_fnc_removeKeepArea", 2];
}, "\a3\ui_f\data\map\markers\military\destroy_ca.paa"] call zen_custom_modules_fnc_register;

[_cat, "Save Mission", {
    private _zen = missionNamespace getVariable ["FST_stonewall_zenAreas", true];
    private _keep = {
        private _l = toLower _x;
        private _w = markerText _x splitString " ";
        (_l find "stonewall_keep_" == 0) || {_zen && {_l find "zen_area_markers_" == 0}}
            || {count _w > 1 && {toUpper (_w select 0) == "KEEP"} && {parseNumber (_w select 1) > 0}}
    } count allMapMarkers;
    ["Stonewall: save this mission", [
        ["TOOLBOX", ["Save", "Everything built is the full record; keep areas only is smaller"], [0, 1, 2, ["Everything built", "Keep areas only"]]],
        ["TOOLBOX:YESNO", [format ["Save now? (%1 keep areas marked)", _keep], "Read-only: nothing in the mission changes"], true]
    ], {
        params ["_values"];
        _values params ["_scope", "_go"];
        if (_go isEqualTo false || {_go isEqualTo 0}) exitWith {};
        ["Save Mission", 90, "If this mission whitelists remoteExec, save from the debug console instead (stonewall_save.min.sqf, SERVER EXEC)."]
            call FST_stonewall_fnc_awaitReply;
        [["all", "areas"] select _scope] remoteExecCall ["FST_stonewall_fnc_save", 2];
        [objNull, "Stonewall: saving on the server..."] call BIS_fnc_showCuratorFeedbackMessage;
    }] call zen_dialog_fnc_create;
}, "\a3\ui_f\data\igui\cfg\simpletasks\types\download_ca.paa"] call zen_custom_modules_fnc_register;
