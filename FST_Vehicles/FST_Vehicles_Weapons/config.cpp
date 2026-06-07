class CfgPatches
{
	class FST_Vehicles_Weapons
	{
		author = "Maldova";
		requiredAddons[] =
		{
			"A3_Data_F",
			"A3_Weapons_F",
			"FST_Weapons"
		};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] =
		{
			"FST_Horn_RepulsorPulse",
			"FST_Horn_CloneConvoy",
			"FST_Vehicle_Launcher_Concussion",
			"FST_Vehicle_Cannon_30mm"
		};
		magazines[] =
		{
			"FST_Vehicle_Mag_4Rnd_Concussion",
			"FST_Vehicle_Mag_140Rnd_30mm_MP",
			"FST_Vehicle_Mag_60Rnd_30mm_APFSDS"
		};
		ammo[] =
		{
			"FST_Vehicle_Ammo_ConcussionMissile"
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
};

class CfgMagazines
{
	class 4Rnd_Titan_long_missiles;
	class 140Rnd_30mm_MP_shells_Tracer_Red;
	class 60Rnd_30mm_APFSDS_shells_Tracer_Red;
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
		count = 140;
		mass = 220;
	};

	class FST_Vehicle_Mag_60Rnd_30mm_APFSDS: 60Rnd_30mm_APFSDS_shells_Tracer_Red
	{
		author = "Maldova";
		displayName = "60Rnd 30mm APFSDS-T";
		displayNameShort = "30mm AP";
		count = 60;
		mass = 180;
	};
};

class CfgWeapons
{
	class CarHorn;
	class missiles_titan;
	class autocannon_30mm;

	class FST_Horn_RepulsorPulse: CarHorn
	{
		author = "Maldova";
		scope = 2;
		displayName = "Repulsor Pulse Horn";
		drySound[] = {"\a3\sounds_f\vehicles\soft\noises\horn_big_car.wss",1,0.8,220};
		hornSound[] = {"\FST\FST_Weapons\FST_Sounds\General\B2BattleDroidGlitch.ogg",2.4,0.92,260};
		reloadTime = 1.2;
		autoFire = 0;
		canLock = 0;
	};

	class FST_Horn_CloneConvoy: CarHorn
	{
		author = "Maldova";
		scope = 2;
		displayName = "Clone Convoy Horn";
		drySound[] = {"\a3\sounds_f\vehicles\soft\noises\horn_big_car.wss",1,0.75,220};
		hornSound[] = {"\FST\FST_Weapons\FST_Sounds\General\TSeriesGlitch.ogg",2.1,0.86,240};
		reloadTime = 1.35;
		autoFire = 0;
		canLock = 0;
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
		magazines[] =
		{
			"FST_Vehicle_Mag_140Rnd_30mm_MP",
			"FST_Vehicle_Mag_60Rnd_30mm_APFSDS"
		};
	};
};
