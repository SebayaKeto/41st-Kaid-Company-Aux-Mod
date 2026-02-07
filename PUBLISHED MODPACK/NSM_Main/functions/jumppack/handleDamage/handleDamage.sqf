#include "\nsm_Main\_include\macros.hpp"
params ["_unit", "_selection", "_damage", "_shooter", "_ammo", "_hitPointIndex", "_instigator", "_hitpoint", "_directHit", "_context"];
				
//if we are not killable, because we are jumping, do a dice roll to see if we should take damage.
if(
	!(_unit getVariable["ace_medical_allowDamage",true]) &&
	(_unit getVariable["NSM_jumppack_isJumping",false]) &&
	{!(_ammo isEqualTo "")}
) then {
	//Get the chance of taking damage based off the backpack
	_backpackType = backpack _unit;
	_dmgData = NSM_JUMPPACK_DAMAGE_MAP getOrDefault 
	[
		_backpackType, 
		[NSM_JUMPPACK_DAMAGE_DEFAULT_CHANCE,NSM_JUMPPACK_DAMAGE_DEFAULT_DAMAGE], 
		true
	];

	_dmgData params [["_chance",NSM_JUMPPACK_DAMAGE_DEFAULT_CHANCE],["_dmgMul",NSM_JUMPPACK_DAMAGE_DEFAULT_DAMAGE]];
	_diceRoll = (random 100);

	//no damage
	//_chance is the % chance to take damage. so say _chance = 30 = 30%, I would dice roll to be less then 30 to take damage (out of 100).
	if(_diceRoll > _chance) exitWith {
		if(NSM_COMMON_RPT_DEBUG) then {
			diag_log format ["T:%1 (%2 < %3) no damage",time,_diceRoll,_chance];
		};
		0
	};

	//from here on take damage
	if(NSM_COMMON_RPT_DEBUG) then {
		diag_log format ["T:%1 (%2 > %3) taking: %4 percent dmg equaling to %5: %6",time,_diceRoll,_chance,_dmgMul*100,_damage*_dmgMul,_this];
		diag_log format["T:%1,args to NSM_jumppack_fnc_ace_handle_damage: %2",time,[_unit, _selection, _damage*_dmgMul, _shooter, _ammo, _hitPointIndex, _instigator, _hitpoint,_directHit,_context]];
	};
	//pass to our custom ace dmg func that ignores ace_allow_damage
	[_unit, _selection, _damage*_dmgMul, _shooter, _ammo, _hitPointIndex, _instigator, _hitpoint,_directHit,_context] call NSM_jumppack_fnc_ace_handle_damage
} else {
	//Let ace handle from here
	// _this call ace_medical_engine_fnc_handleDamage;
	// 0
};