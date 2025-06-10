_unitWithSword = _this;
_unitWithSword setSpeaker "NoVoice";
if (isPlayer _unitWithSword) exitWith {
_unitWithSword removeAllEventHandlers "Killed";
_unitWithSword addEventHandler ["Killed", {
_unitWithSword = _this select 0;
[_unitWithSword, "WBK_b2_dying", 10, 10] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";
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
_unitWithSword spawn {
_unitWithSword = _this;
_countUnitsAround = {!(_x == _unitWithSword) and (alive _x) and !(lifeState _x == "INCAPACITATED")} count nearestObjects [_unitWithSword,["WBK_BX_Assasin_1"],15];
systemChat str _countUnitsAround;
if (_countUnitsAround == 0) exitWith {};
{
if (!(_x == _unitWithSword) and (alive _x) and !(lifeState _x == "INCAPACITATED")) then {
orushiiUnit = _x;
};
} forEach nearestObjects [_unitWithSword,["WBK_BX_Assasin_1"],15];
[orushiiUnit, selectRandom ["BX_FriendlyDown_1","BX_FriendlyDown_2","BX_FriendlyDown_3","BX_FriendlyDown_4"]] spawn BX_SayPhrase;
};
}];
};
_unitWithSword allowFleeing 0;
_unitWithSword setUnitPos "UP";
_unitWithSword allowDamage false;
_unitWithSword removeAllEventHandlers "HandleDamage";
_unitWithSword addEventHandler ["HandleDamage", {
  _objHit = _this select 0;
  _hitter = _this select 3;
  if (!(_objHit == _hitter)) then {
	if ((damage _objHit) > 0.4) exitWith {
	_objHit setDamage 1; 
	};
    _objHit setDamage ((damage _objHit) + 0.07);
  };  
}];





BX_SayPhrase = {
_unit = _this select 0;
_phrase = _this select 1;
if (!(isNil {_unit getVariable "BX_isTalking"})) exitWith {};
{
_x spawn {
_this setVariable ["BX_isTalking",1];
sleep 3;
_this setVariable ["BX_isTalking",nil];
};
} forEach nearestObjects [_unit,["WBK_BX_Assasin_1"],20];
[_unit, _phrase, 130] call CBA_fnc_globalSay3d;
};




Human_Execution_Sword_DROIDMAIN = {
_main = _this select 1;
_victim = _this select 0;
_main setVariable ["canMakeAttack",1];
_main setVariable ["AI_CanTurn",1];
_main setVariable ["actualSwordBlock",0, true];
[_main, "SM_Sword_Execution"] remoteExec ["switchMove", 0, false];
[_victim, "SM_Sword_Execution_Victim"] remoteExec ["switchMove", 0, true];
[_victim, "SM_Sword_Execution_Victim"] remoteExec ["switchMove", 0, true];
[_main, "Disable_Gesture"] remoteExec ["playActionNow", _main];
[_victim, "Disable_Gesture"] remoteExec ["playActionNow", _victim];
_victim attachTo [_main,[0,0,0]];
_victim setDamage 1;
sleep 0.1;
if (!(animationState _main == "SM_Sword_Execution")) exitWith {
detach _victim;
};
_arr = parseSimpleArray getText (configFile >> "CfgWeapons" >> handgunWeapon _main >> "IMS_Melee_Param_Sounds");  
_rndSnd = selectRandom _arr;  
[_main, _rndSnd, 50, 3] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";  
sleep 0.3;
if (!(animationState _main == "SM_Sword_Execution")) exitWith {
detach _victim;
};
[_main, selectRandom ["loud_scream_1","loud_scream_2"], 120, 3] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";  
[_victim, {
_object = _this;
sleep 1.3;
_blood = "#particlesource" createVehicleLocal (getposATL _object);          
_blood attachTo [_object,[0,0,0],"Spine3"];         
_blood setParticleParams [ 
  ["\a3\Data_f\ParticleEffects\Universal\Universal", 16, 13, 1, 16],             
  "",              
  "billboard",           
  0.1, 5,              
  [0, 0, 0],       
  [0.5 + random -1, 0.5 + random -1, 1],            
  1, 1, 0.3, 1,          
  [0.2, 4],       
  [[1,1,1,0.12], [0.01,0.01,0.01,0.0]],     
  [0.00001],     
  0.4,     
  0.4,     
  "",     
  "",     
  "",    
  360,            
  false,             
  0   
 ]; 
 _blood setdropinterval 0.003;
 sleep 0.5;
 deleteVehicle _blood; 
_rndBlood = selectRandom ["BloodSplatter_01_Medium_New_F","BloodPool_01_Medium_New_F"];
_deathBlood = _rndBlood createVehicleLocal getPosATL _object;
_deathBlood attachTo [_object,[0.3,0.7,0]];
detach _deathBlood;
_deathBlood setDir (random 360);
sleep 0.5;
_deathBlood setVectorUp surfaceNormal position _deathBlood;
}] remoteExec ["spawn", [0,-2] select isDedicated,false];
_arr = parseSimpleArray getText (configFile >> "CfgWeapons" >> handgunWeapon _main >> "IMS_Melee_Param_SoundsOnHit");  
_rndSnd = selectRandom _arr;  
[_main, _rndSnd, 50, 4] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";  
sleep 1.5;
if (!(animationState _main == "SM_Sword_Execution")) exitWith {
detach _victim;
};
[_main, selectRandom ["sword_headgore_1","sword_headgore_2"], 50, 4] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";  
sleep 0.9;
if (!(animationState _main == "SM_Sword_Execution")) exitWith {
detach _victim;
};
detach _victim;
[_main, "AmovPercMstpSlowWrflDnon"] remoteExec ["switchMove", 0];
_main setVariable ["canMakeAttack",0];
_main setVariable ["AI_CanTurn",0];
_main enableAI "ALL";
};






