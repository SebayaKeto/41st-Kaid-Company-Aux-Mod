class CfgPatches
{
	class 41st_Weapons_Vehicle
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Weapons_F",
			"41st_Addon",
		};
		author="Daara";
	};
};
class Mode_SemiAuto;
class Mode_FullAuto;

class CfgAmmo
{
	class Cannon_30mm_HE_Plane_CAS_02_F;
	class BulletBase;
	class FST_127x99_red: BulletBase
	{
		hit=30;
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
		caliber=2.5999999;
		typicalSpeed=880;
		timeToLive=10;
		model="3as\3as_weapons\data\tracer_red.p3d";
		effectfly="IDA_BlasterBoltGlow_Medium_Red_Fly";
		tracerScale=1.2;
		tracerStartTime=9.9999997e-006;
		tracerEndTime=10;
		airFriction=-0.00085999997;
		JLTS_isStunAmmo=0;
		JLTS_isEMPAmmo=0;
		ACE_damageType="plasma";
		coefGravity=1;
		ACE_caliber=12.954;
        ACE_bulletLength=58.674;
        ACE_bulletMass=41.9256;
        ACE_muzzleVelocityVariationSD=0.35;
        ACE_ammoTempMuzzleVelocityShifts[]={-26.55, -25.47, -22.85, -20.12, -16.98, -12.80, -7.64, -1.53, 5.96, 15.17, 26.19};
        ACE_ballisticCoefficients[]={0.670};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ASM";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={900};
        ACE_barrelLengths[]={736.6};
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
	class IDA_Blasterbolt_Power6_VEHICLE;
	class IDA_blasterbolt;
	class FST_thermal_shell: IDA_blasterbolt
	{
		model="3as\3as_weapons\data\tracer_green.p3d";
		effectFly="3AS_PlasmaBolt_Medium_Green_Fly";
		ACE_damageType="plasmashell";
		hit=40;
		indirectHit=40;
		explosive=1;
		indirectHitRange=4;
		caliber=2;
		explosionEffects="ExploAmmoExplosion";
		craterEffects="ExploAmmoCrater";
		soundHit1[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_1",
			3.1622777,
			1,
			1400
		};
		soundHit2[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_2",
			3.1622777,
			1,
			1400
		};
		soundHit3[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_3",
			3.1622777,
			1,
			1400
		};
		soundHit4[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_4",
			3.1622777,
			1,
			1400
		};
		soundHit5[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_5",
			3.1622777,
			1,
			1400
		};
		soundHit6[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_6",
			3.1622777,
			1,
			1400
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.2,
			"soundHit2",
			0.2,
			"soundHit3",
			0.2,
			"soundHit4",
			0.1,
			"soundHit5",
			0.15000001,
			"soundHit6",
			0.15000001
		};
	};
	class FST_thermal_laser_YWing: IDA_blasterbolt
	{
		model="3as\3as_weapons\data\tracer_green.p3d";
		effectFly="3AS_PlasmaBolt_Medium_Green_Fly";
		ACE_damageType="plasmashell";
		hit=100;
		indirectHit=75;
		explosive=1;
		indirectHitRange=4;
		caliber=2;
		explosionEffects="ExploAmmoExplosion";
		craterEffects="ExploAmmoCrater";
		soundHit1[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_1",
			3.1622777,
			1,
			1400
		};
		soundHit2[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_2",
			3.1622777,
			1,
			1400
		};
		soundHit3[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_3",
			3.1622777,
			1,
			1400
		};
		soundHit4[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_4",
			3.1622777,
			1,
			1400
		};
		soundHit5[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_5",
			3.1622777,
			1,
			1400
		};
		soundHit6[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_6",
			3.1622777,
			1,
			1400
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.2,
			"soundHit2",
			0.2,
			"soundHit3",
			0.2,
			"soundHit4",
			0.1,
			"soundHit5",
			0.15000001,
			"soundHit6",
			0.15000001
		};
	};
	class FST_thermal_shell_blue: IDA_blasterbolt
	{
		model="3as\3as_weapons\data\tracer_blue.p3d";
		effectFly="3AS_PlasmaBolt_Medium_Blue_Fly";
		ACE_damageType="plasmashell";
		hit=75;
		indirectHit=50;
		explosive=1;
		indirectHitRange=4;
		caliber=2;
		explosionEffects="ExploAmmoExplosion";
		craterEffects="ExploAmmoCrater";
		soundHit1[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_1",
			3.1622777,
			1,
			1400
		};
		soundHit2[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_2",
			3.1622777,
			1,
			1400
		};
		soundHit3[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_3",
			3.1622777,
			1,
			1400
		};
		soundHit4[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_4",
			3.1622777,
			1,
			1400
		};
		soundHit5[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_5",
			3.1622777,
			1,
			1400
		};
		soundHit6[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_6",
			3.1622777,
			1,
			1400
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.2,
			"soundHit2",
			0.2,
			"soundHit3",
			0.2,
			"soundHit4",
			0.1,
			"soundHit5",
			0.15000001,
			"soundHit6",
			0.15000001
		};
	};
	class FST_thermal_shell_red: IDA_blasterbolt
	{
		model="3as\3as_weapons\data\tracer_red.p3d";
		effectFly="3AS_PlasmaBolt_Medium_Red_Fly";
		ACE_damageType="plasmashell";
		hit=75;
		indirectHit=50;
		explosive=1;
		indirectHitRange=4;
		caliber=2;
		explosionEffects="ExploAmmoExplosion";
		craterEffects="ExploAmmoCrater";
		soundHit1[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_1",
			3.1622777,
			1,
			1400
		};
		soundHit2[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_2",
			3.1622777,
			1,
			1400
		};
		soundHit3[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_3",
			3.1622777,
			1,
			1400
		};
		soundHit4[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_4",
			3.1622777,
			1,
			1400
		};
		soundHit5[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_5",
			3.1622777,
			1,
			1400
		};
		soundHit6[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_6",
			3.1622777,
			1,
			1400
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.2,
			"soundHit2",
			0.2,
			"soundHit3",
			0.2,
			"soundHit4",
			0.1,
			"soundHit5",
			0.15000001,
			"soundHit6",
			0.15000001
		};
	};
	class FST_thermal_shell_HP_Blue: IDA_Blasterbolt_Power6_VEHICLE
	{
		model="3as\3as_weapons\data\tracer_blue.p3d";
		effectFly="3AS_PlasmaBolt_Medium_Blue_Fly";
		hit=900;
		indirectHit=150;
		explosive=1;
		indirectHitRange=6;
		caliber=2;
		soundHit1[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_1",
			3.1622777,
			1,
			1400
		};
		soundHit2[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_2",
			3.1622777,
			1,
			1400
		};
		soundHit3[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_3",
			3.1622777,
			1,
			1400
		};
		soundHit4[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_4",
			3.1622777,
			1,
			1400
		};
		soundHit5[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_5",
			3.1622777,
			1,
			1400
		};
		soundHit6[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_6",
			3.1622777,
			1,
			1400
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.2,
			"soundHit2",
			0.2,
			"soundHit3",
			0.2,
			"soundHit4",
			0.1,
			"soundHit5",
			0.15000001,
			"soundHit6",
			0.15000001
		};
	};
	class FST_thermal_shell_HP: IDA_Blasterbolt_Power6_VEHICLE
	{
		model="3as\3as_weapons\data\tracer_red.p3d";
		effectFly="3AS_PlasmaBolt_Medium_Red_Fly";
		hit=900;
		indirectHit=150;
		explosive=1;
		indirectHitRange=4;
		caliber=2;
		soundHit1[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_1",
			3.1622777,
			1,
			1400
		};
		soundHit2[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_2",
			3.1622777,
			1,
			1400
		};
		soundHit3[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_3",
			3.1622777,
			1,
			1400
		};
		soundHit4[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_4",
			3.1622777,
			1,
			1400
		};
		soundHit5[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_5",
			3.1622777,
			1,
			1400
		};
		soundHit6[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_6",
			3.1622777,
			1,
			1400
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.2,
			"soundHit2",
			0.2,
			"soundHit3",
			0.2,
			"soundHit4",
			0.1,
			"soundHit5",
			0.15000001,
			"soundHit6",
			0.15000001
		};
	};
	class FST_thermal_shell_HP_Green: IDA_Blasterbolt_Power6_VEHICLE
	{
		model="3as\3as_weapons\data\tracer_green.p3d";
		effectFly="3AS_PlasmaBolt_Medium_Green_Fly";
		hit=900;
		indirectHit=150;
		explosive=1;
		indirectHitRange=6;
		caliber=2;
		soundHit1[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_1",
			3.1622777,
			1,
			1400
		};
		soundHit2[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_2",
			3.1622777,
			1,
			1400
		};
		soundHit3[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_3",
			3.1622777,
			1,
			1400
		};
		soundHit4[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_4",
			3.1622777,
			1,
			1400
		};
		soundHit5[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_5",
			3.1622777,
			1,
			1400
		};
		soundHit6[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_6",
			3.1622777,
			1,
			1400
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.2,
			"soundHit2",
			0.2,
			"soundHit3",
			0.2,
			"soundHit4",
			0.1,
			"soundHit5",
			0.15000001,
			"soundHit6",
			0.15000001
		};
	};
	class FST_thermal_shell_LP_Red: IDA_Blasterbolt_Power6_VEHICLE
	{
		model="3as\3as_weapons\data\tracer_red.p3d";
		effectFly="3AS_PlasmaBolt_Medium_red_Fly";
		hit=400;
		indirectHit=75;
		explosive=1;
		indirectHitRange=4;
		caliber=2;
		soundHit1[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_1",
			3.1622777,
			1,
			1400
		};
		soundHit2[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_2",
			3.1622777,
			1,
			1400
		};
		soundHit3[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_3",
			3.1622777,
			1,
			1400
		};
		soundHit4[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_4",
			3.1622777,
			1,
			1400
		};
		soundHit5[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_5",
			3.1622777,
			1,
			1400
		};
		soundHit6[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_6",
			3.1622777,
			1,
			1400
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.2,
			"soundHit2",
			0.2,
			"soundHit3",
			0.2,
			"soundHit4",
			0.1,
			"soundHit5",
			0.15000001,
			"soundHit6",
			0.15000001
		};
	};
	class FST_thermal_shell_OP_Red: IDA_Blasterbolt_Power6_VEHICLE
	{
		model="3as\3as_weapons\data\tracer_red";
		effectFly="3AS_PlasmaBolt_Medium_Red_Fly";
		hit=1200;
		indirectHit=300;
		explosive=1;
		indirectHitRange=8;
		caliber=2;
		soundHit1[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_1",
			3.1622777,
			1,
			1400
		};
		soundHit2[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_2",
			3.1622777,
			1,
			1400
		};
		soundHit3[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_3",
			3.1622777,
			1,
			1400
		};
		soundHit4[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_4",
			3.1622777,
			1,
			1400
		};
		soundHit5[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_5",
			3.1622777,
			1,
			1400
		};
		soundHit6[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_6",
			3.1622777,
			1,
			1400
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.2,
			"soundHit2",
			0.2,
			"soundHit3",
			0.2,
			"soundHit4",
			0.1,
			"soundHit5",
			0.15000001,
			"soundHit6",
			0.15000001
		};
	};
	class FST_LAAT_Ball_Laser_Ammo: IDA_Blasterbolt_Power6_VEHICLE
	{
		author="Ruby, Code Inherted From Viz.";
		displayname="LAAT Ball Turret";
		warheadName="LAAT Ball Turret";
		hit=75;
		indirectHit=30;
		deflecting=0;
		indirectHitRange=6;
		caliber=20;
		explosive=1;
		allowAgainstInfantry=1;
		airlock=1;
		model="3as\3as_weapons\data\tracer_green.p3d";
		effectFly="3AS_PlasmaBolt_Medium_Green_Fly";
		aiAmmoUsageFlags="128 + 512";
		soundHit1[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_1",
			3.1622777,
			1,
			1400
		};
		soundHit2[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_2",
			3.1622777,
			1,
			1400
		};
		soundHit3[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_3",
			3.1622777,
			1,
			1400
		};
		soundHit4[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_4",
			3.1622777,
			1,
			1400
		};
		soundHit5[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_5",
			3.1622777,
			1,
			1400
		};
		soundHit6[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_6",
			3.1622777,
			1,
			1400
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.2,
			"soundHit2",
			0.2,
			"soundHit3",
			0.2,
			"soundHit4",
			0.1,
			"soundHit5",
			0.15000001,
			"soundHit6",
			0.15000001
		};
	};
	class B_40mm_GPR;
	class FST_40mm_UB9HV_HEI: B_40mm_GPR
	{
		ace_frag_enabled=0;
		ace_frag_metal=20;
		ace_frag_charge=30;
		ace_frag_gurney_c=2440;
		ace_frag_gurney_k="1/2";
		ace_frag_classes[]=
		{
			"ACE_frag_large"
		};
		ace_frag_skip=1;
		ace_frag_force=0;
		hit=80;
		indirectHit=50;
		indirectHitRange=4;
		explosive=0.80000001;
		airLock=1;
		warheadName="HE";
		caliber=0.28530669;
		deflecting=3;
		cost=10;
		airFriction=-0.00036000001;
		timeToLive=10;
		initSpeed=1440;
		fuseDistance=10;
		aiAmmoUsageFlags="64 + 256";
		model="3as\3AS_Weapons\Data\tracer_shell_red.p3d";
		effectFly="3AS_PlasmaBolt_Medium_Red_Fly";
		tracerScale=1.25;
		tracerStartTime=0.1;
		tracerEndTime=20;
		brightness=100000;
		muzzleEffect="";
		typicalSpeed=50;
		allowAgainstInfantry=1;
		coefGravity=0;
		waterFriction=0;
		SoundSetExplosion[]={};
		class CamShakeExplode
		{
			power=50;
			duration=2.5;
			frequency=20;
			distance=10;
		};
		class CamShakeHit
		{
			power=200;
			duration=1.5;
			frequency=20;
			distance=5;
		};
		class CamShakeFire
		{
			power=1;
			duration=0.2;
			frequency=20;
			distance=1;
		};
		class CamShakePlayerFire
		{
			power=0.0099999998;
			duration=0.1;
			frequency=20;
			distance=0.25;
		};
		soundHit1[]=
		{
			"A3\Sounds_F\arsenal\explosives\Grenades\Explosion_gng_grenades_01",
			5.1622777,
			0.85000002,
			2000
		};
		soundHit2[]=
		{
			"A3\Sounds_F\arsenal\explosives\Grenades\Explosion_gng_grenades_02",
			5.1622777,
			0.85000002,
			2000
		};
		soundHit3[]=
		{
			"A3\Sounds_F\arsenal\explosives\Grenades\Explosion_gng_grenades_03",
			5.1622777,
			0.85000002,
			2000
		};
		soundHit4[]=
		{
			"A3\Sounds_F\arsenal\explosives\Grenades\Explosion_gng_grenades_04",
			5.1622777,
			0.85000002,
			2000
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.25,
			"soundHit2",
			0.25,
			"soundHit3",
			0.25,
			"soundHit4",
			0.25
		};
	};
	class F_40mm_White; //Laat Parachute Flares
	class FST_AWS_SUU25_type1 : F_40mm_White  //Laat Parachute Flares
	{
		model = "\A3\Weapons_F\Ammo\UGL_Flare";
		lightColor[] = {
			1.000000, 1.000000, 1.000000, 0.800000
		};
		intensity = 10000000;
		useFlare = 1;
		deflecting = 30;
		smokeColor[] = {
			1, 1, 1, 0.500000
		};
		effectFlare = "CounterMeasureFlare";
		brightness = 100000;
		size = 3;
		triggerTime = 0;
		triggerSpeedCoef = 1;
		timeToLive = 120;
		airFriction = 1;
	};
	class MissileCore;
	class MissileBase : MissileCore
	{
		class Components;
	};
	class FST_SUU25_Rocket : MissileBase  //Laat Parachute Flares
	{
		model = "\FIR_AirWeaponSystem_US\Data\Rocket\suu25_rocket.p3d";
		proxyShape = "\FIR_AirWeaponSystem_US\Data\Rocket\suu25_rocket.p3d";
		maverickWeaponIndexOffset = 12;
		maverickweapon = 1;
		cost = 500;
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		manualControl = 0;
		maxControlRange = 0;
		airLock = 0;
		irLock = 0;
		laserLock = 0;
		nvLock = 0;
		weaponLockSystem = 0;
		cmimmunity = 1;
		aiAmmoUsageFlags = "64 + 128";
		initTime = 0.002;
		thrustTime = 1.1;
		thrust = 10;
		airFriction = 0.09;
		sideAirFriction = 0.005;
		maxSpeed = 1;
		maneuvrability = 0;
		fuseDistance = 40;
		timeToLive = 20;
		effectsMissileInit = "MissileDAR1";
		whistleDist = 30;
		submunitionAmmo = "FST_AWS_SUU25_type1";
		submunitionConeAngle = 5;
		submunitionConeType[] = {"randomcenter",1};
 		triggerTime = 0.05;
		triggerSpeedCoef[] = {0.0,0.1};

