// FST_HCSpawn_fnc_getVehicleHC
// Server-side. Resolves the dedicated vehicle HC (V28).
//
// The vehicle HC is chosen by registration slot (CBA setting
// FST_HC_VehicleHCSlot, 1-based: the HC that registered as "HC<n>"). Vehicle
// groups are created on it directly so crewed vehicles never change owner
// mid-op, and infantry balancing leaves it alone when
// FST_HC_VehicleHCExclusive is set and at least one other HC exists.
//
// Returns: ARRAY [ownerId, hcIndex], or [-1, -1] when disabled / not connected.

if (!isServer) exitWith { [-1, -1] };
if !(missionNamespace getVariable ["FST_HC_VehicleHCEnabled", true]) exitWith { [-1, -1] };

private _slot = round (missionNamespace getVariable ["FST_HC_VehicleHCSlot", 4]);
private _idx = _slot - 1;
if (_idx < 0 || {_idx >= count FST_HC_Ids} || {_idx >= count FST_HC_Array}) exitWith { [-1, -1] };

private _id = FST_HC_Ids select _idx;
private _obj = FST_HC_Array select _idx;
if (_id <= 2 || {isNull _obj}) exitWith { [-1, -1] };

[_id, _idx]