Human_Execution_ChokeOne_DROIDMAIN = {
_main = _this select 1;
_victim = _this select 0;
_main disableAI "ALL";
_main setVariable ["canMakeAttack",1];
_main setVariable ["AI_CanTurn",1];
_main setVariable ["actualSwordBlock",0, true];
[_main, "Human_Execution_GenericOnehanded_headSmash_1_main"] remoteExec ["switchMove", 0, false];
[_victim, "Human_Execution_GenericOnehanded_headSmash_1_victim"] remoteExec ["switchMove", 0, true];
[_victim, "Human_Execution_GenericOnehanded_headSmash_1_victim"] remoteExec ["switchMove", 0, true];
[_main, "Disable_Gesture"] remoteExec ["playActionNow", _main];
[_victim, "Disable_Gesture"] remoteExec ["playActionNow", _victim];
_victim attachTo [_main,[0,1.25,0]];
_victim setDamage 1;
sleep 0.5;
if (!(alive _main)) exitWith {};
_arr = parseSimpleArray getText (configFile >> "CfgWeapons" >> handgunWeapon _main >> "IMS_Melee_Param_SoundsOnHit");  
_rndSnd = selectRandom _arr;  
[_victim, _rndSnd, 50, 7] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf"; 
[_victim, "dobi_criticalHit", 20, 7] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf"; 
[_main, selectRandom ["BX_EnemyDown_1","BX_EnemyDown_2","BX_EnemyDown_3","BX_EnemyDown_4"]] spawn BX_SayPhrase;
[_victim, {
_object = _this;
_blood = "#particlesource" createVehicleLocal (getposATL _object);          
_blood attachTo [_object,[0,0,0],"neck"];         
_blood setParticleParams [ 
  ["\a3\Data_f\ParticleEffects\Universal\Universal", 16, 13, 1, 16],             
  "",              
  "billboard",           
  0.1, 5,              
  [0, 0, 0],       
  [0.5 + random -1, 0.5 + random -1, 1],            
  1, 1, 0.3, 1,          
  [0.2, 4],       
  [[1,1,1,0.12], [0.001,0.001,0.001,0.0]],     
  [0.00001],     
  0.4,     
  0.4,     
  "",     
  "",     
  "",    
  360,            
  false,             
  0   
 ]; 
 _blood setdropinterval 0.003;
 sleep 0.5;
  deleteVehicle _blood; 
_rndBlood = selectRandom ["BloodSplatter_01_Medium_New_F","BloodPool_01_Medium_New_F"];
_deathBlood = _rndBlood createVehicleLocal getPosATL _object;
_deathBlood attachTo [_object,[0.3,2,0]];
detach _deathBlood;
_deathBlood setDir (random 360);
sleep 0.5;
_deathBlood setVectorUp surfaceNormal position _deathBlood;
}] remoteExec ["spawn", [0,-2] select isDedicated,false];
sleep 0.4;
if (!(alive _main)) exitWith {};
[_victim, "dobi_fall_2", 100, 4] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";  
_rndSndB = selectRandom ["bloodCought_1","bloodCought_2","bloodCought_3"];
[_victim, _rndSndB, 40, 14] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf"; 
sleep 0.4;
if (_rndSndB == "bloodCought_1") then {
[_victim, 0.6] remoteExec ["setAnimSpeedCoef", 0];
};
sleep 0.5;
if (!(alive _main)) exitWith {};
detach _victim;
_main enableAI "ALL";
[_main, "AmovPercMstpSlowWrflDnon"] remoteExec ["switchMove", 0];
_main setVariable ["canMakeAttack",0];
_main setVariable ["AI_CanTurn",0];
};



Human_Execution_StompOnHead_DROIDMAIN = {
_main = _this select 1;
_victim = _this select 0;
_main disableAI "ALL";
_main setVariable ["canMakeAttack",1];
_main setVariable ["AI_CanTurn",1];
_main setVariable ["actualSwordBlock",0, true];
[_main, "SM_Fists_Execution_main"] remoteExec ["switchMove", 0, false];
[_victim, "SM_Fists_Execution_victim"] remoteExec ["switchMove", 0, true];
[_victim, "SM_Fists_Execution_victim"] remoteExec ["switchMove", 0, true];
[_main, "Disable_Gesture"] remoteExec ["playActionNow", _main];
[_victim, "Disable_Gesture"] remoteExec ["playActionNow", _victim];
_victim attachTo [_main,[0,0,0]];
_victim setDamage 1;
sleep 0.3;
if (!(alive _main)) exitWith {};
[_victim, selectRandom ["leg_hit1","leg_hit2","leg_hit3"], 100, 3] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf"; 
sleep 0.8;
if (!(alive _main)) exitWith {};
[_main, selectRandom ["BX_EnemyDown_1","BX_EnemyDown_2","BX_EnemyDown_3","BX_EnemyDown_4"]] spawn BX_SayPhrase;
[_victim, "dobi_bones", 100, 4] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";  
[_victim, "dobi_criticalHit", 50, 7] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf"; 
sleep 1.8;
if (!(alive _main)) exitWith {};
detach _victim;
_main enableAI "ALL";
[_main, "AmovPercMstpSlowWrflDnon"] remoteExec ["switchMove", 0];
_main setVariable ["canMakeAttack",0];
_main setVariable ["AI_CanTurn",0];
};


