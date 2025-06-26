class cfgpatches
{
	class FST_Arquintens
	{
		author="Gold";
		requiredAddons[]=
		{
			"kobra_core"
		};
		units[]=
		{
			"FST_Arquitens"
		};
		weapons[]={};
	};
};
class cfgvehicles
{
	class House_F;
	class FST_Arquitens: House_F
	{
		scope=2;
		scopecurator=2;
		author="Gold";
		displayName="[41st] Arquitens";
		model="\kobra\442_ships\arquintens\arquintens.p3d";
		editorcategory="FST_Faction";
		editorsubcategory="FST_Air_Vehicle";
		vehicleClass="Structures";
		hiddenselections[]=
		{
			"body1",
			"body2",
			"engine"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Arquitens\Data\FST_body1_co.paa",
			"41st_Vehicles\Arquitens\Data\FST_body2_co.paa",
			"41st_Vehicles\Arquitens\Data\FST_engine_co.paa"
		};
	};
};
