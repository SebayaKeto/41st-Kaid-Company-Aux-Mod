class CfgPatches
{
	class FST_AA5
	{
		units[]=
		{
			"FST_X34_Reb",
			"FST_X34_MK2_Reb"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Soft_F",
			"JMSLLTE_vehicles_gr"
		};
	};
};
class RCWSOptics;
class ViewOptics;
class CfgVehicles
{
	class LandVehicle;
	class Car: LandVehicle
	{
		class NewTurret;
	};
	class Car_F: Car
	{
		class HitPoints
		{
			class HitLFWheel;
			class HitLF2Wheel;
			class HitRFWheel;
			class HitRF2Wheel;
			class HitBody;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
		};
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class Components;
			};
		};
		class AnimationSources;
		class EventHandlers;
	};
	class FST_veh_landspeeder_base: Car_F
	{
		author="JMax";
		model="\JMSLLTE_veh_gr_m\landspeeders\x34";
		picture="\JMSLLTE_veh_gr\landspeeders\data\pic_x34.paa";
		Icon="\JMSLLTE_veh_gr\landspeeders\data\ico_x34.paa";
		_generalMacro="JMSLLTE_veh_landspeeder_base";
		displayName="X-34";
		editorSubcategory="JMSLLTE_Speeders";
		terrainCoef=0;
		turnCoef=8;
		precision=10;
		brakeDistance=3;
		acceleration=30;
		enableRadio=1;
		enableGPS=1;
		crewCrashProtection=1.25;
		crewExplosionProtection=0.80000001;
		damageResistance=0.0071899998;
		fireResistance=50;
		armor=100;
		armorStructural=2;
		cost=10000;
		transportMaxBackpacks=3;
		transportSoldier=1;
		slingLoadCargoMemoryPoints[]=
		{
			"SlingLoadCargo1",
			"SlingLoadCargo2",
			"SlingLoadCargo3",
			"SlingLoadCargo4"
		};
		wheelDamageRadiusCoef=0.89999998;
		wheelDestroyRadiusCoef=0.2;
		maxFordingDepth=0.5;
		waterResistance=1;
		driverLeftHandAnimName="drivewheel";
		driverRightHandAnimName="drivewheel";
		canFloat=1;
		waterLinearDampingCoefY=5;
		waterLinearDampingCoefX=2;
		waterAngularDampingCoef=5;
		waterResistanceCoef=0;
		waterLeakiness=1000;
		rudderForceCoef=2;
		rudderForceCoefAtMaxSpeed=2;
		waterEffectSpeed=1;
		engineEffectSpeed=5;
		waterFastEffectSpeed=10;
		engineShiftY=1.2;
		driveOnComponent[]=
		{
			"Slide"
		};
		class TransportItems
		{
			class _xx_FirstAidKit
			{
				name="FirstAidKit";
				count=4;
			};
			class _xx_ToolKit
			{
				name="ToolKit";
				count=1;
			};
		};
		class HitPoints: HitPoints
		{
			class HitLFWheel: HitLFWheel
			{
				armor=0.5;
				passThrough=0;
			};
			class HitLF2Wheel: HitLF2Wheel
			{
				armor=0.5;
				passThrough=0;
			};
			class HitRFWheel: HitRFWheel
			{
				armor=0.5;
				passThrough=0;
			};
			class HitRF2Wheel: HitRF2Wheel
			{
				armor=0.5;
				passThrough=0;
			};
			class HitGlass1: HitGlass1
			{
				armor=0.40000001;
			};
			class HitHull: HitBody
			{
				armor=1;
				material=-1;
				armorComponent="hit_hull";
				name="hit_hull_point";
				visual="camo1";
				passThrough=1;
				minimalHit=0.2;
				explosionShielding=0.5;
				radius=0.15000001;
			};
			class HitEngine
			{
				armor=1;
				material=-1;
				armorComponent="hit_engine";
				name="hit_engine_point";
				visual="-";
				passThrough=0;
				minimalHit=0.2;
				explosionShielding=1;
				radius=0.17;
				class DestructionEffects
				{
					ammoExplosionEffect="";
					class JMSSA_Engine_Smoke
					{
						simulation="particles";
						type="SmallWreckSmoke";
						position="engine_smoke";
						intensity=0.5;
						interval=1;
						lifeTime=60;
					};
					class JMSSA_Engine_Fire: JMSSA_Engine_Smoke
					{
						type="SmallFireFPlace";
					};
					class JMSSA_Engine_Sparks: JMSSA_Engine_Smoke
					{
						type="FireSparks";
					};
					class JMSSA_Engine_Sounds: JMSSA_Engine_Smoke
					{
						simulation="sound";
						type="Fire";
					};
				};
			};
			class HitFuel
			{
				armor=1;
				material=-1;
				armorComponent="hit_fuel";
				name="hit_fuel_point";
				visual="-";
				passThrough=0;
				minimalHit=0.1;
				explosionShielding=1;
				radius=0.11;
			};
		};
		driverAction="JMSLLTE_driver_x34";
		driverInAction="JMSLLTE_driver_x34";
		forceHideDriver=0;
		cargoAction[]=
		{
			"JMSLLTE_gunner_x34"
		};
		getInAction="GetInMid";
		getOutAction="GetOutHigh";
		cargoGetInAction[]=
		{
			"GetInMid"
		};
		cargoGetOutAction[]=
		{
			"GetOutHigh"
		};
		memoryPointDriverOptics="driverview";
		memoryPointGun[]=
		{
			"usti hlavneR",
			"usti hlavneL"
		};
		weapons[]=
		{
			"CarHorn"
		};
		magazines[]={};
		soundGetIn[]=
		{
			"A3\Sounds_F_EPC\Truck_03\int\getin",
			0.56234133,
			1
		};
		soundGetOut[]=
		{
			"A3\Sounds_F_EPC\Truck_03\int\getout",
			0.56234133,
			1,
			20
		};
		soundDammage[]=
		{
			"",
			0.56234133,
			1
		};
		soundEngineOnInt[]=
		{
			"JMSLLTE_veh_gr\Landspeeders\sounds\x34_engine_on.ogg",
			"db-1",
			1
		};
		soundEngineOnExt[]=
		{
			"JMSLLTE_veh_gr\Landspeeders\sounds\x34_engine_on.ogg",
			"db3",
			1,
			500
		};
		soundEngineOffInt[]=
		{
			"JMSLLTE_veh_gr\Landspeeders\sounds\x34_engine_off.ogg",
			"db-1",
			1
		};
		soundEngineOffExt[]=
		{
			"JMSLLTE_veh_gr\Landspeeders\sounds\x34_engine_off.ogg",
			"db3",
			1,
			500
		};
		buildCrash0[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",
			1,
			1,
			200
		};
		buildCrash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",
			1,
			1,
			200
		};
		buildCrash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",
			1,
			1,
			200
		};
		buildCrash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",
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
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1",
			1,
			1,
			200
		};
		WoodCrash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1",
			1,
			1,
			200
		};
		WoodCrash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1",
			1,
			1,
			200
		};
		WoodCrash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1",
			1,
			1,
			200
		};
		soundWoodCrash[]=
		{
			"woodCrash0",
			0.25,
			"woodCrash1",
			0.25,
			"woodCrash2",
			0.25,
			"woodCrash3",
			0.25
		};
		armorCrash0[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",
			1,
			1,
			200
		};
		armorCrash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",
			1,
			1,
			200
		};
		armorCrash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",
			1,
			1,
			200
		};
		armorCrash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",
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
		Crash0[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",
			1,
			1,
			200
		};
		Crash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",
			1,
			1,
			200
		};
		Crash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",
			1,
			1,
			200
		};
		Crash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",
			1,
			1,
			200
		};
		soundCrashes[]=
		{
			"Crash0",
			0.25,
			"Crash1",
			0.25,
			"Crash2",
			0.25,
			"Crash3",
			0.25
		};
		class Sounds
		{
			class Idle_ext
			{
				sound[]=
				{
					"A3\sounds_f\vehicles\soft\offroad_01\engine_ext_idle",
					0.56234133,
					1,
					200
				};
				frequency="0.95 + ((rpm/ 3000) factor[(100/ 3000),(800/ 3000)])*0.15";
				volume="engineOn*camPos*(((rpm/ 3000) factor[(10/ 3000),(50/ 3000)]) * ((rpm/ 3000) factor[(830/ 3000),(600/ 3000)]))";
			};
			class Engine
			{
				sound[]=
				{
					"JMSLLTE_veh_gr\Landspeeders\sounds\x34_engine.ogg",
					0.56234133,
					1,
					250
				};
				frequency="0.8 + ((rpm/ 3000) factor[(610/ 3000),(1100/ 3000)])*0.2";
				volume="engineOn*camPos*(((rpm/ 3000) factor[(620/ 3000),(820/ 3000)]) * ((rpm/ 3000) factor[(1200/ 3000),(1000/ 3000)]))";
			};
			class Engine1_ext
			{
				sound[]=
				{
					"JMSLLTE_veh_gr\Landspeeders\sounds\x34_engine.ogg",
					0.63095737,
					1,
					280
				};
				frequency="0.8 + ((rpm/ 3000) factor[(900/ 3000),(1500/ 3000)])*0.2";
				volume="engineOn*camPos*(((rpm/ 3000) factor[(900/ 3000),(1100/ 3000)]) * ((rpm/ 3000) factor[(1500/ 3000),(1150/ 3000)]))";
			};
			class Engine2_ext
			{
				sound[]=
				{
					"JMSLLTE_veh_gr\Landspeeders\sounds\x34_engine.ogg",
					0.63095737,
					1,
					320
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1150/ 3000),(1850/ 3000)])*0.2";
				volume="engineOn*camPos*(((rpm/ 3000) factor[(1170/ 3000),(1500/ 3000)]) * ((rpm/ 3000) factor[(1900/ 3000),(1650/ 3000)]))";
			};
			class Engine3_ext
			{
				sound[]=
				{
					"JMSLLTE_veh_gr\Landspeeders\sounds\x34_engine.ogg",
					0.70794576,
					1,
					340
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1600/ 3000),(2300/ 3000)])*0.1";
				volume="engineOn*camPos*(((rpm/ 3000) factor[(1600/ 3000),(1850/ 3000)]) * ((rpm/ 3000) factor[(2300/ 3000),(2050/ 3000)]))";
			};
			class Engine4_ext
			{
				sound[]=
				{
					"JMSLLTE_veh_gr\Landspeeders\sounds\x34_engine.ogg",
					0.70794576,
					1,
					360
				};
				frequency="0.8 + ((rpm/ 3000) factor[(2050/ 3000),(2700/ 3000)])*0.1";
				volume="engineOn*camPos*(((rpm/ 3000) factor[(2000/ 3000),(2300/ 3000)]) * ((rpm/ 3000) factor[(2700/ 3000),(2450/ 3000)]))";
			};
			class Engine5_ext
			{
				sound[]=
				{
					"JMSLLTE_veh_gr\Landspeeders\sounds\x34_engine.ogg",
					0.79432821,
					1,
					400
				};
				frequency="0.8 + ((rpm/ 3000) factor[(2450/ 3000),(3000/ 3000)])*0.1";
				volume="engineOn*camPos*((rpm/ 3000) factor[(2400/ 3000),(2700/ 3000)])";
			};
			class IdleThrust
			{
				sound[]=
				{
					"A3\Sounds_F_EPC\Truck_03\ext\truck03_exhaust_1",
					0.63095737,
					1,
					340
				};
				frequency="0.8 + ((rpm/ 3000) factor[(100/ 3000),(800/ 3000)])*0.15";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(10/ 3000),(50/ 3000)]) * ((rpm/ 3000) factor[(830/ 3000),(600/ 3000)]))";
			};
			class EngineThrust
			{
				sound[]=
				{
					"A3\Sounds_F_EPC\Truck_03\ext\truck03_exhaust_2",
					0.70794576,
					1,
					360
				};
				frequency="0.8 + ((rpm/ 3000) factor[(610/ 3000),(1100/ 3000)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(620/ 3000),(820/ 3000)]) * ((rpm/ 3000) factor[(1200/ 3000),(1000/ 3000)]))";
			};
			class Engine1_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F_EPC\Truck_03\ext\truck03_exhaust_3",
					0.79432821,
					1,
					400
				};
				frequency="0.8 + ((rpm/ 3000) factor[(900/ 3000),(1500/ 3000)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(900/ 3000),(1100/ 3000)]) * ((rpm/ 3000) factor[(1500/ 3000),(1150/ 3000)]))";
			};
			class Engine2_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F_EPC\Truck_03\ext\truck03_exhaust_4",
					0.89125091,
					1,
					450
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1150/ 3000),(1850/ 3000)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(1170/ 3000),(1500/ 3000)]) * ((rpm/ 3000) factor[(1900/ 3000),(1650/ 3000)]))";
			};
			class Engine3_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F_EPC\Truck_03\ext\truck03_exhaust_5",
					1,
					1,
					510
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1600/ 3000),(2300/ 3000)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(1600/ 3000),(1850/ 3000)]) * ((rpm/ 3000) factor[(2300/ 3000),(2050/ 3000)]))";
			};
			class Engine4_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F_EPC\Truck_03\ext\truck03_exhaust_6",
					1,
					1,
					520
				};
				frequency="0.8 + ((rpm/ 3000) factor[(2050/ 3000),(2700/ 3000)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(2000/ 3000),(2300/ 3000)]) * ((rpm/ 3000) factor[(2700/ 3000),(2450/ 3000)]))";
			};
			class Engine5_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F_EPC\Truck_03\ext\truck03_exhaust_7",
					1.2589254,
					1,
					550
				};
				frequency="0.8 + ((rpm/ 3000) factor[(2450/ 3000),(3000/ 3000)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 3000) factor[(2400/ 3000),(2700/ 3000)])";
			};
			class Idle_int
			{
				sound[]=
				{
					"A3\sounds_f\vehicles\soft\offroad_01\engine_ext_idle",
					0.2818383,
					1
				};
				frequency="0.8 + ((rpm/ 3000) factor[(100/ 3000),(800/ 3000)])*0.15";
				volume="engineOn*(1-camPos)*(((rpm/ 3000) factor[(10/ 3000),(50/ 3000)]) * ((rpm/ 3000) factor[(830/ 3000),(600/ 3000)]))";
			};
			class Engine_int
			{
				sound[]=
				{
					"JMSLLTE_veh_gr\Landspeeders\sounds\x34_engine.ogg",
					0.31622776,
					1
				};
				frequency="0.8 + ((rpm/ 3000) factor[(610/ 3000),(1100/ 3000)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 3000) factor[(620/ 3000),(820/ 3000)]) * ((rpm/ 3000) factor[(1200/ 3000),(1000/ 3000)]))";
			};
			class Engine1_int
			{
				sound[]=
				{
					"JMSLLTE_veh_gr\Landspeeders\sounds\x34_engine.ogg",
					0.31622776,
					1
				};
				frequency="0.8 + ((rpm/ 3000) factor[(900/ 3000),(1500/ 3000)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 3000) factor[(900/ 3000),(1100/ 3000)]) * ((rpm/ 3000) factor[(1500/ 3000),(1150/ 3000)]))";
			};
			class Engine2_int
			{
				sound[]=
				{
					"JMSLLTE_veh_gr\Landspeeders\sounds\x34_engine.ogg",
					0.31622776,
					1
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1150/ 3000),(1850/ 3000)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 3000) factor[(1170/ 3000),(1500/ 3000)]) * ((rpm/ 3000) factor[(1900/ 3000),(1650/ 3000)]))";
			};
			class Engine3_int
			{
				sound[]=
				{
					"JMSLLTE_veh_gr\Landspeeders\sounds\x34_engine.ogg",
					0.3548134,
					1
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1600/ 3000),(2300/ 3000)])*0.1";
				volume="engineOn*(1-camPos)*(((rpm/ 3000) factor[(1600/ 3000),(1850/ 3000)]) * ((rpm/ 3000) factor[(2300/ 3000),(2050/ 3000)]))";
			};
			class Engine4_int
			{
				sound[]=
				{
					"JMSLLTE_veh_gr\Landspeeders\sounds\x34_engine.ogg",
					0.39810717,
					1
				};
				frequency="0.8 + ((rpm/ 3000) factor[(2050/ 3000),(2700/ 3000)])*0.1";
				volume="engineOn*(1-camPos)*(((rpm/ 3000) factor[(2000/ 3000),(2300/ 3000)]) * ((rpm/ 3000) factor[(2700/ 3000),(2450/ 3000)]))";
			};
			class Engine5_int
			{
				sound[]=
				{
					"JMSLLTE_veh_gr\Landspeeders\sounds\x34_engine.ogg",
					0.44668359,
					1
				};
				frequency="0.8 + ((rpm/ 3000) factor[(2450/ 3000),(3000/ 3000)])*0.1";
				volume="engineOn*(1-camPos)*((rpm/ 3000) factor[(2400/ 3000),(2700/ 3000)])";
			};
			class IdleThrust_int
			{
				sound[]=
				{
					"A3\Sounds_F_EPC\Truck_03\int\truck03_exhaust_1",
					0.3548134,
					1
				};
				frequency="0.8 + ((rpm/ 3000) factor[(100/ 3000),(800/ 3000)])*0.15";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(10/ 3000),(50/ 3000)]) * ((rpm/ 3000) factor[(830/ 3000),(600/ 3000)]))";
			};
			class EngineThrust_int
			{
				sound[]=
				{
					"A3\Sounds_F_EPC\Truck_03\int\truck03_exhaust_2",
					0.39810717,
					1
				};
				frequency="0.8 + ((rpm/ 3000) factor[(610/ 3000),(1100/ 3000)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(620/ 3000),(820/ 3000)]) * ((rpm/ 3000) factor[(1200/ 3000),(1000/ 3000)]))";
			};
			class Engine1_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F_EPC\Truck_03\int\truck03_exhaust_3",
					0.44668359,
					1
				};
				frequency="0.8 + ((rpm/ 3000) factor[(900/ 3000),(1500/ 3000)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(900/ 3000),(1100/ 3000)]) * ((rpm/ 3000) factor[(1500/ 3000),(1150/ 3000)]))";
			};
			class Engine2_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F_EPC\Truck_03\int\truck03_exhaust_4",
					0.50118721,
					1
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1150/ 3000),(1850/ 3000)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(1170/ 3000),(1500/ 3000)]) * ((rpm/ 3000) factor[(1900/ 3000),(1650/ 3000)]))";
			};
			class Engine3_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F_EPC\Truck_03\int\truck03_exhaust_5",
					0.56234133,
					1
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1600/ 3000),(2300/ 3000)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(1600/ 3000),(1850/ 3000)]) * ((rpm/ 3000) factor[(2300/ 3000),(2050/ 3000)]))";
			};
			class Engine4_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F_EPC\Truck_03\int\truck03_exhaust_6",
					0.63095737,
					1
				};
				frequency="0.8 + ((rpm/ 3000) factor[(2050/ 3000),(2700/ 3000)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(2000/ 3000),(2300/ 3000)]) * ((rpm/ 3000) factor[(2700/ 3000),(2450/ 3000)]))";
			};
			class Engine5_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F_EPC\Truck_03\int\truck03_exhaust_7",
					0.70794576,
					1
				};
				frequency="0.8 + ((rpm/ 3000) factor[(2450/ 3000),(3000/ 3000)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 3000) factor[(2400/ 3000),(2700/ 3000)])";
			};
			class TiresRockOut
			{
				sound[]=
				{
					"",
					0.79432821,
					1,
					120
				};
				frequency="1";
				volume="camPos*rock*(speed factor[2, 20])";
			};
			class TiresSandOut
			{
				sound[]=
				{
					"",
					0.70794576,
					1,
					120
				};
				frequency="1";
				volume="camPos*sand*(speed factor[2, 20])";
			};
			class TiresGrassOut
			{
				sound[]=
				{
					"",
					0.70794576,
					1,
					120
				};
				frequency="1";
				volume="camPos*grass*(speed factor[2, 20])";
			};
			class TiresMudOut
			{
				sound[]=
				{
					"",
					0.70794576,
					1,
					120
				};
				frequency="1";
				volume="camPos*mud*(speed factor[2, 20])";
			};
			class TiresGravelOut
			{
				sound[]=
				{
					"",
					0.70794576,
					1,
					120
				};
				frequency="1";
				volume="camPos*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltOut
			{
				sound[]=
				{
					"",
					0.70794576,
					1,
					120
				};
				frequency="1";
				volume="camPos*asphalt*(speed factor[2, 20])";
			};
			class NoiseOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\noise_ext_car_3",
					0.79432821,
					1,
					90
				};
				frequency="1";
				volume="camPos*(damper0 max 0.02)*(speed factor[0, 8])";
			};
			class TiresRockIn
			{
				sound[]=
				{
					"",
					0.39810717,
					1
				};
				frequency="1";
				volume="(1-camPos)*rock*(speed factor[2, 20])";
			};
			class TiresSandIn
			{
				sound[]=
				{
					"",
					0.39810717,
					1
				};
				frequency="1";
				volume="(1-camPos)*sand*(speed factor[2, 20])";
			};
			class TiresGrassIn
			{
				sound[]=
				{
					"",
					0.39810717,
					1
				};
				frequency="1";
				volume="(1-camPos)*grass*(speed factor[2, 20])";
			};
			class TiresMudIn
			{
				sound[]=
				{
					"",
					0.39810717,
					1
				};
				frequency="1";
				volume="(1-camPos)*mud*(speed factor[2, 20])";
			};
			class TiresGravelIn
			{
				sound[]=
				{
					"",
					0.39810717,
					1
				};
				frequency="1";
				volume="(1-camPos)*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltIn
			{
				sound[]=
				{
					"",
					0.39810717,
					1
				};
				frequency="1";
				volume="(1-camPos)*asphalt*(speed factor[2, 20])";
			};
			class NoiseIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\noise_int_car_3",
					0.44668359,
					1
				};
				frequency="1";
				volume="(damper0 max 0.1)*(speed factor[0, 8])*(1-camPos)";
			};
			class breaking_ext_road
			{
				sound[]=
				{
					"",
					0.39810717,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(LongSlipDrive Factor[-0.1, -0.3])*(Speed Factor[2, 10])";
			};
			class acceleration_ext_road
			{
				sound[]=
				{
					"",
					0.39810717,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(LongSlipDrive Factor[0.1, 0.3])*(Speed Factor[10, 1])";
			};
			class turn_left_ext_road
			{
				sound[]=
				{
					"",
					0.39810717,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(latSlipDrive Factor[0.1, 0.3])*(Speed Factor[0, 10])";
			};
			class turn_right_ext_road
			{
				sound[]=
				{
					"",
					0.39810717,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(latSlipDrive Factor[-0.1, -0.3])*(Speed Factor[0, 10])";
			};
			class breaking_ext_dirt
			{
				sound[]=
				{
					"",
					0.39810717,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(LongSlipDrive Factor[-0.1, -0.3])*(Speed Factor[2, 10])";
			};
			class acceleration_ext_dirt
			{
				sound[]=
				{
					"",
					0.39810717,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(LongSlipDrive Factor[0.1, 0.3])*(Speed Factor[10, 1])";
			};
			class turn_left_ext_dirt
			{
				sound[]=
				{
					"",
					0.39810717,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(latSlipDrive Factor[0.1, 0.3])*(Speed Factor[0, 10])";
			};
			class turn_right_ext_dirt
			{
				sound[]=
				{
					"",
					0.39810717,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(latSlipDrive Factor[-0.1, -0.3])*(Speed Factor[0, 10])";
			};
			class breaking_int_road
			{
				sound[]=
				{
					"",
					0.56234133,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(LongSlipDrive Factor[-0.1, -0.3])*(Speed Factor[2, 6])";
			};
			class acceleration_int_road
			{
				sound[]=
				{
					"",
					0.56234133,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(LongSlipDrive Factor[0.1, 0.3])*(Speed Factor[10, 1])";
			};
			class turn_left_int_road
			{
				sound[]=
				{
					"",
					0.56234133,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(latSlipDrive Factor[0.1, 0.3])*(Speed Factor[0, 10])";
			};
			class turn_right_int_road
			{
				sound[]=
				{
					"",
					0.56234133,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(latSlipDrive Factor[-0.1, -0.3])*(Speed Factor[0, 10])";
			};
			class breaking_int_dirt
			{
				sound[]=
				{
					"",
					0.56234133,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(LongSlipDrive Factor[-0.1, -0.3])*(Speed Factor[2, 6])";
			};
			class acceleration_int_dirt
			{
				sound[]=
				{
					"",
					0.56234133,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(LongSlipDrive Factor[0.1, 0.3])*(Speed Factor[10, 1])";
			};
			class turn_left_int_dirt
			{
				sound[]=
				{
					"",
					0.56234133,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(latSlipDrive Factor[0.1, 0.3])*(Speed Factor[0, 10])";
			};
			class turn_right_int_dirt
			{
				sound[]=
				{
					"",
					0.56234133,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(latSlipDrive Factor[-0.1, -0.3])*(Speed Factor[0, 10])";
			};
		};
		thrustDelay=0.2;
		brakeIdleSpeed=1.78;
		maxSpeed=150;
		fuelCapacity=35;
		wheelCircumference=2.277;
		antiRollbarForceCoef=85;
		antiRollbarForceLimit=185;
		antiRollbarSpeedMin=0;
		antiRollbarSpeedMax=100;
		steerAheadSimul=1;
		steerAheadPlan=1;
		predictTurnSimul=1;
		predictTurnPlan=1;
		idleRpm=900;
		redRpm=5900;
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-4.8400002,
				"N",
				0,
				"D1",
				3.4300001,
				"D2",
				2.01,
				"D3",
				1.42,
				"D4",
				1,
				"D5",
				0.82999998,
				"D6",
				0.58999997
			};
			TransmissionRatios[]=
			{
				"High",
				6.7589998
			};
			AmphibiousRatios[]=
			{
				"R1",
				-4.8400002,
				"N",
				0,
				"D1",
				3.4300001,
				"D2",
				2.01,
				"D3",
				1.42,
				"D4",
				1,
				"D5",
				0.82999998,
				"D6",
				0.58999997
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
		};
		simulation="carx";
		dampersBumpCoef=3;
		differentialType="all_limited";
		frontRearSplit=0.60000002;
		frontBias=1.5;
		rearBias=1.4;
		centreBias=1.3;
		clutchStrength=1000;
		enginePower=600;
		maxOmega=520;
		peakTorque=2260;
		dampingRateFullThrottle=0.079999998;
		dampingRateZeroThrottleClutchEngaged=1;
		dampingRateZeroThrottleClutchDisengaged=0.15000001;
		torqueCurve[]=
		{
			{0,0},
			{0.278,0.5},
			{0.34999999,0.75},
			{0.461,1},
			{0.60000002,0.94999999},
			{0.69999999,0.85000002},
			{0.80000001,0.75},
			{1,0.5}
		};
		changeGearMinEffectivity[]={0.94999999,0.15000001,0.94999999,0.94999999,0.94999999,0.94999999,0.94999999};
		switchTime=0.1;
		latency=1;
		class Wheels
		{
			class LF
			{
				boneName="wheel_1_1_damper";
				steering=1;
				side="left";
				center="wheel_1_1_axis";
				boundary="wheel_1_1_bound";
				mass=100;
				MOI=40;
				dampingRate=0.079999998;
				maxBrakeTorque=15000;
				maxHandBrakeTorque=0;
				suspTravelDirection[]={0,-1,0};
				suspForceAppPointOffset="wheel_1_1_axis";
				tireForceAppPointOffset="wheel_1_1_axis";
				maxCompression=0.15000001;
				mMaxDroop=0.15000001;
				sprungMass=2000;
				springStrength=130000;
				springDamperRate=13000;
				longitudinalStiffnessPerUnitGravity=10000;
				latStiffX=25;
				latStiffY=180;
				frictionVsSlipGraph[]=
				{
					{0,1},
					{0.5,1},
					{1,1}
				};
			};
			class LR: LF
			{
				boneName="wheel_1_2_damper";
				steering=0;
				center="wheel_1_2_axis";
				boundary="wheel_1_2_bound";
				suspForceAppPointOffset="wheel_1_2_axis";
				tireForceAppPointOffset="wheel_1_2_axis";
			};
			class RF: LF
			{
				boneName="wheel_2_1_damper";
				center="wheel_2_1_axis";
				boundary="wheel_2_1_bound";
				suspForceAppPointOffset="wheel_2_1_axis";
				tireForceAppPointOffset="wheel_2_1_axis";
				steering=1;
				side="right";
			};
			class RR: RF
			{
				boneName="wheel_2_2_damper";
				steering=0;
				center="wheel_2_2_axis";
				boundary="wheel_2_2_bound";
				suspForceAppPointOffset="wheel_2_2_axis";
				tireForceAppPointOffset="wheel_2_2_axis";
			};
		};
		class PlayerSteeringCoefficients
		{
			turnIncreaseConst=0.30000001;
			turnIncreaseLinear=1;
			turnIncreaseTime=1;
			turnDecreaseConst=5;
			turnDecreaseLinear=3;
			turnDecreaseTime=0;
			maxTurnHundred=0.69999999;
		};
		memoryPointTrackFLL="TrackFLL";
		memoryPointTrackFLR="TrackFLR";
		memoryPointTrackBLL="TrackBLL";
		memoryPointTrackBLR="TrackBLR";
		memoryPointTrackFRL="TrackFRL";
		memoryPointTrackFRR="TrackFRR";
		memoryPointTrackBRL="TrackBRL";
		memoryPointTrackBRR="TrackBRR";
		class CargoTurret;
		class Turrets: Turrets
		{
			class CargoTurret_01: CargoTurret
			{
				gunnerAction="passenger_boat_4";
				gunnerInAction="passenger_boat_4";
				gunnerGetInAction="GetInMid";
				gunnerGetOutAction="GetOutHigh";
				memoryPointsGetInGunner="pos cargo LR";
				memoryPointsGetInGunnerDir="pos cargo LR dir";
				gunnerName="Passenger (left)";
				gunnerCompartments="Compartment2";
				memoryPointGunnerOptics="";
				LODTurnedIn=1;
				LODTurnedOut=1;
				proxyIndex=11;
				isPersonTurret=1;
				canHideGunner=0;
				allowLauncherIn=1;
				allowLauncherOut=1;
				ejectDeadGunner=1;
				class TurnIn
				{
					limitsArrayTop[]=
					{
						{33.820801,-93.961601},
						{40.890598,66.570503}
					};
					limitsArrayBottom[]=
					{
						{-9.4643002,-94.575302},
						{-8.3683004,-67.686699},
						{-9.7173004,43.637199},
						{-10.1082,78.916603}
					};
				};
				class dynamicViewLimits
				{
					CargoTurret_02[]={-85,65};
				};
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerAction="passenger_boat_3";
				gunnerInAction="passenger_boat_3";
				gunnerName="Passenger (right)";
				memoryPointsGetInGunner="pos cargo RR";
				memoryPointsGetInGunnerDir="pos cargo RR dir";
				gunnerCompartments="Compartment2";
				proxyIndex=12;
				class TurnIn
				{
					limitsArrayTop[]=
					{
						{37.1488,-71.900299},
						{36.4967,92.275703}
					};
					limitsArrayBottom[]=
					{
						{-22.183201,-70.0989},
						{-13.9068,-22.810699},
						{-7.1236,75.684898},
						{-7.8564,102.5826}
					};
				};
				class dynamicViewLimits
				{
					CargoTurret_01[]={-65,85};
				};
			};
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"JMSLLTE_veh_gr\landspeeders\data\x34.rvmat",
				"JMSLLTE_veh_gr\landspeeders\data\x34_damage.rvmat",
				"JMSLLTE_veh_gr\destruct.rvmat",
				"JMSLLTE_veh_gr\armored_glass.rvmat",
				"JMSLLTE_veh_gr\armored_glass_damage.rvmat",
				"JMSLLTE_veh_gr\destruct.rvmat"
			};
		};
		destrType="DestructEngine";
		explosionEffect="";
		secondaryExplosion=-1;
		class DestructionEffects
		{
			ammoExplosionEffect="";
			class JMSSA_Fuel_Smoke
			{
				simulation="particles";
				type="ObjectDestructionSmoke2x";
				position="destructioneffect1";
				intensity=0.5;
				interval=1;
				lifeTime=60;
			};
			class JMSSA_Fuel_Fire: JMSSA_Fuel_Smoke
			{
				type="MediumDestructionFire";
				intensity=0.2;
			};
			class JMSSA_Fuel_Sparks: JMSSA_Fuel_Smoke
			{
				type="FireSparks";
				intensity=0.2;
			};
			class JMSSA_Fuel_Sounds: JMSSA_Fuel_Smoke
			{
				simulation="sound";
				type="Fire";
			};
			class SmokeBig1_2
			{
				intensity=0.15000001;
				interval=1;
				lifeTime=3.5;
				position="destructionEffect1";
				simulation="particles";
				type="ObjectDestructionSmoke1_2";
			};
		};
		class Exhausts
		{
			class Exhaust1
			{
				position="exhaust1_pos";
				direction="exhaust1_dir";
				effect="ExhaustsEffectAMV";
			};
			class Exhaust2
			{
				position="exhaust2_pos";
				direction="exhaust2_dir";
				effect="ExhaustsEffectAMV";
			};
		};
		class Reflectors
		{
			class LightCarHeadL01
			{
				color[]={1900,1800,1700};
				ambient[]={5,5,5};
				position="LightCarHeadL01";
				direction="LightCarHeadL01_end";
				hitpoint="Light_L";
				selection="Light_L";
				size=2;
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
		};
		aggregateReflectors[]=
		{
			
			{
				"LightCarHeadL01"
			}
		};
		class EventHandlers: EventHandlers
		{
			init="if (local (_this select 0)) then {[(_this select 0), """", [], false] call bis_fnc_initVehicle;};";
		};
		class AnimationSources: AnimationSources{};
		animationList[]={};
	};
	class FST_veh_landspeederA_base: FST_veh_landspeeder_base
	{
		author="JMax";
		model="\JMSLLTE_veh_gr_m\landspeeders\x34mk2";
		picture="\JMSLLTE_veh_gr\landspeeders\data\pic_x34a.paa";
		Icon="\JMSLLTE_veh_gr\landspeeders\data\ico_x34a.paa";
		_generalMacro="JMSLLTE_veh_landspeederA_base";
		transportSoldier=0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				body="mainTurret";
				gun="mainGun";
				memoryPointGun[]=
				{
					"usti hlavne"
				};
				selectionFireAnim="zasleh1";
				gunBeg="usti hlavne";
				gunEnd="konec hlavne";
				weapons[]=
				{
					"JMSLLTE_vg_mk2turret_gun"
				};
				magazines[]=
				{
					"JMSLLTE_100Rnd_mk2turret_mag",
					"JMSLLTE_100Rnd_mk2turret_mag",
					"JMSLLTE_100Rnd_mk2turret_mag",
					"JMSLLTE_100Rnd_mk2turret_mag",
					"JMSLLTE_100Rnd_mk2turret_mag"
				};
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP01",
					0.17782794,
					1,
					10
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP01",
					0.17782794,
					1,
					10
				};
				gunnerAction="JMSLLTE_gunner_x34";
				gunnerInAction="JMSLLTE_gunner_x34";
				gunnerGetInAction="GetInMid";
				gunnerGetOutAction="GetOutHigh";
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				forceHideGunner=0;
				viewGunnerInExternal=1;
				castGunnerShadow=1;
				stabilizedInAxes=3;
				memoryPointGunnerOptics="gunnerview";
				memoryPointGunnerOutOptics="gunnereye";
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_02_F";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex=2;
				turretInfoType="RscOptics_crows";
				usePip=0;
				minElev=-10;
				maxElev=10;
				initElev=0;
				minTurn=-130;
				maxTurn=100;
				initTurn=0;
				gunnerForceOptics=0;
				class ViewOptics: RCWSOptics
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
				class ViewGunner: ViewOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=15;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					minFov=0.25;
					maxFov=1.25;
					initFov=0.75;
					visionMode[]={};
				};
				class HitPoints: HitPoints
				{
					class HitTurret
					{
						armor=1;
						material=-1;
						armorComponent="hit_main_turret";
						name="hit_main_turret_point";
						visual="vez";
						passThrough=0;
						minimalHit=0.1;
						explosionShielding=0.30000001;
						radius=0.25;
						isTurret=1;
					};
				};
			};
			class CargoTurret_01: CargoTurret
			{
				gunnerAction="passenger_boat_4";
				gunnerInAction="passenger_boat_4";
				gunnerGetInAction="GetInMid";
				gunnerGetOutAction="GetOutHigh";
				memoryPointsGetInGunner="pos cargo LR";
				memoryPointsGetInGunnerDir="pos cargo LR dir";
				gunnerName="Passenger (left)";
				gunnerCompartments="Compartment2";
				memoryPointGunnerOptics="";
				LODTurnedIn=1;
				LODTurnedOut=1;
				proxyIndex=11;
				isPersonTurret=1;
				canHideGunner=0;
				allowLauncherIn=1;
				allowLauncherOut=1;
				ejectDeadGunner=1;
				class TurnIn
				{
					limitsArrayTop[]=
					{
						{33.820801,-93.961601},
						{40.890598,66.570503}
					};
					limitsArrayBottom[]=
					{
						{-9.4643002,-94.575302},
						{-8.3683004,-67.686699},
						{-9.7173004,43.637199},
						{-10.1082,78.916603}
					};
				};
				class dynamicViewLimits
				{
					CargoTurret_02[]={-85,65};
				};
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerAction="passenger_boat_3";
				gunnerInAction="passenger_boat_3";
				gunnerName="Passenger (right)";
				memoryPointsGetInGunner="pos cargo RR";
				memoryPointsGetInGunnerDir="pos cargo RR dir";
				gunnerCompartments="Compartment2";
				proxyIndex=12;
				class TurnIn
				{
					limitsArrayTop[]=
					{
						{37.1488,-71.900299},
						{36.4967,92.275703}
					};
					limitsArrayBottom[]=
					{
						{-22.183201,-70.0989},
						{-13.9068,-22.810699},
						{-7.1236,75.684898},
						{-7.8564,102.5826}
					};
				};
				class dynamicViewLimits
				{
					CargoTurret_01[]={-65,85};
				};
			};
		};
		class AnimationSources: AnimationSources
		{
			class muzzle_source_rot
			{
				source="ammorandom";
				weapon="JMSLLTE_vg_mk2turret_gun";
			};
			class muzzle_source
			{
				source="reload";
				weapon="JMSLLTE_vg_mk4es_s1_gun";
			};
			class ReloadAnim
			{
				source="reload";
				weapon="JMSLLTE_vg_mk2turret_gun";
			};
			class ReloadMagazine
			{
				source="reloadmagazine";
				weapon="JMSLLTE_vg_mk2turret_gun";
			};
			class Revolving
			{
				source="revolving";
				weapon="JMSLLTE_vg_mk2turret_gun";
			};
		};
	};
	class FST_X34_Reb: FST_veh_landspeeder_base
	{
		author="Gold";
		displayName="X-34";
		scope=2;
		scopeCurator=2;
		scopearsenal=2;
		side=2;
		faction="FST_Independent_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="";
		typicalCargo[]={};
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\X-34\Data\X34_Yellow_co.paa"
		};
	};
	class FST_X34_MK2_Reb: FST_veh_landspeederA_base
	{
		author="Gold";
		displayName="X-34 (MkII)";
		scope=2;
		scopeCurator=2;
		side=2;
		faction="FST_Independent_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="";
		typicalCargo[]={};
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\X-34\Data\X34_Yellow_co.paa"
		};
	};
};	