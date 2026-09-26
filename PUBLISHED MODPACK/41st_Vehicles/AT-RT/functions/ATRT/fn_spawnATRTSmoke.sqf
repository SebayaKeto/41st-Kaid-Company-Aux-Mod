// The owner requests visuals once; clients keep at most six active wrecks.
params ["_atrt", ["_visualOnly", false]];
if (isNull _atrt) exitWith {};
if (!_visualOnly) exitWith {
    if (!local _atrt || {_atrt getVariable ["FST_ATRT_smokeSent", false]}) exitWith {};
    _atrt setVariable ["FST_ATRT_smokeSent", true, true];
    private _owners = [];
    {if (!(_x isKindOf "HeadlessClient_F") && {_x distance _atrt < 500}) then {_owners pushBackUnique owner _x}} forEach allPlayers;
    {["FST_atrtSmoke", [_atrt], _x] call CBA_fnc_ownerEvent} forEach _owners;
};
if (!hasInterface || {player distance _atrt > 550} || {_atrt getVariable ["FST_ATRT_visualStarted", false]}) exitWith {};
FST_ATRT_localEffects = (missionNamespace getVariable ["FST_ATRT_localEffects", []]) select {!isNull _x};
if (count FST_ATRT_localEffects > 20) exitWith {};
_atrt setVariable ["FST_ATRT_visualStarted", true];
private _effects = [];
{
    private _smoke = "#particlesource" createVehicleLocal getPosATL _atrt;
    _smoke setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal",16,7,48,1],"","Billboard",1,4,[0,0,0],[0,0,0.7],0,1,0.8,0.1,[0.2,1,2],[[0.1,0.1,0.1,0.4],[0.15,0.15,0.15,0]],[0.5],0,0,"","",_atrt];
    _smoke setDropInterval 0.2;
    _smoke attachTo [_atrt,[0,0,0],_x];
    private _sparks = "#particlesource" createVehicleLocal getPosATL _atrt;
    _sparks setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal",16,13,2,0],"","Billboard",1,0.3,[0,0,0],[0,0,1],0,1,0.8,0.1,[0.03,0],[[1,0.4,0.05,1],[1,0.2,0,0]],[1],0,0,"","",_atrt];
    _sparks setParticleRandom [0.1,[0,0,0],[1,1,1],0,0,[0,0,0,0],0,0];
    _sparks setDropInterval 0.1;
    _sparks attachTo [_atrt,[0,0,0],_x];
    _effects append [_smoke,_sparks];
} forEach ["aiming_axis", "head_axis"];
_atrt setVariable ["FST_ATRT_effects", _effects];
FST_ATRT_localEffects append _effects;
// PFH cleanup works even if the wreck is deleted and scheduled scripts lag.
[{params ["_args", "_handle"]; _args params ["_atrt", "_effects", "_deadline"];
    if (isNull _atrt || {diag_tickTime >= _deadline}) then {
        {deleteVehicle _x} forEach _effects;
        if (!isNull _atrt) then {_atrt setVariable ["FST_ATRT_effects", []]};
        [_handle] call CBA_fnc_removePerFrameHandler;
    };
}, 1, [_atrt, _effects, diag_tickTime + 30]] call CBA_fnc_addPerFrameHandler;
