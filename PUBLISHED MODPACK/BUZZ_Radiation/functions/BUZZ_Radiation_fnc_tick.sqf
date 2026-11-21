/*
 * Main loop, once per second on every machine.
 */
if (!(missionNamespace getVariable ["BUZZ_Radiation_enabled", true])) exitWith {};

private _now = CBA_missionTime;
private _dt = _now - (missionNamespace getVariable ["BUZZ_Radiation_lastTick", _now]);
BUZZ_Radiation_lastTick = _now;
if (_dt <= 0 || {_dt > 5}) exitWith {}; // first tick, or game was paused

BUZZ_Radiation_zones = BUZZ_Radiation_zones select {!isNull _x};
private _active = BUZZ_Radiation_zones select {
    (_x getVariable ["BUZZ_Radiation_active", true]) && {([_x] call (_x getVariable ["BUZZ_Radiation_condition", {true}])) isEqualTo true}
};

BUZZ_Radiation_activeZones = _active;

private _units = if (BUZZ_Radiation_affectAI) then {
    allUnits select {local _x}
} else {
    allPlayers select {local _x && {alive _x} && {!(_x isKindOf "HeadlessClient_F")}}
};

// Never touch units that can't take damage (allowDamage false), a player while they're in the
// Zeus interface or remote-controlling a unit (their own body included), or the unit being
// remote-controlled. Their dose is frozen, so radiation can never kill them.
// Zeus players who are playing on the ground (interface closed) are affected as normal.
private _inZeus = hasInterface && {
    !isNull findDisplay 312 || {!isNull (missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", objNull])}
};
_units = _units select {
    isDamageAllowed _x
    && {!(_inZeus && {_x == player})}
    && {isNull (_x getVariable ["bis_fnc_moduleRemoteControl_owner", objNull])}
};

{
    [_x, [_x, _active] call BUZZ_Radiation_fnc_getExposure, _dt] call BUZZ_Radiation_fnc_updateUnit;
} forEach _units;

if (hasInterface) then {call BUZZ_Radiation_fnc_updatePlayer};
