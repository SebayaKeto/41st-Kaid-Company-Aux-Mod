// per_frame_EH_stop.sqf
// Stops the local recharge/watchdog PFH when no jump pack or active damage override exists.

private _id = missionNamespace getVariable ["FST_jumppack_rechargePFH", -1];
if (_id < 0) exitWith { false };

[_id] call CBA_fnc_removePerFrameHandler;
missionNamespace setVariable ["FST_jumppack_rechargePFH", -1];
true
