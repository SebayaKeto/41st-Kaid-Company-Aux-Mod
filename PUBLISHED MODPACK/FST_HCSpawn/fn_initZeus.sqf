// FST_HCSpawn_fnc_initZeus
// Client-side. Called when a player becomes a curator mid-mission.
// Re-hooks the CuratorGroupPlaced EH if not already present.

private _curator = getAssignedCuratorLogic player;
if (isNull _curator) exitWith {};

// Check if already hooked
if (_curator getVariable ["FST_HC_hooked", false]) exitWith {};

_curator addEventHandler ["CuratorGroupPlaced", {
    params ["_curator", "_group"];
    [_curator, _group] call FST_HCSpawn_fnc_interceptZeusPlace;
}];

_curator setVariable ["FST_HC_hooked", true];
diag_log "[FST_HCSpawn] Zeus curator hooked for intercept";
