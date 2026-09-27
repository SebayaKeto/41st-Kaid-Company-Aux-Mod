localNamespace setVariable ["stonewall_code", (localNamespace getVariable ["stonewall_code", ""]) + "private _dv = missionNamespace getVariable [""stonewall_daidalosVars"", []];
if (_dv isEqualType []) then { { if (_x isEqualType """") then { _daidVars pushBackUnique _x; }; } forEach _dv; };
_dv = missionNamespace getVariable [""FST_stonewall_daidalosVars"", """"];
if (_dv isEqualType """") then {
{
private _v = (_x splitString "" "") joinString """";
if (_v != """") then { _daidVars pushBackUnique _v; };
} forEach (_dv splitString "","");
};
if !(_margin isEqualType 0) then { _margin = 15; };
if !(_zenAreas isEqualType true) then { _zenAreas = true; };
private _cba = isClass (configFile >> ""CfgPatches"" >> ""FST_Stonewall"") && {!isNil ""CBA_fnc_ownerEvent""};
private _clean = { (_this splitString ""|"") joinString ""/"" };
private _t0 = diag_tickTime;
private _d = systemTimeUTC apply { if (_x < 10) then { ""0"" + str _x } else { str _x } };
"];
