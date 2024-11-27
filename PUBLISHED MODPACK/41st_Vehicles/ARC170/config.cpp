class CfgPatches
{
	class FST_ARC_170
	{
		units[]=
		{
			"FST_Arc_170",
			"FST_Arc_170_Ghostly"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
		};
	};
};
class Extended_init_EventHandlers
{
	class FST_Arc_170
	{
		class laat_init_eh
		{
			init="(_this) spawn ls_vehicle_fnc_ImpulsorMonitor; [_this select 0,"""",[7,8,9,10]] call ls_vehicle_fnc_laatCargoTurretPhase;";
		};
	};
	class FST_Arc_170_Ghostly
	{
		class laat_init_eh
		{
			init="(_this) spawn ls_vehicle_fnc_ImpulsorMonitor; [_this select 0,"""",[7,8,9,10]] call ls_vehicle_fnc_laatCargoTurretPhase;";
		};
	};
};
class AnimationSources;
class UserActions;
class Eventhandlers;
class HitPoints;
class HitHull;
class MarkerLights;
class Components;
class EjectionSystem;
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
	class thingX;
	class Motorcycle;
	class Air;
	class Plane: Air
	{
		class NewTurret;
		class ViewPilot;
		class HitPoints
		{
			class HitHull;
		};
	};
	class Plane_Base_F: Plane
	{
		class AnimationSources;
		class ACE_selfActions;
		class Components;
	};
	class Plane_Fighter_03_base_F: Plane_Base_F
	{
		class Turrets
		{
			class MainTurret;
		};
	};
	class Plane_Fighter_03_dynamicLoadout_base_F: Plane_Fighter_03_base_F
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
			};
		};
		class Components: Components
		{
			class TransportPylonsComponent
			{
				class Pylons;
				class Presets;
			};
		};
		class MarkerLights;
	};
	class 3as_arc_170_base: Plane_Fighter_03_dynamicLoadout_base_F
	{
		class Turrets: Turrets
		{
			class LaserPilot: NewTurret
			{
			};
			class Reargun: NewTurret
			{
			};
		};
	};
	class NewTurret;
	class 3as_arc_170_blue: 3as_arc_170_base
	{
		class Components;
		class Turrets: Turrets
		{
			class LaserPilot: LaserPilot
			{
			};
			class Reargun: Reargun
			{
			};
		};
	};
	class FST_Arc_170: 3as_arc_170_base
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		vtol=4;
		author="Ghostly";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		displayName="[41st] ARC-170 Heavy Fighter";
		model="3as\3as_arc170\model\Arc_170.p3d";
		icon="3as\3AS_ARC170\Data\ui\ARC_top_ca.paa";
		picture="3as\3AS_ARC170\Data\ui\ARC_side_ca.paa";
		ls_impulsor_fuelDrain_1=9.9999997e-005;
		ls_impulsor_fuelDrain_2=9.9999997e-005;
		ls_impulsor_boostSpeed_1=600;
		ls_impulsor_boostSpeed_2=1200;
		tas_impulse_break=100;
		ls_hasImpulse=1;
		tas_can_impulse=0;
		ace_cargo_space=1000;
		ace_cargo_hasCargo=1;
		selectionFireAnim="zasleh";
		simulation="airplaneX";
		armor=500;
		acceleration=900;
		maxSpeed=1200;
		airBrake=60;
		airBrakeFrictionCoef=40;
		fuelConsumptionRate=0.2;
		fuelCapacity=8000;
		laserScanner=1;
		driverCanEject=1;
		showAllTargets=4;
		showCrewAim=0;
		radartype=4;
		radarTargetSize=1.4;
		visualTargetSize=1.2;
		irTargetSize=1.4;
		lockDetectionSystem="2 + 8 + 4 + 16";
		incomingMissileDetectionSystem="2 + 8 + 4";
		class Turrets: Turrets
		{
			delete LaserPilot;
			delete Reargun;
		};
		class ViewPilot: ViewPilot
		{
			initAngleX=0;
		};
		weapons[]=
		{
			"FST_ARC_Heavy_Chaingun",
			"FST_Rapture_AGM_Missile",
			"FST_Stormfury_AA_Missile",
			"FST_Harrower_HARM_Missile",
			"ls_weapon_CMFlareLauncher",
			"Laserdesignator_pilotCamera"
		};
		magazines[]=
		{
			"FST_ARC_4000Rnd_Heavy_shells",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"Laserbatteries",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Rapture_12Rnd_AGM_Missile",
			"FST_Rapture_12Rnd_AGM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile"
		};
		hiddenselections[]=
		{
			"camo1",
			"camo2",
			"guns",
			"glass"
		};
		hiddenselectionstextures[]=
		{
			"3as\3AS_ARC170\Data\units\101st_Main_Frame_CO.paa",
			"3as\3AS_ARC170\Data\units\101st_Wings_Engines_CO.paa",
			"3as\3AS_ARC170\Data\units\101st_Guns_CO.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_glass_01_ca.paa"
		};
		memoryPointDriverOptics="PilotCamera_1";
		unitInfoType="RscOptics_CAS_Pilot";
		driverWeaponsInfoType="RscOptics_CAS_01_TGP";
		class pilotCamera
		{
			class OpticsIn
			{
				class Wide
				{
					opticsDisplayName="WFOV";
					initAngleX=0;
					minAngleX=0;
					maxAngleX=0;
					initAngleY=0;
					minAngleY=0;
					maxAngleY=0;
					initFov="(30 / 120)";
					minFov="(30 / 120)";
					maxFov="(30 / 120)";
					directionStabilized=1;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0,1};
					gunnerOpticsModel="\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
				};
				class Medium: Wide
				{
					opticsDisplayName="MFOV";
					initFov="(6 / 120)";
					minFov="(6 / 120)";
					maxFov="(6 / 120)";
					gunnerOpticsModel="\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
				};
				class Narrow: Wide
				{
					opticsDisplayName="NFOV";
					initFov="(2 / 120)";
					minFov="(2 / 120)";
					maxFov="(2 / 120)";
					gunnerOpticsModel="\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
				};
			};
			driverForceOptics=0;
			minTurn=-180;
			maxTurn=180;
			initTurn=0;
			minElev=-180;
			maxElev=180;
			initElev=0;
			maxXRotSpeed=1;
			maxYRotSpeed=1;
			maxMouseXRotSpeed=0.5;
			maxMouseYRotSpeed=0.5;
			pilotOpticsShowCursor=1;
			controllable=1;
		};
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
							minRange=0;
							maxRange=8000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=0;
							maxRange=6000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						angleRangeHorizontal=360;
						angleRangeVertical=360;
						maxTrackableSpeed=600;
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
							minRange=0;
							maxRange=10000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=0;
							maxRange=6000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						angleRangeHorizontal=360;
						angleRangeVertical=360;
						maxTrackableSpeed=100;
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
							minRange=0;
							maxRange=32000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=0;
							maxRange=20000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						typeRecognitionDistance=8000;
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
							minRange=0;
							maxRange=14000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=0;
							maxRange=14000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						typeRecognitionDistance=10000;
						angleRangeHorizontal=360;
						angleRangeVertical=360;
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
							minRange=0;
							maxRange=6000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=0;
							maxRange=6000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						angleRangeHorizontal=360;
						angleRangeVertical=360;
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
							minRange=0;
							maxRange=8000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=0;
							maxRange=8000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						angleRangeHorizontal=360;
						angleRangeVertical=360;
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
			class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
			{
				defaultDisplay="EmptyDisplay";
				class Components
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
					class VehicleDriverDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Driver";
					};
					class VehicleMissileDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Missile";
					};
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={2000,4000,8000,16000,30000};
						resource="RscCustomInfoSensors";
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
			{
				defaultDisplay="SensorDisplay";
				class Components
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
					class VehicleDriverDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Driver";
					};
					class VehicleMissileDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Missile";
					};
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={8000,2000,4000,16000,30000};
						resource="RscCustomInfoSensors";
					};
				};
			};
			class TransportPylonsComponent
			{
				UIPicture="3as\3as_arc170\data\plane_arc_pylon_ca.paa";
				class pylons
				{
					class pylons1
					{
						hardpoints[]=
						{
							"B_AMRAAM_D_RAIL",
							"B_AMRAAM_D_DUAL_RAIL",
							"B_AGM65_RAIL",
							"B_AGM65_DUAL_RAIL",
							"ARC_AGM_PYLON",
							"B_HARM_RAIL",
							"DAGR",
							"B_BOMB_PYLON",
						};
						attachment="PylonRack_Missile_BIM9X_x2";
						priority=10;
						maxweight=5000;
						UIposition[]={0.5,0.25};
					};
					class pylons2: pylons1
					{
						UIposition[]={0.15000001,0.25};
						mirroredMissilePos=1;
					};
					class pylons3: pylons1
					{
						hardpoints[]=
						{
							"B_AMRAAM_D_RAIL",
							"B_AMRAAM_D_DUAL_RAIL",
							"B_AGM65_RAIL",
							"B_AGM65_DUAL_RAIL",
							"ARC_AGM_PYLON",
							"B_HARM_RAIL",
							"DAGR",
							"B_BOMB_PYLON",
						};
						attachment="PylonMissile_1Rnd_Bomb_04_F";
						priority=9;
						maxweight=5000;
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
							"B_AMRAAM_D_RAIL",
							"B_AMRAAM_D_DUAL_RAIL",
							"B_AGM65_RAIL",
							"B_AGM65_DUAL_RAIL",
							"ARC_AGM_PYLON",
							"B_HARM_RAIL",
							"DAGR",
							"B_BOMB_PYLON",
						};
						attachment="PylonRack_Missile_AMRAAM_D_x1";
						priority=7;
						maxweight=5000;
						UIposition[]={0.60000002,0.44999999};
					};
					class pylons6: pylons5
					{
						UIposition[]={0.050000001,0.44999999};
						mirroredMissilePos=5;
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
							"3as_PylonRack_ARC_6Rnd_Missile_AGM",
							"3as_PylonRack_ARC_6Rnd_Missile_AGM",
							"PylonRack_Missile_AMRAAM_D_x1",
							"PylonRack_Missile_AMRAAM_D_x1"
						};
					};
					class CAS
					{
						displayName="$STR_A3_CAS_PRESET_DISPLAYNAME";
						attachment[]=
						{
							"PylonRack_Missile_BIM9X_x1",
							"PylonRack_Missile_BIM9X_x1",
							"PylonMissile_1Rnd_Bomb_04_F",
							"PylonMissile_1Rnd_Bomb_04_F",
							"3as_PylonRack_ARC_6Rnd_Missile_AGM",
							"3as_PylonRack_ARC_6Rnd_Missile_AGM"
						};
					};
				};
			};
		};
		driveoncomponent[]={};
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
		class ACE_selfActions: ACE_selfActions
		{
			class LS_HUD_Changer
			{
				displayName="Change HUD Color :)";
				exceptions[]=
				{
					"isNotInside",
					"isNotSwimming",
					"isNotSitting"
				};
				condition="!(isNull objectParent player) && (driver (vehicle player)==player)";
				showDisabled=0;
				priority=2.5;
				icon="ls_data\icons\hud\colorWheel.paa";
				class LS_Red_HUD
				{
					displayName="Red HUD Color";
					exceptions[]=
					{
						"isNotInside",
						"isNotSwimming",
						"isNotSitting"
					};
					condition="!(isNull objectParent player)";
					statement="[1,0,0,1,vehicle player] spawn ls_utility_fnc_hudColorChange";
					showDisabled=0;
					runOnHover=1;
					priority=2.5;
					icon="ls_data\icons\hud\red.paa";
				};
				class LS_Orange_HUD: LS_Red_HUD
				{
					displayName="Orange HUD Color";
					statement="[1,.05,0,1,vehicle player] spawn ls_utility_fnc_hudColorChange";
					icon="ls_data\icons\hud\orange.paa";
				};
				class LS_Yellow_HUD: LS_Red_HUD
				{
					displayName="Yellow HUD Color";
					statement="[1,1,0,1,vehicle player] spawn ls_utility_fnc_hudColorChange";
					icon="ls_data\icons\hud\yellow.paa";
				};
				class LS_Green_HUD: LS_Red_HUD
				{
					displayName="Green HUD Color";
					statement="[0,1,0,1,vehicle player] spawn ls_utility_fnc_hudColorChange";
					icon="ls_data\icons\hud\green.paa";
				};
				class LS_Cyan_HUD: LS_Red_HUD
				{
					displayName="Cyan HUD Color";
					statement="[0,1,1,1,vehicle player] spawn ls_utility_fnc_hudColorChange";
					icon="ls_data\icons\hud\cyan.paa";
				};
				class LS_Blue_HUD: LS_Red_HUD
				{
					displayName="Blue HUD Color";
					statement="[0,0,1,1,vehicle player] spawn ls_utility_fnc_hudColorChange";
					icon="ls_data\icons\hud\blue.paa";
				};
				class LS_Purple_HUD: LS_Red_HUD
				{
					displayName="Purple HUD Color";
					statement="[.5,0,.5,1,vehicle player] spawn ls_utility_fnc_hudColorChange";
					icon="ls_data\icons\hud\purple.paa";
				};
				class LS_White_HUD: LS_Red_HUD
				{
					displayName="White HUD Color";
					statement="[1,1,1,1,vehicle player] spawn ls_utility_fnc_hudColorChange";
					icon="ls_data\icons\hud\white.paa";
				};
				class LS_Black_HUD: LS_Red_HUD
				{
					displayName="Black HUD Color";
					statement="[0,0,0,1,vehicle player] spawn ls_utility_fnc_hudColorChange";
					icon="ls_data\icons\hud\black.paa";
				};
				class LS_Clear_HUD: LS_Red_HUD
				{
					displayName="No HUD Color";
					statement="[1,1,1,0,vehicle player] spawn ls_utility_fnc_hudColorChange";
					icon="ls_data\icons\hud\noHud.paa";
				};
			};
		};
	};
	class FST_ARC_170_Ghostly: FST_ARC_170
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayName="[41st] ARC-170 Heavy Fighter (Ghostly)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Ghostly";
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\ARC170\Data\FST_Ghostly_Main_Frame_CO.paa",
			"41st_Vehicles\ARC170\Data\FST_Ghostly_Wings_Engines_CO.paa",
			"3as\3AS_ARC170\Data\units\101st_Guns_CO.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_glass_01_ca.paa"
		};
	};	
};
class CfgAmmo
{
	class Cannon_30mm_HE_Plane_CAS_02_F;
	class FST_ARC_Heavy_Energy_shell: Cannon_30mm_HE_Plane_CAS_02_F
	{
		displayname="Heavy Energy";
		warheadName="HEnergy";
		hit=600;
		indirectHit=12;
		indirectHitRange=3;
		caliber=14;
		explosive=1;
		allowAgainstInfantry=1;
		airlock=1;
		model="\Indecisive_Armoury_SW\Ammos\Data\Tracers\IDA_Blasterbolt_Green.p3d";
		effectfly="IDA_BlasterBoltGlow_Green_Fly";
		aiAmmoUsageFlags="128 + 512";
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class VehicleMagazine;
	class FST_ARC_4000Rnd_Heavy_shells: VehicleMagazine
	{
		displayName="30mm Autocannon (HEDP)";
		displayNameShort="BRRRRRRT";
		count=4000;
		model="a3\weapons_f\empty.p3d";
		muzzleImpulseFactor[]={0.0000001,0.022};
		nameSound="mgun";
		ammo="FST_Arc_Heavy_Energy_shell";
	};
};
class CfgWeapons
{
	class CannonCore;
	class Cannon_30mm_Plane_CAS_02_F: CannonCore
	{
	};
	class FST_ARC_Heavy_Chaingun: CannonCore
	{
		displayName="[41st] GAU-41 Avenger";
		canLock=2;
		burst=2;
		ballisticsComputer="4 + 2 + 8";
		magazines[]=
		{
			"FST_ARC_4000Rnd_Heavy_shells",
		};
		reloadTime=0.029999999;
		dispersion=0.0094999997;
		magazineReloadTime=10;
		sounds[]=
		{
			"StandardSound"
		};
		class StandardSound
		{
			begin1[]=
			{
				"A3\Sounds_F\arsenal\weapons_vehicles\gatling_30mm\30mm_01_burst",
				5.6234136,
				1,
				1500,
				{25704,32159}
			};
			soundBegin[]=
			{
				"begin1",
				1
			};
		};
		soundContinuous=1;
		autoFire=1;
	};
};