		// FIR_AWS_FLARE = 1;		
		class CamShakeExplode
		{
			power = 16;
			duration = 1.8;
			frequency = 20;
			distance = 191.554;
		};
		class CamShakeHit
		{
			power = 80;
			duration = 0.6;
			frequency = 20;
			distance = 1;
		};
		class CamShakeFire
		{
			power = 2.9907;
			duration = 1.8;
			frequency = 20;
			distance = 71.5542;
		};
		class CamShakePlayerFire
		{
			power = 2;
			duration = 0.1;
			frequency = 20;
			distance = 1;
		};
	};
	class ShotDeployBase; //LaaT Smoke Rocket
	class FST_Hydra_Rocket_Smoke_Deploy : ShotDeployBase //LaaT Smoke Rocket
	{
		author = "Adapted from FIR Team by Viz"
		model = "\FIR_AirWeaponSystem_US\Data\Rocket\hydra_rocket_fly.p3d";
		proxyShape = "\FIR_AirWeaponSystem_US\Data\Rocket\hydra_rocket.p3d";
		hit = 1;
		indirectHit = 1;
		indirectHitRange = 0.1;
		initTime = 0;
		cost = 400;
		//effectFly = "clustereffectfly";
		CraterEffects = "GrenadeCrater";
		explosionEffects = "GrenadeExplosion";
		submunitionAmmo = "SmokeShellArty";
		submunitionConeAngle = 10;
		submunitionConeType[] = {"randomcenter", 3};
	};
	class FST_Hydra_Rocket_Smoke : MissileBase //LaaT Smoke Rocket
	{
		author = "Adapted from FIR Team by Viz"
		model = "\FIR_AirWeaponSystem_US\Data\Rocket\hydra_rocket_fly.p3d";
		proxyShape = "\FIR_AirWeaponSystem_US\Data\Rocket\hydra_rocket.p3d";
		maverickWeaponIndexOffset = 12;
		maverickweapon = 1;
		cost = 500;
		hit = 1;
		indirectHit = 1;
		indirectHitRange = 1;
		manualControl = 0;
		maxControlRange = 0;
		airLock = 0;
		irLock = 0;
		laserLock = 0;
		nvLock = 0;
		weaponLockSystem = 0;
		cmimmunity = 1;
		aiAmmoUsageFlags = "64 + 128";
		initTime = 0.002;
		thrust = 1060;
		thrustTime = 0.69;
		airFriction = 0.09;
		sideAirFriction = 0.005;
		maxSpeed = 590;
		maneuvrability = 0;
		fuseDistance = 50;
		timeToLive = 60;
		effectsMissileInit = "MissileDAR1";
		whistleDist = 30;

