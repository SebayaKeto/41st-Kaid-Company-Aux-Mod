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
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Pirate.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3.rvmat"
		};
		eden = 1;
	};
	// Base Asset and Texture
	class FST_OutpostWall_Unmarked_Curve: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall Curve (Unmarked)";
		model = "FST\FST_Outpost\LightWalls\FST_OutpostWall_Light_Curve.p3d";
		hiddenSelections[]={"Camo","Camo1","Camo2","Camo3","Camo4"};
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Curve_Unmarked_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Curve_Unmarked_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo4_Curve_Unmarked_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Curve.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Curve.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo4_Curve.rvmat"
		};
	};
	class FST_OutpostWall_Entrance_Base: FST_OutpostWall_Base
	{
		_generalMacro = "FST_OutpostWall_Entrance_Base";
		displayName = "Light Outpost Wall Entrance (Unmarked)";
		model = "FST\FST_Outpost\LightWalls\FST_OutpostWall_Light_Entrance.p3d";
		numberOfDoors=2;
		hiddenSelections[]={"Camo","Camo1","Camo2","Camo3","Camo4","Camo5","Camo6"};
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Entrance\Camo_Entrance_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Entrance\Camo1_Entrance_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Entrance\Camo2_Entrance_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Entrance\Camo3_Entrance_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Entrance\Camo4_Entrance_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Entrance\Camo5_Entrance_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Entrance\Camo6_Entrance_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Entrance\Camo_Entrance.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Entrance\Camo1_Entrance.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Entrance\Camo2_Entrance.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Entrance\Camo3_Entrance.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Entrance\Camo4_Entrance.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Entrance\Camo5_Entrance.rvmat",
			"FST\FST_Outpost\LightWalls\Data\Textures\Entrance\Camo6_Entrance.rvmat"
		};
		class AnimationSources
		{
			// Animation sources for doors
			class Door_1_source
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
				sound = "FST_OutpostWallEntranceSoundset";
				soundPosition="general_door_trigger";
			};
			class Door_2_source
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
				sound = "FST_OutpostWallEntranceSoundset";
				soundPosition="general_door_trigger";
			};
		};
		class UserActions
		{
			class OpenDoor_1
			{
				displayNameDefault = "<img image='FST\FST_Core\UIImages\FST_DoorOpen.paa' size='6' />";
				displayName = "Open Left Door";
				position = "general_door_trigger";
				priority = 10;
				radius = 4;
				condition="((this animationSourcePhase 'Door_1_source') < 0.5) && (cameraOn isKindOf 'CAManBase')";
				statement = "this animateSource ['Door_1_source', 1, true]";
			};
			class CloseDoor_1: OpenDoor_1
			{
				displayNameDefault = "<img image='FST\FST_Core\UIImages\FST_DoorClose.paa' size='5' />";
				displayName = "Close Left Door";
				position = "general_door_trigger";
				priority = 10;
				radius = 4;
				condition="((this animationSourcePhase 'Door_1_source') >= 0.5) && (cameraOn isKindOf 'CAManBase')";
				statement = "this animateSource ['Door_1_source', 0, true]";
			};
			class OpenDoor_2
			{
				displayNameDefault = "<img image='FST\FST_Core\UIImages\FST_DoorOpen.paa' size='6' />";
				displayName = "Open Right Door";
				position = "general_door_trigger";
				priority = 11;
				radius = 4;
				condition="((this animationSourcePhase 'Door_2_source') < 0.5) && (cameraOn isKindOf 'CAManBase')";
				statement = "this animateSource ['Door_2_source', 1, true]";
			};
			class CloseDoor_2: OpenDoor_2
			{
				displayNameDefault = "<img image='FST\FST_Core\UIImages\FST_DoorClose.paa' size='5' />";
				displayName = "Close Right Door";
				condition="((this animationSourcePhase 'Door_2_source') >= 0.5) && (cameraOn isKindOf 'CAManBase')";
				statement = "this animateSource ['Door_2_source', 0, true]";
			};
		};
		actionBegin1="OpenDoor_1";
		actionEnd1="CloseDoor_1";
		actionBegin2="OpenDoor_2";
		actionEnd2="CloseDoor_2";
		class SimpleObject
		{
			eden=1;
			animate[] =
			{
				{
					"door_1_rot",
					0
				},
				{
					"door_2_rot",
					0
				}
			};
			hide[]={};
			verticalOffset=3.0599999;
			verticalOffsetWorld=0;
			init="''";
		};
	};
	class FST_OutpostWall_Entrance_Unmarked: FST_OutpostWall_Entrance_Base
	{
		scope = 2;
		scopecurator = 2;
	};
	class FST_OutpostWall_Unmarked: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
	};
	// Republic
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
	class FST_OutpostWall_GAR_Light: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall (GAR Light)";
		editorSubcategory = "FST_Subcategory_OutpostWallsGAR";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_GARLight_co.paa",
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
	class FST_OutpostWall_Unmarked_Curve_GAROne: FST_OutpostWall_Unmarked_Curve
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall Curve (GAR 1)";
		editorSubcategory = "FST_Subcategory_OutpostWallsGAR";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Curve_Unmarked_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Curve_GAROne_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo4_Curve_GAROne_co.paa"
		};
	};
	class FST_OutpostWall_Unmarked_Curve_GARTwo: FST_OutpostWall_Unmarked_Curve
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall Curve (GAR 2)";
		editorSubcategory = "FST_Subcategory_OutpostWallsGAR";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Curve_Unmarked_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Curve_GARTwo_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo4_Curve_GARTwo_co.paa"
		};
	};
	class FST_OutpostWall_Unmarked_Curve_GARLight: FST_OutpostWall_Unmarked_Curve
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall Curve (GAR Light)";
		editorSubcategory = "FST_Subcategory_OutpostWallsGAR";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Curve_Unmarked_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Curve_GARLight_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo4_Curve_GARLight_co.paa"
		};
	};
	class FST_OutpostWall_Unmarked_Curve_GARUrban: FST_OutpostWall_Unmarked_Curve
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall Curve (GAR Urban)";
		editorSubcategory = "FST_Subcategory_OutpostWallsGAR";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Curve_Unmarked_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Curve_GARUrban_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo4_Curve_GARUrban_co.paa"
		};
	};
	class FST_OutpostWall_Unmarked_Curve_GARWoodland: FST_OutpostWall_Unmarked_Curve
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall Curve (GAR Woodland)";
		editorSubcategory = "FST_Subcategory_OutpostWallsGAR";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Curve_Unmarked_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Curve_GARWoodland_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo4_Curve_GARWoodland_co.paa"
		};
	};
	class FST_OutpostWall_Unmarked_Curve_GARSand: FST_OutpostWall_Unmarked_Curve
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall Curve (GAR Sand)";
		editorSubcategory = "FST_Subcategory_OutpostWallsGAR";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Curve_Unmarked_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Curve_GARSand_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo4_Curve_GARSand_co.paa"
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
	class FST_OutpostWall_CIS_Light: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall (CIS Light)";
		editorSubcategory = "FST_Subcategory_OutpostWallsCIS";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_CISLight_co.paa",
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
	class FST_OutpostWall_CIS_Dark: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall (CIS Dark)";
		editorSubcategory = "FST_Subcategory_OutpostWallsCIS";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Pirate_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_CISDark_co.paa",
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
	class FST_OutpostWall_Curve_CISLight: FST_OutpostWall_Unmarked_Curve
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall Curve (CIS Light)";
		editorSubcategory = "FST_Subcategory_OutpostWallsCIS";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Curve_Unmarked_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Curve_CISLight_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo4_Curve_CISLight_co.paa"
		};
	};
	class FST_OutpostWall_Curve_CISDark: FST_OutpostWall_Unmarked_Curve
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall Curve (CIS Dark)";
		editorSubcategory = "FST_Subcategory_OutpostWallsCIS";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Curve_Pirate_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Curve_CISDark_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo4_Curve_CISDark_co.paa"
		};
	};
	// Minor Faction Assets
	class FST_OutpostWall_Tagged: FST_OutpostWall_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall (Tagged)";
		editorCategory = "FST_CatagoryMinorOutpost";
		editorSubcategory = "FST_Subcategory_OutpostWallsPirates";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Pirate_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Tagged_co.paa",
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
	class FST_OutpostWall_Curve_Tagged: FST_OutpostWall_Unmarked_Curve
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall Curve (Tagged)";
		editorCategory = "FST_CatagoryMinorOutpost";
		editorSubcategory = "FST_Subcategory_OutpostWallsPirates";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Curve_Pirate_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Curve_Tagged_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo4_Curve_Tagged_co.paa"
		};
	};
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
	class FST_OutpostWall_Curve_Pirate: FST_OutpostWall_Unmarked_Curve
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall Curve (Pirate)";
		editorCategory = "FST_CatagoryMinorOutpost";
		editorSubcategory = "FST_Subcategory_OutpostWallsPirates";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Curve_Pirate_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Curve_Pirate_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo4_Curve_Pirate_co.paa"
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
	class FST_OutpostWall_Curve_BlackSun: FST_OutpostWall_Unmarked_Curve
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall Curve (Black Sun)";
		editorCategory = "FST_CatagoryMinorOutpost";
		editorSubcategory = "FST_Subcategory_OutpostWallsBlackSun";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Curve_Pirate_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Curve_BlackSun_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo4_Curve_BlackSun_co.paa"
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
	class FST_OutpostWall_Curve_HuttCartel: FST_OutpostWall_Unmarked_Curve
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Light Outpost Wall Curve (Hutt Cartel)";
		editorCategory = "FST_CatagoryMinorOutpost";
		editorSubcategory = "FST_Subcategory_OutpostWallsHuttCartel";
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo_Curve_Hutt_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo1_Curve_Hutt_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo2_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo3_co.paa",
			"FST\FST_Outpost\LightWalls\Data\Textures\Camo4_Curve_Hutt_co.paa"
		};
	};
};
class CfgSounds
{
	// Define the sound for the door opening
	class FST_Door_Open_Sound_Outpost
	{
		name = "FST_Door_Open_Sound_Outpost";
		// IMPORTANT: Replace this path with the actual path to your sound file
		sound[] = {"FST\FST_Core\Sounds\FST_OutpostEntrance_LightGate.ogg", 1, 1, 15};
		titles[] = {};
	};

	// Define the sound for the door closing
	class FST_Door_Close_Sound_Outpost
	{
		name = "FST_Door_Close_Sound_Outpost";
		// IMPORTANT: Replace this path with the actual path to your sound file
		sound[] = {"FST\FST_Core\Sounds\FST_OutpostEntrance_LightGate.ogg", 1, 1, 15};
		titles[] = {};
	};
};
class CfgAnimationSourceSounds
{
	// This is the soundset referenced by your door's AnimationSources
	class FST_OutpostWallEntranceSoundset
	{
		// Sound played when the animation phase goes from 0 to 1 (opening)
		class open
		{
			sound = "FST_Door_Open_Sound_Outpost";
			// Time in the animation when the sound should start (0.0 = beginning)
			begin = 0.0; 
		};
		// Sound played when the animation phase goes from 1 to 0 (closing)
		class close
		{
			sound = "FST_Door_Close_Sound_Outpost";
			begin = 0.0;
		};
	};
};

