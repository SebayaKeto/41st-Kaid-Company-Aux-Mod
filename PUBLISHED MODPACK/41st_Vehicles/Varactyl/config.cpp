class CfgPatches
{
	class FST_Varactyl
	{
		author="Daara and Ghostly";
		requiredaddons[]=
		{
		};
		requiredversion=1;
		units[]=
		{
			"FST_Varactyl",
		};
		weapons[]={};
	};
};
class SensorTemplatePassiveRadar;
class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftPilot: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightPilot: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateNV;
class SensorTemplateDataLink;
class VehicleSystemsTemplateLeftCommander: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightCommander: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftGunner: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightGunner: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
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
class Optics_Gunner_AAA_01: Optics_Armored
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
class Optics_Gunner_APC_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class cfgvehicles
{
	class RCWSOptics;
	class land;
	class LandVehicle: land
	{
		class NewTurret;
	};
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
		class RCWSOptics;
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
		class EventHandlers;
	};
	class APC_Tracked_03_base_F: Tank_F
	{
	};
	class B_APC_Tracked_01_AA_F: Tank_F
	{
	};
	class FST_Varactyl: B_APC_Tracked_01_AA_F
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		tas_canBlift=1;
		tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]";
		side=1;
		maximumLoad=5000;
		displayName="[41st] TC-410 Varactyl";
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Trooper_P2_DC15S";
		author="Daara and Ghostly";
		incomingMissileDetectionSystem=16;
		weaponLockSystem="2+4+8";
		supplyRadius=10;
		ace_cargo_space=30;
		ace_cargo_hasCargo=1;
		ace_refuel_fuelCargo=999999999999;
		ace_rearm_defaultSupply=999999999999;
		ace_repair_canRepair=1;
		ace_refuel_hooks[]=
		{
			{0.38,-3.1700001,-0.69999999},
			{-0.41,-3.1700001,-0.69999999}
		};
		armor=900;
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"camo3",
			"camo4",
			"CamoNet"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\Varactyl\Data\41st_Dewback_body_01.paa",
			"41st_Vehicles\Varactyl\Data\41st_Dewback_body_02.paa",
			"41st_Vehicles\Varactyl\Data\41_Varactyl_tower_co.paa",
			"41st_Vehicles\Varactyl\Data\41st_Dewback_body_03.paa",
			"a3\Armor_F\Data\camonet_NATO_Desert_CO.paa"
		};
		simulation="tankX";
		canFloat=1;
		thrustDelay=1;
		brakeDistance=1;
		brakeIdleSpeed=1.78;
		maxSpeed=100;
		waterLeakiness=2.5;
		waterPPInVehicle=0;
		waterAngularDampingCoef=0.5;
		waterResistanceCoef=0.0049999999;
		waterSpeedFactor=1;
		waterSpeedCoef=3;
		waterLinearDampingCoefY=10;
		accelAidForceCoef=15;
		accelAidForceSpd=10;
		accelAidForceYOffset=-2;
		fuelCapacity=100;
		wheelCircumference=3.924;
		antiRollbarForceCoef=12;
		antiRollbarForceLimit=10;
		antiRollbarSpeedMin=10;
		antiRollbarSpeedMax=80;
		idleRpm=1000;
		redRpm=4000;
		normalSpeedForwardCoef=0.75;
		slowSpeedForwardCoef=0.25;
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-3,
				"N",
				0,
				"D1",
				4.6500001,
				"D2",
				3.2,
				"D3",
				2.4000001,
				"D4",
				1.87,
				"D5",
				1.54,
				"D6",
				1.29,
				"D7",
				1.11,
				"D8",
				0.97000003,
				"D9",
				0.87,
				"D10",
				0.77999997
			};
			AmphibiousRatios[]=
			{
				"R1",
				-3,
				"N",
				0,
				"D1",
				4.6500001,
				"D2",
				3.2,
				"D3",
				2.4000001,
				"D4",
				1.87,
				"D5",
				1.54,
				"D6",
				1.29,
				"D7",
				1.11,
				"D8",
				0.97000003,
				"D9",
				0.87,
				"D10",
				0.77999997
			};
			TransmissionRatios[]=
			{
				"High",
				5.4499998
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
		};
		tankTurnForce=950000;
		tankTurnForceAngMinSpd=0.69999999;
		tankTurnForceAngSpd=0.75999999;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				memoryPointGun[]=
				{
					"usti hlavne 1",
					"usti hlavne 2"
				};
				minElev=-10;
				maxElev=80;
				initElev=5;
				weapons[]=
				{
					"FST_EWEB_RemoteTurret",
					"SmokeLauncher",
					"ls_weapon_CMFlareLauncher",
					"FST_Stormfury_AA_Missile"
				};
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\noises\servo_APC_gunner",
					0.31622776,
					1,
					30
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\noises\servo_APC_gunner_vertical",
					0.31622776,
					1,
					30
				};
				magazines[]=
				{
					"IDA_blaster_battery_high",
					"IDA_blaster_battery_high",
					"IDA_blaster_battery_high",
					"IDA_blaster_battery_high",
					"IDA_blaster_battery_high",
					"IDA_blaster_battery_high",
					"IDA_blaster_battery_high",
					"IDA_blaster_battery_high",
					"IDA_blaster_battery_high",
					"IDA_blaster_battery_high",
					"IDA_blaster_battery_high",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
					"ls_mag_192rnd_CMFlareChaff_cyan",
					"ls_mag_192rnd_CMFlareChaff_cyan",
					"ls_mag_192rnd_CMFlareChaff_cyan",
					"ls_mag_192rnd_CMFlareChaff_cyan",
					"FST_Stormfury_4Rnd_AA_Missile",
				};
				selectionFireAnim="zasleh";
				gunnerAction="Gunner_APC_tracked_01_aa_F_out";
				gunnerInAction="Gunner_APC_tracked_01_aa_F_in";
				gunnerforceoptics=0;
				forceHideGunner=0;
				usePip=2;
				animationSourceStickX="turret_control_x";
				animationSourceStickY="turret_control_y";
				gunnerRightHandAnimName="turret_control_y";
				gunnerLeftHandAnimName="turret_control_y";
				LODTurnedIn=1000;
				LODOpticsIn=0;
				viewGunnerShadowAmb=0.5;
				viewGunnerShadowDiff=0.050000001;
				class HitPoints: HitPoints
				{
					class HitTurret
					{
						armor=0.80000001;
						material=-1;
						armorComponent="hit_main_turret";
						name="hit_main_turret_point";
						visual="-";
						passThrough=0;
						minimalHit=0.1;
						explosionShielding=0.2;
						radius=0.25;
						isTurret=1;
					};
					class HitGun
					{
						armor=0.60000002;
						material=-1;
						armorComponent="hit_main_gun";
						name="hit_main_gun_point";
						visual="-";
						passThrough=0;
						minimalHit=0.1;
						explosionShielding=0.40000001;
						radius=0.2;
						isGun=1;
					};
				};
				class OpticsIn: Optics_Gunner_AAA_01
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
				turretInfoType="RscOptics_APC_Tracked_01_gunner";
				class Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftGunner
					{
						class Components: components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={16000,8000,4000,2000};
								resource="RscCustomInfoSensors";
							};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightGunner
					{
						defaultDisplay="SensorDisplay";
						class Components: components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={16000,8000,4000,2000};
								resource="RscCustomInfoSensors";
							};
						};
					};
				};
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						gunnerAction="Commander_APC_tracked_01_aa_F_out";
						gunnerInAction="Commander_APC_tracked_01_aa_F_in";
						gunnerforceoptics=0;
						usePip=2;
						animationSourceStickX="com_turret_control_x";
						animationSourceStickY="com_turret_control_y";
						gunnerRightHandAnimName="com_turret_control_y";
						gunnerLeftHandAnimName="com_turret_control_y";
						turretFollowFreeLook=2;
						LODTurnedIn=1000;
						LODOpticsIn=0;
						viewGunnerShadowAmb=0.5;
						viewGunnerShadowDiff=0.050000001;
						class HitPoints: HitPoints
						{
							class HitComTurret
							{
								armor=0.1;
								material=-1;
								armorComponent="hit_com_turret";
								name="hit_com_turret_point";
								visual="-";
								passThrough=0;
								minimalHit=0.1;
								explosionShielding=1;
								radius=0.15000001;
								isTurret=1;
							};
							class HitComGun
							{
								armor=0.1;
								material=-1;
								armorComponent="hit_com_gun";
								name="hit_com_gun_point";
								visual="-";
								passThrough=0;
								minimalHit=0.1;
								explosionShielding=1;
								radius=0.15000001;
								isGun=1;
							};
						};
						class OpticsIn: Optics_Commander_01
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
						class Components
						{
							class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftCommander
							{
								class Components: components
								{
									class SensorDisplay
									{
										componentType="SensorsDisplayComponent";
										range[]={8000,4000,2000,16000};
										resource="RscCustomInfoSensors";
									};
								};
							};
							class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightCommander
							{
								defaultDisplay="SensorDisplay";
								class Components: components
								{
									class SensorDisplay
									{
										componentType="SensorsDisplayComponent";
										range[]={8000,4000,2000,16000};
										resource="RscCustomInfoSensors";
									};
								};
							};
						};
						turretInfoType="RscOptics_MBT_01_commander";
					};
				};
			};
		};
		smokeLauncherOnTurret=1;
		class TransportMagazines
		{
		};
		class TransportItems
		{
		};
		class TransportWeapons
		{
		};
		class TransportBackpacks
		{
		};
	};
};
