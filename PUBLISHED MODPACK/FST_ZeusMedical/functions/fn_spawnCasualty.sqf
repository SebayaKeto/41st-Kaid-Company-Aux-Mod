// FST_zeusMed_fnc_spawnCasualty
// Server (CBA server event "FST_zeusMed_spawn"). Creates a friendly wounded trooper as a rescue objective:
// Plot Armor on, a casualty scenario applied, movement off so it stays where Zeus put it, editable by every curator.
// Arguments: 0: position ASL, 1: scenario index, 2: Zeus owner for feedback <NUMBER>

params ["_posASL", ["_index", 1], ["_zeus", -1]];
if (!isServer) exitWith {};

private _reply = {
    params ["_msg"];
    diag_log text format ["FST_zeusMed: %1 | zeus owner %2", _msg, _zeus];
    if (_zeus > 0) then { ["FST_zeusMed_feedback", [_msg], _zeus] call CBA_fnc_ownerEvent; };
};
if !(missionNamespace getVariable ["FST_zeusMed_enabled", true]) exitWith { ["41st Medical: disabled (FST_zeusMed_enabled)"] call _reply; };

private _class = missionNamespace getVariable ["FST_zeusMed_spawnClass", "FST_Trooper_P2_DC15S"];
if !(isClass (configFile >> "CfgVehicles" >> _class) && {_class isKindOf "CAManBase"}) then {
    [format ["41st Medical: unit class '%1' not found, using B_Soldier_F", _class]] call _reply;
    _class = "B_Soldier_F";
};

private _grp = createGroup [west, true];
private _unit = _grp createUnit [_class, ASLToAGL _posASL, [], 0, "CAN_COLLIDE"];
_unit setPosASL _posASL;
{ _unit disableAI _x } forEach ["MOVE", "PATH"];
_unit setVariable ["FST_zeusMed_casualty", true, true];
{ _x addCuratorEditableObjects [[_unit], false] } forEach allCurators;

// Plot Armor first (AI otherwise die when knocked out on this server's ACE settings), then give ACE a moment to
// initialise the new unit's medical state before wounding it
[_unit, true, -1] call FST_zeusMed_fnc_plotArmorLocal;
[{
    params ["_unit", "_index", "_reply"];
    if (!alive _unit) exitWith { ["41st Medical: spawned trooper died before the scenario"] call _reply; };
    private _label = [_unit, _index] call FST_zeusMed_fnc_scenarios;
    [format ["41st Medical: wounded trooper spawned - %1 (Plot Armor ON)", _label]] call _reply;
}, [_unit, _index, _reply], 2] call CBA_fnc_waitAndExecute;
