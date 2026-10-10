// B1 gait (Miran 9 Oct: "Could we make them march like how WebKnight's B1s do? Assault and the default has them march
// in orderly rows maybe sped up a little so they're not too slow. Rush lets them run like they do now").
// "march": walking gait at BURNS_B1MarchAnimSpeed (default 1.2 = ~1.7 m/s; a B1 walks 1.4 m/s at 1.0, probe mw1) with
// WebKnight's B1 rifle-carry pose when that mod is loaded (its animation only; none of its code runs).
// "run": the normal jog. "": release (garrisons, stations and holding tasks: the pose can't shoot over walls). Owner-local, except the animation speed, which every machine applies (JIP-keyed
// to the unit). Called by burnsApplyRole (every ~5 s) and the pace keeper (pose upkeep); forceWalk is set only on a gait
// change, so the pace keeper may let a lagging droid jog back to its place.
params ["_unit","_gait"];
if (isNull _unit || {!local _unit}) exitWith {};
if (isNil "BURNS_b1PoseAvailable") then {
    BURNS_b1PoseAvailable=isClass (configFile >> "CfgGesturesMale" >> "States" >> "WBK_Droids_B1_Idle") && {isClass (configFile >> "CfgGesturesMale" >> "States" >> "WBK_Droid_Disable_Gesture")};
};
// Shots fired in the pose are steered at their target by BURNS_fnc_drillShot (fn_burnsB1Volley).
private _cur=_unit getVariable ["BURNS_gait",""];
if (_cur!=_gait) then {
    _unit setVariable ["BURNS_gait",if (_gait=="") then {nil} else {_gait}];
    private _coef=if (_gait=="march") then {missionNamespace getVariable ["BURNS_B1MarchAnimSpeed",1.2]} else {1};
    // Track the value we asked for: remoteExecCall applies a frame later, so reading it back could skip a reset
    // (probe lr38: rush squads kept the march speed).
    if (abs ((_unit getVariable ["BURNS_gaitCoef",1])-_coef)>0.01) then {
        _unit setVariable ["BURNS_gaitCoef",_coef];
        [_unit,_coef] remoteExecCall ["setAnimSpeedCoef",0,_unit];
    };
    if (isForcedWalk _unit!=(_gait=="march")) then {_unit forceWalk (_gait=="march")};
    if (_gait!="march" && {BURNS_b1PoseAvailable} && {gestureState _unit=="wbk_droids_b1_idle"}) then {_unit playActionNow "WBK_Droid_Disable_Gesture"};
};
// The pose stays on through the march and its volleys (Miran 9 Oct: "none of them are using his droid march animation";
// 10 Oct: the drop/raise before each volley looked wrong). Shots fired in it are steered (BURNS_fnc_drillShot).
if (_gait=="march" && {alive _unit} && {BURNS_b1PoseAvailable}) then {
    private _pose=(missionNamespace getVariable ["BURNS_B1MarchPose",true]) && {vehicle _unit==_unit} && {_unit checkAIFeature "PATH" || {!isNil {_unit getVariable "BURNS_volleyHold"}}} && {
        !(_unit getVariable ["FST_HC_ownsPath",false]) && {!(_unit getVariable ["BURNS_ownsPath",false])}
    } && {primaryWeapon _unit!="" && {secondaryWeapon _unit==""} && {currentWeapon _unit==primaryWeapon _unit}} && {stance _unit=="STAND"} && {
        // Rifles come up once an enemy is close (BURNS_B1PoseRange, default 150 m): the pose throws shots wide.
        private _ed=(group _unit) getVariable ["BURNS_enemyDist",[-1,1e9]];
        private _d=if (time-(_ed select 0)<3) then {_ed select 1} else {private _e=_unit findNearestEnemy _unit; if (isNull _e) then {1e9} else {_unit distance2D _e}};
        _d>(missionNamespace getVariable ["BURNS_B1PoseRange",150])
    };
    private _posed=gestureState _unit=="wbk_droids_b1_idle";
    // AT droids never take the pose (probe ad45: re-posing blocked their launcher switch, 0 rockets); re-posing is
    // rate-limited to once per 2 s per droid.
    if (_pose && {!_posed} && {time>(_unit getVariable ["BURNS_poseNext",-1])}) then {_unit playActionNow "WBK_Droids_B1_Idle";_unit setVariable ["BURNS_poseNext",time+2]};
    if (!_pose && {_posed}) then {_unit playActionNow "WBK_Droid_Disable_Gesture"};
};
