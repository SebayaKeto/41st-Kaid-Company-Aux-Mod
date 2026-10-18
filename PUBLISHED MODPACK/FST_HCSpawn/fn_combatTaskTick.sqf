// BURNS: original group tactics above Arma's native combat AI.
// nearTargets supplies perceived contact positions, not an allUnits enemy scan.
params ["_group"];
if (isNull _group || {!local _group}) exitWith {};
if ([_group] call FST_HCSpawn_fnc_isProtectedVehicleGroup) exitWith {[_group] call FST_HCSpawn_fnc_burnsSuspendTask};
if (_group getVariable ["BURNS_exempt", false]) exitWith {[_group] call FST_HCSpawn_fnc_burnsSuspendTask};
private _task = ([_group,["FST_HC_combatTask", []]] call FST_HCSpawn_fnc_burnsStateGet);
if (count _task != 3) exitWith {[_group] call FST_HCSpawn_fnc_burnsSuspendTask};
if ((units _group findIf {([_x] call FST_HCSpawn_fnc_isPlayerControlledUnit)}) >= 0) exitWith {[_group] call FST_HCSpawn_fnc_burnsSuspendTask};
private _held=_group getVariable ["FST_HC_heldBy",-1];
if (_held!=-1 && {(_group getVariable ["BURNS_manualHeldOwner",-2])!=_held}) exitWith {[_group] call FST_HCSpawn_fnc_burnsSuspendTask};
private _leader = leader _group;
if (isNull _leader || {!alive _leader} || {!simulationEnabled _leader}) exitWith {[_group] call FST_HCSpawn_fnc_burnsSuspendTask};

