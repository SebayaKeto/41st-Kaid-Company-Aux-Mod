// Keep classification identical for admission, telemetry and direct Zeus spawns.
params ["_class"];
private _cache=missionNamespace getVariable ["FST_heavyClassCache",createHashMap];
private _kind=_cache getOrDefault [_class,-2];
if (_kind!=-2) exitWith {_kind};
_kind=if (_class isKindOf "JMSEF_animals_varren_o") then {0} else {if (_class isKindOf "FST_ATRT") then {1} else {-1}};
_cache set [_class,_kind];
FST_heavyClassCache=_cache;
_kind
