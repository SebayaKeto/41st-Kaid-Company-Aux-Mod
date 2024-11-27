class CfgPatches
{
	class FST_T15_AT
	{
		author="Daara";
		requiredAddons[]=
		{
			"A3_weapons_F",
		};
		units[]={};
		weapons[]=
		{
			"FST_T15"
		};
	};
};	
class Mode_SemiAuto;
class CowsSlot;
class UnderBarrelSlot;
class MuzzleSlot;
class PointerSlot;
class CfgWeapons
{
	class Rifle_Base_F;
	class arifle_MX_Base_F: Rifle_Base_F
	{
		class GunParticles;
		class GunClouds;
		class WeaponSlotsInfo;
	};
	class UGL_F;
	class FST_T15: arifle_MX_Base_F {
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		author="Adapted From The Indecisive Armoury Team";
		scope=2;
		inertia=0;
		canShootInWater=1;
		displayName="[41st] T-15 Heavy Blaster";
		descriptionShort="Long range dedicated anti-material blaster.";
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2.p3d";
		hiddenSelections[] = {
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[] = {
			"\MRC\JLTS\weapons\EPL2\data\EPL2_co.paa",
			"\MRC\JLTS\weapons\EPL2\data\EPL2_mag_co.paa"
		};
		handAnim[] = {
			"OFP2_ManSkeleton",
			"\MRC\JLTS\weapons\EPL2\anims\EPL2_handanim.rtm"
		};
		ace_clearJamAction="";
		reloadAction="GestureReloadSPARUGL";
		reloadMagazineSound[] = {
			"\41st_Weapons\DC-15AS\Data\reload.ogg",
			1.5,
			1,
			100
		};
		recoil="FST_recoil_T15";
		magazines[] = {
			"FST_thermal_coil_LP"
		};
		magazineWell[]={};
		fireLightDiffuse[]={0,0,1};
		drySound[] = {
			"\Indecisive_Armoury_Sounds\weapon_dry.ogg",
			5,
			1,
			10
		};
		muzzles[] = {
			"this",
			"FST_T15_UGL"
		};
		modes[] = {
			"Single"
		};
		
		class Single: Mode_SemiAuto {
			displayName = "Low Power";
			sounds[] = {
				"StandardSound"
			};
			class BaseSoundModeType {
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType {
				weaponSoundEffect="";
				begin1[] = {
					"\41st_Weapons\T15\Data\t15v1 2-177.ogg",
					1,
					1,
					1800
				};
				begin2[] = {
					"\41st_Weapons\T15\Data\t15v1 2-177.ogg",
					1.25,
					1.015,
					1800
				};
				begin3[] = {
					"\41st_Weapons\T15\Data\t15v1 2-177.ogg",
					1.25,
					0.98500001,
					1800
				};
				begin4[] = {
					"\41st_Weapons\T15\Data\t15v1 2-177.ogg",
					1.25,
					1.01,
					1800
				};
				begin5[] = {
					"\41st_Weapons\T15\Data\t15v1 2-177.ogg",
					1.25,
					0.995,
					1800
				};
				soundBegin[] = {
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
				beginwater1[] = {
					"\41st_Weapons\T15\Data\t15v1 2-177.ogg",
					1,
					1,
					400
				};
				soundBeginWater[] = {
					"beginwater1",
					1
				};
			};
			reloadTime=0.3;
			dispersion=0.00145;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.7;
			maxRange=10000;
			maxRangeProbab=0.3;
		};
		class FST_T15_UGL: UGL_F {
			displayName="High Power UGL";
			useModelOptics = false;
			useExternalOptic = true;
			magazines[] = {"FST_thermal_coil_T15","FST_thermal_coil_Nexu"};
			cameraDir = "OP_look";
			discreteDistance[] = {100, 200, 300};
			discreteDistanceCameraPoint[] = {"OP_eye", "OP_eye2", "OP_eye3"}; // Position of the camera
			discreteDistanceInitIndex = 0;
			
			class Single: Mode_SemiAuto {
				sounds[] = {
					"StandardSound"
				};
				class BaseSoundModeType {
					weaponSoundEffect = "";
					closure1[] = {};
					closure2[] = {};
					soundClosure[] = {};
				};
				class StandardSound: BaseSoundModeType {
					weaponSoundEffect = "";
					begin1[] = {
						"\41st_Weapons\T15\Data\t15v1 2-177.ogg",
						1.25,
						1,
						1800
					};
					soundBegin[] = {"begin1", 1};
				};
				reloadTime = 0.5;
				dispersion = 0.002;
				minRange = 2;
				minRangeProbab = 0.5;
				midRange = 100;
				midRangeProbab = 0.7;
				maxRange = 300;
				maxRangeProbab = 0.3;
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo {
            mass=80;
            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "3AS_optic_holo_DC15S",
                    "Optic_MRCO",
                    "3AS_optic_reflex_DC15C"
                };
            };
            class MuzzleSlot: MuzzleSlot {
                compatibleItems[]={};
            };
            class PointerSlot: PointerSlot {
                compatibleItems[] = {
                    "acc_flashlight",
                    "acc_pointer_IR"
                };
            };
            class UnderBarrelSlot: UnderBarrelSlot {
                compatibleItems[] = {
                    "3AS_Bipod_VK38X_F"
                };
            };
        };

		class GunParticles {
			class FirstEffect {
				directionName="Konec hlavne";
				effectName="RifleAssaultCloud";
				positionName="Usti hlavne";
			};
		};
	};
};
class CfgMagazines
{
	class 100Rnd_65x39_caseless_mag;
	class FST_thermal_coil_LP: 100Rnd_65x39_caseless_mag
	{
		author="Adapted From The Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count=20;
		displayName="[41st] Low-power Thermal coil";
		displayNameShort="LP Thermal coil";
		descriptionShort="20 round capacity.";
		ammo="FST_thermal_shell_LP";
		tracersEvery=1;
		initSpeed=300;
		mass=35;
	};
	class FST_thermal_coil_T15: 100Rnd_65x39_caseless_mag
	{
		author="Adapted From The Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count=5;
		displayName="[41st] High-power Thermal Coil";
		displayNameShort="HP Thermal coil";
		descriptionShort="5 round capacity.";
		ammo="FST_thermal_shell_T15";
		tracersEvery=1;
		initSpeed=300;
		mass=35;
	};
	class FST_thermal_coil_Nexu: 100Rnd_65x39_caseless_mag
	{
		author="Adapted From The Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count=1;
		displayName="[41st] High-power Thermal Coil Nexu Edition";
		displayNameShort="HP Thermal coil";
		descriptionShort="5 round capacity.";
		ammo="FST_thermal_shell_HP";
		tracersEvery=1;
		initSpeed=300;
		mass=35;
	};
};
class CfgAmmo
{
	class IDA_blasterbolt;
	class FST_thermal_shell_LP: IDA_blasterbolt {
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Medium_Blue_Fly";
		ACE_damageType="plasma";
		hit=120; // Initial hit before submunitions trigger
		indirectHit=1;
		explosive=1;
		indirectHitRange=0.5;
		caliber=5;
		submunitionAmmo="IDA_blasterbolt"; // Submunition ammo class
		submunitionConeType[]=
		{
			"random",
			12
		};
		submunitionConeAngle=0.05;
		triggerDistance = 50;
	};
	class FST_thermal_shell_T15: IDA_blasterbolt
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Blue_Fly";
		ACE_damageType="plasma";
		hit=400;
		indirectHit=1;
		explosive=1;
		indirectHitRange=0.5;
		caliber=20;
	};
};