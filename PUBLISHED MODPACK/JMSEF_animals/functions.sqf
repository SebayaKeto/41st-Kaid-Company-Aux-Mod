// Single controller, cancelled synchronously by the locality handler.
FST_Gulanthar_fnc_valid = {
    params ["_unit", "_token"];
    !isNull _unit && {alive _unit} && {local _unit} && {(_unit getVariable ["FST_varrenToken", -1]) == _token} && {!(missionNamespace getVariable ["dev_cba_killswitch", false])}
};
FST_Gulanthar_fnc_start = {
    params ["_unit", ["_gained", true]];
    if (isNull _unit) exitWith {};
    private _old = _unit getVariable ["FST_varrenScript", scriptNull];
    if (!_gained) exitWith {
        _unit setVariable ["FST_varrenToken", (_unit getVariable ["FST_varrenToken", 0]) + 1];
        if (!scriptDone _old) then {terminate _old};
        // terminate becomes observable on a later scheduler turn. Clear the
        // slot now; the token prevents a returning owner reusing that script.
        _unit setVariable ["FST_varrenScript", scriptNull];
        _unit setVariable ["dev_behave_running", false];
    };
    if (!local _unit || {!alive _unit} || {!scriptDone _old}) exitWith {};
    if (_unit getVariable ["FST_varrenOwnsAnim", false]) then {
        _unit enableAI "ANIM";
        _unit setVariable ["FST_varrenOwnsAnim", false, true];
    };
    private _token = (_unit getVariable ["FST_varrenToken", 0]) + 1;
    _unit setVariable ["FST_varrenToken", _token];
    _unit setVariable ["FST_varrenScript", [_unit, _token] spawn dev_fnc_varren_behave];
};
// Named effects go only to nearby players. Damage is a separate owner RPC.
FST_Gulanthar_fnc_emit = {
    params ["_unit", ["_duration", 0.2]];
    private _owners = [];
    {if (!(_x isKindOf "HeadlessClient_F") && {_x distance _unit < 250}) then {_owners pushBackUnique owner _x}} forEach allPlayers;
    {["FST_varrenBlood", [_unit, _duration], _x] call CBA_fnc_ownerEvent} forEach _owners;
};
["FST_varrenBlood", {
    params ["_unit", "_duration"];
    if (!hasInterface || {isNull _unit} || {player distance _unit > 300}) exitWith {};
    FST_varrenParticles = (missionNamespace getVariable ["FST_varrenParticles", []]) select {!isNull _x};
    if (count FST_varrenParticles >= 24) exitWith {};
    private _p = "#particlesource" createVehicleLocal getPosATL _unit;
    // Avoid blood1/blood2's undefined expression variables.
    _p setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal",16,13,1,0],"","Billboard",1,0.35,[0,0,0],[0,0,1],1,1,0.8,0.1,[0.06,0.02],[[0.35,0,0,0.8],[0.2,0,0,0]],[1],0,0,"","",_unit];
    _p setParticleRandom [0.1,[0.1,0.1,0.1],[0.8,0.8,0.8],0,0.02,[0,0,0,0],0,0];
    _p setDropInterval 0.04;
    _p attachTo [_unit,[0,0,0],"spine3"];
    FST_varrenParticles pushBack _p;
    [{params ["_p"]; deleteVehicle _p}, [_p], (_duration max 0.1) min 3] call CBA_fnc_waitAndExecute;
    if (local _unit && {isPlayer _unit}) then {[150] call BIS_fnc_bloodEffect};
}] call CBA_fnc_addEventHandler;
FST_Gulanthar_fnc_sound = {
    params ["_unit", "_sound", ["_range", 300]];
    private _owners = [];
    {if (!(_x isKindOf "HeadlessClient_F") && {_x distance _unit < _range}) then {_owners pushBackUnique owner _x}} forEach allPlayers;
    {[_unit, [_sound, _range, 1]] remoteExec ["say3D", _x]} forEach _owners;
};
dev_fnc_varren_behave = {
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
        private _newMode = if (isNull _target) then {0} else {if (_unit distance _target <= varren_distance_agro) then {2} else {1}};
        if (_newMode != _mode) then {
            _mode = _newMode;
            _unit setVariable ["mode", _mode];
            _nextMove = 0;
            (group _unit) setSpeedMode (["LIMITED", "LIMITED", "FULL"] select _mode);
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
                private _destination = if (_mode == 2) then {getPosATL _target} else {[[[getPosATL _target, varren_distance_agro]], []] call BIS_fnc_randomPos};
                [_unit, _destination, _mode != 2] call dev_fnc_move;
                _nextMove = time + (if (_mode == 2) then {2} else {10});
            };
            if (_mode == 2 && {time >= _nextAttack}) then {
                if (_target isKindOf "Man") then {
                    if (_unit distance _target < varren_attack_reachMan) then {
                        if (time >= _nextPsych) then {
                            [_unit, _target] call dev_fnc_varren_attack_psych;
                            _nextPsych = time + (varren_attack_psychTimeout max 1);
                        } else {
                            if (lifeState _target == "INCAPACITATED") then {[_unit, _target, _token] call dev_fnc_varren_eat} else {[_unit, _target, _token] call dev_fnc_varren_attack_melee};
                        };
                        _nextAttack = time + (varren_attack_timeout max 0.5);
                    };
                } else {
                    if (_unit distance _target < varren_attack_reachVeh) then {[_unit, _target, _token] call dev_fnc_varren_attack_meleeVehicle; _nextAttack = time + (varren_attack_timeout max 0.5)};
                };
            };
        };
        sleep 1;
    };
    if ((_unit getVariable ["FST_varrenToken", -1]) == _token) then {_unit setVariable ["dev_behave_running", false]; _unit setVariable ["mode", -1]};
};
dev_fnc_varren_eat = {
    params ["_unit", "_victim", "_token"];
    if (!([_unit, _token] call FST_Gulanthar_fnc_valid) || {isNull _victim} || {_unit distance _victim >= 2}) exitWith {};
    private _animWasEnabled = _unit checkAIFeature "ANIM";
    if (_animWasEnabled) then {_unit setVariable ["FST_varrenOwnsAnim", true, true]; _unit disableAI "ANIM"};
    _unit playMove "form939_eat";
    [_victim, 3] call FST_Gulanthar_fnc_emit;
    sleep 3;
    if (local _unit && {(_unit getVariable ["FST_varrenToken", -1]) == _token} && {_animWasEnabled}) then {_unit enableAI "ANIM"; _unit setVariable ["FST_varrenOwnsAnim", false, true]};
    if ([_unit, _token] call FST_Gulanthar_fnc_valid && {!isNull _victim} && {alive _victim} && {_unit distance _victim < 2}) then {
        [_victim, "body", varren_attack_damageMan, "bullet"] remoteExec ["dev_fnc_addHitPointDamage", _victim];
    };
};
dev_fnc_varren_attack_meleeVehicle = {
    params ["_unit", "_vehicle", "_token"];
    if (!([_unit, _token] call FST_Gulanthar_fnc_valid) || {!alive _vehicle} || {_unit distance _vehicle >= varren_attack_reachVeh}) exitWith {};
    [_unit, selectRandom ["form939_attack4", "form939_attack6"]] remoteExec ["switchMove", 0];
    [_unit, _vehicle, varren_attack_damageVeh, varren_attack_launchVeh, 0.5] remoteExec ["dev_fnc_launchVehicle", _vehicle];
};
dev_fnc_varren_attack_melee = {
    params ["_unit", "_victim", "_token"];
    if (!([_unit, _token] call FST_Gulanthar_fnc_valid) || {!alive _victim} || {_unit distance _victim >= varren_attack_reachMan}) exitWith {};
    private _animWasEnabled = _unit checkAIFeature "ANIM";
    if (_animWasEnabled) then {_unit setVariable ["FST_varrenOwnsAnim", true, true]; _unit disableAI "ANIM"};
    [_unit, selectRandom ["form939_attack4", "form939_attack6"]] remoteExec ["switchMove", 0];
    sleep 0.5;
    if (local _unit && {(_unit getVariable ["FST_varrenToken", -1]) == _token} && {_animWasEnabled}) then {_unit enableAI "ANIM"; _unit setVariable ["FST_varrenOwnsAnim", false, true]};
    if (!([_unit, _token] call FST_Gulanthar_fnc_valid) || {!alive _victim} || {_unit distance _victim >= varren_attack_reachMan}) exitWith {};
    [_victim] call FST_Gulanthar_fnc_emit;
    [_victim, selectRandom ["head", "body"], varren_attack_damageMan, "bullet"] remoteExec ["dev_fnc_addHitPointDamage", _victim];
    [_victim, "dev_hit1", 50] call FST_Gulanthar_fnc_sound;
};
dev_fnc_varren_attack_psych = {
    params ["_unit", "_victim"];
    if (random 1 < varren_attack_psychChance && {[_victim, varren_distance_agro] call dev_fnc_getLoneliness} && {lifeState _victim != "INCAPACITATED"}) then {
        [_victim, "JMSEF_animals_varren_attack", 800] call FST_Gulanthar_fnc_sound;
        [_victim, true, varren_attack_psychDuration] remoteExec ["dev_fnc_setUnconsious", _victim];
    };
};
