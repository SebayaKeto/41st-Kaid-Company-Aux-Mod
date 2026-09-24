// A bounded queue of recent human near misses. Native courage still controls
// recovery above the temporary floor; no courage/accuracy edits or target reveal.

if (missionNamespace getVariable ["BURNS_suppressionStarted",false]) exitWith {};
BURNS_suppressionStarted=true;
BURNS_SuppressedUnits=[];
BURNS_SuppressionCursor=0;
BURNS_SuppressionMaxMs=0;
[{
    private _start=diag_tickTime;
    private _enabled=(missionNamespace getVariable ["BURNS_HumanSuppression",true]) && {missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]};
    for "_i" from 1 to (32 min count BURNS_SuppressedUnits) do {
        if (count BURNS_SuppressedUnits==0) exitWith {};
        BURNS_SuppressionCursor=BURNS_SuppressionCursor mod count BURNS_SuppressedUnits;
        private _u=BURNS_SuppressedUnits select BURNS_SuppressionCursor;
        private _pulse=_u getVariable ["BURNS_suppressionPulse",[-10,0]];
        private _age=time-(_pulse select 0);
        if (!_enabled || {[group _u] call FST_HCSpawn_fnc_isProtectedVehicleGroup} || {isNull _u} || {!local _u} || {!alive _u} || {([_u] call FST_HCSpawn_fnc_isPlayerControlledUnit)} || {_age>=4} || {_u getVariable ["BURNS_exempt",false]} || {(group _u) getVariable ["BURNS_exempt",false]} || {!(_u checkAIFeature "SUPPRESSION")}) then {
            BURNS_SuppressedUnits deleteAt BURNS_SuppressionCursor;
        } else {
            _u setSuppression ((getSuppression _u) max ((_pulse select 1)*(1-_age/4)));
            BURNS_SuppressionCursor=BURNS_SuppressionCursor+1;
        };
        if (diag_tickTime-_start>0.0015) exitWith {};
    };
    BURNS_SuppressionMaxMs=BURNS_SuppressionMaxMs max ((diag_tickTime-_start)*1000);
},0.25,[]] call CBA_fnc_addPerFrameHandler;