_actFrWeapExecut = [{
    _array = _this select 0;
    _mutant = _array select 0;
	if (lifeState _mutant == "INCAPACITATED") exitWith {_mutant allowDamage true;};
	{ 
	 _ifInter = lineIntersects [ getPosASL _mutant, eyePos _x, _mutant, _x];
		if (!(_ifInter)) then {
			 _mutant reveal [_x, 4]; 
		};
	} forEach nearestObjects [_mutant, ["Man"], 10];
	_myNearestEnemy = _mutant findNearestEnemy _mutant;
	if (!(handGunWeapon _myNearestEnemy in IMS_Melee_Weapons) and ((_myNearestEnemy distance _mutant) <= 3) and (alive _mutant) and !(handGunWeapon _myNearestEnemy in IMS_Melee_Weapons) and (_mutant getVariable "canMakeAttack" == 0)) then {
         [_myNearestEnemy,_mutant] spawn selectRandom [Human_Execution_Sword_DROIDMAIN,Human_Execution_ChokeOne_DROIDMAIN,Human_Execution_StompOnHead_DROIDMAIN];
	};
}, 0.4, [_unitWithSword]] call CBA_fnc_addPerFrameHandler;






_unitWithSword removeAllEventHandlers "Killed";
_unitWithSword addEventHandler ["Killed", {
_unitWithSword = _this select 0;
[_unitWithSword, "WBK_b2_dying", 10, 10] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";
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
_unitWithSword spawn {
_unitWithSword = _this;
_countUnitsAround = {!(_x == _unitWithSword) and (alive _x) and !(lifeState _x == "INCAPACITATED")} count nearestObjects [_unitWithSword,["WBK_BX_Assasin_1"],15];
systemChat str _countUnitsAround;
if (_countUnitsAround == 0) exitWith {};
{
if (!(_x == _unitWithSword) and (alive _x) and !(lifeState _x == "INCAPACITATED")) then {
orushiiUnit = _x;
};
} forEach nearestObjects [_unitWithSword,["WBK_BX_Assasin_1"],15];
[orushiiUnit, selectRandom ["BX_FriendlyDown_1","BX_FriendlyDown_2","BX_FriendlyDown_3","BX_FriendlyDown_4"]] spawn BX_SayPhrase;
};
}];



_unitWithSword setSkill 0.8;
_waitTillGuyAppear = true;
while {((_waitTillGuyAppear) and (alive _unitWithSword))} do {
{
_ifInter = lineIntersectsSurfaces [
		AGLToASL (_x modelToWorld [0,0,0.9]), 
		AGLToASL (_unitWithSword modelToWorld [0,0,0.9]), 
		_unitWithSword,
		_x,
		true,
		1,
		"GEOM",
		"NONE"
	];
if (
(count _ifInter == 0) and 
!(side _x == side _unitWithSword) and 
(handGunWeapon _x in IMS_Melee_Weapons) and 
(alive _x) and 
((getPosATL _x select 2) < 1.45)
) then {
_waitTillGuyAppear = false;
};
} forEach nearestObjects [_unitWithSword, ["man"], 15];
sleep 0.2;
};
[_actFrWeapExecut] call CBA_fnc_removePerFrameHandler;
if (!(alive _unitWithSword)) exitWith {};
_unitWithSword setVariable ["IMS_ISAI",1, true];
_unitWithSword setVariable ["IMS_IsAnimPlayed",0, true];
_unitWithSword setVariable ["actualSwordBlock",0, true];
_unitWithSword setVariable ["canMakeAttack",1];
_unitWithSword setVariable ["AI_CanTurn",0];
_unitWithSword setVariable ["concentrationParam",0.7, true];
_unitWithSword setVariable ["disableUnitSFX",1, true];
_unitWithSword setVariable ["IMS_Droid_SwitchToNormalWeapon",0];


[_unitWithSword, "ims_takeOut_TwoHanded"] remoteExec ["playActionNow", _unitWithSword];
[_unitWithSword, "ims_takeOut_TwoHanded"] remoteExec ["playActionNow", _unitWithSword];
[_unitWithSword, "ims_takeOut_TwoHanded"] remoteExec ["playActionNow", _unitWithSword];
[_unitWithSword, selectRandom ["BX_SwitchingMelee_1","BX_SwitchingMelee_2"]] spawn BX_SayPhrase;
sleep 0.55;
if (!(alive _unitWithSword)) exitWith {};
_unitWithSword setVariable ["canMakeAttack",0];
[_unitWithSword, "generic_in", 20, 6] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";
[_unitWithSword, "melee_armed_idle"] remoteExec ["switchMove", 0];










