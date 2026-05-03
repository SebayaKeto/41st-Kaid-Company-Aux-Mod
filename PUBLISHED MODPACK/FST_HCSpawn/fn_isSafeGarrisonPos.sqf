// FST_HCSpawn_fnc_isSafeGarrisonPos
// Returns true if a garrison position is safe enough to spawn infantry.
// Primary purpose: reject building/garrison positions over open water unless
// there is actual object geometry/flooring under the position.
//
// Arguments:
//   0: POSITION ATL-ish position from buildingPos/getPosATL
//
// Notes:
// - surfaceIsWater catches sea/pond XY positions.
// - lineIntersectsSurfaces checks for real geometry below the point. BIKI notes
//   it does not return the sea surface, which is exactly what we want here.

params [["_pos", [], [[]]]];

if (count _pos < 3) exitWith { false };

private _x = _pos select 0;
private _y = _pos select 1;
private _z = _pos select 2;

if !(_x isEqualType 0) exitWith { false };
if !(_y isEqualType 0) exitWith { false };
if !(_z isEqualType 0) exitWith { false };

// Clearly bad/placeholder positions.
if (_pos isEqualTo [0,0,0]) exitWith { false };
if (_z < -2) exitWith { false };

// Normal land positions are accepted. Over-water positions need a support check.
if !(surfaceIsWater [_x, _y]) exitWith { true };

// Water below this XY. Accept only if there is solid object geometry close under it.
// This allows real piers/platforms/buildings over water, but rejects open water/floating air.
private _topATL = [_x, _y, _z + 2.0];
private _bottomATL = [_x, _y, _z - 8.0];
private _hits = lineIntersectsSurfaces [
    ATLToASL _topATL,
    ATLToASL _bottomATL,
    objNull,
    objNull,
    true,
    1,
    "GEOM",
    "NONE"
];

(count _hits) > 0
