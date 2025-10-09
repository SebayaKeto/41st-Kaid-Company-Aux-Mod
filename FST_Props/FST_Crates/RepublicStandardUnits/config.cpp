class CfgPatches
{
	class FST_Props_Crates_RepublicStandardUnits
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
	class Land_WoodenCrate_01_F;
	class Ruins_F;
	class FST_Crate_RSU_TypeOne_Base: Land_WoodenCrate_01_F
	{
		editorCategory = "FST_CatagoryCECTypeOneCratesRSU";  //Defined in our core mod
		editorSubcategory = "FST_CatagoryCECGeneric"; //Defined in our core mod
		scope = 1;
		scopecurator = 1;
		placement = "vertical";
		mapSize = 1;
		destrType = "DestructNo";
		displayName = "CEC-1 (Unmarked)";
		model = "FST\FST_Props\FST_Crates\RepublicStandardUnits\RSUStandardCECOne.p3d";
		faction = "prop";
		eden = 1;
		hiddenSelections[]={"Camo","Camo1"};
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_co.paa",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1.rvmat",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo1_CEC1.rvmat"
		};
		ace_cargo_space = 3;
		ace_cargo_size = 4;
	};
	class FST_Crate_RSU_TypeOne_Unmarked: FST_Crate_RSU_TypeOne_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "CEC-1 (Unmarked)";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_co.paa",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1.rvmat",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo1_CEC1.rvmat"
		};
	};
	class FST_Crate_RSU_TypeOne_HighValue: FST_Crate_RSU_TypeOne_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "CEC-1 (High-Value)";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_HV_co.paa",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1.rvmat",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo1_CEC1.rvmat"
		};
	};
	class FST_Crate_RSU_TypeOne_SE: FST_Crate_RSU_TypeOne_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "CEC-1 (Sensitive Electronics)";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_SE_co.paa",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1.rvmat",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo1_CEC1.rvmat"
		};
	};
	class FST_Crate_RSU_TypeOne_HVMedical: FST_Crate_RSU_TypeOne_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "CEC-1 (High-Value Medical)";
		editorSubcategory = "FST_CatagoryCECMedical";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_Medical_co.paa",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1.rvmat",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo1_CEC1.rvmat"
		};
	};
	class FST_Crate_RSU_TypeOne_Jedi: FST_Crate_RSU_TypeOne_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "CEC-1 (Jedi Artifacts)";
		editorSubcategory = "FST_CatagoryCECForce";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_Jedi_co.paa",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1.rvmat",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo1_CEC1.rvmat"
		};
	};
	class FST_Crate_RSU_TypeOne_Sith: FST_Crate_RSU_TypeOne_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "CEC-1 (Sith Artifacts)";
		editorSubcategory = "FST_CatagoryCECForce";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_Sith_co.paa",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1.rvmat",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo1_CEC1.rvmat"
		};
	};
	// Resupply Crates
	class FST_Crate_RSU_TypeOne_Ammunition: FST_Crate_RSU_TypeOne_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "C5 Resupply (Ammunition)";
		editorSubcategory = "FST_CatagoryCECResupplies";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_C5_co.paa",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1.rvmat",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo1_CEC1.rvmat"
		};
	};
	class FST_Crate_RSU_TypeOne_Explosives: FST_Crate_RSU_TypeOne_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "H3 Resupply (Explosives)";
		editorSubcategory = "FST_CatagoryCECResupplies";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_H3_co.paa",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1.rvmat",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo1_CEC1.rvmat"
		};
	};
	class FST_Crate_RSU_TypeOne_FrontlineMedical: FST_Crate_RSU_TypeOne_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "M1 Resupply (Medical)";
		editorSubcategory = "FST_CatagoryCECResupplies";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_M1_co.paa",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1.rvmat",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo1_CEC1.rvmat"
		};
	};
	//RSU Type-2 Crate
	class FST_Crate_RSU_TypeTwo_Base: FST_Crate_RSU_TypeOne_Base
	{
		editorCategory = "FST_CatagoryCECTypeTwoCratesRSU";  //Defined in our core mod
		editorSubcategory = "FST_CatagoryCECGeneric"; //Defined in our core mod
		scope = 1;
		scopecurator = 1;
		placement = "vertical";
		mapSize = 1;
		destrType = "DestructNo";
		displayName = "CEC-2 (Unmarked)";
		model = "FST\FST_Props\FST_Crates\RepublicStandardUnits\RSUStandardCECTwo.p3d";
		faction = "prop";
		eden = 1;
		hiddenSelections[]={"Camo"};
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2.rvmat"
		};
		ace_cargo_space = 6;
		ace_cargo_size = 8;
	};
	class FST_Crate_RSU_TypeTwo_Unmarked: FST_Crate_RSU_TypeTwo_Base
	{
		scope = 2;
		scopecurator = 2;
	};
	class FST_Crate_RSU_TypeTwo_Ammunition: FST_Crate_RSU_TypeTwo_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "C5 Resupply (Ammunition)";
		editorSubcategory = "FST_CatagoryCECResupplies";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2_C5_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2.rvmat"
		};
	};
	class FST_Crate_RSU_TypeTwo_FrontlineMedical: FST_Crate_RSU_TypeTwo_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "M1 Resupply (Medical)";
		editorSubcategory = "FST_CatagoryCECResupplies";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2_M1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2.rvmat"
		};
	};
	class FST_Crate_RSU_TypeTwo_Explosives: FST_Crate_RSU_TypeTwo_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "H3 Resupply (Explosives)";
		editorSubcategory = "FST_CatagoryCECResupplies";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2_H3_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2.rvmat"
		};
	};
	class FST_Crate_RSU_TypeTwo_Biohazard: FST_Crate_RSU_TypeTwo_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "H2 Containment Crate (Biohazard)";
		editorSubcategory = "FST_CatagoryCECMedical";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2_H2_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2.rvmat"
		};
	};
	class FST_Crate_RSU_TypeTwo_WeaponComps: FST_Crate_RSU_TypeTwo_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "W1 Components (Weapon Comps)";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2_W1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2.rvmat"
		};
	};
	class FST_Crate_RSU_TypeTwo_Unknown: FST_Crate_RSU_TypeTwo_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "X1 Crate (Unknown)";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2_X1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2.rvmat"
		};
	};
	class FST_Crate_RSU_TypeTwo_Rations: FST_Crate_RSU_TypeTwo_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Food Crate (Rations)";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2_Rations_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2.rvmat"
		};
	};
	class FST_Crate_RSU_TypeTwo_Cyan: FST_Crate_RSU_TypeTwo_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "CEC-2 (Cyan)";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2_Cyan_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2.rvmat"
		};
	};
	class FST_Crate_RSU_TypeTwo_Green: FST_Crate_RSU_TypeTwo_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "CEC-2 (Green)";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2_Green_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2.rvmat"
		};
	};
	class FST_Crate_RSU_TypeTwo_Maroon: FST_Crate_RSU_TypeTwo_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "CEC-2 (Maroon)";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2_Maroon_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2.rvmat"
		};
	};
	class FST_Crate_RSU_TypeTwo_Brown: FST_Crate_RSU_TypeTwo_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "CEC-2 (Brown)";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2_Brown_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC2.rvmat"
		};
	};
};