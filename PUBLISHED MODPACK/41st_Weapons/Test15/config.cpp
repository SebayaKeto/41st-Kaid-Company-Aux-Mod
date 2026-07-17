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
			"FST_Optic_MRCO_T21",
			"FST_T21B",
			"FST_Optic_T21B"
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
	// Cowboys Op (Salt): T-21 recoil too heavy -- burst walked off after round 1
	// and single pulled. The per-firemode "empty" recoil override didn't take in
	// the modset, so recoil is lightened here at the WEAPON level (applies to both
	// single and burst). FST_recoil_T15 uses muzzleOuter y=2 (heavy); these values
	// sit just above the DC-15A trooper rifle (y=0.35) -- a controllable, weighty
	// kick that keeps the 3-round burst on target.
	class FST_recoil_T21: FST_recoil_T15
	{
		muzzleOuter[]={0,0.45,0.3,0.15};
		kickBack[]={0.02,0.05};
		temporary=0.012;
	};
};

class CfgAmmo
{
	class IDA_Blasterbolt;

	class FST_thermal_shell_T21_Blue: IDA_Blasterbolt
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectFly="IDA_BlasterBoltGlow_Medium_Blue_Fly";
		ACE_damageType="plasma";

		// --- Cowboys Op (7/11/26) feedback tuning ---
		// Was effectively a worse DC-15: ~250m range, wind-tossed, and near-zero
		// damage vs AAT / N99 / B2 (26 rnds into an AAT did nothing). Given a small
		// HE component + real penetration so it can actually chip armour and reliably
		// kill B2s -- but still well short of the T-15 (caliber 20, hit 400, airburst),
		// which stays the dedicated AT weapon.
		hit=150;
		indirectHit=8;        // small HE leak so rounds bite armour instead of pinging off
		indirectHitRange=0.3; // tiny radius -- still a precise rifle, not an area weapon
		explosive=1;

		// caliber 12: real penetration vs medium armour / components / B2s.
		// Still below the T-15 HP round (caliber 20) and the T-21B AMR (caliber 14),
		// so the damage hierarchy stays T-15 > T-21B > T-21.
		caliber=12;

		// Higher muzzle velocity fixes BOTH the range and the wind complaints:
		// ~500 m/s roughly halves time-of-flight vs the old 300, cutting wind drift
		// and required lead, and the longer TTL lets the round reach past 250m.
		typicalSpeed=500;
		airFriction=-0.005;

		timeToLive=1.5;       // ~500 m/s x 1.5s -> engages armour well beyond 250m
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

	// ---------------------------------------------------------------
	// T-21B: long-range, high-precision ANTI-MATERIAL round.
	// Faster, flatter and far longer-lived than the T-21 battle round,
	// with serious penetration (caliber 14) for materiel / components /
	// light-medium armour at range -- but still below the T-15 HP
	// tank-delete round (caliber 20), so the T-15 stays the top AT.
	// Clean kinetic slug: no splash, no submunition (precision identity).
	// ---------------------------------------------------------------
	class FST_thermal_shell_T21B_Blue: FST_thermal_shell_T21_Blue
	{
		// --- Cowboys Op (T-21B / Assassin) feedback tuning ---
		// Good vs B1s/turrets (1-2 shots) but ~20 shots to kill an AAT/Hellfire,
		// and bolts curved in the wind at range. Response: more penetration + a
		// modest HE component for materiel, and much higher muzzle velocity to
		// flatten the trajectory and cut wind drift. Still below the T-15 HP round.
		hit=300;
		indirectHit=12;        // modest HE so it chews vehicles/materiel (was 0)
		indirectHitRange=0.4;  // small radius -- still a precision AMR, not area
		explosive=1;

		caliber=16;            // up from 14; still below T-15 HP (20) -> T-15 leads AT

		// High velocity fixes the wind-curve at range: flatter, faster, less drift.
		typicalSpeed=750;      // up from 550
		airFriction=-0.003;    // less drag -> holds velocity out to distance
		timeToLive=3.0;
		coefGravity=0.02;
	};
	class FST_thermal_shell_T21B_Green: FST_thermal_shell_T21B_Blue {};
	class FST_thermal_shell_T21B_Yellow: FST_thermal_shell_T21B_Blue {};
	class FST_thermal_shell_T21B_Red: FST_thermal_shell_T21B_Blue {};
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
		initSpeed=500; // raised from 300 (Cowboys Op feedback: range + wind)
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

