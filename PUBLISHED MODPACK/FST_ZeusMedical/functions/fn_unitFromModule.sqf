// FST_zeusMed_fnc_unitFromModule
// Zeus side. The infantry unit a module was dropped on, or objNull (with feedback).
// Arguments: 0: attached object <OBJECT>
// Returns: unit <OBJECT>

params [["_attached", objNull, [objNull]]];

if !(missionNamespace getVariable ["FST_zeusMed_enabled", true]) exitWith {
    [objNull, "41st Medical: disabled in Addon Options (FST_zeusMed_enabled)"] call BIS_fnc_showCuratorFeedbackMessage;
    objNull
};
private _unit = _attached;
if (!isNull _unit && {!(_unit isKindOf "CAManBase")}) then {
    // dropped on a vehicle: use its effective commander, if any
    _unit = effectiveCommander _unit;
};
if (isNull _unit || {!(_unit isKindOf "CAManBase")}) exitWith {
    [objNull, "41st Medical: place this module on a unit"] call BIS_fnc_showCuratorFeedbackMessage;
    objNull
};
if (!alive _unit) exitWith {
    [objNull, "41st Medical: that unit is dead"] call BIS_fnc_showCuratorFeedbackMessage;
    objNull
};
_unit
