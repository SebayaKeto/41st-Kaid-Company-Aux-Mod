// FST_HCSpawn_fnc_trackGroup
// Server-side. Registers a group in the hashmap and updates unit counts.
//
// Arguments:
//   0: GROUP
//   1: NUMBER — HC index in FST_HC_Array

if (!isServer) exitWith {};

params ["_group", "_hcIndex"];

if (isNull _group) exitWith {};

// Already tracked?
if (_group in FST_HC_GroupMap) exitWith {};

private _unitCount = count units _group;

FST_HC_GroupMap set [_group, [_hcIndex, _unitCount]];

// Set HC index on group for debug draw (global broadcast so clients can read it)
_group setVariable ["FST_HC_onHC", _hcIndex, true];

// Update bookkeeping counts
if (_hcIndex >= 0 && _hcIndex < count FST_HC_UnitCounts) then {
    FST_HC_UnitCounts set [_hcIndex, (FST_HC_UnitCounts select _hcIndex) + _unitCount];
};
