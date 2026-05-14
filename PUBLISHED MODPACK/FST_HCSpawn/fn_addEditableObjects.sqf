// FST_HCSpawn_fnc_addEditableObjects
// Server-side. Registers HC-created objects as Zeus editable.
// Accepts object refs or netId strings and retries because freshly-created
// HC-local network objects can resolve on the server a few frames late.
// Optional instant-clone args let the SERVER, not the HC, approve deletion of
// the Zeus original only after replacement objects are resolvable/editable.

if (!isServer) exitWith {};

params [
    ["_objectsOrNetIds", []],
    ["_attempt", 0],
    ["_originalPayload", []],
    ["_sourceOwner", -1],
    ["_expectedCount", 0],
    ["_replacementOwner", -1],
    ["_replacementGroupRef", ""]
];

private _isZeusCloneConfirm = (_sourceOwner > 2) && {count _originalPayload == 3};
private _valid = [];
private _missing = 0;

{
    private _obj = objNull;
    if (_x isEqualType objNull) then {
        _obj = _x;
    } else {
        if (_x isEqualType "") then {
            _obj = objectFromNetId _x;
        };
    };

    if (!isNull _obj) then {
        _valid pushBackUnique _obj;
    } else {
        _missing = _missing + 1;
    };
} forEach _objectsOrNetIds;

if (count _valid > 0) then {
    { _x addCuratorEditableObjects [_valid, true]; } forEach allCurators;
};

// For instant clone/replace, do not let the HC approve deletion by itself.
// Wait until the server has actually resolved and registered every replacement
// object. Treat clone acceptance as all-or-nothing: partial success restores the
// Zeus original and asks the HC to delete the partial replacement group.
if (_isZeusCloneConfirm) then {
    private _expected = _expectedCount max 1;
    if ((count _valid) >= _expected) exitWith {
        private _originalAccepted = [_originalPayload, true] call FST_HCSpawn_fnc_handleZeusOriginalDecision;

        // Only confirmed Zeus clones become tracked HC groups. This avoids briefly
        // tracking a clone that later fails editable registration and gets deleted.
        if (_originalAccepted) then {
            if (_replacementOwner > 2 && {!(_replacementGroupRef isEqualTo "")}) then {
                private _hcIndex = FST_HC_Ids find _replacementOwner;
                if (_hcIndex >= 0) then {
                    [_replacementGroupRef, _hcIndex, true, 0, 90] call FST_HCSpawn_fnc_trackGroup;
                };
            };
        } else {
            // Late success after the server failsafe restored the original: remove
            // the now-unwanted clone instead of tracking a duplicate.
            if (_replacementOwner > 2 && {!(_replacementGroupRef isEqualTo "")}) then {
                ["FST_HC_evt_deleteRejectedClone", [_replacementGroupRef], _replacementOwner] call CBA_fnc_ownerEvent;
            };
        };

        if (FST_HC_DebugLogging) then {
            diag_log format ["[FST_HCSpawn] Zeus clone confirmed after editable registration. valid=%1 expected=%2 attempt=%3 originalAccepted=%4", count _valid, _expected, _attempt, _originalAccepted];
        };
    };

    if (_attempt < 10) exitWith {
        [{
            params ["_objectsOrNetIds", "_attempt", "_originalPayload", "_sourceOwner", "_expectedCount", "_replacementOwner", "_replacementGroupRef"];
            [_objectsOrNetIds, _attempt + 1, _originalPayload, _sourceOwner, _expectedCount, _replacementOwner, _replacementGroupRef] call FST_HCSpawn_fnc_addEditableObjects;
        }, [_objectsOrNetIds, _attempt, _originalPayload, _sourceOwner, _expectedCount, _replacementOwner, _replacementGroupRef], 0.5] call CBA_fnc_waitAndExecute;
    };

    [_originalPayload, false] call FST_HCSpawn_fnc_handleZeusOriginalDecision;

    // If the replacement group exists on the HC but the server could not fully
    // resolve/edit-register it, remove that partial clone so Zeus does not get a
    // duplicate invisible/uncurated group after the original is restored.
    if (_replacementOwner > 2 && {!(_replacementGroupRef isEqualTo "")}) then {
        ["FST_HC_evt_deleteRejectedClone", [_replacementGroupRef], _replacementOwner] call CBA_fnc_ownerEvent;
    };

    diag_log format ["[FST_HCSpawn] Zeus clone editable registration rejected. valid=%1 missing=%2 expected=%3 attempt=%4 replacementOwner=%5 groupRef=%6", count _valid, _missing, _expected, _attempt, _replacementOwner, _replacementGroupRef];
} else {
    if (_missing > 0 && {_attempt < 10}) then {
        [{
            params ["_objectsOrNetIds", "_attempt"];
            [_objectsOrNetIds, _attempt + 1] call FST_HCSpawn_fnc_addEditableObjects;
        }, [_objectsOrNetIds, _attempt], 0.5] call CBA_fnc_waitAndExecute;
    } else {
        if (_missing > 0 && {FST_HC_DebugLogging}) then {
            diag_log format ["[FST_HCSpawn] Editable registration gave up on %1 unresolved object refs after %2 attempts", _missing, _attempt];
        };
    };
};
