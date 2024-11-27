class CfgPatches
{
	class FST_Weapons_Valken
	{
		requiredAddons[]=
		{
			"3AS_Weapons"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_DP23",
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
class CfgAmmo
{
	class IDA_blasterbolt;
	class FST_blasterbolt_scatter: IDA_blasterbolt
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		hit=25;
		submunitionAmmo="FST_blasterbolt";
		submunitionConeType[]=
		{
			"random",
			6
		};
		submunitionConeAngle=0.34999999;
		triggerTime=9.9999997e-010;
	};
};
class CfgMagazines
{
	class 100Rnd_65x39_caseless_mag;
	class FST_blaster_scatter_cell: 100Rnd_65x39_caseless_mag
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count=8;
		displayName="[41st] High-Power Scatter Cell";
		displayNameShort="HP Scatter Cell";
		descriptionShort="8 round capacity";
		ammo="FST_blasterbolt_scatter";
		tracersEvery=1;
		initSpeed=250;
		mass=8;
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
	class FST_DP23: arifle_MX_Base_F
	{
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		inertia=0;
		canShootInWater=1;
		fireSpreadAngle=2;
		discreteDistance[]={50,100,200,300};
		displayName="[41st] DP-23 Scatterblaster";
		descriptionShort="Space Shotgun";
		picture="\MRC\JLTS\weapons\DP23\data\ui\DP23_ui_ca.paa";
		model="\MRC\JLTS\weapons\DP23\DP23.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\weapons\DP23\data\DP23_co.paa"
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\MRC\JLTS\weapons\DP23\anims\DP23_handanim.rtm"
		};
		magazines[]=
		{
			"FST_blaster_scatter_cell",
		};
		magazineWell[]={};
		muzzles[]=
		{
			"this"
		};
		modes[]=
		{
			"Fire"
		};
		ace_clearJamAction="";
		reloadAction="GestureReload_JLTS_DC15S";
		reloadMagazineSound[]=
		{
			"\41st_Weapons\DC-15AS\Data\reload.ogg",
			1.5,
			1,
			100
		};
		recoil="FST_recoil_DP23";
		fireLightDiffuse[]={0,0,1};
		drySound[]=
		{
			"\Indecisive_Armoury_Sounds\weapon_dry.ogg",
			5,
			1,
			10
		};
		class Fire: Mode_Burst
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
					"\41st_Weapons\DP23\Data\dp23v1 2-177.ogg",
					2,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_Weapons\DP23\Data\dp23v1 2-177.ogg",
					2,
					1.015,
					1800
				};
				begin3[]=
				{
					"\41st_Weapons\DP23\Data\dp23v1 2-177.ogg",
					2,
					0.98500001,
					1800
				};
				begin4[]=
				{
					"\41st_Weapons\DP23\Data\dp23v1 2-177.ogg",
					2,
					1.01,
					1800
				};
				begin5[]=
				{
					"\41st_Weapons\DP23\Data\dp23v1 2-177.ogg",
					2,
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
					"\41st_Weapons\DP23\Data\dp23v1 2-177.ogg",
					2,
					1,
					400
				};
				soundBeginWater[]=
				{
					"beginwater1",
					1
				};
			};
			reloadTime=0.60000002;
			Burst=1;
			soundBurst="true";
			dispersion=0;
			minRange=1;
			minRangeProbab=0.5;
			midRange=25;
			midRangeProbab=0.075000003;
			maxRange=50;
			maxRangeProbab=0.30000001;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=50;
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
				compatibleItems[]=
				{
					"acc_flashlight"
				};
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
