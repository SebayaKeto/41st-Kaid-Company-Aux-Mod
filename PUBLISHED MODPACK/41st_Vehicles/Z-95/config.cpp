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
					3.5,
					1,
					1500
				};
				begin2[]=
				{
					"41st_Vehicles\Z-95\Data\Sounds\Z95_cannons_1_657.ogg",
					3.5,
					1.015,
					1500
				};
				begin3[]=
				{
					"41st_Vehicles\Z-95\Data\Sounds\Z95_cannons_1_657.ogg",
					3.5,
					0.985,
					1500
				};
				begin4[]=
				{
					"41st_Vehicles\Z-95\Data\Sounds\Z95_cannons_1_657.ogg",
					3.5,
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
		accuracy=0.5;
		driverForceOptics=0;
		armor=125;
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
			"CMFlareLauncher",
			"Laserdesignator_pilotCamera"
		};
		magazines[]=
		{
			"3AS_Z95_750Rnd_Light_shells",
			"3AS_Z95_750Rnd_Light_shells",
			"120Rnd_CMFlare_Chaff_Magazine",
			"Laserbatteries",
			"120Rnd_CMFlare_Chaff_Magazine",
			"120Rnd_CMFlare_Chaff_Magazine",
			"120Rnd_CMFlare_Chaff_Magazine",
			"120Rnd_CMFlare_Chaff_Magazine"
		};
		maxSpeed=680;
		landingAoa=0.113446;
		landingSpeed=215;
		engineMOI=16;
		stallSpeed=190;
		stallWarningTreshold=0.1;
		wheelSteeringSensitivity=1.5;
		airBrake=55;
		airBrakeFrictionCoef=60;
		flaps=1;
		vtol=4;
		VTOLPitchInfluence=1;
		VTOLRollInfluence=10;
		VTOLYawInfluence=12;
		acceleration=200;
		fuelCapacity=2000;
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
							"B_BIM9X_RAIL"
						};
						attachment="PylonRack_Missile_BIM9X_x1";
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
							"B_BIM9X_RAIL",
							"B_BIM9X_DUAL_RAIL",
							"B_AMRAAM_D_RAIL",
							"B_AMRAAM_D_DUAL_RAIL",
							"B_AGM65_RAIL",
							"ARC_AGM_PYLON"
						};
						attachment="3AS_PylonRack_ARC_6Rnd_Missile_AGM";
						priority=9;
						maxweight=2500;
						UIposition[]={0.55000001,0.34999999};
					};
					class pylons4: pylons3
					{
						UIposition[]={0.1,0.34999999};
						mirroredMissilePos=3;
					};
					class pylons5: pylons1
					{
						hardpoints[]=
						{
							"B_BIM9X_RAIL",
							"B_BIM9X_DUAL_RAIL",
							"B_AMRAAM_D_RAIL",
							"B_AMRAAM_D_DUAL_RAIL",
							"B_AGM65_RAIL",
							"B_AGM65_DUAL_RAIL",
							"B_HARM_RAIL",
							"ARC_AGM_PYLON"
						};
						attachment="PylonRack_Missile_AMRAAM_D_x1";
						priority=7;
						maxweight=5000;
						UIposition[]={0.5,0.25};
					};
					class pylons6: pylons5
					{
						UIposition[]={0.15000001,0.25};
						mirroredMissilePos=5;
					};
					class Pylons7
					{
						hardpoints[]=
						{
							"z95_CANON_PYLON"
						};
						priority=5;
						attachment="3AS_PylonWeapon_Z95_240Rnd_Heavy_Shells";
						maxweight=4000;
						UIposition[]={0.32499999,0.15000001};
					};
				};
				class presets
				{
					class empty
					{
						displayName="$STR_empty";
						attachment[]={};
					};
					class AA
					{
						displayName="$STR_A3_cfgmagazines_titan_aa_dns";
						attachment[]=
						{
							"PylonRack_Missile_BIM9X_x1",
							"PylonRack_Missile_BIM9X_x1",
							"PylonRack_Missile_AMRAAM_D_x2",
							"PylonRack_Missile_AMRAAM_D_x2",
							"PylonRack_Missile_AMRAAM_D_x2",
							"PylonRack_Missile_AMRAAM_D_x2",
							"3AS_PylonWeapon_Z95_240Rnd_Heavy_Shells"
						};
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
		crew="JLTS_Clone_P2_DC15S";
		typicalCargo[]=
		{
			"JLTS_Clone_P2_DC15S"
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