	// T-21B anti-material coils: small precision magazine, high muzzle velocity.
	class FST_thermal_coil_T21B_Blue: FST_thermal_coil_T21_Blue
	{
		displayName="[41st] T-21B AMR Coil (Blue)";
		displayNameShort="T-21B Coil (Blue)";
		descriptionShort="5 round capacity.";
		ammo="FST_thermal_shell_T21B_Blue";
		count=5;          // 5-round cap -- MUST force a reload; see op ammo-bug note
		initSpeed=750;    // matched to the round's new velocity (was 550)
		mass=20;
	};
	class FST_thermal_coil_T21B_Green: FST_thermal_coil_T21B_Blue
	{
		displayName="[41st] T-21B AMR Coil (Green)";
		displayNameShort="T-21B Coil (Green)";
		ammo="FST_thermal_shell_T21B_Green";
	};
	class FST_thermal_coil_T21B_Yellow: FST_thermal_coil_T21B_Blue
	{
		displayName="[41st] T-21B AMR Coil (Yellow)";
		displayNameShort="T-21B Coil (Yellow)";
		ammo="FST_thermal_shell_T21B_Yellow";
	};
	class FST_thermal_coil_T21B_Red: FST_thermal_coil_T21B_Blue
	{
		displayName="[41st] T-21B AMR Coil (Red)";
		displayNameShort="T-21B Coil (Red)";
		ammo="FST_thermal_shell_T21B_Red";
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
	class optic_LRPS;
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
			// "empty" is the vanilla zero-recoil class (from A3_Weapons_F).
			// The previous "recoil_empty" was not a real class, so the engine
			// fell back to the weapon-level FST_recoil_T21 and burst still kicked.
			recoil="empty";
			recoilProne="empty";

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

	// ===============================================================
	// T-21B: long-range high-precision ANTI-MATERIAL rifle (scoped).
	// Single fire only, very low dispersion, slow deliberate cadence,
	// heavy. Ships with the dedicated FST_Optic_T21B long-range scope.
	// Inherits model / sounds / recoil / slots from FST_T21; only the
	// role-defining stats are overridden below.
	// ===============================================================
	class FST_Optic_T21B: optic_LRPS
	{
		author="41st";
		scope=2;
		scopeArsenal=2;
		displayName="[41st] T-21B AMR Scope";
		descriptionShort="Long-range precision optic for the T-21B anti-material rifle.";
		// Cowboys Op: the MRCO-based scope sat at ~1x (the nested zoom override
		// never applied), so troopers said it felt like a holo. Re-based on the
		// vanilla LRPS optic, which has real high magnification + long-range
		// zeroing out of the box -- guaranteed to actually zoom. Cosmetically a
		// vanilla scope for now; can be reskinned to an SW model later once the
		// magnification is confirmed good in-game.
	};

	class FST_T21B: FST_T21
	{
		author="Gold";
		scope=2;
		scopeArsenal=2;
		baseWeapon="FST_T21B";
		displayName="[41st] T-21B Anti-Material Rifle";
		descriptionShort="Long-range, high-precision anti-material blaster.";

		// Precision AMR: single fire only, no burst.
		modes[]={"Single"};

		// Anti-material coils only.
		magazines[]=
		{
			"FST_thermal_coil_T21B_Blue",
			"FST_thermal_coil_T21B_Green",
			"FST_thermal_coil_T21B_Yellow",
			"FST_thermal_coil_T21B_Red"
		};

		// Re-open the inherited Single mode: slower cadence, tighter grouping.
		class Single
		{
			reloadTime=0.85;   // ~70 RPM deliberate marksman cadence
			dispersion=0.0004; // tight precision grouping
		};

		// Re-open the inherited slots: heavier, and add the AMR scope options.
		class WeaponSlotsInfo
		{
			mass=120; // heavy anti-material rifle
			class CowsSlot
			{
				compatibleItems[]=
				{
					"FST_Optic_T21B",
					"FST_Optic_MRCO_T21",
					"FST_Attachment_Optic_Holo_DC15",
					"optic_LRPS",
					"optic_SOS"
				};
			};
		};
	};
};
