class CfgPatches
{
	class FST_GAT
	{
		requiredAddons[]=
		{
			"A3_Armor_F_Beta",
			"3AS_Main",
			"3AS_Weapons"
		};
		units[]=
		{
			"FST_GAT",
			"FST_AA_GAT"
		};
		weapons[]={};
	};
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
	class FST_GAT_base_F: Tank_F
	{
		attenuationEffectType="TankAttenuation";
		soundGetIn[]=
		{
			"A3\sounds_f\vehicles\armor\noises\get_in_out",
			0.56234097,
			1
		};
		soundGetOut[]=
		{
			"A3\sounds_f\vehicles\armor\noises\get_in_out",
			0.56234097,
			1,
			20
		};
		soundDammage[]=
		{
			"",
			0.56234097,
			1
		};
		soundEngineOnInt[]=
		{
			"3as\3as_gat\sounds\GATStart.wss",
			2,
			1
		};
		soundEngineOnExt[]=
		{
			"3as\3as_gat\sounds\GATStart.wss",
			4,
			1,
			200
		};
		soundEngineOffInt[]=
		{
			"3as\3as_gat\sounds\GATOff.wss",
			2,
			1
		};
		soundEngineOffExt[]=
		{
			"3as\3as_gat\sounds\GATOff.wss",
			4,
			1,
			200
		};
		buildCrash0[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_08",
			1,
			1,
			200
		};
		buildCrash1[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_09",
			1,
			1,
			200
		};
		buildCrash2[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_10",
			1,
			1,
			200
		};
		buildCrash3[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_11",
			1,
			1,
			200
		};
		soundBuildingCrash[]=
		{
			"buildCrash0",
			0.25,
			"buildCrash1",
			0.25,
			"buildCrash2",
			0.25,
			"buildCrash3",
			0.25
		};
		WoodCrash0[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_08",
			1,
			1,
			200
		};
		WoodCrash1[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_09",
			1,
			1,
			200
		};
		WoodCrash2[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_10",
			1,
			1,
			200
		};
		WoodCrash3[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_11",
			1,
			1,
			200
		};
		WoodCrash4[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_01",
			1,
			1,
			200
		};
		WoodCrash5[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_08",
			1,
			1,
			200
		};
		soundWoodCrash[]=
		{
			"woodCrash0",
			0.16599999,
			"woodCrash1",
			0.16599999,
			"woodCrash2",
			0.16599999,
			"woodCrash3",
			0.16599999,
			"woodCrash4",
			0.16599999,
			"woodCrash5",
			0.16599999
		};
		ArmorCrash0[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_08",
			1,
			1,
			200
		};
		ArmorCrash1[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_09",
			1,
			1,
			200
		};
		ArmorCrash2[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_10",
			1,
			1,
			200
		};
		ArmorCrash3[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_11",
			1,
			1,
			200
		};
		soundArmorCrash[]=
		{
			"ArmorCrash0",
			0.25,
			"ArmorCrash1",
			0.25,
			"ArmorCrash2",
			0.25,
			"ArmorCrash3",
			0.25
		};
		class Sounds
		{
			class Idle_ext
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					4,
					1,
					200
				};
				frequency="0.95 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class Engine
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					4.48808,
					1,
					240
				};
				frequency="0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_ext
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					5.6501598,
					1,
					280
				};
				frequency="0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_ext
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					6.3396001,
					1,
					320
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_ext
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					7.1131301,
					1,
					360
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_ext
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					7.98104,
					1,
					400
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_ext
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					8.9548903,
					1,
					440
				};
				frequency="0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume="engineOn*camPos*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class IdleThrust
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					5.6501598,
					1,
					200
				};
				frequency="0.8 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class EngineThrust
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					7.1131301,
					1,
					200
				};
				frequency="0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_Thrust_ext
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					8.9548903,
					1,
					230
				};
				frequency="0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_Thrust_ext
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					10.0475,
					1,
					290
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_Thrust_ext
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					8.9548903,
					1,
					350
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_Thrust_ext
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					11.27353,
					1,
					400
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_Thrust_ext
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					12.64913,
					1,
					450
				};
				frequency="0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class Idle_int
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					2,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class Engine_int
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					1.41589,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_int
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					1.58866,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_int
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					1.7825,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_int
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					2,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_int
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					2.24404,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_int
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					2.5178499,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class IdleThrust_int
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					2.5178499,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class EngineThrust_int
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					1.58866,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_Thrust_int
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					1.7825,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_Thrust_int
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					1.7825,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_Thrust_int
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					2,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_Thrust_int
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					2.24404,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_Thrust_int
			{
				sound[]=
				{
					"3as\3as_gat\sounds\GATIdle.wss",
					2.5178499,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class NoiseInt
			{
				sound[]=
				{
					"A3\sounds_f\vehicles\armor\noises\noise_tank_int_1",
					0.50118703,
					1
				};
				frequency="1";
				volume="(1-camPos)*(angVelocity max 0.04)*(speed factor[4, 15])";
			};
			class NoiseExt
			{
				sound[]=
				{
					"A3\sounds_f\vehicles\armor\noises\noise_tank_ext_1",
					0.89125103,
					1,
					50
				};
				frequency="1";
				volume="camPos*(angVelocity max 0.04)*(speed factor[4, 15])";
			};
			class ThreadsOutH0
			{
				sound[]=
				{
					"",
					0.39810699,
					1,
					140
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsOutH1
			{
				sound[]=
				{
					"",
					0.446684,
					1,
					160
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsOutH2
			{
				sound[]=
				{
					"",
					0.50118703,
					1,
					180
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsOutH3
			{
				sound[]=
				{
					"",
					0.56234097,
					1,
					200
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsOutH4
			{
				sound[]=
				{
					"",
					0.56234097,
					1,
					220
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class ThreadsOutS0
			{
				sound[]=
				{
					"",
					0.316228,
					1,
					120
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsOutS1
			{
				sound[]=
				{
					"",
					0.35481301,
					1,
					140
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsOutS2
			{
				sound[]=
				{
					"",
					0.39810699,
					1,
					160
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsOutS3
			{
				sound[]=
				{
					"",
					0.446684,
					1,
					180
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsOutS4
			{
				sound[]=
				{
					"",
					0.50118703,
					1,
					200
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class ThreadsInH0
			{
				sound[]=
				{
					"",
					0.25118899,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsInH1
			{
				sound[]=
				{
					"",
					0.281838,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsInH2
			{
				sound[]=
				{
					"",
					0.316228,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsInH3
			{
				sound[]=
				{
					"",
					0.35481301,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsInH4
			{
				sound[]=
				{
					"",
					0.39810699,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class ThreadsInS0
			{
				sound[]=
				{
					"",
					0.316228,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsInS1
			{
				sound[]=
				{
					"",
					0.316228,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsInS2
			{
				sound[]=
				{
					"",
					0.35481301,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsInS3
			{
				sound[]=
				{
					"",
					0.35481301,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsInS4
			{
				sound[]=
				{
					"",
					0.39810699,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
		};
		simulation="tankX";
		enginePower=680;
		maxOmega=246;
		maxSpeed=90;
		peakTorque=4832;
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
		thrustDelay=0.5;
		clutchStrength=100;
		fuelCapacity=40;
		brakeIdleSpeed=1.78;
		latency=0.1;
		tankTurnForce=400000;
		idleRpm=700;
		redRpm=2640;
		engineLosses=25;
		transmissionLosses=15;
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R2",
				-3.9000001,
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
		class Wheels
		{
			class L2
			{
				boneName="wheel_podkoloL1";
				center="wheel_1_2_axis";
				boundary="wheel_1_2_bound";
				damping=75;
				steering=0;
				side="left";
				weight=150;
				mass=150;
				MOI=22;
				latStiffX=25;
				latStiffY=280;
				longitudinalStiffnessPerUnitGravity=100000;
				maxBrakeTorque=20000;
				sprungMass=4000;
				springStrength=100000;
				springDamperRate=40000;
				dampingRate=1;
				dampingRateInAir=8000;
				dampingRateDamaged=10;
				dampingRateDestroyed=10000;
				maxDroop=0.15000001;
				maxCompression=0.15000001;
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
				sprungMass=1500;
				springStrength=37500;
				springDamperRate=7500;
				maxDroop=0;
				maxCompression=0;
			};
			class L1: L2
			{
				boneName="";
				center="wheel_1_1_axis";
				boundary="wheel_1_1_bound";
				sprungMass=1500;
				springStrength=37500;
				springDamperRate=7500;
				maxDroop=0;
				maxCompression=0;
			};
			class R2: L2
			{
				boneName="wheel_podkolop1";
				center="wheel_2_2_axis";
				boundary="wheel_2_2_bound";
				side="right";
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
				sprungMass=1500;
				springStrength=37500;
				springDamperRate=7500;
				maxDroop=0;
				maxCompression=0;
			};
			class R1: R2
			{
				boneName="";
				center="wheel_2_1_axis";
				boundary="wheel_2_1_bound";
				sprungMass=1500;
				springStrength=37500;
				springDamperRate=7500;
				maxDroop=0;
				maxCompression=0;
			};
		};
		author="Daara";
		destrType="DestructWreck";
		editorSubcategory="FST_Ground_Vehicle";
		scope=0;
		displayName="[41st] GAT Medium Tank";
		memoryPointDriverOptics[]=
		{
			"driverview"
		};
		driverOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
		driverForceOptics=1;
		driverLeftHandAnimName="drivewheel";
		driverRightHandAnimName="drivewheel";
		driverLeftLegAnimName="pedal_brake";
		driverRightLegAnimName="pedal_thrust";
		viewDriverShadowAmb=0.5;
		viewDriverShadowDiff=0.050000001;
		transportSoldier=0;
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
		cargoAction[]={};
		maxFordingDepth=-0.80000001;
		canFloat=1;
		waterResistance=9.9999997e-005;
		waterResistanceCoef=1e-010;
		waterLeakiness=0.0099999998;
		waterAngularDampingCoef=5;
		waterLinearDampingCoefX=10;
		waterLinearDampingCoefY=10;
		waterSpeedFactor=10;
		LODDriverTurnedin=1100;
		LODDriverTurnedOut=0;
		LODDriverOpticsIn=1202;
		driverAction="Driver_MBT_03_cannon_F_out";
		driverInAction="Driver_MBT_01_cannon_F_in";
		extCameraPosition[]={0,3,-9};
		forceHideDriver=1;
		viewDriverInExternal=1;
		class ViewOptics: ViewOptics
		{
			visionMode[]=
			{
				"Normal",
				"NVG"
			};
		};
		crewExplosionProtection=0.99989998;
		damageResistance=0.0054700002;
		cost=2500000;
		crewVulnerable=0;
		epeImpulseDamageCoef=18;
		waterPPInVehicle=0;
		wheelCircumference=2.1500001;
		tracksSpeed=1.4;
		model="\3AS\3AS_GAT\3AS_GAT.p3d";
		icon="3as\3AS_GAT\data\ui\GAT_top_ca.paa";
		memoryPointTaskMarker="TaskMarker_1_pos";
		hideWeaponsDriver=1;
		hideWeaponsCargo=1;
		hasdriver=1;
		armor=400;
		armorLights=0.1;
		armorStructural=6;
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=2.5999999;
				material=-1;
				name="telo";
				visual="hull";
				passThrough=1;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.30000001;
			};
			class HitERA_Front
			{
				simulation="Armor_ERA_Light";
				armorComponent="ERA_F";
				name="ERA_F_point";
				armor=-100;
				minimalHit=1;
				radius=0.30000001;
				passThrough=0;
				visual="-";
				explosionShielding=2;
				class DestructionEffects
				{
					ammoExplosionEffect="";
					effectRadius=1;
					ignoreFuel=1;
					class Explo
					{
						simulation="particles";
						type="MineExplosionParticles";
						position="era_F_pos";
						lifeTime=0.0099999998;
						interval=1;
						intensity=0.0099999998;
					};
					class Smoke: Explo
					{
						type="ERASmoke";
						lifeTime=0.050000001;
					};
					class Sound: Explo
					{
						simulation="sound";
						type="ERA_Explosion";
						lifeTime=1;
					};
				};
			};
			class HitERA_Left_1: HitERA_Front
			{
				name="ERA_L_1_point";
				armorComponent="ERA_L_1a";
				class DestructionEffects
				{
					ammoExplosionEffect="";
					effectRadius=1;
					ignoreFuel=1;
					class Explo
					{
						simulation="particles";
						type="MineExplosionParticles";
						position="era_L_1_pos";
						lifeTime=0.0099999998;
						interval=1;
						intensity=0.0099999998;
					};
					class Smoke: Explo
					{
						type="ERASmoke";
						lifeTime=0.050000001;
					};
					class Sound: Explo
					{
						simulation="sound";
						type="ERA_Explosion";
						lifeTime=1;
					};
				};
			};
			class HitERA_Left_2: HitERA_Front
			{
				name="ERA_L_2_point";
				armorComponent="ERA_L_1b";
				class DestructionEffects
				{
					ammoExplosionEffect="";
					effectRadius=1;
					ignoreFuel=1;
					class Explo
					{
						simulation="particles";
						type="MineExplosionParticles";
						position="era_L_2_pos";
						lifeTime=0.0099999998;
						interval=1;
						intensity=0.0099999998;
					};
					class Smoke: Explo
					{
						type="ERASmoke";
						lifeTime=0.050000001;
					};
					class Sound: Explo
					{
						simulation="sound";
						type="ERA_Explosion";
						lifeTime=1;
					};
				};
			};
			class HitERA_Left_3: HitERA_Front
			{
				name="ERA_L_3_point";
				armorComponent="ERA_L_2a";
				class DestructionEffects
				{
					ammoExplosionEffect="";
					effectRadius=1;
					ignoreFuel=1;
					class Explo
					{
						simulation="particles";
						type="MineExplosionParticles";
						position="era_L_3_pos";
						lifeTime=0.0099999998;
						interval=1;
						intensity=0.0099999998;
					};
					class Smoke: Explo
					{
						type="ERASmoke";
						lifeTime=0.050000001;
					};
					class Sound: Explo
					{
						simulation="sound";
						type="ERA_Explosion";
						lifeTime=1;
					};
				};
			};
			class HitERA_Left_4: HitERA_Front
			{
				name="ERA_L_4_point";
				armorComponent="ERA_L_2b";
				class DestructionEffects
				{
					ammoExplosionEffect="";
					effectRadius=1;
					ignoreFuel=1;
					class Explo
					{
						simulation="particles";
						type="MineExplosionParticles";
						position="era_L_4_pos";
						lifeTime=0.0099999998;
						interval=1;
						intensity=0.0099999998;
					};
					class Smoke: Explo
					{
						type="ERASmoke";
						lifeTime=0.050000001;
					};
					class Sound: Explo
					{
						simulation="sound";
						type="ERA_Explosion";
						lifeTime=1;
					};
				};
			};
			class HitERA_Left_5: HitERA_Front
			{
				name="ERA_L_5_point";
				armorComponent="ERA_L_3a";
				class DestructionEffects
				{
					ammoExplosionEffect="";
					effectRadius=1;
					ignoreFuel=1;
					class Explo
					{
						simulation="particles";
						type="MineExplosionParticles";
						position="era_L_4_pos";
						lifeTime=0.0099999998;
						interval=1;
						intensity=0.0099999998;
					};
					class Smoke: Explo
					{
						type="ERASmoke";
						lifeTime=0.050000001;
					};
					class Sound: Explo
					{
						simulation="sound";
						type="ERA_Explosion";
						lifeTime=1;
					};
				};
			};
			class HitERA_Right_1: HitERA_Front
			{
				name="ERA_R_1_point";
				armorComponent="ERA_R_1a";
				class DestructionEffects
				{
					ammoExplosionEffect="";
					effectRadius=1;
					ignoreFuel=1;
					class Explo
					{
						simulation="particles";
						type="MineExplosionParticles";
						position="era_R_1_pos";
						lifeTime=0.0099999998;
						interval=1;
						intensity=0.0099999998;
					};
					class Smoke: Explo
					{
						type="ERASmoke";
						lifeTime=0.050000001;
					};
					class Sound: Explo
					{
						simulation="sound";
						type="ERA_Explosion";
						lifeTime=1;
					};
				};
			};
			class HitERA_Right_2: HitERA_Front
			{
				name="ERA_R_2_point";
				armorComponent="ERA_R_1b";
				class DestructionEffects
				{
					ammoExplosionEffect="";
					effectRadius=1;
					ignoreFuel=1;
					class Explo
					{
						simulation="particles";
						type="MineExplosionParticles";
						position="era_R_2_pos";
						lifeTime=0.0099999998;
						interval=1;
						intensity=0.0099999998;
					};
					class Smoke: Explo
					{
						type="ERASmoke";
						lifeTime=0.050000001;
					};
					class Sound: Explo
					{
						simulation="sound";
						type="ERA_Explosion";
						lifeTime=1;
					};
				};
			};
			class HitERA_Right_3: HitERA_Front
			{
				name="ERA_R_3_point";
				armorComponent="ERA_R_2a";
				class DestructionEffects
				{
					ammoExplosionEffect="";
					effectRadius=1;
					ignoreFuel=1;
					class Explo
					{
						simulation="particles";
						type="MineExplosionParticles";
						position="era_R_3_pos";
						lifeTime=0.0099999998;
						interval=1;
						intensity=0.0099999998;
					};
					class Smoke: Explo
					{
						type="ERASmoke";
						lifeTime=0.050000001;
					};
					class Sound: Explo
					{
						simulation="sound";
						type="ERA_Explosion";
						lifeTime=1;
					};
				};
			};
			class HitERA_Right_4: HitERA_Front
			{
				name="ERA_R_4_point";
				armorComponent="ERA_R_2b";
				class DestructionEffects
				{
					ammoExplosionEffect="";
					effectRadius=1;
					ignoreFuel=1;
					class Explo
					{
						simulation="particles";
						type="MineExplosionParticles";
						position="era_R_4_pos";
						lifeTime=0.0099999998;
						interval=1;
						intensity=0.0099999998;
					};
					class Smoke: Explo
					{
						type="ERASmoke";
						lifeTime=0.050000001;
					};
					class Sound: Explo
					{
						simulation="sound";
						type="ERA_Explosion";
						lifeTime=1;
					};
				};
			};
			class HitERA_Right_5: HitERA_Front
			{
				name="ERA_R_5_point";
				armorComponent="ERA_R_3a";
				class DestructionEffects
				{
					ammoExplosionEffect="";
					effectRadius=1;
					ignoreFuel=1;
					class Explo
					{
						simulation="particles";
						type="MineExplosionParticles";
						position="era_R_5_pos";
						lifeTime=0.0099999998;
						interval=1;
						intensity=0.0099999998;
					};
					class Smoke: Explo
					{
						type="ERASmoke";
						lifeTime=0.050000001;
					};
					class Sound: Explo
					{
						simulation="sound";
						type="ERA_Explosion";
						lifeTime=1;
					};
				};
			};
			class HitLTrack: HitLTrack
			{
				armor=4;
				material=-1;
				name="pasL";
				passThrough=0;
				minimalHit=0.001;
				explosionShielding=1;
				radius=0.30000001;
			};
			class HitRTrack: HitRTrack
			{
				armor=4;
				material=-1;
				name="pasP";
				passThrough=0;
				minimalHit=0.001;
				explosionShielding=1;
				radius=0.30000001;
			};
			class HitEngine: HitEngine
			{
				armor=4;
				material=-1;
				name="engine";
				visual="-";
				passThrough=1;
				minimalHit=0.001;
				explosionShielding=1;
				radius=0.30000001;
			};
		};
		animationSourceHatch="";
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
		insideSoundCoef=0.89999998;
		threat[]={0.80000001,1,0.30000001};
		class Reflectors
		{
			class Left
			{
				color[]={1900,1800,1700};
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
				useFlare=0;
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
				hitpoint="Light_R_flare";
				useFlare=1;
			};
			class Left2: Left
			{
				position="light_L_flare";
				hitpoint="Light_L_flare";
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
		smokeLauncherGrenadeCount=8;
		smokeLauncherVelocity=14;
		smokeLauncherOnTurret=1;
		smokeLauncherAngle=120;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets
				{
				};
				memoryPointGun[]=
				{
					"z_gunL_muzzle",
					"z_gunR_muzzle"
				};
				weapons[]=
				{
					"FST_ATTE_Turret",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"FST_thermal_coil_Red",
					"FST_thermal_coil_Red",
					"FST_thermal_coil_Red",
					"FST_thermal_coil_Red",
					"FST_thermal_coil_Red",
					"FST_thermal_coil_Red",
					"FST_thermal_coil_Red",
					"FST_thermal_coil_Red",
					"FST_thermal_coil_Red",
					"FST_thermal_coil_Red",
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
				gunnerOutOpticsModel="";
				gunnerOutOpticsEffect[]={};
				gunnerOpticsEffect[]={};
				gunnerForceOptics=1;
				visionMode[]=
				{
					"Normal"
				};
				thermalMode[]={};
				class OpticsIn
				{
					class Wide
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						initFov=0.155;
						minFov=0.155;
						maxFov=0.155;
						visionMode[]=
						{
							"Normal",
							"NVG",
							"Ti"
						};
						thermalMode[]={0,1};
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
						gunnerOpticsEffect[]={};
					};
					class Narrow: Wide
					{
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
						initFov=0.046999998;
						minFov=0.046999998;
						maxFov=0.046999998;
					};
				};
				gunnerAction="mbt2_slot2b_in";
				forceHideGunner=1;
				outGunnerMayFire=1;
				gunnerInAction="mbt2_slot2b_in";
				gunnerRightHandAnimName="";
				gunnerLeftHandAnimName="";
				gunnerFireAlsoInInternalCamera=1;
				gunnerOutFireAlsoInInternalCamera=1;
				proxyIndex=1;
				viewGunnerInExternal=0;
				gunnerName="Gunner";
				proxytype="CPGunner";
				isPersonTurret=0;
				personTurretAction="vehicle_turnout_1";
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_best",
					"db-40",
					1,
					50
				};
				minElev=-20;
				maxElev=40;
				initElev=0;
				inGunnerMayFire=1;
				class HitPoints
				{
					class HitTurret
					{
						armor=4;
						material=-1;
						name="vez";
						visual="vez";
						passThrough=1;
						minimalHit=0.001;
						explosionShielding=1;
						radius=0.30000001;
					};
					class HitGun
					{
						armor=0.4;
						material=-1;
						name="zbran";
						visual="";
						passThrough=1;
						minimalHit=0001;
						explosionShielding=1;
						radius=0.30000001;
					};
				};
			};
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3as\3as_GAT\data\GAT_hull.rvmat",
				"3as\3as_GAT\data\GAT_hull.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat",
				"3as\3as_GAT\data\GAT_weapons_Heavy.rvmat",
				"3as\3as_GAT\data\GAT_weapons_Heavy.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat"
			};
		};
		class AnimationSources
		{
			class muzzle_rot_cannon
			{
				source="ammorandom";
				weapon="3AS_GATRepeater";
			};
			class recoil_source
			{
				source="reload";
				weapon="3AS_AATCannon";
			};
			class muzzle_rot_coax
			{
				source="ammorandom";
				weapon="3AS_GATRepeater";
			};
		};
		animationList[]=
		{
			"showCamonetCannon",
			0,
			"showCamonetPlates1",
			0,
			"showCamonetPlates2",
			0,
			"showCamonetTurret",
			0,
			"showCamonetHull",
			0
		};
	};
	class FST_CIS_GAT_base_F: FST_GAT_base_F
	{
		author="Daara";
		_generalMacro="B_MBT_01_base_F";
		features="Randomization: No      <br />Camo selections: 2 - hull, main turret      <br />Script door sources: None      <br />Script animations: None      <br />Executed scripts: None      <br />Firing from vehicles: No      <br />Slingload: No      <br />Cargo proxy indexes: 1 to 6";
		crew="O_UAV_AI";
		side=0;
		faction="FST_BattleDroids_Faction";
	};
	class FST_CIS_GAT_F: FST_CIS_GAT_base_F
	{
		author="Daara";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_MBT_01_cannon_F.jpg";
		scope=0;
		displayName="[41st] GAT Medium Tank";
		hiddenSelections[]=
		{
			"Camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_GAT\data\hull_CO.paa",
			"3AS\3AS_GAT\data\weapons_CO.paa"
		};
		class TextureSources
		{
			class CIS
			{
				displayName="Trade Federation";
				author="3AS Mod Team";
				textures[]=
				{
					"3AS\3AS_GAT\data\hull_CO.paa",
					"3AS\3AS_GAT\data\weapons_CO.paa"
				};
				factions[]=
				{
					"3AS_CIS"
				};
			};
			class Olive
			{
				displayName="Olive";
				author="3AS Mod Team";
				textures[]=
				{
					"3AS\3AS_GAT\data\Olive\hull_CO.paa",
					"3AS\3AS_GAT\data\Olive\weapons_CO.paa"
				};
				factions[]=
				{
					"3AS_CIS"
				};
			};
		};
		class AnimationSources: AnimationSources
		{
			class muzzle_hide_cannon
			{
				source="reload";
				weapon="cannon_120mm";
			};
			class muzzle_rot_cannon
			{
				source="ammorandom";
				weapon="cannon_120mm";
			};
			class HitComTurret_src
			{
				source="Hit";
				hitpoint="HitComTurret";
				raw=1;
			};
			class showBags
			{
				displayName="Show Bags";
				author="$STR_A3_Bohemia_Interactive";
				source="user";
				animPeriod=0.001;
				initPhase=0;
				mass=-50;
			};
		};
	};
	class FST_GAT: FST_CIS_GAT_base_F
	{
		scope=2;
		scopeCurator=2;
		forceingarage=1;
		displayname="[41st] GAT Medium Tank";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionstextures[]=
		{
			"3AS\3AS_GAT\data\hull_CO.paa",
			"3AS\3AS_GAT\data\weapons_CO.paa"
		};
		editorPreview="3as\3as_gat\images\3AS_GAT.jpg";
		class TextureSources
		{
			class CIS
			{
				displayName="Trade Federation";
				author="3AS Mod Team";
				textures[]=
				{
					"3AS\3AS_GAT\data\hull_CO.paa",
					"3AS\3AS_GAT\data\weapons_CO.paa"
				};
				factions[]=
				{
					"3AS_CIS"
				};
			};
			class Olive
			{
				displayName="Olive";
				author="3AS Mod Team";
				textures[]=
				{
					"3AS\3AS_GAT\data\Olive\hull_CO.paa",
					"3AS\3AS_GAT\data\Olive\weapons_CO.paa"
				};
				factions[]=
				{
					"3AS_CIS"
				};
			};
		};
		accuracy=1000;
	};
	class FST_AA_GAT: FST_CIS_GAT_base_F
	{
		author="Viz";
		scope=2;
		scopeCurator=2;
		forceingarage=1;
		displayname="[41st] GAT Medium Tank [SPAA]";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionstextures[]=
		{
			"3AS\3AS_GAT\data\hull_CO.paa",
			"3AS\3AS_GAT\data\weapons_CO.paa"
		};
		editorPreview="3as\3as_gat\images\3AS_GAT.jpg";
		class TextureSources
		{
			class CIS
			{
				displayName="Trade Federation";
				author="3AS Mod Team";
				textures[]=
				{
					"3AS\3AS_GAT\data\hull_CO.paa",
					"3AS\3AS_GAT\data\weapons_CO.paa"
				};
				factions[]=
				{
					"3AS_CIS"
				};
			};
			class Olive
			{
				displayName="Olive";
				author="3AS Mod Team";
				textures[]=
				{
					"3AS\3AS_GAT\data\Olive\hull_CO.paa",
					"3AS\3AS_GAT\data\Olive\weapons_CO.paa"
				};
				factions[]=
				{
					"3AS_CIS"
				};
			};
		};
		accuracy=1000;
		allowTabLock=1;
		radarType=2;
		gunnerCanSee="1 + 2 + 4 + 8 + 32";
		commanderCanSee="1 + 2 + 4 + 8 + 32";
		class Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent
					{
						class AirTarget
						{
							minRange=5000;
							maxRange=5000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=5000;
							maxRange=5000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						typeRecognitionDistance=5000;
						maxTrackableSpeed=1600;
						angleRangeHorizontal=360;
						angleRangeVertical=360;
						animDirection="mainGun";
						aimDown=-0.5;
					};
					class ActiveRadarSensorComponent
					{
						class AirTarget
						{
							minRange=7000;
							maxRange=7000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=7000;
							maxRange=7000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						typeRecognitionDistance=7000;
						angleRangeHorizontal=360;
						angleRangeVertical=360;
						groundNoiseDistanceCoef=1;
						componentType="ActiveRadarSensorComponent";
						maxGroundNoiseDistance=20000;
						minSpeedThreshold=5;
						maxSpeedThreshold=1900;
						color[]={0,1,1,1};
						allowsMarking=1;
						animDirection="";
						aimDown=0;
						minTrackableSpeed=-1e+010;
						maxTrackableSpeed=1e+010;
						minTrackableATL=-1e+010;
						maxTrackableATL=1e+010;
					};
					class DataLinkSensorComponent
					{
					};
				};
			};
			class TransportCountermeasuresComponent
			{
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets
				{
				};
				weapons[]=
				{
					"FST_40mw_HH9P_AC",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"FST_40mm_UB9HV_HEI_x140_mag",
					"FST_40mm_UB9HV_HEI_x140_mag",
					"FST_40mm_UB9HV_HEI_x140_mag",
					"FST_40mm_UB9HV_HEI_x140_mag",
					"FST_40mm_UB9HV_HEI_x140_mag",
					"FST_40mm_UB9HV_HEI_x140_mag",
					"FST_40mm_UB9HV_HEI_x140_mag",
					"FST_40mm_UB9HV_HEI_x140_mag",
					"FST_40mm_UB9HV_HEI_x140_mag",
					"FST_40mm_UB9HV_HEI_x140_mag",
					"FST_40mm_UB9HV_HEI_x140_mag",
					"FST_40mm_UB9HV_HEI_x140_mag",
					"SmokeLauncherMag"
				};
				minElev=-9;
				maxElev=75;
				class Components
				{
					class VehicleSystemsDisplayManagerComponentLeft
					{
						class Components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={7000,4000,2000};
								resource="RscCustomInfoSensors";
							};
							class VehicleDriverDisplay
							{
								componentType="TransportFeedDisplayComponent";
								source="Driver";
							};
							class VehicleCommanderDisplay
							{
								componentType="TransportFeedDisplayComponent";
								source="Commander";
							};
							class EmptyDisplay
							{
								componentType="EmptyDisplayComponent";
							};
							class MinimapDisplay
							{
								componentType="MinimapDisplayComponent";
							};
							class MineDetectorDisplay
							{
								componentType="MineDetectorDisplayComponent";
							};
							class CrewDisplay
							{
								componentType="CrewDisplayComponent";
							};
							class UAVDisplay
							{
								componentType="UAVFeedDisplayComponent";
							};
							class SlingLoadDisplay
							{
								componentType="SlingLoadDisplayComponent";
							};
						};
						componentType="VehicleSystemsDisplayManager";
						left=1;
						defaultDisplay="EmptyDisplay";
						x="(profilenamespace getvariable [""IGUI_GRID_CUSTOMINFOLEFT_X"",	(safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
						y="(profilenamespace getvariable [""IGUI_GRID_CUSTOMINFOLEFT_Y"",	(safezoneY + safezoneH - 21 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
					};
					class VehicleSystemsDisplayManagerComponentRight
					{
						defaultDisplay="SensorDisplay";
						class Components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={16000,8000,4000,2000};
								resource="RscCustomInfoSensors";
							};
							class VehicleDriverDisplay
							{
								componentType="TransportFeedDisplayComponent";
								source="Driver";
							};
							class VehicleCommanderDisplay
							{
								componentType="TransportFeedDisplayComponent";
								source="Commander";
							};
							class EmptyDisplay
							{
								componentType="EmptyDisplayComponent";
							};
							class MinimapDisplay
							{
								componentType="MinimapDisplayComponent";
							};
							class MineDetectorDisplay
							{
								componentType="MineDetectorDisplayComponent";
							};
							class CrewDisplay
							{
								componentType="CrewDisplayComponent";
							};
							class UAVDisplay
							{
								componentType="UAVFeedDisplayComponent";
							};
							class SlingLoadDisplay
							{
								componentType="SlingLoadDisplayComponent";
							};
						};
						componentType="VehicleSystemsDisplayManager";
						right=1;
						x="(profilenamespace getvariable [""IGUI_GRID_CUSTOMINFORIGHT_X"",	((safezoneX + safezoneW) - (		(10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)))])";
						y="(profilenamespace getvariable [""IGUI_GRID_CUSTOMINFORIGHT_Y"",	(safezoneY + safezoneH - 21 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
					};
				};
			};
		};
		class AnimationSources: AnimationSources
		{
			class muzzle_hide_cannon
			{
				source="reload";
				weapon="DBA_40mw_HH9P_AC";
			};
			class muzzle_rot_cannon
			{
				source="ammorandom";
				weapon="DBA_40mw_HH9P_AC";
			};
			class HitComTurret_src
			{
				source="Hit";
				hitpoint="HitComTurret";
				raw=1;
			};
			class showBags
			{
				displayName="Show Bags";
				author="$STR_A3_Bohemia_Interactive";
				source="user";
				animPeriod=0.001;
				initPhase=0;
				mass=-50;
			};
		};
	};
};
