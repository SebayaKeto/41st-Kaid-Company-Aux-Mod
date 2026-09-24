params ["_target", "_player", "_side"];

if (isNull _target || {isNull _player}) exitWith {};

private _source = _player getVariable ["MEAP_snapSource", objNull];
if (isNull _source) exitWith {["MEAP: Set a snap source first."] call CBA_fnc_notify;};
if (_source isEqualTo _target) exitWith {["MEAP: Source and target must be different objects."] call CBA_fnc_notify;};
if !(local _source) exitWith {["MEAP: You must own the source object to move it."] call CBA_fnc_notify;};

private _targetPointName = [_side] call MEAP_fnc_pointNameFromSide;
private _sourceSide = [_side] call MEAP_fnc_oppositeSide;
private _sourcePointName = [_sourceSide] call MEAP_fnc_pointNameFromSide;

if (_targetPointName isEqualTo "" || {_sourcePointName isEqualTo ""}) exitWith {["MEAP: Invalid snap side."] call CBA_fnc_notify;};

private _sourceSelections = (_source selectionNames "Memory") apply {toLower _x};
private _targetSelections = (_target selectionNames "Memory") apply {toLower _x};

if !((toLower _sourcePointName) in _sourceSelections) exitWith
{
    [format ["MEAP: Source is missing memory point %1.", _sourcePointName]] call CBA_fnc_notify;
};

if !((toLower _targetPointName) in _targetSelections) exitWith
{
    [format ["MEAP: Target is missing memory point %1.", _targetPointName]] call CBA_fnc_notify;
};

private _ok = [_source, _target, _sourcePointName, _targetPointName] call MEAP_fnc_applySnapTransform;

if (_ok) then
{
    [format ["MEAP: Snapped source to target %1 side.", _side]] call CBA_fnc_notify;
}
else
{
    ["MEAP: Snap failed because the source transform could not be applied."] call CBA_fnc_notify;
};
