// Called via a local `call` from fn_laatiDeployAction.sqf once it has locally
// detected its own newly-deployed AT-RT (object presence + detach — see the
// comment there) — this always runs on the deploying player's own machine, so
// `player` below is always the right person; no cross-machine targeting or
// broadcast handoff involved.
// Ejects the player from the LAAT/i and mounts them on the new AT-RT.
// Replicates the full Saddle Up behaviour including HUD, jump system, mount poll,
// and auto-eject.
// params: [_atrt]
params ["_atrt"];

if (isNull _atrt) exitWith {};

// Wait for server init to finish (supply box broadcast confirms readiness)
private _timeout = time + 20;
waitUntil { !isNull (_atrt getVariable ["supplyBox", objNull]) || time > _timeout || !alive _atrt };
if (!alive _atrt) exitWith {};

// Bail if another player has already claimed the seat
if (!isNil { _atrt getVariable "rider" }) exitWith {};

// Eject from LAAT/i before attaching to AT-RT
// moveOut is not instant — attaching in the same frame can be overridden when the
// exit completes a frame later, dropping the player at the LAAT/i instead of on the
// AT-RT. Wait for the exit to actually finish before attaching.
if (vehicle player != player) then {
    moveOut player;
    private _exitTimeout = time + 2;
    waitUntil { vehicle player == player || time > _exitTimeout };
};
if (!alive _atrt) exitWith {};

private _rider = player;

_atrt setVariable ["rider", _rider, true];
[_rider, "driver_Quadbike"] remoteExec ["switchMove", 0];
_rider attachTo [_atrt, [0, 0, 0], "seat"];

private _shield = "3AS_ATRT_Collision" createVehicle (position _atrt);
[_shield, false] remoteExec ["allowDamage", 0];
_shield attachTo [_atrt, [0.0, 0.3, -2.3], "seat"];
_atrt setVariable ["shield", _shield, true];

objNull remoteControl driver _rider;
player remoteControl _atrt;

if (cameraOn != vehicle _atrt) then { (vehicle _atrt) switchCamera cameraView; };
_atrt enableStamina false;
_atrt forceWalk false;
_atrt setVariable ["ace_unconscious", false, true];

// Mount poll — mirrors Saddle Up
[_atrt] spawn {
    params ["_a"];
    while { !isNull (_a getVariable ["rider", objNull]) && alive _a } do {
        sleep 0.25;
        _a forceWalk false;
        _a enableStamina false;
        _a setUnitPos "UP";
        _a allowDamage false;
        _a setUnconscious false;
        if (behaviour _a != "CARELESS") then { _a setBehaviour "CARELESS"; };
        if (_a getVariable ["ace_unconscious", false]) then {
            _a setVariable ["ace_unconscious", false, true];
            [_a, ""] remoteExec ["switchMove", 0];
        };
    };
};

inGameUISetEventHandler ["Action", "if ((_this select 3) isEqualTo ""BackFromUAV"") then {true};"];

