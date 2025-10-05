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
		accuracy = 0.2;
		animated = 0;
		armor = 10000;
		cost = 0;
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
};