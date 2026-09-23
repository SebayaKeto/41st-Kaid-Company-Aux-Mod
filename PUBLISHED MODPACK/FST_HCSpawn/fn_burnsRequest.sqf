// Server broker. Resolve ownership at dispatch rather than moving the AI to Zeus.
params ["_mode",["_groups",[]],["_objects",[]],["_pos",[]],["_radius",150],["_options",[]],["_caller",-1]];
if (!isServer || {!([_caller,"BURNS order"] call FST_HCSpawn_fnc_isAuthorizedCaller)}) exitWith {false};
private _allowed=["stop","rush","hunt","creep","assault","retreat","cqb","garrison","camp","defend","patrol","reset","target","artillery_register","artillery_remove","artillery_fire","enable_group","disable_group","enable_unit","disable_unit","radio_on","radio_off","reinforce_on","reinforce_off"];
if !(_mode in _allowed) exitWith {false};
if (count _pos<2) exitWith {false};
if (_mode in ["rush","hunt","creep","assault","retreat","cqb","garrison","camp","defend","patrol","target"] && {!(missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true])}) exitWith {
    "[BURNS] Order declined: BURNS AI is disabled in addon settings. Existing orders are unchanged." remoteExec ["systemChat",_caller];false
};
_groups=+_groups;
{private _g=group _x; if (isNull _g) then {_g=group effectiveCommander _x}; if (!isNull _g) then {_groups pushBackUnique _g}} forEach _objects;
_groups=_groups select {!isNull _x && {count units _x>0} && {(units _x findIf {([_x] call FST_HCSpawn_fnc_isPlayerControlledUnit)})<0}};
_groups=_groups select {!([_x] call FST_HCSpawn_fnc_isProtectedVehicleGroup)};
_groups=_groups select [0,32];
_radius=(_radius max 25) min 3000;
if (_mode in ["reinforce_on","reinforce_off"]) then {
    if (isNil "BURNS_ReinforcementGroups") then {BURNS_ReinforcementGroups=[]};
    {if (_mode=="reinforce_on") then {BURNS_ReinforcementGroups pushBackUnique _x} else {BURNS_ReinforcementGroups=BURNS_ReinforcementGroups-[_x]}} forEach _groups;
};
if (_mode in ["garrison","camp","defend","cqb"]) then {_radius=_radius min 250};
if (_mode in ["enable_unit","disable_unit"]) exitWith {
    private _selectedUnits=_objects select {!isNull _x && {_x isKindOf "CAManBase"}};
    if (_selectedUnits isEqualTo []) then {{_selectedUnits append units _x} forEach _groups};
    _selectedUnits=_selectedUnits arrayIntersect _selectedUnits;
    {if (!([_x] call FST_HCSpawn_fnc_isPlayerControlledUnit)) then {["BURNS_unitAI",[_x,_mode=="enable_unit",_caller],owner _x] call CBA_fnc_ownerEvent}} forEach (_selectedUnits select [0,128]);
    true
};
if (isNil "BURNS_ArtilleryGroups") then {BURNS_ArtilleryGroups=[]};
if (_mode in ["artillery_register","artillery_remove"]) exitWith {
    {_x setVariable ["BURNS_artillery",_mode=="artillery_register",true]; if (_mode=="artillery_register") then {BURNS_ArtilleryGroups pushBackUnique _x} else {BURNS_ArtilleryGroups=BURNS_ArtilleryGroups-[_x]}} forEach _groups;
    format ["[BURNS] Artillery registry updated for %1 group(s).",count _groups] remoteExec ["systemChat",_caller];
    true
};
if (_mode=="artillery_fire" && {count _groups==0}) then {_groups=BURNS_ArtilleryGroups select {!isNull _x && {_x getVariable ["BURNS_artillery",false]}}};
if (count _groups==0) exitWith {"[BURNS] Select an AI unit, vehicle or group first." remoteExec ["systemChat",_caller]; false};
// Resolve target changes per group before scanning. Each movement request gets
// a revision so Reset/new orders cancel older queued scans and transfer retries.
private _movement=["rush","hunt","creep","assault","retreat","garrison","camp","defend","cqb","patrol","target"];
private _orders=[];
{
    private _group=_x;
    private _held=_group getVariable ["FST_HC_heldBy",-1];
    if (_held!=-1 && {_held!=_caller || {_caller<3}}) then {continue};
    if (_mode in _movement && {_group getVariable ["BURNS_exempt",false]}) then {continue};
    private _resolvedMode=_mode;
    private _resolvedRadius=_radius;
    private _resolvedOptions=+_options;
    if (_mode=="target") then {
        private _patrol=([_group,["BURNS_patrol",[]]] call FST_HCSpawn_fnc_burnsStateGet);
        private _task=([_group,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet);
        if (count _patrol==2) then {
            _resolvedMode="patrol";_resolvedRadius=_patrol select 1;
        } else {
            if (count _task==3) then {_resolvedMode=_task select 0;_resolvedRadius=_task select 2} else {_resolvedMode="assault"};
        };
        // Element 3 contains positions booked for the OLD destination.
        _resolvedOptions=(_group getVariable ["BURNS_taskOptions",[false,true,false]]) select [0,3];
        // An explicit Set Task Target can constrain a search to an area. The
        // ordinary Rush/Hunt/Creep actions have no anchor and require no click.
        if (_resolvedMode in ["rush","hunt","creep"]) then {
            _resolvedOptions set [3,[]];
            _resolvedOptions set [4,+_pos];
        };
    };
    private _revision=-1;
    if (_mode in (_movement+["stop","reset","disable_group"])) then {
        _revision=(_group getVariable ["BURNS_orderRevision",0])+1;
        _group setVariable ["BURNS_orderRevision",_revision,true];
    };
    _orders pushBack [_group,_resolvedMode,_resolvedRadius,_resolvedOptions,_revision];
} forEach _groups;
if (_orders isEqualTo []) exitWith {
    if (_caller>2) then {"[BURNS] Order declined: selected squads are disabled or held by another Zeus." remoteExec ["systemChat",_caller]};false
};
[_orders,_pos,_caller] spawn {
    params ["_orders","_pos","_caller"];
    {
        _x params ["_group","_mode","_radius","_options","_revision"];
        private _current={_revision<0 || {(_group getVariable ["BURNS_orderRevision",-1])==_revision}};
        if (isNull _group || {(units _group findIf {([_x] call FST_HCSpawn_fnc_isPlayerControlledUnit)})>=0} || {!(call _current)}) then {continue};
        private _holdTask=_mode in ["garrison","camp","defend"];
        private _positions=[];
        if (_holdTask) then {
            _radius=_radius min 250;
            private _deadline=time+10;
            private _scan=[_pos,_radius] call FST_HCSpawn_fnc_burnsPositions;
            waitUntil {
                sleep 0.1;
                _scan=[_pos,_radius] call FST_HCSpawn_fnc_burnsPositions;
                (_scan select 0) || {time>_deadline} || {!(call _current)}
            };
            if (_scan select 0) then {_positions=_scan select 1};
        };
        if (!(call _current) || {isNull _group}) then {continue};
        private _groupOptions=+_options;
        if (_holdTask) then {
            _groupOptions=[_options param [0,false],_options param [1,true],false,[_group,_positions,count units _group] call FST_HCSpawn_fnc_burnsReservePositions];
        };
        ["BURNS_order",[_mode,_group,_pos,_radius,_groupOptions,_caller,0,_revision],groupOwner _group] call CBA_fnc_ownerEvent;
        if (((_forEachIndex+1) mod ((missionNamespace getVariable ["FST_HC_TransferBatchSize",4]) max 1))==0) then {sleep (missionNamespace getVariable ["FST_HC_TransferInterval",2])};
    } forEach _orders;
};
true
