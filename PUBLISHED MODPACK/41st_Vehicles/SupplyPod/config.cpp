class CfgPatches
{
	class FST_Pod
	{
		author="Ghostly";
		requiredaddons[]=
		{
		};
		requiredversion=1;
		units[]=
		{
			"FST_Supplies_Pod",
			"FST_Logistics_Pod"
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
class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftPilot: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightPilot: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class CfgVehicles
{
	class Air;
	class Helicopter: Air
	{
		class HitPoints;
		class Turrets;
	};
	class Helicopter_Base_F: Helicopter
	{
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitFuel;
			class HitEngine;
			class HitAvionics;
			class HitHRotor;
			class HitVRotor;
			class HitTransmission;
		};
		class Turrets: Turrets
		{
			class MainTurret;
		};
		class AnimationSources;
		class EventHandlers;
		class ViewPilot;
		class ViewOptics;
	};
	class Helicopter_Base_H: Helicopter_Base_F
	{
		class Turrets: Turrets
		{
			class CopilotTurret;
			class MainTurret: MainTurret
			{
				class ViewGunner;
			};
		};
		class Components;
	};
	class LandVehicle;
	class StaticWeapon: LandVehicle
	{
		class EventHandlers;
	};
	class Pod_Heli_Transport_04_crewed_base_F: StaticWeapon
	{
	};
	class FST_Supplies_Pod: Pod_Heli_Transport_04_crewed_base_F
	{
		scope=2;
		scopecurator=2;
		forceingarage=1;
		side=1;
		tas_canBlift=1;
		tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]";
		displayname="[41st] Resupply Pod";
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\Land_Pod_Heli_Transport_04_covered_F.jpg";
		_generalMacro="Land_Pod_Heli_Transport_04_covered_F";
		model="\A3\Air_F_Heli\Heli_Transport_04\Pod_Heli_Transport_04_covered_F.p3d";
		picture="\A3\Air_F_Heli\Heli_Transport_04\Data\UI\Pod_Heli_Transport_04_covered_CA.paa";
		icon="iconObject_1x2";
		accuracy=1000;
		ace_refuel_fuelCargo=999999999999;
		ace_rearm_defaultSupply=999999999999;
		ace_repair_canRepair=1;
		ace_refuel_hooks[]=
		{
			{0.38,-3.1700001,-0.69999999},
			{-0.41,-3.1700001,-0.69999999}
		};
		armor=900;
		hiddenSelections[]=
		{
			"Camo_1",
			"Camo_2"
		};
		hiddenSelectionsTextures[] = {
		"\41st_Vehicles\SupplyPod\Data\Taru_Pod_01.paa",
		"\41st_Vehicles\SupplyPod\Data\Taru_Pod_02.paa"
		};
		textureList[] = {};
				supplyRadius=10;
		transportSoldier=14;
		hideWeaponsCargo=1;
		cargoProxyIndexes[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14};
		class CargoTurret;
		class Turrets
		{
			class CargoTurret_01: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="cargo_r_pos";
				memoryPointsGetInGunnerDir="cargo_r_dir";
				gunnerName="$STR_A3_Land_Pod_Heli_Transport_04_bench_F_Turrets_CargoTurret_010";
				proxyIndex=1;
				primaryGunner = 1; 
				maxElev=20;
				minElev=-45;
				maxTurn=55;
				minTurn=-65;
				isPersonTurret=1;
				ejectDeadGunner=0;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-65,95};
					CargoTurret_03[]={-75,95};
					CargoTurret_04[]={-80,95};
				};
			};
			class CargoTurret_02: CargoTurret_01
			{
				proxyIndex=2;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,65};
					CargoTurret_03[]={-65,95};
					CargoTurret_04[]={-75,95};
				};
			};
			class CargoTurret_03: CargoTurret_01
			{
				proxyIndex=3;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,75};
					CargoTurret_02[]={-95,65};
					CargoTurret_04[]={-65,95};
				};
			};
			class CargoTurret_04: CargoTurret_01
			{
				proxyIndex=4;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,80};
					CargoTurret_02[]={-95,75};
					CargoTurret_03[]={-95,65};
				};
			};
			class CargoTurret_05: CargoTurret_01
			{
				gunnerCompartments="Compartment3";
				memoryPointsGetInGunner="cargo_l_pos";
				memoryPointsGetInGunnerDir="cargo_l_dir";
				gunnerName="$STR_A3_Land_Pod_Heli_Transport_04_bench_F_Turrets_CargoTurret_050";
				proxyIndex=5;
				class dynamicViewLimits
				{
					CargoTurret_06[]={-65,95};
					CargoTurret_07[]={-75,95};
					CargoTurret_08[]={-80,95};
				};
			};
			class CargoTurret_06: CargoTurret_05
			{
				proxyIndex=6;
				class dynamicViewLimits
				{
					CargoTurret_05[]={-95,65};
					CargoTurret_07[]={-65,95};
					CargoTurret_08[]={-75,95};
				};
			};
			class CargoTurret_07: CargoTurret_05
			{
				proxyIndex=7;
				class dynamicViewLimits
				{
					CargoTurret_05[]={-95,75};
					CargoTurret_06[]={-95,65};
					CargoTurret_08[]={-65,95};
				};
			};
			class CargoTurret_08: CargoTurret_05
			{
				proxyIndex=8;
				class dynamicViewLimits
				{
					CargoTurret_05[]={-95,80};
					CargoTurret_06[]={-95,75};
					CargoTurret_07[]={-95,65};
				};
			};
		};
		cargoAction[]=
		{
			"passenger_apc_generic04",
			"passenger_apc_generic02",
			"passenger_apc_generic03",
			"passenger_apc_generic04",
			"passenger_apc_narrow_generic01",
			"passenger_apc_narrow_generic02",
			"passenger_apc_generic03",
			"passenger_apc_narrow_generic03",
			"passenger_generic01_foldhands",
			"passenger_apc_generic03",
			"passenger_apc_narrow_generic03",
			"passenger_apc_generic01",
			"passenger_apc_generic01",
			"passenger_generic01_leanleft",
			"passenger_generic01_leanright",
			"passenger_low01"
		};
		class TransportMagazines
		{
			class _xx_Laserbatteries
			{
				magazine="Laserbatteries";
				count=4;
			};
			class _xx_FST_blaster_cell_High
			{
				count=160;
				magazine="FST_blaster_cell_High_Blue";
			};
			class _xx_FST_blaster_cell
			{
				count=160;
				magazine="FST_blaster_cell_Blue";
			};
			class _xx_FST_blaster_cell_low
			{
				count=20;
				magazine="FST_blaster_cell_low_Blue";
			};
			class _xx_FST_blaster_scatter_cell
			{
				count=40;
				magazine="FST_blaster_scatter_cell_Blue";
			};
			class _xx_FST_thermal_slugmag_DP23
			{
				count=40
				magazine="FST_thermal_slugmag_DP23_Blue";
			};
			class _xx_FST_blaster_battery
			{
				count=40;
				magazine="FST_blaster_battery_Blue";
			};
			class _xx_FST_thermal_coil_LP
			{
				count=40;
				magazine="FST_thermal_coil_LP_Blue";
			};
			class _xx_FST_thermal_coil_T15
			{
				count=20;
				magazine="FST_thermal_coil_T15_Blue";
			};
			class _xx_FST_blaster_cell_Valken
			{
				count=40;
				magazine="FST_blaster_cell_Valken_Blue";
			};
			class _xx_FST_blaster_cell_Overcharged
			{
				count=10;
				magazine="FST_blaster_cell_Overcharged_Blue";
			};
			class _xx_FST_blaster_cell_LE
			{
				count=16;
				magazine="FST_blaster_cell_LE_Blue";
			};
			class _xx_FST_RPS6_rocket
			{
				count=40;
				magazine="FST_RPS6_rocket";
			};
			class _xx_FST_PLX1_Rocket
			{
				count=10;
				magazine="FST_PLX1_Rocket";
			};
			class _xx_FST_PLX1_AA_mag
			{
				count=10;
				magazine="FST_PLX1_AA_mag";
			};
			class _xx_FST_grenade_Detonator_mag
			{
				count=40;
				magazine="FST_grenade_Detonator_mag";
			};
			class _xx_IDA_grenade_Smoke_mag
			{
				count=20;
				magazine="IDA_grenade_Smoke_mag";
			};
			class _xx_IDA_grenade_Smoke_Red_mag
			{
				count=20;
				magazine="IDA_grenade_Smoke_Red_mag";
			};
			class _xx_IDA_grenade_Smoke_Blue_mag
			{
				count=20;
				magazine="IDA_grenade_Smoke_Blue_mag";
			};
			class _xx_IDA_grenade_Smoke_Green_mag
			{
				count=20;
				magazine="IDA_grenade_Smoke_Green_mag";
			};
			class _xx_IDA_grenade_Smoke_Purple_mag
			{
				count=20;
				magazine="IDA_grenade_Smoke_Purple_mag";
			};
			class _xx_IDA_Smoke_LauncherGrenade
			{
				count=20;
				magazine="IDA_Smoke_LauncherGrenade";
			};
			class _xx_IDA_SmokeRed_LauncherGrenade
			{
				count=20;
				magazine="IDA_SmokeRed_LauncherGrenade";
			};
			class _xx_IDA_SmokeGreen_LauncherGrenade
			{
				count=20;
				magazine="IDA_SmokeGreen_LauncherGrenade";
			};
			class _xx_IDA_SmokeBlue_LauncherGrenade
			{
				count=20;
				magazine="IDA_SmokeBlue_LauncherGrenade";
			};
			class _xx_ACE_40mm_Flare_Red
			{
				count=12;
				magazine="ACE_40mm_Flare_Red";
			};
			class _xx_ACE_40mm_Flare_White
			{
				count=12;
				magazine="ACE_40mm_Flare_White";
			};
			class _xx_FST_HE_LauncherGrenade
			{
				count=40;
				magazine="FST_HE_LauncherGrenade";
			};
			class _xx_IDA_explosive_Detpack_mag
			{
				count=20;
				magazine="IDA_explosive_Detpack_mag";
			};
			class _xx_FST_blaster_battery_DC15L
			{
				count=40;
				magazine="FST_blaster_battery_DC15L_Blue";
			};
		};
		class TransportBackpacks
		{
			class _xx_FST_Backpack_Medic
			{ 
				Backpack="FST_Backpack_Medic";
				count=4;
			};
		};
		class TransportItems
		{
			class _xx_ACE_CableTie
			{
				name="ACE_CableTie";
				count=60;
			};
			class _xx_IDA_BactaBandage
			{
				count=400;
				name="IDA_BactaBandage";
			};
			class _xx_ACE_PlasmaIV
			{
				count=60;
				name="ACE_PlasmaIV";
			};
			class _xx_IDA_BattleStim
			{
				count=100;
				name="IDA_BattleStim";
			};
			class _xx_ACE_Adenosine
			{
				count=100;
				name="ACE_Adenosine";
			};
			class _xx_ACE_Splint
			{
				count=60;
				name="ACE_Splint";
			};
			class _xx_ACE_tourniquet
			{
				count=80;
				name="ACE_tourniquet";
			};
			class _xx_IDA_Cauterizer
			{
				count=10;
				name="IDA_Cauterizer";
			};
			class _xx_FST_Bacta_Tank
			{
				count=10;
				name="FST_Bacta_Tank";
			};
		};
	};
	class FST_Logistics_Pod: Pod_Heli_Transport_04_crewed_base_F
	{
		scope=2;
		scopecurator=2;
		forceingarage=1;
		side=1;
		tas_canBlift=1;
		tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]";
		displayname="[41st] Logistics Pod";
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\Land_Pod_Heli_Transport_04_covered_F.jpg";
		_generalMacro="Land_Pod_Heli_Transport_04_covered_F";
		model="\A3\Air_F_Heli\Heli_Transport_04\Pod_Heli_Transport_04_covered_F.p3d";
		picture="\A3\Air_F_Heli\Heli_Transport_04\Data\UI\Pod_Heli_Transport_04_covered_CA.paa";
		icon="iconObject_1x2";
		accuracy=1000;
		ace_refuel_fuelCargo=999999999999;
		ace_rearm_defaultSupply=999999999999;
		ace_repair_canRepair=1;
		ace_refuel_hooks[]=
		{
			{0.38,-3.1700001,-0.69999999},
			{-0.41,-3.1700001,-0.69999999}
		};
		armor=900;
		hiddenSelections[]=
		{
			"Camo_1",
			"Camo_2"
		};
		hiddenSelectionsTextures[] = {
		"\41st_Vehicles\SupplyPod\Data\Taru_Pod_01.paa",
		"\41st_Vehicles\SupplyPod\Data\Taru_Pod_02.paa"
		};
		textureList[] = {};
				supplyRadius=10;
		transportSoldier=14;
		hideWeaponsCargo=1;
		cargoProxyIndexes[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14};
		class CargoTurret;
		class Turrets
		{
			class CargoTurret_01: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="cargo_r_pos";
				memoryPointsGetInGunnerDir="cargo_r_dir";
				gunnerName="$STR_A3_Land_Pod_Heli_Transport_04_bench_F_Turrets_CargoTurret_010";
				proxyIndex=1;
				primaryGunner = 1; 
				maxElev=20;
				minElev=-45;
				maxTurn=55;
				minTurn=-65;
				isPersonTurret=1;
				ejectDeadGunner=0;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-65,95};
					CargoTurret_03[]={-75,95};
					CargoTurret_04[]={-80,95};
				};
			};
			class CargoTurret_02: CargoTurret_01
			{
				proxyIndex=2;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,65};
					CargoTurret_03[]={-65,95};
					CargoTurret_04[]={-75,95};
				};
			};
			class CargoTurret_03: CargoTurret_01
			{
				proxyIndex=3;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,75};
					CargoTurret_02[]={-95,65};
					CargoTurret_04[]={-65,95};
				};
			};
			class CargoTurret_04: CargoTurret_01
			{
				proxyIndex=4;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,80};
					CargoTurret_02[]={-95,75};
					CargoTurret_03[]={-95,65};
				};
			};
			class CargoTurret_05: CargoTurret_01
			{
				gunnerCompartments="Compartment3";
				memoryPointsGetInGunner="cargo_l_pos";
				memoryPointsGetInGunnerDir="cargo_l_dir";
				gunnerName="$STR_A3_Land_Pod_Heli_Transport_04_bench_F_Turrets_CargoTurret_050";
				proxyIndex=5;
				class dynamicViewLimits
				{
					CargoTurret_06[]={-65,95};
					CargoTurret_07[]={-75,95};
					CargoTurret_08[]={-80,95};
				};
			};
			class CargoTurret_06: CargoTurret_05
			{
				proxyIndex=6;
				class dynamicViewLimits
				{
					CargoTurret_05[]={-95,65};
					CargoTurret_07[]={-65,95};
					CargoTurret_08[]={-75,95};
				};
			};
			class CargoTurret_07: CargoTurret_05
			{
				proxyIndex=7;
				class dynamicViewLimits
				{
					CargoTurret_05[]={-95,75};
					CargoTurret_06[]={-95,65};
					CargoTurret_08[]={-65,95};
				};
			};
			class CargoTurret_08: CargoTurret_05
			{
				proxyIndex=8;
				class dynamicViewLimits
				{
					CargoTurret_05[]={-95,80};
					CargoTurret_06[]={-95,75};
					CargoTurret_07[]={-95,65};
				};
			};
		};
		cargoAction[]=
		{
			"passenger_apc_generic04",
			"passenger_apc_generic02",
			"passenger_apc_generic03",
			"passenger_apc_generic04",
			"passenger_apc_narrow_generic01",
			"passenger_apc_narrow_generic02",
			"passenger_apc_generic03",
			"passenger_apc_narrow_generic03",
			"passenger_generic01_foldhands",
			"passenger_apc_generic03",
			"passenger_apc_narrow_generic03",
			"passenger_apc_generic01",
			"passenger_apc_generic01",
			"passenger_generic01_leanleft",
			"passenger_generic01_leanright",
			"passenger_low01"
		};
	};
};