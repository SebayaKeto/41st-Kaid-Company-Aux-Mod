params ["_object"];

if (isNull _object) exitWith {false};
if !(_object isKindOf "House_F") exitWith {false};

private _points = [
    "MEAP_SnapPoint_Left",
    "MEAP_SnapPoint_Right",
    "MEAP_SnapPoint_Front",
    "MEAP_SnapPoint_Back",
    "MEAP_SnapPoint_Top",
    "MEAP_SnapPoint_Bottom"
];

private _memorySelections = (_object selectionNames "Memory") apply {toLower _x};

(_points findIf {(toLower _x) in _memorySelections}) > -1
