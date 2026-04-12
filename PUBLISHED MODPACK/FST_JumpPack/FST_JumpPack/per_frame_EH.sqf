
// per_frame_EH.sqf
// REWRITE: Replaced CBA_fnc_addPerFrameHandler + spawn with a 0.25s timer + call.
// At 60fps the old version spawned 60 scheduled threads/sec and did 3 config lookups
// + 2 network broadcasts per frame. This version runs 4 times/sec with zero spawns,
// zero config lookups (uses cached values), and minimal network traffic.

[
	{
		params ["_args", "_id"];
		[_args, _id] call FST_jumppack_fnc_add_cba_per_frame;
	},
	0.25,  // 4 ticks per second — smooth recharge, no scheduler pressure
	[0]
] call CBA_fnc_addPerFrameHandler;
