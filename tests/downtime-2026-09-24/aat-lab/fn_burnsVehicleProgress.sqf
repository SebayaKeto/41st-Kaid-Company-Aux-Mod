// Bounded recovery for explicit armored movement. Never teleports or enables
// externally disabled PATH/MOVE. Stationary firing inside the goal is legitimate.
params ["_group","_destination","_mode"];
private _v=vehicle leader _group;
if (!(_v isKindOf "Tank") || {!local _v} || {!canMove _v} || {!(_mode in ["assault","rush","hunt"])}) exitWith {_destination};
private _driver=driver _v;
if (isNull _driver || {!local _driver} || {!alive _driver} || {!(_driver checkAIFeature "PATH")} || {!(_driver checkAIFeature "MOVE")}) exitWith {_destination};
// N99 can retain a completed driver's move across group ownership even after
// the new waypoint is accepted. Re-arm on each new owner OR task revision;
// the old task can tick on the new owner just before a replacement order arrives.
private _revision=[_group,["BURNS_movementRevision",0]] call FST_HCSpawn_fnc_burnsStateGet;
private _driveKey=[clientOwner,_revision];
if (_v isKindOf "FST_N99" && {!((_v getVariable ["BURNS_n99DriveKey",[]]) isEqualTo _driveKey)}) then {
    _v setVariable ["BURNS_n99DriveKey",_driveKey];
    _driver doMove _destination;
    diag_log format ["[BURNS_N99_OWNER_MOVE] vehicle=%1 owner=%2 destination=%3",netId _v,clientOwner,_destination];
};
if (_v distance2D _destination<25) exitWith {_v setVariable ["BURNS_driveProgress",nil];_v setVariable ["BURNS_driveDetour",nil];_destination};
private _detour=_v getVariable ["BURNS_driveDetour",[]];
if (count _detour==4 && {(_detour select 1) distance2D _destination<25} && {time<(_detour select 2)} && {_revision==(_detour select 3)} && {_v distance2D (_detour select 0)>6}) exitWith {_detour select 0};
_v setVariable ["BURNS_driveDetour",nil];
private _state=_v getVariable ["BURNS_driveProgress",[getPosATL _v,time,+_destination,0]];
_state params ["_position","_since","_goal","_attempt"];
if (_v distance2D _position>4 || {_goal distance2D _destination>25}) then {_state=[getPosATL _v,time,+_destination,0]};
if (time-(_state select 1)>12 && {abs speed _v<2} && {count (_v getVariable ["BURNS_armorPulse",[]])==0}) then {
    _attempt=(_state select 3)+1;
    if (_attempt<=2) then {
        // One rare, bounded free-position query; try opposite sides on retries.
        // The engine still finds the path and drives there normally.
        private _approach=(getPosATL _v) getPos [20,(_v getDir _destination)+([-55,55] select (_attempt mod 2))];
        private _free=_approach findEmptyPosition [0,6,typeOf _v];
        if (count _free==3 && {!surfaceIsWater _free} && {(surfaceNormal _free select 2)>0.9}) then {
            _v setVariable ["BURNS_driveDetour",[_free,+_destination,time+20,_revision]];
            // A waypoint alone can leave a stopped combat driver latched in
            // place. Give this bounded recovery leg directly to the local driver.
            _driver doMove _free;
        };
        diag_log format ["[BURNS_VEHICLE_RECOVERY] vehicle=%1 class=%2 owner=%3 attempt=%4 position=%5 destination=%6",netId _v,typeOf _v,clientOwner,_attempt,getPosATL _v,_destination];
    } else {
        if (_attempt==3) then {
            diag_log format ["[BURNS_VEHICLE_BLOCKED] vehicle=%1 class=%2 destination=%3",netId _v,typeOf _v,_destination];
            private _caller=_group getVariable ["BURNS_taskCaller",-1];
            if (_caller>2) then {format ["[BURNS] %1 cannot reach its destination. Check terrain or choose a new approach.",getText(configOf _v >> "displayName")] remoteExec ["systemChat",_caller]};
        };
    };
    _state=[getPosATL _v,time,+_destination,_attempt min 4];
};
_v setVariable ["BURNS_driveProgress",_state];
private _next=_v getVariable ["BURNS_driveDetour",[]];
if (count _next==4) then {_next select 0} else {_destination}
