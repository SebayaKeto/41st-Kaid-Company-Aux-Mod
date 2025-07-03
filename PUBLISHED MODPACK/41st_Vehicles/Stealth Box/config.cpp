class CfgPatches
{
	class FST_StealthBoxy
	{
		requiredAddons[]=
		{
			"A3_Armor_F_Beta",
			"A3_weapons_F",
			"A3_Data_F",
			"A3_Air_F"
		};
		units[]=
		{
            "FST_StealthBox"
        };
    };
};
class CfgVehicles
{
    class ls_vehicle_stealthbox_base;

    class FST_StealthBox: ls_vehicle_stealthbox_base
    {

        displayname="[41st] Stealth Box";
        author="Ruby inherted from LS."; 
        side=2;
        scope=2;
        crew="JLTS_Clone_P2_DC15S";
		faction="FST_Independent_Faction";
		editorSubcategory="FST_Ground_Vehicle";
    };
};