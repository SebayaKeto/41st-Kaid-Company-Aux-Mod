class CfgPatches
{
	class FST_Weapons_DC17M
	{
		addonRootClass="3AS_Weapons";
		requiredAddons[]=
		{
			"3AS_Weapons",
			"A3_Data_F"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_DC17M_F"
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
class UGL_F;
class CfgWeapons
{
	class Rifle;
	class Rifle_Base_F: Rifle
	{
		class WeaponSlotsInfo;
		class GunParticles;
	};
	class FST_DC17M_Base_F: Rifle_Base_F
	{
		author="$STR_3as_Studio";
		magazines[]=
		{
			"FST_blaster_cell_Valken_Blue",
			"FST_HE_LauncherGrenade"
		};
		reloadAction="GestureReloadMX";
		magazineReloadSwitchPhase=0.40000001;
		discreteDistanceInitIndex=0;
		recoil="FST_recoil_DC15A";
		maxRecoilSway=0.0099999998;
		swayDecaySpeed=1.25;
		inertia=0.40000001;
		dexterity=1.7;
		initSpeed=-1;
		maxZeroing=100;
		class GunParticles: GunParticles
		{
			class SecondEffect
			{
				positionName="Nabojnicestart";
				directionName="Nabojniceend";
				effectName="CaselessAmmoCloud";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: CowsSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]={};
			};
			class PointerSlot: PointerSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[]=
				{
					"",
					""
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]={};
			};
		};
		opticsZoomMin=0.25;
		opticsZoomMax=1.25;
		opticsZoomInit=0.75;
		distanceZoomMin=400;
		distanceZoomMax=400;
		descriptionShort="DC17M, 41st Kaid Bn";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"3AS\3AS_Weapons\Data\Anim\DC17M.rtm"
		};
		selectionFireAnim="zasleh";
		fireLightDiffuse[]={7,36,190,1};
		fireLightIntensity=0.02;
		flash="gunfire";
		flashSize=0.1;
		modes[]=
		{
			"FullAuto",
			"Single"
		};
		class FullAuto: Mode_FullAuto
		{
			reloadTime=0.16500001;
			dispersion=0.00092999998;
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=30;
			maxRangeProbab=0.1;
			soundContinuous=0;
			soundBurst=0;
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_DC17M_Shot_SoundSet"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					""
				};
			};
		};
		class Single: Mode_SemiAuto
		{
			reloadTime=0.1;
			dispersion=0.00025000001;
			minRange=2;
			minRangeProbab=0.30000001;
			midRange=150;
			midRangeProbab=0.69999999;
			maxRange=350;
			maxRangeProbab=0.1;
			soundContinuous=0;
			soundBurst=0;
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_DC17M_Shot_SoundSet"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_DC17M_Shot_SoundSet"
				};
			};
		};
		aiDispersionCoefY=6;
		aiDispersionCoefX=4;
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
			"\3AS\3AS_Main\Sounds\Blaster_empty",
			2,
			1,
			20
		};
		reloadMagazineSound[]=
		{
			"\3AS\3AS_Main\Sounds\Old\Blaster_reload.wss",
			1,
			1,
			30
		};
	};
	class FST_DC17M_F: FST_DC17M_Base_F
	{
		scope=2;
		displayName="[41st] DC17M Carbine";
		model="3AS\3AS_Weapons\DC17M\3AS_DC17M_f";
		picture="\3AS\3AS_Weapons\DC17M\data\UI\3as_dc17m.paa";
		weaponInfoType="RscWeaponZeroing";
		modelOptics="3AS\3AS_Weapons\Data\3AS_2D_Optic.p3d";
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
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
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
				opticsZoomMin=0.015;
				opticsZoomMax=0.2;
				opticsZoomInit=0.2;
				memoryPointCamera="opticView";
				visionMode[]=
				{
					"Normal",
					"NVG",
					"TI"
				};
				thermalMode[]={0};
				opticsFlare="true";
				distanceZoomMin=100;
				distanceZoomMax=100;
				cameraDir="";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=60;
		};
		ace_overheating_mrbs=3000;
		ace_overheating_slowdownFactor=1;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=0.75;
	};
};