animPush = {
_unit = _this select 0;
_anim = _this select 1;
_myNearestEnemy = _unit findNearestEnemy _unit;
_ifInter = lineIntersectsSurfaces [
		AGLToASL (_myNearestEnemy modelToWorld [0,0,0.1]), 
		AGLToASL (_unit modelToWorld [0,0,0.1]), 
		_unit,
		_myNearestEnemy,
		true,
		1,
		"GEOM",
		"NONE"
	];
if ( (_unit getVariable "IMS_IsAnimPlayed" == 0) and (alive _unit) and (_unit getVariable "canMakeAttack" == 0) and (isTouchingGround _unit) and (count _ifInter == 0) and !(animationState _unit == "starWars_lightsaber_block_1") and !(animationState _unit == "starWars_lightsaber_block_2") and !(animationState _unit == "starWars_lightsaber_block_3") and !(animationState _unit == "starWars_lightsaber_hit_1") and !(animationState _unit == "starWars_lightsaber_hit_2") and !(animationState _unit == "starWars_lightsaber_blockPursuit")) then {
    _unit setVariable ["IMS_IsAnimPlayed",1, true];
    sleep 0.5;
    if ((_unit getVariable "canMakeAttack" == 0)) then {
      _unit playMoveNow _anim;
    };
    sleep 1;
    _unit setVariable ["IMS_IsAnimPlayed",0, true];
};
};


_unitWithSword removeAllEventHandlers "HandleDamage";
_unitWithSword addEventHandler ["HandleDamage", {
  _objHit = _this select 0;
  _hitter = _this select 3;
  if (!(_objHit == _hitter)) then {
	if ((damage _objHit) > 0.4) exitWith {
	_objHit setDamage 1; 
	};
    _objHit setDamage ((damage _objHit) + 0.07);
  };  
}];



WBK_DroidComFireAtTarget = {
_droid = _this;
[_droid, [-9, -9, 1.5], "starWars_landRoll_b"] remoteExec ["strafeFwrd_SW", _droid];
sleep 1.2;
if (!(animationState _droid == "starWars_landRoll_b")) exitWith {};
_droid setVariable ["actualSwordBlock",1, true];
_droid setVariable ["canMakeAttack",1];
_droid setVariable ["AI_CanTurn",0];
[_droid, "SW_FIGHT_DROID_COMMANDO_FIRING"] remoteExec ["switchMove", 0]; 
sleep 0.6;
if (!(animationState _droid == "SW_FIGHT_DROID_COMMANDO_FIRING")) exitWith {};
_droid setAmmo [primaryWeapon _droid, 10];
_droid forceWeaponFire [primaryWeapon _droid, "Single"]; 
_objHit = _droid findNearestEnemy _droid;
if ((_objHit getVariable "actualSwordBlock" == 1)) then {
	  if (((_objHit worldToModel (_droid modelToWorld [0, 0, 0])) select 1) < 0) then {
	  	  if ((damage _objHit) > 0.5) exitWith {
		  _objHit removeAllEventHandlers "HandleDamage";
	      _objHit setDamage 1; 
		  [_objHit, "Disable_Gesture"] remoteExec ["playActionNow", _objHit];
	      _rndAnim = selectRandom ["lightsaber_death_1","lightsaber_death_2","lightsaber_death_3","lightsaber_death_4","lightsaber_death_5","lightsaber_death_6","lightsaber_death_7","flamethrower_burning_6","flamethrower_burning_7"];
		  [_objHit, _rndAnim] remoteExec ["switchMove", 0, true];
	      };
	      [_objHit] spawn SW_AdditionalDamage;
	  }else{
	      [_objHit, _droid] spawn otroZeniePolnoje;
	 };
}else{
	if ((damage _objHit) > 0.5) exitWith {
	      _objHit removeAllEventHandlers "HandleDamage";
	      _objHit setDamage 1; 
		  [_objHit, "Disable_Gesture"] remoteExec ["playActionNow", _objHit];
	      _rndAnim = selectRandom ["lightsaber_death_1","lightsaber_death_2","lightsaber_death_3","lightsaber_death_4","lightsaber_death_5","lightsaber_death_6","lightsaber_death_7","flamethrower_burning_6","flamethrower_burning_7"];
		  [_objHit, _rndAnim] remoteExec ["switchMove", 0, true];
	};
    [_objHit] spawn SW_AdditionalDamage;
};
sleep 0.5;
if (!(animationState _droid == "SW_FIGHT_DROID_COMMANDO_FIRING")) exitWith {};
_droid setAmmo [primaryWeapon _droid, 10];
_droid forceWeaponFire [primaryWeapon _droid, "Single"]; 
_objHit = _droid findNearestEnemy _droid;
if ((_objHit getVariable "actualSwordBlock" == 1)) then {
	  if (((_objHit worldToModel (_droid modelToWorld [0, 0, 0])) select 1) < 0) then {
	  	  if ((damage _objHit) > 0.5) exitWith {
		  _objHit removeAllEventHandlers "HandleDamage";
	      _objHit setDamage 1; 
		  [_objHit, "Disable_Gesture"] remoteExec ["playActionNow", _objHit];
	      _rndAnim = selectRandom ["lightsaber_death_1","lightsaber_death_2","lightsaber_death_3","lightsaber_death_4","lightsaber_death_5","lightsaber_death_6","lightsaber_death_7","flamethrower_burning_6","flamethrower_burning_7"];
		  [_objHit, _rndAnim] remoteExec ["switchMove", 0, true];
	      };
	      [_objHit] spawn SW_AdditionalDamage;
	  }else{
	      [_objHit, _droid] spawn otroZeniePolnoje;
	 };
}else{
	if ((damage _objHit) > 0.5) exitWith {
	      _objHit removeAllEventHandlers "HandleDamage";
	      _objHit setDamage 1; 
		  [_objHit, "Disable_Gesture"] remoteExec ["playActionNow", _objHit];
	      _rndAnim = selectRandom ["lightsaber_death_1","lightsaber_death_2","lightsaber_death_3","lightsaber_death_4","lightsaber_death_5","lightsaber_death_6","lightsaber_death_7","flamethrower_burning_6","flamethrower_burning_7"];
		  [_objHit, _rndAnim] remoteExec ["switchMove", 0, true];
	};
    [_objHit] spawn SW_AdditionalDamage;
};
sleep 0.4;
if (!(animationState _droid == "SW_FIGHT_DROID_COMMANDO_FIRING")) exitWith {};
_droid setAmmo [primaryWeapon _droid, 10];
_droid forceWeaponFire [primaryWeapon _droid, "Single"]; 
_objHit = _droid findNearestEnemy _droid;
if ((_objHit getVariable "actualSwordBlock" == 1)) then {
	  if (((_objHit worldToModel (_droid modelToWorld [0, 0, 0])) select 1) < 0) then {
	  	  if ((damage _objHit) > 0.5) exitWith {
		  _objHit removeAllEventHandlers "HandleDamage";
	      _objHit setDamage 1; 
		  [_objHit, "Disable_Gesture"] remoteExec ["playActionNow", _objHit];
	      _rndAnim = selectRandom ["lightsaber_death_1","lightsaber_death_2","lightsaber_death_3","lightsaber_death_4","lightsaber_death_5","lightsaber_death_6","lightsaber_death_7","flamethrower_burning_6","flamethrower_burning_7"];
		  [_objHit, _rndAnim] remoteExec ["switchMove", 0, true];
	      };
	      [_objHit] spawn SW_AdditionalDamage;
	  }else{
	      [_objHit, _droid] spawn otroZeniePolnoje;
	 };
}else{
	if ((damage _objHit) > 0.5) exitWith {
	      _objHit removeAllEventHandlers "HandleDamage";
	      _objHit setDamage 1; 
		  [_objHit, "Disable_Gesture"] remoteExec ["playActionNow", _objHit];
	      _rndAnim = selectRandom ["lightsaber_death_1","lightsaber_death_2","lightsaber_death_3","lightsaber_death_4","lightsaber_death_5","lightsaber_death_6","lightsaber_death_7","flamethrower_burning_6","flamethrower_burning_7"];
		  [_objHit, _rndAnim] remoteExec ["switchMove", 0, true];
	};
    [_objHit] spawn SW_AdditionalDamage;
};
sleep 0.8;
if (!(animationState _droid == "SW_FIGHT_DROID_COMMANDO_FIRING")) exitWith {};
[_droid, "melee_armed_idle"] remoteExec ["switchMove", 0]; 
_droid setVariable ["actualSwordBlock",0, true];
_droid setVariable ["canMakeAttack",0];
_droid setVariable ["AI_CanTurn",0];
};



 



