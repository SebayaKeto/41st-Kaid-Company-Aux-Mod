params ["_target", "_player"];

if (isNull _target || {isNull _player}) exitWith {};

_player setVariable ["MEAP_snapSource", _target, false];

private _displayName = getText (configOf _target >> "displayName");
if (_displayName isEqualTo "") then
{
	_displayName = typeOf _target;
};

[format ["MEAP: Snap source set to %1.", _displayName]] call CBA_fnc_notify;
