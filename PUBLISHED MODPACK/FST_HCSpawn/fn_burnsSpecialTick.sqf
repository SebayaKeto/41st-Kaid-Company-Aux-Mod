// Bounded building tasks. One shared cached area query, never one per soldier.
params ["_group","_mode","_centre","_radius"];
if !(_mode in ["garrison","camp","defend","cqb"]) exitWith {false};
private _units=(units _group) select {alive _x && {local _x} && {vehicle _x==_x} && {!(_x getVariable ["BURNS_exempt",false])}};
if (count _units==0) exitWith {true};
private _leader=leader _group;
private _options=_group getVariable ["BURNS_taskOptions",[]];
if (_mode=="cqb") exitWith {
    private _route=_group getVariable ["BURNS_cqbRoute",[]];
    if (count _route==0) then {
        private _scan=[_centre,_radius] call FST_HCSpawn_fnc_burnsPositions;
        if (_scan select 0) then {
            _route=(_scan select 1) select [0,32];
            if (count _route==0) then {_route=[_centre]};
            _group setVariable ["BURNS_cqbRoute",_route,true];
            _group setVariable ["BURNS_cqbIndex",0,true];
        } else {_group setVariable ["FST_HC_taskNext",time+2]};
    };
    if (count _route>0) then {
        private _index=_group getVariable ["BURNS_cqbIndex",0];
        if (_index>=count _route) then {[_group,"stop"] call FST_HCSpawn_fnc_setCombatTask} else {
            private _p=_route select _index;
            private _deadline=_group getVariable ["BURNS_cqbDeadline",-1];
            if (_deadline<0) then {
                {_x doMove (_route select ((_index+_forEachIndex) min (count _route-1)))} forEach _units;
                _group setVariable ["BURNS_cqbDeadline",time+45,true];
            } else {
                if (_leader distance _p<3 || {time>_deadline}) then {
                    _group setVariable ["BURNS_cqbIndex",_index+1,true];
                    _group setVariable ["BURNS_cqbDeadline",-1,true];
                };
            };
        };
    };
    true
};
// Install the local hit hook again when a held squad changes HC owner.
{
        if !(_x getVariable ["BURNS_holdHook",false]) then {
            _x setVariable ["BURNS_holdHook",true];
            _x addEventHandler ["Hit", {
                params ["_unit"];
                if (!local _unit) exitWith {};
                private _g=group _unit;
                if (((_g getVariable ["FST_HC_combatTask",[]]) param [0,""]) in ["garrison","camp","defend"] && {(_g getVariable ["BURNS_taskOptions",[]]) param [1,true]}) then {
                    _g setVariable ["BURNS_holdReleased",true,true];
                    _g setVariable ["FST_HC_taskNext",time];
                };
            }];
        };
} forEach _units;
private _slots=_group getVariable ["BURNS_stationSlots",[]];
if (count _slots==0) then {
    private _scan=if (count _options>3) then {[true,+(_options select 3)]} else {[_centre,_radius] call FST_HCSpawn_fnc_burnsPositions};
    if !(_scan select 0) exitWith {_group setVariable ["FST_HC_taskNext",time+2]};
    private _positions=_scan select 1;
    private _teleport=_options param [0,false];
    {
        private _p=if (_forEachIndex<count _positions) then {_positions select _forEachIndex} else {_centre getPos [8+4*floor(_forEachIndex/8),45*_forEachIndex]};
        if (surfaceIsWater _p && {!([_p] call FST_HCSpawn_fnc_isSafeGarrisonPos)}) then {_p=getPosATL _x};
        _slots pushBack [_x,_p];
        if (_teleport) then {_x setPosATL _p};
        _x doMove _p;
    } forEach _units;
    _group setVariable ["BURNS_stationSlots",_slots,true];
};
private _release=_group getVariable ["BURNS_holdReleased",false];
private _enemy=_leader findNearestEnemy _leader;
if (_options param [1,true] && {!isNull _enemy}) then {_release=true};
if (_release) then {
    if !(_group getVariable ["BURNS_holdReleased",false]) then {_group setVariable ["BURNS_holdReleased",true,true]};
    {if (_x getVariable ["BURNS_ownsPath",false]) then {_x enableAI "PATH";_x setVariable ["BURNS_ownsPath",nil,true]}} forEach _units;
};
{
    _x params ["_unit","_p"];
    if (isNull _unit || {!alive _unit} || {!local _unit} || {_unit getVariable ["BURNS_exempt",false]}) then {continue};
    if (!_release) then {
        if (_unit distance _p<3 && {!(_unit getVariable ["BURNS_ownsPath",false])}) then {
            doStop _unit;
            _unit disableAI "PATH";
            _unit setVariable ["BURNS_ownsPath",true,true];
        };
    } else {
        // Defenders move between cached stations; never chase out of the AO.
        if (_unit distance2D _centre > _radius || {_mode=="defend"}) then {_unit doMove _p};
    };
} forEach _slots;
// Camp's last pair patrols the perimeter using ordinary move commands.
if (_mode=="camp" && {!_release} && {count _units>=6}) then {
    {
        _x enableAI "PATH";
        _x setVariable ["BURNS_ownsPath",nil,true];
        _x doMove (_centre getPos [(_radius min 100)*0.7,(floor(time/30)*90)+180*_forEachIndex]);
    } forEach (_units select [count _units-2,2]);
};
true
