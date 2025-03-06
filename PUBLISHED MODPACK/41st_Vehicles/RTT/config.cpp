class CfgPatches
{
	class FST_RTT
	{
		requiredAddons[]=
		{
			"A3_Armor_F_Beta",
			"3AS_RTT"
		};
		units[]=
		{
			"FST_RTT",
			"FST_RTT_Wheeled"
		};
		weapons[]={};
	};
};
class DefaultEventHandlers;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
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
					class CommanderOptics;
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
	};
	class APC_Tracked_01_base_F: Tank_F
	{
		class Sounds;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets;
			};
		};
	};
	class 3AS_RTT_Base: Tank_F{};
	class FST_RTT: 3AS_RTT_Base
	{
		author="3AS_Studio Adapted by Viz";
		scope=2;
		scopeCurator=2;
		accuracy=1000;
		displayname="[41st] RTT [WORK IN PROGRESS]";
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		side=1;
		editorPreview="3AS\3AS_rtt\images\3AS_RTT.jpg";
		model="3AS\3AS_rtt\model\rTT.p3d";
		icon="3AS\3AS_RTT\data\ui\RTT_top_ca.paa";
		picture="3as\3AS_RTT\data\ui\RTT_side_ca.paa";
		attenuationEffectType="TankAttenuation";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_rtt\data\rtt\exterior_CO.paa"
		};
		crew="FST_Trooper_P2_DC15S";
		typicalCargo[]=
		{
			"FST_Trooper_P2_DC15S"
		};
		armor=1100;
		armorStructural=6;
		tas_canBlift=1;
		tas_liftVars="[[[[0,-4,-6.5]]], [-0.001], [-0.4]]";
		enginePower=4250;
		maxOmega=160;
		peakTorque=5832;
		maxSpeed=100;
		canFloat=1;
		class Turrets: Turrets
		{
			class CargoTurret_01: NewTurret
			{
				gunnerAction="passenger_inside_5";
				gunnerInAction="passenger_inside_5";
				gunnerGetInAction="GetInLow";
				gunnerGetOutAction="GetOutLow";
				gunnerName="Passenger Gunner (Right Seat 1)";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerCompartments="Compartment1";
				proxyType="CPCargo";
				proxyIndex=14;
				startEngine=0;
				isPersonTurret=1;
				inGunnerMayFire=1;
				LODTurnedIn=1100;
				showAsCargo=1;
				maxElev=15;
				minElev=-35;
				maxTurn=30;
				minTurn=-30;
				isCopilot=0;
				hideWeaponsGunner=0;
				forceHideGunner=1;
				turretFollowFreeLook=0;
				viewGunnerInExternal=1;
				disableSoundAttenuation=1;
				canEject=1;
				commanding=0;
				allowLauncherIn=1;
				class TurnIn
				{
					limitsArrayTop[]=
					{
						{44.883202,-24.2533},
						{44.852001,95}
					};
					limitsArrayBottom[]=
					{
						{-6.1384001,-23.5436},
						{-9.0489998,-13.7683},
						{-23.624901,94.896301}
					};
				};
				class TurnOut
				{
					limitsArrayTop[]=
					{
						{44.883202,-24.2533},
						{44.852001,95}
					};
					limitsArrayBottom[]=
					{
						{-6.1384001,-23.5436},
						{-9.0489998,-13.7683},
						{-23.624901,94.896301}
					};
				};
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerName="Passenger Gunner (Right Seat 2)";
				proxyIndex=13;
			};
			class CargoTurret_03: CargoTurret_02
			{
				gunnerName="Passenger Gunner (Left Seat 1)";
				proxyIndex=11;
			};
			class CargoTurret_04: CargoTurret_03
			{
				gunnerName="Passenger Gunner (Left Seat 2)";
				proxyIndex=12;
			};
		};
		smokeLauncherGrenadeCount=8;
		smokeLauncherVelocity=14;
		smokeLauncherOnTurret=1;
		smokeLauncherAngle=120;
		class ViewOptics: ViewOptics
		{
			visionMode[]=
			{
				"Normal",
				"NVG"
			};
		};
		getInAction="GetInlow";
		getOutAction="GetOutLow";
		cargoGetInAction[]=
		{
			"GetInlow",
			"GetInlow"
		};
		cargoAction[]=
		{
			"RTT_Cargo_Right",
			"RTT_Cargo_Right",
			"RTT_Cargo_Right",
			"RTT_Cargo_Right",
			"RTT_Cargo_Right",
			"RTT_Cargo_Left",
			"RTT_Cargo_Left",
			"RTT_Cargo_Left",
			"RTT_Cargo_Left",
			"RTT_Cargo_Left"
		};
	};
	class Car;
	class Car_F: Car
	{
		class NewTurret;
		class Sounds;
		class HitPoints
		{
			class HitBody;
			class HitEngine;
			class HitFuel;
			class HitHull;
		};
	};
	class Wheeled_APC_F: Car_F
	{
		class ViewOptics;
		class ViewCargo;
		class Sounds: Sounds
		{
			class Engine;
			class Movement;
		};
		class NewTurret;
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewOptics;
				class Turrets
				{
					class CommanderOptics;
				};
			};
		};
	};
	class 3AS_RTT_Wheeled_Base: Wheeled_APC_F{};
	class FST_RTT_Wheeled: 3AS_RTT_Wheeled_Base
	{
		author="3AS_Studio Adapted by Viz";
		scope=2;
		scopeCurator=2;
		accuracy=1000;
		displayname="[41st] RTT Wheeled";
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		side=1;
		editorPreview="3AS\3AS_rtt\images\3AS_RTT.jpg";
		model="3AS\3AS_rtt\model\RTT_APC_Wheeled.p3d";
		icon="3AS\3AS_RTT\data\ui\RTT_top_ca.paa";
		picture="3as\3AS_RTT\data\ui\RTT_side_ca.paa";
		crew="FST_Trooper_P2_DC15S";
		typicalCargo[]=
		{
			"FST_Trooper_P2_DC15S"
		};
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_rtt\data\rtt\exterior_CO.paa"
		};
		attenuationEffectType="TankAttenuation";
		tas_canBlift=1;
		tas_liftVars="[[[[0,-4,-6.5]]], [-0.001], [-0.4]]";
		cost=1500000;
		crewCrashProtection=9.9999997e-005;
		damageResistance=0.02;
		crewVulnerable=1;
		armor=1100;
		armorStructural=6;
		class Turrets: Turrets
		{
			class CargoTurret_01: NewTurret
			{
				gunnerAction="passenger_inside_5";
				gunnerInAction="passenger_inside_5";
				gunnerGetInAction="GetInLow";
				gunnerGetOutAction="GetOutLow";
				gunnerName="Passenger Gunner (Right Seat 1)";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerCompartments="Compartment1";
				proxyType="CPCargo";
				proxyIndex=14;
				startEngine=0;
				isPersonTurret=1;
				inGunnerMayFire=1;
				LODTurnedIn=1100;
				showAsCargo=1;
				maxElev=15;
				minElev=-35;
				maxTurn=30;
				minTurn=-30;
				isCopilot=0;
				hideWeaponsGunner=0;
				forceHideGunner=1;
				turretFollowFreeLook=0;
				viewGunnerInExternal=1;
				disableSoundAttenuation=1;
				canEject=1;
				commanding=0;
				allowLauncherIn=1;
				class TurnIn
				{
					limitsArrayTop[]=
					{
						{44.883202,-24.2533},
						{44.852001,95}
					};
					limitsArrayBottom[]=
					{
						{-6.1384001,-23.5436},
						{-9.0489998,-13.7683},
						{-23.624901,94.896301}
					};
				};
				class TurnOut
				{
					limitsArrayTop[]=
					{
						{44.883202,-24.2533},
						{44.852001,95}
					};
					limitsArrayBottom[]=
					{
						{-6.1384001,-23.5436},
						{-9.0489998,-13.7683},
						{-23.624901,94.896301}
					};
				};
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerName="Passenger Gunner (Right Seat 2)";
				proxyIndex=13;
			};
			class CargoTurret_03: CargoTurret_02
			{
				gunnerName="Passenger Gunner (Left Seat 1)";
				proxyIndex=11;
			};
			class CargoTurret_04: CargoTurret_03
			{
				gunnerName="Passenger Gunner (Left Seat 2)";
				proxyIndex=12;
			};
		};
		smokeLauncherGrenadeCount=8;
		smokeLauncherVelocity=14;
		smokeLauncherOnTurret=1;
		smokeLauncherAngle=120;
		class ViewOptics: ViewOptics
		{
			visionMode[]=
			{
				"Normal",
				"NVG"
			};
		};
		getInAction="GetInlow";
		getOutAction="GetOutLow";
		cargoGetInAction[]=
		{
			"GetInlow",
			"GetInlow"
		};
		cargoAction[]=
		{
			"RTT_Cargo_Right",
			"RTT_Cargo_Right",
			"RTT_Cargo_Right",
			"RTT_Cargo_Right",
			"RTT_Cargo_Right",
			"RTT_Cargo_Left",
			"RTT_Cargo_Left",
			"RTT_Cargo_Left",
			"RTT_Cargo_Left",
			"RTT_Cargo_Left"
		};
	};
};