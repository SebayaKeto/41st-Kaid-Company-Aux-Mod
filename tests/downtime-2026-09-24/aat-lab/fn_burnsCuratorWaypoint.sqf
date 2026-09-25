// CuratorWaypointPlaced: a normal Zeus waypoint supersedes BURNS intent.
// The server assigns a revision before forwarding to the current AI owner.
params ["_curator","_group","_index"];
if (isNull _group || {_index<0} || {_index>=count waypoints _group}) exitWith {false};
private _wp=[_group,_index];
if (waypointDescription _wp in ["FST HC combat","BURNS patrol"]) exitWith {false};
["BURNS_request",["stop",[_group],[],waypointPosition _wp,150,[],clientOwner]] call CBA_fnc_serverEvent;
true
