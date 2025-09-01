class CfgPatches
{
	class FST_Providence
	{
		author="Gold";
		requiredAddons[]={};
		weapons[]={};
		units[]=
		{
		};
	};
};
class CfgEditorCategories
{
	class FST_Providence_Category
	{
		displayname="[41st] Providence";
		priority=8;
		side=7;
	};
};
class CfgEditorSubcategories
{
	class FST_Providence_Category_P
	{
		displayName="41st Providence Parts";
	};
	class FST_Providence_Category_S
	{
		displayName="41st Providence Ships";
	};
};
class CfgVehicles
{
	class ls_staticShip_providence;
	class FST_staticShip_providence_Jorge: ls_staticShip_providence 
	{
		scope = 2;
		scopeCurator = 2;
		author = "Gold";
		displayName = "[41st] Jorge Providence-Class";
		editorcategory="FST_Providence_Category";
		editorsubcategory="FST_Providence_Category_S";
		multiStructureParts[] = 
		{
			{"FST_staticShipPart_providence_body1_Jorge", "body1"},
			{"FST_staticShipPart_providence_body2_Jorge", "body2"},
			{"FST_staticShipPart_providence_body3_Jorge", "body3"},
			{"FST_staticShipPart_providence_bridge_Jorge", "bridge"},
			{"FSt_staticShipPart_providence_engine_Jorge", "engine"},
			{"ls_staticShipPart_providence_interior", "interior"}
		};
	};
	class ls_staticShip_providence_hollow;
	class FST_staticShip_providence_hollow_Jorge: ls_staticShip_providence_hollow 
	{
		author = "Gold";
		displayname = "[41st] Jorge Providence-Class (Hollowed)";
		editorcategory="FST_Providence_Category";
		editorsubcategory="FST_Providence_Category_S";
		multiStructureParts[] = 
		{
			{"FST_staticShipPart_providence_body1_Jorge", "body1"},
			{"FST_staticShipPart_providence_body2_Jorge", "body2"},
			{"FST_staticShipPart_providence_body3_Jorge", "body3"},
			{"FST_staticShipPart_providence_bridge_Jorge", "bridge"},
			{"FST_staticShipPart_providence_engine_Jorge", "engine"}
		};
	};
	class ls_staticShip_providence_dreadnought;
	class FST_staticShip_providence_dreadnought_Jorge: ls_staticShip_providence_dreadnought 
	{
		author = "Gold";
		displayName = "[41st] Jorge Providence-Class Dreadnought";
		editorcategory="FST_Providence_Category";
		editorsubcategory="FST_Providence_Category_S";
		multiStructureParts[] = 
		{
			{"FST_staticShipPart_providence_body1_dreadnought_Jorge", "body1"},
			{"FST_staticShipPart_providence_body2_dreadnought_Jorge", "body2"},
			{"FST_staticShipPart_providence_body3_dreadnought_Jorge", "body3"},
			{"FST_staticShipPart_providence_bridge_dreadnought_Jorge", "bridge"},
			{"FST_staticShipPart_providence_engine_dreadnought_Jorge", "engine"},
			{"ls_staticShipPart_providence_interior_dreadnought", "interior"}
		};
	};
	class ls_staticShip_providence_dreadnought_hollow;
	class FST_staticShip_providence_dreadnought_hollow_Jorge: ls_staticShip_providence_dreadnought_hollow 
	{
		author = "Gold";
		displayName = "[41st] Jorge Providence-Class Dreadnought (Hollowed)";
		editorcategory="FST_Providence_Category";
		editorsubcategory="FST_Providence_Category_S";
		multiStructureParts[] = 
		{
			{"FST_staticShipPart_providence_body1_dreadnought_Jorge", "body1"},
			{"FST_staticShipPart_providence_body2_dreadnought_Jorge", "body2"},
			{"FST_staticShipPart_providence_body3_dreadnought_Jorge", "body3"},
			{"FST_staticShipPart_providence_bridge_dreadnought_Jorge", "bridge"},
			{"FST_staticShipPart_providence_engine_dreadnought_Jorge", "engine"}
		};
	};
	class ls_staticShipPart_providence_body1;
	class FST_staticShipPart_providence_body1_Jorge: ls_staticShipPart_providence_body1
	{
		scope = 2;
		scopeCurator = 2;
		author = "Gold";
		displayName = "[41st] Jorge Body 1";
		editorcategory="FST_Providence_Category";
		editorSubcategory = "FST_Providence_Category_P";
		hiddenSelections[] = 
		{
			"body1"
		};
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Providence\Data\FST_body1_Jorge_Prov_co.paa"
		};
	};
	class ls_staticShipPart_providence_body1_dreadnought;
	class FST_staticShipPart_providence_body1_dreadnought_Jorge: ls_staticShipPart_providence_body1_dreadnought 
	{
		author = "Gold";
		displayName = "[41st] Jorge Body 1 (Dreadnought)";
		editorcategory="FST_Providence_Category";
		editorSubcategory = "FST_Providence_Category_P";
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Providence\Data\FST_body1_Jorge_Prov_co.paa"
		};
	};
	class ls_staticShipPart_providence_body2;
	class FST_staticShipPart_providence_body2_Jorge: ls_staticShipPart_providence_body2 
	{
		author = "Gold";
		displayName = "[41st] Jorge Body 2";
		editorcategory="FST_Providence_Category";
		editorSubcategory = "FST_Providence_Category_P";
		hiddenSelections[] = 
		{
			"body2"
		};
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Providence\Data\FST_body2_Jorge_Prov_co.paa"
		};
	};
	class ls_staticShipPart_providence_body2_dreadnought;
	class FST_staticShipPart_providence_body2_dreadnought_Jorge: ls_staticShipPart_providence_body2_dreadnought 
	{
		author = "Gold";
		displayName = "[41st] Jorge Body 2 (Dreadnought)";
		editorcategory="FST_Providence_Category";
		editorSubcategory = "FST_Providence_Category_P";
		hiddenSelections[] = 
		{
			"body2"
		};
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Providence\Data\FST_body2_Jorge_Prov_co.paa"
		};
	};
	class ls_staticShipPart_providence_body3;
	class FST_staticShipPart_providence_body3_Jorge: ls_staticShipPart_providence_body3
	{
		author = "Gold";
		displayName = "[41st] Jorge Body 3";
		editorcategory="FST_Providence_Category";
		editorSubcategory = "FST_Providence_Category_P";
		hiddenSelections[] = 
		{
			"body3"
		};
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Providence\Data\FST_body3_Jorge_Prov_co.paa"
		};
	};
	class ls_staticShipPart_providence_body3_dreadnought;
	class FST_staticShipPart_providence_body3_dreadnought_Jorge: ls_staticShipPart_providence_body3_dreadnought 
	{
		author = "Gold";
		displayName = "[41st] Jorge Body 3 (Dreadnought)";
		editorcategory="FST_Providence_Category";
		editorSubcategory = "FST_Providence_Category_P";
		hiddenSelections[] =
		{
			"body3"
		};
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Providence\Data\FST_body3_Jorge_Prov_co.paa"
		};
	};
	class ls_staticShipPart_providence_bridge;
	class FST_staticShipPart_providence_bridge_Jorge: ls_staticShipPart_providence_bridge 
	{
		author = "Gold";
		displayName = "[41st] Jorge Bridge";
		editorcategory="FST_Providence_Category";
		editorSubcategory = "FST_Providence_Category_P";
		hiddenSelections[] = 
		{
			"bridge"
		};
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Providence\Data\FST_bridge_Jorge_Prov_co.paa"
		};
	};
	class ls_staticShipPart_providence_bridge_dreadnought; 
	class FST_staticShipPart_providence_bridge_dreadnought_Jorge: ls_staticShipPart_providence_bridge_dreadnought 
	{
		author = "Gold";
		displayName = "[41st] Jorge Bridge (Dreadnought)";
		editorcategory="FST_Providence_Category";
		editorSubcategory = "FST_Providence_Category_P";
		hiddenSelections[] = 
		{
			"bridge"
		};
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Providence\Data\FST_bridge_Jorge_Prov_co.paa"
		};
	};
	class ls_staticShipPart_providence_engine;
	class FST_staticShipPart_providence_engine_Jorge: ls_staticShipPart_providence_engine 
	{
		author = "Gold";
		displayName = "[41st] Jorge Engine";
		editorcategory="FST_Providence_Category";
		editorSubcategory = "FST_Providence_Category_P";
		hiddenSelections[] = 
		{
			"engine"
		};
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Providence\Data\FST_engine_Jorge_Prov_co.paa"
		};
	};
	class ls_staticShipPart_providence_engine_dreadnought;
	class FST_staticShipPart_providence_engine_dreadnought_Jorge: ls_staticShipPart_providence_engine_dreadnought
	{
		author = "Gold";
		displayName = "[41st] Jorge Engine (Dreadnought)";
		editorcategory="FST_Providence_Category";
		editorSubcategory = "FST_Providence_Category_P";
		hiddenSelections[] = 
		{
			"engine"
		};
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Providence\Data\FST_engine_Jorge_Prov_co.paa"
		};
	};
	class ls_staticShip_providence_zeus;
	class FST_staticShip_providence_zeus_Jorge: ls_staticShip_providence_zeus 
	{
		scope = 2;
		scopeCurator = 2;
		author = "Gold";
		displayname = "[41st] Jorge Providence-Class (Zeus)";
		editorpreview="";
		editorcategory="FST_Providence_Category";
		editorsubcategory="FST_Providence_Category_S";
		icon="iconObject_1x1";
		hiddenSelections[] = 
		{
			"body1",
			"body2",
			"body3",
			"bridge",
			"engine",
			"interior"
		};
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Providence\Data\FST_body1_Jorge_Prov_co.paa",
			"41st_Vehicles\Providence\Data\FST_body2_Jorge_Prov_co.paa",
			"41st_Vehicles\Providence\Data\FST_body3_Jorge_Prov_co.paa",
			"41st_Vehicles\Providence\Data\FST_bridge_Jorge_Prov_co.paa",
			"41st_Vehicles\Providence\Data\FST_engine_Jorge_Prov_co.paa",
			"ls_core_props_staticships\providence\data\interior_co.paa"
		};
	};
	class ls_staticShip_providence_dreadnought_zeus;
	class FST_staticShip_providence_dreadnought_zeus_Jorge: ls_staticShip_providence_dreadnought_zeus 
	{
		scope = 2;
		scopeCurator = 2;
		author = "Gold";
		displayname = "[41st] Jorge Providence-Class Dreadnought (Zeus)";
		editorpreview="";
		editorcategory="FST_Providence_Category";
		editorsubcategory="FST_Providence_Category_S";
		icon="iconObject_1x1";
		hiddenSelections[] = 
		{
			"body1",
			"body2",
			"body3",
			"bridge",
			"engine",
			"interior"
		};
		hiddenSelectionsTextures[] = 
		{
			"41st_Vehicles\Providence\Data\FST_body1_Jorge_Prov_co.paa",
			"41st_Vehicles\Providence\Data\FST_body2_Jorge_Prov_co.paa",
			"41st_Vehicles\Providence\Data\FST_body3_Jorge_Prov_co.paa",
			"41st_Vehicles\Providence\Data\FST_bridge_Jorge_Prov_co.paa",
			"41st_Vehicles\Providence\Data\FST_engine_Jorge_Prov_co.paa",
			"ls_core_props_staticships\providence\data\interior_co.paa"
		};
	};
};