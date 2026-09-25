params [
    ["_action", "", [""]],
    ["_unit", objNull, [objNull]],
    ["_object", objNull, [objNull]],
    ["_details", "", [""]]
];

if (!isServer) exitWith {};
call MEAP_fnc_initializeArchitectState;

private _audit = missionNamespace getVariable ["MEAP_Architect_auditTrail", []];
private _entry = [
    diag_tickTime,
    toUpper _action,
    if (isNull _unit) then {""} else {[_unit] call MEAP_fnc_getArchitectKey},
    if (isNull _object) then {""} else {netId _object},
    if (isNull _object) then {""} else {typeOf _object},
    _details
];
_audit pushBack _entry;

private _depth = missionNamespace getVariable ["MEAP_Architect_auditDepth", 200];
while {count _audit > _depth} do {_audit deleteAt 0;};
missionNamespace setVariable ["MEAP_Architect_auditTrail", _audit];
