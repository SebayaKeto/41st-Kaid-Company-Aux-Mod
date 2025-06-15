class CfgPatches
{
	class FST_Acclamator
	{
		requiredAddons[]={};
		weapons[]={};
		units[]=
		{
			"FST_Acclamator_zeus",
			"FST_Acclamator_base",
			"FST_Acclamator_hollow",
			"FST_Acclamator_landed",
			"FST_Acclamator_landed_hollow",
			"FST_Acclamator_landed_noRamp",
			"FST_Acclamator_landed_hollow_noRamp"
		};
		author="Viz";
	};
};
class Eventhandlers;
class CfgVehicles
{
	class StaticShip;
	class House_F;
	class FST_Acclamator_zeus: House_F
	{
		author="Viz";
		model="\ls\core\addons\props_staticships\acclamator\ls_acclamator.p3d";
		scope=2;
		scopecurator=2;
		editorpreview="";
		editorcategory="FST_Acclamator_Category";
		editorsubcategory="FST_Acclamator_Category_S";
		icon="iconObject_1x1";
		displayname="[41st] Acclamator (Zeus)";
		hiddenselections[]=
		{
			"body_1",
			"body_2",
			"body_3",
			"body_4",
			"body_5",
			"body_6",
			"engine",
			"glass",
			"interior_1",
			"interior_2",
			"interior_3",
			"interior_4",
			"landing_feet",
			"landing_legs",
			"ramp"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Acclamator\data\FST_body_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_2_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_3_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_4_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_5_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_6_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\engine_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\glass_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\interior_1_co.paa",
			"41st_Vehicles\Acclamator\data\FST_interior_2_co.paa",
			"41st_Vehicles\Acclamator\data\FST_interior_3_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\interior_4_co.paa"
		};
	};
	class FST_Acclamator_base: FST_Acclamator_zeus
	{
		author="Viz";
		model="\ls\core\addons\props_staticships\acclamator\ls_acclamator.p3d";
		reversed=0;
		scope=2;
		scopecurator=1;
		editorpreview="";
		editorcategory="FST_Acclamator_Category";
		editorsubcategory="FST_Acclamator_Category_S";
		vehicleClass="Structures_Military";
		icon="iconObject_1x1";
		displayname="[41st] Acclamator";
		mapsize=1326;
		destrType=0;
		featureType=2;
	};
	class FST_Acclamator_hollow: FST_Acclamator_base {
		author = "Viz";
		displayName = "[41st] Acclamator (Hollow)";
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Acclamator\data\FST_body_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_2_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_3_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_4_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_5_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_6_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\engine_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\glass_co.paa"
		};
	};
	class FST_Acclamator_landed: FST_Acclamator_base {
		author = "Viz";
		displayName = "[41st] Acclamator Landed";
		hiddenSelectionsTextures[] = {
			"41st_Vehicles\Acclamator\data\FST_body_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_2_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_3_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_4_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_5_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_6_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\engine_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\glass_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\interior_1_co.paa",
			"41st_Vehicles\Acclamator\data\FST_interior_2_co.paa",
			"41st_Vehicles\Acclamator\data\FST_interior_3_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\interior_4_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\landing_feet_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\landing_legs_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\ramp_co.paa"
		};
	};
	class FST_Acclamator_landed_hollow: FST_Acclamator_base {
		author = "Viz";
		displayName = "[41st] Acclamator Landed (Hollow)";
		hiddenSelectionsTextures[] = {
			"41st_Vehicles\Acclamator\data\FST_body_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_2_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_3_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_4_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_5_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_6_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\engine_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\glass_co.paa",
			"",
			"",
			"",
			"",
			"\ls\core\addons\props_staticships\acclamator\data\landing_feet_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\landing_legs_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\ramp_co.paa"
		};
	};
	class FST_Acclamator_landed_noRamp: FST_Acclamator_base {
		author = "Viz";
		displayName = "[41st] Acclamator Landed (No Ramp)";
		hiddenSelectionsTextures[] = {
			"41st_Vehicles\Acclamator\data\FST_body_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_2_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_3_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_4_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_5_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_6_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\engine_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\glass_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\interior_1_co.paa",
			"41st_Vehicles\Acclamator\data\FST_interior_2_co.paa",
			"41st_Vehicles\Acclamator\data\FST_interior_3_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\interior_4_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\landing_feet_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\landing_legs_co.paa"
		};
	};
	class FST_Acclamator_landed_hollow_noRamp: FST_Acclamator_base {
		author = "Viz";
		displayName = "[41st] Acclamator Landed (Hollow, No Ramp)";
		hiddenSelectionsTextures[] = {
			"41st_Vehicles\Acclamator\data\FST_body_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_2_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_3_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_4_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_5_co.paa",
			"41st_Vehicles\Acclamator\data\FST_body_6_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\engine_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\glass_co.paa",
			"",
			"",
			"",
			"",
			"\ls\core\addons\props_staticships\acclamator\data\landing_feet_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\landing_legs_co.paa"
		};
	};
};