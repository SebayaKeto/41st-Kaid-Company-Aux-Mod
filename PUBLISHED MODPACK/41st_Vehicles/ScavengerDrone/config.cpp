class CfgPatches
{
	class FST_ScavDrone
	{
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Soft_F",
			"3AS_Drones"
		};
		units[]=
		{
			"FST_ScavDrone"
		};
		weapons[]={};
	};
};

class CfgVehicles
{
	class Helicopter;
	class Helicopter_Base_F: Helicopter
	{
		class Turrets;
	};
	class ScavBase: Helicopter_Base_F
	{
        class Turrets: Turrets
		{
			class MainTurret;
		};
    };

    class FST_ScavDrone: ScavBase
    {
        scope = 2
        author = "Ruby";
        displayname = "[41st] Scavenger Drone";
        side = 0
        faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
        hiddenSelections[]=
		{
			"camo"
		};
		hiddenselectionsTextures[]=
		{
			"3as\3as_drones\data\ScavDroid\CIS_Scav_CO.paa"
		};
        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                weapons[] = 
                {
                    "FST_E5"
                };
                magazines[] =
                {
                   	"FST_Droid_blaster_cell_red",
                    "FST_Droid_blaster_cell_red",
                    "FST_Droid_blaster_cell_red",
                    "FST_Droid_blaster_cell_red",
                    "FST_Droid_blaster_cell_red",
                    "FST_Droid_blaster_cell_red",
                };
            };
        };
    };
};