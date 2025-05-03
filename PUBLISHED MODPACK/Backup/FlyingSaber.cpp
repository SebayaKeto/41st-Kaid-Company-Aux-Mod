/* 	class FST_laat_Base;
	class FST_Saber_Fly: FST_laat
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		maximumLoad=5000;
		ace_cargo_space=30;
		ace_cargo_hasCargo=1;
		altFullForce=14;
		altNoForce=20;
		displayName="[41st] TX-130 Saber Tank (Fly)";
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Trooper_P2_DC15S";
		editorPreview="\3as\3as_saber\images\3as_saber_m1.jpg";
		author="Daara";
		tas_canBlift=1;
		tas_can_impulse=0;
		tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]";
		model="3as\3as_saber\model\tcw_tx130";
		steerAheadSimul=0.5;
		steerAheadPlan=0.34999999;
		predictTurnPlan=0.80000001;
		predictTurnSimul=0.60000002;
		brakeDistance=5;
		acceleration=15;
		turnCoef=2;
		canFloat=1;
		waterPPInVehicle=0;
		waterResistanceCoef=0.07;
		waterLeakiness=2.5;
		waterSpeedFactor=0.5;
		waterAngularDampingCoef=5;
		waterLinearDampingCoefY=2;
		waterLinearDampingCoefX=0.5;
		maxFordingDepth=0.5;
		waterResistance=1;
		weapons[] = {};
		magazines[] = {};
		fuelCapacity = 5000;
		maxBrakeTorque=85000;
		memoryPointDriverOptics[]=
		{
			"driverview"
		};
		driverOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
		spotableNightLightsOff=0.050000001;
		spotableNightLightsOn=4;
		visibleNightLightsOff=0.1;
		visibleNightLightsOn=0.2;
		extCameraPosition[]={0,3.5,-9};
		cost=1500000;
		damageResistance=0.079999998;
		crewVulnerable=0;
		armor=950;
		driverCanSee="4+8+2+32+16";
		gunnerCanSee="4+2+8+32+16";
		armorStructural=5;
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=4.5;
				material=-1;
				name="telo";
				visual="zbytek";
				passThrough=1;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.27500001;
			};
			class HitEngine: HitEngine
			{
				armor=0.60000002;
				material=-1;
				name="motor";
				passThrough=0.2;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.33000001;
			};
			class HitFuel: HitFuel
			{
				armor=0.5;
				material=-1;
				name="palivo";
				passThrough=0.1;
				minimalHit=0.1;
				explosionShielding=0.60000002;
				radius=0.25;
			};
		};
		class AnimationSources: AnimationSources
		{
			class Revolving
			{
				source="revolving";
				weapon="Missiles_DAGR";
			};
			class Select_Rockets
			{
				source="user";
				animPeriod=1e-007;
				initPhase=0;
			};
		};
		class Turrets: Turrets
		{
			class CargoTurret_01: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				canHideGunner=0;
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				gunnerName="$STR_A3_TURRETS_BENCH_R1";
				proxyIndex=1;
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
				gunnerCompartments="Compartment3";
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				gunnerName="$STR_A3_TURRETS_BENCH_L2";
				proxyIndex=2;
				class dynamicViewLimits
				{
					CargoTurret_03[]={-65,95};
				};
			};
			class CargoTurret_03: CargoTurret_02
			{
				gunnerCompartments="Compartment3";
				gunnerName="$STR_A3_TURRETS_BENCH_L1";
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				proxyIndex=3;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-95,65};
				};
			};
			class CargoTurret_04: CargoTurret_01
			{
				gunnerCompartments="Compartment2";
				gunnerName="$STR_A3_TURRETS_BENCH_R2";
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				proxyIndex=4;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-95,65};
				};
			};
			class MainTurret_top: MainTurret
			{
				class Turrets
				{
				};
				body="obTurret";
				gun="obGun";
				weapons[]=
				{
					"FST_Heavy_laser_Cannon",
					"FST_Medium_twin_laser_turret",
					"FST_Rapture_AGM_Missile",
					"FST_Stormfury_AA_Missile",
					"SmokeLauncher"
				};
				memoryPointGun[]=
				{
					"z_gunL_muzzle",
					"z_gunR_muzzle"
				};
				magazines[]=
				{
					"FST_100Rnd_Plasma_shells",
					"FST_100Rnd_Plasma_shells",
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"FST_Stormfury_12Rnd_AA_Missile",
					"FST_Rapture_12Rnd_AGM_Missile",
					"SmokeLauncherMag",
					"SmokeLauncherMag"
				};
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_best",
					0.0099999998,
					1,
					50
				};
				startEngine=0;
				hideWeaponsGunner=1;
				stabilizedInAxes=3;
				turretInfoType="RscWeaponRangeZeroing";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				selectionFireAnim="zasleh2";
				flash="gunfire";
				animationSourceBody="obTurret";
				animationSourceGun="obGun";
				discreteDistanceInitIndex=2;
				memoryPointGunnerOptics="commanderview";
				gunnerOpticsEffect[]={};
				gunnerForceOptics=0;
				visionMode[]=
				{
					"Normal"
				};
				thermalMode[]={};
				missileBeg="missleEnd";
				missileEnd="missleBeg";
				gunnerInOpticsShowCursor=1;
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
				gunnerOutOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
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
				gunnerAction="Saber_Driver";
				forceHideGunner=1;
				outGunnerMayFire=0;
				gunnerInAction="Saber_Driver";
				gunnerRightHandAnimName="";
				gunnerLeftHandAnimName="";
				gunnerFireAlsoInInternalCamera=1;
				gunnerOutFireAlsoInInternalCamera=1;
				proxyIndex=2;
				viewGunnerInExternal=1;
				proxytype="CPGunner";
				gunnername="Gunner";
				commanding=1;
				personTurretAction="vehicle_turnout_1";
				minOutElev=-10;
				maxOutElev=15;
				initOutElev=0;
				minOutTurn=-45;
				maxOutTurn=90;
				initOutTurn=0;
				minTurn=-15;
				maxTurn=15;
				initTurn=0;
				minElev=-8;
				maxElev=20;
				initElev=0;
				inGunnerMayFire=1;
				LODTurnedOut=1000;
				LODTurnedIn=1000;
				gunnerGetInAction="GetInHigh";
				gunnerGetOutAction="GetOutHigh";
				class HitPoints
				{
					class HitTurret
					{
						armor=1.2;
						material=-1;
						name="vez";
						visual="vez";
						passThrough=0;
						minimalHit=0.02;
						explosionShielding=0.30000001;
						radius=0.25;
					};
					class HitGun
					{
						armor=1.2;
						material=-1;
						name="zbran";
						visual="";
						passThrough=0;
						minimalHit=0;
						explosionShielding=1;
						radius=0.25;
					};
				};
				class ViewOptics: RCWSOptics
				{
					visionMode[]=
					{
						"Normal",
						"TI"
					};
				}; */
