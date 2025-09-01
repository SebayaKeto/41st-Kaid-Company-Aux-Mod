class CfgPatches
{
	class FST_Props
	{
		units[]=
		{
			"land_FST_cis_Wall_Bunker_v2",
			"land_FST_CIS_Bunker_v2",
			"land_FST_cis_Wall_Tower_v2",
			"land_FST_cis_Wall_Gate_v2",
		};
		weapons[]={};
		requiredAddons[]=
		{
			"A3_Data_F",
			"3AS_Terrain_Universal"
		};
		author="$STR_3AS_Studio";
	};
};
class CfgVehicleClasses
{
	class Prop
	{
		displayname="Prop";
	};
};
class CfgFactionClasses
{
	class Prop
	{
		displayName="Prop";
		priority=1;
		side=3;
	};
};
class CfgEditorSubcategories
{
	class FST_Baseplates
	{
		displayName="41st Baseplates";
	};
	class FST_CIS_JORGE_FOB
	{
		displayName="41st CIS FOB (Jorge)";
	};
};
class CfgVehicles
{
	class Strategic;
	class House;
	class House_F: House
	{
		class DestructionEffects;
	};
	class 3AS_Prop_Base_Animate: House_F{};
	class Ruins_F;
	class Lamps_base_F;
	class ThingX;
	class 3AS_Prop_Base;
	class land_FST_CIS_Bunker_v2: 3AS_Prop_Base_Animate
	{
		model="\3AS\3AS_structures\FOB\3AS_cis_Bunker_v2.p3d";
		displayName="CIS Bunker (DJ)";
		editorPreview="\3AS\3AS_structures\FOB\editorPreviews\land_3AS_CIS_Bunker_v2.jpg";
		placement="vertical";
		mapSize=2;
		editorCategory="3AS_EditorCategory_CISProps";
		editorSubcategory="3AS_EditorSubcategory_Walls";
		faction="Prop";
		scope=2;
		scopeCurator=2;
		eden=1;
		hiddenSelections[]=
		{
			"Camo1"
		};
		destrType="DestructNo";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\CIS_Bunker_co.paa"
		};
		class DestructionEffects: DestructionEffects
		{
		};
		class SimpleObject
		{
			animate[]=
			{
				
				{
					"open_left",
					0
				},
				
				{
					"open_right",
					0
				},
				
				{
					"open_left_small",
					0
				},
				
				{
					"open_right_small",
					0
				}
			};
			eden=1;
			verticalOffset=0;
		};
	};
	class land_3AS_CIS_Bunker_v2;
	class land_FST_cis_Wall_Bunker_v2: land_3AS_CIS_Bunker_v2
	{
		model="\3AS\3AS_structures\FOB\3AS_cis_Wall_Bunker_v2.p3d";
		displayName="CIS Wall Bunker (DJ)";
		editorPreview="\3AS\3AS_structures\FOB\editorPreviews\land_3AS_cis_Wall_Bunker_v2.jpg";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\CIS_small_Wall_Bunker_co.paa"
		};
	};
	class land_3AS_CIS_Wall_Med_v2;
	class land_FST_cis_Wall_Tower_v2: land_3AS_CIS_Bunker_v2
	{
		model="\3AS\3AS_structures\FOB\3AS_cis_Wall_Tower_v2.p3d";
		displayName="CIS Tower (DJ)";
		editorPreview="\3AS\3AS_structures\FOB\editorPreviews\land_3AS_cis_Wall_Tower_v2.jpg";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\CIS_Tower_co.paa"
		};
		ladders[]=
		{
			
			{
				"start",
				"end"
			},
			
			{
				"start1",
				"end1"
			}
		};
	};
	class land_3AS_CIS_Wall_Door_v2;
	class land_FST_cis_Wall_Gate_v2: land_3AS_CIS_Wall_Door_v2
	{
		displayName="CIS Wall Gate (DJ)";
		model="\3AS\3AS_structures\FOB\3AS_cis_Wall_gate_v2.p3d";
		editorPreview="\3AS\3AS_structures\FOB\editorPreviews\land_3AS_cis_Wall_Gate_v2.jpg";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\CIS_small_Wall_gate_co.paa"
		};
	};
	///////////////
	/////WALLS/////
	///////////////
	class land_3AS_cis_Wall_Short_v2;
	class FST_CIS_Small_Wall_Short: land_3AS_cis_Wall_Short_v2
	{
		displayName="[41st] CIS Small Wall Short (Jorge)";
		model="\3AS\3AS_structures\FOB\3AS_cis_Wall_Short_v2.p3d";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_CIS_small_wall_short_Jorge_co.paa"
		};
	};
	class land_3AS_CIS_Ramp_v2;
	class FST_CIS_Small_Wall_Ramp_Jorge: land_3AS_CIS_Ramp_v2
	{
		displayName="[41st] CIS Small Wall Ramp (Jorge)";
		model="\3AS\3AS_structures\FOB\3AS_cis_ramp_v2.p3d";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_cis_small_wall_ramp_Jorge_co.paa"
		};
	};
	class land_3AS_CIS_Wall_Inv_Corner_v2;
	class FST_CIS_Wall_Inv_Corner_Jorge: land_3AS_CIS_Wall_Inv_Corner_v2
	{
		displayName="[41st] CIS Wall Inverted Corner (Jorge)";
		model="\3AS\3AS_structures\FOB\3AS_cis_Wall_Inv_Corner_v2.p3d";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_CIS_small_wall_invcorner_Jorge_co.paa"
		};
	};
	class land_3AS_CIS_Wall_Gate_v2;
	class FST_CIS_Wall_Gate_Jorge: land_3AS_CIS_Wall_Gate_v2
	{
		displayName="[41st] CIS Wall Gate (Jorge)";
		model="\3AS\3AS_structures\FOB\3AS_cis_Wall_gate_v2.p3d";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_CIS_small_wall_gate_Jorge_co.paa"
		};
	};
	class FST_CIS_Wall_Door_Jorge: land_3AS_CIS_Wall_Door_v2
	{
		displayName="[41st] CIS Wall Door (Jore)";
		model="\3AS\3AS_structures\FOB\3AS_cis_Wall_Door_v2.p3d";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_CIS_small_wall_door_Jorge_co.paa"
		};
	};
	class FST_CIS_Small_Wall_Bunker_Jorge: land_3AS_CIS_Bunker_v2
	{
		displayName="[41st] CIS Wall Bunker (Jorge)";
		model="\3AS\3AS_structures\FOB\3AS_cis_Wall_Bunker_v2.p3d";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_CIS_small_wall_bunker_Jorge_co.paa"
		};
	};
	class land_3AS_CIS_Wall_Corner_v2;
	class FST_CIS_Small_Wall_Corner_Jorge: land_3AS_CIS_Wall_Corner_v2
	{
		displayName="[41st] CIS Small Wall Corner (Jorge)";
		model="\3AS\3AS_structures\FOB\3AS_cis_Wall_Corner_v2.p3d";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_CIS_small_wall_corner_Jorge_co.paa"
		};
	};
	class FST_CIS_Small_Wall_Med: land_3AS_CIS_Wall_Med_v2
	{
		displayName="[41st] CIS Small Wall Med (Jorge)";
		scope=2;
		scopecurator=2;
		model="3AS\3AS_structures\FOB\3AS_cis_Wall_Med_v2.p3d";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_CIS_small_wall_medium_Jorge_co.paa"
		};
	};
	class land_3AS_cis_Wall_Long_v2;
	class FST_cis_Small_Wall_Long: land_3AS_cis_Wall_Long_v2
	{
		author="Gold";
		displayName="[41st] CIS Small Wall Long (Jorge)";
		model="\3AS\3AS_structures\FOB\3AS_cis_Wall_Long_v2.p3d";
		editorPreview="\3AS\3AS_structures\FOB\editorPreviews\land_3AS_cis_Wall_Long_v2.jpg";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_CIS_small_wall_long_Jorge_co.paa"
		};
	};
	class 3AS_City_Wall_Straight_Prop;
	class FST_City_Wall_Straight_Jorge: 3AS_City_Wall_Straight_Prop
	{
		displayName="[41st] City Wall Straight (Jorge)";
		model="3AS\3AS_structures\city\walls\city_wall.p3d";
		hiddenselections[]=
		{
			"camo"
		};
		hiddenselectionstextures[]=
		{
			"41st_Props\Data\FST_City_Walls_Basic_Jorge_co.paa"
		};
	};
	///////////////
	/////LOGO//////
	///////////////
	class land_3AS_CIS_Wall_Med_Logo_v2;
	class FST_CIS_Wall_Med_Logo_Jorge: land_3AS_CIS_Wall_Med_Logo_v2
	{
		displayName="[41st] CIS Wall Medium Logo (Jorge)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_CIS_small_wall_medium_logo_Jorge_co.paa"
		};
	};
	///////////////
	////BUNKERS////
	///////////////
	class FST_CIS_Bunker_Jorge: land_3AS_CIS_Bunker_v2
	{
		displayName="[41st] CIS Bunker";
		model="\3AS\3AS_structures\FOB\3AS_cis_Bunker_v2.p3d";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_CIS_bunker_Jorge_co.paa"
		};
	};
	///////////////
	////TOWERS/////
	///////////////
	class land_3AS_CIS_Wall_Tower_v2;
	class FST_CIS_Wall_Tower_Jorge: land_3AS_CIS_Wall_Tower_v2
	{
		displayName="[41st] CIS Tower (Jorge)";
		model="\3AS\3AS_structures\FOB\3AS_cis_Wall_Tower_v2.p3d";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_CIS_tower_Jorge_co.paa"
		};
	};
	///////////////
	//LANDINGPADS//
	///////////////
	class 3AS_Pad_CIS_Prop;
	class FST_CIS_LandingPad_Jorge: 3AS_Pad_CIS_Prop
	{
		author="Gold";
		displayName="[41st] CIS Landing Pad (Jorge)";
		model="\3AS\3AS_structures\landingPads\Pad_CIS.p3d";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_pad_cis_Jorge_co.paa"
		};
	};
	//////////////
	/////TENT/////
	//////////////
	class 3AS_Tent;
	class FST_Tent_Jorge: 3AS_Tent
	{
		displayName="[41st] Republic Tent (Jorge)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		scope=2;
		scopeCurator=2;
		hiddenSelections[]=
		{
			"Camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_Tent_details_Jorge_co.paa",
			"41st_Props\Data\FST_Tent_door_Jorge_co.paa"
		};
	};
	//////////////
	//BASEPLATES//
	//////////////
	class 3AS_FOB_Baseplate;
	class FST_FOB_Baseplate_Jorge: 3AS_FOB_Baseplate
	{
		displayName="[41st] Base plate (Jorge)";
		model="\3AS\3AS_structures\FOB\Baseplate.p3d";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_baseplate_concrete_Jorge_co.paa"
		};
	};
	class 3AS_Prop_Baseplate_10x10;
	class FST_Prop_Baseplate_10: 3AS_Prop_Baseplate_10x10
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate (10x10)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_50BP.paa"
		};
		editorPreview="3as\3AS_Platforms\Platforms\EditorPreviews\3AS_Prop_Baseplate_10_GAR.jpg";
	};
	class FST_Prop_Baseplate_10_Jorge: 3AS_Prop_Baseplate_10x10
	{
		author="Gold";
		displayName="[41st] Jorge Baseplate (10x10)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_bp_cis_Jorge_co.paa"
		};
	};
	class FST_Prop_Baseplate_10_Square: 3AS_Prop_Baseplate_10x10
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate (10x10) Square";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_S_50BP.paa"
		};
		editorPreview="3as\3AS_Platforms\Platforms\EditorPreviews\3AS_Prop_Baseplate_10_GAR_Square.jpg";
	};
	class FST_Prop_Baseplate_10_Square_Jorge: FST_Prop_Baseplate_10_Square
	{
		author="Gold";
		displayName="[41st] Baseplate (10x10) Square (Jorge)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_bp_cis_Square_Jorge_co.paa"
		};
	};
	class 3AS_Prop_Baseplate_10x10_thin;
	class FST_Prop_Baseplate_10_Thin: 3AS_Prop_Baseplate_10x10_thin
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate Thin (10x10)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_50BP.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Platforms\Platforms\data\bp_50_gar\bp_50_gar.rvmat"
		};
	};
	class FST_Prop_Baseplate_10_Thin_Square: 3AS_Prop_Baseplate_10x10_thin
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate Thin (10x10) Square";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_S_50BP.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Platforms\Platforms\data\bp_50_gar_s\bp_50_gar_s.rvmat"
		};
	};
	class 3AS_Prop_Baseplate_10x10_Corner;
	class FST_Baseplate_10x10_Corner_Jorge: 3AS_Prop_Baseplate_10x10_Corner
	{
		displayName="[41st] Baseplate (10x10) Corner (Jorge)";
		model="\3AS\3AS_Platforms\Platforms\Baseplate_10x10_corner.p3d";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_bp_Corner_cis_Jorge_co.paa"
		};
	};
	class 3AS_Prop_Baseplate_20x20;
	class FST_Prop_Baseplate_20: 3AS_Prop_Baseplate_20x20
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate (20x20)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_50BP.paa"
		};
		editorPreview="3as\3AS_Platforms\Platforms\EditorPreviews\3AS_Prop_Baseplate_10_GAR.jpg";
	};
	class FST_Prop_Baseplate_20_Jorge: 3AS_Prop_Baseplate_20x20
	{
		author="Gold";
		displayName="[41st] Jorge Baseplate (20x20)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_bp_cis_Jorge_co.paa"
		};
	};
	class FST_Prop_Baseplate_20_Square: 3AS_Prop_Baseplate_20x20
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate (20x20) Square";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_S_50BP.paa"
		};
		editorPreview="3as\3AS_Platforms\Platforms\EditorPreviews\3AS_Prop_Baseplate_10_GAR_Square.jpg";
	};
	class FST_Prop_Baseplate_20_Square_Jorge: FST_Prop_Baseplate_20_Square
	{
		author="Gold";
		displayName="[41st] Baseplate (20x20) Square (Jorge)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_bp_cis_Square_Jorge_co.paa"
		};
	};
	class 3AS_Prop_Baseplate_20x20_thin;
	class FST_Prop_Baseplate_20_Thin: 3AS_Prop_Baseplate_20x20_thin
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate Thin (20x20)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_50BP.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Platforms\Platforms\data\bp_50_gar\bp_50_gar.rvmat"
		};
	};
	class FST_Prop_Baseplate_20_Thin_Square: 3AS_Prop_Baseplate_20x20_thin
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate Thin (20x20) Square";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_S_50BP.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Platforms\Platforms\data\bp_50_gar_s\bp_50_gar_s.rvmat"
		};
	};
	class 3AS_Prop_Baseplate_20x20_Corner;
	class FST_Baseplate_20x20_Corner_Jorge: 3AS_Prop_Baseplate_20x20_Corner
	{
		displayName="[41st] Baseplate (20x20) Corner (Jorge)";
		model="\3AS\3AS_Platforms\Platforms\Baseplate_20x20_corner.p3d";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_bp_Corner_cis_Jorge_co.paa"
		};
	};
	class 3AS_Prop_Baseplate_30x30;
	class FST_Prop_Baseplate_30: 3AS_Prop_Baseplate_30x30
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate (30x30)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_50BP.paa"
		};
		editorPreview="3as\3AS_Platforms\Platforms\EditorPreviews\3AS_Prop_Baseplate_10_GAR.jpg";
	};
	class FST_Prop_Baseplate_30_Jorge: 3AS_Prop_Baseplate_30x30
	{
		author="Gold";
		displayName="[41st] Jorge Baseplate (30x30)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_bp_cis_Jorge_co.paa"
		};
	};
	class FST_Prop_Baseplate_30_Square: 3AS_Prop_Baseplate_30x30
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate (30x30) Square";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_S_50BP.paa"
		};
		editorPreview="3as\3AS_Platforms\Platforms\EditorPreviews\3AS_Prop_Baseplate_10_GAR_Square.jpg";
	};
	class FST_Prop_Baseplate_30_Square_Jorge: FST_Prop_Baseplate_30_Square
	{
		author="Gold";
		displayName="[41st] Baseplate (30x30) Square (Jorge)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_bp_cis_Square_Jorge_co.paa"
		};
	};
	class 3AS_Prop_Baseplate_30x30_thin;
	class FST_Prop_Baseplate_30_Thin: 3AS_Prop_Baseplate_30x30_thin
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate Thin (30x30)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_50BP.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Platforms\Platforms\data\bp_50_gar\bp_50_gar.rvmat"
		};
	};
	class FST_Prop_Baseplate_30_Thin_Square: 3AS_Prop_Baseplate_30x30_thin
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate Thin (30x30) Square";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_S_50BP.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Platforms\Platforms\data\bp_50_gar_s\bp_50_gar_s.rvmat"
		};
	};
	class 3AS_Prop_Baseplate_30x30_Corner;
	class FST_Baseplate_30x30_Corner_Jorge: 3AS_Prop_Baseplate_30x30_Corner
	{
		displayName="[41st] Baseplate (30x30) Corner (Jorge)";
		model="\3AS\3AS_Platforms\Platforms\Baseplate_30x30_corner.p3d";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_bp_Corner_cis_Jorge_co.paa"
		};
	};
	class 3AS_Prop_Baseplate_40x40;
	class FST_Prop_Baseplate_40: 3AS_Prop_Baseplate_40x40
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate (40x40)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_50BP.paa"
		};
		editorPreview="3as\3AS_Platforms\Platforms\EditorPreviews\3AS_Prop_Baseplate_10_GAR.jpg";
	};
	class FST_Prop_Baseplate_40_Jorge: 3AS_Prop_Baseplate_40x40
	{
		author="Gold";
		displayName="[41st] Jorge Baseplate (40x40)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_bp_cis_Jorge_co.paa"
		};
	};
	class FST_Prop_Baseplate_40_Square: 3AS_Prop_Baseplate_40x40
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate (40x40) Square";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_S_50BP.paa"
		};
		editorPreview="3as\3AS_Platforms\Platforms\EditorPreviews\3AS_Prop_Baseplate_10_GAR_Square.jpg";
	};
	class FST_Prop_Baseplate_40_Square_Jorge: FST_Prop_Baseplate_40_Square
	{
		author="Gold";
		displayName="[41st] Baseplate (40x40) Square (Jorge)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_bp_cis_Square_Jorge_co.paa"
		};
	};
	class 3AS_Prop_Baseplate_40x40_thin;
	class FST_Prop_Baseplate_40_Thin: 3AS_Prop_Baseplate_40x40_thin
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate Thin (40x40)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_50BP.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Platforms\Platforms\data\bp_50_gar\bp_50_gar.rvmat"
		};
	};
	class FST_Prop_Baseplate_40_Thin_Square: 3AS_Prop_Baseplate_40x40_thin
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate Thin (40x40) Square";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_S_50BP.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Platforms\Platforms\data\bp_50_gar_s\bp_50_gar_s.rvmat"
		};
	};
	class 3AS_Prop_Baseplate_40x40_Corner;
	class FST_Baseplate_40x40_Corner_Jorge: 3AS_Prop_Baseplate_40x40_Corner
	{
		displayName="[41st] Baseplate (40x40) Corner (Jorge)";
		model="\3AS\3AS_Platforms\Platforms\Baseplate_40x40_corner.p3d";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_bp_Corner_cis_Jorge_co.paa"
		};
	};
	class 3AS_Prop_Baseplate_50x50;
	class FST_Prop_Baseplate_50: 3AS_Prop_Baseplate_50x50
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate (50x50)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_50BP.paa"
		};
		editorPreview="3as\3AS_Platforms\Platforms\EditorPreviews\3AS_Prop_Baseplate_10_GAR.jpg";
	};
	class FST_Prop_Baseplate_50_Jorge: 3AS_Prop_Baseplate_50x50
	{
		author="Gold";
		displayName="[41st] Jorge Baseplate (50x50)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_bp_cis_Jorge_co.paa"
		};
	};
	class FST_Prop_Baseplate_50_Square: 3AS_Prop_Baseplate_50x50
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate (50x50) Square";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_S_50BP.paa"
		};
		editorPreview="3as\3AS_Platforms\Platforms\EditorPreviews\3AS_Prop_Baseplate_10_GAR_Square.jpg";
	};
	class FST_Prop_Baseplate_50_Square_Jorge: FST_Prop_Baseplate_50_Square
	{
		author="Gold";
		displayName="[41st] Baseplate (50x50) Square (Jorge)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_bp_cis_Square_Jorge_co.paa"
		};
	};
	class 3AS_Prop_Baseplate_50x50_thin;
	class FST_Prop_Baseplate_50_Thin: 3AS_Prop_Baseplate_50x50_thin
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate Thin (50x50)";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_50BP.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Platforms\Platforms\data\bp_50_gar\bp_50_gar.rvmat"
		};
	};
	class FST_Prop_Baseplate_50_Thin_Square: 3AS_Prop_Baseplate_50x50_thin
	{
		author="Gold";
		displayName="[41st] Gweem Baseplate Thin (50x50) Square";
		editorCategory="FST_Faction";
		editorSubcategory="FST_Baseplates";
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\Baseplates\FST_GAR_S_50BP.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Platforms\Platforms\data\bp_50_gar_s\bp_50_gar_s.rvmat"
		};
	};
	class 3AS_Prop_Baseplate_50x50_Corner;
	class FST_Baseplate_50x50_Corner_Jorge: 3AS_Prop_Baseplate_50x50_Corner
	{
		displayName="[41st] Baseplate (50x50) Corner (Jorge)";
		model="\3AS\3AS_Platforms\Platforms\Baseplate_50x50_corner.p3d";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_bp_Corner_cis_Jorge_co.paa"
		};
	};
	///////////////
	////BANNERS////
	///////////////
	class 3AS_FOB_Banner_CIS_Prop;
	class FST_FOB_Banner_CIS_Jorge_Prop: 3AS_FOB_Banner_CIS_Prop
	{
		displayName="[41st] CIS Banner (Jorge)";
		scope=2;
		scopeCurator=2;
		model="3AS\3AS_structures\FOB\Banner.p3d";
		editorPreview="3AS\3AS_structures\FOB\editorPreviews\3AS_FOB_Banner_CIS_Prop.jpg";
		editorCategory="FST_Faction";
		editorSubcategory="FST_CIS_JORGE_FOB";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Props\Data\FST_CIS_Banner_Jorge_co.paa"
		};
	};
};
