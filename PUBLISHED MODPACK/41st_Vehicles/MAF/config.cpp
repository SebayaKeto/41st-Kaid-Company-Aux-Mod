class CfgPatches
{
	class FST_CIS_Heli_MAF
	{
		requiredAddons[]=
		{
			"A3_Armor_F_Beta",
			"A3_Weapons_F",
			"A3_Data_F",
			"A3_Air_F"
		};
		units[]=
		{
			"FST_MAF_Gunship_F",
			"FST_MAF_Transport_F",
			"FST_MAF_CIS_Gunship",
			"FST_MAF_CIS_Transport"
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
class ls_impulsor_base;
class CfgVehicles
{
	class Air;
	class Helicopter: Air
	{
		class HitPoints;
		class ACE_Actions
		{
			class ACE_MainActions;
		};
	};
	class Helicopter_Base_F: Helicopter
	{
		class Turrets;
		class Eventhandlers;
		class HitPoints: HitPoints
		{
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
			class HitHull;
			class HitEngine;
			class HitAvionics;
			class HitVRotor;
			class HitHRotor;
			class HitFuel;
		};
	};
	class Heli_Attack_01_base_F: Helicopter_Base_F
	{
		class Turrets: Turrets
		{
			class CopilotTurret;
			class MainTurret;
		};
		class AnimationSources;
		class ViewPilot;
		class ViewOptics;
		class components;
		class RotorLibHelicopterProperties;
	};
	class 3AS_MAF_Base_F: Heli_Attack_01_base_F {};
	class FST_MAF_Base_F: 3AS_MAF_Base_F
	{
		author="Adapted from 3AS Mod Team by Viz";
		_generalMacro="Heli_Attack_01_base_F";
		scope=0;
		side=0;
		scopeCurator=0;
		forceInGarage=0;
		driverForceOptics=1;
		forcehidedriver=1;
		memoryPointDriverOptics="driverview";
		driverOpticsModel="\A3\Drones_F\Weapons_F_Gamma\Reticle\UGV_01_Optics_Gunner_F.p3d";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Droid_B1_OOM";
		displayName="[41st] MAF";
		model="3as\3AS_CIS_Heli\MAF\model\3AS_MAF.p3d";
		icon="3as\3AS_CIS_Heli\MAF\data\ui\MAF_top_ca.paa";
		picture="3as\3AS_CIS_Heli\MAF\data\ui\MAF_side_ca.paa";
		editorpreview="";
		memoryPointtaskMarker="TaskMarker_1_pos";
		accuracy=0.5;
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenselectionstextures[]=
		{
			"3as\3AS_CIS_Heli\MAF\data\MAF_Body_Front_co.paa",
			"3as\3AS_CIS_Heli\MAF\data\MAF_Body_Back_co.paa"
		};
		nameSound="veh_helicopter_s";
		fuelCapacity=1000;
		fuelConsumptionRate=0.2;
		mainBladeRadius=0.1;
		liftForceCoef=3;
		bodyFrictionCoef=1.9845001;
		cyclicAsideForceCoef=2.8;
		backRotorForceCoef=1.8;
		cyclicForwardForceCoef=2;
		acceleration=450;
		maxSpeed=600;
		brakeDistance=400;
		mainRotorSpeed=-1;
		backRotorSpeed=1;
		maxMainRotorDive=7;
		minMainRotorDive=-7;
		neutralMainRotorDive=0;
		startDuration=4.5;
		castDriverShadow=0;
		canFloat=1;
		waterLeakiness=0.2;
		waterResistanceCoef=0.89999998;
		waterResistance=1;
		waterLinearDampingCoefY=3;
		waterLinearDampingCoefX=2;
		waterAngularDampingCoef=3;
		maxFordingDepth=110.65;
		armor=175;
		armorStructural=1.25;
		altFullForce=137400;
		altNoForce=172400;
		crewCrashProtection=0;
		explosionShielding=0.33000001;
		epeImpulseDamageCoef=0;
		ace_fastroping_enabled=1;
		ace_fastroping_ropeOrigins[]=
		{
			
			{
				"rope1"
			},
			
			{
				"Rope2"
			}
		};
		ace_fastroping_onCut="ace_fastroping_fnc_onCutCommon";
		ace_fastroping_onPrepare="ace_fastroping_fnc_onPrepareCommon";
		slingLoadMaxCargoMass=5000000;
		radarType=8;
		getInRadius=10;
		typicalCargo[]=
		{
			"B_HeliPilot_F"
		};
		memorypointlmissile="Laser_L1_Pos";
		memorypointrmissile="Laser_R1_Pos";
		memoryPointLRocket="Laser_L2_Pos";
		memoryPointRRocket="Laser_R2_Pos";
		weapons[]=
		{
			"3AS_MAF_Light_Canon",
			"CMFlareLauncher"
		};
		magazines[]=
		{
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"3as_MAF_500Rnd_Light_shells",
			"3as_MAF_500Rnd_Light_shells",
			"3as_MAF_500Rnd_Light_shells",
			"3as_MAF_500Rnd_Light_shells"
		};
		memoryPointGun[]=
		{
			"Laser_L1_Pos",
			"Laser_L2_Pos",
			"Laser_R1_Pos",
			"Laser_R2_Pos"
		};
		primarygunner=1;
		selectionFireAnim="zasleh";
		maximumLoad=25000;
		transportSoldier=20;
		cargoProxyIndexes[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
		getInProxyOrder[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
		hideWeaponsCargo=1;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				caneject=0;
				castgunnershadow=1;
				commanding=-1;
				discretedistance[]={100,200,300,400,500,600,700,800,1000,1200,1500,1800,2100};
				discretedistanceinitindex=5;
				gunneraction="MTT_cargo";
				gunnerInAction="MTT_cargo";
				gunnerforceoptics=1;
				displayname="CoPilot";
				gunnergetinaction="Heli_Attack_01_Gunner_Enter";
				gunnergetoutaction="Heli_Attack_01_Gunner_Exit";
				gunnerlefthandanimname="lever_copilot";
				gunneropticseffect[]=
				{
					"TankCommanderOptics1",
					"BWTV"
				};
				gunneropticsmodel="";
				gunnerrighthandanimname="stick_copilot";
				initelev=0;
				initturn=0;
				iscopilot=1;
				maxelev=70;
				maxturn=180;
				memorypointgunneroptics="Gunner_Optics";
				memorypointsgetingunner="getin_pos";
				memorypointsgetingunnerdir="getin_dir";
				minelev=-5;
				minturn=-180;
				outgunnermayfire=1;
				precisegetinout=1;
				primarygunner=0;
				selectionfireanim="zaslehTop";
				soundservo[]=
				{
					"",
					0.0099999998,
					1
				};
				startengine=0;
				animationSourceBody="BackLaser_Turret";
				animationsourcegun="BackLaser_Gun";
				animationsourcehatch="";
				body="BackLaser_Turret";
				gun="BackLaser_Gun";
				turretinfotype="RscOptics_Heli_Attack_01_gunner";
				weapons[]=
				{
					"CMFlareLauncher",
					"3AS_MAF_Light_Canon"
				};
				magazines[]=
				{
					"240Rnd_CMFlare_Chaff_Magazine",
					"240Rnd_CMFlare_Chaff_Magazine",
					"240Rnd_CMFlare_Chaff_Magazine",
					"240Rnd_CMFlare_Chaff_Magazine",
					"3as_MAF_500Rnd_Light_shells"
				};
				gunBeg="Laser_T1_dir";
				gunEnd="Laser_T1_pos";
				memoryPointGun[]=
				{
					"Laser_T2_dir",
					"Laser_T1_dir"
				};
			};
		};
		class ls_impulsor: ls_impulsor_base
		{
			enabled=1;
			speed=300;
			fueldrain=0.0001;
			overchargespeed=800;
			overchargeFuelDrain=0.0001;
			overchargeCooldown=0
		};
		class VehicleTransport
		{
			class Carrier
			{
				cargoBayDimensions[]=
				{
					"Limit1",
					"limit2"
				};
				disableHeightLimit=1;
				maxLoadMass=60000;
				cargoAlignment[]=
				{
					"center",
					"front"
				};
				cargoSpacing[]={0,0.15000001,0};
				exits[]=
				{
					"pos_cargo_load"
				};
				unloadingInterval=2;
				loadingDistance=10;
				loadingAngle=180;
				parachuteClassDefault="B_Parachute_02_F";
				parachuteHeightLimitDefault=50;
			};
		};
		class Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent: SensorTemplateIR
					{
						class AirTarget
						{
							minRange=0;
							maxRange=0;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=0;
							maxRange=0;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						maxTrackableSpeed=70;
						animDirection="mainGun";
						angleRangeHorizontal=46;
						angleRangeVertical=34;
						aimdown=-0.25;
					};
					class VisualSensorComponent: SensorTemplateVisual
					{
						class AirTarget
						{
							minRange=0;
							maxRange=0;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=0;
							maxRange=0;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						maxTrackableSpeed=70;
						animDirection="mainGun";
						angleRangeHorizontal=46;
						angleRangeVertical=34;
						aimdown=-0.25;
					};
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange=5000;
							maxRange=5000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=4000;
							maxRange=4000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						maxTrackableSpeed=125;
						angleRangeHorizontal=180;
						angleRangeVertical=90;
						groundNoiseDistanceCoef=-1;
						maxGroundNoiseDistance=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
						aimDown=30;
					};
					class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
					{
					};
					class LaserSensorComponent: SensorTemplateLaser
					{
					};
					class NVSensorComponent: SensorTemplateNV
					{
					};
				};
			};
		};
		class Eventhandlers: Eventhandlers
		{
			postInit="if (local (_this select 0)) then { [(_this select 0), """", [], false] call BIS_fnc_initVehicle; };";
		};
		class AnimationSources: AnimationSources
		{
			class HideSeats
			{
				displayName="Hide Seats";
				author="$STR_A3_Bohemia_Interactive";
				source="user";
				lockCargoAnimationPhase=1;
				lockCargo[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
				initPhase=0;
				forceAnimatePhase=0;
				forceAnimate[]={};
				mass=-250;
				animPeriod=1;
				OnPhaseChanged="_this call TAS_fnc_mafVehicleTransport;";
			};
			class Muzzle_flash
			{
				source="ammorandom";
				weapon="3AS_MAF_Light_Canon";
			};
			class Muzzle_flash2
			{
				source="ammorandom";
				weapon="3AS_MAF_Light_Canon";
			};
		};
		animationList[]=
		{
			"HideSeats",
			1
		};
		class TextureSources
		{
			class Base
			{
				displayName="Grey";
				author="Charger";
				textures[]=
				{
					"3as\3AS_CIS_Heli\MAF\data\MAF_Body_Front_co.paa",
					"3as\3AS_CIS_Heli\MAF\data\MAF_Body_Back_co.paa"
				};
				factions[]=
				{
					"FST_BattleDroids_Faction"
				};
			};
			class CIS
			{
				displayName="Blue";
				author="Charger";
				textures[]=
				{
					"3as\3AS_CIS_Heli\MAF\data\MAF_Body_Front_CIS_co.paa",
					"3as\3AS_CIS_Heli\MAF\data\MAF_Body_Back_CIS_co.paa"
				};
				factions[]=
				{
					"FST_BattleDroids_Faction"
				};
			};
			class Pink
			{
				displayName="The One True Texture";
				author="Vulgar";
				Textures[]=
				{
					"#(argb,8,8,3)color(1,0.501961,1,1.0,co)",
					"#(argb,8,8,3)color(1,0.501961,1,1.0,co)",
					"#(argb,8,8,3)color(1,0.501961,1,1.0,co)"
				};
				factions[]=
				{
					"FST_BattleDroids_Faction"
				};
			};
		};
		textureList[]=
		{
			"Base",
			1,
			"CIS",
			0,
			"Pink",
			0
		};
	};
	class FST_MAF_Gunship_F: FST_MAF_Base_F
	{
		displayName="[41st] MAF (Gunship)";
		scope=2;
		side=0;
		scopeCurator=2;
		scopearsenal=2;
		forceInGarage=1;
		animationList[]=
		{
			"HideSeats",
			1
		};
		textureList[]=
		{
			"Base",
			1,
			"CIS",
			0,
			"Pink",
			0
		};
	};
	class FST_MAF_Transport_F: FST_MAF_Base_F
	{
		scope=2;
		side=0;
		scopeCurator=2;
		scopearsenal=2;
		forceInGarage=1;
		displayName="[41st] MAF (Transport)";
		animationList[]=
		{
			"HideSeats",
			0
		};
		textureList[]=
		{
			"Base",
			1,
			"CIS",
			0,
			"Pink",
			0
		};
	};
	class FST_MAF_CIS_Gunship: FST_MAF_Base_F
	{
		displayName="[41st] MAF (CIS Gunship)";
		forceInGarage=0;
		textureList[]=
		{
			"Base",
			0,
			"CIS",
			1,
			"Pink",
			0
		};
	};
	class FST_MAF_CIS_Transport: FST_MAF_Base_F
	{
		displayName="[41st] MAF (CIS Transport)";
		forceInGarage=0;
		textureList[]=
		{
			"Base",
			0,
			"CIS",
			1,
			"Pink",
			0
		};
	};
};
class CfgFunctions
{
	class TAS
	{
		class mafVehicleInVehicle
		{
			file="3as\3AS_CIS_Heli\MAF\fnc";
			class mafVehicleTransport
			{
			};
		};
	};
};