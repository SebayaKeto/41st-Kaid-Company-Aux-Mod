params [["_scrollDelta", 0, [0]]];

private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
if (count _state == 0) exitWith {};

private _rows = _state getOrDefault ["paletteRows", []];
if (_rows isEqualTo []) exitWith {};

private _search = _state getOrDefault ["paletteFilterControl", controlNull];
private _filter = toLower (_state getOrDefault ["paletteFilter", ""]);
private _entries = _state getOrDefault ["paletteEntries", []];
private _classes = _state get "classes";
private _classIndex = _state getOrDefault ["classIndex", -1];
private _selectedClass = if (_classIndex >= 0) then {_classes param [_classIndex, ""]} else {""};
private _selectionType = _state getOrDefault ["selectionType", "OBJECT"];
private _selectedBlueprintId = _state getOrDefault ["selectedBlueprintId", ""];
private _selectedIdentifier = [_selectedClass, _selectedBlueprintId] select (_selectionType isEqualTo "BUILD");

_state set ["paletteRefreshing", true];

if (!isNull _search) then {_search ctrlEnable true;};

private _filteredEntries = _entries select
{
    _x params ["", "_identifier", "_displayName"];
    _filter isEqualTo "" || {(toLower _displayName find _filter) >= 0 || {(toLower _identifier find _filter) >= 0}}
};
private _maxScrollIndex = ((count _filteredEntries) - (count _rows)) max 0;
private _scrollIndex = ((_state getOrDefault ["paletteScrollIndex", 0]) + _scrollDelta) max 0 min _maxScrollIndex;
if (_state getOrDefault ["paletteRevealSelection", false]) then
{
    private _selectedIndex = _filteredEntries findIf
    {
        _x params ["_entryType", "_identifier"];
        _entryType isEqualTo _selectionType && {_identifier isEqualTo _selectedIdentifier}
    };
    if (_selectedIndex >= 0) then
    {
        if (_selectedIndex < _scrollIndex) then {_scrollIndex = _selectedIndex;};
        if (_selectedIndex >= (_scrollIndex + count _rows)) then
        {
            _scrollIndex = _selectedIndex - count _rows + 1;
        };
    };
    _scrollIndex = _scrollIndex max 0 min _maxScrollIndex;
    _state set ["paletteRevealSelection", false];
};
_state set ["paletteScrollIndex", _scrollIndex];

private _visibleEntries = [];
{
    private _entry = _filteredEntries param [_scrollIndex + _forEachIndex, []];
    if (_entry isEqualTo []) then
    {
        _x ctrlShow false;
    }
    else
    {
        _entry params ["_entryType", "_identifier", "_displayName", "_cost"];
        private _typeLabel = ["OBJECT", "BUILD"] select (_entryType isEqualTo "BUILD");
        private _label = format ["[%1] %2", _typeLabel, _displayName];
        if (_entryType isEqualTo "OBJECT" && {_state getOrDefault ["budgetEnabled", false]}) then
        {
            _label = format ["%1 [%2]", _label, _cost];
        };
        _x ctrlSetText _label;
        _x ctrlSetTooltip format ["%1\n%2", _typeLabel, _identifier];
        private _rowColor = [0.01, 0.02, 0.01, 0.72];
        if (_entryType isEqualTo _selectionType && {_identifier isEqualTo _selectedIdentifier}) then
        {
            _rowColor = [0.12, 0.22, 0.13, 0.9];
        };
        _x ctrlSetBackgroundColor _rowColor;
        _x ctrlShow true;
        _x ctrlEnable true;
        _visibleEntries pushBack _entry;
    };
} forEach _rows;

_state set ["paletteVisibleEntries", _visibleEntries];
_state set ["paletteRefreshing", false];
