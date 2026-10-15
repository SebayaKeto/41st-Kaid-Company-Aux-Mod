// BURNS stance policy. B1: upright (FST_HC_DroidStanceEnabled). B2 (V54): never prone, from any source (FST_HC_B2NoProne).
// BX (commandos) stay WebKnight/BURNS-task controlled. [true] call = B2-only pass (clients: Zeus-local AI).
params [["_b2Only", false]];
if (hasInterface && {!isServer} && {!_b2Only}) exitWith {0};
private _b1On = !_b2Only && {missionNamespace getVariable ["FST_HC_DroidStanceEnabled", true]};
private _b2On = (missionNamespace getVariable ["FST_HC_B2NoProne", true]) && {!isNil "BURNS_fnc_isB2"};
if (!_b1On && {!_b2On}) exitWith {0};
private _fixed = 0;
private _b2s = [];
{
    if (!local _x || {!alive _x}) then {continue};
    if (_b2On && {[_x] call BURNS_fnc_isB2}) then {
        if (isPlayer _x || {([_x] call FST_HCSpawn_fnc_isPlayerControlledUnit)}) then {continue};
        _b2s pushBack _x;
        if !(_x getVariable ["BURNS_b2StanceHook", false]) then {
            _x setVariable ["BURNS_b2StanceHook", true];
            _x addEventHandler ["AnimChanged", {
                params ["_unit"];
                // Fires on every animation change: leave at once when the stance order is already right.
                if (!local _unit || {toUpper unitPos _unit == "UP"}) exitWith {};
                if (missionNamespace getVariable ["FST_HC_B2NoProne", true]) then {[_unit] call BURNS_fnc_b2Up};
            }];
        };
        if ([_x] call BURNS_fnc_b2Up) then {_fixed = _fixed + 1};
        if (stance _x == "PRONE" && {toUpper unitPos _x == "UP"} && {vehicle _x == _x} && {lifeState _x != "INCAPACITATED"}) then {
            _x playActionNow "PlayerStand";
            _fixed = _fixed + 1;
            diag_log format ["[BURNS_B2STANCE] prone with unitPos UP -> stand: %1 %2 anim=%3", _x, typeOf _x, animationState _x];
        };
        continue;
    };
    if (!_b1On) then {continue};
    if (!local _x || {!alive _x} || {([_x] call FST_HCSpawn_fnc_isPlayerControlledUnit)} || {vehicle _x != _x} || {lifeState _x == "INCAPACITATED"}) then {continue};
    if ((group _x) getVariable ["BURNS_exempt", false]) then {continue};
    if (_x getVariable ["BURNS_exempt",false]) then {continue};
    if (([_x] call FST_HCSpawn_fnc_burnsRole) != "b1") then {continue};
    if !(_x getVariable ["BURNS_stanceHook", false]) then {
        _x setVariable ["BURNS_stanceHook", true];
        _x addEventHandler ["AnimChanged", {
            params ["_unit"];
            // Fires on every animation change: leave at once when the stance is already right.
            if (!local _unit || {toUpper unitPos _unit == "UP" && {stance _unit == "STAND"}}) exitWith {};
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
if (_b2On) then {missionNamespace setVariable ["BURNS_b2Local", _b2s]};
_fixed
