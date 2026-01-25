#include "basicdefines_FST.hpp"

class CfgPatches
{
	class FST_Weapons_Primary
	{
		author = "Maldova";
		requiredAddons[]=
		{
			"A3_Weapons_F"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_DC15A"
		};
		magazines[]=
		{
			"FST_DC15A_Mag"
		};
		ammo[]=
		{
			"FST_DC15A_Energy_Ammo"
		};	
	};
};
class CfgAmmo
{
	class BulletBase;
	class B_65x39_Caseless: BulletBase {};
	
	class FST_DC15A_Energy_Ammo: B_65x39_Caseless
	{
		hit = 12;
		typicalSpeed = 920;
		supersonicCrackNear[] = {};
		supersonicCrackFar[] = {};
		visibleFire = 3;
		audibleFire = 5;
	};
};
class CfgMagazines
{
	class 30Rnd_65x39_caseless_mag;
	
	class FST_DC15A_Mag: 30Rnd_65x39_caseless_mag
	{
		author = "Maldova";
		scope = Public;
		displayName = "[41st] DC-15A Energy Cell";
		displayNameShort = "High Energy";
		descriptionShort = "DC-15A Energy Cell";
		picture = "\A3\Weapons_F\Data\UI\M_30stanag_CA.paa";
		ammo = "FST_DC15A_Energy_Ammo";
		count = 60;
		mass = 8;
		initSpeed = 920;
		tracersEvery = 1;
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class SlotInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class CfgWeapons
{
	class Rifle;
	class Rifle_Base_F: Rifle
	{
		class WeaponSlotsInfo;
		class GunParticles;
	};
	class FST_DC15A: Rifle_Base_F
	{
		author = "Maldova";
		scope = Public;
		displayName = "[41st] DC-15A Blaster Rifle";
		descriptionShort = "DC-15A Blaster Rifle";
		model = "\FST\FST_Weapons\FST_Primary\DC15A .p3d";
		//picture = "\A3\Weapons_F\Rifles\MX\Data\UI\gear_mx_rifle_ca.paa";
		baseWeapon = "FST_DC15A";
		
		magazines[] = {"FST_DC15A_Mag"};
		magazineWell[] = {};
		
		modes[] = {"Single","FullAuto"};
		
		class Single: Mode_SemiAuto
		{
			reloadTime = 0.08;
			dispersion = 0.00087;
			minRange = 2;
			minRangeProbab = 0.5;
			midRange = 200;
			midRangeProbab = 0.7;
			maxRange = 400;
			maxRangeProbab = 0.3;
		};
		
		class FullAuto: Mode_FullAuto
		{
			reloadTime = 0.08;
			dispersion = 0.00087;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 15;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
			aiRateOfFire = 1e-006;
		};
		
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 80;
		};
	};
};