class CfgPatches
{
	class FST_Vehicles_Weapons
	{
		author = "Maldova";
		requiredAddons[] =
		{
			"A3_Data_F",
			"A3_Weapons_F",
			"FST_Core",
			"FST_Weapons"
		};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] =
		{
			"FST_Horn_RepulsorPulse",
			"FST_Horn_CloneConvoy",
			"FST_Vehicle_Launcher_Concussion",
			"FST_Vehicle_Cannon_30mm",
			"FST_Vehicle_HMG_50cal"
		};
		magazines[] =
		{
			"FST_Vehicle_Mag_4Rnd_Concussion",
			"FST_Vehicle_Mag_140Rnd_30mm_MP",
			"FST_Vehicle_Mag_60Rnd_30mm_APFSDS",
			"FST_Vehicle_Mag_500Rnd_50cal_Tracer"
		};
		ammo[] =
		{
			"FST_Vehicle_Ammo_ConcussionMissile",
			"FST_Vehicle_Ammo_50cal_Tracer"
		};
	};
};

class CfgCloudlets
{
	class Default;
	class FST_Vehicle_MissileTrail_BlueIon: Default
	{
		interval = 0.004;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 8;
		particleFSLoop = 0;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 0.7;
		moveVelocity[] = {0,0.7,0};
		rotationVelocity = 1;
		weight = 1;
		volume = 0.8;
		rubbing = 0.1;
		size[] = {0.1,0.24,0.42};
		color[] =
		{
			{0.2,0.55,1,0.45},
			{0.45,0.75,1,0.22},
			{0.7,0.9,1,0.02}
		};
		animationSpeed[] = {1};
		randomDirectionPeriod = 0.1;
		randomDirectionIntensity = 0.08;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 0.2;
		positionVar[] = {0.04,0.04,0.04};
		moveVelocityVar[] = {0.1,0.2,0.1};
		rotationVelocityVar = 2;
		sizeVar = 0.08;
		colorVar[] = {0.05,0.05,0.05,0.02};
		randomDirectionPeriodVar = 0.02;
		randomDirectionIntensityVar = 0.01;
	};

	class FST_Vehicle_MissileImpact_Concussion: Default
	{
		interval = 0.008;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 13;
		particleFSFrameCount = 1;
		particleFSLoop = 0;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 0.32;
		moveVelocity[] = {0,1.2,0};
		rotationVelocity = 1;
		weight = 1.1;
		volume = 0.9;
		rubbing = 0.12;
		size[] = {0.8,1.8,2.8};
		color[] =
		{
			{0.85,0.95,1,0.35},
			{0.45,0.75,1,0.18},
			{0.25,0.5,0.9,0.01}
		};
		animationSpeed[] = {1};
		randomDirectionPeriod = 0.04;
		randomDirectionIntensity = 0.06;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 0.06;
		positionVar[] = {0.04,0.04,0.04};
		moveVelocityVar[] = {0.2,0.2,0.2};
		rotationVelocityVar = 2;
		sizeVar = 0.1;
		colorVar[] = {0.02,0.02,0.02,0.02};
		randomDirectionPeriodVar = 0.01;
		randomDirectionIntensityVar = 0.01;
	};
};

class CfgAmmo
{
	class M_PG_AT;
	class B_127x99_Ball_Tracer_Red;
	class B_30mm_MP_Tracer_Red;
	class B_30mm_APFSDS_Tracer_Red;
	class FST_Vehicle_Ammo_ConcussionMissile: M_PG_AT
	{
		author = "Maldova";
		displayName = "Concussion Missile";
		hit = 360;
		indirectHit = 65;
		indirectHitRange = 4;
		maxSpeed = 420;
		initSpeed = 130;
		thrustTime = 4;
		thrust = 270;
		maneuvrability = 22;
		trackLead = 0.9;
		trackOversteer = 0.7;
		airLock = 1;
		irLock = 1;
		laserLock = 1;
		nvLock = 1;
		cmImmunity = 0.72;
		effectsMissile = "FST_Vehicle_MissileTrail_BlueIon";
		explosionEffects = "FST_Vehicle_MissileImpact_Concussion";
		whistleDist = 10;
	};

	class FST_Vehicle_Ammo_50cal_Tracer: B_127x99_Ball_Tracer_Red
	{
		author = "Maldova";
		displayName = "50 Cal Blue Tracer";
		effectFly = "FST_Proj_Blue_Emissive_Small";
		tracerColor[] = {0.15,0.55,1,1};
		tracerColorR[] = {0.45,0.8,1,1};
		tracerScale = 2.2;
		tracerStartTime = 0.01;
		tracerEndTime = 3.8;
		nvgOnly = 0;
	};

