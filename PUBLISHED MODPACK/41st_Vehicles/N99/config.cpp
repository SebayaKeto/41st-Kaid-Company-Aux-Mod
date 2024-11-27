class CfgPatches
{
	class FST_N99
	{
		author="Daara";
		requiredaddons[]=
		{
			"41st_Addon",
		};
		requiredversion=1;
		units[]=
		{
			"FST_N99",
		};
		weapons[]={};
	};
};
class Optics_Armored;
class Optics_Gunner_APC_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class DefaultEventHandlers;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class Mode_SemiAuto;
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
		class ViewPilot;
		class ViewOptics;
		class ViewCargo;
		class HeadLimits;
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitFuel;
			class HitEngine;
			class HitLTrack;
			class HitRTrack;
		};
		class Sounds: Sounds
		{
			class Engine;
			class Movement;
		};
	};
	class 3AS_N99_base_F: Tank_F{};
	class 3AS_CIS_N99_base_F: 3AS_N99_base_F{};
	class 3AS_CIS_N99_F: 3AS_CIS_N99_base_F{};
	class 3AS_N99: 3AS_CIS_N99_F{};
	class FST_N99: 3AS_N99
	{
		scope=2;
		scopeCurator=2;
		forceingarage=1;
		maximumLoad=5000;
		ace_cargo_space=30;
        ace_cargo_hasCargo=1;
		displayName="[41st] N99 IFV";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="IDA_B1";
		model="\3AS\3AS_N99\model\3AS_N99.p3d";
		icon="3AS\3AS_N99\data\ui\N99_top_ca.paa";
		crewCrashProtection=0.05;
		author="Daara";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"camo3",
			"camo4"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_N99\data\weapons_CO.paa",
			"3AS\3AS_N99\data\main_tracks_center_co.paa",
			"3as\3AS_N99\data\main_hull_co.paa",
			"a3\armor_f_beta\apc_tracked_01\data\mbt_01_track_co.paa"
		};
		editorPreview="\3as\3AS_AAT\images\3AS_AAT.jpg";
		accuracy=1000;
		armor=715;
		armorLights=0.1;
		armorStructural=4;
		crewExplosionProtection=0.99989998;
		damageResistance=0.0054700002;
		cost=2500000;
		crewVulnerable=0;
		epeImpulseDamageCoef=18;
		wheelCircumference=2.1500001;
		tracksSpeed=1.4;
		memoryPointTaskMarker="TaskMarker_1_pos";
		hideWeaponsDriver=1;
		hideWeaponsCargo=1;
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=2.5999999;
				material=-1;
				name="telo";
				visual="zbytek";
				passThrough=1;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.30000001;
			};
			class HitEngine: HitEngine
			{
				armor=4;
				material=-1;
				name="motor";
				passThrough=1;
				minimalHit=0.001;
				explosionShielding=1;
				radius=0.30000001;
			};
			class HitLTrack: HitLTrack
			{
				armor=4;
				material=-1;
				name="track_l_hit";
				passThrough=1;
				minimalHit=0.001;
				explosionShielding=1;
				radius=0.30000001;
			};
			class HitRTrack: HitRTrack
			{
				armor=4;
				material=-1;
				name="track_r_hit";
				passThrough=1;
				minimalHit=0.001;
				explosionShielding=1;
				radius=0.30000001;
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets
				{
				};
				memoryPointGun[]=
				{
					"usti hlavne",
					"usti hlavne2"
				};
				weapons[]=
				{
					"FST_AAT_Side",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"FST_500Rnd_127x99_mag_red",
					"FST_500Rnd_127x99_mag_red",
					"FST_500Rnd_127x99_mag_red",
					"FST_500Rnd_127x99_mag_red",
					"FST_500Rnd_127x99_mag_red",
					"FST_500Rnd_127x99_mag_red",
					"SmokeLauncherMag"
				};
				turretInfoType="RscWeaponRangeZeroing";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				selectionFireAnim="zasleh";
				animationSourceBody="Mainturret";
				animationSourceGun="MainGun";
				body="Mainturret";
				gun="MainGun";
				discreteDistanceInitIndex=5;
				memoryPointGunnerOptics="gunnerview";
				gunnerForceOptics=1;
				class OpticsIn: Optics_Gunner_APC_01
				{
					class Wide: Wide
					{
					};
					class Medium: Medium
					{
					};
					class Narrow: Narrow
					{
					};
				};
				gunnerAction="mbt2_slot2b_in";
				forceHideGunner=1;
				gunnerInAction="mbt2_slot2b_in";
				gunnerFireAlsoInInternalCamera=1;
				gunnerOutFireAlsoInInternalCamera=1;
				proxyIndex=1;
				viewGunnerInExternal=0;
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_best",
					"db-40",
					1,
					50
				};
				minElev=-5;
				minTurn=-15;
				maxturn=15;
				maxElev=20;
				initElev=0;
				stabilizedInAxes=0;
				class HitPoints
				{
					class HitTurret
					{
						armor=4;
						material=-1;
						name="otocvez";
						visual="vez";
						passThrough=1;
						minimalHit=0.001;
						explosionShielding=1;
						radius=0.3000001;
					};
					class HitGun
					{
						armor=4;
						material=-1;
						name="otocvez";
						visual="vez";
						passThrough=1;
						minimalHit=0.001;
						explosionShielding=1;
						radius=0.3000001;
					};
				};
			};
		};
	};
};