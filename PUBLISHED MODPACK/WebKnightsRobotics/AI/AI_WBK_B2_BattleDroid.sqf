_unitWithSword = _this;
_unitWithSword allowFleeing 0;
_unitWithSword setSpeaker "NoVoice";
_unitWithSword setVariable ["disableUnitSFX",1,true];
[_unitWithSword, "B2_SupperBattleDroid_idle"] remoteExec ["switchMove", 0];
if (isNil {_unitWithSword getVariable "Droid_Health"}) then {
_unitWithSword setVariable ["Droid_Health",WBK_B2_AmountOfDamage,true];
};



_unitWithSword addEventHandler ["HandleDamage", {
  _objHit = _this select 0;
  _hitter = _this select 3;
  if (!(_objHit == _hitter)) then {
	if (_objHit getVariable 'Droid_Health' <= 0) exitWith {
	_objHit removeAllEventHandlers "HandleDamage";
	_objHit setDamage 1; 
	};
    _health = _objHit getVariable "Droid_Health";
	_health = _health - 1;
    _objHit setVariable ["Droid_Health",_health,true];
	_rndHitAnim = random 100;
	if ((_rndHitAnim >= 85) and !(animationState _objHit == "B2_SupperBattleDroid_hit")) then {
	_objHit spawn {
	_this disableAI "ALL";
	[_this, "B2_SupperBattleDroid_hit"] remoteExec ["switchMove", 0];
	sleep 1.21;
	if (!(animationState _this == "B2_SupperBattleDroid_hit")) exitWith {_this enableAI "ALL";};
	[_this, "B2_SupperBattleDroid_idle"] remoteExec ["switchMove", 0];
	_this enableAI "ALL";
	};
	};
  };  
}];





_unitWithSword addEventHandler ["PathCalculated",
{ 
	_unit = _this select 0;
	_unit spawn {
	sleep 0.5;
	_this playMoveNow "B2_SupperBattleDroid_walk";
	};
	_pathFindPoses = _this select 1;
	_arStart = _unit getVariable "WBK_DT_PathFindingObjects";
	if (!(isNil "_arStart")) then {
	deleteVehicle _arStart;
	};
    _lastPoint = _pathFindPoses select (count _pathFindPoses - 1);
	_marker = "Sign_Arrow_Yellow_F" createVehicleLocal _lastPoint; 
	_marker hideObject true;
	_unit setVariable ["WBK_DT_PathFindingObjects",_marker];
[_unit,_marker] spawn {
_unit = _this select 0;
_marker = _this select 1;
waitUntil {
sleep 0.2; 
if ((isNull _unit) or (isNull _marker) or !(alive _unit)) exitWith { true };
((_unit distance _marker) <= 2)
};
_unit playMoveNow "B2_SupperBattleDroid_idle";
};
}];
_unitWithSword removeAllEventHandlers "Killed";
_unitWithSword addEventHandler ["Killed", {
_unitWithSword = _this select 0;
_arStart = _unitWithSword getVariable "WBK_DT_PathFindingObjects";
	if (!(isNil "_arStart")) then {
	deleteVehicle _arStart;
	};
[_unitWithSword, "B2_SupperBattleDroid_die"] remoteExec ["switchMove", 0];
[_unitWithSword, "WBK_b2_dying", 70, 10] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";
[_unitWithSword, {
_object = _this;
_particlesSpark = "#particlesource" createVehicleLocal (getposATL _object);                                  
_particlesSpark setParticleParams         
	[     
		["\A3\data_f\ParticleEffects\Universal\Universal", 16, 4, 11, 4],  //sprite name        
		"", //animation name        
		"Billboard", //type        
		0.5, 1.4, //timer period and fadeout timer        
		[0, 0, 0], //position        
		[3, 3, 3], //move velocity        
		5, 1, 0.35,  0.80, //rot vel, weight, volume, rubbing        
		[0.08,0.01], //size transform        
		[[1,1,1,0], [0.1,0.1,0.1,-4], [0,0,0,-4],[1,1,1,1]],  //color and transperency        
		[1000], //animation phase speed        
		0.2,   //randomdirection period        
		0.9,  //randomization intensity        
		"", //onTimer        
		"",  //beforeDestroy        
		"",  //object        
		360,  //angle        
		false,  //on the surface        
		0  //bounce         
	];          
_particlesSpark setdropinterval 0.001;         
_particlesSpark attachTo [_object,[0.3,0,0.04],"neck"];
sleep 0.1;
deleteVehicle _particlesSpark;
}] remoteExec ["spawn", [0,-2] select isDedicated,false];
}];



