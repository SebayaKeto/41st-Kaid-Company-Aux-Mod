class CfgPatches
{
	class FST_Static_J1_Proton_Cannon
	{
		addonRootClass="FST_J1_Cannon";
		requiredAddons[]=
		{
			"41st_Weapons_Vehicle",
			"3AS_VehicleWeapons"
		};
		units[]=
		{
			"FST_J1_Proton_Cannon",
			"FST_J1_Proton_Legged",
			"FST_J1_Proton_AT",
			"FST_J1_Proton_AT_Legged",
			"FST_J1_Cinematic_Proton_Cannon",
			"FST_J1_Cinematic_Proton_Legged"
		};
		author="Viz";
		weapons[]={};
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

class Mode_SemiAuto;
class Mode_FullAuto;
class Mode_Burst;
class CfgAmmo
{
	class ammo_Penetrator_Base;
	class Cinematic_ammo_Penetrator_AAT: ammo_Penetrator_Base
	{
		caliber=43.333302;
		warheadName="TandemHEAT";
		hit=0;
		effectFly="3AS_PlasmaBolt_Large_Red_Fly";
	};
	class 3AS_Proton_AT;
	class FST_Proton_AT: 3AS_Proton_AT
	{
		author="Adapted from 3AS by Viz";
		hit=450;
		warheadName="TandemHEAT";
		submunitionAmmo="ammo_Penetrator_AAT";
		submunitionDirectionType="SubmunitionModelDirection";
		submunitionInitSpeed=1000;
		submunitionParentSpeedCoef=0;
		submunitionInitialOffset[]={0,0,-0.2};
		indirectHit=30;
		indirectHitRange=5;
		typicalSpeed=1400;
		explosive=0.30000001;
		cost=50;
		airFriction=-0.000275;
		airlock=1;
		deflecting=0;
		model="3as\3AS_Weapons\Data\tracer_shell_red.p3d";
		tracerScale=1;
		tracerStartTime=0.0099999998;
		tracerEndTime=3;
		explosionSoundEffect="DefaultExplosion";
		effectFly="3AS_PlasmaBolt_Large_Red_Fly";
		soundFly[]=
		{
			"",
			0.56234133,
			1,
			1500
		};
		muzzleEffect="";
		simulation="shotbullet";
		CraterEffects="ATRocketCrater";
		explosionEffects="MortarExplosion";
		aiAmmoUsageFlags="64 + 128 + 256 + 512";
	};
	class FST_Proton_AT_Cinematic: FST_Proton_AT
	{
		author="Viz";
		submunitionAmmo="Cinematic_ammo_Penetrator_AAT";
		hit=0;
		indirectHit=0;
		indirectHitRange=0;
		explosive=0.30000001;
		cost=50;
	};
};
class CfgMagazines
{
	class VehicleMagazine;
	class FST_6Rnd_Proton_AP: VehicleMagazine
	{
		author="Adapted from 3AS by Viz";
		dispalyName="6 Rnd Proton HEAT Shells";
		displayNameShort="6 Rnd HEAT";
		ammo="FST_Proton_AT";
		initSpeed=1330;
		count=6;
		maxLeadSpeed=25;
		tracersEvery=1;
		nameSound="cannon";
		muzzleImpulseFactor[]={0.5,3};
		effectFly="3AS_PlasmaBolt_Large_Red_Fly";
	};
	class FST_10Rnd_Proton_AP: VehicleMagazine
	{
		author="Adapted from 3AS by Viz";
		dispalyName="10 Rnd Proton HEAT Shells";
		displayNameShort="10 Rnd HEAT";
		ammo="FST_Proton_AT";
		initSpeed=1330;
		count=10;
		maxLeadSpeed=25;
		tracersEvery=1;
		nameSound="cannon";
		muzzleImpulseFactor[]={0.5,3};
		effectFly="3AS_PlasmaBolt_Large_Red_Fly";
	};
	class FST_6Rnd_Proton_Cinematic: FST_6Rnd_Proton_AP
	{
		author="Adapted from 3AS by Viz";
		ammo="FST_Proton_AT_Cinematic";
	};
	class FST_10Rnd_Proton_Cinematic: FST_10Rnd_Proton_AP
	{
		author="Adapted from 3AS by Viz";
		ammo="FST_Proton_AT_Cinematic";
	};
};
class CfgWeapons
{
	class 3AS_HeavyAATCannon_Base;
	class FST_Proton_Cannon: 3AS_HeavyAATCannon_Base
	{
		author="Adapted from 3AS by Viz";
		scope=2;
		FCSMaxLeadSpeed=30.555599;
		FCSZeroingDelay=0.5;
		reloadTime=9;
		magazineReloadTime=6;
		magazines[]=
		{
			"FST_6Rnd_Proton_AP",
			"FST_10Rnd_Proton_AP"
		};
		class manual: Mode_SemiAuto
		{
			displayName="J1 Cannon";
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_J1_SoundSet"
				};
			};
			reloadTime=2;
			soundBurst=0;
			dispersion=0.003;
			showToPlayer=1;
			minRange=2;
			minRangeProbab=0.5;
			midRange=150;
			midRangeProbab=0.69999999;
			maxRange=450;
			maxRangeProbab=0.30000001;
			aiRateOfFire=2;
			aiRateOfFireDistance=150;
		};
		class close: manual
		{
			showToPlayer=0;
			soundBurst=0;
			soundContinuous=0;
			aiRateOfFire=2;
			aiRateOfFireDistance=500;
			aiRateOfFireDispersion=1;
			minRange=0;
			minRangeProbab=0.050000001;
			midRange=100;
			midRangeProbab=0.57999998;
			maxRange=300;
			maxRangeProbab=0.30000001;
		};
		class short: close
		{
			minRange=150;
			minRangeProbab=0.2;
			midRange=500;
			midRangeProbab=0.69999999;
			maxRange=1500;
			maxRangeProbab=0.40000001;
			aiRateOfFire=3;
			aiRateOfFireDistance=500;
			aiRateOfFireDispersion=2;
		};
		class medium: close
		{
			minRange=250;
			minRangeProbab=0.2;
			midRange=750;
			midRangeProbab=0.69999999;
			maxRange=1000;
			maxRangeProbab=0.40000001;
			aiRateOfFire=5;
			aiRateOfFireDistance=700;
			aiRateOfFireDispersion=3;
		};
		class far: close
		{
			minRange=500;
			minRangeProbab=0.2;
			midRange=1200;
			midRangeProbab=0.69999999;
			maxRange=2100;
			maxRangeProbab=0.30000001;
			aiRateOfFire=7;
			aiRateOfFireDistance=1000;
			aiRateOfFireDispersion=3;
		};
	};
	class FST_Cinematic_Proton_Cannon: FST_Proton_Cannon
	{
		magazines[]=
		{
			"FST_10Rnd_Proton_Cinematic",
			"FST_6Rnd_Proton_Cinematic"
		};
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
	class FST_J1_Proton_Cannon: StaticMGWeapon
	{
		author="Adapted from 3AS by Viz";
		_generalMacro="B_HMG_01_F";
		scope=2;
		scopeCurator=2;
		side=0;
		faction="FST_BattleDroids_Faction";
		crew="FST_Droid_B1_OOM";
		displayName="[41st] J1 Proton Cannon";
		class Armory
		{
			description="";
		};
		model="3AS\3AS_CIS_Static\J1_Proton_Cannon\model\3AS_J1_Proton_Cannon.p3d";
		editorSubcategory="EdSubcat_Turrets";
		icon="3as\3AS_CIS_Static\J1_Proton_Cannon\Data\ui\J1_top_ca.paa";
		picture="3as\3AS_CIS_Static\J1_Proton_Cannon\Data\ui\J1_side_ca.paa";
		threat[]={1,0.30000001,0.30000001};
		cost=150000;
		getInAction="";
		getOutAction="";
		armor=200;
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3as\3AS_CIS_Static\J1_Proton_Cannon\Data\J1_Body.rvmat",
				"3as\3AS_CIS_Static\J1_Proton_Cannon\Data\damage\Body_damage.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat",
				"3as\3AS_CIS_Static\J1_Proton_Cannon\Data\J1_Gun_Legs.rvmat",
				"3as\3AS_CIS_Static\J1_Proton_Cannon\Data\damage\Gun_damage.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat",
				"3as\3AS_CIS_Static\J1_Proton_Cannon\Data\J1_Gun_Plate.rvmat",
				"3as\3AS_CIS_Static\J1_Proton_Cannon\Data\damage\Gun_Plate_damage.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat"
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				optics=1;
				discreteDistance[]={100,200,300,400,600,800,1000,1200,1500,1600,1700,1800,1900,2000};
				discreteDistanceInitIndex=2;
				turretInfoType="RscOptics_crows";
				gunnerOpticsModel="\a3\weapons_f_gamma\reticle\HMG_01_Optics_Gunner_F";
				minElev=-30;
				maxElev=15;
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
					"FST_Proton_Cannon"
				};
				proxyType="CPGunner";
				proxyIndex=1;
				magazines[]=
				{
					"FST_6Rnd_Proton_AP",
					"FST_6Rnd_Proton_AP",
					"FST_6Rnd_Proton_AP",
					"FST_6Rnd_Proton_AP",
					"FST_6Rnd_Proton_AP",
					"FST_6Rnd_Proton_AP",
					"FST_6Rnd_Proton_AP",
					"FST_6Rnd_Proton_AP",
					"FST_6Rnd_Proton_AP",
					"FST_6Rnd_Proton_AP",
					"FST_6Rnd_Proton_AP",
					"FST_6Rnd_Proton_AP",
					"FST_6Rnd_Proton_AP",
					"FST_6Rnd_Proton_AP",
					"FST_6Rnd_Proton_AP",
					"FST_6Rnd_Proton_AP"
				};
				gunnerAction="FieldCannon_Gunner";
				gunnergetInAction="";
				gunnergetOutAction="";
				memoryPointGunnerOptics="gunnerview";
				memoryPointsGetInGunner="pos_gunner";
				memoryPointsGetInGunnerDir="pos_gunner_dir";
				selectionFireAnim="zasleh";
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
				aggregateReflectors[]=
				{
					
					{
						"Light_1"
					}
				};
			};
		};
		class AnimationSources
		{
			class Muzzle_Flash
			{
				source="ammorandom";
				weapon="3AS_AATCannon";
			};
			class ReloadAnim
			{
				source="reload";
				weapon="3AS_AATCannon";
			};
			class Reload1
			{
				source="reload";
				weapon="3AS_AATCannon";
			};
			class ReloadMagazine
			{
				source="reloadmagazine";
				weapon="3AS_AATCannon";
			};
			class Revolving
			{
				source="revolving";
				weapon="3AS_AATCannon";
			};
		};
		hiddenselections[]=
		{
			"camo0",
			"camo1"
		};
		hiddenselectionstextures[]=
		{
			"3as\3as_cis_static\j1_proton_cannon\data\j1_body_co.paa",
			"3as\3as_cis_static\j1_proton_cannon\data\j1_gun_plate_co.paa"
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
	class FST_J1_Proton_Legged: FST_J1_Proton_Cannon
	{
		author="Adapted from 3AS by Viz";
		displayName="[41st] J1 Proton Cannon (Legged)";
		scope=2;
		scopeCurator=2;
		side=0;
		faction="FST_BattleDroids_Faction";
		crew="FST_Droid_B1_OOM";
		icon="3as\3AS_CIS_Static\J1_Proton_Cannon\Data\ui\J1_Legged_top_ca.paa";
		picture="3as\3AS_CIS_Static\J1_Proton_Cannon\Data\ui\J1_Legged_side_ca.paa";
		model="3AS\3AS_CIS_Static\J1_Proton_Cannon\model\3AS_J1_Proton_Legged.p3d";
		hiddenselections[]=
		{
			"camo0",
			"camo1"
		};
		hiddenselectionstextures[]=
		{
			"3as\3as_cis_static\j1_proton_cannon\data\j1_body_co.paa",
			"3as\3as_cis_static\j1_proton_cannon\data\j1_gun_Legs_co.paa"
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				maxHorizontalRotSpeed=0.60000002;
				maxVeritcalRotSpeed=0.80000001;
				magazines[]=
				{
					"FST_10Rnd_Proton_AP",
					"FST_10Rnd_Proton_AP",
					"FST_10Rnd_Proton_AP",
					"FST_10Rnd_Proton_AP",
					"FST_10Rnd_Proton_AP",
					"FST_10Rnd_Proton_AP",
					"FST_10Rnd_Proton_AP",
					"FST_10Rnd_Proton_AP",
					"FST_10Rnd_Proton_AP",
					"FST_10Rnd_Proton_AP",
					"FST_10Rnd_Proton_AP",
					"FST_10Rnd_Proton_AP",
					"FST_10Rnd_Proton_AP",
					"FST_10Rnd_Proton_AP",
					"FST_10Rnd_Proton_AP",
					"FST_10Rnd_Proton_AP"
				};
			};
		};
	};
	class FST_J1_Proton_AT: FST_J1_Proton_Cannon
	{
		author = "Ruby";
		displayname = "[41st] J1 Proton Cannon (AT)";
		scope = 2;
		scopecurator=2;
		side=0;
		faction="FST_BattleDroids_Faction";
		crew="FST_Droid_B1_OOM";
		model="3AS\3AS_CIS_Static\J1_Proton_Cannon\model\3AS_J1_Proton_Cannon.p3d";
		editorSubcategory="EdSubcat_Turrets";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[]=
				{
					"3AS_Hailfire_Barrage_Weapon"
				};
				magazines[]=
				{
					"3AS_30Rnd_Missile",
					"3AS_30Rnd_Missile",
					"3AS_30Rnd_Missile",
					"3AS_30Rnd_Missile"
				};
			};
		};
	};
	class FST_J1_Proton_AT_Legged: FST_J1_Proton_Legged
	{
		author = "Ruby";
		displayname = "[41st] J1 Proton Cannon (AT/Legged)";
		scope = 2;
		scopecurator=2;
		side=0;
		faction="FST_BattleDroids_Faction";
		crew="FST_Droid_B1_OOM";
		model="3AS\3AS_CIS_Static\J1_Proton_Cannon\model\3AS_J1_Proton_Legged.p3d";
		hiddenselections[]=
		{
			"camo0",
			"camo1"
		};
		hiddenselectionstextures[]=
		{
			"3as\3as_cis_static\j1_proton_cannon\data\j1_body_co.paa",
			"3as\3as_cis_static\j1_proton_cannon\data\j1_gun_Legs_co.paa"
		};
		editorSubcategory="EdSubcat_Turrets";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[]=
				{
					"3AS_Hailfire_Barrage_Weapon"
				};
				magazines[]=
				{
					"3AS_30Rnd_Missile",
					"3AS_30Rnd_Missile",
					"3AS_30Rnd_Missile",
					"3AS_30Rnd_Missile"
				};
			};
		};
	};
	class FST_J1_Cinematic_Proton_Cannon: FST_J1_Proton_Cannon
	{
		author="Adapted from 3AS by Viz";
		displayName="[41st] J1 Proton Cannon (Cinematic)";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[]=
				{
					"FST_Cinematic_Proton_Cannon"
				};
				magazines[]=
				{
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic",
					"FST_6Rnd_Proton_Cinematic"
				};
			};
		};
	};
	class FST_J1_Cinematic_Proton_Legged: FST_J1_Cinematic_Proton_Cannon
	{
		author="Adapted from 3AS by Viz";
		displayName="[41st] J1 Proton Cannon (Cinematic/Legged)";
		scope=2;
		scopeCurator=2;
		side=0;
		faction="FST_BattleDroids_Faction";
		crew="FST_Droid_B1_OOM";
		icon="3as\3AS_CIS_Static\J1_Proton_Cannon\Data\ui\J1_Legged_top_ca.paa";
		picture="3as\3AS_CIS_Static\J1_Proton_Cannon\Data\ui\J1_Legged_side_ca.paa";
		model="3AS\3AS_CIS_Static\J1_Proton_Cannon\model\3AS_J1_Proton_Legged.p3d";
		hiddenselections[]=
		{
			"camo0",
			"camo1"
		};
		hiddenselectionstextures[]=
		{
			"3as\3as_cis_static\j1_proton_cannon\data\j1_body_co.paa",
			"3as\3as_cis_static\j1_proton_cannon\data\j1_gun_Legs_co.paa"
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				magazines[]=
				{
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic",
					"FST_10Rnd_Proton_Cinematic"
				};
				maxHorizontalRotSpeed=0.60000002;
				maxVeritcalRotSpeed=0.80000001;
			};
		};
	};
};