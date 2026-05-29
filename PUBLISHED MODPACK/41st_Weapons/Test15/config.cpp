class CfgPatches
{
	class FST_T21_AT
	{
		author="Daara";
		requiredAddons[]=
		{
			"A3_Weapons_F"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_T21",
			"FST_Optic_MRCO_T21"
		};
	};
};

class Mode_SemiAuto;
class Mode_Burst;
class CowsSlot;
class UnderBarrelSlot;
class MuzzleSlot;
class PointerSlot;


class CfgRecoils
{
	class FST_recoil_T15;
	class FST_recoil_T21: FST_recoil_T15 {};
};

class CfgAmmo
{
	class IDA_Blasterbolt;

	class FST_thermal_shell_T21_Blue: IDA_Blasterbolt
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectFly="IDA_BlasterBoltGlow_Medium_Blue_Fly";
		ACE_damageType="plasma";

		// Clean direct-fire LP-derived round.
		// No submunitions, no splash, no hidden secondary projectile.
		hit=115;
		indirectHit=0;
		indirectHitRange=0;
		explosive=0;

		// Anti-material pressure without inheriting the current HP tank-delete behavior.
		caliber=3;

		// Approximate Battlefront-style short damage falloff through velocity loss.
		// There is no literal CfgAmmo "drop-off start/end" pair in Arma 3.
		typicalSpeed=300;
		airFriction=-0.01;

		timeToLive=0.9;
		coefGravity=0.02;
		waterFriction=-0.01;
		deflecting=0;

		cartridge="";
		tracerStartTime=0.05;
		tracerEndTime=10;
		nvgOnly=0;
		airLock=1;
		irTarget=1;
		brightness=1000;
		flareSize=5;
		tracerScale=1;
		effectFlare="FlareShell";
		explosionEffects="IDA_ImpactEffect";
		craterEffects="";
	};

	// Color placeholders inherit the blue projectile behavior.
	// Swap model/effectFly here if you have verified Green/Yellow/Red tracer/effect classnames.
	class FST_thermal_shell_T21_Green: FST_thermal_shell_T21_Blue {};
	class FST_thermal_shell_T21_Yellow: FST_thermal_shell_T21_Blue {};
	class FST_thermal_shell_T21_Red: FST_thermal_shell_T21_Blue {};
};

class CfgMagazines
{
	class IDA_Blaster_Cell_Power1_300Rnd_Blue;

	class FST_thermal_coil_T21_Blue: IDA_Blaster_Cell_Power1_300Rnd_Blue
	{
		scope=2;
		author="Adapted From The Indecisive Armoury Team";
		displayName="[41st] T-21 Thermal Coil (Blue)";
		displayNameShort="T-21 Coil (Blue)";
		descriptionShort="12 round capacity.";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		ammo="FST_thermal_shell_T21_Blue";
		count=12;
		initSpeed=300;
		mass=35;
	};

	class FST_thermal_coil_T21_Green: FST_thermal_coil_T21_Blue
	{
		displayName="[41st] T-21 Thermal Coil (Green)";
		displayNameShort="T-21 Coil (Green)";
		ammo="FST_thermal_shell_T21_Green";
	};

	class FST_thermal_coil_T21_Yellow: FST_thermal_coil_T21_Blue
	{
		displayName="[41st] T-21 Thermal Coil (Yellow)";
		displayNameShort="T-21 Coil (Yellow)";
		ammo="FST_thermal_shell_T21_Yellow";
	};

	class FST_thermal_coil_T21_Red: FST_thermal_coil_T21_Blue
	{
		displayName="[41st] T-21 Thermal Coil (Red)";
		displayNameShort="T-21 Coil (Red)";
		ammo="FST_thermal_shell_T21_Red";
	};
};

class CfgWeapons
{
	class WeaponSlotsInfo;
	class Rifle_Base_F;
	class arifle_MX_Base_F: Rifle_Base_F
	{
		class GunParticles;
		class GunClouds;
		class WeaponSlotsInfo;
	};
	class IDA_T15;

	class optic_MRCO;
	class InventoryOpticsItem_Base_F;
	class FST_Optic_MRCO_T21: optic_MRCO
	{
		author="Vengence";
		scope=2;
		scopeArsenal=2;
		displayName="[41st] T-21 MRCO Optic";
		picture="\a3\Weapons_F\acc\Data\UI\icon_optic_MRCO_ca.paa";
		model="\A3\weapons_f_beta\acc\acco_MRCO_F.p3d";
		weaponInfoType="RscWeaponZeroing";
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass=8;
			modelOptics="\A3\Weapons_f_beta\acc\reticle_MRCO_F";
			optics=2;
			class OpticsModes
			{
				class Iron
				{
					opticsID=1;
					useModelOptics=0;
					opticsPPEffects[]={"",""};
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
				class AlternateScope
				{
					modelOptics="\Indecisive_Armoury_Weapons_REPUBLIC\Data\LowPower_Scope\IDA_LowPower_Scope_Blue.p3d";
					opticsID=2;
					useModelOptics=1;
					opticsPPEffects[]={"OpticsRadialBlur1","OpticsBlur1"};
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
					cameraDir="";
				};
			};
		};
	};

