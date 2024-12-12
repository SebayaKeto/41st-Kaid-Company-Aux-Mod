class CfgPatches
{
	class FST_DC15AS
	{
		requiredAddons[]=
		{
			"3AS_Weapons"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_DLT15",
		};
	};
};
class CfgRecoils
{
	class recoil_default;
	class FST_recoil_DLT15: recoil_default
	{
		muzzleOuter[] = {0.5, 1.6, 0.6, 0.6};
		kickBack[] = {0.05, 0.07};
		temporary = 0.004;
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
	class JLTS_stun_muzzle;
	class Rifle_Base_F
	{
		class WeaponSlotsInfo;
		class GunParticles;
	};
	class UGL_F;
	class arifle_MX_Base_F: Rifle_Base_F
	{
		class GunParticles;
		class GunClouds;
		class WeaponSlotsInfo;
	};
	class FST_DLT15: arifle_MX_Base_F
	{
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		author="Adapted from the Indecisive Armoury Team";
		scope=0;
		scopecurator=0;
		scopearsenal=0;
		inertia=0;
		canShootInWater=1;
		baseWeapon="FST_DLT15";
		displayName="[41st] DLT-15 Light repeating blaster";
		descriptionShort="A large and fast automatic rifle.";
		picture="Indecisive_Armoury_Weapons_REPUBLIC\Data\DLT15\DLT15_ui.paa";
		model="Indecisive_Armoury_Weapons_REPUBLIC\Data\DLT15\Model\IDA_DLT15.p3d";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"Indecisive_Armoury_Anims\Republic\DLT15.rtm"
		};
		ace_clearJamAction="";
		reloadAction="GestureReloadM200";
		reloadMagazineSound[]=
		{
			"\Indecisive_Armoury_Sounds\blaster_reload_1.ogg",
			1.5,
			1,
			100
		};
		recoil="FST_recoil_DLT15";
		magazines[]=
		{
			"FST_blaster_battery"
		};
		magazineWell[]={};
		modes[]=
		{
			"FullAuto"
		};
		fireLightDiffuse[]={0.1,0.25,1};
		drySound[]=
		{
			"\Indecisive_Armoury_Sounds\weapon_dry.ogg",
			5,
			1,
			10
		};
		muzzles[]=
		{
			"this"
		};
		class FullAuto: Mode_FullAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect="";
				begin1[]=
				{
					"\41st_Weapons\DLT15\Data\1DLT_2_172.ogg",
					1.25,
					1,
					1800
				};
				begin2[]=
				{
					"41st_Weapons\DLT15\Data\2DLT_2_172.ogg",
					1.25,
					1.015,
					1800
				};
				begin3[]=
				{
					"41st_Weapons\DLT15\Data\3DLT_2_172.ogg",
					1.25,
					0.98500001,
					1800
				};
				begin4[]=
				{
					"\41st_Weapons\DLT15\Data\1DLT_2_172.ogg",
					1.25,
					1.01,
					1800
				};
				begin5[]=
				{
					"41st_Weapons\DLT15\Data\2DLT_2_172.ogg",
					1.25,
					0.995,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					0.2,
					"begin2",
					0.2,
					"begin3",
					0.2,
					"begin4",
					0.2,
					"begin5",
					0.2
				};
				beginwater1[]=
				{
					"41st_Weapons\DLT15\Data\2DLT_2_172.ogg",
					1,
					1,
					400
				};
				soundBeginWater[]=
				{
					"beginwater1",
					1
				};
			};
			reloadTime=0.054545455;
			dispersion=0.0014;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=60;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]={};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]={};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[]=
				{
					"acc_flashlight"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]=
				{
					"3AS_Bipod_VK38X_f"
				};
			};
		};
		class GunParticles
		{
			class FirstEffect
			{
				directionName="Konec hlavne";
				effectName="RifleAssaultCloud";
				positionName="Usti hlavne";
			};
		};
	};
};