		submunitionAmmo = "FST_Hydra_Rocket_Smoke_Deploy";
		submunitionConeAngle = 5;
		submunitionConeType[] = {"randomcenter",3};
		triggerDistance = 5;
		triggerSpeedCoef[] = {0.8,1};

		class CamShakeExplode
		{
			power = 16;
			duration = 1.8;
			frequency = 20;
			distance = 191.554;
		};
		class CamShakeHit
		{
			power = 80;
			duration = 0.6;
			frequency = 20;
			distance = 1;
		};
		class CamShakeFire
		{
			power = 2.9907;
			duration = 1.8;
			frequency = 20;
			distance = 71.5542;
		};
		class CamShakePlayerFire
		{
			power = 2;
			duration = 0.1;
			frequency = 20;
			distance = 1;
		};
	};
};

class CfgMagazines
{
	class VehicleMagazine;
	class 1Rnd_HE_Grenade_shell;
	class FST_500Rnd_127x99_mag_red: VehicleMagazine
	{
		displayname="12.7x99mm 500Rnd plasma cell (Red)";
		displaynameshort="12.7x99mm";
		scope=2;
		count=500;
		ammo="FST_127x99_red";
		initSpeed=910;
		maxLeadSpeed=36.111099;
		tracersEvery=1;
		nameSound="mgun";
		muzzleImpulseFactor[]={0.050000001,0.050000001};
	};
	class FST_thermal_coil: 1Rnd_HE_Grenade_shell
	{
		author="Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		count=150;
		displayName="[41st] 150 Rnd Thermal Coil (Green)";
		displayNameShort="Thermal Coil";
		descriptionShort="Fires Thermal Shells.";
		ammo="FST_thermal_shell";
		tracersEvery=1;
		initSpeed=800;
		mass=20;
	};
	class FST_thermal_coil_Ball: 1Rnd_HE_Grenade_shell
	{
		author="Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		count=350;
		displayName="[41st] LAAT Ball Cannon";
		displayNameShort="LAAT BRR Mode";
		descriptionShort="Fires Thermal Shells.";
		ammo="FST_LAAT_Ball_Laser_Ammo";
		tracersEvery=1;
		initSpeed=800;
		mass=20;
	};
	class FST_thermal_Y_Wing: 1Rnd_HE_Grenade_shell
	{
		author="Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		count=150;
		displayName="[41st] 150 Rnd Y Wing Laser ";
		displayNameShort="Y Wing Laser Rounds";
		descriptionShort="Fires Laser Rounds for the Y Wing.";
		ammo="FST_thermal_laser_YWing";
		tracersEvery=1;
		initSpeed=800;
		mass=20;
	};
	class FST_thermal_coil_blue: 1Rnd_HE_Grenade_shell
	{
		author="Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		count=150;
		displayName="[41st] 150 Rnd Thermal Coil (Blue)";
		displayNameShort="Thermal Coil";
		descriptionShort="Fires Thermal Shells.";
		ammo="FST_thermal_shell_blue";
		tracersEvery=1;
		initSpeed=800;
		mass=20;
	};
	class FST_thermal_coil_red: 1Rnd_HE_Grenade_shell
	{
		author="Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		count=150;
		displayName="[41st] 150 Rnd Thermal Coil (Red)";
		displayNameShort="Thermal Coil";
		descriptionShort="Fires Thermal Shells.";
		ammo="FST_thermal_shell_red";
		tracersEvery=1;
		initSpeed=800;
		mass=20;
	};
	class FST_thermal_coil_HP_Blue: 1Rnd_HE_Grenade_shell
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		count=1;
		displayName="[41st] High-Power Thermal coil (Blue)";
		displayNameShort="HP Thermal Coil";
		descriptionShort="Fires High-Power Thermal Shells.";
		ammo="FST_thermal_shell_HP_Blue";
		tracersEvery=1;
		initSpeed=800;
		mass=20;
	};
	class FST_thermal_coil_LP_Red: 1Rnd_HE_Grenade_shell
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		count=1;
		displayName="[41st] Low-Power Thermal coil (Red)";
		displayNameShort="HP Thermal Coil";
		descriptionShort="Fires Low-Power Thermal Shells.";
		ammo="FST_thermal_shell_LP_Red";
		tracersEvery=1;
		initSpeed=800;
		mass=20;
	};
	class FST_thermal_coil_OP_Red: 1Rnd_HE_Grenade_shell
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		count=1;
		displayName="[41st] Overpowered Thermal coil (Red)";
		displayNameShort="HP Thermal Coil";
		descriptionShort="Fires OP Thermal Shells.";
		ammo="FST_thermal_shell_OP_Red";
		tracersEvery=1;
		initSpeed=800;
		mass=20;
	};
	class FST_thermal_coil_HP: 1Rnd_HE_Grenade_shell
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		count=1;
		displayName="[41st] High-Power Thermal coil";
		displayNameShort="HP Thermal Coil";
		descriptionShort="Fires High-Power Thermal Shells.";
		ammo="FST_thermal_shell_HP";
		tracersEvery=1;
		initSpeed=800;
		mass=20;
	};
	class FST_LAAT_P_12rnd_M : VehicleMagazine  //Laat Parachute Flares
	{
		author = "Adapted from FIR Team by Viz"
		scope = 2;
		displayName = "LAAT FLARE x 1";
		displayNameShort = "LAAT FLARE";
		ammo = "FST_SUU25_Rocket";
		descriptionShort = "Parachute Flare";
		initSpeed = 0;
		count = 12;
		maxLeadSpeed = 0;
		model = "\FIR_AirWeaponSystem_US\data\proxies\pod_8x_SUU25.p3d";
		mass = 125;
	};
	class FST_LAAT_Smoke_P_16rnd_M : VehicleMagazine //Laat Smoke Rockets
	{
		author = "Adapted from FIR Team by Viz"
		scope = 2;
		displayName = "LAAT RP Smoke x 1";
		displayNameShort = "LAAT RP Smoke";
		ammo = "FST_Hydra_Rocket_Smoke";
		descriptionShort = "unguided rocket, 2.75-inch, RP Smoke";				
		initSpeed = 0;
		count = 16;
		maxLeadSpeed = 300;
		model = "\FIR_AirWeaponSystem_US\data\proxies\pod_7x_Hydra.p3d";
		mass = 125;
	};
	class FST_40mm_UB9HV_HEI_x140_mag: VehicleMagazine
	{
		displayname="40mw UB-9HV High-Explosive Incendiary";
		ammo="FST_40mm_UB9HV_HEI";
		displaynamemagazine="UB-9HV HEI";
		shortnamemagazine="UB-9HV HEI";
		displayNameMFDFormat="UB-9HV HEI";
		displayNameShort="UB-9HV HEI";
		count=500;
		initSpeed=1440;
		maxLeadSpeed=2000;
		tracersevery=1;
	};
};
class CfgWeapons
{
	class MGun;
	class LMG_coax;
	class autocannon_Base_F;
	class player;
	class OPTRE_M247T_Coax;
	class CannonCore;
	class Cannon_30mm_Plane_CAS_02_F: CannonCore
	{
		class LowROF;
	};
	class ls_laat_gun;
	
