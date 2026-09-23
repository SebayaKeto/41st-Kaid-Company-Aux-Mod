params ["_group","_contacts"];
if !(missionNamespace getVariable ["BURNS_RifleAssistEnabled",true]) exitWith {};
if (!([_group] call FST_HCSpawn_fnc_burnsB1Eligible) || {count (_group getVariable ["BURNS_pointFire",[]])>0}) exitWith {};
private _leader=leader _group;
private _candidates=[];
private _activeThreat=false;
{
    _x params ["_pos","_type","_side","_cost","_object"];
    if (isNull _object || {!alive _object} || {isObjectHidden _object} || {_side in [civilian,sideUnknown,sideLogic]} || {(side _group) getFriend _side>=0.6}) then {continue};
    private _down=[_object] call FST_HCSpawn_fnc_burnsIsDown;
    if (_object isKindOf "CAManBase" && {!_down} && {vehicle _object==_object} && {_leader distance2D _pos<100}) exitWith {_activeThreat=true};
    if (_down && {_leader distance _object<30}) then {_candidates pushBackUnique _object};
    private _vehicle=vehicle _object;
    if (_vehicle isKindOf "LandVehicle" && {!(_vehicle isKindOf "CAManBase")} && {!captive _vehicle} && {count crew _vehicle>0}) then {_candidates pushBackUnique _vehicle};
} forEach _contacts;
if (_activeThreat) exitWith {};
// Small slices of the existing shared player cache cover casualties that ACE
// removed from native target lists, including squads without a BURNS task.
// Actual firing still requires close range, facing and two clear sight lines.
private _downed=missionNamespace getVariable ["BURNS_DownedPlayers",[]];
private _count=count _downed;
private _bodyCursor=_group getVariable ["BURNS_casualtyCursor",0];
for "_i" from 1 to (8 min _count) do {
    _bodyCursor=_bodyCursor mod _count;
    private _body=_downed select _bodyCursor;
    _bodyCursor=_bodyCursor+1;
    if (_leader distance _body<30) then {_candidates pushBackUnique _body};
};
_group setVariable ["BURNS_casualtyCursor",_bodyCursor];
// A casualty can fall out of native targeting. The task's existing target may
// be used at close range after visual/FOV checks, without revealing it to AI.
private _seek=[_group,["BURNS_rushTarget",objNull]] call FST_HCSpawn_fnc_burnsStateGet;
if (([_seek] call FST_HCSpawn_fnc_burnsIsDown) && {_leader distance _seek<30}) then {_candidates pushBackUnique _seek};
private _target=objNull;
private _distance=1e12;
{
    private _d=_leader distance _x;
    if ([_x] call FST_HCSpawn_fnc_burnsIsDown) then {
        if (_x getVariable ["ace_captives_isHandcuffed",false] || {_x getVariable ["ace_captives_isSurrendering",false]}) then {continue};
        private _claim=_x getVariable ["BURNS_casualtyClaim",[]];
        if (count _claim==3 && {(_claim select 0)!=_group} && {!isNull (_claim select 0)} && {(_claim select 1)>time} && {groupOwner (_claim select 0)==(_claim select 2)}) then {continue};
    };
    private _side=if (_x isKindOf "CAManBase") then {side group _x} else {side _x};
    if (_d<_distance && {alive _x} && {!isObjectHidden _x} && {!(_side in [civilian,sideUnknown,sideLogic])} && {(side _group) getFriend _side<0.6}) then {_target=_x;_distance=_d};
} forEach _candidates;
if (isNull _target) exitWith {};
private _kind=if ([_target] call FST_HCSpawn_fnc_burnsIsDown) then {"casualty"} else {"armor"};
if (_kind=="casualty") then {
    if (_target getVariable ["ace_captives_isHandcuffed",false] || {_target getVariable ["ace_captives_isSurrendering",false]}) then {_target=objNull} else {
        private _claim=_target getVariable ["BURNS_casualtyClaim",[]];
        if (count _claim==3 && {(_claim select 0)!=_group} && {!isNull (_claim select 0)} && {(_claim select 1)>time} && {groupOwner (_claim select 0)==(_claim select 2)}) then {_target=objNull};
    };
};
if (isNull _target) exitWith {};
private _units=units _group;
if (count _units==0) exitWith {};
private _cursor=(_group getVariable ["BURNS_rifleCursor",0]) mod count _units;
_group setVariable ["BURNS_rifleCursor",_cursor+1];
private _unit=_units select _cursor;
private _range=if (_kind=="casualty") then {30} else {if (fog>=0.4 && {missionNamespace getVariable ["BURNS_LowVisibilityAssist",false]}) then {missionNamespace getVariable ["BURNS_VisibleContactRange",125]} else {250}};
private _min=if (_kind=="casualty") then {4} else {15};
if (!local _unit || {!alive _unit} || {isNil {_unit getVariable "BURNS_b1Applied"}} || {primaryWeapon _unit!="FST_E5"} || {currentWeapon _unit!="FST_E5"} || {secondaryWeapon _unit!=""} || {_unit distance _target<_min} || {_unit distance _target>_range} || {_unit ammo "FST_E5"<=0} || {abs getForcedSpeed _unit<0.01}) exitWith {};
if (vehicle _unit!=_unit || {[_unit] call FST_HCSpawn_fnc_burnsIsDown} || {_unit getVariable ["BURNS_exempt",false]} || {
    [_unit] call FST_HCSpawn_fnc_isPlayerControlledUnit
} || {!(_unit checkAIFeature "PATH")} || {!(_unit checkAIFeature "FIREWEAPON")} || {!(_unit checkAIFeature "WEAPONAIM")}) exitWith {};
if (abs ((((_unit getDir _target)-getDir _unit+540) mod 360)-180)>70) exitWith {};
if (([_unit,"VIEW",_target] checkVisibility [eyePos _unit,aimPos _target])<=0.5 || {([_unit,"FIRE",_target] checkVisibility [eyePos _unit,aimPos _target])<=0.5}) exitWith {};
private _speed=getForcedSpeed _unit;
private _wp=currentWaypoint _group;
private _revision=[_group,["BURNS_movementRevision",0]] call FST_HCSpawn_fnc_burnsStateGet;
private _eh=_unit addEventHandler ["Fired",{params ["_unit","_weapon"];if (_weapon=="FST_E5") then {
    _unit setVariable ["BURNS_lastAssistShot",diag_tickTime];
    BURNS_RifleShotsDuringAssist=(missionNamespace getVariable ["BURNS_RifleShotsDuringAssist",0])+1;
}}];
private _deadline=diag_tickTime+6;
_unit setVariable ["BURNS_pointFireLease",[clientOwner,time+10,_speed,_deadline],true];
_unit forceSpeed 0;
_group setVariable ["BURNS_pointFire",[_unit,_target,_kind,_deadline,_revision,_wp,waypointPosition [_group,_wp],_speed,clientOwner,_eh]];
_group setVariable ["BURNS_pointFireRequest",diag_tickTime];
_group setVariable ["BURNS_fireAim",nil];
if (_kind=="casualty") then {_target setVariable ["BURNS_casualtyClaim",[_group,time+9,clientOwner],true]};
BURNS_FireJobs pushBack [_group,_unit,_eh,_deadline];