/* 				class Components: Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftCommander
					{
						class Components: components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={200,400,800,1600};
								resource="RscCustomInfoSensors";
							};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightCommander
					{
						defaultDisplay="SensorDisplay";
						class Components: components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={200,400,800,1600};
								resource="RscCustomInfoSensors";
							};
						};
					};
				}; */
			};
/* 			class MainTurret_bottom: MainTurret_top
			{
				body="MainTurret";
				gun="MainGun";
				proxyIndex=1;
				gunnername="Commander";
				animationSourceBody="Mainturret";
				animationSourceGun="Maingun";
				AnimationSourceHatch="HatchCommander";
				minOutElev=-10;
				maxOutElev=15;
				initOutElev=0;
				minOutTurn=-360;
				maxOutTurn=360;
				initOutTurn=0;
				minTurn=-360;
				maxTurn=360;
				initTurn=0;
				minElev=-15;
				maxElev=15;
				initElev=0;
				gunnerAction="Saber_Commander_OUT";
				gunnerInAction="Saber_Commander_In";
				forceHideGunner=0;
				outGunnerMayFire=1;
				ingunnerMayFire=1;
				stabilizedInAxes=4;
				ispersonturret=0;
				enabledByAnimationSource="HatchCommander";
				gunnerRightHandAnimName="HandR";
				gunnerLeftHandAnimName="HandL";
				personTurretAction="vehicle_turnout_1";
				memoryPointGun[]=
				{
					"usti hlavne3",
					"usti hlavne4"
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
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
				};
				memoryPointGunnerOptics="gunnerview";
				gunnerHasFlares=1;
				gunnerOutOpticsShowCursor=1;
				maxHorizontalRotSpeed=0.61500001;
				class HitPoints
				{
					class HitTurret
					{
						armor=0.30000001;
						material=-1;
						name="Commander_Turret";
						visual="commander_turret";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.60000002;
						radius=0.25;
					};
					class HitGun
					{
						armor=0.30000001;
						material=-1;
						name="Commander_Gun";
						visual="Commander_Gun";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.60000002;
						radius=0.25;
					};
				};
				selectionFireAnim="zasleh3";
				class Turrets
				{
				}; */
/* 				class Components: Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftCommander
					{
						class Components: components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={200,400,800,1600};
								resource="RscCustomInfoSensors";
							};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightCommander
					{
						defaultDisplay="SensorDisplay";
						class Components: components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={200,400,800,1600};
								resource="RscCustomInfoSensors";
							};
						};
					};
				}; */
/* 			};
		};
		class Damage
		{
			tex[]={};
			mat[]={};
		};
		smokeLauncherGrenadeCount=12;
		smokeLauncherVelocity=14;
		smokeLauncherOnTurret=1;
		smokeLauncherAngle=180;
		class ViewOptics: ViewOptics
		{
			visionMode[]=
			{
				"Normal",
				"TI"
			};
		};
		class Exhausts
		{
			class Exhaust_1
			{
				position="Exhaust_1_pos";
				direction="Exhaust_1_dir";
				effect="ExhaustsEffectHeliBig";
			};
			class Exhaust_2
			{
				position="Exhaust_2_pos";
				direction="Exhaust_2_dir";
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
		driverInAction="Saber_Driver";
		viewDriverInExternal=1;
		proxytype="CPDriver";
		proxyIndex=1;
		forcehideDriver=1;
		DriverForceOptics=0;
		memoryPointTrack1L="Track LL";
		memoryPointTrack1R="Track LR";
		memoryPointTrack2L="Track RL";
		memoryPointTrack2R="Track RR";
		dustFrontLeftPos="dustFrontLeft";
		dustFrontRightPos="dustFrontRight";
		dustBackLeftPos="dustBackLeft";
		dustBackRightPos="dustBackRight";
		hiddenSelections[]=
		{
			"Camo1",
			"Camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\Saber\Data\Hull\41st_Saber_Hull_Co.paa",
			"41st_Vehicles\Saber\Data\Weapons\41st_Saber_Weapons_co.paa",
		};
		class TransportItems
		{
			class _transport_ToolKit
			{
				name="ToolKit";
				count=2;
			};
		};
	}; */