class CfgPatches
{
	class FST_Engineer
	{
		requiredAddons[]=
		{
			"ace_fortify"
		};
		requiredVersion=0.1;
		units[]={};
		author="Ruby";
		weapons[]=
		{
			"ACE_FortifyToken";
		};
		magazines[]={};
		ammo[]={};
	};
};
class CfgWeapons {
    class ACE_ItemCore;
    class ACE_FortifyToken: ACE_ItemCore {
        scopeArsenal = 2;
        displayName = "[41st] Republic Engineer Tokens";
        picture = "\41st_Engineer\Data\RepublicToken.paa";
    };
};