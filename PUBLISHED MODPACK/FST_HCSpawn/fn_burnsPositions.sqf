// Shared, owner-local building-position cache. Returns [ready, positions].
// One queued scan at a time; requests in the same 50m cell share the result.
// Explicit building tasks and occasional human contact-cover requests share it.
params ["_centre", ["_radius",100]];
private _requestedRadius=(_radius max 25) min 250;
_radius = (ceil (((_radius max 25) min 250) / 50)) * 50;
private _cell = [round ((_centre select 0)/50)*50, round ((_centre select 1)/50)*50, 0];
private _key = str [_cell,_radius];
if (isNil "BURNS_PositionCache") then {
    BURNS_PositionCache = createHashMap;
    BURNS_PositionQueue = [];
    BURNS_PositionWorker = false;
    BURNS_PositionScans = 0;
    BURNS_PositionCacheHits = 0;
    BURNS_PositionMaxQueryMs = 0;
    BURNS_PositionWorkMs = 0;
};
private _cached = BURNS_PositionCache getOrDefault [_key,[]];
if (count _cached > 0 && {time < (_cached select 0)}) exitWith {
    if !(_cached select 1) exitWith {[false,[]]};
    BURNS_PositionCacheHits = BURNS_PositionCacheHits + 1;
    [true, (_cached select 2) select {_x distance2D _centre <= _requestedRadius}]
};
if (count BURNS_PositionQueue >= 32) exitWith {[false,[]]};
// Bounded memory; preserve pending requests when evicting old ready entries.
if (count BURNS_PositionCache >= 64) then {
    private _keys = keys BURNS_PositionCache;
    private _oldest = _keys select 0;
    private _expiry = 1e12;
    {private _v=BURNS_PositionCache get _x; if ((_v select 1) && {(_v select 0)<_expiry}) then {_oldest=_x;_expiry=_v select 0}} forEach _keys;
    if (_expiry < 1e12) then {BURNS_PositionCache deleteAt _oldest};
};
BURNS_PositionCache set [_key,[time+120,false,[]]];
BURNS_PositionQueue pushBack [_key,_cell,_radius+36];
if (!BURNS_PositionWorker) then {
    BURNS_PositionWorker = true;
    [] spawn {
        while {count BURNS_PositionQueue > 0} do {
            (BURNS_PositionQueue deleteAt 0) params ["_key","_centre","_radius"];
            private _start=diag_tickTime;
            private _buildings = (nearestObjects [_centre,["House","Building"],_radius,true]) select [0,256];
            private _markers = (nearestObjects [_centre,["3as_GarrisonPoint","CBA_BuildingPos"],_radius,true]) select [0,64];
            BURNS_PositionMaxQueryMs = BURNS_PositionMaxQueryMs max ((diag_tickTime-_start)*1000);
            BURNS_PositionScans = BURNS_PositionScans + 1;
            private _positions=[];
            {private _p=getPosATL _x; if ([_p] call FST_HCSpawn_fnc_isSafeGarrisonPos) then {_positions pushBackUnique _p}} forEach _markers;
            BURNS_PositionWorkMs=BURNS_PositionWorkMs+(diag_tickTime-_start)*1000;
            private _slice=diag_tickTime;
            {
                if (count _positions>=192) exitWith {};
                private _workStart=diag_tickTime;
                for "_i" from 0 to 31 do {
                    private _p=_x buildingPos _i;
                    if (_p isEqualTo [0,0,0] || {count _positions>=192}) exitWith {};
                    if ([_p] call FST_HCSpawn_fnc_isSafeGarrisonPos) then {_positions pushBackUnique _p};
                };
                BURNS_PositionWorkMs=BURNS_PositionWorkMs+(diag_tickTime-_workStart)*1000;
                // Yield by work budget instead of sleeping once for every prop.
                if (diag_tickTime-_slice>0.001) then {sleep 0.01;_slice=diag_tickTime};
            } forEach _buildings;
            BURNS_PositionCache set [_key,[time+120,true,_positions]];
            sleep 0.25;
        };
        BURNS_PositionWorker=false;
    };
};
[false,[]]
