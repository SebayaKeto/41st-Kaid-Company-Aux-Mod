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
	class FST_Acclamator_Huntress_zeus: House_F
	{
		author="Gold";
		model="\ls\core\addons\props_staticships\acclamator\ls_acclamator.p3d";
		scope=2;
		scopecurator=2;
		editorpreview="";
		editorcategory="FST_Acclamator_Category";
		editorsubcategory="FST_Acclamator_Category_S";
		icon="iconObject_1x1";
		displayname="[41st] Acclamator Huntress (Zeus)";
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
			"41st_Vehicles\Acclamator\data\FST_Body_1_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_2_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_3_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_4_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_5_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_6_Huntress_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\engine_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\glass_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\interior_1_co.paa",
			"41st_Vehicles\Acclamator\data\FST_interior_2_co.paa",
			"41st_Vehicles\Acclamator\data\FST_interior_3_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\interior_4_co.paa"
		};
	};
	class FST_Acclamator_Huntress_base: FST_Acclamator_Huntress_zeus
	{
		author="Gold";
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
	class FST_Acclamator_Huntress_hollow: FST_Acclamator_Huntress_base
	{
		author = "Gold";
		displayName = "[41st] Acclamator Huntress (Hollow)";
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Acclamator\data\FST_Body_1_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_2_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_3_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_4_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_5_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_6_Huntress_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\engine_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\glass_co.paa"
		};
	};
	class FST_Acclamator_Huntress_landed: FST_Acclamator_Huntress_base
	{
		author = "Gold";
		displayName = "[41st] Acclamator Huntress Landed";
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Acclamator\data\FST_Body_1_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_2_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_3_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_4_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_5_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_6_Huntress_co.paa",
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
	class FST_Acclamator_Huntress_landed_hollow: FST_Acclamator_Huntress_base
	{
		author = "Gold";
		displayName = "[41st] Acclamator Huntress Landed (Hollow)";
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Acclamator\data\FST_Body_1_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_2_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_3_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_4_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_5_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_6_Huntress_co.paa",
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
	class FST_Acclamator_Huntress_landed_noRamp: FST_Acclamator_Huntress_base
	{
		author = "Gold";
		displayName = "[41st] Acclamator Huntress Landed (No Ramp)";
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Acclamator\data\FST_Body_1_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_2_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_3_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_4_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_5_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_6_Huntress_co.paa",
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
	class FST_Acclamator_Huntress_landed_hollow_noRamp: FST_Acclamator_Huntress_base
	{
		author = "Gold";
		displayName = "[41st] Acclamator Huntress Landed (Hollow, No Ramp)";
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Acclamator\data\FST_Body_1_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_2_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_3_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_4_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_5_Huntress_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_6_Huntress_co.paa",
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
	class FST_Acclamator_JorgeTrooper_zeus: House_F
	{
		author="Gold";
		model="\ls\core\addons\props_staticships\acclamator\ls_acclamator.p3d";
		scope=2;
		scopecurator=2;
		editorpreview="";
		editorcategory="FST_Acclamator_Category";
		editorsubcategory="FST_Acclamator_Category_S";
		icon="iconObject_1x1";
		displayname="[41st] Acclamator JorgeTrooper (Zeus)";
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
			"41st_Vehicles\Acclamator\data\FST_Body_1_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_2_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_3_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_4_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_5_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_6_JorgeTrooper_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\engine_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\glass_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\interior_1_co.paa",
			"41st_Vehicles\Acclamator\data\FST_interior_2_co.paa",
			"41st_Vehicles\Acclamator\data\FST_interior_3_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\interior_4_co.paa"
		};
	};
	class FST_Acclamator_JorgeTrooper_base: FST_Acclamator_JorgeTrooper_zeus
	{
		author="Gold";
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
	class FST_Acclamator_JorgeTrooper_hollow: FST_Acclamator_JorgeTrooper_base
	{
		author = "Gold";
		displayName = "[41st] Acclamator JorgeTrooper (Hollow)";
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Acclamator\data\FST_Body_1_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_2_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_3_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_4_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_5_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_6_JorgeTrooper_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\engine_co.paa",
			"\ls\core\addons\props_staticships\acclamator\data\glass_co.paa"
		};
	};
	class FST_Acclamator_JorgeTrooper_landed: FST_Acclamator_JorgeTrooper_base
	{
		author = "Gold";
		displayName = "[41st] Acclamator JorgeTrooper Landed";
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Acclamator\data\FST_Body_1_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_2_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_3_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_4_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_5_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_6_JorgeTrooper_co.paa",
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
	class FST_Acclamator_JorgeTrooper_landed_hollow: FST_Acclamator_JorgeTrooper_base
	{
		author = "Gold";
		displayName = "[41st] Acclamator JorgeTrooper Landed (Hollow)";
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Acclamator\data\FST_Body_1_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_2_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_3_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_4_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_5_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_6_JorgeTrooper_co.paa",
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
	class FST_Acclamator_JorgeTrooper_landed_noRamp: FST_Acclamator_JorgeTrooper_base
	{
		author = "Gold";
		displayName = "[41st] Acclamator JorgeTrooper Landed (No Ramp)";
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Acclamator\data\FST_Body_1_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_2_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_3_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_4_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_5_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_6_JorgeTrooper_co.paa",
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
	class FST_Acclamator_JorgeTrooper_landed_hollow_noRamp: FST_Acclamator_JorgeTrooper_base
	{
		author = "Gold";
		displayName = "[41st] Acclamator JorgeTrooper Landed (Hollow, No Ramp)";
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Acclamator\data\FST_Body_1_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_2_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_3_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_4_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_5_JorgeTrooper_co.paa",
			"41st_Vehicles\Acclamator\data\FST_Body_6_JorgeTrooper_co.paa",
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