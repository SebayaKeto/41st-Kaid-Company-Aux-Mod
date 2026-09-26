// Only the current owner sends global animation/damage changes.
params ["_vehicle","_epoch"];
if (isNull _vehicle || {!alive _vehicle} || {!local _vehicle} || {(_vehicle getVariable ["FST_raiderOwnerEpoch",-1])!=_epoch}) exitWith {};
_vehicle setVariable ["FST_raiderOwnerTicks",(_vehicle getVariable ["FST_raiderOwnerTicks",0])+1];
private _cmd=effectiveCommander _vehicle;
if (!isNull _cmd && {isTurnedOut _cmd} && {_vehicle animationSourcePhase "main_hatch_rotate"<0.5}) then {
    _vehicle animateSource ["main_hatch_rotate",1,true];
    _vehicle setVariable ["FST_raiderAnimationWrites",(_vehicle getVariable ["FST_raiderAnimationWrites",0])+1];
};
private _gunner=gunner _vehicle;
private _weapon=if (isNull _gunner) then {""} else {currentWeapon _gunner};
private _phase=if (_weapon=="FST_VW_Sabre_LG_MissileLauncher") then {1} else {0};
if (abs ((_vehicle animationSourcePhase "MissilePods")-_phase)>0.01) then {
    _vehicle animateSource ["MissilePods",_phase,true];
    _vehicle setVariable ["FST_raiderAnimationWrites",(_vehicle getVariable ["FST_raiderAnimationWrites",0])+1];
};
// Preserve the existing armor rule and polling cadence, now ownership-safe.
if ((["HitLSideArmor","HitRSideArmor","HitRearArmor"] findIf {_vehicle getHitPointDamage _x>=1})>=0 && {_vehicle getHitPointDamage "HitHull">0.5}) then {
    _vehicle setHitPointDamage ["HitHull",0.5];
};