WBK_DroidCommandoDodgeAndDropGrenade = {
_droid = _this;
[_droid, "SW_FIGHT_DROID_COMMANDO_DODGING"] remoteExec ["switchMove", 0]; 
[_droid, "roll_sound", 50, 5] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";  
_droid setVariable ["actualSwordBlock",1, true];
_droid setVariable ["canMakeAttack",1];
_droid setVariable ["AI_CanTurn",1];
_WBK_GrenadeObj = createMine ["BombCluster_02_UXO3_F", position _droid, [], 0];
_WBK_GrenadeObj spawn {
sleep 1;
{
if (!(_x == _this) and (alive _x)) then {
if ((animationState _x == "starWars_landRoll_b") or (animationState _x == "starWars_landRoll")) exitWith {};
[_x, _this] spawn {
_unitToPlay = _this select 0;
_droid = _this select 1;
if (lifeState _unitToPlay == "INCAPACITATED") exitWith {};
_var = _unitToPlay getVariable "IMS_LaF_ShotsToTakeOutOneGuy";
_var = _var - 25;
if (_var <= 0) exitWith {
[_unitToPlay, 0.1, "body", "bullet"] remoteExec ["ace_medical_fnc_addDamageToUnit", _unitToPlay];
[_unitToPlay, true] remoteExec ["ace_medical_fnc_setUnconscious", _unitToPlay];
};
_unitToPlay setVariable ["IMS_LaF_ShotsToTakeOutOneGuy",_var,true];
[_unitToPlay, 228, _droid] remoteExec ["concentrationToZero", _unitToPlay, false];  
}; 
};
} forEach nearestObjects [_this,["MAN"],7];
sleep 0.1;
_this setDamage 1;
};
[_WBK_GrenadeObj, [3 * (sin (getdir _droid )), 3 * (cos (getdir _droid)), 2]] remoteExec ["setvelocity", _WBK_GrenadeObj];
sleep 0.1;
if (!(animationState _droid == "SW_FIGHT_DROID_COMMANDO_DODGING")) exitWith {};
[_droid, selectRandom ["BX_ThrowingGrenade_1","BX_ThrowingGrenade_2","BX_ThrowingGrenade_3"]] spawn BX_SayPhrase;
[_droid, [-12 * (sin (getdir _droid )), -12 * (cos (getdir _droid)), 2]] remoteExec ["setvelocity", _droid];
sleep 0.7;
_droid setVariable ["AI_CanTurn",0];
_droid setVariable ["actualSwordBlock",0, true];
_droid setVariable ["canMakeAttack",0];
sleep 0.2;
if (!(animationState _droid == "SW_FIGHT_DROID_COMMANDO_DODGING")) exitWith {};
[_droid, [-9, -9, 1.5], "starWars_landRoll_b"] remoteExec ["strafeFwrd_SW", _droid];
};



