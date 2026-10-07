// Load into LAAT/i (server)
params ["_hp", "_cell", "_reserves", "_atrt", "_laati"];

// Create crate
private _crate = createVehicle ["BUZZ_ATRT_TransportCrate", getPos _laati, [], 0, "NONE"];
_crate setVariable ["BUZZ_packed_hp",       _hp,       true];
_crate setVariable ["BUZZ_packed_cell",     _cell,     true];
_crate setVariable ["BUZZ_packed_reserves", _reserves, true];

// Destroy AT-RT
private _box    = _atrt getVariable ["supplyBox", objNull];
private _shield = _atrt getVariable ["shield",    objNull];
if (!isNull _box)    then { deleteVehicle _box; };
if (!isNull _shield) then { deleteVehicle _shield; };
deleteVehicle _atrt;

// Crate manifest
private _crates = _laati getVariable ["BUZZ_laatiCrates", []];
_crates pushBack _crate;
_laati setVariable ["BUZZ_laatiCrates", _crates, true];

// ACE Cargo load
[_crate, _laati, true] call ace_cargo_fnc_loadItem;
_crate hideObjectGlobal true;

// Failed-load fallback
if !(_crate in (_laati getVariable ["ace_cargo_loaded", []])) then {
    _crate setVariable ["BUZZ_laatiStowed", _laati, true];
};

// Deploy action install
if !(_laati getVariable ["BUZZ_deployInstalled", false]) then {
    _laati setVariable ["BUZZ_deployInstalled", true, true];
    [_laati] remoteExec ["BUZZ_fnc_laatiInstallDeploy", 0, true];
};
