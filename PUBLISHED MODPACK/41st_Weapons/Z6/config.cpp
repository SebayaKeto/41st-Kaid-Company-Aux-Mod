class CfgPatches
{
	class FST_Weapons_DC15L
	{
		requiredAddons[]=
		{
			"3AS_Weapons"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_Z6",
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
class CfgMagazines
{
	class 100Rnd_65x39_caseless_mag;
	class FST_blaster_battery: 100Rnd_65x39_caseless_mag
	{
		author="Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\z6\data\ui\z6_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\z6\z6_mag.p3d";
		count=300;
		displayName="[41st] High-Power Energy Battery";
		displayNameShort="HP Energy Battery";
		descriptionShort="300 round capacity.";
		ammo="FST_blasterbolt_high";
		tracersEvery=1;
		initSpeed=250;
		mass=35;
	};
	class FST_blaster_battery_Red: FST_blaster_battery
	{
		author="Indecisive Armoury Team";
		picture="\MRC\JLTS\weapons\z6\data\ui\z6_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\z6\z6_mag.p3d";
		displayName="[41st] Low-Power Energy Battery (Red)";
		ammo="FST_blasterbolt_Red";
	};
};
class CfgWeapons
{
	class Rifle_Base_F;
	class arifle_MX_Base_F: Rifle_Base_F
	{
		class GunParticles;
		class GunClouds;
		class WeaponSlotsInfo;
	};
	class FST_Z6: arifle_MX_Base_F
	{
		WBK_UseHeavyWeaponFramework = true;
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		ace_overheating_jamTypesAllowed[]=
		{
			"Fire",
			"Dud"
		};
		author="Adapted From the Indecisive Armoury Team";
		inertia=0;
		canShootInWater=1;
		scope=2;
		autoReload="true";
		baseWeapon="FST_Z6";
		displayName="[41st] Z-6 rotary cannon";
		displayNameShort="Z-6 rotary cannon";
		descriptionShort="Rapid Fire. Reloads automatically.";
		picture="\MRC\JLTS\weapons\Z6\data\ui\Z6_ui_ca.paa";
		model="\MRC\JLTS\weapons\Z6\Z6.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"camo3"
		};
		hiddenSelectionsTextures[]=
		{
			"Indecisive_Armoury_Weapons_REPUBLIC\Data\Z6_co.paa",
			"Indecisive_Armoury_Weapons_REPUBLIC\Data\Z6_Barrel_co.paa",
			"Indecisive_Armoury_Weapons_REPUBLIC\Data\Z6_Mag_co.paa"
		};
		magazines[]=
		{
			"FST_blaster_battery",
		};
		recoil="FST_recoil_Z6";
		maxZeroing=1200;
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\MRC\JLTS\weapons\Z6\anims\Z6_handanim.rtm"
		};
		reloadAction="";
		ace_clearJamAction="";
		magazineWell[]={};
		fireLightDiffuse[]={0,0,1};
		drySound[]=
		{
			"\Indecisive_Armoury_Sounds\weapon_dry.ogg",
			5,
			1,
			10
		};
		reloadMagazineSound[]=
		{
			"\Indecisive_Armoury_Sounds\Republic\Z-6\Z6_reload.ogg",
			1.5,
			1,
			100
		};
		muzzles[]=
		{
			"this"
		};
		modes[]=
		{
			"Auto"
		};
		class Auto: Mode_FullAuto
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
					"\41st_weapons\Z6\Data\z6 -3-965 (1).ogg",
					1.5,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_weapons\Z6\Data\z6 -3-965 (2).ogg",
					1.5,
					1.015,
					1800
				};
				begin3[]=
				{
					"\41st_weapons\Z6\Data\z6 -3-965 (3).ogg",
					1.5,
					0.98500001,
					1800
				};
				begin4[]=
				{
					"\41st_weapons\Z6\Data\z6 -3-965 (4).ogg",
					1.5,
					1.01,
					1800
				};
				begin5[]=
				{
					"\41st_weapons\Z6\Data\z6 -3-965 (5).ogg",
					1.5,
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
					"\41st_weapons\Z6\Data\z6 -3-965.ogg",
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
			reloadTime=0.059999999;
			magazines[]=
			{
				"FST_blaster_battery",
			};
			dispersion=0.003;
			burst=1;
			soundContinuous="false";
			soundBurst="true";
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.075000003;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		aiDispersionCoefY=24;
		aiDispersionCoefX=21;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=100;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]=
				{
					"3AS_optic_holo_DC15S"
				};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]={};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[]={};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]={};
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
