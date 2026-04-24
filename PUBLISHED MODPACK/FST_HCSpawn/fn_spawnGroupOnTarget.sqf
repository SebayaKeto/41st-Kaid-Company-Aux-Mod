// FST_HCSpawn_fnc_spawnGroupOnTarget
// Server-side. Routes spawn request to least-loaded HC or server.

if (!isServer) exitWith {};

params ["_side", "_unitClasses", "_pos", ["_behavior", "garrison"], ["_radius", -1], ["_vehData", []]];

// AI cap check
if (!([count _unitClasses] call FST_HCSpawn_fnc_canSpawn)) exitWith {
    "[FST] AI cap reached — spawn blocked." remoteExec ["systemChat", -2];
};

if (_radius < 0) then {
    _radius = switch (_behavior) do {
        case "garrison": { FST_HC_GarrisonRadius };
        case "patrol":   { FST_HC_PatrolRadius };
        default          { 100 };
    };
};

private _targetId = [] call FST_HCSpawn_fnc_getSpawnTarget;
private _isOnHC = _targetId != 2;
private _hcIndex = if (_isOnHC) then { FST_HC_Ids find _targetId } else { -1 };

// Pre-increment unit counts so the NEXT call to getSpawnTarget
// sees this HC as loaded. Prevents rapid-fire all going to HC1.
// Periodic recountUnits corrects any drift from actual tracked groups.
if (_hcIndex >= 0 && _hcIndex < count FST_HC_UnitCounts) then {
    FST_HC_UnitCounts set [_hcIndex, (FST_HC_UnitCounts select _hcIndex) + count _unitClasses];
};

[_side, _unitClasses, _pos, _behavior, _radius, _vehData, _isOnHC, _targetId, _hcIndex]
    remoteExecCall ["FST_HCSpawn_fnc_createGroupLocal", _targetId];