// This records the owner actually servicing the task even if a valid waypoint
// needs no new order after a handoff.
if ((_group getVariable ["FST_HC_taskLastOwner", -1]) != clientOwner) then {
    _group setVariable ["FST_HC_taskLastOwner", clientOwner, true];
};
// Straggler regroup (Miran 6 Oct): a B1 squad cut down to 1-2 droids joins the nearest friendly
// B1 squad on a combat task (3+ alive, 12 max after joining, within 300 m) instead of wandering
// on alone. Held/Zeus/player groups never qualify (burnsB1Eligible + the checks above).
private _merged=false;
if (missionNamespace getVariable ["BURNS_B1Regroup",true] && {time>=(_group getVariable ["BURNS_regroupNext",-1])}) then {
    _group setVariable ["BURNS_regroupNext",time+10];
    private _alive=units _group select {alive _x};
    if (count _alive>0 && {count _alive<=2} && {[_group] call FST_HCSpawn_fnc_burnsB1Eligible}) then {
        private _best=grpNull;
        private _bestD=300;
        {
            if (_x==_group || {!local _x} || {side _x!=side _group}) then {continue};
            private _n={alive _x} count units _x;
            if (_n<3 || {_n+count _alive>12}) then {continue};
            private _d=(leader _x) distance2D _leader;
            if (_d<_bestD && {count (([_x,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet))==3} && {[_x] call FST_HCSpawn_fnc_burnsB1Eligible}) then {_bestD=_d;_best=_x};
        } forEach (missionNamespace getVariable ["FST_HC_CombatGroups",[]]);
        if (!isNull _best) then {
            {[_x,true,_group] call FST_HCSpawn_fnc_burnsReleaseAdvanceUnit} forEach _alive;
            _alive joinSilent _best;
            _merged=true;
            BURNS_B1Regroups=(missionNamespace getVariable ["BURNS_B1Regroups",0])+1;
        };
    };
};
if (_merged) exitWith {};
_task params ["_mode", "_objective", "_radius"];
private _wpIndex = ([_group,["FST_HC_taskWaypoint", -1]] call FST_HCSpawn_fnc_burnsStateGet);
private _current = currentWaypoint _group;
// Check this before issuing suppression or movement orders.
if (_wpIndex >= 0 && {_current != _wpIndex} && {_current < count waypoints _group} && {waypointDescription [_group, _current] != "FST HC combat"}) exitWith {
    [_group,"stop"] call FST_HCSpawn_fnc_setCombatTask;
};
if ((units _group findIf {([_x] call FST_HCSpawn_fnc_burnsRole)=="webknight"})>=0) exitWith {
    if !([_group,_mode,_objective,_radius] call FST_HCSpawn_fnc_burnsBXTask) then {[_group] call FST_HCSpawn_fnc_burnsSuspendTask};
};
if ([_group,_mode,_objective,_radius] call FST_HCSpawn_fnc_burnsSpecialTick) exitWith {};
if (!(_leader checkAIFeature "PATH") && {isNil {_leader getVariable "BURNS_volleyHold"}}) exitWith {[_group] call FST_HCSpawn_fnc_burnsReleaseAdvance}; // Respect externally scripted holds (not a drill volley halt: probe af35).
// Rush has no clicked destination or objective-radius leash. Acquisition
// uses a shared owner-local unit cache; it never scans terrain/props or reveals
// targets to the native firing AI.
private _seeking=_mode in ["rush","hunt","creep"];
private _rushTarget = objNull;
if (_seeking) then {_rushTarget=[_group] call FST_HCSpawn_fnc_burnsRushTarget};
if (_seeking && {isNull _rushTarget}) exitWith {
    [_group] call FST_HCSpawn_fnc_burnsSuspendTask;
    if ((([_group,["BURNS_rushState",""]] call FST_HCSpawn_fnc_burnsStateGet))!="waiting") then {
        ([_group,["BURNS_rushState","waiting",true]] call FST_HCSpawn_fnc_burnsStateSet);
        private _caller=_group getVariable ["BURNS_taskCaller",-1];
        if (_caller>2) then {format ["[BURNS] %1 is waiting: no eligible hostile exists.",toUpper _mode] remoteExec ["systemChat",_caller]};
    };
};
if (_seeking && {(([_group,["BURNS_rushState",""]] call FST_HCSpawn_fnc_burnsStateGet))!="pursuing"}) then {([_group,["BURNS_rushState","pursuing",true]] call FST_HCSpawn_fnc_burnsStateSet)};
private _destination = +_objective;
private _nearest = 1e12;
private _contact = objNull;
private _contactPos = [];
private _contactDistance = 1e12;
{
    _x params ["_knownPos", "_type", "_side", "_cost", "_object"];
    if (isNull _object || {!alive _object} || {_side in [civilian, sideUnknown, sideLogic]} || {(side _group) getFriend _side >= 0.6}) then {continue};
    if (!_seeking && {(_knownPos distance2D _objective) > _radius}) then {continue};
    private _distance = _leader distance2D _knownPos;
    if (_distance < _nearest) then { _nearest = _distance; _destination = +_knownPos; _contact = _object; _contactPos=+_knownPos; _contactDistance=_distance; };
} forEach (if (_mode=="rush") then {[]} else {_leader nearTargets _radius});
// Explicit Zeus search orders may track players' positions, matching that
// mission-making workflow. No target is revealed to the AI's firing knowledge.
// Normal HCSpawn assaults continue to use only perceived contacts.
if (!_seeking && {_mode in ["rush","hunt","creep"]} && {(_group getVariable ["BURNS_taskOptions",[]]) param [2,false]}) then {
    {
        if ((side _group) getFriend (side group _x)>=0.6 || {!alive _x}) then {continue};
        private _p=BURNS_PlayerPositions select _forEachIndex;
        private _d=_leader distance2D _p;
        if (_d<_nearest && {_p distance2D _objective<=_radius}) then {_nearest=_d;_destination=ASLToATL _p};
    } forEach BURNS_Players;
};
if (_seeking) then {
    _destination=getPosATL (vehicle _rushTarget);
    _destination set [2,0];   // V55p: a rush leg is always on the ground, never at a target's height
    _nearest=_leader distance2D _destination;
    // A perceived contact may be the occupied vehicle or another crew member.
    // Compare their current platforms, retaining only evidence for this target.
    if (!isNull _contact && {vehicle _contact != vehicle _rushTarget}) then {_contact=objNull};
};
if (_mode=="assault") then {_destination=+_objective};
if (_mode=="retreat") then {_destination=+_objective;_nearest=1e12};
// _contactPos comes ONLY from nearTargets perceived evidence.
if (!isNull _contact && {_group getVariable ["BURNS_hasRadio",false]} && {time>=(_group getVariable ["BURNS_nextRadio",-1])}) then {
    _group setVariable ["BURNS_nextRadio",time+90];
    ["BURNS_support",[_group,_contactPos]] call CBA_fnc_serverEvent;
};
// Hunt approaches from the group's current side and leaves room for cover.
// Assault closes directly. Neither mode forces droids prone or disables FSMs.
if (_mode=="creep" && {_nearest < 1e12} && {_nearest > 80}) then {
    _destination = _destination getPos [60, _destination getDir (getPosATL _leader)];
};
// Human squads approach a known contact from a flank while one rifleman
// suppresses its perceived position. B1s keep the direct line of advance.
private _human = ([_leader] call FST_HCSpawn_fnc_burnsRole) == "human";
if (_human && {!isNull _contact} && {_mode in ["hunt","assault"]}) then {
    [_group,_contactPos] call FST_HCSpawn_fnc_burnsUseCover;
};
private _tactic = if (_human) then {"advance"} else {"line-advance"};
if (_human && {_mode=="hunt"} && {!isNull _contact} && {_contactDistance > 100} && {_contactDistance < 600} && {vehicle _leader == _leader}) then {
    private _flank = _group getVariable ["BURNS_flankSide", 0];
    if (_flank == 0) then {
        _flank = selectRandom [-1,1];
        _group setVariable ["BURNS_flankSide", _flank, true];
    };
    private _approach = _contactPos getPos [80, (_contactPos getDir (getPosATL _leader)) + 60 * _flank];
    if !(surfaceIsWater _approach) then {_destination = _approach};
    private _coverUnit = (units _group) findIf {local _x && {alive _x} && {!(_x getVariable ["BURNS_exempt",false])} && {_x != _leader} && {vehicle _x == _x} && {([_x] call FST_HCSpawn_fnc_burnsRole) == "human"}};
    if (_coverUnit >= 0) then {
        (units _group select _coverUnit) doSuppressiveFire ATLToASL _contactPos;
    };
    _tactic = "flank-and-suppress";
};
// At 100-150 players, unchanged diagnostics must not broadcast every AI tick.
if ((_group getVariable ["BURNS_lastTactic", ""]) != _tactic) then {
    _group setVariable ["BURNS_lastTactic", _tactic, true];
};
// Hunt is a progressing patrol, not Rush with a different speed label.
// Keep each short patrol leg until reached; then bias the next toward the
// nearest hostile. No target reveal and no terrain/prop search.
if (_mode=="hunt" && {_nearest>100} && {isNull _contact}) then {
    private _leg=([_group,["BURNS_huntLeg",[]]] call FST_HCSpawn_fnc_burnsStateGet);
    if (count _leg==0 || {_leader distance2D _leg<25}) then {
        private _phase=1-(([_group,["BURNS_huntPhase",0]] call FST_HCSpawn_fnc_burnsStateGet));
        ([_group,["BURNS_huntPhase",_phase,true]] call FST_HCSpawn_fnc_burnsStateSet);
        _leg=(getPosATL _leader) getPos [150 min (_nearest*0.5),(_leader getDir _destination)+([-25,25] select _phase)];
        if (surfaceIsWater _leg) then {_leg=+_destination};
        ([_group,["BURNS_huntLeg",_leg,true]] call FST_HCSpawn_fnc_burnsStateSet);
    };
    _destination=+_leg;
};
// An AAT approach should finish on our side of the contact,
// not at the enemy's exact position. This does not control the hull or force fire.
// Only one local AAT and its mounted crew; mixed groups keep existing behavior.
if (missionNamespace getVariable ["BURNS_ArmorAssistEnabled",true] && {_mode in ["rush","hunt","assault"]}) then {
    private _armor=vehicle _leader;
    if (_armor isKindOf "FST_AAT" && {local _armor} && {canMove _armor} && {
        (units _group findIf {alive _x && {vehicle _x!=_armor}})<0
    }) then {
        // Rush normally skips nearTargets. Query native knowledge once on its
        // existing task tick; no new scheduler, world scan or knowledge reveal.
        private _armorTarget=if (_mode=="assault") then {_contact} else {_rushTarget};
        private _evidence=[];
        {
            _x params ["_pos","_type","_side","_cost","_obj"];
            if (!isNull _obj && {alive _obj} && {!isNull _armorTarget && {vehicle _obj==vehicle _armorTarget}} && {
                !(_side in [civilian,sideUnknown,sideLogic]) && {(side _group) getFriend _side<0.6}
            }) exitWith {_evidence=+_pos};
        } forEach (_leader nearTargets (500 min _radius));
        if (count _evidence>=2) then {
            private _distance=_armor distance2D _evidence;
            // Do not manufacture a retreat order when already inside the band.
            // Native combat can still reposition and seek a firing solution.
            private _goal=+_destination;
            if (_distance>200) then {
                _goal=_evidence getPos [150,_evidence getDir (getPosATL _armor)];
            } else {
                private _gunner=gunner _armor;
                private _angle=abs ((((_armor getDir _evidence)-(getDir _armor)+540) mod 360)-180);
                // Do not park behind cover or freeze with the rear toward the
                // threat. This is one obstruction ray, never a detection boost.
                if (!isNull _gunner && {alive _gunner} && {canFire _armor} && {_angle<50} && {
                    ([_armor,"FIRE",vehicle _armorTarget] checkVisibility [eyePos _gunner,aimPos (vehicle _armorTarget)])>0.5
                }) then {_goal=getPosATL _armor};
            };
            if !(surfaceIsWater _goal) then {_destination=_goal};
        };
    };
};
// ADSD long-range skirmisher (Miran 3 Oct): hold ~450 m from a known enemy (band 350-600 m),
// and shift 60 m sideways every ~40 s between volleys. AATs still charge. Was 700 m (500-900):
// probe 4 Oct, crews never spotted infantry at 700 m, so the ADSD sat there without firing.
if (_mode in ["rush","hunt","assault"] && {(vehicle _leader) isKindOf "FST_Advanced_DSD_Base"} && {local (vehicle _leader)} && {canMove (vehicle _leader)}) then {
    private _v=vehicle _leader;
    private _foe=if (!isNull _rushTarget) then {vehicle _rushTarget} else {vehicle _contact};
    private _fp=if (!isNull _foe) then {getPosATL _foe} else {+_contactPos};
    if (count _fp>=2) then {
        private _d=_v distance2D _fp;
        private _goal=getPosATL _v;
        // Not actually seen yet (Rush hands over the shared cache position): keep closing (down
        // to 150 m) until the crew spots it, then fall back into the band and snipe. Probe 4 Oct:
        // crews only spot infantry that shoot at them (~300 m); parked at 370 m blind = no shots.
        private _seen=if (!isNull _foe) then {(_group knowsAbout _foe)>=1} else {true};
        if (_d>600 || {_seen && {_d<350}} || {!_seen && {_d>170}}) then {
            _goal=_fp getPos [[150,450] select _seen,_fp getDir (getPosATL _v)];
            _group setVariable ["BURNS_adsdShiftGoal",nil];
        } else {
            if (time>=(_group getVariable ["BURNS_adsdShift",-1])) then {
                _group setVariable ["BURNS_adsdShift",time+40];
                _group setVariable ["BURNS_adsdShiftGoal",(getPosATL _v) getPos [60,(_fp getDir (getPosATL _v))+selectRandom [90,-90]]];
            };
            // Keep the sidestep goal until reached; otherwise hold and fire.
            private _shift=_group getVariable ["BURNS_adsdShiftGoal",[]];
            if (count _shift>=2 && {_v distance2D _shift>8}) then {_goal=+_shift};
        };
        if !(surfaceIsWater _goal) then {_destination=_goal};
        _group setVariable ["BURNS_caTactic","adsd-skirmish"]; // local diagnostic only (no broadcast)
    };
};
// Combined arms (players via Miran, 3 Oct): a foot squad on rush/assault within 300 m of a
// friendly crewed armored vehicle that is ADVANCING ahead of it (its own task is assault/rush
// and it is moving) follows 25 m behind and to one side instead of overtaking it. It lets go
// once that armor is within 220 m of the goal (AATs hold ~150 m from contact) or stops.
_group setVariable ["BURNS_caTactic",nil];
if (_mode in ["rush","assault"] && {vehicle _leader==_leader} && {missionNamespace getVariable ["BURNS_CombinedArms",true]}) then {
    private _armor=objNull;
    private _best=300;
    {
        private _ag=group driver _x;
        if (alive _x && {canMove _x} && {!isNull driver _x} && {_ag!=_group} && {side _ag==side _group} && {abs speed _x>3} && {
            (((([_ag,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet)) param [0,""]) in ["assault","rush"])
        }) then {
            private _d=_leader distance2D _x;
            if (_d<_best) then {_best=_d;_armor=_x};
        };
    } forEach (_leader nearEntities [["Tank","Wheeled_APC_F"],300]);
    if (!isNull _armor) then {
        private _ad=_armor distance2D _destination;
        if (_ad<(_leader distance2D _destination) && {_ad>220}) then {
            if (isNil {_group getVariable "BURNS_caSide"}) then {_group setVariable ["BURNS_caSide",selectRandom [-1,1]]};
            private _slot=(getPosATL _armor) getPos [25,(_destination getDir (getPosATL _armor))+30*(_group getVariable ["BURNS_caSide",1])];
            if !(surfaceIsWater _slot) then {_destination=_slot};
            _group setVariable ["BURNS_caTactic","with-armor"]; // local diagnostic only (no broadcast)
        };
    };
};
// Do not march an entire B1 formation onto a prone casualty. Keep the
// approach eight metres short; the rifle service assigns a single finisher.
private _down=_seeking && {[_rushTarget] call FST_HCSpawn_fnc_burnsIsDown};
private _seekState=[_rushTarget,_down];
if (_seeking && {!((_group getVariable ["BURNS_seekState",[]]) isEqualTo _seekState)}) then {
    _group setVariable ["BURNS_seekState",_seekState];
    [_group,["FST_HC_taskLastOrder",[],true]] call FST_HCSpawn_fnc_burnsStateSet;
};
if (_down && {vehicle _leader==_leader}) then {
    private _body=getPosATL _rushTarget;
    _destination=if (_leader distance2D _body>10) then {_body getPos [8,_body getDir (getPosATL _leader)]} else {getPosATL _leader};
};
// Tank spread (V55o; Miran 18 Oct: AATs on Rush "often end up all trying to take the same path and clumping up"): every rush tank drove at
// the same target position. Friendly AI tanks within 350 m are ranked by netId (stable each tick) and each heads for its own point beside
// the destination, 45 m apart across the approach, while still more than 80 m out.
private _sv=vehicle _leader;
// V55t (AR test 18 Oct: on Assault the spread pulled AATs off the road, road share 50-67% -> 25-35%): Rush and Hunt only.
if (_mode in ["rush","hunt"] && {_sv!=_leader} && {_sv isKindOf "Tank"} && {local _sv} && {(_sv distance2D _destination)>80}) then {
    private _mates=(_sv nearEntities [["Tank"],350]) select {alive _x && {!isNull driver _x} && {!isPlayer driver _x} && {side group driver _x==side _group}};
    if (count _mates>1) then {
        // V55s (sk test 18 Oct: at SW two AATs given sides by netId crossed paths and jammed 9 m apart for 10 min): each tank takes its
        // side by where it is now across one shared approach axis (destination -> the tanks' centre), so no two paths cross.
        private _c=[0,0,0]; {_c=_c vectorAdd getPosATL _x} forEach _mates; _c=_c vectorMultiply (1/count _mates);
        private _ax=_destination getDir _c;
        private _rt=[sin (_ax+90),cos (_ax+90),0];
        _mates=[_mates,[],{((getPosATL _x) vectorDiff _destination) vectorDotProduct _rt},"ASCEND"] call BIS_fnc_sortBy;
        private _off=((_mates find _sv)-((count _mates)-1)/2)*45;
        if (abs _off>1) then {
            private _q=_destination getPos [abs _off,_ax+([90,-90] select (_off<0))];
            if !(surfaceIsWater _q) then {_destination=[_q select 0,_q select 1,0]};
        };
    };
};
if (_mode=="assault") then {_destination=[_group,_destination,_contact,_contactPos] call FST_HCSpawn_fnc_burnsArmorSectionGoal};
// Vehicle road march (V55n; Miran 18 Oct, Sarrak-1: "The AATs are trying and getting stuck trying to go up the hill on the red line instead
// of following the road"). Section column legs and single-tank waypoints ran straight at the objective in AWARE, so a road bending round a
// hill was ignored. A tank or wheeled APC on a road (12 m) whose road, followed up to 150 m on toward the objective, closes on it by 30% of
// that length (15% to keep going) heads for the road point 80 m on instead - while the objective is over 250 m away, no enemy is within
// 300 m and its section is not deployed in LINE. Vehicle recovery below still wins. CBA setting "B1 road march" switches it off too.
private _veh=vehicle _leader;
private _vRoad=[];
if ((missionNamespace getVariable ["BURNS_B1RoadMarch",true]) && {_mode in ["assault","rush","hunt"]} && {_veh!=_leader} && {_veh isKindOf "Tank" || {_veh isKindOf "Wheeled_APC_F"}} && {local _veh} && {canMove _veh} && {
    ((_group getVariable ["BURNS_sectionPlan",[]]) param [2,""])!="LINE"
} && {(_veh distance2D _objective)>250}) then {
    private _ne=_leader findNearestEnemy _veh;
    if (isNull _ne || {(_veh distance2D _ne)>300}) then {
        private _vp=getPosATL _veh;
        private _was=_group getVariable ["BURNS_vehRoad",false];
        private _rs=(_vp nearRoads 12) select {!((getRoadInfo _x) param [2,false])};
        if (count _rs>0) then {
            private _cur=_rs select 0; private _seen=[_cur]; private _len=0; private _gp=[];
            for "_i" from 1 to 60 do {
                private _next=(roadsConnectedTo _cur) select {!(_x in _seen) && {!((getRoadInfo _x) param [2,false])}};
                if (count _next==0 || {_len>=150}) exitWith {};
                private _best=_next select 0; private _bd=1e9;
                {private _d=_x distance2D _objective; if (_d<_bd) then {_bd=_d;_best=_x}} forEach _next;
                _len=_len+(_cur distance2D _best); _seen pushBack _best; _cur=_best;
                if (count _gp==0 && {_len>=80}) then {_gp=getPosATL _cur};
            };
            if (count _gp==0) then {_gp=getPosATL _cur};
            if (_len>=40 && {((_vp distance2D _objective)-(_cur distance2D _objective))>=(if (_was) then {0.15} else {0.3})*_len}) then {_vRoad=[_gp select 0,_gp select 1,0]};
        };
    };
};
if ((count _vRoad==3)!=(_group getVariable ["BURNS_vehRoad",false])) then {
    _group setVariable ["BURNS_vehRoad",count _vRoad==3];
    if (missionNamespace getVariable ["BURNS_B1Debug",false]) then {diag_log format ["[BURNS_DBG] vehicle road march %1 (%2): %3, %4 m to go",_group,typeOf _veh,["off","on"] select (count _vRoad==3),round (_veh distance2D _objective)]};
};
if (count _vRoad==3) then {_destination=_vRoad};
_destination=[_group,_destination,_mode] call FST_HCSpawn_fnc_burnsVehicleProgress;
private _last = ([_group,["FST_HC_taskLastOrder", []]] call FST_HCSpawn_fnc_burnsStateGet);
if (_mode=="creep") then {
    private _combatMode=if (_nearest<80) then {"RED"} else {"GREEN"};
    _group setCombatMode _combatMode;
    if (_wpIndex>=0 && {_wpIndex<count waypoints _group}) then {[_group,_wpIndex] setWaypointCombatMode _combatMode};
};
// B1 foot squads on assault/rush/hunt keep YELLOW even on an already-active waypoint (see below).
if (_mode in ["assault","rush","hunt"] && {vehicle _leader==_leader} && {([_leader] call FST_HCSpawn_fnc_burnsRole)=="b1"} && {combatMode _group=="RED"}) then {_group setCombatMode "YELLOW"};
if (count _last > 0 && {(_last distance2D _destination) < (if ((vehicle _leader) isKindOf "Tank") then {5} else {25})} && {_wpIndex >= 0} && {_wpIndex < count waypoints _group}) exitWith {
    if (_mode in ["rush","hunt","creep","assault"]) then {[_group,_destination] call FST_HCSpawn_fnc_burnsB1Advance};
};
if (!local _group) exitWith {};
private _wp = [_group, _wpIndex];
if (_wpIndex < 0 || {_wpIndex >= count waypoints _group} || {waypointDescription _wp != "FST HC combat"}) then {
    _wp = _group addWaypoint [_destination, 0];
    _wpIndex = _wp select 1;
    ([_group,["FST_HC_taskWaypoint", _wpIndex, true]] call FST_HCSpawn_fnc_burnsStateSet);
};
_wp setWaypointDescription "FST HC combat";
_wp setWaypointPosition [_destination, 0];
_wp setWaypointType "MOVE";
_wp setWaypointCompletionRadius (if (_mode == "hunt") then {30} else {15});
// Infantry pacing must not turn a mounted B1 crew into a slow walking squad.
_wp setWaypointSpeed (if (vehicle _leader==_leader && {([_leader] call FST_HCSpawn_fnc_burnsRole) == "b1"}) then {"LIMITED"} else {if (_mode == "hunt") then {"NORMAL"} else {"FULL"}});
_wp setWaypointBehaviour "AWARE";
// Explicit AAT/N99 advances retain the ordered approach while firing at will.
// RED permits independent engagement movement that can override that approach.
// B1 foot squads also hold YELLOW (fire at will, keep formation). Probe 6 Oct: under RED the native
// leader handed out individual ATTACK orders (58/77 out-of-slot samples) that overrode BURNS slots,
// so lines dissolved and stragglers stopped 20-100 m off their places.
_wp setWaypointCombatMode (if ((((vehicle _leader) isKindOf "FST_AAT" || {(vehicle _leader) isKindOf "FST_N99"}) && {_mode in ["assault","rush","hunt"]}) || {
    vehicle _leader==_leader && {([_leader] call FST_HCSpawn_fnc_burnsRole)=="b1"} && {_mode in ["assault","rush","hunt"]}
}) then {"YELLOW"} else {"RED"});
if (_mode=="creep") then {
    _wp setWaypointSpeed "LIMITED";
    _wp setWaypointCombatMode (if (_nearest<80) then {"RED"} else {"GREEN"});
    if (_human) then {_wp setWaypointBehaviour "STEALTH"};
};
if (_mode=="retreat") then {_wp setWaypointCombatMode "GREEN";_wp setWaypointSpeed "FULL"};
_group setCurrentWaypoint _wp;
// A direct leader order starts the explicit rush without waiting for a native
// waypoint/FSM reconsideration. B1 squads receive compact individual slots.
private _tight=false;
if (_mode in ["rush","hunt","creep","assault"]) then {_tight=[_group,_destination] call FST_HCSpawn_fnc_burnsB1Advance};
if (_mode=="rush" && {!_tight} && {vehicle _leader==_leader}) then {_leader doMove _destination;_leader setVariable ["BURNS_moveCleanupToken",nil];_leader setVariable ["BURNS_formationGoal",+_destination];_group setVariable ["BURNS_advanceOrders",[[_leader,+_destination]],true]};
([_group,["FST_HC_taskLastOrder", +_destination, true]] call FST_HCSpawn_fnc_burnsStateSet);
