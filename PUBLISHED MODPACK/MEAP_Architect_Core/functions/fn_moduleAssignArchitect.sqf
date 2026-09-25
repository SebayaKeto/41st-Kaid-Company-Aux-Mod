params ["_logic", ["_units", []], ["_activated", true]];

if (!isServer || {!_activated} || {isNull _logic}) exitWith {false};
call MEAP_fnc_initializeArchitectState;

private _target = attachedTo _logic;
if (isNull _target) then
{
    _target = _logic getVariable ["bis_fnc_curatorAttachObject_object", objNull];
};
if (isNull _target) then
{
    _target = (_units select {isPlayer _x}) param [0, objNull];
};
if (isNull _target) then
{
    _target = (synchronizedObjects _logic select {isPlayer _x}) param [0, objNull];
};

if (isNull _target || {!isPlayer _target} || {!(_target isKindOf "CAManBase")}) exitWith
{
    deleteVehicle _logic;
    false
};

private _grant = getNumber (configOf _logic >> "MEAP_grantArchitect") > 0;
private _key = [_target] call MEAP_fnc_getArchitectKey;
private _grants = missionNamespace getVariable ["MEAP_Architect_grants", createHashMap];

if (_grant) then
{
    _grants set [_key, true];
    _target setVariable ["MEAP_isArchitect", true, true];
    ["Daidalos role assigned."] remoteExecCall ["MEAP_fnc_architectMessage", _target];
}
else
{
    _grants deleteAt _key;
    _target setVariable ["MEAP_isArchitect", false, true];
    [_target, true, _target getVariable ["MEAP_Architect_serverCloseToken", ""]] call MEAP_fnc_closeArchitectMode;
    ["Daidalos role revoked."] remoteExecCall ["MEAP_fnc_architectMessage", _target];
};

deleteVehicle _logic;
true