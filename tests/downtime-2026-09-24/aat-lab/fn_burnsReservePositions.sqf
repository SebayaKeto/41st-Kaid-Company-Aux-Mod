// Server-only allocation prevents separate HCs putting squads in the same slots.
// Runs on explicit Zeus orders, not in the combat loop.
params ["_group","_positions","_count"];
if (!isServer) exitWith {[]};
if (isNil "BURNS_PositionBookings") then {BURNS_PositionBookings=createHashMap};
{
    private _booking=BURNS_PositionBookings get _x;
    _booking params ["_g","_until"];
    if (isNull _g || {_g==_group} || {count units _g==0} || {time>_until && {!(((([_g,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet)) param [0,""]) in ["garrison","camp","defend"])}}) then {BURNS_PositionBookings deleteAt _x};
} forEach keys BURNS_PositionBookings;
private _result=[];
private _keyFor={str (_this apply {round (_x*10)})};
// Include holds established through the public owner-local task API.
{
    if (_x==_group) then {continue};
    private _g=_x;
    {
        _x params ["_unit","_pos"];
        if (alive _unit) then {BURNS_PositionBookings set [_pos call _keyFor,[_g,time+30]]};
    } forEach (_g getVariable ["BURNS_stationSlots",[]]);
} forEach allGroups;
{
    if (count _result>=_count || {count BURNS_PositionBookings>=8192}) exitWith {};
    private _key=_x call _keyFor;
    if !(_key in BURNS_PositionBookings) then {
        BURNS_PositionBookings set [_key,[_group,time+30]];
        _result pushBack _x;
    };
} forEach _positions;
_result
