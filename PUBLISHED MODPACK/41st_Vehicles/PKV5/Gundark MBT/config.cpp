class CfgPatches
{
	class FST_PKV5_MainCannonUP
	{
		author="41st";
		requiredAddons[]=
		{
			"A3_Armor_F_Beta",
			"ls_vehicles_pkv5"
		};
		units[]=
		{
			"FST_PKV5_UP_Stormer",
			"FST_PKV5_UP_Stormer_Gray",
			"FST_PKV5_UP_Stormer_PDF"
		};
		weapons[]={};
	};
};

class CfgVehicles
{
	class LandVehicle;
	class Tank: LandVehicle
	{
		class NewTurret;
		class HitPoints;
	};
	class Tank_F: Tank
	{
		class ViewOptics;
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitEngine;
		};
		class Turrets
		{
			class MainTurret;
		};
		class CommanderOptics;
		class ViewCargo;
	};

	// Legion base actually contains the model, proxies, driver, cargo, gunner, and commander layout.
	// Declare its nested classes so our derived class can inherit and patch them instead of replacing them.
	class ls_vehicle_pkv5_base: Tank_F
	{
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitEngine;
			class HitFuel;
			class HitLTrack;
			class HitRTrack;
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class HitPoints
				{
					class HitTurret;
					class HitGun;
				};
			};
			class CommanderOptics: CommanderOptics
			{
				class HitPoints
				{
					class HitComGun;
					class HitComTurret;
				};
			};
		};
	};

	class FST_PKV5_Main_UP: ls_vehicle_pkv5_base
	{
		scope=0;
		scopeCurator=0;
		author="41st";
		displayName="PK-V5 Main Cannon";
		vehicleClass="Armored";
		accuracy=1000;

		// Legion model uses lowercase selections. The 41st and Legion UVs match.
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Vehicles\PKV5\Data\FST_PKV5_Hull.paa",
			"\41st_Vehicles\PKV5\Data\FST_PKV5_Cannon.paa"
		};

		textureList[]=
		{
			"FST_41st_Gundark", 1,
			"FST_41st_Gundark_Gray", 0,
			"FST_41st_Gundark_PDF", 0
		};
		class TextureSources
		{
			class FST_41st_Gundark
			{
				displayName="41st";
				author="41st";
				factions[]={"FST_Faction"};
				textures[]=
				{
					"\41st_Vehicles\PKV5\Data\FST_PKV5_Hull.paa",
					"\41st_Vehicles\PKV5\Data\FST_PKV5_Cannon.paa"
				};
			};
			class FST_41st_Gundark_Gray: FST_41st_Gundark
			{
				displayName="41st Gray";
				textures[]=
				{
					"\41st_Vehicles\PKV5\Data\FST_PKV5_Hull_Plain.paa",
					"\41st_Vehicles\PKV5\Data\FST_PKV5_Weapons_Cannon_Turret_Plain.paa"
				};
			};
			class FST_41st_Gundark_PDF: FST_41st_Gundark
			{
				displayName="PDF";
				textures[]=
				{
					"\41st_Vehicles\PKV5\Data\FST_PKV5_Hull_PDF.paa",
					"\41st_Vehicles\PKV5\Data\FST_PKV5_Weapons_Cannon_Turret_Plain.paa"
				};
			};
		};

		maximumLoad=5000;
		ace_cargo_space=30;
		ace_cargo_hasCargo=1;
		tas_canBlift=1;
		tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]";

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
			class _xx_ToolKit
			{
				name="ToolKit";
				count=1;
			};
		};

		// Restored 41st/3AS TX-130-style engine and movement sound profile from the original Gundark.
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
			"3as\3as_saber\Sounds\tx130startin.ogg",
			3,
			1
		};
		soundEngineOnExt[]=
		{
			"3as\3as_saber\Sounds\tx130startex.ogg",
			4,
			1,
			200
		};
		soundEngineOffInt[]=
		{
			"3as\3as_saber\Sounds\tx130stopin.ogg",
			3,
			1
		};
		soundEngineOffExt[]=
		{
			"3as\3as_saber\Sounds\tx130stopex.ogg",
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
					"3as\3as_saber\Sounds\tx130idle.ogg",
					1,
					1,
					480
				};
				frequency="0.95 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class Engine
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idle.ogg",
					1.1,
					1,
					550
				};
				frequency="0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_ext
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idle.ogg",
					1.4,
					1,
					550
				};
				frequency="0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_ext
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idle.ogg",
					1.5,
					1,
					550
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_ext
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idle.ogg",
					1.5,
					1,
					550
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_ext
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idle.ogg",
					1.5,
					1,
					550
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_ext
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idle.ogg",
					1.5,
					1,
					550
				};
				frequency="0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume="engineOn*camPos*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class IdleThrust
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idle.ogg",
					2.8,
					1,
					550
				};
				frequency="0.8 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class EngineThrust
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idle.ogg",
					1.5,
					1,
					550
				};
				frequency="0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_Thrust_ext
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idle.ogg",
					1.5,
					1,
					550
				};
				frequency="0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_Thrust_ext
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idle.ogg",
					1.5,
					1,
					550
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_Thrust_ext
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idle.ogg",
					1.5,
					1,
					550
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_Thrust_ext
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idle.ogg",
					1.5,
					1,
					550
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_Thrust_ext
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idle.ogg",
					1.5,
					1,
					550
				};
				frequency="0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class Idle_int
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idlein.ogg",
					1.5,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class Engine_int
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idlein.ogg",
					1,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_int
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idlein.ogg",
					1,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_int
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idlein.ogg",
					1,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_int
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idlein.ogg",
					1,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_int
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idlein.ogg",
					1.1,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_int
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idlein.ogg",
					1.25,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class IdleThrust_int
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idlein.ogg",
					1.25,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class EngineThrust_int
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idlein.ogg",
					1,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_Thrust_int
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idlein.ogg",
					1,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_Thrust_int
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idlein.ogg",
					1,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_Thrust_int
			{
				sound[]=
				{
					"3as\3as_saber\Sounds\tx130idlein.ogg",
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
					"3as\3as_saber\Sounds\tx130idlein.ogg",
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
					"3as\3as_saber\Sounds\tx130idlein.ogg",
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

		// 41st handling/tuning values layered onto Legion's smaller model.
		enginePower=1650;
		maxOmega=320;
		peakTorque=7700;
		maxSpeed=90;
		fuelCapacity=1885;
		brakeIdleSpeed=1.78;
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R2", -2.2000001,
				"N", 0,
				"D1", 4.6999998,
				"D2", 3.5,
				"D3", 2.5999999,
				"D4", 2,
				"D5", 1.5,
				"D6", 1.125,
				"D7", 0.85000002
			};
			TransmissionRatios[]=
			{
				"High", 15
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
			transmissionDelay=0.1;
		};

		armor=500;
		armorStructural=3.5;
		crewVulnerable=0;
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=4.5;
				passThrough=1;
				minimalHit=0.14;
				explosionShielding=2;
				radius=0.40000001;
			};
			class HitEngine: HitEngine
			{
				armor=1;
				passThrough=0;
				minimalHit=0.079999998;
				explosionShielding=1.4400001;
				radius=0.33000001;
			};
			class HitFuel: HitFuel
			{
				armor=0.30000001;
				passThrough=0.1;
				minimalHit=0.1;
				explosionShielding=0.60000002;
				radius=0.30000001;
			};
			class HitLTrack: HitLTrack
			{
				armor=1;
				passThrough=0;
				minimalHit=0.079999998;
				explosionShielding=1.4400001;
				radius=0.30000001;
			};
			class HitRTrack: HitRTrack
			{
				armor=1;
				passThrough=0;
				minimalHit=0.079999998;
				explosionShielding=1.4400001;
				radius=0.30000001;
			};
		};

		smokeLauncherGrenadeCount=8;
		smokeLauncherVelocity=14;
		smokeLauncherOnTurret=0;
		smokeLauncherAngle=120;

		// Patch Legion's inherited turret classes. Do not replace them with bare classes,
		// or Arma drops the gunner/commander seat metadata inherited from Tank_F/Legion.
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				// Keep Legion's animated turret layout, but force Arma to use the Legion muzzle/direction memory points
				// for shot origin/tracer/smoke instead of falling back to the inherited/static origin.
				memoryPointGun="machinegun";
				gunBeg="machinegun";
				gunEnd="pip1_dir";
				selectionFireAnim="";

				weapons[]=
				{
					"FST_PKV5_Sabre_Cannons_Super_NoSmoke",
					"Laserdesignator_vehicle"
				};
				magazines[]=
				{
					"FST_25rnd_Gundark_Mag",
					"FST_25rnd_Gundark_Mag",
					"FST_25rnd_Gundark_Mag_HE",
					"FST_25rnd_Gundark_Mag_HE",
					"Laserbatteries"
				};
				minElev=-6;
				maxElev=20;
				initElev=0;
				turretInfoType="RscWeaponRangeZeroing";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400};
				discreteDistanceInitIndex=5;
				gunnerForceOptics=0;
				class HitPoints: HitPoints
				{
					class HitTurret: HitTurret
					{
						armor=0.80000001;
						passThrough=0;
						minimalHit=0.2;
						explosionShielding=0.30000001;
						radius=0.25;
					};
					class HitGun: HitGun
					{
						armor=0.30000001;
						passThrough=0;
						minimalHit=0.5;
						explosionShielding=1;
						radius=0.25;
					};
				};
			};
			class CommanderOptics: CommanderOptics
			{
				weapons[]=
				{
					"SmokeLauncher",
					"Laserdesignator_vehicle"
				};
				magazines[]=
				{
					"SmokeLauncherMag",
					"SmokeLauncherMag",
					"Laserbatteries"
				};
				minElev=-25;
				maxElev=60;
				initElev=0;
				minTurn=-360;
				maxTurn=360;
				initTurn=0;
				turretInfoType="RscWeaponRangeZeroing";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex=2;
			};
		};
	};

	class FST_PKV5_UP_Stormer: FST_PKV5_Main_UP
	{
		scope=2;
		scopeCurator=2;
		displayName="[41st] PK-V5 'Gundark' Light Tank";
		accuracy=1000;
		side=1;
		faction="FST_Faction";
		crew="FST_Trooper_P2_DC15S";
		typicalCrew[]={"FST_Trooper_P2_DC15S"};
		typicalCargo[]={"FST_Trooper_P2_DC15S"};
		editorSubcategory="FST_Ground_Vehicle";
		hiddenSelectionsTextures[]=
		{
			"\41st_Vehicles\PKV5\Data\FST_PKV5_Hull.paa",
			"\41st_Vehicles\PKV5\Data\FST_PKV5_Cannon.paa"
		};
	};

	class FST_PKV5_UP_Stormer_Gray: FST_PKV5_Main_UP
	{
		scope=2;
		scopeCurator=2;
		displayName="[41st] PK-V5 'Gundark' Light Tank/Gray";
		accuracy=1000;
		side=1;
		faction="FST_Faction";
		crew="FST_P2_Recruit";
		typicalCrew[]={"FST_P2_Recruit"};
		typicalCargo[]={"FST_P2_Recruit"};
		editorSubcategory="FST_Ground_Vehicle";
		hiddenSelectionsTextures[]=
		{
			"\41st_Vehicles\PKV5\Data\FST_PKV5_Hull_Plain.paa",
			"\41st_Vehicles\PKV5\Data\FST_PKV5_Weapons_Cannon_Turret_Plain.paa"
		};
	};

	class FST_PKV5_UP_Stormer_PDF: FST_PKV5_Main_UP
	{
		scope=2;
		scopeCurator=2;
		displayName="[41st] PK-V5 'Gundark' Light Tank/PDF";
		accuracy=1000;
		side=0;
		faction="FST_Faction";
		crew="JLTS_Droid_B1_Prototype";
		typicalCrew[]={"JLTS_Droid_B1_Prototype"};
		typicalCargo[]={"JLTS_Droid_B1_Prototype"};
		editorSubcategory="FST_Ground_Vehicle";
		hiddenSelectionsTextures[]=
		{
			"\41st_Vehicles\PKV5\Data\FST_PKV5_Hull_PDF.paa",
			"\41st_Vehicles\PKV5\Data\FST_PKV5_Weapons_Cannon_Turret_Plain.paa"
		};
	};
};
