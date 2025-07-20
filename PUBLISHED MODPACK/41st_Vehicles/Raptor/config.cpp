class CfgPatches
{
	class FST_vehicles_agt
	{
		author="Legion Studios";
		authors[]=
		{
			"Cannon",
			"DartRuffian"
		};
		name="Legion Studios: Core - Vehicles (AGT 'Raptor')";
		addonRootClass="ls_vehicles";
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"ls_vehicles"
		};
		units[]=
		{
			"FST_vehicle_agtRaptor_base",
			"FST_vehicle_agtRaptor",
			"FST_vehicle_agtRaptor_Scorch"
		};
		weapons[]={};
		version=2;
		versionStr="2.0.2.0";
		versionAr[]={2,0,2,0};
	};
};
class RCWSOptics;
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;
class CfgVehicles
{
	class Car_F;
	class UGV_01_base_F: Car_F
	{
		class Turrets;
		class HitPoints;
	};
	class UGV_01_rcws_base_F: UGV_01_base_F
	{
		class AnimationSources;
		class Turrets: Turrets
		{
			class MainTurret;
		};
		class HitPoints: HitPoints
		{
			class HitFuel;
			class HitBody;
			class HitEngine;
		};
		class Components;
	};
	class FST_vehicle_agtRaptor_base: UGV_01_rcws_base_F
	{
		model="\ls\core\addons\vehicles_agt\ls_vehicle_agtRaptor.p3d";
		editorpreview="\ls\core\addons\vehicles_agt\data\ui\editorPreviews\ls_vehicle_agtRaptor.jpg";
		icon="\ls\core\addons\vehicles_agt\data\ui\agt_icon_ca.paa";
		picture="\ls\core\addons\vehicles_agt\data\ui\agt_icon_side_ca.paa";
		editorSubcategory="EdSubcat_drones";
		crew="O_UAV_AI";
		displayName="AGT_BASE";
		weapons[]=
		{
			"CarHorn"
		};
		magazines[]={};
		memoryPointGun[]={};
		uavCameraDriverPos="PiP0_pos";
		uavCameraDriverDir="PiP0_dir";
		class HitPoints: HitPoints
		{
			class HitRFWheel
			{
				armor=1;
				explosionShielding=4;
				armorComponent="hit_fr_wheel";
				material=-1;
				passThrough=0.30000001;
				name="wheel_fr_point";
				visual="wheel_fr_destruct";
			};
			class HitLFWheel: HitRFWheel
			{
				armorComponent="hit_fl_wheel";
				name="wheel_fl_point";
				visual="wheel_fl_destruct";
			};
			class HitLF2Wheel: HitRFWheel
			{
				armorComponent="hit_bl_wheel";
				name="wheel_bl_point";
				visual="wheel_bl_destruct";
			};
			class HitRF2Wheel: HitRFWheel
			{
				armorComponent="hit_br_wheel";
				name="wheel_br_point";
				visual="wheel_br_destruct";
			};
			class HitEngine: HitEngine
			{
				visual="engine_destruct";
				name="engine_point";
				armorComponent="hit_engine";
				armor=0.5;
				material=-1;
				passThrough=0.30000001;
			};
			class HitFuel: HitFuel
			{
				visual="fuel_destruct";
			};
			class HitBody: HitBody
			{
				name="karoserie";
				visual="zbytek";
				armor=0.5;
				material=-1;
				passThrough=0.30000001;
			};
		};
		class Components: Components
		{
			class TransportPylonsComponent
			{
				uiPicture="\ls\core\addons\vehicles_agt\data\ui\agt_icon_ca.paa";
				class Pylons
				{
					class PylonLeft
					{
						attachment="";
						priority=5;
						turret[]={0};
						UIposition[]={0.15000001,0.2};
						hardpoints[]=
						{
							"SCALPEL_1RND",
							"B_ASRAAM",
							"DAR",
							"DAGR",
							"B_AMRAAM_D_DUAL_RAIL",
							"B_SDB_QUAD_RAIL",
							"B_GBU12",
							"B_AGM65_RAIL",
							"BRU_32_EJECTOR",
							"B_A143_BUZZARD_CENTER_PYLON"
						};
					};
					class PylonRight: PylonLeft
					{
						UIposition[]={0.55000001,0.2};
					};
				};
				class Presets
				{
					class Empty
					{
						displayName="Empty";
						attachment[]={};
					};
					class Test
					{
						displayname="Tester";
						attachment[]=
						{
							"PylonRack_12Rnd_PG_missiles",
							"PylonRack_12Rnd_missiles"
						};
					};
				};
			};
		};
		hiddenSelections[]=
		{
			"Camo1",
			"Camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\vehicles_agt\data\camo1_co.paa",
			"\ls\core\addons\vehicles_agt\data\camo2_co.paa"
		};
		class AnimationSources: AnimationSources
		{
			class HitFRWheel
			{
				hitPoint="HitRFWheel";
				raw=1;
				source="Hit";
			};
			class HitEngine
			{
				hitPoint="HitEngine";
				raw=1;
				source="Hit";
			};
			class HitFLWheel: HitFRWheel
			{
				hitPoint="HitLFWheel";
			};
			class HitBRWheel: HitFRWheel
			{
				hitPoint="HitRF2Wheel";
			};
			class HitBLWheel: HitFRWheel
			{
				hitPoint="HitLF2Wheel";
			};
		};
		class TransportItems
		{
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				isCopilot=0;
				dontCreateAI=0;
				body="mainTurret";
				gun="mainGun";
				memoryPointGunnerOptics="PiP1_pos";
				memoryPointGun="machinegun";
				gunnerForceOptics=1;
				gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_F.p3d";
				turretInfoType="RscOptics_UGV_gunner";
				weapons[]=
				{
					"FST_AAT_Side"
				};
				magazines[]=
				{
					"FST_500Rnd_127x99_mag_red",
					"FST_500Rnd_127x99_mag_red"
				};
				maxHorizontalRotSpeed=1.8;
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\soft\UGV_01\Servo_UGV_gunner.wss",
					0.31622776,
					1,
					30
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\soft\UGV_01\Servo_UGV_gunner_vertical.wss",
					0.31622776,
					1,
					30
				};
				minElev=-10;
				maxElev=60;
				forceHideGunner=1;
				outGunnerMayFire=1;
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex=2;
				stabilizedInAxes=3;
				class HitPoints
				{
					class HitTurret
					{
						armor=0.5;
						material=-1;
						armorComponent="hit_main_turret";
						name="hit_main_turret_point";
						visual="OtocVez";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.40000001;
						radius=0.25;
						isTurret=1;
					};
					class HitGun
					{
						armor=0.5;
						material=-1;
						armorComponent="hit_main_gun";
						name="hit_main_gun_point";
						visual="OtocHlaven";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.40000001;
						radius=0.2;
						isGun=1;
					};
				};
				class ViewOptics: RCWSOptics
				{
					visionMode[]=
					{
						"Normal",
						"TI"
					};
					initFov=0.46669999;
					maxFov=0.46669999;
					minFov=0.035;
					directionStabilized=1;
				};
				class Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
					{
						class components
						{
							class EmptyDisplay
							{
								componentType="EmptyDisplayComponent";
							};
							class MinimapDisplay
							{
								componentType="MinimapDisplayComponent";
								resource="RscCustomInfoMiniMap";
							};
							class UAVDisplay
							{
								componentType="UAVFeedDisplayComponent";
							};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
					{
						class components
						{
							class EmptyDisplay
							{
								componentType="EmptyDisplayComponent";
							};
							class MinimapDisplay
							{
								componentType="MinimapDisplayComponent";
								resource="RscCustomInfoMiniMap";
							};
							class UAVDisplay
							{
								componentType="UAVFeedDisplayComponent";
							};
						};
					};
				};
			};
		};
		attenuationEffectType="CarAttenuation";
		soundGetIn[]=
		{
			"A3\Sounds_F\vehicles\soft\Hatchback_01\Hatchback_01_door.wss",
			"db-5",
			1
		};
		soundGetOut[]=
		{
			"A3\Sounds_F\vehicles\soft\Hatchback_01\Hatchback_01_door.wss",
			"db-5",
			1,
			40
		};
		soundDammage[]=
		{
			"",
			"db-5",
			1
		};
		soundEngineOnInt[]=
		{
			"\ls\core\addons\sounds\vehicles\barc\start.wss",
			"db-8",
			1
		};
		soundEngineOnExt[]=
		{
			"\ls\core\addons\sounds\vehicles\barc\start.wss",
			"db-7",
			1,
			200
		};
		soundEngineOffInt[]=
		{
			"\ls\core\addons\sounds\vehicles\speeder\idle.wss",
			"db-8",
			1
		};
		soundEngineOffExt[]=
		{
			"\ls\core\addons\sounds\vehicles\speeder\idle.wss",
			"db-7",
			1,
			200
		};
		soundGear[]=
		{
			"\ls\core\addons\sounds\vehicles\barc\gear.wss",
			"db-8",
			1
		};
		buildCrash0[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",
			"db0",
			1,
			200
		};
		buildCrash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",
			"db0",
			1,
			200
		};
		buildCrash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",
			"db0",
			1,
			200
		};
		buildCrash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",
			"db0",
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
			"db0",
			1,
			200
		};
		WoodCrash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1",
			"db0",
			1,
			200
		};
		WoodCrash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1",
			"db0",
			1,
			200
		};
		WoodCrash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1",
			"db0",
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
			"db0",
			1,
			200
		};
		armorCrash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",
			"db0",
			1,
			200
		};
		armorCrash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",
			"db0",
			1,
			200
		};
		armorCrash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",
			"db0",
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
					"\ls\core\addons\sounds\vehicles\105kLancer\idle.wss",
					"db-13",
					1,
					150
				};
				frequency="0.9 + ((rpm/6900) factor[(400/6900),(1150/6900)]) * 0.2";
				volume="engineOn * camPos * (((rpm/6900) factor[(400/6900),(700/6900)]) * ((rpm/6900) factor[(1100/6900),(900/6900)]))";
			};
			class Engine
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\engine_1.wss",
					"db-11",
					1,
					200
				};
				frequency="0.8 + ((rpm/6900) factor[(900/6900),(2100/6900)]) * 0.2";
				volume="engineOn * camPos * (((rpm/6900) factor[(870/6900),(1100/6900)]) * ((rpm/6900) factor[(2100/6900),(1300/6900)]))";
			};
			class Engine1_ext
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\engine_2.wss",
					"db-9",
					1,
					240
				};
				frequency="0.8 + ((rpm/6900) factor[(1300/6900),(3100/6900)]) * 0.2";
				volume="engineOn * camPos * (((rpm/6900) factor[(1250/6900),(2050/6900)]) * ((rpm/6900) factor[(3100/6900),(2300/6900)]))";
			};
			class Engine2_ext
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\engine_3.wss",
					"db-8",
					1,
					280
				};
				frequency="0.8 + ((rpm/6900) factor[(2200/6900),(4100/6900)]) * 0.2";
				volume="engineOn * camPos * (((rpm/6900) factor[(2250/6900),(3050/6900)]) * ((rpm/6900) factor[(4100/6900),(3300/6900)]))";
			};
			class Engine3_ext
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\engine_4.wss",
					"db-7",
					1,
					320
				};
				frequency="0.8 + ((rpm/6900) factor[(3300/6900),(4900/6900)]) * 0.2";
				volume="engineOn * camPos * (((rpm/6900) factor[(3250/6900),(4050/6900)]) * ((rpm/6900) factor[(4870/6900),(4200/6900)]))";
			};
			class Engine4_ext
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\engine_5.wss",
					"db-6",
					1,
					360
				};
				frequency="0.8 + ((rpm/6900) factor[(4200/6900),(6200/6900)]) * 0.2";
				volume="engineOn * camPos * (((rpm/6900) factor[(4150/6900),(4800/6900)]) * ((rpm/6900) factor[(6150/6900),(5150/6900)]))";
			};
			class Engine5_ext
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\engine_5.wss",
					"db-5",
					1,
					420
				};
				frequency="0.95 + ((rpm/6900) factor[(5100/6900),(6900/6900)])*0.15";
				volume="engineOn * camPos * ((rpm/6900) factor[(5100/6900),(6100/6900)])";
			};
			class IdleThrust
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\idle_thrust.wss",
					"db-6",
					1,
					200
				};
				frequency="0.9 + ((rpm/6900) factor[(400/6900),(1150/6900)])*0.2";
				volume="engineOn * camPos*(0.4 + (0.6 * (thrust factor[0.1,1]))) * (((rpm/6900) factor[(400/6900),(700/6900)]) * ((rpm/6900) factor[(1100/6900),(900/6900)]))";
			};
			class EngineThrust
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\thrust_1.wss",
					"db-5",
					1,
					250
				};
				frequency="0.8 + ((rpm/6900) factor[(900/6900),(2100/6900)])*0.2";
				volume="engineOn * camPos*(0.4 + (0.6 * (thrust factor[0.1,1]))) * (((rpm/6900) factor[(870/6900),(1100/6900)]) * ((rpm/6900) factor[(2100/6900),(1300/6900)]))";
			};
			class Engine1_Thrust_ext
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\thrust_2.wss",
					"db-4",
					1,
					280
				};
				frequency="0.8 + ((rpm/6900) factor[(1300/6900),(3100/6900)])*0.2";
				volume="engineOn * camPos*(0.4 + (0.6 * (thrust factor[0.1,1]))) * (((rpm/6900) factor[(1250/6900),(2050/6900)]) * ((rpm/6900) factor[(3100/6900),(2300/6900)]))";
			};
			class Engine2_Thrust_ext
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\thrust_3.wss",
					"db-3",
					1,
					320
				};
				frequency="0.8 + ((rpm/6900) factor[(2200/6900),(4100/6900)]) * 0.2";
				volume="engineOn * camPos * (0.4 + (0.6 * (thrust factor[0.1,1]))) * (((rpm/6900) factor[(2250/6900),(3050/6900)]) * ((rpm/6900) factor[(4100/6900),(3300/6900)]))";
			};
			class Engine3_Thrust_ext
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\thrust_4.wss",
					"db-2",
					1,
					360
				};
				frequency="0.8 + ((rpm/6900) factor[(3300/6900),(4900/6900)]) * 0.2";
				volume="engineOn * camPos * (0.4 + (0.6 * (thrust factor[0.1,1]))) * (((rpm/6900) factor[(3250/6900),(4050/6900)]) * ((rpm/6900) factor[(4870/6900),(4200/6900)]))";
			};
			class Engine4_Thrust_ext
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\thrust_5.wss",
					"db0",
					1,
					400
				};
				frequency="0.8 + ((rpm/6900) factor[(4200/6900),(6200/6900)])*0.3";
				volume="engineOn * camPos*(0.4 + (0.6 * (thrust factor[0.1,1]))) * (((rpm/6900) factor[(4150/6900),(4800/6900)]) * ((rpm/6900) factor[(6150/6900),(5150/6900)]))";
			};
			class Engine5_Thrust_ext
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\thrust_5.wss",
					"db-2",
					1,
					450
				};
				frequency="0.9 + ((rpm/6900) factor[(5100/6900),(6900/6900)]) * 0.2";
				volume="engineOn * camPos*(0.4 + (0.6 * (thrust factor[0.1,1]))) * ((rpm/6900) factor[(5100/6900),(6100/6900)])";
			};
			class Idle_int
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\idle.wss",
					"db-15",
					1
				};
				frequency="0.9 + ((rpm/6900) factor[(400/6900),(1150/6900)]) * 0.2";
				volume="engineOn * (1 - camPos) * (((rpm/6900) factor[(400/6900),(700/6900)]) * ((rpm/6900) factor[(1100/6900),(900/6900)]))";
			};
			class Engine_int
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\engine_1.wss",
					"db-14",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(900/6900),(2100/6900)]) * 0.2";
				volume="engineOn * (1 - camPos) * (((rpm/6900) factor[(870/6900),(1100/6900)]) * ((rpm/6900) factor[(2100/6900),(1300/6900)]))";
			};
			class Engine1_int
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\engine_2.wss",
					"db-12",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(1300/6900),(3100/6900)]) * 0.2";
				volume="engineOn * (1 - camPos) * (((rpm/6900) factor[(1250/6900),(2050/6900)]) * ((rpm/6900) factor[(3100/6900),(2300/6900)]))";
			};
			class Engine2_int
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\engine_3.wss",
					"db-11",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(2200/6900),(4100/6900)]) * 0.2";
				volume="engineOn * (1 - camPos) * (((rpm/6900) factor[(2250/6900),(3050/6900)]) * ((rpm/6900) factor[(4100/6900),(3300/6900)]))";
			};
			class Engine3_int
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\engine_4.wss",
					"db-10",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(3300/6900),(4900/6900)]) * 0.2";
				volume="engineOn*(1 - camPos) * (((rpm/6900) factor[(3250/6900),(4050/6900)]) * ((rpm/6900) factor[(4870/6900),(4200/6900)]))";
			};
			class Engine4_int
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\engine_5.wss",
					"db-9",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(4200/6900),(6200/6900)]) * 0.2";
				volume="engineOn*(1 - camPos) * (((rpm/6900) factor[(4150/6900),(4800/6900)]) * ((rpm/6900) factor[(6150/6900),(5150/6900)]))";
			};
			class Engine5_int
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\engine_5.wss",
					"db-6",
					1
				};
				frequency="0.95 + ((rpm/6900) factor[(5100/6900),(6900/6900)]) * 0.15";
				volume="engineOn*(1 - camPos) * ((rpm/6900) factor[(5100/6900),(6100/6900)])";
			};
			class IdleThrust_int
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\idle_thrust.wss",
					"db-10",
					1
				};
				frequency="0.9 + ((rpm/6900) factor[(400/6900),(1150/6900)]) * 0.2";
				volume="engineOn * (1 - camPos) * (0.4 + (0.6 * (thrust factor[0.1,1]))) * (((rpm/6900) factor[(400/6900),(700/6900)]) * ((rpm/6900) factor[(1100/6900),(900/6900)]))";
			};
			class EngineThrust_int
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\thrust_1.wss",
					"db-9",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(900/6900),(2100/6900)]) * 0.2";
				volume="engineOn * (1 - camPos) * (0.4 + (0.6 * (thrust factor[0.1,1]))) * (((rpm/6900) factor[(870/6900),(1100/6900)]) * ((rpm/6900) factor[(2100/6900),(1300/6900)]))";
			};
			class Engine1_Thrust_int
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\thrust_2.wss",
					"db-8",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(1300/6900),(3100/6900)])*0.2";
				volume="engineOn * (1 - camPos) * (0.4 + (0.6 * (thrust factor[0.1,1]))) * (((rpm/6900) factor[(1250/6900),(2050/6900)]) * ((rpm/6900) factor[(3100/6900),(2300/6900)]))";
			};
			class Engine2_Thrust_int
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\thrust_3.wss",
					"db-7",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(2200/6900),(4100/6900)]) * 0.2";
				volume="engineOn * (1 - camPos) * (0.4 + (0.6 * (thrust factor[0.1,1]))) * (((rpm/6900) factor[(2250/6900),(3050/6900)]) * ((rpm/6900) factor[(4100/6900),(3300/6900)]))";
			};
			class Engine3_Thrust_int
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\thrust_4.wss",
					"db-6",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(3300/6900),(4900/6900)]) * 0.2";
				volume="engineOn * (1 - camPos) * (0.4 + (0.6 * (thrust factor[0.1,1]))) * (((rpm/6900) factor[(3250/6900),(4050/6900)]) * ((rpm/6900) factor[(4870/6900),(4200/6900)]))";
			};
			class Engine4_Thrust_int
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\thrust_5.wss",
					"db-5",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(4200/6900),(6200/6900)]) * 0.3";
				volume="engineOn * (1 - camPos) * (0.4 + (0.6 * (thrust factor[0.1,1]))) * (((rpm/6900) factor[(4150/6900),(4800/6900)]) * ((rpm/6900) factor[(6150/6900),(5150/6900)]))";
			};
			class Engine5_Thrust_int
			{
				sound[]=
				{
					"\ls\core\addons\sounds\vehicles\105kLancer\thrust_5.wss",
					"db-4",
					1
				};
				frequency="0.9 + ((rpm/6900) factor[(5100/6900),(6900/6900)]) * 0.2";
				volume="engineOn * (1 - camPos) * (0.4 + (0.6 * (thrust factor[0.1,1]))) * ((rpm/6900) factor[(5100/6900),(6100/6900)])";
			};
			class Movement
			{
				sound="soundEnviron";
				frequency="1";
				volume="0";
			};
			class TiresRockOut
			{
				sound[]=
				{
					"",
					"db-6",
					1,
					60
				};
				frequency="1";
				volume="camPos*rock*(speed factor[2, 20])";
			};
			class TiresSandOut
			{
				sound[]=
				{
					"",
					"db-6",
					1,
					60
				};
				frequency="1";
				volume="camPos*sand*(speed factor[2, 20])";
			};
			class TiresGrassOut
			{
				sound[]=
				{
					"",
					"db-6",
					1,
					60
				};
				frequency="1";
				volume="camPos*grass*(speed factor[2, 20])";
			};
			class TiresMudOut
			{
				sound[]=
				{
					"",
					"db-6",
					1,
					60
				};
				frequency="1";
				volume="camPos*mud*(speed factor[2, 20])";
			};
			class TiresGravelOut
			{
				sound[]=
				{
					"",
					"db-6",
					1,
					60
				};
				frequency="1";
				volume="camPos*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltOut
			{
				sound[]=
				{
					"",
					"db-6",
					1,
					60
				};
				frequency="1";
				volume="camPos*asphalt*(speed factor[2, 20])";
			};
			class NoiseOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\noise_ext_car_3.wss",
					"db-8",
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
					"db-6",
					1
				};
				frequency="1";
				volume="(1 - camPos)*rock*(speed factor[2, 20])";
			};
			class TiresSandIn
			{
				sound[]=
				{
					"",
					"db-6",
					1
				};
				frequency="1";
				volume="(1 - camPos)*sand*(speed factor[2, 20])";
			};
			class TiresGrassIn
			{
				sound[]=
				{
					"",
					"db-6",
					1
				};
				frequency="1";
				volume="(1 - camPos)*grass*(speed factor[2, 20])";
			};
			class TiresMudIn
			{
				sound[]=
				{
					"",
					"db-6",
					1
				};
				frequency="1";
				volume="(1 - camPos)*mud*(speed factor[2, 20])";
			};
			class TiresGravelIn
			{
				sound[]=
				{
					"",
					"db-6",
					1
				};
				frequency="1";
				volume="(1 - camPos)*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltIn
			{
				sound[]=
				{
					"",
					"db-6",
					1
				};
				frequency="1";
				volume="(1 - camPos)*asphalt*(speed factor[2, 20])";
			};
			class NoiseIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\noise_int_car_3.wss",
					"db-12",
					1
				};
				frequency="1";
				volume="(damper0 max 0.1)*(speed factor[0, 8])*(1 - camPos)";
			};
			class breaking_ext_road
			{
				sound[]=
				{
					"",
					"db-3",
					1,
					80
				};
				frequency=1;
				volume="engineOn * camPos * asphalt * (longSlipDrive factor[-0.1, -0.4]) * (speed factor[2, 15])";
			};
			class acceleration_ext_road
			{
				sound[]=
				{
					"",
					"db-3",
					1,
					80
				};
				frequency=1;
				volume="engineOn * camPos * asphalt * (longSlipDrive factor[0.1, 0.4]) * (speed factor[15, 2])";
			};
			class turn_left_ext_road
			{
				sound[]=
				{
					"",
					"db-3",
					1,
					80
				};
				frequency=1;
				volume="engineOn * camPos * asphalt * (latSlipDrive factor[0.1, 0.4]) * (speed factor[2, 15])";
			};
			class turn_right_ext_road
			{
				sound[]=
				{
					"",
					"db-3",
					1,
					80
				};
				frequency=1;
				volume="engineOn * camPos * asphalt * (latSlipDrive factor[-0.1, -0.4]) * (speed factor[2, 15])";
			};
			class breaking_ext_dirt
			{
				sound[]=
				{
					"",
					"db-3",
					1,
					60
				};
				frequency=1;
				volume="engineOn * camPos * (1 - asphalt) * (longSlipDrive factor[-0.1, -0.4]) * (speed factor[1, 15])";
			};
			class acceleration_ext_dirt
			{
				sound[]=
				{
					"",
					"db-3",
					1,
					60
				};
				frequency=1;
				volume="engineOn * camPos * (1 - asphalt) * (longSlipDrive factor[0.1, 0.4]) * (speed factor[15, 1])";
			};
			class turn_left_ext_dirt
			{
				sound[]=
				{
					"",
					"db-3",
					1,
					60
				};
				frequency=1;
				volume="engineOn * camPos * (1 - asphalt) * (latSlipDrive factor[0.1, 0.4]) * (speed factor[1, 15])";
			};
			class turn_right_ext_dirt
			{
				sound[]=
				{
					"",
					"db-3",
					1,
					60
				};
				frequency=1;
				volume="engineOn * camPos * (1 - asphalt) * (latSlipDrive factor[-0.1, -0.4]) * (speed factor[1, 15])";
			};
			class breaking_int_road
			{
				sound[]=
				{
					"",
					"db-10",
					1
				};
				frequency=1;
				volume="engineOn*asphalt * (1  -  camPos) * (longSlipDrive factor[-0.1, -0.4]) * (speed factor[2, 15])";
			};
			class acceleration_int_road
			{
				sound[]=
				{
					"",
					"db-10",
					1
				};
				frequency=1;
				volume="engineOn*asphalt * (1  -  camPos) * (longSlipDrive factor[0.1, 0.4]) * (speed factor[15, 2])";
			};
			class turn_left_int_road
			{
				sound[]=
				{
					"",
					"db-10",
					1
				};
				frequency=1;
				volume="engineOn*asphalt * (1  -  camPos) * (latSlipDrive factor[0.1, 0.4]) * (speed factor[2, 15])";
			};
			class turn_right_int_road
			{
				sound[]=
				{
					"",
					"db-10",
					1
				};
				frequency=1;
				volume="engineOn*asphalt * (1  -  camPos) * (latSlipDrive factor[-0.1, -0.4]) * (speed factor[2, 15])";
			};
			class breaking_int_dirt
			{
				sound[]=
				{
					"",
					"db-10",
					1
				};
				frequency=1;
				volume="engineOn * (1 - asphalt) * (1 - camPos) * (longSlipDrive factor[-0.1, -0.4]) * (speed factor[2, 15])";
			};
			class acceleration_int_dirt
			{
				sound[]=
				{
					"",
					"db-10",
					1
				};
				frequency=1;
				volume="engineOn * (1 - asphalt) * (1 - camPos) * (longSlipDrive factor[0.1, 0.4]) * (speed factor[15, 2])";
			};
			class turn_left_int_dirt
			{
				sound[]=
				{
					"",
					"db-10",
					1
				};
				frequency=1;
				volume="engineOn * (1 - asphalt) * (1 - camPos) * (latSlipDrive factor[0.1, 0.4]) * (speed factor[2, 15])";
			};
			class turn_right_int_dirt
			{
				sound[]=
				{
					"",
					"db-10",
					1
				};
				frequency=1;
				volume="engineOn * (1 - asphalt) * (1 - camPos) * (latSlipDrive factor[-0.1, -0.4]) * (speed factor[2, 15])";
			};
		};
		canFloat=1;
		waterLeakiness=2.5;
		waterPPInVehicle=0;
		waterAngularDampingCoef=0.5;
		waterResistanceCoef=0.0049999999;
		waterSpeedFactor=1;
		waterSpeedCoef=3;
		accelAidForceCoef=30;
		accelAidForceSpd=20;
		waterLinearDampingCoefY=10;
		maxSpeed=250;
		wheelCircumference=2.277;
		idleRpm=1000;
		redRpm=7000;
		differentialType="all_limited";
		frontRearSplit=0.44999999;
		minOmega=104.72;
		maxOmega=850;
		enginePower=400;
		peakTorque=3000;
		torqueCurve[]=
		{
			{0,0},
			{0.22175901,0.88333303},
			{0.36959901,0.93333298},
			{0.43119901,0.94999999},
			{0.49279901,0.93333298},
			{0.73919803,0.91666698},
			{0.923998,0.86666697},
			{0.98559803,0.783333}
		};
		changeGearMinEffectivity[]={0.94999999,0.15000001,0.89999998,0.89999998,0.89999998,0.89999998,0.89999998,0.80000001};
		switchTime=0.31;
		latency=1;
		class Wheels
		{
			class LF
			{
				boneName="wheel_lf_damper";
				steering=1;
				side="left";
				center="wheel_lf_axis";
				boundary="wheel_lf_bound";
				width=0.2;
				mass=4000;
				MOI=5.3000002;
				dampingRate=0.5;
				maxBrakeTorque=3000;
				maxHandBrakeTorque=0;
				suspTravelDirection[]={0,-1,0};
				suspForceAppPointOffset="wheel_lf_axis";
				tireForceAppPointOffset="wheel_lf_axis";
				maxCompression=0.2;
				MaxDroop=0.5;
				sprungMass=2000;
				springStrength=50000;
				springDamperRate=6725;
				longitudinalStiffnessPerUnitGravity=100000;
				latStiffX=25;
				latStiffY=18000;
				frictionVsSlipGraph[]=
				{
					{0,1},
					{0.5,1},
					{1,1}
				};
			};
			class LR: LF
			{
				boneName="wheel_lb_damper";
				steering=0;
				center="wheel_lb_axis";
				boundary="wheel_lb_bound";
				suspForceAppPointOffset="wheel_lb_axis";
				tireForceAppPointOffset="wheel_lb_axis";
				maxHandBrakeTorque=3000;
			};
			class RF: LF
			{
				side="right";
				boneName="wheel_rf_damper";
				center="wheel_rf_axis";
				boundary="wheel_rf_bound";
				suspForceAppPointOffset="wheel_rf_axis";
				tireForceAppPointOffset="wheel_rf_axis";
				steering=1;
			};
			class RR: RF
			{
				boneName="wheel_rb_damper";
				steering=0;
				center="wheel_rb_axis";
				boundary="wheel_rb_bound";
				suspForceAppPointOffset="wheel_rb_axis";
				tireForceAppPointOffset="wheel_rb_axis";
				maxHandBrakeTorque=3000;
			};
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"ls\core\addons\vehicles_agt\data\camo1.rvmat",
				"ls\core\addons\vehicles_agt\data\camo1_damage.rvmat",
				"ls\core\addons\vehicles_agt\data\camo1_destruct.rvmat",
				"ls\core\addons\vehicles_agt\data\camo2.rvmat",
				"ls\core\addons\vehicles_agt\data\camo2_damage.rvmat",
				"ls\core\addons\vehicles_agt\data\camo2_destruct.rvmat"
			};
		};
		class Reflectors
		{
			class Left
			{
				color[]={7000,7500,10000};
				ambient[]={70,75,100};
				intensity=50;
				size=5;
				innerAngle=15;
				outerAngle=65;
				coneFadeCoef=10;
				position="Light_L_Pos";
				direction="Light_L_Dir";
				hitpoint="Light_b_hitpoint";
				selection="Light_L_Lamp";
				useFlare=1;
				flareSize=15;
				flareMaxDistance=250;
				dayLight=0;
				class Attenuation
				{
					start=0;
					constant=0;
					linear=1;
					quadratic=1;
					hardLimitStart=100;
					hardLimitEnd=200;
				};
			};
			class Right: Left
			{
				position="Light_R_Pos";
				direction="Light_R_Dir";
				hitpoint="Light_b_hitpoint";
				selection="Light_R_Lamp";
			};
		};
	};
	class FST_vehicle_agtRaptor: FST_vehicle_agtRaptor_base
	{
		scope=2;
		author="Legion Studios";
		displayName="[41st] AGT 'Raptor'";
		side=0;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		class TextureSources
		{
			class CIS
			{
				author="Legion Studios";
				displayName="CIS";
				textures[]=
				{
					"\ls\core\addons\vehicles_agt\data\camo1_co.paa",
					"\ls\core\addons\vehicles_agt\data\camo2_co.paa"
				};
				factions[]={};
			};
			class Tan: CIS
			{
				displayName="Tan";
				textures[]=
				{
					"\ls\core\addons\vehicles_agt\data\textures\tan\camo1_co.paa",
					"\ls\core\addons\vehicles_agt\data\textures\tan\camo2_co.paa"
				};
			};
			class Olive: CIS
			{
				displayName="Olive";
				textures[]=
				{
					"\ls\core\addons\vehicles_agt\data\textures\olive\camo1_co.paa",
					"\ls\core\addons\vehicles_agt\data\textures\olive\camo2_co.paa"
				};
			};
			class Snow: CIS
			{
				displayName="Snow";
				textures[]=
				{
					"\ls\core\addons\vehicles_agt\data\textures\snow\camo1_co.paa",
					"\ls\core\addons\vehicles_agt\data\textures\snow\camo2_co.paa"
				};
			};
			class Urban: CIS
			{
				displayName="Urban";
				textures[]=
				{
					"\ls\core\addons\vehicles_agt\data\textures\urban\camo1_co.paa",
					"\ls\core\addons\vehicles_agt\data\textures\urban\camo2_co.paa"
				};
			};
			class Woodland: CIS
			{
				displayName="Woodland";
				textures[]=
				{
					"\ls\core\addons\vehicles_agt\data\textures\woodland\camo1_co.paa",
					"\ls\core\addons\vehicles_agt\data\textures\woodland\camo2_co.paa"
				};
			};
			class TradeFederation: CIS
			{
				displayName="Trade Federation";
				textures[]=
				{
					"\ls\core\addons\vehicles_agt\data\textures\tradefederation\camo1_co.paa",
					"\ls\core\addons\vehicles_agt\data\textures\tradefederation\camo2_co.paa"
				};
			};
		};
};
	class FST_vehicle_agtRaptor_Scorch: FST_vehicle_agtRaptor
	{
		scope=2;
		author="Legion Studios";
		displayName="[41st] AGT 'Raptor' (Scorch)";
		side=0;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				isCopilot=0;
				dontCreateAI=0;
				body="mainTurret";
				gun="mainGun";
				memoryPointGunnerOptics="PiP1_pos";
				memoryPointGun="machinegun";
				gunnerForceOptics=1;
				gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_F.p3d";
				turretInfoType="RscOptics_UGV_gunner";
				weapons[]=
				{
					"FST_BTX42"
				};
				magazines[]=
				{
					"FST_FuelTank",
					"FST_FuelTank",
					"FST_FuelTank",
					"FST_FuelTank",
					"FST_FuelTank",
					"FST_FuelTank",
					"FST_FuelTank",
					"FST_FuelTank",
					"FST_FuelTank",
					"FST_FuelTank"
				};
				maxHorizontalRotSpeed=1.8;
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\soft\UGV_01\Servo_UGV_gunner.wss",
					0.31622776,
					1,
					30
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\soft\UGV_01\Servo_UGV_gunner_vertical.wss",
					0.31622776,
					1,
					30
				};
				minElev=-10;
				maxElev=60;
				forceHideGunner=1;
				outGunnerMayFire=1;
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex=2;
				stabilizedInAxes=3;
				class HitPoints
				{
					class HitTurret
					{
						armor=0.5;
						material=-1;
						armorComponent="hit_main_turret";
						name="hit_main_turret_point";
						visual="OtocVez";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.40000001;
						radius=0.25;
						isTurret=1;
					};
					class HitGun
					{
						armor=0.5;
						material=-1;
						armorComponent="hit_main_gun";
						name="hit_main_gun_point";
						visual="OtocHlaven";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.40000001;
						radius=0.2;
						isGun=1;
					};
				};
				class ViewOptics: RCWSOptics
				{
					visionMode[]=
					{
						"Normal",
						"TI"
					};
					initFov=0.46669999;
					maxFov=0.46669999;
					minFov=0.035;
					directionStabilized=1;
				};
			};
		};
	};
};
