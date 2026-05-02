// FST_HCSpawn_fnc_transferGroup
// Server-side. Transfers a single group to the least-loaded HC.
// Handles garrison detection, loadout preservation, and tracking.
//
// Arguments:
//   0: GROUP

if (!isServer) exitWith {};

params ["_group"];

if (isNull _group || {count units _group == 0}) exitWith {};
if (count FST_HC_Array == 0) exitWith {};

private _leader = leader _group;
private _units = units _group;
private _vehicle = vehicle _leader;

// --- Detect garrison state ---
private _isGarrisoned = !(_leader checkAIFeature "PATH");

// --- Save loadouts ---
if (FST_HC_PreserveLoadouts) then {
    { _x setVariable ["FST_HC_savedLoadout", getUnitLoadout _x]; } forEach _units;
};

// --- Lock vehicle during transfer ---
if (_vehicle != _leader) then { _vehicle lock true; };

// --- Pick target HC ---
private _targetId = [] call FST_HCSpawn_fnc_getSpawnTarget;
private _hcIndex = FST_HC_Ids find _targetId;

// --- Transfer ---
_group setGroupOwner _targetId;

// --- Enable dynamic simulation (only if not garrisoned) ---
if (!_isGarrisoned) then {
    _group enableDynamicSimulation true;
};

// --- Track ---
[_group, _hcIndex] call FST_HCSpawn_fnc_trackGroup;

// --- Reapply garrison on HC ---
if (_isGarrisoned) then {
    private _hcId = FST_HC_Ids select _hcIndex;
    ["FST_HC_evt_reapplyGarrison", [_group], _hcId] call CBA_fnc_ownerEvent;
};

// --- Restore loadouts ---
if (FST_HC_PreserveLoadouts) then {
    [{
        params ["_units"];
        {
            private _loadout = _x getVariable ["FST_HC_savedLoadout", []];
            if (count _loadout > 0 && {uniform _x == ""}) then {
                _x setUnitLoadout _loadout;
            };
        } forEach _units;
    }, [_units], 1] call CBA_fnc_waitAndExecute;
};

// --- Unlock vehicle ---
if (_vehicle != _leader) then {
    [{ params ["_v"]; _v lock false; }, [_vehicle], 0.5] call CBA_fnc_waitAndExecute;
};
