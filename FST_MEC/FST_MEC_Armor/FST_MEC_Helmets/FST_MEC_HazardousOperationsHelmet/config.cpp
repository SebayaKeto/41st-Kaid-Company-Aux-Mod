#define _ARMA_
#include "\FST\FST_MEC\FST_MEC_Armor\mec_base_defines.hpp"

class CfgPatches
{
	class FST_Helmets
	{
		author = "Maldova";
		units[] = {};
		weapons[] = {"FST_MEC_HazardousOperationsHelmet_Base","FST_MEC_HazardousOperationsHelmet"};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_characters_f"};
	};
};
class CfgWeapons
{
	class H_HelmetO_ViperSP_hex_F;
	class HeadgearItem;
	class FST_MEC_HazardousOperationsHelmet_Base: H_HelmetO_ViperSP_hex_F
	{
		scope = 1;
		scopeCurator = 1;
		author = MEC_AUTHOR;
		displayName = "[MEC] Hazardous Operations Helmet";
		picture = "FST\FST_MEC\ui\icons\mec_hazardhelmet_icon.paa";
		model = "FST\FST_MEC\FST_MEC_Armor\FST_MEC_Helmets\FST_MEC_HazardousOperationsHelmet\MEC_HazardousOperationsHelmet.p3d";
		hiddenSelections[] = {"Camo","Camo1"};
		hiddenSelectionsTextures[] = {"FST\FST_MEC\FST_MEC_Armor\FST_MEC_Helmets\FST_MEC_HazardousOperationsHelmet\Data\Textures\Camo_co.paa","FST\FST_MEC\FST_MEC_Armor\FST_MEC_Helmets\FST_MEC_HazardousOperationsHelmet\Data\Textures\Camo_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_MEC\FST_MEC_Armor\FST_MEC_Helmets\FST_MEC_HazardousOperationsHelmet\Data\Textures\Camo.rvmat","FST\FST_MEC\FST_MEC_Armor\FST_MEC_Helmets\FST_MEC_HazardousOperationsHelmet\Data\Textures\Camo1.rvmat"};
		subItems[] = {};
		class ItemInfo: HeadgearItem
		{
			uniformModel = "FST\FST_MEC\FST_MEC_Armor\FST_MEC_Helmets\FST_MEC_HazardousOperationsHelmet\MEC_HazardousOperationsHelmet.p3d";
			hiddenSelections[] = {"Camo","Camo1"};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName = "HitHead";
					armor = 14;
					passThrough = 0.2;
				};
			};
		};
	};
	class FST_MEC_HazardousOperationsHelmet: FST_MEC_HazardousOperationsHelmet_Base
	{	
		scope = 2;
		scopeCurator = 2;
	};
};
