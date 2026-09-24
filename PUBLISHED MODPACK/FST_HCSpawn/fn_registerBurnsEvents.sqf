// BURNS commands work independently of HC transfer management.
if (missionNamespace getVariable ["BURNS_eventsRegistered",false]) exitWith {};
BURNS_eventsRegistered=true;
if (isServer) then {
    ["BURNS_simulation",{_this call FST_HCSpawn_fnc_burnsSimulation}] call CBA_fnc_addEventHandler;
    ["BURNS_request", {_this call FST_HCSpawn_fnc_burnsRequest}] call CBA_fnc_addEventHandler;
    ["BURNS_rerouteOrder", {
        params ["_mode","_group","_pos","_radius","_options","_caller",["_hop",1],["_revision",-1]];
        if (isNull _group || {!(_hop in [1,2,3])} || {!([_caller,"BURNS order retry"] call FST_HCSpawn_fnc_isAuthorizedCaller)}) exitWith {};
        if (_revision>=0 && {_revision<(_group getVariable ["BURNS_orderRevision",-1])}) exitWith {};
        private _owner=groupOwner _group;
        if (_owner<2) exitWith {};
        ["BURNS_order",[_mode,_group,_pos,_radius,_options,_caller,_hop,_revision],_owner] call CBA_fnc_ownerEvent;
    }] call CBA_fnc_addEventHandler;
    BURNS_ReinforcementGroups=[];
    ["BURNS_support", {
        params ["_source","_pos"];
        if (isNull _source || {!(_source getVariable ["BURNS_hasRadio",false])} || {time<(missionNamespace getVariable ["BURNS_supportNext",-1])}) exitWith {};
        if (time<(_source getVariable ["BURNS_supportNext",-1])) exitWith {};
        if ([_source] call FST_HCSpawn_fnc_isProtectedVehicleGroup) exitWith {};
        BURNS_supportNext=time+5;
        _source setVariable ["BURNS_supportNext",time+90];
        BURNS_ReinforcementGroups=BURNS_ReinforcementGroups select {!isNull _x && {_x getVariable ["BURNS_reinforcement",false]}};
        private _sent=0;
        {
            if (_sent>=2) exitWith {};
            if (_x==_source || {side _x!=side _source} || {!alive leader _x} || {leader _x distance2D _pos>3000} || {(units _x findIf {([_x] call FST_HCSpawn_fnc_isPlayerControlledUnit)})>=0} || {time<(_x getVariable ["BURNS_supportBusy",-1])}) then {continue};
            if (_x getVariable ["BURNS_exempt",false] || {(_x getVariable ["FST_HC_heldBy",-1])!=-1}) then {continue};
            if ([_x] call FST_HCSpawn_fnc_isProtectedVehicleGroup) then {continue};
            _x setVariable ["BURNS_supportBusy",time+120];
            ["BURNS_order",["assault",_x,_pos,500,[false,true,false],2,0],groupOwner _x] call CBA_fnc_ownerEvent;
            _sent=_sent+1;
        } forEach BURNS_ReinforcementGroups;
    }] call CBA_fnc_addEventHandler;

};
["BURNS_order", {
    params ["_mode","_group","_pos","_radius","_options","_caller",["_hop",0],["_revision",-1]];
    if (isNull _group) exitWith {};
    if (_revision>=0 && {_revision<((_group getVariable ["BURNS_orderRevision",-1]) max (_group getVariable ["BURNS_appliedRevision",-1]))}) exitWith {};
    if (!local _group || {(units _group findIf {alive _x && {!local _x}})>=0}) exitWith {
        // A transfer may race dispatch. Only the server can resolve groupOwner.
        // At most three delayed retries; never use owner 0 or broadcast the order.
        if (_hop<3) then {
            // groupOwner can change before the new machine owns every unit.
            // Wait for actual unit locality; a group-owner update can lag beyond 5 seconds.
            [{
                params ["","_group"];
                isNull _group || {local _group && {(units _group findIf {alive _x && {!local _x}})<0}}
            },{
                params ["_mode","_group","_pos","_radius","_options","_caller","_hop","_revision"];
                if (!isNull _group) then {["BURNS_rerouteOrder",[_mode,_group,_pos,_radius,_options,_caller,_hop+1,_revision]] call CBA_fnc_serverEvent};
            },[_mode,_group,_pos,_radius,_options,_caller,_hop,_revision],5,{
                params ["_mode","_group","_pos","_radius","_options","_caller","_hop","_revision"];
                if (!isNull _group) then {["BURNS_rerouteOrder",[_mode,_group,_pos,_radius,_options,_caller,_hop+1,_revision]] call CBA_fnc_serverEvent};
            }] call CBA_fnc_waitUntilAndExecute;
        } else {
            diag_log format ["[BURNS_ORDER_LOCALITY_TIMEOUT] mode=%1 group=%2 requestedOwner=%3 actualOwner=%4",_mode,_group,clientOwner,groupOwner _group];
            if (_caller>2) then {"[BURNS] Ownership is still changing; the order was not applied. Retry once the transfer finishes." remoteExec ["systemChat",_caller]};
        };
    };
    if (_revision>=0) then {_group setVariable ["BURNS_appliedRevision",_revision,true]};
    if (_mode=="artillery_fire") exitWith {[_group,_pos,_options,_caller] call FST_HCSpawn_fnc_burnsArtillery};
    private _ok=[_mode,_group,_pos,_radius,_options,_caller] call FST_HCSpawn_fnc_burnsCommand;
    diag_log format ["[BURNS_ORDER_RESULT] mode=%1 group=%2 owner=%3 accepted=%4 caller=%5",_mode,_group,clientOwner,_ok,_caller];
    diag_log format ["[BURNS_ORDER_IDENTITY] group=%1 vehicle=%2 class=%3 pos=%4 destination=%5 revision=%6",_group,netId vehicle leader _group,typeOf vehicle leader _group,getPosATL vehicle leader _group,_pos,_revision];
    if (_ok && {_caller>2} && {_mode!="stop"}) then {format ["[BURNS] %1: order accepted for %2.",toUpper _mode,groupId _group] remoteExec ["systemChat",_caller]};
    if (!_ok) then {"[BURNS] Order declined: BURNS disabled for this group, held by another Zeus, player controlled, or invalid task." remoteExec ["systemChat",_caller]};
}] call CBA_fnc_addEventHandler;
["BURNS_unitAI", {
    params ["_unit","_enabled",["_caller",-1]];
    private _held=(group _unit) getVariable ["FST_HC_heldBy",-1];
    if (_held!=-1 && {_held!=_caller || {_caller<3}}) exitWith {};
    if (!local _unit || {([_unit] call FST_HCSpawn_fnc_isPlayerControlledUnit)} || {([_unit] call FST_HCSpawn_fnc_burnsRole)=="webknight"}) exitWith {};
    if ([group _unit] call FST_HCSpawn_fnc_isProtectedVehicleGroup) exitWith {};
    _unit setVariable ["BURNS_exempt",!_enabled,true];
    if (_enabled) then {[group _unit] call FST_HCSpawn_fnc_burnsApplyRole} else {
        [_unit] call FST_HCSpawn_fnc_burnsRestoreRole;
    };
}] call CBA_fnc_addEventHandler;

