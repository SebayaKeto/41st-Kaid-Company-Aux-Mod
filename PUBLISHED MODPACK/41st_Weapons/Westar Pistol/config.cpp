class CfgPatches
{
	class FST_Weapons_Lego
	{
		requiredAddons[]=
		{
			"3AS_Weapons"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_Westar35_SA_Pistol",
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
class CfgWeapons
{
	class Pistol_Base_F;
	class WeaponSlotsInfo;
	class hgun_Pistol_heavy_01_F: Pistol_Base_F
	{
        class WeaponSlotsInfo;
	};
	class FST_Westar35_SA_Pistol: hgun_Pistol_heavy_01_F
	{
		author="Adapted from SW Legion Studios";
		displayName="[41st] Westar35SA Pistol";
		baseWeapon="FST_Westar35_SA_Pistol";
		descriptionShort="High Powered Sidearm";
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		scope=2;
		scopearsenal=2;
		inertia=0;
		canShootInWater=1;
		picture="\SWLW_merc_mando\pistols\westar35sa\data\ui\SWLW_westar35sa_ui.paa";
		model="SWLW_merc_mando\pistols\westar35sa\westar35sa.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"SWLW_merc_mando\pistols\westar35sa\data\westar35sa_co.paa"
		};
		magazines[]=
		{
			"FST_pistol_westar35sa_Mag_Blue",
			"FST_pistol_westar35sa_Mag_Green",
			"FST_pistol_westar35sa_Mag_Yellow",
			"FST_pistol_westar35sa_Mag_Red"
		};
		ace_clearJamAction="";
		reloadAction="GestureReloadPistol";
		recoil="recoil_pistol_4five";
		magazineWell[]={};
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
			"this"
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
					"SWLW_merc_mando\pistols\westar35sa\sounds\westar35sa",
					1,
					1,
					1800
				};
				begin2[]=
				{
					"SWLW_merc_mando\pistols\westar35sa\sounds\westar35sa",
					1,
					1,
					1800
				};
				begin3[]=
				{
					"SWLW_merc_mando\pistols\westar35sa\sounds\westar35sa",
					1,
					1,
					1800
				};
				begin4[]=
				{
					"SWLW_merc_mando\pistols\westar35sa\sounds\westar35sa",
					1,
					1,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					0.25,
					"begin2",
					0.25,
					"begin3",
					0.25,
					"begin4",
					0.25
				};
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			recoil="recoil_pistol_heavy";
			recoilProne="recoil_prone_pistol_heavy";
			reloadTime=0.2;
			dispersion=0.01015;
			minRange=5;
			minRangeProbab=0.30000001;
			midRange=25;
			midRangeProbab=0.60000002;
			maxRange=50;
			maxRangeProbab=0.1;
			aiRateOfFire=2;
			aiRateOfFireDistance=25;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=24;
			holsterScale=0.89999998;
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]={};
			};
			class CowsSlot: CowsSlot
			{
				compatibleItems[]={};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[]=
                {
                    "FST_Attachment_Light_Normal_White_pistol",
                    "FST_Attachment_Light_Beam_White_pistol",
                    "FST_Attachment_Module_Light_Normal_White_Pistol",
                    "FST_Attachment_Module_Light_Beam_White_Pistol",
                };
			};
		};
	};
	class acc_flashlight;
	class ItemCore;
	class InventoryFlashLightItem_Base_F;
	class FST_Attachment_Light_Normal_White_pistol: acc_flashlight
	{
		author="Inspired from SW Legion Studios";
		displayName = "[41st] WestarSA Light (Normal)";
		model="SWLW_merc_mando\pistols\westar35sa\westar35sa_laser.p3d";
		picture="\SWLW_merc_mando\pistols\westar35sa\data\ui\SWLW_westar35sa_laser_ui.paa";
		scope=2;
        scopeArsenal = 2;
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\SWLW_merc_mando\pistols\westar35sa\data\westar35sa_co.paa"
		};
		class Iteminfo
        {
        //    allowedSlots[] = {801,701,901};
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
	class FST_Attachment_Module_Light_Normal_White_Pistol: acc_flashlight
	{
		author="Inspired from SW Legion Studios";
		displayName = "[41st] WestarSA Light (Normal/Beam)";
		model="SWLW_merc_mando\pistols\westar35sa\westar35sa_laser.p3d";
		picture="\SWLW_merc_mando\pistols\westar35sa\data\ui\SWLW_westar35sa_laser_ui.paa";
		scope=2;
        scopeArsenal = 2;
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\SWLW_merc_mando\pistols\westar35sa\data\westar35sa_co.paa"
		};
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
	class FST_Attachment_Module_Light_Beam_White_Pistol: acc_flashlight
	{
		author="Inspired from SW Legion Studios";
		displayName = "[41st] WestarSA Light/Laser Module";
		model="SWLW_merc_mando\pistols\westar35sa\westar35sa_laser.p3d";
		picture="\SWLW_merc_mando\pistols\westar35sa\data\ui\SWLW_westar35sa_laser_ui.paa";
		scope=1;
        scopeArsenal = 0;
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\SWLW_merc_mando\pistols\westar35sa\data\westar35sa_co.paa"
		};
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
	class FST_Attachment_Light_Beam_White_pistol: acc_flashlight
    {
        author="Inspired from SW Legion Studios";
		displayName = "[41st] WestarSA Light/Laser Module";
		model="SWLW_merc_mando\pistols\westar35sa\westar35sa_laser.p3d";
		picture="\SWLW_merc_mando\pistols\westar35sa\data\ui\SWLW_westar35sa_laser_ui.paa";
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
};
