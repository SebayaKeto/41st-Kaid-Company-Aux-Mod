class CfgPatches
{
	class FST_weapons_Grenades
	{
		author="Adapted from JLTS";
		name="41st Grenades";
		requiredAddons[]=
		{
			"A3_data_F",
			"A3_anims_F",
			"A3_weapons_F",
			"A3_characters_F",
			"JLTS_weapons_EPL2"
		};
		weapons[]={};
		units[]={};
		magazines[]=
		{
			"FST_grenade_emp_mag",
			"FST_grenade_Detonator_mag",
			"FST_grenade_rock_mag"
		};
		ammo[]=
		{
			"FST_grenade_emp_ammo",
			"FST_grenade_Detonator_ammo",
			"FST_grenade_rock_ammo",
		};
	};
};
class CfgWeapons
{
	class GrenadeLauncher;
	class Throw: GrenadeLauncher
	{
		muzzles[]+=
		{
			"FST_grenade_emp_muzzle",
			"FST_grenade_Detonator_muzzle",
			"FST_grenade_Penetrator_muzzle",
			"FST_grenade_rock_muzzle"
		};
		class ThrowMuzzle;
		class FST_grenade_emp_muzzle: ThrowMuzzle
		{
			magazines[]=
			{
				"FST_grenade_emp_mag"
			};
		};
		class FST_grenade_Detonator_muzzle: ThrowMuzzle
		{
			magazines[]=
			{
				"FST_grenade_Detonator_mag"
			};
		};
		class FST_grenade_Penetrator_muzzle: ThrowMuzzle
		{
			magazines[]=
			{
				"FST_grenade_Penetrator_mag"
			};
		};
		class FST_grenade_rock_muzzle: ThrowMuzzle
		{
			magazines[]=
			{
				"FST_grenade_rock_mag"
			};
		};
	};
};
