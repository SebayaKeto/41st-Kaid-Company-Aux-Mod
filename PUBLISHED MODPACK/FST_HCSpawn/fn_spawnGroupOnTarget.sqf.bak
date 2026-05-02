// FST_HCSpawn_fnc_spawnGroupOnTarget
// Server-side. Routes spawn request to least-loaded HC or server.

if (!isServer) exitWith {};

params ["_side", "_unitClasses", "_pos", ["_behavior", "garrison"], ["_radius", -1], ["_vehData", []]];

// AI cap check — inline
private _cap = FST_HC_AICap;
if (_cap > 0) then {
    private _total = 0;
    { _total = _total + _x; } forEach FST_HC_UnitCounts;
    if (_total + count _unitClasses > _cap) exitWith {
        "[FST] AI cap reached — spawn blocked." remoteExec ["systemChat", -2];
    };
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

private _args = [_side, _unitClasses, _pos, _behavior, _radius, _vehData, _isOnHC, _targetId, _hcIndex];

if (_isOnHC) then {
    private _hcId = FST_HC_Ids select _hcIndex;
    ["FST_HC_evt_createGroupLocal", _args, _hcId] call CBA_fnc_ownerEvent;
} else {
    _args call FST_HCSpawn_fnc_createGroupLocal;
};
