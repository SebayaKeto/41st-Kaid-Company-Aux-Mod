class CfgPatches
{
	class FST_Outpost_LightWalls
	{
		author="Maldova";
		requiredAddons[]=
		{
			"A3_Structures_F_Exp_Civilian",
			"FST_Core",
			"FST_Common"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_OutpostWall_Unmarked",
			"FST_OutpostWall_GAR",
			"FST_OutpostWall_GAR_Woodland",
			"FST_OutpostWall_GAR_Sand",
			"FST_OutpostWall_GAR_Urban",
			"FST_OutpostWall_GAR_UrbanPropoganda",
			"FST_OutpostWall_GAR_FSTOne",
			"FST_OutpostWall_GAR_FSTTwo",
			"FST_OutpostWall_GAR_Jungle",
			"FST_OutpostWall_CIS"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class House;
	class House_F: House
	{
		class DestructionEffects;
	};
	class Ruins_F;
	class FST_OutpostWall_Base: House_F
	{
		editorCategory = "FST_CatagoryMajorOutpost";
		editorSubcategory = "FST_Subcategory_OutpostWallsNeutral";
		scope = 1;
		scopecurator = 1;
		placement = "vertical";
		mapSize = 1;
		destrType = "DestructNo";
		displayName = "Light Outpost Wall (Unmarked)";
		model = "FST\FST_Outpost\LightWalls\FST_OutpostWall_Light.p3d";
		hiddenSelections[]={"Camo","Camo1","Camo2","Camo3"};
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Unmarked_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3.rvmat"
		};
		faction = "prop";
		eden = 1;
	};
	// Base Asset and Texture
	class FST_OutpostWall_Unmarked: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall (Unmarked)";
	};
	class FST_OutpostWall_GAR: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall (GAR 1)";
		editorSubcategory = "FST_Subcategory_OutpostWallsGAR";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3.rvmat"
		};
	};
	class FST_OutpostWall_GAR_V2: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall (GAR 2)";
		editorSubcategory = "FST_Subcategory_OutpostWallsGAR";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_V2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3.rvmat"
		};
	};
	class FST_OutpostWall_GAR_Woodland: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall (Woodland)";
		editorSubcategory = "FST_Subcategory_OutpostWallsGAR";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Woodland_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3.rvmat"
		};
	};
	class FST_OutpostWall_GAR_Sand: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall (Sand)";
		editorSubcategory = "FST_Subcategory_OutpostWallsGAR";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Sand_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3.rvmat"
		};
	};
	class FST_OutpostWall_GAR_Urban: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall (Urban)";
		editorSubcategory = "FST_Subcategory_OutpostWallsGAR";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_UrbanOne_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3.rvmat"
		};
	};
	class FST_OutpostWall_GAR_UrbanPropoganda: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall (Urban Propoganda)";
		editorSubcategory = "FST_Subcategory_OutpostWallsGAR";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_UrbanTwo_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_UrbanTwo.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3.rvmat"
		};
	};
	class FST_OutpostWall_GAR_FSTOne: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall (Kaid)";
		editorSubcategory = "FST_Subcategory_OutpostWallsGAR";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_FSTOne_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3.rvmat"
		};
	};
	class FST_OutpostWall_GAR_FSTTwo: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall (Kaid Camo)";
		editorSubcategory = "FST_Subcategory_OutpostWallsGAR";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_FSTTwo_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3.rvmat"
		};
	};
	class FST_OutpostWall_GAR_Jungle: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall (Jungle)";
		editorSubcategory = "FST_Subcategory_OutpostWallsGAR";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Jungle_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3.rvmat"
		};
	};
	// CIS Assets
	class FST_OutpostWall_CIS: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall (CIS)";
		editorSubcategory = "FST_Subcategory_OutpostWallsCIS";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_CIS_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_CIS.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3.rvmat"
		};
	};
	// Minor Faction Assets
	class FST_OutpostWall_Pirate: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall (Pirate)";
		editorCategory = "FST_CatagoryMinorOutpost";
		editorSubcategory = "FST_Subcategory_OutpostWallsPirates";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Pirate_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Pirate_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Pirate.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3.rvmat"
		};
	};
	class FST_OutpostWall_BlackSun: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall (Black Sun)";
		editorCategory = "FST_CatagoryMinorOutpost";
		editorSubcategory = "FST_Subcategory_OutpostWallsBlackSun";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Pirate_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_BlackSun_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Pirate.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3.rvmat"
		};
	};
	class FST_OutpostWall_HuttCartel: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall (Hutt Cartel)";
		editorCategory = "FST_CatagoryMinorOutpost";
		editorSubcategory = "FST_Subcategory_OutpostWallsHuttCartel";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Hutt_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Hutt_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Pirate.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3.rvmat"
		};
	};
};
