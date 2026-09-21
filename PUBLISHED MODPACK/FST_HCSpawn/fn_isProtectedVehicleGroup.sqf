// Read-only guard; scans only this group's members and their occupied vehicles.
// Empty player vehicles have no crew group and are never adopted by HCSpawn.
// Protect BLUFOR vehicle assets even with temporary AI crews; protect any
// side's vehicle when a player rides in another group's crew/cargo seat.
params ["_group"];
if (isNull _group) exitWith {false};
private _members = units _group;
if ((_members findIf {isPlayer _x}) >= 0) exitWith {true};
private _checked = [];
(_members findIf {
    private _v = vehicle _x;
    if (_v == _x || {_v in _checked}) then {false} else {
        _checked pushBack _v;
        side _group == west ||
        {getNumber (configOf _v >> "side") == 1} ||
        {_v getVariable ["BURNS_playerVehicle",false]} ||
        {(crew _v findIf {isPlayer _x}) >= 0}
    }
}) >= 0
