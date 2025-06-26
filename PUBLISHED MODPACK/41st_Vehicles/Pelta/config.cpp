class cfgpatches
{
	class FST_Pelta
	{
		author="Gold";
		requiredAddons[]=
		{
			"kobra_core"
		};
		units[]=
		{
			"FST_Pelta"
		};
		weapons[]={};
	};
};
class cfgvehicles
{
	class House_F;
	class FST_Pelta: House_F
	{
		scope=2;
		scopecurator=2;
		author="Gold";
		displayName="[41st] Pelta Class Frigate";
		model="\kobra\442_ships\pelta\pelta_zeus.p3d";
		editorcategory="FST_Faction";
		editorsubcategory="FST_Air_Vehicle";
		vehicleClass="Structures";
		hiddenselections[]=
		{
			"body1",
			"body2",
			"greeble",
			"engine_wing",
			"engine",
			"hatch_open",
			"hatch_closed",
			"landing_gear"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Pelta\Data\FST_body1_co.paa",
			"41st_Vehicles\Pelta\Data\FST_body2_co.paa",
			"41st_Vehicles\Pelta\Data\FST_greeble_co.paa",
			"41st_Vehicles\Pelta\Data\FST_engine_wings_co.paa",
			"41st_Vehicles\Pelta\Data\FST_engine_co.paa",
			"",
			"41st_Vehicles\Pelta\Data\FST_hatch_co.paa",
			""
		};
	};
	class FST_Pelta_Landed: FST_Pelta
	{
		displayName="[41st] Pelta Class Frigate (Landed)";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Pelta\Data\FST_body1_co.paa",
			"41st_Vehicles\Pelta\Data\FST_body2_co.paa",
			"41st_Vehicles\Pelta\Data\FST_greeble_co.paa",
			"41st_Vehicles\Pelta\Data\FST_engine_wings_co.paa",
			"41st_Vehicles\Pelta\Data\FST_engine_co.paa",
			"",
			"41st_Vehicles\Pelta\Data\FST_hatch_co.paa",
			"41st_Vehicles\Pelta\Data\FST_landing_gear_co.paa"
		};
	};
};
