class CfgPatches
{
	class FST_Tukata
	{
		author="Gold";
		units[]={};
		weapons[]={};
		requiredVersion=;
		requiredAddons[]=
		{
			"A3_Characters_F",
			"JMSLLTE_merc_helm_mod"
		};
	};
};
class cfgWeapons
{
	class JMSLLTE_MercSphere_red_helmet;
	class FST_MercSphere_Tukata_helmet: JMSLLTE_MercSphere_red_helmet
	{
		scope=2;
		author="Gold";
		displayName="[41st] Commando sphere (red)";
		picture="\JMSLLTE_merc\helmets\data\ico\ico_h_BhSp_red.paa";
		hiddenSelectionsTextures[]=
		{
			"41st_Tukata\Data\Helmets\FST_MercSphere_Tukata_co.paa"
		};
	};
};	