WBK_DroidCommandoDodgeAndHit = {
_droid = _this;
[_droid, "SW_FIGHT_DROID_COMMANDO_DODGING"] remoteExec ["switchMove", 0]; 
[_droid, "roll_sound", 50, 5] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";  
_droid setVariable ["actualSwordBlock",1, true];
_droid setVariable ["canMakeAttack",1];
_droid setVariable ["AI_CanTurn",1];
sleep 0.1;
if (!(animationState _droid == "SW_FIGHT_DROID_COMMANDO_DODGING")) exitWith {};
[_droid, [-12 * (sin (getdir _droid )), -12 * (cos (getdir _droid)), 2]] remoteExec ["setvelocity", _droid];
sleep 0.7;
_droid setVariable ["AI_CanTurn",0];
sleep 0.5;
if (!(animationState _droid == "SW_FIGHT_DROID_COMMANDO_DODGING")) exitWith {};
_arr = parseSimpleArray getText (configFile >> "CfgWeapons" >> handgunWeapon _droid >> "IMS_Melee_Param_Sounds");  
_rndSnd = selectRandom _arr;  
[_droid, _rndSnd, 50, 3] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";  
_droid setVariable ["AI_CanTurn",1];
[_droid,"SW_FIGHT_DROID_COMMANDO_DODGING"] spawn setHitOrDeflect_Around;
[_droid, [6 * (sin (getdir _droid )), 6 * (cos (getdir _droid)), 1.2]] remoteExec ["setvelocity", _droid];
sleep 0.3;
if (!(animationState _droid == "SW_FIGHT_DROID_COMMANDO_DODGING")) exitWith {};
[_droid,"SW_FIGHT_DROID_COMMANDO_DODGING"] spawn setHitOrDeflect_Around;
[_droid, [10 * (sin (getdir _droid )), 10 * (cos (getdir _droid)), 1.2]] remoteExec ["setvelocity", _droid];
sleep 0.2;
if (!(animationState _droid == "SW_FIGHT_DROID_COMMANDO_DODGING")) exitWith {};
_droid setVariable ["AI_CanTurn",0];
[_droid,"SW_FIGHT_DROID_COMMANDO_DODGING"] spawn setHitOrDeflect_Around;
sleep 1.1;
if (!(animationState _droid == "SW_FIGHT_DROID_COMMANDO_DODGING")) exitWith {};
[_droid, "melee_armed_idle"] remoteExec ["switchMove", 0]; 
[_droid, "twoHanded_block"] remoteExec ["playActionNow", _droid];
_droid playMoveNow "melee_armed_runB";
_droid setVariable ["actualSwordBlock",1, true];
_droid setVariable ["canMakeAttack",0];
_droid setVariable ["AI_CanTurn",0];
sleep 0.2;
_droid setVariable ["actualSwordBlock",0, true];
[_droid, "Disable_Gesture"] remoteExec ["playActionNow", _droid];
};




WBK_DroidComPiruet_1 = {
_unitToPlay = _this select 0;
[_unitToPlay, "random_shhh", 50, 3] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";
[_unitToPlay, "starWars_lightsaber_lightattack3"] remoteExec ["switchMove", 0];
_unitToPlay setVariable ["canMakeAttack",1];
sleep 0.25;
if (!(animationState _unitToPlay == "starWars_lightsaber_lightattack3")) exitWith {};
_unitToPlay setVariable ["AI_CanTurn",1];
[_unitToPlay, [9 * (sin (getdir _unitToPlay )), 9 * (cos (getdir _unitToPlay)), 3]] remoteExec ["setvelocity", _unitToPlay];
_arr = parseSimpleArray getText (configFile >> "CfgWeapons" >> handgunWeapon _unitToPlay >> "IMS_Melee_Param_Sounds");  
_rndSnd = selectRandom _arr;  
[_unitToPlay, _rndSnd, 50, 3] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";  
_unitToPlay setVariable ["actualSwordBlock",1, true];
sleep 0.5;
if (!(animationState _unitToPlay == "starWars_lightsaber_lightattack3")) exitWith {};
_unitToPlay setVariable ["actualSwordBlock",0, true];
[_unitToPlay,"starWars_lightsaber_lightattack3"] spawn setHitOrDeflect_TroughtShield;
sleep 0.05;
if (!(animationState _unitToPlay == "starWars_lightsaber_lightattack3")) exitWith {};
[_unitToPlay, "lightSaber_hit_4", 30, 3] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";  
sleep 0.64;
if (!(animationState _unitToPlay == "starWars_lightsaber_lightattack3")) exitWith {};
_unitToPlay setVariable ["canMakeAttack",0];
_unitToPlay setVariable ["AI_CanTurn",0];
if (animationState _unitToPlay == "starWars_lightsaber_lightattack3") then {
[_unitToPlay, "melee_armed_idle"] remoteExec ["playMoveNow", 0];
_unitToPlay setVariable ["canMakeAttack",0, true];
_unitToPlay setVariable ["AI_CanTurn",0];
sleep 0.3;
if (animationState _unitToPlay == "melee_armed_idle") then {
[_unitToPlay, "melee_armed_idle"] remoteExec ["switchMove", 0];
};
};
};


