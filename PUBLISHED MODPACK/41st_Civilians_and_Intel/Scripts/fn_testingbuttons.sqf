
params ["_term","_user"];

{
	_term setVariable [_x, nil, true]
} forEach
[
	"FST_DeviceInUse",
	"FST_DeviceFullBroken",
	"FST_DeviceBroken",
	"FST_DeviceAssessed",
	"FST_CurrentError",
	"FST_LastAttempt",
	"FST_GoodRepair",
	"FST_DeviceRepaired",
	"FST_DeviceLocked",
	"FST_DeviceHacked",
	"FST_DeviceAccessed",
	"FST_DiffPassed",
	"FST_AttemptsLeft",
	"FST_1600Pressed",
	"FST_1601Pressed",
	"FST_1602Pressed",
	"FST_1603Pressed",
	"FST_1604Pressed",
	"FST_1605Pressed",
	"FST_1606Pressed",
	"FST_1607Pressed",
	"FST_1608Pressed",
	"FST_1609Pressed",
	"FST_1610Pressed"
];

hintSilent parseText "<t color='#0074cc'>Device Hack/Repair Minigame Flags Cleared</t>";
