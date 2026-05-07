
params ["_unit"];

if (!local _unit) exitWith {}; 

[_unit] spawn {

params ["_unit"];

sleep 0.1;

[_unit, "FST_clone_Default_head"] remoteExec ["setFace", 0, _unit];
[_unit, "Male04ENGB"] remoteExec ["setSpeaker", 0, _unit];
[_unit, "CIS Clone Prisoner"] remoteExec ["setName", 0, _unit];
removeGoggles _unit;
[_unit, true] call ace_captives_fnc_setHandcuffed;

};