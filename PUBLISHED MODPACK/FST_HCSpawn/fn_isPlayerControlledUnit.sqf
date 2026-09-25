// Read-only, constant-time test; no global player/unit scans or network traffic.
// Vanilla/ZEN remote control leaves isPlayer false on the controlled AI.
params ["_unit"];
if (isNull _unit) exitWith {false};
if (isPlayer _unit) exitWith {true};
private _inverse=objNull;
if (local _unit) then {_inverse=remoteControlled _unit};
if (!isNull _inverse && {isPlayer _inverse}) exitWith {true};
// Vanilla publishes this marker before/through the unit-locality handoff and
// clears it on normal release. The actual V11 test verified both transitions.
private _controller=_unit getVariable ["bis_fnc_moduleRemoteControl_owner",objNull];
if !(_controller isEqualType objNull) exitWith {false};
if (isNull _controller || {!isPlayer _controller}) exitWith {false};
if (local _controller) exitWith {
    isRemoteControlling _controller && {(remoteControlled _controller) isEqualTo _unit}
};
// A remote controller's native link is not locally authoritative. Conservatively
// honor its engine marker until cleared; do not introduce polling or a lease.
true