if (hasInterface && player isEqualTo _rider) then {
    [_atrt, _rider] execVM "\BUZZ_Vehicles\ATRT\scripts\hud.sqf";

    uiNamespace setVariable ["BUZZ_jumpAiming", false];
    uiNamespace setVariable ["BUZZ_jumpAtrt",   _atrt];

    private _jumpInd = "VR_3DSelector_01_default_F" createVehicleLocal [0, 0, -1000];
    _jumpInd allowDamage false;
    _jumpInd enableSimulation false;
    uiNamespace setVariable ["BUZZ_jumpInd", _jumpInd];

    private _jumpDnEH = (findDisplay 46) displayAddEventHandler ["KeyDown", {
        params ["_d", "_k"];
        if (_k != 47) exitWith { false };
        private _a = uiNamespace getVariable ["BUZZ_jumpAtrt", objNull];
        if (isNull _a) exitWith { false };
        if (time >= (_a getVariable ["BUZZ_jumpCooldown", 0])) then {
            uiNamespace setVariable ["BUZZ_jumpAiming", true];
        };
        true
    }];

    private _jumpUpEH = (findDisplay 46) displayAddEventHandler ["KeyUp", {
        params ["_d", "_k"];
        if (_k != 47) exitWith { false };
        if (!(uiNamespace getVariable ["BUZZ_jumpAiming", false])) exitWith { false };
        uiNamespace setVariable ["BUZZ_jumpAiming", false];
        private _ind = uiNamespace getVariable ["BUZZ_jumpInd", objNull];
        if (!isNull _ind) then { _ind setPosASL [0, 0, -1000]; };
        private _a = uiNamespace getVariable ["BUZZ_jumpAtrt", objNull];
        if (isNull _a) exitWith { false };
        if (time < (_a getVariable ["BUZZ_jumpCooldown", 0])) exitWith { false };

        private _camPos = positionCameraToWorld [0, 0, 0];
        private _camFwd = positionCameraToWorld [0, 0, 1];
        private _dir    = _camFwd vectorDiff _camPos;

        private _pitch = asin (_dir select 2);
        if (_pitch < 15) then {
            private _hMag = sqrt ((_dir select 0)^2 + (_dir select 1)^2);
            if (_hMag > 0.001) then {
                private _sc = cos 15 / _hMag;
                _dir = [(_dir select 0) * _sc, (_dir select 1) * _sc, sin 15];
            } else {
                _dir = [0, 0, 1];
            };
        };

        private _vel = [(_dir select 0) * 28, (_dir select 1) * 28, (_dir select 2) * 18];
        _a setVelocity _vel;
        [_a, _vel] remoteExec ["setVelocity", 2];
        _a setVariable ["BUZZ_jumpCooldown", time + 15, true];
        false
    }];

    private _jumpDrawEH = addMissionEventHandler ["Draw3D", {
        if (!(uiNamespace getVariable ["BUZZ_jumpAiming", false])) exitWith {};
        private _a = uiNamespace getVariable ["BUZZ_jumpAtrt", objNull];
        if (isNull _a) exitWith {};

        private _camPos = positionCameraToWorld [0, 0, 0];
        private _camFwd = positionCameraToWorld [0, 0, 1];
        private _dir    = _camFwd vectorDiff _camPos;

        private _pitch = asin (_dir select 2);
        if (_pitch < 15) then {
            private _hMag = sqrt ((_dir select 0)^2 + (_dir select 1)^2);
            if (_hMag > 0.001) then {
                private _sc = cos 15 / _hMag;
                _dir = [(_dir select 0) * _sc, (_dir select 1) * _sc, sin 15];
            } else {
                _dir = [0, 0, 1];
            };
        };

        private _ind    = uiNamespace getVariable ["BUZZ_jumpInd", objNull];
        private _simPos = getPosASL _a;
        private _simVel = [(_dir select 0) * 28, (_dir select 1) * 28, (_dir select 2) * 18];
        private _dt     = 0.12;
        private _prev   = _simPos;

        for "_i" from 1 to 80 do {
            _simPos = _simPos vectorAdd (_simVel vectorMultiply _dt);
            _simVel = _simVel vectorAdd [0, 0, -9.81 * _dt];
            if ((_simPos select 2) <= getTerrainHeight [_simPos select 0, _simPos select 1]) exitWith {
                if (!isNull _ind) then { _ind setPosASL _simPos; };
            };
            drawLine3D [ASLToAGL _prev, ASLToAGL _simPos, [0.65, 0.95, 1.00, 0.45]];
            drawIcon3D [
                "\A3\ui_f\data\map\markers\military\circle_CA.paa",
                [0.35, 0.85, 1.00, 0.92],
                ASLToAGL _simPos,
                0.5, 0.5, 0, "", 0, 0, "PuristaMedium"
            ];
            _prev = _simPos;
        };
    }];

    _atrt setVariable ["BUZZ_jumpDnEH",   _jumpDnEH];
    _atrt setVariable ["BUZZ_jumpUpEH",   _jumpUpEH];
    _atrt setVariable ["BUZZ_jumpDrawEH", _jumpDrawEH];

    // ── Force eject (ESC) ──────────────────────────────────────────────────────
    // Unconditional escape hatch — see the matching block in init.sqf's Saddle
    // Up action for the full rationale. Mirrored here since deploy-mounting
    // goes through this function instead of Saddle Up.
    private _ejectEH = (findDisplay 46) displayAddEventHandler ["KeyDown", {
        params ["_d", "_k"];
        if (_k != 1) exitWith { false };
        private _a = uiNamespace getVariable ["BUZZ_jumpAtrt", objNull];
        if (isNull _a) exitWith { false };
        private _r = _a getVariable ["rider", objNull];
        if (isNull _r || { !local _r }) exitWith { false };

        [_r, ""] remoteExec ["switchMove", 0];
        _r setVariable ["ace_unconscious", false, true];
        _r setUnconscious false;
        _r enableSimulationGlobal false;
        detach _r;
        _r setVelocity [0, 0, 0];
        if (alive _a) then { _r setPosATL (_a modelToWorld [0.5, -4.0, 0]); };
        objNull remoteControl driver _a;
        _r remoteControl _r;
        _r enableSimulationGlobal true;
        if (cameraOn != vehicle _r) then { (vehicle _r) switchCamera cameraView; };

        deleteVehicle (_a getVariable ["shield", objNull]);
        _a setVariable ["rider",  nil, true];
        _a setVariable ["shield", nil, true];

        private _dn   = _a getVariable ["BUZZ_jumpDnEH",   -1];
        private _up   = _a getVariable ["BUZZ_jumpUpEH",   -1];
        private _draw = _a getVariable ["BUZZ_jumpDrawEH", -1];
        private _esc  = _a getVariable ["BUZZ_ejectEH",    -1];
        if (_dn   >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyDown", _dn]; };
        if (_up   >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyUp",   _up]; };
        if (_draw >= 0) then { removeMissionEventHandler ["Draw3D", _draw]; };
        if (_esc  >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyDown", _esc]; };
        _a setVariable ["BUZZ_jumpDnEH",   nil];
        _a setVariable ["BUZZ_jumpUpEH",   nil];
        _a setVariable ["BUZZ_jumpDrawEH", nil];
        _a setVariable ["BUZZ_ejectEH",    nil];
        uiNamespace setVariable ["BUZZ_jumpAiming", false];
        uiNamespace setVariable ["BUZZ_jumpAtrt",   objNull];
        private _ind = uiNamespace getVariable ["BUZZ_jumpInd", objNull];
        if (!isNull _ind) then { deleteVehicle _ind; };
        uiNamespace setVariable ["BUZZ_jumpInd", objNull];
        inGameUISetEventHandler ["Action", ""];

        true
    }];
    _atrt setVariable ["BUZZ_ejectEH", _ejectEH];
};

// Auto-eject when rider dies or is incapacitated — mirrors Saddle Up
[_atrt, _rider] spawn {
    params ["_atrt", "_rider"];
    waitUntil {
        sleep 0.25;
        !alive _rider ||
        lifeState _rider == "INCAPACITATED" ||
        _rider getVariable ["ace_unconscious", false] ||
        !alive _atrt
    };
    if (isNull (_atrt getVariable ["rider", objNull])) exitWith {};
    if (!alive _atrt) then {
        private _dt = time + 1.0;
        waitUntil { isNull (_atrt getVariable ["rider", objNull]) || time > _dt };
        if (isNull (_atrt getVariable ["rider", objNull])) exitWith {};
    };

    [_rider, ""] remoteExec ["switchMove", 0];
    detach _rider;
    if (alive _atrt && alive _rider) then { _rider setPos (_atrt modelToWorld [0, -4.0, 0]); };
    objNull remoteControl driver _atrt;
    _rider remoteControl _rider;
    if (cameraOn != vehicle _rider) then { (vehicle _rider) switchCamera cameraView; };

    deleteVehicle (_atrt getVariable ["shield", objNull]);
    _atrt setVariable ["rider",  nil, true];
    _atrt setVariable ["shield", nil, true];
    if (hasInterface) then {
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
    };
    inGameUISetEventHandler ["Action", ""];
};
