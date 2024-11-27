class CfgPatches
{
	class FST_Weapons_Valken
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
			"FST_TwinDC17_Secondary",
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
class CfgMagazines
{
	class 100Rnd_65x39_caseless_mag;
	class FST_blaster_cell_low: 100Rnd_65x39_caseless_mag
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count=30;
		displayName="[41st] Low-Power Energy Cell";
		displayNameShort="LP Energy Cell";
		descriptionShort="30 Rnds Low Power Pistol Ammo";
		ammo="FST_blasterbolt";
		tracersEvery=1;
		initSpeed=250;
		mass=4;
	};
	class FST_blaster_cell_low_green: 100Rnd_65x39_caseless_mag
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count=30;
		displayName="[41st] Low-Power Energy Cell (Green)";
		displayNameShort="LP Energy Cell";
		descriptionShort="30 Rnds Low Power Pistol Ammo";
		ammo="FST_blasterbolt_green";
		tracersEvery=1;
		initSpeed=250;
		mass=4;
	};
	class FST_blaster_cell_low_yellow: 100Rnd_65x39_caseless_mag
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count=30;
		displayName="[41st] Low-Power Energy Cell (Yellow)";
		displayNameShort="LP Energy Cell";
		descriptionShort="30 Rnds Low Power Pistol Ammo";
		ammo="FST_blasterbolt_yellow";
		tracersEvery=1;
		initSpeed=250;
		mass=4;
	};
};
class CfgWeapons
{
	class NVGoggles;
	class Pistol_Base_F;
	class WeaponSlotsInfo;
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
			"FST_blaster_cell_low",
			"FST_blaster_cell_low_green",
			"FST_blaster_cell_low_yellow"
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
	class SWLW_DC17_ARC: FST_DC17
	{
		class WeaponSlotsInfo;
	};
	class FST_twinDC17Left_dummy: NVGoggles
	{
		scope=1;
		author="Adapted from the Indecisive Armoury Team";
		model="\ls_weapons\secondary\dual\ls_weapon_dualDC17_dummy.p3d";
		thermalMode[]={2,3};
		canShootInWater=1;
		visionMode[]=
		{
			"Normal"
		};
		modelOptics="-";
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
		class ItemInfo
		{
			type=616;
			hmdType=0;
			uniformModel="\ls_weapons\secondary\dual\ls_weapon_dualDC17_dummy.p3d";
			modelOff="\ls_weapons\secondary\dual\ls_weapon_dualDC17_dummy.p3d";
			mass=4;
		};
	};
	class FST_TwinDC17_Secondary: SWLW_DC17_ARC
	{
		scope=2;
		baseWeapon="FST_twinDC17_secondary";
		displayName="[41st] Twin DC-17 Blaster Pistols";
		model="\ls_weapons\secondary\dual\ls_weapon_dualDC17_secondary.p3d";
		canShootInWater=1;
		ls_isWeaponType=1;
		ls_akimboAlternate="FST_twinDC17Left_dummy";
		magazines[]=
		{
			"FST_blaster_cell_low",
			"FST_blaster_cell_low_green",
			"FST_blaster_cell_low_yellow"
		};
		muzzles[]=
		{
			"Right",
			"Left"
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\ls_weapons\secondary\dual\data\handAnim\dual_handAnim.rtm"
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
		class Right: SWLW_DC17_ARC
		{
			displayName="Right Hand";
			magazines[]=
			{
				"FST_blaster_cell_low",
			};
			reloadAction="";
			reloadMagazineSound[]=
			{
				"\Indecisive_Armoury_Sounds\auto_reload.wss",
				1.5,
				1,
				100
			};
		};
		class Left: Right
		{
			displayName="Left Hand";
			muzzlePos="usti hlavne left";
			muzzleEnd="konec hlavne left";
		};
	};
};
