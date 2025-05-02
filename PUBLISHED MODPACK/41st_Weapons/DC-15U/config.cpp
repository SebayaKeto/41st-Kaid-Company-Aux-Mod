class CfgPatches
{
	class FST_DC15U
	{
		addonRootClass="A3_Weapons_F_Mark";
		requiredAddons[]=
		{
			"A3_data_F",
			"A3_anims_F",
			"A3_Weapons_F_Mark",
			"A3_Weapons_F",
			"3AS_Weapons",
			"JLTS_weapons_DC15S"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_DC15U"
		};
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class MuzzleSlot_338: MuzzleSlot
{
	class compatibleItems
	{
		muzzle_snds_338_black=1;
		muzzle_snds_338_green=1;
		muzzle_snds_338_sand=1;
	};
};
class CfgWeapons
{
	class Rifle_Base_F
	{
		class WeaponSlotsInfo;
		class GunParticles;
	};
	class arifle_MX_Base_F: Rifle_Base_F
	{
		class GunParticles;
		class GunClouds;
		class WeaponSlotsInfo;
	};
	class FST_DC15U: arifle_MX_Base_F
	{
		author="Gold";
		_generalMacro="srifle_DMR_02_F";
		displayName="[41st] DC-15U Underwater Rifle";
		descriptionShort="Long range, medium rate of fire.";
		baseWeapon="FST_DC15U";
		scope=2;
        scopeArsenal=2;
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		inertia=0;
		canShootInWater=1;
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_plastic_ui_ca.paa";
		model="\41st_Weapons\DC-15U\Data\DC-15U.p3d";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\A3\Weapons_F_Mark\LongRangeRifles\DMR_02\data\Anim\DMR_02.rtm"
		};
		ace_clearJamAction="";
		reloadAction="GestureReloadDMR02";
		reloadMagazineSound[]=
		{
			"\41st_Weapons\DC-15AS\Data\reload.ogg",
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
			"Single"
		};
		fireLightDiffuse[]={0,0,1};
		drySound[]=
		{
			"\Indecisive_Armoury_SW\Sounds\weapon_dry.ogg",
			5,
			1,
			10
		};
		muzzles[]=
		{
			"this",
			//"ACE_muzzle_mzls_338"
		};
		modelOptics="\A3\Weapons_F\acc\reticle_lrps_F";
		class OpticsModes
		{
			class IDA_773Firepuncher_Scope
			{
				opticsID=1;
				useModelOptics=1;
				opticsPPEffects[]=
				{
					"OpticsRadialBlur1",
					"OpticsBlur1"
				};
				opticsZoomMin=0.0285;
				opticsZoomMax=0.125;
				opticsZoomInit=0.125;
				discreteDistance[]={200};
				discreteDistanceInitIndex=0;
				discreteInitIndex=0;
				discretefov[]={0.125,0.0285};
				distanceZoomMin=100;
				distanceZoomMax=1000;
				memoryPointCamera="opticView";
				visionMode[]={};
				opticsFlare=1;
				opticsDisablePeripherialVision=1;
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
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177.ogg",
					1.5,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177 (1).ogg",
					1.5,
					1,
					1800
				};
				begin3[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177 (2).ogg",
					1.5,
					1,
					1800
				};
				begin4[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177.ogg",
					1.5,
					1,
					1800
				};
				begin5[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177 (1).ogg",
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
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177.ogg",
					1.5,
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
			dispersion=0.001;
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
                compatibleItems[]={};
            };
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]=
				{
					"ACE_muzzle_mzls_338"
				};
			};
            class PointerSlot: PointerSlot
            {
                compatibleItems[]=
                {
                    "FST_Attachment_Light_Normal_White",
                    "FST_Attachment_Light_Beam_White",
                    "FST_Attachment_Module_Light_Normal_White",
                    "FST_Attachment_Module_Light_Beam_White"
                };
            };
            class UnderBarrelSlot: UnderBarrelSlot
            {
                compatibleItems[]={};
            };
        };
		class LinkedItems
		{
			class LinkedItemsMuzzle
			{
				slot="MuzzleSlot";
				item="ACE_muzzle_mzls_338";
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
    class acc_flashlight;
    class FST_Attachment_Light_Normal_White: acc_flashlight
    {
        displayName = "[41st] Light (Normal)";
        scope=2;
        scopeArsenal = 2;
        class Iteminfo
        {
            allowedSlots[] = {801,701,901};
            mass = 4;
            mountAction = "MountSide";
            scope = 0;
            type = 301;
            unmountAction = "DismountSide";
            class Flashlight
            {
                ACE_Flashlight_Beam = "\z\ace\addons\map\UI\Flashlight_beam_white_ca.paa";
                ACE_Flashlight_Colour = "white";
                ACE_Flashlight_Size = 2.75;
                ACE_Flashlight_Sound = 1;
                ambient[] = {0.9,0.81,0.7};
                color[] = {180,160,130};
                coneFadeCoef = 8;
                dayLight = 0;
                direction = "flash";
                flareMaxDistance = 150;
                flareSize = 1.6;
                innerAngle = 5;
                intensity = 140;
                outerAngle = 100;
                position = "flash dir";
                scale[] = {1,1,1};
                size = 1.2;
                useFlare = 1;
                volumeShape = "a3\data_f\VolumeLightFlashlight.p3d";
                class Attenuation
                {
                    constant = 0.5;
                    hardLimitEnd = 60;
                    hardLimitStart = 27;
                    linear = 0.1;
                    quadratic = 0.2;
                    start = 0;
                };
            };
        };
    };
	class FST_Attachment_Module_Light_Normal_White: acc_flashlight
	{
		displayName = "[41st] Light (Normal/Beam)";
		scope=2;
		scopeArsenal = 2;
		MRT_switchItemHintText = "White Light";
		MRT_SwitchItemNextClass = "FST_Attachment_Module_Light_Beam_White";
		MRT_SwitchItemPrevClass = "FST_Attachment_Module_Light_Beam_White";
		class Iteminfo
		{
			allowedSlots[] = {801,701,901};
            mass = 4;
            mountAction = "MountSide";
            scope = 0;
            type = 301;
            unmountAction = "DismountSide";
            class Flashlight
            {
                ACE_Flashlight_Beam = "\z\ace\addons\map\UI\Flashlight_beam_white_ca.paa";
                ACE_Flashlight_Colour = "white";
                ACE_Flashlight_Size = 2.75;
                ACE_Flashlight_Sound = 1;
                ambient[] = {0.9,0.81,0.7};
                color[] = {180,160,130};
                coneFadeCoef = 8;
                dayLight = 0;
                direction = "flash";
                flareMaxDistance = 150;
                flareSize = 1.6;
                innerAngle = 5;
                intensity = 140;
                outerAngle = 100;
                position = "flash dir";
                scale[] = {1,1,1};
                size = 1.2;
                useFlare = 1;
                volumeShape = "a3\data_f\VolumeLightFlashlight.p3d";
                class Attenuation
                {
                    constant = 0.5;
                    hardLimitEnd = 60;
                    hardLimitStart = 27;
                    linear = 0.1;
                    quadratic = 0.2;
                    start = 0;
                };
            };
        };
    };
    class FST_Attachment_Module_Light_Beam_White: acc_flashlight
    {
        displayName = "[41st] Light/Laser Module";
        scope=1;
        scopeArsenal = 0;
        MRT_switchItemHintText = "Beam White Light";
        MRT_SwitchItemNextClass = "FST_Attachment_Module_Light_Normal_White";
        MRT_SwitchItemPrevClass = "FST_Attachment_Module_Light_Normal_White";
        class Iteminfo
        {
            allowedSlots[] = {801,701,901};
            mass = 4;
            mountAction = "MountSide";
            scope = 0;
            type = 301;
            unmountAction = "DismountSide";
            class Flashlight
            {
                ambient[] = {0.9,0.81,0.7};
                color[] = {180,160,130};
                coneFadeCoef = 30;
                dayLight = 0;
                direction = "flash";
                flareMaxDistance = 500;
                flareSize = 4;
                innerAngle = 8;
                intensity = 140;
                irLight = 0;
                outerAngle = 25;
                position = "flash dir";
                scale[] = {1,1,1};
                size = 1;
                useFlare = 1;
                volumeShape = "a3\data_f\VolumeLightFlashlight.p3d";
                class Attenuation
                {
                    constant = 0.2;
                    hardLimitEnd = 540;
                    hardLimitStart = 27;
                    linear = 0.2;
                    quadratic = 0.2;
                    start = 20;
                };
            };
        };
    };
	class FST_Attachment_Light_Beam_White: acc_flashlight
    {
        displayName = "[41st] Light (Beam)";
        scope=2;
        scopeArsenal = 2;
        class Iteminfo
        {
            allowedSlots[] = {801,701,901};
            mass = 4;
            mountAction = "MountSide";
            scope = 0;
            type = 301;
            unmountAction = "DismountSide";
            class Flashlight
            {
                ambient[] = {0.9,0.81,0.7};
                color[] = {180,160,130};
                coneFadeCoef = 30;
                dayLight = 0;
                direction = "flash";
                flareMaxDistance = 500;
                flareSize = 4;
                innerAngle = 8;
                intensity = 140;
                irLight = 0;
                outerAngle = 25;
                position = "flash dir";
                scale[] = {1,1,1};
                size = 1;
                useFlare = 1;
                volumeShape = "a3\data_f\VolumeLightFlashlight.p3d";
                class Attenuation
                {
                    constant = 0.2;
                    hardLimitEnd = 540;
                    hardLimitStart = 27;
                    linear = 0.2;
                    quadratic = 0.2;
                    start = 20;
                };
            };
        };
    };
	class ACE_muzzle_mzls_338
	{
		scope=2;
		displayName="ACE_muzzle_mzls_338";
		picture="\A3\weapons_F\Data\UI\myMuzzleAccessory_CA.paa";
		model="\A3\weapons_f\acc\myMuzzleAccessory";
	};
};
