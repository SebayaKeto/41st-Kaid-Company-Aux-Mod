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
class CfgVehicles
{
	class Strategic;
	class House;
	class House_F: House
	{
		class DestructionEffects;
	};
	class 3AS_Prop_Base_Animate: House_F
	{
	};
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
};