_actFr = [{
    _array = _this select 0;
    _mutant = _array select 0;
	if ((lifeState _mutant == "INCAPACITATED") or (animationState _mutant == "starWars_force_podniati_victim_anim")) exitWith {_mutant allowDamage true;};
    _mutant action ["SwitchWeapon", _mutant, _mutant, 100]; 
	_mutant allowDamage false;
	_mutant disableAI "MINEDETECTION";
	_mutant disableAI "WEAPONAIM";
	_mutant disableAI "SUPPRESSION";
	_mutant disableAI "COVER";
	_mutant disableAI "AIMINGERROR";
	_mutant disableAI "TARGET";
	_mutant disableAI "AUTOCOMBAT";
	_mutant disableAI "FSM";
	_mutant setBehaviour "CARELESS";  
	{ 
	 _ifInter = lineIntersects [ getPosASL _mutant, eyePos _x, _mutant, _x];
		if (!(_ifInter)) then {
			 _mutant reveal [_x, 4]; 
		};
	} forEach nearestObjects [_mutant, ["Man"], 40];  
	_myNearestEnemy = _mutant findNearestEnemy _mutant;
	
	if (_mutant getVariable "canMakeAttack" == 0) then {
	_prm = _mutant getVariable "concentrationParam"; 
	_newprm = _prm + 0.3; 
	if (_newprm >= 0.9) then { 
	_mutant setVariable ["concentrationParam",0.9]; 
	}else{ 
	_mutant setVariable ["concentrationParam",_newprm]; 
	};
	};
	
	if ((animationState _mutant == "starWars_lightsaber_blockPursuit") and ((_myNearestEnemy distance _mutant) <= 5) and (alive _mutant)) exitWith {
	 _mutant spawn selectRandom [WBK_DroidCommandoDodgeAndHit,WBK_DroidCommandoDodgeAndDropGrenade];
	};
	if (!(animationState _mutant == "starWars_lightsaber_lightattack3") and !(animationState _mutant == "starWars_lightsaber_attackLeg") and !(animationState _mutant == "IMS_Leg_Kick") and (animationState _myNearestEnemy == "starWars_lightsaber_blockPursuit") and ((_myNearestEnemy distance _mutant) <= 3) and (alive _mutant)) exitWith {
	 [_myNearestEnemy,_mutant] spawn selectRandom [Human_Execution_Sword,Human_Execution_ChokeOne,Human_Execution_StompOnHead,Human_Execution_OneHanded];
	};
	
	
	
	if ((_mutant getVariable "canMakeAttack" == 0) and ((_myNearestEnemy distance _mutant) <= 4) and (alive _mutant)) then {
    _rndLeg = random 100;
	if ((_myNearestEnemy getVariable "actualSwordBlock" == 1) and (_rndLeg >= 50)) exitWith {[_mutant] spawn selectRandom [legPunch,legPunchVertuha,WBK_DroidComPiruet_1];};
	_rndFire = random 100;
	if ((_rndFire >= 80) and (handGunWeapon _myNearestEnemy in IMS_Lightsabers)) exitWith {_mutant spawn WBK_DroidComFireAtTarget;};
	   
        [_mutant, 3] spawn IMS_MeleeFunction;
	};
}, 0.4, [_unitWithSword]] call CBA_fnc_addPerFrameHandler;



_loopPathfind = [{
    _array = _this select 0;
    _unit = _array select 0;
	if ((lifeState _unit == "INCAPACITATED") or (animationState _unit == "starWars_force_podniati_victim_anim")) exitWith {_mutant allowDamage true;};
	_nearEnemy = _unit findNearestEnemy _unit; 
    if (!(isNull _nearEnemy) and (alive _nearEnemy) and (alive _unit)) then {
	_ifInter = lineIntersectsSurfaces [
		AGLToASL (_nearEnemy modelToWorld [0,0,0.9]), 
		AGLToASL (_unit modelToWorld [0,0,0.9]), 
		_unit,
		_nearEnemy,
		true,
		1,
		"GEOM",
		"NONE"
	];
      if (
      (_unit getVariable "AI_CanTurn" == 0) and 
      (isTouchingGround _unit) and
	  (count _ifInter == 0) and 
	  (_unit distance _nearEnemy < 15) and
	  ((getPosATL _nearEnemy select 2) < 1.45) and 
	  !(lifeState _unit == "INCAPACITATED")
      ) exitWith {
	    _unit disableAI "PATH";
	    _unit disableAI "ANIM";
		doStop _unit;
        [_unit, selectRandom ["melee_SprintF","melee_SprintFl","melee_SprintFr"]] spawn animPush;
        _dir = [[0,1,0], -([_unit, _nearEnemy] call BIS_fnc_dirTo)] call BIS_fnc_rotateVector2D;
        _unit setVelocityTransformation [ 
          getPosASL _unit,  
          getPosASL _unit,  
          [0,0,(velocity _unit select 2) - 1],  
          [(velocity _unit select 0),(velocity _unit select 1),(velocity _unit select 2) - 1], 
          vectorDir _unit,  
          _dir,  
          vectorUp _unit,  
          vectorUp _unit, 
          0.1
        ]; 
      };
	}; 
}, 0.01, [_unitWithSword]] call CBA_fnc_addPerFrameHandler;


