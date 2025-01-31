class CfgPatches
{
	class FST_SaberTank
	{
		author="Daara";
		requiredaddons[]=
		{
		};
		requiredversion=1;
		units[]=
		{
			//"FST_Saber",
			"FST_Saber_Rancor",
			"FST_Saber_Jorge",
			//"FST_SuperSaber",
			"FST_SuperSaber_Rancor",
			"FST_SuperSaber_Jorge"
			//"FST_Saber_Fly"
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
class Optics_Gunner_APC_01: Optics_Armored
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
class cfgvehicles
{
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
		class Components;
		class CargoTurret;
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
	class Helicopter;
	class Helicopter_Base_F: Helicopter
	{
		class Turrets;
		class HitPoints;
	};
	class Helicopter_Base_H: Helicopter_Base_F
	{
		class CargoTurret;
		class ACE_selfActions;
		class Turrets: Turrets
		{
			class MainTurret;
		};
		class AnimationSources;
		class Eventhandlers;
		class Viewoptics;
		class ViewPilot;
		class RotorLibHelicopterProperties;
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitFuel;
			class HitEngine;
			class HitHRotor;
			class HitVRotor;
			class HitAvionics;
		};
	};
	class 3as_laat_Base: Helicopter_Base_H
	{
	};
	class FST_LAAT: 3as_laat_Base
	{
	};
	class 3as_saber_01_Base: Tank_F
	{
	};
	class FST_Saber: 3as_saber_01_Base
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		maximumLoad=5000;
		ace_cargo_space=30;
		ace_cargo_hasCargo=1;
		displayName="[41st] TX-130 Saber Tank";
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Trooper_P2_DC15S";
		editorPreview="\3as\3as_saber\images\3as_saber_m1.jpg";
		author="Daara";
		tas_canBlift=1;
		tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]";
		model="3as\3as_saber\model\tcw_tx130";
		steerAheadSimul=0.5;
		steerAheadPlan=0.34999999;
		predictTurnPlan=0.80000001;
		predictTurnSimul=0.60000002;
		brakeDistance=5;
		acceleration=15;
		turnCoef=2;
		canFloat=1;
		waterPPInVehicle=0;
		waterResistanceCoef=0.07;
		waterLeakiness=2.5;
		waterSpeedFactor=0.5;
		waterAngularDampingCoef=5;
		waterLinearDampingCoefY=2;
		waterLinearDampingCoefX=0.5;
		maxFordingDepth=0.5;
		waterResistance=1;
		fuelCapacity=45;
		maxBrakeTorque=85000;
		memoryPointDriverOptics[]=
		{
			"driverview"
		};
		driverOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
		spotableNightLightsOff=0.050000001;
		spotableNightLightsOn=4;
		visibleNightLightsOff=0.1;
		visibleNightLightsOn=0.2;
		extCameraPosition[]={0,3.5,-9};
		cost=1500000;
		damageResistance=0.079999998;
		crewVulnerable=0;
		armor=950;
		driverCanSee="4+8+2+32+16";
		gunnerCanSee="4+2+8+32+16";
		armorStructural=5;
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=4.5;
				material=-1;
				name="telo";
				visual="zbytek";
				passThrough=1;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.27500001;
			};
			class HitEngine: HitEngine
			{
				armor=0.60000002;
				material=-1;
				name="motor";
				passThrough=0.2;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.33000001;
			};
			class HitLTrack: HitLTrack
			{
				armor=1;
				material=-1;
				name="track_l_hit";
				passThrough=0;
				minimalHit=0.02;
				explosionShielding=0.30000001;
				radius=0.30000001;
			};
			class HitRTrack: HitRTrack
			{
				armor=1;
				material=-1;
				name="track_r_hit";
				passThrough=0;
				minimalHit=0.02;
				explosionShielding=0.30000001;
				radius=0.30000001;
			};
			class HitFuel: HitFuel
			{
				armor=0.5;
				material=-1;
				name="palivo";
				passThrough=0.1;
				minimalHit=0.1;
				explosionShielding=0.60000002;
				radius=0.25;
			};
		};
		class AnimationSources: AnimationSources
		{
			class Revolving
			{
				source="revolving";
				weapon="Missiles_DAGR";
			};
			class Select_Rockets
			{
				source="user";
				animPeriod=1e-007;
				initPhase=0;
			};
		};
		class Turrets: Turrets
		{
			class CargoTurret_01: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				canHideGunner=0;
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				gunnerName="$STR_A3_TURRETS_BENCH_R1";
				proxyIndex=1;
				soundAttenuationTurret="HeliAttenuationGunner";
				isPersonTurret=1;
				ejectDeadGunner=1;
				class dynamicViewLimits
				{
					CargoTurret_04[]={-65,95};
				};
				playerPosition=4;
				gunnerGetInAction="GetInHeli_Light_01bench";
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerCompartments="Compartment3";
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				gunnerName="$STR_A3_TURRETS_BENCH_L2";
				proxyIndex=2;
				class dynamicViewLimits
				{
					CargoTurret_03[]={-65,95};
				};
			};
			class CargoTurret_03: CargoTurret_02
			{
				gunnerCompartments="Compartment3";
				gunnerName="$STR_A3_TURRETS_BENCH_L1";
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				proxyIndex=3;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-95,65};
				};
			};
			class CargoTurret_04: CargoTurret_01
			{
				gunnerCompartments="Compartment2";
				gunnerName="$STR_A3_TURRETS_BENCH_R2";
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				proxyIndex=4;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,65};
				};
			};
			class MainTurret_top: MainTurret
			{
				class Turrets
				{
				};
				body="obTurret";
				gun="obGun";
				weapons[]=
				{
					"FST_Heavy_laser_Cannon",
					"FST_Medium_twin_laser_turret",
					"FST_Rapture_AGM_Missile",
					"FST_Stormfury_AA_Missile",
					"SmokeLauncher"
				};
				memoryPointGun[]=
				{
					"z_gunL_muzzle",
					"z_gunR_muzzle"
				};
				magazines[]=
				{
					"FST_100Rnd_Plasma_shells",
					"FST_100Rnd_Plasma_shells",
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"FST_Stormfury_12Rnd_AA_Missile",
					"FST_Rapture_12Rnd_AGM_Missile",
					"SmokeLauncherMag",
					"SmokeLauncherMag"
				};
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_best",
					0.0099999998,
					1,
					50
				};
				startEngine=0;
				hideWeaponsGunner=1;
				stabilizedInAxes=3;
				turretInfoType="RscWeaponRangeZeroing";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				selectionFireAnim="zasleh2";
				flash="gunfire";
				animationSourceBody="obTurret";
				animationSourceGun="obGun";
				discreteDistanceInitIndex=2;
				memoryPointGunnerOptics="commanderview";
				gunnerOpticsEffect[]={};
				gunnerForceOptics=0;
				visionMode[]=
				{
					"Normal"
				};
				thermalMode[]={};
				missileBeg="missleEnd";
				missileEnd="missleBeg";
				gunnerInOpticsShowCursor=1;
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
				gunnerOutOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
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
				gunnerAction="Saber_Driver";
				forceHideGunner=1;
				outGunnerMayFire=0;
				gunnerInAction="Saber_Driver";
				gunnerRightHandAnimName="";
				gunnerLeftHandAnimName="";
				gunnerFireAlsoInInternalCamera=1;
				gunnerOutFireAlsoInInternalCamera=1;
				proxyIndex=2;
				viewGunnerInExternal=1;
				proxytype="CPGunner";
				gunnername="Gunner";
				commanding=1;
				personTurretAction="vehicle_turnout_1";
				minOutElev=-10;
				maxOutElev=15;
				initOutElev=0;
				minOutTurn=-45;
				maxOutTurn=90;
				initOutTurn=0;
				minTurn=-15;
				maxTurn=15;
				initTurn=0;
				minElev=-8;
				maxElev=20;
				initElev=0;
				inGunnerMayFire=1;
				LODTurnedOut=1000;
				LODTurnedIn=1000;
				gunnerGetInAction="GetInHigh";
				gunnerGetOutAction="GetOutHigh";
				class HitPoints
				{
					class HitTurret
					{
						armor=1.2;
						material=-1;
						name="vez";
						visual="vez";
						passThrough=0;
						minimalHit=0.02;
						explosionShielding=0.30000001;
						radius=0.25;
					};
					class HitGun
					{
						armor=1.2;
						material=-1;
						name="zbran";
						visual="";
						passThrough=0;
						minimalHit=0;
						explosionShielding=1;
						radius=0.25;
					};
				};
				class ViewOptics: RCWSOptics
				{
					visionMode[]=
					{
						"Normal",
						"TI"
					};
				};
				class Components: Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftCommander
					{
						class Components: components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={200,400,800,1600};
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
								range[]={200,400,800,1600};
								resource="RscCustomInfoSensors";
							};
						};
					};
				};
			};
			class MainTurret_bottom: MainTurret_top
			{
				body="MainTurret";
				gun="MainGun";
				proxyIndex=1;
				gunnername="Commander";
				animationSourceBody="Mainturret";
				animationSourceGun="Maingun";
				AnimationSourceHatch="HatchCommander";
				minOutElev=-10;
				maxOutElev=15;
				initOutElev=0;
				minOutTurn=-360;
				maxOutTurn=360;
				initOutTurn=0;
				minTurn=-360;
				maxTurn=360;
				initTurn=0;
				minElev=-15;
				maxElev=15;
				initElev=0;
				gunnerAction="Saber_Commander_OUT";
				gunnerInAction="Saber_Commander_In";
				forceHideGunner=0;
				outGunnerMayFire=1;
				ingunnerMayFire=1;
				stabilizedInAxes=4;
				ispersonturret=0;
				enabledByAnimationSource="HatchCommander";
				gunnerRightHandAnimName="HandR";
				gunnerLeftHandAnimName="HandL";
				personTurretAction="vehicle_turnout_1";
				memoryPointGun[]=
				{
					"usti hlavne3",
					"usti hlavne4"
				};
				weapons[]=
				{
					"FST_Medium_twin_laser_turret",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
				};
				memoryPointGunnerOptics="gunnerview";
				gunnerHasFlares=1;
				gunnerOutOpticsShowCursor=1;
				maxHorizontalRotSpeed=1.2;
				class HitPoints
				{
					class HitTurret
					{
						armor=0.30000001;
						material=-1;
						name="Commander_Turret";
						visual="commander_turret";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.60000002;
						radius=0.25;
					};
					class HitGun
					{
						armor=0.30000001;
						material=-1;
						name="Commander_Gun";
						visual="Commander_Gun";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.60000002;
						radius=0.25;
					};
				};
				selectionFireAnim="zasleh3";
				class Turrets
				{
				};
				class Components: Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftCommander
					{
						class Components: components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={200,400,800,1600};
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
								range[]={200,400,800,1600};
								resource="RscCustomInfoSensors";
							};
						};
					};
				};
			};
		};
		class Damage
		{
			tex[]={};
			mat[]={};
		};
		smokeLauncherGrenadeCount=12;
		smokeLauncherVelocity=14;
		smokeLauncherOnTurret=1;
		smokeLauncherAngle=180;
		class ViewOptics: ViewOptics
		{
			visionMode[]=
			{
				"Normal",
				"TI"
			};
		};
		class Exhausts
		{
			class Exhaust_1
			{
				position="Exhaust_1_pos";
				direction="Exhaust_1_dir";
				effect="ExhaustsEffectHeliBig";
			};
			class Exhaust_2
			{
				position="Exhaust_2_pos";
				direction="Exhaust_2_dir";
				effect="ExhaustsEffectHeliBig";
			};
		};
		class Reflectors
		{
			class Left
			{
				color[]={1900,1300,950};
				ambient[]={5,5,5};
				position="Light_L";
				direction="Light_L_end";
				hitpoint="Light_L";
				selection="Light_L";
				size=1;
				innerAngle=100;
				outerAngle=179;
				coneFadeCoef=10;
				intensity=1;
				useFlare=1;
				dayLight=0;
				flareSize=1;
				class Attenuation
				{
					start=1;
					constant=0;
					linear=0;
					quadratic=0.25;
					hardLimitStart=30;
					hardLimitEnd=60;
				};
			};
			class Right: Left
			{
				position="Light_R";
				direction="Light_R_end";
				hitpoint="Light_R";
				selection="Light_R";
			};
			class Right2: Right
			{
				position="light_R_flare";
				useFlare=1;
			};
			class Left2: Left
			{
				position="light_L_flare";
				useFlare=1;
			};
		};
		aggregateReflectors[]=
		{
			
			{
				"Left",
				"Right",
				"Left2",
				"Right2"
			}
		};
		driverAction="Saber_Driver";
		driverInAction="Saber_Driver";
		viewDriverInExternal=1;
		proxytype="CPDriver";
		proxyIndex=1;
		forcehideDriver=1;
		DriverForceOptics=0;
		memoryPointTrack1L="Track LL";
		memoryPointTrack1R="Track LR";
		memoryPointTrack2L="Track RL";
		memoryPointTrack2R="Track RR";
		dustFrontLeftPos="dustFrontLeft";
		dustFrontRightPos="dustFrontRight";
		dustBackLeftPos="dustBackLeft";
		dustBackRightPos="dustBackRight";
		hiddenSelections[]=
		{
			"Camo1",
			"Camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\Saber\Data\Hull\41st_Saber_Hull_Co.paa",
			"41st_Vehicles\Saber\Data\Weapons\41st_Saber_Weapons_co.paa",
		};
		class TransportItems
			{
				class _xx_IDA_Cauterizer
				{
					name="IDA_Cauterizer";
					count=1;
				};
				class _xx_FST_Bacta_Tank
				{
					name="FST_Bacta_Tank";
					count=1;
				};
		};
		class _transport_ToolKit
		{
			name="ToolKit";
			count=2';
		};
	};
	class FST_Saber_Rancor: FST_Saber
	{	
		author="Gold";
		displayName="[41st] TX-130 Saber Tank (Rancor)";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\Saber\Data\Hull\41st_Saber_Hull_Rancor_co.paa",
			"41st_Vehicles\Saber\Data\Weapons\41st_Saber_Weapons_Rancor_co.paa",
		};
	};	
	class FST_Saber_Jorge: FST_Saber
	{	
		author="Gold";
		displayName="[41st] TX-130 Saber Tank (Jorge)";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\Saber\Data\Hull\41st_Saber_Hull_Jorge_co.paa",
			"41st_Vehicles\Saber\Data\Weapons\41st_Saber_Weapons_Jorge_co.paa",
		};
	};	
	class FST_SuperSaber: FST_Saber
	{
		scope=2;
		scopeCurator=2;
		side=1;
		faction="FST_Faction";
		displayName="[41st] TX-130 Super Saber Tank";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Trooper_P2_DC15S";
		editorPreview="\3as\3as_saber\images\3as_saber_m1.jpg";
		author="Daara";
		typicalCargo[]=
		{
			"JLTS_Clone_P2_DC15S"
		};
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		model="3AS\3AS_Saber\model\tcw_tx130_Super.p3d";
		tas_liftVars="[[[[0,-4,-6.5]]], [0.1], [-0.5]]";
		icon="3AS\3AS_Saber\data\ui\Saber_Super_top_ca.paa";	
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=4.5;
				material=-1;
				name="telo";
				visual="zbytek";
				passThrough=1;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.27500001;
			};
			class HitEngine: HitEngine
			{
				armor=0.60000002;
				material=-1;
				name="motor";
				passThrough=0.2;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.33000001;
			};
			class HitLTrack: HitLTrack
			{
				armor=1;
				material=-1;
				name="track_l_hit";
				passThrough=0;
				minimalHit=0.02;
				explosionShielding=0.30000001;
				radius=0.30000001;
			};
			class HitRTrack: HitRTrack
			{
				armor=1;
				material=-1;
				name="track_r_hit";
				passThrough=0;
				minimalHit=0.02;
				explosionShielding=0.30000001;
				radius=0.30000001;
			};
			class HitFuel: HitFuel
			{
				armor=0.5;
				material=-1;
				name="palivo";
				passThrough=0.1;
				minimalHit=0.1;
				explosionShielding=0.60000002;
				radius=0.25;
			};
		};
		class Turrets: Turrets
		{
			class Mainturret_Super: Mainturret_top
			{
				body="MainTurret_Super";
				gun="Maingun_Super";
				animationSourceBody="MainTurret_Super";
				animationSourceGun="Maingun_Super";
				weapons[]=
				{
					"3AS_Sabre_Cannons_Super",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"3AS_25rnd_Sabre_Super_Mag",
					"3AS_25rnd_Sabre_Super_Mag",
					"3AS_25rnd_Sabre_Super_Mag",
					"3AS_25rnd_Sabre_Super_Mag",
					"3AS_25rnd_Sabre_Super_Mag",
				};
				minTurn=-360;
				maxTurn=360;
				initTurn=0;
				minElev=-10;
				maxElev=30;
				initElev=0;
				proxytype="CPGunner";
				gunnername="Gunner";
				proxyIndex=2;
				gunnerAction="Saber_Driver";
				gunnerInAction="Saber_Driver";
				forceHideGunner=1;
				outGunnerMayFire=0;
				inGunnerMayFire=1;
				gunnerRightHandAnimName="konec hlavne3";
				gunnerLeftHandAnimName="konec hlavne3";
				soundAttenuationTurret="HeliAttenuationGunner";
				memoryPointGun[]=
				{
					"usti hlavne3",
					"usti hlavne4"
				};
				memoryPointGunnerOptics="SuperSabergunnerview";
				gunnerOpticsEffect[]={};
				gunnerHasFlares=1;
			};
			class CargoTurret_01: CargoTurret_01
			{
			};
			class CargoTurret_02: CargoTurret_02
			{
			};
			class CargoTurret_03: CargoTurret_03
			{
			};
			class CargoTurret_04: CargoTurret_04
			{
			};
		};
	};
	class FST_SuperSaber_Rancor: FST_SuperSaber
	{	
		author="Gold";
		displayName="[41st] TX-130 Super Saber Tank (Rancor)";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\Saber\Data\Hull\41st_Saber_Hull_Rancor_co.paa",
			"41st_Vehicles\Saber\Data\Weapons\41st_Saber_Weapons_Rancor_co.paa",
		};
	};	
	class FST_SuperSaber_Jorge: FST_SuperSaber
	{	
		author="Gold";
		displayName="[41st] TX-130 Super Saber Tank (Jorge)";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\Saber\Data\Hull\41st_Saber_Hull_Jorge_co.paa",
			"41st_Vehicles\Saber\Data\Weapons\41st_Saber_Weapons_Jorge_co.paa",
		};
	};	
	class FST_Saber_Fly: FST_LAAT
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		maximumLoad=5000;
		ace_cargo_space=30;
		ace_cargo_hasCargo=1;
		altFullForce=14;
		altNoForce=20;
		displayName="[41st] TX-130 Saber Tank (Fly)";
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Trooper_P2_DC15S";
		editorPreview="\3as\3as_saber\images\3as_saber_m1.jpg";
		author="Daara";
		tas_canBlift=1;
		tas_can_impulse=0;
		tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]";
		model="3as\3as_saber\model\tcw_tx130";
		steerAheadSimul=0.5;
		steerAheadPlan=0.34999999;
		predictTurnPlan=0.80000001;
		predictTurnSimul=0.60000002;
		brakeDistance=5;
		acceleration=15;
		turnCoef=2;
		canFloat=1;
		waterPPInVehicle=0;
		waterResistanceCoef=0.07;
		waterLeakiness=2.5;
		waterSpeedFactor=0.5;
		waterAngularDampingCoef=5;
		waterLinearDampingCoefY=2;
		waterLinearDampingCoefX=0.5;
		maxFordingDepth=0.5;
		waterResistance=1;
		fuelCapacity=45;
		maxBrakeTorque=85000;
		memoryPointDriverOptics[]=
		{
			"driverview"
		};
		driverOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
		spotableNightLightsOff=0.050000001;
		spotableNightLightsOn=4;
		visibleNightLightsOff=0.1;
		visibleNightLightsOn=0.2;
		extCameraPosition[]={0,3.5,-9};
		cost=1500000;
		damageResistance=0.079999998;
		crewVulnerable=0;
		armor=950;
		driverCanSee="4+8+2+32+16";
		gunnerCanSee="4+2+8+32+16";
		armorStructural=5;
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=4.5;
				material=-1;
				name="telo";
				visual="zbytek";
				passThrough=1;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.27500001;
			};
			class HitEngine: HitEngine
			{
				armor=0.60000002;
				material=-1;
				name="motor";
				passThrough=0.2;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.33000001;
			};
			class HitFuel: HitFuel
			{
				armor=0.5;
				material=-1;
				name="palivo";
				passThrough=0.1;
				minimalHit=0.1;
				explosionShielding=0.60000002;
				radius=0.25;
			};
		};
		class AnimationSources: AnimationSources
		{
			class Revolving
			{
				source="revolving";
				weapon="Missiles_DAGR";
			};
			class Select_Rockets
			{
				source="user";
				animPeriod=1e-007;
				initPhase=0;
			};
		};
		class Turrets: Turrets
		{
			class CargoTurret_01: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				canHideGunner=0;
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				gunnerName="$STR_A3_TURRETS_BENCH_R1";
				proxyIndex=1;
				soundAttenuationTurret="HeliAttenuationGunner";
				isPersonTurret=1;
				ejectDeadGunner=1;
				class dynamicViewLimits
				{
					CargoTurret_04[]={-65,95};
				};
				playerPosition=4;
				gunnerGetInAction="GetInHeli_Light_01bench";
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerCompartments="Compartment3";
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				gunnerName="$STR_A3_TURRETS_BENCH_L2";
				proxyIndex=2;
				class dynamicViewLimits
				{
					CargoTurret_03[]={-65,95};
				};
			};
			class CargoTurret_03: CargoTurret_02
			{
				gunnerCompartments="Compartment3";
				gunnerName="$STR_A3_TURRETS_BENCH_L1";
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				proxyIndex=3;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-95,65};
				};
			};
			class CargoTurret_04: CargoTurret_01
			{
				gunnerCompartments="Compartment2";
				gunnerName="$STR_A3_TURRETS_BENCH_R2";
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				proxyIndex=4;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,65};
				};
			};
			class MainTurret_top: MainTurret
			{
				class Turrets
				{
				};
				body="obTurret";
				gun="obGun";
				weapons[]=
				{
					"FST_Heavy_laser_Cannon",
					"FST_Medium_twin_laser_turret",
					"FST_Rapture_AGM_Missile",
					"FST_Stormfury_AA_Missile",
					"SmokeLauncher"
				};
				memoryPointGun[]=
				{
					"z_gunL_muzzle",
					"z_gunR_muzzle"
				};
				magazines[]=
				{
					"FST_100Rnd_Plasma_shells",
					"FST_100Rnd_Plasma_shells",
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"FST_Stormfury_12Rnd_AA_Missile",
					"FST_Rapture_12Rnd_AGM_Missile",
					"SmokeLauncherMag",
					"SmokeLauncherMag"
				};
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_best",
					0.0099999998,
					1,
					50
				};
				startEngine=0;
				hideWeaponsGunner=1;
				stabilizedInAxes=3;
				turretInfoType="RscWeaponRangeZeroing";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				selectionFireAnim="zasleh2";
				flash="gunfire";
				animationSourceBody="obTurret";
				animationSourceGun="obGun";
				discreteDistanceInitIndex=2;
				memoryPointGunnerOptics="commanderview";
				gunnerOpticsEffect[]={};
				gunnerForceOptics=0;
				visionMode[]=
				{
					"Normal"
				};
				thermalMode[]={};
				missileBeg="missleEnd";
				missileEnd="missleBeg";
				gunnerInOpticsShowCursor=1;
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
				gunnerOutOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
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
				gunnerAction="Saber_Driver";
				forceHideGunner=1;
				outGunnerMayFire=0;
				gunnerInAction="Saber_Driver";
				gunnerRightHandAnimName="";
				gunnerLeftHandAnimName="";
				gunnerFireAlsoInInternalCamera=1;
				gunnerOutFireAlsoInInternalCamera=1;
				proxyIndex=2;
				viewGunnerInExternal=1;
				proxytype="CPGunner";
				gunnername="Gunner";
				commanding=1;
				personTurretAction="vehicle_turnout_1";
				minOutElev=-10;
				maxOutElev=15;
				initOutElev=0;
				minOutTurn=-45;
				maxOutTurn=90;
				initOutTurn=0;
				minTurn=-15;
				maxTurn=15;
				initTurn=0;
				minElev=-8;
				maxElev=20;
				initElev=0;
				inGunnerMayFire=1;
				LODTurnedOut=1000;
				LODTurnedIn=1000;
				gunnerGetInAction="GetInHigh";
				gunnerGetOutAction="GetOutHigh";
				class HitPoints
				{
					class HitTurret
					{
						armor=1.2;
						material=-1;
						name="vez";
						visual="vez";
						passThrough=0;
						minimalHit=0.02;
						explosionShielding=0.30000001;
						radius=0.25;
					};
					class HitGun
					{
						armor=1.2;
						material=-1;
						name="zbran";
						visual="";
						passThrough=0;
						minimalHit=0;
						explosionShielding=1;
						radius=0.25;
					};
				};
				class ViewOptics: RCWSOptics
				{
					visionMode[]=
					{
						"Normal",
						"TI"
					};
				};
