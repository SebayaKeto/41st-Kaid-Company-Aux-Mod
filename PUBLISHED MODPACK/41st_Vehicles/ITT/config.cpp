class CfgPatches
{
	class FST_ITT
	{
		requiredAddons[]=
		{
			"A3_Armor_F_Beta"
		};
		units[]=
		{
			"FST_ITT",
			"FST_ITT_Medical",
			"FST_ITT_Logistic"
		};
		weapons[]={};
		author="$STR_3AS_Studio";
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
class DefaultEventHandlers;
class EventHandlers;
class AnimationSources;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class RCWSOptics;
class Optics_Armored;
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
class Optics_Gunner_APC_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class CargoTurret;
class CfgVehicles
{
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
	class APC_Wheeled_01_base_F: Wheeled_APC_F
	{
	};
	class FST_ITT_Base: APC_Wheeled_01_base_F
	{
		thrustDelay=0.1;
		brakeIdleSpeed=1.78;
		maxSpeed=110;
		fuelCapacity=50;
		wheelCircumference=2.8365002;
		normalSpeedForwardCoef=0.89999998;
		antiRollbarForceCoef=24;
		antiRollbarForceLimit=30;
		antiRollbarSpeedMin=15;
		antiRollbarSpeedMax=70;
		idleRpm=500;
		redRpm=2200;
		maxOmega=275;
		minOmega=50;
		ace_cargo_hasCargo=1;
		ace_cargo_space=1000;
		torqueCurve[]=
		{
			
			{
				"(0/2300)",
				"(0/2260)"
			},
			
			{
				"(500/2300)",
				"(2000/2260)"
			},
			
			{
				"(1400/2300)",
				"(2100/2260)"
			},
			
			{
				"(1500/2300)",
				"(2200/2260)"
			},
			
			{
				"(1550/2300)",
				"(2260/2260)"
			},
			
			{
				"(1600/2300)",
				"(2200/2260)"
			},
			
			{
				"(2300/2300)",
				"(1700/2260)"
			},
			
			{
				"(4700/2300)",
				"(0/2260)"
			}
		};
		changeGearMinEffectivity[]={0.94999999,0.15000001,0.97000003,0.97000003,0.97000003,0.97000003,0.97000003,0.98500001};
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-4.8400002,
				"N",
				0,
				"D1",
				3.4300001,
				"D2",
				2.01,
				"D3",
				1.42,
				"D4",
				0.89999998
			};
			TransmissionRatios[]=
			{
				"High",
				10
			};
			AmphibiousRatios[]=
			{
				"R1",
				-30,
				"N",
				0,
				"D1",
				8
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
		};
		tf_range=100000;
		tf_isolatedAmount=0.40000001;
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_hasLRradio=1;
		simulation="carx";
		damperSize=0.2;
		damperForce=1;
		damperDamping=1;
		dampersBumpCoef=6;
		differentialType="all_limited";
		frontRearSplit=0.5;
		frontBias=1.3;
		rearBias=1.3;
		centreBias=1;
		clutchStrength=180;
		enginePower=6000;
		peakTorque=8825;
		dampingRateFullThrottle=0.079999998;
		dampingRateZeroThrottleClutchEngaged=2;
		dampingRateZeroThrottleClutchDisengaged=0.050000001;
		switchTime=0.2;
		latency=1;
		class Wheels
		{
			class L1
			{
				boneName="wheel_1_1_damper";
				steering=1;
				side="left";
				center="wheel_1_1_axis";
				boundary="wheel_1_1_bound";
				width="0.2";
				mass=30;
				MOI=15;
				dampingRate=1.75;
				dampingRateDamaged=1;
				dampingRateDestroyed=1000;
				maxBrakeTorque=6500;
				maxHandBrakeTorque=0;
				suspTravelDirection[]={0,-1,0};
				suspForceAppPointOffset="wheel_1_1_axis";
				tireForceAppPointOffset="wheel_1_1_axis";
				maxCompression=0.25;
				maxDroop=0.25;
				sprungMass=1875;
				springStrength=46000;
				springDamperRate=21000;
				longitudinalStiffnessPerUnitGravity=10000;
				latStiffX=25;
				latStiffY=180;
				frictionVsSlipGraph[]=
				{
					{0,1},
					{0.5,1},
					{1,1}
				};
			};
			class R1: L1
			{
				steering=1;
				boneName="wheel_2_1_damper";
				center="wheel_2_1_axis";
				boundary="wheel_2_1_bound";
				suspForceAppPointOffset="wheel_2_1_axis";
				tireForceAppPointOffset="wheel_2_1_axis";
				side="right";
			};
			class L2: L1
			{
				boneName="wheel_1_2_damper";
				steering=1;
				maxHandBrakeTorque=6500;
				center="wheel_1_2_axis";
				boundary="wheel_1_2_bound";
				suspForceAppPointOffset="wheel_1_2_axis";
				tireForceAppPointOffset="wheel_1_2_axis";
			};
			class L3: L1
			{
				boneName="wheel_1_3_damper";
				steering=0;
				maxHandBrakeTorque=6500;
				center="wheel_1_3_axis";
				boundary="wheel_1_3_bound";
				suspForceAppPointOffset="wheel_1_3_axis";
				tireForceAppPointOffset="wheel_1_3_axis";
			};
			class L4: L1
			{
				boneName="wheel_1_4_damper";
				steering=0;
				center="wheel_1_4_axis";
				boundary="wheel_1_4_bound";
				maxHandBrakeTorque=6500;
				suspForceAppPointOffset="wheel_1_4_axis";
				tireForceAppPointOffset="wheel_1_4_axis";
			};
			class R2: R1
			{
				boneName="wheel_2_2_damper";
				steering=1;
				maxHandBrakeTorque=6500;
				center="wheel_2_2_axis";
				boundary="wheel_2_2_bound";
				suspForceAppPointOffset="wheel_2_2_axis";
				tireForceAppPointOffset="wheel_2_2_axis";
			};
			class R3: R1
			{
				boneName="wheel_2_3_damper";
				steering=0;
				maxHandBrakeTorque=6500;
				center="wheel_2_3_axis";
				boundary="wheel_2_3_bound";
				suspForceAppPointOffset="wheel_2_3_axis";
				tireForceAppPointOffset="wheel_2_3_axis";
			};
			class R4: R1
			{
				boneName="wheel_2_4_damper";
				steering=0;
				center="wheel_2_4_axis";
				boundary="wheel_2_4_bound";
				maxHandBrakeTorque=6500;
				suspForceAppPointOffset="wheel_2_4_axis";
				tireForceAppPointOffset="wheel_2_4_axis";
			};
		};
		terrainCoef=1.5;
		turnCoef=2;
		canFloat=1;
		engineShiftY=1;
		waterPPInVehicle=0;
		waterResistance=0.0099999998;
		waterResistanceCoef=0.0099999998;
		waterAngularDampingCoef=5;
		waterLinearDampingCoefX=10;
		waterLinearDampingCoefY=2;
		rudderForceCoef=1;
		rudderForceCoefAtMaxSpeed=0.15000001;
		waterSpeedFactor=2;
		memoryPointsLeftEngineEffect="EngineEffectL";
		memoryPointsRightEngineEffect="EngineEffectR";
		numberPhysicalWheels=8;
		displayName="[41st] ITT";
		model="3AS\3as_ITT\model\3as_ITT.p3d";
		author="$STR_3AS_Studio";
		destrType="DestructWreck";
		editorSubcategory="FST_Ground_Vehicle";
		picture="3AS\3as_ITT\data\ui\ITT_Side_ca.paa";
		icon="3AS\3as_ITT\data\ui\ITT_top_ca.paa";
		tas_canBlift=1;
		tas_liftVars="[[[[0,-4,-6.5]]], [-0.001], [-0.4]]";
		weapons[]=
		{
			"TruckHorn2"
		};
		memoryPointsGetInDriver="pos driver";
		memoryPointsGetInDriverDir="pos driver dir";
		driverOpticsModel="\a3\weapons_f\reticle\Optics_Driver_01_F";
		magazines[]={};
		cost=1500000;
		crewCrashProtection=9.9999997e-005;
		damageResistance=0.02;
		crewVulnerable=1;
		armor=700;
		armorStructural=8.5;
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=3.5;
				material=-1;
				name="telo";
				visual="zbytek";
				passThrough=1;
				minimalHit=0.14;
				explosionShielding=2;
				radius=0.25;
			};
			class HitEngine: HitEngine
			{
				armor=1;
				material=-1;
				name="motor";
				passThrough=0.80000001;
				minimalHit=0.23999999;
				explosionShielding=1;
				radius=0.33000001;
			};
			class HitFuel: HitFuel
			{
				armor=1.5;
				material=-1;
				name="palivo";
				passThrough=1;
				minimalHit=0.1;
				explosionShielding=0.40000001;
				radius=0.25;
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
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets
				{
				};
				memoryPointGun[]=
				{
					"usti hlavne",
					"usti hlavne1"
				};
				gunEnd="konec hlavne";
				gunBeg="usti hlavne";
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				gunnerCompartments="Compartment3";
				weapons[]=
				{
					"FST_30mm_Autocannon",
					"Laserdesignator_pilotCamera",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"FST_thermal_coil",
					"FST_thermal_coil",
					"Laserbatteries",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
					"SmokeLauncherMag"
				};
				selectionFireAnim="Zasleh_Top";
				minElev=-5;
				maxElev=45;
				initElev=5;
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner",
					0.56234133,
					1,
					50
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner_vertical",
					0.56234133,
					1,
					50
				};
				startEngine=0;
				usepip=2;
				showCrewAim=2;
				stabilizedInAxes=3;
				maxHorizontalRotSpeed=0.85000002;
				maxVerticalRotSpeed=0.55000001;
				turretInfoType="RscWeaponRangeZeroing";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400};
				discreteDistanceInitIndex=2;
				memoryPointGunnerOptics="gunnerview";
				gunnerOutOpticsModel="";
				gunnerOutOpticsEffect[]={};
				gunnerOpticsEffect[]={};
				gunnerForceOptics=0;
				gunnerAction="Saber_Driver";
				gunnerInAction="Commander_APC_Wheeled_01_in";
				gunnerGetInAction="GetInLow";
				gunnerGetOutAction="GetOutLow";
				forceHideGunner=1;
				inGunnerMayFire=1;
				viewGunnerInExternal=1;
				proxyIndex=2;
				proxytype="CPGunner";
				class OpticsIn: Optics_Gunner_APC_01
				{
					class Wide: Wide
					{
						gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_02_w_F.p3d";
						gunnerOpticsEffect[]={};
					};
					class Medium: Medium
					{
						gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_02_m_F.p3d";
					};
					class Narrow: Narrow
					{
						gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_MTB_02_n_F.p3d";
					};
				};
				class HitPoints
				{
					class HitTurret
					{
						armor=0.80000001;
						material=-1;
						name="mainturret";
						passthrough=0.5;
						visual="mainturret";
					};
					class HitGun
					{
						armor=0.40000001;
						material=-1;
						name="maingun";
						passthrough=0.2;
						visual="maingun";
					};
				};
			};
			class CommanderTurret: MainTurret
			{
				memoryPointGun[]=
				{
					"usti hlavne2",
					"usti hlavne3"
				};
				gunEnd="konec hlavne2";
				gunBeg="usti hlavne2";
				weapons[]=
				{
					"FST_30mm_Autocannon"
				};
				magazines[]=
				{
					"FST_thermal_coil",
					"FST_thermal_coil",
				};
				minElev=-12.5;
				maxElev=12.5;
				initElev=0;
				minTurn=-12.5;
				maxTurn=12.5;
				memoryPointGunnerOptics="Commanderview";
				gunnerName="Commander";
				proxyIndex=1;
				animationSourceBody="obTurret";
				animationSourceGun="obGun";
				body="obTurret";
				gun="obGun";
				gunnerAction="CoDriver_Van_02";
				gunnerInAction="CoDriver_Van_02";
				selectionFireAnim="Zasleh";
				LODTurnedIn=1000;
				class HitPoints
				{
					class HitGun
					{
						armor=0.40000001;
						material=-1;
						name="commandergun";
						passthrough=0.2;
						visual="none";
					};
				};
			};
			class CargoTurret_01: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				canHideGunner=0;
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerName="Exterior Gunner";
				proxyIndex=11;
				soundAttenuationTurret="HeliAttenuationGunner";
				isPersonTurret=1;
				ejectDeadGunner=1;
				class dynamicViewLimits
				{
					CargoTurret_04[]={-65,95};
				};
				playerPosition=4;
				gunnerGetInAction="GetInHeli_Light_01bench";
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerAction="vehicle_coshooter_1";
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerName="Exterior Gunner Top Right 1";
				proxyIndex=15;
				class dynamicViewLimits
				{
					CargoTurret_03[]={-65,95};
				};
			};
			class CargoTurret_03: CargoTurret_02
			{
				gunnerAction="passenger_inside_1";
				gunnerCompartments="Compartment2";
				gunnerName="Exterior Gunner Top Right 2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=13;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-95,65};
				};
			};
			class CargoTurret_04: CargoTurret_01
			{
				gunnerAction="passenger_inside_3";
				gunnerCompartments="Compartment2";
				gunnerName="Exterior Gunner Top Left 2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=14;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,65};
				};
			};
			class CargoTurret_05: CargoTurret
			{
				gunnerAction="passenger_inside_7";
				canHideGunner=0;
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerName="Exterior Gunner Top Left 3";
				proxyIndex=12;
				soundAttenuationTurret="HeliAttenuationGunner";
				isPersonTurret=1;
				ejectDeadGunner=1;
				class dynamicViewLimits
				{
					CargoTurret_04[]={-65,95};
				};
				playerPosition=4;
				gunnerGetInAction="GetInHeli_Light_01bench";
			};
			class CargoTurret_06: CargoTurret_01
			{
				gunnerAction="passenger_inside_3";
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerName="Exterior Gunner Top Right 3";
				proxyIndex=18;
				class dynamicViewLimits
				{
					CargoTurret_03[]={-65,95};
				};
			};
			class CargoTurret_07: CargoTurret_02
			{
				gunnerAction="passenger_inside_1";
				gunnerCompartments="Compartment2";
				gunnerName="Exterior Gunner Top Right 4";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=17;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-95,65};
				};
			};
			class CargoTurret_08: CargoTurret_01
			{
				gunnerAction="passenger_bench_1";
				gunnerCompartments="Compartment2";
				gunnerName="Exterior Gunner Top Left 4";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=16;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,65};
				};
			};
			class CargoTurret_09: CargoTurret
			{
				gunnerAction="vehicle_passenger_stand_01";
				canHideGunner=0;
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerName="Right Side Gunner 1";
				proxyIndex=19;
				soundAttenuationTurret="HeliAttenuationGunner";
				isPersonTurret=1;
				ejectDeadGunner=1;
				class dynamicViewLimits
				{
					CargoTurret_04[]={-65,95};
				};
				playerPosition=4;
				gunnerGetInAction="GetInHeli_Light_01bench";
			};
			class CargoTurret_10: CargoTurret_09
			{
				gunnerCompartments="Compartment2";
				gunnerName="Right Side Gunner 2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=20;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,65};
				};
			};
			class CargoTurret_11: CargoTurret_10
			{
				gunnerCompartments="Compartment2";
				gunnerName="Right Side Gunner 3";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=21;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,65};
				};
			};
			class CargoTurret_12: CargoTurret_01
			{
				gunnerAction="vehicle_passenger_stand_01";
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerName="Left Side Gunner 1";
				proxyIndex=22;
				class dynamicViewLimits
				{
					CargoTurret_03[]={-65,95};
				};
			};
			class CargoTurret_13: CargoTurret_12
			{
				gunnerCompartments="Compartment2";
				gunnerName="Left Side Gunner 2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=23;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-95,65};
				};
			};
			class CargoTurret_14: CargoTurret_13
			{
				gunnerCompartments="Compartment2";
				gunnerName="Left Side Gunner 3";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=24;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-95,65};
				};
			};
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3as\3as_ITT\data\ITT.rvmat",
				"3as\3as_ITT\data\ITT.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat",
				"3as\3as_ITT\data\Glass.rvmat",
				"3as\3as_ITT\data\Glass.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat",
				"3as\3as_ITT\data\Back_Interior.rvmat",
				"3as\3as_ITT\data\Back_Interior.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat",
				"3as\3as_ITT\data\Door.rvmat",
				"3as\3as_ITT\data\Door.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat",
				"3as\3as_ITT\data\Front_Interior.rvmat",
				"3as\3as_ITT\data\Front_Interior.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat",
				"3as\3as_ITT\data\Emissive.rvmat",
				"3as\3as_ITT\data\Emissive.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat",
				"3as\3as_ITT\data\Turret.rvmat",
				"3as\3as_ITT\data\Turret.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat"
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
		class Exhausts
		{
			class Exhaust_1
			{
				position="Exhaust1_";
				direction="Exhaust1_dir";
				effect="ExhaustsEffectHeliBig";
			};
			class Exhaust_2
			{
				position="Exhaust2";
				direction="Exhaust2_dir";
				effect="ExhaustsEffectHeliBig";
			};
		};
		class Reflectors
		{
			class Left
			{
				color[]={1900,1300,950};
				ambient[]={5,5,5};
				position="Light_L";
				direction="Light_L_end";
				hitpoint="Light_L";
				selection="Light_L";
				size=1;
				innerAngle=100;
				outerAngle=179;
				coneFadeCoef=10;
				intensity=1;
				useFlare=1;
				dayLight=0;
				flareSize=1;
				class Attenuation
				{
					start=1;
					constant=0;
					linear=0;
					quadratic=0.25;
					hardLimitStart=30;
					hardLimitEnd=60;
				};
			};
			class Right: Left
			{
				position="Light_R";
				direction="Light_R_end";
				hitpoint="Light_R";
				selection="Light_R";
			};
			class Right2: Right
			{
				position="light_R_flare";
				useFlare=1;
			};
			class Left2: Left
			{
				position="light_L_flare";
				useFlare=1;
			};
		};
		aggregateReflectors[]=
		{
			
			{
				"Left",
				"Right",
				"Left2",
				"Right2"
			}
		};
		driverAction="Saber_Driver";
		driverInAction="Commander_APC_Wheeled_01_in";
		driverLeftHandAnimName="drivingstick_left";
		driverRightHandAnimName="drivingstick_right";
		driverLeftLegAnimName="pedal_brake";
		driverRightLegAnimName="pedal_thrust";
		viewDriverInExternal=1;
		DriverForceOptics=0;
		memoryPointTrack1L="Track LL";
		memoryPointTrack1R="Track LR";
		memoryPointTrack2L="Track RL";
		memoryPointTrack2R="Track RR";
		dustFrontLeftPos="dustFrontLeft";
		dustFrontRightPos="dustFrontRight";
		dustBackLeftPos="dustBackLeft";
		dustBackRightPos="dustBackRight";
		forceHideDriver=1;
		getInAction="GetInlow";
		getOutAction="GetOutLow";
		cargoGetInAction[]=
		{
			"GetInlow",
			"GetInlow"
		};
		cargoAction[]=
		{
			"Aegis_Cargo",
			"Aegis_Cargo2",
			"Aegis_Cargo",
			"Aegis_Cargo2",
			"Aegis_Cargo",
			"Aegis_Cargo2",
			"Aegis_Cargo",
			"Aegis_Cargo2",
			"Aegis_Cargo",
			"Aegis_Cargo2",
			"Aegis_Cargo",
			"Aegis_Cargo2"
		};
		cargoIsCoDriver[]={0};
		cargoGetOutAction[]=
		{
			"GetOutMedium"
		};
		hideWeaponsDriver=1;
		hideWeaponsCargo=0;
		driverCompartments="Compartment3";
		cargoCompartments[]=
		{
			"Compartment1"
		};
		transportSoldier=12;
		cargoProxyIndexes[]={1,2,3,4,5,6,7,8,9,10,25,26};
		getInProxyOrder[]={1,2,3,4,5,6,7,8,9,10,25,26};
		faction="FST_Faction";
		extCameraPosition[]={0,4,-15};
		class UserActions
		{
			class open
			{
				radius=10;
				position="action";
				priority=11;
				onlyForPlayer=0;
				displayName="Open Doors";
				condition="(this animationSourcePhase ""open_door"" == 0)  AND (currentPilot this isEqualTo player) AND (alive this)";
				statement="this animateSource [""open_door"",2]";
			};
			class close
			{
				displayName="Close Doors";
				position="action";
				radius=10;
				priority=11;
				onlyForPlayer=0;
				condition="(this animationSourcePhase ""open_door"" == 2) AND (currentPilot this isEqualTo player) AND (alive this)";
				statement="this animateSource [""open_door"",0]";
			};
		};
		class AnimationSources
		{
			class open_door
			{
				source="user";
				animPeriod=2;
				initPhase=0;
			};
			class Turrets
			{
				source="user";
				animPeriod=1;
				initPhase=1;
			};
			class Muzzle_Flash
			{
				source="ammorandom";
				weapon="3as_ITT_Front_20mm";
			};
			class Muzzle_Flash2
			{
				source="ammorandom";
				weapon="3as_ITT_Turret_MG";
			};
		};
		soundGetIn[]=
		{
			"A3\sounds_f\vehicles\armor\noises\get_in_out",
			0.56234133,
			1
		};
		soundGetOut[]=
		{
			"A3\sounds_f\vehicles\armor\noises\get_in_out",
			0.56234133,
			1,
			20
		};
		soundTurnIn[]=
		{
			"A3\Sounds_F\vehicles\noises\Turn_in_out",
			1.7782794,
			1,
			20
		};
		soundTurnOut[]=
		{
			"A3\Sounds_F\vehicles\noises\Turn_in_out",
			1.7782794,
			1,
			20
		};
		soundTurnInInternal[]=
		{
			"A3\Sounds_F\vehicles\noises\Turn_in_out",
			1.7782794,
			1,
			20
		};
		soundTurnOutInternal[]=
		{
			"A3\Sounds_F\vehicles\noises\Turn_in_out",
			1.7782794,
			1,
			20
		};
		soundDammage[]=
		{
			"",
			0.56234133,
			1
		};
		soundEngineOnInt[]=
		{
			"A3\Sounds_F\vehicles\armor\APC\APC1\int_engine_start",
			0.39810717,
			1
		};
		soundEngineOnExt[]=
		{
			"A3\Sounds_F\vehicles\armor\APC\APC1\ext_engine_start",
			0.56234133,
			1,
			200
		};
		soundEngineOffInt[]=
		{
			"A3\Sounds_F\vehicles\armor\APC\APC1\int_engine_stop",
			0.39810717,
			1
		};
		soundEngineOffExt[]=
		{
			"A3\Sounds_F\vehicles\armor\APC\APC1\ext_engine_stop",
			0.56234133,
			1,
			200
		};
		soundBushCollision1[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_1",
			0.17782794,
			1,
			100
		};
		soundBushCollision2[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_2",
			0.17782794,
			1,
			100
		};
		soundBushCollision3[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_3",
			0.17782794,
			1,
			100
		};
		soundBushCrash[]=
		{
			"soundBushCollision1",
			0.33000001,
			"soundBushCollision2",
			0.33000001,
			"soundBushCollision3",
			0.33000001
		};
		soundGeneralCollision1[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_crash_default_1",
			1,
			1,
			100
		};
		soundGeneralCollision2[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_crash_default_2",
			1,
			1,
			100
		};
		soundGeneralCollision3[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_crash_default_3",
			1,
			1,
			100
		};
		soundGeneralCollision4[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_crash_default_4",
			1,
			1,
			100
		};
		soundCrashes[]=
		{
			"soundGeneralCollision1",
			0.25,
			"soundGeneralCollision2",
			0.25,
			"soundGeneralCollision3",
			0.25,
			"soundGeneralCollision4",
			0.25
		};
		buildCrash0[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_building_1",
			1,
			1,
			200
		};
		buildCrash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_building_2",
			1,
			1,
			200
		};
		buildCrash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_building_3",
			1,
			1,
			200
		};
		buildCrash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_building_4",
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
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_wood_1",
			1,
			1,
			200
		};
		WoodCrash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_wood_2",
			1,
			1,
			200
		};
		WoodCrash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_wood_3",
			1,
			1,
			200
		};
		WoodCrash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_wood_4",
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
			0.16599999
		};
		ArmorCrash0[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_armor_1",
			1,
			1,
			200
		};
		ArmorCrash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_armor_2",
			1,
			1,
			200
		};
		ArmorCrash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_armor_3",
			1,
			1,
			200
		};
		ArmorCrash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_armor_4",
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
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_engine_01",
					0.3548134,
					1,
					200
				};
				frequency="0.95 + ((rpm/ 2300) factor[(10/ 2300),(200/ 2300)])*0.15";
				volume="engineOn*camPos*(((rpm/ 2300) factor[(10/ 2300),(200/ 2300)]) * ((rpm/ 2300) factor[(500/ 2300),(425/ 2300)]))";
			};
			class Engine
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_engine_02",
					0.39810717,
					1,
					200
				};
				frequency="0.8 + ((rpm/ 2300) factor[(430/ 2300),(730/ 2300)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2300) factor[(430/ 2300),(510/ 2300)]) * ((rpm/ 2300) factor[(730/ 2300),(620/ 2300)]))";
			};
			class Engine1_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_engine_03",
					0.44668359,
					1,
					200
				};
				frequency="0.8 + ((rpm/ 2300) factor[(630/ 2300),(1000/ 2300)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2300) factor[(600/ 2300),(720/ 2300)]) * ((rpm/ 2300) factor[(1100/ 2300),(840/ 2300)]))";
			};
			class Engine2_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_engine_06",
					0.50118721,
					1,
					250
				};
				frequency="0.8 + ((rpm/ 2300) factor[(850/ 2300),(1300/ 2300)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2300) factor[(800/ 2300),(1000/ 2300)]) * ((rpm/ 2300) factor[(1300/ 2300),(1100/ 2300)]))";
			};
			class Engine3_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_engine_07",
					0.56234133,
					1,
					300
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1100/ 2300),(1600/ 2300)])*0.1";
				volume="engineOn*camPos*(((rpm/ 2300) factor[(1100/ 2300),(1270/ 2300)]) * ((rpm/ 2300) factor[(1550/ 2300),(1380/ 2300)]))";
			};
			class Engine4_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_engine_08",
					0.63095737,
					1,
					300
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1400/ 2300),(2000/ 2300)])*0.1";
				volume="engineOn*camPos*(((rpm/ 2300) factor[(1380/ 2300),(1500/ 2300)]) * ((rpm/ 2300) factor[(2000/ 2300),(1700/ 2300)]))";
			};
			class Engine5_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_engine_10",
					0.70794576,
					1,
					300
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1700/ 2300),(2300/ 2300)])*0.1";
				volume="engineOn*camPos*((rpm/ 2300) factor[(1600/ 2300),(2100/ 2300)])";
			};
			class IdleThrust
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_exhaust_01",
					0.56234133,
					1,
					200
				};
				frequency="0.8 + ((rpm/ 2300) factor[(10/ 2300),(200/ 2300)])*0.15";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(10/ 2300),(200/ 2300)]) * ((rpm/ 2300) factor[(500/ 2300),(425/ 2300)]))";
			};
			class EngineThrust
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_exhaust_02",
					0.63095737,
					1,
					200
				};
				frequency="0.8 + ((rpm/ 2300) factor[(430/ 2300),(730/ 2300)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(430/ 2300),(510/ 2300)]) * ((rpm/ 2300) factor[(730/ 2300),(620/ 2300)]))";
			};
			class Engine1_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_exhaust_03",
					0.63095737,
					1,
					230
				};
				frequency="0.8 + ((rpm/ 2300) factor[(630/ 2300),(1000/ 2300)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(600/ 2300),(720/ 2300)]) * ((rpm/ 2300) factor[(1100/ 2300),(840/ 2300)]))";
			};
			class Engine2_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_exhaust_06",
					0.70794576,
					1,
					250
				};
				frequency="0.8 + ((rpm/ 2300) factor[(850/ 2300),(1300/ 2300)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(800/ 2300),(1000/ 2300)]) * ((rpm/ 2300) factor[(1300/ 2300),(1100/ 2300)]))";
			};
			class Engine3_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_exhaust_07",
					0.70794576,
					1,
					350
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1100/ 2300),(1600/ 2300)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(1100/ 2300),(1270/ 2300)]) * ((rpm/ 2300) factor[(1550/ 2300),(1380/ 2300)]))";
			};
			class Engine4_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_exhaust_08",
					1,
					1,
					350
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1400/ 2300),(2000/ 2300)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(1380/ 2300),(1500/ 2300)]) * ((rpm/ 2300) factor[(2000/ 2300),(1700/ 2300)]))";
			};
			class Engine5_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_exhaust_10",
					1.1220185,
					1,
					400
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1700/ 2300),(2300/ 2300)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 2300) factor[(1600/ 2300),(2100/ 2300)])";
			};
			class Idle_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_engine_01",
					0.31622776,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(10/ 2300),(200/ 2300)])*0.15";
				volume="engineOn*(1-camPos)*(((rpm/ 2300) factor[(10/ 2300),(200/ 2300)]) * ((rpm/ 2300) factor[(500/ 2300),(425/ 2300)]))";
			};
			class Engine_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_engine_02",
					0.3548134,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(430/ 2300),(730/ 2300)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2300) factor[(430/ 2300),(510/ 2300)]) * ((rpm/ 2300) factor[(730/ 2300),(620/ 2300)]))";
			};
			class Engine1_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_engine_03",
					0.39810717,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(630/ 2300),(1000/ 2300)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2300) factor[(600/ 2300),(720/ 2300)]) * ((rpm/ 2300) factor[(1100/ 2300),(840/ 2300)]))";
			};
			class Engine2_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_engine_06",
					0.44668359,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(850/ 2300),(1300/ 2300)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2300) factor[(800/ 2300),(1000/ 2300)]) * ((rpm/ 2300) factor[(1300/ 2300),(1100/ 2300)]))";
			};
			class Engine3_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_engine_07",
					0.50118721,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1100/ 2300),(1600/ 2300)])*0.1";
				volume="engineOn*(1-camPos)*(((rpm/ 2300) factor[(1100/ 2300),(1270/ 2300)]) * ((rpm/ 2300) factor[(1550/ 2300),(1380/ 2300)]))";
			};
			class Engine4_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_engine_08",
					0.56234133,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1400/ 2300),(2000/ 2300)])*0.1";
				volume="engineOn*(1-camPos)*(((rpm/ 2300) factor[(1380/ 2300),(1500/ 2300)]) * ((rpm/ 2300) factor[(2000/ 2300),(1700/ 2300)]))";
			};
			class Engine5_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_engine_10",
					0.63095737,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1700/ 2300),(2300/ 2300)])*0.1";
				volume="engineOn*(1-camPos)*((rpm/ 2300) factor[(1600/ 2300),(2100/ 2300)])";
			};
			class IdleThrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_exhaust_01",
					0.3548134,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(10/ 2300),(200/ 2300)])*0.15";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(10/ 2300),(200/ 2300)]) * ((rpm/ 2300) factor[(500/ 2300),(425/ 2300)]))";
			};
			class EngineThrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_exhaust_02",
					0.39810717,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(430/ 2300),(730/ 2300)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(430/ 2300),(510/ 2300)]) * ((rpm/ 2300) factor[(730/ 2300),(620/ 2300)]))";
			};
			class Engine1_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_exhaust_03",
					0.44668359,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(630/ 2300),(1000/ 2300)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(600/ 2300),(720/ 2300)]) * ((rpm/ 2300) factor[(1100/ 2300),(840/ 2300)]))";
			};
			class Engine2_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_exhaust_06",
					0.44668359,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(850/ 2300),(1300/ 2300)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(800/ 2300),(1000/ 2300)]) * ((rpm/ 2300) factor[(1300/ 2300),(1100/ 2300)]))";
			};
			class Engine3_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_exhaust_07",
					0.50118721,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1100/ 2300),(1600/ 2300)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(1100/ 2300),(1270/ 2300)]) * ((rpm/ 2300) factor[(1550/ 2300),(1380/ 2300)]))";
			};
			class Engine4_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_exhaust_08",
					0.56234133,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1400/ 2300),(2000/ 2300)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(1380/ 2300),(1500/ 2300)]) * ((rpm/ 2300) factor[(2000/ 2300),(1700/ 2300)]))";
			};
			class Engine5_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_exhaust_10",
					0.63095737,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1700/ 2300),(2300/ 2300)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 2300) factor[(1600/ 2300),(2100/ 2300)])";
			};
			class NoiseInt
			{
				sound[]=
				{
					"A3\sounds_f\vehicles\armor\noises\noise_tank_int_1",
					0.50118721,
					1
				};
				frequency="1";
				volume="(1-camPos)*(angVelocity max 0.04)*(Speed factor[4, 15])";
			};
			class NoiseExt
			{
				sound[]=
				{
					"A3\sounds_f\vehicles\armor\noises\noise_tank_ext_1",
					0.63095737,
					1,
					150
				};
				frequency="1";
				volume="camPos*(angVelocity max 0.04)*(Speed factor[4, 15])";
			};
			class TiresRockOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_1",
					1,
					1,
					60
				};
				frequency="1";
				volume="camPos*rock*(Speed factor[2, 20])";
			};
			class TiresSandOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\ext-tires-sand1",
					1,
					1,
					60
				};
				frequency="1";
				volume="camPos*sand*(Speed factor[2, 20])";
			};
			class TiresGrassOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_2",
					1,
					1,
					60
				};
				frequency="1";
				volume="camPos*grass*(Speed factor[2, 20])";
			};
			class TiresMudOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\ext-tires-mud2",
					1,
					1,
					60
				};
				frequency="1";
				volume="camPos*mud*(Speed factor[2, 20])";
			};
			class TiresGravelOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\ext_tires_gravel_1",
					1,
					1,
					60
				};
				frequency="1";
				volume="camPos*gravel*(Speed factor[2, 20])";
			};
			class TiresAsphaltOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\ext_tires_asfalt_2",
					1,
					1,
					60
				};
				frequency="1";
				volume="camPos*asphalt*(Speed factor[2, 20])";
			};
			class NoiseOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\noise_int_car_3",
					1.5848932,
					1,
					90
				};
				frequency="1";
				volume="camPos*(damper0 max 0.02)*(Speed factor[0, 8])";
			};
			class TiresRockIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_1",
					0.70794576,
					1
				};
				frequency="1";
				volume="(1-camPos)*rock*(Speed factor[2, 20])";
			};
			class TiresSandIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\int-tires-sand2",
					0.70794576,
					1
				};
				frequency="1";
				volume="(1-camPos)*sand*(Speed factor[2, 20])";
			};
			class TiresGrassIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_2",
					0.70794576,
					1
				};
				frequency="1";
				volume="(1-camPos)*grass*(Speed factor[2, 20])";
			};
			class TiresMudIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\int-tires-mud2",
					0.70794576,
					1
				};
				frequency="1";
				volume="(1-camPos)*mud*(Speed factor[2, 20])";
			};
			class TiresGravelIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\int_tires_gravel_1",
					0.70794576,
					1
				};
				frequency="1";
				volume="(1-camPos)*gravel*(Speed factor[2, 20])";
			};
			class TiresAsphaltIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\int_tires_asfalt_2",
					0.70794576,
					1
				};
				frequency="1";
				volume="(1-camPos)*asphalt*(Speed factor[2, 20])";
			};
			class NoiseIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\noise_int_car_3",
					0.50118721,
					1
				};
				frequency="1";
				volume="(damper0 max 0.1)*(Speed factor[0, 8])*(1-camPos)";
			};
			class breaking_ext_road
			{
				sound[]=
				{
					"",
					1,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(LongSlipDrive factor[-0.2, -0.3])*(Speed factor[2, 10])";
			};
			class acceleration_ext_road
			{
				sound[]=
				{
					"",
					1,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(LongSlipDrive factor[0.2, 0.3])*(Speed factor[10, 1])";
			};
			class turn_left_ext_road
			{
				sound[]=
				{
					"",
					1,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(latSlipDrive factor[0.15, 0.3])*(Speed factor[0, 10])";
			};
			class turn_right_ext_road
			{
				sound[]=
				{
					"",
					1,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(latSlipDrive factor[-0.15, -0.3])*(Speed factor[0, 10])";
			};
			class breaking_ext_dirt
			{
				sound[]=
				{
					"",
					1,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(LongSlipDrive factor[-0.2, -0.3])*(Speed factor[2, 10])";
			};
			class acceleration_ext_dirt
			{
				sound[]=
				{
					"",
					1,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(LongSlipDrive factor[0.2, 0.3])*(Speed factor[10, 1])";
			};
			class turn_left_ext_dirt
			{
				sound[]=
				{
					"",
					1,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(latSlipDrive factor[0.15, 0.3])*(Speed factor[0, 10])";
			};
			class turn_right_ext_dirt
			{
				sound[]=
				{
					"",
					1,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(latSlipDrive factor[-0.15, -0.3])*(Speed factor[0, 10])";
			};
			class breaking_int_road
			{
				sound[]=
				{
					"",
					1,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(LongSlipDrive factor[-0.2, -0.3])*(Speed factor[2, 6])";
			};
			class acceleration_int_road
			{
				sound[]=
				{
					"",
					1,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(LongSlipDrive factor[0.2, 0.3])*(Speed factor[10, 1])";
			};
			class turn_left_int_road
			{
				sound[]=
				{
					"",
					1,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(latSlipDrive factor[0.15, 0.3])*(Speed factor[0, 10])";
			};
			class turn_right_int_road
			{
				sound[]=
				{
					"",
					1,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(latSlipDrive factor[-0.15, -0.3])*(Speed factor[0, 10])";
			};
			class breaking_int_dirt
			{
				sound[]=
				{
					"",
					1,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(LongSlipDrive factor[-0.2, -0.3])*(Speed factor[2, 6])";
			};
			class acceleration_int_dirt
			{
				sound[]=
				{
					"",
					1,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(LongSlipDrive factor[0.2, 0.3])*(Speed factor[10, 1])";
			};
			class turn_left_int_dirt
			{
				sound[]=
				{
					"",
					1,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(latSlipDrive factor[0.15, 0.3])*(Speed factor[0, 10])";
			};
			class turn_right_int_dirt
			{
				sound[]=
				{
					"",
					1,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(latSlipDrive factor[-0.15, -0.3])*(Speed factor[0, 10])";
			};
			class RainExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\noises\rain1_ext",
					1,
					1,
					100
				};
				frequency=1;
				volume="camPos * (rain - rotorSpeed/2) * 2";
			};
			class RainInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\noises\rain1_int",
					1,
					1,
					100
				};
				frequency=1;
				volume="(1-camPos)*(rain - rotorSpeed/2)*2";
			};
		};
	};
	class FST_ITT: FST_ITT_Base
	{
		scope=2;
		scopeCurator=2;
		forceingarage=1;
		side=1;
		displayname="[41st] ITT Transport";
		crew="FST_Trooper_P2_DC15S";
		typicalCargo[]=
		{
			"FST_Trooper_P2_DC15S"
		};
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"camo3",
			"camo4",
			"camo5",
			"camo6",
			"camo7"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\ITT\Data\Body\ITT_Body_co.paa",
			"3as\3as_ITT\data\glass_co.paa",
			"3as\3as_ITT\data\itt_int_back_co.paa",
			"41st_Vehicles\ITT\Data\Door\ITT_door_co.paa",
			"3as\3as_ITT\data\itt_int_front_co.paa",
			"3as\3as_ITT\data\itt_emiss_co.paa",
			"41st_Vehicles\ITT\Data\Turret\ITT_turret_co.paa",
		};
		editorPreview="3AS\3AS_rtt\images\3AS_RTT.jpg";
	};
	class FST_ITT_Medical: FST_ITT_Base
	{
		scope=2;
		scopeCurator=2;
		forceingarage=1;
		side=1;
		displayname="[41st] ITT (Medical)";
		crew="FST_Trooper_P2_DC15S";
		typicalCargo[]=
		{
			"FST_Trooper_P2_DC15S"
		};
		editorPreview="3AS\3AS_rtt\images\3AS_RTT.jpg";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets
				{
				};
				memoryPointGun[]=
				{
					""
				};
				gunEnd="";
				gunBeg="";
				weapons[]=
				{
					"FakeWeapon"
				};
				magazines[]=
				{
					"FakeMagazine"
				};
				selectionFireAnim="";
				minElev=0;
				maxElev=0;
				minTurn=0;
				maxTurn=0;
				initElev=0;
				memoryPointGunnerOptics="gunnerview2";
				gunnerAction="CoDriver_Van_02";
				gunnerInAction="CoDriver_Van_02";
				proxyIndex=1;
				proxytype="CPGunner";
				gunnerName="Medical Technician";
			};
			class CommanderTurret: CommanderTurret
			{
				gunnerName="Gunner";
				proxyIndex=2;
				gunnerAction="Saber_Driver";
				gunnerInAction="Commander_APC_Wheeled_01_in";
				memoryPointGunnerOptics="commanderview";
				LODTurnedIn=1000;
			};
			class CargoTurret_01: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				canHideGunner=0;
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerName="Exterior Gunner";
				proxyIndex=11;
				soundAttenuationTurret="HeliAttenuationGunner";
				isPersonTurret=1;
				ejectDeadGunner=1;
				class dynamicViewLimits
				{
					CargoTurret_04[]={-65,95};
				};
				playerPosition=4;
				gunnerGetInAction="GetInHeli_Light_01bench";
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerAction="vehicle_coshooter_1";
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerName="Exterior Gunner Top Right 1";
				proxyIndex=15;
				class dynamicViewLimits
				{
					CargoTurret_03[]={-65,95};
				};
			};
			class CargoTurret_03: CargoTurret_02
			{
				gunnerAction="passenger_inside_1";
				gunnerCompartments="Compartment2";
				gunnerName="Exterior Gunner Top Right 2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=13;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-95,65};
				};
			};
			class CargoTurret_04: CargoTurret_01
			{
				gunnerAction="passenger_inside_3";
				gunnerCompartments="Compartment2";
				gunnerName="Exterior Gunner Top Left 2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=14;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,65};
				};
			};
			class CargoTurret_05: CargoTurret
			{
				gunnerAction="passenger_inside_7";
				canHideGunner=0;
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerName="Exterior Gunner Top Left 3";
				proxyIndex=12;
				soundAttenuationTurret="HeliAttenuationGunner";
				isPersonTurret=1;
				ejectDeadGunner=1;
				class dynamicViewLimits
				{
					CargoTurret_04[]={-65,95};
				};
				playerPosition=4;
				gunnerGetInAction="GetInHeli_Light_01bench";
			};
			class CargoTurret_06: CargoTurret_01
			{
				gunnerAction="passenger_inside_3";
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerName="Exterior Gunner Top Right 3";
				proxyIndex=18;
				class dynamicViewLimits
				{
					CargoTurret_03[]={-65,95};
				};
			};
			class CargoTurret_07: CargoTurret_02
			{
				gunnerAction="passenger_inside_1";
				gunnerCompartments="Compartment2";
				gunnerName="Exterior Gunner Top Right 4";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=17;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-95,65};
				};
			};
			class CargoTurret_08: CargoTurret_01
			{
				gunnerAction="passenger_bench_1";
				gunnerCompartments="Compartment2";
				gunnerName="Exterior Gunner Top Left 4";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=16;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,65};
				};
			};
			class CargoTurret_09: CargoTurret
			{
				gunnerAction="vehicle_passenger_stand_01";
				canHideGunner=0;
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerName="Right Side Gunner 1";
				proxyIndex=19;
				soundAttenuationTurret="HeliAttenuationGunner";
				isPersonTurret=1;
				ejectDeadGunner=1;
				class dynamicViewLimits
				{
					CargoTurret_04[]={-65,95};
				};
				playerPosition=4;
				gunnerGetInAction="GetInHeli_Light_01bench";
			};
			class CargoTurret_10: CargoTurret_09
			{
				gunnerCompartments="Compartment2";
				gunnerName="Right Side Gunner 2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=20;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,65};
				};
			};
			class CargoTurret_11: CargoTurret_10
			{
				gunnerCompartments="Compartment2";
				gunnerName="Right Side Gunner 3";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=21;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,65};
				};
			};
			class CargoTurret_12: CargoTurret_01
			{
				gunnerAction="vehicle_passenger_stand_01";
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerName="Left Side Gunner 1";
				proxyIndex=22;
				class dynamicViewLimits
				{
					CargoTurret_03[]={-65,95};
				};
			};
			class CargoTurret_13: CargoTurret_12
			{
				gunnerCompartments="Compartment2";
				gunnerName="Left Side Gunner 2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=23;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-95,65};
				};
			};
			class CargoTurret_14: CargoTurret_13
			{
				gunnerCompartments="Compartment2";
				gunnerName="Left Side Gunner 3";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=24;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-95,65};
				};
			};
		};
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"camo3",
			"camo4",
			"camo5",
			"camo6",
			"camo7"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\ITT\Data\Body\ITT_Body_co.paa",
			"3as\3as_ITT\data\glass_co.paa",
			"3as\3as_ITT\data\itt_int_back_co.paa",
			"41st_Vehicles\ITT\Data\Door\ITT_door_co.paa",
			"3as\3as_ITT\data\itt_int_front_co.paa",
			"3as\3as_ITT\data\itt_emiss_co.paa",
			"41st_Vehicles\ITT\Data\Turret\ITT_turret_co.paa",
		};
		class AnimationSources
		{
			class open_door
			{
				source="user";
				animPeriod=2;
				initPhase=0;
			};
			class Turrets
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class Crates
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
		};
	};
	class FST_ITT_Logistic: FST_ITT_Medical
	{
		displayname="[41st] ITT (Logistics)";
		editorPreview="3AS\3AS_rtt\images\3AS_RTT.jpg";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerName="Logistics Officer";
				selectionFireAnim="";
			};
			class CommanderTurret: CommanderTurret
			{
				gunnerName="Gunner";
			};
			class CargoTurret_01: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				canHideGunner=0;
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerName="Exterior Gunner";
				proxyIndex=11;
				soundAttenuationTurret="HeliAttenuationGunner";
				isPersonTurret=1;
				ejectDeadGunner=1;
				class dynamicViewLimits
				{
					CargoTurret_04[]={-65,95};
				};
				playerPosition=4;
				gunnerGetInAction="GetInHeli_Light_01bench";
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerAction="vehicle_coshooter_1";
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerName="Exterior Gunner Top Right 1";
				proxyIndex=15;
				class dynamicViewLimits
				{
					CargoTurret_03[]={-65,95};
				};
			};
			class CargoTurret_03: CargoTurret_02
			{
				gunnerAction="passenger_inside_1";
				gunnerCompartments="Compartment2";
				gunnerName="Exterior Gunner Top Right 2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=13;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-95,65};
				};
			};
			class CargoTurret_04: CargoTurret_01
			{
				gunnerAction="passenger_inside_3";
				gunnerCompartments="Compartment2";
				gunnerName="Exterior Gunner Top Left 2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=14;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,65};
				};
			};
			class CargoTurret_09: CargoTurret
			{
				gunnerAction="vehicle_passenger_stand_01";
				canHideGunner=0;
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerName="Right Side Gunner 1";
				proxyIndex=19;
				soundAttenuationTurret="HeliAttenuationGunner";
				isPersonTurret=1;
				ejectDeadGunner=1;
				class dynamicViewLimits
				{
					CargoTurret_04[]={-65,95};
				};
				playerPosition=4;
				gunnerGetInAction="GetInHeli_Light_01bench";
			};
			class CargoTurret_10: CargoTurret_09
			{
				gunnerCompartments="Compartment2";
				gunnerName="Right Side Gunner 2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=20;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,65};
				};
			};
			class CargoTurret_11: CargoTurret_10
			{
				gunnerCompartments="Compartment2";
				gunnerName="Right Side Gunner 3";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=21;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,65};
				};
			};
			class CargoTurret_12: CargoTurret_01
			{
				gunnerAction="vehicle_passenger_stand_01";
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerName="Left Side Gunner 1";
				proxyIndex=22;
				class dynamicViewLimits
				{
					CargoTurret_03[]={-65,95};
				};
			};
			class CargoTurret_13: CargoTurret_12
			{
				gunnerCompartments="Compartment2";
				gunnerName="Left Side Gunner 2";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=23;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-95,65};
				};
			};
			class CargoTurret_14: CargoTurret_13
			{
				gunnerCompartments="Compartment2";
				gunnerName="Left Side Gunner 3";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				proxyIndex=24;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-95,65};
				};
			};
		};
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"camo3",
			"camo4",
			"camo5",
			"camo6",
			"camo7"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\ITT\Data\Body\ITT_Body_co.paa",
			"3as\3as_ITT\data\glass_co.paa",
			"3as\3as_ITT\data\itt_int_back_co.paa",
			"41st_Vehicles\ITT\Data\Door\ITT_door_co.paa",
			"3as\3as_ITT\data\itt_int_front_co.paa",
			"3as\3as_ITT\data\itt_emiss_co.paa",
			"41st_Vehicles\ITT\Data\Turret\ITT_turret_co.paa",
		};
		class AnimationSources
		{
			class open_door
			{
				source="user";
				animPeriod=2;
				initPhase=0;
			};
			class Turrets
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class Crates
			{
				source="user";
				animPeriod=1;
				initPhase=1;
			};
		};
		transportSoldier=6;
		cargoProxyIndexes[]={1,2,6,7,25,26};
		getInProxyOrder[]={1,2,6,7,25,26};
		supplyRadius=10;
		transportAmmo=1e+012;
		transportFuel=1e+012;
		secondaryExplosion=10000;
		fuelExplosionPower=1;
	};
};
class Mode_FullAuto;
class CfgWeapons
{
	class CannonCore;
	class LMG_RCWS;
	class FST_Light_Defence_Coax: LMG_RCWS
	{
		displayName="[41st] Light Defence Coax";
		author="Daara";
		descriptionShort="LDC";
		magazines[]=
		{
			"FST_500Rnd_High_Capacity_Plasma_Cell"
		};
		muzzleEnd="konec hlavne3";
		muzzlePos="usti hlavne3";
		selectionFireAnim="zasleh3";
		modes[]=
		{
			"FullAuto",
		};
		cursor="EmptyCursor";
		class FullAuto: Mode_FullAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				soundsetshot[]=
				{
					"3AS_Z6_SoundSet"
				};
			};
			soundContinuous=0;
			soundBurst=0;
			reloadTime=0.0795;
			aiRateOfFire=1;
			aiRateOfFireDistance=10;
			minRange=0;
			minRangeProbab=0.0099999998;
			midRange=1;
			midRangeProbab=0.0099999998;
			maxRange=2;
			maxRangeProbab=0.0099999998;
		};
		class GunParticles
		{
			class effect1
			{
				positionName="konec hlavne3";
				directionName="Usti hlavne3";
				effectName="MachineGunCloud";
			};
		};
	};
	class FST_Medium_Defence_Gun: CannonCore
	{
		displayName="[41st] Medium Defence Gun";
		author="Daara";
		descriptionShort="MDC";
		magazines[]=
		{
			"FST_200Rnd_30mm_shells"
		};
		muzzleEnd="konec hlavne3";
		muzzlePos="usti hlavne3";
		selectionFireAnim="zasleh3";
		modes[]=
		{
			"FullAuto",
		};
		cursor="EmptyCursor";
		class FullAuto: Mode_FullAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_saber30_Shot_SoundSet"
				};
			};
			soundContinuous=0;
			soundBurst=0;
			reloadTime=0.4;
			aiRateOfFire=1;
			aiRateOfFireDistance=10;
			minRange=0;
			minRangeProbab=0.0099999998;
			midRange=1;
			midRangeProbab=0.0099999998;
			maxRange=2;
			maxRangeProbab=0.0099999998;
		};
		class GunParticles
		{
			class effect1
			{
				positionName="konec hlavne3";
				directionName="Usti hlavne3";
				effectName="MachineGunCloud";
			};
		};
	};
};