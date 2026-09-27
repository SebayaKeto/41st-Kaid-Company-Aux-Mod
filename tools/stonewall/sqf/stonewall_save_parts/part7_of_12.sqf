localNamespace setVariable ["stonewall_code", (localNamespace getVariable ["stonewall_code", ""]) + "private _fortCls = [];
{
if (_x find ""ace_fortify_objects_"" == 0) then {
private _list = missionNamespace getVariable [_x, []];
if (_list isEqualType []) then {
{ if (_x isEqualType [] && {count _x > 0}) then { _fortCls pushBackUnique toLower (_x#0); }; } forEach _list;
};
};
} forEach allVariables missionNamespace;
private _skipKinds = [""Man"", ""Animal"", ""Logic"", ""WeaponHolder"", ""WeaponHolderSimulated"", ""Crater"", ""CraterLong"",
""Ruins"", ""EmptyDetector"", ""CBA_NamespaceDummy"", ""ACE_Explosives_Place"", ""MineBase"", ""ACE_bodyBagObject"", ""ACE_Grave""];
private _attached = 0;
private _objs = (allMissionObjects ""All"") + (allSimpleObjects []);
private _clsAddons = createHashMap;
private _n = 0;
private _nArea = 0;
private _skipped = 0;
private _noClass = 0;
{
private _o = _x;
private _t = typeOf _o;
call {
if (isNull _o) exitWith {};
if (_t == """") exitWith { _noClass = _noClass + 1; };
"];