/* 				class Components: Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftCommander
					{
						class Components: components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={200,400,800,1600};
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
								range[]={200,400,800,1600};
								resource="RscCustomInfoSensors";
							};
						};
					};
				}; */
			};
			class MainTurret_bottom: MainTurret_top
			{
				body="MainTurret";
				gun="MainGun";
				proxyIndex=1;
				gunnername="Commander";
				animationSourceBody="Mainturret";
				animationSourceGun="Maingun";
				AnimationSourceHatch="HatchCommander";
				minOutElev=-10;
				maxOutElev=15;
				initOutElev=0;
				minOutTurn=-360;
				maxOutTurn=360;
				initOutTurn=0;
				minTurn=-360;
				maxTurn=360;
				initTurn=0;
				minElev=-15;
				maxElev=15;
				initElev=0;
				gunnerAction="Saber_Commander_OUT";
				gunnerInAction="Saber_Commander_In";
				forceHideGunner=0;
				outGunnerMayFire=1;
				ingunnerMayFire=1;
				stabilizedInAxes=4;
				ispersonturret=0;
				enabledByAnimationSource="HatchCommander";
				gunnerRightHandAnimName="HandR";
				gunnerLeftHandAnimName="HandL";
				personTurretAction="vehicle_turnout_1";
				memoryPointGun[]=
				{
					"usti hlavne3",
					"usti hlavne4"
				};
				weapons[]=
				{
					"FST_Medium_twin_laser_turret",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
				};
				memoryPointGunnerOptics="gunnerview";
				gunnerHasFlares=1;
				gunnerOutOpticsShowCursor=1;
				maxHorizontalRotSpeed=0.61500001;
				class HitPoints
				{
					class HitTurret
					{
						armor=0.30000001;
						material=-1;
						name="Commander_Turret";
						visual="commander_turret";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.60000002;
						radius=0.25;
					};
					class HitGun
					{
						armor=0.30000001;
						material=-1;
						name="Commander_Gun";
						visual="Commander_Gun";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.60000002;
						radius=0.25;
					};
				};
				selectionFireAnim="zasleh3";
				class Turrets
				{
				};
/* 				class Components: Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftCommander
					{
						class Components: components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={200,400,800,1600};
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
								range[]={200,400,800,1600};
								resource="RscCustomInfoSensors";
							};
						};
					};
				}; */
			};
		};
		class Damage
		{
			tex[]={};
			mat[]={};
		};
		smokeLauncherGrenadeCount=12;
		smokeLauncherVelocity=14;
		smokeLauncherOnTurret=1;
		smokeLauncherAngle=180;
		class ViewOptics: ViewOptics
		{
			visionMode[]=
			{
				"Normal",
				"TI"
			};
		};
		class Exhausts
		{
			class Exhaust_1
			{
				position="Exhaust_1_pos";
				direction="Exhaust_1_dir";
				effect="ExhaustsEffectHeliBig";
			};
			class Exhaust_2
			{
				position="Exhaust_2_pos";
				direction="Exhaust_2_dir";
				effect="ExhaustsEffectHeliBig";
			};
		};
		class Reflectors
		{
			class Left
			{
				color[]={1900,1300,950};
				ambient[]={5,5,5};
				position="Light_L";
				direction="Light_L_end";
				hitpoint="Light_L";
				selection="Light_L";
				size=1;
				innerAngle=100;
				outerAngle=179;
				coneFadeCoef=10;
				intensity=1;
				useFlare=1;
				dayLight=0;
				flareSize=1;
				class Attenuation
				{
					start=1;
					constant=0;
					linear=0;
					quadratic=0.25;
					hardLimitStart=30;
					hardLimitEnd=60;
				};
			};
			class Right: Left
			{
				position="Light_R";
				direction="Light_R_end";
				hitpoint="Light_R";
				selection="Light_R";
			};
			class Right2: Right
			{
				position="light_R_flare";
				useFlare=1;
			};
			class Left2: Left
			{
				position="light_L_flare";
				useFlare=1;
			};
		};
		aggregateReflectors[]=
		{
			
			{
				"Left",
				"Right",
				"Left2",
				"Right2"
			}
		};
		driverAction="Saber_Driver";
		driverInAction="Saber_Driver";
		viewDriverInExternal=1;
		proxytype="CPDriver";
		proxyIndex=1;
		forcehideDriver=1;
		DriverForceOptics=0;
		memoryPointTrack1L="Track LL";
		memoryPointTrack1R="Track LR";
		memoryPointTrack2L="Track RL";
		memoryPointTrack2R="Track RR";
		dustFrontLeftPos="dustFrontLeft";
		dustFrontRightPos="dustFrontRight";
		dustBackLeftPos="dustBackLeft";
		dustBackRightPos="dustBackRight";
		hiddenSelections[]=
		{
			"Camo1",
			"Camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\Saber\Data\Hull\41st_Saber_Hull_Co.paa",
			"41st_Vehicles\Saber\Data\Weapons\41st_Saber_Weapons_co.paa",
		};
		class TransportItems
		{
			class _transport_ToolKit
			{
				name="ToolKit";
				count=2;
			};
		};
	};
};
class CfgAmmo
{
	class IDA_thermal_shell;
	class FST_100mm_thermal_shells: IDA_thermal_shell
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Blue_Fly";
		JLTS_isEMPAmmo=0;
		hit=100;
		indirectHit=50;
		explosive=1;
		indirectHitRange=5;
		caliber=2;
	};	
};
class CfgMagazines
{
	class VehicleMagazine;
	class FST_500Rnd_High_Capacity_Plasma_Cell: VehicleMagazine
	{
		displayname="500Rnd High Capacity plasma cell";
		displaynameshort="HC Plasma Cell";
		scope=2;
		count=500;
		ammo="FST_blasterbolt_Overcharged_Blue";
		initSpeed=910;
		maxLeadSpeed=36.111099;
		tracersEvery=1;
		nameSound="mgun";
		muzzleImpulseFactor[]={0.050000001,0.050000001};
	};
	class FST_100Rnd_Plasma_shells: VehicleMagazine
	{
		scope=2;
		displayName="[41st] 100 Medium HE Shells";
		displayNameShort="MHES";
		ammo="FST_thermal_shell_HP_Green";
		count=100;
		initSpeed=1430;
		maxLeadSpeed=83.333298;
		nameSound="cannon";
		tracersEvery=1;
		muzzleImpulseFactor[]={0.050000001,0.050000001};
	};
};
class Mode_FullAuto;
class CfgWeapons
{
	class CannonCore;
	class MGun;
	class LMG_RCWS: MGun
	{
		class manual: MGun
		{
		};
		class close: manual
		{
		};
		class short: close
		{
		};
		class medium: close
		{
		};
		class far: close
		{
		};
	};
	class LMG_M200: LMG_RCWS
	{
	};
	class FST_Medium_twin_laser_turret: LMG_RCWS
	{
		displayName="[41st] Medium Twin Laser Turret";
		author="Daara";
		descriptionShort="LDC";
		magazines[]=
		{
			"FST_500Rnd_High_Capacity_Plasma_Cell"
		};
		muzzleEnd="konec hlavne3";
		muzzlePos="usti hlavne3";
		selectionFireAnim="zasleh3";
		modes[]=
		{
			"FullAuto",
		};
		cursor="EmptyCursor";
		class FullAuto: Mode_FullAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				soundsetshot[]=
				{
					"3AS_Z6_SoundSet"
				};
			};
			soundContinuous=0;
			soundBurst=0;
			reloadTime=0.0795;
			aiRateOfFire=1;
			aiRateOfFireDistance=10;
			minRange=0;
			minRangeProbab=0.0099999998;
			midRange=1;
			midRangeProbab=0.0099999998;
			maxRange=2;
			maxRangeProbab=0.0099999998;
		};
	};
	class FST_Heavy_laser_Cannon: CannonCore
	{
		displayName="[41st] Heavy Laser Cannon";
		author="Daara";
		descriptionShort="HLC";
		magazines[]=
		{
			"FST_100Rnd_Plasma_shells"
		};
		muzzleEnd="konec hlavne3";
		muzzlePos="usti hlavne3";
		selectionFireAnim="zasleh3";
		modes[]=
		{
			"FullAuto",
		};
		cursor="EmptyCursor";
		class FullAuto: Mode_FullAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				begin1[]=
				{
					"swlg_clones_tanks\tx130\data\sounds\Saber_heavy_shot.wss",
					3.1622777,
					1,
					1500
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			soundContinuous=0;
			reloadTime=2;
			magazineReloadTime=4;
			autoReload=1;
			autoFire=0;
			dispersion=0.00056999997;
			aiRateOfFire=1;
			aiRateOfFireDistance=10;
			minRange=0;
			minRangeProbab=0.0099999998;
			midRange=1;
			midRangeProbab=0.0099999998;
			maxRange=2;
			maxRangeProbab=0.0099999998;
		};
	};
};
