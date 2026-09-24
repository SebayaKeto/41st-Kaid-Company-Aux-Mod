// Creature-specific gait correction. No animation-speed multiplier, teleport,
// damage changes or replacement of the creature's hunt/attack controller.
params ["_unit"];
if (!(_unit isKindOf "JMSEF_animals_varren_o") || {!local _unit} || {!alive _unit} || {
    [_unit] call FST_HCSpawn_fnc_isPlayerControlledUnit
}) exitWith {};
private _animation=toLower animationState _unit;
private _climbing=_animation=="burns_gulanthar_climb";
private _mode=_unit getVariable ["mode",-1];
private _g=group _unit;
private _canHelp=missionNamespace getVariable ["BURNS_GulantharSlopeEnabled",true] && {missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]} && {!(_g getVariable ["BURNS_exempt",false])} && {!(_unit getVariable ["BURNS_exempt",false])} && {(_g getVariable ["FST_HC_heldBy",-1])==-1};
if (_canHelp && {_mode==2} && {_unit checkAIFeature "ANIM"} && {_unit checkAIFeature "PATH"} && {_animation in ["form939_idle","form939_walk","burns_gulanthar_climb"]}) then {
    private _progress=_unit getVariable ["BURNS_creatureProgress",[getPosATL _unit,time]];
    if (_unit distance2D (_progress select 0)>1) then {_progress=[getPosATL _unit,time]};
    if (time-(_progress select 1)>1.5 && {abs speed _unit<1} && {currentWaypoint _g<=0 || {currentWaypoint _g>=count waypoints _g}}) then {
        private _enemy=_unit findNearestEnemy _unit;
        if (!isNull _enemy && {alive _enemy} && {_unit knowsAbout _enemy>=1} && {_unit distance _enemy>5} && {_unit distance _enemy<100} && {([_unit,"VIEW",_enemy] checkVisibility [eyePos _unit,aimPos _enemy])>0.5}) then {
            _unit doMove getPosATL _enemy;
            _unit setVariable ["BURNS_creatureRecoveries",(_unit getVariable ["BURNS_creatureRecoveries",0])+1];
        };
        _progress=[getPosATL _unit,time+2];
    };
    _unit setVariable ["BURNS_creatureProgress",_progress];
} else {_unit setVariable ["BURNS_creatureProgress",nil]};
private _normal=surfaceNormal getPosATL _unit;
private _dir=getDir _unit;
private _incline=atan (-((_normal select 0)*sin _dir+(_normal select 1)*cos _dir)/((_normal select 2) max 0.001));
private _active=missionNamespace getVariable ["BURNS_GulantharSlopeEnabled",true] && {
    missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]
} && {!((group _unit) getVariable ["BURNS_exempt",false])} && {((group _unit) getVariable ["FST_HC_heldBy",-1])==-1} && {
    (_unit getVariable ["mode",-1])==2
} && {_unit checkAIFeature "ANIM"} && {_unit checkAIFeature "PATH"} && {
    isTouchingGround _unit && {_incline>(if (_climbing) then {4} else {9})} && {_incline<(if (_climbing) then {38} else {33})}
} && {!(_unit getVariable ["BURNS_exempt",false])};
if (!_active) exitWith {if (_climbing) then {_unit playMoveNow "form939_walk"}};
if (_animation!="form939_walk" || {abs speed _unit>9}) exitWith {};
private _moves=getText(configOf _unit >> "moves");
if !(isClass(configFile >> _moves >> "States" >> "BURNS_gulanthar_climb")) exitWith {};
_unit playMoveNow "BURNS_gulanthar_climb";
BURNS_GulantharClimbEntries=(missionNamespace getVariable ["BURNS_GulantharClimbEntries",0])+1;
