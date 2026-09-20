// FST_HCSpawn_fnc_isVehicleTransferSafe
// Server-side (V28). Decides whether a group that is (partly) mounted can
// change owner without the crew and the vehicle ending up on different
// machines for a few frames. That split is what broke multi-crew coordination
// whenever a moving vehicle was handed to an HC.
//
// A vehicle group is safe to move only when, for every vehicle its members
// occupy:
//   - the vehicle is (nearly) stationary,
//   - an aircraft is on the ground,
//   - every crew member of the vehicle belongs to this group (no split crews),
//   - no player is aboard.
// Groups with nobody mounted are always safe.
//
// Arguments:
//   0: GROUP
// Returns: ARRAY [BOOL safe, STRING reason]

params ["_group"];

if (isNull _group) exitWith { [false, "null group"] };

private _units = units _group;
private _vehicles = [];
{
    private _veh = vehicle _x;
    if (_veh != _x) then { _vehicles pushBackUnique _veh; };
} forEach _units;

if (count _vehicles == 0) exitWith { [true, "on foot"] };

private _maxSpeed = missionNamespace getVariable ["FST_HC_VehicleTransferMaxSpeed", 1.5];
private _reason = "";
{
    private _veh = _x;
    if (!alive _veh) then { continue };
    private _speed = vectorMagnitude velocity _veh;
    if (_speed > _maxSpeed) exitWith { _reason = format ["%1 moving (%2 m/s)", typeOf _veh, round _speed]; };
    if ((_veh isKindOf "Air") && {!isTouchingGround _veh}) exitWith { _reason = format ["%1 airborne", typeOf _veh]; };
    private _crew = crew _veh;
    if ((_crew findIf { isPlayer _x }) >= 0) exitWith { _reason = format ["player aboard %1", typeOf _veh]; };
    if ((_crew findIf { !(_x in _units) }) >= 0) exitWith { _reason = format ["%1 crewed by another group", typeOf _veh]; };
} forEach _vehicles;

if (_reason != "") exitWith { [false, _reason] };
[true, format ["%1 vehicle(s) stationary", count _vehicles]]
