// Fresh, bounded admission between dispatch and creation. Server reserves once;
// the worker creates once and never refunds an uncertain/lost acknowledgement.
DI_fnc_eligibleWorkers = {
    params ["_requested"];
    // Capability functions can exist before the BURNS registry is initialized.
    // Do not call its vehicle selector until all worker arrays are ready.
    if (isNil "FST_HC_Array" || {isNil "FST_HC_Ids"} || {isNil "FST_HC_UnitCounts"}) exitWith {[]};
    private _ranked = [];
    private _vehicle = if (isNil "FST_HCSpawn_fnc_getVehicleHC") then {[-1,-1]} else {[] call FST_HCSpawn_fnc_getVehicleHC};
    private _cap = missionNamespace getVariable ["FST_HC_PerHCSoftCap",0];
    private _exclusive = missionNamespace getVariable ["FST_HC_VehicleHCExclusive",true];
    {
        private _id = _x;
        private _i = _forEachIndex;
        private _entity = (missionNamespace getVariable ["FST_HC_Array",[]]) param [_i,objNull];
        private _health = DI_workers getOrDefault [str _id,[]];
        private _load = (missionNamespace getVariable ["FST_HC_UnitCounts",[]]) param [_i,0];
        if (_id <= 2 || {isNull _entity} || {owner _entity != _id} ||
            {_exclusive && {_id == _vehicle select 0}} ||
            {count _health < 3} || {time-(_health select 0) > 25} ||
            {_health select 1 < DI_minWorkerFPS} ||
            {_cap > 0 && {_load + _requested > _cap}}) then {continue};
        _ranked pushBack [_load,_id];
    } forEach (missionNamespace getVariable ["FST_HC_Ids",[]]);
    _ranked sort true;
    _ranked apply {_x select 1}
};
DI_fnc_spawnAdmitted = {
    params ["_id","_snapshot"];
    private _r = DI_actions getOrDefault [_id,createHashMap];
    if (count _r == 0 || {DI_mode != "active"} || {DI_phase != "active"} ||
        {_r get "generation" != DI_generation}) exitWith {false};
    private _o = DI_objectives getOrDefault [_r get "objective",createHashMap];
    if (count _o == 0 || {_o get "complete"}) exitWith {false};
    if !([_r get "position",_snapshot get "humans"] call DI_fnc_positionClear) exitWith {false};
    if (DI_testMode && {_r getOrDefault ["diagnostic",false]}) exitWith {true};
    private _ready = _snapshot get "ready";
    if (count _ready == 0) exitWith {false};
    private _center = _o get "position";
    private _near = _ready select {_x distance2D _center < DI_objectiveActivationDistance};
    if (count _near == 0) then {
        private _hints = [_ready] call DI_fnc_mapHints;
        _near = _hints getOrDefault [_r get "objective",[]];
    };
    if (count _near == 0) exitWith {false};
    private _strength = 0;
    {
        private _multiplier = if ([groupId group _x] call DI_fnc_elite) then {DI_eliteMultiplier} else {1};
        if ((DI_squadHistory getOrDefault [groupId group _x,[0,false,0]]) select 0 >= 2) then {_multiplier = _multiplier * 0.5};
        _strength = _strength + _multiplier;
    } forEach _near;
    private _pending = 0;
    {if (_x != _id && {!(_y getOrDefault ["settled",false])}) then {_pending = _pending + (_y get "count")}} forEach DI_actions;
    ([_ready,[_ready] call DI_fnc_mapHints] call DI_fnc_pressureEnemies) params ["_enemy","_engaged"];
    private _budget = floor ((count _ready * DI_globalReadyMultiplier) min DI_maxActiveInfantry min DI_pressureBudget);
    private _count = _r get "count";
    _count + count _engaged + _pending <= _budget &&
    {_count + ({_x distance2D _center < DI_localForceRadius} count _enemy) + _pending <= floor (_strength * DI_localReadyMultiplier)}
};
DI_fnc_spawnGrant = {
    if (!isServer) exitWith {};
    params ["_op","_id","_nonce","_owner"];
    private _r = DI_actions getOrDefault [_id,createHashMap];
    if (_op != DI_operation || {count _r == 0} || {_r get "nonce" != _nonce} ||
        {_r get "owner" != _owner} || {!(_owner in (missionNamespace getVariable ["FST_HC_Ids",[]]))} ||
        {!(remoteExecutedOwner in [0,_owner])} || {_r getOrDefault ["settled",false]}) exitWith {};
    private _diAuthorized = true;
    private _snap = [] call DI_fnc_observe;
    // Grant expires from first issue, never extended by duplicate requests.
    if !("grantUntil" in _r) then {
        private _admit = time-(_r get "createdAt") <= 15 &&
            {_owner in ([0] call DI_fnc_eligibleWorkers)} && {[_id,_snap] call DI_fnc_spawnAdmitted};
        _r set ["grantUntil",if (_admit) then {serverTime+DI_spawnGrantSeconds} else {-1}];
        _r set ["readyAtGrant",count (_snap get "ready")];
    };
    // Even a retry of a valid grant rechecks current server conditions.
    if !([_id,_snap] call DI_fnc_spawnAdmitted) then {_r set ["grantUntil",-1]};
    [_op,_id,_nonce,_r get "generation",_r get "template",_r get "position",_r get "objective",_owner,
        _r get "grantUntil",_r get "readyAtGrant",_r get "diagnostic"] remoteExecCall ["DI_fnc_workerCreate",_owner];
};
