// Central guard for EVERY formation entry point, including persistent callbacks.
params ["_group",["_allowStation",false]];
if (isNull _group || {!local _group}) exitWith {false};
if (!(missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]) || {!(missionNamespace getVariable ["FST_HC_DroidStanceEnabled",true])} || {_group getVariable ["BURNS_exempt",false]}) exitWith {false};
if (side _group in [civilian,sideLogic] || {[_group] call FST_HCSpawn_fnc_isProtectedVehicleGroup}) exitWith {false};
private _held=_group getVariable ["FST_HC_heldBy",-1];
if (_held!=-1 && {(_group getVariable ["BURNS_manualHeldOwner",-2])!=_held}) exitWith {false};
private _units=units _group select {alive _x};
count _units>0 && {(_units findIf {!local _x || {([_x] call FST_HCSpawn_fnc_isPlayerControlledUnit)} || {vehicle _x!=_x} || {!simulationEnabled _x} || {lifeState _x=="INCAPACITATED"} || {_x getVariable ["BURNS_exempt",false]} || {!(_x checkAIFeature "PATH") && {!(_allowStation && {_x getVariable ["FST_HC_ownsPath",false] || {_x getVariable ["BURNS_ownsPath",false]}})}} || {([_x] call FST_HCSpawn_fnc_burnsRole)!="b1"}})<0}
