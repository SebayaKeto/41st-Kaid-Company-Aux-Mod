class CfgPatches
{
	class FST_Static_FlakCannon
	{
		requiredAddons[]=
		{
			"3AS_Static"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_FlakCannon"
		};
		weapons[]={};
	};
};
class CfgAmmo
{
	class BulletBase;
	class 3AS_FlakCannon_AA:BulletBase{};
	class FST_FlakCannon_AA: 3AS_FlakCannon_AA
	{
		hit=90;
		indirectHit=30;
		indirectHitRange=2.4000001;
		warheadName="HE";
		visibleFire=38;
		audibleFire=200;
		visibleFireTime=5;
		proximityExplosionDistance=50;
		dangerRadiusBulletClose=20;
		dangerRadiusHit=60;
		suppressionRadiusBulletClose=12;
		suppressionRadiusHit=24;
		deflecting=0;
		explosive=0.60000002;
		airLock=1;
		aiAmmoUsageFlags="64 + 128 + 256";
		cost=42;
		CraterEffects="ExploAmmoCrater";
		explosionEffects="GrenadeExplosion";
		explosionSoundEffect="DefaultExplosion";
		model="\3AS\3AS_Weapons\Data\tracer_shell_red.p3d";
		tracerScale=1.85;
		tracerStartTime=0;
		tracerEndTime=10;
		timeToLive=10;
		airFriction=-0.00050000002;
		muzzleEffect="";
		caliber=2.8;
		typicalSpeed=960;
		effectFly="3AS_PlasmaBolt_Large_Red_Fly";
	};
};
class CfgMagazines
{
	class VehicleMagazine;
	class 3AS_FlakCannon_1000Rnd_AA_shells: VehicleMagazine{};
	class FST_FlakCannon_1000Rnd_AA_shells: 3AS_FlakCannon_1000Rnd_AA_shells
	{
		author="Adapted from 3AS by Viz";
		scope=2;
		displayName="[41st] 1000Rnd Flak Cannon Shells";
		displayNameShort="1000Rnd Flak Cannon Shells";
		ammo="FST_FlakCannon_AA";
		count=1000;
		initSpeed=1440;
		maxLeadSpeed=800;
		tracersEvery=1;
		nameSound="cannon";
		muzzleImpulseFactor[]={1,4};
	};
};
class CfgWeapons{
	class CannonCore;
	class 3AS_Flak_Cannon: CannonCore{};
	class FST_Flak_Cannon: 3AS_Flak_Cannon
	{
		scope=1;
		displayName="[41st] Flak Cannon";
		nameSound="cannon";
		cursor="EmptyCursor";
		cursorAim="mg";
		magazines[]=
		{
			"FST_FlakCannon_1000Rnd_AA_shells"
		};
		magazineReloadTime=20;
		modes[]=
		{
			"manual",
			"close",
			"short",
			"medium",
			"far"
		};
		canLock=0;
		ballisticsComputer="2 + 4";
		class manual: CannonCore
		{
			displayName="41st_autocannon_35mm_manual0";
			textureType="fullAuto";
			autoFire=1;
			burst=2;
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				soundsetshot[]=
				{
					"3AS_Flakcanon_SoundSet"
				};
			};
			soundContinuous=0;
			soundBurst=0;
			reloadTime=0.054545499;
			dispersion=0.0044999998;
			aiRateOfFire=1;
			aiRateOfFireDistance=10;
			minRange=0;
			minRangeProbab=0.0099999998;
			midRange=1;
			midRangeProbab=0.0099999998;
			maxRange=2;
			maxRangeProbab=0.0099999998;
		};
		class close: manual
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=12;
			burstRangeMax=28;
			aiRateOfFire=0.5;
			aiRateOfFireDispersion=0.5;
			aiRateOfFireDistance=200;
			minRange=1;
			minRangeProbab=0.1;
			midRange=100;
			midRangeProbab=0.75;
			maxRange=400;
			maxRangeProbab=0.85000002;
		};
		class short: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=18;
			burstRangeMax=42;
			aiRateOfFire=1;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=300;
			minRange=200;
			minRangeProbab=0.30000001;
			midRange=400;
			midRangeProbab=0.85000002;
			maxRange=750;
			maxRangeProbab=0.85000002;
		};
		class medium: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=18;
			burstRangeMax=42;
			aiRateOfFire=2;
			aiRateOfFireDispersion=4;
			aiRateOfFireDistance=800;
			minRange=600;
			minRangeProbab=0.60000002;
			midRange=750;
			midRangeProbab=0.85000002;
			maxRange=1250;
			maxRangeProbab=0.60000002;
		};
		class far: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=18;
			burstRangeMax=42;
			aiRateOfFire=2;
			aiRateOfFireDispersion=7;
			aiRateOfFireDistance=1200;
			minRange=1000;
			minRangeProbab=0.69999999;
			midRange=1250;
			midRangeProbab=0.60000002;
			maxRange=2500;
			maxRangeProbab=0.1;
		};
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
class DefaultVehicleSystemsDisplayManagerLeft;
class Optics_Armored;
class Optics_Gunner_APC_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
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
		class Components;
	};
	class 3as_FlakCannon_Base: StaticMGWeapon{};
	class FST_FlakCannon_Base: 3as_FlakCannon_Base
	{
		author="3AS mod Team adapted by Viz";
		_generalMacro="HMG_01_base_F";
		scope=0;
		displayName="[41st] Flak Cannon";
		class Armory
		{
			description="CIS Anti Air Cannon";
		};
		model="3AS\3AS_Static\FlakCannon\model\FlakCannon.p3d";
		editorSubcategory="EdSubcat_Turrets";
		icon="3AS\3as_static\FlakCannon\Data\ui\FlakCannon_top_ca.paa";
		picture="3AS\3as_static\FlakCannon\Data\ui\FlakCannon_side_ca.paa";
		threat[]={1,0.30000001,0.30000001};
		cost=150000;
		getInAction="";
		getOutAction="";
		extCameraPosition[]={0,7,-20};
		armor=600;
		armorStructured=1;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				optics=1;
				discreteDistance[]={100,200,300,400,600,800,1000,1200,1500,1600,1700,1800,1900,2000};
				discreteDistanceInitIndex=2;
				turretInfoType="RscOptics_APC_Tracked_01_gunner";
				memoryPointGunnerOptics="gunnerview";
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
				minElev=-5;
				maxElev=75;
				minTurn=-360;
				initelev=28;
				maxVerticalRotSpeed=0.90000001;
				maxHorizontalRotSpeed = 0.90000001;
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
				maxTurn=360;
				weapons[]=
				{
					"FST_Flak_Cannon"
				};
				magazines[]=
				{
					"FST_FlakCannon_1000Rnd_AA_shells",
					"FST_FlakCannon_1000Rnd_AA_shells"
				};
				gunnerAction="ParticleCannon_Gunner";
				gunnergetInAction="";
				gunnergetOutAction="";
				memoryPointsGetInGunner="pos_gunner";
				memoryPointsGetInGunnerDir="pos_gunner_dir";
				memoryPointGun[]=
				{
					"usti hlavne 1",
					"usti hlavne 2",
					"usti hlavne 3",
					"usti hlavne 4"
				};
				gunBeg="usti hlavne";
				gunEnd="konec hlavne";
				class OpticsIn: Optics_Gunner_APC_01
				{
					class Wide: Wide
					{
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
						gunnerOpticsEffect[]={};
					};
					class Medium: Medium
					{
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_M_F";
					};
					class Narrow: Narrow
					{
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_N_F";
					};
				};
				gunnerRightHandAnimName="OtocHlaven_shake";
				gunnerLeftHandAnimName="OtocHlaven_shake";
				selectionFireAnim="zasleh";
				ejectDeadGunner=1;
			};
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
							minRange=500;
							maxRange=4000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=500;
							maxRange=3500;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						typeRecognitionDistance=4000;
						maxTrackableSpeed=700;
						angleRangeHorizontal=90;
						angleRangeVertical=60;
						animDirection="mainGun";
						aimDown=-0.5;
					};
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange=10000;
							maxRange=10000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=7000;
							maxRange=7000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						typeRecognitionDistance=7000;
						angleRangeHorizontal=360;
						angleRangeVertical=100;
						aimDown=-45;
						maxTrackableSpeed=1388.89;
					};
					class DataLinkSensorComponent: SensorTemplateDataLink
					{
					};
				};
			};
		};
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3as\3as_static\FlakCannon\Data\CIS_AA_co.paa"
		};
	};
	class FST_FlakCannon: FST_FlakCannon_Base
	{
		editorPreview="";
		_generalMacro="B_HMG_01_F";
		scope=2;
		scopeCurator=2;
		side=0;
		faction="FST_BattleDroids_Faction";
		crew="FST_Droid_B1_E5";
	};
};