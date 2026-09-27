localNamespace setVariable ["stonewall_code", (localNamespace getVariable ["stonewall_code", ""]) + "if (!isNil { _o getVariable ""ace_fortify_tokensUsed"" }) exitWith { _src = ""fortify""; };
if (_daidVars findIf { !isNil { _o getVariable _x } } >= 0) exitWith { _src = ""daidalos""; };
private _tag = _o getVariable [""stonewall_src"", """"];
if (_tag != """") exitWith { _src = _tag; };
if ((toLower _t) in _fortCls) exitWith { _src = ""fortify_class""; };
};
private _kind = call {
if (_o isKindOf ""StaticWeapon"") exitWith { ""static_weapon"" };
if (_o isKindOf ""LandVehicle"") exitWith { ""land_vehicle"" };
if (_o isKindOf ""Air"") exitWith { ""air"" };
if (_o isKindOf ""Ship"") exitWith { ""ship"" };
if (_o isKindOf ""ReammoBox_F"" || {_o isKindOf ""ReammoBox""}) exitWith { ""box"" };
if (_o isKindOf ""Thing"") exitWith { ""thing"" };
if (_o isKindOf ""Static"") exitWith { ""static"" };
""other""
};
if !(_t in _clsAddons) then {
private _cfg = configFile >> ""CfgVehicles"" >> _t;
"];
