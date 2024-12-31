class CfgPatches
{
	class FST_AV7
	{
		addonRootClass="a3_data_f";
		requiredAddons[]=
		{
			"a3_data_f"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_AV7",
			"FST_AV7_EdenOnly"
		};
		weapons[]={};
	};
};
class DefaultEventHandlers;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class RCWSOptics;
class Optics_Armored;
class Optics_Commander_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class Optics_Gunner_MBT_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};

class Mode_SemiAuto;
class Mode_Burst;
class CfgWeapons
{
	class 3AS_AV7_300mm_AMOS;
	class AV7_Cannon: 3AS_AV7_300mm_AMOS{
		scope=1;
		displayName="[41st] AV7_300mm_Cannon";
		sounds[]=
		{
			"StandardSound"
		};
		class StandardSound {
			soundSetShot[]= {
				"3AS_HeavyTurboLaser_SoundSet"
			};
		};
		reloadSound[]=
		{
			"A3\Sounds_F\arsenal\weapons_vehicles\cannon_120mm\Cannon_120mm_Reload_01",
			2.5118864,
			1,
			10
		};
		reloadTime=7;
		magazineReloadTime=7;
		autoReload=1;
		canLock=0;
		magazines[]=
		{
			"3AS_32Rnd_300mm_Mo_shells",
			"3AS_12Rnd_300mm_Mo_smoke",
			"3AS_4Rnd_300mm_Mo_guided",
			"3AS_4Rnd_300mm_Mo_LG",
			"3AS_12Rnd_300mm_Mo_mine",
			"3AS_4Rnd_300mm_Mo_Cluster",
			"3AS_12Rnd_300mm_Mo_AT_mine"
		};
		modes[]=
		{
			"Single1",
			"Single2",
			"Single3",
			"Single4",
			"Single5",
			"Burst1",
			"Burst2",
			"Burst3",
			"Burst4",
			"Burst5"
		};
		class GunParticles
		{
			class Effect1
			{
				effectName="ArtilleryFired1";
				positionName="MainCannon_Barrel";
				directionName="MainCannon_Barrel_Dir";
			};
		};
		class Single1: Mode_SemiAuto
		{
			displayName="$STR_A3_mortar_120mm_AMOS_Single10";
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				soundSetShot[]= {
					"3AS_HeavyTurboLaser_SoundSet"
				};
			};
			reloadTime=4;
			artilleryDispersion=3.2;
			artilleryCharge=0.19;
			aiRateOfFire=1;
			aiRateOfFireDistance=10;
			minRange=0;
			minRangeProbab=0.0099999998;
			midRange=1;
			midRangeProbab=0.0099999998;
			maxRange=2;
			maxRangeProbab=0.0099999998;
		};
		class Single2: Single1
		{
			displayName="$STR_A3_mortar_120mm_AMOS_Single20";
			artilleryCharge=0.30000001;
		};
		class Single3: Single1
		{
			displayName="$STR_A3_mortar_120mm_AMOS_Single30";
			artilleryCharge=0.47999999;
		};
		class Single4: Single1
		{
			displayName="$STR_A3_mortar_120mm_AMOS_Single40";
			artilleryCharge=0.80000001;
		};
		class Single5: Single1
		{
			displayName="$STR_A3_mortar_120mm_AMOS_Single50";
			artilleryCharge=1;
		};
		class Burst1: Mode_Burst
		{
			showToPlayer=0;
			displayName="$STR_A3_mortar_120mm_AMOS_Burst10";
			burst=6;
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				soundSetShot[]= {
					"3AS_HeavyTurboLaser_SoundSet"
				};
			};
			soundBurst=0;
			reloadTime=6;
			minRange=800;
			minRangeProbab=0.5;
			midRange=1500;
			midRangeProbab=0.69999999;
			maxRange=2000;
			maxRangeProbab=0.5;
			artilleryDispersion=5.3000002;
			artilleryCharge=0.19;
		};
		class Burst2: Burst1
		{
			showToPlayer=0;
			displayName="$STR_A3_mortar_120mm_AMOS_Burst20";
			minRange=2000;
			minRangeProbab=0.40000001;
			midRange=3000;
			midRangeProbab=0.60000002;
			maxRange=5200;
			maxRangeProbab=0.40000001;
			artilleryCharge=0.30000001;
		};
		class Burst3: Burst1
		{
			showToPlayer=0;
			displayName="$STR_A3_mortar_120mm_AMOS_Burst30";
			minRange=5200;
			minRangeProbab=0.30000001;
			midRange=8000;
			midRangeProbab=0.40000001;
			maxRange=13300;
			maxRangeProbab=0.30000001;
			artilleryCharge=0.47999999;
		};
		class Burst4: Burst1
		{
			showToPlayer=0;
			displayName="$STR_A3_mortar_120mm_AMOS_Burst40";
			minRange=14600;
			minRangeProbab=0.2;
			midRange=25000;
			midRangeProbab=0.30000001;
			maxRange=37000;
			maxRangeProbab=0.2;
			artilleryCharge=0.80000001;
		};
		class Burst5: Burst1
		{
			showToPlayer=0;
			displayName="$STR_A3_mortar_120mm_AMOS_Burst50";
			minRange=25000;
			minRangeProbab=0.1;
			midRange=40000;
			midRangeProbab=0.2;
			maxRange=58000;
			maxRangeProbab=0.1;
			artilleryCharge=1;
		};
	};
};
class CfgVehicles
{
	class LandVehicle;
	class Tank: LandVehicle
	{
		class NewTurret;
		class Sounds;
		class HitPoints;
	};
	class Tank_F: Tank
	{
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewGunner;
				class Turrets
				{
					class CommanderOptics;
				};
			};
		};
		class AnimationSources;
	};
	class MBT_01_base_F: Tank_F
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
				};
			};
		};
	};
	class 3AS_01_arty_base_F: MBT_01_base_F{};
	class FST_AV7: 3AS_01_arty_base_F
	{
		author="Adapted from 3AS";
		displayName="[41st] AV-7 Field Cannon Artillery";
		scope=2;
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		generalMacro="B_MBT_01_arty_base_F";
		crew="FST_Trooper_P2_DC15S";
		typicalCargo[]=
		{
			"FST_Trooper_P2_DC15S"
		};
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\AV-7\Data\av7_co.paa"
		};
		side=1;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
				};
				animationSourceHatch="";
				gunnerForceOptics=0;
				usePip=2;
				ejectDeadGunner=1;
				selectionFireAnim="zasleh";
				forceHideGunner=1;
				viewGunnerInExternal=1;
				gunBeg="MainCannon_Barrel";
				gunEnd="MainCannon_Chamber";
				gunnerAction="AV7_Driver";
				gunnerInAction="AV7_Driver";
				gunnerGetInAction="GetInHigh";
				gunnerGetOutAction="GetOutHigh";
				animationSourceStickX="turret_control_x";
				animationSourceStickY="turret_control_y";
				gunnerLeftHandAnimName="turret_control_y";
				gunnerRightHandAnimName="turret_control_y";
				memorypointsgetingunner="pos_driver";
				memorypointsgetingunnerdir="pos_driver_dir";
				LODTurnedIn=1000;
				LODOpticsIn=0;
				minElev=-5;
				maxElev=80;
				initElev=10;
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner",
					0.15848932,
					1,
					30
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner_vertical",
					0.15848932,
					1,
					30
				};
				weapons[]=
				{
					"AV7_Cannon"
				};
				magazines[]=
				{
					"3AS_32Rnd_300mm_Mo_shells",
					"3AS_12Rnd_300mm_Mo_smoke",
					"3AS_4Rnd_300mm_Mo_guided",
					"3AS_4Rnd_300mm_Mo_LG",
					"3AS_4Rnd_300mm_Mo_LG",
					"3AS_12Rnd_300mm_Mo_mine",
					"3AS_4Rnd_300mm_Mo_Cluster",
					"3AS_4Rnd_300mm_Mo_Cluster",
					"3AS_12Rnd_300mm_Mo_AT_mine"
				};
			};
		};
	};
	class FST_AV7_EdenOnly: 3AS_01_arty_base_F
	{
		author="Adapted from 3AS";
		forceingarage=0;
		displayName="[41st] AV-7 (Eden ONLY // Legs Deployed)";
		scope=2;
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		generalMacro="B_MBT_01_arty_base_F";
		tas_canBlift=1;
		tas_liftVars="[[[[0,-4,-6.5]]], [-0.001], [-0.4]]";
		crew="FST_Trooper_P2_DC15S";
		typicalCargo[]=
		{
			"FST_Trooper_P2_DC15S"
		};
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\AV-7\Data\av7_co.paa"
		};
		side=1;
		class AnimationSources: AnimationSources
		{
			class Legs
			{
				source="user";
				animPeriod=0;
				initPhase=1;
				mass=1;
				author="$STR_3AS_Studio";
				displayName="Toggle Legs";
				onPhaseChanged="_this call TAS_fnc_toggleLegs;";
			};
		};
	};
};
class CfgFunctions
{
	class TAS
	{
		class AV7Fncs
		{
			file="\3as\3AS_AV7\functions";
			class toggleLegs
			{
			};
		};
	};
};
