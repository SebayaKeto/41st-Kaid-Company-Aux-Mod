class CfgPatches
{
	class WPS_Weapons_Magazines
	{
		weapons[]=
		{
		};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Weapons_F"
		};
		magazines[]=
		{
		};
		ammo[]=
		{
		};
		units[]={};
	};
};
class WPS_FX_Bullet_Teal
{
	class FX_Missile_Light
	{
		simulation="light";
		type="WPS_BlasterBoltLight_BlueFly";
		position[]={0,0,0};
		intensity=5000;
		useFlare=1;
		flareSize=2;
		flareMaxDistance=5000;
		interval=1;
	};
};
class CfgLights
{
	class WPS_BlasterBoltLight_BlueFly
	{
		color[] = {0,0,0,0};
		diffuse[] = {7,36,190,1};
		ambient[] = {0,0,0,0.5,1};
		brightness = 10;
		intensity = 6000;
		class Attenuation
		{
			start = 0;
			constant = 0;
			linear = 0;
			quadratic = 255;
			hardLimitStart = "1e20 * 0.7";
			hardLimitEnd = 1e+20;
		};
		dayLight = 1;
		useFlare = 1;
		flareSize = 0.35;
		flareMaxDistance = 6000;
	};
	class WPS_BlasterBoltLight_Base
	{
		diffuse[] = {1,0.6,0.4};
		color[] = {1,0.6,0.4};
		ambient[] = {0,0,0,0};
		brightness = 12;
		size = 1;
		intensity = 9000;
		drawLight = 0;
		blinking = 1;
		class Attenuation
		{
			start = 0;
			constant = 0;
			linear = 0;
			quadratic = 2.2;
			hardLimitStart = 500;
			hardLimitEnd = 1000;
		};
		position[] = {0,3.5,0};
	};
	class WPS_BlasterBoltLight_Blue: WPS_BlasterBoltLight_Base
	{

	};
	class WPS_BlasterBoltSparks_Base
	{
		diffuse[] = {1,0.8,0.8};
		color[] = {1,0.8,0.8};
		ambient[] = {0,0,0,0};
		brightness = 60;
		size = 1;
		intensity = 1200;
		drawLight = 0;
		blinking = 0;
		class Attenuation
		{
			start = 0;
			constant = 0;
			linear = 0;
			quadratic = 1;
			hardLimitStart = 40;
			hardLimitEnd = 80;
		};
		position[] = {0,0,0};
	};
	class WPS_BlasterBoltSparks_Blue: WPS_BlasterBoltSparks_Base
	{

	};
};
class CfgCloudlets
{
	class Default;
	class WPS_ImpactSparks_Base: Default
	{
		interval = 0.0009;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 13;
		particleFSFrameCount = 2;
		particleFSLoop = 0;
		angleVar = 360;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 3;
		lifeTime = 2.5;
		moveVelocity[] = {"(- inDirX * 2 + surfNormalX / 2) * inSpeed / 200","( - inDirY * 2 + surfNormalY / 2) * inSpeed / 200","( - inDirZ * 2 + surfNormalZ / 2) * inSpeed / 200"};
		rotationVelocity = 1;
		weight = 100;
		volume = 0.01;
		rubbing = 0.3;
		size[] = {0.12,0};
		sizeCoef = 1;
		color[] = {{1,0.6,0.4,-50}};
		colorCoef[] = {1,1,1,1};
		emissiveColor[] = {{10,6,4,1}};
		animationSpeed[] = {1000};
		animationSpeedCoef = 1;
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		blockAIVisibility = 0;
		bounceOnSurface = 0.1;
		bounceOnSurfaceVar = 0.1;
		lifeTimeVar = 5;
		position[] = {0,0,0};
		positionVar[] = {0.01,0.01,0.01};
		moveVelocityVar[] = {1,3,1};
		rotationVelocityVar = 0;
		sizeVar = 0;
		colorVar[] = {0.05,0.05,0.05,5};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class WPS_ImpactSparks_One: WPS_ImpactSparks_Base
	{

	};
	class WPS_ImpactSparks_Two: WPS_ImpactSparks_Base
	{
		interval = 0.01;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 13;
		particleFSFrameCount = 2;
		particleFSLoop = 0;
		angleVar = 360;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 3;
		lifeTime = 0.039;
		moveVelocity[] = {0,0,0};
		rotationVelocity = 1;
		weight = 1.275;
		volume = 1;
		rubbing = 0;
		size[] = {0.45,0.225,0};
		sizeCoef = 1;
		color[] = {{1,0.6,0.4,-50}};
		colorCoef[] = {1,1,1,1};
		animationSpeed[] = {1000};
		animationSpeedCoef = 1;
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		blockAIVisibility = 0;
		lifeTimeVar = 0.02;
		position[] = {0,0,0};
		positionVar[] = {0,0,0};
		moveVelocityVar[] = {0,0,0};
		rotationVelocityVar = 0;
		sizeVar = 0.03;
		colorVar[] = {0.05,0.05,0.05,5};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
};
class WPS_ImpactBlasterBolt
{
	class Light1
	{
		simulation = "light";
		type = "WPS_BlasterBoltLight_Blue";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.3;
	};
	class SparksLight
	{
		simulation = "light";
		type = "WPS_BlasterBoltSparks_Blue";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.5;
	};
	class ImpactSparks1
	{
		simulation = "particles";
		type = "WPS_ImpactSparks_One";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.3;
	};
	class ImpactSparks2
	{
		simulation = "particles";
		type = "WPS_ImpactSparks_Two";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.3;
	};
	class ImpactSmoke
	{
		simulation = "particles";
		type = "ImpactSmoke";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.3;
	};
};
