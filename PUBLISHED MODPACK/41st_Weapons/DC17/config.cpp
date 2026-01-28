class CfgPatches
{
	class FST_Weapons_DC17
	{
		requiredAddons[]=
		{
			"3AS_Weapons"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_DC17",
			"FST_DC17_Primary",
			"FST_DualDC17_ARC",
			"FST_TwinDC17_Secondary",
			"FST_TwinDC17_Primary"
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
	class NVGoggles;
	class Pistol_Base_F;
	class WeaponSlotsInfo;
	class 3AS_DC17S_Dual_F;
	class hgun_Pistol_heavy_01_F: Pistol_Base_F
	{
        class WeaponSlotsInfo;
	};
	class FST_DC17: hgun_Pistol_heavy_01_F
	{
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		author="Adapted from the Indecisive Armoury Team";
		displayName="[41st] DC-17 Blaster Pistol";
		descriptionShort="High Powered Sidearm";
		scope=2;
		inertia=0;
		canShootInWater=1;
		baseWeapon="FST_DC17";
		picture="\MRC\JLTS\weapons\DC17SA\data\ui\DC17SA_ui_ca.paa";
		model="Indecisive_Armoury_Weapons_REPUBLIC\Data\DC17\Model\IDA_DC17.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"Indecisive_Armoury_Weapons_REPUBLIC\Data\DC17\Textures\dc17_co.paa"
		};
		magazines[]=
		{
			"FST_blaster_cell_low_Blue",
			"FST_blaster_cell_low_Green",
			"FST_blaster_cell_low_Yellow",
			"FST_blaster_cell_low_Red"
		};
		ace_clearJamAction="";
		reloadAction="GestureReloadPistolHeavy02";
		recoil="FST_recoil_dc17";
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
					"\41st_Weapons\DC17\Data\dc17v2 2-117.ogg",
					1.25,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_Weapons\DC17\Data\dc17v2 2-117.ogg",
					1.25,
					1.015,
					1800
				};
				begin3[]=
				{
					"\41st_Weapons\DC17\Data\dc17v2 2-117.ogg",
					1.25,
					0.98500001,
					1800
				};
				begin4[]=
				{
					"\41st_Weapons\DC17\Data\dc17v2 2-117.ogg",
					1.25,
					1.01,
					1800
				};
				begin5[]=
				{
					"\41st_Weapons\DC17\Data\dc17v2 2-117.ogg",
					1.25,
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
					"\41st_Weapons\DC17\Data\dc17v2 2-117.ogg",
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
			reloadTime=0.1;
			dispersion=0.0011;
			minRange=0;
			minRangeProbab=1;
			midRange=100;
			midRangeProbab=0.75;
			maxRange=250;
			maxRangeProbab=0.5;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=20;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]=
				{
					"3AS_optic_holo_DC15S"
				};
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
	};
	class ls_weapon_dc17s_dual_base: FST_DC17
	{
		class WeaponSlotsInfo;
	};
	class FST_weapon_dualDC17Left_dummy: NVGoggles
	{
		scope=1;
		author="Legion Studios";
		model="ls\core\addons\weapons_dcseries\dc17s_dual\ls_weapon_dc17s_dual_dummy.p3d";
		thermalMode[]={2,3};
		visionMode[]=
		{
			"Normal"
		};
		modelOptics="-";
		class ItemInfo
		{
			type=616;
			hmdType=0;
			uniformModel="ls\core\addons\weapons_dcseries\dc17s_dual\ls_weapon_dc17s_dual_dummy.p3d";
			modelOff="ls\core\addons\weapons_dcseries\dc17s_dual\ls_weapon_dc17s_dual_dummy.p3d";
			mass=4;
		};
	};
	class FST_weapon_dualDC17Left_dummy_Primary: FST_weapon_dualDC17Left_dummy
	{
		scope=1;
		type = 1;
		author="Gold";
		model="\JMSLLTE_weapons\dc17\dc17_dual.p3d";
		thermalMode[]={2,3};
		visionMode[]=
		{
			"Normal"
		};
		modelOptics="-";
		class ItemInfo
		{
			type=616;
			hmdType=0;
			uniformModel="ls\core\addons\weapons_dcseries\dc17s_dual\ls_weapon_dc17s_dual_dummy.p3d";
			modelOff="ls\core\addons\weapons_dcseries\dc17s_dual\ls_weapon_dc17s_dual_dummy.p3d";
			mass=4;
		};
	};
	class FST_TwinDC17_Secondary: ls_weapon_dc17s_dual_base
	{
		scope=2;
		baseWeapon="FST_twinDC17_secondary";
		displayName="[41st] Twin DC-17 Blaster Pistols";
		model="ls\core\addons\weapons_dcseries\dc17s_dual\ls_weapon_dc17s_dual.p3d";
		canShootInWater=1;
		weapontype=WEAPONTYPE_AKIMBO=1;
		akimboDummy="FST_weapon_dualDC17Left_dummy";

		muzzles[]=
		{
			"Right",
			"Left"
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"ls\core\addons\weapons_dcseries\dc17s_dual\anims\dc17s_dual_handanim.rtm"
		};
		reloadAction="";
		reloadMagazineSound[]=
		{
			"\Indecisive_Armoury_Sounds\auto_reload.wss",
			1.5,
			1,
			100
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=20;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]={};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[]={};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]={};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]={};
			};
		};
		class Right: FST_DC17
		{
			displayName="Right Hand";
			magazines[]=
			{
				"FST_blaster_cell_low_Blue",
				"FST_blaster_cell_low_Green",
				"FST_blaster_cell_low_Yellow",
				"FST_blaster_cell_low_Red"
			};
			reloadAction="";
		};
		class Left: Right
		{
			displayName="Left Hand";
			muzzlePos="usti hlavne left";
			muzzleEnd="konec hlavne left";
		};
	};
	class FST_TwinDC17_Primary: FST_TwinDC17_Secondary
	{
		scope=2;
		type = 1;
		baseWeapon="FST_TwinDC17_Secondary_Primary";
		displayName="[41st] Twin DC-17 Blaster Pistols";
		model="\JMSLLTE_weapons\dc17\dc17_dual.p3d";
		canShootInWater=1;
	//	weaponType=WEAPONTYPE_AKIMBO=1;
		akimboDummy="FST_weapon_dualDC17Left_dummy_Primary";
		muzzles[]=
		{
			"Right",
			"Left"
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\JMSLLTE_weapons\anim\A_handanim_dualPistol.rtm"
		};
		reloadAction="";
		reloadMagazineSound[]=
		{
			"\Indecisive_Armoury_Sounds\auto_reload.wss",
			1.5,
			1,
			100
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=20;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]={};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[]={};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]={};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]={};
			};
		};
		class Right: FST_DC17
		{
			displayName="Right Hand";
			magazines[]=
			{
				"FST_blaster_cell_low_Blue",
				"FST_blaster_cell_low_Green",
				"FST_blaster_cell_low_Yellow",
				"FST_blaster_cell_low_Red"
			};
			reloadAction="";
		};
		class Left: Right
		{
			displayName="Left Hand";
			muzzlePos="usti_hlavne";
			muzzleEnd="usti_hlavne1";
		};
	};
	class FST_weapon_dualDC17_secondary: ls_weapon_dc17s_dual_base
	{
		scope=2;
		displayName="[41st] Twin DC-17 Blaster Pistols";
		model="ls\core\addons\weapons_dcseries\dc17s_dual\ls_weapon_dc17s_dual.p3d";
		weaponType=WEAPONTYPE_AKIMBO=1;
		akimboDummy="ls_weapon_dc17s_dual_dummyWeapon";
		magazines[]=
		{
			"FST_blaster_cell_low_Blue",
			"FST_blaster_cell_low_Green",
			"FST_blaster_cell_low_Yellow",
			"FST_blaster_cell_low_Red"
		};
		muzzles[]=
		{
			"Right",
			"Left"
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"ls\core\addons\weapons_dcseries\dc17s_dual\anims\dc17s_dual_handanim.rtm"
		};
		reloadAction="ls_dualPistol_reload";
		reloadMagazineSound[]=
		{
			"\Indecisive_Armoury_Sounds\auto_reload.wss",
			1.5,
			1,
			100
		};
		class Right: FST_DC17
		{
			displayName="Right Hand";
			magazines[]=
			{
				"FST_blaster_cell_low_Blue",
				"FST_blaster_cell_low_Green",
				"FST_blaster_cell_low_Yellow",
				"FST_blaster_cell_low_Red"
			};
			reloadAction="ls_dualPistol_reload";
			reloadMagazineSound[]=
			{
				"ls\core\addons\sounds\weapons\reload\dc17s_dual.ogg",
				3.5481339,
				1,
				10
			};
		};
		class Left: Right
		{
			displayName="Left Hand";
			muzzlePos="usti hlavne left";
			muzzleEnd="konec hlavne left";
		};
	};
	class FST_DualDC17_ARC: 3AS_DC17S_Dual_F
	{
		author = "Ruby";
		scope = 2;
		baseweapon = "FST_DualDC17_ARC";
		displayname = "[41st] Dual DC-17 (ARC)";
		model="\3AS\3AS_Weapons\Republic\DC17S\3AS_DC17S_Dual_F.p3d";
		picture="\3AS\3AS_Weapons\Republic\DC17S\Data\UI\3as_dc17s.paa";
		UiPicture="\A3\weapons_f\data\UI\icon_regular_CA.paa";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"3AS\3AS_Weapons\Republic\DC17S\Data\Anim\DC17S_Dual_Handanim.rtm"
		};
		reloadAction="3AS_GestureReloadDualDC17S";
		magazines[]=
		{
			"FST_blaster_cell_low_Blue",
			"FST_blaster_cell_low_Green",
			"FST_blaster_cell_low_Yellow",
			"FST_blaster_cell_low_Red"
		};
		magazineWell[]={};
		modes[]=
		{
			"Single"
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
					"\41st_Weapons\DC17\Data\dc17v2 2-117.ogg",
					1.25,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_Weapons\DC17\Data\dc17v2 2-117.ogg",
					1.25,
					1.015,
					1800
				};
				begin3[]=
				{
					"\41st_Weapons\DC17\Data\dc17v2 2-117.ogg",
					1.25,
					0.98500001,
					1800
				};
				begin4[]=
				{
					"\41st_Weapons\DC17\Data\dc17v2 2-117.ogg",
					1.25,
					1.01,
					1800
				};
				begin5[]=
				{
					"\41st_Weapons\DC17\Data\dc17v2 2-117.ogg",
					1.25,
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
					"\41st_Weapons\DC17\Data\dc17v2 2-117.ogg",
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
			reloadTime=0.1;
			dispersion=0.0011;
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
			class CowsSlot: CowsSlot
			{
				compatibleItems[]={};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[]={};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]={};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]={};
			};
		};
	};
};
