class CfgPatches
{
	class FST_JMSLLTE_veh_gr_hovertanks
	{
		units[]=
		{
			"FST_JMSLLTE_veh_S1firehawke_emp_F",
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Armor_F_Beta",
			"JMSLLTE_vehicles_gr"
		};
		author="JMax";
	};
};
class DefaultEventHandlers;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class RCWSOptics;
class Optics_Armored;
class Optics_Commander_02: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class Optics_Gunner_MBT_03: Optics_Armored
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
		class CommanderOptics;
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
					class CommanderOptics: CommanderOptics
					{
						class ViewGunner;
					};
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
		class EventHandlers;
	};
	class FST_JMSLLTE_veh_hovertanks_base: Tank_F
	{
		author="JMax";
		mapSize=6.5700002;
		model="\JMSLLTE_veh_gr_m\Hovertanks\S1_firehawke.p3d";
		picture="";
		Icon="";
		displayName="S1";
		_generalMacro="FST_JMSLLTE_veh_hovertanks_base";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Vehicles\Firehawk\data\FST_Firehawk_co.paa"
		};
		preferRoads=0;
		simulation="tankX";
		fuelCapacity=25;
		brakeIdleSpeed=1.78;
		maxSpeed=200;
		normalSpeedForwardCoef=0.75;
		slowSpeedForwardCoef=0.25;
		waterResistance=1;
		canFloat=1;
		waterLinearDampingCoefY=5;
		waterLinearDampingCoefX=2;
		waterAngularDampingCoef=5;
		waterResistanceCoef=0;
		waterLeakiness=1000;
		rudderForceCoef=2;
		rudderForceCoefAtMaxSpeed=1;
		waterEffectSpeed=1;
		engineEffectSpeed=5;
		waterFastEffectSpeed=10;
		enginePower=1230;
		maxOmega=345.57501;
		minOmega=146.608;
		redRpm=3300;
		idleRpm=1400;
		peakTorque=5000;
		torqueCurve[]=
		{
			{0.42424199,0.80000001},
			{0.54545498,0.94999999},
			{0.60606098,0.99000001},
			{0.63636398,1},
			{0.66666698,0.98000002},
			{0.72727299,0.93000001},
			{0.87878799,0.75999999},
			{1,0.60000002}
		};
		thrustDelay=0.5;
		engineMOI=15;
		dampingRateFullThrottle=1.3;
		dampingRateZeroThrottleClutchEngaged=6;
		dampingRateZeroThrottleClutchDisengaged=1;
		clutchStrength=40;
		latency=1.2;
		switchTime=0;
		changeGearType="rpmratio";
		changeGearOmegaRatios[]={1,0.42424199,0.45454499,0.33333299,0.98484802,0.42424199,0.98484802,0.60606098,0.98484802,0.57575798,1,0.54545498};
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-3.4000001,
				"N",
				0,
				"D1",
				4.4000001,
				"D2",
				3,
				"D3",
				1.75,
				"D4",
				1
			};
			transmissionRatios[]=
			{
				"High",
				13
			};
			AmphibiousRatios[]=
			{
				"R1",
				-3.4000001,
				"N",
				0,
				"D1",
				4.4000001,
				"D2",
				3,
				"D3",
				1.75,
				"D4",
				1
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
		};
		tankTurnForce=1100000;
		tankTurnForceAngMinSpd=0.75999999;
		tankTurnForceAngSpd=0.80000001;
		accelAidForceCoef=1.5;
		accelAidForceYOffset=-1;
		accelAidForceSpd=1.4;
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
				mass=200;
				MOI=16.260201;
				dampingRate=1100;
				dampingRateInAir=1100;
				dampingRateDestroyed=3000;
				maxDroop=0.18000001;
				maxCompression=0.15000001;
				sprungMass=4286;
				springStrength=350000;
				springDamperRate=20000;
				maxBrakeTorque=30000;
				latStiffX=1;
				latStiffY=35;
				longitudinalStiffnessPerUnitGravity=14000;
				frictionVsSlipGraph[]=
				{
					{0,0.75},
					{0.050000001,1.5},
					{0.5,0.89999998}
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
			class L5: L4
			{
				boneName="wheel_podkolol4";
				center="wheel_1_5_axis";
				boundary="wheel_1_5_bound";
			};
			class L6: L4
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
			class L8: L2
			{
				boneName="wheel_podkolol7";
				center="wheel_1_8_axis";
				boundary="wheel_1_8_bound";
			};
			class L9: L2
			{
				boneName="wheel_podkolol9";
				center="wheel_1_9_axis";
				boundary="wheel_1_9_bound";
				maxDroop=0.0099999998;
				maxCompression=0.0099999998;
			};
			class L1: L2
			{
				boneName="";
				center="wheel_1_1_axis";
				boundary="wheel_1_1_bound";
				maxDroop=0.0099999998;
				maxCompression=0.0099999998;
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
			class R8: R2
			{
				boneName="wheel_podkolop7";
				center="wheel_2_8_axis";
				boundary="wheel_2_8_bound";
			};
			class R9: R2
			{
				boneName="wheel_podkolop9";
				center="wheel_2_9_axis";
				boundary="wheel_2_9_bound";
				maxDroop=0.0099999998;
				maxCompression=0.0099999998;
			};
			class R1: R2
			{
				boneName="";
				center="wheel_2_1_axis";
				boundary="wheel_2_1_bound";
				maxDroop=0.0099999998;
				maxCompression=0.0099999998;
			};
		};
		numberPhysicalWheels=18;
		antiRollbarForceCoef=85;
		antiRollbarForceLimit=185;
		antiRollbarSpeedMin=0;
		antiRollbarSpeedMax=80;
		editorSubcategory="EdSubcat_Tanks";
		scope=0;
		maxFordingDepth=1.5;
		steerAheadSimul=0.5;
		steerAheadPlan=0.34999999;
		predictTurnPlan=2.8;
		predictTurnSimul=2.5999999;
		brakeDistance=15;
		precision=5;
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
		cargoAction[]=
		{
			"passenger_flatground_leanleft",
			"passenger_flatground_generic01",
			"passenger_flatground_generic02",
			"passenger_flatground_generic03",
			"passenger_flatground_generic04",
			"passenger_flatground_generic05"
		};
		wheelCircumference=1.25;
		tracksSpeed=-1;
		forceHideDriver=0;
		driverForceOptics=1;
		LODDriverOpticsIn=1202;
		driverOpticsModel="\a3\weapons_f\reticle\Optics_Driver_01_F";
		viewDriverInExternal=1;
		LODDriverTurnedOut=1200;
		driverInfoPanelCameraPos="driverview_old";
		driverAction="Driver_MBT_03_cannon_F_out";
		driverInAction="Driver_MBT_03_cannon_F_in";
		extCameraPosition[]={0,3,-9.75};
		driverLeftHandAnimName="drivewheel";
		driverRightHandAnimName="drivewheel";
		driverLeftLegAnimName="pedal_brake";
		driverRightLegAnimName="pedal_thrust";
		class ViewOptics: ViewOptics
		{
			visionMode[]=
			{
				"Normal"
			};
			initFov=0.25;
			minFov=0.13;
			maxFov=0.25;
		};
		class ViewPilot: ViewPilot
		{
			initAngleX=-5;
			initAngleY=0;
			initFov=0.89999998;
			maxAngleX=85;
			maxAngleY=150;
			maxFov=1.25;
			maxMoveX=0.075000003;
			maxMoveY=0.075000003;
			maxMoveZ=0.1;
			minAngleX=-65;
			minAngleY=-150;
			minFov=0.25;
			minMoveX=-0.075000003;
			minMoveY=-0.075000003;
			minMoveZ=-0.075000003;
			speedZoomMaxFOV=0;
			speedZoomMaxSpeed=1e+010;
		};
		viewDriverShadowAmb=0.5;
		viewDriverShadowDiff=0.050000001;
		armor=850;
		armorLights=0.1;
		armorStructural=8;
		damageResistance=0.0054700002;
		cost=2500000;
		crewVulnerable=0;
		crewExplosionProtection=100;
		epeImpulseDamageCoef=18;
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
			"JMSLLTE_veh_gr\Hovertanks\sounds\s1_engine_on.ogg",
			"db-1",
			1
		};
		soundEngineOnExt[]=
		{
			"JMSLLTE_veh_gr\Hovertanks\sounds\s1_engine_on.ogg",
			"db3",
			1,
			500
		};
		soundEngineOffInt[]=
		{
			"JMSLLTE_veh_gr\Hovertanks\sounds\s1_engine_on.ogg",
			"db-1",
			1
		};
		soundEngineOffExt[]=
		{
			"JMSLLTE_veh_gr\Hovertanks\sounds\s1_engine_on.ogg",
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
					"A3\Sounds_F_EPC\Truck_03\ext\truck03_engine_1",
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
					"JMSLLTE_veh_gr\Hovertanks\sounds\s1_engine.ogg",
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
					"JMSLLTE_veh_gr\Hovertanks\sounds\s1_engine.ogg",
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
					"JMSLLTE_veh_gr\Hovertanks\sounds\s1_engine.ogg",
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
					"JMSLLTE_veh_gr\Hovertanks\sounds\s1_engine.ogg",
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
					"JMSLLTE_veh_gr\Hovertanks\sounds\s1_engine.ogg",
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
					"JMSLLTE_veh_gr\Hovertanks\sounds\s1_engine.ogg",
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
					"A3\Sounds_F_EPC\Truck_03\int\truck03_engine_1",
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
					"JMSLLTE_veh_gr\Hovertanks\sounds\s1_engine.ogg",
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
					"JMSLLTE_veh_gr\Hovertanks\sounds\s1_engine.ogg",
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
					"JMSLLTE_veh_gr\Hovertanks\sounds\s1_engine.ogg",
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
					"JMSLLTE_veh_gr\Hovertanks\sounds\s1_engine.ogg",
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
					"JMSLLTE_veh_gr\Hovertanks\sounds\s1_engine.ogg",
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
					"JMSLLTE_veh_gr\Hovertanks\sounds\s1_engine.ogg",
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
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=1.6;
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
				armor=0.60000002;
				material=-1;
				armorComponent="hit_engine";
				name="hit_engine_point";
				visual="-";
				passThrough=0;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.30000001;
				class DestructionEffects
				{
					ammoExplosionEffect="";
					class JMSLLTE_Engine_Smoke
					{
						simulation="particles";
						type="SmallWreckSmoke";
						position="engine_smoke";
						intensity=0.5;
						interval=1;
						lifeTime=60;
					};
					class JMSLLTE_Engine_Fire: JMSLLTE_Engine_Smoke
					{
						type="SmallFireFPlace";
					};
					class JMSLLTE_Engine_Sparks: JMSLLTE_Engine_Smoke
					{
						type="FireSparks";
					};
					class JMSLLTE_Engine_Sounds: JMSLLTE_Engine_Smoke
					{
						simulation="sound";
						type="Fire";
					};
				};
			};
			class HitFuel: HitFuel
			{
				armor=2;
				material=-1;
				armorComponent="hit_fuel";
				name="hit_fuel_point";
				visual="-";
				passThrough=0;
				minimalHit=0.1;
				explosionShielding=0.60000002;
				radius=0.30000001;
			};
			class HitLTrack: HitLTrack
			{
				material=-1;
				armorComponent="hit_trackL";
				name="hit_trackL_point";
				visual="pas_L";
				radius=0.2;
				armor=0.89999998;
				minimalHit=0.15000001;
				explosionShielding=0.30000001;
				passThrough=0;
			};
			class HitRTrack: HitRTrack
			{
				material=-1;
				armorComponent="hit_trackR";
				name="hit_trackR_point";
				visual="pas_P";
				radius=0.2;
				armor=0.89999998;
				minimalHit=0.15000001;
				explosionShielding=0.30000001;
				passThrough=0;
			};
		};
		class EventHandlers: EventHandlers
		{
			init="if (local (_this select 0)) then {[(_this select 0), """", [], false] call bis_fnc_initVehicle;};";
		};
		class Exhausts
		{
			class Exhaust1
			{
				position="exhaust";
				direction="exhaust_dir";
				effect="ExhaustEffectTankSide";
			};
		};
		insideSoundCoef=0.89999998;
		threat[]={0.80000001,1,0.30000001};
		class Reflectors
		{
			class LightCarHeadL01
			{
				color[]={2000,1700,1500};
				ambient[]={10,6.5,4,5};
				position="LightCarHeadL01";
				direction="LightCarHeadL01_end";
				hitpoint="Light_L";
				selection="Light_L";
				size=1;
				innerAngle=1;
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
			class LightCarHeadR01: LightCarHeadL01
			{
				position="LightCarHeadR01";
				direction="LightCarHeadR01_end";
				hitpoint="Light_R";
				selection="Light_R";
			};
		};
		aggregateReflectors[]=
		{
			
			{
				"LightCarHeadL01",
				"LightCarHeadR01"
			}
		};
		soundLocked[]=
		{
			"",
			1,
			1
		};
		soundIncommingMissile[]=
		{
			"",
			1,
			1
		};
		smokeLauncherGrenadeCount=1;
		smokeLauncherVelocity=14;
		smokeLauncherOnTurret=1;
		smokeLauncherAngle=90;
		enableManualFire=0;
		class CargoTurret;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class MainGun: CommanderOptics
					{
						animationSourceBody="mainTurret_main";
						animationSourceGun="mainGun_main";
						animationSourceHatch="hatchGunner2";
						body="mainTurret_main";
						gun="mainGun_main";
						memoryPointGunnerOutOptics="gunnerview_main";
						memoryPointGunnerOptics="gunnerview_main";
						gunBeg="Usti hlavne";
						gunEnd="Konec hlavne";
						memoryPointGun="usti hlavne";
						selectionFireAnim="zasleh";
						gunnerName="Gunner";
						proxyIndex=2;
						minElev=-5;
						maxElev=70;
						initElev=0;
						minTurn=-360;
						maxTurn=360;
						initTurn=0;
						weapons[]=
						{
							"FST_AAT_Cannon"
						};
						magazines[]=
						{
							"FST_thermal_coil_LP_Blue",
							"FST_thermal_coil_LP_Blue",
							"FST_thermal_coil_LP_Blue",
							"FST_thermal_coil_LP_Blue",
							"FST_thermal_coil_LP_Blue"
						};
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
						outGunnerMayFire=0;
						inGunnerMayFire=1;
						gunnerAction="Commander_MBT_01_cannon_F_out";
						gunnerInAction="Commander_MBT_01_cannon_F_in";
						gunnerGetInAction="GetInLow";
						gunnerGetOutAction="GetOutLow";
						gunnerType="JMSLLTE_emp_army_tankSerg";
						discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
						discreteDistanceInitIndex=1;
						gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_m_F.p3d";
						gunnerOutOpticsModel="";
						gunnerOpticsEffect[]={};
						gunnerForceOptics=1;
						usePip=0;
						LODOpticsIn=0;
						isPersonTurret=1;
						personTurretAction="vehicle_turnout_2";
						animationSourceStickX="com_turret_control_x";
						animationSourceStickY="com_turret_control_y";
						gunnerRightHandAnimName="com_turret_control";
						minOutElev=-10;
						maxOutElev=25;
						initOutElev=0;
						minOutTurn=-95;
						maxOutTurn=95;
						initOutTurn=0;
						class ViewGunner: ViewGunner
						{
							initAngleX=-5;
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
							initFov=0.11;
							minFov=0.11;
							maxFov=0.11;
						};
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
								initFov="(24 / 120)";
								minFov="(24 / 120)";
								maxFov="(24 / 120)";
								visionMode[]=
								{
									"Normal",
									"NVG",
									"TI"
								};
								gunnerOpticsModel="\JMSLLTE_weapons\Scope\optics_gunner_s1_m_f.p3d";
								opticsPPEffects[]={};
							};
							class Narrow: Wide
							{
								initFov="(120 * 0.05625 / 120)";
								minFov="(120 * 0.05625 / 120)";
								maxFov="(120 * 0.05625 / 120)";
								gunnerOpticsModel="\JMSLLTE_weapons\Scope\optics_gunner_s1_n_f.p3d";
							};
						};
						viewGunnerShadowAmb=0.5;
						viewGunnerShadowDiff=0.050000001;
						turretInfoType="RscOptics_JMSLLTE_S1_gunner";
						showCrewAim=1;
						startEngine=1;
						gunnerHasFlares=1;
						stabilizedInAxes=3;
						maxHorizontalRotSpeed=1.4;
						maxVerticalRotSpeed=1.4;
						viewGunnerInExternal=0;
						class HitPoints
						{
							class HitTurret
							{
								armor=0.80000001;
								material=-1;
								armorComponent="hit_main_turret";
								name="hit_main_turret_point";
								visual="vez";
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
								visual="zbran";
								passThrough=0;
								minimalHit=0.1;
								explosionShielding=0.40000001;
								radius=0.2;
								isGun=1;
							};
						};
					};
					class CommanderOptics: CommanderOptics
					{
						memoryPointGunnerOutOptics="commanderview";
						memoryPointGunnerOptics="commanderview";
						gunBeg="Usti hlavne2";
						gunEnd="Konec hlavne2";
						memoryPointGun="usti hlavne2";
						selectionFireAnim="zasleh2";
						minElev=-10;
						maxElev=10;
						initElev=0;
						minTurn=-360;
						maxTurn=360;
						initTurn=0;
						weapons[]=
						{
							"SmokeLauncher"
						};
						magazines[]=
						{
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
						outGunnerMayFire=0;
						inGunnerMayFire=1;
						gunnerAction="Commander_MBT_01_cannon_F_out";
						gunnerInAction="Commander_MBT_01_cannon_F_in";
						gunnerGetInAction="GetInLow";
						gunnerGetOutAction="GetOutLow";
						discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
						discreteDistanceInitIndex=2;
						gunnerOpticsModel="\a3\weapons_f\reticle\Optics_Driver_01_F";
						gunnerOutOpticsModel="";
						gunnerOpticsEffect[]={};
						gunnerForceOptics=1;
						usePip=0;
						LODOpticsIn=0;
						isPersonTurret=1;
						personTurretAction="vehicle_turnout_2";
						animationSourceStickX="com_turret_control_x";
						animationSourceStickY="com_turret_control_y";
						gunnerRightHandAnimName="com_turret_control";
						class dynamicViewLimits
						{
							MainTurret[]={-135,75};
						};
						minOutElev=-10;
						maxOutElev=25;
						initOutElev=0;
						minOutTurn=-95;
						maxOutTurn=95;
						initOutTurn=0;
						class ViewGunner: ViewGunner
						{
							initAngleX=-5;
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
							gunnerOpticsModel="\a3\weapons_f\reticle\Optics_Driver_01_F";
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
								"Normal"
							};
							thermalMode[]={2,3};
						};
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
								initFov=0.133;
								minFov=0.133;
								maxFov=0.133;
								visionMode[]=
								{
									"Normal"
								};
								gunnerOpticsModel="\a3\weapons_f\reticle\Optics_Driver_01_F";
								opticsPPEffects[]=
								{
									"TankGunnerOptics2",
									"OpticsBlur1",
									"OpticsCHAbera1"
								};
								OpticsFlare=1;
							};
							class Narrow: Wide
							{
								initFov=0.40000001;
								minFov=0.40000001;
								maxFov=0.40000001;
								opticsDisablePeripherialVision=1;
							};
						};
						viewGunnerShadowAmb=0.5;
						viewGunnerShadowDiff=0.050000001;
						turretInfoType="RscOptics_JMSLLTE_S1_gunner";
						showCrewAim=1;
						startEngine=0;
						gunnerHasFlares=1;
						stabilizedInAxes=3;
						maxHorizontalRotSpeed=1.8;
						maxVerticalRotSpeed=1.8;
						viewGunnerInExternal=1;
						class HitPoints
						{
							class HitComTurret
							{
								armor=0.1;
								material=-1;
								armorComponent="hit_com_turret";
								name="hit_com_turret_point";
								visual="vezVelitele";
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
								visual="zbranVelitele";
								passThrough=0;
								minimalHit=0.1;
								explosionShielding=1;
								radius=0.15000001;
								isGun=1;
							};
						};
					};
				};
				gunBeg="usti hlavne1";
				gunEnd="konec hlavne1";
				gunnerInAction="Gunner_MBT_03_cannon_F_in";
				gunnerAction="Gunner_MBT_03_cannon_F_out";
				gunnerGetInAction="GetInLow";
				gunnerGetOutAction="GetOutLow";
				gunnerType="JMSLLTE_emp_army_tankSerg";
				weapons[]=
				{
					"FST_EWEB_RemoteTurret"
				};
				magazines[]=
				{
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue"
				};
				soundServo[]=
				{
					"",
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
				memoryPointGun="usti hlavne1";
				selectionFireAnim="zasleh1";
				gunnerName="Gunner (blaster)";
				forceHideGunner=1;
				usePip=0;
				LODOpticsIn=0;
				stabilizedInAxes=0;
				viewGunnerShadowAmb=0.5;
				viewGunnerShadowDiff=0.050000001;
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600};
				discreteDistanceInitIndex=2;
				memoryPointGunnerOptics="gunnerview";
				minElev=-3;
				maxElev=2;
				initElev=0;
				minTurn=-30;
				maxTurn=30;
				initTurn=0;
				gunnerOpticsModel="\A3\weapons_f\reticle\optics_gunner_mtb_02_f";
				gunnerOutOpticsModel="";
				gunnerOutOpticsEffect[]={};
				gunnerOpticsEffect[]={};
				gunnerForceOptics=1;
				startEngine=1;
				inGunnerMayFire=1;
				viewGunnerInExternal=0;
				isPersonTurret=0;
				personTurretAction="vehicle_turnout_1";
				minOutElev=-3;
				maxOutElev=2;
				initOutElev=0;
				minOutTurn=-135;
				maxOutTurn=90;
				initOutTurn=0;
				maxHorizontalRotSpeed=0.80000001;
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
						initFov="(24 / 120)";
						minFov="(24 / 120)";
						maxFov="(24 / 120)";
						visionMode[]=
						{
							"Normal",
							"NVG",
							"TI"
						};
						gunnerOpticsModel="\JMSLLTE_weapons\Scope\optics_gunner_s1_m_f.p3d";
						opticsPPEffects[]={};
					};
					class Narrow: Wide
					{
						initFov="(120 * 0.05625 / 120)";
						minFov="(120 * 0.05625 / 120)";
						maxFov="(120 * 0.05625 / 120)";
						gunnerOpticsModel="\JMSLLTE_weapons\Scope\optics_gunner_s1_n_f.p3d";
					};
				};
				class ViewOptics: ViewOptics
				{
					initFov=0.11;
					minFov=0.11;
					maxFov=0.11;
				};
				turretInfoType="RscOptics_JMSLLTE_S1_gunner";
				showCrewAim=2;
				class TurnOut
				{
					limitsArrayTop[]=
					{
						{20.1126,-107.5349},
						{19.8932,99.317703}
					};
					limitsArrayBottom[]=
					{
						{-9.1273003,-108.1836},
						{-7.1046,-44.255001},
						{-9.1674995,31.497801},
						{-9.0504999,102.8447}
					};
				};
				class HitPoints
				{
					class HitTurret
					{
						armor=0.80000001;
						material=-1;
						armorComponent="hit_turret";
						name="hit_turret_point";
						visual="vez";
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
						armorComponent="hit_gun";
						name="hit_gun_point";
						visual="zbran";
						passThrough=0;
						minimalHit=0.1;
						explosionShielding=0.40000001;
						radius=0.2;
						isGun=1;
					};
				};
			};
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"JMSLLTE_veh_gr\Hovertanks\data\firehawke.rvmat",
				"JMSLLTE_veh_gr\Hovertanks\data\firehawke_damage.rvmat",
				"JMSLLTE_veh_gr\destruct.rvmat"
			};
		};
		class AnimationSources: AnimationSources
		{
			class recoil_source
			{
				source="reload";
				weapon="JMSLLTE_vg_mk4es_s1_gun";
			};
			class recoil_source_main
			{
				source="reload";
				weapon="JMSLLTE_vg_HMS3_S1_cannon";
			};
			class muzzle_source
			{
				source="reload";
				weapon="JMSLLTE_vg_mk4es_s1_gun";
			};
			class HideBagsSide
			{
				displayName="Hide side bags";
				author="JMax";
				source="user";
				animPeriod=1;
				initPhase=1;
				mass=-15;
			};
			class HideBagsTurret
			{
				displayName="Hide turret bags";
				author="JMax";
				source="user";
				animPeriod=1;
				initPhase=1;
				mass=-5;
			};
			class HideCrates
			{
				displayName="Hide crates";
				author="JMax";
				source="user";
				animPeriod=1;
				initPhase=1;
				mass=-20;
			};
		};
		class Library
		{
			libTextDesc="";
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
	class FST_JMSLLTE_veh_S1firehawke_emp_F: FST_JMSLLTE_veh_hovertanks_base
	{
		author="Daara";
		scope=2;
		scopeCurator=2;
		_generalMacro="FST_JMSLLTE_veh_S1firehawke_emp_F";
		displayName="[41st] S-1 Firehawk Repulsortank";
		picture="\JMSLLTE_veh_gr\Hovertanks\data\pic_s1.paa";
		Icon="\JMSLLTE_veh_gr\Hovertanks\data\ico_s1.paa";
		side=1;
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="JMSLLTE_emp_army_tank";
		animationList[]=
		{
			"HideBagsSide",
			0.30000001,
			"HideBagsTurret",
			0.5,
			"HideCrates",
			0.15000001
		};
	};
};
