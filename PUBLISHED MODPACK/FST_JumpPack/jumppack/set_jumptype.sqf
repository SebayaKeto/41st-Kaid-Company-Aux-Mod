

params ["_unit", "_inc"];

if !(missionNamespace getVariable ["FST_jumppack_enabled", true]) exitWith {};

// Use cached jumppack check (no config lookup)
if !(player getVariable ["FST_jumppack_hasJumppack", false]) exitWith {};

// Use cached jump types (no config lookup)
private _jumppackData = player getVariable ["FST_jumppack_cachedJumpTypes", []];
private _numJumps = count _jumppackData;
if (_numJumps == 0) exitWith {};

private _backpackObj = unitBackpack _unit;
if (_backpackObj isEqualTo objNull) exitWith {};

private _jumpIndex = _backpackObj getVariable ["FST_jumppack_selected_jump", 0];

private _a = _jumpIndex + _inc;
private _b = _numJumps;
private _newIndex = (_a - (floor(_a / _b)) * _b);

_backpackObj setVariable ["FST_jumppack_selected_jump", _newIndex];

// Data for hint
private _newSelectedJump = _jumppackData select _newIndex;
private _jumpName = _newSelectedJump select 0;
private _jumpCost = (_newSelectedJump select 1) select 2;
hint parseText format ["name: %1 <br />Cost: <t color='#00FFFF'>%2</t><br />Current Energy:<t color='#aaff00'>%3</t>", _jumpName, _jumpCost, _backpackObj getVariable ["FST_jumppack_energy", 0]];
