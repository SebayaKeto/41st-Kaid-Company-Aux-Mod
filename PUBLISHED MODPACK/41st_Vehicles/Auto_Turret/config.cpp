class CfgPatches 
{
    class FST_AutoTurret
	{
		author = "Viz"
        units[] = 
		{
			"FST_AutoDefenseTurret", 
			"FST_AutoDefenseTurretCQC" 	
		};
        weapons[] = {
		};
        requiredAddons[] = 
		{
			"ls_weapons_core",
			"ls_vehicles_weapons",
			"A3_Weapons_F",
			"3AS_Weapons"
		};
        requiredVersion = 0.1;
    };
};

class CfgVehicles {
    class ls_turret_autoturret_base;

    class FST_AutoDefenseTurretCQC: ls_turret_autoturret_base {
        displayName = "Auto Defense Turret CQC (41st)";
        armor = 2000;
		scope = 2;
		scopeCurator = 2;
		editorCategory = "FST_BattleDroids_Faction";
		model="\ls_vehicles_turrets\AutoTurret\AutoTurret.p3d";
        weapons[] = 
		{
			"FST_DP23" 
		};
        magazines[] = 
		{
			"FST_blaster_scatter_cell" 
		};
        hiddenSelectionsTextures[] = 
		{
            "\ls_vehicles_turrets\AutoTurret\data\RoofRepeater_co.paa"
        };
        class Sounds {
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType 
			{
				weaponSoundEffect = "";
				begin1[] = {
					"\41st_vehicles\Auto_Turret\Data\dp23v1 2-177.ogg",
					2.2, // Slightly louder volume
					1, // Default pitch
					1800
				};
				begin2[] = {
					"\41st_vehicles\Auto_Turret\Data\dp23v1 2-177.ogg",
					2.2,
					1.01, // Slightly higher pitch
					1800
				};
				begin3[] = {
					"\41st_vehicles\Auto_Turret\Data\dp23v1 2-177.ogg",
					2.2,
					0.99, // Slightly lower pitch
					1800
				};
				begin4[] = {
					"\41st_vehicles\Auto_Turret\Data\dp23v1 2-177.ogg",
					2.2,
					1.02,
					1800
				};
				begin5[] = {
					"\41st_vehicles\Auto_Turret\Data\dp23v1 2-177.ogg",
					2.2,
					0.98,
					1800
				};
				soundBegin[] = {
					"begin1", 0.2,
					"begin2", 0.2,
					"begin3", 0.2,
					"begin4", 0.2,
					"begin5", 0.2
				};
				beginwater1[] = {
					"\41st_vehicles\Auto_Turret\Data\dp23v1 2-177.ogg",
					2.2,
					1,
					400
				};
				soundBeginWater[] = {
					"beginwater1", 1
				};
			};
        };
    };
    class FST_AutoDefenseTurret : ls_turret_autoturret_base {
        displayName = "Auto Defense Turret (41st)";
        armor = 2000;
		scope = 2;
		scopeCurator = 2;
		editorCategory = "FST_BattleDroids_Faction";
		model="\ls_vehicles_turrets\AutoTurret\AutoTurret.p3d";
        weapons[] = 
		{
			"FST_Z6"
		};
        magazines[] = 
		{
			"FST_blaster_battery_Red" 
		};
        hiddenSelectionsTextures[] = 
		{
            "\ls_vehicles_turrets\AutoTurret\data\RoofRepeater_co.paa"
        };
        class Sounds {
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType 
			{
				weaponSoundEffect = "";
				begin1[] = {
					"\41st_vehicles\Auto_Turret\Data\z6 -3-965 (1).ogg",
					1.8, // Slightly louder volume
					1, // Default pitch
					1800
				};
				begin2[] = {
					"\41st_vehicles\Auto_Turret\Data\z6 -3-965 (2).ogg",
					1.8,
					1.01, // Slightly higher pitch
					1800
				};
				begin3[] = {
					"\41st_vehicles\Auto_Turret\Data\z6 -3-965 (3).ogg",
					1.8,
					0.99, // Slightly lower pitch
					1800
				};
				begin4[] = {
					"\41st_vehicles\Auto_Turret\Data\z6 -3-965 (4).ogg",
					1.8,
					1.02,
					1800
				};
				begin5[] = {
					"\41st_vehicles\Auto_Turret\Data\z6 -3-965 (5).ogg",
					1.8,
					0.98,
					1800
				};
				soundBegin[] = {
					"begin1", 0.2,
					"begin2", 0.2,
					"begin3", 0.2,
					"begin4", 0.2,
					"begin5", 0.2
				};
				beginwater1[] = {
					"\41st_vehicles\Auto_Turret\Data\z6 -3-965.ogg",
					1.5,
					1,
					400
				};
				soundBeginWater[] = {
					"beginwater1", 1
				};
			};
        };
    };
};
