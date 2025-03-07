class CfgPatches
{
	class FST_B54_ShielBreaker
	{
		author="Inspired from JMax";
		requiRedVersion=0.1;
		requiRedAddons[]=
		{
			"A3_Data_F",
			"A3_Weapons_F",
			"JMSLLTE_weapons"
		};
		units[]={};
		weapons[]=
		{
			"FST_B54_ShielBreaker"
		};
	};
};
class Mode_Burst;
class Mode_SemiAuto;
class SlotInfo;
class CowsSlot;
class MuzzleSlot;
class CfgWeapons
{
	class ItemCore;
	class InventoryItem_Base_F;
	class InventoryOpticsItem_Base_F;
	class Pistol_Base_F;
	class JMSLLTE_BlasterPistol_Base: Pistol_Base_F
	{
		class WeaponSlotsInfo
		{
			class SlotInfo;
		};
	};
	class FST_B54_ShielBreaker: JMSLLTE_BlasterPistol_Base
	{
		author="Gold";
		displayname="B54-Shieldbreaker Pistol";
		scope=2;
		model="\JMSLLTE_weapons\bryar\bryarpistol.p3d";
		picture="\JMSLLTE_weapons\bryar\ico_bryar.paa";
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		inertia=0;
		canShootInWater=1;
		magazines[]=
		{
			"FST_blaster_cell_B54_Blue",
			"FST_blaster_cell_B54_Green",
			"FST_blaster_cell_B54_Yellow",
			"FST_blaster_cell_B54_Red"
		};
		reloadAction="GestureReloadPistol";
		drySound[]=
		{
			"JMSLLTE_weapons\sounds\overheat_met_2.ogg",
			5,//1
			1,//1
			10//20
		};
		reloadMagazineSound[]=
		{
			"JMSLLTE_weapons\sounds\reload.wss",
			0.56234133,
			1,
			30
		};
		selectionFireAnim="muzzleFlash";
		soundBullet[]={};
		modes[]=
		{
			"Single"
		};
		fireLightDuration=0.0049999999;
		fireLightIntensity=0.0049999999;
		fireLightDiffuse[]={0.1,0,0.0024999999};
		fireLightAmbient[]={0,0,0};
		class Single: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"JMSLLTE_K16_Shot_SoundSet",
					"SDAR_Tail_SoundSet",
					"SDAR_InteriorTail_SoundSet"
				};
			};
			recoil="recoil_pistol_heavy";
			recoilProne="recoil_prone_pistol_heavy";
			reloadTime=0.15000001;
			dispersion=0			// was originally 0.0011;
			minRange=1;
			minRangeProbab=0.30000001;
			midRange=35;
			midRangeProbab=0.60000002;
			maxRange=70;
			maxRangeProbab=0.1;
			aiRateOfFire=2;
			aiRateOfFireDistance=25;
		};
		recoil="recoil_pistol_4five";
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: CowsSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				displayName="Optics Slot";
				compatibleItems[]={};
			};
			class MuzzleSlot: SlotInfo
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]={};
			};
		};
		class ItemInfo
		{
			priority=2;
		};
	};
};
class CfgSoundSets
{
	class Pistol_Shot_Base_SoundSet;
	class JMSLLTE_K16_Shot_SoundSet: Pistol_Shot_Base_SoundSet
	{
		soundShaders[]=
		{
			"JMSLLTE_rifle_Closure_SoundShader",
			"JMSLLTE_K16_closeShot_SoundShader",
			"JMSLLTE_K16_closeShot_SoundShader",
			"JMSLLTE_rifle_distShot_SoundShader"
		};
	};
};	
class CfgSoundShaders
{	
	class JMSLLTE_K16_closeShot_SoundShader
	{
		samples[]=
		{
			
			{
				"\JMSLLTE_weapons\Sounds\Pistols\k16_fire.ogg",
				1
			},
			
			{
				"\JMSLLTE_weapons\Sounds\Pistols\k16_fire.ogg",
				1
			},
			
			{
				"\JMSLLTE_weapons\Sounds\Pistols\k16_fire.ogg",
				1
			}
		};
		volume=0.5;
		range=60;
		rangeCurve="closeShotCurve";
	};
};	
