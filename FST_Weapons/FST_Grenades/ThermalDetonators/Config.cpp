#include "basicdefines_FST.hpp"

class CfgPatches
{
	class FST_Grenade_MKV_Penetrator
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
			"FST_MKVPenetrator"
		};
		ammo[]=
		{
			"FST_MKVPenetrator_Ammo"
		};	
	};
};
class CfgAmmo
{
    class GrenadeHand; //Standard define of base Grenade class.  There are a few different classes you can use here I just used GrenadeHand.
	class FST_MKVPenetrator_Ammo: GrenadeHand
	{
		hit = 1400;
		indirectHit = 1300;
		indirectHitRange = 4;
		model = "FST\FST_Weapons\FST_Grenades\ThermalDetonators\Class-V_ThermalDetonator.p3d";
		//soundFly[] = {"WPS\WPS_Weapons\Sounds\Grenades\Imploder_Fly.ogg",3.9,1,110};
		//soundSetExplosion[] =
		//{
		//	"WPS_MK1Imploder_Exp_Soundset",
		//	"Explosion_Debris_SoundSet"
		//};
		//ace_grenades_pullPinSound[]=
		//{
		//	"WPS\WPS_Weapons\Sounds\Grenades\Grenade_Pin1.wss",1.9,1,15
		//};
		allowAgainstInfantry = 1;
		explosionType = "bomb";
		explosionEffects = "BombExplosion";
	};
	class SubmunitionBase;
	class FST_Submunition_Penetrator: SubmunitionBase
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
	class FST_MKVPenetrator: HandGrenade
	{
		author = "Maldova";
		scope = Public; //Scope of Public (2) as defined above
		value = 1; // Value Arma tells you to define for frags
		picture = "FST\FST_Weapons\FST_Grenades\ThermalDetonators\UI\Class-V_ThermalDetonator_Side.paa";
		model = "FST\FST_Weapons\FST_Grenades\ThermalDetonators\Class-V_ThermalDetonator.p3d"; // Model for the magazine
		displayName = "[FST] MK-V Thermal Penetrator"; //Name displayed in Inventory and Arsenal
		displayNameShort = "MK-V Penetrator"; //Name displayed on a players HUD
		descriptionShort = "MK-V Thermal Penetrator"; //Description displayed in inventory.
		ammo = "FST_MKVPenetrator_Ammo"; //Ammo used by the magazine
		submunitionAmmo = "FST_Submunition_Penetrator";
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
		//sound[] = {"WPS\WPS_Weapons\Sounds\Grenades\Imploder_Fly.ogg",0.000316228,1};
		mass = 22; //Defines the mass of the object in the inventory
		class Library
		{
			libTextDesc = "Standard-Issue Thermal Penetrator of the GAR.  Allows for limited damage against armored targets and high damage in a 5m radius."; //Defines the description use for an indepth explanation.
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
			"FST_MKVPenetrator_Throw"
		};
		class ThrowMuzzle;
		//Defining the Muzzle so the grenade can actually be thrown.  Without this it will just be an object (Magazine) you can add to an inventory.
		class FST_MKVPenetrator_Throw: ThrowMuzzle
		{
			model = "FST\FST_Weapons\FST_Grenades\ThermalDetonators\Class-V_ThermalDetonator.p3d";
			magazines[] =
			{
				"FST_MKVPenetrator"
			};
		};
	};
};