// Detection device check
params ["_unit", ["_list", []]];
if (_list isEqualTo []) exitWith {true};
((items _unit + assignedItems _unit) findIf {(toLower _x) in _list}) > -1
