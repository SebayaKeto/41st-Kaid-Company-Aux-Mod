params [
    ["_target", objNull, [objNull]],
    ["_category", "", [""]]
];

if (isNull _target || {!(_category in ["Barrier", "Tiny", "Small", "Medium", "Large"])}) exitWith {[]};

private _baseName = format ["MEAP_SnapPoint_%1", _category];
private _baseNameLower = toLower _baseName;
private _indexedPrefix = _baseNameLower + "_";
private _points = (_target selectionNames "Memory") select
{
    private _nameLower = toLower _x;
    _nameLower isEqualTo _baseNameLower
    || {_nameLower select [0, count _indexedPrefix] isEqualTo _indexedPrefix}
};
_points sort true;

_points