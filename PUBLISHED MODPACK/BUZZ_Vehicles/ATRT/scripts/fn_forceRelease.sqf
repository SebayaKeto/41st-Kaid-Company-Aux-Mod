// =============================================================================
//  BUZZ AT-RT — fn_forceRelease.sqf
//  Hands control from an AT-RT back to the local player's own body, then keeps
//  checking and retrying until the engine confirms control actually moved.
//  Runs on the rider's machine. Used by Ctrl+ESC and the desync watchdog.
//  params: [_atrt, _wake]  (_wake = also clear the rider's unconscious state)
// =============================================================================

params [["_a", objNull], ["_wake", false]];

if (!hasInterface) exitWith {};
if (!canSuspend) exitWith { _this spawn BUZZ_fnc_forceRelease; };

// Release Lock
// One release at a time. Expires after 5 s so an error can't block future ejects.
if (time < (missionNamespace getVariable ["BUZZ_releaseUntil", -1])) exitWith {};
BUZZ_releaseUntil = time + 5;

private _r = player;

// Body Recovery
// Detach the body and, if it was sitting on the walker, drop it behind.
private _wasRiding = !isNull _a && { (attachedTo _r) isEqualTo _a };
if (_wake) then {
    _r setVariable ["ace_unconscious", false, true];
    _r setUnconscious false;
};
if (_wasRiding || _wake) then { [_r, ""] remoteExec ["switchMove", 0]; };
if (!isNull (attachedTo _r)) then { detach _r; };
_r setVelocity [0, 0, 0];
if (_wasRiding && { alive _a }) then { _r setPosATL (_a modelToWorld [0.5, -4.0, 0]); };

// Release Loop
// Stuck = engine still links us to the walker, or the camera is still on it.
// Retries every 0.1 s for 2 s; selectPlayer is the last-resort input rebind.
private _fnStuck = {
    !isNull _a && { ((remoteControlled _a) isEqualTo player) || { cameraOn isEqualTo _a } }
};
for "_i" from 1 to 20 do {
    if (!(call _fnStuck)) exitWith {};
    objNull remoteControl _a;
    if (_i in [5, 12]) then { selectPlayer player; };
    (vehicle player) switchCamera cameraView;
    sleep 0.1;
};
if (cameraOn != vehicle player) then { (vehicle player) switchCamera cameraView; };
if (call _fnStuck) then {
    systemChat "AT-RT: release failed — press Ctrl+ESC again.";
    diag_log format ["BUZZ_fnc_forceRelease: still stuck on %1 (remoteControlled=%2, cameraOn=%3)", _a, remoteControlled _a, cameraOn];
};

// Walker Cleanup
// Clear the rider slot and shield if they still point at us.
if (!isNull _a && { (_a getVariable ["rider", objNull]) isEqualTo _r }) then {
    deleteVehicle (_a getVariable ["shield", objNull]);
    _a setVariable ["rider",  nil, true];
    _a setVariable ["shield", nil, true];
};

// Handler Cleanup
// Remove the jump system and any old per-mount eject handler.
if (!isNull _a) then {
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
};
uiNamespace setVariable ["BUZZ_jumpAiming", false];
uiNamespace setVariable ["BUZZ_jumpAtrt",   objNull];
private _ind = uiNamespace getVariable ["BUZZ_jumpInd", objNull];
if (!isNull _ind) then { deleteVehicle _ind; };
uiNamespace setVariable ["BUZZ_jumpInd", objNull];
inGameUISetEventHandler ["Action", ""];

BUZZ_releaseUntil = -1;
