class CfgPatches
{
	class 41st_Officer_Uniform
	{
		author="Jay Leno's Chin";
		fileName = "Officer_Uniform.pbo";
		requiredAddons[]=
		{
			"A3_Characters_F",
			"A3_Data_F",
			"A3_Weapons_F"
		};
		weapons[]=
		{
			"41st_Officer_Uniform_Female",
			"41st_Officer_Uniform_Male"
		};
		units[]=
		{
			"41st_Officer_Female",
			"41st_Officer_Male"
		};
	};
};

class CfgVehicles
{
	class B_Soldier_base_F;
	class 41st_Officer_Female : B_Soldier_base_F
    {
        author = "Jay Leno's Chin";
        scope = 2;
        scopeCurator = 2;
        scopeArsenal = 2;
		side=1;
		faction="BLU_F";
		editorSubcategory="EdSubcat_Personnel";
        displayName = "Female Officer (41st)";
        uniformClass = "41st_Officer_Uniform_Female";
		model="Officer Uniform\Model\officer_Uniform_Female.p3d";
        hiddenSelections[] =
		{
			"Camo1",
			"Camo2",
			"Camo3"
		};
        hiddenSelectionsTextures[] = 
		{
			"Officer Uniform\Textures\Tunic_co.paa",
			"Officer Uniform\Textures\Trousers_co.paa",
			"Officer Uniform\Textures\belt_and_gloves_co.paa"
		};
        linkedItems[] = {"ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
        RespawnlinkedItems[] = {"ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
        backpack = "";
    };
	
	class 41st_Officer_Male : B_Soldier_base_F
    {
        author = "Jay Leno's Chin";
        scope = 2;
        scopeCurator = 2;
        scopeArsenal = 2;
		side=1;
		faction="BLU_F";
		editorSubcategory="EdSubcat_Personnel";
        displayName = "Male Officer (41st)";
        uniformClass = "41st_Officer_Uniform_Male";
		model="Officer Uniform\Model\officer_Uniform_Male.p3d";
        linkedItems[] = {"ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
        RespawnlinkedItems[] = {"ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
        backpack = "";
    };
};

class CfgWeapons
{
	class InventoryItem_Base_F;
	class ItemCore;
	class UniformItem;
	class Uniform_Base;
	class 41st_Officer_Uniform_Female: Uniform_Base
	{
		author="Jay Leno's Chin";
		scope=2;
		displayName="Female Officer Uniform (41st)";
		picture="";
		model="Officer Uniform\Model\officer_Uniform_Female.p3d";
        hiddenSelections[] =
		{
			"Camo1",
			"Camo2",
			"Camo3"
		};
        hiddenSelectionsTextures[] = 
		{
			"Officer Uniform\Textures\Trousers_co.paa",
			"Officer Uniform\Textures\Tunic_co.paa",
			"Officer Uniform\Textures\belt_and_gloves_co.paa"
		};
		class ItemInfo: UniformItem
		{
			uniformModel="Officer Uniform\Model\officer_Uniform_Female.p3d";
			uniformClass="41st_Officer_Female";
			containerClass="Supply40";
			mass=40;
		};
	};
	
	class 41st_Officer_Uniform_Male: Uniform_Base
	{
		author="Jay Leno's Chin";
		scope=2;
		displayName="Male Officer Uniform (41st)";
		picture="";
		model="Officer Uniform\Model\officer_Uniform_Male.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="Officer Uniform\Model\officer_Uniform_Male.p3d";
			uniformClass="41st_Officer_Male";
			containerClass="Supply40";
			mass=40;
		};
	};
};
class CfgGlasses
{
	class None;

	class RankPlaque_LT_M: None
	{
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayname = "Rank Plaque (Lieutenant)";
		model = "Officer Uniform\Model\Rank_Plaque_Male.p3d";
		hiddenSelections[] = 
		{
			"Camo_LT_CMDR",
			"Camo_Cpt",
			"Camo_CMDR",
			"Camo_CO",
		};
		identityTypes[] = {};
		class XtdGearInfo
		{
			model = "RankPlaque";
			Rank = "LT";
			Gender = "Male";
		};
	};
	
	class RankPlaque_LT_Cmdr_M: None
	{
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayname = "Rank Plaque (Lt-Commander)";
		model = "Officer Uniform\Model\Rank_Plaque_Male.p3d";
		hiddenSelections[] = 
		{
			"Camo_LT",
			"Camo_Cpt",
			"Camo_CMDR",
			"Camo_CO",
		};
		identityTypes[] = {};
		class XtdGearInfo
		{
			model = "RankPlaque";
			Rank = "LT_Cmdr";
			Gender = "Male";
		};
	};
	
	class RankPlaque_Cmdr_M: None
	{
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayname = "Rank Plaque (Commander)";
		model = "Officer Uniform\Model\Rank_Plaque_Male.p3d";
		hiddenSelections[] = 
		{
			"Camo_LT",
			"Camo_LT_CMDR",
			"Camo_Cpt",
			"Camo_CO",
		};
		identityTypes[] = {};
		class XtdGearInfo
		{
			model = "RankPlaque";
			Rank = "Cmdr";
			Gender = "Male";
		};
	};
	
	class RankPlaque_Cpt_M: None
	{
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayname = "Rank Plaque (Captain)";
		model = "Officer Uniform\Model\Rank_Plaque_Male.p3d";
		hiddenSelections[] = 
		{
			"Camo_LT",
			"Camo_LT_CMDR",
			"Camo_CMDR",
			"Camo_CO",
		};
		identityTypes[] = {};
		class XtdGearInfo
		{
			model = "RankPlaque";
			Rank = "Cpt";
			Gender = "Male";
		};
	};
	
	class RankPlaque_Commodore_M: None
	{
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayname = "Rank Plaque (Commodore)";
		model = "Officer Uniform\Model\Rank_Plaque_Male.p3d";
		hiddenSelections[] = 
		{
			"Camo_LT",
			"Camo_LT_CMDR",
			"Camo_CMDR",
			"Camo_Cpt",
		};
		identityTypes[] = {};
		class XtdGearInfo
		{
			model = "RankPlaque";
			Rank = "Commodore";
			Gender = "Male";
		};
	};
	
	class RankPlaque_LT_F: None
	{
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayname = "Rank Plaque (Lieutenant)";
		model = "Officer Uniform\Model\Rank_Plaque_Female.p3d";
		hiddenSelections[] = 
		{
			"Camo_LT_CMDR",
			"Camo_Cpt",
			"Camo_CMDR",
			"Camo_CO",
		};
		identityTypes[] = {};
		class XtdGearInfo
		{
			model = "RankPlaque";
			Rank = "LT";
			Gender = "Female";
		};
	};
	
	class RankPlaque_LT_Cmdr_F: None
	{
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayname = "Rank Plaque (Lt-Commander)";
		model = "Officer Uniform\Model\Rank_Plaque_Female.p3d";
		hiddenSelections[] = 
		{
			"Camo_LT",
			"Camo_Cpt",
			"Camo_CMDR",
			"Camo_CO",
		};
		identityTypes[] = {};
		class XtdGearInfo
		{
			model = "RankPlaque";
			Rank = "LT_Cmdr";
			Gender = "Female";
		};
	};
	
	class RankPlaque_Cmdr_F: None
	{
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayname = "Rank Plaque (Commander)";
		model = "Officer Uniform\Model\Rank_Plaque_Female.p3d";
		hiddenSelections[] = 
		{
			"Camo_LT",
			"Camo_LT_CMDR",
			"Camo_Cpt",
			"Camo_CO",
		};
		identityTypes[] = {};
		class XtdGearInfo
		{
			model = "RankPlaque";
			Rank = "Cmdr";
			Gender = "Female";
		};
	};
	
	class RankPlaque_Cpt_F: None
	{
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayname = "Rank Plaque (Captain)";
		model = "Officer Uniform\Model\Rank_Plaque_Female.p3d";
		hiddenSelections[] = 
		{
			"Camo_LT",
			"Camo_LT_CMDR",
			"Camo_CMDR",
			"Camo_CO",
		};
		identityTypes[] = {};
		class XtdGearInfo
		{
			model = "RankPlaque";
			Rank = "Cpt";
			Gender = "Female";
		};
	};
	
	class RankPlaque_Commodore_F: None
	{
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayname = "Rank Plaque (Commodore)";
		model = "Officer Uniform\Model\Rank_Plaque_Female.p3d";
		hiddenSelections[] = 
		{
			"Camo_LT",
			"Camo_LT_CMDR",
			"Camo_CMDR",
			"Camo_Cpt",
		};
		identityTypes[] = {};
		class XtdGearInfo
		{
			model = "RankPlaque";
			Rank = "Commodore";
			Gender = "Female";
		};
	};
};
class XtdGearModels
{
	class CfgGlasses
	{
		class RankPlaque
		{
			label = "Republic Rank Plaque (41st)";
			author = "Jay Leno's Chin";
			options[] = {"Rank","Gender"};
			class Rank
			{
				changeingame = 0;
				values[] = {"LT","LT_Cmdr","Cmdr","Cpt","Commodore"};
				class LT
				{
					label = "Lieutenant";
				};
				class LT_Cmdr
				{
					label = "Lt-Commander";
				};
				class Cmdr
				{
					label = "Commander";
				};
				class Cpt
				{
					label = "Captain";
				};
				class Commodore
				{
					label = "Commodore";
				};
			};
			class Gender
			{
				changeingame = 0;
				values[] = {"Male","Female"};
				class Male
				{
					label = "Male";
				};
				class Female
				{
					label = "Female";
				};
			};
		};
	};
};