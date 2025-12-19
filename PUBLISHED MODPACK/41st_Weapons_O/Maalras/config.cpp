class CfgPatches
{
	class FST_Maalras_SMG
	{
		requiredAddons[]=
		{
			"A3_Weapons_F"
		};
		units[]={};
		weapons[]={};
	};
};
class Mode_SemiAuto;
class Mode_FullAuto;
class WeaponSlotsInfo;
class CowsSlot_Rail;
class MuzzleSlot_57;
class PointerSlot_Rail;
class CfgWeapons
{
	class Rifle;
	class Rifle_Base_F: Rifle
	{
		class WeaponSlotsInfo;
	};
	class FST_MaalrasSMG_Base: Rifle_Base_F
	{
		ACE_overheating_allowSwapBarrel=1;
		ACE_Overheating_Dispersion=0;
		ACE_Overheating_JamChance=0;
		ACE_overheating_mrbs=3e+009;
		ACE_overheating_slowdownFactor=0;
		ace_overpressure_angle=0;
		ace_overpressure_damage=0;
		ace_overpressure_priority=1;
		ace_overpressure_range=0;
		author="Vulgar";
		_generalMacro="SMG_03_TR_black";
		displayName="";
		model="DBA_Republic\Addons\DBA_Weapons\DBA_Maalras\MaalrasSMG.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"DBA_Republic\Addons\DBA_Weapons\DBA_Maalras\data\Maalras_CO.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DBA_Republic\Addons\DBA_Weapons\DBA_Maalras\data\Rifle.rvmat"
		};
		modelOptics="-";
		optics=1;
		opticsZoomMin=0.34999999;
		opticsZoomMax=0.34999999;
		magazines[]=
		{
			"FST_blaster_cell_Blue",
			"FST_blaster_cell_Green",
			"FST_blaster_cell_Yellow",
			"FST_blaster_cell_Red"
		};
		muzzles[]=
		{
			"this"
		};
		modes[]=
		{
			"Single",
			"FullAuto"
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"DBA_Republic\Addons\DBA_Weapons\DBA_Maalras\anims\RezMaalrasHandAnim.rtm"
		};
		reloadAction="GestureReload_smg_03";
		recoil="recoil_smg_03";
		magazineReloadSwitchPhase=0.40000001;
		inertia=0.2;
		aimTransitionSpeed=1.4;
		dexterity=1.8;
		initSpeed=-1;
		maxZeroing=600;
		picture="DBA_Republic\Addons\DBA_Effects\icons\Maalras_CA.paa";
		UiPicture="DBA_Republic\Addons\DBA_Effects\icons\Maalras_CA.paa";
		descriptionShort="A Light SMG";
		class Library
		{
			libTextDesc="Gun";
		};
		class OpticsModes
		{
			class Kolimator
			{
				opticsID=1;
				useModelOptics=0;
				opticsPPEffects[]=
				{
					"OpticsCHAbera1",
					"OpticsBlur1"
				};
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
				opticsZoomInit=0.75;
				memoryPointCamera="opticView";
				opticsFlare=0;
				opticsDisablePeripherialVision=1;
				distanceZoomMin=100;
				distanceZoomMax=100;
				cameraDir="";
			};
		};
		reloadMagazineSound[]=
		{
			"A3\Sounds_F_Mod\arsenal\weapons\SMG\ADR_97\ADR_97_Reload",
			1,
			1,
			10
		};
		changeFiremodeSound[]=
		{
			"A3\Sounds_F_Mod\arsenal\weapons\SMG\ADR_97\ADR_97_Firemode",
			1,
			1,
			5
		};
		drySound[]=
		{
			"A3\Sounds_F_Mod\arsenal\weapons\SMG\ADR_97\ADR_97_Dry",
			1,
			1,
			10
		};
		class Single: Mode_SemiAuto
		{
			multiplier=1;
			burst=1;
			reloadTime=0.059999999;
			soundContinuous=0;
			autoFire=0;
			minRange=20;
			minRangeProbab=0.89;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
			aiRateOfFire=2;
			aiRateOfFireDistance=55;
			dispersion=0.0020300001;
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
					"41st_Weapons_O\Maalras\Data\Maalras1.ogg",
					1,
					1,
					1800
				};
				begin2[]=
				{
					"41st_Weapons_O\Maalras\Data\Maalras2.ogg",
					1,
					1,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					1,
					"begin2",
					1
				};
			};
		};
		class FullAuto: Mode_FullAuto
		{
			multiplier=1;
			burst=1;
			soundContinuous=0;
			autoFire=1;
			minRange=1;
			minRangeProbab=0.99;
			midRange=50;
			midRangeProbab=0.75;
			maxRange=100;
			maxRangeProbab=0.2;
			aiRateOfFire=3;
			aiRateOfFireDistance=1000;
			dispersion=0.0020300001;
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
					"41st_Weapons_O\Maalras\Data\Maalras1.ogg",
					1,
					1,
					1800
				};
				begin2[]=
				{
					"41st_Weapons_O\Maalras\Data\Maalras2.ogg",
					1,
					1,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					1,
					"begin2",
					1
				};
			};
			reloadTime=0.059999999;
		};
		class WeaponSlotsInfo
		{
			class CowsSlot: CowsSlot_Rail
			{
				compatibleItems[]=
				{
					"DBA_MRCO_A",
					"DBA_MRCO_B"
				};
				iconPosition[]={0.40000001,0.30000001};
				iconScale=0.2;
			};
			class PointerSlot: PointerSlot_Rail
			{
				iconPosition[]={0.33000001,0.37};
				iconScale=0.25;
				compatibleItems[]={};
			};
			class MuzzleSlot: MuzzleSlot_57
			{
				iconPosition[]={0,0.5};
				iconScale=0.25;
				compatibleItems[]={};
			};
			mass=50;
		};
	};
	class FST_Maalras_SMG: FST_MaalrasSMG_Base
	{
		author="Gold";
		displayName="[41st] Maalras";
		baseWeapon="FST_Maalras_SMG";
		scope=2;
	};	
};
