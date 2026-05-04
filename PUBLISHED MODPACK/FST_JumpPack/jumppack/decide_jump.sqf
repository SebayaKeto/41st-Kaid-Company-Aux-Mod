

params ["_unit"];

// Use cached jumppack check (no config lookup)
if !(player getVariable ["FST_jumppack_hasJumppack", false]) exitWith {
	[
		format ["<t color='#FF0000'>You dont have a jumppack.</t>"],
		format ["<t color='#FF0000'>ArE YoU StUpId MaTey YoU DoNTY HaBE a JumPPacK OwO???.</t>"],
		0.2
	] call FST_jumppack_fnc_memeify_test;
};

// If captive no jump
if (_unit getVariable ["ace_captives_ishandcuffed", false]) exitWith {
	[
		format ["<t color='#FF0000'>Cant jump while captured.</t>"],
		format ["<t color='#FF0000'>Bitch, where u tryna go.</t>"],
		0.2
	] call FST_jumppack_fnc_memeify_test;
};

// If underwater or on water, no jump
if ((eyePos _unit select 2 < 0) || (underwater _unit) || ((surfaceIsWater getPos _unit) && (getPosASL _unit select 2 < 0))) exitWith {
	[
		format ["<t color='#FF0000'>No water jumping.</t>"],
		format ["<t color='#FF0000'>Water is too warm :) OwO.</t>"],
		0.2
	] call FST_jumppack_fnc_memeify_test;
};

// If in vehicle, no jump
if (!(isNull objectParent _unit)) exitWith {
	[
		format ["<t color='#FF0000'>No jumping in vehicle,</t>"],
		format ["<t color='#FF0000'>Seatbelt on.</t>"],
		0.2
	] call FST_jumppack_fnc_memeify_test;
};

// Use cached jump types (no config lookup)
private _jumppackData = player getVariable ["FST_jumppack_cachedJumpTypes", []];

if (count _jumppackData == 0) exitWith {
	[format ["<t color='#FF0000'>Script Hab Stroke # Type 1 :(</t>"], ""] call ace_common_fnc_displayTextPicture;
};

// Energy check
private _backpackObj    = unitBackpack _unit;
if (_backpackObj isEqualTo objNull) exitWith {};

private _jumpIndex     = _backpackObj getVariable ["FST_jumppack_selected_jump", 0];
if (_jumpIndex < 0 || {_jumpIndex >= count _jumppackData}) then {
	_jumpIndex = 0;
	_backpackObj setVariable ["FST_jumppack_selected_jump", 0];
};

private _currentEnergy = _backpackObj getVariable ["FST_jumppack_energy", 0];
private _selectedJump  = _jumppackData select _jumpIndex;
private _cost          = (_selectedJump select 1) select 2;

if (_cost > _currentEnergy) exitWith {
	[
		format ["<t color='#FF0000'>Not Enough Energy</t>"],
		format ["<t color='#FF0000'>Not Enough V-Bucks.</t>"],
		0.2
	] call FST_jumppack_fnc_memeify_test;
};

private _jumpMovementData = _selectedJump select 1;
private _veloData         = [_jumpMovementData select 0, _jumpMovementData select 1, _jumpMovementData select 3];
private _proneFlag        = _jumpMovementData select 5;
private _directionalFlag  = _jumpMovementData select 4;

private _canProneJump       = (_proneFlag == 1);
private _canDirectionalJump = (_directionalFlag == 1);

if ((stance _unit == "PRONE") && !_canProneJump) exitWith {
	[
		format ["<t color='#FF0000'>No prone jump selected.</t>"],
		format ["<t color='#FF0000'>No Grasshopper mode.</t>"],
		0.2
	] call FST_jumppack_fnc_memeify_test;
};

// Consume energy — broadcast this one since it's a meaningful state change
private _newEnergy = _currentEnergy - _cost;
_backpackObj setVariable ["FST_jumppack_energy", _newEnergy, true];

// Use cached capacity (no config lookup)
private _energyCapacity = player getVariable ["FST_jumppack_cachedCapacity", 0];
[_newEnergy, _energyCapacity] call FST_jumppack_fnc_show_current_energy;

[_unit,
_veloData select 0,
_veloData select 1,
_veloData select 2,
_canDirectionalJump
]
spawn FST_jumppack_fnc_jump;
