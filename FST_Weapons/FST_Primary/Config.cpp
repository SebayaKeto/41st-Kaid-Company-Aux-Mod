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
			"FST_DC15A_VersionTwo",
			"FST_DC15C_VersionTwo"
		};
		magazines[]=
		{
		};
		ammo[]=
		{
		};	
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
	class FST_DC15A_VersionTwo: Rifle_Base_F
	{
		author = "Maldova";
		scope = 2;
		displayName = "[41st] DC-15A Blaster Rifle";
		descriptionShort = "DC-15A Blaster Rifle";
		model = "\FST\FST_Weapons\FST_Primary\DC15A.p3d";
		picture = "FST\FST_Weapons\FST_Primary\Icons\DC15AIcon.paa";
		baseWeapon = "FST_DC15A_VersionTwo";
		magazineWell[] = {"FST_DC15AMagwell"};
		modes[] = {"Single","FullAuto"};
		class FullAuto: Mode_FullAuto
		{
			reloadTime = 0.2;
			dispersion = 0.00066;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 15;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
			soundContinuous = 0;
			soundBurst = 0;
			sounds[] = {"StandardSound"};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[] = {"FST_DC15Soundset_Shot"};
			};
		};
		class Single: Mode_SemiAuto
		{
			reloadTime = 0.05;
			dispersion = 0.00066;
			minRange = 2;
			minRangeProbab = 0.5;
			midRange = 200;
			midRangeProbab = 0.7;
			maxRange = 400;
			maxRangeProbab = 0.3;
			soundContinuous = 0;
			soundBurst = 0;
			sounds[] = {"StandardSound"};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[] = {"FST_DC15Soundset_Shot"};
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 80;
			class MuzzleSlot: MuzzleSlot
			{
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[] = {};
				iconPosition[] = {0,0.45};
				iconScale = 0.2;
			};
			class CowsSlot: CowsSlot
			{
				linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[] = 
				{
					"3AS_Optic_Red_DC15A",
					"3AS_Optic_LEScope_DC15A"
				};
			};
			class PointerSlot: PointerSlot
			{
				linkProxy = "\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[] = {};
			};
		};
	};
	class FST_DC15C_VersionTwo: Rifle_Base_F
	{
		author = "Maldova";
		scope = 2;
		displayName = "[41st] DC-15C Blaster Rifle";
		descriptionShort = "DC-15C Blaster Rifle";
		model = "\FST\FST_Weapons\FST_Primary\DC15C.p3d";
		picture = "FST\FST_Weapons\FST_Primary\Icons\DC15CIcon.paa";
		baseWeapon = "FST_DC15C_VersionTwo";
		magazineWell[] = {"FST_DC15AMagwell"};
		modes[] = {"Single","FullAuto"};
		class FullAuto: Mode_FullAuto
		{
			reloadTime = 0.2;
			dispersion = 0.00066;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 15;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
			soundContinuous = 0;
			soundBurst = 0;
			sounds[] = {"StandardSound"};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[] = {"FST_DC15Soundset_Shot"};
			};
		};
		class Single: Mode_SemiAuto
		{
			reloadTime = 0.05;
			dispersion = 0.00066;
			minRange = 2;
			minRangeProbab = 0.5;
			midRange = 200;
			midRangeProbab = 0.7;
			maxRange = 400;
			maxRangeProbab = 0.3;
			soundContinuous = 0;
			soundBurst = 0;
			sounds[] = {"StandardSound"};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[] = {"FST_DC15Soundset_Shot"};
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 80;
			class CowsSlot: CowsSlot
			{
				linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[] = 
				{
					"3AS_Optic_Red_DC15A",
					"3AS_Optic_LEScope_DC15A"
				};
			};
		};
	};
};