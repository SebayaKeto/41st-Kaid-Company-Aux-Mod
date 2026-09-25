// Add pursuit gaits without replacing the installed creature controller.
params ["_unit"];
if (isNull _unit || {!local _unit} || {!(_unit isKindOf "JMSEF_animals_varren_o")}) exitWith {};
private _animation=toLower animationState _unit;
private _ours=_animation in ["burns_gulanthar_run","burns_gulanthar_climb"];
private _g=group _unit;
private _wp=currentWaypoint _g;
private _manual=_wp>0 && {_wp<count waypoints _g} && {!(waypointDescription [_g,_wp] in ["FST HC combat","BURNS patrol"])};
private _allowed=alive _unit && {!([_unit] call FST_HCSpawn_fnc_isPlayerControlledUnit)} && {
    missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]
} && {!(_g getVariable ["BURNS_exempt",false])} && {!(_unit getVariable ["BURNS_exempt",false])} && {
    (_g getVariable ["FST_HC_heldBy",-1])==-1
} && {!_manual} && {vehicle _unit==_unit} && {isNull attachedTo _unit} && {
    (_g getVariable ["BURNS_creatureTaskIntent",""]) in ["","hunt","assault","rush","cqb"]
} && {
    (_unit getVariable ["mode",-1])==2
} && {_unit checkAIFeature "ANIM"} && {_unit checkAIFeature "PATH"} && {_unit checkAIFeature "MOVE"} && {
    !([_unit] call FST_HCSpawn_fnc_burnsIsDown)
};
if (!_allowed) exitWith {
    if (_ours && {alive _unit}) then {_unit playMoveNow "form939_walk"};
    _unit setVariable ["BURNS_creatureProgress",nil];
};
// Never interrupt attacks, eating, death or the native stuck handler's ANIM lease.
if !(_animation in ["form939_idle","form939_idle2","form939_idle3","form939_walk","form939_sprint","burns_gulanthar_climb","burns_gulanthar_run"]) exitWith {};
if (time<(_unit getVariable ["BURNS_creatureGaitNext",-1])) exitWith {};
_unit setVariable ["BURNS_creatureGaitNext",time+0.3];
// Follow the native controller's movement intent. Its automatic detection need
// not create an Arma knowsAbout entry, and losing sight must not cancel a run.
private _destination=(expectedDestination _unit) param [0,getPosATL _unit];
private _pursuit=currentCommand _unit=="MOVE" && {!unitReady _unit} && {getForcedSpeed _unit!=0} && {
    _unit distance2D _destination>3
};
private _normal=surfaceNormal getPosATL _unit;
private _dir=getDir _unit;
private _incline=atan (-((_normal select 0)*sin _dir+(_normal select 1)*cos _dir)/((_normal select 2) max 0.001));
private _desired="";
if (_pursuit && {isTouchingGround _unit}) then {
    if (missionNamespace getVariable ["BURNS_GulantharSlopeEnabled",true] && {_incline> (if (_animation=="burns_gulanthar_climb") then {4} else {9})} && {_incline<33}) then {
        _desired="BURNS_gulanthar_climb";
    } else {
        if (missionNamespace getVariable ["BURNS_GulantharRunEnabled",true] && {_incline>=-20} && {_incline<=9}) then {_desired="BURNS_gulanthar_run"};
    };
};
if (_desired=="") exitWith {if (_ours) then {_unit playMoveNow "form939_walk"};_unit setVariable ["BURNS_creatureProgress",nil]};
private _progress=_unit getVariable ["BURNS_creatureProgress",[getPosATL _unit,time]];
if (_unit distance2D (_progress select 0)>1) then {_progress=[getPosATL _unit,time]};
if (time-(_progress select 1)>1.5 && {abs speed _unit<1}) then {
    // Only the stalled-order recovery acquires a target, using visible knowledge.
    private _enemy=_unit findNearestEnemy _unit;
    if (!isNull _enemy && {alive _enemy} && {!captive _enemy} && {!isObjectHidden _enemy} && {
        _unit knowsAbout _enemy>=1
    } && {_unit distance _enemy>12} && {_unit distance _enemy<200} && {
        ([_unit,"VIEW",vehicle _enemy] checkVisibility [eyePos _unit,aimPos vehicle _enemy])>0.5
    }) then {
        _unit doMove getPosATL _enemy;
        _unit setVariable ["BURNS_creatureRecoveries",(_unit getVariable ["BURNS_creatureRecoveries",0])+1];
    };
    _progress=[getPosATL _unit,time+2];
};
_unit setVariable ["BURNS_creatureProgress",_progress];
// A gait changes how an existing move is performed; it must not create motion
// while the native controller is intentionally stationary.
if (currentCommand _unit!="MOVE" || {unitReady _unit} || {getForcedSpeed _unit==0}) exitWith {if (_ours) then {_unit playMoveNow "form939_walk"}};
if (_animation!=toLower _desired) then {
    private _moves=getText(configOf _unit >> "moves");
    if (isClass(configFile >> _moves >> "States" >> _desired)) then {
        _unit playMoveNow _desired;
        _unit setVariable ["BURNS_creatureGaitEntries",(_unit getVariable ["BURNS_creatureGaitEntries",0])+1];
    };
};
