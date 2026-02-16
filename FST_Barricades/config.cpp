class CfgPatches
{
	class FST_Barricades_SecurityBarrier
	{
		author="Maldova";
		requiredAddons[]=
		{
			"A3_Structures_F_Exp_Civilian",
			"FST_Core"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_Barricade_SecurityBarrier",
			"FST_Barricade_SecurityBarrier_Factory",
			"FST_Barricade_SecurityBarrier_Sand",
			"FST_Barricade_SecurityBarrier_Tundra",
			"FST_Barricade_SecurityBarrier_Jungle",
			"FST_Barricade_FerocreteBarrier_Small"
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
	class FST_Barricade_SecurityBarrier_Base: House_F
	{
		editorCategory = "FST_CatagoryBarricades";
		editorSubcategory = "FST_Subcategory_SecurityBarricades";
		scope = 1;
		scopecurator = 1;
		placement = "vertical";
		mapSize = 1;
		destrType = "DestructNo";
		displayName = "[41st] Security Barrier";
		model = "FST\FST_Barricades\41st_SecurityBarrier.p3d";
		faction = "prop";
		eden = 1;
	};
	// Base Asset and Texture
	class FST_Barricade_SecurityBarrier: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier";
		hiddenSelections[] = {"Camo1","Plasteel", "Steel"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat"};
	};
	class FST_Barricade_SecurityBarrier_Factory: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier (Factory)";
		hiddenSelections[] = {"Camo1","Plasteel", "Steel"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_Factory_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_Factory_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat"};
	};
	//Camo Colors
	class FST_Barricade_SecurityBarrier_Sand: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier (Sand)";
		hiddenSelections[] = {"Camo1","Plasteel", "Steel"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_Sand_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_Sand_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat"};
	};
	class FST_Barricade_SecurityBarrier_Tundra: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier (Tundra)";
		hiddenSelections[] = {"Camo1","Plasteel", "Steel"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_Tundra_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_Tundra_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat"};
	};
	class FST_Barricade_SecurityBarrier_Jungle: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier (Jungle)";
		hiddenSelections[] = {"Camo1","Plasteel", "Steel"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_JungleOvergrown_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_JungleOvergrown_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat"};
	};
	class FST_Barricade_FerocreteBarrier_Base: House_F
	{
		editorCategory = "FST_CatagoryBarricades";
		editorSubcategory = "FST_Subcategory_SecurityBarricades";
		scope = 1;
		scopecurator = 1;
		placement = "vertical";
		mapSize = 1;
		destrType = "DestructNo";
		displayName = "[41st] Ferocrete Barrier (Small)";
		model = "FST\FST_Barricades\Republic_SmallConcreteBarricade.p3d";
		faction = "prop";
		eden = 1;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\TrimSheets\Republic_ConcreteTrimsheet_01_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\TrimSheets\Republic_ConcreteTrimsheet_01.rvmat"};
	};
	class FST_Barricade_FerocreteBarrier_Small: FST_Barricade_FerocreteBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
	};
	class FST_Barricade_FerocreteBarrier_Corner: FST_Barricade_FerocreteBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Ferocrete Barrier (Corner)";
		model = "FST\FST_Barricades\Republic_CornerConcreteBarricade.p3d";
	};
};
class cfgFunctions
{
	class FST_Barricades
	{
		tag = "FST";

		class Scripts
		{
			file = "FST\FST_Barricades\Functions";

			class toggleShield{};
		};
	};
};