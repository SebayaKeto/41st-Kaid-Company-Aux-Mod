class CfgPatches
{
	class FST_UTAT
	{
		requiredAddons[]=
		{
			"A3_Armor_F_Beta",
			"3AS_UTAT"
		};
		units[]=
		{
			"FST_UTAT"
		};
		weapons[]={};
		author="Viz";
	};
};
class RCWSOptics;
class Optics_Armored;
class Optics_Gunner_APC_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class DefaultEventHandlers;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
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
class Optics_Commander_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class CfgRecoils
{
	recoil_empty[]={0,0,0};
};
class CfgVehicles
{
	class LandVehicle;
	class Tank: LandVehicle
	{
		class ACE_SelfActions;
		class NewTurret;
		class Sounds;
		class HitPoints;
		class Eventhandlers;
	};
	class Tank_F: Tank
	{
		TFAR_hasIntercom=1;
		TFAR_defaultIntercomSlot = -1;
		class ACE_SelfActions: ACE_SelfActions
		{
			class TFAR_IntercomChannel
			{
				displayName="$STR_tfar_core_Intercom_ACESelfAction_Name";
				condition="true";
				statement="";
				icon="";
				class TFAR_IntercomChannel_disabled
				{
					displayName = "Disabled";
					condition = "_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)], -2]; if (_intercom == -2) then { _vehicle setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)], -1, true]; _intercom = -1 }; _intercom != -1";
					statement = "(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)], -1, true];";
				};
				class TFAR_IntercomChannel_1
				{
					displayName="$STR_tfar_core_Intercom_ACESelfAction_Channel1";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 0";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],0,true];";
				};
				class TFAR_IntercomChannel_2
				{
					displayName="$STR_tfar_core_Intercom_ACESelfAction_Channel2";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 1";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],1,true];";
				};
				class TFAR_IntercomChannel_Misc_1
				{
					displayName="Misc channel 1";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 2";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],2,true];";
				};
				class TFAR_IntercomChannel_Misc_2
				{
					displayName="Misc channel 2";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 3";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],3,true];";
				};
				class TFAR_IntercomChannel_Misc_3
				{
					displayName="Misc channel 3";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 4";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],4,true];";
				};
			};
		};
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class Turrets
				{
					class CommanderOptics;
				};
			};
		};
		class AnimationSources;
		class ViewPilot;
		class CargoTurret;
		class ViewOptics;
		class RCWSOptics;
		class ViewGunner;
		class ViewCargo;
		class HeadLimits;
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitEngine;
			class HitLTrack;
			class HitRTrack;
			class HitFuel;
		};
		class Sounds: Sounds
		{
			class Engine;
			class Movement;
		};
	};
	class Strategic;
	class 3AS_UTAT_Base: Tank_F{};
	class FST_UTAT: 3AS_UTAT_Base
	{
		author="3AS_Studio Adapted by Viz";
		scope=2;
		scopeCurator=2;
		accuracy=1000;
		displayname="[41st] UT-AT";
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		side=1;
		editorPreview="\3AS\3AS_UTAT\3AS_UTAT.jpg";
		model="3AS\3AS_UTAT\model\3AS_UTAT.p3d";
		icon="3AS\3AS_UTAT\data\ui\UTAT_top_ca.paa";
		picture="3AS\3AS_UTAT\data\ui\UTAT_side_ca.paa";
		attenuationEffectType="TankAttenuation";
		hiddenSelections[]=
		{
			"camo",
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_UTAT\data\UTAT_Primary_CO.paa",
			"3AS\3AS_UTAT\data\UTAT_Secondary_CO.paa"
		};
		crew="FST_Trooper_P2_DC15S";
		typicalCargo[]=
		{
			"FST_Trooper_P2_DC15S"
		};
		tas_canBlift=1;
		tas_liftVars="[[[[0,-4.5,-9]]], [0], [0]]";
		maxSpeed=60;
		fuelCapacity=50;
		enginePower=10000;
		cost=25000000;
		armor=400;
		armorStructural=7;
		crewExplosionProtection=0.99989998;
		damageResistance=0.0054700002;
		crewVulnerable=0;
		tf_range=100000;
		tf_isolatedAmount=0.40000001;
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_hasLRradio=1;
		enableRadio=1;
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=3.5;
				material=-1;
				armorComponent="hit_hull";
				name="hit_hull_point";
				visual="zbytek";
				passThrough=1;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.25;
			};
			class HitEngine: HitEngine
			{
				armor=1.5;
				material=-1;
				armorComponent="hit_engine";
				name="hit_engine_point";
				passThrough=0.2;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.33000001;
			};
			class HitLTrack: HitLTrack
			{
				armor=1.25;
				material=-1;
				name="hit_repulsorl_point";
				passThrough=0;
				minimalHit=0.079999998;
				explosionShielding=0.60000002;
				radius=0.30000001;
			};
			class HitRTrack: HitRTrack
			{
				armor=1.25;
				material=-1;
				name="hit_repulsorr_point";
				passThrough=0;
				minimalHit=0.079999998;
				explosionShielding=0.60000002;
				radius=0.30000001;
			};
			class HitFuel: HitFuel
			{
				armor=1.5;
				material=-1;
				armorComponent="hit_fuel";
				name="hit_fuel_point";
				passThrough=0.1;
				minimalHit=0.1;
				explosionShielding=0.60000002;
				radius=0.25;
			};
		};
		class Useraction
		{
			class LowerPeriscope
			{
				displayName="Lower Periscope";
				radius=15;
				position="periscope_action";
				onlyForPlayer=0;
				condition="this animationPhase ""Periscope9"" == 1";
				statement="this animateSource [""Periscope9"",0]";
			};
			class RaisePeriscope: LowerPeriscope
			{
				displayName="Raise Periscope";
				condition="this animationSPhase ""Periscope9"" == 0";
				statement="this animateSource [""Periscope9"",1]";
			};
		};
		class AnimationSources
		{
			class Periscope9
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class recoil_source
			{
				source="reload";
				weapon="FST_Mass_Driver_Cannon";
			};
			class recoil_source2
			{
				source="reload";
				weapon="FST_Mass_Driver_Cannon_UTAT_R";
			};
			class recoil_source3
			{
				source="reload";
				weapon="FST_Mass_Driver_Cannon_UTAT_L";
			};
		};
		class ViewOptics: ViewOptics
		{
			initAngleX=0;
			minAngleX=-30;
			maxAngleX=30;
			initAngleY=0;
			minAngleY=-100;
			maxAngleY=100;
			initFov=0.155;
			minFov=0.034000002;
			maxFov=0.155;
			visionMode[]=
			{
				"Normal",
				"NVG",
				"Ti"
			};
			thermalMode[]={2,3,4};
		};
		class Turrets: Turrets
		{
			class UnderTurret: NewTurret
			{
				body="MainTurret8";
				gun="MainGun8";
				proxyIndex=2;
				usePip=2;
				viewGunnerInExternal=1;
				proxytype="CPDriver";
				gunnername="Commander";
				memoryPointsGetInGunner="getin";
				memoryPointsGetInGunnerDir="getin_dir";
				animationSourceBody="MainTurret8";
				animationSourceGun="MainGun8";
				maxHorizontalRotSpeed=1.8;
				maxVerticalRotSpeed=1.8;
				stabilizedInAxes="StabilizedInAxesBoth";
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_best",
					"db-40",
					1,
					50
				};
				minElev=-30;
				maxElev=0;
				initElev=0;
				minTurn=-30;
				maxTurn=30;
				initTurn=0;
				gunnerAction="UTAT_Commander";
				gunnerInAction="UTAT_Commander";
				forceHideGunner=1;
				outGunnerMayFire=1;
				inGunnerMayFire=1;
				gunnerRightHandAnimName="konec hlavne3";
				gunnerLeftHandAnimName="konec hlavne3";
				soundAttenuationTurret="HeliAttenuationGunner";
				isPersonTurret=0;
				personTurretAction="vehicle_turnout_1";
				memoryPointGun[]=
				{
					"z_gunL_muzzle",
					"z_gunR_muzzle"
				};
				weapons[]=
				{
					"FST_Medium_twin_laser_turret",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"SmokeLauncherMag"
				};
				turretInfoType="RscWeaponRangeZeroing";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex=2;
				memoryPointGunnerOptics="commanderview";
				memoryPointGunnerOutOptics="commanderview";
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
				gunnerOutOpticsModel="";
				gunnerOpticsEffect[]={};
				gunnerHasFlares=1;
				gunnerForceOptics=0;
				commanding=10;
				class ViewGunner
				{
					initAngleX=5;
					minAngleX=-85;
					maxAngleX=85;
					initAngleY=0;
					minAngleY=-150;
					maxAngleY=150;
					initFov=0.69999999;
					minFov=0.41999999;
					maxFov=0.85000002;
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
						initFov=0.155;
						minFov=0.155;
						maxFov=0.155;
						visionMode[]=
						{
							"Normal",
							"NVG",
							"Ti"
						};
						thermalMode[]={0,1};
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
						gunnerOpticsEffect[]={};
					};
					class Narrow: Wide
					{
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
						initFov=0.046999998;
						minFov=0.046999998;
						maxFov=0.046999998;
					};
				};
			};
			class MainCannon: NewTurret
			{
				memoryPointGun="Main_Cannon_Muzzle";
				primary=1;
				gunBeg="Main_Cannon_Barrel";
				gunEnd="Main_Cannon_Muzzle";
				weapons[]=
				{
					"FST_Mass_Driver_Cannon"
				};
				magazines[]=
				{
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue"
				};
				turretInfoType="RscWeaponRangeZeroing";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				selectionFireAnim="zasleh";
				animationSourceBody="Mainturret";
				animationSourceGun="MainGun";
				body="Mainturret";
				gun="MainGun";
				memoryPointsGetInGunner="getin";
				memoryPointsGetInGunnerDir="getin_dir";
				discreteDistanceInitIndex=5;
				memoryPointGunnerOptics="gunnerview";
				gunnerOutOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
				gunnerOutOpticsEffect[]={};
				gunnerOpticsEffect[]={};
				gunnerForceOptics=0;
				visionMode[]=
				{
					"Normal"
				};
				startEngine=0;
				thermalMode[]={};
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
						initFov=0.155;
						minFov=0.155;
						maxFov=0.155;
						visionMode[]=
						{
							"Normal",
							"NVG",
							"Ti"
						};
						thermalMode[]={0,1};
						gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Gunner_F";
						gunnerOpticsEffect[]={};
					};
					class Narrow: Wide
					{
						gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Gunner_F";
						initFov=0.046999998;
						minFov=0.046999998;
						maxFov=0.046999998;
					};
				};
				gunnerAction="UTAT_Gunner";
				forceHideGunner=1;
				outGunnerMayFire=1;
				gunnerInAction="UTAT_Gunner";
				gunnerRightHandAnimName="";
				gunnerLeftHandAnimName="";
				gunnerFireAlsoInInternalCamera=1;
				gunnerOutFireAlsoInInternalCamera=1;
				proxyIndex=1;
				viewGunnerInExternal=0;
				gunnerName="Gunner";
				proxytype="CPGunner";
				isPersonTurret=0;
				usePip=2;
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_best",
					"db-40",
					1,
					50
				};
				minElev=-2.5;
				maxElev=25;
				initElev=0;
				inGunnerMayFire=1;
				class ViewGunner
				{
					initAngleX=0;
					initAngleY=-5;
					minAngleX=-85;
					maxAngleX=85;
					minAngleY=-150;
					maxAngleY=150;
					initFov=0.69999999;
					minFov=0.41999999;
					maxFov=0.85000002;
				};
				class HitPoints
				{
					class HitTurret
					{
						armor=1;
						material=-1;
						name="hit_mainturret_point";
						visual="vez";
						passThrough=0;
						minimalHit=0.02;
						explosionShielding=0.30000001;
						radius=0.25;
					};
					class HitGun
					{
						armor=1;
						material=-1;
						name="hit_maincannon_point";
						visual="";
						passThrough=0;
						minimalHit=0;
						explosionShielding=1;
						radius=0.25;
					};
				};
			};
			class RightCannon: NewTurret
			{
				body="MainTurret2";
				gun="MainGun2";
				proxyIndex=2;
				viewGunnerInExternal=0;
				proxytype="CPGunner";
				gunnername="Right Cannon Operator";
				animationSourceBody="MainTurret2";
				animationSourceGun="MainGun2";
				maxHorizontalRotSpeed=1.8;
				maxVerticalRotSpeed=1.8;
				stabilizedInAxes="StabilizedInAxesBoth";
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_best",
					"db-40",
					1,
					50
				};
				minElev=-15;
				maxElev=20;
				initElev=0;
				minTurn=-10;
				maxTurn=4;
				initTurn=0;
				usePip=2;
				memoryPointsGetInGunner="getin";
				memoryPointsGetInGunnerDir="getin_dir";
				gunnerAction="UTAT_Gunner";
				gunnerInAction="UTAT_Gunner";
				forceHideGunner=1;
				outGunnerMayFire=1;
				inGunnerMayFire=1;
				gunnerRightHandAnimName="konec hlavne3";
				gunnerLeftHandAnimName="konec hlavne3";
				soundAttenuationTurret="HeliAttenuationGunner";
				isPersonTurret=0;
				memoryPointGun="R_Cannon_Muzzle";
				gunbeg="R_Cannon_Chamber";
				gunend="R_Cannon_Muzzle";
				weapons[]=
				{
					"FST_Mass_Driver_Cannon_UTAT_R"
				};
				magazines[]=
				{
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue"
				};
				turretInfoType="RscWeaponRangeZeroing";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex=2;
				memoryPointGunnerOptics="gunnerview_3";
				gunnerForceOptics=0;
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
				gunnerOutOpticsModel="";
				gunnerOpticsEffect[]={};
				gunnerHasFlares=1;
				class ViewOptics: ViewOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.155;
					minFov=0.034000002;
					maxFov=0.155;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={2,3,4};
				};
				gunnerGetInAction="GetInHigh";
				gunnerGetOutAction="GetOutHigh";
				startEngine=0;
				class HitPoints
				{
					class HitTurret
					{
						armor=0.89999998;
						material=-1;
						name="hit_rightturret_point";
						visual="commander_turret";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.5;
						radius=0.25;
					};
					class HitGun
					{
						armor=0.89999998;
						material=-1;
						name="hit_rightgun_point";
						visual="-";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.5;
						radius=0.25;
					};
				};
				selectionFireAnim="zasleh1";
			};
			class LeftCannon: NewTurret
			{
				body="MainTurret3";
				startEngine=0;
				gun="MainGun3";
				proxyIndex=3;
				viewGunnerInExternal=0;
				proxytype="CPGunner";
				gunnername="Left Cannon Operator";
				animationSourceBody="MainTurret3";
				animationSourceGun="MainGun3";
				maxHorizontalRotSpeed=1.8;
				maxVerticalRotSpeed=1.8;
				stabilizedInAxes="StabilizedInAxesBoth";
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_best",
					"db-40",
					1,
					50
				};
				minElev=-15;
				maxElev=15;
				initElev=0;
				minTurn=-4;
				maxTurn=10;
				initTurn=0;
				memoryPointsGetInGunner="getin";
				memoryPointsGetInGunnerDir="getin_dir";
				gunnerAction="UTAT_Gunner";
				gunnerInAction="UTAT_Gunner";
				forceHideGunner=1;
				outGunnerMayFire=1;
				inGunnerMayFire=1;
				gunnerRightHandAnimName="konec hlavne3";
				gunnerLeftHandAnimName="konec hlavne3";
				soundAttenuationTurret="HeliAttenuationGunner";
				isPersonTurret=0;
				personTurretAction="vehicle_turnout_1";
				memoryPointGun="R_Cannon_Muzzle";
				gunbeg="L_Cannon_Chamber";
				gunend="L_Cannon_Muzzle";
				weapons[]=
				{
					"FST_Mass_Driver_Cannon_UTAT_L"
				};
				magazines[]=
				{
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue"
				};
				turretInfoType="RscWeaponRangeZeroing";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex=2;
				memoryPointGunnerOptics="gunnerview_2";
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
				gunnerForceOptics=0;
				gunnerOutOpticsModel="";
				gunnerOpticsEffect[]={};
				gunnerHasFlares=1;
				usePip=2;
				class ViewOptics: ViewOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.155;
					minFov=0.034000002;
					maxFov=0.155;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={2,3,4};
				};
				gunnerGetInAction="GetInHigh";
				gunnerGetOutAction="GetOutHigh";
				class HitPoints
				{
					class HitTurret
					{
						armor=0.89999998;
						material=-1;
						name="hit_leftturret_point";
						visual="commander_turret";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.5;
						radius=0.25;
					};
					class HitGun
					{
						armor=0.89999998;
						material=-1;
						name="hit_leftgun_point";
						visual="Commander_Gun";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.5;
						radius=0.25;
					};
				};
				selectionFireAnim="zasleh1";
			};
			class DorsalTurret_RF: NewTurret
			{
				body="MainTurret6";
				gun="MainGun6";
				proxyIndex=4;
				viewGunnerInExternal=0;
				proxytype="CPGunner";
				gunnername="Dorsal Turret (Left Front)";
				animationSourceBody="MainTurret6";
				animationSourceGun="MainGun6";
				maxHorizontalRotSpeed=1;
				maxVerticalRotSpeed=1;
				stabilizedInAxes="StabilizedInAxesBoth";
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_best",
					"db-40",
					1,
					50
				};
				minElev=-7;
				maxElev=70;
				initElev=0;
				minTurn=-360;
				maxTurn=360;
				initTurn=0;
				usePip=2;
				memoryPointsGetInGunner="getin";
				memoryPointsGetInGunnerDir="getin_dir";
				gunnerAction="UTAT_Gunner";
				gunnerInAction="UTAT_Gunner";
				forceHideGunner=1;
				outGunnerMayFire=1;
				inGunnerMayFire=1;
				gunnerRightHandAnimName="konec hlavne3";
				gunnerLeftHandAnimName="konec hlavne3";
				soundAttenuationTurret="HeliAttenuationGunner";
				isPersonTurret=0;
				personTurretAction="vehicle_turnout_1";
				memoryPointGun="LFG_Muzzle";
				gunbeg="LFG_Chamber";
				gunend="LFG_Muzzle";
				weapons[]=
				{
					"FST_ATTE_Turret"
				};
				magazines[]=
				{
					"FST_thermal_coil_Blue",
					"FST_thermal_coil_Blue",
					"FST_thermal_coil_Blue",
					"FST_thermal_coil_Blue"
				};
				turretInfoType="RscWeaponRangeZeroing";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex=2;
				memoryPointGunnerOptics="gunnerview_6";
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
				gunnerForceOptics=0;
				gunnerOutOpticsModel="";
				gunnerOpticsEffect[]={};
				gunnerHasFlares=1;
				class ViewOptics: RCWSOptics
				{
					visionMode[]=
					{
						"Normal",
						"TI"
					};
				};
				class OpticsIn: Optics_Gunner_APC_01
				{
					class Wide: Wide
					{
					};
					class Medium: Medium
					{
					};
					class Narrow: Narrow
					{
					};
				};
				gunnerGetInAction="GetInHigh";
				gunnerGetOutAction="GetOutHigh";
				startEngine=0;
				class HitPoints
				{
					class HitTurret
					{
						armor=0.5;
						material=-1;
						name="hit_rfturret_point";
						visual="LF_turret";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.40000001;
						radius=0.25;
					};
					class HitGun
					{
						armor=0.5;
						material=-1;
						name="hit_rfgun_point";
						visual="LF_Gun";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.40000001;
						radius=0.25;
					};
				};
				selectionFireAnim="zasleh1";
			};
			class DorsalTurret_RR: DorsalTurret_RF
			{
				body="MainTurret7";
				gun="MainGun7";
				proxyIndex=5;
				viewGunnerInExternal=0;
				proxytype="CPGunner";
				gunnername="Dorsal Turret (Left Rear)";
				weapons[]=
				{
					"FST_ATTE_Turret"
				};
				magazines[]=
				{
					"FST_thermal_coil_Blue",
					"FST_thermal_coil_Blue",
					"FST_thermal_coil_Blue",
					"FST_thermal_coil_Blue"
				};
				animationSourceBody="MainTurret7";
				animationSourceGun="MainGun7";
				personTurretAction="vehicle_turnout_1";
				memoryPointGun="LRG_Muzzle";
				gunbeg="LRG_Chamber";
				gunend="LRG_Muzzle";
				memoryPointGunnerOptics="gunnerview_7";
				class HitPoints: HitPoints
				{
					class HitTurret: HitTurret
					{
						name="hit_lrturret_point";
						visual="LR_turret";
					};
					class HitGun: HitGun
					{
						name="hit_lrgun_point";
						visual="LR_Gun";
					};
				};
			};
			class DorsalTurret_LF: DorsalTurret_RF
			{
				body="MainTurret4";
				gun="MainGun4";
				proxyIndex=6;
				viewGunnerInExternal=0;
				proxytype="CPGunner";
				gunnername="Dorsal Turret (Right Front)";
				animationSourceBody="MainTurret4";
				animationSourceGun="MainGun4";
				memoryPointGun="RFG_Muzzle";
				gunbeg="RFG_Chamber";
				gunend="RFG_Muzzle";
				memoryPointGunnerOptics="gunnerview_4";
				class HitPoints: HitPoints
				{
					class HitTurret: HitTurret
					{
						name="hit_rfturret_point";
						visual="RF_turret";
					};
					class HitGun: HitGun
					{
						name="hit_rfgun_point";
						visual="RF_Gun";
					};
				};
			};
			class DorsalTurret_LR: DorsalTurret_RR
			{
				body="MainTurret5";
				gun="MainGun5";
				proxyIndex=7;
				viewGunnerInExternal=0;
				proxytype="CPGunner";
				gunnername="Dorsal Turret (Right Rear)";
				animationSourceBody="MainTurret5";
				animationSourceGun="MainGun5";
				memoryPointGun="RRG_Muzzle";
				gunbeg="RRG_Chamber";
				gunend="RRG_Muzzle";
				memoryPointGunnerOptics="gunnerview_5";
				class HitPoints: HitPoints
				{
					class HitTurret: HitTurret
					{
						name="hit_rrturret_point";
						visual="RR_turret";
					};
					class HitGun: HitGun
					{
						name="hit_rrgun_point";
						visual="RR_Gun";
					};
				};
			};
		};
		class RenderTargets
		{
			class GunnerCam
			{
				renderTarget="rendertarget0";
				class CameraView1
				{
					pointPosition="gunnerview";
					pointDirection="gunnerview_Dir_1";
					renderQuality=2;
					renderVisionMode=0;
					fov=1;
				};
			};
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3as\3as_utat\data\utat_primary.rvmat",
				"3AS\3AS_UTAT\data\damage\Primary_damage.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat",
				"3as\3as_utat\data\utat_secondary.rvmat",
				"3AS\3AS_UTAT\data\damage\Secondary_damage.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat"
			};
		};
		smokeLauncherGrenadeCount=8;
		smokeLauncherVelocity=14;
		smokeLauncherOnTurret=1;
		smokeLauncherAngle=120;
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
							minRange=5000;
							maxRange=5000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=3000;
							maxRange=3000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						angleRangeHorizontal=360;
						angleRangeVertical=360;
						maxTrackableSpeed=400;
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
							minRange=2000;
							maxRange=2000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=1500;
							maxRange=1500;
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
							minRange=12000;
							maxRange=12000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=6000;
							maxRange=6000;
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
							minRange=8000;
							maxRange=8000;
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
						range[]={800,2000,4000,1600};
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
						range[]={800,2000,4000,1600};
						resource="RscCustomInfoSensors";
					};
				};
			};
		};
		class Eventhandlers: Eventhandlers
		{
			postInit="if (local (_this select 0)) then { [(_this select 0), """", [], false] call BIS_fnc_initVehicle; };";
		};
	};
};
class cfgWeapons
{
	class CannonCore;
	class FST_Mass_Driver_Cannon: CannonCore{};
	class FST_Mass_Driver_Cannon_UTAT_R: FST_Mass_Driver_Cannon
	{
		class GunParticles
		{
			class FirstEffect
			{
				effectName="CannonFired";
				positionName="R_Cannon_Chamber";
				directionName="R_Cannon_Muzzle";
			};
		};
	};
	class FST_Mass_Driver_Cannon_UTAT_L: FST_Mass_Driver_Cannon
	{
		class GunParticles
		{
			class FirstEffect
			{
				effectName="CannonFired";
				positionName="L_Cannon_Chamber";
				directionName="L_Cannon_Muzzle";
			};
		};
	};
};