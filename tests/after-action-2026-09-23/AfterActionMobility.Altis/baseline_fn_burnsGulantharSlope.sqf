// Creature-specific gait correction. No animation-speed multiplier, teleport,
// damage changes or replacement of the creature's hunt/attack controller.
params ["_unit"];
if (!(_unit isKindOf "JMSEF_animals_varren_o") || {!local _unit} || {!alive _unit} || {
    [_unit] call FST_HCSpawn_fnc_isPlayerControlledUnit
}) exitWith {};
private _animation=toLower animationState _unit;
private _climbing=_animation=="burns_gulanthar_climb";
private _normal=surfaceNormal getPosATL _unit;
private _dir=getDir _unit;
private _incline=atan (-((_normal select 0)*sin _dir+(_normal select 1)*cos _dir)/((_normal select 2) max 0.001));
private _active=missionNamespace getVariable ["BURNS_GulantharSlopeEnabled",true] && {
    missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]
} && {!((group _unit) getVariable ["BURNS_exempt",false])} && {((group _unit) getVariable ["FST_HC_heldBy",-1])==-1} && {
    (_unit getVariable ["mode",-1])==2
} && {_unit checkAIFeature "ANIM"} && {_unit checkAIFeature "PATH"} && {
    isTouchingGround _unit && {_incline>7} && {_incline<35}
} && {!(_unit getVariable ["BURNS_exempt",false])};
if (!_active) exitWith {if (_climbing) then {_unit playMoveNow "form939_walk"}};
if (_animation!="form939_walk" || {abs speed _unit>9}) exitWith {};
private _moves=getText(configOf _unit >> "moves");
if !(isClass(configFile >> _moves >> "States" >> "BURNS_gulanthar_climb")) exitWith {};
_unit playMoveNow "BURNS_gulanthar_climb";
BURNS_GulantharClimbEntries=(missionNamespace getVariable ["BURNS_GulantharClimbEntries",0])+1;
