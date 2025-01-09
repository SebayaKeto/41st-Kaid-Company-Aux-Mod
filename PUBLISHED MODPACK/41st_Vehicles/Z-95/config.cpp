class CfgPatches
{
	class FST_Z95_base
	{
		requiredAddons[]=
		{
			"A3_Air_F_Exp",
			"3AS_ARC_170",
			"3AS_VehicleWeapons",
			"3AS_Main"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_Z95_Republic"
		};
		weapons[]={};
		author="Adapted from 3AS by Viz";
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
class CfgWeapons
{
	class CannonCore;
	class Cannon_30mm_Plane_CAS_02_F: CannonCore
	{
		class LowROF;
	};
	class 3AS_ARC_Light_Canon: Cannon_30mm_Plane_CAS_02_F{};
	class FST_Z95_Light_Cannon: 3AS_ARC_Light_Canon
	{
		displayName="[41st] Blastech LEC95 Low Energy Cannon";
		magazines[]=
		{
			"3as_Z95_1000Rnd_Light_shells",
			"3as_Z95_750Rnd_Light_shells"
		};
		reloadTime=0.059999999;
		class LowROF: LowROF
		{
			reloadTime=0.059999999;
			displayName="Blastech LEC95 Low Energy Cannon";
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType 
			{
				begin1[]=
				{
					"41st_Vehicles\Z-95\Data\Sounds\Z95_cannons_1_657.ogg",
					1.5,
					1,
					1500
				};
				begin2[]=
				{
					"41st_Vehicles\Z-95\Data\Sounds\Z95_cannons_1_657.ogg",
					1.5,
					1.015,
					1500
				};
				begin3[]=
				{
					"41st_Vehicles\Z-95\Data\Sounds\Z95_cannons_1_657.ogg",
					1.5,
					0.985,
					1500
				};
				begin4[]=
				{
					"41st_Vehicles\Z-95\Data\Sounds\Z95_cannons_1_657.ogg",
					1.5,
					1.01,
					1500
				};
				soundBegin[] = 
				{
					"begin1", 0.25,
					"begin2", 0.25,
					"begin3", 0.25,
					"begin4", 0.25
				};
			};
		};
		class GunParticles{};
	};
};
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
	class 3AS_Z95_VTOL_Base_F: VTOL_Base_F{};
	class FST_Z95_VTOL_Base_F: 3AS_Z95_VTOL_Base_F
	{
		author="Viz";
		_generalMacro="VTOL_02_base_F";
		gearretracting=1;
		scope=0;
		scopeCurator=0;
		displayName="VTOL_02_base_F0";
		model="3AS\3AS_Z95\Model\Z95_Headhunter.p3d";
		icon="3as\3AS_Z95\Data\ui\Z95_top_ca.paa";
		picture="3as\3AS_Z95\Data\ui\Z95_side_ca.paa";
		overviewPicture="\A3\Data_F_Exp\Images\VehicleXian_ca.paa";
		vehicleClass="Air";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		ace_cargo_space=1000;
		ace_cargo_hasCargo=1;
		selectionFireAnim="zasleh";
		simulation="airplaneX";
		accuracy=0.5;
		driverForceOptics=0;
		armor=500;
		acceleration=900;
		maxSpeed=1400;
		airBrake=60;
		airBrakeFrictionCoef=40;
		fuelConsumptionRate=0.2;
		fuelCapacity=8000;
		laserScanner=1;
		driverCanEject=1;
		armorStructured=1;
		explosionShielding=5;
		lockDetectionSystem="2 + 8 + 4 + 16";
		incomingMissileDetectionSystem="2 + 8 + 4";
		maximumLoad=3000;
		supplyRadius=5;
		getInRadius=3;
		weapons[]=
		{
			"FST_Z95_Light_Cannon",
			"FST_Stormfury_AA_Missile",
			"FST_Harrower_HARM_Missile",
			"CMFlareLauncher",
			"Laserdesignator_pilotCamera"
		};
		magazines[]=
		{
			"3AS_Z95_750Rnd_Light_shells",
			"3AS_Z95_750Rnd_Light_shells",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"120Rnd_CMFlare_Chaff_Magazine",
			"120Rnd_CMFlare_Chaff_Magazine",
			"120Rnd_CMFlare_Chaff_Magazine",
			"120Rnd_CMFlare_Chaff_Magazine",
			"120Rnd_CMFlare_Chaff_Magazine",
			"Laserbatteries"
		};
		landingAoa=0.113446;
		landingSpeed=215;
		engineMOI=16;
		stallWarningTreshold=0.1;
		wheelSteeringSensitivity=1.5;
		flaps=1;
		vtol=4;
		VTOLPitchInfluence=10;
		VTOLRollInfluence=10;
		VTOLYawInfluence=10;
		irScanRangeMin=10;
		irScanRangeMax=10000;
		irScanToEyeFactor=8;
		hiddenselections[]=
		{
			"camo",
			"camo1"
		};
		hiddenselectionstextures[]=
		{
			"3AS\3AS_Z95\Data\green_co.paa",
			"3AS\3AS_Z95\Data\cockpit_co.paa"
		};
		class AnimationSources: AnimationSources
		{
			class Muzzle_Flash
			{
				source="ammorandom";
				weapon="FST_Z95_Light_Cannon";
			};
			class HideWeapons
			{
				source="user";
				animPeriod=1e-006;
				initPhase=0;
			};
			class canopy_hide
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class ejection_seat_hide
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class ejection_seat_motion
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
		};
		class Components: Components
		{
			class TransportPylonsComponent
			{
				UIPicture="3as\3AS_Z95\Data\ui\pylon_z95.paa";
				class pylons
				{
					class pylons1
					{
						hardpoints[]=
						{
							""
						};
						attachment="";
						priority=10;
						maxweight=300;
						UIposition[]={0.60000002,0.44999999};
					};
				};
			};
		};
	};
	class FST_Z95_VTOL_Base: FST_Z95_VTOL_Base_F
	{
		displayName="$STR_A3_CfgVehicles_VTOL_02_infantry_base_F0";
		scope=0;
		scopeCurator=0;
		class Library
		{
			libTextDesc="[3AS] Z-95 HeadHunter";
		};
	};
	class FST_Z95_VTOL_Dynamic_Base_F: FST_Z95_VTOL_Base
	{
		class AnimationSources: AnimationSources
		{
			class HideWeapons
			{
				source="user";
				animPeriod=1e-006;
				initPhase=1;
			};
		};
		class Components: Components
		{
		};
	};
	class FST_Z95_Republic: FST_Z95_VTOL_Dynamic_Base_F
	{
		author="Adapted from 3AS by Viz";
		_generalMacro="O_T_VTOL_02_infantry_dynamicLoadout_F";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Z-95 HeadHunter";
		side=1;
		crew="FST_Pilot_P1";
		typicalCargo[]=
		{
			"FST_Pilot_P1"
		};
		faction="FST_Faction";
		availableForSupportTypes[]=
		{
			"CAS_Bombing"
		};
		editorPreview="";
		hiddenselections[]=
		{
			"camo",
			"camo1",
			"camo2"
		};
		hiddenselectionstextures[]=
		{
			"3AS\3AS_Z95\Data\body_co.paa",
			"3AS\3AS_Z95\Data\cockpit_co.paa",
			"3AS\3AS_Z95\data\glass\glass_ca"
		};
	};
};
