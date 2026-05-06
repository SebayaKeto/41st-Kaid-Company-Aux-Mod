// FST_HCSpawn_fnc_recountUnits
// Server-side. Recounts unit totals from tracked groups and corrects stale HC indexes.
// Efficiency pass: routine recount iterates FST_HC_TrackedGroups instead of allGroups.

if (!isServer) exitWith {};
if (count FST_HC_Array == 0) exitWith {};

if (isNil "FST_HC_TrackedGroups") then { FST_HC_TrackedGroups = []; };

private _counts = [];
_counts resize (count FST_HC_Array);
{ _counts set [_forEachIndex, 0]; } forEach _counts;

private _tracked = 0;
private _kept = [];

{
    private _grp = _x;
    if (isNull _grp || {count units _grp == 0}) then {
        if (!isNull _grp) then {
            _grp setVariable ["FST_HC_tracked", nil];
            _grp setVariable ["FST_HC_onHC", nil];
        };
        continue;
    };

    private _data = _grp getVariable ["FST_HC_tracked", []];
    if (count _data == 0) then { continue };

    private _ownerID = groupOwner _grp;
    private _hcIndex = FST_HC_Ids find _ownerID;

    if (_hcIndex < 0) then {
        // No longer actually on one of our HCs; clear stale tracking so catch-all can requeue later.
        _grp setVariable ["FST_HC_tracked", nil];
        _grp setVariable ["FST_HC_onHC", nil];
        continue;
    };

    private _unitCount = count units _grp;
    _grp setVariable ["FST_HC_tracked", [_hcIndex, _unitCount]];
    _grp setVariable ["FST_HC_onHC", _hcIndex];

    _counts set [_hcIndex, (_counts select _hcIndex) + _unitCount];
    _tracked = _tracked + 1;
    _kept pushBackUnique _grp;
} forEach +FST_HC_TrackedGroups;

FST_HC_TrackedGroups = _kept;
FST_HC_UnitCounts = _counts;
FST_HC_TrackedCount = _tracked;
