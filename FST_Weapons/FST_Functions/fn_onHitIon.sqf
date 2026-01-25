/*
 * Author: Maldova
 * 
 *
 * Arguments:
 * 0: Unit 
 * 1: Unit 
 * 2: Ammo 
 *
 * Example:
 * [Target,Shooter,"FST_DX11"] call FST_Weapon_fnc_onHitIon;
 *
 * Return Value:
 * None
 *
 */

params ["_target","_shooter", "_ammo"];

if (getNumber(configFile >> "CfgWeapons" >> Uniform _target >> "FST_isBX") == 1) exitWith {false;};

private _targetPos = getPos _target;

if (getNumber(configFile >> "CfgWeapons" >> Uniform _target >> "JLTS_isDroid") == 0) then
{
	playSound3D 
	[
		selectRandom
		[
			"FST\FST_Weapons\FST_Sounds\General\HumanInjuredGroan-01.ogg",
			"FST\FST_Weapons\FST_Sounds\General\HumanInjuredGroan-02.ogg",
			"FST\FST_Weapons\FST_Sounds\General\HumanInjuredGroan-03.ogg",
			"FST\FST_Weapons\FST_Sounds\General\HumanInjuredGroan-04.ogg",
			"FST\FST_Weapons\FST_Sounds\General\HumanInjuredGroan-05.ogg",
			"FST\FST_Weapons\FST_Sounds\General\HumanInjuredGroan-06.ogg"
		],
		_target,
		false,
		_targetPos,
		5, 0.7, 50
	];	
};
if (getNumber(configFile >> "CfgWeapons" >> Uniform _target >> "JLTS_isDroid") == 1 || getNumber(configFile >> "CfgWeapons" >> Uniform _target >> "FST_isB1") == 1 || getNumber(configFile >> "CfgWeapons" >> Uniform _target >> "FST_isB2") == 1 || getNumber(configFile >> "CfgWeapons" >> Uniform _target >> "FST_isTSeries") == 1) then
{
	playSound3D 
	[
		selectRandom
		[
			"FST\FST_Weapons\FST_Sounds\General\B1BattleDroid_NonLethal_Injured-01.ogg",
			"FST\FST_Weapons\FST_Sounds\General\B1BattleDroid_NonLethal_Injured-02.ogg",
			"FST\FST_Weapons\FST_Sounds\General\B1BattleDroid_NonLethal_Injured-03.ogg",
			"FST\FST_Weapons\FST_Sounds\General\B1BattleDroid_NonLethal_Injured-04.ogg"
		],
		_target,
		false,
		_targetPos,
		5, 0.7, 50
	];	
	_target setDamage 1;
};

