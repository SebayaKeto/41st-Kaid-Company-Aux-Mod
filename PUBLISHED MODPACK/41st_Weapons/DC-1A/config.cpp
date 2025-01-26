class CfgPatches
{
	class FST_DC1A_Prototype
	{
		requiredAddons[]=
		{
			"3AS_Weapons",
			"JLTS_weapons_DC15S",
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_DC1A_Prototype",
		};
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class SlotInfo;
class CowsSlot;
class MuzzleSlot;
class MuzzleSlot_65;
class PointerSlot;
class PointerSlot_Rail;
class UnderBarrelSlot;
class UnderBarrelSlot_rail;
class CowsSlot_Rail;
class CfgWeapons
{
	class Rifle_Base_F
	{
		class WeaponSlotsInfo;
		class GunParticles;
	};
	class UGL_F;
	class FST_DC1A_Prototype: Rifle_Base_F
	{
		author="Gold";
		displayName="[41st] DC1A Prototype";
		baseWeapon="FST_DC1A_Prototype";
		model="DBA_Republic\Addons\DBA_Weapons\DBA_DC15A\Data\DC15AMOD0.p3d";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_plastic_ui_ca.paa";
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		scope=2;
		scopeArsenal=2;
		ace_clearJamAction="";
		reloadAction="3AS_GestureReload_DC17M";
		magazines[]=
		{
			"FST_DC1A_Prototype_120Rnd_Blue",
			"FST_DC1A_Prototype_120Rnd_Green",
			"FST_DC1A_Prototype_120Rnd_Yellow",
			"FST_DC1A_Prototype_120Rnd_Red",
		};
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"DBA_Republic\Addons\DBA_Weapons\DBA_DC15A\Data\DC15AMOD0_CO.paa",
			"DBA_Republic\Addons\DBA_Weapons\DBA_DC15A\Data\MOD0Stock_CO.paa"
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"DBA_Republic\Addons\DBA_Weapons\DBA_DC15A\anims\RezDC15aHandAnim.rtm"
		};
		cursor="mg";
		recoil="DBA_Mod0_Recoil";
		reloadMagazineSound[]=
		{
			"\41st_Weapons\DC-15AS\Data\reload.ogg",
			1.5,
			1,
			100
		};
		drySound[]=
		{
			"\Indecisive_Armoury_Sounds\weapon_dry.ogg",
			5,
			1,
			10
		};
		modes[]=
		{
			"FullAuto",
			"single",
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
				begin1[]=
				{
					"MRC\JLTS\weapons\DC15A\sounds\dc15a_fire",
					1,
					1,
					1800
				};
				closure2[]=
				{
					"A3\Sounds_F\arsenal\weapons\Rifles\MX\Closure_Mx_02",
					0.5,
					1,
					10
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
				soundClosure[]=
				{
					"closure2",
					0.5
				};
			};
			reloadTime=0.066666663;
			dispersion=0.00073000003;
			recoilProne="DBA_Mod0_Recoil";
			minRange=0;
			minRangeProbab=0.30000001;
			midRange=5;
			midRangeProbab=0.69999999;
			maxRange=10;
			maxRangeProbab=0.039999999;
			showToPlayer=1;
		};
		class Single: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]=
				{
					"MRC\JLTS\weapons\DC15A\sounds\dc15a_fire",
					1,
					1,
					1800
				};
				closure2[]=
				{
					"A3\Sounds_F\arsenal\weapons\Rifles\MX\Closure_Mx_02",
					0.5,
					1,
					10
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
				soundClosure[]=
				{
					"closure2",
					0.5
				};
			};
			reloadTime=0.079999998;
			dispersion=0.00073000003;
			minRange=2;
			minRangeProbab=0.0099999998;
			midRange=200;
			midRangeProbab=0.0099999998;
			maxRange=400;
			maxRangeProbab=0.0099999998;
			recoil="DBA_Mod0_Recoil";
			recoilProne="DBA_Mod0_Recoil";
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: MuzzleSlot
			{
			};
			class CowsSlot: CowsSlot_Rail
			{
				iconPosition[]={0.5,0.34999999};
				compatibleItems[]=
				{
					"DBA_MOD0Optic_A",
					"DBA_MGO_A"
				};
				iconScale=0.2;
			};
			class UnderBarrelSlot: UnderBarrelSlot_rail
			{
				iconPosition[]={0.30000001,0.80000001};
				iconScale=0.30000001;
				compatibleItems[]=
				{
				};
			};
			mass=120;
		};
		aiDispersionCoefY=24;
		aiDispersionCoefX=21;
	};
};	