// B1 line pace keeper (Miran 9 Oct review: "still aren't keeping a formation"). Between the 2 s track orders of
// fn_burnsB1Advance, every ~0.5 s each droid's speed (leader included) is re-matched to its place in the line, which forms
// on the squad's average position: faster when behind its place, easing off and stopping when ahead. Called by the
// engagement service. Owner-local, forceSpeed only.
params ["_group"];
private _tr=_group getVariable ["BURNS_track",[]];
if (count _tr!=6 || {time-(_tr select 0)>5}) exitWith {};
if (time<(_group getVariable ["BURNS_paceNext",-1])) exitWith {};
_group setVariable ["BURNS_paceNext",time+0.75];
_tr params ["","_fwd","_right","_lead0","_ordered","_offs"];
private _leader=leader _group;
if (!alive _leader || {!local _leader} || {_leader!=(_ordered select 0)}) exitWith {};
// Cost: only for squads near players (BURNS_B1DrillRange, 0 = everywhere); fn_burnsB1Advance still keeps far lines.
private _range=missionNamespace getVariable ["BURNS_B1DrillRange",1200];
if (_range>0 && {((missionNamespace getVariable ["BURNS_PlayerPositions",[]]) findIf {(_x distance2D (getPosWorld _leader))<_range})<0}) exitWith {};
private _lead=if (time<(_leader getVariable ["BURNS_volleyHold",-1])) then {0} else {_lead0};
// One enemy-distance query per squad (the march pose reads it) and one armour query when an AT droid needs it.
private _enemy=_leader findNearestEnemy _leader;
_group setVariable ["BURNS_enemyDist",[time,if (isNull _enemy) then {1e9} else {_leader distance2D _enemy}]];
private _armourNear=-1;
private _lp=getPosATL _leader;
private _anchor=0; private _n=0;
{if (alive _x && {_x==_leader || {secondaryWeapon _x==""}}) then {_anchor=_anchor+((((getPosATL _x) vectorDiff _lp) vectorDotProduct _fwd)+((_offs select _forEachIndex) select 1));_n=_n+1}} forEach _ordered;
_anchor=_anchor/(_n max 1);
{
    private _u=_x;
    if (!alive _u || {!local _u} || {time<(_u getVariable ["BURNS_volleyHold",-1])}) then {continue};
    private _lease=_u getVariable ["BURNS_pointFireLease",[]];
    if (count _lease==4 && {time<(_lease select 1)}) then {continue};
    (_offs select _forEachIndex) params ["_o","_b"];
    private _ideal=_lp vectorAdd (_right vectorMultiply _o) vectorAdd (_fwd vectorMultiply (_anchor-_b));
    private _along=((getPosATL _u) vectorDiff _ideal) vectorDotProduct _fwd;
    private _speed=if (_along>0) then {_lead*((1-_along/3) max 0)} else {
        if (_lead<0.1) then {if (_u distance2D _ideal<1.5) then {0} else {((-_along*0.5) max 0.8) min 2.5}} else {(_lead+((-_along*0.5) min 1.5)) min 4.5}
    };
    if (abs (getForcedSpeed _u-_speed)>0.1) then {_u forceSpeed _speed};
    // Marching droids walk in step; one more than 4 m behind its place may jog back (walks again within 2 m).
    if ((_u getVariable ["BURNS_gait",""])=="march") then {
        private _walk=if (isForcedWalk _u) then {_along>-4} else {_along>-2};
        if (_walk!=isForcedWalk _u) then {_u forceWalk _walk};
        [_u,"march"] call FST_HCSpawn_fnc_burnsB1Gait;
    };
    // AT droid catch-up (Miran 9 Oct: "AT droid sometimes lags behind"; probe lp36: p90 up to 32 m behind). AT droids stay
    // under native control for their launchers, and native AI stops to shoot. One more than 8 m behind its place with no
    // enemy vehicle to engage stops engaging (FIREWEAPON + AUTOTARGET off) and walks back; within 3 m, or after 15 s, it
    // fights normally again. With armour about it never holds fire.
    if (secondaryWeapon _u!="" && {!(_u getVariable ["BURNS_drilled",false])}) then {
        private _since=_u getVariable ["BURNS_atCatchUp",-1];
        private _at=assignedTarget _u;
        if (_armourNear<0) then {_armourNear=[0,1] select ((((leader _group) nearTargets 500) findIf {
            private _o=_x select 4; !isNull _o && {alive _o} && {(side _group) getFriend (_x select 2)<0.6} && {_o isKindOf "LandVehicle"}
        })>=0)};
        private _armour=(!isNull _at && {alive _at} && {!(_at isKindOf "CAManBase")}) || {_armourNear==1};
        if (_since<0) then {
            if (_along<-8 && {!_armour}) then {
                _u disableAI "FIREWEAPON"; _u disableAI "AUTOTARGET"; _u doWatch objNull; _u doTarget objNull;
                _u setVariable ["BURNS_atCatchUp",time];
                private _tg=_u getVariable ["BURNS_trackGoal",[]];
                if (count _tg>=2) then {_u doMove _tg};
            };
        } else {
            if (_along>-3 || {_armour} || {time-_since>15}) then {
                _u enableAI "FIREWEAPON"; _u enableAI "AUTOTARGET";
                _u setVariable ["BURNS_atCatchUp",nil];
            };
        };
    };
    // Aimed shots between volleys (Miran 9 Oct: "non volley fire is better than no fire"; probe lp33: riflemen silent 70%
    // of contact seconds). A drilled droid facing its target (within 50 degrees, own line of fire clear) takes a single
    // steered shot (BURNS_fnc_drillShot) every 1-2 s while it walks. No aiming orders, so the line never stops (lp24).
    if (_u getVariable ["BURNS_drilled",false] && {!(_u getVariable ["BURNS_volleyFiring",false])} && {time>(_u getVariable ["BURNS_skirmishNext",-1])} && {currentWeapon _u==primaryWeapon _u} && {_u ammo (primaryWeapon _u)>0}) then {
        private _t=assignedTarget _u;
        if (isNull _t || {!alive _t}) then {_t=_group getVariable ["BURNS_drillTarget",objNull]};
        if (!isNull _t && {alive _t} && {_u distance2D _t<450}) then {
            private _dir=vectorNormalized ((aimPos _t) vectorDiff (eyePos _u));
            if (abs ((((_u getDir _t)-getDir _u+540) mod 360)-180)<=50 && {([_u,"VIEW",_t] checkVisibility [(eyePos _u) vectorAdd (_dir vectorMultiply 1.5),aimPos _t])>=0.5}) then {
                private _w=primaryWeapon _u;
                private _m=(getArray (configFile >> "CfgWeapons" >> _w >> "modes")) param [0,"this"];
                _u setVariable ["BURNS_aimTarget",_t];_u setVariable ["BURNS_aimUntil",diag_tickTime+0.3];
                _u forceWeaponFire [_w,if (_m=="this") then {_w} else {_m}];
                _u setVariable ["BURNS_skirmishNext",time+1+random 1];
            };
        };
    };
} forEach _ordered;
