/*
 * Removes a zone on this machine.
 * Example (trigger On Deactivation): [thisTrigger] call BUZZ_Radiation_fnc_removeZone;
 */
params [["_zone", objNull, [objNull]]];
BUZZ_Radiation_zones = BUZZ_Radiation_zones - [_zone];
