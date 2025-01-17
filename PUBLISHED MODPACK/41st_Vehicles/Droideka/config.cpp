class CfgPatches
{
	class FST_Droideka
	{
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Armor_F_Beta",
			"3AS_Main"
		};
		units[]=
		{
			"FST_Droideka",
			"FST_Deka_Wreck",
			"FST_Sniper_Deka"
		};
		weapons[]={};
	};
};
class CfgAmmo
{
    class FST_blasterbolt_Overcharged_red;
    class FST_blasterbolt_Overcharged_Droideka: FST_blasterbolt_Overcharged_Red
    {
        model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
        effectfly="IDA_BlasterBoltGlow_Medium_Red_Fly";
        lightcolor[]={1,0,0};
        ACE_damageType="plasma";
        hit=40;
        indirectHit=20;
        explosive=1;
        indirectHitRange=0.5;
        caliber=2;
        explosionEffects="";
        craterEffects="";
    };
};
class CfgMagazines
{
    class 100Rnd_65x39_caseless_mag;
    class FST_blaster_battery_Droideka: 100Rnd_65x39_caseless_mag
    {
        author="Daara";
        JLTS_hasElectronics=0;
        JLTS_hasEMPProtection=1;
        scope=2;
        modelSpecial="";
        modelSpecialIsProxy=0;
        picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
        model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
        count=100;
        displayName="[41st] Overcharged High-Power Energy Cell (Droideka)";
        displayNameShort="OHP Energy battery";
        descriptionShort="100 round capacity.";
        ammo="FST_blasterbolt_Overcharged_Droideka";
        tracersEvery=1;
        initSpeed=275;
        mass=25;
    };
};
class Mode_FullAuto;
class CfgWeapons
{
    class Cannon_droideka;
    class FST_Droideka_Cannon: Cannon_droideka
    {
        JLTS_hasElectronics=1;
        JLTS_hasEMPProtection=0;
        JLTS_repairTime=5;
        ace_overheating_mrbs=40000;
        ace_overheating_slowdownFactor=0;
        ace_overheating_allowSwapBarrel=0;
        ace_overheating_dispersion=1;
        ace_overheating_closedBolt=0;
        ace_overheating_barrelMass=1;
        author="Daara";
        scope=1;
        inertia=0;
        canShootInWater=1;
        baseWeapon="FST_Droideka_Cannon";
        displayName="[41st] Droideka Cannon";
        descriptionShort="High Damage, Cover Penetrating";
        magazines[]=
        {
            "FST_blaster_battery_Droideka"
        };
        ballisticsComputer=1;
        autoFire=1;
        canLock=2;
        airLock=1;
        weaponInfoType="RscWeaponZeroing";
        cursor="EmptyCursor";
        cursorAim="cannon";
        nameSound="cannon";
        initSpeed=310;
        muzzlePos="usti hlavne";
        muzzleEnd="konec hlavne";
        selectionFireAnim="";
        reloadTime=1;
        reloadmagazinetime=4;
        magazinereloadtime=4;
        fireLightDuration=0.029999999;
        fireLightIntensity=0.5;
        fireLightDiffuse[]={1,0,0};
        fireLightAmbient[]={0.1,0,0};
        soundBullet[]={};
        soundContinuous=0;
        reloadMagazineSound[]=
        {
            "",
            1,
            1,
            1
        };
        reloadSound[]=
        {
            "",
            1,
            1,
            1
        };
        modes[]=
        {
            "manual",
            "close",
            "short",
            "Medium",
            "Far",
        };
        class manual: Mode_FullAuto
        {
            autoFire=1;
            sounds[]=
            {
                "StandardSound"
            };
            class StandardSound
            {
				closure1[]=
				{
					"A3\sounds_f\weapons\closure\sfx7",
					0.56234133,
					1,
					40
				};
				closure2[]=
				{
					"A3\sounds_f\weapons\closure\sfx8",
					0.56234133,
					1,
					40
				};
				soundClosure[]=
				{
					"closure1",
					0.5,
					"closure2",
					0.5
				};
				begin1[]=
				{
					"A3\Sounds_F\arsenal\weapons_vehicles\LMG_65mm\LMG_65mm_turret_01",
					1,
					1,
					2100
				};
				begin2[]=
				{
					"A3\Sounds_F\arsenal\weapons_vehicles\LMG_65mm\LMG_65mm_turret_02",
					1,
					1,
					2100
				};
				begin3[]=
				{
					"A3\Sounds_F\arsenal\weapons_vehicles\LMG_65mm\LMG_65mm_turret_03",
					1,
					1,
					2100
				};
				soundBegin[]=
				{
					"begin1",
					0.34,
					"begin2",
					0.33000001,
					"begin3",
					0.33000001
				};
				soundsetshot[]=
				{
					"3AS_Droideka_Shot_SoundSet"
				};
			};
            recoil="empty";
            reloadTime=0.1000001;
            reloadmagazinetime=4;
            magazinereloadtime=4;
            soundBurst=0;
            dispersion=0.0060000001;
            showToPlayer=1;
            aiRateOfFireDistance=50;
            minRange=1;
            minRangeProbab=0.0099999998;
            midRange=2;
            midRangeProbab=0.0099999998;
            maxRange=3;
            maxRangeProbab=0.0099999998;
            textureType="fullAuto";
        };
        class close: manual
        {
            showToPlayer=0;
            burst=20;
            aiBurstTerminable=1;
            aiRateOfFire=0.15000001;
            aiRateOfFireDistance=400;
            minRange=0;
            minRangeProbab=0.050000001;
            midRange=200;
            midRangeProbab=0.57999998;
            maxRange=400;
            maxRangeProbab=0.2;
        };
        class short: close
        {
            burst=20;
            aiBurstTerminable=1;
            aiRateOfFire=0.15000001;
            aiRateOfFireDistance=500;
            minRange=300;
            minRangeProbab=0.2;
            midRange=400;
            midRangeProbab=0.57999998;
            maxRange=500;
            maxRangeProbab=0.2;
        };
        class medium: close
        {
            burst=15;
            aiBurstTerminable=1;
            aiRateOfFire=0.2;
            aiRateOfFireDistance=9000;
            minRange=400;
            minRangeProbab=0.2;
            midRange=700;
            midRangeProbab=0.57999998;
            maxRange=900;
            maxRangeProbab=0.2;
        };
        class far: close
        {
            burst=10;
            aiBurstTerminable=1;
            aiRateOfFire=0.40000001;
            aiRateOfFireDistance=1500;
            minRange=800;
            minRangeProbab=0.2;
            midRange=1000;
            midRangeProbab=0.40000001;
            maxRange=1500;
            maxRangeProbab=0.0099999998;
        };
    };
};
class RCWSOptics;
class CfgVehicles
{
	class LandVehicle;
	class Tank: LandVehicle
	{
		class NewTurret;
		class Sounds;
		class HitPoints;
		class CommanderOptics;
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
	class 3AS_Deka_Static_Base: StaticMGWeapon {};
	class FST_Droideka_Base: 3AS_Deka_Static_Base
	{
		author="Viz";
		scope=0;
		scopeCurator=0;
		faction="FST_BattleDroids_Faction";
        editorSubcategory="FST_Ground_Vehicle";
		model="3AS\3AS_Deka\Deka.p3d";
		armor=50;
		accuracy=1;
		class Hitpoints
		{
			class HitHull
			{
				armor=1000;
				material=-1;
				name="hull_hit";
				visual="zbytek";
				passthrough=0.029999999;
				minimalhit=0.14;
				explosionshielding=2;
				radius=0.25;
			};
			class HitEngine
			{
				armor=300;
				material=-1;
				name="engine_hit";
				passThrough=0.079999998;
				minimalHit=0.23999999;
				explosionShielding=1;
				radius=0.33000001;
			};
			class HitShield
			{
				armorComponent="Deka_Shield_Component";
				armor=10;
				material=-1;
				name="Shield_hit";
				passThrough=0;
				minimalHit=0;
				explosionShielding=1;
				radius=0.33000001;
			};
			class hitammo_l: HitEngine
			{
				name="ammo_l_hit";
			};
			class hitammo_r: hitammo_l
			{
				name="ammo_r_hit";
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				memoryPointGunnerOptics="gunner_view";
				gunBeg="Usti hlavne";
				gunEnd="Konec hlavne";
				memoryPointGun[]=
				{
					"Usti hlavne",
					"Usti hlavne2"
				};
				primary=1;
				primaryGunner=1;
				enableManualFire=1;
				optics=0;
				minElev=-15;
				maxElev=35;
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
					"FST_Droideka_Cannon"
				};
				magazines[]=
				{
					"FST_blaster_battery_Droideka",
					"FST_blaster_battery_Droideka",
					"FST_blaster_battery_Droideka",
					"FST_blaster_battery_Droideka",
					"FST_blaster_battery_Droideka"
				};
				gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Gunner_F.p3d";
				gunnerForceOptics=1;
				turretInfoType="RscOptics_UAV_gunner";
				LODTurnedIn=-1;
				LODTurnedOut=-1;
				visionMode[]=
				{
					"Normal",
					"NVG",
					"TI"
				};
				gunnergetInAction="";
				gunnergetOutAction="";
				displayName="";
				gunnerOutOpticsModel="";
				gunnerOutOpticsEffect[]={};
				gunnerOpticsEffect[]={};
				gunnerInAction="Disabled";
				gunnerAction="Disabled";
				forceHideGunner=1;
				inGunnerMayFire=1;
				viewGunnerInExternal=1;
				class Turrets
				{
				};
				class ViewOptics: RCWSOptics
				{
					visionMode[]=
					{
						"Normal",
						"TI"
					};
				};
				class HitPoints
				{
					class HitTurret
					{
						armor=0.80000001;
						material=-1;
						name="main_turret_hit";
						visual="vez";
						passThrough=0;
						minimalHit=0.02;
						explosionShielding=0.30000001;
						radius=0.25;
					};
					class HitGun
					{
						armor=0.30000001;
						material=-1;
						name="main_gun_hit";
						visual="";
						passThrough=0;
						minimalHit=0;
						explosionShielding=1;
						radius=0.25;
					};
				};
			};
		};
		class AnimationSources
		{
			class Muzzle_Flash
			{
				source="ammorandom";
				weapon="FST_Droideka_Cannon";
			};
			class recoil_source
			{
				source="reload";
				weapon="FST_Droideka_Cannon";
			};
		};
		hiddenselections[]=
		{
			"camo"
		};
		hiddenselectionstextures[]=
		{
			"\3AS\3AS_deka\data\deka_co.paa"
		};
	};
	class FST_Droideka: FST_Droideka_Base
	{
		_generalMacro="B_HMG_01_F";
		TAS_DekaShieldRegen=0.02;
		author="Viz";
		displayName="[41st] Droideka";
		scope=2;
		scopeCurator=2;
		scopearsenal=2;
		side=0;
		crew="O_UAV_AI";
	};
	class FST_Droideka_Christmas: FST_Droideka
	{
		author="Viz";
		displayName="[41st] Jack Frostdeka";
		model="\Christmas_Snowmans\objects\ClothesSnowman.p3d";
	};
	class FST_Deka_Static_Sniper_Base: FST_Droideka_Base
	{
		icon="3AS\3AS_Deka\data\ui\Deka_Sniper_top_ca.paa";
		picture="3AS\3AS_Deka\data\ui\Deka_Sniper_side_ca.paa";
		model="\3AS\3AS_deka\deka_Sniper.p3d";
		hiddenselections[]=
		{
			"camo"
		};
		hiddenselectionstextures[]=
		{
			"\3AS\3AS_deka\data\sniperdroideka_co.paa"
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3AS\3AS_deka\data\dekaSniper.rvmat",
				"3AS\3AS_deka\data\dekaSniper.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat"
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunBeg="Usti hlavne";
				gunEnd="Konec hlavne";
				memoryPointGun[]=
				{
					"usti hlavne"
				};
				gunnerForceOptics=1;
				optics=1;
				minElev=-15;
				maxElev=35;
				minTurn=-360;
				maxTurn=360;
				weapons[]=
				{
					"3AS_Deka_Sniper"
				};
				magazines[]=
				{
					"3AS_10Rnd_EM100_AP_Mag",
					"3AS_10Rnd_EM100_AP_Mag",
					"3AS_10Rnd_EM100_AP_Mag",
					"3AS_10Rnd_EM100_AP_Mag",
					"3AS_10Rnd_EM100_AP_Mag"
				};
			};
		};
		class AnimationSources: AnimationSources
		{
			class Muzzle_Flash
			{
				source="ammorandom";
				weapon="3AS_Deka_Sniper";
			};
			class recoil_source
			{
				source="reload";
				weapon="3AS_Deka_Sniper";
			};
		};
	};
	class FST_Sniper_Deka: FST_Deka_Static_Sniper_Base
	{
		displayname="[41st] Droideka Sniper";
		_generalMacro="B_HMG_01_F";
		TAS_DekaShieldRegen=0.02;
		scope=2;
		scopearsenal=2;
		scopecurator=2;
		side=0;
		Author = "Viz";
		crew="O_UAV_AI";
	};
};
class Extended_PreInit_EventHandlers
{
	class FST_DroidekaShield_pre_init_event
	{
		init="call compile preprocessFileLineNumbers '3AS\3AS_deka\XEH_preInit.sqf'";
	};
};
class Extended_Init_EventHandlers
{
	class FST_Droideka
	{
		class FST_Deka_Init_Eh
		{
			init="_this execVM '3AS\3AS_deka\DroidekaShieldRegen.sqf'";
		};
	};
	class FST_Sniper_Deka
	{
		class FST_DekaSniper_Init_Eh
		{
			init="_this execVM '3AS\3AS_deka\DroidekaShieldRegen.sqf'";
		};
	};
};
class Extended_HitPart_EventHandlers
{
	class FST_Droideka
	{
		class FST_Deka_HitPart_Eh
		{
			hitpart="_this select 0 execVM '3AS\3AS_deka\DroidekaShieldHit.sqf'";
		};
	};
	class FST_Sniper_Deka
	{
		class FST_Deka_HitPart_Eh
		{
			hitpart="_this select 0 execVM '3AS\3AS_deka\DroidekaShieldHit.sqf'";
		};
	};
};
class Extended_Killed_EventHandlers
{
	class FST_Droideka
	{
		class TAS_Deka_deleteShield
		{
			killed="_this select 0 execVM '3AS\3AS_deka\fnc_deleteDekaShield.sqf'";
		};
	};
	class FST_Sniper_Deka
	{
		class TAS_Deka_deleteShield
		{
			killed="_this select 0 execVM '3AS\3AS_deka\fnc_deleteDekaShield.sqf'";
		};
	};
};
