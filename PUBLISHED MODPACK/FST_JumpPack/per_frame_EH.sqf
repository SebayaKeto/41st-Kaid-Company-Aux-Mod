// per_frame_EH.sqf
// Starts the local recharge/watchdog PFH only when it is actually needed.
// Idempotent: safe to call repeatedly from loadout changes, arsenal close, or jump start.

private _existing = missionNamespace getVariable ["FST_jumppack_rechargePFH", -1];
if (_existing >= 0) exitWith { _existing };

private _id = [
	{
		params ["_args", "_id"];
		[_args, _id] call FST_jumppack_fnc_add_cba_per_frame;
	},
	0.25,
	[]
] call CBA_fnc_addPerFrameHandler;

missionNamespace setVariable ["FST_jumppack_rechargePFH", _id];
_id
