/*class CfgPatches
{
	class FST_Fang_Fighter
	{
		units[]=
		{
			"FST_Fang_Ship",
			"FST_Fang_Elite_Ship",
			"FST_Fang_AA_Ship",
			"FST_Fang_CAS_Ship"
		};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Data_F_Tank_Loadorder"
		};
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

class CfgVehicles
{
	class Plane;
	class Plane_Base_F: Plane
	{
		class HitPoints;
	};
	class VTOL_Base_F: Plane_Base_F
	{
		class AnimationSources;
		class EventHandlers;
		class NewTurret;
		class CargoTurret;
		class Components;
		class HitPoints: HitPoints
		{
			class HitHull;
		};
		class ViewPilot;
	};
	class MFD;
	class DBA_Mando_base: VTOL_Base_F{};
	class FST_Fang_base: DBA_Mando_base
	{
		irTarget=1;
		irTargetSize=1;
		radarTarget=1;
		radarTargetSize=1;
		memoryPointDriverOptics="PilotCamera_pos";
		unitInfoType="RscOptics_CAS_Pilot";
		driverWeaponsInfoType="RscOptics_CAS_01_TGP";
		class Components: Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent: SensorTemplateIR
					{
						class AirTarget
						{
							minRange=1000;
							maxRange=10000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=1000;
							maxRange=10000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						angleRangeHorizontal=360;
						angleRangeVertical=360;
						maxTrackableSpeed=1800;
						componentType="IRSensorComponent";
						typeRecognitionDistance=2000;
						maxFogSeeThrough=0.995;
						color[]={1,0,0,1};
						allowsMarking=1;
						groundNoiseDistanceCoef=-1;
						maxGroundNoiseDistance=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
						animDirection="";
						aimDown=0;
						minTrackableSpeed=-1e+010;
						minTrackableATL=-1e+010;
						maxTrackableATL=1e+010;
					};
					class VisualSensorComponent: SensorTemplateVisual
					{
						class AirTarget
						{
							minRange=30000;
							maxRange=30000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=30000;
							maxRange=30000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						angleRangeHorizontal=360;
						angleRangeVertical=360;
						maxTrackableSpeed=1800;
						aimDown=1;
						animDirection="";
						componentType="VisualSensorComponent";
						nightRangeCoef=0;
						maxFogSeeThrough=0.94;
						color[]={1,1,0.5,0.80000001};
						typeRecognitionDistance=2000;
						allowsMarking=1;
						groundNoiseDistanceCoef=-1;
						maxGroundNoiseDistance=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
						minTrackableSpeed=-1e+010;
						minTrackableATL=-1e+010;
						maxTrackableATL=1e+010;
					};
					class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
					{
						componentType="PassiveRadarSensorComponent";
						class AirTarget
						{
							minRange=45000;
							maxRange=45000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=20000;
							maxRange=20000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						typeRecognitionDistance=12000;
						angleRangeHorizontal=360;
						angleRangeVertical=360;
						groundNoiseDistanceCoef=-1;
						maxGroundNoiseDistance=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
						animDirection="";
						aimDown=0;
						color[]={0.5,1,0.5,0.5};
						minTrackableSpeed=-1e+010;
						maxTrackableSpeed=1e+010;
						minTrackableATL=-1e+010;
						maxTrackableATL=1e+010;
						allowsMarking=0;
					};
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange=30000;
							maxRange=30000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=8000;
							maxRange=8000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						typeRecognitionDistance=8000;
						angleRangeHorizontal=180;
						angleRangeVertical=180;
						groundNoiseDistanceCoef=0.2;
						componentType="ActiveRadarSensorComponent";
						maxGroundNoiseDistance=200;
						minSpeedThreshold=30;
						maxSpeedThreshold=40;
						color[]={0,1,1,1};
						allowsMarking=1;
						animDirection="";
						aimDown=0;
						minTrackableSpeed=-1e+010;
						maxTrackableSpeed=1e+010;
						minTrackableATL=-1e+010;
						maxTrackableATL=1e+010;
					};
					class LaserSensorComponent: SensorTemplateLaser
					{
						componentType="LaserSensorComponent";
						class AirTarget
						{
							minRange=15000;
							maxRange=15000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=15000;
							maxRange=15000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						angleRangeHorizontal=180;
						angleRangeVertical=180;
						typeRecognitionDistance=0;
						color[]={1,1,1,0};
						allowsMarking=1;
						groundNoiseDistanceCoef=-1;
						maxGroundNoiseDistance=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
						animDirection="";
						aimDown=0;
						minTrackableSpeed=-1e+010;
						maxTrackableSpeed=1e+010;
						minTrackableATL=-1e+010;
						maxTrackableATL=1e+010;
					};
					class NVSensorComponent: SensorTemplateNV
					{
						componentType="NVSensorComponent";
						color[]={1,1,1,0};
						typeRecognitionDistance=0;
						class AirTarget
						{
							minRange=8000;
							maxRange=8000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=8000;
							maxRange=8000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						angleRangeHorizontal=90;
						angleRangeVertical=90;
						allowsMarking=1;
						groundNoiseDistanceCoef=-1;
						maxGroundNoiseDistance=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
						animDirection="";
						aimDown=0;
						minTrackableSpeed=-1e+010;
						maxTrackableSpeed=1e+010;
						minTrackableATL=-1e+010;
						maxTrackableATL=1e+010;
					};
				};
			};
			class TransportPylonsComponent
			{
				uiPicture="a3\air_f_gamma\plane_fighter_03\data\ui\plane_a143_3den_ca.paa";
				class Pylons
				{
					class pylons1
					{
						hardpoints[]=
						{
							"DBA_CIS_Fighter_Rail"
						};
						attachment="";
						priority=10;
						maxweight=300;
						UIposition[]={0.60000002,0.44999999};
					};
					class pylons2: pylons1
					{
						UIposition[]={0.050000001,0.44999999};
						mirroredMissilePos=1;
					};
					class pylons3: pylons1
					{
						hardpoints[]=
						{
							"DBA_CIS_Fighter_Rail"
						};
						attachment="";
						priority=9;
						maxweight=2500;
						UIposition[]={0.55000001,0.34999999};
					};
					class pylons4: pylons3
					{
						hardpoints[]=
						{
							"DBA_CIS_Fighter_Rail"
						};
						attachment="";
						priority=13;
						maxweight=5000;
						UIposition[]={0.1,0.34999999};
						mirroredMissilePos=3;
					};
					class pylons5: pylons1
					{
						hardpoints[]=
						{
							"DBA_CIS_Fighter_Rail"
						};
						attachment="";
						priority=7;
						maxweight=5000;
						UIposition[]={0.5,0.25};
					};
					class pylons6: pylons5
					{
						hardpoints[]=
						{
							"DBA_CIS_Fighter_Rail"
						};
						attachment="";
						priority=12;
						maxweight=5000;
						UIposition[]={0.15000001,0.25};
						mirroredMissilePos=5;
					};
					class Pylons7
					{
						hardpoints[]=
						{
							"DBA_CIS_Fighter_Rail"
						};
						priority=5;
						attachment="";
						maxweight=4000;
						UIposition[]={0.1,0.25};
					};
				};
				class Presets
				{
					class Empty
					{
						displayName="$STR_empty";
						attachment[]={};
					};
					class EarlyHeavy
					{
						displayName="Early Heavy Infrared Preset";
						attachment[]=
						{
						};
					};
					class Intermediate
					{
						displayName="Intermediate Infrared Preset";
						attachment[]=
						{
						};
					};
					class IntermediateHeavy
					{
						displayName="Intermediate Heavy Infrared Preset";
						attachment[]=
						{
						};
					};
					class ModernHeavy
					{
						displayName="Modern Heavy Infrared Preset";
						attachment[]=
						{
						};
					};
					class EarlyModern
					{
						displayName="Modern Infrared Preset";
						attachment[]=
						{
						};
					};
					class ModernSARH
					{
						displayName="Modern SARH Preset";
						attachment[]=
						{
						};
					};
					class EarlySARH
					{
						displayName="Early SARH Preset";
						attachment[]=
						{
						};
					};
					class IntermediateSARH
					{
						displayName="Intermediate SARH Preset";
						attachment[]=
						{
						};
					};
				};
			};
		};
		selectionFireAnim="zasleh";
		simulation="airplaneX";
		vtol=4;
		scope=0;
		scopecurator=0;
		model="DBA_CIS\Addons\DBA_Vehicles\DBA_AirVehicles\Fang\Fang_Fighter.p3d";
		displayName="[41st] Fang-Class Starfighter";
		crew="FST_Droid_B1_OOM";
		forceHideDriver=0;
		forceHideGunner=1;
		forceHideCommander=1;
		driverForceOptics=1;
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenselectionstextures[]=
		{
			"DBA_CIS\Addons\DBA_Vehicles\DBA_AirVehicles\Fang\Grey_CO.paa"
		};
		insideSoundCoef=0.2;
		destrType="DestructWreck";
		driveraction="Plane_Fighter_03_pilot";
		armor=250;
		camouflage=8;
		audible=10;
		accuracy=0.2;
		memoryPointCM[]=
		{
			"flare_launcher1",
			"flare_launcher2"
		};
		memoryPointCMDir[]=
		{
			"flare_launcher1_dir",
			"flare_launcher2_dir"
		};
		htMin=60;
		htMax=1800;
		afMax=200;
		mfMax=100;
		mFact=0;
		tBody=0;
		radartype=4;
		lockdetectionsystem="2 + 8 + 4";
		incommingmissliedetectionsystem=16;
		maxSpeed=850;
		acceleration=600;
		landingAoa="6 * 3.1415 / 180";
		landingSpeed=215;
		stallSpeed=50;
		stallWarningTreshold=0.1;
		armorStructured=1;
		envelope[]={0,0.5,2.5,4.8000002,6,7,7.5,7.5,7.5,7,6.4000001,5.5999999,2.0999999,1.7,1.4,1.35,1.3,1.15,0};
		draconicForceXCoef=6.5;
		draconicForceYCoef=8.5;
		draconicForceZCoef=9;
		draconicTorqueXCoef=2.0999999;
		draconicTorqueYCoef=3;
		angleOfIndicence=0.090000004;
		airFriction0[]={60,50,12};
		airFriction1[]={70,50,12};
		airFriction2[]={60,50,12};
		altNoForce=13000;
		altFullForce=10000;
		elevatorCoef[]={0,0.80000001,0.89999998,1,1.1,1.2,1.2,1.3,1.3,1.3,1.4,1.4,1.4};
		elevatorSensitivity=1.3;
		elevatorControlsSensitivityCoef=5;
		aileronCoef[]={0,0.5,1,1.2,1.3,1.2,1.1};
		aileronSensitivity=1.1;
		aileronControlsSensitivityCoef=5;
		rudderCoef[]={0.5,1.8,2.5999999,2.75,2.8,2.8499999,2.9000001,2.95,2.98,3.01,2.7,1.1,0.89999998,0.69999999,0.5,0.30000001};
		rudderinfluence=0.89999998;
		rudderControlsSensitivityCoef=2;
		thrustCoef[]={2.5,3.5,3.5999999,3.8,4,4.5,5,4.5,3.5,3,2.7,2.5,2.0999999,2,1,1};
		irScanRangeMin=10;
		irScanRangeMax=10000;
		irScanToEyeFactor=8;
		fuelCapacity=8000;
		wheelSteeringSensitivity=1.5;
		maxOmega=2000;
		airBrake=40;
		airBrakeFrictionCoef=5;
		flaps=1;
		flapsFrictionCoef=0.31999999;
		gearsUpFrictionCoef=0.60000002;
		airFrictionCoefs0[]={0,0,0};
		airFrictionCoefs1[]={0.1,0.5,0.0066};
		airFrictionCoefs2[]={0.001,0.0049999999,6.8000001e-005};
		laserScanner=1;
		memoryPointLRocket="P Raketa";
		memoryPointRRocket="L Raketa";
		cost=10000000;
		type="VAir";
		threat[]={0.2,1,0.89999998};
		minGForce=0.30000001;
		maxGForce=10;
		gForceShakeAttenuation=0.5;
		class camShakeGForce
		{
			power=1;
			frequency=20;
			distance=0;
			minSpeed=1;
		};
	};
	class FST_Fang_Ship: FST_Fang_base
	{
		scope=2;
		scopecurator=2;
		armor=100;
		armorStructural=4;
		Displayname="[41st] Fang-Class Starfighter";
		side=0;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Droid_B1_OOM";
		icon="A3\Air_F_Gamma\Plane_Fighter_03\Data\UI\Map_Plane_Fighter_03_CA.paa";
		forceingarage=1;
		gunBeg[]=
		{
			"Usti hlavne1",
			"Usti hlavne2"
		};
		Gunend[]=
		{
			"Konec hlavne1",
			"Konec hlavne2"
		};
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenselectionstextures[]=
		{
			"DBA_CIS\Addons\DBA_Vehicles\DBA_AirVehicles\Fang\Blue_CO.paa"
		};
		weapons[]=
		{
			"CMFlareLauncher",
			"DBA_30mw_G108K"
		};
		editorPreview="";
		magazines[]=
		{
			"DBA_30mm_STN_x800_mag",
			"DBA_30mm_STN_x800_mag",
			"DBA_30mm_STN_x800_mag",
			"120Rnd_CMFlare_Chaff_Magazine",
			"120Rnd_CMFlare_Chaff_Magazine",
			"120Rnd_CMFlare_Chaff_Magazine",
			"120Rnd_CMFlare_Chaff_Magazine",
			"120Rnd_CMFlare_Chaff_Magazine"
		};
	};
	class FST_Fang_Elite_Ship: FST_Fang_base
	{
		scope=2;
		scopecurator=2;
		Displayname="[41st] Elite Fang-Class Starfighter";
		side=0;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Droid_B1_OOM";
		icon="A3\Air_F_Gamma\Plane_Fighter_03\Data\UI\Map_Plane_Fighter_03_CA.paa";
		armor=100;
		armorStructural=8;
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenselectionstextures[]=
		{
			"DBA_CIS\Addons\DBA_Vehicles\DBA_AirVehicles\Fang\Red_CO.paa"
		};
		gunBeg[]=
		{
			"Usti hlavne1",
			"Usti hlavne2"
		};
		Gunend[]=
		{
			"Konec hlavne1",
			"Konec hlavne2"
		};
		weapons[]=
		{
			"CMFlareLauncher",
			"DBA_30mw_G108K",
			"FST_Stormfury_AA_Missile_AI",
			"FST_Rapture_AGM_Missile_AI"
		};
		editorPreview="";
		magazines[]=
		{
			"DBA_30mm_STN_x800_mag",
			"DBA_30mm_STN_x800_mag",
			"DBA_30mm_STN_x800_mag",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Rapture_12Rnd_AGM_Missile",
			"FST_Rapture_12Rnd_AGM_Missile",
			"240Rnd_CMFlare_Chaff_Magazine"
		};
	};
	class FST_Fang_AA_Ship: FST_Fang_base
	{
		scope=2;
		scopecurator=2;
		Displayname="[41st] Fang-Class Starfighter (AA)";
		side=0;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Droid_B1_OOM";
		icon="A3\Air_F_Gamma\Plane_Fighter_03\Data\UI\Map_Plane_Fighter_03_CA.paa";
		armor=100;
		armorStructural=4;
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenselectionstextures[]=
		{
			"DBA_CIS\Addons\DBA_Vehicles\DBA_AirVehicles\Fang\Red_CO.paa"
		};
		gunBeg[]=
		{
			"Usti hlavne1",
			"Usti hlavne2"
		};
		Gunend[]=
		{
			"Konec hlavne1",
			"Konec hlavne2"
		};
		weapons[]=
		{
			"CMFlareLauncher",
			"DBA_30mw_G108K",
			"FST_Stormfury_AA_Missile_AI"
		};
		editorPreview="";
		magazines[]=
		{
			"DBA_30mm_STN_x800_mag",
			"DBA_30mm_STN_x800_mag",
			"DBA_30mm_STN_x800_mag",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Stormfury_12Rnd_AA_Missile",
			"240Rnd_CMFlare_Chaff_Magazine"
		};
	};
	class FST_Fang_CAS_Ship: FST_Fang_base
	{
		scope=2;
		scopecurator=2;
		Displayname="[41st] Fang-Class Starfighter (CAS)";
		side=0;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Droid_B1_OOM";
		icon="A3\Air_F_Gamma\Plane_Fighter_03\Data\UI\Map_Plane_Fighter_03_CA.paa";
		armor=100;
		armorStructural=4;
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenselectionstextures[]=
		{
			"DBA_CIS\Addons\DBA_Vehicles\DBA_AirVehicles\Fang\Red_CO.paa"
		};
		gunBeg[]=
		{
			"Usti hlavne1",
			"Usti hlavne2"
		};
		Gunend[]=
		{
			"Konec hlavne1",
			"Konec hlavne2"
		};
		weapons[]=
		{
			"CMFlareLauncher",
			"DBA_30mw_G108K",
			"FST_Rapture_AGM_Missile_AI"
		};
		editorPreview="";
		magazines[]=
		{
			"DBA_30mm_STN_x800_mag",
			"DBA_30mm_STN_x800_mag",
			"DBA_30mm_STN_x800_mag",
			"FST_Rapture_12Rnd_AGM_Missile",
			"FST_Rapture_12Rnd_AGM_Missile",
			"240Rnd_CMFlare_Chaff_Magazine"
		};
	};
};