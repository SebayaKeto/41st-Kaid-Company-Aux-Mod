// Server admission transaction. No suspension between count, check and reserve.
// Result: [allowed, reason, [reservation ID, mission-time expiry]].
if (canSuspend) exitWith {
    private _result=[];
    isNil {_result=_this call FST_HCSpawn_fnc_heavyCheck};
    _result
};
params ["_classes", "_targetOwner", ["_exclude", []], ["_reserve", true]];
if (!isServer) exitWith {[false,"server admission required",[]]};
private _requested=[0,0];
{private _k=[_x] call FST_HCSpawn_fnc_heavyKind; if (_k>=0) then {_requested set [_k,(_requested select _k)+1]}} forEach _classes;
private _hasHeavy=(_requested select 0)+(_requested select 1)>0;
// Optional global pressure brake. Ordinary AI require no heavy reservation,
// but still check Main and destination health when the operator enables it.
private _gateAll=missionNamespace getVariable ["FST_HC_PauseAllSpawnsLowFPS",false];
if (!_hasHeavy && {!_gateAll}) exitWith {[true,"",[]]};
private _counts=[0,0];
FST_HeavyObjects=(missionNamespace getVariable ["FST_HeavyObjects",[]]) select {!isNull _x && {alive _x}};
{if !(_x in _exclude) then {private _k=[typeOf _x] call FST_HCSpawn_fnc_heavyKind; _counts set [_k,(_counts select _k)+1]}} forEach FST_HeavyObjects;
private _reservations=missionNamespace getVariable ["FST_HeavyReservations",createHashMap];
{
    private _r=_reservations get _x;
    if (time>=(_r select 0)) then {_reservations deleteAt _x} else {
        for "_i" from 0 to 1 do {_counts set [_i,(_counts select _i)+((_r select 1) select _i)]};
    };
} forEach keys _reservations;
private _limits=[missionNamespace getVariable ["FST_HC_GulantharLimit",8],missionNamespace getVariable ["FST_HC_ATRTLimit",12]];
private _reason="";
for "_i" from 0 to 1 do {
    if ((_requested select _i)>0 && {(_counts select _i)+(_requested select _i)>(_limits select _i)}) then {
        _reason=format ["%1 limit (%2 existing/reserved + %3 requested; limit %4)",["Gulanthar","AT-RT"] select _i,_counts select _i,_requested select _i,_limits select _i];
    };
};
private _health=missionNamespace getVariable ["FST_HeavyHealth",createHashMap];
{
    private _sample=_health getOrDefault [str _x,[]];
    if (count _sample<3 || {diag_tickTime-(_sample select 0)>20}) then {_reason=format ["waiting for fresh performance data from owner %1",_x]} else {
        if (_sample select 2) then {_reason=format ["sustained low FPS on owner %1 (%2 FPS)",_x,round (_sample select 1)]};
    };
} forEach ([2,_targetOwner] arrayIntersect [2,_targetOwner]);
if (_reason!="") exitWith {[false,_reason,[]]};
private _ticket=[];
if (_reserve && {_hasHeavy}) then {
    FST_HeavySerial=(missionNamespace getVariable ["FST_HeavySerial",0])+1;
    private _id=format ["%1:%2",clientOwner,FST_HeavySerial];
    private _expiry=time+30;
    _reservations set [_id,[_expiry,_requested,_targetOwner]];
    FST_HeavyReservations=_reservations;
    _ticket=[_id,_expiry];
};
[true,"",_ticket]
