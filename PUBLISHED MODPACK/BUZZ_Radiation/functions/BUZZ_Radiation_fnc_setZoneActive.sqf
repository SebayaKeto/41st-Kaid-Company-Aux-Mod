/*
 * Switches a zone on or off. For an Eden module the change is sent to every
 * machine (and JIP), so it can be called from anywhere, e.g. a server-only trigger.
 * Example: [rad_reactor, false] call BUZZ_Radiation_fnc_setZoneActive;
 */
params [["_zone", objNull, [objNull]], ["_active", true, [true]]];
if (isNull _zone) exitWith {};
_zone setVariable ["BUZZ_Radiation_active", _active, netId _zone != "0:0"];
