#include "Sounds\FST_Vehicles_Land_APC_SabreAPC_Sounds.hpp"

class CfgPatches
{
	class FST_Vehicles_Land_SabreAPC
	{
		requiredAddons[]=
		{
			"FST_Common",
			"FST_Core",
			"FST_Vehicles_Weapons",
			"A3_Armor_F_Gamma"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_Vehicle_Land_SabreAPC"
		};
		weapons[]={};
	};
};
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateNV;
class SensorTemplateDataLink;
class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftDriver: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightDriver: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
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
class CfgVehicles
{
	class LandVehicle;
	class Tank: LandVehicle
	{
		class NewTurret;
		class Sounds;
		class HitPoints;
		class ACE_SelfActions;
	};
	class Tank_F: Tank
	{
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class Turrets
				{
					class CommanderOptics;
				};
			};
		};
		class Components;
		class AnimationSources;
		class ViewPilot;
		class CargoTurret;
		class ViewOptics;
		class ViewGunner;
		class ViewCargo;
		class HeadLimits;
		class ACE_SelfActions: ACE_SelfActions{};
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitEngine;
			class HitLTrack;
			class HitRTrack;
			class HitFuel;
		};
		class Sounds: Sounds
		{
			class Engine;
			class Movement;
		};
	};
	class FST_Vehicle_Land_Base: Tank_F
	{
		//3AS Declerations
		tas_canBlift = 1;
		tas_liftVars = "[[[[0,-4,-4]]], [0.1], [-0.5]]";
		//Regular Configurations
		author="Maldova";
		mapSize=35.0001;
		simulation="tankX";
		mass=23500;
		fuelCapacity=80;
		brakeIdleSpeed=0.2;
		maxSpeed=90;
		normalSpeedForwardCoef=0.62;
		slowSpeedForwardCoef=0.31;
		engineMOI=14;
		enginePower=2150;
		maxOmega=345.57501;
		minOmega=146.608;
		redRpm=7500;
		idleRpm=850;
		peakTorque=17500;
		torqueCurve[]=
		{
			{0,0},

			{
				"(1600/2640)",
				"(2650/2850)"
			},

			{
				"(1800/2640)",
				"(2800/2850)"
			},

			{
				"(1900/2640)",
				"(2850/2850)"
			},

			{
				"(2000/2640)",
				"(2800/2850)"
			},

			{
				"(2200/2640)",
				"(2750/2850)"
			},

			{
				"(2400/2640)",
				"(2600/2850)"
			},

			{
				"(2640/2640)",
				"(2350/2850)"
			}
		};
		thrustDelay=0.2;
		dampingRateFullThrottle=0.42;
		dampingRateZeroThrottleClutchEngaged=1.45;
		dampingRateZeroThrottleClutchDisengaged=0.25;
		clutchStrength=170;
		latency=0.14;
		switchTime=0;
		changeGearType="rpmratio";
		changeGearOmegaRatios[]={1,0.42424199,0.45454499,0.33333299,0.939394,0.42424199,0.909091,0.63636398,0.84848499,0.66666698,1,0.66666698};
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R2",
				-0.8,
				"N",
				0,
				"D1",
				4.6999998,
				"D2",
				3.5,
				"D3",
				2.5999999,
				"D4",
				2,
				"D5",
				1.5,
				"D6",
				1.125,
				"D7",
				0.85000002
			};
			TransmissionRatios[]=
			{
				"High",
				5.5
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
			transmissionDelay=0.25;
		};
		antiRollbarForceCoef=10;
		antiRollbarForceLimit=22;
		antiRollbarSpeedMin=5;
		antiRollbarSpeedMax=55;
		tankTurnForce=56000;
		tankTurnForceAngMinSpd=0;
		tankTurnForceAngSpd=0.07;
		accelAidForceCoef=0.009;
		accelAidForceYOffset=-0.5;
		accelAidForceSpd=0.2;
		class Sounds
		{
			class Idle_ext
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idle.ogg",1,1,480};
				frequency = "0.95 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume = "engineOn*camPos*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class Engine
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idle.ogg",1.1,1,550};
				frequency = "0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume = "engineOn*camPos*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_ext
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idle.ogg",1.4,1,550};
				frequency = "0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume = "engineOn*camPos*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_ext
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idle.ogg",1.5,1,550};
				frequency = "0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume = "engineOn*camPos*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_ext
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idle.ogg",1.5,1,550};
				frequency = "0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume = "engineOn*camPos*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_ext
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idle.ogg",1.5,1,550};
				frequency = "0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume = "engineOn*camPos*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_ext
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idle.ogg",1.5,1,550};
				frequency = "0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume = "engineOn*camPos*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class IdleThrust
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idle.ogg",2.8,1,550};
				frequency = "0.8 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class EngineThrust
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idle.ogg",1.5,1,550};
				frequency = "0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_Thrust_ext
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idle.ogg",1.5,1,550};
				frequency = "0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_Thrust_ext
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idle.ogg",1.5,1,550};
				frequency = "0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_Thrust_ext
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idle.ogg",1.5,1,550};
				frequency = "0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_Thrust_ext
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idle.ogg",1.5,1,550};
				frequency = "0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_Thrust_ext
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idle.ogg",1.5,1,550};
				frequency = "0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class Idle_int
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idlein.ogg",1.5,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume = "engineOn*(1-camPos)*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class Engine_int
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idlein.ogg",1,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_int
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idlein.ogg",1,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_int
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idlein.ogg",1,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_int
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idlein.ogg",1,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume = "engineOn*(1-camPos)*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_int
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idlein.ogg",1.1,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume = "engineOn*(1-camPos)*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_int
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idlein.ogg",1.25,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume = "engineOn*(1-camPos)*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class IdleThrust_int
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idlein.ogg",1.25,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class EngineThrust_int
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idlein.ogg",1,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_Thrust_int
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idlein.ogg",1,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_Thrust_int
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idlein.ogg",1,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_Thrust_int
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idlein.ogg",2,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_Thrust_int
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idlein.ogg",2.24404,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_Thrust_int
			{
				sound[] = {"3as\3as_saber\Sounds\tx130idlein.ogg",2.51785,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class NoiseInt
			{
				sound[] = {"A3\sounds_f\vehicles\armor\noises\noise_tank_int_1",0.501187,1};
				frequency = "1";
				volume = "(1-camPos)*(angVelocity max 0.04)*(speed factor[4, 15])";
			};
			class NoiseExt
			{
				sound[] = {"A3\sounds_f\vehicles\armor\noises\noise_tank_ext_1",0.891251,1,50};
				frequency = "1";
				volume = "camPos*(angVelocity max 0.04)*(speed factor[4, 15])";
			};
			class ThreadsOutH0
			{
				sound[] = {"",0.398107,1,140};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsOutH1
			{
				sound[] = {"",0.446684,1,160};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsOutH2
			{
				sound[] = {"",0.501187,1,180};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsOutH3
			{
				sound[] = {"",0.562341,1,200};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsOutH4
			{
				sound[] = {"",0.562341,1,220};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class ThreadsOutS0
			{
				sound[] = {"",0.316228,1,120};
				frequency = "1";
				volume = "engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsOutS1
			{
				sound[] = {"",0.354813,1,140};
				frequency = "1";
				volume = "engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsOutS2
			{
				sound[] = {"",0.398107,1,160};
				frequency = "1";
				volume = "engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsOutS3
			{
				sound[] = {"",0.446684,1,180};
				frequency = "1";
				volume = "engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsOutS4
			{
				sound[] = {"",0.501187,1,200};
				frequency = "1";
				volume = "engineOn*(camPos)*(grass)*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class ThreadsInH0
			{
				sound[] = {"",0.251189,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsInH1
			{
				sound[] = {"",0.281838,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsInH2
			{
				sound[] = {"",0.316228,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsInH3
			{
				sound[] = {"",0.354813,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsInH4
			{
				sound[] = {"",0.398107,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class ThreadsInS0
			{
				sound[] = {"",0.316228,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsInS1
			{
				sound[] = {"",0.316228,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsInS2
			{
				sound[] = {"",0.354813,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsInS3
			{
				sound[] = {"",0.354813,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsInS4
			{
				sound[] = {"",0.398107,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
		};
		class Wheels
		{
			class L2
			{
				boneName = "wheel_podkoloL1";
				center = "wheel_1_2_axis";
				boundary = "wheel_1_2_bound";
				suspTravelDirection[] = {0,-1,0};
				damping = 90;
				steering = 0;
				side = "left";
				weight = 90;
				mass = 180;
				MOI = 12;
				latStiffX = 2;
				latStiffY = 24;
				longitudinalStiffnessPerUnitGravity = 7800;
				maxBrakeTorque = 13000;
				sprungMass = -1;
				springStrength = 17000;
				springDamperRate = 15000;
				dampingRate = 4.8;
				dampingRateInAir = 450;
				dampingRateDamaged = 8;
				dampingRateDestroyed = 400;
				maxDroop = 0.09;
				maxCompression = 0.09;
				frictionVsSlipGraph[] =
				{
					{0,0.6},
					{0.5,1},
					{1,0.75}
				};
			};
			class L3: L2
			{
				boneName = "wheel_podkolol2";
				center = "wheel_1_3_axis";
				boundary = "wheel_1_3_bound";
			};
			class L4: L2
			{
				boneName = "wheel_podkolol3";
				center = "wheel_1_4_axis";
				boundary = "wheel_1_4_bound";
			};
			class L5: L2
			{
				boneName = "wheel_podkolol4";
				center = "wheel_1_5_axis";
				boundary = "wheel_1_5_bound";
			};
			class L6: L2
			{
				boneName = "wheel_podkolol5";
				center = "wheel_1_6_axis";
				boundary = "wheel_1_6_bound";
			};
			class L7: L2
			{
				boneName = "wheel_podkolol6";
				center = "wheel_1_7_axis";
				boundary = "wheel_1_7_bound";
			};
			class R2: L2
			{
				boneName = "wheel_podkolop1";
				center = "wheel_2_2_axis";
				boundary = "wheel_2_2_bound";
				side = "right";
			};
			class R3: R2
			{
				boneName = "wheel_podkolop2";
				center = "wheel_2_3_axis";
				boundary = "wheel_2_3_bound";
			};
			class R4: R2
			{
				boneName = "wheel_podkolop3";
				center = "wheel_2_4_axis";
				boundary = "wheel_2_4_bound";
			};
			class R5: R2
			{
				boneName = "wheel_podkolop4";
				center = "wheel_2_5_axis";
				boundary = "wheel_2_5_bound";
			};
			class R6: R2
			{
				boneName = "wheel_podkolop5";
				center = "wheel_2_6_axis";
				boundary = "wheel_2_6_bound";
			};
			class R7: R2
			{
				boneName = "wheel_podkolop6";
				center = "wheel_2_7_axis";
				boundary = "wheel_2_7_bound";
			};
		};
		editorcategory="FST_Catagory_Vehicles_Land";
		editorSubcategory="FST_Catagory_Vehicles_Land_APC";
		scope=0;
		hasCommander=1;
		commanderCanSee=31;
		commanderForceOptics=0;
		memoryPointDriverOptics[]={"driverview"};
		driverOpticsModel="\A3\weapons_f\reticle\optics_empty";
		driverForceOptics=0;
		driverInfoPanelCameraPos="driverview";
		driverLeftHandAnimName="drivewheel";
		driverRightHandAnimName="drivewheel";
		driverLeftLegAnimName="pedal_brake";
		driverRightLegAnimName="pedal_thrust";
		viewDriverShadowAmb=0.5;
		viewDriverShadowDiff=0.050000001;
		transportSoldier=0;
		cargoProxyIndexes[]={};
		memoryPointsGetInDriver="pos driver";
		memoryPointsGetInDriverDir="pos driver dir";
		memoryPointsGetInCargo="pos driver";
		memoryPointsGetInCargoDir="pos driver dir";
		getInAction="GetInLow";
		getOutAction="GetOutLow";
		cargoGetInAction[]=
		{
			"GetInLow"
		};
		cargoGetOutAction[]=
		{
			"GetOutLow"
		};
		cargoAction[]=
		{
			"passenger_apc_narrow_generic01",
			"passenger_apc_narrow_generic02",
			"passenger_apc_narrow_generic03",
			"passenger_apc_narrow_generic01",
			"passenger_apc_narrow_generic02",
			"passenger_apc_narrow_generic03"
		};
		maxFordingDepth=0.5;
		waterResistance=9.9999997e-005;
		waterDamageEngine=0;
		LODDriverTurnedin=1100;
		LODDriverTurnedOut=0;
		LODDriverOpticsIn=1202;
		driverAction="Driver_MBT_03_cannon_F_out";
		driverInAction="Driver_MBT_03_cannon_F_in";
		extCameraPosition[]={0,3,-9};
		forceHideDriver=1;
		forceHideCargo=0;
		viewDriverInExternal=1;
		class ViewOptics: ViewOptics
		{
			visionMode[]=
			{
				"Normal",
				"NVG"
			};
			initFov=0.25;
			minFov=0.15000001;
			maxFov=0.25;
		};
		class ViewPilot: ViewPilot
		{
			initAngleX=-3;
			initAngleY=0;
			initFov=0.89999998;
			minFov=0.25;
			maxFov=1.25;
			minAngleX=-75;
			maxAngleX=75;
			minAngleY=-150;
			maxAngleY=150;
			minMoveX=0;
			maxMoveX=0;
			minMoveY=-0.075000003;
			maxMoveY=0.075000003;
			minMoveZ=-0.075000003;
			maxMoveZ=0.1;
		};
		armor=1750;
		armorLights=0.2;
		armorStructural=7;
		crewExplosionProtection=0.99989998;
		damageResistance=0.0054700002;
		cost=2500000;
		crewVulnerable=0;
		epeImpulseDamageCoef=18;
		waterPPInVehicle=0;
		canFloat=1;
		waterResistanceCoef=0.001;
		waterLeakiness=0;
		waterSpeedFactor=1.2;
		waterAngularDampingCoef=15;
		waterLinearDampingCoefX=10;
		waterLinearDampingCoefY=15;
		engineShiftY=0.8;
		wheelCircumference=2.1500001;
		tracksSpeed=1.4;
		model="FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\FST_Vehicles_Land_APC_SabreAPC_Model.p3d";
		picture="FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Icons\FST_Vehicles_Land_APC_SabreAPC_EditorPreview.jpg";
		Icon="FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Icons\FST_Vehicles_Land_APC_SabreAPC_Icon.paa";
		memoryPointTaskMarker="TaskMarker_1_pos";
		hideWeaponsDriver=1;
		hideWeaponsCargo=0;
		weapons[]={"FST_SabreAPC_Horn"};
		memoryPointGun="";
		memoryPointGunDir="";
		magazines[]={};
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=5.300001;
				material=-1;
				armorComponent="hit_hull";
				name="hit_hull_point";
				visual="zbytek";
				passThrough=1;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.30000001;
			};
			class HitEngine: HitEngine
			{
				armor=0.60000001;
				material=-1;
				armorComponent="hit_engine";
				name="hit_engine_point";
				visual="-";
				passThrough=0.2;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.30000001;
			};
			class HitFuel: HitFuel
			{
				armor=0.50000001;
				material=-1;
				armorComponent="hit_fuel";
				name="hit_fuel_point";
				visual="-";
				passThrough=0.1;
				minimalHit=0.1;
				explosionShielding=0.60000002;
				radius=0.30000001;
			};
			class HitLTrack: HitLTrack
			{
				armor = 0.8;
				material = -1;
				name = "track_l_hit";
				passThrough = 0;
				minimalHit = 0.08;
				explosionShielding = 0.8;
				radius = 0.3;
			};
			class HitRTrack: HitRTrack
			{
				armor = 0.8;
				material = -1;
				name = "track_r_hit";
				passThrough = 0;
				minimalHit = 0.08;
				explosionShielding = 0.8;
				radius = 0.3;
			};
		};
		animationSourceHatch="main_hatch_rotate";
		class Exhausts
		{
			class Exhaust1
			{
				position="exhaust_1_pos";
				direction="exhaust_1_dir";
				effect="ExhaustsEffectAMV";
			};
			class Exhaust2
			{
				position="exhaust_2_pos";
				direction="exhaust_2_dir";
				effect="ExhaustsEffectAMV";
			};
		};
		class Reflectors
		{
			class DriverLongBeam
			{
				color[]={1900,1300,950};
				ambient[]={5,5,5};
				position="Emissive_03";
				direction="Emissive_03_Dir";
				hitpoint="Emissive_03";
				selection="Emissive_03";
				size=1;
				innerAngle=12;
				outerAngle=30;
				coneFadeCoef=10;
				intensity=6;
				useFlare=1;
				dayLight=0;
				flareSize=1;
				class Attenuation
				{
					start=1;
					constant=0;
					linear=0;
					quadratic=0.1;
					hardLimitStart=75;
					hardLimitEnd=180;
				};
			};
			class DriverLeft: DriverLongBeam
			{
				position="Emissive_04";
				direction="Emissive_04_Dir";
				hitpoint="Emissive_04";
				selection="Emissive_04";
				innerAngle=60;
				outerAngle=120;
				intensity=2;
				class Attenuation
				{
					start=1;
					constant=0;
					linear=0;
					quadratic=0.2;
					hardLimitStart=35;
					hardLimitEnd=90;
				};
			};
			class DriverRight: DriverLeft
			{
				position="Emissive_05";
				direction="Emissive_05_Dir";
				hitpoint="Emissive_05";
				selection="Emissive_05";
			};
		};
		aggregateReflectors[]=
		{
			{
				"DriverLongBeam",
				"DriverLeft",
				"DriverRight"
			}
		};
		insideSoundCoef=0.89999998;
		threat[]={0.80000001,1,0.30000001};
		TFAR_hasIntercom=1;
		TFAR_defaultIntercomSlot=2;
		class ACE_SelfActions: ACE_SelfActions
		{
			class TFAR_IntercomChannel
			{
				displayName="$STR_tfar_core_Intercom_ACESelfAction_Name";
				condition="true";
				statement="";
				icon="";
				class TFAR_IntercomChannel_disabled
				{
					displayName="Disabled";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 0";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],0,true];";
				};
				class TFAR_IntercomChannel_Crew
				{
					displayName="Crew";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != -1";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-1,true];";
				};
				class TFAR_IntercomChannel_Command
				{
					displayName="Command";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 1";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],1,true];";
				};
				class TFAR_IntercomChannel_Passengers
				{
					displayName="Passengers";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 2";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],2,true];";
				};
				class TFAR_IntercomChannel_Misc
				{
					displayName="Misc";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 3";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],3,true];";
				};
				class TFAR_IntercomChannel_SeraphsSearchHistory
				{
					displayName="Seraph's Search History";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 4";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],4,true];";
				};
			};
		};
		class RenderTargets
		{
			class commander_display
			{
				renderTarget="rendertarget0";
				class CameraView1
				{
					pointPosition="commanderview";
					pointDirection="commanderview_dir";
					renderVisionMode=0;
					renderQuality=2;
					fov=0.305731;
					turret[]={1};
				};
				BBoxes[]=
				{
					"PIP_COM_TL",
					"PIP_COM_TR",
					"PIP_COM_BL",
					"PIP_COM_BR"
				};
			};
		};
		soundLocked[]=
		{
			"\A3\Sounds_F\weapons\Rockets\opfor_lock_1",
			1,
			1
		};
		soundIncommingMissile[]=
		{
			"\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1",
			0.31622776,
			1
		};
		smokeLauncherGrenadeCount=12;
		smokeLauncherVelocity=25;
		smokeLauncherOnTurret=1;
		smokeLauncherAngle=150;
		class Turrets: Turrets
		{
			class MainTurret_Gunner: MainTurret
			{
				startEngine = 0;
				hideWeaponsGunner = 1;
				showCrewAim = 2;
				stabilizedInAxes = 3;
				gunBeg[] = {"LeftGunnerTurret_Muzzle","RightGunnerTurret_Muzzle"};
				gunEnd[] = {"LeftGunnerTurret_Muzzle_Dir","RightGunnerTurret_Muzzle_Dir"};
				memoryPointGun[] = {"LeftGunnerTurret_Muzzle","RightGunnerTurret_Muzzle"};
				weapons[] = {"FST_VW_Sabre_30mm_Cannon","SmokeLauncher","FST_VW_Sabre_LG_MissileLauncher"};
				magazines[] = {"FST_VW_120Rnd_30mm_HE_Bolts","FST_VW_120Rnd_30mm_HE_Bolts","FST_VW_120Rnd_30mm_HE_Bolts","FST_VW_120Rnd_30mm_HE_Bolts","FST_VW_120Rnd_30mm_HE_Bolts","FST_VW_120Rnd_30mm_HE_Bolts","FST_VW_120Rnd_30mm_AP_Bolts","FST_VW_120Rnd_30mm_AP_Bolts","FST_VW_120Rnd_30mm_AP_Bolts","FST_VW_120Rnd_30mm_AP_Bolts","FST_VW_120Rnd_30mm_AP_Bolts","FST_VW_120Rnd_30mm_AP_Bolts","SmokeLauncherMag","SmokeLauncherMag","SmokeLauncherMag","SmokeLauncherMag","FST_VW_4Rnd_AT_LG_Missiles"};
				turretInfoType = "RscWeaponRangeZeroing";
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				selectionFireAnim = "zasleh2";
				flash = "gunfire";
				animationSourceBody = "LeftMainGun_Yaw";
				animationSourceGun = "LeftMainGun_Pitch";
				body = "LeftMainGun_Yaw";
				gun = "LeftMainGun_Pitch";
				soundServo[] = {"A3\Sounds_F\vehicles\armor\noises\servo_best",0.01,1,50};
				discreteDistanceInitIndex = 2;
				memoryPointGunnerOptics = "gunnerview";
				gunnerOpticsEffect[] = {};
				gunnerForceOptics = 0;
				visionMode[] = {"Normal","NVG", "TI"};
				thermalMode[] = {};
				missileBeg = "missilebeg_left";
				missileEnd = "missileend_left";
				gunnerInOpticsShowCursor = 1;
				usepip = 2;
				gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Commander_02_F";
				gunnerOutOpticsModel = "\A3\weapons_f\reticle\Optics_Commander_02_F";
				class OpticsIn: Optics_Gunner_APC_01
				{
					class Wide: Wide{};
					class Medium: Medium{};
					class Narrow: Narrow{};
				};
				gunnerAction = "Saber_Driver";
				forceHideGunner = 1;
				outGunnerMayFire = 0;
				gunnerInAction = "Saber_Driver";
				gunnerRightHandAnimName = "";
				gunnerLeftHandAnimName = "";
				gunnerFireAlsoInInternalCamera = 1;
				gunnerOutFireAlsoInInternalCamera = 1;
				proxyIndex = 2;
				viewGunnerInExternal = 1;
				proxytype = "CPGunner";
				gunnername = "Gunner";
				commanding = 1;
				personTurretAction = "vehicle_turnout_1";
				minOutElev = -10;
				maxOutElev = 15;
				initOutElev = 0;
				minOutTurn = -90;
				maxOutTurn = 90;
				initOutTurn = 0;
				minTurn = -15;
				maxTurn = 15;
				initTurn = 0;
				minElev = -8;
				maxElev = 20;
				initElev = 0;
				inGunnerMayFire = 1;
				LODTurnedOut = 1000;
				LODTurnedIn = 1000;
				gunnerGetInAction = "GetInHigh";
				gunnerGetOutAction = "GetOutHigh";
				gunnerOutOpticsShowCursor = 1;
				maxHorizontalRotSpeed = 0.720001;
				class HitPoints
				{
					class HitTurret
					{
						armor = 1.2;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 0;
						minimalHit = 0.02;
						explosionShielding = 0.3;
						radius = 0.25;
					};
					class HitGun
					{
						armor = 1.2;
						material = -1;
						name = "zbran";
						visual = "";
						passThrough = 0;
						minimalHit = 0;
						explosionShielding = 1;
						radius = 0.25;
					};
				};
				class ViewOptics: RCWSOptics
				{
					visionMode[] = {"Normal","TI"};
				};
				class Components: Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftGunner
					{
						class Components: components
						{
							class SensorDisplay
							{
								componentType = "SensorsDisplayComponent";
								range[] = {800,400,200,1600};
								resource = "RscCustomInfoSensors";
							};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightGunner
					{
						defaultDisplay = "SensorDisplay";
						class Components: components
						{
							class SensorDisplay
							{
								componentType = "SensorsDisplayComponent";
								range[] = {800,400,200,1600};
								resource = "RscCustomInfoSensors";
							};
						};
					};
				};
				class Turrets{};
			};
			class CommanderTurret: MainTurret
			{
				primaryObserver = 1;
				startEngine = 0;
				hideWeaponsGunner = 0;
				showCrewAim = 2;
				stabilizedInAxes = 3;
				memoryPointGun[] = {"CommanderMuzzle"};
				weapons[] = {"3AS_Sabre_MG","SmokeLauncher"};
				magazines[] = {"3AS_300Rnd_SabreMG_Mag","3AS_300Rnd_SabreMG_Mag","3AS_300Rnd_SabreMG_Mag","3AS_300Rnd_SabreMG_Mag","3AS_300Rnd_SabreMG_Mag","3AS_300Rnd_SabreMG_Mag","SmokeLauncherMag","SmokeLauncherMag"};
				turretInfoType = "RscWeaponRangeZeroing";
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				selectionFireAnim = "zasleh2";
				flash = "gunfire";
				animationSourceBody = "CommanderTurret";
				animationSourceGun = "Yaw_CommanderTurret";
				body = "CommanderTurret";
				gun = "Yaw_CommanderTurret";
				soundServo[] = {"A3\Sounds_F\vehicles\armor\noises\servo_best",0.01,1,50};
				discreteDistanceInitIndex = 2;
				memoryPointGunnerOptics = "commanderview";
				memoryPointGunnerOutOptics = "commanderview";
				gunnerOpticsEffect[] = {};
				gunnerForceOptics = 0;
				visionMode[] = {"Normal"};
				thermalMode[] = {};
				gunnerInOpticsShowCursor = 1;
				usepip = 2;
				gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Commander_02_F";
				gunnerOutOpticsModel = "\A3\weapons_f\reticle\Optics_Commander_02_F";
				class OpticsIn: Optics_Gunner_APC_01
				{
					class Wide: Wide{};
					class Medium: Medium{};
					class Narrow: Narrow{};
				};
				gunnerAction = "Commander_MBT_01_cannon_F_out";
				forceHideGunner = 0;
				canHideGunner = 1;
				outGunnerMayFire = 1;
				gunnerInAction = "Saber_Commander_In";
				gunnerOutAction = "Commander_MBT_01_cannon_F_out";
				gunnerRightHandAnimName = "";
				gunnerLeftHandAnimName = "";
				gunnerFireAlsoInInternalCamera = 1;
				gunnerOutFireAlsoInInternalCamera = 1;
				proxyIndex = 3;
				viewGunnerInExternal = 1;
				proxytype = "CPCommander";
				gunnername = "Commander";
				commanding = 2;
				personTurretAction = "vehicle_turnout_1";
				minOutElev = -10;
				maxOutElev = 25;
				initOutElev = 0;
				minOutTurn = -135;
				maxOutTurn = 135;
				initOutTurn = 0;
				minTurn = -90;
				maxTurn = 90;
				initTurn = 0;
				minElev = -8;
				maxElev = 20;
				initElev = 0;
				inGunnerMayFire = 0;
				LODTurnedOut = 1000;
				LODTurnedIn = 1000;
				gunnerGetInAction = "GetInHigh";
				gunnerGetOutAction = "GetOutHigh";
				class HitPoints
				{
					class HitTurret
					{
						armor = 1.2;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 0;
						minimalHit = 0.02;
						explosionShielding = 0.3;
						radius = 0.25;
					};
					class HitGun
					{
						armor = 1.2;
						material = -1;
						name = "zbran";
						visual = "";
						passThrough = 0;
						minimalHit = 0;
						explosionShielding = 1;
						radius = 0.25;
					};
				};
				class ViewOptics: RCWSOptics
				{
					visionMode[] = {"Normal","TI"};
				};
				class Components: Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftGunner
					{
						class Components: components
						{
							class SensorDisplay
							{
								componentType = "SensorsDisplayComponent";
								range[] = {800,400,200,1600};
								resource = "RscCustomInfoSensors";
							};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightGunner
					{
						defaultDisplay = "SensorDisplay";
						class Components: components
						{
							class SensorDisplay
							{
								componentType = "SensorsDisplayComponent";
								range[] = {800,400,200,1600};
								resource = "RscCustomInfoSensors";
							};
						};
					};
				};
				class Turrets{};
			};
			// Internal seats (proxy 4-9): no shooting
			class CargoTurret_04: CargoTurret
			{
				gunnerAction = "passenger_bench_1";
				proxyType = "CPCargo";
				gunnerCompartments = "Compartment2";
				memoryPointsGetInGunner = "pos driver";
				memoryPointsGetInGunnerDir = "pos driver dir";
				gunnerName = "$STR_FST_SABER_APC_PASSENGER_SEAT_01";
				proxyIndex = 4;
				soundAttenuationTurret = "HeliAttenuationGunner";
				isPersonTurret = 1;
				ejectDeadGunner = 1;
				canHideGunner = 0;
				playerPosition = 1;
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				inGunnerMayFire = 0;
				outGunnerMayFire = 0;
				weapons[] = {};
				magazines[] = {};
			};
			class CargoTurret_05: CargoTurret_04
			{
				gunnerAction = "passenger_apc_narrow_generic02";
				gunnerName = "$STR_FST_SABER_APC_PASSENGER_SEAT_02";
				proxyIndex = 5;
				playerPosition = 2;
			};
			class CargoTurret_06: CargoTurret_04
			{
				gunnerAction = "passenger_apc_narrow_generic03";
				gunnerName = "$STR_FST_SABER_APC_PASSENGER_SEAT_03";
				proxyIndex = 6;
				playerPosition = 3;
			};
			class CargoTurret_07: CargoTurret_04
			{
				gunnerAction = "passenger_apc_narrow_generic01";
				gunnerName = "$STR_FST_SABER_APC_PASSENGER_SEAT_04";
				proxyIndex = 7;
				playerPosition = 4;
			};
			class CargoTurret_08: CargoTurret_04
			{
				gunnerAction = "passenger_apc_narrow_generic02";
				gunnerName = "$STR_FST_SABER_APC_PASSENGER_SEAT_05";
				proxyIndex = 8;
				playerPosition = 5;
			};
			class CargoTurret_09: CargoTurret_04
			{
				gunnerAction = "passenger_apc_narrow_generic03";
				gunnerName = "$STR_FST_SABER_APC_PASSENGER_SEAT_06";
				proxyIndex = 9;
				playerPosition = 6;
			};
			class CargoTurret_23: CargoTurret_04
			{
				gunnerAction = "passenger_apc_narrow_generic01";
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_23";
				proxyIndex = 23;
				playerPosition = 7;
			};
			// Exterior turret seats (proxy 10+): passengers can fire
			class CargoTurret_BaseTurret: CargoTurret
			{
				gunnerAction = "passenger_inside_1";
				proxyType = "CPCargo";
				gunnerCompartments = "Compartment2";
				memoryPointsGetInGunner = "pos driver";
				memoryPointsGetInGunnerDir = "pos driver dir";
				soundAttenuationTurret = "HeliAttenuationGunner";
				isPersonTurret = 1;
				ejectDeadGunner = 1;
				canHideGunner = 0;
				gunnerGetInAction = "GetInHeli_Light_01bench";
				gunnerGetOutAction = "GetOutLow";
				inGunnerMayFire = 1;
				outGunnerMayFire = 1;
				minTurn = -90;
				maxTurn = 90;
				initTurn = 0;
				minElev = -35;
				maxElev = 55;
				initElev = 0;
				minOutTurn = -90;
				maxOutTurn = 90;
				initOutTurn = 0;
				minOutElev = -35;
				maxOutElev = 55;
				initOutElev = 0;
			};
			// Upper Left Exterior seats (proxy 10-13): left side entry
			class CargoTurret_10: CargoTurret_BaseTurret
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_10";
				proxyIndex = 10;
				playerPosition = 2;
				memoryPointsGetInGunner = "leftsideentry";
				memoryPointsGetInGunnerDir = "leftsideentry_dir";
				inGunnerMayFire = 1;
				outGunnerMayFire = 1;
				personTurretAction = "vehicle_turnout_2";
				minTurn = -85;
				maxTurn = 85;
				minOutTurn = -85;
				maxOutTurn = 85;
			};
			class CargoTurret_11: CargoTurret_10
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_11";
				proxyIndex = 11;
				playerPosition = 3;
			};
			class CargoTurret_12: CargoTurret_10
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_12";
				proxyIndex = 12;
				playerPosition = 4;
			};
			class CargoTurret_13: CargoTurret_10
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_13";
				proxyIndex = 13;
				playerPosition = 5;
			};
			// Lower Left Exterior seats (proxy 14-15): left side entry
			class CargoTurret_14: CargoTurret_10
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_14";
				proxyIndex = 14;
				playerPosition = 6;
			};
			class CargoTurret_15: CargoTurret_10
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_15";
				proxyIndex = 15;
				playerPosition = 7;
			};
			// Upper Right Exterior seats (proxy 16-19): right side entry
			class CargoTurret_16: CargoTurret_BaseTurret
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_16";
				proxyIndex = 16;
				playerPosition = 8;
				memoryPointsGetInGunner = "rightsideentry";
				memoryPointsGetInGunnerDir = "rightsideentry_dir";
				inGunnerMayFire = 1;
				outGunnerMayFire = 1;
				personTurretAction = "vehicle_turnout_2";
				minTurn = -85;
				maxTurn = 85;
				minOutTurn = -85;
				maxOutTurn = 85;
			};
			class CargoTurret_17: CargoTurret_16
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_17";
				proxyIndex = 17;
				playerPosition = 9;
			};
			class CargoTurret_18: CargoTurret_16
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_18";
				proxyIndex = 18;
				playerPosition = 10;
			};
			class CargoTurret_19: CargoTurret_16
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_19";
				proxyIndex = 19;
				playerPosition = 11;
			};
			// Rear external passenger seat (proxy 20)
			class CargoTurret_20: CargoTurret_BaseTurret
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_20";
				proxyIndex = 20;
				playerPosition = 12;
				memoryPointsGetInGunner = "pos driver";
				memoryPointsGetInGunnerDir = "pos driver dir";
				inGunnerMayFire = 1;
				outGunnerMayFire = 1;
				personTurretAction = "vehicle_turnout_2";
				minTurn = -85;
				maxTurn = 85;
				minOutTurn = -85;
				maxOutTurn = 85;
				minOutElev = -35;
				maxOutElev = 55;
				// Rear exterior -- passengers use personal weapons (isPersonTurret)
			};
			// Lower Right Exterior seats (proxy 21-22): right side entry
			class CargoTurret_21: CargoTurret_BaseTurret
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_21";
				proxyIndex = 21;
				playerPosition = 13;
				memoryPointsGetInGunner = "rightsideentry";
				memoryPointsGetInGunnerDir = "rightsideentry_dir";
				inGunnerMayFire = 1;
				outGunnerMayFire = 1;
				personTurretAction = "vehicle_turnout_2";
				minTurn = -85;
				maxTurn = 85;
				minOutTurn = -85;
				maxOutTurn = 85;
			};
			class CargoTurret_22: CargoTurret_21
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_22";
				proxyIndex = 22;
				playerPosition = 14;
			};
		};
		class Damage
		{
			tex[]={};
			mat[]={};
		};
		class AnimationSources: AnimationSources
		{
			class muzzle_rot_cannon
			{
				source="ammorandom";
				weapon="cannon_120mm";
			};
			class muzzle_rot_coax
			{
				source="ammorandom";
				weapon="LMG_M200";
			};
			class muzzle_hide_coax
			{
				source="reload";
				weapon="LMG_M200";
			};
			class recoil_source
			{
				source="reload";
				weapon="FST_Vehicle_Cannon_30mm";
			};
			class LeftMainGun_Recoil_source
			{
				source="reload";
				weapon="FST_Vehicle_Cannon_30mm";
			};
			class RightMainGun_Recoil_source
			{
				source="reload";
				weapon="FST_Vehicle_Cannon_30mm";
			};
			class Smoke_source
			{
				source="revolving";
				weapon="SmokeLauncher";
			};
			class HitEngine_src
			{
				source="Hit";
				hitpoint="HitEngine";
				raw=1;
			};
			class HitFuel_src
			{
				source="Hit";
				hitpoint="HitFuel";
				raw=1;
			};
			class HitHull_src
			{
				source="Hit";
				hitpoint="HitHull";
				raw=1;
			};
			class HitMainGun_src
			{
				source="Hit";
				hitpoint="HitGun";
				raw=1;
			};
			class HitTurret_src
			{
				source="Hit";
				hitpoint="HitTurret";
				raw=1;
			};
		};
		class Library
		{
			libTextDesc="$STR_A3_CfgVehicles_MBT_01_cannon_base_F_Library0";
		};
		class TransportMagazines
		{
		};
		class TransportWeapons
		{
		};
		class TransportItems
		{
		};
	};
	class FST_Vehicle_Land_SabreAPC_base_F: FST_Vehicle_Land_Base
	{
		crew="B_crew_F";
		typicalCargo[]=
		{
			"B_Soldier_F"
		};
		side=1;
		faction="BLU_F";
	};
	class FST_Vehicle_Land_SabreAPC: FST_Vehicle_Land_SabreAPC_base_F
	{
		class EventHandlers: DefaultEventHandlers
		{
			init="params ['_veh']; if (local _veh) then {_veh setVehicleAmmo 1;}; private _hookPos = _veh selectionPosition ['ACE_Refuel_Point','Memory']; if !(_hookPos isEqualTo [0,0,0]) then {_veh setVariable ['ace_refuel_hooks', [_hookPos], true];}; [_veh] spawn {params ['_v']; while {alive _v} do {private _cmd = effectiveCommander _v; if (!isNull _cmd && {isTurnedOut _cmd} && {_v animationSourcePhase 'main_hatch_rotate' < 0.5}) then {_v animateSource ['main_hatch_rotate',1,true];}; uiSleep 0.25;};}; [_veh] spawn {params ['_v']; while {alive _v} do {private _gunner = gunner _v; private _missileActive = !isNull _gunner && {currentWeapon _gunner isEqualTo 'FST_Vehicle_Launcher_Concussion'}; private _missilePhase = if (_missileActive) then {1} else {0}; if ((_v animationSourcePhase 'MissilePods') != _missilePhase) then {_v animateSource ['MissilePods',_missilePhase,true];}; uiSleep 0.1;};}; [_veh] spawn {params ['_v']; if (!hasInterface) exitWith {}; private _mk = {params ['_vehObj','_mem']; private _l = '#lightpoint' createVehicleLocal [0,0,0]; _l setLightColor [1,0.08,0.08]; _l setLightAmbient [0.35,0.03,0.03]; _l setLightIntensity 2.5; _l setLightUseFlare false; _l setLightAttenuation [0,0,0,1,18,30]; _l lightAttachObject [_vehObj, _vehObj selectionPosition [_mem,'Memory']]; _l}; private _lp1 = [_v,'Emissive_01'] call _mk; private _lp2 = [_v,'Emissive_02'] call _mk; waitUntil {sleep 1; !alive _v}; deleteVehicle _lp1; deleteVehicle _lp2;};";
		};
		class SimpleObject
		{
			eden=1;
			animate[]=
			{
				
				{
					"damagehide",
					0
				},
				
				{
					"wheel_koll1",
					0
				},
				
				{
					"wheel_kolol1",
					0
				},
				
				{
					"wheel_podkolol1",
					0
				},
				
				{
					"wheel_kolp1",
					0
				},
				
				{
					"wheel_kolop1",
					0
				},
				
				{
					"wheel_podkolop1",
					0
				},
				
				{
					"wheel_koll2",
					0
				},
				
				{
					"wheel_kolp2",
					0
				},
				
				{
					"wheel_kolol2",
					0
				},
				
				{
					"wheel_kolol3",
					0
				},
				
				{
					"wheel_kolol4",
					0
				},
				
				{
					"wheel_kolol5",
					0
				},
				
				{
					"wheel_kolol6",
					0
				},
				
				{
					"wheel_kolop2",
					0
				},
				
				{
					"wheel_kolop3",
					0
				},
				
				{
					"wheel_kolop4",
					0
				},
				
				{
					"wheel_kolop5",
					0
				},
				
				{
					"wheel_kolop6",
					0
				},
				
				{
					"wheel_podkolol2",
					0
				},
				
				{
					"wheel_podkolol3",
					0
				},
				
				{
					"wheel_podkolol4",
					0
				},
				
				{
					"wheel_podkolol5",
					0
				},
				
				{
					"wheel_podkolol6",
					0
				},
				
				{
					"wheel_podkolop2",
					0
				},
				
				{
					"wheel_podkolop3",
					0
				},
				
				{
					"wheel_podkolop4",
					0
				},
				
				{
					"wheel_podkolop5",
					0
				},
				
				{
					"wheel_podkolop6",
					0
				},
				
				{
					"podkolol1_hide_damage",
					0
				},
				
				{
					"podkolol2_hide_damage",
					0
				},
				
				{
					"podkolol3_hide_damage",
					0
				},
				
				{
					"podkolol4_hide_damage",
					0
				},
				
				{
					"podkolol5_hide_damage",
					0
				},
				
				{
					"podkolol6_hide_damage",
					0
				},
				
				{
					"podkolol7_hide_damage",
					0
				},
				
				{
					"podkolol8_hide_damage",
					0
				},
				
				{
					"podkolop1_hide_damage",
					0
				},
				
				{
					"podkolop2_hide_damage",
					0
				},
				
				{
					"podkolop3_hide_damage",
					0
				},
				
				{
					"podkolop4_hide_damage",
					0
				},
				
				{
					"podkolop5_hide_damage",
					0
				},
				
				{
					"podkolop6_hide_damage",
					0
				},
				
				{
					"podkolop7_hide_damage",
					0
				},
				
				{
					"podkolop8_hide_damage",
					0
				},
				
				{
					"damagevez",
					0
				},
				
				{
					"mainturret",
					0
				},
				
				{
					"LeftMainGun",
					0
				},

				{
					"RightMainGun",
					0
				},

				{
					"LeftMainGun_Recoil",
					0
				},

				{
					"RightMainGun_Recoil",
					0
				},

				{
					"MissilePods",
					0
				},

				{
					"hatchcommander",
					0
				},
				
				{
					"recoil",
					0
				},
				
				{
					"obsturret",
					0
				},
				
				{
					"obsgun",
					0
				},
				
				{
					"maingunoptics",
					0.17
				},
				
				{
					"maingunint",
					0.17
				},
				
				{
					"damagevezvelitele",
					0
				},
				
				{
					"poklop_commander_damage",
					0
				},
				
				{
					"poklop_driver_damage",
					0
				},
				
				{
					"hatchdriver",
					0
				},
				
				{
					"plates_1_y",
					0
				},
				
				{
					"plates_2_y",
					0
				},
				
				{
					"plates_1_x",
					0
				},
				
				{
					"plates_2_x",
					0
				},
				
				{
					"plates_1_bank",
					0
				},
				
				{
					"plates_2_bank",
					0
				},
				
				{
					"drivingwheel",
					0
				},
				
				{
					"indicatorspeed_mfd_driver",
					0
				},
				
				{
					"indicatorrpm",
					0
				},
				
				{
					"indicatorrpm_mfd_driver",
					0
				},
				
				{
					"lights_driver",
					0
				},
				
				{
					"lights_driver_off",
					0
				},
				
				{
					"lights_turret",
					0
				},
				
				{
					"dmg_com_halo_unhide",
					0
				},
				
				{
					"engine_damage_indicator",
					0
				},
				
				{
					"main_gun_damage_indicator",
					0
				},
				
				{
					"track_damage_indicator",
					0
				},
				
				{
					"pedal_thrust",
					0
				},
				
				{
					"pedal_brake",
					0
				},
				
				{
					"indicatortempwater_mfd_driver",
					0
				},
				
				{
					"indicatorfuel_mfd_driver",
					1
				},
				
				{
					"indicator_hull_direction_mfd_driver",
					0
				},
				
				{
					"indicator_main_turret_mfd_driver",
					0
				},
				
				{
					"indicator_hull_direction_mfd_com",
					0
				},
				
				{
					"indicator_main_turret_mfd_com",
					0
				},
				
				{
					"indicator_main_turret_onscreen_com",
					0
				},
				
				{
					"indicator_com_turret_mfd_com",
					0
				},
				
				{
					"indicator_com_turret_onscreen_com",
					0
				},
				
				{
					"indicator_hull_direction_mfd_gunner",
					0
				},
				
				{
					"indicator_main_turret_mfd_gunner",
					0
				},
				
				{
					"indicator_com_smoke_1",
					1
				},
				
				{
					"indicator_com_smoke_2",
					1
				},
				
				{
					"indicator_damage_engine",
					0
				},
				
				{
					"indicator_damage_fuel",
					0
				},
				
				{
					"indicator_damage_tracks",
					0
				},
				
				{
					"indicator_turret_damage_hull",
					0
				},
				
				{
					"lights_turret2",
					0
				},
				
				{
					"indicator_turret_damage_engine",
					0
				},
				
				{
					"indicator_turret_damage_fuel",
					0
				},
				
				{
					"indicator_turret_damage_main_gun",
					0
				},
				
				{
					"indicator_turret_damage_track",
					0
				},
				
				{
					"indicator_turret_damage_turret",
					0
				},
				
				{
					"indicator_turret_damage_comturret",
					0
				},
				
				{
					"hide_mfd_and_pip_screen_driver",
					1
				},
				
				{
					"hide_mfd_and_pip_screen_gunner",
					1
				},
				
				{
					"hide_mfd_elements",
					1
				},
				
				{
					"cannon_muzzle_flash",
					0
				},
				
				{
					"zaslehrot_cannon",
					521
				},
				
				{
					"cannon_ready_light",
					0
				},
				
				{
					"turret_control_x",
					0
				},
				
				{
					"turret_control_y",
					0
				},
				
				{
					"com_turret_control_x",
					0
				},
				
				{
					"com_turret_control_y",
					0
				},
				
				{
					"indicator_com_turret_mfd_gunner",
					0
				},
				
				{
					"indicator_com_turret_mfd_driver",
					0
				}
			};
			hide[]=
			{
				"clan",
				"zasleh",
				"zasleh_1",
				"light_l",
				"light_r",
				"zadni svetlo",
				"brzdove svetlo",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset=2.477;
			verticalOffsetWorld=-0.20900001;
			postinit="[this, '', []] call bis_fnc_initVehicle";
		};
		editorPreview="FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Icons\FST_Vehicles_Land_APC_SabreAPC_EditorPreview.jpg";
		scope=2;
		displayName="$STR_FST_SABER_APC_DISPLAYNAME";
		hiddenSelections[]=
		{
			"Camo",
			"Camo1",
			"Camo2",
			"Camo3",
			"Camo4",
			"Camo5",
			"Camo6",
			"Camo7",
			"Camo8",
			"Camo9",
			"Camo10",
			"Camo11",
			"Emissive",
			"Emissive_Gun"
		};
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo_co.paa",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo1_co.paa",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo2_co.paa",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo3_co.paa",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo4_co.paa",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo5_co.paa",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo6_co.paa",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo7_co.paa",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo8_co.paa",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo9_co.paa",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo10_co.paa",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo11_co.paa",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo1_co.paa",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo2_co.paa"

		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo.rvmat",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo1.rvmat",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo2.rvmat",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo3.rvmat",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo4.rvmat",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo5.rvmat",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo6.rvmat",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo7.rvmat",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo8.rvmat",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo9.rvmat",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo10.rvmat",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo11.rvmat",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Emissive.rvmat",
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Emissive_Gun.rvmat"
		};
		class UserActions
		{
			class OpenRearDoor
			{
				displayName="$STR_FST_SABER_APC_ACTION_OPEN_REAR_DOOR";
				position="RearDoor";
				radius=4;
				priority=10;
				onlyForPlayer=0;
				condition="(alive this) && ((player == driver this) && (this animationSourcePhase 'rear_door_rotate' < 0.5))";
				statement="this animateSource ['rear_door_rotate',1,false]";
			};
			class CloseRearDoor: OpenRearDoor
			{
				displayName="$STR_FST_SABER_APC_ACTION_CLOSE_REAR_DOOR";
				condition="(alive this) && ((player == driver this) && (this animationSourcePhase 'rear_door_rotate' >= 0.5))";
				statement="this animateSource ['rear_door_rotate',0,false]";
			};
			class OpenMainHatch: OpenRearDoor
			{
				displayName="$STR_FST_SABER_APC_ACTION_OPEN_HATCH";
				position="MainHatch";
				condition="(alive this) && (effectiveCommander this == player) && (this animationSourcePhase 'main_hatch_rotate' < 0.5)";
				statement="this animateSource ['main_hatch_rotate',1,false]";
			};
			class CloseMainHatch: OpenMainHatch
			{
				displayName="$STR_FST_SABER_APC_ACTION_CLOSE_HATCH";
				condition="(alive this) && (effectiveCommander this == player) && (this animationSourcePhase 'main_hatch_rotate' >= 0.5)";
				statement="this animateSource ['main_hatch_rotate',0,false]";
			};
		};
		class AnimationSources: AnimationSources
		{
			class rear_door_rotate
			{
				source="user";
				animPeriod=3;
				initPhase=0;
			};
			class main_hatch_rotate
			{
				source="user";
				animPeriod=4;
				initPhase=0;
			};
			class MissilePods
			{
				source="user";
				animPeriod=0.2;
				initPhase=0;
			};
		};
	};
};
