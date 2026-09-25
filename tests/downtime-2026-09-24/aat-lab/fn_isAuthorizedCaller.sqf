// FST_HCSpawn_fnc_isAuthorizedCaller
// Server-side. Validates a CLAIMED client owner ID before the server acts on a
// spawn / hold / cleanup request.
//
// CBA events carry no verified sender, so every request payload includes the
// client's own clientOwner. This checks that the claimed ID currently belongs to
// an assigned curator or a logged-in admin. It blocks accidental or stray-script
// use by non-Zeus clients; it does not defeat a client that deliberately lies
// about its owner ID (that would need remoteExec + remoteExecutedOwner).
//
// Arguments:
//   0: NUMBER - claimed owner ID
//   1: STRING - context label for the rejection log (optional)
// Returns: BOOL

if (!isServer) exitWith { false };

params [["_ownerId", -1, [0]], ["_context", "", [""]]];

if !(missionNamespace getVariable ["FST_HC_EventAuthEnabled", true]) exitWith { true };

// Server-internal callers and registered headless clients are always trusted.
if (_ownerId == 2) exitWith { true };
if (_ownerId in (missionNamespace getVariable ["FST_HC_Ids", []])) exitWith { true };
if (_ownerId < 3) exitWith { false };

if ((admin _ownerId) > 0) exitWith { true };

private _isCurator = (allCurators findIf {
    private _unit = getAssignedCuratorUnit _x;
    !isNull _unit && {(owner _unit) == _ownerId}
}) >= 0;

if (!_isCurator) then {
    // Throttled so a misbehaving client cannot flood the RPT.
    private _last = missionNamespace getVariable ["FST_HC_AuthRejectLastLog", -999];
    if ((time - _last) >= 5) then {
        missionNamespace setVariable ["FST_HC_AuthRejectLastLog", time];
        diag_log format ["[FST_HCSpawn][AUTH] Rejected %1 request from owner %2 (not a curator or admin).", _context, _ownerId];
    };
    "[FST] Request rejected: Zeus or admin only." remoteExec ["systemChat", _ownerId];
};

_isCurator
