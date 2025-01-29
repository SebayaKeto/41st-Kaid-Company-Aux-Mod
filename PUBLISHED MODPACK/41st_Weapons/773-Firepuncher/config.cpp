//Adapted from Indecisive Armoury Team
class CfgPatches
{
	class FST_773Firepuncher
	{
		requiredAddons[]=
		{
			"A3_data_F",
			"A3_anims_F",
			"A3_weapons_F",
			"A3_characters_F",
			"A3_Characters_F_Proxies"
		};
		units[]={};
		weapons[]=
		{
			"FST_773Firepuncher",
		};
	};
};
class Mode_SemiAuto;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class CfgWeapons
{	
	class optic_lrps;
	class ItemCore;
	class InventoryOpticsItem_Base_F;
	class arifle_MX_Base_F
	{
		class WeaponSlotsInfo;
		class GunParticles;
	};
	class FST_773Firepuncher: arifle_MX_Base_F
	{
		author="Gold";
		displayName="[41st] 773 Firepuncher marksman rifle";
		baseWeapon="FST_773Firepuncher";
		descriptionShort="Long range, high power.";
		picture="Indecisive_Armoury_Weapons_IMPERIAL\Data\774CX\774CX_ui.paa";
		model="\Indecisive_Armoury_Weapons_REPUBLIC\Data\773Firepuncher\Model\IDA_773Firepuncher.p3d";
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		scope=2;
		scopeArsenal=2;
		inertia=0;
		canShootInWater=1;
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\A3\Weapons_F\Rifles\TRG20\Data\Anim\TRG_21G.rtm"
		};
		ace_clearJamAction="";
		reloadAction="GestureReloadTrgUGL";
		reloadMagazineSound[]=
		{
			"\Indecisive_Armoury_Sounds\blaster_reload_6.ogg",
			1.5,
			1,
			100
		};
		recoil="FST_recoil_dc15a";
		magazines[]=
		{
			"FST_blaster_cell_LE_Blue",
			"FST_blaster_cell_LE_Green",
			"FST_blaster_cell_LE_Yellow",
			"FST_blaster_cell_LE_Red"
		};
		magazineWell[]={};
		modes[]=
		{
			"Single",
		};
		fireLightDiffuse[]={0,0,1};
		drySound[]=
		{
			"\Indecisive_Armoury_Sounds\weapon_dry.ogg",
			5,
			1,
			10
		};
		muzzles[]=
		{
			"this",
		};
		class OpticsModes
		{
			class Ironsights
			{
				opticsID=1;
				useModelOptics=0;
				opticsFlare="true";
				opticsPPEffects[]=
				{
					"OpticsCHAbera5",
					"OpticsBlur5"
				};
				opticsDisablePeripherialVision=0.67000002;
				opticsZoomMin=0.5;
				opticsZoomMax=1.1;
				opticsZoomInit=0.75;
				memoryPointCamera="eye";
				visionMode[]={};
				distanceZoomMin=100;
				distanceZoomMax=100;
			};
			class Scope: Ironsights
			{
				opticsID=2;
				useModelOptics=1;
				opticsPPEffects[]=
				{
					"OpticsCHAbera5",
					"OpticsBlur5"
				};
				opticsDisablePeripherialVision=0.67000002;
				opticsZoomMin=0.125;
				opticsZoomMax=0.125;
				opticsZoomInit=0.125;
				memoryPointCamera="opticView";
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
				opticsFlare="true";
				distanceZoomMin=100;
				distanceZoomMax=100;
				cameraDir="";
			};
		};	
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
					"\Indecisive_Armoury_Sounds\Republic\773Firepuncher\773Firepuncher.ogg",
					1.5,
					1,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
				beginwater1[]=
				{
					"\Indecisive_Armoury_Sounds\Republic\773Firepuncher\773Firepuncher.ogg",
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
			class SilencedSound: BaseSoundModeType
			{
				weaponSoundEffect="";
				begin1[]=
				{
					"\Indecisive_Armoury_Sounds\Republic\773Firepuncher\773Firepuncher.ogg",
					1.5,
					1,
					1000
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
				beginwater1[]=
				{
					"\Indecisive_Armoury_Sounds\Republic\773Firepuncher\773Firepuncher.ogg",
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
			reloadTime=0.13333334;
			dispersion=0.0007;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=80;
			class CowsSlot: CowsSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]=
				{
					"FST_773_scope"
				};
				iconPicture="";
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]=
				{
					"FST_Muzzle_774CX"
				};
				
			};
            class PointerSlot: PointerSlot
            {
                compatibleItems[]=
                {
                    "FST_Attachment_Light_Normal_White",
                    "FST_Attachment_Light_Beam_White",
                    "FST_Attachment_Module_Light_Normal_White",
                    "FST_Attachment_Module_Light_Beam_White",
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
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="FST_773_scope";
			};
			class LinkedItemsMuzzle
			{
				slot="MuzzleSlot";
				item="FST_Muzzle_774CX";
			};
		};
	};
	class FST_773_scope: optic_lrps
	{
		author="Inspired from the Indecisive Armoury Team";
		scope=2;
		displayname="773-FP Scope";
		picture="\Indecisive_Armoury_Weapons_REPUBLIC\Data\773Scope\773Scope_ui.paa";
		model="\Indecisive_Armoury_Weapons_REPUBLIC\Data\773Scope\Model\IDA_773_Scope.p3d";
		memoryPointCamera="eye";
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass=10;
			optics=1;
			modelOptics="\Indecisive_Armoury_Weapons_REPUBLIC\Data\773Scope\2dScope\IDA_DMR_Scope.p3d";
			allowedSlots[]={801,701,901};
			class OpticsModes
			{
				class IronSights
                {
                    distanceZoomMax = 100;
                    distanceZoomMin = 100;
                    memoryPointCamera = "eye";
                    opticsDisablePeripherialVision = 0.67;
                    opticsFlare = "true";
                    opticsID = 1;
                    opticsPPEffects[] = {"OpticsCHAbera5","OpticsBlur5"};
                    opticsZoomInit = 0.75;
                    opticsZoomMax = 1.1;
                    opticsZoomMin = 0.375;
                    useModelOptics = 0;
                    visionMode[] = {};
                };
                class Scope
                {
                    cameraDir = "";
                    distanceZoomMax = 100;
                    distanceZoomMin = 100;
                    memoryPointCamera = "opticView";
                    opticsDisablePeripherialVision = 0.67;
                    opticsFlare = "true";
                    opticsID = 2;
                    opticsPPEffects[] = {"OpticsCHAbera5","OpticsBlur5"};
                    opticsZoomInit = 0.0625;
                    opticsZoomMax = 0.0625;
                    opticsZoomMin = 0.03125;
                    useModelOptics = 1;
                    visionMode[] = {"Normal","NVG"};
				};
			};
		};
	};
	class InventoryMuzzleItem_Base_F;
	class FST_Muzzle_774CX: ItemCore
	{
		author="Inspired by 3as Studio";
		_generalMacro="muzzle_snds_H";
		htMin=1;
		htMax=600;
		afMax=0;
		mfMax=0;
		mFact=1;
		tBody=100;
		scope=2;
		displayName="[41st] 774CX Muzzle";
		picture="\a3\Weapons_F\acc\Data\UI\icon_muzzle_snds_H_ca.paa";
		model="";
		class ItemInfo: InventoryMuzzleItem_Base_F
		{
			mass=10;
			class MagazineCoef
			{
				initSpeed=1.25;
			};
			class AmmoCoef
			{
				hit=1;
				typicalSpeed=1;
				airFriction=1;
				visibleFire=1;
				audibleFire=1;
				visibleFireTime=1;
				audibleFireTime=1;
				cost=1;
			};
			soundTypeIndex=0;
			muzzleEnd="zaslehPoint";
			alternativeFire="Zasleh2";
			class MuzzleCoef
			{
				dispersionCoef=0.80000001;
				artilleryDispersionCoef=1;
				fireLightCoef=1;
				recoilCoef=1;
				recoilProneCoef=1;
				minRangeCoef=1;
				minRangeProbabCoef=1;
				midRangeCoef=1;
				midRangeProbabCoef=1;
				maxRangeCoef=1;
				maxRangeProbabCoef=1;
			};
		};
		inertia=0.2;
	};
};