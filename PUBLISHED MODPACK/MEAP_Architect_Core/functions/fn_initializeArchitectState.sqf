if (!isServer) exitWith {};

{
    private _value = missionNamespace getVariable [_x, createHashMap];
    if !(_value isEqualType createHashMap) then {_value = createHashMap;};
    missionNamespace setVariable [_x, _value];
} forEach
[
    "MEAP_Architect_grants",
    "MEAP_Architect_actionTimes",
    "MEAP_Architect_editLocks",
    "MEAP_Architect_history",
    "MEAP_Architect_objectCounts",
    "MEAP_Architect_budgetBalances",
    "MEAP_Architect_fobs",
    "MEAP_Architect_sessions",
    "MEAP_Architect_snapshots",
    "MEAP_Architect_blueprints",
    "MEAP_Architect_blueprintCounters"
];

private _allowedClasses = missionNamespace getVariable ["MEAP_Architect_allowedClasses", []];
if !(_allowedClasses isEqualType []) then {_allowedClasses = [];};
missionNamespace setVariable ["MEAP_Architect_allowedClasses", _allowedClasses];

private _auditTrail = missionNamespace getVariable ["MEAP_Architect_auditTrail", []];
if !(_auditTrail isEqualType []) then {_auditTrail = [];};
missionNamespace setVariable ["MEAP_Architect_auditTrail", _auditTrail];