// One server planner, only for up to eight explicitly selected 2–3 tank sections.
// Existing owner-local tasks drive and fight. This only assigns stable goals.
if (!isServer) exitWith {};
private _keep=[];
{
    _x params ["_token","_roster","_objective","_axis","_origin","_phase","_plans","_last","_created","_caller"];
    private _enabled=missionNamespace getVariable ["BURNS_ArmorSectionsEnabled",true];
    _enabled=_enabled && {missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]};
    // Allow owner-event delivery to all HCs before planning the first leg.
    if (time-_created<10 && {(_roster findIf {(_x getVariable ["BURNS_sectionToken",""])!=_token})>=0} && {_enabled}) then {_keep pushBack _x;continue};
    private _members=_roster select {
        private _v=vehicle leader _x;private _d=driver _v;
        _enabled && {!isNull _x} && {(_x getVariable ["BURNS_sectionToken",""])==_token} && {
            (([_x,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet) param [0,""])=="assault"
        } && {!(_x getVariable ["BURNS_exempt",false])} && {(_x getVariable ["FST_HC_heldBy",-1])==-1} && {
            !([_x] call FST_HCSpawn_fnc_isProtectedVehicleGroup)
        } && {_v isKindOf "FST_AAT"} && {alive _v} && {canMove _v} && {simulationEnabled _v} && {!isNull _d} && {
            _d checkAIFeature "PATH"
        } && {_d checkAIFeature "MOVE"} && {(units _x findIf {alive _x && {vehicle _x!=_v}})<0}
    };
    if (count _members<2) then {
        {if ((_x getVariable ["BURNS_sectionToken",""])==_token) then {_x setVariable ["BURNS_sectionPlan",nil,true];_x setVariable ["BURNS_sectionToken",nil,true]}} forEach _roster;
        diag_log format ["[BURNS_SECTION_END] %1",_token];continue
    };
    // Never move surviving tanks into new slots because another tank was lost.
    private _vehicles=_members apply {vehicle leader _x};
    private _contact=false;
    {
        private _known=_x getVariable ["BURNS_sectionContact",[]];
        if (count _known==2 && {time-(_known select 1)<20} && {vehicle leader _x distance2D (_known select 0)<450}) then {_contact=true};
    } forEach _members;
    private _deploy=_phase=="COLUMN" && {time-_last>10} && {_contact || {(_vehicles findIf {_x distance2D _objective<180})>=0}};
    // Native tank movement brakes before the waypoint centre. Accept that band
    // rather than issuing repeated corrections to an already useful firing line.
    private _arrived=count _plans>0 && {(_plans findIf {(_x select 0) in _members && {vehicle leader (_x select 0) distance2D (_x select 1)>30}})<0};
    private _advance=count _plans==0 || {_deploy} || {_arrived && {time-_last>20}};
    private _stalled=count _plans>0 && {!_arrived} && {time-_last>60};
    if (_stalled) then {
        // Release cohesion rather than repeatedly reshuffling a blocked section.
        {if ((_x getVariable ["BURNS_sectionToken",""])==_token) then {_x setVariable ["BURNS_sectionPlan",nil,true];_x setVariable ["BURNS_sectionToken",nil,true]}} forEach _roster;
        if (_caller>2) then {"[BURNS] AAT section could not form on this terrain. Tanks continue their individual Assault orders; choose a clearer approach to regroup." remoteExec ["systemChat",_caller]};
        diag_log format ["[BURNS_SECTION_BLOCKED] %1",_token];continue
    };
    if (_advance) then {
        private _forward=[sin _axis,cos _axis,0];
        private _progress=_vehicles apply {((getPosATL _x) vectorDiff _origin) vectorDotProduct _forward};
        private _front=selectMax _progress;
        private _remaining=_origin distance2D _objective;
        private _step=if (_phase=="COLUMN" && {!_deploy}) then {55} else {35};
        private _center=_origin getPos [(_front+_step) min _remaining,_axis];
        // Prefer 150 m and close from beyond 200 m. Do not keep walking a line
        // toward a known tank simply because the clicked objective lies beyond it.
        private _close=false;
        {private _k=_x getVariable ["BURNS_sectionContact",[]];if (count _k==2 && {time-(_k select 1)<20} && {vehicle leader _x distance2D (_k select 0)<175}) then {_close=true}} forEach _members;
        if (_phase=="LINE" && {_close}) then {_advance=false};
        if (_advance) then {
            private _nextPhase=if (_deploy || {_phase=="LINE"}) then {"LINE"} else {"COLUMN"};
            private _new=[];private _safe=true;
            {
                private _index=_roster find _x;
                // Alternating fixed slots avoid swapping left/right across ticks.
                private _offset=([0,-30,30,-60] select _index);
                private _slot=if (_nextPhase=="LINE") then {_center getPos [abs _offset,_axis+(if (_offset<0) then {-90} else {90})]} else {_center getPos [35*_index,_axis+180]};
                private _v=vehicle leader _x;private _p=getPosATL _v;
                private _length=_p distance2D _slot;private _dir=_p getDir _slot;
                // A line is attempted only in a short, open, gentle corridor.
                // Native pathfinding handles column travel; hill recovery is separate.
                if (_nextPhase=="LINE") then {
                    if (_length>160) then {_safe=false};
                    for "_d" from 0 to ((_length min 160)+7) step 8 do {
                        private _q=_p getPos [_d min _length,_dir];
                        if (surfaceIsWater _q || {acos(surfaceNormal _q select 2)>12} || {
                            count(nearestTerrainObjects [_q,["TREE","SMALL TREE","ROCK","ROCKS","HOUSE","WALL"],7,false,true])>0
                        } || {(nearestObjects [_q,["LandVehicle","Man","Static"],7,true] findIf {!(_x in _vehicles) && {!(vehicle _x in _vehicles)}})>=0}) then {_safe=false};
                    };
                };
                _new pushBack [_x,_slot];
            } forEach _members;
            if (_safe) then {
                _plans=_new;_phase=_nextPhase;_last=time;
                diag_log format ["[BURNS_SECTION_PLAN] %1",[_token,_phase,_plans apply {[netId leader (_x select 0),_x select 1]}]];
            } else {
                // Keep a valid column plan; do not hammer failed line surveys.
                _last=time;
                diag_log format ["[BURNS_SECTION_LINE_REFUSED] %1",_token];
            };
        };
    };
    {if ((_x select 0) in _members) then {(_x select 0) setVariable ["BURNS_sectionPlan",[_token,+(_x select 1),_phase,time+6],true]}} forEach _plans;
    _keep pushBack [_token,_roster,_objective,_axis,_origin,_phase,_plans,_last,_created,_caller];
} forEach (missionNamespace getVariable ["BURNS_ArmorSections",[]]);
BURNS_ArmorSections=_keep;
if (count _keep==0 && {!isNil "BURNS_ArmorSectionPFH"}) then {[BURNS_ArmorSectionPFH] call CBA_fnc_removePerFrameHandler;BURNS_ArmorSectionPFH=nil};
