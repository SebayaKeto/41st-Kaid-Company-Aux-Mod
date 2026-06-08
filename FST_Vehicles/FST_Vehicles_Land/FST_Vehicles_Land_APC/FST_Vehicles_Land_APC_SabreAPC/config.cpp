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
		class CargoTurret;
		class AnimationSources;
		class ViewPilot;
		class ViewOptics;
		class ViewCargo;
		class ACE_SelfActions;
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
	class FST_Vehicle_Land_Base: Tank_F
	{
		//3AS Declerations
		tas_canBlift = 1;
		tas_liftVars = "[[[[0,-4,-4]]], [0.1], [-0.5]]";
		//Regular Configurations
		author="Maldova";
		mapSize=25.0001;
		simulation="tankX";
		fuelCapacity=60;
		brakeIdleSpeed=0.2;
		maxSpeed=95;
		normalSpeedForwardCoef=0.69999999;
		slowSpeedForwardCoef=0.34999999;
		engineMOI=9;
		enginePower=1400;
		maxOmega=345.57501;
		minOmega=146.608;
		redRpm=7500;
		idleRpm=850;
		peakTorque=8000;
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
		thrustDelay=0.040000001;
		dampingRateFullThrottle=0.30000001;
		dampingRateZeroThrottleClutchEngaged=3;
		dampingRateZeroThrottleClutchDisengaged=0.25;
		clutchStrength=200;
		latency=0.1;
		switchTime=0;
		changeGearType="rpmratio";
		changeGearOmegaRatios[]={1,0.42424199,0.45454499,0.33333299,0.939394,0.42424199,0.909091,0.63636398,0.84848499,0.66666698,1,0.66666698};
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R2",
				-2.2000001,
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
				15
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
			transmissionDelay=0.1;
		};
		tankTurnForce=1280000;
		tankTurnForceAngMinSpd=0.60000002;
		tankTurnForceAngSpd=0.91000003;
		accelAidForceCoef=1;
		accelAidForceYOffset=-2;
		accelAidForceSpd=1.6;
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
				side="left";
				suspTravelDirection[]={-0.125,-1,0};
				boneName="wheel_podkoloL1";
				center="wheel_1_2_axis";
				boundary="wheel_1_2_bound";
				steering=0;
				width=0.5;
				mass=150;
				MOI=33.452999;
				dampingRate=590;
				dampingRateInAir=590;
				dampingRateDestroyed=3400;
				maxDroop=0.18000001;
				maxCompression=0.18000001;
				sprungMass=-1;
				springStrength=350000;
				springDamperRate=15514;
				maxBrakeTorque=23000;
				latStiffX=2;
				latStiffY=33;
				longitudinalStiffnessPerUnitGravity=10000;
				frictionVsSlipGraph[]=
				{
					{0,0.55000001},
					{0.30000001,1.28},
					{0.64999998,0.55000001}
				};
			};
			class L3: L2
			{
				boneName="wheel_podkolol2";
				center="wheel_1_3_axis";
				boundary="wheel_1_3_bound";
			};
			class L4: L2
			{
				boneName="wheel_podkolol3";
				center="wheel_1_4_axis";
				boundary="wheel_1_4_bound";
			};
			class L5: L2
			{
				boneName="wheel_podkolol4";
				center="wheel_1_5_axis";
				boundary="wheel_1_5_bound";
			};
			class L6: L2
			{
				boneName="wheel_podkolol5";
				center="wheel_1_6_axis";
				boundary="wheel_1_6_bound";
			};
			class L7: L2
			{
				boneName="wheel_podkolol6";
				center="wheel_1_7_axis";
				boundary="wheel_1_7_bound";
			};
			class L9: L2
			{
				boneName="wheel_podkolol9";
				center="wheel_1_9_axis";
				boundary="wheel_1_9_bound";
				maxDroop=0;
				maxCompression=0;
			};
			class L1: L2
			{
				boneName="";
				center="wheel_1_1_axis";
				boundary="wheel_1_1_bound";
				maxDroop=0;
				maxCompression=0;
			};
			class R2: L2
			{
				side="right";
				suspTravelDirection[]={0.125,-1,0};
				boneName="wheel_podkolop1";
				center="wheel_2_2_axis";
				boundary="wheel_2_2_bound";
			};
			class R3: R2
			{
				boneName="wheel_podkolop2";
				center="wheel_2_3_axis";
				boundary="wheel_2_3_bound";
			};
			class R4: R2
			{
				boneName="wheel_podkolop3";
				center="wheel_2_4_axis";
				boundary="wheel_2_4_bound";
			};
			class R5: R2
			{
				boneName="wheel_podkolop4";
				center="wheel_2_5_axis";
				boundary="wheel_2_5_bound";
			};
			class R6: R2
			{
				boneName="wheel_podkolop5";
				center="wheel_2_6_axis";
				boundary="wheel_2_6_bound";
			};
			class R7: R2
			{
				boneName="wheel_podkolop6";
				center="wheel_2_7_axis";
				boundary="wheel_2_7_bound";
			};
			class R9: R2
			{
				boneName="wheel_podkolop9";
				center="wheel_2_9_axis";
				boundary="wheel_2_9_bound";
				maxDroop=0;
				maxCompression=0;
			};
			class R1: R2
			{
				boneName="";
				center="wheel_2_1_axis";
				boundary="wheel_2_1_bound";
				maxDroop=0;
				maxCompression=0;
			};
		};
		editorcategory="FST_Catagory_Vehicles_Land";
		editorSubcategory="FST_Catagory_Vehicles_Land_APC";
		scope=0;
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
		transportSoldier=6;
		cargoProxyIndexes[]={4,5,6,7,8,9};
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
		maxFordingDepth=-0.80000001;
		waterResistance=1;
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
		armor=900;
		armorLights=0.1;
		armorStructural=6;
		crewExplosionProtection=0.99989998;
		damageResistance=0.0054700002;
		cost=2500000;
		crewVulnerable=0;
		epeImpulseDamageCoef=18;
		waterPPInVehicle=0;
		waterLinearDampingCoefY= 3;		
		waterLinearDampingCoefX= 3.0;		
		waterAngularDampingCoef= 1.5;		
		waterResistanceCoef= 0.015;	
		wheelCircumference=2.1500001;
		tracksSpeed=1.4;
		model="FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\FST_Vehicles_Land_APC_SabreAPC_Model.p3d";
		picture="FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Icons\FST_Vehicles_Land_APC_SabreAPC_EditorPreview.jpg";
		Icon="FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Icons\FST_Vehicles_Land_APC_SabreAPC_Icon.paa";
		memoryPointTaskMarker="TaskMarker_1_pos";
		hideWeaponsDriver=1;
		hideWeaponsCargo=1;
		weapons[]=
		{
			"FST_Horn_RepulsorPulse",
			"SmokeLauncher"
		};
		memoryPointGun="Smoke_Launcher_POS";
		memoryPointGunDir="Smoke_Launcher_Dir";
		magazines[]=
		{
			"SmokeLauncherMag",
			"SmokeLauncherMag",
			"SmokeLauncherMag"
		};
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
				armor = -250;
				material = -1;
				name = "track_l_hit";
				passThrough = 0;
				minimalHit = 0.08;
				explosionShielding = 0.8;
				radius = 0.3;
			};
			class HitRTrack: HitRTrack
			{
				armor = -250;
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
				effect="FST_ExhaustEffect_IonWhiteHot";
			};
			class Exhaust2
			{
				position="exhaust_2_pos";
				direction="exhaust_2_dir";
				effect="FST_ExhaustEffect_IonWhiteHot";
			};
		};
		aggregateReflectors[] = {"DriverLight_03","DriverLight_04","DriverLight_05"};
		class Reflectors
		{
			class RedArea_01
			{
				color[]={800,40,40};
				ambient[]={8,0.3,0.3};
				position="Emissive_01";
				direction="Emissive_01_Dir";
				hitpoint="Light_L";
				selection="Light_L";
				size=1;
				innerAngle=110;
				outerAngle=179;
				coneFadeCoef=8;
				intensity=10;
				useFlare=0;
				dayLight=1;
				flareSize=0.6;
				class Attenuation
				{
					start=0.2;
					constant=0;
					linear=0;
					quadratic=1;
					hardLimitStart=20;
					hardLimitEnd=40;
				};
			};
			class RedArea_02: RedArea_01
			{
				position="Emissive_02";
				direction="Emissive_02_Dir";
			};
			class DriverLight_03
			{
				color[]={1800,1700,1500};
				ambient[]={5,5,4.5};
				position="Emissive_03";
				direction="Emissive_03_Dir";
				hitpoint="Light_R";
				selection="Light_R";
				size=1;
				innerAngle=70;
				outerAngle=130;
				coneFadeCoef=6;
				intensity=45;
				useFlare=1;
				dayLight=0;
				flareSize=0.8;
				class Attenuation
				{
					start=1;
					constant=0;
					linear=0;
					quadratic=0.2;
					hardLimitStart=45;
					hardLimitEnd=90;
				};
			};
			class DriverLight_04: DriverLight_03
			{
				position="Emissive_04";
				direction="Emissive_04_Dir";
			};
			class DriverLight_05: DriverLight_03
			{
				position="Emissive_05";
				direction="Emissive_05_Dir";
			};
		};
		insideSoundCoef=0.89999998;
		threat[]={0.80000001,1,0.30000001};
		TFAR_hasIntercom=1;
		TFAR_defaultIntercomSlot=-1;
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
					turret[]={0,0};
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
			class MainTurret: MainTurret
			{
				primaryGunner=1;
				commanding=1;
				proxyIndex=2;
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						primaryObserver=1;
						commanding=2;
						proxyIndex=3;
						body="CommanderTurret";
						gun="Yaw_CommanderTurret";
						animationSourceBody="CommanderTurret";
						animationSourceGun="Yaw_CommanderTurret";
						AnimationSourceHatch="main_hatch_rotate";
						memoryPointGunnerOutOptics="commanderview";
						memoryPointGunnerOptics="commanderview";
						minElev=-25;
						maxElev=60;
						initElev=0;
						minTurn=-270;
						maxTurn=270;
						initTurn=0;
						weapons[]=
						{
							"FST_Vehicle_HMG_50cal",
							"SmokeLauncher"
						};
						memoryPointGun="Commander_Muzzle";
						memoryPointGunDir="Commander_Muzzle_Dir";
						gunBeg="Commander_Muzzle";
						gunEnd="Commander_Muzzle_Dir";
						magazines[]=
						{
							"FST_Vehicle_Mag_500Rnd_50cal_Tracer",
							"SmokeLauncherMag"
						};
						soundServo[]=
						{
							"A3\Sounds_F\vehicles\armor\noises\servo_armor_comm",
							0.56234133,
							1,
							30
						};
						soundServoVertical[]=
						{
							"A3\Sounds_F\vehicles\armor\noises\servo_armor_comm",
							0.56234133,
							1,
							30
						};
						outGunnerMayFire=1;
						inGunnerMayFire=0;
						gunnerAction="Commander_MBT_01_cannon_F_out";
						gunnerInAction="Commander_MBT_01_cannon_F_in";
						gunnerGetInAction="GetInLow";
						gunnerGetOutAction="GetOutLow";
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
						gunnerOutOpticsModel="";
						gunnerOpticsEffect[]={};
						turretFollowFreeLook=2;
						gunnerForceOptics=0;
						usePip=2;
						animationSourceStickX="com_turret_control_x";
						animationSourceStickY="com_turret_control_y";
						gunnerRightHandAnimName="com_turret_control";
						LODTurnedIn=1100;
						LODOpticsIn=0;
						viewGunnerShadowAmb=0.5;
						viewGunnerShadowDiff=0.050000001;
						isPersonTurret=1;
						forceHideGunner=0;
						personTurretAction="vehicle_turnout_2";
						minOutElev=-10;
						maxOutElev=25;
						initOutElev=0;
						minOutTurn=-95;
						maxOutTurn=95;
						initOutTurn=0;
						class ViewGunner: ViewGunner
						{
							initAngleX=-10;
							initAngleY=0;
							initFov=0.89999998;
							minFov=0.25;
							maxFov=1.25;
							minAngleX=-65;
							maxAngleX=85;
							minAngleY=-150;
							maxAngleY=150;
							minMoveX=-0.075000003;
							maxMoveX=0.075000003;
							minMoveY=-0.075000003;
							maxMoveY=0.075000003;
							minMoveZ=-0.075000003;
							maxMoveZ=0.1;
						};
						class ViewOptics: ViewOptics
						{
							initAngleX=0;
							minAngleX=-30;
							maxAngleX=30;
							initAngleY=0;
							minAngleY=-100;
							maxAngleY=100;
							initFov=0.31;
							minFov=0.034000002;
							maxFov=0.31;
							visionMode[]=
							{
								"Normal",
								"TI"
							};
							thermalMode[]={2,3};
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
						turretInfoType="RscOptics_MBT_01_commander";
						showCrewAim=1;
						startEngine=0;
						gunnerHasFlares=1;
						stabilizedInAxes=3;
						maxHorizontalRotSpeed=1.8;
						maxVerticalRotSpeed=1.8;
						viewGunnerInExternal=1;
					};
				};
				class ViewGunner: ViewGunner
				{
					initAngleX=-17;
					initAngleY=0;
					initFov=0.89999998;
					minFov=0.25;
					maxFov=1.25;
					minAngleX=-95;
					maxAngleX=95;
					minAngleY=-250;
					maxAngleY=250;
					minMoveX=0;
					maxMoveX=0;
					minMoveY=0;
					maxMoveY=0;
					minMoveZ=0;
					maxMoveZ=0;
				};
				gunnerForceOptics=0;
				usePip=2;
				LODTurnedIn=1100;
				LODOpticsIn=0;
				animationSourceStickX="turret_control_x";
				animationSourceStickY="turret_control_y";
				gunnerLeftHandAnimName="turret_control_y";
				gunnerRightHandAnimName="turret_control_y";
				viewGunnerShadowAmb=0.5;
				viewGunnerShadowDiff=0.050000001;
				memoryPointGun[]=
				{
					"z_gunL_Muzzle",
					"z_gunR_Muzzle"
				};
				memoryPointLRocket="MissilesL_Start";
				memoryPointRRocket="MissilesR_Start";
				memoryPointLMissile="MissilesL_Start";
				memoryPointRMissile="MissilesR_Start";
				minTurn=-20;
				maxTurn=20;
				initTurn=0;
				gunnerAction="mbt1_slot2_out";
				gunnerInAction="Gunner_MBT_01_cannon_F_in";
				gunnerGetInAction="GetInLow";
				gunnerGetOutAction="GetOutLow";
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner",
					0.15848932,
					1,
					50
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner_vertical",
					0.15848932,
					1,
					50
				};
				weapons[]=
				{
					"FST_Vehicle_Cannon_30mm",
					"FST_Vehicle_Launcher_Concussion"
				};
				magazines[]=
				{
					"FST_Vehicle_Mag_140Rnd_30mm_MP",
					"FST_Vehicle_Mag_140Rnd_30mm_MP",
					"FST_Vehicle_Mag_140Rnd_30mm_MP",
					"FST_Vehicle_Mag_140Rnd_30mm_MP",
					"FST_Vehicle_Mag_60Rnd_30mm_APFSDS",
					"FST_Vehicle_Mag_60Rnd_30mm_APFSDS",
					"FST_Vehicle_Mag_4Rnd_Concussion"
				};
				forceHideGunner=0;
				outGunnerMayFire=1;
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000,3100,3200,3300,3400,3500,3600,3700,3800,3900,4000};
				discreteDistanceInitIndex=5;
				memoryPointGunnerOptics="gunnerview";
				minElev=-10;
				maxElev=35;
				initElev=0;
				gunnerOutOpticsModel="";
				gunnerOutOpticsEffect[]={};
				gunnerOpticsEffect[]={};
				startEngine=0;
				inGunnerMayFire=1;
				viewGunnerInExternal=1;
				class OpticsIn: Optics_Gunner_MBT_01
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
				turretInfoType="RscOptics_MBT_01_gunner";
				showCrewAim=2;
				class HitPoints
				{
					class HitTurret
					{
						armor=0.30000001;
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
			};
			class CargoTurret_07: CargoTurret
			{
				gunnerAction = "passenger_bench_1";
				gunnerCompartments = "Compartment2";
				memoryPointsGetInGunner = "pos driver";
				memoryPointsGetInGunnerDir = "pos driver dir";
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_07";
				proxyIndex = 7;
				soundAttenuationTurret = "HeliAttenuationGunner";
				isPersonTurret = 1;
				ejectDeadGunner = 1;
				canHideGunner = 0;
				playerPosition = 1;
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
			class CargoTurret_08: CargoTurret_07
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_08";
				proxyIndex = 8;
				playerPosition = 2;
			};
			class CargoTurret_09: CargoTurret_07
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_09";
				proxyIndex = 9;
				playerPosition = 3;
			};
			class CargoTurret_10: CargoTurret_07
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_10";
				proxyIndex = 10;
				playerPosition = 4;
			};
			class CargoTurret_11: CargoTurret_07
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_11";
				proxyIndex = 11;
				playerPosition = 5;
			};
			class CargoTurret_12: CargoTurret_07
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_12";
				proxyIndex = 12;
				playerPosition = 6;
			};
			class CargoTurret_13: CargoTurret_07
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_13";
				proxyIndex = 13;
				playerPosition = 7;
			};
			class CargoTurret_14: CargoTurret_07
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_14";
				proxyIndex = 14;
				playerPosition = 8;
			};
			class CargoTurret_15: CargoTurret_07
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_15";
				proxyIndex = 15;
				playerPosition = 9;
			};
			class CargoTurret_16: CargoTurret_07
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_16";
				proxyIndex = 16;
				playerPosition = 10;
			};
			class CargoTurret_17: CargoTurret_07
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_17";
				proxyIndex = 17;
				playerPosition = 11;
			};
			class CargoTurret_18: CargoTurret_07
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_18";
				proxyIndex = 18;
				playerPosition = 12;
			};
			class CargoTurret_19: CargoTurret_07
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_19";
				proxyIndex = 19;
				playerPosition = 13;
			};
			class CargoTurret_20: CargoTurret_07
			{
				gunnerName = "$STR_FST_SABER_APC_GUNNER_SEAT_20";
				proxyIndex = 20;
				playerPosition = 14;
				weapons[]= {"SmokeLauncher"};
				memoryPointGun="Smoke_Launcher_POS";
				memoryPointGunDir="Smoke_Launcher_Dir";
				magazines[]= {"SmokeLauncherMag"};
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
			init="params ['_veh']; private _hookPos = _veh selectionPosition ['ACE_Refuel_Point','Memory']; if !(_hookPos isEqualTo [0,0,0]) then {_veh setVariable ['ace_refuel_hooks', [_hookPos], true];}; [_veh] spawn {params ['_v']; while {alive _v} do {private _cmd = effectiveCommander _v; if (!isNull _cmd && {isTurnedOut _cmd} && {_v animationSourcePhase 'main_hatch_rotate' < 0.5}) then {_v animateSource ['main_hatch_rotate',1,true];}; uiSleep 0.25;};}; [_veh] spawn {params ['_v']; while {alive _v} do {private _gunner = gunner _v; private _missileActive = !isNull _gunner && {currentWeapon _gunner isEqualTo 'FST_Vehicle_Launcher_Concussion'}; private _missilePhase = if (_missileActive) then {1} else {0}; if ((_v animationSourcePhase 'MissilePods') != _missilePhase) then {_v animateSource ['MissilePods',_missilePhase,true];}; uiSleep 0.1;};};";
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
					"maingun",
					0.17
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
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Data\Textures\Base\Camo_co.paa",
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
				condition="(alive this) && ((player == driver this) || (effectiveCommander this == player)) && (this animationSourcePhase 'rear_door_rotate' < 0.5)";
				statement="this animateSource ['rear_door_rotate',1,true]";
			};
			class CloseRearDoor: OpenRearDoor
			{
				displayName="$STR_FST_SABER_APC_ACTION_CLOSE_REAR_DOOR";
				condition="(alive this) && ((player == driver this) || (effectiveCommander this == player)) && (this animationSourcePhase 'rear_door_rotate' >= 0.5)";
				statement="this animateSource ['rear_door_rotate',0,true]";
			};
			class OpenMainHatch: OpenRearDoor
			{
				displayName="$STR_FST_SABER_APC_ACTION_OPEN_HATCH";
				position="MainHatch";
				condition="(alive this) && (effectiveCommander this == player) && (this animationSourcePhase 'main_hatch_rotate' < 0.5)";
				statement="this animateSource ['main_hatch_rotate',1,true]";
			};
			class CloseMainHatch: OpenMainHatch
			{
				displayName="$STR_FST_SABER_APC_ACTION_CLOSE_HATCH";
				condition="(alive this) && (effectiveCommander this == player) && (this animationSourcePhase 'main_hatch_rotate' >= 0.5)";
				statement="this animateSource ['main_hatch_rotate',0,true]";
			};
		};
		class AnimationSources: AnimationSources
		{
			class rear_door_rotate
			{
				source="user";
				animPeriod=1.5;
				initPhase=0;
			};
			class main_hatch_rotate
			{
				source="user";
				animPeriod=1;
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
