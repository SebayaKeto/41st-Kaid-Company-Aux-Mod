/* class CfgPatches 
{
    class FST_AutoTurret
	{
		author = "Viz";
        units[] = 
		{
			"FST_AutoDefenseTurret", 
			"FST_AutoDefenseTurretCQC" 	
		};
        weapons[] = {};
        requiredAddons[] = 
		{
			"41st_Addon",
			"ls_vehicles_weapons",
			"A3_Weapons_F",
			"3AS_Weapons"
		};
        requiredVersion = 0.1;
    };
};

class CfgVehicles {
	class LandVehicle;
	class StaticWeapon: LandVehicle
	{
		class Turrets
		{
			class MainTurret;
		};
	};
	class StaticMGWeapon: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics;
			};
		};
	};
    class ls_turret_autoturret_base:StaticMGWeapon{};
	
	class FST_AutoDefenseTurret : ls_turret_autoturret_base {
		author ="Viz";
        displayName = "Auto Defense Turret (41st)";
        armor = 2000;
		scope = 2;
		scopeCurator = 2;
		crew="O_UAV_AI";
		side=0;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		model="\ls\core\addons\vehicles_mrbc\ls_turret_autoturret.p3d";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = 
				{
					"FST_Z6"
				};
				magazines[]=
				{
					"FST_blaster_battery_Red",
					"FST_blaster_battery_Red",
					"FST_blaster_battery_Red",
					"FST_blaster_battery_Red",
					"FST_blaster_battery_Red"
				};
				minElev = -30;
				maxElev = 80;
			};
		};
        hiddenSelectionsTextures[] = 
		{
			"\ls\core\addons\vehicles_mrbc\data\autoturret\camo1_co.paa"
        };
    };

    class FST_AutoDefenseTurretCQC: ls_turret_autoturret_base 
	{
		author = "Viz";
        displayName = "Auto Defense Turret CQC (41st)";
        armor = 2000;
		scope = 2;
		scopeCurator = 2;
		crew="O_UAV_AI";
		side=0;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		model="\ls\core\addons\vehicles_mrbc\ls_turret_autoturret.p3d";
        class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[]=
				{
					"FST_DP23"
				};
				magazines[]=
				{
					"FST_blaster_scatter_cell_DP23_Red",
					"FST_blaster_scatter_cell_DP23_Red",
					"FST_blaster_scatter_cell_DP23_Red",
					"FST_blaster_scatter_cell_DP23_Red",
					"FST_blaster_scatter_cell_DP23_Red"
				};
				minElev = -30;
				maxElev = 80;
			};
		};
        hiddenSelectionsTextures[] = 
		{
            "\ls\core\addons\vehicles_mrbc\data\autoturret\camo1_co.paa"
        };
        class AnimationSources
		{
			class Revolving
			{
				source="revolving";
				weapon="FST_DP23";
			};
			class muzzle_source
			{
				source="reload";
				weapon="FST_DP23";
			};
			class muzzleflash
			{
				source="reload";
				weapon="FST_DP23";
			};
			class muzzle_source_rot
			{
				source="ammorandom";
				weapon="FST_DP23";
			};
			class minigun
			{
				source="revolving";
				weapon="FST_DP23";
			};
		};
    };  
};
 */