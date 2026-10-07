// Pack AT-RT (server)
params ["_pos", "_dir", "_hp", "_cell", "_reserves", "_atrt"];
// Rider check
if (!isNull (_atrt getVariable ["rider", objNull])) exitWith {};
private _crate = createVehicle ["BUZZ_ATRT_TransportCrate", ASLToAGL _pos, [], 0, "NONE"];
_crate setDir _dir;
_crate setPosASL _pos;
_crate setVariable ["BUZZ_packed_hp",       _hp,       true];
_crate setVariable ["BUZZ_packed_cell",     _cell,     true];
_crate setVariable ["BUZZ_packed_reserves", _reserves, true];
_crate setVariable ["BUZZ_packed_class",    typeOf _atrt, true];
private _box    = _atrt getVariable ["supplyBox", objNull];
private _shield = _atrt getVariable ["shield",    objNull];
if (!isNull _box)    then { deleteVehicle _box; };
if (!isNull _shield) then { deleteVehicle _shield; };
deleteVehicle _atrt;
