class CfgPatches
{
	class FST_static_turbolaser_xx10
	{
		requiredAddons[]=
		{
			"3AS_Static"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_XX10",
			"FST_XX9"
		};
		weapons[]=
		{
			"FST_TurboLaserCannonBase",
			"FST_TurboLaserCannon"
		};
		magazines[]=
		{
			"FST_turbolaserCharge_24rnd"
		};
		ammo[]=
		{
			"FST_Green_Plasma_AT"
		};
	};
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
class CfgAmmo
{
	class Cannon_30mm_HE_Plane_CAS_02_F;
	class 3AS_Green_Plasma_AT: Cannon_30mm_HE_Plane_CAS_02_F {};
	class FST_Green_Plasma_AT: 3AS_Green_Plasma_AT
	{
		model="3as\3AS_Weapons\Data\tracer_shell_Green.p3d";
		aiAmmoUsageFlags="128 + 512 + 256 + 64";
		hit=686.91998;
		indirectHit=31;
		indirectHitRange=3;
		CraterEffects="ATRocketCrater";
		explosionEffects="ATRocketExplosion";
	};
};
class CfgMagazines
{
	class 24Rnd_125mm_APFSDS;
	class 3as_turbolaserCharge_24rnd: 24Rnd_125mm_APFSDS {};
	class FST_turbolaserCharge_24rnd: 3as_turbolaserCharge_24rnd
	{
		scope=2;
		tracersEvery=1;
		ammo="3AS_Green_Plasma_AT";
		displayName="[41st] 24 Rnd AP Shells";
	};
};
class CfgWeapons
{
	class CannonCore;
	class 3as_TurboLaserCannonBase: CannonCore {};
	class FST_TurboLaserCannonBase: 3as_TurboLaserCannonBase
	{
		scope=2;
		displayName="[41st] Heavy Cannon";
		cursor="EmptyCursor";
		cursorAim="cannon";
		showAimCursorInternal=0;
		nameSound="cannon";
		reloadTime=6;
		magazineReloadTime=6;
		autoReload=1;
		canLock=0;
		ballisticsComputer="2 + 16";
		FCSMaxLeadSpeed=25;
		FCSZeroingDelay=1;
		aiDispersionCoefY=2;
		aiDispersionCoefX=2;
		autoFire=0;
	};
	class FST_TurboLaserCannon: FST_TurboLaserCannonBase
	{
		scope=2;
		FCSMaxLeadSpeed=30.555599;
		FCSZeroingDelay=0.5;
		magazines[]=
		{
			"FST_turbolaserCharge_24rnd",
			"4Rnd_125mm_cannon_missiles"
		};
	};
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
	};
	class 3as_Turbolaser_Base: StaticMGWeapon{};
	class FST_Turbolaser_Base: 3as_Turbolaser_Base{
		author="Adapted from 3as_Studio by Viz";
		_generalMacro="HMG_01_base_F";
		scope=0;
		displayName="[41st] XX10";
		armor=500;
		model="3AS\3as_static\XX10\XX10_Turbolaser.p3d";
		editorSubcategory="EdSubcat_Turrets";
		icon="3AS\3as_static\XX10\Data\ui\XX10_top_ca.paa";
		picture="3AS\3as_static\XX10\Data\ui\XX10_side_ca.paa";
		extCameraPosition[]={0,11,-13};
		threat[]={1,0.30000001,0.30000001};
		cost=150000;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				optics=1;
				discreteDistance[]={100,200,300,400,600,800,1000,1200,1500,1600,1700,1800,1900,2000};
				discreteDistanceInitIndex=2;
				turretInfoType="RscOptics_crows";
				gunnerOpticsModel="\a3\weapons_f_gamma\reticle\HMG_01_Optics_Gunner_F";
				minElev=-15;
				maxElev=90;
				minTurn=-360;
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
					"3as_TurboLaserCannon"
				};
				selectionFireAnim="zasleh";
				magazines[]=
				{
					"3as_turbolaserCharge_24rnd",
					"3as_turbolaserCharge_24rnd",
					"3as_turbolaserCharge_24rnd",
					"3as_turbolaserCharge_24rnd"
				};
			};
		};
	};
	class FST_XX10: FST_Turbolaser_Base
	{
		author="Adapted from 3as_Studio by Viz";
		_generalMacro="B_HMG_01_F";
		scope=2;
		side=1;
		faction="FST_Faction";
		crew="FST_Pilot_P1";
	};
	class FST_XX9: FST_Turbolaser_Base
	{
		author="Adapted from 3as_Studio by Viz";
		displayName="XX9 Turbolaser";
		model="3as\3as_static\XX10\XX9_Turbolaser.p3d";
		_generalMacro="B_HMG_01_F";
		icon="3AS\3as_static\XX10\Data\ui\XX9_top_ca.paa";
		picture="3AS\3as_static\XX10\Data\ui\XX9_side_ca.paa";
		scope=2;
		side=1;
		faction="FST_Faction";
		crew="FST_Pilot_P1";
	};
};