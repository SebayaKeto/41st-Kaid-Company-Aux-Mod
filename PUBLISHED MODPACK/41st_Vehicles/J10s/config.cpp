class CfgPatches
{
	class FST_CIS_Static_J10s
	{
		addonRootClass="FST_CIS_Static";
		requiredAddons[]=
		{
			"3AS_Main"
		};
		units[]=
		{
			"FST_J10s_F"
		};
		weapons[]={};
		author="$STR_3as_Studio";
	};
};
class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		FSTJ10Gunner="FSTJ10Gunner";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	skeletonName="OFP2_ManSkeleton";
	gestures="CfgGesturesMale";
	class States
	{
		class Crew;
		class FSTJ10Gunner: Crew
		{
			file="3as\3AS_CIS_Static\J10s\data\Anim\J10s_Gunner.rtm";
			looped=0;
			showWeaponAim=1;
			disableWeapons=1;
			disableWeaponsLong=1;
			variantsAI[]={};
			speed=0.40000001;
			ConnectTo[]=
			{
				"AmovPercMstpSnonWnonDnon",
				0.02
			};
			connectFrom[]={};
			interpolateFrom[]={};
			InterpolateTo[]=
			{
				"Unconscious",
				0.1
			};
			lefthandIKCurve[]={1};
			righthandIKCurve[]={1};
			preload=0;
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
class Optics_Armored;
class Optics_Gunner_APC_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
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
		class AnimationSources;
		class Components;
	};
	class FST_J10s_Base_F: StaticMGWeapon
	{
		author="$STR_3as_Studio";
		_generalMacro="HMG_01_base_F";
		scope=0;
		displayName="[41st] J10s Blaster Turret";
		class Armory
		{
			description="Standard Blaster Turret of the CIS";
		};
		model="3as\3AS_CIS_Static\J10s\model\3AS_J10s.p3d";
		icon="3as\3AS_CIS_Static\J10s\data\ui\J10_top_ca.paa";
		picture="3as\3AS_CIS_Static\J10s\data\ui\J10_side_ca.paa";
		threat[]={1,0.30000001,0.30000001};
		cost=150000;
		crew="FST_Droid_B1_OOM";
		side=0;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		forceingarage=0;
		armor=150;
		armorStructured=1;
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3as\3AS_CIS_Static\J10s\data\J10s_Body.rvmat",
				"3as\3AS_CIS_Static\J10s\data\damage\Body_damage.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat",
				"3as\3AS_CIS_Static\J10s\data\J10s_Turret.rvmat",
				"3as\3AS_CIS_Static\J10s\data\damage\Gun_damage.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat"
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				discreteDistance[]={100,200,300,400,600,800,1000,1200,1500,1600,1700,1800,1900,2000};
				discreteDistanceInitIndex=2;
				turretInfoType="RscOptics_Offroad_01";
				minElev=-20;
				maxElev=60;
				minTurn=-360;
				maxTurn=360;
				selectionFireAnim="zasleh";
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
				weapons[]=
				{
					"FST_J10_Turret_MG"
				};
				magazines[]=
				{
					"FST_500Rnd_J10MG_Mag",
					"FST_500Rnd_J10MG_Mag",
					"FST_500Rnd_J10MG_Mag"
				};
				memoryPointGunnerOptics="gunnerview";
				gunnerLeftHandAnimName="HandleL";
				gunnerRightHandAnimName="HandleR";
				gunnerAction="FSTJ10Gunner";
				gunnerInAction="FSTJ10Gunner";
				gunnerGetInAction="GetInLow";
				gunnerGetOutAction="GetOutLow";
				gunnerForceOptics=0;
				memoryPointsGetInGunner="pos_gunner";
				memoryPointsGetInGunnerDir="pos_gunner_dir";
				animationSourceBody="Mainturret";
				Body="Mainturret";
				animationSourceGun="Maingun";
				Gun="Maingun";
				memoryPointGun[]=
				{
					"usti hlavne",
					"usti hlavne1"
				};
				class OpticsIn: Optics_Gunner_APC_01
				{
					class Wide: Wide
					{
						gunnerOpticsModel="\a3\weapons_f\Reticle\optics_empty.p3d";
						gunnerOpticsEffect[]={};
					};
					class Medium: Medium
					{
						gunnerOpticsModel="\a3\weapons_f\Reticle\optics_empty.p3d";
					};
					class Narrow: Narrow
					{
						gunnerOpticsModel="\a3\weapons_f\Reticle\optics_empty.p3d";
					};
				};
				ejectDeadGunner=1;
			};
		};
		class AnimationSources: AnimationSources
		{
			class Muzzle_flash
			{
				source="revolving";
				weapon="FST_J10_Turret_MG";
			};
		};
		hiddenSelections[]=
		{
			"camo0",
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3as\3AS_CIS_Static\J10s\data\J10_legs_co.paa",
			"3as\3AS_CIS_Static\J10s\data\J10_Turret_co.paa"
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
	};
	class FST_J10s_F: FST_J10s_Base_F
	{
		scope=2;
		displayName="[41st] J10s Blaster Turret";
		crew="FST_Droid_B1_OOM";
		side=0;
		forceingarage=1;
	};
};
class CfgWeapons
{
	class MGun;
	class FST_J10_Turret_MG: MGun
	{
		class GunClouds
		{
		};
		bullet1[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_01",
			0.2818383,
			1,
			10
		};
		bullet2[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_02",
			0.2818383,
			1,
			10
		};
		bullet3[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_03",
			0.2818383,
			1,
			10
		};
		bullet4[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_04",
			0.2818383,
			1,
			10
		};
		bullet5[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Dirt_01",
			0.2818383,
			1,
			10
		};
		bullet6[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Dirt_02",
			0.2818383,
			1,
			10
		};
		bullet7[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Dirt_03",
			0.2818383,
			1,
			10
		};
		bullet8[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Dirt_04",
			0.2818383,
			1,
			10
		};
		bullet9[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Grass_01",
			0.2818383,
			1,
			10
		};
		bullet10[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Grass_02",
			0.2818383,
			1,
			10
		};
		bullet11[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Grass_03",
			0.2818383,
			1,
			10
		};
		bullet12[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Grass_04",
			0.2818383,
			1,
			10
		};
		soundBullet[]=
		{
			"bullet1",
			0.079999998,
			"bullet2",
			0.083999999,
			"bullet3",
			0.083999999,
			"bullet4",
			0.083999999,
			"bullet5",
			0.093000002,
			"bullet6",
			0.093000002,
			"bullet7",
			0.074000001,
			"bullet8",
			0.074000001,
			"bullet9",
			0.083999999,
			"bullet10",
			0.085000001,
			"bullet11",
			0.082999997,
			"bullet12",
			0.082999997
		};
		class GunParticles
		{
		};
		scope=1;
		displayName="[41st] J-10 Blaster Turret";
		magazines[]=
		{
			"FST_500Rnd_J10MG_Mag"
		};
		magazineReloadTime=2.5;
		modes[]=
		{
			"manual",
			"close",
			"short",
			"medium",
			"far"
		};
		canLock=0;
		ballisticsComputer="2 + 16";
		FCSMaxLeadSpeed=0;
		FCSZeroingDelay=1;
		maxZeroing=1500;
		aiDispersionCoefY=3;
		aiDispersionCoefX=3;
		class manual: MGun
		{
			displayName="$STR_A3_LMG_RCWS0";
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_EWEB_Shot_SoundSet"
				};
			};
			soundContinuous=0;
			soundBurst=0;
			reloadTime=0.1;
			dispersion=0.0016;
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
			burst=8;
			burstRangeMax=16;
			aiRateOfFire=0.15000001;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=63;
			minRange=0;
			minRangeProbab=0.80000001;
			midRange=25;
			midRangeProbab=0.69999999;
			maxRange=188;
			maxRangeProbab=0.2;
		};
		class short: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=6;
			burstRangeMax=12;
			aiRateOfFire=0.2;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=188;
			minRange=25;
			minRangeProbab=0.69999999;
			midRange=188;
			midRangeProbab=0.69999999;
			maxRange=750;
			maxRangeProbab=0.2;
		};
		class medium: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=3;
			burstRangeMax=12;
			aiRateOfFire=0.2;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=313;
			minRange=188;
			minRangeProbab=0.69999999;
			midRange=750;
			midRangeProbab=0.64999998;
			maxRange=1000;
			maxRangeProbab=0.1;
		};
		class far: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=3;
			burstRangeMax=8;
			aiRateOfFire=0.25;
			aiRateOfFireDispersion=4;
			aiRateOfFireDistance=750;
			minRange=750;
			minRangeProbab=0.64999998;
			midRange=1000;
			midRangeProbab=0.40000001;
			maxRange=1500;
			maxRangeProbab=0.1;
		};
	};
};
class CfgMagazines
{
	class VehicleMagazine;
	class FST_500Rnd_J10MG_Mag: VehicleMagazine
	{
		author="$STR_3as_Studio";
		scope=2;
		displayName="500 Rnd J10 Turret Gun Ammo";
		displayNameShort="HE";
		ammo="FST_EC90_RedPlasma";
		count=500;
		initSpeed=868;
		maxLeadSpeed=250;
		nameSound="mg";
		tracersEvery=1;
		muzzleImpulseFactor[]={0,0};
	};
};
class CfgAmmo
{
	class IDA_blasterbolt;
	class FST_EC90_RedPlasma: IDA_blasterbolt
	{
		lightcolor[]={1,0,0};
		hit=28;
		indirectHit=0;
		indirectHitRange=0;
		cartridge="";
		visibleFire=8;
		audibleFire=120;
		dangerRadiusBulletClose=12;
		dangerRadiusHit=16;
		suppressionRadiusBulletClose=8;
		suppressionRadiusHit=12;
		cost=5;
		airLock=1;
		caliber=3.79;
		typicalSpeed=694;
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
		tracerScale=1.895;
		airFriction=-0.00012;
		effectfly="IDA_BlasterBoltGlow_Red_Fly";
		
		class CamShakeExplode
		{
			power=3.6055501;
			duration=0.80000001;
			frequency=20;
			distance=10.8167;
		};
		class CamShakeHit
		{
			power=13;
			duration=0.40000001;
			frequency=20;
			distance=1;
		};
	};
};