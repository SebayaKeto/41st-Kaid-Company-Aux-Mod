// FST_HCSpawn_fnc_untrackGroup
// Server-side. Removes a group from tracking.

if (!isServer) exitWith {};

params ["_group"];

FST_HC_GroupMap deleteAt _group;
FST_HC_ZeusHeld deleteAt _group;
