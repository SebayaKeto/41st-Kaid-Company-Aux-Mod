#define Private 0
#define Protected 1
#define Public 2

class CfgPatches
{
	class WPS_Grenade_MK1Imploder
	{
		author = "Maldova";
		requiredAddons[]=
		{
			"A3_Weapons_F"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]={}; // You dont need to define the throwMuzzle as a weapon since the players arm is the weapon and we are adding the Grenade as a magazine to the players arm.
		magazines[]=
		{
			"WPS_MK1Imploder"
		};
		ammo[]=
		{
			"WPS_MK1Imploder_Ammo"
		};	
	};
};
class CfgAmmo
{
    class GrenadeHand; //Standard define of base Grenade class.  There are a few different classes you can use here I just used GrenadeHand.
	class WPS_MK1Imploder_Ammo: GrenadeHand
	{
		hit = 1400;
		indirectHit = 1300;
		indirectHitRange = 4;
		model = "WPS\WPS_Weapons\Grenades\MK1Imploder\MK-1ThermalImploder.p3d";
		soundFly[] = {"WPS\WPS_Weapons\Sounds\Grenades\Imploder_Fly.ogg",3.9,1,110};
		soundSetExplosion[] =
		{
			"WPS_MK1Imploder_Exp_Soundset",
			"Explosion_Debris_SoundSet"
		};
		ace_grenades_pullPinSound[]=
		{
			"WPS\WPS_Weapons\Sounds\Grenades\Grenade_Pin1.wss",1.9,1,15
		};
		allowAgainstInfantry = 1;
		explosionType = "bomb";
		explosionEffects = "BombExplosion";
	};
	class SubmunitionBase;
	class WPS_Submunition_Imploder: SubmunitionBase
	{
		hit = 1000;
		indirectHit = 750;
		indirectHitRange = 4;
	};
};
class CfgMagazines
{
	//Standard define for the magazine.   Grenades technically have no weapon they are a magazine being thrown and the players hand is the weapon.
	class HandGrenade;
	//Class Define for the MK1 Grenade
	class WPS_MK1Imploder: HandGrenade
	{
		author = "Maldova";
		scope = Public; //Scope of Public (2) as defined above
		value = 1; // Value Arma tells you to define for frags
		picture = "\WPS\WPS_Weapons\Grenades\UI\ImploderIcon.paa";
		model = "WPS\WPS_Weapons\Grenades\MK1Imploder\MK-1ThermalImploder.p3d"; // Model for the magazine
		displayName = "[104th] MK-1 Thermal Imploder"; //Name displayed in Inventory and Arsenal
		displayNameShort = "MK-1 Imploder"; //Name displayed on a players HUD
		descriptionShort = "MK-1 Thermal Imploder"; //Description displayed in inventory.
		ammo = "WPS_MK1Imploder_Ammo"; //Ammo used by the magazine
		submunitionAmmo = "WPS_Submunition_Imploder";
		submunitionInitSpeed = 1000;
		submunitionDirectionType = "SubmunitionAutoLeveling";
		submunitionConeType[] = 
		{
			"randomcenter",
			2
		};
		count = 1;// How many rounds of the ammo is in this magazine
		type = 256; // 256 is the type used for Grenades by Arma.
		initSpeed = 14; //Defines the starting speed of the grenade when it leaves the players hand
		nameSound = "handgrenade"; //Defines the type of radio calls AI will use when this object is detected.  They will use calls like "Look out Grenade!" when they see this object.
		maxLeadSpeed = 6;
		explosive = 1;
		sound[] = {"WPS\WPS_Weapons\Sounds\Grenades\Imploder_Fly.ogg",0.000316228,1};
		mass = 22; //Defines the mass of the object in the inventory
		class Library
		{
			libTextDesc = "Standard-Issue Thermal Imploder of the GAR.  Allows for limited damage against armored targets and high damage in a 5m radius."; //Defines the description use for an indepth explanation.
		};
		class CamShakeExplode
		{
			power=28;
			duration=2.3;
			frequency=23;
			distance=69.817802;
		};
	};
};
class CfgWeapons
{
	//Defining the Throw/ThrowMuzzle (aka players hand) and it has to inherit from the base Grenade Launcher.
	class GrenadeLauncher;
	class Throw: GrenadeLauncher
	{
		// += is very important as it adds your grenade to the list of other grenades.  Just having = will overwrite all grenades loaded before this from other mods and can/will cause other issues.
		muzzles[]+=
		{
			"WPS_MK1Imploder_Throw"
		};
		class ThrowMuzzle;
		//Defining the Muzzle so the grenade can actually be thrown.  Without this it will just be an object (Magazine) you can add to an inventory.
		class WPS_MK1Imploder_Throw: ThrowMuzzle
		{
			model = "WPS\WPS_Weapons\Grenades\MK1Imploder\MK-1ThermalImploder.p3d";
			magazines[] =
			{
				"WPS_MK1Imploder"
			};
		};
	};
};