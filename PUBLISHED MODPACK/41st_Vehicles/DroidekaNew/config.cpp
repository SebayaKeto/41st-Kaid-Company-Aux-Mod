class CfgPatches
{
	class FST_DroidekaNew
	{
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Armor_F_Beta"
		};
		units[]=
		{
			"FST_Droideka_New"
		};
		weapons[]={};
	};
};

class CfgVehicles
{
  class ls_droid_droideka_base;
  class FST_Droideka_New: ls_droid_droideka_base
  {
    displayname = "[41st] Droideka (Walking)";
    author = "Ruby";
    scope = 2;
    faction="FST_BattleDroids_Faction";
    editorSubcategory="FST_Ground_Vehicle";
    weapons[]=
    {
      "FST_Droideka_Cannon"
    };
    magazines[]=
    {
        "FST_blaster_battery_Droideka",
        "FST_blaster_battery_Droideka",
        "FST_blaster_battery_Droideka",
        "FST_blaster_battery_Droideka",
        "FST_blaster_battery_Droideka"
    };
  };
};
