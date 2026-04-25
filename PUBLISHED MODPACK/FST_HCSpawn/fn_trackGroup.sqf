// FST_HCSpawn_fnc_trackGroup
// Server-side. Marks a group as tracked and updates unit counts.

if (!isServer) exitWith {};

params ["_group", "_hcIndex"];

if (isNull _group) exitWith {};

// Already tracked?
private _existing = _group getVariable ["FST_HC_tracked", []];
if (count _existing > 0) exitWith {};

private _unitCount = count units _group;

// Mark as tracked (server-local variable)
_group setVariable ["FST_HC_tracked", [_hcIndex, _unitCount]];

// Set HC index for debug draw
_group setVariable ["FST_HC_onHC", _hcIndex];

// Don't increment FST_HC_UnitCounts here — spawnGroupOnTarget and
// requestFillGarrison pre-increment for load balancing. recountUnits
// corrects to actual values every 30s.

FST_HC_TrackedCount = FST_HC_TrackedCount + 1;
