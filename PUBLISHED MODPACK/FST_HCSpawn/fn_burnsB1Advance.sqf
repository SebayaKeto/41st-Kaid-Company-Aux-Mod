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
        // Squads on every machine count (Miran 10 Oct "bunch up ... killed by a single grenade"): module squads are spread
        // over the HCs, and lanes that saw only same-HC squads let lines from different HCs converge on one objective.
        private _peers=allGroups select {
            side _x==side _group && {count units _x>0} && {
                private _t=[_x,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet;
                count _t==3 && {(_t select 0) in ["assault","hunt"]} && {((_t select 1) distance2D _destination)<60}
            }
        };
        if !(_group in _peers) then {_peers pushBack _group};
        private _c=[0,0,0];
        {_c=_c vectorAdd (getPosATL leader _x)} forEach _peers;
        _c=_c vectorMultiply (1/count _peers);
        private _axis=_c getDir _destination;
        // Sideways place of every squad, then pushed apart left to right so neighbouring lines keep 10 m between them
        // (line width from the droid count and BURNS_B1LineSpacing), re-centred on the squads' average.
        private _gapL=missionNamespace getVariable ["BURNS_B1LineSpacing",4];
        private _lats=[];
        {
            private _rel=(getPosATL leader _x) vectorDiff _c;
            _lats pushBack [((_rel select 0)*cos _axis)-((_rel select 1)*sin _axis),netId _x,((({alive _x} count units _x) min 12)-1) max 0,_forEachIndex];
        } forEach _peers;
        _lats sort true;
        private _adj=[];
        private _sum=0;
        {
            private _l=_x select 0;
            if (_forEachIndex>0) then {private _p=_adj select (_forEachIndex-1); _l=_l max ((_p select 0)+((_p select 1)+(_x select 2))*_gapL/2+10)};
            _adj pushBack [_l,_x select 2,_x select 3];
            _sum=_sum+(_x select 0)-_l;
        } forEach _lats;
        private _me=_peers find _group;
        private _lat=(((_adj select (_adj findIf {(_x select 2)==_me})) select 0)+_sum/(count _adj)) max -150 min 150;
        private _lock=if (count _lane==4 && {(_lane select 0) isEqualTo _key}) then {_lane select 3} else {time+30};
        _lane=[_key,_lat,_axis,_lock];
        _group setVariable ["BURNS_lane",_lane];
        _group setVariable ["BURNS_linePeers",_peers-[_group]];
    };
    _lane params ["","_lat","_axis"];
    if (abs _lat>5) then {_destination=_destination getPos [abs _lat,_axis+([-90,90] select (_lat>0))]};
};
// The B1 line is centred on its objective, not on its leader (the leader's place follows where it stood; see the deal
// below), so neighbouring lanes keep their gap.
if (_line && {missionNamespace getVariable ["BURNS_B1TrackFormation",true]} && {!(missionNamespace getVariable ["BURNS_B1HybridFormation",false])}) then {
    private _deal0=_group getVariable ["BURNS_trackDeal",[]];
    if (count _deal0==4 && {abs (_deal0 select 3)>0.5}) then {_destination=_destination getPos [abs (_deal0 select 3),(_deal0 select 1)+([-90,90] select ((_deal0 select 3)>0))]};
};
private _direction=_origin getDir _destination;
// Lane convergence (probe hlt51: four module squads 40 m apart with 44 m wide lines walked straight at lane objectives
// 400 m away, so the outer squads slid sideways a few metres a minute and neighbouring lines overlapped 28% of the time).
// Beyond 80 m the squad aims at its lane line 3x its sideways error ahead (at least 40 m): at most ~18 degrees off the
// lane axis, in its lane within ~60 m, and under the 30 degree re-deal threshold so the line keeps its places.
if (_taskMode in ["assault","hunt"]) then {
    private _laneC=_group getVariable ["BURNS_lane",[]];
    if (count _laneC==4) then {
        private _ax=_laneC select 2;
        private _af=[sin _ax,cos _ax,0];
        private _ar=[cos _ax,-(sin _ax),0];
        private _rel=_origin vectorDiff _destination;
        private _toGo=-(_rel vectorDotProduct _af);
        private _err=_rel vectorDotProduct _ar;
        if (_toGo>80 && {abs _err>3}) then {
            private _ahead=(((abs _err)*3) max 40) min (_toGo-40);
            _direction=_origin getDir (_destination vectorAdd (_af vectorMultiply (_ahead-_toGo)));
        };
    };
};
// Road march (Miran 17 Oct: "Can we give droids on a road preference for staying on the road?"). The road from the leader is
// followed up to 120 m on toward the objective (at each junction the branch nearest the objective). If that stretch closes on the
// objective by at least 30% of its length (15% to stay on a road already being marched), the squad follows the road: the leader heads
// for the road point 40 m on, the droids in pairs on its trail. A 50 m look-ahead (probe rdV55c) dropped the road at every bend of a
// winding road. The squad deploys into line where the road turns away, within 100 m of the objective or with an enemy within 100 m
// (back on the road beyond 120 m). A squad still in COLUMN (far out, no contact) heads for the road point instead of the straight
// bearing. CBA setting "B1 road march".
private _roadPt=[];
if ((missionNamespace getVariable ["BURNS_B1RoadMarch",true]) && {_taskMode=="assault"} && {(_origin distance2D _destination)>100}) then {
    private _was=_group getVariable ["BURNS_roadMarch",false];
    private _ne=_leader findNearestEnemy _leader; private _ed=if (isNull _ne) then {1e9} else {_leader distance2D _ne};
    if (_ed>(if (_was) then {100} else {120})) then {
        private _r=roadAt _origin;
        if (isNull _r) then {private _rs=(_origin nearRoads (if (_was) then {15} else {8})) select {!((getRoadInfo _x) param [2,false])}; if (count _rs>0) then {_r=_rs select 0}};
        if (!isNull _r && {!((getRoadInfo _r) param [2,false])}) then {
            private _cur=_r; private _seen=[_r]; private _len=0; private _goalPt=[];
            for "_i" from 1 to 60 do {
                private _next=(roadsConnectedTo _cur) select {!(_x in _seen) && {!((getRoadInfo _x) param [2,false])}};
                if (count _next==0 || {_len>=120}) exitWith {};
                private _best=_next select 0; private _bd=1e9;
                {private _d=_x distance2D _destination; if (_d<_bd) then {_bd=_d;_best=_x}} forEach _next;
                _len=_len+(_cur distance2D _best); _seen pushBack _best; _cur=_best;
                if (count _goalPt==0 && {_len>=40}) then {_goalPt=getPosATL _cur};
            };
            if (count _goalPt==0) then {_goalPt=getPosATL _cur};
            if (_len>=30 && {((_origin distance2D _destination)-(_cur distance2D _destination))>=(if (_was) then {0.15} else {0.3})*_len}) then {_roadPt=[_goalPt select 0,_goalPt select 1,0]};
        };
    };
};
if (!_line && {count _roadPt>=2}) then {_direction=_origin getDir _roadPt};
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
    _group setVariable ["BURNS_track",nil];_group setVariable ["BURNS_trackGo",nil];_group setVariable ["BURNS_trackDeal",nil];_group setVariable ["BURNS_leaderTrail",nil];{_group setVariable [_x,nil]} forEach ["BURNS_detourGoal","BURNS_detourFails","BURNS_roadMarch","BURNS_detourStart","BURNS_detourUntil","BURNS_detourCount","BURNS_detourMove","BURNS_leaderProg","BURNS_trackDetour"];
    {if (!isNil {_x getVariable "BURNS_atCatchUp"}) then {_x enableAI "FIREWEAPON";_x enableAI "AUTOTARGET";_x enableAI "TARGET";_x setVariable ["BURNS_atCatchUp",nil]}} forEach _ordered;
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
    // Places in the line follow where the droids stand (Miran 10 Oct: "when trying to make lines often bunch up and then
    // all get killed by a single grenade"). Probe lp48: places dealt left/right by roster number sent half the squad
    // across the leader - up to 7 of 8 droids inside one 5 m circle for ~20 s - and every casualty re-dealt them. Now
    // the droids are ranked by their sideways position (the front rank by distance forward) and keep that order; the
    // deal is redone only when the roster changes or, beyond 80 m of the objective, the heading turns more than 30 degrees
    // (closer in the heading swings; no re-deal churn). One rank up to 12 droids, BURNS_B1LineSpacing apart (default
    // 4 m); a bigger squad stands in two ranks, the rear rank staggered half a place.
    private _deal=_group getVariable ["BURNS_trackDeal",[]];
    if (count _deal!=4 || {!((_deal select 0) isEqualTo _ordered)} || {_remain>80 && {abs (((((_deal select 1)-_direction)+540) mod 360)-180)>30}}) then {
        private _gap=missionNamespace getVariable ["BURNS_B1LineSpacing",4];
        private _n=count _ordered;
        private _cols=if (_n<=12) then {_n} else {ceil (_n/2)};
        private _keyed=[];
        {private _d=(getPosATL _x) vectorDiff _lp;_keyed pushBack [_d vectorDotProduct _fwd,_d vectorDotProduct _right,_forEachIndex]} forEach _ordered;
        private _rest=_keyed select [1,_n];
        _rest sort false;
        private _place=_ordered apply {[0,0]};
        {
            private _rank=_forEachIndex;
            private _row=_x apply {[_x select 1,_x select 2]};
            _row sort true;
            private _m=count _row;
            {_place set [_x select 1,[((_forEachIndex-(_m-1)/2)+_rank*0.5)*_gap,_rank*_spacing]]} forEach _row;
        } forEach ([[_keyed select 0]+(_rest select [0,_cols-1]),_rest select [_cols-1,_n]] select {count _x>0});
        private _lo=(_place select 0) select 0;
        _deal=[+_ordered,_direction,_place apply {[(_x select 0)-_lo,_x select 1]},_lo];
        _group setVariable ["BURNS_trackDeal",_deal];
    };
    private _offs=_deal select 2;
    // Terrain splits (Miran 17 Oct, Aparra: "bunching up on the road here, and then not advancing because some of their droids are
    // split up due to terrain"). A droid whose place lay in or behind a rock wall walked into it and stood still, and the line formed
    // on the squad's average, so a few stuck droids pulled the line back and the whole squad stopped. Now a droid ordered to move
    // (forced speed >=1) that has moved under 2 m in 8 s while >6 m from its track point is "blocked": it leaves the line's anchor
    // and files along the leader's own trail (reachable: the leader walked it), 4 m apart, for 20 s per strike (max 60), then tries
    // its place again. Strikes clear once it reaches its place. Leader trail: a point every 3 m, last 12.
    private _dbg=missionNamespace getVariable ["BURNS_B1Debug",false];
    private _trail=_group getVariable ["BURNS_leaderTrail",[]];
    if (count _trail>0 && {((_trail select (count _trail-1)) distance2D _lp)>40}) then {_trail=[]};
    if (count _trail==0 || {((_trail select (count _trail-1)) distance2D _lp)>3}) then {
        _trail pushBack [_lp select 0,_lp select 1,0];
        if (count _trail>12) then {_trail deleteAt 0};
        _group setVariable ["BURNS_leaderTrail",_trail];
    };
    // Squad stall -> detour (Miran 17 Oct, Aparra: "These two squads got stuck for a bit here, rather than going down the road they
    // just kept trying to go around on terrain"). The line steers every droid, the leader too, at a point up to 40 m ahead on the
    // straight bearing, so a rock band across that bearing stops the whole squad and the 2 s re-orders keep it probing the same way.
    // A leader ordered to move that has closed under 6 m on its objective in 12 s puts the squad on a detour: the leader gets one
    // long move to the objective (the engine plans the whole route round) and every droid files along its trail, 4 m apart; then
    // the line forms again. 30 s, then 60 s, 90 s on repeat stalls within 2 min.
    private _road=_go && {count _roadPt>=2};
    if (_road!=(_group getVariable ["BURNS_roadMarch",false])) then {
        private _dbg=missionNamespace getVariable ["BURNS_B1Debug",false];
        _group setVariable ["BURNS_roadMarch",_road];
        if (_dbg) then {diag_log format ["[BURNS_DBG] road march %1: %2, %3 m to go",_group,["off","on"] select _road,round _remain]};
    };
    // A detour lasts until the leader has closed 25 m on the objective since it began (probe rk2V55b: a 30 s detour ended still
    // beside the wall and the line walked back into it), at most 2 min.
    private _dStart=_group getVariable ["BURNS_detourStart",[]];
    if (_go && {!_road} && {count _dStart==2} && {time>=(_group getVariable ["BURNS_detourUntil",-1])} && {time-(_dStart select 0)<120} && {((_dStart select 1)-_remain)<25}) then {
        _group setVariable ["BURNS_detourUntil",time+4];
    };
    private _detour=_go && {!_road} && {time<(_group getVariable ["BURNS_detourUntil",-1])};
    // A flank detour ends when the leader reaches its flank point (then the line tries again from there).
    private _dGoal=_group getVariable ["BURNS_detourGoal",[]];
    if (_detour && {count _dGoal==3} && {(_lp distance2D _dGoal)<20}) then {
        _group setVariable ["BURNS_detourUntil",time]; _group setVariable ["BURNS_detourGoal",[]]; _detour=false;
        if (_dbg) then {diag_log format ["[BURNS_DBG] detour %1: reached flank point, %2 m to go",_group,round _remain]};
    };
    if (!_detour && {count _dGoal==3}) then {_group setVariable ["BURNS_detourGoal",[]]};
    private _lprog=_group getVariable ["BURNS_leaderProg",[]];
    private _lfs=getForcedSpeed _leader;
    if (_detour || {_road} || {!_go} || {_waiting} || {time<(_leader getVariable ["BURNS_volleyHold",-1])} || {_lfs>=0 && {_lfs<1}} || {count _lprog!=2}) then {
        _group setVariable ["BURNS_leaderProg",[time,_remain]];
    } else {
        if (time-(_lprog select 0)>=12) then {
            if (((_lprog select 1)-_remain)<6) then {
                private _dc=_group getVariable ["BURNS_detourCount",[0,-1e9]];
                private _k=if (time-(_dc select 1)>120) then {1} else {((_dc select 0)+1) min 3};
                _group setVariable ["BURNS_detourCount",[_k,time]];
                _group setVariable ["BURNS_detourUntil",time+30*_k];
                _group setVariable ["BURNS_detourMove",nil];
                // Flank detours (V55l; Sarrak probe sk1, Crossmarket: road march led a B1 squad to a CIS wall gate closed at mission start,
                // 249 m out; five detours straight at the objective each closed 0 m, the engine kept planning through the gate, while B2s and
                // AATs got in through gaps in the wall). If the previous detour gained under 10 m, this one heads for a point beside the
                // objective, rotated 70 deg round it from the leader (then -70, +140, -140 on further failures), so the squad works round the
                // outside of a wall or obstacle until it finds a way in.
                private _ds0=_group getVariable ["BURNS_detourStart",[]];
                private _fails=_group getVariable ["BURNS_detourFails",0];
                _fails=if (count _ds0==2 && {((_ds0 select 1)-_remain)<10}) then {_fails+1} else {0};
                _group setVariable ["BURNS_detourFails",_fails];
                private _fg=[];
                if (_fails>0) then {
                    _fg=_destination getPos [((_remain max 60) min 250),(_destination getDir _lp)+([70,-70,140,-140] select ((_fails-1) mod 4))];
                    _fg=[_fg select 0,_fg select 1,0];
                    if (surfaceIsWater _fg) then {_fg=[]};
                };
                _group setVariable ["BURNS_detourGoal",_fg];
                _group setVariable ["BURNS_detourStart",[time,_remain]];
                _detour=true;
                if (_dbg) then {diag_log format ["[BURNS_DBG] detour %1: closed %2 m in %3 s, %4 m to go, for %5 s%6",_group,round ((_lprog select 1)-_remain),round (time-(_lprog select 0)),round _remain,30*_k,if (count _fg==3) then {format [", flank %1 (failed detours %2)",[round (_fg select 0),round (_fg select 1)],_fails]} else {""}]};
            };
            _group setVariable ["BURNS_leaderProg",[time,_remain]];
        };
    };
    // Files: on a detour or a road march every droid follows the leader's trail.
    private _file=_detour || _road;
    private _blocked=_ordered apply {false};
    {
        if (_forEachIndex==0) then {continue};
        private _u=_x;
        private _p=getPosATL _u;
        private _prog=_u getVariable ["BURNS_lineProg",[]];
        private _lease=_u getVariable ["BURNS_pointFireLease",[]];
        private _fs=getForcedSpeed _u;
        private _idle=_file || {time<(_u getVariable ["BURNS_volleyHold",-1])} || {count _lease==4 && {time<(_lease select 1)}} || {_fs>=0 && {_fs<1}} || {vehicle _u!=_u};
        if (_idle || {count _prog!=2}) then {_u setVariable ["BURNS_lineProg",[time,_p]]} else {
            if (time-(_prog select 0)>=8) then {
                private _tg=_u getVariable ["BURNS_trackGoal",[]];
                if ((_p distance2D (_prog select 1))<2 && {count _tg>=2} && {(_u distance2D _tg)>6}) then {
                    private _k=(_u getVariable ["BURNS_lineStrikes",0])+1;
                    _u setVariable ["BURNS_lineStrikes",_k];
                    _u setVariable ["BURNS_lineBlocked",time+((20*_k) min 60)];
                    if (_dbg) then {diag_log format ["[BURNS_DBG] blocked %1 %2: moved %3 m in %4 s, %5 m from track point, strike %6",_group,_u,round ((_p distance2D (_prog select 1))*10)/10,round (time-(_prog select 0)),round (_u distance2D _tg),_k]};
                };
                _u setVariable ["BURNS_lineProg",[time,_p]];
            };
        };
        _blocked set [_forEachIndex,_file || {time<(_u getVariable ["BURNS_lineBlocked",-1])}];
    } forEach _ordered;
    // The line forms on its own position, not on the leader (probe lp28: chasing the leader, the line trailed it in a shallow V,
    // riflemen a median 3 m and p90 9 m behind). AT droids on native control and blocked droids are left out, and the anchor is the
    // median (lower middle), not the mean, so a few droids caught on terrain can't hold the whole line back.
    private _alongs=[];
    {if (!(_blocked select _forEachIndex) && {_x==_leader || {secondaryWeapon _x==""}}) then {_alongs pushBack ((((getPosATL _x) vectorDiff _lp) vectorDotProduct _fwd)+((_offs select _forEachIndex) select 1))}} forEach _ordered;
    _alongs sort true;
    private _anchor=if (count _alongs==0) then {0} else {_alongs select floor (((count _alongs)-1)/2)};
    private _ideals=_offs apply {_lp vectorAdd (_right vectorMultiply (_x select 0)) vectorAdd (_fwd vectorMultiply (_anchor-(_x select 1)))};
    // Blocked droids: a point on the leader's trail 6 m + 4 m per blocked droid behind the leader, alternating 1.5 m left/right.
    private _nb=0;
    {
        if !(_blocked select _forEachIndex) then {continue};
        private _u=_x;
        if (!_file && {((_ideals select _forEachIndex) distance2D _u)<5}) then {
            _u setVariable ["BURNS_lineBlocked",nil];_blocked set [_forEachIndex,false];
            if (_dbg) then {diag_log format ["[BURNS_DBG] unblocked %1 %2: back at its place",_group,_u]};
            continue;
        };
        private _back=if (_road) then {6+3*floor (_nb/2)} else {6+4*_nb};
        private _acc=0; private _prev=_lp; private _pt=+_lp;
        for "_i" from (count _trail-1) to 0 step -1 do {
            private _q=_trail select _i;
            _acc=_acc+(_prev distance2D _q); _pt=_q; _prev=_q;
            if (_acc>=_back) exitWith {};
        };
        if (_acc<_back) then {_pt=_pt vectorAdd (_fwd vectorMultiply (_acc-_back))};
        _pt=_pt vectorAdd (_right vectorMultiply ([-1.5,1.5] select (_nb mod 2))*(if (_road) then {4/3} else {1}));
        _ideals set [_forEachIndex,[_pt select 0,_pt select 1,0]];
        _nb=_nb+1;
    } forEach _ordered;
    // The leader eases off while its line lags (75th percentile >6 m behind its places) and waits beyond 12 m;
    // one straggler (e.g. an AT droid on native control) no longer stops the squad.
    private _leadSpeed=if (_go) then {if (_waiting && {!_file}) then {_march*0.4} else {_march}} else {0};
    _group setVariable ["BURNS_trackDetour",_file];
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
        private _blk=_blocked select _forEachIndex;
        if (!_blk && {(_u distance2D _ideal)<3}) then {_u setVariable ["BURNS_lineStrikes",nil]};
        private _along=((getPosATL _u) vectorDiff _ideal) vectorDotProduct _fwd;
        private _goal=if (_go && {!_blk}) then {_ideal vectorAdd (_fwd vectorMultiply _toFront)} else {+_ideal};
        _goal set [2,0];
        // Detour leader: one move order to the objective itself, re-sent only if the objective moves or the leader stops.
        // Road-march leader: the road point ~50 m ahead, re-sent as it moves on 10 m.
        private _dLead=_file && {_u==_leader};
        if (_dLead) then {_ideal=if (_road) then {+_roadPt} else {private _dg=_group getVariable ["BURNS_detourGoal",[]]; if (count _dg==3) then {+_dg} else {[_destination select 0,_destination select 1,0]}};_goal=+_ideal};
        private _target=assignedTarget _u;
        if (isNull _target) then {_target=_contact};
        private _inSlot=_u distance2D _ideal<3;
        private _hasShot=_inSlot && {!isNull _target} && {alive _target} && {_u knowsAbout _target>=1} && {_u distance2D _target<250} && {([_u,"FIRE",vehicle _target] checkVisibility [eyePos _u,aimPos vehicle _target])>0.5};
        if (time<(_u getVariable ["BURNS_volleyHold",-1])) then {continue};
        private _hold=_hasShot && {!_walkFire};
        // Every droid, the leader included, keeps its place in the line: behind it a droid closes at up to +1.5 m/s,
        // ahead of it it eases off and stops 3 m ahead, so nobody walks out in front while the line volleys or waits.
        // A blocked droid jogs to its trail point (at least 2 m/s) and then keeps the leader's pace.
        private _speed=if (_dLead) then {_leadSpeed} else {if (_hold) then {0} else {
            if (_blk) then {
                if ((_u distance2D _ideal)>3) then {((_leadSpeed+1.5) max 2) min 4.5} else {_leadSpeed}
            } else {
                if (_along>0) then {_leadSpeed*((1-_along/3) max 0)} else {
                    if (_leadSpeed<0.1) then {if (_u distance2D _ideal<1.5) then {0} else {((-_along*0.5) max 0.8) min 2.5}} else {(_leadSpeed+((-_along*0.5) min 1.5)) min 4.5}
                }
            }
        }};
        private _owned=_u getVariable ["BURNS_advanceSpeed",[]];
        if (count _owned==0) then {_owned=[getForcedSpeed _u,_speed]};
        if ((_u getVariable ["BURNS_advanceController",grpNull])!=_group) then {_u setVariable ["BURNS_advanceController",_group,true]};
        if (abs (getForcedSpeed _u-_speed)>0.05) then {_u forceSpeed _speed};
        if !(_owned isEqualTo [_owned select 0,_speed]) then {_owned=[_owned select 0,_speed]};
        if !((_u getVariable ["BURNS_advanceSpeed",[]]) isEqualTo _owned) then {_u setVariable ["BURNS_advanceSpeed",_owned,true]};
        _u setVariable ["BURNS_formationGoal",_ideal];
        // A new track order only when the droid nears its current track point or its track moved sideways.
        private _last=_u getVariable ["BURNS_trackGoal",[]];
        private _reorder=count _last<2 || {time>(_u getVariable ["BURNS_trackAt",-1])+20} || {_u distance2D _last<8 && {_go}} || {abs (((_goal vectorDiff _last) vectorDotProduct _right))>3} || {!_go && {_last distance2D _goal>3}} || {_blk && {_last distance2D _goal>4}};
        if (_dLead) then {_reorder=count _last<2 || {_last distance2D _goal>(if (_road) then {10} else {15})} || {unitReady _u}};
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
