// Stable short bounds; a whole squad shares the same frozen front and bearing.
// A firing solution takes precedence over correcting an individual formation slot.
params ["_group","_destination"];
if (isNull _group || {!local _group}) exitWith {false};
if !([_group] call FST_HCSpawn_fnc_burnsB1Eligible) exitWith {[_group] call FST_HCSpawn_fnc_burnsReleaseAdvance;false};
private _leader=leader _group;
private _units=units _group select {alive _x};
private _ordered=[_leader]+(_units-[_leader]);
// Rear-rank specialists were tried 6 Oct and dropped: AT droids behind the front rank lost their
// firing lanes (rocketed 25% vs 54% in the plain line with infantry present).
private _old=_group getVariable ["BURNS_advanceRoster",[]];
{[_x,true,_group] call FST_HCSpawn_fnc_burnsReleaseAdvanceUnit} forEach (_old-_ordered);
private _changed=!(_old isEqualTo _ordered);
_group setVariable ["BURNS_advanceRoster",_ordered];
private _formation=[_group] call FST_HCSpawn_fnc_burnsB1Formation;
private _line=_formation=="LINE";
private _previous=_group getVariable ["BURNS_localAdvanceFormation",""];
_changed=_changed || {_previous!=_formation};
_group setVariable ["BURNS_localAdvanceFormation",_formation];
private _origin=getPosATL _leader;
// Lanes (Miran 6 Oct review): squads sent at the same assault/hunt objective keep the sideways spacing
// they started with (relative to their shared centroid, max 150 m), so they arrive side by side as one
// battle line instead of funnelling into a single blob. A lone squad has a zero offset.
private _taskMode=([_group,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet) param [0,""];
private _objective0=+_destination;
if (_taskMode in ["assault","hunt"]) then {
    private _key=_destination apply {round (_x/10)};
    private _lane=_group getVariable ["BURNS_lane",[]];
    // Recomputed for the first 30 s of an order so squads ordered together all count, then locked.
    if (count _lane!=4 || {!((_lane select 0) isEqualTo _key)} || {time<(_lane select 3)}) then {
        private _peers=(missionNamespace getVariable ["FST_HC_CombatGroups",[]]) select {
            local _x && {side _x==side _group} && {
                private _t=[_x,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet;
                count _t==3 && {(_t select 0) in ["assault","hunt"]} && {((_t select 1) distance2D _destination)<60}
            }
        };
        if !(_group in _peers) then {_peers pushBack _group};
        private _c=[0,0,0];
        {_c=_c vectorAdd (getPosATL leader _x)} forEach _peers;
        _c=_c vectorMultiply (1/count _peers);
        private _axis=_c getDir _destination;
        private _rel=_origin vectorDiff _c;
        private _lat=(((_rel select 0)*cos _axis)-((_rel select 1)*sin _axis)) max -150 min 150;
        private _lock=if (count _lane==4 && {(_lane select 0) isEqualTo _key}) then {_lane select 3} else {time+30};
        _lane=[_key,_lat,_axis,_lock];
        _group setVariable ["BURNS_lane",_lane];
        _group setVariable ["BURNS_linePeers",_peers-[_group]];
    };
    _lane params ["","_lat","_axis"];
    if (abs _lat>5) then {_destination=_destination getPos [abs _lat,_axis+([-90,90] select (_lat>0))]};
};
private _direction=_origin getDir _destination;
// Hybrid formation (Miran 7 Oct): on assault/rush/hunt the engine's own formation (LINE in contact or on the
// approach, COLUMN on the march) moves the squad: the leader walks straight at its lane objective and the
// droids follow in formation. Per-droid slot orders made the line stop-start (~0.5 m/s in contact). BURNS
// keeps the lanes, the shared battle line (a leader >10 m ahead of the rearmost squad pauses, max 25 s),
// volleys and regroup. OFF by default: probe 7 Oct, engine followers stop and shoot in sustained contact and fell
// 25-33 m behind (squads spread 100-190 m), even with a leash; the per-droid slot system keeps the line.
if ((missionNamespace getVariable ["BURNS_B1HybridFormation",false]) && {_taskMode in ["assault","rush","hunt"]}) exitWith {
    if !(_group getVariable ["BURNS_hybridMode",false]) then {
        {[_x,false,_group] call FST_HCSpawn_fnc_burnsReleaseAdvanceUnit} forEach _ordered;
        {if (_x!=_leader && {!([_x] call FST_HCSpawn_fnc_isPlayerControlledUnit)}) then {_x doFollow _leader}} forEach _ordered;
        _group setVariable ["BURNS_advanceRoster",nil];
        _group setVariable ["BURNS_hybridMode",true];
    };
    private _march=missionNamespace getVariable ["BURNS_B1MarchSpeed",2.5];
    private _lead=_march;
    private _laneH=_group getVariable ["BURNS_lane",[]];
    private _peersH=(_group getVariable ["BURNS_linePeers",[]]) select {!isNull _x && {({alive _x} count units _x)>0}};
    if (count _laneH==4 && {count _peersH>0}) then {
        private _ax=[sin (_laneH select 2),cos (_laneH select 2),0];
        private _along={((_objective0 vectorDiff (getPosATL leader _this)) vectorDotProduct _ax)};
        private _mine=_group call _along;
        private _rear=selectMax ((_peersH apply {_x call _along})+[_mine]);
        if (_mine<_rear-10) then {
            private _since=_group getVariable ["BURNS_lineWaitSince",-1];
            if (_since<0) then {_since=time;_group setVariable ["BURNS_lineWaitSince",time]};
            if (time-_since<25) then {_lead=0};
        } else {_group setVariable ["BURNS_lineWaitSince",-1]};
    };
    // Leash: the leader pauses while its droids average >12 m off their formation positions and resumes
    // under 8 m (probe 7 Oct: without it followers fell 25-33 m behind and squads spread over 100+ m).
    private _members=_ordered select {_x!=_leader};
    if (count _members>0) then {
        private _err=0; {_err=_err+(_x distance2D (formationPosition _x))} forEach _members; _err=_err/count _members;
        private _leashed=_group getVariable ["BURNS_leash",false];
        if (_err>12) then {_leashed=true};
        if (_err<8) then {_leashed=false};
        _group setVariable ["BURNS_leash",_leashed];
        if (_leashed) then {_lead=0};
    };
    {
        private _spd=if (_x==_leader) then {_lead} else {(_march+1.5) min 4.5};
        if (isNil {_x getVariable "BURNS_advanceSpeed"}) then {_x setVariable ["BURNS_advanceSpeed",[getForcedSpeed _x,_spd],true]};
        if (abs (getForcedSpeed _x-_spd)>0.05) then {_x forceSpeed _spd};
    } forEach _ordered;
    private _lastDest=_group getVariable ["BURNS_hybridDest",[]];
    if (count _lastDest<2 || {_lastDest distance2D _destination>15} || {unitReady _leader && {_leader distance2D _destination>20}}) then {
        _leader doMove _destination;
        _group setVariable ["BURNS_hybridDest",+_destination];
    };
    if (speedMode _group!="NORMAL") then {_group setSpeedMode "NORMAL"};
    true
};
_group setVariable ["BURNS_hybridMode",nil];
private _track=(missionNamespace getVariable ["BURNS_B1TrackFormation",true]) && {_line};
private _frame=_group getVariable ["BURNS_bound",[]];
private _contact=_leader findNearestEnemy _leader;
private _engaging=!isNull _contact && {alive _contact} && {_leader distance2D _contact<250} && {([_leader,"FIRE",vehicle _contact] checkVisibility [eyePos _leader,aimPos vehicle _contact])>0.5};
// Frames survive owner handoff. Only a replacement destination, changed roster,
// completed bound or timed-out obstructed bound creates new movement orders.
private _new=count _frame!=4 || {_changed};
if (!_new) then {
    _frame params ["_front","_bearing","_deadline","_dest"];
    private _arrived={private _slot=_x getVariable ["BURNS_formationGoal",[]];count _slot>=2 && {_x distance2D _slot<4}} count _ordered;
    // Fire-and-advance (Miran 7 Oct review: "not advancing much once they start shooting"). Engaged
    // squads keep bounding (short steps, 6 s frames) instead of freezing until contact ends; they only
    // stop within 50 m of the objective.
    _new=_dest distance2D _destination>25 || {time>_deadline || {_arrived>=ceil(count _ordered*0.75)} || {_track && {_leader distance2D _front<4}}};
    if (_engaging && {_origin distance2D _destination<50}) then {_new=_dest distance2D _destination>25};
};
if (_new) then {
    // Advance together (Miran 7 Oct): squads sharing the objective move as one battle line. A squad
    // more than 10 m further forward (along the shared axis) than the rearmost one holds its bound
    // until the others come up; after 25 s of waiting it goes anyway so a stuck squad can't freeze the line.
    // Bound length: 15 m in line on the approach, 12 m per 4 s frame while firing.
    private _step=(if (_engaging) then {12} else {if (_line) then {15} else {18}}) min (_origin distance2D _destination);
    private _lane2=_group getVariable ["BURNS_lane",[]];
    private _peersL=(_group getVariable ["BURNS_linePeers",[]]) select {!isNull _x && {({alive _x} count units _x)>0}};
    if (count _lane2==4 && {count _peersL>0}) then {
        private _ax=[sin (_lane2 select 2),cos (_lane2 select 2),0];
        private _along={((_objective0 vectorDiff (getPosATL leader _this)) vectorDotProduct _ax)};
        private _mine=_group call _along;
        private _rear=selectMax ((_peersL apply {_x call _along})+[_mine]);
        if (_mine<_rear-10) then {
            private _since=_group getVariable ["BURNS_lineWaitSince",-1];
            if (_since<0) then {_since=time;_group setVariable ["BURNS_lineWaitSince",time]};
            if (time-_since<25) then {_step=0};
        } else {_group setVariable ["BURNS_lineWaitSince",-1]};
    };
    // Continuous advance (probe 7 Oct): an 8 m bound was reached in ~3 s and the line then waited for the next
    // 6 s frame. In contact the slot sits 12 m ahead and refreshes every 4 s, so the line walks steadily.
    _frame=[_origin getPos [_step,_direction],_direction,time+(if (_engaging) then {4} else {20}),+_destination];
    _group setVariable ["BURNS_bound",_frame,true];
};
_frame params ["_front","_bearing"];
private _columns=if (_line) then {6 min count _ordered} else {1};
private _spacing=if (_line) then {4.5} else {3.5};
private _march=missionNamespace getVariable ["BURNS_B1MarchSpeed",2.5];
private _walkFire=_taskMode in ["assault","rush","hunt"];
if (!_track) then {
    _group setVariable ["BURNS_track",nil];_group setVariable ["BURNS_trackGo",nil];
    {if (!isNil {_x getVariable "BURNS_atCatchUp"}) then {_x enableAI "FIREWEAPON";_x enableAI "AUTOTARGET";_x setVariable ["BURNS_atCatchUp",nil]}} forEach _ordered;
};
if (_track) exitWith {
    // Parallel tracks (Miran 9 Oct review: "still aren't keeping a formation"). Each droid walks its own straight
    // track beside the leader at the leader's pace: faster when behind its place in the line, easing off when ahead.
    // The old slot bounds made droids race to a slot 12 m ahead and stop short of it, so the line was always jagged.
    // The line keeps walking unless it waits for the shared battle line or is near the objective (probe lp19: waiting
    // for each 12 m bound frame left droids standing still half the time, median speed 0.1 m/s).
    private _fwd=[sin _direction,cos _direction,0];
    private _right=[cos _direction,-(sin _direction),0];
    private _lp=getPosATL _leader;
    private _since=_group getVariable ["BURNS_lineWaitSince",-1];
    private _remain=_lp distance2D _destination;
    // A squad ahead of the shared battle line slows to 40% instead of stopping (Miran 10 Oct: "constantly advancing").
    private _waiting=_since>=0 && {time-_since<25};
    private _go=_remain>(if (_engaging) then {50} else {15});
    private _toFront=_remain min 40;
    private _offs=_ordered apply {
        private _i=_ordered find _x;
        // One rank, 3 m apart, while the squad has up to 10 droids (single firing line: every droid has a clear shot).
        private _cols=if (count _ordered<=10) then {count _ordered} else {_columns};
        private _c=_i mod _cols;
        [if (_c==0) then {0} else {ceil(_c/2)*3*([-1,1] select (_c mod 2))},floor(_i/_cols)*_spacing]
    };
    // The line forms on its own average position, not on the leader (probe lp28: chasing the leader, the line trailed it
    // in a shallow V, riflemen a median 3 m and p90 9 m behind). AT droids on native control are left out of the average.
    private _alongs=[];
    {if (_x==_leader || {secondaryWeapon _x==""}) then {_alongs pushBack ((((getPosATL _x) vectorDiff _lp) vectorDotProduct _fwd)+((_offs select _forEachIndex) select 1))}} forEach _ordered;
    private _anchor=0;
    {_anchor=_anchor+_x} forEach _alongs;
    _anchor=_anchor/((count _alongs) max 1);
    private _ideals=_offs apply {_lp vectorAdd (_right vectorMultiply (_x select 0)) vectorAdd (_fwd vectorMultiply (_anchor-(_x select 1)))};
    // The leader eases off while its line lags (75th percentile >6 m behind its places) and waits beyond 12 m;
    // one straggler (e.g. an AT droid on native control) no longer stops the squad.
    private _leadSpeed=if (_go) then {if (_waiting) then {_march*0.4} else {_march}} else {0};
    // fn_burnsB1Pace re-matches follower speeds every ~0.5 s between these orders.
    _group setVariable ["BURNS_track",[time,_fwd,_right,_leadSpeed,+_ordered,_offs]];
    _group setVariable ["BURNS_trackGo",_go];
    {
        private _u=_x;
        private _lease=_u getVariable ["BURNS_pointFireLease",[]];
        if (count _lease==4 && {time<(_lease select 1)}) then {continue};
        private _ideal=_ideals select _forEachIndex;
        _ideal set [2,0];
        if (surfaceIsWater _ideal) then {continue};
        private _along=((getPosATL _u) vectorDiff _ideal) vectorDotProduct _fwd;
        private _goal=if (_go) then {_ideal vectorAdd (_fwd vectorMultiply _toFront)} else {+_ideal};
        _goal set [2,0];
        private _target=assignedTarget _u;
        if (isNull _target) then {_target=_contact};
        private _inSlot=_u distance2D _ideal<3;
        private _hasShot=_inSlot && {!isNull _target} && {alive _target} && {_u knowsAbout _target>=1} && {_u distance2D _target<250} && {([_u,"FIRE",vehicle _target] checkVisibility [eyePos _u,aimPos vehicle _target])>0.5};
        if (time<(_u getVariable ["BURNS_volleyHold",-1])) then {continue};
        private _hold=_hasShot && {!_walkFire};
        // Every droid, the leader included, keeps its place in the line: behind it a droid closes at up to +1.5 m/s,
        // ahead of it it eases off and stops 3 m ahead, so nobody walks out in front while the line volleys or waits.
        private _speed=if (_hold) then {0} else {
            if (_along>0) then {_leadSpeed*((1-_along/3) max 0)} else {
                if (_leadSpeed<0.1) then {if (_u distance2D _ideal<1.5) then {0} else {((-_along*0.5) max 0.8) min 2.5}} else {(_leadSpeed+((-_along*0.5) min 1.5)) min 4.5}
            }
        };
        private _owned=_u getVariable ["BURNS_advanceSpeed",[]];
        if (count _owned==0) then {_owned=[getForcedSpeed _u,_speed]};
        if ((_u getVariable ["BURNS_advanceController",grpNull])!=_group) then {_u setVariable ["BURNS_advanceController",_group,true]};
        if (abs (getForcedSpeed _u-_speed)>0.05) then {_u forceSpeed _speed};
        if !(_owned isEqualTo [_owned select 0,_speed]) then {_owned=[_owned select 0,_speed]};
        if !((_u getVariable ["BURNS_advanceSpeed",[]]) isEqualTo _owned) then {_u setVariable ["BURNS_advanceSpeed",_owned,true]};
        _u setVariable ["BURNS_formationGoal",_ideal];
        // A new track order only when the droid nears its current track point or its track moved sideways.
        private _last=_u getVariable ["BURNS_trackGoal",[]];
        private _reorder=count _last<2 || {time>(_u getVariable ["BURNS_trackAt",-1])+20} || {_u distance2D _last<8 && {_go}} || {abs (((_goal vectorDiff _last) vectorDotProduct _right))>3} || {!_go && {_last distance2D _goal>3}};
        if ((!_hasShot || {_walkFire}) && {_reorder}) then {
            _u doMove _goal;_u setVariable ["BURNS_moveCleanupToken",nil];_u setVariable ["BURNS_trackGoal",_goal];_u setVariable ["BURNS_trackAt",time];
            _u setVariable ["BURNS_formationOrderCount",(_u getVariable ["BURNS_formationOrderCount",0])+1];
        };
    } forEach _ordered;
    private _orders=_ordered apply {[_x,_x getVariable ["BURNS_formationGoal",[]]]};
    if !(_orders isEqualTo (_group getVariable ["BURNS_advanceOrders",[]])) then {_group setVariable ["BURNS_advanceOrders",_orders,true]};
    if (speedMode _group!="NORMAL") then {_group setSpeedMode "NORMAL"};
    if ((_group getVariable ["BURNS_lastRoleSpeed",""])!="NORMAL") then {_group setVariable ["BURNS_lastRoleSpeed","NORMAL",true]};
    true
};
private _maxLag=0;
{private _delta=_origin vectorDiff getPosATL _x;_maxLag=_maxLag max ((_delta select 0)*sin _bearing+(_delta select 1)*cos _bearing-floor(_forEachIndex/_columns)*_spacing)} forEach _ordered;
{
    private _u=_x;
    private _lease=_u getVariable ["BURNS_pointFireLease",[]];
    if (count _lease==4 && {time<(_lease select 1)}) then {continue};
    private _column=_forEachIndex mod _columns;
    private _offset=if (_column==0) then {0} else {ceil(_column/2)*3.5*([-1,1] select (_column mod 2))};
    private _goal=(_front getPos [abs _offset,_bearing+([90,-90] select (_offset<0))]) getPos [floor(_forEachIndex/_columns)*_spacing,_bearing+180];
    if (surfaceIsWater _goal) then {continue};
    private _target=assignedTarget _u;
    if (isNull _target) then {_target=_contact};
    // Slot tether (Miran 6 Oct "the droids barely hold a semblance of a formation"; probe: in contact
    // each droid froze wherever it first got a shot, leaving stragglers 100+ m behind). A droid only
    // halts to shoot when it is within 3 m of its slot; otherwise it walks to its place firing.
    private _slotNow=_u getVariable ["BURNS_formationGoal",[]];
    private _inSlot=count _slotNow<2 || {_u distance2D _slotNow<3};
    private _hasShot=_inSlot && {!isNull _target} && {alive _target} && {_u knowsAbout _target>=1} && {_u distance2D _target<250} && {([_u,"FIRE",vehicle _target] checkVisibility [eyePos _u,aimPos vehicle _target])>0.5};
    // Walk and shoot (Miran 7 Oct): on assault/rush/hunt a droid with a shot keeps walking to its slot and
    // fires on the move; halting for every shot made the line stop-start (~0.5 m/s, probe LN5).
    private _walkFire=_taskMode in ["assault","rush","hunt"];
    private _hold=(_hasShot && {!_walkFire}) || {_line && {_u distance2D _goal<3}} || {_u==_leader && {_maxLag>8}} || {time<(_u getVariable ["BURNS_volleyHold",-1])};
    private _speed=if (_hold) then {0} else {if (_u==_leader) then {_march} else {(_march+1.5) min 4.5}};
    private _owned=_u getVariable ["BURNS_advanceSpeed",[]];
    if (count _owned==0) then {_owned=[getForcedSpeed _u,_speed]};
    if ((_u getVariable ["BURNS_advanceController",grpNull])!=_group) then {_u setVariable ["BURNS_advanceController",_group,true]};
    if (abs (getForcedSpeed _u-_speed)>0.05) then {_u forceSpeed _speed};
    if !(_owned isEqualTo [_owned select 0,_speed]) then {_owned=[_owned select 0,_speed]};
    if !((_u getVariable ["BURNS_advanceSpeed",[]]) isEqualTo _owned) then {_u setVariable ["BURNS_advanceSpeed",_owned,true]};
    private _last=_u getVariable ["BURNS_formationGoal",[]];
    // Slot correction: a droid more than 2 m off its slot is re-ordered there (at most every 2 s), not only on a new bound.
    if ((!_hasShot || {_walkFire}) && {_new || {count _last==0} || {_u distance2D _goal>2 && {time>=(_u getVariable ["BURNS_slotReorder",-1])}}}) then {
        _u setVariable ["BURNS_slotReorder",time+2];
        _u doMove _goal;_u setVariable ["BURNS_moveCleanupToken",nil];_u setVariable ["BURNS_formationGoal",_goal];
        _u setVariable ["BURNS_formationOrderCount",(_u getVariable ["BURNS_formationOrderCount",0])+1];
    };
} forEach _ordered;
private _orders=_ordered apply {[_x,_x getVariable ["BURNS_formationGoal",[]]]};
if !(_orders isEqualTo (_group getVariable ["BURNS_advanceOrders",[]])) then {_group setVariable ["BURNS_advanceOrders",_orders,true]};
if (speedMode _group!="NORMAL") then {_group setSpeedMode "NORMAL"};
if ((_group getVariable ["BURNS_lastRoleSpeed",""])!="NORMAL") then {_group setVariable ["BURNS_lastRoleSpeed","NORMAL",true]};
true
