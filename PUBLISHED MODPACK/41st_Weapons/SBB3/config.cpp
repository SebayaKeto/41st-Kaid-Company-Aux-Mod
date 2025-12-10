class CfgPatches
{
	class FST_Weapons_SBB3
	{
		requiredAddons[]=
		{
			"3AS_Weapons"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_SBB3"
		};
	};
};
class Mode_SemiAuto;
class SlotInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class CfgWeapons
{
	class WeaponSlotsInfo;
	class IDA_SBB3;
	class FST_SBB3: IDA_SBB3
	{
		author="Gold";
		displayName="[41st] SB-B3 Scatterblaster";
		baseWeapon="FST_SBB3";
		descriptionShort="Close range spread";
		magazines[]=
		{
			"FST_blaster_scatter_cell_SBB3_Blue",
			"FST_blaster_scatter_cell_SBB3_Green",
			"FST_blaster_scatter_cell_SBB3_Yellow",
			"FST_blaster_scatter_cell_SBB3_Red",
		};
		reloadAction="WBK_HaloShotgun_Reload";
		recoil="FST_recoil_DP23";
		class Fire: Mode_SemiAuto
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
					"\Indecisive_Armoury_Sounds\CIS\SBB3.ogg",
					1,
					1,
					1800
				};
				begin2[]=
				{
					"\Indecisive_Armoury_Sounds\CIS\SBB3.ogg",
					1,
					1.015,
					1800
				};
				begin3[]=
				{
					"\Indecisive_Armoury_Sounds\CIS\SBB3.ogg",
					1,
					0.98500001,
					1800
				};
				begin4[]=
				{
					"\Indecisive_Armoury_Sounds\CIS\SBB3.ogg",
					1,
					1.01,
					1800
				};
				begin5[]=
				{
					"\Indecisive_Armoury_Sounds\CIS\SBB3.ogg",
					1,
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
					"\Indecisive_Armoury_Sounds\CIS\SBB3.ogg",
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
			reloadTime=0.71499997;
			Burst=1;
			soundBurst="true";
			dispersion=0;
			minRange=1;
			minRangeProbab=1;
			midRange=25;
			midRangeProbab=0.075000003;
			maxRange=10000;
			maxRangeProbab=0.1;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=50;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]={};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]={};
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
};