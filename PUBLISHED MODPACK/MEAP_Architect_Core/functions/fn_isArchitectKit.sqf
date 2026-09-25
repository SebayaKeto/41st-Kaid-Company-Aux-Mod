// The kit menu broadcasts WBK_Kit_Name whenever a player takes a kit.
// Read that current role directly so changing kits also removes kit-based access.
params [["_unit", objNull, [objNull]]];
if (isNull _unit) exitWith {false};
private _role = toLower (_unit getVariable ["WBK_Kit_Name", ""]);
_role in ["engineer", "combat engineer", "combat engineer/eod", "eod"]
