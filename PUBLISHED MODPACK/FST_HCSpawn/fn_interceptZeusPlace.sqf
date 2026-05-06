// FST_HCSpawn_fnc_interceptZeusPlace
// Client-side. CuratorGroupPlaced EH.
// Default path is the instant clone/replace method because it preserves the
// near-immediate Zeus workflow the unit relies on. The safer setGroupOwner path
// is still available through CBA settings for testing or low-pressure missions.

params ["_curator", "_group"];

private _zeusMode = missionNamespace getVariable ["FST_HC_ZeusMode", "instant"];
if (_zeusMode isEqualTo "off") exitWith {};
if (isNull _group) exitWith {};

// No HCs connected — leave units where Zeus placed them.
private _hcIds = missionNamespace getVariable ["FST_HC_Ids", []];
if (count _hcIds == 0) exitWith {};

if (count units _group == 0) exitWith {};
if (isPlayer leader _group) exitWith {};
private _units = units _group;

// Respect blacklist before instant clone. The instant path deletes the original
// client-side, so we must not bypass blacklist settings here.
if ([_group] call FST_HCSpawn_fnc_isBlacklisted) exitWith {};

// Prevent duplicate CuratorGroupPlaced handlers or rapid retries from handling
// the same Zeus placement twice.
if (_group getVariable ["FST_HC_pendingTransfer", false]) exitWith {};
if (_group getVariable ["FST_HC_interceptQueued", false]) exitWith {};
if (count (_group getVariable ["FST_HC_tracked", []]) > 0) exitWith {};
_group setVariable ["FST_HC_interceptQueued", true, true];

// Vehicle groups are not safe to instant-clone: the old clone path only captured
// the leader vehicle and would lose multi-vehicle groups, custom cargo, crew state,
// and some modded vehicle setup. Preserve them with setGroupOwner instead.
private _hasVehicle = (_units findIf { vehicle _x != _x }) >= 0;
if ((_zeusMode isEqualTo "instant") && {_hasVehicle}) exitWith {
    ["FST_HC_evt_queueZeusGroup", [_group, clientOwner]] call CBA_fnc_serverEvent;
};

// FAST PATH: instant clone/replace. We delay the snapshot slightly so
// modded units have time to finish post-create weapon/loadout assignment. This
// fixes the rapid-spawn race where getUnitLoadout could capture an empty weapon
// array and the HC clone would be forced unarmed.
if (_zeusMode isEqualTo "instant") exitWith {
    private _snapshotDelay = missionNamespace getVariable ["FST_HC_ZeusLoadoutSnapshotDelay", 0.75];

    [{
        params ["_group"];

        if (isNull _group) exitWith {};
        if (count units _group == 0) exitWith {
            _group setVariable ["FST_HC_interceptQueued", nil, true];
        };
        if (isPlayer leader _group) exitWith {
            _group setVariable ["FST_HC_interceptQueued", nil, true];
        };

        // If HCs disappeared while we waited, leave the original Zeus group alive.
        private _hcIds = missionNamespace getVariable ["FST_HC_Ids", []];
        if (count _hcIds == 0) exitWith {
            _group setVariable ["FST_HC_interceptQueued", nil, true];
        };

        private _units = units _group;
        private _hasVehicle = (_units findIf { vehicle _x != _x }) >= 0;
        if (_hasVehicle) exitWith {
            ["FST_HC_evt_queueZeusGroup", [_group, clientOwner]] call CBA_fnc_serverEvent;
        };

        private _side = side _group;
        private _leader = leader _group;
        private _unitClasses = [];
        private _unitData = [];
        private _origin = getPosATL _leader;

        {
            private _uPos = getPosATL _x;
            private _rel = _uPos vectorDiff _origin;
            private _entry = [typeOf _x, _rel, getDir _x, rank _x, skill _x, unitPos _x];

            // Preserve exact Zeus/unit loadout, but only after the unit has had
            // a short time to settle. The HC side also validates this snapshot
            // before applying it, so a still-bad empty loadout cannot strip weapons.
            _entry pushBack (getUnitLoadout _x);

            _unitClasses pushBack (typeOf _x);
            _unitData pushBack _entry;
        } forEach _units;

        private _originalPayload = [_group, _units, objNull];

        ["FST_HC_evt_spawn", [_side, _unitClasses, _origin, "none", 0, [], _unitData, clientOwner, _originalPayload]] call CBA_fnc_serverEvent;

        missionNamespace setVariable ["FST_HC_ZeusInstantCloneClientCount", (missionNamespace getVariable ["FST_HC_ZeusInstantCloneClientCount", 0]) + 1];
    }, [_group], _snapshotDelay] call CBA_fnc_waitAndExecute;
};

// SLOW/CLEAN PATH: transfer the actual Zeus-created group.
["FST_HC_evt_queueZeusGroup", [_group, clientOwner]] call CBA_fnc_serverEvent;
