// PERF PASS 2026-09-20 (41st): behavior preserved, cost reduced.
// - switchMove has global effect; the remoteExec-to-all copies (one message per
//   connected client per droid hit/death) are replaced with the direct command.
// - nearestObjects -> nearEntities for the "Man" scans (entity list, not the
//   full object tree).
// - setAmmo / allowDamage / disableAI are only re-issued when their state has
//   actually drifted instead of every tick.
// - The per-frame handlers remove themselves when the droid dies or is deleted,
//   so the per-droid "waitUntil {sleep 0.5}" watchdog thread is gone.
_unitWithSword = _this;
if (isPlayer _unitWithSword) exitWith {
_unitWithSword setVariable ["disableUnitSFX",1,true];
_unitWithSword removeAllEventHandlers "Killed";
_unitWithSword addEventHandler ["Killed", {
_unitWithSword = _this select 0;
[_unitWithSword, selectRandom ["B1_DeathSound_1","B1_DeathSound_2","B1_DeathSound_3","B1_DeathSound_4","B1_DeathSound_5","B1_DeathSound_6","B1_DeathSound_7","B1_DeathSound_8"], 90, 10] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";
_rndANim = selectRandom ["B1_Droid_die_1","B1_Droid_die_2","B1_Droid_die_3"];
_unitWithSword switchMove _rndANim;
_unitWithSword playActionNow "Disable_Gesture";
if (_rndANim == "B1_Droid_die_2") exitWith {
_unitWithSword setAnimSpeedCoef 0.8;
};
if (_rndANim == "B1_Droid_die_3") exitWith {
_unitWithSword setAnimSpeedCoef 0.5;
};
}];
};




_unitWithSword disableAI "MINEDETECTION";
_unitWithSword disableAI "SUPPRESSION";
_unitWithSword disableAI "COVER";
_unitWithSword disableAI "AIMINGERROR";
_unitWithSword allowFleeing 0;
_unitWithSword setSpeaker "NoVoice";
_unitWithSword setSkill 0.3;
_unitWithSword setVariable ["disableUnitSFX",1,true];
_unitWithSword removeAllEventHandlers "Killed";
if (isNil {_unitWithSword getVariable "Droid_Health"}) then {
_unitWithSword setVariable ["Droid_Health",WBK_B1_AmountOfDamage,true];
};


_unitWithSword addEventHandler ["Killed", {
_unitWithSword = _this select 0;
[_unitWithSword, selectRandom ["B1_DeathSound_1","B1_DeathSound_2","B1_DeathSound_3","B1_DeathSound_4","B1_DeathSound_5","B1_DeathSound_6","B1_DeathSound_7","B1_DeathSound_8"], 90, 10] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";
_rndANim = selectRandom ["B1_Droid_die_1","B1_Droid_die_2","B1_Droid_die_3"];
_unitWithSword switchMove _rndANim;
_unitWithSword playActionNow "Disable_Gesture";
if (_rndANim == "B1_Droid_die_2") exitWith {
_unitWithSword setAnimSpeedCoef 0.8;
};
if (_rndANim == "B1_Droid_die_3") exitWith {
_unitWithSword setAnimSpeedCoef 0.5;
};}];



[_unitWithSword, "HandleDamage", {
  _objHit = _this select 0;
  if ((animationState _objHit == "B1_Droid_execution_main")) exitWith {};
  _hitter = _this select 3;
  _objHit reveal _hitter;
  if (!(side _hitter == side _objHit)) then {
  _objHit doMove (getPos _hitter);
  };
  if (!(_objHit == _hitter) and (alive _objHit)) then {
	if (_objHit getVariable 'Droid_Health' <= 0) exitWith {
	_objHit removeAllEventHandlers "HandleDamage";
	_objHit setDamage 1;
	};
if (isNil {_objHit getVariable "B1Speak"}) then {
_objHit spawn {
_this setVariable ["B1Speak",1];
[_this, selectRandom ["B1_hit_1","B1_hit_2","B1_hit_3","B1_hit_4","B1_hit_5","B1_hit_6"], 90] call CBA_fnc_globalSay3d;
sleep 10;
_this setVariable ["B1Speak",nil];
};
};
    _health = _objHit getVariable "Droid_Health";
	_health = _health - 1;
    _objHit setVariable ["Droid_Health",_health,true];
	_rndHitAnim = random 100;
	if ((_rndHitAnim >= 50) and !(animationState _objHit == "B1_Droid_hit_1") and !(animationState _objHit == "B1_Droid_hit_2") and !(animationState _objHit == "B1_Droid_execution_main")) then {
	_objHit spawn {
	_this disableAI "ALL";
	_this playActionNow "Disable_Gesture";
	_rndAnim = selectRandom ["B1_Droid_hit_1","B1_Droid_hit_2"];
	_this switchMove _rndAnim;
	sleep 1.18;
	if (!(animationState _this == _rndAnim)) exitWith {_this enableAI "ALL";};
	_this playActionNow "B1_GunHolding";
	_this switchMove "AmovPercMstpSrasWrflDnon";
	_this enableAI "ALL";
	};
	};
  };
}] call WBK_fnc_addAIEH;











[_unitWithSword, "Fired", {
_unitWithSword = _this select 0;
if (isNil {_unitWithSword getVariable "B1Speak"}) then {
_unitWithSword spawn {
_this setVariable ["B1Speak",1];
[_this, selectRandom ["B1_shooting_1","B1_shooting_2","B1_shooting_3","B1_shooting_4"], 60] call CBA_fnc_globalSay3d;
sleep (random 10);
_this setVariable ["B1Speak",nil];
};
};
}] call WBK_fnc_addAIEH;
_unitWithSword setUnitPos "UP";





