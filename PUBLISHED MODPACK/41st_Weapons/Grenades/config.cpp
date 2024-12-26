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
			"FST_grenade_Detonator_mag"
		};
		ammo[]=
		{
			"FST_grenade_emp_ammo",
			"FST_grenade_Detonator_ammo"
		};
	};
};
class CfgAmmo
{
	class GrenadeHand_stone;
	class GrenadeHand;
	class FST_grenade_emp_ammo: GrenadeHand_stone
	{
		JLTS_isEMPAmmo=1;
		ace_frag_enabled=0;
		ace_grenades_pullPinSound[]=
		{
			"\Indecisive_Armoury_Sounds\Detonator_Pin.ogg",
			6,
			1,
			10
		};
		author="Adapted from JLTS";
		hit=0.0099999998;
		indirectHit=0.0099999998;
		explosive=0.0099999998;
		indirectHitRange=7;
		model="\Indecisive_Armoury_Ammos\Data\Thermal_Detonator\IDA_Thermal_Detonator.p3d";
		explosionEffects="JLTS_fx_exp_EMP";
		grenadeBurningSound[]=
		{
			"EMPSoundLoop1",
			0.5
		};
		EMPSoundLoop1[]=
		{
			"MRC\JLTS\weapons\Grenades\sounds\grenade_burning.wss",
			0.125893,
			1,
			70
		};
		SoundSetExplosion[]=
		{
			"JLTS_GrenadeEMP_Exp_SoundSet",
			"JLTS_GrenadeEMP_Tail_SoundSet",
			"Explosion_Debris_SoundSet"
		};
		soundFly[]=
		{
			"\Indecisive_Armoury_Sounds\Detonator_Timer.ogg",
			6,
			1,
			90
		};
		aiAmmoUsageFlags=0;
		class CamShakeExplode
		{
			distance=10;
			duration=1;
			frequency=20;
			power=0;
		};
	};
	class FST_grenade_Detonator_ammo: GrenadeHand_stone
	{
		hit=40;
		indirectHit=30;
		indirectHitRange=10;
		dangerRadiusHit=80;
		suppressionRadiusHit=40;
		explosionEffectsRadius=30;
		explosionEffects="VehicleExplosionEffects";
		CraterEffects="MineNondirectionalCraterSmall";
		effectsSmoke="ACE_Incendiary";
		explosive=1;
		ace_frag_enabled=1;
		ace_frag_skip=0;
		ace_frag_force=1;
		ace_frag_classes[]=
		{
			"ace_frag_tiny_HD"
		};
		ace_frag_metal=210;
		ace_frag_charge=185;
		ace_frag_gurney_c=2843;
		ace_frag_gurney_k="3/5";
		model="Indecisive_Armoury_Ammos\Data\Thermal_Detonator\IDA_Thermal_Detonator.p3d";
		visibleFire=0.5;
		audibleFire=0.050000001;
		visibleFireTime=1;
		fuseDistance=0;
		ace_grenades_pullPinSound[]=
		{
			"Indecisive_Armoury_Sounds\Detonator_Pin.ogg",
			6,
			1,
			10
		};
		SoundSetExplosion[]=
		{
			"Mortar_Exp_SoundSet",
			"Mortar_Tail_SoundSet",
			"Explosion_Debris_SoundSet"
		};
		soundFly[]=
		{
			"Indecisive_Armoury_Sounds\Detonator_Timer.ogg",
			6,
			1,
			90
		};
	};
};
class CfgMagazines
{
	class HandGrenade;
	class FST_grenade_emp_mag: HandGrenade
	{
		scope=2;
		author="Adapted from JLTS";
		model="\MRC\JLTS\weapons\Grenades\grenade_emp.p3d";
		displayName="[41st] Droid Popper";
		picture="\MRC\JLTS\weapons\grenades\data\ui\grenade_emp_ui_ca.paa";
		descriptionShort="EMP Grenade";
		displayNameShort="[41st] Droid Popper";
		ammo="FST_grenade_emp_ammo";
	};
	class FST_grenade_Detonator_mag: HandGrenade
	{
		scope=2;
		author="Adapted from the Indecisive Armoury Team";
		picture="\Indecisive_Armoury_Ammos\Data\Thermal_Detonator\Thermal_Detonator_ui.paa";
		model="\Indecisive_Armoury_Ammos\Data\Thermal_Detonator\IDA_Thermal_Detonator.p3d";
		displayName="[41st] Thermal Detonator";
		displayNameShort="Thermal Detonator";
		descriptionShort="Thermal Detonator";
		ammo="FST_grenade_Detonator_ammo";
		mass=12;
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
			"FST_grenade_Detonator_muzzle"
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
	};
};
