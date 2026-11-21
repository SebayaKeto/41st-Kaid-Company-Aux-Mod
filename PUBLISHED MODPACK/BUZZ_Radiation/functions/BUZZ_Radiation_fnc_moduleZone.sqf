/*
 * Eden module init for Radiation Zone / Safe Zone / Decontamination Zone.
 * Runs on every machine (isGlobal = 2), so each one registers the zone locally.
 */
params [["_logic", objNull, [objNull]], ["_units", []], ["_activated", true]];
if (!_activated || isNull _logic) exitWith {};

private _cfg = configOf _logic;
private _tier = if (isNumber (_cfg >> "BUZZ_Radiation_fixedTier")) then {
    getNumber (_cfg >> "BUZZ_Radiation_fixedTier")
} else {
    _logic getVariable ["Tier", 1]
};
if (_tier isEqualType "") then {_tier = parseNumber _tier};

// A JIP client may already have a tier/active state set later in the mission
// (BUZZ_Radiation_fnc_setZoneTier / setZoneActive broadcast it). Keep that instead of the Eden value.
if (!isNil {_logic getVariable "BUZZ_Radiation_tier"}) then {_tier = _logic getVariable "BUZZ_Radiation_tier"};

private _condition = _logic getVariable ["Condition", "true"];

// Area: synced triggers if any, otherwise the module's own Eden area.
private _areas = (synchronizedObjects _logic) select {_x isKindOf "EmptyDetector"};
if (_areas isEqualTo []) then {
    private _oa = _logic getVariable ["objectArea", []];
    if (count _oa >= 2) then {
        _oa params ["_a", "_b", ["_angle", getDir _logic], ["_rect", false], ["_c", -1]];
        _areas = [[getPosATL _logic, _a, _b, _angle, _rect, _c]];
    } else {
        _areas = [[getPosATL _logic, 50, 50, getDir _logic, false, -1]];
    };
};

[_logic, _tier, _areas, _condition] call BUZZ_Radiation_fnc_addZone;