WBK_B1_Melee = {
_unitToPlay = _this select 0;
_victim = _this select 1;
_unitToPlay disableAI "ALL";
_unitToPlay switchMove "B1_Droid_execution_main";
_victim switchMove "B1_Droid_execution_victim";
_unitToPlay playActionNow "Disable_Gesture";
[_victim, "Disable_Gesture"] remoteExec ["playActionNow", _victim];
_victim setDamage 1;
_victim attachTo [_unitToPlay,[0,1.4,0]];
[_victim, 180] remoteExec ["setDir", _victim];
sleep 0.1;
[_victim, selectRandom ["melee_swing_equipment_1","melee_swing_equipment_2"], 50, 3] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";
sleep 0.1;
[_victim, "dobi_bones", 50, 3] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";
sleep 0.8;
_rndPashalka = random 100;
if (_rndPashalka <= 15) then {
[_victim, "B1_execution_cloneSnd_easterEgg", 30, 5] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";
}else{
[_victim, "B1_execution_cloneSnd", 30, 5] execVM "\WebKnight_StarWars_Mechanic\createSoundGlobal.sqf";
};
sleep 1;
_unitToPlay forceWeaponFire [weaponState _unitToPlay select 1, weaponState _unitToPlay select 2];
detach _victim;
sleep 0.5;
[_unitToPlay, selectRandom ["B1_EnemyKilled_1","B1_EnemyKilled_2"], 60] call CBA_fnc_globalSay3d;
_unitToPlay playActionNow "B1_GunHolding";
sleep 0.2;
if (!(animationState _unitToPlay == "B1_Droid_execution_main")) exitWith {_unitToPlay enableAI "ALL";};
_unitToPlay playActionNow "B1_GunHolding";
_unitToPlay switchMove "AmovPercMstpSrasWrflDnon";
_unitToPlay enableAI "ALL";
};





_actFrMelee = [{
    _array = _this select 0;
    _mutant = _array select 0;
	if (isNull _mutant || {!alive _mutant} || {!local _mutant}) exitWith { [_this select 1] call CBA_fnc_removePerFrameHandler; };
	{
	 _ifInter = lineIntersects [ getPosASL _mutant, eyePos _x, _mutant, _x];
		if (!(_ifInter)) then {
			 _mutant reveal [_x, 4];
		};
	} forEach (_mutant nearEntities ["Man", 5]);
	_myNearestEnemy = _mutant findNearestEnemy _mutant;
	if ((currentWeapon _myNearestEnemy == "") and !(handGunWeapon _myNearestEnemy in IMS_Melee_Weapons) and (((_mutant worldToModel (_myNearestEnemy modelToWorld [0, 0, 0])) select 1) > 0) and ((_myNearestEnemy distance _mutant) <= 2.1) and (_mutant getVariable "canMakeAttack" == 0) and (alive _mutant) and !(lifeState _mutant == "INCAPACITATED") and !(animationState _mutant == "B1_Droid_execution_main")) then {
	[_mutant, _myNearestEnemy] spawn WBK_B1_Melee;
	};
}, 0.4, [_unitWithSword]] call CBA_fnc_addPerFrameHandler;


_actFr = [{
    _array = _this select 0;
    _mutant = _array select 0;
	if (isNull _mutant || {!alive _mutant} || {!local _mutant}) exitWith { [_this select 1] call CBA_fnc_removePerFrameHandler; };
	// setAmmo broadcasts; only top up when the magazine actually dropped.
	if ((_mutant ammo (currentWeapon _mutant)) < 10) then { _mutant setAmmo [currentWeapon _mutant, 10]; };
	if (isDamageAllowed _mutant) then { _mutant allowDamage false; };
_g = count (_mutant nearObjects ["GrenadeHand", 4]);
if ((_g >= 1)) then {
[_mutant, selectRandom ["B1_incGrenade_1","B1_incGrenade_2","B1_incGrenade_3","B1_incGrenade_4"], 60] call CBA_fnc_globalSay3d;
};


	if ((_mutant getVariable "canMakeAttack" == 0) and (alive _mutant) and !(lifeState _mutant == "INCAPACITATED") and !(animationState _mutant == "B1_Droid_hit_1") and !(animationState _mutant == "B1_Droid_hit_2") and !(animationState _mutant == "B1_Droid_execution_main")) then {
	_mutant playActionNow "B1_GunHolding";
	}else{
	_mutant playActionNow "Disable_Gesture";
	};
}, 2, [_unitWithSword]] call CBA_fnc_addPerFrameHandler;



_loopPathfind = [{
    _array = _this select 0;
    _unit = _array select 0;
	if (isNull _unit || {!alive _unit} || {!local _unit}) exitWith { [_this select 1] call CBA_fnc_removePerFrameHandler; };
	_nearEnemy = _unit findNearestEnemy _unit;
    if (!(isNull _nearEnemy) and (alive _unit)) then {
    _unit doMove (getPos _nearEnemy);
	};
}, 10, [_unitWithSword]] call CBA_fnc_addPerFrameHandler;









// Per-frame handlers above remove themselves on death/deletion or loss of locality; no polling thread needed.
// LOCALITY (41st): stop on this machine once the unit is owned elsewhere; AI_localityHook restarts the script on the new owner.