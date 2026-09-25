params ["_vehicle","_token"];
if (isNull _vehicle || {!local _vehicle}) exitWith {};
private _pulse=_vehicle getVariable ["BURNS_armorPulse",[]];
if (count _pulse==0 || {(_pulse select 0)!=_token}) exitWith {};
// Release the turn latch even when the unit just became player controlled.
// No forward/reverse command is issued by cleanup.
_vehicle sendSimpleCommand "STOPTURNING";
_vehicle setVariable ["BURNS_armorPulse",nil,true];
_pulse params ["","_group","_driver","_wp","_wpPos","_revision"];
if (!([_group] call FST_HCSpawn_fnc_burnsEngagementAllowed) || {!local _driver} || {driver _vehicle!=_driver}) exitWith {};
if (currentWaypoint _group!=_wp || {waypointPosition [_group,_wp] distance2D _wpPos>1} || {
    ([_group,["BURNS_movementRevision",0]] call FST_HCSpawn_fnc_burnsStateGet)!=_revision
}) exitWith {};
if (_wp<count waypoints _group) then {_group setCurrentWaypoint [_group,_wp]};
// Return a stopped subordinate driver to its commander after the short turn.
if (_driver!=leader _group) then {_driver doFollow leader _group};
_group setVariable ["FST_HC_taskNext",time];
