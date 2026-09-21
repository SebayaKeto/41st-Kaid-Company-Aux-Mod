params ["_unit"];
if (isNull _unit || {!local _unit} || {([_unit] call FST_HCSpawn_fnc_burnsRole)=="webknight"}) exitWith {};
if (_unit getVariable ["BURNS_ownsPath",false]) then {
    _unit enableAI "PATH";
    _unit setVariable ["BURNS_ownsPath",nil,true];
    _unit doFollow leader group _unit;
};
private _saved=_unit getVariable ["BURNS_originalRole",[]];
if (count _saved==0) exitWith {};
_saved params ["_stance","_speed","_features","_skills"];
_unit setUnitPos _stance;
_unit setUnitPosWeak _stance;
_unit forceSpeed _speed;
{if (_features select _forEachIndex) then {_unit enableAI _x} else {_unit disableAI _x}} forEach ["COVER","SUPPRESSION","AUTOCOMBAT"];
{_unit setSkill [_x,_skills param [_forEachIndex,_unit skill _x]]} forEach ["general","commanding","courage","reloadSpeed","spotTime","aimingAccuracy","aimingSpeed"];
_unit setVariable ["BURNS_b1Applied",nil];
_unit setVariable ["BURNS_skillApplied",nil];
_unit setVariable ["BURNS_originalRole",nil,true];
