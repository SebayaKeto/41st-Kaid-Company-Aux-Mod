// Server broker. Resolve ownership at dispatch rather than moving the AI to Zeus.
params ["_mode",["_groups",[]],["_objects",[]],["_pos",[]],["_radius",150],["_options",[]],["_caller",-1]];
if (!isServer || {!([_caller,"BURNS order"] call FST_HCSpawn_fnc_isAuthorizedCaller)}) exitWith {false};
private _allowed=["rush","hunt","creep","assault","retreat","cqb","garrison","camp","defend","patrol","reset","target","artillery_register","artillery_remove","artillery_fire","enable_group","disable_group","enable_unit","disable_unit","radio_on","radio_off","reinforce_on","reinforce_off"];
if !(_mode in _allowed) exitWith {false};
if (count _pos<2) exitWith {false};
_groups=+_groups;
{private _g=group _x; if (isNull _g) then {_g=group effectiveCommander _x}; if (!isNull _g) then {_groups pushBackUnique _g}} forEach _objects;
_groups=_groups select {!isNull _x && {count units _x>0} && {(units _x findIf {isPlayer _x})<0}};
_groups=_groups select {!([_x] call FST_HCSpawn_fnc_isProtectedVehicleGroup)};
_groups=_groups select [0,32];
_radius=(_radius max 25) min 3000;
if (_mode in ["reinforce_on","reinforce_off"]) then {
    if (isNil "BURNS_ReinforcementGroups") then {BURNS_ReinforcementGroups=[]};
    {if (_mode=="reinforce_on") then {BURNS_ReinforcementGroups pushBackUnique _x} else {BURNS_ReinforcementGroups=BURNS_ReinforcementGroups-[_x]}} forEach _groups;
};
if (_mode in ["garrison","camp","defend","cqb"]) then {_radius=_radius min 250};
if (_mode in ["enable_unit","disable_unit"]) exitWith {
    {if (!isPlayer _x && {_x isKindOf "CAManBase"}) then {["BURNS_unitAI",[_x,_mode=="enable_unit"],owner _x] call CBA_fnc_ownerEvent}} forEach (_objects select [0,128]);
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
// Use the existing transfer batch size and pacing for large command selections.
[_mode,_groups,_pos,_radius,_options,_caller] spawn {
    params ["_mode","_groups","_pos","_radius","_options","_caller"];
    private _holdTask=_mode in ["garrison","camp","defend"];
    private _positions=[];
    if (_holdTask) then {
        private _deadline=time+10;
        private _scan=[_pos,_radius] call FST_HCSpawn_fnc_burnsPositions;
        waitUntil {sleep 0.1;_scan=[_pos,_radius] call FST_HCSpawn_fnc_burnsPositions;(_scan select 0) || {time>_deadline}};
        if (_scan select 0) then {_positions=_scan select 1};
    };
    {
        if (isNull _x || {(units _x findIf {isPlayer _x})>=0}) then {continue};
        private _groupOptions=+_options;
        if (_holdTask) then {
            _groupOptions=[_options param [0,false],_options param [1,true],false,[_x,_positions,count units _x] call FST_HCSpawn_fnc_burnsReservePositions];
        };
        ["BURNS_order",[_mode,_x,_pos,_radius,_groupOptions,_caller,0],groupOwner _x] call CBA_fnc_ownerEvent;
        if (((_forEachIndex+1) mod ((missionNamespace getVariable ["FST_HC_TransferBatchSize",4]) max 1))==0) then {sleep (missionNamespace getVariable ["FST_HC_TransferInterval",2])};
    } forEach _groups;
};
true
