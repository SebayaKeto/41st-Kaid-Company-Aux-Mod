/*
 * onLoad of the Radiation Monitor info panel.
 */
params ["_display"];
private _list = (uiNamespace getVariable ["BUZZ_Radiation_monitorDisplays", []]) select {!isNull _x};
_list pushBackUnique _display;
uiNamespace setVariable ["BUZZ_Radiation_monitorDisplays", _list];
[alive player && {!isNull objectParent player || {[player, missionNamespace getVariable ["BUZZ_Radiation_monitorList", []]] call BUZZ_Radiation_fnc_hasItem}}] call BUZZ_Radiation_fnc_updateMonitor;
call BUZZ_Radiation_fnc_updateRadar;
