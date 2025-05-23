class CfgPatches
{
	class FST_RG4D
	{
		author="Daara";
		requiredAddons[]=
		{
			"A3_data_F",
			"A3_weapons_F",
			"A3_characters_F",
			"JLTS_weapons_Core"
		};
		weapons[]=
		{
			"FST_RG4D"
		};
		units[]={};
		magazines[]={};
	};
};
class Mode_SemiAuto;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class CfgWeapons
{
	class WeaponSlotsInfo;
	class JLTS_RG4D;
	class FST_RG4D: JLTS_RG4D
	{
		author="Daara";
		displayName="[41st] RG-4D Navy Service Pistol";
		scope=2;
		baseWeapon="FST_RG4D";
		model="\MRC\JLTS\weapons\RG4D\RG4D.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\weapons\RG4D\data\RG4D_co.paa"
		};
		magazines[]=
		{
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Green",
			"FST_blaster_cell_High_Yellow",
			"FST_blaster_cell_High_Red"
		};
		fireLightDiffuse[]={0,0,1};
		muzzles[]=
		{
			"this"
		};
		reloadAction="GestureReloadPistolHeavy02";
		class Single: Mode_SemiAuto
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
					"MRC\JLTS\weapons\RG4D\sounds\RG4D_fire",
					3,
					1,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			reloadTime=0.13333334;
			dispersion=0.00045;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=20;
			class CowsSlot
			{
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[]=
				{
					"JLTS_DC17SA_flashlight"
				};
			};
			class MuzzleSlot: MuzzleSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]={};
				iconPosition[]={0.23999999,0.34999999};
				iconScale=0.2;
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]={};
			};
		};
		weaponInfoType="RscOptics_nightstalker";
		modelOptics="\a3\weapons_f\acc\reticle_nightstalker_f.p3d";
		class OpticModes
		{
			class Scope
			{
				opticsID=1;
				useModelOptics=1;
				opticsPPEffects[]=
				{
					"OpticsCHAbera1",
					"OpticsBlur1"
				};
				opticsZoomMin=0.025;
				opticsZoomMax=0.0625;
				opticsZoomInit=0.0625;
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex=1;
				distanceZoomMin=100;
				distanceZoomMax=1000;
				memoryPointCamera="opticView";
				visionMode[]=
				{
					"Normal",
					"NVG",
					"Ti"
				};
				thermalMode[]={5,6};
				opticsFlare=1;
				opticsDisablePeripherialVision=1;
				cameraDir="";
			};
		};
	};
};
class CfgVehicles
{
	class Weapon_Base_F;
	class JLTS_GH_RG4D: Weapon_Base_F
	{
		author="MrClock";
		displayName="$STR_JLTS_names_RG4D";
		scope=2;
		class TransportWeapons
		{
			class JLTS_RG4D
			{
				count=1;
				weapon="JLTS_RG4D";
			};
		};
		class TransportMagazines
		{
			class JLTS_RG4D_mag
			{
				count=1;
				magazine="JLTS_RG4D_mag";
			};
		};
	};
};
