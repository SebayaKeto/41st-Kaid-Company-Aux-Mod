class CfgPatches
{
	class 3AS_Structures_FOB
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
		model="\3AS\3AS_structures\FOB\3AS_cis_Wall_gate_v2.p3d";
		displayName="CIS Wall Gate (DJ)";
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
};
