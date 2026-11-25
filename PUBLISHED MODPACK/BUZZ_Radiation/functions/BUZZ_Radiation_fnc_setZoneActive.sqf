// Switches a zone on or off
params [["_zone", objNull, [objNull]], ["_active", true, [true]]];
if (isNull _zone) exitWith {};
_zone setVariable ["BUZZ_Radiation_active", _active, netId _zone != "0:0"];
