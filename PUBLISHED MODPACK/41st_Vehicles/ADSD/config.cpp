class CfgPatches
{
	class FST_ADSD
	{
		addonRootClass="3AS_Static";
		requiredAddons[]=
		{
			"3AS_Static"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_Advanced_DSD"
		};
		weapons[]={};
		author="$STR_3AS_Studio";
	};
};
class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class CfgDestructPos
{
	scope=1;
	class DelayedDestruction;
	class DelayedDestructionAmmo: DelayedDestruction
	{
		timeBeforeHiding="21";
		hideDuration="10";
	};
};
class WeaponCloudsMGun;
class CfgVehicles
{
	class All;
	class Strategic;
	class Land;
	class LandVehicle: Land
	{
		class ViewPilot;
		class ViewGunner;
		class NewTurret;
	};
	class StaticWeapon: LandVehicle
	{
		class Turrets
		{
			class MainTurret;
		};
	};
	class StaticMGWeapon: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics;
			};
		};
	};
	class Tank: LandVehicle
	{
		class NewTurret;
		class Sounds;
		class HitPoints;
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
	class 3AS_AAT_base_F: Tank_F
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
	class FST_Advanced_DSD_Base: 3AS_AAT_base_F
	{
		displayName="[41st] Advanced Dwarf Spider Droid (ADSD)";
		model="3AS\3AS_ADSD\model\ADSD.p3d";
		hasdriver=1;
		forceHideDriver=1;
		armor=1500;
		armorHull=1;
		armorTurret=0.80000001;
		armorGun=0.60000002;
		armorEngine=0.80000001;
		armorTracks=0.60000002;
		armorStructural=4;
		autocenter=0;
		destrType="DestructWreck";
		driverOptics="driverview";
		driverinAction="MTT_cargo";
		icon="3as\3AS_ADSD\data\ui\ADSD_top_ca.paa";
		picture="3as\3AS_ADSD\data\ui\ADSD_side_ca.paa";
		simulation="tankX";
		enginePower=3000;
		maxOmega=1000;
		maxSpeed=12;
		peakTorque=10000;
		torqueCurve[]=
		{
			{0,0},
			
			{
				"(1600/2640)",
				"(2650/2850)"
			},
			
			{
				"(1800/2640)",
				"(2800/2850)"
			},
			
			{
				"(1900/2640)",
				"(2850/2850)"
			},
			
			{
				"(2000/2640)",
				"(2800/2850)"
			},
			
			{
				"(2200/2640)",
				"(2750/2850)"
			},
			
			{
				"(2400/2640)",
				"(2600/2850)"
			},
			
			{
				"(2640/2640)",
				"(2350/2850)"
			}
		};
		thrustDelay=0.5;
		clutchStrength=180;
		fuelCapacity=50;
		brakeIdleSpeed=1.78;
		latency=0.1;
		tankTurnForce=2000000;
		idleRpm=700;
		redRpm=2640;
		engineLosses=25;
		transmissionLosses=15;
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R2",
				-3.9000001,
				"N",
				0,
				"D1",
				4.6999998,
				"D2",
				3.5,
				"D3",
				2.5999999,
				"D4",
				2,
				"D5",
				1.5,
				"D6",
				1.125,
				"D7",
				0.85000002
			};
			TransmissionRatios[]=
			{
				"High",
				15
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
			transmissionDelay=0.1;
		};
		class Wheels
		{
			class L2
			{
				boneName="wheel_podkoloL1";
				center="wheel_1_2_axis";
				boundary="wheel_1_2_bound";
				damping=75;
				steering=0;
				side="left";
				weight=150;
				mass=150;
				MOI=8;
				latStiffX=25;
				latStiffY=280;
				longitudinalStiffnessPerUnitGravity=100000;
				maxBrakeTorque=20000;
				sprungMass=4000;
				springStrength=324000;
				springDamperRate=36000;
				dampingRate=1;
				dampingRateInAir=8000;
				dampingRateDamaged=10;
				dampingRateDestroyed=10000;
				maxDroop=0.15000001;
				maxCompression=0.15000001;
			};
			class L3: L2
			{
				boneName="wheel_podkolol2";
				center="wheel_1_3_axis";
				boundary="wheel_1_3_bound";
			};
			class L4: L2
			{
				boneName="wheel_podkolol3";
				center="wheel_1_4_axis";
				boundary="wheel_1_4_bound";
			};
			class L5: L2
			{
				boneName="wheel_podkolol4";
				center="wheel_1_5_axis";
				boundary="wheel_1_5_bound";
			};
			class L6: L2
			{
				boneName="wheel_podkolol5";
				center="wheel_1_6_axis";
				boundary="wheel_1_6_bound";
			};
			class L7: L2
			{
				boneName="wheel_podkolol6";
				center="wheel_1_7_axis";
				boundary="wheel_1_7_bound";
			};
			class L9: L2
			{
				boneName="wheel_podkolol9";
				center="wheel_1_9_axis";
				boundary="wheel_1_9_bound";
				sprungMass=1500;
				springStrength=37500;
				springDamperRate=7500;
				maxDroop=0;
				maxCompression=0;
			};
			class L1: L2
			{
				boneName="";
				center="wheel_1_1_axis";
				boundary="wheel_1_1_bound";
				sprungMass=1500;
				springStrength=37500;
				springDamperRate=7500;
				maxDroop=0;
				maxCompression=0;
			};
			class R2: L2
			{
				boneName="wheel_podkolop1";
				center="wheel_2_2_axis";
				boundary="wheel_2_2_bound";
				side="right";
			};
			class R3: R2
			{
				boneName="wheel_podkolop2";
				center="wheel_2_3_axis";
				boundary="wheel_2_3_bound";
			};
			class R4: R2
			{
				boneName="wheel_podkolop3";
				center="wheel_2_4_axis";
				boundary="wheel_2_4_bound";
			};
			class R5: R2
			{
				boneName="wheel_podkolop4";
				center="wheel_2_5_axis";
				boundary="wheel_2_5_bound";
			};
			class R6: R2
			{
				boneName="wheel_podkolop5";
				center="wheel_2_6_axis";
				boundary="wheel_2_6_bound";
			};
			class R7: R2
			{
				boneName="wheel_podkolop6";
				center="wheel_2_7_axis";
				boundary="wheel_2_7_bound";
			};
			class R9: R2
			{
				boneName="wheel_podkolop9";
				center="wheel_2_9_axis";
				boundary="wheel_2_9_bound";
				sprungMass=1500;
				springStrength=37500;
				springDamperRate=7500;
				maxDroop=0;
				maxCompression=0;
			};
			class R1: R2
			{
				boneName="";
				center="wheel_2_1_axis";
				boundary="wheel_2_1_bound";
				sprungMass=1500;
				springStrength=37500;
				springDamperRate=7500;
				maxDroop=0;
				maxCompression=0;
			};
		};
		class HitPoints
		{
			class HitHull
			{
				armor=1.6;
				material=-1;
				name="telo";
				visual="zbytek";
				passThrough=0.079999998;
				minimalHit=0.14;
				explosionShielding=10;
				radius=0.11;
			};
			class HitEngine
			{
				armor=1.5;
				material=-1;
				name="motor";
				passThrough=0.079999998;
				minimalHit=0.23999999;
				explosionShielding=1;
				radius=0.33000001;
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets
				{
				};
				optics=1;
				discreteDistance[]={100,200,300,400,600,800,1000,1200,1500,1600,1700,1800,1900,2000};
				discreteDistanceInitIndex=2;
				turretInfoType="RscOptics_crows";
				memoryPointGunnerOptics="gunnerview";
				gunnerOpticsModel="\a3\weapons_f_gamma\reticle\HMG_01_Optics_Gunner_F";
				minElev=-5;
				maxElev=70;
				minTurn=-90;
				maxVerticalRotSpeed=0.5;
				animationSourceBody="Mainturret";
				Body="Mainturret";
				animationSourceGun="Maingun";
				Gun="Maingun";
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\boat\Boat_Armed_01\servo_boat_comm",
					1.4125376,
					1,
					30
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\boat\Boat_Armed_01\servo_boat_comm_vertical",
					1.4125376,
					1,
					30
				};
				maxTurn=90;
				weapons[]=
				{
					"FST_AAT_Cannon",
					"FST_AAT_Side"
				};
				magazines[]=
				{
					"FST_500Rnd_127x99_mag_red",
					"FST_500Rnd_127x99_mag_red",
					"FST_500Rnd_127x99_mag_red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
					"FST_thermal_coil_OP_Red",
				};
				gunnerAction="gunner_static_low01";
				gunnergetInAction="";
				gunnergetOutAction="";
				displayName="Gunner";
				memoryPointGun="usti hlavne3";
				memoryPointsGetInGunner="pos_gunner";
				memoryPointsGetInGunnerDir="pos_gunner_dir";
				forceHideGunner=1;
				gunnerForceOptics=1;
				class ViewOptics: ViewOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.117;
					minFov=0.028999999;
					maxFov=0.117;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0,1};
				};
				gunnerRightHandAnimName="OtocHlaven_shake";
				gunnerLeftHandAnimName="OtocHlaven_shake";
				ejectDeadGunner=1;
				class HitPoints
				{
					class HitTurret
					{
						armor=0.60000002;
						material=-1;
						name="vez";
						visual="zbytek";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.60000002;
						radius=0.15000001;
					};
					class HitGun
					{
						armor=0.60000002;
						material=-1;
						name="zbran";
						visual="zbytek";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.60000002;
						radius=0.15000001;
					};
				};
			};
		};
		class AnimationSources
		{
			class mainturret
			{
				source="mainturret";
				weapon="3AS_ParticleCannon";
			};
			class maingun
			{
				source="maingun";
				weapon="3AS_ParticleCannon";
			};
			class walk
			{
				source="user";
				animPeriod=1;
				initphase=0;
			};
		};
		soundGetOut[]=
		{
			"A3\sounds_f\dummysound",
			0.001,
			1,
			5
		};
		soundGetIn[]=
		{
			"A3\sounds_f\dummysound",
			0.00031622799,
			1,
			5
		};
		class Eventhandlers
		{
			init="_this execVM '3as\3AS_ADSD\scripts\init_walk_new.sqf';";
		};
	};
	class FST_Advanced_DSD: FST_Advanced_DSD_Base
	{
		author="$STR_3AS_Studio";
		_generalMacro="B_MBT_01_base_F";
		features="Randomization: No      <br />Camo selections: 2 - hull, main turret      <br />Script door sources: None      <br />Script animations: None      <br />Executed scripts: None      <br />Firing from vehicles: No      <br />Slingload: No      <br />Cargo proxy indexes: 1 to 6";
		side=0;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Droid_B1_E5";
		scopeCurator=2;
		scope=2;
		editorPreview="\3as\3AS_ADSD\images\3AS_Advanced_DSD.jpg";
		class TransportMagazines
		{
		};
		class TransportWeapons
		{
		};
		class TransportItems
		{
		};
	};
};
