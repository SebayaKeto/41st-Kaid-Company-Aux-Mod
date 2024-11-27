class CfgPatches
{
	class FST_weapons_E60AA
	{
		author="Daara";
		name="41st E60 AA";
		requiredAddons[]=
		{
			"A3_data_f",
			"A3_weapons_f",
			"A3_characters_f"
		};
		weapons[]=
		{
			"FST_E60R_AA"
		};
		units[]=
		{
			"FST_GH_E60R1_AA"
		};
		magazines[]={};
	};
};
class CfgMagazines
{
	class Titan_AA;
	class FST_E60R_AA_mag: Titan_AA
	{
		JLTS_hasElectronics=1;
		JLTS_hasEMPProtection=1;
		author="Daara";
		displayName="[41st] E60 AA Magazine";
		descriptionShort="E60 AA Missile";
		ammo="FST_Stormfury_High_Velocity_Missile";
	};
};
class CfgWeapons
{
	class launch_Titan_base;
	class launch_Titan_short_base: launch_Titan_base
	{
		class WeaponSlotsInfo;
	};
	class FST_E60R_AA: launch_Titan_short_base
	{
		JLTS_hasElectronics=1;
		JLTS_hasEMPProtection=1;
		JLTS_friedItem="";
		author="Daara";
		scope=2;
		displayName="[41st] E60R AA Launcher";
		descriptionShort="$STR_JLTS_descs_PortableMissileLauncher";
		picture="\MRC\JLTS\weapons\E60R\data\ui\E60R_ui_ca.paa";
		uiPicture="MRC\JLTS\weapons\E60R\data\ui\E60R_ui_ca.paa";
		model="\MRC\JLTS\weapons\E60R\E60R.p3d";
		modelSpecial="";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\MRC\JLTS\weapons\E60R\anims\E60R_handanim.rtm"
		};
		hiddenSelections[]=
		{
			"camo1",
			"illum"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\weapons\E60R\data\E60R_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"\a3\characters_f_bootcamp\common\data\vrarmoremmisive.rvmat"
		};
		magazines[]=
		{
			"FST_E60R_AA_mag",
		};
		magazineWell[]={};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=154;
		};
	};
};
class CfgVehicles
{
	class Weapon_Base_F;
	class FST_GH_E60R1_AA: Weapon_Base_F
	{
		author="Daara";
		displayName="[41st] E60R AA Launcher";
		scope=2;
		class TransportWeapons
		{
			class FST_E60R_AA
			{
				count=1;
				weapon="FST_E60R_AA";
			};
		};
		class TransportMagazines
		{
			class FST_E60R_AA_mag
			{
				count=1;
				magazine="FST_E60R_AA_mag";
			};
		};
	};
};
