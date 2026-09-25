params ["_source", "_target", "_sourcePointName", "_targetPointName"];

if (isNull _source || {isNull _target}) exitWith {false};
if (!local _source) exitWith {false};

private _sourceMemorySelections = (_source selectionNames "Memory") apply {toLower _x};
private _targetMemorySelections = (_target selectionNames "Memory") apply {toLower _x};

if !((toLower _sourcePointName) in _sourceMemorySelections) exitWith {false};
if !((toLower _targetPointName) in _targetMemorySelections) exitWith {false};

private _sourcePoint = _source selectionPosition [_sourcePointName, "Memory"];
private _targetPoint = _target selectionPosition [_targetPointName, "Memory"];

_source setDir (getDir _target);

private _sourcePointWorld = _source modelToWorldWorld _sourcePoint;
private _targetPointWorld = _target modelToWorldWorld _targetPoint;
private _delta = _targetPointWorld vectorDiff _sourcePointWorld;

_source setPosWorld ((getPosWorld _source) vectorAdd _delta);

true
