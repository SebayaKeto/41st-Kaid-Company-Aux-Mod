class CfgPatches
{
	class FST_Droideka
	{
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Static_F_Jets"
		};
		units[]=
		{
			"FST_Droideka",
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
        hit=32;
        indirectHit=15;
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
                begin1[]=
                {
					"kobra\442_a_vehicle\laat\sounds\dc-15r.wss",
					1,
					1,
					500
				};
				soundBegin[]=
				{
					"begin1",
					1
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
class CfgVehicles
{
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
		class HitPoints;
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
	class HitPoints;
	class DBA_Droideka_Base: StaticMGWeapon {};
	class FST_Droideka_Base: DBA_Droideka_Base
	{
		author="Viz";
		scope=0;
		scopeCurator=0;
		faction="FST_BattleDroids_Faction";
		model="DBA_CIS\Addons\DBA_Vehicles\DBA_GroundVehicles\DBA_Droideka\DBA_Droideka.p3d";
		armor=30;
		accuracy=1;
		class animationsources
		{
			class DroidekaShieldHide
			{
				animPeriod=0.001;
				initPhase=0;
				source="user";
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				memoryPointsGetInGunner="GunnerIn";
				memoryPointsGetInGunnerDir="GunnerIn_dir";
				turretinfotype="RscOptics_APC_Tracked_01_gunner";
				animationSourceBody="MainTurret";
				Body="MainTurret";
				animationSourceGun="MainGun";
				Gun="MainGun";
				optics=1;
				minElev=-15;
				maxElev=55;
				minTurn=-360;
				maxTurn=360;
				hasgunner=1;
				gunnerName="Droideka AI";
				primary=1;
				primaryGunner=1;
				startEngine=0;
				enableManualFire=1;
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
				gunnerForceOptics=1;
				memoryPointGun[]=
				{
					"gun_left_Low_Pos",
					"gun_left_Up_Pos",
					"gun_Right_Low_Pos",
					"Gun_left_Up_Pos"
				};
				uavCameraGunnerPos="camera_pos";
				uavCameraGunnerDir="camera_dir";
				memoryPointGunnerOptics="camera_pos";
				forceHideGunner=1;
				gunnerOutForceOptics=1;
				viewgunnerinExternal=0;
				outGunnerMayFire=1;
				inGunnerMayFire=1;
				castGunnerShadow=0;
				showAllTargets=2;
				class OpticsIn
				{
					class Wide
					{
						opticsDisplayName="W";
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						initFov=0.46599999;
						minFov=0.46599999;
						maxFov=0.46599999;
						visionMode[]=
						{
							"Normal",
							"NVG",
							"Ti"
						};
						thermalMode[]={0,1};
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
					};
					class Medium: Wide
					{
						opticsDisplayName="M";
						initFov=0.093000002;
						minFov=0.093000002;
						maxFov=0.093000002;
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_m_F";
					};
					class Narrow: Wide
					{
						opticsDisplayName="N";
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_n_F";
						initFov=0.028999999;
						minFov=0.028999999;
						maxFov=0.028999999;
					};
				};
				weapons[]=
				{
					"FST_Droideka_Cannon"
				};
				magazines[]=
				{
					"FST_blaster_battery_Droideka",
					"FST_blaster_battery_Droideka",
					"DBA_30mm_HVN_x2400_mag"
				};
			};
		};
		class AttributeValues
		{
			RadarUsageAI=1;
		};
	};
	class FST_Droideka: FST_Droideka_Base
	{
		class SimpleObject
		{
			eden=1;
			verticalOffset=2.467;
			verticalOffsetWorld=-0.039000001;
			init="''";
		};
		author="Viz";
		displayName="[41st] Droideka";
		scope=2;
		scopeCurator=2;
		side=0;
		crew="B_UAV_AI";
		typicalCargo[]=
		{
			"B_UAV_AI"
		};
	};
	class FST_Droideka_Christmas: FST_Droideka
	{
		author="Viz";
		displayName="[41st] Jack Frostdeka";
		model="\Christmas_Snowmans\objects\ClothesSnowman.p3d";
	};
	class DBA_Sniper_Deka;
	class FST_Sniper_Deka: DBA_Sniper_Deka
	{
		Author = "Viz";
		faction="FST_BattleDroids_Faction";
		displayName="Sniper Droideka (Still in progress)";
		class Armory
		{
			description="";
		};
		
	};
};
class Extended_Init_EventHandlers
{
	class FST_Droideka
	{
		class FST_Droideka_Init_Eh
		{
			init="_this execVM 'DBA_CIS\Addons\DBA_Vehicles\DBA_GroundVehicles\DBA_Droideka\DroidekaShieldRegen.sqf'";
		};
	};
};
class Extended_HitPart_EventHandlers
{
	class FST_Droideka
	{
		class FST_Droideka_HitPart_Eh
		{
			hitpart="_this select 0 execVM 'DBA_CIS\Addons\DBA_Vehicles\DBA_GroundVehicles\DBA_Droideka\DroidekaShieldHit.sqf'";
		};
	};
};