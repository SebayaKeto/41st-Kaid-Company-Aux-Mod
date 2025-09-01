class CfgPatches
{
	class FST_Munificent
	{
		author="Gold";
		requiredAddons[]={};
		weapons[]={};
		units[]={};
	};
};
class CfgEditorCategories
{
	class FST_Munificent_Category
	{
		displayname="[41st] Munificent";
		priority=8;
		side=7;
	};
};
class CfgEditorSubcategories
{
	class FST_Munificent_Category_S
	{
		displayName="41st Munificent Ships";
	};
};
class CfgVehicles
{
	class ls_staticShip_munificent;
	class FST_staticShip_munificent: ls_staticShip_munificent 
	{
    scope = 2;
    scopeCurator = 2;
    author = "Gold";
    displayName = "[41st] Munificent";
	editorcategory="FST_Munificent_Category";
	editorsubcategory="FST_Munificent_Category_S";
    hiddenSelections[] = 
	{
        "body1",
		"body2",
        "body3",
		"body4",
        "engine"
    };
    hiddenSelectionsTextures[] = 
	{
       "41st_Vehicles\Munificent\Data\FST_body1_Muni_Jorge_co.paa",
       "41st_Vehicles\Munificent\Data\FST_body2_Muni_Jorge_co.paa",
       "41st_Vehicles\Munificent\Data\FST_body3_Muni_Jorge_co.paa",
       "41st_Vehicles\Munificent\Data\FST_body4_Muni_Jorge_co.paa",
       "41st_Vehicles\Munificent\Data\FST_engine_Muni_Jorge_co.paa"
    };
};
};