// =============================================================================
//  BUZZ AT-RT — light.sqf
//  Rifle-style spotlight that follows the cannon's aim (i.e. the cursor).
//  Called once per AT-RT on every client with an interface (see init.sqf).
//
//  The light is a local #lightreflector — each client draws its own copy, so
//  nothing is networked except the on/off flag BUZZ_lightOn (set by the
//  "Light On/Off" action and by Saddle Up at night).  Position and direction
//  are refreshed every frame from the cannon's weaponDirection, which the
//  engine syncs to all clients, so other players see the beam sweep too.
//
//  Tuning: LIGHT_INTENSITY / attenuation / cone below control how bright and
//  how wide the beam is.
// =============================================================================

params ["_atrt"];

if (!hasInterface) exitWith {};

private _lamp = "#lightreflector" createVehicleLocal [0, 0, 0];
_lamp setLightColor   [1.0, 0.95, 0.85];
_lamp setLightAmbient [1.0, 0.95, 0.85];
_lamp setLightUseFlare false;
_lamp setLightDayLight false;
_lamp setLightAttenuation [0.5, 0, 0, 0.0004, 0, 300];
_lamp setLightConePars [55, 12, 1];
_lamp setLightIntensity 0;

addMissionEventHandler ["EachFrame", {
    _thisArgs params ["_atrt", "_lamp"];

    if (isNull _atrt || !alive _atrt) exitWith {
        deleteVehicle _lamp;
        removeMissionEventHandler ["EachFrame", _thisEventHandler];
    };

    private _on = (_atrt getVariable ["BUZZ_lightOn", false])
        && { !isNull (_atrt getVariable ["rider", objNull]) }
        && { !(_atrt getVariable ["BUZZ_dying", false]) };

    if (!_on) exitWith { _lamp setLightIntensity 0; };

    private _dir = _atrt weaponDirection (currentWeapon _atrt);
    if (_dir isEqualTo [0, 0, 0]) then { _dir = eyeDirection _atrt; };

    // Start the beam slightly ahead of the eye so the walker's own model
    // doesn't sit inside the light cone.
    private _pos = (eyePos _atrt) vectorAdd (_dir vectorMultiply 0.6);

    private _right = _dir vectorCrossProduct [0, 0, 1];
    if (vectorMagnitude _right < 0.001) then { _right = [1, 0, 0]; };
    private _up = _right vectorCrossProduct _dir;

    _lamp setPosASL _pos;
    _lamp setVectorDirAndUp [_dir, _up];
    _lamp setLightIntensity 25000;
}, [_atrt, _lamp]];
