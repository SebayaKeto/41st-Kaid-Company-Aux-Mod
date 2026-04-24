// FST_HCSpawn_fnc_recountUnits
// Server-side. Recounts unit totals from tracked groups only.
// O(tracked groups) — NOT O(allUnits * HCs) like ZHC.
// Also cleans up dead/empty groups from the hashmap.

if (!isServer) exitWith {};
if (count FST_HC_Array == 0) exitWith {};

// Zero out counts
private _counts = [];
_counts resize (count FST_HC_Array);
{ _counts set [_forEachIndex, 0]; } forEach _counts;

// Recount from tracked groups
private _deadGroups = [];
{
    private _grp = _x;
    private _data = _y;
    _data params ["_hcIndex", "_oldCount"];

    if (isNull _grp || {count units _grp == 0}) then {
        _deadGroups pushBack _grp;
    } else {
        if (_hcIndex >= 0 && _hcIndex < count _counts) then {
            _counts set [_hcIndex, (_counts select _hcIndex) + count units _grp];
        };
    };
} forEach FST_HC_GroupMap;

// Clean up dead groups
{
    FST_HC_GroupMap deleteAt _x;
} forEach _deadGroups;

FST_HC_UnitCounts = _counts;
