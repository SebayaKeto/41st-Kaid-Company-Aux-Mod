// BURNS B1-only stance policy. B2/BX are exclusively WebKnight-controlled.
if (hasInterface && {!isServer}) exitWith {0};
if !(missionNamespace getVariable ["FST_HC_DroidStanceEnabled", true]) exitWith {0};
private _fixed = 0;
{
    if (!local _x || {!alive _x} || {([_x] call FST_HCSpawn_fnc_isPlayerControlledUnit)} || {vehicle _x != _x} || {lifeState _x == "INCAPACITATED"}) then {continue};
    if ((group _x) getVariable ["BURNS_exempt", false]) then {continue};
    if (_x getVariable ["BURNS_exempt",false]) then {continue};
    if (([_x] call FST_HCSpawn_fnc_burnsRole) != "b1") then {continue};
    if !(_x getVariable ["BURNS_stanceHook", false]) then {
        _x setVariable ["BURNS_stanceHook", true];
        _x addEventHandler ["AnimChanged", {
            params ["_unit"];
            if (!local _unit || {!alive _unit} || {([_unit] call FST_HCSpawn_fnc_isPlayerControlledUnit)} || {vehicle _unit != _unit} || {lifeState _unit == "INCAPACITATED"}) exitWith {};
            if (!(missionNamespace getVariable ["FST_HC_DroidStanceEnabled", true]) || {(group _unit) getVariable ["BURNS_exempt", false]}) exitWith {};
            if (_unit getVariable ["BURNS_exempt",false]) exitWith {};
            if (toUpper unitPos _unit != "UP" || {stance _unit != "STAND"}) then {
                _unit setUnitPos "UP";
                _unit setUnitPosWeak "UP";
            };
        }];
    };
    if (toUpper unitPos _x != "UP" || {stance _x != "STAND"}) then {
        _x setUnitPos "UP";
        _x setUnitPosWeak "UP";
        _fixed = _fixed + 1;
    };
} forEach allUnits;
_fixed
