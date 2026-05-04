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

// FAST PATH: instant clone/replace. This avoids waiting for setGroupOwner
// to settle and recreates the group directly on an HC. The server now validates
// cap/HC availability before telling this client to delete the original.
if (_zeusMode isEqualTo "instant") exitWith {
    private _side = side _group;
    private _leader = leader _group;
    private _leaderVeh = vehicle _leader;
    private _unitClasses = [];
    private _unitData = [];
    private _vehData = [];
    private _origin = getPosATL _leader;

    if (!isNull _leaderVeh && {_leaderVeh != _leader}) then {
        _vehData = [typeOf _leaderVeh, getPosATL _leaderVeh, getDir _leaderVeh, vectorUp _leaderVeh];
        _origin = getPosATL _leaderVeh;
    } else {
        {
            private _uPos = getPosATL _x;
            private _rel = _uPos vectorDiff _origin;
            private _entry = [typeOf _x, _rel, getDir _x, rank _x, skill _x, unitPos _x];

            // Mandatory: preserve exact Zeus/unit loadout during instant clone.
            _entry pushBack (getUnitLoadout _x);

            _unitClasses pushBack (typeOf _x);
            _unitData pushBack _entry;
        } forEach _units;
    };

    // Route replacement to server, which chooses the least-loaded HC and orders
    // that HC to create the group locally.
    private _originalVehicle = if (count _vehData > 0) then { _leaderVeh } else { objNull };
    private _originalPayload = [_group, _units, _originalVehicle];

    ["FST_HC_evt_spawn", [_side, _unitClasses, _origin, "none", 0, _vehData, _unitData, clientOwner, _originalPayload]] call CBA_fnc_serverEvent;

    missionNamespace setVariable ["FST_HC_ZeusInstantCloneClientCount", (missionNamespace getVariable ["FST_HC_ZeusInstantCloneClientCount", 0]) + 1];
};

// SLOW/CLEAN PATH: transfer the actual Zeus-created group.
["FST_HC_evt_queueZeusGroup", [_group, clientOwner]] call CBA_fnc_serverEvent;
