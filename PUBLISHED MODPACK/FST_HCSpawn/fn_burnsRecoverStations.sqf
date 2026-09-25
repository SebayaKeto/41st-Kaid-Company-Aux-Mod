// Owner-local progress tracking. No teleport, world scan or per-unit timer.
// At most one empty-position query per group visit; one retry per station.
params ["_group","_slots","_centre","_radius",["_patrollers",[]]];
private _changed=false;
private _queried=false;
private _pending=false;
{
    _x params ["_unit","_target"];
    if (isNull _unit || {_unit in _patrollers} || {!local _unit} || {!alive _unit} || {_unit getVariable ["BURNS_exempt",false]} || {!(_unit checkAIFeature "PATH")}) then {continue};
    if (_unit distance _target<3) then {_unit setVariable ["BURNS_stationProgress",nil];continue};
    _pending=true;
    private _position=getPosATL _unit;
    private _progress=_unit getVariable ["BURNS_stationProgress",[+_target,+_position,time]];
    if (!((_progress select 0) isEqualTo _target) || {_position distance2D (_progress select 1)>1}) then {_progress=[+_target,+_position,time]};
    _unit setVariable ["BURNS_stationProgress",_progress];
    if (time-(_progress select 2)<20 || {_queried}) then {continue};
    _queried=true;
    private _level=_unit getVariable ["BURNS_stationFallback",0];
    private _next=+_position;
    private _message="cannot reach a fallback; holding its current position";
    if (_level==0) then {
        _unit setVariable ["BURNS_stationOriginal",+_target,true];
        private _approach=_target getPos [10,_target getDir _position];
        _approach set [2,0];
        if (_approach distance2D _centre>_radius) then {_approach=_centre getPos [_radius*0.8,_centre getDir _position]};
        private _free=_approach findEmptyPosition [0,6,typeOf _unit];
        if (count _free==3 && {!surfaceIsWater _free} && {_free distance2D _centre<=_radius}) then {
            _next=_free;
            _level=1;
            _message="cannot reach its building station; trying nearby clear ground";
        } else {_level=2};
    } else {_level=2};
    _unit setVariable ["BURNS_stationFallback",_level,true];
    _unit setVariable ["BURNS_stationProgress",[+_next,+_position,time]];
    _slots set [_forEachIndex,[_unit,_next]];
    _changed=true;
    doStop _unit;
    _unit doMove _next;
    diag_log format ["[BURNS_STATION_RECOVERY] owner=%1 group=%2 unit=%3 level=%4 original=%5 next=%6",clientOwner,_group,_unit,_level,_unit getVariable ["BURNS_stationOriginal",[]],_next];
    private _caller=_group getVariable ["BURNS_taskCaller",-1];
    if (_caller>2 && {time>=(_group getVariable ["BURNS_stationNoticeNext",-1])}) then {
        _group setVariable ["BURNS_stationNoticeNext",time+10];
        format ["[BURNS] %1: a unit %2. Placement is partial.",groupId _group,_message] remoteExec ["systemChat",_caller];
    };
} forEach _slots;
if (_changed) then {_group setVariable ["BURNS_stationSlots",_slots,true]};
private _live=_slots select {!isNull (_x select 0) && {alive (_x select 0)} && {!((_x select 0) in _patrollers)} && {!((_x select 0) getVariable ["BURNS_exempt",false])}};
private _arrived={(_x select 0) distance (_x select 1)<3} count _live;
private _fallbacks={((_x select 0) getVariable ["BURNS_stationFallback",0])>0} count _live;
private _status=[if (_fallbacks>0) then {"partial"} else {if (_arrived==count _live) then {"complete"} else {"moving"}},_arrived,count _live,_fallbacks];
if !((_group getVariable ["BURNS_stationStatus",[]]) isEqualTo _status) then {_group setVariable ["BURNS_stationStatus",_status,true]};
// Only while approaching stations. Completed groups return to normal cadence.
if (_pending) then {_group setVariable ["FST_HC_taskNext",time+5]};
_slots
