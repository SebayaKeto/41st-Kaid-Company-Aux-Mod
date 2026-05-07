class cfgpatches
{
	class FST_HAGM_Tank
	{
		requiredAddons[]=
		{
			"3AS_Main",
			"3AS_VehicleWeapons"
		};
		weapons[]={};
		units[]=
		{
			"FST_HAGM",
            "FST_HAGM_Cinematic"
		};
	};
};
class Mode_SemiAuto;

class CfgVehicles
{
    class Tank;
    class Tank_F: Tank
    {
        class Turrets;
    };
    class 3AS_HAGM_Tan: Tank_F
    {
        class Turrets: Turrets
        {
            class MainTurret;
        };
        class ACE_SelfActions;
    };
    class FST_HAGM: 3AS_HAGM_Tan
    {
        scope = 2;
        scopecurator = 2;
        author = "Ruby";
        faction = "FST_BattleDroids_Faction";
		editorSubcategory = "FST_Ground_Vehicle";
		crew = "FST_Droid_B1_OOM";
        displayname =  "[41st] HAG-M Artillery Tank";
        class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets
				{};
                weapons[]=
				{
					"FST_HAGM_mortar"
				};
				magazines[]=
				{
					"FST_32Rnd_155mm_HAGM_Mortar_shells",
					"FST_32Rnd_155mm_HAGM_Mortar_shells",
					"FST_32Rnd_155mm_HAGM_Mortar_shells",
				};
            };
        };
    };
};

class CfgWeapons
{
	class CannonCore;
	class mortar_155mm_AMOS: CannonCore{};
	class FST_HAGM_mortar: mortar_155mm_AMOS
	{
        scope=2;
		displayName="[41st] HAGM Mortar";
		nameSound="cannon";
		cursor="mortar";
		cursorAim="EmptyCursor";
        reloadTime=10;
		magazines[]=
		{
			"FST_32Rnd_155mm_HAGM_Mortar_shells",
			"FST_8Rnd_82mm_Mo_Flare_white",
			"FST_8Rnd_82mm_Mo_Smoke_white"
        };
        modes[] = {"Single1", "Single2", "Single3"};
		class Single1: Mode_SemiAuto {
			artilleryCharge = 0.19;
			displayName = "$STR_A3_mortar_120mm_AMOS_Single10";
            aiRateOfFire=1;
			aiRateOfFireDistance=10;
			maxRange = 500;
			minRange = 200;
			reloadTime=2;
			magazineReloadTime=10;
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_HeavyTurboLaser_SoundSet"
				};
			};
		};
		class Single2: Single1 {
			artilleryCharge = 0.3;
			displayName = "$STR_A3_mortar_120mm_AMOS_Single20";
			maxRange = 2450;
		};
		class Single3: Single1 {
			artilleryCharge = 0.48;
			displayName = "$STR_A3_mortar_120mm_AMOS_Single30";
			maxRange = 3760;
		};
		class GunParticles
		{
		};
	};
};

class CfgMagazines
{
    class VehicleMagazine;
    class 32Rnd_155mm_Mo_shells;
	class FST_32Rnd_155mm_HAGM_Mortar_shells: 32Rnd_155mm_Mo_shells
	{
		scope=2;
		displayName="155mm HAGM Shells";
		displayNameShort="HESH";
		displayNameMFDFormat="HESH";
		ammo="FST_ATAP_155mm_AMOS_Mortar_Ammo";
		count=32;
		initSpeed=400;
		nameSound="heat";
		muzzleImpulseFactor[]={0.5,0.5};
	};
};

class CfgAmmo
{
    class Sh_155mm_AMOS;
    class FST_ATAP_155mm_AMOS_Mortar_Ammo: Sh_155mm_AMOS
    {
        model="3as\3as_weapons\data\tracer_shell_Red";
		effectFly="3AS_PlasmaBolt_Medium_Blue_Red";
        hit=640;
        indirectHit=95;
        indirectHitRange=6.25;
        warheadName="HESH";
        caliber=22;
        deflecting=5;
        cost=300;
        timeToLive=180;
        aiAmmoUsageFlags="64 + 128 + 256 + 512";
        CraterEffects="ArtyShellCrater";
        ExplosionEffects="MortarExplosion";
        suppressionRadiusHit=75;
        explosive=0.80000001;
        submunitionAmmo="3AS_ATAP_HE_Submunition";
        submunitionConeType[]=
        {
            "randomcenter",
            1
        };
        submunitionInitialOffset[]={0,0,0.2};
        submunitionInitSpeed=5;
	};
};