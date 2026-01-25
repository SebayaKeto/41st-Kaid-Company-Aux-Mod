class CfgPatches
{
	class WPS_Weapons_Magazines_Other
	{
		weapons[]=
		{
		};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Weapons_F",
			"WPS_Weapons_Magazines_Blasters"
		};
		magazines[]=
		{
			"WPS_FuelPack_Standard"
		};
		ammo[]=
		{
			"WPS_BTX42_FireShot"
		};
		units[]={};
	};
};
class CfgAmmo
{
	class BulletBase;
	class WPS_BTX42_FireShot: BulletBase
	{
		submunitionAmmo = "WPS_BTX42_FireShot_submunition";
		submunitionConeType[] = {"poissondisc",4};
		submunitionConeAngle = 4;
		triggerTime = 0.05;
		hit = 10;
		indirectHit = 6.5;
		indirectHitRange = 2.5;
		cartridge = "";
		cost = 2;
		visibleFire = 32;
		audibleFire = 12;
		visibleFireTime = 20;
		airFriction = 0.1;
		timetolive = 2;
		maxSpeed = 25;
		typicalSpeed = 0.12;
		coefGravity = 0.4;
		deflecting = 0;
		explosive = 1;
		fuseDistance = 1;
		caliber = 0.5;
		tracerScale = 0.001;
		tracerStartTime = 0.01;
		tracerEndTime = 0.1;
		craterEffects = "";
		explosionEffects = "WPS_FlameExplosion";
		model = "FST\FST_Weapons\FST_Magazines\Other\Data\FlameShot_Red.p3d";
		effectFly = "WPS_FlameTrail";
		WPS_AmmoType = 5;
		class CamShakeExplode
		{
			power = 1;
			duration = "((round (3^0.5))*0.2 max 0.2)";
			frequency = 2;
			distance = 1;
		};
		class CamShakeHit
		{
			power = 1;
			duration = "((round (3^0.25))*0.2 max 0.2)";
			frequency = 2;
			distance = 0.25;
		};
		class CamShakeFire
		{
			power = 0;
			duration = 0;
			frequency = 0;
			distance = 0;
		};
		class CamShakePlayerFire
		{
			power = 0;
			duration = 0;
			frequency = 0;
			distance = 0;
		};
	};
	class WPS_BTX42_FireShot_submunition: BulletBase
	{
		hit = 10;
		indirectHit = 5;
		indirectHitRange = 1;
		cartridge = "";
		cost = 2;
		visibleFire = 32;
		audibleFire = 12;
		visibleFireTime = 20;
		airFriction = 0;
		timetolive = 3.5;
		maxSpeed = 25;
		typicalSpeed = 0.12;
		coefGravity = 0.4;
		deflecting = 0;
		explosive = 1;
		fuseDistance = 1;
		caliber = 0.5;
		tracerScale = 0.01;
		tracerStartTime = 0.01;
		tracerEndTime = 0.1;
		craterEffects = "";
		explosionEffects = "WPS_FlameExplosion";
		model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
		effectFly = "WPS_FlameTrail";
		class CamShakeExplode
		{
			power = 1;
			duration = "((round (3^0.5))*0.2 max 0.2)";
			frequency = 2;
			distance = 1;
		};
		class CamShakeHit
		{
			power = 1;
			duration = "((round (3^0.25))*0.2 max 0.2)";
			frequency = 2;
			distance = 0.25;
		};
		class CamShakeFire
		{
			power = 0;
			duration = 0;
			frequency = 0;
			distance = 0;
		};
		class CamShakePlayerFire
		{
			power = 0;
			duration = 0;
			frequency = 0;
			distance = 0;
		};
	};
};
class CfgMagazines
{	
	class WPS_ChargePack_Base;
	class WPS_FuelPack_Standard: WPS_ChargePack_Base
	{
		scope = 2;
		displayName = "[WPS] Fuel Pack";
		ammo = "WPS_BTX42_FireShot";
		descriptionShort = "Standard Fuel pack for the BTX-42";
		count = 400;
	};
};
class CfgMagazineWells
{
	class WPS_BTX42Magwell
	{
		BTX42Magazines[] = 
		{
			"WPS_FuelPack_Standard"
		};
	};
};
class cfgRecoils
{
	class WPS_Recoil_Default;
	class WPS_Recoil_BTX42: WPS_Recoil_Default
	{
		kickBack[] = {0,0};
		temporary = 0.01;
	};
};
class CfgCloudlets
{	
	class Default;
	class ObjectDestructionFire1Small;
	class WPS_FlameTrail_Projectile: Default
	{
		interval = 0.015;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 2;
		particleFSFrameCount = 80;
		particleFSLoop = 0;
		angleVar = 0.5;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 25;
		moveVelocity[] = {0,0,0};
		rotationVelocity = 1;
		weight = 0.06;
		volume = 0.05;
		rubbing = 0.1;
		size[] = {0.8};
		color[] = {{0.9,0.9,0.9,0.4},{0.9,0.9,0.9,0.18},{0.9,0.9,0.9,0.06},{0.9,0.9,0.9,0.02}};
		animationSpeed[] = {0.5};
		randomDirectionPeriod = 0.1;
		randomDirectionIntensity = 0.05;
		onTimerScript = "";
		beforeDestroyScript = "";
		destroyOnWaterSurface = 1;
		bounceOnSurface = 0.1;
		bounceOnSurfaceVar = 0.12;
		blockAIVisibility = 0;
		sizeCoef = 1;
		colorCoef[] = {1,1,1,1};
		animationSpeedCoef = 1;
		position[] = {0,0,0};
		lifeTimeVar = 3;
		positionVar[] = {0,0,0};
		MoveVelocityVar[] = {0.6,0.6,0.6};
		rotationVelocityVar = 3;
		sizeVar = 0;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class WPS_FlameTrail_HeatHazeEffect: Default
	{
		interval = 0.06;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\A3\data_f\ParticleEffects\Universal\Refract";
		particleFSNtieth = 16;
		particleFSIndex = 2;
		particleFSFrameCount = 80;
		particleFSLoop = 0;
		angleVar = 0.5;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 25;
		moveVelocity[] = {"25*directionX","25*directionY","25*directionZ"};
		rotationVelocity = 1;
		weight = 0.06;
		volume = 0.05;
		rubbing = 0.1;
		size[] = {0.4};
		color[] = {{0.9,0.9,0.9,0.4},{0.9,0.9,0.9,0.18},{0.9,0.9,0.9,0.06},{0.9,0.9,0.9,0.01}};
		animationSpeed[] = {0.5};
		randomDirectionPeriod = 0.1;
		randomDirectionIntensity = 0.05;
		onTimerScript = "";
		beforeDestroyScript = "";
		destroyOnWaterSurface = 1;
		bounceOnSurface = 0.1;
		bounceOnSurfaceVar = 0.12;
		blockAIVisibility = 0;
		sizeCoef = 1;
		colorCoef[] = {1,1,1,1};
		animationSpeedCoef = 1;
		position[] = {"positionX","positionY","positionZ"};
		lifeTimeVar = 3;
		positionVar[] = {0,0,0};
		MoveVelocityVar[] = {0.6,0.6,0.6};
		rotationVelocityVar = 3;
		sizeVar = 0;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class WPS_FlameTrail_Fire: ObjectDestructionFire1Small
	{
		coreIntensity = 3.75;
		coreDistance = 2;
		damageTime = 0.1;
		constantDistance = 1;
		damageType = "Fire";
		size[] = {"1.2 * 0.15 + 1","0.1 * 0.15 + 0.2"};
		animationSpeedCoef = 1;
		sizeCoef = 1;
		animationSpeed[] = {1};
	};
	class ExploAmmoSmoke;
	class WPS_BTX42_BaseCloudlet: ExploAmmoSmoke
	{
		interval = 6.25e-05;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		angleVar = 0;
		particleFSLoop = 0;
		particleShape = "\A3\data_f\cl_basic";
		particleFSNtieth = 1;
		particleFSIndex = 0;
		particleFSFrameCount = 1;
		animationName = "";
		particleType = "BillBoard";
		timerPeriod = 1;
		lifeTime = 0.1;
		moveVelocity[] = {0,0,0};
		rotationVelocity = 0;
		weight = 127.5;
		volume = 0.01;
		rubbing = 1e-09;
		size[] = {0.05,0.05,0.05};
		sizeCoef = 3.0;
		color[] = {{0.8,0,0.6,0.35},{0.8,0,0.6,0.2},{0.8,0,0.6,0.05}};
		colorCoef[] = {0.8,0.2,0.6,1.2};
		animationSpeed[] = {0};
		animationSpeedCoef = 1;
		randomDirectionPeriod = 0.0;
		randomDirectionIntensity = 0.0;
		onTimerScript = "";
		beforeDestroyScript = "";
		blockAIVisibility = 0;
		lifeTimeVar = 0.0;
		rotationVelocityVar = 0.0;
		sizeVar = 0.02;
		colorVar[] = {0.2,0.1,0.2,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
		position[] = {0,0,0};
		positionVar[] = {0,0,0};
		positionVarConst[] = {0,0,0};
		moveVelocityVar[] = {0,0,0};
		moveVelocityVarConst[] = {0,0,0};
		emissiveColor[] = {{30,0,0,0},{0,0,0,0}};
	};
	class WPS_BTX42_FlameExplosion: WPS_BTX42_BaseCloudlet
	{
		interval = "0.015";
		circleRadius = 0.1;
		circleVelocity[] = {0,0,0};
		particleShape = "\a3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 10;
		particleFSFrameCount = 32;
		particleFSLoop = 1;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 3;
		lifeTime = 2;
		moveVelocity[] = {0,0.025,0};
		rotationVelocity = 0;
		weight = 0.075;
		volume = 0.05;
		rubbing = 0.05;
		size[] = {0.5,0.5,0.5,0.5};
		sizeCoef = 3.5;
		color[] = {{0.7,1,0.6,0.6},{0.7,1,0.6,0.4},{0.7,1,0.6,0.22},{0.7,1,0.6,0.1},{0.7,1,0.6,0}};
		colorCoef[] = {0.7,1,0.6,1};
		animationSpeed[] = {1.7,0.6,0.4,0.3,0.3};
		randomDirectionPeriod = 0.2;
		randomDirectionIntensity = 0.05;
		onTimerScript = "";
		lifeTimeVar = 1.7;
		positionVar[] = {"1 + 1.1 * intensity",0.3,"1 + 1.1 * intensity"};
		moveVelocityVar[] = {0.1,0.1,0.1};
		rotationVelocityVar = 0;
		sizeVar = 0.05;
		colorVar[] = {0.1,0.1,0.1,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
};
class WPS_FlameTrail_GeneralEffect
{
	class WPS_FlameTrail_Projectile
	{
		simulation = "particles";
		type = "WPS_FlameTrail_Projectile";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.25;
		qualityLevel = -1;
	};
};
class WPS_FlameTrail_ProjectileEffect
{
	class WPS_Projectile_FlameEffect
	{
		simulation = "particles";
		type = "WPS_FlameTrail_Projectile";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 3.5;
		qualityLevel = -1;
	};
};
class WPS_FlameExplosion
{
	class WPS_BTX42_FlameLight
	{
		simulation = "light";
		type = "FiredLightMed";
		position = "destructionEffect1";
		intensity = 1;
		interval = 1;
		lifeTime = 10;
	};
	class WPS_BTX42_FlameSound
	{
		simulation = "sound";
		type = "Fire";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 10;
	};
	class WPS_BTX42_FlameExplosion
	{
		simulation = "particles";
		type = "WPS_BTX42_FlameExplosion";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 10;
	};
};
class WPS_FlameTrail
{
	class WPS_BTX42_FlameTrail
	{
		simulation = "particles";
		type = "WPS_FlameTrail_Fire";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 3;
		qualityLevel = -1;
	};
};