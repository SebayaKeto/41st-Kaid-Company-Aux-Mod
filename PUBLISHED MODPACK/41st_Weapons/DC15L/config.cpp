class CfgPatches
{
	class FST_Weapons_Republic_DC15L
	{
		addonRootClass="3AS_Weapons_Republic";
		requiredAddons[]=
		{
			"3AS_Weapons_Republic"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"3AS_DC15L_F"
		};
	};
};
class 3AS_MuzzleSlot_DC15L;
class 3AS_CowsSlot_DC15L;
class 3AS_UnderBarrelSlot_DC15L;
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
	class UGL_F;
	class FST_DC15L_Base_F: Rifle_Base_F
	{
		author="Adapted from 3AS";
		magazines[]= 
		{
			"FST_blaster_battery_DC15L_Blue",
			"FST_blaster_battery_DC15L_Green",
			"FST_blaster_battery_DC15L_Yellow",
			"FST_blaster_battery_DC15L_Red",
			"FST_blaster_cell_Blue",
			"FST_blaster_cell_Green",
			"FST_blaster_cell_Yellow",
			"FST_blaster_cell_Red",
		};
		magazineWell[]={};
		magazineReloadSwitchPhase=0.5;
		class Library
		{
			libTextDesc="$STR_3AS_Weapons_Republic_DC15L_Library";
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"3as\3AS_Weapons\Republic\DC15L\Data\Anims\New_DC15L_Handanim.rtm"
		};
		reloadAction="GestureReloadMX";
		recoil="FST_recoil_dc15a";
		maxZeroing=1400;
		discreteDistanceInitIndex=0;
		maxRecoilSway=0.0125;
		swayDecaySpeed=1.25;
		inertia=0.60000002;
		aimTransitionSpeed=0.80000001;
		dexterity=1.4;
		initSpeed=-1;
		class GunParticles: GunParticles
		{
		};
		class WeaponSlotsInfo: WeaponSlotsInfo 
		{
			class CowsSlot: CowsSlot 
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]= 
				{
				//	"3as_Optic_DC15L_F",
					"FST_Optic_DC15L"
				};
			};
			class PointerSlot: PointerSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[]= 
				{
					"FST_Attachment_Light_Normal_White",
                    "FST_Attachment_Light_Beam_White",
                    "FST_Attachment_Module_Light_Normal_White",
                    "FST_Attachment_Module_Light_Beam_White",
					"acc_pointer_IR"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot 
			{
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]= 
				{
					"FST_Bipod_DC15L_f"
				};
			};
		};
		distanceZoomMin=300;
		distanceZoomMax=300;
		descriptionShort="$STR_3AS_Weapons_Republic_DC15L_DesShort";
		modes[]=
		{
			"FullAuto",
			"SlowAuto"
		};
		class FullAuto: Mode_FullAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
					weaponSoundEffect="";
				begin1[]= 
				{
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326.ogg",
					1.5,
					1,
					1800
				};
				begin2[]= 
				{
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326 (1).ogg",
					1.5,
					1,
					1800
				};
				begin3[]= 
				{
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326 (2).ogg",
					1.5,
					1,
					1800
				};
				begin4[]= 
				{
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326.ogg",
					1.5,
					1,
					1800
				};
				begin5[]= 
				{
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326 (1).ogg",
					1.5,
					1,
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
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326.ogg",
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
            reloadTime=0.1;  // 600 RPM
            textureType = "fastAuto"; //Faster Icon for fire type
            dispersion=0.0011;
            minRange=1;
			minRangeProbab=1;
			midRange=50;
			midRangeProbab=1;
			maxRange=100;
			maxRangeProbab=0.9;
            displayNameShort = "Full Auto";
		};
		class SlowAuto: FullAuto
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
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326.ogg",
					1.5,
					1,
					1800
				};
				begin2[]= 
				{
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326 (1).ogg",
					1.5,
					1,
					1800
				};
				begin3[] =
				{
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326 (2).ogg",
					1.5,
					1,
					1800
				};
				begin4[]= 
				{
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326.ogg",
					1.5,
					1,
					1800
				};
				begin5[]= 
				{
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326 (1).ogg",
					1.5,
					1,
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
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326.ogg",
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
            reloadTime=0.171;  // 350 RPM
            textureType = "fullAuto"; //Faster Icon for fire type
            dispersion=0.0011;
            minRange=100;
            minRangeProbab=1;
            midRange=150;
            midRangeProbab=0.9;
            maxRange=10000;
            maxRangeProbab=0.1;
			aiRateOfFire=0.05;
			aiRateOfFireDistance=1000;
            displayNameShort = "Slow Auto";
		};
		aiDispersionCoefY=24;
		aiDispersionCoefX=21;
		caseless[]=
		{
			"",
			1,
			1,
			1
		};
		soundBullet[]=
		{
			"caseless",
			1
		};
		drySound[]=
		{
			"\Indecisive_Armoury_Sounds\weapon_dry.ogg",
			5,
			1,
			10
		};
		reloadMagazineSound[]= 
		{
			"\41st_Weapons\DC-15AS\Data\reload.ogg",
			1.5,
			1,
			100
		};
		ace_overheating_mrbs=3000;
		ace_overheating_slowdownFactor=1;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=0.75;
	};
	class ItemCore;
	class InventoryOpticsItem_Base_F;
	class FST_Optic_DC15L: ItemCore
	{
		author="Gold";
		scope=2;
		displayName="[41st] DC-15L Scope";
		picture="\a3\Weapons_F\acc\Data\UI\icon_optic_MRCO_ca.paa";
		model="\3AS\3AS_Weapons\Republic\ACC\3AS_acco_DC15L_Scope_F.p3d";
		descriptionShort="$STR_3AS_Weapons_Republic_Optic_DC15L_Scope_DesShort";
		weaponInfoType="RscOptics_sos";
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass=8;
			opticType=1;
			optics=1;
			modelOptics="\a3\weapons_f\acc\reticle_mrco_f";
			class OpticsModes
			{
				class cq
				{
					opticsID = 1;
					useModelOptics = 0;
					opticsPPEffects[] = { "Default" };
					opticsFlare = 0;
					opticsDisablePeripherialVision = 0;
					opticsZoomMin=0.25;
					opticsZoomMax=1.25;
					opticsZoomInit=0.75;
				/*	opticsZoomMin=0.25;
					opticsZoomMax=1.25;
					opticsZoomInit=0.75;*/
					memoryPointCamera="opticView";
				//	memoryPointCamera = "eye";
					visionMode[] = {};
					distanceZoomMin = 300;
					distanceZoomMax = 300;
				};
			};
		};
		inertia=0.1;
	};
	class FST_DC15L_F: FST_DC15L_Base_F
	{
		author="Adapted from 3AS";
		baseWeapon="FST_DC15L_F";
		scope=2;
		displayName="[41st] DC-15L Repeater Rifle";
		model="\3AS\3AS_Weapons\Republic\DC15L\3AS_DC15L_F.p3d";
		picture="\3AS\3AS_Weapons\Republic\DC15L\Data\UI\3as_dc15l.paa";
		UiPicture="\A3\weapons_f\data\UI\icon_regular_CA.paa";
		weaponInfoType="RscOptics_nightstalker";
		modelOptics="\Indecisive_Armoury_Weapons_REPUBLIC\Data\LowPower_Scope\IDA_LowPower_Scope_Blue.p3d";
		class OpticsModes
		{
			class Iron
			{
				opticsID=1;
				useModelOptics=0;
				opticsPPEffects[]=
				{
					"",
					""
				};
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
				opticsZoomInit=0.75;
				discreteDistance[]={200};
				discreteDistanceInitIndex=0;
				distanceZoomMin=200;
				distanceZoomMax=200;
				memoryPointCamera="eye";
				visionMode[]={};
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
			};
			class IDA_DC15A_Scope
			{
				opticsID=2;
				useModelOptics=1;
				opticsPPEffects[]=
				{
					"OpticsRadialBlur1",
					"OpticsBlur1"
				};
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
				opticsZoomInit=0.75;
				discreteDistance[]={200};
				discreteDistanceInitIndex=0;
				distanceZoomMin=100;
				distanceZoomMax=200;
				memoryPointCamera="eye";
				visionMode[]={};
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
				cameraDir="";
			};
		};
	};
};
