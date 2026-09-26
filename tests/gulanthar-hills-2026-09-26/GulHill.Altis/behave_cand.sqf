GH_behave_cand = {
    params ["_unit", "_token"];
    if (!local _unit) exitWith {};
    _unit setVariable ["dev_behave_running", true];
    if !(_unit getVariable ["dev_health_applied", false]) then {
        _unit setVariable ["dev_health_applied", true, true];
        _unit setDamage (1 - varren_health);
    };
    private _mode = -1;
    private _nextSearch = 0;
    private _nextMove = 0;
    private _nextBody = 0;
    private _nextAttack = 0;
    private _nextPsych = 0;
    private _nextSound = 0;
    private _enemies = [];
    private _body = objNull;
    private _bodyUntil = 0;
    private _ignoredBodies = [];
    private _origin = getPosATL _unit;
    sleep random 1;
    while {!isNull _unit && {alive _unit} && {local _unit} && {(_unit getVariable ["FST_varrenToken", -1]) == _token}} do {
        // Dormant rather than destroyed: toggling the kill switch off resumes.
        if (missionNamespace getVariable ["dev_cba_killswitch", false]) then {
            if (_mode != -1) then {doStop _unit; _unit setVariable ["mode", -1]; _mode = -1};
            sleep 1;
            continue;
        };
        if (time >= _nextSearch) then {
            _enemies = [_unit, varren_distance_hunt, varren_distance_max, 5] call dev_fnc_getEnemies;
            _nextSearch = time + 2;
            _unit setVariable ["FST_varrenSearches", (_unit getVariable ["FST_varrenSearches", 0]) + 1];
        };
        _enemies = _enemies select {!isNull _x && {alive _x}};
        private _target = _enemies param [0, objNull];
        private _chargeDistance = varren_distance_agro max (missionNamespace getVariable ["FST_GulantharChargeDistance", 600]);
        private _newMode = if (isNull _target) then {0} else {if (_unit distance _target <= _chargeDistance) then {2} else {1}};
        if (_newMode != _mode) then {
            _mode = _newMode;
            _unit setVariable ["mode", _mode];
            _nextMove = 0;
            (group _unit) setSpeedMode (["LIMITED", "NORMAL", "FULL"] select _mode);
            _unit forceSpeed (if (_mode == 2) then {15} else {-1});
            if (time >= _nextSound) then {
                [_unit, ["JMSEF_animals_varren_spawn", "JMSEF_animals_varren_stalk", "JMSEF_animals_varren_attack"] select _mode] call FST_Gulanthar_fnc_sound;
                _nextSound = time + 6;
            };
        };
        if (_mode == 0 && {varren_distance_roam > 0}) then {
            _ignoredBodies = _ignoredBodies select {!isNull (_x select 0) && {time < (_x select 1)}};
            if (!isNull _body && {time > _bodyUntil}) then {_ignoredBodies pushBack [_body, time + 60]; _body = objNull};
            if (time >= _nextBody) then {
                // Share one corpse enumeration per owner every five seconds.
                if (time >= (missionNamespace getVariable ["FST_varrenBodiesNext", -1])) then {FST_varrenBodies = allDeadMen; FST_varrenBodiesNext = time + 5};
                if (isNull _body) then {
                    private _best = varren_distance_roam;
                    {
                        private _candidate = _x;
                        private _d = _unit distance _candidate;
                        if (!isNull _candidate && {_d < _best} && {(_ignoredBodies findIf {(_x select 0) == _candidate}) < 0}) then {_body = _candidate; _best = _d};
                    } forEach (missionNamespace getVariable ["FST_varrenBodies", []]);
                    _bodyUntil = time + 20;
                };
                _nextBody = time + 5;
            };
            if (!isNull _body) then {
                if (_unit distance _body < 2) then {
                    [_unit, _body, _token] call dev_fnc_varren_eat;
                    _ignoredBodies pushBack [_body, time + 60]; _body = objNull;
                } else {
                    if (time >= _nextMove) then {[_unit, getPosATL _body, true] call dev_fnc_move; _nextMove = time + 5};
                };
            } else {
                if (time >= _nextMove) then {
                    if (_unit distance _origin > varren_distance_roam + 10) then {_origin = getPosATL _unit};
                    [_unit, [[[_origin, varren_distance_roam]], []] call BIS_fnc_randomPos] call dev_fnc_move;
                    _nextMove = time + 30 + random 90;
                };
            };
        };
        if (_mode > 0 && {!isNull _target} && {[_unit, _token] call FST_Gulanthar_fnc_valid}) then {
            if (time >= _nextMove) then {
                // Close on the target itself; the generic helper offsets the
                // destination by 2 m and the old stalking path wandered around it.
                if (_mode == 2) then {
                    _unit doMove getPosATL _target;
                    (group _unit) setSpeedMode "FULL";
                } else {
                    // Preserve user waypoints outside the charge distance.
                    [_unit, getPosATL _target, true] call dev_fnc_move;
                    (group _unit) setSpeedMode "NORMAL";
                };
                _nextMove = time + (if (_mode == 2) then {if (_unit distance _target < 50) then {0.5} else {1}} else {2});
            };
            if (_mode == 2 && {time >= _nextAttack}) then {
                if (_target isKindOf "Man") then {
                    if (_unit distance _target < varren_attack_reachMan) then {
                        private _psychUsed = false;
                        if (time >= _nextPsych) then {
                            _psychUsed = [_unit, _target] call dev_fnc_varren_attack_psych;
                            _nextPsych = time + (varren_attack_psychTimeout max 1);
                        };
                        // A failed special-attack roll must not consume a bite.
                        if (!_psychUsed) then {
                            if (lifeState _target == "INCAPACITATED") then {[_unit, _target, _token] call dev_fnc_varren_eat} else {[_unit, _target, _token] call dev_fnc_varren_attack_melee};
                        };
                        _nextAttack = time + (varren_attack_timeout max 0.5);
                    };
                } else {
                    if (_unit distance _target < varren_attack_reachVeh) then {[_unit, _target, _token] call dev_fnc_varren_attack_meleeVehicle; _nextAttack = time + (varren_attack_timeout max 0.5)};
                };
            };
        };
        // React quickly at melee distance without increasing the 2 s enemy scan.
        sleep (if (_mode == 2) then {if (_unit distance _target < 50) then {0.25} else {0.5}} else {1});
    };
    if ((_unit getVariable ["FST_varrenToken", -1]) == _token) then {_unit setVariable ["dev_behave_running", false]; _unit setVariable ["mode", -1]};
};