_loopPathfindDoMove = [{
    _array = _this select 0;
    _unit = _array select 0;
	_nearEnemy = _unit findNearestEnemy _unit; 
    if (!(isNull _nearEnemy) and (alive _nearEnemy) and (alive _unit)) then {
	_ifInter = lineIntersectsSurfaces [
		AGLToASL (_nearEnemy modelToWorld [0,0,0.9]), 
		AGLToASL (_unit modelToWorld [0,0,0.9]), 
		_unit,
		_nearEnemy,
		true,
		1,
		"GEOM",
		"NONE"
	];
	 if ((_unit distance _nearEnemy > 15) or (!(count _ifInter == 0)) or ((getPosATL _nearEnemy select 2) >= 1.45)) exitWith {
		_unit enableAI "PATH";
	    _unit enableAI "ANIM";
		_unit enableAI "MOVE";
		_unit doMove [getPos _nearEnemy select 0, getPos _nearEnemy select 1, 0];
	 };
	}else{
	    _unit enableAI "PATH";
	    _unit enableAI "ANIM";
		_unit enableAI "MOVE";
	}; 
}, 1.2, [_unitWithSword]] call CBA_fnc_addPerFrameHandler;



_loopIsThereAnyMeleeGuys = [{
_array = _this select 0;
_unit = _array select 0;
_CtnUn = {(!(side _x == side _unit) and (handGunWeapon _x in IMS_Melee_Weapons) and (alive _x) and ((getPosATL _x select 2) < 1.45))} count nearestObjects [_unit, ["man"], 15];
if (_CtnUn == 0) then {
_unit setVariable ["IMS_Droid_SwitchToNormalWeapon",1];
};
}, 0.5, [_unitWithSword]] call CBA_fnc_addPerFrameHandler;
waitUntil {sleep 0.5; 
if (isNull _unitWithSword) exitWith { true };
(!(alive _unitWithSword) or (_unitWithSword getVariable "IMS_Droid_SwitchToNormalWeapon" == 1))
};
[_actFr] call CBA_fnc_removePerFrameHandler;
[_loopPathfind] call CBA_fnc_removePerFrameHandler;
[_loopPathfindDoMove] call CBA_fnc_removePerFrameHandler;
[_loopIsThereAnyMeleeGuys] call CBA_fnc_removePerFrameHandler;
_unitWithSword removeAllEventHandlers "HandleDamage";
if (!(alive _unitWithSword)) exitWith {};
_unitWithSword disableAI "MINEDETECTION";
_unitWithSword disableAI "WEAPONAIM";
_unitWithSword disableAI "SUPPRESSION";
_unitWithSword disableAI "COVER";
_unitWithSword disableAI "AIMINGERROR";
_unitWithSword disableAI "TARGET";
_unitWithSword disableAI "AUTOCOMBAT";
_unitWithSword disableAI "FSM";
_unitWithSword setBehaviour "AWARE"; 
_unitWithSword enableAI "PATH";
_unitWithSword enableAI "ANIM";
_unitWithSword enableAI "MOVE";
_unitWithSword allowDamage false;
[_unitWithSword, selectRandom ["BX_EnemyDown_1","BX_EnemyDown_2","BX_EnemyDown_3","BX_EnemyDown_4"]] spawn BX_SayPhrase;
if (
(animationState _unitWithSword == "Human_Execution_GenericOnehanded_headSmash_1_main") or
(animationState _unitWithSword == "Human_Execution_GenericTwoHanded_headSmash_1_main") or
(animationState _unitWithSword == "Human_Execution_GenericTwoHanded_headSmash_main") or
(animationState _unitWithSword == "Human_Execution_GenericUnconscious_main") or
(animationState _unitWithSword == "Star_Wars_executionOnHuman_1_main") or
(animationState _unitWithSword == "Star_Wars_executionOnHuman_2_main") or
(animationState _unitWithSword == "Human_Execution_GenericHeavy_main") or
(animationState _unitWithSword == "SM_Execution_ChainSaw_main") or
(animationState _unitWithSword == "SM_Fists_Execution_main") or
(animationState _unitWithSword == "SM_Sword_Execution")
) then {
sleep 4;
};
[_unitWithSword, "ims_takeOut_TwoHanded_sheat"] remoteExec ["playActionNow", _unitWithSword];
[_unitWithSword, "ims_takeOut_TwoHanded_sheat"] remoteExec ["playActionNow", _unitWithSword];
[_unitWithSword, "ims_takeOut_TwoHanded_sheat"] remoteExec ["playActionNow", _unitWithSword];
sleep 0.7;
if (!(alive _unitWithSword)) exitWith {};
[_unitWithSword, "generic_out", 20, 6] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";
[_unitWithSword, "AmovPercMstpSrasWrflDnon"] remoteExec ["switchMove", 0];
_unitWithSword execVM "\WebKnightsRobotics\AI\AI_Ims_CommandoDroidAI.sqf";