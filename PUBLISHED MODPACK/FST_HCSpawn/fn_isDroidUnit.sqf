// FST_HCSpawn_fnc_isDroidUnit
// Pure classification: is this unit a CIS droid (B1/B2/BX/commando)?
// No side effects and NO settings gate -- callers decide what to do with the
// answer. Split out of fn_emergencyStabilizeDroid (2026-08-08) because that
// function gates on FST_HC_EmergencyDroidBandaidEnabled before classifying,
// which silently broke any caller that only wanted the classification (the
// droid corpse cleanup's Killed handler never matched with the bandaid off).
//
// The verdict is cached per classname in a hashmap: classification depends
// only on config data, so hot paths (Killed handlers, periodic scans) pay
// config reads + substring scans once per CLASS, then one hash lookup per call.

params ["_unit"];

if (isNull _unit) exitWith { false };
if (isPlayer _unit) exitWith { false };
if !(_unit isKindOf "CAManBase") exitWith { false };

private _class = typeOf _unit;

private _cache = missionNamespace getVariable "FST_HC_DroidClassCache";
if (isNil "_cache") then {
    _cache = createHashMap;
    missionNamespace setVariable ["FST_HC_DroidClassCache", _cache];
};

private _cached = _cache get _class;
if (!isNil "_cached") exitWith { _cached };

private _type = toLower _class;
private _display = toLower getText (configFile >> "CfgVehicles" >> _class >> "displayName");
private _faction = toLower getText (configFile >> "CfgVehicles" >> _class >> "faction");

private _typeHits = {(_type find _x) >= 0} count ["droid", "fst_b1", "fst_b2", "b1_", "b2_", "_b1", "_b2", "bx_droid", "commando_droid"];
private _displayHits = {(_display find _x) >= 0} count ["droid", "b1", "b2", "commando droid", "battle droid", "super battle"];
private _isDroid = (_typeHits > 0) || {_displayHits > 0} || {((_faction find "cis") >= 0 || {(_faction find "separatist") >= 0}) && {(_type find "droid") >= 0}};

_cache set [_class, _isDroid];
_isDroid
