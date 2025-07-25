class CfgPatches
{
	class FST_Datapad
	{
		requiredAddons[]=
		{
			"3AS_Weapons"
		};
		requiredVersion=0.1;
		units[]={};
		author="Gold";
		weapons[]={};
		magazines[]={};
		ammo[]={};
	};
};
class CfgWeapons
{
	class 3AS_RepublicDatapadPistol;
	class FST_RepublicDatapad_Tooka: 3AS_RepublicDatapadPistol
	{
		scope=2;
		displayName="[FST] Republic Datapad (Tooka)";
		model="\3AS\3AS_Weapons\Roleplay\RepublicDatapadpistol.p3d";
		picture="\3AS\3AS_Weapons\Roleplay\data\UI\3as_datapad.paa";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Weapons\Datapad\Data\FST_Datapad_TookaPad.paa"
		};
	};
};