	class FST_T21: IDA_T15
	{
		author="Gold";
		scope=2;
		scopeArsenal=2;
		baseWeapon="FST_T21";
		displayName="[41st] T-21 Heavy Blaster";
		descriptionShort="Heavy blaster with a 3-round anti-armor burst.";
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2.p3d";

		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\weapons\EPL2\data\EPL2_co.paa",
			"\MRC\JLTS\weapons\EPL2\data\EPL2_mag_co.paa"
		};

		reloadAction="GestureReloadSPARUGL";
		reloadMagazineSound[]=
		{
			"\41st_Weapons\DC-15AS\Data\reload.ogg",
			1.5,
			1,
			100
		};

		recoil="FST_recoil_T21";

		// New T-21 style coils. These replace both old LP and HP mags for this weapon.
		magazines[]=
		{
			"FST_thermal_coil_T21_Blue",
			"FST_thermal_coil_T21_Green",
			"FST_thermal_coil_T21_Yellow",
			"FST_thermal_coil_T21_Red"
		};
		magazineWell[]={};

		// No separate high-power UGL/muzzle anymore.
		muzzles[]=
		{
			"this"
		};

		modes[]=
		{
			"Single",
			"Burst"
		};

		class Single: Mode_SemiAuto
		{
			displayName="Single";
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
				begin1[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1,1,1800};
				begin2[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1.25,1.015,1800};
				begin3[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1.25,0.98500001,1800};
				begin4[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1.25,1.01,1800};
				begin5[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1.25,0.995,1800};
				soundBegin[]=
				{
					"begin1",0.2,
					"begin2",0.2,
					"begin3",0.2,
					"begin4",0.2,
					"begin5",0.2
				};
				beginwater1[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1,1,400};
				soundBeginWater[]={"beginwater1",1};
			};

			// 180 RPM: 60 / 0.33333334 = ~180.
			reloadTime=0.33333334;
			dispersion=0.00145;

			minRange=60;
			minRangeProbab=1;
			midRange=300;
			midRangeProbab=0.85;
			maxRange=10000;
			maxRangeProbab=0.05;

			aiRateOfFire=4;
			aiRateOfFireDistance=1;
			aiRateOfFireDispersion=3;
		};

		class Burst: Mode_Burst
		{
			displayName="Burst";
			burst=3;
			soundBurst=0;

			// Remove recoil only from burst mode.
			// Single still uses the weapon-level FST_recoil_T21.
			recoil="recoil_empty";
			recoilProne="recoil_empty";

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
				begin1[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1,1,1800};
				begin2[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1.25,1.015,1800};
				begin3[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1.25,0.98500001,1800};
				begin4[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1.25,1.01,1800};
				begin5[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1.25,0.995,1800};
				soundBegin[]=
				{
					"begin1",0.2,
					"begin2",0.2,
					"begin3",0.2,
					"begin4",0.2,
					"begin5",0.2
				};
				beginwater1[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1,1,400};
				soundBeginWater[]={"beginwater1",1};
			};

			// 3-round burst. The internal cyclic rate is faster than single so it feels like a burst.
			reloadTime=0.1;
			dispersion=0.0018;

			minRange=60;
			minRangeProbab=1;
			midRange=300;
			midRangeProbab=0.85;
			maxRange=10000;
			maxRangeProbab=0.05;

			aiRateOfFire=1;
			aiRateOfFireDistance=1;
			aiRateOfFireDispersion=3;
		};

		class OpticsModes
		{
			class Ironsights
			{
				opticsID=1;
				useModelOptics=0;
				opticsPPEffects[]={"",""};
				opticsZoomMin=0.375;
				opticsZoomMax=1.1;
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
				opticsPPEffects[]={"OpticsRadialBlur1","OpticsBlur1"};
				opticsZoomMin=0.375;
				opticsZoomMax=1.1;
				opticsZoomInit=0.75;
				discreteDistance[]={200};
				discreteDistanceInitIndex=0;
				distanceZoomMin=200;
				distanceZoomMax=200;
				memoryPointCamera="eye";
				visionMode[]={};
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
				cameraDir="";
			};
		};

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=80;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]=
				{
					"FST_Attachment_Optic_Holo_DC15",
					"FST_Optic_MRCO_T21"
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
					"FST_Attachment_Module_Light_Beam_White",
					"acc_pointer_IR"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]=
				{
					"3AS_Bipod_VK38X_F"
				};
			};
		};
	};
};