	class FST_Vehicle_Ammo_30mm_MP_Emissive: B_30mm_MP_Tracer_Red
	{
		author = "Maldova";
		displayName = "30mm MP Emissive";
		effectFly = "FST_Proj_Blue_Emissive_Heavy";
	};

	class FST_Vehicle_Ammo_30mm_APFSDS_Emissive: B_30mm_APFSDS_Tracer_Red
	{
		author = "Maldova";
		displayName = "30mm APFSDS Emissive";
		effectFly = "FST_Proj_Blue_Emissive_Heavy";
	};
};

class CfgMagazines
{
	class 4Rnd_Titan_long_missiles;
	class 140Rnd_30mm_MP_shells_Tracer_Red;
	class 60Rnd_30mm_APFSDS_shells_Tracer_Red;
	class 500Rnd_127x99_mag;
	class FST_Vehicle_Mag_4Rnd_Concussion: 4Rnd_Titan_long_missiles
	{
		author = "Maldova";
		displayName = "4Rnd Concussion Missiles";
		displayNameShort = "Concussion";
		ammo = "FST_Vehicle_Ammo_ConcussionMissile";
		count = 4;
		initSpeed = 130;
		mass = 120;
	};

	class FST_Vehicle_Mag_140Rnd_30mm_MP: 140Rnd_30mm_MP_shells_Tracer_Red
	{
		author = "Maldova";
		displayName = "140Rnd 30mm MP-T";
		displayNameShort = "30mm MP";
		ammo = "FST_Vehicle_Ammo_30mm_MP_Emissive";
		count = 140;
		mass = 220;
	};

	class FST_Vehicle_Mag_60Rnd_30mm_APFSDS: 60Rnd_30mm_APFSDS_shells_Tracer_Red
	{
		author = "Maldova";
		displayName = "60Rnd 30mm APFSDS-T";
		displayNameShort = "30mm AP";
		ammo = "FST_Vehicle_Ammo_30mm_APFSDS_Emissive";
		count = 60;
		mass = 180;
	};

	class FST_Vehicle_Mag_500Rnd_50cal_Tracer: 500Rnd_127x99_mag
	{
		author = "Maldova";
		displayName = "500Rnd .50 Cal Tracer";
		displayNameShort = ".50 Tracer";
		ammo = "FST_Vehicle_Ammo_50cal_Tracer";
		count = 500;
		mass = 140;
	};
};

class CfgWeapons
{
	class CarHorn;
	class missiles_titan;
	class autocannon_30mm;
	class HMG_127_APC;

	class TruckHorn2;
	class FST_SabreAPC_Horn: TruckHorn2
	{
		displayName="[FST] Sabre APC Horn";
		begin1[]=
		{
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Sounds\Horns_01.ogg",
			1,
			1,
			200
		};
		begin2[]=
		{
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Sounds\Horns_02.ogg",
			1,
			1,
			200
		};
		begin3[]=
		{
			"FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Sounds\Horns_03.ogg",
			1,
			1,
			200
		};
		soundBegin[]=
		{
			"begin1",
			0.33333334,
			"begin2",
			0.33333334,
			"begin3",
			0.33333334
		};
		reloadTime=1.2;
	};

	class FST_Vehicle_Launcher_Concussion: missiles_titan
	{
		author = "Maldova";
		scope = 2;
		displayName = "FST Concussion Missile Rack";
		displayNameShort = "Concussion Rack";
		magazines[] = {"FST_Vehicle_Mag_4Rnd_Concussion"};
		canLock = 2;
		weaponLockSystem = 2 + 4;
		aiRateOfFire = 4;
		aiRateOfFireDistance = 1800;
		reloadTime = 0.25;
	};

	class FST_Vehicle_Cannon_30mm: autocannon_30mm
	{
		author = "Maldova";
		scope = 2;
		displayName = "FST Twin 30mm Cannon";
		displayNameShort = "Twin 30mm";
		muzzleImpulseFactor[] = {0.0001,0.005};
		magazines[] =
		{
			"FST_Vehicle_Mag_140Rnd_30mm_MP",
			"FST_Vehicle_Mag_60Rnd_30mm_APFSDS"
		};
	};

	class FST_Vehicle_HMG_50cal: HMG_127_APC
	{
		author = "Maldova";
		scope = 2;
		displayName = "FST Commander .50 Cal";
		displayNameShort = "Commander .50";
		magazines[] = {"FST_Vehicle_Mag_500Rnd_50cal_Tracer"};
	};
};
