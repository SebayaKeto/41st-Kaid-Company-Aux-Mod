DI_fnc_log = {
    params ["_kind",["_data",[]]];
    diag_log format ["[DAARA] %1 t=%2 owner=%3 data=%4",_kind,round time,clientOwner,_data];
};
DI_fnc_elite = {
    params ["_name"];
    private _n = toLower _name;
    (_n find "ranger" >= 0) || {_n find "vornskr" >= 0}
};
// Pure compatibility path for servers without the new shared BURNS helper.
// Query remoteControlled only where the queried object is local.
DI_fnc_isPlayerControlledUnitFallback = {
    params ["_unit"];
    if (isNull _unit) exitWith {false};
    if (isPlayer _unit) exitWith {true};
    private _inverseControlled=false;
    if (local _unit) then {
        private _controller=remoteControlled _unit;
        _inverseControlled=!isNull _controller && {isPlayer _controller};
    };
    if (_inverseControlled) exitWith {true};
    private _controller=_unit getVariable ["bis_fnc_moduleRemoteControl_owner",objNull];
    if !(_controller isEqualType objNull) exitWith {false};
    if (isNull _controller || {!isPlayer _controller}) exitWith {false};
    if (local _controller) exitWith {isRemoteControlling _controller && {(remoteControlled _controller)==_unit}};
    // The remote actor's forward link is not safely queryable here. Preserve
    // the engine-published marker through handoff until the engine clears it.
    // A stale marker for a connected remote actor conservatively blocks AI.
    true
};
DI_fnc_isPlayerControlledUnit = {
    params ["_unit"];
    if (!isNil "FST_HCSpawn_fnc_isPlayerControlledUnit") exitWith {
        [_unit] call FST_HCSpawn_fnc_isPlayerControlledUnit
    };
    [_unit] call DI_fnc_isPlayerControlledUnitFallback
};
DI_fnc_groupControllable = {
    params ["_group"];
    if (isNull _group || {side _group != east} || {_group getVariable ["DI_operation",""] != (missionNamespace getVariable ["DI_operation","unset"])}) exitWith {false};
    (units _group findIf {
        private _vehicle = vehicle _x;
        ([_x] call DI_fnc_isPlayerControlledUnit) || {_vehicle != _x && {
            side _vehicle == west ||
            {getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "side") == 1} ||
            {(crew _vehicle findIf {[_x] call DI_fnc_isPlayerControlledUnit}) >= 0}
        }}
    }) < 0
};
DI_fnc_capabilityReady = {
    !isNil "FST_HCSpawn_fnc_getSpawnTarget" && {!isNil "FST_HCSpawn_fnc_burnsCommand"} &&
    {!isNil "FST_HC_Templates"} && {!isNil "CBA_fnc_waitAndExecute"}
};
DI_fnc_policy = {
    // Pure function reused by in-engine policy tests. No mutation/spawning.
    params ["_phase","_ready","_waiting","_connected","_recentDeaths","_baseline",["_telemetry",true]];
    private _hold = _phase != "active" || {!_telemetry} || {_ready <= 0};
    private _airHold = _hold || {_waiting > 5};
    createHashMapFromArray [
        ["infantryAllowed",!_hold], ["airAllowed",!_airHold], ["groundAAAllowed",!_airHold],
        ["catastrophicDeaths",_baseline > 0 && {_recentDeaths > floor (2.5 * _baseline)}],
        ["readyBudget",floor ((_ready * DI_globalReadyMultiplier) min DI_maxActiveInfantry)],
        ["connected",_connected]
    ]
};
DI_fnc_authorized = {
    params ["_unit","_origin"];
    if (_origin == 2 && {isServer}) exitWith {true};
    if (isNull _unit || {!isPlayer _unit} || {owner _unit != _origin}) exitWith {false};
    (admin _origin > 0) || {(allCurators findIf {getAssignedCuratorUnit _x == _unit}) >= 0}
};
DI_fnc_humans = {
    private _curators = allCurators apply {getAssignedCuratorUnit _x};
    allPlayers select {
        !(_x isKindOf "HeadlessClient_F") && {!(_x in _curators)} &&
        {getPlayerUID _x != ""} && {!(_x getVariable ["ace_spectator_isSet",false])} &&
        {!(_x getVariable ["DI_exclude",false])}
    }
};
DI_fnc_unconscious = {
    params ["_unit"];
    (_unit getVariable ["ACE_isUnconscious",false]) || {lifeState _unit == "INCAPACITATED"}
};
DI_fnc_nearBase = {
    params ["_position",["_radius",350]];
    private _base = missionNamespace getVariable ["DI_base",[601.80798,289.271,180.86099]];
    _position distance2D _base < _radius
};
DI_fnc_safeSpawn = {
    // No spawning here. Check terrain/obstacles and every human observer.
    params ["_center","_players"];
    private _answer = [];
    // First try the original defensive ring, then a wider approach ring. Once
    // players reach the objective the inner ring alone is always too close.
    // The outer search retains every visibility, base and distance guard.
    for "_attempt" from 1 to 36 do {
        if (count _answer > 0) exitWith {};
        private _p = _center getPos [if (_attempt <= 18) then {60 + random 160} else {450 + random 350},random 360];
        _p set [2,0];
        if (surfaceIsWater _p || {[_p,DI_baseProtectionRadius] call DI_fnc_nearBase}) then {continue};
        if ((_players findIf {alive _x && {_x distance2D _p < DI_minSpawnPlayerDistance + 10}}) >= 0) then {continue};
        private _flat = _p isFlatEmpty [8,-1,0.25,8,0,false,objNull];
        if (count _flat < 2) then {continue};
        _p = ASLToATL _flat;
        private _eye = ATLToASL (_p vectorAdd [0,0,1.5]);
        // GEOM blocks buildings; terrain blocks ridges. Airborne observers included.
        private _visible = _players findIf {
            alive _x && {_x distance2D _p < 2000} &&
            {!terrainIntersectASL [eyePos _x,_eye]} &&
            {count (lineIntersectsSurfaces [eyePos _x,_eye,_x,vehicle _x,true,1,"VIEW","NONE"]) == 0}
        };
        if (_visible >= 0) then {continue};
        _answer = _p;

    };
    _answer
};


// Pure admission helpers are shared by production and the engine regression harness.
DI_fnc_departureEligible = {
    params ["_connected","_assemblyPeak","_departed","_stableSeconds"];
    _connected >= DI_autoStepMinimum && {_assemblyPeak >= DI_autoStepMinimum} &&
    {_stableSeconds >= DI_assemblyPersistence} &&
    {_departed >= (20 min (8 max ceil (_connected * 0.25)))}
};
DI_fnc_positionClear = {
    params ["_pos","_players"];
    if (count _pos != 3 || {surfaceIsWater _pos} || {[_pos,DI_baseProtectionRadius] call DI_fnc_nearBase}) exitWith {false};
    if ((_players findIf {alive _x && {_x distance2D _pos < DI_minSpawnPlayerDistance + 10}}) >= 0) exitWith {false};
    if (count (_pos isFlatEmpty [8,-1,0.25,8,0,false,objNull]) < 2) exitWith {false};
    private _eye = ATLToASL (_pos vectorAdd [0,0,1.5]);
    (_players findIf {
        alive _x && {_x distance2D _pos < 2000} &&
        {!terrainIntersectASL [eyePos _x,_eye]} &&
        {count (lineIntersectsSurfaces [eyePos _x,_eye,_x,vehicle _x,true,1,"VIEW","NONE"]) == 0}
    }) < 0
};
