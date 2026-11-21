/*
 * True if the unit carries (or has assigned) any item in the list.
 * An empty list means "everyone has it".
 */
params ["_unit", ["_list", []]];
if (_list isEqualTo []) exitWith {true};
((items _unit + assignedItems _unit) findIf {(toLower _x) in _list}) > -1
