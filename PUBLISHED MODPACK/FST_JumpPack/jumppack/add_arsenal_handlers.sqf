// add_arsenal_handlers.sqf
// Registers local Arsenal hooks once. The handlers are intentionally cheap for
// no-jump-pack ops: opening/closing Arsenal without changing backpacks and
// without an active jump pack exits without cache refresh work.

params [
	["_unit", player, [player]]
];

if !(missionNamespace getVariable ["FST_jumppack_enabled", true]) exitWith {false};
if (missionNamespace getVariable ["FST_jumppack_arsenalHandlersAdded", false]) exitWith {true};
missionNamespace setVariable ["FST_jumppack_arsenalHandlersAdded", true];

private _onOpened = {
	if !(missionNamespace getVariable ["FST_jumppack_enabled", true]) exitWith {};
	player setVariable ["FST_jumppack_arsenalBackpackBefore", backpack player];

	// Only pause recharge for actual jump-pack users. Normal infantry opening
	// Arsenal in no-jump-pack ops should do no meaningful work.
	if (player getVariable ["FST_jumppack_hasJumppack", false]) then {
		player call FST_jumppack_fnc_arsenal_opened;
	};
};

private _onClosed = {
	if !(missionNamespace getVariable ["FST_jumppack_enabled", true]) exitWith {};
	player call FST_jumppack_fnc_arsenal_closed;
};

[missionNamespace, "arsenalOpened", _onOpened] call BIS_fnc_addScriptedEventHandler;
[missionNamespace, "arsenalClosed", _onClosed] call BIS_fnc_addScriptedEventHandler;

["ACE_arsenal_displayOpened", _onOpened] call CBA_fnc_addEventHandler;
["ACE_arsenal_displayClosed", _onClosed] call CBA_fnc_addEventHandler;

true
