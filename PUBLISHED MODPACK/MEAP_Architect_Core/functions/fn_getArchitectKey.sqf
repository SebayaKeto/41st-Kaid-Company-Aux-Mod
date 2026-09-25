params [["_unit", objNull, [objNull]]];

if (isNull _unit) exitWith {""};

private _uid = getPlayerUID _unit;
if (_uid isNotEqualTo "") exitWith {_uid};

format ["OWNER_%1", owner _unit]