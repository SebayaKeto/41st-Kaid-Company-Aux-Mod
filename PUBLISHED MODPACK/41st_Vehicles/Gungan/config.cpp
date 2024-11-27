class CfgPatches
{
	class FST_Boat
	{
		units[]=
		{
			"FST_Boat_Gungan_Z6_F",
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"OPTRE_Vehicles"
		};
		addonRootClass="OPTRE_Vehicles";
	};
};
class CfgVehicles
{
	class Ship;
	class Boat_F: Ship
	{
		class AnimationSources
		{
			class Gatling;
			class Gatling_flash;
		};
		class Eventhandlers;
		class HitPoints;
		class ViewPilot;
		class CargoTurret;
		class Turrets;
		class NewTurret;
		class ViewOptics;
	};
	class FST_Boat_Gungan_F: Boat_F
	{
		dlc="OPTRE";
		author="Article 2 Studios";
		displayName="M112 Wet Patrol Craft";
		model="OPTRE_Vehicles\catfish\optre_catfish";
		picture="\A3\boat_F\Boat_Transport_01\data\UI\map_Boat_Transport_01_CA.paa";
		Icon="\A3\boat_F\Boat_Transport_01\data\UI\map_Boat_Transport_01_CA.paa";
		cost=500;
		accuracy=0.5;
		class HitPoints: HitPoints
		{
			class HitHull
			{
				armor=2;
				material=50;
				name="karoserie";
				passThrough=1;
				explosionShielding=10;
			};
		};
		simulation="shipx";
		maxSpeed=120;
		overSpeedBrakeCoef=0.80000001;
		enginePower=750;
		engineShiftY=0.050000001;
		waterLeakiness=1;
		turnCoef=1;
		thrustDelay=1.5;
		waterLinearDampingCoefY=4.5;
		waterLinearDampingCoefX=7.5;
		waterAngularDampingCoef=4.5;
		waterResistanceCoef=0.015;
		rudderForceCoef=0.175;
		rudderForceCoefAtMaxSpeed=0.0024999999;
		idleRpm=200;
		redRpm=1600;
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-1,
				"N",
				0,
				"D1",
				2,
				"D2",
				1.75,
				"D3",
				1.5
			};
			TransmissionRatios[]=
			{
				"High",
				1
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
		};
		waterEffectSpeed=12;
		engineEffectSpeed=12;
		waterFastEffectSpeed=40;
		leftEngineEffect="LEngEffectsSmall";
		rightEngineEffect="REngEffectsSmall";
		leftFastWaterEffect="LFastWaterEffects";
		rightFastWaterEffect="RFastWaterEffects";
		memoryPointsLeftWaterEffect="waterEffectR";
		memoryPointsRightWaterEffect="waterEffectL";
		memoryPointsLeftEngineEffect="EngineEffectL";
		memoryPointsRightEngineEffect="EngineEffectR";
		getInAction="GetInLow";
		getOutAction="GetOutBoat";
		cargoGetInAction[]=
		{
			"GetInLow"
		};
		cargoGetOutAction[]=
		{
			"GetOutBoat"
		};
		driverAction="driver_mid01";
		driverLeftHandAnimName="drivingWheel";
		driverRightHandAnimName="drivingWheel";
		cargoAction[]=
		{
			"passenger_bench_1"
		};
		cargoIsCoDriver[]={0};
		ejectDeadDriver=0;
		ejectDeadCargo=0;
		transportSoldier=0;
		enableRadio=1;
		enableGPS=1;
		class TransportItems
		{
			class _xx_FirstAidKit
			{
				name="FirstAidKit";
				count=6;
			};
		};
		brakeDistance=3;
		slingLoadCargoMemoryPoints[]=
		{
			"SlingLoadCargo1",
			"SlingLoadCargo2",
			"SlingLoadCargo3",
			"SlingLoadCargo4"
		};
		armor=100;
		armorStructural=4;
		damageResistance=0.050000001;
		class CargoTurret;
		class Turrets: Turrets
		{
			class CargoTurret_01: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				memoryPointsGetInGunner="pos gunner";
				memoryPointsGetInGunnerDir="pos gunner dir";
				gunnerName="Passenger (FFV - Left 01)";
				proxyIndex=1;
				isPersonTurret=1;
				maxElev=50;
				minElev=-5;
				maxTurn=45;
				minTurn=-45;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-65,95};
				};
				class TurnIn
				{
					limitsArrayTop[]=
					{
						{33.820801,-93.961601},
						{40.890598,66.570503}
					};
					limitsArrayBottom[]=
					{
						{-9.4643002,-94.575302},
						{-8.3683004,-67.686699},
						{-9.7173004,43.637199},
						{-10.1082,78.916603}
					};
				};
				class TurnOut: TurnIn
				{
				};
			};
			class CargoTurret_02: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				memoryPointsGetInGunner="pos gunner";
				memoryPointsGetInGunnerDir="pos gunner dir";
				gunnerName="Passenger (FFV - Left 02)";
				proxyIndex=2;
				isPersonTurret=1;
				maxElev=50;
				minElev=-5;
				maxTurn=45;
				minTurn=-45;
				class TurnIn
				{
					limitsArrayTop[]=
					{
						{33.820801,-93.961601},
						{40.890598,66.570503}
					};
					limitsArrayBottom[]=
					{
						{-9.4643002,-94.575302},
						{-8.3683004,-67.686699},
						{-9.7173004,43.637199},
						{-10.1082,78.916603}
					};
				};
				class TurnOut: TurnIn
				{
				};
			};
			class CargoTurret_03: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				memoryPointsGetInGunner="pos gunner";
				memoryPointsGetInGunnerDir="pos gunner dir";
				gunnerName="Passenger (FFV - Right 01)";
				proxyIndex=3;
				isPersonTurret=1;
				maxElev=50;
				minElev=-5;
				maxTurn=45;
				minTurn=-45;
				class TurnIn
				{
					limitsArrayTop[]=
					{
						{33.820801,-93.961601},
						{40.890598,66.570503}
					};
					limitsArrayBottom[]=
					{
						{-9.4643002,-94.575302},
						{-8.3683004,-67.686699},
						{-9.7173004,43.637199},
						{-10.1082,78.916603}
					};
				};
				class TurnOut: TurnIn
				{
				};
			};
			class CargoTurret_04: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				memoryPointsGetInGunner="pos gunner";
				memoryPointsGetInGunnerDir="pos gunner dir";
				gunnerName="Passenger (FFV - Right 02)";
				proxyIndex=4;
				isPersonTurret=1;
				maxElev=50;
				minElev=-5;
				maxTurn=45;
				minTurn=-45;
				class TurnIn
				{
					limitsArrayTop[]=
					{
						{33.820801,-93.961601},
						{40.890598,66.570503}
					};
					limitsArrayBottom[]=
					{
						{-9.4643002,-94.575302},
						{-8.3683004,-67.686699},
						{-9.7173004,43.637199},
						{-10.1082,78.916603}
					};
				};
				class TurnOut: TurnIn
				{
				};
			};
			class CargoTurret_05: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				memoryPointsGetInGunner="pos gunner";
				memoryPointsGetInGunnerDir="pos gunner dir";
				gunnerName="Passenger (FFV - Rear)";
				proxyIndex=5;
				isPersonTurret=1;
				allowLauncherIn=1;
				maxElev=50;
				minElev=-5;
				maxTurn=60;
				minTurn=-60;
				class TurnIn
				{
					limitsArrayTop[]=
					{
						{33.820801,-93.961601},
						{40.890598,66.570503}
					};
					limitsArrayBottom[]=
					{
						{-9.4643002,-94.575302},
						{-8.3683004,-67.686699},
						{-9.7173004,43.637199},
						{-10.1082,78.916603}
					};
				};
				class TurnOut: TurnIn
				{
				};
			};
		};
		attenuationEffectType="OpenCarAttenuation";
		insideSoundCoef=1;
		soundEngineOnInt[]=
		{
			"OPTRE_Vehicles\catfish\data\sounds\Startup",
			"db-5",
			1
		};
		soundEngineOnExt[]=
		{
			"OPTRE_Vehicles\catfish\data\sounds\Startup",
			"db-5",
			1,
			300
		};
		soundEngineOffInt[]=
		{
			"OPTRE_Vehicles\catfish\data\sounds\Shutdown",
			"db-5",
			1
		};
		soundEngineOffExt[]=
		{
			"OPTRE_Vehicles\catfish\data\sounds\Shutdown",
			"db-5",
			1,
			300
		};
		buildCrash0[]=
		{
			"A3\sounds_f\Vehicles\soft\noises\crash_building_01",
			"db0",
			1,
			200
		};
		buildCrash1[]=
		{
			"A3\sounds_f\Vehicles\soft\noises\crash_building_02",
			"db0",
			1,
			200
		};
		buildCrash2[]=
		{
			"A3\sounds_f\Vehicles\soft\noises\crash_building_03",
			"db0",
			1,
			200
		};
		buildCrash3[]=
		{
			"A3\sounds_f\Vehicles\soft\noises\crash_building_04",
			"db0",
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
			"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_01",
			"db0",
			1,
			200
		};
		WoodCrash1[]=
		{
			"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_02",
			"db0",
			1,
			200
		};
		WoodCrash2[]=
		{
			"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_03",
			"db0",
			1,
			200
		};
		WoodCrash3[]=
		{
			"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_04",
			"db0",
			1,
			200
		};
		WoodCrash4[]=
		{
			"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_05",
			"db0",
			1,
			200
		};
		WoodCrash5[]=
		{
			"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_06",
			"db0",
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
			"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_01",
			"db0",
			1,
			200
		};
		ArmorCrash1[]=
		{
			"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_02",
			"db0",
			1,
			200
		};
		ArmorCrash2[]=
		{
			"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_03",
			"db0",
			1,
			200
		};
		ArmorCrash3[]=
		{
			"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_04",
			"db0",
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
			class IdleOut
			{
				sound[]=
				{
					"OPTRE_Vehicles\catfish\data\sounds\idle",
					"db-7",
					1,
					300
				};
				frequency="0.95 + ((rpm/1600) factor[(100/1600),(250/1600)])*0.15";
				volume="engineOn*(((rpm/1600) factor[(100/1600),(150/1600)])*((rpm/1600) factor[(300/1600),(200/1600)]))";
			};
			class Engine
			{
				sound[]=
				{
					"OPTRE_Vehicles\catfish\data\sounds\RPM_1",
					"db-4",
					1,
					350
				};
				frequency="0.85 + ((rpm/1600) factor[(200/1600),(480/1600)])*0.2";
				volume="engineOn*(((rpm/1600) factor[(270/1600),(320/1600)])*((rpm/1600) factor[(530/1600),(450/1600)]))";
			};
			class EngineMidOut
			{
				sound[]=
				{
					"OPTRE_Vehicles\catfish\data\sounds\RPM_2",
					"db-2",
					1,
					380
				};
				frequency="0.85 + ((rpm/1600) factor[(420/1600),(720/1600)])*0.2";
				volume="engineOn*(((rpm/1600) factor[(480/1600),(550/1600)])*((rpm/1600) factor[(720/1600),(650/1600)]))";
			};
			class EngineMaxOut2
			{
				sound[]=
				{
					"OPTRE_Vehicles\catfish\data\sounds\RPM_3",
					"db-1",
					1,
					440
				};
				frequency="0.86 + ((rpm/1600) factor[(680/1600),(1000/1600)])*0.2";
				volume="engineOn*(((rpm/1600) factor[(680/1600),(750/1600)])*((rpm/1600) factor[(1020/1600),(950/1600)]))";
			};
			class EngineMaxOut3
			{
				sound[]=
				{
					"OPTRE_Vehicles\catfish\data\sounds\RPM_4",
					"db0",
					1,
					500
				};
				frequency="0.85 + ((rpm/1600) factor[(900/1600),(1300/1600)])*0.2";
				volume="engineOn*(((rpm/1600) factor[(980/1600),(1050/1600)])*((rpm/1600) factor[(1550/1600),(1220/1600)]))";
			};
			class EngineMaxOut4
			{
				sound[]=
				{
					"OPTRE_Vehicles\catfish\data\sounds\RPM_5",
					"db2",
					1,
					550
				};
				frequency="0.85 + ((rpm/1600) factor[(1200/1600),(1600/1600)])*0.2";
				volume="engineOn*((rpm/1600) factor[(1200/1600),(1600/1600)])";
			};
			class WaternoiseOutW0
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-0-speed1",
					"db-3",
					1,
					150
				};
				frequency="1";
				volume="(speed factor[4, 1])";
			};
			class WaternoiseOutW1
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-20-speed",
					"db-2",
					1,
					250
				};
				frequency="1";
				volume="((speed factor[2, 6]) min (speed factor[6, 4]))";
			};
			class WaternoiseOutW2
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-50-speed",
					"db0",
					1,
					350
				};
				frequency="1";
				volume="(speed factor[3, 9])";
			};
		};
		class Reflectors
		{
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"OPTRE_Vehicles\Catfish\data\optre_catfish_boat.rvmat",
				"OPTRE_Vehicles\Catfish\data\optre_damaged_boat.rvmat",
				"OPTRE_Vehicles\Catfish\data\optre_destroyed_boat.rvmat"
			};
		};
		extCameraPosition[]={0,0.60000002,-10};
		class Eventhandlers: Eventhandlers
		{
			init="if (local (_this select 0)) then {[(_this select 0), """", [], nil] call bis_fnc_initVehicle;};";
			killed="if (local (_this select 0)) then {[(_this select 0), nil, [], false] call bis_fnc_initVehicle;};";
		};
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"\OPTRE_Vehicles\catfish\data\optre_catfish_boat_standard_co.paa"
		};
		class AnimationSources: AnimationSources
		{
			class Proxy
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class Gatling
			{
				source="revolving";
				weapon="OPTRE_M41_LAAG";
			};
			class Gatling_flash
			{
				source="reload";
				weapon="OPTRE_M41_LAAG";
			};
		};
		class textureSources
		{
			class texStandard
			{
				Displayname="Standard";
				author="Article 2 Studios";
				textures[]=
				{
					"41st_Vehicles\Gungan\Data\optre_catfish_boat_FST.paa",
					"\OPTRE_Vehicles\catfish\data\optre_catfish_interior_co.paa",
					"\OPTRE_Vehicles\catfish\data\optre_catfish_seats_co.paa",
					"\OPTRE_Vehicles\catfish\data\optre_catfish_windscreen_ca.paa"

				};
				factions[]=
				{
					"FST_Faction"
				};
			};
		};
		textureList[]=
		{
			"Standard",
			1,
			"Tan",
			1,
			"White",
			1,
			"Black",
			0.5,
			"Green",
			0.5,
			"Cheese",
			0.5
		};
		tf_range=25000;
		tf_isolatedAmount=0.40000001;
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_hasLRradio=1;
	};
	class FST_Boat_Gungan_Unarmed_F: FST_Boat_Gungan_F
	{
		scope=2;
		scopeCurator=2;
		displayName="MC-112 Gungan Patrolcraft (Unarmed)";
		side=1;
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Trooper_P2_DC15S";
		textureList[]=
		{
			"Standard",
			1
		};
	};
	class FST_Boat_Gungan_Z6_F: FST_Boat_Gungan_Unarmed_F
	{
		scope=2;
		scopeCurator=2;
		displayName="MC-112 Gungan Patrolcraft (Z6)";
		model="OPTRE_Vehicles\catfish\optre_catfish_mg";
		side=1;
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Trooper_P2_DC15S";
		textureList[]=
		{
			"Standard",
			1
		};
		class CargoTurret;
		class MainTurret;
		class Turrets: Turrets
		{
			class CargoTurret_01: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				memoryPointsGetInGunner="pos gunner";
				memoryPointsGetInGunnerDir="pos gunner dir";
				gunnerName="Passenger (FFV - Left 01)";
				proxyIndex=1;
				isPersonTurret=1;
				maxElev=50;
				minElev=-5;
				maxTurn=45;
				minTurn=-45;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-65,95};
				};
				class TurnIn
				{
					limitsArrayTop[]=
					{
						{33.820801,-93.961601},
						{40.890598,66.570503}
					};
					limitsArrayBottom[]=
					{
						{-9.4643002,-94.575302},
						{-8.3683004,-67.686699},
						{-9.7173004,43.637199},
						{-10.1082,78.916603}
					};
				};
				class TurnOut: TurnIn
				{
				};
			};
			class CargoTurret_02: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				memoryPointsGetInGunner="pos gunner";
				memoryPointsGetInGunnerDir="pos gunner dir";
				gunnerName="Passenger (FFV - Left 02)";
				proxyIndex=2;
				isPersonTurret=1;
				maxElev=50;
				minElev=-5;
				maxTurn=45;
				minTurn=-45;
				class TurnIn
				{
					limitsArrayTop[]=
					{
						{33.820801,-93.961601},
						{40.890598,66.570503}
					};
					limitsArrayBottom[]=
					{
						{-9.4643002,-94.575302},
						{-8.3683004,-67.686699},
						{-9.7173004,43.637199},
						{-10.1082,78.916603}
					};
				};
				class TurnOut: TurnIn
				{
				};
			};
			class CargoTurret_03: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				memoryPointsGetInGunner="pos gunner";
				memoryPointsGetInGunnerDir="pos gunner dir";
				gunnerName="Passenger (FFV - Right 01)";
				proxyIndex=3;
				isPersonTurret=1;
				maxElev=50;
				minElev=-5;
				maxTurn=45;
				minTurn=-45;
				class TurnIn
				{
					limitsArrayTop[]=
					{
						{33.820801,-93.961601},
						{40.890598,66.570503}
					};
					limitsArrayBottom[]=
					{
						{-9.4643002,-94.575302},
						{-8.3683004,-67.686699},
						{-9.7173004,43.637199},
						{-10.1082,78.916603}
					};
				};
				class TurnOut: TurnIn
				{
				};
			};
			class CargoTurret_04: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				memoryPointsGetInGunner="pos gunner";
				memoryPointsGetInGunnerDir="pos gunner dir";
				gunnerName="Passenger (FFV - Right 02)";
				proxyIndex=4;
				isPersonTurret=1;
				maxElev=50;
				minElev=-5;
				maxTurn=45;
				minTurn=-45;
				class TurnIn
				{
					limitsArrayTop[]=
					{
						{33.820801,-93.961601},
						{40.890598,66.570503}
					};
					limitsArrayBottom[]=
					{
						{-9.4643002,-94.575302},
						{-8.3683004,-67.686699},
						{-9.7173004,43.637199},
						{-10.1082,78.916603}
					};
				};
				class TurnOut: TurnIn
				{
				};
			};
			class CargoTurret_05: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				memoryPointsGetInGunner="pos gunner";
				memoryPointsGetInGunnerDir="pos gunner dir";
				gunnerName="Passenger (FFV - Rear)";
				proxyIndex=5;
				isPersonTurret=1;
				allowLauncherIn=1;
				maxElev=50;
				minElev=-5;
				maxTurn=60;
				minTurn=-60;
				class TurnIn
				{
					limitsArrayTop[]=
					{
						{33.820801,-93.961601},
						{40.890598,66.570503}
					};
					limitsArrayBottom[]=
					{
						{-9.4643002,-94.575302},
						{-8.3683004,-67.686699},
						{-9.7173004,43.637199},
						{-10.1082,78.916603}
					};
				};
				class TurnOut: TurnIn
				{
				};
			};
			class MainTurret: NewTurret
			{
				body="mainTurret";
				gun="mainGun";
				animationsourcebody="mainTurret";
				animationSourceGun="mainGun";
				gunAxis="Osa Hlavne";
				gunBeg="Usti hlavne";
				gunEnd="konec hlavne";
				LODTurnedOut=1100;
				LODTurnedIn=1100;
				LODOpticsIn=1100;
				LODOpticsOut=1100;
				ejectDeadGunner=0;
				minElev=-15;
				maxElev=30;
				minTurn=-360;
				maxTurn=360;
				initTurn=0;
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
				proxyIndex=1;
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
				gunnerForceOptics=0;
				hasGunner=1;
				discreteDistance[]={100,200,300,400,600,800,1000,1200};
				discreteDistanceInitIndex=2;
				class ViewGunner: ViewOptics
				{
					initAngleX=-15;
					minAngleX=-45;
					maxAngleX=45;
					initFov=0.89999998;
					minFov=0.41999999;
					maxFov=0.89999998;
					visionMode[]={};
				};
			};
		};
		hiddenSelections[]=
		{
			"camo",
			"camoInterior",
			"camoSeat",
			"camoWindow",
			"Camo3",
			"camo_sight",
			"camo_turret_decal"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\Gungan\Data\optre_catfish_boat_FST.paa",
			"\OPTRE_Vehicles\catfish\data\optre_catfish_interior_co.paa",
			"\OPTRE_Vehicles\catfish\data\optre_catfish_seats_co.paa",
			"\OPTRE_Vehicles\catfish\data\optre_catfish_windscreen_ca.paa",
			"\OPTRE_Vehicles\Warthog\data\snow\m12_turret_snow_co.paa",
			"\optre_vehicles\warthog\data\turrets\sight_co.paa",
			""
		};
	};
};
