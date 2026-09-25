// Restore only values that still match this role's last write.
params ["_unit",["_releaseStation",true]];
if (isNull _unit || {!local _unit} || {([_unit] call FST_HCSpawn_fnc_isPlayerControlledUnit)} || {([_unit] call FST_HCSpawn_fnc_burnsRole)=="webknight"} || {[group _unit] call FST_HCSpawn_fnc_isProtectedVehicleGroup}) exitWith {};
if (_releaseStation && {vehicle _unit==_unit} && {_unit getVariable ["BURNS_ownsPath",false]}) then {
    _unit enableAI "PATH";
    _unit setVariable ["BURNS_ownsPath",nil,true];
    private _slots=(group _unit) getVariable ["BURNS_stationSlots",[]];
    private _index=_slots findIf {(_x select 0)==_unit};
    private _slot=if (_index>=0) then {(_slots select _index) select 1} else {getPosATL _unit};
            private _token=(_unit getVariable ["BURNS_cleanupSerial",0])+1;
            _unit setVariable ["BURNS_cleanupSerial",_token];
            _unit setVariable ["BURNS_moveCleanupToken",_token];
            [FST_HCSpawn_fnc_burnsReleaseStation,[_unit,+_slot,_token],0.1] call CBA_fnc_waitAndExecute;
};
[_unit] call FST_HCSpawn_fnc_burnsReleaseAdvanceUnit;
private _hook=_unit getVariable ["BURNS_b1DangerHook",-1];
if (_hook>=0) then {_unit removeEventHandler ["Hit",_hook];_unit setVariable ["BURNS_b1DangerHook",nil]};
private _fireHook=_unit getVariable ["BURNS_b1NearbyFireHook",-1];
if (_fireHook>=0) then {_unit removeEventHandler ["FiredNear",_fireHook];_unit setVariable ["BURNS_b1NearbyFireHook",nil]};
private _saved=_unit getVariable ["BURNS_originalRole",[]];
private _applied=_unit getVariable ["BURNS_roleAppliedState",[]];
if (count _saved!=4 || {count _applied!=5}) exitWith {};
_saved params ["_stance","_speed","_features","_skills"];
_applied params ["_role","_lastStance","_lastSpeed","_lastFeatures","_lastSkills"];
if (_role=="b1") then {
    // The independent B1 stance setting still owns upright posture.
    private _keepUpright=missionNamespace getVariable ["FST_HC_DroidStanceEnabled",true] && {!(_unit getVariable ["BURNS_exempt",false])} && {!((group _unit) getVariable ["BURNS_exempt",false])};
    if (!_keepUpright && {unitPos _unit==_lastStance}) then {_unit setUnitPos _stance;_unit setUnitPosWeak _stance};
    if (abs(getForcedSpeed _unit-_lastSpeed)<0.01) then {_unit forceSpeed _speed};
    {if ((_unit checkAIFeature _x)==(_lastFeatures select _forEachIndex)) then {
        if (_features select _forEachIndex) then {_unit enableAI _x} else {_unit disableAI _x};
    }} forEach ["COVER","SUPPRESSION","AUTOCOMBAT"];
};
{if (abs((_unit skill _x)-(_lastSkills select _forEachIndex))<0.0001) then {_unit setSkill [_x,_skills select _forEachIndex]}} forEach ["general","commanding","courage","reloadSpeed","spotTime","aimingAccuracy","aimingSpeed"];
{_unit setVariable [_x,nil,true]} forEach ["BURNS_b1Applied","BURNS_skillApplied","BURNS_originalRole","BURNS_roleAppliedState"];
