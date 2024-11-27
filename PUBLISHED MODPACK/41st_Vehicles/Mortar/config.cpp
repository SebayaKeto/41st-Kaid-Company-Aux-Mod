class CfgPatches
{
	class FST_mortar
	{
		units[]=
		{
			"FST_Republic_Mortar",
			"FST_Republic_Mortar_Bag",
		};
		weapons[]={};
		requiredAddons[]=
		{
			"A3_Data_F"
		};
		version=1.14;
		fileName="Data";
		author="Daara";
	};
};
class CfgVehicles
{
	class LandVehicle;
	class StaticWeapon: LandVehicle
	{
		class Turrets
		{
			class MainTurret;
		};
	};
	class StaticMortar: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics;
			};
		};
	};
	class Mortar_01_base_F: StaticMortar
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics: ViewOptics
				{
				};
			};
		};
		class assembleInfo;
	};
	class B_Mortar_01_F: Mortar_01_base_F
	{
		class SimpleObject;
	};
	class FST_Republic_Mortar: B_Mortar_01_F
	{
		displayname="[41st] Republic Mortar";
		model="3AS\3as_static\Mortar\model\republicmortar.p3d";
		editorPreview="\3as\3as_static\images\3AS_Republic_Mortar.jpg";
		crew="FST_Trooper_P2_DC15S";
		icon="3AS\3as_static\Mortar\Data\ui\Mortar_top_ca.paa";
		armor=150;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				initelev=0;
				maxelev=40;
				minelev=-15;
				initturn=0;
				maxturn=360;
				minturn=-360;
				weapons[]=
				{
					"FST_mortar_82mm"
				};
				magazines[]=
				{
					"FST_8Rnd_82mm_Mo_shells",
					"FST_8Rnd_82mm_Mo_Flare_white",
					"FST_8Rnd_82mm_Mo_Smoke_white",
					"FST_8Rnd_82mm_Mo_guided",
					"FST_8Rnd_82mm_Mo_LG"
				};
				elevationMode=3;
				gunnerforceoptics=1;
			};
		};
		class assembleInfo: assembleInfo
		{
			dissasembleTo[]=
			{
				"FST_Republic_Mortar_Bag"
			};
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3as\3as_static\mortar\data\base.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_01_damage.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_01_destruct.rvmat",
				"3as\3as_static\mortar\data\tube.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_02_damage.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_02_destruct.rvmat"
			};
		};
		hiddenSelections[]=
		{
			"Camo_1",
			"Camo_2"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Vehicles\Mortar\Data\41st_Mortar_Baseplate.paa",
			"\41st_Vehicles\Mortar\Data\41st_Mortar_tube.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"\3as\3as_static\Mortar\data\base.rvmat",
			"\3as\3as_static\Mortar\data\tube.rvmat"
		};
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		scopeCurator=2;
		scope=2;
	};
	class Bag_Base;
	class Weapon_Bag_Base: Bag_Base
	{
		class assembleInfo
		{
		};
	};
	class FST_Republic_Mortar_Bag: Weapon_Bag_Base
	{
		faction="FST_Faction";
		model="\3as\3as_static\Mortar\model\mortarpack.p3d";
		author="Daara";
		_generalMacro="B_Mortar_01_weapon_F";
		scope=2;
		scopeCurator=2;
		editorCategory="FST_Crates";
        editorSubcategory="FST_Supplies";
        displayName="[41st] Folded Republic Mortar";
        hiddenSelections[]=
        {
            "Camo_1",
            "Camo_2"
        };
        hiddenSelectionsTextures[]=
        {
            "\41st_Vehicles\Mortar\Data\41st_Mortar_Baseplate.paa", ////only change rest is reference
            "\41st_Vehicles\Mortar\Data\41st_Mortar_tube.paa"       ////only change rest is reference
        };
		hiddenSelectionsMaterials[]=
		{
			"\3as\3as_static\Mortar\data\base.rvmat",
			"\3as\3as_static\Mortar\data\tube.rvmat"
		};
		picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Small_mcamo.paa";
		mass=450;
		class assembleInfo: assembleInfo
		{
			base[]=
			{
				""
			};
			displayName="Build Mortar";
			assembleTo="FST_Republic_Mortar";
		};
	};
};
class Mode_Burst;
class Mode_SemiAuto;
class CfgWeapons
{
	class CannonCore;
	class FST_mortar_82mm: CannonCore
	{
		scope=1;
		displayname="[41st] Republic Mortar 82mm";
		nameSound="CannonCore";
		cursor="mortar";
		cursorAim="EmptyCursor";
		sounds[]=
		{
			"StandardSound"
		};
		class BaseSoundModeType;
		class StandardSound: BaseSoundModeType
		{
			soundSetShot[]=
			{
				"3AS_Mortar_SoundSet"
			};
		};
		reloadSound[]=
		{
			"A3\Sounds_F\arsenal\weapons_static\Mortar\reload_mortar",
			1,
			1,
			20
		};
		reloadMagazineSound[]=
		{
			"A3\Sounds_F\arsenal\weapons_static\Mortar\reload_magazine_Mortar",
			1,
			1,
			20
		};
		soundServo[]=
		{
			"",
			9.9999997e-005,
			1
		};
		reloadTime=1.8;
		magazineReloadTime=5;
		autoReload=1;
		canLock=0;
		magazines[]=
		{
			"FST_8Rnd_82mm_Mo_shells",
			"FST_8Rnd_82mm_Mo_Flare_white",
			"FST_8Rnd_82mm_Mo_Smoke_white",
			"FST_8Rnd_82mm_Mo_guided",
			"FST_8Rnd_82mm_Mo_LG"
		};
		ballisticsComputer=2;
		class GunParticles
		{
			class FirstEffect
			{
				effectName="MortarFired";
				positionName="Usti Hlavne";
				directionName="Konec Hlavne";
			};
		};
		modes[]=
		{
			"Single1",
			"Single2",
			"Single3",
			"Burst1",
			"Burst2",
			"Burst3"
		};
		class Single1: Mode_SemiAuto
		{
			displayName="$STR_A3_mortar_82mm_Single10";
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_Mortar_SoundSet"
				};
			};
			reloadSound[]=
			{
				"A3\Sounds_F\arsenal\weapons_static\Mortar\reload_mortar",
				1,
				1,
				20
			};
			reloadTime=1.8;
			artilleryDispersion=1.9;
			artilleryCharge=0.34999999;
			aiRateOfFire=1;
			aiRateOfFireDistance=10;
			minRange=0;
			minRangeProbab=0.0099999998;
			midRange=1;
			midRangeProbab=0.0099999998;
			maxRange=2;
			maxRangeProbab=0.0099999998;
		};
		class Single2: Single1
		{
			displayName="$STR_A3_mortar_82mm_Single20";
			artilleryCharge=0.69999999;
		};
		class Single3: Single1
		{
			displayName="$STR_A3_mortar_82mm_Single30";
			artilleryCharge=1;
		};
		class Burst1: Mode_Burst
		{
			showToPlayer=0;
			displayName="$STR_A3_mortar_82mm_Burst10";
			burst=4;
			aiBurstTerminable=1;
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				begin1[]=
				{
					"A3\Sounds_F\arsenal\weapons_static\Mortar\mortar_01",
					1.2589254,
					1,
					250
				};
				begin2[]=
				{
					"A3\Sounds_F\arsenal\weapons_static\Mortar\mortar_02",
					1.2589254,
					1,
					250
				};
				soundBegin[]=
				{
					"begin1",
					0.5,
					"begin2",
					0.5
				};
			};
			reloadSound[]=
			{
				"A3\Sounds_F\arsenal\weapons_static\Mortar\reload_mortar",
				1,
				1,
				20
			};
			soundServo[]=
			{
				"",
				9.9999997e-005,
				1
			};
			soundBurst=0;
			reloadTime=1.8;
			artilleryDispersion=2.2;
			artilleryCharge=0.34999999;
			minRange=60;
			minRangeProbab=0.5;
			midRange=290;
			midRangeProbab=0.69999999;
			maxRange=665;
			maxRangeProbab=0.5;
		};
		class Burst2: Burst1
		{
			showToPlayer=0;
			displayName="$STR_A3_mortar_82mm_Burst20";
			artilleryCharge=0.69999999;
			minRange=230;
			minRangeProbab=0.40000001;
			midRange=1175;
			midRangeProbab=0.60000002;
			maxRange=2660;
			maxRangeProbab=0.40000001;
		};
		class Burst3: Burst1
		{
			showToPlayer=0;
			displayName="$STR_A3_mortar_82mm_Burst30";
			artilleryCharge=1;
			minRange=540;
			minRangeProbab=0.30000001;
			midRange=2355;
			midRangeProbab=0.40000001;
			maxRange=5500;
			maxRangeProbab=0.30000001;
		};
	};
};
class CfgMagazines
{
	class VehicleMagazine;
	class FST_8Rnd_82mm_Mo_shells: VehicleMagazine
	{
		author="Daara";
		displayName="[41st] HE Mortar Shells";
		displayNameShort="HE";
		displayNameMFDFormat="HE";
		scope=2;
		count=24;
		ammo="FST_82mm_HE_Mortar";
		nameSound="heat";
		muzzleImpulseFactor[]={0,0};
		initSpeed=200;
		ace_arsenal_hide=-1;
		ace_artillerytables_airFriction=-9.9999997e-005;
	};
	class FST_8Rnd_82mm_Mo_Flare_white: FST_8Rnd_82mm_Mo_shells
	{
		author="Daara";
		ammo="FST_82mm_Flare_White";
		displayName="[41st] Flare Mortar Shell (White)";
		displayNameShort="White Flare";
		count=6;
	};
	class FST_8Rnd_82mm_Mo_Smoke_white: FST_8Rnd_82mm_Mo_shells
	{
		author="Daara";
		ammo="FST_82mm_Smoke_White";
		displayName="[41st] Smoke Mortar Shell (White)";
		displayNameShort="White Smoke";
		count=12;
	};
	class FST_8Rnd_82mm_Mo_guided: FST_8Rnd_82mm_Mo_shells
	{
		author="Daara";
		ammo="FST_82mm_Guided_Mortar";
		displayName="[41st] Guided Mortar Shells";
		displayNameShort="Guided";
		count=12;
	};
	class FST_8Rnd_82mm_Mo_LG: FST_8Rnd_82mm_Mo_shells
	{
		author="Daara";
		ammo="FST_82mm_LG_Mortar";
		displayName="[41st] Laser Guided Mortar Shells";
		displayNameShort="Laser Guided";
		count=6;
	};
};
class CfgAmmo
{
	class SubmunitionBase;
	class Sh_155mm_AMOS;
	class FlareCore;
	class ShotDeployBase;
	class FST_82mm_HE_Mortar: Sh_155mm_AMOS
	{
		displayname="[41st] Republic HE Mortar Shell";
		hit=340;
		indirectHit=125;
		indirectHitRange=15;
		cost=200;
		muzzleEffect="";
		warheadName="HE";
		dangerRadiusHit=750;
		suppressionRadiusHit=75;
		typicalSpeed=800;
		caliber=10;
		deflecting=0;
		explosive=0.80000001;
		effectFly="3AS_PlasmaBolt_Medium_Yellow_Fly";
		class CamShakeExplode
		{
			power=16.4;
			duration=1.8;
			frequency=20;
			distance=216.44299;
		};
		class CamShakeHit
		{
			power=82;
			duration=0.60000002;
			frequency=20;
			distance=1;
		};
		class CamShakeFire
		{
			power=3.0092199;
			duration=1.8;
			frequency=20;
			distance=72.4431;
		};
		class CamShakePlayerFire
		{
			power=0.0099999998;
			duration=0.1;
			frequency=20;
			distance=1;
		};
	};
	class FST_82mm_Flare_White: FlareCore
	{
		timeToLive=90;
		model="\A3\weapons_f\ammo\shell";
		effectFlare="CounterMeasureFlare";
		aimAboveTarget[]={30,60,120,180,240,300,360};
		aimAboveDefault=8;
		triggerTime=-1;
		triggerSpeedCoef=1;
		lightColor[]={0.94999999,0.94999999,1,0.5};
		smokeColor[]={1,1,1,0.5};
		intensity=1000000;
	};
	class FST_82mm_Smoke_White: ShotDeployBase
	{
		model="\A3\weapons_f\ammo\shell";
		submunitionAmmo="SmokeShellArty";
	};
	class FST_82mm_Guided_Mortar: SubmunitionBase
	{
		submunitionAmmo="3AS_M_82mm_AT";
		submunitionCount=1;
		submunitionConeAngle=0;
		laserLock=0;
		autoSeekTarget=1;
		cost=200;
		muzzleEffect="";
		triggerDistance=300;
		airFriction=0;
		hit=165;
		effectFly="3AS_PlasmaBolt_Medium_Yellow_Fly";
		class CamShakeFire
		{
			power=3.0092199;
			duration=1.8;
			frequency=20;
			distance=72.4431;
		};
		class CamShakePlayerFire
		{
			power=0.0099999998;
			duration=0.1;
			frequency=20;
			distance=1;
		};
	};
	class FST_82mm_LG_Mortar: FST_82mm_Guided_Mortar
	{
		submunitionAmmo="3AS_M_82mm_AT_LG";
		cost=500;
		laserLock=1;
		irLock=0;
		muzzleEffect="";
	};
};