dev_fnc_varren_behave = {
	params ["_unit"];

	if (!local _unit) exitWith {};
    if (dev_cba_killswitch) exitWith {};
	
	_unit setDamage (1 - varren_health);

	while {alive _unit} do {
		//-- Idle
			_unit setVariable ["mode", 0];  //-- 0: idle, 1: hunt, 2: agro
			[_unit, "JMSEF_animals_varren_spawn", 6, 300] call dev_fnc_say3D;  //-- IM BORED SOUND
			(group _unit) setSpeedMode "LIMITED"; _unit forceSpeed -1;
			[_unit] spawn {  //-- Roaming/eating
				params ["_unit"];
				_initialPos = getPosATL _unit;				
				while {dev_asymhuman_distance_roam > 0 && alive _unit && _unit getVariable "mode" == 0} do {
					_bodies = [_unit, varren_distance_roam] call dev_fnc_getBodies;
					if (count _bodies != 0) then {
						_nearestBody = _bodies#0;
						[_unit, getPosATL _nearestBody, true] call dev_fnc_move;
						[_unit, _nearestBody] call dev_fnc_varren_eat;
					} else {
						sleep (random [0, 60, 120]);
						if (_unit getVariable "mode" != 0) exitWith {};  //-- Cause it may have changed after the sleep started
						if (_unit distance _initialPos > (varren_distance_roam + 10)) then {_initialPos = getPosATL _unit};  //-- If moved further than initialPos (probably by Zeus), then update initialPos
						[_unit, [[[_initialPos, varren_distance_roam]],[]] call BIS_fnc_randomPos] call dev_fnc_move;  //-- Move to random location in radius
					};
				};
			};

			//-- Wait
			waitUntil {sleep 1; !alive _unit || count ([_unit, varren_distance_hunt, varren_distance_max] call dev_fnc_getEnemies) > 0};  //-- Wait until there are enemies in hunt distance

		//-- Hunt
			_unit setVariable ["mode", 1];  //-- 0: idle, 1: hunt, 2: agro	
			[_unit, "JMSEF_animals_varren_stalk", 6, 300] call dev_fnc_say3D;  //-- IM CURIOUS SOUND
			(group _unit) setSpeedMode "LIMITED";	
			[_unit] spawn {  //-- Find enemies and go close ish to them
				params ["_unit"];
				while {alive _unit && _unit getVariable "mode" == 1} do {
					_enemies = [_unit, varren_distance_hunt, varren_distance_hunt] call dev_fnc_getEnemies;
					if (count _enemies != 0) then {[_unit, [[[getPosATL (_enemies#0), varren_distance_agro]],[]] call BIS_fnc_randomPos] call dev_fnc_move};  //-- Move to random location in radius of nearest enemy
					sleep 10;
				};
			};

			//-- Wait
			waitUntil {sleep 1; !alive _unit || count ([_unit, varren_distance_agro, varren_distance_max] call dev_fnc_getEnemies) > 0};  //-- Wait until there are enemies in agro distance

		//-- Agro
			_unit setVariable ["mode", 2];  //-- 0: idle, 1: hunt, 2: agro	
			[_unit, "JMSEF_animals_varren_attack", 6, 300] call dev_fnc_say3D;  //-- IM ANGRY SOUND
			(group _unit) setSpeedMode "FULL"; _unit forceSpeed 15;
			[_unit] spawn {params ["_unit"];
				while {alive _unit && _unit getVariable "mode" == 2} do {
					_enemies = [_unit, varren_distance_agro, varren_distance_max, 5] call dev_fnc_getEnemies;
					if (count _enemies != 0) then {
						_nearestEnemy =_enemies#0;
						[_unit, getPosATL _nearestEnemy, false] call dev_fnc_move;
						[_unit, _nearestEnemy] call dev_fnc_varren_attack;
						[_unit, varren_sound_ambient, 0.25] call dev_fnc_ambientSound;
						[_unit, _nearestEnemy, "form939_walk", "form939_idle"] call dev_fnc_stuckHandler;  //-- Must be called instead of spawned and will sleep 1 second
					};
					sleep 1;
				};
			};

			//-- Wait
			waitUntil {sleep 1; !alive _unit || count ([_unit, varren_distance_agro, varren_distance_max] call dev_fnc_getEnemies) == 0};  //-- Wait until there are no more enemies in agro distance
	};
};

dev_fnc_varren_eat = {
	params ["_unit", "_victim"];

	[_unit, (_unit getReldir _victim) + getDir _unit, 0.1] call dev_fnc_lookAt;  //-- Aim
	if (_unit distance _victim < 2 && animationState _unit != "form939_eat") then {  //-- If close enough and not already eating then start eating
		_unit disableAI "ANIM";
		_unit playMove "form939_eat";
		[_victim, 3] spawn dev_fnc_smoke;
		[[_victim, getPos _victim, 2, false, 3], dev_fnc_blood] remoteExec ["spawn", 0];  //-- Blood particles
		sleep 3;  //-- Duration of animation
		_unit enableAI "ANIM";
	};

	[_victim, "body", varren_attack_damageMan, "bullet"] remoteExec ["dev_fnc_addHitPointDamage", _victim];  //-- Damage
};

dev_fnc_varren_attack = {
	params ["_unit", "_victim"];

	if (_victim isKindOf "Man" && _unit distance _victim < varren_attack_reachMan) then {  //-- Man
		if (_unit getVariable ["psych", true]) then {  //-- Psych attack, only allowed every 15 seconds (varren_attack_psychTimeout)
			[_unit, _victim] call dev_fnc_varren_attack_psych;
			[_unit, "psych", varren_attack_psychTimeout] spawn dev_fnc_attackTimeout2;  //-- Timeout, so this doesnt spam
		} else {  //-- Melee
			if (lifeState _victim == "INCAPACITATED") then {
				[_unit, _victim] call dev_fnc_varren_eat;  //-- If uncon, then eat to death
			} else {
				[_unit, _victim] call dev_fnc_varren_attack_melee;
			};
		};
		
		sleep varren_attack_timeout;
	};

	if (!(_victim isKindOf "Man") && _unit distance _victim < varren_attack_reachVeh) then {  //-- Vehicle
		[_unit, _victim] spawn dev_fnc_varren_attack_meleeVehicle;
		sleep varren_attack_timeout;
	};
};

dev_fnc_varren_attack_meleeVehicle = {
	params ["_unit", "_vehicle"];

	[_unit, selectRandom ["form939_attack4", "form939_attack6"]] remoteExec ["switchMove", 0];  //-- Animation
	[_unit, _vehicle, varren_attack_damageVeh, varren_attack_launchVeh, 0.5] remoteExec ["dev_fnc_launchVehicle", _vehicle];  //-- Launch/damage
};

dev_fnc_varren_attack_melee = {
	params ["_unit", "_victim"];

	_unit disableAI "ANIM";
	[_unit, selectRandom ["form939_attack4", "form939_attack6"]] remoteExec ["switchMove", 0];  //-- Animation
	sleep 0.5;  //-- Time between animation start and impact
	_bodyPart = selectRandom ["head", "body"];  //-- Random bodypart selection		
	[[_victim, _victim modelToWorld (_victim selectionPosition _bodyPart), 2], dev_fnc_blood] remoteExec ["spawn", 0];  //-- Blood particles
	[_victim, _bodyPart, varren_attack_damageMan, "bullet"] remoteExec ["dev_fnc_addHitPointDamage", _victim];  //-- Damage
	[_victim, "dev_hit1", 3, 50,[0.8,1,2]] call dev_fnc_say3D;  //-- Hit sound
	_unit enableAI "ANIM";
};

dev_fnc_varren_attack_psych = {
	params ["_unit", "_victim"];

	if (random 1 < varren_attack_psychChance && [_victim, varren_distance_agro] call dev_fnc_getLoneliness && lifeState _victim != "INCAPACITATED") then {  //-- If alone and not already uncon, then psych, also probability
		[_victim, "JMSEF_animals_varren_attack", 6, 800] call dev_fnc_say3D;;  //-- Psych sound
		[[_victim, true, varren_attack_psychDuration], dev_fnc_setUnconsious] remoteExec ["spawn", _victim];  //-- Uncon
	};
};