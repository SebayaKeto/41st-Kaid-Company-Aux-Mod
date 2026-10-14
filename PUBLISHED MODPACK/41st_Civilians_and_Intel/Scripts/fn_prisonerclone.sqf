
params ["_unit"];

if (isNull _unit) exitWith {};
if (!local _unit) exitWith {}; 

if (_unit getVariable ["FST_Initialized", false]) exitWith {};
_unit setVariable ["FST_Initialized", true, true];

["FST_applyName", [ _unit, "CIS Clone Prisoner"]] call CBA_fnc_globalEvent;

[_unit] spawn {

params ["_unit"];

if (isNull _unit) exitWith {};

sleep 0.05;

if (isNull _unit) exitWith {};
if (!local _unit) exitWith {};

["FST_applyIdentity", [ _unit, "FST_clone_Default_head", "Male04ENGB"]] call CBA_fnc_globalEvent;
removeGoggles _unit;
[_unit, true] call ace_captives_fnc_setHandcuffed;

};