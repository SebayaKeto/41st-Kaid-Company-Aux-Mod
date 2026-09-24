// Owner-local: report perceived contact and consume a short-lived server plan.
// No target reveal, AI feature changes, group merging, or direct drive commands.
params ["_g","_fallback",["_contact",objNull],["_knownPos",[]]];
private _token=_g getVariable ["BURNS_sectionToken",""];
if (_token=="" || {!(missionNamespace getVariable ["BURNS_ArmorSectionsEnabled",true])}) exitWith {_fallback};
if (!isNull _contact && {count _knownPos>=2}) then {
    _g setVariable ["BURNS_sectionContact",[+_knownPos,time],true];
};
private _plan=_g getVariable ["BURNS_sectionPlan",[]];
if (count _plan!=4 || {(_plan select 0)!=_token} || {time>(_plan select 3)} || {!([_g] call FST_HCSpawn_fnc_burnsEngagementAllowed)}) exitWith {_fallback};
private _driver=driver vehicle leader _g;
if (!isNull _driver && {local _driver} && {_driver checkAIFeature "PATH"} && {_driver checkAIFeature "MOVE"}) then {[_driver,_token,_plan select 1] call FST_HCSpawn_fnc_burnsArmorSectionDriver};
_g setVariable ["BURNS_lastTactic","aat-section-"+toLower (_plan select 2),true];
+(_plan select 1)
