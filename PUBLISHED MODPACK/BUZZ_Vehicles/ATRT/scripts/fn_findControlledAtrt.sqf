// =============================================================================
//  BUZZ AT-RT — fn_findControlledAtrt.sqf
//  Returns the AT-RT the local player is controlling or riding, or objNull.
//  Checks the engine's own remote-control link first, so it still finds the
//  walker after our rider/jump variables have already been cleared.
// =============================================================================

private _found = objNull;

// Engine Link
// Any AT-RT (including dead ones) the engine says this player is controlling.
{
    if ((remoteControlled _x) isEqualTo player) exitWith { _found = _x; };
} forEach (entities [["BUZZ_ATRT"], [], false, false]);

// Fallbacks
// The walker the body is attached to, then the one the jump system last tracked.
if (isNull _found) then {
    private _att = attachedTo player;
    if (!isNull _att && { _att isKindOf "BUZZ_ATRT" }) then { _found = _att; };
};
if (isNull _found) then { _found = uiNamespace getVariable ["BUZZ_jumpAtrt", objNull]; };

_found
