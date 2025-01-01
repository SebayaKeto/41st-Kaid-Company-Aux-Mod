class CfgPatches
{
	class FST_Nu
    {
		requiredAddons[]=
		{
			"A3_Armor_F_Beta",
			"A3_weapons_F",
			"A3_Data_F",
			"A3_Air_F"
		};
		units[]=
        {
            "FST_Nu_Shuttle",
        };
        weapons[]=
		{
			"FST_SmokeLauncher"
		};
 		magazines[]=
		{
			"FST_SmokeLauncherMag"
		};
		ammo[]=
		{
			"FST_SmokeLauncherAmmo"
		}; 
	};
};
class Optics_Armored;
class Optics_Gunner_APC_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
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
class Extended_init_EventHandlers
{
	class FST_Nu_Shuttle
	{
		class laat_init_eh
		{
			init="(_this) spawn ls_vehicle_fnc_ImpulsorMonitor; [_this select 0,"""",[7,8,9,10]] call ls_vehicle_fnc_laatCargoTurretPhase;";
		};
	};
}; 
class DefaultEventhandlers;
class CfgVehicles
{
	class House;
	class House_F: House
	{
		class DestructionEffects;
	};
	class Air;
	class Helicopter: Air
	{
		class Turrets;
		class HitPoints;
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
	class Helicopter_Base_H: Helicopter_Base_F
	{
		class RotorLibHelicopterProperties;
		class ViewPilot;
		class ViewOptics;
		class Turrets: Turrets
		{
			class CopilotTurret;
		};
		class AnimationSources;
		class Components;
	};
	class 3AS_Nu_Base_F: Helicopter_Base_H
	{
		class AnimationSources;
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitFuel;
			class HitEngine;
			class HitHRotor;
			class HitVRotor;
			class HitAvionics;
		};
		class SimpleObject
		{
			eden=1;
			animate[]=
			{
				
				{
					"damagehide",
					0
				},
				
				{
					"HideSeats",
					0
				},
				
				{
					"wing_fold_r",
					0
				},
				
				{
					"wing_fold_l",
					0
				},
				
				{
					"Front_Ramp",
					0
				},
				
				{
					"Maingun",
					0
				},
				
				{
					"Mainturret",
					0
				},
				
				{
					"Maingun2",
					0
				},
				
				{
					"MainTurret",
					0
				}
			};
			hide[]=
			{
				"zaslehR",
				"zaslehL"
			};
			verticalOffset=2.3859999;
			verticalOffsetWorld=-0.075999998;
		};
	};
	class FST_Nu_Base: 3AS_Nu_Base_F
	{
		_generalmacro="FST_Nu_Attack_S";
		accuracy=5;
		author="Ruby and Gold";
		availableforsupporttypes[]=
		{
			"CAS_Heli",
			"Transport",
			"Drop"
		};
        cost="3e+006";
		crew="FST_Pilot_P1";
		displayname="[41st] Nu Attack Shuttle Base";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		vehicleclass="Helicopter";
		scope=2;
		side=0;
		fuelCapacity=8000;
		dustEffect="";
		waterEffect="";
		ls_impulsor_fuelDrain_1=9.9999997e-005;
		ls_impulsor_fuelDrain_2=9.9999997e-005;
		ls_impulsor_boostSpeed_1=300;
		ls_impulsor_boostSpeed_2=800;
		tas_impulse_break=100;
		model="3as\3AS_Republic_Heli\Nu_Class\model\3AS_NuClass.p3d";
		ls_hasImpulse=1;
		tas_can_impulse=0;
		tas_canBlift=1;
		tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]";
		altFullForce=10000;
		altNoForce=15000;
		maxSpeed=900;
		acceleration=600;
		maxFordingDepth=5;
		incomingMissileDetectionSystem="1 + 2 + 4 + 8 + 16 + 32";
		LockDetectionSystem="1 + 2 + 4 + 8 + 16 + 32";
		getInRadius=5;
		mainBladeRadius=0;
		liftForceCoef=3;
		bodyFrictionCoef=11;
		cyclicAsideForceCoef=5;
		cyclicForwardForceCoef=3;
		backRotorForceCoef=2;
		draconicForceXCoef=11;
		draconicForceYCoef=2;
		draconicForceZCoef=2;
		draconicTorqueXCoef=0.050000001;
		draconicTorqueYCoef=0;
		defaultUserMFDvalues[]={0,1,0,1,0};
		armor=400;
		armorStructural=1;
		tf_range=100000;
		tf_isolatedAmount=0.40000001;
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_hasLRradio=1;
		enableRadio=1;
		ace_fastroping_enabled=1;
		ace_fastroping_ropeOrigins[]=
		{
			{1.5,1,-3.5},
			{1.5,2.5,-3.5},
			{1.5,-1,-3.5},
			{-1.5,1,-3.5},
			{-1.5,2.5,-3.5},
			{-1.5,-1,-3.5}
		};
		ace_fastroping_onCut="ace_fastroping_fnc_onCutCommon";
		ace_fastroping_onPrepare="ace_fastroping_fnc_onPrepareCommon";
		smokeLauncherAngle=360;
		smokeLauncherGrenadeCount=18;
		smokeLauncherVelocity=20;
 		class EventHandlers: DefaultEventhandlers
		{
			fired="_this call (uinamespace getvariable 'BIS_fnc_effectFired');_this execVM '\3AS\3as_Laat\LAATI\scripts\fired_laser.sqf';";
		}; 
		ace_cargo_hasCargo=1;
		ace_cargo_space=1000;
        class ace_cargo
		{
            class cargo
			{
                class Land_CanisterFuel_F
				{
                    type = "Land_CanisterFuel_F";
                    amount = 1;
                };
            };
        };	
		class TransportItems
		{
			class _xx_IDA_Cauterizer
			{
				name="IDA_Cauterizer";
				count=1;
			};
			class _xx_ACE_plasmaIV
			{
				name="ACE_plasmaIV";
				count=2;
			};
			class _xx_FST_Bacta_Tank
			{
				name="FST_Bacta_Tank";
				count=1;
			};
		};
		hiddenSelections[]=
		{
			"camo",
			"camo1",
			"camo2",
			"camo3",
			"camo4",
			"camo5",
			"camo6"
		};
		hiddenSelectionsTextures[]=
		{
        "41st_Vehicles\Nu\Data\FST_NU_HullExterior.paa",
			"41st_Vehicles\Nu\Data\FST_NU_Hullfront.paa",
			"41st_Vehicles\Nu\Data\FST_Nu_Wings.paa",
			"3as\3as_republic_heli\rho_class\data\cockpit_co.paa",
			"41st_Vehicles\Nu\Data\FST_Nu_Cockpit_Interface.paa",
			"41st_Vehicles\Nu\Data\FST_Nu_Interior.paa",
			"3as\3as_republic_heli\rho_class\data\interior_optional_co.paa"
		};
        class HitPoints
		{
			class HitHull
			{
				armor=999;
				convexComponent="hull_hit";
				depends="Total";
				explosionShielding=1;
				material=51;
				name="hull_hit";
				passThrough=1;
				visual="zbytek";
				radius=0.0099999998;
			};
			class HitFuel
			{
				convexcomponent="engine_hit";
				hitpoint="engine_hit";
				name="engine_hit";
				explosionShielding=2;
				radius=0.1;
				visual="";
				passthrough=0.1;
				minimalhit=0.1;
				material=-1;
				armor=4;
			};
			class HitEngine
			{
				armor=1;
				convexComponent="engine_hit";
				explosionShielding=2;
				material=51;
				name="engine_hit";
				hitpoint="engine_hit";
				passThrough=1;
				visual="";
				radius=0.2;
			};
			class HitEngine_1: HitEngine
			{
				convexComponent="engine_hit_1";
				name="engine_hit_1";
				hitpoint="engine_hit_1";
			};
			class HitEngine_2: HitEngine
			{
				convexComponent="engine_hit_2";
				name="engine_hit_2";
				hitpoint="engine_hit_2";
			};
			class HitHRotor
			{
				armor=3;
				convexComponent="main_rotor_hit";
				explosionShielding=2.5;
				material=51;
				name="main_rotor_hit";
				passThrough=0.1;
				visual="";
				radius=0.0099999998;
			};
			class HitVRotor
			{
				armor=3;
				convexComponent="tail_rotor_hit";
				explosionShielding=6;
				material=51;
				name="tail_rotor_hit";
				passThrough=0.30000001;
				visual="";
				radius=0.0099999998;
			};
			class HitAvionics
			{
				armor=10;
				convexComponent="avionics_hit";
				explosionShielding=5;
				material=51;
				name="avionics_hit";
				passThrough=1;
				visual="";
				radius=0.5;
			};
			class HitGlass1
			{
				armor=2;
				name="HitGlass1";
				radius=0.40000001;
				visual="";
				passThrough=1;
				explosionShielding=3;
			};
			class HitGlass2
			{
				armor=2;
				name="HitGlass2";
				radius=0.40000001;
				visual="";
				passThrough=1;
				explosionShielding=3;
			};
			class HitGlass3
			{
				armor=2;
				name="HitGlass3";
				radius=0.40000001;
				visual="";
				passThrough=1;
				explosionShielding=3;
			};
		};
		typicalcargo[]=
		{
			"FST_Pilot_P1"
		};
		weapons[]=
		{
			"FST_30mm_Autocannon_LAAT",
			"FST_Rapture_AGM_Missile",
			"FST_Foehammer_AGM_Missile",
			"FST_Stormfury_AA_Missile",
			"FST_Harrower_HARM_Missile",
			"Laserdesignator_pilotCamera",
			"ls_weapon_CMFlareLauncher",
			"FST_SmokeLauncher"
        };
		magazines[]=
		{
			"Laser_Battery",
			"Laserbatteries",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"FST_thermal_coil",
			"FST_thermal_coil",
			"FST_thermal_coil",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
		};
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
					initFov="(75 / 120)";
					minFov="(75 / 120)";
					maxFov="(75 / 120)";
					directionStabilized=1;
					thermalMode[]={0,1};
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					gunnerOpticsModel="A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
					opticsPPEffects[]=
					{
						"OpticsCHAbera2",
						"OpticsBlur2"
					};
				};
				class Medium: Wide
				{
					opticsDisplayName="MFOV";
					initFov="(14.4 / 120)";
					minFov="(14.4 / 120)";
					maxFov="(14.4 / 120)";
					gunnerOpticsModel="A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
				};
				class Narrow: Wide
				{
					opticsDisplayName="NFOV";
					initFov="(4.8 / 120)";
					minFov="(4.8 / 120)";
					maxFov="(4.8 / 120)";
					gunnerOpticsModel="A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
				};
				showMiniMapInOptics=1;
				showUAVViewInOptics=0;
				showSlingLoadManagerInOptics=0;
			};
			minTurn=-180;
			maxTurn=360;
			initTurn=0;
			minElev=-5;
			maxElev=90;
			initElev=-10;
			maxXRotSpeed=0.30000001;
			maxYRotSpeed=0.30000001;
			pilotOpticsShowCursor=1;
			controllable=1;
			ace_missileguidance_usePilotCameraForTargeting=0;
		};
        class CargoTurret;
		class Turrets: Turrets
		{
			class Copilot: CopilotTurret
			{
				gunBeg="z_gunr_muzzle";
				gunEnd="z_gunr_chamber";
				viewGunnerShadow=0;
				castGunnerShadow=0;
				caneject=0;
				proxyindex=1;
				commanding=-1;
				gunnerforceoptics=0;
				gunnername="CoPilot";
				gunnerinaction="Rho_Gunner";
				gunneraction="Rho_Gunner";
				selectionFireAnim="zaslehR";
				gunnerCompartments="Compartment1";
				gunneropticseffect[]=
				{
					"TankCommanderOptics1",
					"BWTV"
				};
				gunneropticsmodel="\A3\Weapons_F_Beta\Reticle\Heli_Transport_01_Optics_Gunner_F";
				gunnerlefthandanimname="";
				gunnerrighthandanimname="";
				initelev=0;
				initturn=0;
				iscopilot=1;
				maxelev=30;
				maxturn=-5;
				minelev=-30;
				minturn=-40;
				memoryPointGunnerOptics="gunnerview1";
				memorypointsgetingunner="pos_driver";
				memorypointsgetingunnerdir="pos_driver_dir";
				startengine=0;
				animationSourceBody="mainturret";
				animationsourcegun="maingun";
				body="mainturret";
				gun="maingun";
				usepip=2;
				turretinfotype="RscOptics_Heli_Attack_01_gunner";
				weapons[]=
				{
					"FST_30mm_Autocannon_LAAT",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"FST_thermal_coil",
					"FST_thermal_coil",
					"FST_thermal_coil",
					"Laser_Battery"
				};
				class OpticsIn
				{
					class Wide
					{
						gunneropticsmodel="\A3\weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_wide_F";
						initanglex=0;
						initangley=0;
						initfov=0.46599999;
						maxanglex=30;
						maxangley=100;
						maxfov=0.46599999;
						minanglex=-30;
						minangley=-100;
						minfov=0.46599999;
						opticsdisplayname="W";
						thermalmode[]={0,1};
						visionmode[]=
						{
							"Normal",
							"NVG",
							"Ti"
						};
					};
					class Medium: Wide
					{
						gunneropticsmodel="\A3\weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_medium_F";
						initfov=0.093000002;
						maxfov=0.093000002;
						minfov=0.093000002;
						opticsdisplayname="M";
					};
					class Narrow: Wide
					{
						gunneropticsmodel="\A3\weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_narrow_F";
						initfov=0.028999999;
						maxfov=0.028999999;
						minfov=0.028999999;
						opticsdisplayname="N";
					};
				};
				class Hitpoints
				{
					class HitTurret1
					{
						armor=0.80000001;
						material=-1;
						name="gun1";
						passthrough=0.5;
						visual="gun1";
					};
					class HitGun1
					{
						armor=0.40000001;
						material=-1;
						name="gun2";
						passthrough=0.2;
						visual="gun2";
					};
				};	
			};	
            class Copilot2: CopilotTurret
			{
            	gunBeg="z_gunl_muzzle";
				gunEnd="z_gunl_chamber";
				proxyindex=2;
				commanding=-2;
				viewGunnerShadow=0;
				castGunnerShadow=0;
				gunnername="CoPilot 2";
				proxytype="CPGunner";
				gunnerforceoptics=0;
				selectionFireAnim="zaslehL";
				gunnerinaction="Rho_Gunner2";
				gunneraction="Rho_Gunner2";
				gunnerlefthandanimname="";
				gunnerrighthandanimname="";
				gunneropticseffect[]=
				{
					"TankCommanderOptics1",
					"BWTV"
				};
				gunneropticsmodel="\A3\Weapons_F_Beta\Reticle\Heli_Transport_01_Optics_Gunner_F";
				initelev=0;
				initturn=0;
				maxturn=40;
				minturn=5;
				maxelev=30;
				minelev=-30;
				memoryPointGunnerOptics="gunnerview2";
				animationSourceBody="mainturret2";
				animationsourcegun="maingun2";
				body="mainturret2";
				gun="maingun2";
				memorypointsgetingunner="pos_driver";
				memorypointsgetingunnerdir="pos_driver_dir";
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner",
					0.36234099,
					1,
					20
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner_vertical",
					0.36234099,
					1,
					30
				};
				startengine=0;
				animationsourcehatch="";
				primaryGunner=0;
				isCopilot=0;
				memorypointlmissile="Rocket_1";
				memorypointrmissile="Rocket_2";
				memoryPointLRocket="Rocket_1";
				memoryPointRRocket="Rocket_2";
				turretinfotype="RscOptics_Heli_Attack_01_gunner";
				usepip=2;
				weapons[]=
				{
					"FST_30mm_Autocannon_LAAT",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"FST_thermal_coil",
					"FST_thermal_coil",
					"FST_thermal_coil",
					"Laser_Battery"
				};
				class OpticsIn
				{
					class Wide
					{
						gunneropticsmodel="\A3\weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_wide_F";
						initanglex=0;
						initangley=0;
						initfov=0.46599999;
						maxanglex=30;
						maxangley=100;
						maxfov=0.46599999;
						minanglex=-30;
						minangley=-100;
						minfov=0.46599999;
						opticsdisplayname="W";
						thermalmode[]={0,1};
						visionmode[]=
						{
							"Normal",
							"NVG",
							"Ti"
						};
					};
					class Medium: Wide
					{
						gunneropticsmodel="\A3\weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_medium_F";
						initfov=0.093000002;
						maxfov=0.093000002;
						minfov=0.093000002;
						opticsdisplayname="M";
					};
					class Narrow: Wide
					{
						gunneropticsmodel="\A3\weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_narrow_F";
						initfov=0.028999999;
						maxfov=0.028999999;
						minfov=0.028999999;
						opticsdisplayname="N";
					};
				};
				class OpticsOut
				{
					class Monocular
					{
						gunneropticseffect[]={};
						gunneropticsmodel="";
						initanglex=0;
						initangley=0;
						initfov=1.1;
						maxanglex=30;
						maxangley=100;
						maxfov=1.1;
						minanglex=-30;
						minangley=-100;
						minfov=0.133;
						visionmode[]=
						{
							"Normal",
							"NVG"
						};
					};
				};
				class Hitpoints
				{
					class HitTurret1
					{
						armor=0.80000001;
						material=-1;
						name="gun1";
						passthrough=0.5;
						visual="gun1";
					};
					class HitGun1
					{
						armor=0.40000001;
						material=-1;
						name="gun2";
						passthrough=0.2;
						visual="gun2";
					};
				};
			};
		};
	};
	class FST_Nu_Shuttle: FST_Nu_Base
	{
		_generalmacro="FST_Nu_Attack_S";
		accuracy=5;
		author="Ruby and Gold";
		availableforsupporttypes[]=
		{
			"CAS_Heli",
			"Transport",
			"Drop"
		};
		cost="3e+006";
		crew="FST_Pilot_P1";
		displayname="[41st] Nu Attack Shuttle";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		vehicleclass="Helicopter";
		scope=2;
		side=1;
		class EventHandlers: DefaultEventhandlers
		{
			fired="_this call (uinamespace getvariable 'BIS_fnc_effectFired');_this execVM '\3AS\3as_Laat\LAATI\scripts\fired_laser.sqf';";
		}; 
		typicalcargo[]=
		{
			"JLTS_Clone_P2_DC15S"
		};
		hiddenSelections[]=
		{
			"camo",
			"camo1",
			"camo2",
			"camo3",
			"camo4",
			"camo5",
			"camo6"
		};
		editorPreview="3as\3AS_nu\images\3AS_nuclass.jpg";
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\Nu\Data\FST_NU_HullExterior.paa",
			"41st_Vehicles\Nu\Data\FST_NU_Hullfront.paa",
			"41st_Vehicles\Nu\Data\FST_Nu_Wings.paa",
			"3as\3as_republic_heli\rho_class\data\cockpit_co.paa",
			"41st_Vehicles\Nu\Data\FST_Nu_Cockpit_Interface.paa",
			"41st_Vehicles\Nu\Data\FST_Nu_Interior.paa",
			"3as\3as_republic_heli\rho_class\data\interior_optional_co.paa"
		};
		class UserActions
		{
			class rampOpen
			{
				displayName="Cargo Ramp Open";
				position="cargoaction";
				radius=12;
				condition="(this animationSourcePhase 'ramp' ==0 AND (alive this))";
				statement="this animateSource ['ramp',1]";
				onlyforplayer=0;
				role=0;
			};
			class rampClose: rampOpen
			{
				displayName="Cargo Ramp Close";
				position="cargoaction";
				radius=12;
				condition="(this animationSourcePhase 'ramp' ==1 AND (alive this))";
				statement="this animateSource ['ramp',0]";
				onlyforplayer=0;
			};
			class AnimationSources
			{
			};
			class rampfront
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class ramp
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
		};
		class Library
		{
			libtextdesc="";
		}
	};
};
class components
{
	class SensorsManagerComponent
	{
		class Components
		{
		};
		class IRSensorComponent: SensorTemplateIR
		{
		};
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
			maxRange=8000;
			objectDistanceLimitCoef=1;
			viewDistanceLimitCoef=1;
		};
		angleRangeHorizontal=360;
		angleRangeVertical=360;
		maxTrackableSpeed=1000;
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
			maxRange=8000;
			objectDistanceLimitCoef=-1;
			viewDistanceLimitCoef=1;
		};
		class GroundTarget
		{
			minRange=0;
			maxRange=8000;
			objectDistanceLimitCoef=1;
			viewDistanceLimitCoef=1;
		};
		angleRangeHorizontal=360;
		angleRangeVertical=360;
		maxTrackableSpeed=1000;
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
			maxRange=20000;
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
			maxRange=10000;
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
			typeRecognitionDistance=8000;
			angleRangeHorizontal=360;
			angleRangeVertical=360;
			groundNoiseDistanceCoef=-1;
			componentType="ActiveRadarSensorComponent";
			maxGroundNoiseDistance=-1;
			minSpeedThreshold=0;
			maxSpeedThreshold=0;
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
	};
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
class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
{
	defaultDisplay="EmptyDisplay";
	class Components
	{
		class EmptyDisplay
		{
			componentType="EmptyDisplayComponent";
		};
	};	
	class MinimapDisplay
	{
		componentType="MinimapDisplayComponent";
		resource="RscCustomInfoMiniMap";
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
			range[]={4000,6000,8000,12000};
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
			range[]={4000,6000,8000,12000};
			resource="RscCustomInfoSensors";				
		};	
	};	
};	
