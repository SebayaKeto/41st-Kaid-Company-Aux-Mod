// Scheduled owner-local admission for one creation step. All managed builders
// share the same frame/spacing gate; no per-request future-slot backlog.
// Vehicle crew creation remains an engine batch, and other mods are unaffected.
params [["_deadline",-1]];
if (!canSuspend) exitWith {false};
if (_deadline<0) then {_deadline=time+30};
private _admitted=false;
waitUntil {
    private _expired=time>=_deadline;
    if (!_expired) then {
        // Atomic claim even when several scheduled builders wake together.
        isNil {
            if (diag_frameNo!=(missionNamespace getVariable ["FST_HC_SpawnLastFrame",-1]) && {
                diag_tickTime>=(missionNamespace getVariable ["FST_HC_SpawnNextTime",-1])
            }) then {
                FST_HC_SpawnLastFrame=diag_frameNo;
                FST_HC_SpawnNextTime=diag_tickTime+((missionNamespace getVariable ["FST_HC_SpawnSpacing",0.05]) max 0.01 min 1);
                _admitted=true;
            };
        };
    };
    if (!_admitted && {!_expired}) then {sleep 0.01};
    _admitted || {_expired}
};
_admitted
