params [
    ["_unit", objNull, [objNull]],
    ["_object", objNull, [objNull]],
    ["_action", "", [""]]
];

if (!isServer || {isNull _unit} || {isNull _object}) exitWith {false};

private _ownerKey = _object getVariable ["MEAP_Architect_constructedBy", ""];
private _unitKey = [_unit] call MEAP_fnc_getArchitectKey;
private _isAdmin = (admin owner _unit) > 0;
private _ownerMayMaintain = missionNamespace getVariable ["MEAP_Architect_ownerMayMaintain", true];
private _unownedMayMaintain = missionNamespace getVariable ["MEAP_Architect_unownedMayMaintain", true];

_isAdmin
|| {_ownerKey isEqualTo "" && {_unownedMayMaintain}}
|| {_ownerMayMaintain && {_ownerKey isEqualTo _unitKey}}
