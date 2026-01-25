/*
 * Author: Maldova
 *
 *
 * Arguments:
 * Inherited from FST_Weapons_fnc_onHit
 *
 * Example:
 * call FST_Weapon_fnc_onHit;
 *
 * Return Value:
 * None
 *
 */

params["_target", "_shooter", "_projectile", "_position", "_velocity", "_selection", "_ammo", "_vector", "_radius", "_surfaceType", "_isDirect"];

#define REGULAR 1
#define STUN 2
#define CONCUSSION 3
#define INCENDIARY 5
#define DISINTEGRATION 6
#define ION 7

private _ammoUsed = _ammo select 4;

private _ammoType = getNumber(configFile >> "CfgAmmo" >> _ammoUsed >> "FST_AmmoType");

if (isNil{_ammo select 4}) exitWith {};

switch(_ammoType) do 
{
	case STUN: 
    {
		[_target,_shooter,_ammoUsed] call FST_Weapon_fnc_onHitStun
	};
    case CONCUSSION:
    {
        [_target,_shooter,_ammoUsed] call FST_Weapon_fnc_onHitConcussion
    };
    case ION:
    {
        [_target,_shooter,_ammoUsed] call FST_Weapon_fnc_onHitIon
    };
    case INCENDIARY:
    {
        [_target,_shooter,_ammoUsed] call FST_Weapon_fnc_onHitIncendiary
    };
    case DISINTEGRATION:
    {
        [_target,_shooter,_ammoUsed] call FST_Weapon_fnc_onHitDisintegration
    };
};