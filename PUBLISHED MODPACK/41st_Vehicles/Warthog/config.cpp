class CfgPatches
{
	class FST_Warthog
	{
		author="Daara";
		requiredaddons[]=
		{
		};
		requiredversion=1;
		units[]=
		{
			"FST_Technical",
			"FST_Technical_Transport",
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class land;
	class LandVehicle: land
	{
		class NewTurret;
	};
	class Car: LandVehicle
	{
		class NewTurret;
	};
	class Car_F: Car
	{
		class Sounds;
		class AnimationSources
		{
			class HitLFWheel;
			class HitRFWheel;
			class HitLBWheel;
			class HitRBWheel;
			class HitLF2Wheel;
			class HitRF2Wheel;
			class HitLMWheel;
			class HitRMWheel;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
			class Gatling;
			class Gatling_flash;
		};
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewOptics;
			};
		};
		class HitPoints
		{
			class HitLFWheel;
			class HitLBWheel;
			class HitRFWheel;
			class HitRBWheel;
			class HitLF2Wheel;
			class HitRF2Wheel;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
			class HitFuel;
			class HitEngine;
			class HitBody;
		};
	};
	class OPTRE_M12_Base: Car_F{};
	class OPTRE_M813_TT: OPTRE_M12_Base{};
	class OPTRE_M12_LRV: OPTRE_M12_Base{};
	class FST_Technical: OPTRE_M12_LRV
	{
		tas_canBlift=1;
        tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]"; 
		displayName="[41st] Militia Technical";
		author="Daara";
		side=1;
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Trooper_P2_DC15S";
		maxSpeed=202;
		fuelCapacity=50;
		normalSpeedForwardCoef=0.5;
		slowSpeedForwardCoef=0.25;
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-6,
				"N",
				0,
				"D1",
				4.65,
				"D2",
				3.20,
				"D3",
				2.40,
				"D4",
				1.87,
				"D5",
				1.54,
				"D6",
				1.29,
				"D7",
				1.11,
				"D8",
				0.97,
				"D9",
				0.87,
				"D10",
				0.78,
			};
			AmphibiousRatios[]=
			{
				"R1",
				-6,
				"N",
				0,
				"D1",
				4.65,
				"D2",
				3.20,
				"D3",
				2.40,
				"D4",
				1.87,
				"D5",
				1.54,
				"D6",
				1.29,
				"D7",
				1.11,
				"D8",
				0.97,
				"D9",
				0.87,
				"D10",
				0.78,
			};
			TransmissionRatios[]=
			{
				"High",
				5.45
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
		};
		class Turrets: Turrets
		{
			class CargoGunner_1: NewTurret
			{
				gunnerInAction="passenger_inside_2";
				gunnerAction="passenger_flatground_4_vehicle_passenger_stand_1";
				gunnerCompartments="Compartment1";
				memoryPointsGetInGunner="pos pas";
				memoryPointsGetInGunnerDir="pos pas dir";
				outGunnerMayFire=1;
				inGunnerMayFire=1;
				memoryPointGunnerOptics="";
				gunnerName="Front Passenger";
				proxyIndex=1;
				proxyType="CPCargo";
				showAsCargo=1;
				maxElev=30;
				minElev=-20;
				maxTurn=95;
				minTurn=-95;
				animationSourceHatch="cargo_front";
				enabledByAnimationSource="";
				LODTurnedIn=1200;
				LODTurnedOut=-1;
				viewGunnerInExternal=1;
				canHideGunner=1;
				hasGunner=1;
				allowLauncherIn=0;
				allowLauncherOut=0;
				isPersonTurret=2;
				weapons[]={};
				magazines[]={};
				primaryGunner=0;
				primaryObserver=0;
				gunnerOpticsShowCursor=0;
				body="";
				gun="";
				animationSourceBody="";
				animationSourceGun="";
				soundServo[]=
				{
					"",
					"db-50",
					1
				};
				startEngine=0;
				hideWeaponsGunner=0;
				gunnerGetInAction="GetInHigh";
				gunnerGetOutAction="GetOutHigh";
				commanding=-1;
				gunnerOpticsModel="";
				gunnerOutOpticsColor[]={0,0,0,1};
				gunnerForceOptics=0;
				gunnerOutForceOptics=0;
				gunnerOutOpticsShowCursor=0;
				gunnerOpticsEffect[]={};
				stabilizedInAxes=0;
			};
			class MainTurret: MainTurret
			{
				body="mainturret";
				gun="maingun";
				animationsourcebody="mainturret";
				animationSourceGun="maingun";
				gunAxis="Osa Hlavne";
				gunBeg="Usti hlavne";
				gunEnd="konec hlavne";
				LODTurnedOut=1100;
				LODTurnedIn=1100;
				LODOpticsIn=1100;
				LODOpticsOut=1100;
				ejectDeadGunner=1;
				minElev=-15;
				maxElev=30;
				minTurn=-360;
				maxTurn=360;
				initTurn=0;
				fireLightDiffuse[]={0,0,1};
				turretAxis="OsaVeze";
				maxHorizontalRotSpeed=1.75;
				maxVerticalRotSpeed=1.5;
				gunnerAction="OPTRE_Gunner_Gaus_Warthog";
				gunnerInAction="OPTRE_Gunner_Gaus_Warthog";
				gunnerGetInAction="GetInMRAP_01";
				gunnerGetOutAction="GetOutMRAP_01";
				gunnerName="Gunner";
				hideWeaponsGunner=0;
				soundServo[]=
				{
					"",
					0.0099999998,
					1
				};
				stabilizedInAxes=3;
				outGunnerMayFire=1;
				inGunnerMayFire=1;
				commanding=1;
				primaryGunner=1;
				turretInfoType="RscWeaponZeroing";
				memoryPointsGetInGunner="Pos Gunner";
				memoryPointsGetInGunnerDir="Pos Gunner dir";
				gunnerLeftHandAnimName="OtocHlaven";
				gunnerRightHandAnimName="OtocHlaven";
				memoryPointGun="machinegun";
				weapons[]=
				{
					"FST_Rotary_Blaster_Coax",
				};
				magazines[]=
				{
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"FST_500Rnd_High_Capacity_Plasma_Cell",
				};
				memoryPointGunnerOptics="gunnerview";
				memoryPointGunnerOutOptics="gunnerview";
				gunnerOpticsShowCursor=1;
				castGunnerShadow=1;
				startEngine=0;
				enableManualFire=0;
				gunnerOpticsModel="a3\weapons_f\Reticle\optics_empty";
				gunnerOutOpticsModel="a3\weapons_f\Reticle\optics_empty";
				gunnerForceOptics=1;
				hasGunner=1;
				class ViewGunner: ViewOptics
				{
					initAngleX=0;
					minAngleX=-45;
					maxAngleX=45;
					initFov=0.89999998;
					minFov=0.41999999;
					maxFov=0.89999998;
					visionMode[]={};
				};
			};
		};
		class Sounds
		{
			soundSetsInt[]=
			{
				"Mrap_01_Engine_RPM0_EXT_SoundSet",
				"Mrap_01_Engine_RPM1_EXT_SoundSet",
				"Mrap_01_Engine_RPM2_EXT_SoundSet",
				"Mrap_01_Engine_RPM3_EXT_SoundSet",
				"Mrap_01_Engine_RPM4_EXT_SoundSet",
				"Mrap_01_Engine_EXT_Burst_SoundSet",
				"Mrap_01_Rattling_EXT_SoundSet",
				"Mrap_01_Stress_EXT_SoundSet",
				"Mrap_01_Rain_EXT_SoundSet",
				"Mrap_01_Tires_Rock_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Grass_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Sand_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Gravel_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Mud_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Asphalt_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Water_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Rock_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Grass_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Sand_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Gravel_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Mud_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Asphalt_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Water_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Turn_Hard_EXT_SoundSet",
				"Mrap_01_Tires_Turn_Soft_EXT_SoundSet",
				"Mrap_01_Tires_Brake_Hard_EXT_SoundSet",
				"Mrap_01_Tires_Brake_Soft_EXT_SoundSet",
				"",
				"Tires_Movement_Dirt_Ext_01_SoundSet"
			};
			soundSetsExt[]=
			{
				"Mrap_01_Engine_RPM0_EXT_SoundSet",
				"Mrap_01_Engine_RPM1_EXT_SoundSet",
				"Mrap_01_Engine_RPM2_EXT_SoundSet",
				"Mrap_01_Engine_RPM3_EXT_SoundSet",
				"Mrap_01_Engine_RPM4_EXT_SoundSet",
				"Mrap_01_Engine_EXT_Burst_SoundSet",
				"Mrap_01_Rattling_EXT_SoundSet",
				"Mrap_01_Stress_EXT_SoundSet",
				"Mrap_01_Rain_EXT_SoundSet",
				"Mrap_01_Tires_Rock_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Grass_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Sand_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Gravel_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Mud_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Asphalt_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Water_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Rock_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Grass_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Sand_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Gravel_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Mud_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Asphalt_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Water_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Turn_Hard_EXT_SoundSet",
				"Mrap_01_Tires_Turn_Soft_EXT_SoundSet",
				"Mrap_01_Tires_Brake_Hard_EXT_SoundSet",
				"Mrap_01_Tires_Brake_Soft_EXT_SoundSet",
				"",
				"Tires_Movement_Dirt_Ext_01_SoundSet"
			};
		};
		class TransportMagazines{};
		class TransportItems{};
		class TransportWeapons{};
		class TransportBackpacks{};
	};
	class FST_Technical_Transport: OPTRE_M813_TT
	{
		scope=2;
		scopeCurator=2;
		tas_canBlift=1;
        tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]"; 
		displayName="[41st] Militia Transport";
		author="Daara";
		model="\OPTRE_Vehicles\Warthog\M12_MAAV_TT.p3d";
		transportSoldier=0;
		side=1;
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Trooper_P2_DC15S";
		maxSpeed=202;
		fuelCapacity=50;
		normalSpeedForwardCoef=0.5;
		slowSpeedForwardCoef=0.25;
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-6,
				"N",
				0,
				"D1",
				4.65,
				"D2",
				3.20,
				"D3",
				2.40,
				"D4",
				1.87,
				"D5",
				1.54,
				"D6",
				1.29,
				"D7",
				1.11,
				"D8",
				0.97,
				"D9",
				0.87,
				"D10",
				0.78,
			};
			AmphibiousRatios[]=
			{
				"R1",
				-6,
				"N",
				0,
				"D1",
				4.65,
				"D2",
				3.20,
				"D3",
				2.40,
				"D4",
				1.87,
				"D5",
				1.54,
				"D6",
				1.29,
				"D7",
				1.11,
				"D8",
				0.97,
				"D9",
				0.87,
				"D10",
				0.78,
			};
			TransmissionRatios[]=
			{
				"High",
				5.45
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
		};
		class Turrets: Turrets
		{
			class CargoGunner_1: NewTurret
			{
				gunnerInAction="passenger_inside_2";
				gunnerAction="passenger_flatground_4_vehicle_passenger_stand_1";
				gunnerCompartments="Compartment1";
				memoryPointsGetInGunner="pos pas";
				memoryPointsGetInGunnerDir="pos pas dir";
				outGunnerMayFire=1;
				inGunnerMayFire=1;
				memoryPointGunnerOptics="";
				gunnerName="Front Passenger";
				proxyIndex=1;
				proxyType="CPCargo";
				showAsCargo=1;
				maxElev=30;
				minElev=-20;
				maxTurn=95;
				minTurn=-95;
				animationSourceHatch="cargo_front";
				enabledByAnimationSource="";
				LODTurnedIn=1200;
				LODTurnedOut=-1;
				viewGunnerInExternal=1;
				canHideGunner=1;
				hasGunner=1;
				allowLauncherIn=0;
				allowLauncherOut=0;
				isPersonTurret=2;
				weapons[]={};
				magazines[]={};
				primaryGunner=0;
				primaryObserver=0;
				gunnerOpticsShowCursor=0;
				body="";
				gun="";
				animationSourceBody="";
				animationSourceGun="";
				soundServo[]=
				{
					"",
					"db-50",
					1
				};
				startEngine=0;
				hideWeaponsGunner=0;
				gunnerGetInAction="GetInHigh";
				gunnerGetOutAction="GetOutHigh";
				commanding=-1;
				gunnerOpticsModel="";
				gunnerOutOpticsColor[]={0,0,0,1};
				gunnerForceOptics=0;
				gunnerOutForceOptics=0;
				gunnerOutOpticsShowCursor=0;
				gunnerOpticsEffect[]={};
				stabilizedInAxes=0;
			};
			class CargoGunner_02: CargoGunner_1
			{
				gunnerAction="passenger_bench_1";
				gunnerInAction="passenger_bench_1";
				gunnerName="Right Passenger (Rear)";
				memoryPointsGetInGunner="pos pasrr";
				memoryPointsGetInGunnerDir="pos pasrr dir";
				proxyIndex=4;
				gunnerCompartments="Compartment2";
				canHideGunner=0;
				inGunnerMayFire=1;
			};
			class CargoGunner_03: CargoGunner_02
			{
				gunnerAction="passenger_bench_1";
				gunnerInAction="passenger_bench_1";
				gunnerName="Left Passenger (Rear)";
				memoryPointsGetInGunner="pos paslr";
				memoryPointsGetInGunnerDir="pos paslr dir";
				proxyIndex=5;
				gunnerCompartments="Compartment2";
				canHideGunner=0;
			};
			class CargoGunner_04: CargoGunner_02
			{
				gunnerAction="passenger_inside_2";
				gunnerInAction="passenger_inside_2";
				gunnerName="Right Passenger (Middle)";
				memoryPointsGetInGunner="pos pasrm";
				memoryPointsGetInGunnerDir="pos pasrm dir";
				proxyIndex=6;
				gunnerCompartments="Compartment2";
				canHideGunner=0;
			};
			class CargoGunner_05: CargoGunner_02
			{
				gunnerAction="passenger_inside_2";
				gunnerInAction="passenger_inside_2";
				gunnerName="Left Passenger (Middle)";
				memoryPointsGetInGunner="pos paslm";
				memoryPointsGetInGunnerDir="pos paslm dir";
				proxyIndex=7;
				gunnerCompartments="Compartment2";
				canHideGunner=0;
			};
			class CargoGunner_06: CargoGunner_02
			{
				gunnerAction="passenger_inside_2";
				gunnerInAction="passenger_inside_2";
				gunnerName="Right Passenger (Front)";
				memoryPointsGetInGunner="pos pasrf";
				memoryPointsGetInGunnerDir="pos pasrf dir";
				proxyIndex=8;
				gunnerCompartments="Compartment2";
				canHideGunner=0;
			};
			class CargoGunner_07: CargoGunner_02
			{
				gunnerAction="passenger_inside_2";
				gunnerInAction="passenger_inside_2";
				gunnerName="Left Passenger (Front)";
				memoryPointsGetInGunner="pos paslf";
				memoryPointsGetInGunnerDir="pos paslf dir";
				proxyIndex=9;
				gunnerCompartments="Compartment2";
				canHideGunner=0;
			};
		};
		tf_range=25000;
		tf_isolatedAmount=0.40000001;
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_hasLRradio=1;
		enableRadio=1;
		class Sounds
		{
			soundSetsInt[]=
			{
				"Mrap_01_Engine_RPM0_INT_SoundSet",
				"Mrap_01_Engine_RPM1_INT_SoundSet",
				"Mrap_01_Engine_RPM2_INT_SoundSet",
				"Mrap_01_Engine_RPM3_INT_SoundSet",
				"Mrap_01_Engine_RPM4_INT_SoundSet",
				"Mrap_01_Engine_INT_Burst_SoundSet",
				"Mrap_01_Rattling_INT_SoundSet",
				"Mrap_01_Stress_INT_SoundSet",
				"Mrap_01_Rain_INT_SoundSet",
				"Mrap_01_Tires_Rock_Fast_INT_SoundSet",
				"Mrap_01_Tires_Grass_Fast_INT_SoundSet",
				"Mrap_01_Tires_Sand_Fast_INT_SoundSet",
				"Mrap_01_Tires_Gravel_Fast_INT_SoundSet",
				"Mrap_01_Tires_Mud_Fast_INT_SoundSet",
				"Mrap_01_Tires_Asphalt_Fast_INT_SoundSet",
				"Mrap_01_Tires_Water_Fast_INT_SoundSet",
				"Mrap_01_Tires_Rock_Slow_INT_SoundSet",
				"Mrap_01_Tires_Grass_Slow_INT_SoundSet",
				"Mrap_01_Tires_Sand_Slow_INT_SoundSet",
				"Mrap_01_Tires_Gravel_Slow_INT_SoundSet",
				"Mrap_01_Tires_Mud_Slow_INT_SoundSet",
				"Mrap_01_Tires_Asphalt_Slow_INT_SoundSet",
				"Mrap_01_Tires_Water_Slow_INT_SoundSet",
				"Mrap_01_Tires_Turn_Hard_INT_SoundSet",
				"Mrap_01_Tires_Turn_Soft_INT_SoundSet",
				"Mrap_01_Tires_Brake_Hard_INT_SoundSet",
				"Mrap_01_Tires_Brake_Soft_INT_SoundSet",
				"",
				"Tires_Movement_Dirt_Int_01_SoundSet"
			};
			soundSetsExt[]=
			{
				"Mrap_01_Engine_RPM0_EXT_SoundSet",
				"Mrap_01_Engine_RPM1_EXT_SoundSet",
				"Mrap_01_Engine_RPM2_EXT_SoundSet",
				"Mrap_01_Engine_RPM3_EXT_SoundSet",
				"Mrap_01_Engine_RPM4_EXT_SoundSet",
				"Mrap_01_Engine_EXT_Burst_SoundSet",
				"Mrap_01_Rattling_EXT_SoundSet",
				"Mrap_01_Stress_EXT_SoundSet",
				"Mrap_01_Rain_EXT_SoundSet",
				"Mrap_01_Tires_Rock_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Grass_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Sand_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Gravel_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Mud_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Asphalt_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Water_Fast_EXT_SoundSet",
				"Mrap_01_Tires_Rock_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Grass_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Sand_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Gravel_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Mud_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Asphalt_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Water_Slow_EXT_SoundSet",
				"Mrap_01_Tires_Turn_Hard_EXT_SoundSet",
				"Mrap_01_Tires_Turn_Soft_EXT_SoundSet",
				"Mrap_01_Tires_Brake_Hard_EXT_SoundSet",
				"Mrap_01_Tires_Brake_Soft_EXT_SoundSet",
				"",
				"Tires_Movement_Dirt_Ext_01_SoundSet"
			};
		};
		class TransportMagazines{};
		class TransportItems{};
		class TransportWeapons{};
		class TransportBackpacks{};
	};
};