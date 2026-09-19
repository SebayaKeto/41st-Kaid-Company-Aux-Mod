// Runs on the rider's machine when "Load into LAAT/i" is triggered.
// Handles Buck Off and HUD locally; animation and packing are server-side
// (fn_laatiLoadAnim) so all clients see the AT-RT walk into the LAAT/i.
// _this: [_atrt, _caller, _actionId]
params ["_atrt", "_caller"];

private _rider = _atrt getVariable ["rider", objNull];
if (isNull _rider) exitWith {};
if (_atrt getVariable ["BUZZ_packing", false]) exitWith {};

private _nearby = nearestObjects [_atrt, ["FST_laati_mk2"], 10];
if (count _nearby == 0) exitWith { hint "No LAAT/i within range."; };
private _laati = _nearby select 0;

private _skipAnim = _laati getVariable ["BUZZ_animating", false];

// Capture stats while supply box is still attached.
private _hp       = _atrt getVariable ["BUZZ_hp",       1.0];
private _cell     = _atrt getVariable ["BUZZ_powerCell",  300];
private _box      = _atrt getVariable ["supplyBox",    objNull];
private _reserves = 0;
if (!isNull _box) then {
    private _cargo = getMagazineCargo _box;
    private _idx   = (_cargo select 0) find "BUZZ_ATRT_T15ReserveMag";
    if (_idx >= 0) then { _reserves = (_cargo select 1) select _idx; };
};

// ── Buck Off immediately ──────────────────────────────────────────────────────
private _dn   = _atrt getVariable ["BUZZ_jumpDnEH",   -1];
private _up   = _atrt getVariable ["BUZZ_jumpUpEH",   -1];
private _draw = _atrt getVariable ["BUZZ_jumpDrawEH", -1];
private _esc  = _atrt getVariable ["BUZZ_ejectEH",    -1];
if (_dn   >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyDown", _dn]; };
if (_up   >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyUp",   _up]; };
if (_draw >= 0) then { removeMissionEventHandler ["Draw3D", _draw]; };
if (_esc  >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyDown", _esc]; };
_atrt setVariable ["BUZZ_jumpDnEH",   nil];
_atrt setVariable ["BUZZ_jumpUpEH",   nil];
_atrt setVariable ["BUZZ_jumpDrawEH", nil];
_atrt setVariable ["BUZZ_ejectEH",    nil];
uiNamespace setVariable ["BUZZ_jumpAiming", false];
uiNamespace setVariable ["BUZZ_jumpAtrt",   objNull];
private _ind = uiNamespace getVariable ["BUZZ_jumpInd", objNull];
if (!isNull _ind) then { deleteVehicle _ind; };
uiNamespace setVariable ["BUZZ_jumpInd", objNull];

// Kill the AT-RT's momentum before detaching. If the player was actively
// walking when Load was triggered, the rider inherits the AT-RT's residual
// velocity at the instant of detach (attachTo carries parent motion into the
// child on release) and gets flung clear — after which they're too far/ragdolled
// for the moveInTurret below to seat them, so it silently fails and they end up
// neither on the AT-RT nor in the LAAT/i. Stopping first and giving physics a
// beat to settle makes the eject deterministic no matter what the AT-RT was
// doing when the action fired.
_atrt setVelocity [0, 0, 0];
doStop _atrt;
sleep 0.15;

[_rider, ""] remoteExec ["switchMove", 0];
objNull remoteControl driver _atrt;
_rider remoteControl _rider;
detach _rider;

// setVelocity alone doesn't stop a unit that's already in PhysX ragdoll (a fall/
// knockdown reaction) — ragdoll motion is driven by the physics engine directly
// and overrides scripted velocity, so the rider keeps tumbling/sliding regardless.
// It also means moveInTurret below can silently fail to seat them, since a unit
// mid-ragdoll isn't in a state the engine will move into a vehicle. Freezing
// simulation for the handoff hard-stops that: the rider is pinned exactly where
// detached instead of sliding away, then simulation resumes once they're seated
// (or after the seat attempt regardless, so they're never left frozen).
_rider enableSimulationGlobal false;
_rider setVelocity [0, 0, 0];
_rider setPosATL (getPosATL _atrt);
if (cameraOn != vehicle _rider) then { (vehicle _rider) switchCamera cameraView; };
deleteVehicle (_atrt getVariable ["shield", objNull]);
_atrt setVariable ["rider",  nil, true];
_atrt setVariable ["shield", nil, true];
_atrt setVariable ["BUZZ_crosshairOn", false];
inGameUISetEventHandler ["Action", ""];

// ── Find best available LAAT/i seat (ramp gunner → bench → other) ─────────────
private _cfgTurrets = configFile >> "CfgVehicles" >> (typeOf _laati) >> "Turrets";
private _rampPaths  = [];
private _benchPaths = [];
private _otherPaths = [];
{
    private _cls = configName (_cfgTurrets select (_x select 0));
    if (_cls in ["CargoTurret_01", "CargoTurret_02"]) then {
        _rampPaths pushBack _x;
    } else {
        if (_cls in ["CargoTurret_03", "CargoTurret_04", "CargoTurret_05", "CargoTurret_06"]) then {
            _benchPaths pushBack _x;
        } else { _otherPaths pushBack _x; };
    };
} forEach (allTurrets [_laati, true]);

private _available = (_rampPaths  select { isNull (_laati turretUnit _x) })
                   + (_benchPaths select { isNull (_laati turretUnit _x) })
                   + (_otherPaths select { isNull (_laati turretUnit _x) });

// ── Start HUD on this client; animation and pack are handed to the server ─────
_atrt setVariable ["BUZZ_packing", true, true];
[_atrt, _rider, 5, "LOADING INTO LAAT/i"] execVM "\BUZZ_Vehicles\ATRT\scripts\pack_hud.sqf";

// Seat rider immediately — 0.1 s lets the engine process the detach.
[_rider, _laati, _available] spawn {
    params ["_rider", "_laati", "_available"];
    sleep 0.1;
    if (count _available > 0) then {
        _rider moveInTurret [_laati, _available select 0];
    };
    // Always re-enable, even if no seat was free — otherwise a failed seat
    // attempt leaves the rider permanently frozen on the ground.
    _rider enableSimulationGlobal true;
};

// Server runs the animation (visible to all clients) then packs.
[_atrt, _laati, _hp, _cell, _reserves, _skipAnim] remoteExecCall ["BUZZ_fnc_laatiLoadAnim", 2];
