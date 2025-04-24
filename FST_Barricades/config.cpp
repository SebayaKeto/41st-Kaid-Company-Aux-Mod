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
			"FST_Barricade_SecurityBarrier_Inverted",
			"FST_Barricade_SecurityBarrier_Sand",
			"FST_Barricade_SecurityBarrier_Woodland",
			"FST_Barricade_SecurityBarrier_Tundra",
			"FST_Barricade_SecurityBarrier_Arid",
			"FST_Barricade_SecurityBarrier_Urban",
			"FST_Barricade_SecurityBarrier_Jungle",
			"FST_Barricade_SecurityBarrier_Command",
			"FST_Barricade_SecurityBarrierShieldWide",
			"FST_Barricade_SecurityBarrierShieldTowerTop"
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
		hiddenSelections[] = {"Camo1","Plasteel", "Plasteel", "Camo1Low"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrierLow_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrierLow.rvmat"};
	};
	// Overgrown Base Variation
	class FST_Barricade_SecurityBarrier_Overgrown: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier (Overgrown)";
		hiddenSelections[] = {"Camo1","Plasteel", "Plasteel", "Camo1Low"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_Overgrown_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_Overgrown_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrierLow_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrierLow.rvmat"};
	};
	//Inverted Colors
	class FST_Barricade_SecurityBarrier_Inverted: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier (Inverted)";
		hiddenSelections[] = {"Camo1","Plasteel", "Plasteel", "Camo1Low"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_41stInverted_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_41stInverted_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrierLow_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrierLow.rvmat"};
	};
	//Camo Colors
	class FST_Barricade_SecurityBarrier_Sand: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier (Sand)";
		hiddenSelections[] = {"Camo1","Plasteel", "Plasteel", "Camo1Low"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_Sand_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_Sand_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrierLow_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrierLow.rvmat"};
	};
	class FST_Barricade_SecurityBarrier_Woodland: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier (Woodland)";
		hiddenSelections[] = {"Camo1","Plasteel", "Plasteel", "Camo1Low"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_Woodland_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_Woodland_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrierLow_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrierLow.rvmat"};
	};
	class FST_Barricade_SecurityBarrier_Tundra: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier (Tundra)";
		hiddenSelections[] = {"Camo1","Plasteel", "Plasteel", "Camo1Low"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_Tundra_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_Tundra_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrierLow_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrierLow.rvmat"};
	};
	class FST_Barricade_SecurityBarrier_Arid: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier (Arid)";
		hiddenSelections[] = {"Camo1","Plasteel", "Plasteel", "Camo1Low"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_Arid_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_Arid_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrierLow_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrierLow.rvmat"};
	};
	class FST_Barricade_SecurityBarrier_Urban: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier (Urban)";
		hiddenSelections[] = {"Camo1","Plasteel", "Plasteel", "Camo1Low"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_Urban_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_Urban_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrierLow_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrierLow.rvmat"};
	};
	class FST_Barricade_SecurityBarrier_Jungle: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier (Jungle)";
		hiddenSelections[] = {"Camo1","Plasteel", "Plasteel", "Camo1Low"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_JungleOvergrown_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_JungleOvergrown_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrierLow_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrierLow.rvmat"};
	};
	// Specialized Textures
	class FST_Barricade_SecurityBarrier_Command: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier (Command)";
		hiddenSelections[] = {"Camo1","Plasteel", "Plasteel", "Camo1Low"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_Command_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_Command_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrierLow_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrierLow.rvmat"};
	};
	// Shielded Security Barricade
	class FST_Barricade_SecurityBarrierShieldWide_Base: FST_Barricade_SecurityBarrier_Base
	{
		displayName = "[41st] Security Barrier (Shield)";
		model = "FST\FST_Barricades\41st_SecurityBarrierShieldWide.p3d";
	};
	class FST_Barricade_SecurityBarrierShieldWide: FST_Barricade_SecurityBarrierShieldWide_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Shielded Security Barrier";
		hiddenSelections[] = {"Camo1","Plasteel", "Shield"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrierShield_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Common\Data\Textures\Shield\BlueShield_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrierShield.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Common\Data\Textures\Shield\Shield.rvmat"};
	};
	//Tower Top W/ Shield No Ladder
	class FST_Barricade_SecurityBarrierShieldTowerTop_Base: FST_Barricade_SecurityBarrier_Base
	{
		displayName = "[41st] Security Barrier (Shield)";
		model = "FST\FST_Barricades\41st_SecurityTowerTopNoLadder.p3d";
	};
	class FST_Barricade_SecurityBarrierShieldTowerTop: FST_Barricade_SecurityBarrierShieldTowerTop_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Shielded Security Tower Top";
		hiddenSelections[] = {"Camo1","Plasteel", "Shield", "Camo1Low","Camo2","StairArmor","Railing","MetalGrid"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrierShield_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Common\Data\Textures\Shield\BlueShield_co.paa","FST\FST_Barricades\Data\Textures\FSTBarrierShield_co.paa","FST\FST_Barricades\Data\Textures\Camo2_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa","FST\FST_Common\Data\Textures\HazardSteel\HazardSteel_co.paa","FST\FST_Common\Data\Textures\MetalGrid\MetalGrid_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrierShield.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Common\Data\Textures\Shield\Shield.rvmat","","FST\FST_Barricades\Data\Textures\Camo2.rvmat","FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat","FST\FST_Common\Data\Textures\HazardSteel\HazardSteel.rvmat","FST\FST_Common\Data\Textures\MetalGrid\MetalGrid.rvmat"};
	};
};