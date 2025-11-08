#include "\FST\FST_MEC\mec_base_defines.hpp"

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
			"FST_MEC_Platform"
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
	class FST_MEC_Platform: House_F
	{
		editorCategory = "FST_MEC_CategoryStructures";
		editorSubcategory = "FST_MEC_SubcategoryPlatforms";
		author = MEC_AUTHOR;
		scope = 2;
		scopecurator = 2;
		placement = "vertical";
		mapSize = 1;
		destrType = "DestructNo";
		displayName = "[MEC] Simple Platform (White)";
		model = "P:\FST\FST_MEC\FST_MEC_Outpost\FST_MEC_Platform\FST_MEC_Platform.p3d";
		hiddenSelections[]={"Camo"};
		hiddenSelectionsTextures[]=
		{
			"FST\FST_MEC\FST_MEC_Outpost\FST_MEC_Platform\Data\Textures\Camo_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_MEC\FST_MEC_Outpost\FST_MEC_Platform\Data\Textures\Camo.rvmat"
		};
		armor = 1000;
		class SimpleObject
		{
			animate = "";
			hide = "";
			verticalOffset = 0;
			verticalOffsetWorld = 0;
			initPhase = 0;
		};
		eden = 1;
	};
	class FST_MEC_Platform_Republic: FST_MEC_Platform
	{
		author = MEC_AUTHOR;
		scope = 2;
		scopecurator = 2;
		displayName = "[MEC] Simple Platform (Republic)";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_MEC\FST_MEC_Outpost\FST_MEC_Platform\Data\Textures\Camo_Republic_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_MEC\FST_MEC_Outpost\FST_MEC_Platform\Data\Textures\Camo_Republic.rvmat"
		};
	};
	class FST_MEC_Platform_Senate: FST_MEC_Platform
	{
		author = MEC_AUTHOR;
		scope = 2;
		scopecurator = 2;
		displayName = "[MEC] Simple Platform (Senate)";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_MEC\FST_MEC_Outpost\FST_MEC_Platform\Data\Textures\Camo_Senate_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_MEC\FST_MEC_Outpost\FST_MEC_Platform\Data\Textures\Camo_Senate.rvmat"
		};
	};
	class FST_MEC_Platform_Factory: FST_MEC_Platform
	{
		author = MEC_AUTHOR;
		scope = 2;
		scopecurator = 2;
		displayName = "[MEC] Simple Platform (Company Logo)";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_MEC\FST_MEC_Outpost\FST_MEC_Platform\Data\Textures\Camo_MEC_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_MEC\FST_MEC_Outpost\FST_MEC_Platform\Data\Textures\Camo_MEC.rvmat"
		};
	};
	class FST_MEC_Platform_Orange: FST_MEC_Platform
	{
		author = MEC_AUTHOR;
		scope = 2;
		scopecurator = 2;
		displayName = "[MEC] Simple Platform (Orange)";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_MEC\FST_MEC_Outpost\FST_MEC_Platform\Data\Textures\Camo_Orange_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_MEC\FST_MEC_Outpost\FST_MEC_Platform\Data\Textures\Camo.rvmat"
		};
	};
	class FST_MEC_Platform_Blue: FST_MEC_Platform
	{
		author = MEC_AUTHOR;
		scope = 2;
		scopecurator = 2;
		displayName = "[MEC] Simple Platform (Blue)";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_MEC\FST_MEC_Outpost\FST_MEC_Platform\Data\Textures\Camo_Blue_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_MEC\FST_MEC_Outpost\FST_MEC_Platform\Data\Textures\Camo.rvmat"
		};
	};
	class FST_MEC_Platform_Black: FST_MEC_Platform
	{
		author = MEC_AUTHOR;
		scope = 2;
		scopecurator = 2;
		displayName = "[MEC] Simple Platform (Black)";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_MEC\FST_MEC_Outpost\FST_MEC_Platform\Data\Textures\Camo_Black_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_MEC\FST_MEC_Outpost\FST_MEC_Platform\Data\Textures\Camo.rvmat"
		};
	};
	class FST_MEC_Platform_FST: FST_MEC_Platform
	{
		author = MEC_AUTHOR;
		scope = 2;
		scopecurator = 2;
		displayName = "[MEC] Simple Platform (FST)";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_MEC\FST_MEC_Outpost\FST_MEC_Platform\Data\Textures\Camo_FST_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_MEC\FST_MEC_Outpost\FST_MEC_Platform\Data\Textures\Camo_Republic.rvmat"
		};
	};
};

