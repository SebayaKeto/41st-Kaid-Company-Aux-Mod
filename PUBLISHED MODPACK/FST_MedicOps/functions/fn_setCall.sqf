// FST_medOps_fnc_setCall
// Where the unit is local. Raise or clear its medic call (public unit variable, read by every medic's HUD).
// Arguments: 0: unit, 1: on <BOOL>, 2: reason "down" | "called" (default "called")

params ["_unit", "_on", ["_reason", "called"]];
if (!local _unit) exitWith {};
if (_on) then {
    if !(missionNamespace getVariable ["FST_medOps_beacons", true]) exitWith {};
    _unit setVariable ["FST_medOps_call", [_reason, CBA_missionTime], true];
    if (hasInterface && {_unit == player} && {_reason == "called"}) then { hint "Medic called. Your position is on the medics' screens."; };
} else {
    if (!isNil { _unit getVariable "FST_medOps_call" }) then {
        _unit setVariable ["FST_medOps_call", nil, true];
    };
};
