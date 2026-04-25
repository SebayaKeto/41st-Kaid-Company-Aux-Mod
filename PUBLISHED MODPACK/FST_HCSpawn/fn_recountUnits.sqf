// FST_HCSpawn_fnc_recountUnits
// Server-side. Recounts unit totals from tracked groups.
// Also cleans up dead/empty groups.

if (!isServer) exitWith {};
if (count FST_HC_Array == 0) exitWith {};

private _counts = [];
_counts resize (count FST_HC_Array);
{ _counts set [_forEachIndex, 0]; } forEach _counts;

private _tracked = 0;

{
    private _data = _x getVariable ["FST_HC_tracked", []];
    if (count _data > 0) then {
        if (isNull _x || {count units _x == 0}) then {
            // Dead group — clear tracking
            _x setVariable ["FST_HC_tracked", nil];
            _x setVariable ["FST_HC_onHC", nil];
        } else {
            private _hcIndex = _data select 0;
            if (_hcIndex >= 0 && _hcIndex < count _counts) then {
                _counts set [_hcIndex, (_counts select _hcIndex) + count units _x];
            };
            _tracked = _tracked + 1;
        };
    };
} forEach allGroups;

FST_HC_UnitCounts = _counts;
FST_HC_TrackedCount = _tracked;
