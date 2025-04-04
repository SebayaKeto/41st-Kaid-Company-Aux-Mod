class CfgPatches
{
	class FST_Weapons_DC15L
	{
		requiredAddons[]=
		{
			"3AS_Weapons",
			"A3_Weapons_F",
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_Z6",
			"FST_Z6_Jorge"
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
	class WeaponSlotsInfo;
	class IDA_Z6;
	class FST_Z6: IDA_Z6
	{
		WBK_UseHeavyWeaponFramework = true;
		author="Gold";
		autoReload="true";
		baseWeapon="FST_Z6";
		displayName="[41st] Z-6 rotary cannon";
		displayNameShort="Z-6 rotary cannon";
		descriptionShort="Rapid Fire. Reloads automatically.";
		magazines[]=
		{
			"FST_blaster_battery_Blue",
			"FST_blaster_battery_Green",
			"FST_blaster_battery_Yellow",
			"FST_blaster_battery_Red"
		};
		recoil="FST_recoil_Z6";
		reloadAction="";
		magazineWell[]={};
		fireLightDiffuse[]={0,0,1};
		reloadMagazineSound[]=
		{
			"\Indecisive_Armoury_Sounds\Republic\Z-6\Z6_reload.ogg",
			1.5,
			1,
			100
		};
		muzzles[]=
		{
			"this"
		};
		modes[]=
		{
			"Auto"
		};
		class Auto: Mode_FullAuto
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
					"\41st_weapons\Z6\Data\z6 -3-965 (1).ogg",
					1.5,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_weapons\Z6\Data\z6 -3-965 (2).ogg",
					1.5,
					1.015,
					1800
				};
				begin3[]=
				{
					"\41st_weapons\Z6\Data\z6 -3-965 (3).ogg",
					1.5,
					0.98500001,
					1800
				};
				begin4[]=
				{
					"\41st_weapons\Z6\Data\z6 -3-965 (4).ogg",
					1.5,
					1.01,
					1800
				};
				begin5[]=
				{
					"\41st_weapons\Z6\Data\z6 -3-965 (5).ogg",
					1.5,
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
					"\41st_weapons\Z6\Data\z6 -3-965.ogg",
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
			reloadTime=0.059999999;
			magazines[]=
			{
				"FST_blaster_battery",
				"FST_blaster_battery_Red"
			};
			dispersion=0.003;
			burst=1;
			soundContinuous="false";
			soundBurst="true";
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.075000003;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		aiDispersionCoefY=24;
		aiDispersionCoefX=21;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=100;
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
	};
	class FST_Z6_Jorge: FST_Z6
	{
		author="Gold";
		displayName="[41st] Jorge's vengeance";
		baseWeapon="FST_Z6_Jorge";
		displayNameShort="Z-6 rotary cannon";
		descriptionShort="Rapid Fire. Reloads automatically.";
		picture="\MRC\JLTS\weapons\Z6\data\ui\Z6_ui_ca.paa";
		model="\MRC\JLTS\weapons\Z6\Z6.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"camo3",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Weapons\Z6\Data\Body\FST_Z6_Weathered_co.paa",
			"41st_Weapons\Z6\Data\Barrel\FST_Z6_Barrel_Weathered_co.paa",
			"41st_Weapons\Z6\Data\Mag\FST_Z6_Mag_Weathered_co.paa",
		};
		magazines[]=
		{
			"FST_EWEB_cell_Blue",
			"FST_EWEB_cell_Green",
			"FST_EWEB_cell_Yellow",
			"FST_EWEB_cell_Red"
		};
		recoil="FST_recoil_Z6";
		reloadAction="";
		magazineWell[]={};
		fireLightDiffuse[]={0,0,1};
		reloadMagazineSound[]=
		{
			"\Indecisive_Armoury_Sounds\Republic\Z-6\Z6_reload.ogg",
			1.5,
			1,
			100
		};
		muzzles[]=
		{
			"this"
		};
		modes[]=
		{
			"Auto"
		};
		class Auto: Mode_FullAuto
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
					"\41st_weapons\Z6\Data\z6 -3-965 (1).ogg",
					1.5,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_weapons\Z6\Data\z6 -3-965 (2).ogg",
					1.5,
					1.015,
					1800
				};
				begin3[]=
				{
					"\41st_weapons\Z6\Data\z6 -3-965 (3).ogg",
					1.5,
					0.98500001,
					1800
				};
				begin4[]=
				{
					"\41st_weapons\Z6\Data\z6 -3-965 (4).ogg",
					1.5,
					1.01,
					1800
				};
				begin5[]=
				{
					"\41st_weapons\Z6\Data\z6 -3-965 (5).ogg",
					1.5,
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
					"\41st_weapons\Z6\Data\z6 -3-965.ogg",
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
			reloadTime=0.059999999;
			dispersion=0.003;
			burst=1;
			soundContinuous="false";
			soundBurst="true";
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.075000003;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		aiDispersionCoefY=48; //was originally 24
		aiDispersionCoefX=42; //was originally 21
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=100;
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
				compatibleItems[]={
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
	};
	class acc_flashlight;
	class FST_Base_Flashlight: acc_flashlight
	{
		scope = 0; // Base class, not to be used directly
		class Iteminfo
		{
			allowedSlots[] = {801,701,901};
			mass = 4;
			mountAction = "MountSide";
			type = 301;
			unmountAction = "DismountSide";
			class Flashlight
			{
				ambient[] = {0.9,0.81,0.7};
				color[] = {180,160,130};
				dayLight = 0;
				direction = "flash";
				useFlare = 1;
				volumeShape = "a3\\data_f\\VolumeLightFlashlight.p3d";
			};
		};
	};
	class FST_Attachment_Light_Normal_White: FST_Base_Flashlight
	{
		displayName = "[41st] Light (Normal)";
		scope = 2;
		scopeArsenal = 2;
		class Iteminfo: Iteminfo
		{
			class Flashlight: Flashlight
			{
				ACE_Flashlight_Beam = "\\z\\ace\\addons\\map\\UI\\Flashlight_beam_white_ca.paa";
				ACE_Flashlight_Colour = "white";
				ACE_Flashlight_Size = 2.75;
				ACE_Flashlight_Sound = 1;
				coneFadeCoef = 8;
				flareMaxDistance = 150;
				flareSize = 1.6;
				innerAngle = 5;
				intensity = 140;
				outerAngle = 100;
				scale[] = {1,1,1};
				size = 1.2;
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
	class FST_Attachment_Light_Beam_White: FST_Base_Flashlight
	{
		displayName = "[41st] Light (Beam)";
		scope = 2;
		scopeArsenal = 2;
		class Iteminfo: Iteminfo
		{
			class Flashlight: Flashlight
			{
				coneFadeCoef = 30;
				flareMaxDistance = 500;
				flareSize = 4;
				innerAngle = 8;
				intensity = 140;
				outerAngle = 25;
				scale[] = {1,1,1};
				size = 1;
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
	class FST_Attachment_Module_Light_Normal_White: FST_Base_Flashlight
	{
		displayName = "[41st] Light (Normal/Beam)";
		scope = 2;
		scopeArsenal = 2;
		MRT_switchItemHintText = "White Light";
		MRT_SwitchItemNextClass = "FST_Attachment_Module_Light_Beam_White";
		MRT_SwitchItemPrevClass = "FST_Attachment_Module_Light_Beam_White";
		class Iteminfo: Iteminfo
		{
			class Flashlight: Flashlight
			{
				ACE_Flashlight_Beam = "\\z\\ace\\addons\\map\\UI\\Flashlight_beam_white_ca.paa";
				ACE_Flashlight_Colour = "white";
				ACE_Flashlight_Size = 2.75;
				ACE_Flashlight_Sound = 1;
				coneFadeCoef = 8;
				flareMaxDistance = 150;
				flareSize = 1.6;
				innerAngle = 5;
				intensity = 140;
				outerAngle = 100;
				scale[] = {1,1,1};
				size = 1.2;
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
	class FST_Attachment_Module_Light_Beam_White: FST_Base_Flashlight
	{
		displayName = "[41st] Light/Laser Module";
		scope = 1;
		scopeArsenal = 0;
		MRT_switchItemHintText = "Beam White Light";
		MRT_SwitchItemNextClass = "FST_Attachment_Module_Light_Normal_White";
		MRT_SwitchItemPrevClass = "FST_Attachment_Module_Light_Normal_White";
		class Iteminfo: Iteminfo
		{
			class Flashlight: Flashlight
			{
				coneFadeCoef = 30;
				flareMaxDistance = 500;
				flareSize = 4;
				innerAngle = 8;
				intensity = 140;
				outerAngle = 25;
				scale[] = {1,1,1};
				size = 1;
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
