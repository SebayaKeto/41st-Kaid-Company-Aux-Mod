class cfgpatches
{
	class FST_Quasar
	{
		author="Gold";
		requiredAddons[]=
		{
			"kobra_core"
		};
		units[]=
		{
			"FST_Quasar"
		};
		weapons[]={};
	};
};
class cfgvehicles
{
	class House_F;
	class FST_Quasar: House_F
	{
		scope=2;
		scopecurator=2;
		author="Gold";
		displayName="[41st] Quasar";
		model="\kobra\442_ships\quasar\quasar.p3d";
		editorcategory="FST_Faction";
		editorsubcategory="FST_Air_Vehicle";
		vehicleClass="Structures";
		hiddenselections[]=
		{
			"body1",
			"body2",
			"engine",
			"guns",
			"interior1",
			"interior2",
			"interior3",
			"interior4",
			"door1",
			"door2",
			"frame"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Quasar\Data\FST_body1_co.paa",
			"41st_Vehicles\Quasar\Data\FST_body2_co.paa",
			"41st_Vehicles\Quasar\Data\FST_engine_co.paa",
			"41st_Vehicles\Quasar\Data\FST_guns_co.paa",
			"41st_Vehicles\Quasar\Data\FST_interior1_co.paa",
			"41st_Vehicles\Quasar\Data\FST_interior2_co.paa",
			"41st_Vehicles\Quasar\Data\FST_interior3_co.paa",
			"41st_Vehicles\Quasar\Data\FST_interior4_co.paa",
			"kobra\442_ships\quasar\data\doors_co.paa",
			"kobra\442_ships\quasar\data\doors_co.paa",
			"kobra\442_ships\quasar\data\frame_co.paa"
		};
	};
};
