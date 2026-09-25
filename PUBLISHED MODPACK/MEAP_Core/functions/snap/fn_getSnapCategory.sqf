params ["_source"];

private _config = configNull;
if (_source isEqualType objNull) then
{
    if (isNull _source) exitWith {};
    _config = configOf _source;
};
if (_source isEqualType "") then
{
    _config = configFile >> "CfgVehicles" >> _source;
};
if (isNull _config) exitWith {""};

private _category = getText (_config >> "MEAP_SW_snapCategory");
if !(_category in ["Barrier", "Tiny", "Small", "Medium", "Large"]) exitWith {""};

_category