	//AAT------------------------------------------------
	
	class FST_AAT_Cannon: autocannon_Base_F
	{
		displayName="Main Cannon";
		author="Daara";
		cursor="EmptyCursor";
		reloadTime=2;
		fireLightDiffuse[]={1,0,0};
		class GunParticles
		{
			class Effect
			{
				effectName="";
				positionName="";
				directionName="";
			};
			class Shell
			{
				positionName="";
				directionName="";
				effectName="";
			};
		};
		muzzles[]=
		{
			"HP",
		};
		class HP: autocannon_Base_F
		{
			displayName="Main Blaster cannon";
			cursor="EmptyCursor";
			magazines[]=
			{
				"IDA_thermal_coil_HP",
				"FST_thermal_coil_LP_Red",
				"FST_thermal_coil_OP_Red",
				"FST_thermal_coil_HP",
				"FST_thermal_coil_LP_Blue"
			};
			magazineReloadTime=2.5;
			modes[]=
			{
				"Fire",
			};
			class Fire: Mode_SemiAuto
			{
				sounds[]=
				{
					"StandardSound"
				};
				class BaseSoundModeType
				{
					weaponSoundEffect="DefaultRifle";
					closure1[]={};
					closure2[]={};
					soundClosure[]=
					{
						"closure1",
						0.5,
						"closure2",
						0.5
					};
				};
				class StandardSound
				{
					begin1[]=
					{
						"\41st_Weapons\Vehicle\Sounds\FST_AAT_Cannon.ogg",
						2.5118864,
						1,
						1500
					};
					begin2[]=
					{
						"\41st_Weapons\Vehicle\Sounds\FST_AAT_Cannon.ogg",
						2.5118864,
						1.015,
						1500
					};
					begin3[]=
					{
						"\41st_Weapons\Vehicle\Sounds\FST_AAT_Cannon.ogg",
						2.5118864,
						0.985,
						1500
					};
					begin4[]=
					{
						"\41st_Weapons\Vehicle\Sounds\FST_AAT_Cannon.ogg",
						2.5118864,
						1.01,
						1500
					};
					begin5[]=
					{
						"\41st_Weapons\Vehicle\Sounds\FST_AAT_Cannon.ogg",
						2.5118864,
						0.995,
						1500
					};
					soundBegin[]=
					{
						"begin1",
						1
					};
					dispersion=0.0018;
					reloadTime=6;
				};
			};
		};
	};
	class LMG_RCWS;
	class FST_40mw_HH9P_AC: LMG_RCWS
	{
		// Credit to the DBA Team
		displayName="[41st] HH-9P 40mw Anti-Aircraft Gun";
		ballisticsComputer="2 + 4";
		FCSMaxLeadSpeed=2000;
		FCSZeroingDelay=0.1;
		canLock=1;
		airlock=1;
		scope=2;
		aiDispersionCoefX=0.1;
		aiDispersionCoefY=0.1;
		class GunParticles
		{
			class effect1
			{
				positionName="z_gunl_chamber";
				directionName="z_gunl_muzzle";
				effectName="MachineGunCloud";
			};
			class effect2
			{
				positionName="z_gunr_chamber";
				directionName="z_gunr_muzzle";
				effectName="MachineGunCloud";
			};
		};
		magazines[]=
		{
			"FST_40mm_UB9HV_HEI_x140_mag"
		};
		modes[]=
		{
			"manual",
			"close",
			"short",
			"medium",
			"far"
		};
		magazineReloadTime=2;
		class manual: Mode_SemiAuto
		{
			displayName="[41st] HH-9P 40mw Anti-Aircraft Gun";
			textureType="fullAuto";
			sounds[]=
			{
				"StandardSound"
			};
			reloadTime=0.10714286;
			class StandardSound
			{
				begin1[]=
				{
					"ls\core\addons\sounds\vehicles\saber\weapon\saber_heavy_shot.wss",
					2.8499999,
					0.75,
					2500
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			autoFire=1;
			soundContinuous=0;
			burst=1;
			soundBurst=0;
			multiplier=1;
			dispersion=0.0029088799;
			aiRateOfFire=1;
			showToPlayer=1;
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
			soundBurst=0;
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=10;
			burstRangeMax=20;
			aiRateOfFire=1;
			aiRateOfFireDispersion=1;
			aiRateOfFireDistance=50;
			minRange=0;
			minRangeProbab=0.69999999;
			midRange=100;
			midRangeProbab=0.94999999;
			maxRange=300;
			maxRangeProbab=0.89999998;
		};
		class short: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=10;
			burstRangeMax=30;
			aiRateOfFire=1;
			aiRateOfFireDispersion=1;
			aiRateOfFireDistance=150;
			minRange=100;
			minRangeProbab=0.94999999;
			midRange=300;
			midRangeProbab=0.94999999;
			maxRange=600;
			maxRangeProbab=0.89999998;
		};
		class medium: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=10;
			burstRangeMax=30;
			aiRateOfFire=1;
			aiRateOfFireDispersion=1;
			aiRateOfFireDistance=350;
			minRange=300;
			minRangeProbab=0.97500002;
			midRange=600;
			midRangeProbab=0.94999999;
			maxRange=800;
			maxRangeProbab=0.89999998;
		};
		class far: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=10;
			burstRangeMax=40;
			aiRateOfFire=1;
			aiRateOfFireDispersion=1;
			aiRateOfFireDistance=850;
			minRange=800;
			minRangeProbab=0.94999999;
			midRange=1000;
			midRangeProbab=0.90000004;
			maxRange=2500;
			maxRangeProbab=0.90000004;
		};
	};
	class FST_AAT_Side_base: LMG_RCWS
	{
		class GunParticles;
		class manual;
	};
	class FST_AAT_Side: FST_AAT_Side_base
	{
		displayName="12.7mm AAT Side-mounted Guns";
		scope=1;
		magazines[]=
		{
			"FST_500Rnd_127x99_mag_red"
		};
		maxZeroing=2000;
		class GunParticles
		{
			class effect1
			{
				positionName="usti_hlavne_1";
				directionName="konec_hlavne_1";
				effectName="MachineGunCloud";
			};
			class effect2: effect1
			{
				positionName="usti_hlavne_2";
				directionName="konec_hlavne_2";
			};
		};
		showAimCursorInternal=0;
		class manual: mgun
		{
			TextureType="";
			displayName="12.7mm AAT Side Gun";
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				begin1[]=
				{
					"ls\core\addons\sounds\vehicles\aat\weapon\main_shot.wss",
					1.5848932,
					1,
					2100
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			soundContinuous=0;
			soundBurst=0;
			reloadTime=0.1;
			dispersion=0.0012000001;
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
			aiRateOfFire=0.5;
			aiRateOfFireDispersion=1.5;
			aiRateOfFireDistance=50;
			minRange=0;
			minRangeProbab=0.69999999;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=200;
			maxRangeProbab=0.2;
		};
		class short: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=6;
			burstRangeMax=16;
			aiRateOfFire=1;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=150;
			minRange=100;
			minRangeProbab=0.69999999;
			midRange=400;
			midRangeProbab=0.75;
			maxRange=800;
			maxRangeProbab=0.2;
		};
		class medium: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=4;
			burstRangeMax=12;
			aiRateOfFire=2;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=400;
			minRange=400;
			minRangeProbab=0.75;
			midRange=800;
			midRangeProbab=0.69999999;
			maxRange=1500;
			maxRangeProbab=0.1;
		};
		class far: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=3;
			burstRangeMax=12;
			aiRateOfFire=4;
			aiRateOfFireDispersion=4;
			aiRateOfFireDistance=800;
			minRange=800;
			minRangeProbab=0.60000002;
			midRange=1500;
			midRangeProbab=0.25;
			maxRange=2000;
			maxRangeProbab=0.050000001;
		};
	};
	class FST_EWEB_RemoteTurret: OPTRE_M247T_Coax
	{
		displayName="E-Web Remote Turret";
		author="Daara";
		descriptionShort="E-Web";
		magazines[]=
		{
			"FST_EWEB_cell_Blue",
		};
		muzzleEnd="konec hlavne3";
		muzzlePos="usti hlavne3";
		selectionFireAnim="zasleh3";
		modes[]=
		{
			"FullAuto",
		};
		cursor="EmptyCursor";
		class FullAuto: Mode_FullAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="DefaultRifle";
				closure1[]={};
				closure2[]={};
				soundClosure[]=
				{
					"closure1",
					0.5,
					"closure2",
					0.5
				};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]=
				{
					"\41st_Weapons\EWEB\Sounds\EWEB.ogg",
					1,
					1,
					2000
				};
				begin2[]=
				{
					"\41st_Weapons\EWEB\Sounds\EWEB.ogg",
					1,
					1,
					2000
				};
				soundBegin[]=
				{
					"begin1",
					0.34,
					"begin2",
					0.33000001
				};
			};
			reloadTime=0.1;
			dispersion=0.001;
			recoil="recoil_auto_mk200";
			recoilProne="recoil_auto_prone_mk200";
			minRange=2;
			minRangeProbab=0.30000001;
			midRange=300;
			midRangeProbab=0.69999999;
			maxRange=600;
			maxRangeProbab=0.050000001;
			soundBurst=0;
			burst=1;
			displayName="$STR_DN_MODE_FULLAUTO";
			textureType="fullAuto";
		};
		class GunParticles
		{
			class effect1
			{
				positionName="konec hlavne3";
				directionName="Usti hlavne3";
				effectName="MachineGunCloud";
			};
		};
	};
	class FST_30mm_Autocannon: autocannon_Base_F
	{
		displayName="Medium Blaster Cannon";
		author="Daara";
		cursor="EmptyCursor";
		reloadTime=0.2;
		fireLightDiffuse[]={0,1,0};
		class GunParticles
		{
			class Effect
			{
				effectName="";
				positionName="";
				directionName="";
			};
			class Shell
			{
				positionName="";
				directionName="";
				effectName="";
			};
		};
		muzzles[]=
		{
			"HE",
		};
		class HE: autocannon_Base_F
		{
			displayName="30mm Blaster cannon";
			cursor="EmptyCursor";
			magazines[]=
			{
				"FST_thermal_coil"
			};
			magazineReloadTime=10;
			class player: player
			{
				class StandardSound
				{
					begin1[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						1,
						1500
					};
					begin2[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						1.015,
						1500
					};
					begin3[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						0.985,
						1500
					};
					begin4[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						1.01,
						1500
					};
					begin5[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						0.995,
						1500
					};
					soundBegin[]=
					{
						"begin1",
						1
					};
					dispersion=0.0018;
					reloadTime=0.4;
				};
			};
		};
	};
	class FST_Autocannon_40mm: CannonCore
	{
		scope=1;
		displayName="Medium Blaster Cannon";
		nameSound="cannon";
		cursor="EmptyCursor";
		cursorAim="mg";
		magazines[]=
		{
			"FST_thermal_coil"
		};
		magazineReloadTime=6;
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
		class GunParticles
		{
			class FirstEffect
			{
				effectName="";
				positionName="usti hlavne1";
				directionName="konec hlavne1";
			};
			class SecondEffect
			{
				effectName="";
				positionName="usti hlavne2";
				directionName="konec hlavne2";
			};
		};
		class manual: CannonCore
		{
			displayName="Autocannon Manual";
			textureType="fullAuto";
			autoFire=1;
			burst=1;
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				begin1[]=
				{
					"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
					2.5118864,
					1,
					1500
				};
				begin2[]=
				{
					"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
					2.5118864,
					1.015,
					1500
				};
				begin3[]=
				{
					"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
					2.5118864,
					0.985,
					1500
				};
				soundBegin[]=
				{
					"begin1",
					33,
					"begin2",
					33,
					"begin3",
					33
				};
			};
			soundContinuous=0;
			soundBurst=0;
			dispersion=0.0018;
			reloadTime=0.3;
			aiRateOfFire=0.40000001;
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
			aiRateOfFireDispersion=1;
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
			aiRateOfFireDispersion=2;
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
			aiRateOfFireDispersion=3;
			aiRateOfFireDistance=1200;
			minRange=1000;
			minRangeProbab=0.69999999;
			midRange=1250;
			midRangeProbab=0.60000002;
			maxRange=2500;
			maxRangeProbab=0.1;
		};
	};
	class FST_30mm_Autocannon_LAAT: Cannon_30mm_Plane_CAS_02_F
	{
		displayName="Medium LAAT Blaster Cannon";
		author="Daara";
		cursor="EmptyCursor";
		magazines[]=
		{
			"FST_thermal_coil",
		};
		reloadTime=0.175;
		magazineReloadTime=10;
		burst=1;
		fireLightDiffuse[]={1,0,0};
		class GunParticles
		{
			class Effect
			{
				effectName="";
				positionName="";
				directionName="";
			};
			class Shell
			{
				positionName="";
				directionName="";
				effectName="";
			};
		};
		class LowROF: LowROF
		{
			magazineReloadTime=10;
			reloadTime=0.175;
			burst=1;
			displayname="";
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				begin1[]=
				{
					"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
					2.5118864,
					1,
					1500
				};
				begin2[]=
				{
					"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
					2.5118864,
					1.015,
					1500
				};
				begin3[]=
				{
					"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
					2.5118864,
					0.985,
					1500
				};
				begin4[]=
				{
					"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
					2.5118864,
					1.01,
					1500
				};
				begin5[]=
				{
					"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
					2.5118864,
					0.995,
					1500
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
		};
	};
	class FST_LAAT_Ball_Turret: Cannon_30mm_Plane_CAS_02_F
	{
		displayName="[41st] Ball Turret Cannon";
		canLock=0;
		ballisticsComputer="4 + 2 + 8";
		magazines[]=
		{
			"FST_thermal_coil_Ball"
		};
		reloadTime=0.074999999;
		dispersion=0.0094999997;
		magazineReloadTime=10;
		burst=1;
		class LowROF: LowROF
		{
			reloadtime=0.074999998;
			magazineReloadTime=10;
			burst=1;
			displayname="";
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				begin1[]=
				{
					"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
					2.5118864,
					1,
					1500
				};
				begin2[]=
				{
					"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
					2.5118864,
					1.015,
					1500
				};
				begin3[]=
				{
					"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
					2.5118864,
					0.985,
					1500
				};
				begin4[]=
				{
					"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
					2.5118864,
					1.01,
					1500
				};
				begin5[]=
				{
					"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
					2.5118864,
					0.995,
					1500
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
		};
	};
	class FST_30mm_Autocannon_YWing: Cannon_30mm_Plane_CAS_02_F
	{
		displayName="Medium Y Wing Blaster Cannon";
		author="Daara";
		cursor="EmptyCursor";
		reloadTime=0.2;
		fireLightDiffuse[]={0,1,0};
		class GunParticles
		{
			class Effect
			{
				effectName="";
				positionName="";
				directionName="";
			};
			class Shell
			{
				positionName="";
				directionName="";
				effectName="";
			};
		};
		muzzles[]=
		{
			"HE",
		};
		class HE: autocannon_Base_F
		{
			displayName="30mm Y Wing Blaster Cannon";
			cursor="EmptyCursor";
			magazines[]=
			{
				"FST_thermal_Y_Wing"
			};
			magazineReloadTime=10;
			class player: player
			{
				class StandardSound
				{
					begin1[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						1,
						1500
					};
					begin2[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						1.015,
						1500
					};
					begin3[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						0.985,
						1500
					};
					begin4[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						1.01,
						1500
					};
					begin5[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						0.995,
						1500
					};
					soundBegin[]=
					{
						"begin1",
						1
					};
					dispersion=0.0018;
					reloadTime=0.04;
				};
			};
		};
	};
	class FST_Mass_Driver_Cannon: CannonCore
	{
		scope=1;
		displayName="[41st] Mass Driver Cannon";
		cursor="EmptyCursor";
		cursorAim="cannon";
		showAimCursorInternal=0;
		nameSound="cannon";
		reloadSound[]=
		{
			"A3\Sounds_F\arsenal\weapons_vehicles\cannon_120mm\Cannon_120mm_Reload_01",
			2.5118864,
			1,
			10
		};
		reloadMagazineSound[]=
		{
			"A3\Sounds_F\arsenal\weapons_vehicles\cannon_120mm\Cannon_120mm_Reload_01",
			2.5118864,
			1,
			10
		};
		magazines[]=
		{
			"FST_thermal_coil_HP_Blue"
		};
		reloadTime=6;
		magazineReloadTime=6;
		autoReload=1;
		canLock=0;
		ballisticsComputer="2 + 8 + 16";
		FCSMaxLeadSpeed=250;
		FCSZeroingDelay=1;
		aiDispersionCoefY=2;
		aiDispersionCoefX=2;
		autoFire=0;
		modes[]=
		{
			"player",
			"topDown",
			"close",
			"short",
			"medium",
			"far"
		};
		class GunParticles
		{
			class FirstEffect
			{
				effectName="CannonFired";
				positionName="Usti hlavne";
				directionName="Konec hlavne";
			};
		};
		class player: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_Maincanon_Shot_SoundSet"
				};
			};
			soundContinuous=0;
			reloadTime=6;
			magazineReloadTime=6;
			autoReload=1;
			autoFire=0;
			dispersion=0.00056999997;
			aiRateOfFire=1;
			aiRateOfFireDistance=10;
			minRange=0;
			minRangeProbab=0.0099999998;
			midRange=1;
			midRangeProbab=0.0099999998;
			maxRange=2;
			maxRangeProbab=0.0099999998;
		};
		class TopDown: player
		{
			textureType="topDown";
			displayName="$STR_A3_FireMode_TopDown0";
			minRange=150;
			minRangeProbab=0.40000001;
			midRange=400;
			midRangeProbab=0.94999999;
			maxRange=8000;
			maxRangeProbab=0.94999999;
		};
		class close: player
		{
			showToPlayer=0;
			burst=1;
			burstRangeMax=1;
			aiRateOfFire=6;
			aiRateOfFireDispersion=0.5;
			aiRateOfFireDistance=500;
			minRange=5;
			minRangeProbab=0.1;
			midRange=500;
			midRangeProbab=0.80000001;
			maxRange=1000;
			maxRangeProbab=0.85000002;
		};
		class short: close
		{
			showToPlayer=0;
			burst=1;
			burstRangeMax=1;
			aiRateOfFire=6;
			aiRateOfFireDispersion=1;
			aiRateOfFireDistance=1000;
			minRange=500;
			minRangeProbab=0.30000001;
			midRange=1000;
			midRangeProbab=0.85000002;
			maxRange=1500;
			maxRangeProbab=0.85000002;
		};
		class medium: close
		{
			dispersion=0.00071250001;
			showToPlayer=0;
			burst=1;
			burstRangeMax=1;
			aiRateOfFire=8;
			aiRateOfFireDispersion=4;
			aiRateOfFireDistance=1250;
			minRange=1000;
			minRangeProbab=0.60000002;
			midRange=1500;
			midRangeProbab=0.85000002;
			maxRange=2000;
			maxRangeProbab=0.80000001;
		};
		class far: close
		{
			dispersion=0.00071250001;
			showToPlayer=0;
			burst=1;
			burstRangeMax=1;
			aiRateOfFire=10;
			aiRateOfFireDispersion=8;
			aiRateOfFireDistance=1500;
			minRange=1500;
			minRangeProbab=0.75;
			midRange=2000;
			midRangeProbab=0.80000001;
			maxRange=3500;
			maxRangeProbab=0.050000001;
		};
	};
	class FST_ATTE_Turret: MGun
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
		displayName="[41st] Rapid Fire Turret";
		magazines[]=
		{
			"FST_thermal_coil_Blue",
			"FST_thermal_coil_Red",		
			"FST_thermal_coil"
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
		ballisticsComputer="2 + 16";
		FCSMaxLeadSpeed=30;
		FCSZeroingDelay=1;
		maxZeroing=1500;
		aiDispersionCoefY=3;
		aiDispersionCoefX=3;
		class manual: MGun
		{
			displayName="[41st] ATTE PD Turret";
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_HeavyBlaster_SoundSet"
				};
			};
			soundContinuous=0;
			soundBurst=0;
			reloadTime=0.2;
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
			aiRateOfFire=0.5;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=50;
			minRange=0;
			minRangeProbab=0.80000001;
			midRange=20;
			midRangeProbab=0.69999999;
			maxRange=50;
			maxRangeProbab=0.2;
		};
		class short: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=6;
			burstRangeMax=12;
			aiRateOfFire=1;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=150;
			minRange=20;
			minRangeProbab=0.69999999;
			midRange=150;
			midRangeProbab=0.69999999;
			maxRange=300;
			maxRangeProbab=0.2;
		};
		class medium: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=3;
			burstRangeMax=12;
			aiRateOfFire=2;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=250;
			minRange=150;
			minRangeProbab=0.69999999;
			midRange=600;
			midRangeProbab=0.64999998;
			maxRange=800;
			maxRangeProbab=0.1;
		};
		class far: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=3;
			burstRangeMax=8;
			aiRateOfFire=4;
			aiRateOfFireDispersion=4;
			aiRateOfFireDistance=600;
			minRange=600;
			minRangeProbab=0.64999998;
			midRange=800;
			midRangeProbab=0.40000001;
			maxRange=1200;
			maxRangeProbab=0.1;
		};
	};
	class RocketPods;
	class FST_SUU25 : RocketPods //Laat Parachute Flares
	{
		author = "Adapted from FIR Team by Viz"
		ballisticsComputer = 8;
		holdsterAnimValue = 1;
		magazines[] = { "FST_LAAT_P_12rnd_M" };
		displayName = "[41st] LAAT Flare Dispenser";
		modes[] = { "Far_AI", "Burst" };
		cursor = "EmptyCursor";
		cursorAim = "rocket";
		class Far_AI : RocketPods
		{
			minRange = 50;
			minRangeProbab = 0.041;
			midRange = 600;
			midRangeProbab = 0.21;
			maxRange = 2500;
			maxRangeProbab = 0.11;
			displayName = "HYDRA-SINGLE";

			sounds[] = { "StandardSound" };

			class StandardSound
			{
				begin1[] = { "A3\Sounds_F\weapons\Rockets\new_rocket_7", 1.7782794, 1.2, 1600 };
				soundBegin[] = { "begin1", 1 };
				weaponSoundEffect = "DefaultRifle";
			};
			soundFly[] = { "\A3\Sounds_F\weapons\Rockets\rocket_fly_2", 1.0, 1.2, 700 };
			weaponSoundEffect = "DefaultRifle";

			burst = 1;
			reloadTime = 1;
			autoFire = 0;
			showToPlayer = 0;
		};
		class Burst : RocketPods
		{
			minRange = 1;
			minRangeProbab = 0.001;
			midRange = 2;
			midRangeProbab = 0.001;
			maxRange = 3;
			maxRangeProbab = 0.001;
			displayName = "FLR DPS";
			burst = 1;
			reloadTime = 1;
			soundContinuous = 0;
			autoFire = 1;

			sounds[] = { "StandardSound" };

			class StandardSound
			{
				begin1[] = { "A3\Sounds_F\weapons\Rockets\new_rocket_7", 1.7782794, 1.2, 1600 };
				soundBegin[] = { "begin1", 1 };
				weaponSoundEffect = "DefaultRifle";
			};
			soundFly[] = { "\A3\Sounds_F\weapons\Rockets\rocket_fly_2", 1.0, 1.2, 700 };
			weaponSoundEffect = "DefaultRifle";
		};
	};
	class FIR_RKT_Base : RocketPods
	{	
		class EventHandlers 
		{
			fired = "[_this] execVM '\FIR_AirWeaponSystem_US\Script\TGTSystem\FCS\ROCKET_EH.sqf';";
		};	
	};
	class FST_RKT_Launcher : FIR_RKT_Base //Laat Smoke Rocket
	{
		author = "Adapted from FIR Team by Viz"
		ballisticsComputer = 8;
		holdsterAnimValue = 1;
		magazines[] = {"FST_LAAT_Smoke_P_16rnd_M"};
		displayName = "LAAT Rocket Launcher";
		modes[] = { "Far_AI", "Single","Burst" };
		cursor = "EmptyCursor";
		cursorAim = "rocket";
		class Far_AI : FIR_RKT_Base
		{
			minRange = 50;
			minRangeProbab = 0.041;
			midRange = 600;
			midRangeProbab = 0.21;
			maxRange = 2500;
			maxRangeProbab = 0.11;
			displayName = "HYDRA-SINGLE";

			sounds[] = { "StandardSound" };

			class StandardSound
			{
				begin1[] = { "A3\Sounds_F\weapons\Rockets\new_rocket_7", 1.7782794, 1.2, 1600 };
				soundBegin[] = { "begin1", 1 };
				weaponSoundEffect = "DefaultRifle";
			};
			soundFly[] = { "\A3\Sounds_F\weapons\Rockets\rocket_fly_2", 1.0, 1.2, 700 };
			weaponSoundEffect = "DefaultRifle";

			burst = 1;
			reloadTime = 0.08;
			autoFire = 0;
			showToPlayer = 0;
		};
		class Single : FIR_RKT_Base
		{
			minRange = 1;
			minRangeProbab = 0.001;
			midRange = 2;
			midRangeProbab = 0.001;
			maxRange = 3;
			maxRangeProbab = 0.001;
			displayName = "SINGLE";
			burst = 1;
			reloadTime = 0.1;
			soundContinuous = 0;
			autoFire = 0;

			sounds[] = { "StandardSound" };

			class StandardSound
			{
				begin1[] = { "A3\Sounds_F\weapons\Rockets\new_rocket_7", 1.7782794, 1.2, 1600 };
				soundBegin[] = { "begin1", 1 };
				weaponSoundEffect = "DefaultRifle";
			};
			soundFly[] = { "\A3\Sounds_F\weapons\Rockets\rocket_fly_2", 1.0, 1.2, 700 };
			weaponSoundEffect = "DefaultRifle";		
		};		
		class Burst : FIR_RKT_Base
		{
			minRange = 1;
			minRangeProbab = 0.001;
			midRange = 2;
			midRangeProbab = 0.001;
			maxRange = 3;
			maxRangeProbab = 0.001;
			displayName = "FULLAUTO";
			burst = 1;
			reloadTime = 0.1;
			soundContinuous = 0;
			autoFire = 1;
			textureType = "fullAuto";
			sounds[] = { "StandardSound" };

			class StandardSound
			{
				begin1[] = { "A3\Sounds_F\weapons\Rockets\new_rocket_7", 1.7782794, 1.2, 1600 };
				soundBegin[] = { "begin1", 1 };
				weaponSoundEffect = "DefaultRifle";
			};
			soundFly[] = { "\A3\Sounds_F\weapons\Rockets\rocket_fly_2", 1.0, 1.2, 700 };
			weaponSoundEffect = "DefaultRifle";		
			
			dispersion = 0.006000;
		};		
	};
};

