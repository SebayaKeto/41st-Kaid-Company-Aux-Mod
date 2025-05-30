#define _ARMA_

class CfgPatches
{
	class FST_Helmets
	{
		author = "Maldova";
		units[] = {};
		weapons[] = {"FST_ScoutHelmet_Base","FST_ScoutHelmet_MarkedOne","FST_ScoutHelmet_Woodland_MarkedOne","FST_ScoutHelmet_Woodland_Unmarked"};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_characters_f"};
	};
};
class CfgWeapons
{
	class H_HelmetO_ViperSP_hex_F;
	class HeadgearItem;
	class FST_ScoutHelmet_Base: H_HelmetO_ViperSP_hex_F
	{
		scope = 2;
		scopeCurator = 2;
		author = "Maldova";
		displayName = "Scout Helmet";
		picture = "";
		hiddenSelections[] = {"Camo1","Visor"};
		hiddenSelectionsTextures[] = {"FST\FST_Helmets\Data\Textures\ScoutUnmarked_co.paa","FST\FST_Helmets\Data\Textures\GreenVisor_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Helmets\Data\Textures\ScoutHelmet.rvmat","FST\FST_Helmets\Data\Textures\visor.rvmat"};
		model = "FST\FST_Helmets\FST_ScoutHelmet.p3d";
		subItems[] = {};
		class ItemInfo: HeadgearItem
		{
			uniformModel = "FST\FST_Helmets\FST_ScoutHelmet.p3d";
			hiddenSelections[] = {"Camo1","Visor"};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName = "HitHead";
					armor = 7;
					passThrough = 0.5;
				};
			};
		};
	};
	class FST_ScoutHelmet_MarkedOne: FST_ScoutHelmet_Base
	{
		displayName = "Scout Helmet (CT)";
		hiddenSelections[] = {"Camo1","Visor"};
		hiddenSelectionsTextures[] = {"FST\FST_Helmets\Data\Textures\ScoutMarkedOne_co.paa","FST\FST_Helmets\Data\Textures\GreenVisor_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Helmets\Data\Textures\ScoutHelmet.rvmat","FST\FST_Helmets\Data\Textures\visor.rvmat"};
	};
	class FST_ScoutHelmet_Woodland_Unmarked: FST_ScoutHelmet_Base
	{
		displayName = "Scout Helmet (Woodland)";
		hiddenSelections[] = {"Camo1","Visor"};
		hiddenSelectionsTextures[] = {"FST\FST_Helmets\Data\Textures\ScoutWoodlandUnmarked_co.paa","FST\FST_Helmets\Data\Textures\GreenVisor_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Helmets\Data\Textures\ScoutHelmet.rvmat","FST\FST_Helmets\Data\Textures\visor.rvmat"};
	};
	class FST_ScoutHelmet_Woodland_MarkedOne: FST_ScoutHelmet_Base
	{
		displayName = "Scout Helmet (CT Woodland)";
		hiddenSelections[] = {"Camo1","Visor"};
		hiddenSelectionsTextures[] = {"FST\FST_Helmets\Data\Textures\ScoutWoodlandMarkedOne_co.paa","FST\FST_Helmets\Data\Textures\GreenVisor_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Helmets\Data\Textures\ScoutHelmet.rvmat","FST\FST_Helmets\Data\Textures\visor.rvmat"};
	};
};
