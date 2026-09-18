// Server only — packs the AT-RT and appends it to the LAAT/i crate queue.
// Deploy action is installed on all machines on the first load.
// Called directly by fn_laatiLoadAnim (already on server).
// params: [_hp, _cell, _reserves, _atrt, _laati]
params ["_hp", "_cell", "_reserves", "_atrt", "_laati"];

// Create crate at the LAAT/i position so ACE's proximity check passes.
// ACE hides the item itself after loading; we do not need hideObjectGlobal.
private _crate = createVehicle ["BUZZ_ATRT_TransportCrate", getPos _laati, [], 0, "NONE"];
_crate setVariable ["BUZZ_packed_hp",       _hp,       true];
_crate setVariable ["BUZZ_packed_cell",     _cell,     true];
_crate setVariable ["BUZZ_packed_reserves", _reserves, true];

// Destroy AT-RT (same teardown as packServer)
private _box    = _atrt getVariable ["supplyBox", objNull];
private _shield = _atrt getVariable ["shield",    objNull];
if (!isNull _box)    then { deleteVehicle _box; };
if (!isNull _shield) then { deleteVehicle _shield; };
deleteVehicle _atrt;

// Append crate to the array on all machines BEFORE the ACE call so the deploy
// action can find it even if ace_cargo_fnc_loadItem errors.
private _crates = _laati getVariable ["BUZZ_laatiCrates", []];
_crates pushBack _crate;
_laati setVariable ["BUZZ_laatiCrates", _crates, true];

// Load into ACE Cargo. Third arg true = skip distance/stability check so this
// works regardless of whether the LAAT/i is grounded, hovering, or moving.
// ACE hides the crate itself on success; hideObjectGlobal is the safety net.
[_crate, _laati, true] call ace_cargo_fnc_loadItem;
_crate hideObjectGlobal true;

// Install the deploy action on every machine exactly once per LAAT/i lifetime.
// BUZZ_deployInstalled is set globally here so the outer guard never fires twice.
// JIP flag (true) is required: without it, target 0 only reaches clients already
// connected at this exact moment. Since BUZZ_deployInstalled is synced via setVariable
// (which IS JIP-aware) and this block only ever runs once per LAAT/i, any player who
// joins later would see the guard already true and never receive the addAction call —
// permanently losing the Deploy AT-RT option on that LAAT/i. The JIP queue entry is
// keyed by function+args (per-LAAT/i), so it replays exactly once for each late joiner
// without accumulating duplicate entries.
if !(_laati getVariable ["BUZZ_deployInstalled", false]) then {
    _laati setVariable ["BUZZ_deployInstalled", true, true];
    [_laati] remoteExec ["BUZZ_fnc_laatiInstallDeploy", 0, true];
};
