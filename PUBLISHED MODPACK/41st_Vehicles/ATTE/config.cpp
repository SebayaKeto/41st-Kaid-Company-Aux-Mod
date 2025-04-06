class CfgPatches
{
	class FST_ATTE
	{
		requiredAddons[]=
		{
			"A3_Armor_F_Beta",
			"3AS_Main",
			"3AS_VehicleWeapons",
			"3AS_APC_Jug",
			"3AS_Animations"
		};
		units[]=
		{
			"FST_ATTE_Base",
			"FST_ATTE_Jorge",
			"FST_ATTE_gwenn",
			"FST_ATTE_Rancor",
			"FST_ATTE_Klanka"
		};
		weapons[]={};
		ammo[]=
		{
		};
		author="Daara Adapted from 3AS";
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
class VehicleSystemsTemplateLeftDriver: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightDriver: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftCommander: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightCommander: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftGunner: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightGunner: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class DefaultEventHandlers;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class CfgVehicles
{
	class Car;
	class Car_F: Car
	{
		class ACE_SelfActions;
		class Sounds;
		class Eventhandlers;
		class HitPoints
		{
			class HitBody;
			class HitEngine;
			class HitFuel;
			class HitHull;
			class HitLFWheel;
			class HitLBWheel;
			class HitLMWheel;
			class HitLF2Wheel;
			class HitRFWheel;
			class HitRBWheel;
			class HitRMWheel;
			class HitRF2Wheel;
		};
	};
	class Wheeled_APC_F: Car_F
	{
		TFAR_hasIntercom=1;
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
					displayName="Disabled";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 0";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],0,true];";
				};
				class TFAR_IntercomChannel_1
				{
					displayName="$STR_tfar_core_Intercom_ACESelfAction_Channel1";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != -1";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-1,true];";
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
		class ViewPilot;
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
				class ViewGunner;
				class Turrets
				{
					class CommanderOptics;
				};
			};
		};
		class AnimationSources;
	};
	class APC_Wheeled_01_base_F: Wheeled_APC_F
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
					};
				};
			};
		};
	};
	class LandVehicle;
	class Tank: LandVehicle
	{
		class NewTurret;
		class Sounds;
		class HitPoints;
		class AnimationSources;
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
		class Components;
		class AnimationSources: AnimationSources
		{
		};
		class ViewPilot;
		class CargoTurret;
		class ViewOptics;
		class RCWSOptics;
		class ViewGunner;
		class ViewCargo;
		class HeadLimits;
		class EventHandlers;
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
	class Wreck_Base_F;
	class FST_ATTE_Base: APC_Wheeled_01_base_F
	{
		destrType="DestructWreck";
		attenuationEffectType="TankAttenuation";
		soundGetIn[]=
		{
			"A3\sounds_f\vehicles\armor\noises\get_in_out",
			0.56234097,
			1
		};
		soundGetOut[]=
		{
			"A3\sounds_f\vehicles\armor\noises\get_in_out",
			0.56234097,
			1,
			20
		};
		soundDammage[]=
		{
			"",
			0.56234097,
			1
		};
		soundEngineOnInt[]=
		{
			"3AS\3as_ATTE\Sounds\attestart.ogg",
			2,
			1
		};
		soundEngineOnExt[]=
		{
			"3AS\3as_ATTE\Sounds\attestart.ogg",
			4,
			1,
			200
		};
		soundEngineOffInt[]=
		{
			"a3\sounds_f\vehicles\armor\apc\apc1\int_engine_stop.wss",
			2,
			1
		};
		soundEngineOffExt[]=
		{
			"a3\sounds_f\vehicles\armor\apc\apc1\int_engine_stop.wss",
			4,
			1,
			200
		};
		buildCrash0[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_08",
			1,
			1,
			200
		};
		buildCrash1[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_09",
			1,
			1,
			200
		};
		buildCrash2[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_10",
			1,
			1,
			200
		};
		buildCrash3[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_11",
			1,
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
			"A3\sounds_f\Vehicles\crashes\crash_08",
			1,
			1,
			200
		};
		WoodCrash1[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_09",
			1,
			1,
			200
		};
		WoodCrash2[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_10",
			1,
			1,
			200
		};
		WoodCrash3[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_11",
			1,
			1,
			200
		};
		WoodCrash4[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_01",
			1,
			1,
			200
		};
		WoodCrash5[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_08",
			1,
			1,
			200
		};
		soundWoodCrash[]=
		{
			"woodCrash0",
			0.16599999,
			"woodCrash1",
			0.16599999,
			"woodCrash2",
			0.16599999,
			"woodCrash3",
			0.16599999,
			"woodCrash4",
			0.16599999,
			"woodCrash5",
			0.16599999
		};
		ArmorCrash0[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_08",
			1,
			1,
			200
		};
		ArmorCrash1[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_09",
			1,
			1,
			200
		};
		ArmorCrash2[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_10",
			1,
			1,
			200
		};
		ArmorCrash3[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_11",
			1,
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
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1,
					1,
					200
				};
				frequency="0.95 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class Engine
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1,
					1,
					240
				};
				frequency="0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_ext
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1,
					1,
					280
				};
				frequency="0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_ext
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1,
					1,
					320
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_ext
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1,
					1,
					360
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_ext
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1,
					1,
					400
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_ext
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1,
					1,
					440
				};
				frequency="0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume="engineOn*camPos*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class IdleThrust
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1,
					1,
					200
				};
				frequency="0.8 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class EngineThrust
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\attewalktest1.ogg",
					2,
					1,
					400
				};
				frequency="0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_Thrust_ext
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\attewalktest1.ogg",
					2,
					1,
					550
				};
				frequency="0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_Thrust_ext
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\attewalktest1.ogg",
					2,
					1,
					650
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_Thrust_ext
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\attewalktest1.ogg",
					2,
					1,
					750
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_Thrust_ext
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\attewalktest1.ogg",
					2,
					1,
					850
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_Thrust_ext
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\attewalktest1.ogg",
					2,
					1,
					1000
				};
				frequency="0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class Idle_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					2,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class Engine_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1.41589,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1.58866,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1.7825,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					2,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					2.24404,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					2.5178499,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class IdleThrust_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					2.5178499,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class EngineThrust_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\attewalktest1.ogg",
					1.58866,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_Thrust_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\attewalktest1.ogg",
					1.7825,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_Thrust_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\attewalktest1.ogg",
					1.7825,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_Thrust_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\attewalktest1.ogg",
					2,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_Thrust_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\attewalktest1.ogg",
					2.24404,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_Thrust_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\attewalktest1.ogg",
					2.5178499,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class NoiseInt
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					0.50118703,
					1
				};
				frequency="1";
				volume="(1-camPos)*(angVelocity max 0.04)*(speed factor[4, 15])";
			};
			class NoiseExt
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					0.89125103,
					1,
					50
				};
				frequency="1";
				volume="camPos*(angVelocity max 0.04)*(speed factor[4, 15])";
			};
			class ThreadsOutH0
			{
				sound[]=
				{
					"",
					0.39810699,
					1,
					140
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsOutH1
			{
				sound[]=
				{
					"",
					0.446684,
					1,
					160
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsOutH2
			{
				sound[]=
				{
					"",
					0.50118703,
					1,
					180
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsOutH3
			{
				sound[]=
				{
					"",
					0.56234097,
					1,
					200
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsOutH4
			{
				sound[]=
				{
					"",
					0.56234097,
					1,
					220
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class ThreadsOutS0
			{
				sound[]=
				{
					"",
					0.316228,
					1,
					120
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsOutS1
			{
				sound[]=
				{
					"",
					0.35481301,
					1,
					140
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsOutS2
			{
				sound[]=
				{
					"",
					0.39810699,
					1,
					160
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsOutS3
			{
				sound[]=
				{
					"",
					0.446684,
					1,
					180
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsOutS4
			{
				sound[]=
				{
					"",
					0.50118703,
					1,
					200
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class ThreadsInH0
			{
				sound[]=
				{
					"",
					0.25118899,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsInH1
			{
				sound[]=
				{
					"",
					0.281838,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsInH2
			{
				sound[]=
				{
					"",
					0.316228,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsInH3
			{
				sound[]=
				{
					"",
					0.35481301,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsInH4
			{
				sound[]=
				{
					"",
					0.39810699,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class ThreadsInS0
			{
				sound[]=
				{
					"",
					0.316228,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsInS1
			{
				sound[]=
				{
					"",
					0.316228,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsInS2
			{
				sound[]=
				{
					"",
					0.35481301,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsInS3
			{
				sound[]=
				{
					"",
					0.35481301,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsInS4
			{
				sound[]=
				{
					"",
					0.39810699,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
		};
		simulation="carx";
		fuelCapacity=80;
		brakeIdleSpeed=1.78;
		maxSpeed=45;
		normalSpeedForwardCoef=0.85000002;
		antiRollbarForceCoef=24;
		antiRollbarForceLimit=30;
		antiRollbarSpeedMin=15;
		antiRollbarSpeedMax=70;
		enginePower=13500;
		maxOmega=100;
		minOmega=50;
		idleRpm=800;
		redRpm=6000;
		peakTorque=300000;
		torqueCurve[]=
		{
			{0,1},
			{0.33000001,1},
			{1,0.80000001}
		};
		thrustDelay=0.0099999998;
		engineMOI=12;
		dampingRateFullThrottle=0.5;
		dampingRateZeroThrottleClutchEngaged=7500;
		dampingRateZeroThrottleClutchDisengaged=7500;
		maxFordingDepth=5;
		canFloat=0;
		waterPPInVehicle=0;
		waterResistanceCoef=0.07;
		waterLeakiness=25;
		waterSpeedFactor=0.5;
		waterAngularDampingCoef=5;
		waterLinearDampingCoefY=2;
		waterLinearDampingCoefX=0.5;
		waterResistance=1;
		clutchStrength=275;
		latency=0.1;
		switchTime=0;
		changeGearType="rpmratio";
		changeGearOmegaRatios[]={1,0.33333334,0.33333334,0,0.99333334,0.33333334,0.98333335,0.69999999,0.98333335,0.73333335,0.98333335,0.73333335};
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-0.25,
				"N",
				0,
				"D1",
				7,
				"D2",
				5.75,
				"D3",
				4.5,
				"D4",
				3,
				"D5",
				2.5,
				"D6",
				1.75,
				"D7",
				1
			};
			transmissionRatios[]=
			{
				"High",
				2.8499999
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
		};
		damperSize=0.2;
		damperForce=1;
		damperDamping=0.0099999998;
		dampersBumpCoef=6;
		differentialType="all_limited";
		frontRearSplit=0.5;
		frontBias=1.3;
		rearBias=1.3;
		centreBias=2;
		numberPhysicalWheels=20;
		class Wheels
		{
			class L1
			{
				boneName="wheel_1_1_damper";
				steering=1;
				side="left";
				center="wheel_1_1_axis";
				boundary="wheel_1_1_bound";
				suspForceAppPointOffset="wheel_1_1_axis";
				tireForceAppPointOffset="wheel_1_1_axis";
				damping=35;
				weight=150;
				mass=150;
				moi=3000;
				latStiffX=25;
				latStiffY=1800;
				longitudinalStiffnessPerUnitGravity=100000;
				maxBrakeTorque=80000;
				sprungMass=2500;
				springStrength=122500;
				springDamperRate=28000;
				dampingRate=150;
				dampingRateInAir=8000;
				dampingRateDamaged=10;
				dampingRateDestroyed=10000;
				maxDroop=0.5;
				maxCompression=0.5;
				frictionVsSlipGraph[]=
				{
					{0,1},
					{0.5,1},
					{1,1}
				};
			};
			class FRL1: L1
			{
				steering=0;
				boneName="FrontRightLeg1";
				center="wheel_2_4_axis";
				boundary="wheel_2_4_bound";
				suspForceAppPointOffset="wheel_2_4_axis";
				tireForceAppPointOffset="wheel_2_4_axis";
				side="right";
				weight=150;
				mass=150;
			};
			class FLL1: L1
			{
				boneName="FrontLeftLeg1";
				steering=0;
				center="wheel_1_4_axis";
				boundary="wheel_1_4_bound";
				maxHandBrakeTorque=40000;
				suspForceAppPointOffset="wheel_1_4_axis";
				tireForceAppPointOffset="wheel_1_4_axis";
			};
			class FLL2: FLL1
			{
				boneName="FrontLeftLeg2";
			};
			class FLL3: FLL1
			{
				boneName="FrontLeftLeg3";
			};
			class BLL1: FLL1
			{
				boneName="BackLeftLeg1";
			};
			class BLL2: FLL1
			{
				boneName="BackLeftLeg2";
			};
			class BLL3: FLL1
			{
				boneName="BackLeftLeg3";
			};
			class ML0: FLL1
			{
				boneName="MiddleLeftLeg0";
			};
			class ML1: FLL1
			{
				boneName="MiddleLeftLeg1";
			};
			class ML2: FLL1
			{
				boneName="MiddleLeftLeg2";
			};
			class MR0: FLL1
			{
				boneName="MiddleRightLeg0";
				steering=0;
			};
			class MR1: MR0
			{
				boneName="MiddleRightLeg1";
			};
			class MR2: MR0
			{
				boneName="MiddleRightLeg2";
			};
			class BRL1: FRL1
			{
				boneName="BackRightLeg1";
			};
			class BRL2: BRL1
			{
				boneName="BackRightLeg2";
			};
			class BRL3: BRL1
			{
				boneName="BackRightLeg3";
			};
			class FRL2: BRL1
			{
				boneName="FrontRightLeg2";
			};
			class FRL3: BRL1
			{
				boneName="FrontRightLeg3";
			};
			class T1: BRL1
			{
				boneName="TorsoBody";
				steering=1;
				side="Right";
				center="wheel_2_1_axis";
				boundary="wheel_2_1_bound";
				suspForceAppPointOffset="wheel_2_1_axis";
				tireForceAppPointOffset="wheel_2_1_axis";
			};
		};
		editorSubcategory="FST_Ground_Vehicle";
		editorPreview="\3AS\3AS_ATAP\3AS_ATAP_base.jpg";
		scope=2;
		scopeCurator=2;
		displayname="[41st] AT-TE Heavy Walker";
		faction="FST_Faction";
		side=1;
		crew="FST_Trooper_P2_DC15S";
		getInAction="GetInLow";
		getOutAction="GetOutLow";
		icon="3AS\3AS_ATTE\data\UI\ATTE_top_ca.paa";
		picture="3AS\3AS_ATTE\data\UI\ATTE_side_ca.paa";
		cargoGetInAction[]=
		{
			"GetInLow"
		};
		cargoGetOutAction[]=
		{
			"GetOutLow"
		};
		memoryPointDriverOptics[]=
		{
			"driverview"
		};
		driverOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
		driveraction="UTAT_Driver";
		driverInAction="UTAT_Driver";
		forcehidedriver=1;
		LODDriverTurnedIn=1100;
		driverForceOptics=0;
		ejectDeadDriver=1;
		driverCanSee="4+8+2+32+16";
		gunnerCanSee="4+2+8+32+16";
		dustFrontLeftPos="FL";
		dustFrontRightPos="FR";
		dustBackLeftPos="BL";
		dustBackRightPos="BR";
		tas_canBlift=1;
		tas_liftVars="[[[[0,-4.5,-9]]], [0], [0]]";
		armor=650;
		armorStructural=6;
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=3;
				material=-1;
				armorComponent="hit_hull";
				name="hit_hull_point";
				visual="zbytek";
				passThrough=1;
				minimalHit=0.2;
				explosionShielding=2;
				radius=0.75;
			};
			class HitEngine: HitEngine
			{
				armor=2.25;
				material=-1;
				armorComponent="hit_engine";
				name="hit_engine_point";
				passThrough=0.2;
				minimalHit=0.1;
				explosionShielding=0.69999999;
				radius=0.5;
			};
			class HitFuel: HitFuel
			{
				armor=2.25;
				material=-1;
				armorComponent="hit_fuel";
				name="hit_fuel_point";
				passThrough=0.1;
				minimalHit=0.1;
				explosionShielding=0.75;
				radius=0.5;
			};
			class HitLTrack
			{
				armor=2;
				material=-1;
				name="hit_track_left_point";
				passThrough=0;
				minimalHit=0.079999998;
				explosionShielding=1.4400001;
				radius=0.5;
			};
			class HitRTrack
			{
				armor=2;
				material=-1;
				name="hit_track_right_point";
				passThrough=0;
				minimalHit=0.079999998;
				explosionShielding=1.4400001;
				radius=0.5;
			};
			class HitGlass1
			{
				armor=3;
				name="Hit_Glass1_point";
				radius=0.40000001;
				visual="";
				passThrough=0.1;
				explosionShielding=3;
			};
			class HitGlass2
			{
				armor=3;
				name="Hit_Glass2_point";
				radius=0.40000001;
				visual="";
				passThrough=0.1;
				explosionShielding=3;
			};
			class HitGlass3
			{
				armor=3;
				name="Hit_Glass3_point";
				radius=0.40000001;
				visual="";
				passThrough=0.1;
				explosionShielding=3;
			};
		};
		forceDriveroptics=0;
		extCameraPosition[]={0,6,-30};
		class Eventhandlers: Eventhandlers
		{
			postInit="if (local (_this select 0)) then { [(_this select 0), """", [], false] call BIS_fnc_initVehicle; };";
		};
		autocenter=0;
		availableForSupportTypes[]=
		{
			"Artillery"
		};
		model="3AS\3AS_ATTE\model\3AS_ATTE.p3d";
		memoryPointsGetInDriver="pos_gunner";
		memoryPointsGetInDriverDir="pos_gunner_dir";
		memoryPointsGetInCargo="pos_gunner";
		memoryPointsGetInCargoDir="pos_gunner_dir";
		castDriverShadow=0;
		hideWeaponsCargo=1;
		proxyIndex=1;
		cargoAction[]=
		{
			"passenger_generic02_foldhands",
			"passenger_apc_narrow_generic03",
			"passenger_apc_generic02",
			"passenger_apc_narrow_generic01",
			"passenger_apc_generic04",
			"passenger_apc_narrow_generic02",
			"passenger_generic01_leanright",
			"passenger_generic01_leanleft",
			"RTT_Cargo_Right",
			"RTT_Cargo_Right",
			"RTT_Cargo_Left",
			"RTT_Cargo_Left",
			"passenger_generic02_foldhands",
			"passenger_apc_narrow_generic03",
			"RTT_Cargo_Right",
			"RTT_Cargo_Left",
			"passenger_apc_generic02",
			"passenger_apc_narrow_generic01",
			"passenger_apc_generic04",
			"passenger_apc_narrow_generic02",
			"passenger_generic01_leanright",
			"passenger_generic01_leanleft",
			"UTAT_Gunner",
			"UTAT_Gunner",
			"UTAT_Gunner",
			"UTAT_Gunner"
		};
		transportSoldier=26;
		cargoProxyIndexes[]={1};
		getInProxyOrder[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
		hiddenselections[]=
		{
			"camo1",
			"camo2",
			"camo3",
			"camo4",
			"camo5",
			"camo11"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\ATTE\Data\Shell\FST_ATTE_Shell_Base_co.paa",
			"3as\3AS_ATTE\data\Textures\3AS_ATTE_Cockpit_co.paa",
			"41st_Vehicles\ATTE\Data\Detail\FST_ATTE_Detail_Base_co.paa",
			"41st_Vehicles\ATTE\Data\Legs\FST_ATTE_Legs_Base_co.paa",
			"3as\3AS_ATTE\data\Textures\3AS_ATTE_Glass_ca.paa",
			"3as\3as_atte\data\textures\3as_atte_armor_co.paa"
		};
		proxytype="CPDriver";
		viewDriverinExternal=1;
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3as\3AS_ATTE\data\Textures\Shell.rvmat",
				"3as\3AS_ATTE\data\Textures\damage\ATTE_shell_damage.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat",
				"3as\3AS_ATTE\data\Textures\Cockpit.rvmat",
				"3as\3AS_ATTE\data\Textures\damage\ATTE_Cockpit_damage.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat",
				"3as\3AS_ATTE\data\Textures\Detail.rvmat",
				"3as\3AS_ATTE\data\Textures\damage\ATTE_Detail_damage.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat",
				"3as\3AS_ATTE\data\Textures\Legs.rvmat",
				"3as\3AS_ATTE\data\Textures\damage\ATTE_Legs_damage.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat",
				"3as\3AS_ATTE\data\Textures\Glass.rvmat",
				"3as\3AS_ATTE\data\Textures\damage\ATTE_Glass_damage.rvmat",
				"3as\3AS_ATTE\data\Textures\damage\ATTE_Glass_damage.rvmat"
			};
		};
		class ViewPilot: ViewPilot
		{
			initAngleY=0;
			initAngleX=-5;
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
					fov=0.20345201;
					turret[]={0};
				};
				BBoxes[]=
				{
					"PIP_MAINGUN_TL",
					"PIP_MAINGUN_TR",
					"PIP_MAINGUN_BL",
					"PIP_MAINGUN_BR"
				};
			};
			class CommanderCam
			{
				renderTarget="rendertarget2";
				class CameraView1
				{
					pointPosition="commanderview";
					pointDirection="commanderview_dir";
					renderQuality=2;
					renderVisionMode=0;
					fov=0.20345201;
					turret[]={1};
				};
				BBoxes[]=
				{
					"PIP_COMMANDERGUN_TL",
					"PIP_COMMANDERGUN_TR",
					"PIP_COMMANDERGUN_BL",
					"PIP_COMMANDERGUN_BR"
				};
			};
			class PIPRearGunner
			{
				renderTarget="rendertarget1";
				class CameraView1
				{
					pointPosition="commanderview2";
					pointDirection="commanderview2_dir";
					renderQuality=2;
					renderVisionMode=0;
					turret[]={2};
					fov=0.20345201;
				};
				BBoxes[]=
				{
					"PIP_GUN_TL",
					"PIP_GUN_TR",
					"PIP_GUN_BL",
					"PIP_GUN_BR"
				};
			};
		};
		class DestructionEffects
		{
			class Light1
			{
				simulation="light";
				type="ObjectDestructionLightSmall";
				position="destructionEffect1";
				intensity=0.001;
				interval=1;
				lifeTime=3;
				enabled="distToWater";
			};
			class Sound
			{
				simulation="sound";
				position="destructionEffect1";
				intensity=0.5;
				interval=1;
				lifeTime=1;
				type="Fire";
			};
			class Fire1
			{
				simulation="particles";
				type="ObjectDestructionFire1Tiny";
				position="destructionEffect1";
				intensity=0.25;
				interval=1;
				lifeTime=3;
			};
			class Refract1
			{
				simulation="particles";
				type="SmallFireFRefract";
				position="destructionEffect1";
				intensity=0.5;
				interval=1;
				lifeTime=3;
			};
		};
		class AnimationSources: AnimationSources
		{
			class Proxy
			{
				source="user";
				animPeriod=0.001;
				initPhase=1;
			};
			class Proxy1
			{
				source="user";
				animPeriod=0.001;
				initPhase=0;
			};
			class ShowATTEIntBackPassenger
			{
				displayName="Hide Interior Rear (Passenger)";
				author="$STR_A3_Bohemia_Interactive";
				source="proxy1";
				lockCargoAnimationPhase=1;
				lockCargo[]={12,13,14,15,16,17,18,19,20,21};
				initPhase=0;
				mass=-50;
			};
			class ShowATTEIntCommand
			{
				displayName="Hide Interior 1 (Command)";
				author="$STR_A3_Bohemia_Interactive";
				source="Proxy";
				lockCargoAnimationPhase=1;
				lockCargo[]={22,23,24,25};
				initPhase=1;
				forceAnimatePhase=0;
				forceAnimate[]=
				{
					"ShowATTEIntPassenger",
					1
				};
				onPhaseChanged="this lockCargo [22,false];this lockCargo [23,false];this lockCargo [24,false];this lockCargo [25,false];";
				mass=-50;
			};
			class ShowATTEIntPassenger
			{
				displayName="Hide Interior 1 (Passenger)";
				author="$STR_A3_Bohemia_Interactive";
				source="proxy1";
				lockCargoAnimationPhase=1;
				lockCargo[]={0,1,2,3,4,5,6,7,8,9,10,11};
				initPhase=0;
				forceAnimatePhase=0;
				forceAnimate[]=
				{
					"ShowATTEIntCommand",
					1
				};
				mass=-50;
			};
			class ShowATTERebelMod
			{
				displayName="Hide Rebel Modifications";
				author="$STR_A3_Bohemia_Interactive";
				source="Proxy";
				animPeriod=0.0099999998;
				initPhase=1;
				forceAnimatePhase=1;
				forceAnimate[]=
				{
					"ShowATTERebelMod2",
					1
				};
				forceAnimate2[]=
				{
					"ShowATTERebelMod2",
					0
				};
				mass=-50;
			};
			class ShowATTERebelMod2
			{
				source="Proxy";
				animPeriod=0.001;
				initPhase=1;
			};
			class ShowATTENuts
			{
				displayName="Hide Le Nuts";
				author="$STR_A3_Bohemia_Interactive";
				source="Proxy";
				animPeriod=0.0099999998;
				initPhase=0;
				scopeCurator=2;
				mass=-50;
			};
			class Muzzle_flash
			{
				source="ammorandom";
				weapon="3AS_ATTE_Turret";
			};
			class Muzzle_flash2
			{
				source="ammorandom";
				weapon="3AS_ATTE_Turret";
			};
			class recoil_source
			{
				source="reload";
				weapon="3AS_Mass_Driver_Cannon";
			};
		};
		animationList[]=
		{
			"ShowATTENuts",
			1,
			"ShowATTEIntPassenger",
			0,
			"ShowATTEIntBackPassenger",
			0,
			"ShowATTEIntCommand",
			1,
			"ShowATTERebelMod",
			1
		};
		class UserActions
		{
		};
		class Reflectors
		{
			class Right
			{
				color[]={7000,7500,10000};
				ambient[]={70,75,100};
				intensity=50;
				size=1;
				innerAngle=15;
				outerAngle=65;
				coneFadeCoef=10;
				position="Light_R_pos";
				direction="Light_R_dir";
				hitpoint="Light_R_hitpoint";
				selection="Light_R";
				useFlare=1;
				flareSize=10;
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
			class Left: Right
			{
				position="Light_L_pos";
				direction="Light_L_dir";
				hitpoint="Light_L_hitpoint";
				selection="Light_L";
			};
		};
		aggregateReflectors[]=
		{
			
			{
				"Left"
			},
			
			{
				"Right"
			}
		};
		class MFD
		{
			class MFD_Rear_Gunner_Display_Damage
			{
				topLeft="mfd_gun_TL";
				topRight="mfd_gun_TR";
				bottomLeft="mfd_gun_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={2};
				font="PuristaBold";
				class Bones
				{
				};
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Draw
				{
					color[]={1,1,1};
					alpha=1;
					condition="1";
					class Damage_Hull
					{
						type="text";
						source="static";
						text="HULL";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.039999999,0.18000001},
							1
						};
						right[]=
						{
							{0.064999998,0.18000001},
							1
						};
						down[]=
						{
							{0.039999999,0.44},
							1
						};
					};
					class Damage_Engine
					{
						type="text";
						source="static";
						text="ENG";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.11,0.18000001},
							1
						};
						right[]=
						{
							{0.13500001,0.18000001},
							1
						};
						down[]=
						{
							{0.11,0.44},
							1
						};
					};
					class Damage_Fuel
					{
						type="text";
						source="static";
						text="FUEL";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.178,0.18000001},
							1
						};
						right[]=
						{
							{0.20299999,0.18000001},
							1
						};
						down[]=
						{
							{0.178,0.44},
							1
						};
					};
					class Damage_Wheels
					{
						type="text";
						source="static";
						text="TRKS";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.039999999,0.55000001},
							1
						};
						right[]=
						{
							{0.064999998,0.55000001},
							1
						};
						down[]=
						{
							{0.039999999,0.81},
							1
						};
					};
					class Damage_Gun
					{
						type="text";
						source="static";
						text="GUN";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.11,0.55000001},
							1
						};
						right[]=
						{
							{0.13500001,0.55000001},
							1
						};
						down[]=
						{
							{0.11,0.81},
							1
						};
					};
					class Damage_Turret
					{
						type="text";
						source="static";
						text="TRT";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.178,0.55000001},
							1
						};
						right[]=
						{
							{0.20299999,0.55000001},
							1
						};
						down[]=
						{
							{0.178,0.81},
							1
						};
					};
				};
			};
			class MFD_Rear_Gunner_Display
			{
				topLeft="mfd_gun_TL";
				topRight="mfd_gun_TR";
				bottomLeft="mfd_gun_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={2};
				font="PuristaBold";
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Bones
				{
					class FuelScale
					{
						type="linear";
						source="fuel";
						sourceIndex=1;
						sourceScale=1;
						min=0;
						max=1;
						minPos[]={0,0};
						maxPos[]={-0.090000004,0};
					};
				};
				class Draw
				{
					color[]={1,1,1};
					alpha=1;
					condition="1";
					class Main_Gun
					{
						type="text";
						source="static";
						text="MAIN GUN";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.273,0.18000001},
							1
						};
						right[]=
						{
							{0.29800001,0.18000001},
							1
						};
						down[]=
						{
							{0.273,0.44},
							1
						};
					};
					class Main_Gun_Ammo_count
					{
						type="text";
						source="ammo";
						sourceScale=1;
						sourceLength=2;
						sourceIndex=0;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.273,0.55000001},
							1
						};
						right[]=
						{
							{0.29800001,0.55000001},
							1
						};
						down[]=
						{
							{0.273,0.81},
							1
						};
					};
					class Main_Gun_Ammo_Type_text
					{
						type="text";
						source="static";
						text="TYPE";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.38499999,0.18000001},
							1
						};
						right[]=
						{
							{0.41,0.18000001},
							1
						};
						down[]=
						{
							{0.38499999,0.44},
							1
						};
					};
					class Main_Gun_Ammo_Type
					{
						type="text";
						source="ammoFormat";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.38499999,0.55000001},
							1
						};
						right[]=
						{
							{0.41,0.55000001},
							1
						};
						down[]=
						{
							{0.38499999,0.81},
							1
						};
					};
					class Azimuth
					{
						type="text";
						source="static";
						text="GUN AZIM";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.60500002,0.18000001},
							1
						};
						right[]=
						{
							{0.63,0.18000001},
							1
						};
						down[]=
						{
							{0.60500002,0.44},
							1
						};
					};
					class Smoke
					{
						type="text";
						source="static";
						text="SMOKE";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.71700001,0.18000001},
							1
						};
						right[]=
						{
							{0.74199998,0.18000001},
							1
						};
						down[]=
						{
							{0.71700001,0.44},
							1
						};
					};
					class Fuel_background_white
					{
						color[]={0.2,0.2,0.2};
						alpha=0.1;
						condition="1";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										{0.87699997,0.69999999},
										1
									},
									
									{
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel_background_green
					{
						color[]={0,0.69999999,0};
						condition="fuel>=0.5";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel_background_yellow
					{
						color[]={0.89999998,0.69999999,0};
						condition="fuel<0.5";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel_background_red
					{
						color[]={0.69999999,0,0};
						condition="fuel<0.3";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel
					{
						type="text";
						source="static";
						text="FUEL";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.82999998,0.18000001},
							1
						};
						right[]=
						{
							{0.85500002,0.18000001},
							1
						};
						down[]=
						{
							{0.82999998,0.44},
							1
						};
					};
					class Fuel_number
					{
						type="text";
						source="fuel";
						sourceScale=100;
						sourceLength=1;
						scale=1;
						align="left";
						refreshRate=0.1;
						pos[]=
						{
							{0.83499998,0.40000001},
							1
						};
						right[]=
						{
							{0.86000001,0.40000001},
							1
						};
						down[]=
						{
							{0.83499998,0.66000003},
							1
						};
					};
					class Fuel_percent_sign
					{
						type="text";
						source="static";
						text="%";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="right";
						refreshRate=0.1;
						pos[]=
						{
							{0.84500003,0.40000001},
							1
						};
						right[]=
						{
							{0.87,0.40000001},
							1
						};
						down[]=
						{
							{0.84500003,0.66000003},
							1
						};
					};
				};
			};
			class MFD_Rear_Gunner_OnScreen
			{
				topLeft="PIP_GUN_TL";
				topRight="PIP_GUN_TR";
				bottomLeft="mfd_gun_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={2};
				font="EtelkaMonospaceProBold";
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Bones
				{
				};
				class Draw
				{
					color[]={0.15000001,1,0.050000001};
					alpha=1;
					condition="1";
					class Azimuth_number
					{
						type="text";
						source="[x]turretworld";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.5,0.235},
							1
						};
						right[]=
						{
							{0.52499998,0.235},
							1
						};
						down[]=
						{
							{0.5,0.27200001},
							1
						};
					};
					class Elevation_Text
					{
						type="text";
						source="static";
						text="E: ";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.23,0.30000001},
							1
						};
						right[]=
						{
							{0.255,0.30000001},
							1
						};
						down[]=
						{
							{0.23,0.33700001},
							1
						};
					};
					class Elevation_Number
					{
						type="text";
						source="[y]turretworld";
						sourceScale=1;
						sourceLength=4;
						sourcePrecision=1;
						refreshRate=0;
						align="center";
						scale=1;
						pos[]=
						{
							{0.25999999,0.30000001},
							1
						};
						right[]=
						{
							{0.285,0.30000001},
							1
						};
						down[]=
						{
							{0.25999999,0.33700001},
							1
						};
					};
					class Lased_Range
					{
						type="text";
						source="laserDist";
						sourceScale=1;
						sourceLength=4;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.5,0.64999998},
							1
						};
						right[]=
						{
							{0.52499998,0.64999998},
							1
						};
						down[]=
						{
							{0.5,0.68699998},
							1
						};
					};
					class VisionMode_Text
					{
						type="text";
						source="static";
						text="WFOV";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.75,0.64999998},
							1
						};
						right[]=
						{
							{0.77499998,0.64999998},
							1
						};
						down[]=
						{
							{0.75,0.68699998},
							1
						};
					};
					class VisionMode_String
					{
						type="text";
						source="visionMode";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.82499999,0.64999998},
							1
						};
						right[]=
						{
							{0.85000002,0.64999998},
							1
						};
						down[]=
						{
							{0.82499999,0.68699998},
							1
						};
					};
				};
			};
			class MFD_Rear_Gunner_Display_MainTurret
			{
				topLeft="mfd_gun_TL";
				topRight="mfd_gun_TR";
				bottomLeft="mfd_gun_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={2};
				font="PuristaBold";
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Bones
				{
				};
				class Draw
				{
					color[]={1,1,1};
					alpha=1;
					condition="1";
					class Smoke_ammo
					{
						type="text";
						source="ammo";
						sourceScale=1;
						sourceLength=3;
						sourceIndex=2;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.72000003,0.55000001},
							1
						};
						right[]=
						{
							{0.745,0.55000001},
							1
						};
						down[]=
						{
							{0.72000003,0.81},
							1
						};
					};
					class Azimuth_number
					{
						type="text";
						source="[x]turretworld";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.61000001,0.55000001},
							1
						};
						right[]=
						{
							{0.63499999,0.55000001},
							1
						};
						down[]=
						{
							{0.61000001,0.81},
							1
						};
					};
				};
			};
			class MFD_Gunner_Display_Damage
			{
				topLeft="mfd_maingun_TL";
				topRight="mfd_maingun_TR";
				bottomLeft="mfd_maingun_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={0};
				font="PuristaBold";
				class Bones
				{
				};
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Draw
				{
					color[]={1,1,1};
					alpha=1;
					condition="1";
					class Damage_Hull
					{
						type="text";
						source="static";
						text="HULL";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.039999999,0.18000001},
							1
						};
						right[]=
						{
							{0.064999998,0.18000001},
							1
						};
						down[]=
						{
							{0.039999999,0.44},
							1
						};
					};
					class Damage_Engine
					{
						type="text";
						source="static";
						text="ENG";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.11,0.18000001},
							1
						};
						right[]=
						{
							{0.13500001,0.18000001},
							1
						};
						down[]=
						{
							{0.11,0.44},
							1
						};
					};
					class Damage_Fuel
					{
						type="text";
						source="static";
						text="FUEL";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.178,0.18000001},
							1
						};
						right[]=
						{
							{0.20299999,0.18000001},
							1
						};
						down[]=
						{
							{0.178,0.44},
							1
						};
					};
					class Damage_Wheels
					{
						type="text";
						source="static";
						text="TRKS";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.039999999,0.55000001},
							1
						};
						right[]=
						{
							{0.064999998,0.55000001},
							1
						};
						down[]=
						{
							{0.039999999,0.81},
							1
						};
					};
					class Damage_Gun
					{
						type="text";
						source="static";
						text="GUN";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.11,0.55000001},
							1
						};
						right[]=
						{
							{0.13500001,0.55000001},
							1
						};
						down[]=
						{
							{0.11,0.81},
							1
						};
					};
					class Damage_Turret
					{
						type="text";
						source="static";
						text="TRT";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.178,0.55000001},
							1
						};
						right[]=
						{
							{0.20299999,0.55000001},
							1
						};
						down[]=
						{
							{0.178,0.81},
							1
						};
					};
				};
			};
			class MFD_Gunner_Display
			{
				topLeft="mfd_maingun_TL";
				topRight="mfd_maingun_TR";
				bottomLeft="mfd_maingun_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={0};
				font="PuristaBold";
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Bones
				{
					class FuelScale
					{
						type="linear";
						source="fuel";
						sourceIndex=1;
						sourceScale=1;
						min=0;
						max=1;
						minPos[]={0,0};
						maxPos[]={-0.090000004,0};
					};
				};
				class Draw
				{
					color[]={1,1,1};
					alpha=1;
					condition="1";
					class Main_Gun
					{
						type="text";
						source="static";
						text="MAIN GUN";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.273,0.18000001},
							1
						};
						right[]=
						{
							{0.29800001,0.18000001},
							1
						};
						down[]=
						{
							{0.273,0.44},
							1
						};
					};
					class Main_Gun_Ammo_count
					{
						type="text";
						source="ammo";
						sourceScale=1;
						sourceLength=2;
						sourceIndex=0;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.273,0.55000001},
							1
						};
						right[]=
						{
							{0.29800001,0.55000001},
							1
						};
						down[]=
						{
							{0.273,0.81},
							1
						};
					};
					class Main_Gun_Ammo_Type_text
					{
						type="text";
						source="static";
						text="TYPE";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.38499999,0.18000001},
							1
						};
						right[]=
						{
							{0.41,0.18000001},
							1
						};
						down[]=
						{
							{0.38499999,0.44},
							1
						};
					};
					class Main_Gun_Ammo_Type
					{
						type="text";
						source="ammoFormat";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.38499999,0.55000001},
							1
						};
						right[]=
						{
							{0.41,0.55000001},
							1
						};
						down[]=
						{
							{0.38499999,0.81},
							1
						};
					};
					class Azimuth
					{
						type="text";
						source="static";
						text="GUN AZIM";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.60500002,0.18000001},
							1
						};
						right[]=
						{
							{0.63,0.18000001},
							1
						};
						down[]=
						{
							{0.60500002,0.44},
							1
						};
					};
					class Smoke
					{
						type="text";
						source="static";
						text="SMOKE";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.71700001,0.18000001},
							1
						};
						right[]=
						{
							{0.74199998,0.18000001},
							1
						};
						down[]=
						{
							{0.71700001,0.44},
							1
						};
					};
					class Fuel_background_white
					{
						color[]={0.2,0.2,0.2};
						alpha=0.1;
						condition="1";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										{0.87699997,0.69999999},
										1
									},
									
									{
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel_background_green
					{
						color[]={0,0.69999999,0};
						condition="fuel>=0.5";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel_background_yellow
					{
						color[]={0.89999998,0.69999999,0};
						condition="fuel<0.5";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel_background_red
					{
						color[]={0.69999999,0,0};
						condition="fuel<0.3";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel
					{
						type="text";
						source="static";
						text="FUEL";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.82999998,0.18000001},
							1
						};
						right[]=
						{
							{0.85500002,0.18000001},
							1
						};
						down[]=
						{
							{0.82999998,0.44},
							1
						};
					};
					class Fuel_number
					{
						type="text";
						source="fuel";
						sourceScale=100;
						sourceLength=1;
						scale=1;
						align="left";
						refreshRate=0.1;
						pos[]=
						{
							{0.83499998,0.40000001},
							1
						};
						right[]=
						{
							{0.86000001,0.40000001},
							1
						};
						down[]=
						{
							{0.83499998,0.66000003},
							1
						};
					};
					class Fuel_percent_sign
					{
						type="text";
						source="static";
						text="%";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="right";
						refreshRate=0.1;
						pos[]=
						{
							{0.84500003,0.40000001},
							1
						};
						right[]=
						{
							{0.87,0.40000001},
							1
						};
						down[]=
						{
							{0.84500003,0.66000003},
							1
						};
					};
				};
			};
			class MFD_Gunner_OnScreen
			{
				topLeft="PIP_maingun_TL";
				topRight="PIP_maingun_TR";
				bottomLeft="mfd_maingun_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={0};
				font="EtelkaMonospaceProBold";
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Bones
				{
				};
				class Draw
				{
					color[]={0.15000001,1,0.050000001};
					alpha=1;
					condition="1";
					class Azimuth_number
					{
						type="text";
						source="[x]turretworld";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.5,0.235},
							1
						};
						right[]=
						{
							{0.52499998,0.235},
							1
						};
						down[]=
						{
							{0.5,0.27200001},
							1
						};
					};
					class Elevation_Text
					{
						type="text";
						source="static";
						text="E: ";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.23,0.30000001},
							1
						};
						right[]=
						{
							{0.255,0.30000001},
							1
						};
						down[]=
						{
							{0.23,0.33700001},
							1
						};
					};
					class Elevation_Number
					{
						type="text";
						source="[y]turretworld";
						sourceScale=1;
						sourceLength=4;
						sourcePrecision=1;
						refreshRate=0;
						align="center";
						scale=1;
						pos[]=
						{
							{0.25999999,0.30000001},
							1
						};
						right[]=
						{
							{0.285,0.30000001},
							1
						};
						down[]=
						{
							{0.25999999,0.33700001},
							1
						};
					};
					class Lased_Range
					{
						type="text";
						source="laserDist";
						sourceScale=1;
						sourceLength=4;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.5,0.64999998},
							1
						};
						right[]=
						{
							{0.52499998,0.64999998},
							1
						};
						down[]=
						{
							{0.5,0.68699998},
							1
						};
					};
					class VisionMode_Text
					{
						type="text";
						source="static";
						text="WFOV";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.75,0.64999998},
							1
						};
						right[]=
						{
							{0.77499998,0.64999998},
							1
						};
						down[]=
						{
							{0.75,0.68699998},
							1
						};
					};
					class VisionMode_String
					{
						type="text";
						source="visionMode";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.82499999,0.64999998},
							1
						};
						right[]=
						{
							{0.85000002,0.64999998},
							1
						};
						down[]=
						{
							{0.82499999,0.68699998},
							1
						};
					};
				};
			};
			class MFD_Gunner_Display_MainTurret
			{
				topLeft="mfd_maingun_TL";
				topRight="mfd_maingun_TR";
				bottomLeft="mfd_maingun_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={0};
				font="PuristaBold";
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Bones
				{
				};
				class Draw
				{
					color[]={1,1,1};
					alpha=1;
					condition="1";
					class Smoke_ammo
					{
						type="text";
						source="ammo";
						sourceScale=1;
						sourceLength=3;
						sourceIndex=2;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.72000003,0.55000001},
							1
						};
						right[]=
						{
							{0.745,0.55000001},
							1
						};
						down[]=
						{
							{0.72000003,0.81},
							1
						};
					};
					class Azimuth_number
					{
						type="text";
						source="[x]turretworld";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.61000001,0.55000001},
							1
						};
						right[]=
						{
							{0.63499999,0.55000001},
							1
						};
						down[]=
						{
							{0.61000001,0.81},
							1
						};
					};
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
				class _xx_FST_Bacta_Tank
				{
					name="FST_Bacta_Tank";
					count=1;
				};
			};
			class TransportWeapons
			{
				
			}
			class TransportMagazines
			{	
			}
		class Turrets: Turrets
		{
			class MainTurretTop: MainTurret
			{
				startEngine=0;
				body="MainTurret";
				memoryPointsGetInGunner="pos_gunner";
				memoryPointsGetInGunnerDir="pos_gunner_dir";
				gun="MainGun";
				proxyIndex=1;
				viewGunnerInExternal=1;
				commanding=5;
				gunnerCompartments="Compartment1";
				proxytype="CPGunner";
				gunnername="Gunner";
				showgunneroptics=1;
				animationSourceBody="Mainturret";
				animationSourceGun="Maingun";
				gunBeg="usti hlavne";
				gunEnd="konec hlavne";
				memoryPointGun="usti hlavne";
				memoryPointGunnerOptics="gunnerview";
				weapons[]=
				{
					"FST_Mass_Driver_Cannon",
					"SmokeLauncher"
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
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
				};
				gunnerAction="mbt1_slot2_out";
				ejectDeadGunner=1;
				gunnerInAction="ATAP_Commander";
				gunnerGetInAction="GetInHigh";
				gunnerGetOutAction="GetOutHigh";
				gunnerOpticsModel="A3\weapons_f\reticle\Optics_Gunner_02_F";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex=2;
				selectionFireAnim="-";
				primaryGunner=1;
				minElev=-13;
				initElev=0;
				maxElev=50;
				maxTurn=360;
				minTurn=-360;
				minOutElev=-10;
				maxOutElev=15;
				initOutElev=0;
				minOutTurn=-15;
				maxOutTurn=175;
				initOutTurn=0;
				forceHideGunner=1;
				outGunnerMayFire=0;
				inGunnerMayFire=1;
				gunnerForceOptics=0;
				LODTurnedIn=1000;
				LODOpticsIn=1;
				usepip=2;
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
						gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
						gunnerOpticsEffect[]={};
					};
					class Narrow: Wide
					{
						gunnerOpticsModel="A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
						initFov=0.046999998;
						minFov=0.046999998;
						maxFov=0.046999998;
					};
				};
				class HitPoints
				{
					class HitTurrettop
					{
						armor=0.2;
						material=-1;
						name="hit_mainturret_point";
						visual="-";
						armorComponent="hit_mainturret";
						passThrough=0;
						minimalHit=0.1;
						explosionShielding=0.2;
						radius=0.25;
					};
					class HitGuntop
					{
						armor=0.1;
						material=-1;
						name="hit_maingun_point";
						visual="-";
						armorComponent="hit_maingun";
						passThrough=0;
						minimalHit=0.1;
						explosionShielding=0.40000001;
						radius=0.5;
					};
				};
				class ViewGunner: ViewGunner
				{
					initAngleX=-8;
					initAngleY=0;
				};
				class Turrets
				{
				};
			};
			class MainTurretFront: MainTurretTop
			{
				startEngine=0;
				memoryPointsGetInGunner="pos_gunner";
				memoryPointsGetInGunnerDir="pos_gunner_dir";
				body="mainturret2";
				gun="maingun2";
				proxyIndex=2;
				viewGunnerInExternal=1;
				commanding=4;
				primaryGunner=0;
				gunnername="Commander";
				animationSourceBody="mainturret2";
				animationSourceGun="maingun2";
				forceHideGunner=1;
				selectionFireAnim="-";
				gunnerAction="UTAT_Driver";
				gunnerInAction="UTAT_Driver";
				gunnerGetInAction="GetInHigh";
				gunnerGetOutAction="GetOutHigh";
				gunEnd="";
				gunBeg="";
				memoryPointGun[]=
				{
					"FTL_muzzle",
					"FTR_Muzzle",
					"FBR_Muzzle",
					"FBL_Muzzle"
				};
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner",
					0.56234097,
					1,
					30
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner_vertical",
					0.56234097,
					1,
					30
				};
				weapons[]=
				{
					"FST_ATTE_Turret",
					"FST_EWEB_RemoteTurret"
				};
				magazines[]=
				{
					"FST_thermal_coil_blue",
					"FST_thermal_coil_blue",
					"FST_thermal_coil_blue",
					"FST_thermal_coil_blue",
					"FST_thermal_coil_blue",
					"FST_thermal_coil_blue",
					"FST_thermal_coil_blue",
					"FST_thermal_coil_blue",
					"FST_thermal_coil_blue",
					"FST_thermal_coil_blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue"
				};
				minElev=-10;
				maxElev=20;
				maxTurn=25;
				minTurn=-25;
				initElev=0;
				initTurn=0;
				memoryPointGunnerOptics="commanderview";
				gunnerForceOptics=0;
				usepip=2;
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
						gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
						gunnerOpticsEffect[]={};
					};
					class Narrow: Wide
					{
						gunnerOpticsModel="A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
						initFov=0.046999998;
						minFov=0.046999998;
						maxFov=0.046999998;
					};
				};
				class HitPoints
				{
					class HitTurretFront
					{
						armor=0.2;
						material=-1;
						name="hit_commanderTurret_point";
						visual="-";
						armorComponent="hit_commanderTurret";
						passThrough=0;
						minimalHit=0.1;
						explosionShielding=0.2;
						radius=0.25;
					};
					class HitGunFront
					{
						armor=0.1;
						material=-1;
						name="hit_commanderGun_point";
						visual="-";
						armorComponent="hit_commanderGun";
						passThrough=0;
						minimalHit=0.1;
						explosionShielding=0.40000001;
						radius=0.5;
					};
				};
				class ViewGunner: ViewGunner
				{
					initAngleX=2;
					initAngleY=0;
				};
				class Turrets
				{
				};
			};
			
			class MainTurretBack: MainTurretFront
			{
				body="mainturret3";
				gun="maingun3";
				animationSourceBody="mainturret3";
				animationSourceGun="maingun3";
				proxyIndex=3;
				commanding=3;
				proxytype="CPgunner";
				gunnername="Rear Gunner";
				memoryPointGun[]=
				{
					"BTL_muzzle",
					"BTR_Muzzle"
				};
				maxTurn=200;
				minTurn=160;
				initElev=0;
				initTurn=180;
				LODTurnedIn=1200;
				LODOpticsIn=1000;
				memoryPointGunnerOptics="commanderview2";
				selectionFireAnim="zasleh3";
				usePiP=2;
				class ViewGunner: ViewGunner
				{
					initAngleX=0;
					initAngleY=-5;
				};
				class HitPoints
				{
					class HitTurretRear
					{
						armor=0.2;
						material=-1;
						name="hit_rearTurret_point";
						visual="-";
						armorComponent="hit_rearTurret";
						passThrough=0;
						minimalHit=0.1;
						explosionShielding=0.2;
						radius=0.25;
					};
					class HitGunRear
					{
						armor=0.1;
						material=-1;
						name="hit_rearGun_point";
						visual="-";
						armorComponent="hit_rearGun";
						passThrough=0;
						minimalHit=0.1;
						explosionShielding=0.40000001;
						radius=0.5;
					};
				};
			};
		};
		ace_cargo_hasCargo=1;
		ace_cargo_space=1000;
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
				maxLoadMass=1000000;
				cargoAlignment[]=
				{
					"center",
					"front"
				};
				cargoSpacing[]={0,0,0};
				exits[]=
				{
					"pos_cargo_load"
				};
				unloadingInterval=2;
				loadingDistance=10;
				loadingAngle=60;
				parachuteClassDefault="B_Parachute_02_F";
				parachuteHeightLimitDefault=50;
			};
		};
	};
	class FST_ATTE_Jorge: FST_ATTE_Base
	{
		author="Gold";
		displayname="[41st] AT-TE Heavy Walker (Jorge)";
		scope=2;
		hiddenselections[]=
		{
			"camo1",
			"camo2",
			"camo3",
			"camo4",
			"camo5",
			"camo11"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\ATTE\Data\Shell\FST_ATTE_Shell_Jorge_co.paa",
			"3as\3AS_ATTE\data\Textures\3AS_ATTE_Cockpit_co.paa",
			"41st_Vehicles\ATTE\Data\Detail\FST_ATTE_Detail_Jorge_co.paa",
			"41st_Vehicles\ATTE\Data\Legs\FST_ATTE_Legs_Jorge_co.paa",
			"3as\3AS_ATTE\data\Textures\3AS_ATTE_Glass_ca.paa",
			"3as\3as_atte\data\textures\3as_atte_armor_co.paa"
		};
	};
	class FST_ATTE_gwenn: FST_ATTE_Base
	{
		author="Viz";
		displayname="[41st] AT-TE Heavy Walker (Grenner)";
		scope=2;
		hiddenselections[]=
		{
			"camo1",
			"camo2",
			"camo3",
			"camo4",
			"camo5",
			"camo11"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\ATTE\Data\Shell\FST_ATTE_Shell_Grenner_co.paa",
			"3as\3AS_ATTE\data\Textures\3AS_ATTE_Cockpit_co.paa",
			"41st_Vehicles\ATTE\Data\Detail\FST_ATTE_Detail_Grenner_co.paa",
			"41st_Vehicles\ATTE\Data\Legs\FST_ATTE_Legs_Grenner_co.paa",
			"3as\3AS_ATTE\data\Textures\3AS_ATTE_Glass_ca.paa",
			"3as\3as_atte\data\textures\3as_atte_armor_co.paa"
		};
	};
	class FST_ATTE_Rancor: FST_ATTE_Base
	{
		author="Gold";
		displayname="[41st] AT-TE Heavy Walker (Rancor)";
		scope=2;
		hiddenselections[]=
		{
			"camo1",
			"camo2",
			"camo3",
			"camo4",
			"camo5",
			"camo11"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\ATTE\Data\Shell\FST_ATTE_Shell_Rancor_co.paa",
			"3as\3AS_ATTE\data\Textures\3AS_ATTE_Cockpit_co.paa",
			"41st_Vehicles\ATTE\Data\Detail\FST_ATTE_Detail_Rancor_co.paa",
			"41st_Vehicles\ATTE\Data\Legs\FST_ATTE_Legs_Rancor_co.paa",
			"3as\3AS_ATTE\data\Textures\3AS_ATTE_Glass_ca.paa",
			"3as\3as_atte\data\textures\3as_atte_armor_co.paa"
		};
	};
	class FST_ATTE_Klanka: FST_ATTE_Base
	{
		author="Daara";
		displayname="[41st] AT-TE Heavy Walker (Klanka Killa)";
		scope=2;
		hiddenselections[]=
		{
			"camo1",
			"camo2",
			"camo3",
			"camo4",
			"camo5",
			"camo11"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\ATTE\Data\Shell\FST_ATTE_Shell_Klanka_co.paa",
			"3as\3AS_ATTE\data\Textures\3AS_ATTE_Cockpit_co.paa",
			"41st_Vehicles\ATTE\Data\Detail\FST_ATTE_Detail_Rancor_co.paa",
			"41st_Vehicles\ATTE\Data\Legs\FST_ATTE_Legs_Klanka_co.paa",
			"3as\3AS_ATTE\data\Textures\3AS_ATTE_Glass_ca.paa",
			"3as\3as_atte\data\textures\3as_atte_armor_co.paa"
		};
	};
};
