/*
 * Protective gear worn: 0 = none, 1 = helmet OR armour, 2 = helmet AND armour.
 * If only one list is filled in (Addon Options), that piece alone counts as full.
 */
params ["_unit"];
private _helmets = missionNamespace getVariable ["BUZZ_Radiation_helmetList", []];
private _vests = missionNamespace getVariable ["BUZZ_Radiation_vestList", []];
if (_helmets isEqualTo [] && {_vests isEqualTo []}) exitWith {0};

private _hasHelmet = (toLower headgear _unit) in _helmets;
private _hasVest = (toLower vest _unit) in _vests;

if (_helmets isEqualTo []) exitWith {[0, 2] select _hasVest};
if (_vests isEqualTo []) exitWith {[0, 2] select _hasHelmet};
(parseNumber _hasHelmet) + (parseNumber _hasVest)