_unitWithSword addEventHandler ["Fired", {
_unitWithSword = _this select 0;
if (isNil {_unitWithSword getVariable "B2Speak"}) then {
_unitWithSword spawn {
_this setVariable ["B2Speak",1];
[_this, selectRandom ["WBK_b2_firing_1","WBK_b2_firing_2","WBK_b2_firing_3","WBK_b2_firing_4","WBK_b2_firing_5"], 60] call CBA_fnc_globalSay3d;
sleep 7;
_this setVariable ["B2Speak",nil];
};
};
}];
_unitWithSword setUnitPos "UP";
_unitWithSword allowDamage false;



WBK_B2_Melee = {
_unitToPlay = _this;
_unitToPlay disableAI "ALL";
[_unitToPlay, "B2_SupperBattleDroid_melee"] remoteExec ["switchMove", 0];
sleep 0.1;
if (!(animationState _unitToPlay == "B2_SupperBattleDroid_melee")) exitWith {_unitToPlay enableAI "ALL";};
[_unitToPlay, selectRandom ["generis_empty_4","generis_empty_5","generis_empty_2"], 50, 3] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";
sleep 0.1;
if (!(animationState _unitToPlay == "B2_SupperBattleDroid_melee")) exitWith {_unitToPlay enableAI "ALL";};
if (isNil {_unitToPlay getVariable "B2Speak"}) then {
_unitToPlay spawn {
_this setVariable ["B2Speak",1];
[_this, selectRandom ["WBK_b2_firing_1","WBK_b2_firing_2","WBK_b2_firing_3","WBK_b2_firing_4","WBK_b2_firing_5"], 60] call CBA_fnc_globalSay3d;
sleep 3;
_this setVariable ["B2Speak",nil];
};
};
_myNearestEnemy = _unitToPlay findNearestEnemy _unitToPlay;
if ((_myNearestEnemy distance _unitToPlay) <= 2.5) then {
_myNearestEnemy setDamage 1;
[_myNearestEnemy, "dobi_CriticalHit", 50, 5] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";
[_myNearestEnemy, selectRandom ["lightsaber_death_11","lightsaber_death_20","lightsaber_death_5","lightsaber_death_8"]] remoteExec ["switchMove", 0];
[_myNearestEnemy, (_myNearestEnemy getDir _unitToPlay)] remoteExec ["setDir", 0];
};
sleep 0.9;
if (!(animationState _unitToPlay == "B2_SupperBattleDroid_melee")) exitWith {_unitToPlay enableAI "ALL";};
_unitToPlay enableAI "ALL";
[_unitToPlay, "B2_SupperBattleDroid_idle"] remoteExec ["switchMove", 0];
};



_actFr = [{
    _array = _this select 0;
    _mutant = _array select 0;
	_mutant disableAI "MINEDETECTION";
	_mutant disableAI "SUPPRESSION";
	_mutant disableAI "COVER";
	_mutant disableAI "AIMINGERROR";
	_mutant disableAI "FSM";
	_mutant setBehaviour "CARELESS";
	_mutant allowDamage false;
	{ 
	 _ifInter = lineIntersects [ getPosASL _mutant, eyePos _x, _mutant, _x];
		if (!(_ifInter)) then {
			 _mutant reveal [_x, 4]; 
		};
	} forEach nearestObjects [_mutant, ["Man"], 15]; 
	_myNearestEnemy = _mutant findNearestEnemy _mutant;
	if (!(handGunWeapon _myNearestEnemy in IMS_Lightsabers) and (((_myNearestEnemy worldToModel (_mutant modelToWorld [0, 0, 0])) select 1) > 0) and ((_myNearestEnemy distance _mutant) <= 2.5) and (_mutant getVariable "canMakeAttack" == 0) and (alive _mutant) and !(lifeState _mutant == "INCAPACITATED") and !(animationState _mutant == "B2_SupperBattleDroid_melee")) then {
	_mutant spawn WBK_B2_Melee;
	};
}, 0.4, [_unitWithSword]] call CBA_fnc_addPerFrameHandler;

waitUntil {sleep 0.5; 
if (isNull _unitWithSword) exitWith { true };
(!(alive _unitWithSword))
};
[_actFr] call CBA_fnc_removePerFrameHandler;