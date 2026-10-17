// B1 drill volleys (Miran 6 Oct "volley fire"; 9 Oct review: "still aren't keeping a formation or volley firing at all").
// Native AI fire is a constant trickle and droids leave their slots to take shots, so no volley ever stands out.
// In contact a B1 squad now goes under drill fire control: its riflemen cannot fire (FIREWEAPON off; probe lp16: unit
// combat mode GREEN did not stop native fire) and walk in formation; every 4-5.5 s the line halts, presents on one
// visible enemy and fires together in five timed rounds. Firing is enabled only inside that volley window.
// AT droids stay under native control (rockets). Owner-local; the drilled mark is the only broadcast (on change).
params ["_group"];
private _dbg=missionNamespace getVariable ["BURNS_B1Debug",false];
private _drillOn=time<(_group getVariable ["BURNS_drillUntil",-1]);
// Release: drilled droids may aim and fire on their own again as soon as drill control lapses.
if (!_drillOn) then {
    {
        if (local _x && {_x getVariable ["BURNS_drilled",false]}) then {
            if !(_x checkAIFeature "FIREWEAPON") then {_x enableAI "FIREWEAPON"}; _x enableAI "TARGET"; _x enableAI "AUTOTARGET";
            if (!isNil {_x getVariable "BURNS_volleyHold"}) then {_x enableAI "PATH";_x setVariable ["BURNS_volleyHold",nil]};
            _x setVariable ["BURNS_drilled",nil,true];
            _x setVariable ["BURNS_volleyFiring",nil];
        };
    } forEach units _group;
};
if !(missionNamespace getVariable ["BURNS_B1VolleyEnabled",true]) exitWith {};
if !([_group,true] call FST_HCSpawn_fnc_burnsB1Eligible) exitWith {
    if (_dbg && {([leader _group] call FST_HCSpawn_fnc_burnsRole)=="b1"}) then {
        private _u=units _group select {alive _x};
        // V53: every reason fn_burnsB1Eligible checks (11 Oct op: 591 HC lines read "not eligible" with all six old reasons 0)
        [_group,format ["not eligible: held %1, not local %2, in vehicle %3, PATH off %4, not B1 %5, exempt %6, sim off %7, incap %8, player %9, protected %10, tasks %11, stance %12, grp exempt %13",
            _group getVariable ["FST_HC_heldBy",-1],{!local _x} count _u,{vehicle _x!=_x} count _u,
            {!(_x checkAIFeature "PATH") && {isNil {_x getVariable "BURNS_volleyHold"}}} count _u,
            {([_x] call FST_HCSpawn_fnc_burnsRole)!="b1"} count _u,{_x getVariable ["BURNS_exempt",false]} count _u,
            {!simulationEnabled _x} count _u,{lifeState _x=="INCAPACITATED"} count _u,{[_x] call FST_HCSpawn_fnc_isPlayerControlledUnit} count _u,
            [_group] call FST_HCSpawn_fnc_isProtectedVehicleGroup,missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true],
            missionNamespace getVariable ["FST_HC_DroidStanceEnabled",true],_group getVariable ["BURNS_exempt",false]]] call BURNS_fnc_dbgWhy;
    };
};
private _mode=([_group,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet) param [0,""];
if !(_mode in ["assault","rush","hunt"]) exitWith {if (_dbg) then {[_group,"no drill task ("+_mode+")"] call BURNS_fnc_dbgWhy}};
private _leader=leader _group;
// Fire at will (Miran 9 Oct: "non volley fire is better than no fire"): drill control is released at once in close
// combat (an enemy within 40 m), while the squad is not advancing (waiting for the battle line or at its objective,
// fn_burnsB1Advance), or when the drill has not managed a volley for 12 s (then no drill for 15 s).
private _close=(_leader nearTargets 40) findIf {
    private _o=_x select 4; !isNull _o && {alive _o} && {(side _group) getFriend (_x select 2)<0.6} && {!((_x select 2) in [civilian,sideUnknown,sideLogic])}
}>=0;
private _holding=!(_group getVariable ["BURNS_trackGo",true]);
// Cost (Miran 10 Oct: "make sure this won't make us lower droid counts"): drill only near players (BURNS_B1DrillRange,
// default 1200 m; 0 = everywhere). Squads nobody can see fight natively.
private _range=missionNamespace getVariable ["BURNS_B1DrillRange",1200];
private _far=_range>0 && {((missionNamespace getVariable ["BURNS_PlayerPositions",[]]) findIf {(_x distance2D (getPosWorld _leader))<_range})<0};
private _stale=_drillOn && {time-((_group getVariable ["BURNS_drillSince",time]) max (_group getVariable ["BURNS_lastVolley",-1]))>12};
if (_stale) then {_group setVariable ["BURNS_drillBlock",time+15]};
if (_close || {_holding} || {_far} || {_stale} || {time<(_group getVariable ["BURNS_drillBlock",-1])}) exitWith {
    if (_dbg) then {[_group,"released: "+(if (_close) then {"enemy within 40 m"} else {if (_holding) then {"holding"} else {if (_far) then {"far from players"} else {if (_stale) then {"no volley for 12 s"} else {"blocked after stale"}}}})] call BURNS_fnc_dbgWhy};
    _group setVariable ["BURNS_drillUntil",-1];
    _group setVariable ["BURNS_drillSince",nil];
    {
        if (local _x && {_x getVariable ["BURNS_drilled",false]}) then {
            if !(_x checkAIFeature "FIREWEAPON") then {_x enableAI "FIREWEAPON"}; _x enableAI "TARGET"; _x enableAI "AUTOTARGET";
            if (!isNil {_x getVariable "BURNS_volleyHold"}) then {_x enableAI "PATH";_x setVariable ["BURNS_volleyHold",nil]};
            _x setVariable ["BURNS_drilled",nil,true];
            _x setVariable ["BURNS_volleyFiring",nil];
        };
    } forEach units _group;
};
// Target: nearest perceived enemy 20-450 m (native B1s open fire from ~380 m, probe lp17). The sight ray starts 1.5 m toward the target so the
// viewer's own body does not block it (probe 6 Oct: ~300 false "no target").
// V53 (Miran 11 Oct op: module squads on HCs "not much volley fire"; probe hls51: squads knew the targets their riflemen were already shooting
// at only 0.86-0.92): squad knowledge >= 0.5 (was 1), and the leader OR the rifleman engaging that target may be the one who sees it; if the
// leader's scan finds nothing, a rifleman's own assigned target that he can see is used.
private _target=objNull;
private _best=450;
private _seeFrom={
    params ["_u","_p"];
    private _eye=eyePos _u;
    _eye=_eye vectorAdd ((vectorNormalized ((aimPos _p) vectorDiff _eye)) vectorMultiply 1.5);
    ([_u,"VIEW",_p] checkVisibility [_eye,aimPos _p])>0.5
};
private _engaging=(units _group) select {alive _x && {local _x} && {!isNull assignedTarget _x}};
{
    _x params ["_pos","","_side","","_obj"];
    if (isNull _obj || {!alive _obj} || {captive _obj} || {isObjectHidden _obj} || {_side in [civilian,sideUnknown,sideLogic]} || {(side _group) getFriend _side>=0.6}) then {continue};
    private _p=vehicle _obj;
    if (_p isKindOf "Air" || {[_obj] call FST_HCSpawn_fnc_burnsIsDown}) then {continue};
    private _d=_leader distance2D _p;
    if (_d<_best && {_d>20} && {_group knowsAbout _p>=0.5} && {
        ([_leader,_p] call _seeFrom) || {(_engaging findIf {(vehicle assignedTarget _x)==_p && {[_x,_p] call _seeFrom}})>=0}
    }) then {_best=_d;_target=_p};
} forEach (_leader nearTargets 450);
if (isNull _target) then {
    {
        private _p=vehicle (assignedTarget _x);
        if (alive _p && {!(_p isKindOf "Air")} && {(side _group) getFriend (side group _p)<0.6} && {!([_p] call FST_HCSpawn_fnc_burnsIsDown)} && {
            (_leader distance2D _p)>20 && {(_leader distance2D _p)<450}
        } && {[_x,_p] call _seeFrom}) exitWith {_target=_p};
    } forEach _engaging;
};
if (isNull _target) exitWith {if (_dbg) then {[_group,"no visible target"] call BURNS_fnc_dbgWhy}};
// Drill members: B1 riflemen on foot (no launcher; probes lp27/V31: drilled AT droids froze or drifted 50-116 m).
// The lease runs 8 s past the last sighting.
private _drill=(units _group) select {
    alive _x && {local _x} && {vehicle _x==_x} && {!(_x getVariable ["BURNS_exempt",false])} && {!([_x] call FST_HCSpawn_fnc_isPlayerControlledUnit)} && {
        primaryWeapon _x!="" && {secondaryWeapon _x==""} && {([_x] call FST_HCSpawn_fnc_burnsRole)=="b1"}
    }
};
if (count _drill<3) exitWith {if (_dbg) then {[_group,"under 3 riflemen"] call BURNS_fnc_dbgWhy}};
// Only riflemen who can see the drill target are drilled (Miran 17 Oct, Aparra: "A lot of the droids here were just standing around
// instead of firing" - a squad in a treeline). A drilled droid has its own fire off and fires only at the drill target, so in woods
// most of the squad stood silent while the few with a view volleyed. The rest are released to fire on their own at what they see.
private _sees=_drill select {[_x,_target] call _seeFrom};
{
    if (local _x && {_x getVariable ["BURNS_drilled",false]}) then {
        if !(_x checkAIFeature "FIREWEAPON") then {_x enableAI "FIREWEAPON"}; _x enableAI "TARGET"; _x enableAI "AUTOTARGET";
        if (!isNil {_x getVariable "BURNS_volleyHold"}) then {_x enableAI "PATH";_x setVariable ["BURNS_volleyHold",nil]};
        _x setVariable ["BURNS_drilled",nil,true];
        _x setVariable ["BURNS_volleyFiring",nil];
    };
} forEach (_drill-_sees);
if (_dbg && {count _sees<count _drill}) then {diag_log format ["[BURNS_DBG] drill %1: %2 of %3 riflemen see the target; the rest fire on their own",_group,count _sees,count _drill]};
_drill=_sees;
// ...and only those who could take part in a volley: within 40 m of the leader and facing within 60 degrees of the target (the
// shooter test below). Op log 17 Oct (Aparra Sat-1, Bravo 2-2, 46 droids): the whole squad was drilled - own fire off - while
// too few faced the target to volley, so it stood silent until the 12 s stale release, fired on its own for 15 s, and was drilled
// again (12:37:10 drilling, 12:37:23 "no volley for 12 s"). Droids that cannot volley now keep firing on their own.
private _able=_drill select {
    currentWeapon _x==primaryWeapon _x && {_x ammo (primaryWeapon _x)>0} && {_x distance2D _leader<40} && {
        abs ((((_x getDir _target)-getDir _x+540) mod 360)-180)<60
    }
};
{
    if (local _x && {_x getVariable ["BURNS_drilled",false]}) then {
        if !(_x checkAIFeature "FIREWEAPON") then {_x enableAI "FIREWEAPON"}; _x enableAI "TARGET"; _x enableAI "AUTOTARGET";
        if (!isNil {_x getVariable "BURNS_volleyHold"}) then {_x enableAI "PATH";_x setVariable ["BURNS_volleyHold",nil]};
        _x setVariable ["BURNS_drilled",nil,true];
        _x setVariable ["BURNS_volleyFiring",nil];
    };
} forEach (_drill-_able);
_drill=_able;
if (count _drill<3) exitWith {
    if (_dbg) then {[_group,"under 3 riflemen can volley the target"] call BURNS_fnc_dbgWhy};
    _group setVariable ["BURNS_drillUntil",-1];
};
// Drill-shot steering: a scripted drill round (BURNS_aimTarget/BURNS_aimUntil set just before it) or any round fired in the
// WebKnight march pose goes at its target with a random spread (BURNS_B1AimSpread, sigma degrees, default 0.15: ~28%
// on a standing man at 200 m, about like aimed native fire). Probe ap1 at 200 m: posed 0/20 hits, steered at the target
// 20/20, unposed 5/20. The pose throws the muzzle ~0.4 degrees off, and walking droids do not aim at all.
// BURNS_fnc_drillShot is defined in XEH_preInit (every machine); fn_burnsB1Gait also puts it on marching riflemen.
{if (isNil {_x getVariable "BURNS_drillShotEH"}) then {_x setVariable ["BURNS_drillShotEH",_x addEventHandler ["Fired",{_this call BURNS_fnc_drillShot}]]}} forEach _drill;
if (!_drillOn) then {_group setVariable ["BURNS_drillSince",time]};
_group setVariable ["BURNS_drillUntil",time+8];
_group setVariable ["BURNS_drillTarget",_target];
if (_dbg) then {[_group,"drilling"] call BURNS_fnc_dbgWhy};
{
    // No native aiming either (probe lp47: 68% of the remaining stops were droids told to walk but halted to aim at a
    // target they could not shoot). Drill shots need no AI aim: they are steered (BURNS_fnc_drillShot).
    if (_x checkAIFeature "FIREWEAPON") then {_x disableAI "FIREWEAPON"};
    if (_x checkAIFeature "AUTOTARGET") then {_x disableAI "AUTOTARGET"; _x disableAI "TARGET"};
    if !(_x getVariable ["BURNS_drilled",false]) then {_x setVariable ["BURNS_drilled",true,true]};
} forEach _drill;
// A watcher on this owner releases the squad even if the engagement service stops visiting it.
if (isNil {_group getVariable "BURNS_drillWatch"}) then {
    _group setVariable ["BURNS_drillWatch",true];
    if (isNil "BURNS_fnc_drillWatch") then {
        BURNS_fnc_drillWatch={
            params ["_g"];
            if (isNull _g) exitWith {};
            if (time<(_g getVariable ["BURNS_drillUntil",-1])) exitWith {[BURNS_fnc_drillWatch,[_g],3] call CBA_fnc_waitAndExecute};
            _g setVariable ["BURNS_drillWatch",nil];
            {
                if (local _x && {_x getVariable ["BURNS_drilled",false]}) then {
                    if !(_x checkAIFeature "FIREWEAPON") then {_x enableAI "FIREWEAPON"}; _x enableAI "TARGET"; _x enableAI "AUTOTARGET";
                    if (!isNil {_x getVariable "BURNS_volleyHold"}) then {_x enableAI "PATH";_x setVariable ["BURNS_volleyHold",nil]};
                    _x setVariable ["BURNS_drilled",nil,true];
                    _x setVariable ["BURNS_volleyFiring",nil];
                };
            } forEach units _g;
        };
    };
    [BURNS_fnc_drillWatch,[_group],3] call CBA_fnc_waitAndExecute;
};
{if (!(_x checkAIFeature "PATH") && {time>(_x getVariable ["BURNS_volleyHold",-1])} && {!isNil {_x getVariable "BURNS_volleyHold"}}) then {_x enableAI "PATH";_x setVariable ["BURNS_volleyHold",nil]}} forEach _drill;
if (time<(_group getVariable ["BURNS_volleyNext",-1])) exitWith {};
// Shooters: drill members with the squad (within 40 m of the leader), rifle in hand, not facing away.
private _shooters=_drill select {
    currentWeapon _x==primaryWeapon _x && {_x ammo (primaryWeapon _x)>0} && {_x distance2D _leader<40} && {
        abs ((((_x getDir _target)-getDir _x+540) mod 360)-180)<60
    } && {count (_x getVariable ["BURNS_pointFireLease",[]])!=4}
};
if (count _shooters<3) exitWith {};
_group setVariable ["BURNS_volleyNext",time+7+random 1.5];
// Walking volley (Miran 10 Oct: "we need them constantly advancing ideally, no stops"): no halt and no aim orders (both
// make Arma units stop; after a halt the line stood 2-3 s before walking again). The droids keep walking with native
// fire off and fire scripted rounds; each round is steered at the target (BURNS_fnc_drillShot).
{_x setVariable ["BURNS_volleyFiring",true]} forEach _shooters;
_group setVariable ["BURNS_lastVolley",time];
BURNS_B1Volleys=(missionNamespace getVariable ["BURNS_B1Volleys",0])+1;
// Every 0.1 s: on target = rifle within 4 degrees of the target and own line of fire clear (probe 6 Oct: rounds fired
// off-aim or through the droids in front hit 6-8% vs ~35% native). "Fire!" comes once 75% of the line is on target or
// 1.5 s after the order. Ragged on purpose (Miran 10 Oct: "avoid having them all fire the exact split second"): each
// droid starts within 0.25 s of the order and spaces its five rounds 0.2-0.32 s apart, so the volley rolls along the
// line for about 1.5 s. Afterwards the line walks on.
if (isNil "BURNS_fnc_drillStep") then {
    BURNS_fnc_drillStep={
        params ["_shooters","_target","_t0","_fireAt","_next","_rounds"];
        private _now=diag_tickTime;
        private _live=0;
        if (_fireAt<0) then {_fireAt=_now;_next=_shooters apply {_now+random 0.25}};
        {
            private _u=_x;
            if ((_rounds select _forEachIndex)>=5 || {!alive _target} || {!alive _u} || {!local _u} || {currentWeapon _u!=primaryWeapon _u} || {_u ammo (primaryWeapon _u)<1}) then {continue};
            _live=_live+1;
            if (_now<(_next select _forEachIndex)) then {continue};
            // Facing the target (within 50 degrees) and a clear line of fire from the droid's own eyes.
            private _dir=vectorNormalized ((aimPos _target) vectorDiff (eyePos _u));
            if (abs ((((_u getDir _target)-getDir _u+540) mod 360)-180)>50 || {
                ([_u,"VIEW",_target] checkVisibility [(eyePos _u) vectorAdd (_dir vectorMultiply 1.5),aimPos _target])<0.5
            }) then {_next set [_forEachIndex,_now+0.15];continue};
            private _w=primaryWeapon _u;
            private _m=(getArray (configFile >> "CfgWeapons" >> _w >> "modes")) param [0,"this"];
            _u setVariable ["BURNS_volleyShotUntil",_now+0.2];
            _u setVariable ["BURNS_aimTarget",_target];_u setVariable ["BURNS_aimUntil",_now+0.3];
            _u forceWeaponFire [_w,if (_m=="this") then {_w} else {_m}];
            _rounds set [_forEachIndex,(_rounds select _forEachIndex)+1];
            _next set [_forEachIndex,_now+0.2+random 0.12];
            BURNS_B1VolleyShots=(missionNamespace getVariable ["BURNS_B1VolleyShots",0])+1;
        } forEach _shooters;
        if (_live>0 && {_now<_fireAt+2.5}) then {
            [BURNS_fnc_drillStep,[_shooters,_target,_t0,_fireAt,_next,_rounds],0.15] call CBA_fnc_waitAndExecute;
        } else {
            {
                if (alive _x && {local _x} && {!([_x] call FST_HCSpawn_fnc_isPlayerControlledUnit)}) then {
                    _x setVariable ["BURNS_volleyFiring",nil];
                    if (!isNil {_x getVariable "BURNS_volleyHold"}) then {
                        _x setVariable ["BURNS_volleyHold",nil];
                        _x enableAI "PATH";
                    };
                };
            } forEach _shooters;
        };
    };
};
[BURNS_fnc_drillStep,[_shooters,_target,diag_tickTime,-1,[],_shooters apply {0}],0.1] call CBA_fnc_waitAndExecute;
