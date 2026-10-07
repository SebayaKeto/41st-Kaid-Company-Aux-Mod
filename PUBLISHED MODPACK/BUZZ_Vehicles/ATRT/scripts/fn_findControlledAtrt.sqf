// =============================================================================
//  BUZZ AT-RT — fn_findControlledAtrt.sqf
// =============================================================================

private _found = objNull;

// Engine Link
{
    if ((remoteControlled _x) isEqualTo player) exitWith { _found = _x; };
} forEach (entities [["BUZZ_ATRT"], [], false, false]);

// Fallbacks
if (isNull _found) then {
    private _att = attachedTo player;
    if (!isNull _att && { _att isKindOf "BUZZ_ATRT" }) then { _found = _att; };
};
if (isNull _found) then { _found = uiNamespace getVariable ["BUZZ_jumpAtrt", objNull]; };

_found
