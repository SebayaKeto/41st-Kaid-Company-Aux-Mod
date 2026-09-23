/*
    FST_fnc_recallVehicleServer
    Server only — deletes a vehicle recalled via the garage/hangar button.

    Deleting an object ACE still tracks as loaded cargo (e.g. the BUZZ AT-RT
    crates, which set ace_cargo_size) without unloading it first is a known
    crash vector — ACE's internal per-parent cargo bookkeeping can fault
    later when it's touched. Unload from ACE cargo and strip any curator
    registration before the delete.

    Pulled out into its own registered function (rather than an inline code
    block passed straight to remoteExec) because remoteExec's compile-time
    handling of an anonymous code literal containing a nested `{...} forEach`
    block throws "Type code, expected String" — remoteExec wants either a
    String function name or a pre-defined Code variable, not a raw inline
    block with further inline blocks nested inside it.

    params: [_v]
*/
params ["_v"];

if (isNull _v) exitWith {};

private _parent = _v getVariable ["ace_cargo_parent", objNull];
if (!isNil "ace_cargo_fnc_unloadItem" && { !isNull _parent }) then {
    [_v, _parent, objNull, [], false] call ace_cargo_fnc_unloadItem;
};

{ _x removeCuratorEditableObjects [[_v], true]; } forEach allCurators;

deleteVehicle _v;
