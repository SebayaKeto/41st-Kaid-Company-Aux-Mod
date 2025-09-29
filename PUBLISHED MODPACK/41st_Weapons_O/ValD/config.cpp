class CfgPatches
{
	class FST_ValD
	{
		requiredAddons[]=
		{
			"A3_Weapons_F"
		};
		units[]={};
		weapons[]={};
	};
};
class Mode_FullAuto;
class WeaponSlotsInfo;
class MuzzleSlot_762;
class CowsSlot_Rail;
class PointerSlot_Rail;
class UnderBarrelSlot_rail;
class CfgWeapons
{
	class Rifle_Base_F;
	class Rifle_Long_Base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo;
	};
	class FST_ValD: Rifle_Long_Base_F
	{
		author="Gold";
		displayName="[41st] Val-D";
		baseWeapon="FST_ValD";
		scope=2;
		model="DBA_Republic\Addons\DBA_Weapons\DBA_ValD\DBA_ValD.p3d";
		picture="DBA_Republic\Addons\DBA_Effects\icons\Verpine_CA.paa";
		UiPicture="DBA_Republic\Addons\DBA_Effects\icons\Verpine_CA.paa";
		magazines[]=
		{
			"FST_blaster_cell_Blue",
			"FST_blaster_cell_Green",
			"FST_blaster_cell_Yellow",
			"FST_blaster_cell_Red"
		};
		reloadAction="GestureReloadDMR03";
		recoil="DBA_Recoil_Val_C";
		maxZeroing=1600;
		overviewPicture="DBA_Republic\Addons\DBA_Effects\icons\Verpine_CA.paa";
		discreteDistanceInitIndex=0;
		cursor="srifle";
		dexterity=1.6799999;
		descriptionShort="Gun";
		inertia=0.80000001;
		aimTransitionSpeed=0.69999999;
		class ItemInfo
		{
			priority=1;
		};
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"DBA_Republic\Addons\DBA_Weapons\DBA_ValD\Data\Val-D_CO.paa"
		};
		class Library
		{
			libTextDesc="Hi";
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\A3\Weapons_F_EPA\LongRangeRifles\DMR_01\data\Anim\dmr_01.rtm"
		};
		drySound[]=
		{
			"MRC\JLTS\weapons\Core\sounds\weapon_dry.wss",
			5,
			1,
			10
		};
		muzzles[]=
		{
			"this"
		};
		modes[]=
		{
			"fullAuto",
			"close",
			"medium",
			"far",
			"veryFar"
		};
		class fullAuto: Mode_FullAuto
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
					"DBA_Republic\Addons\DBA_Weapons\DBA_Zakkeg\Zakkeg.ogg",
					1,
					1,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			reloadTime=0.1;
			dispersion=0.00145;
			recoil="M240Recoil";
			recoilProne="M240RecoilProne";
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=220;
			class MuzzleSlot: MuzzleSlot_762
			{
				iconPosition[]={0.12,0.43099999};
				iconScale=0.15000001;
				compatibleItems[]={};
			};
			class CowsSlot: CowsSlot_Rail
			{
				iconPosition[]={0.5,0.36000001};
				iconScale=0.15000001;
				compatibleItems[]=
				{
					"DBA_MRCO_A",
					"DBA_MRCO_B"
				};
			};
			class PointerSlot: PointerSlot_Rail
			{
				iconPosition[]={0.33000001,0.40000001};
				iconScale=0.2;
				compatibleItems[]={};
			};
			class UnderBarrelSlot: UnderBarrelSlot_rail
			{
				iconPosition[]={0.30000001,0.80000001};
				iconScale=0.30000001;
				compatibleItems[]={};
			};
		};
		distanceZoomMin=300;
		distanceZoomMax=300;
	};
};
