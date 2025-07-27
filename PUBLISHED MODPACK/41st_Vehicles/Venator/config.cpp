class CfgPatches
{
	class FST_venator
	{
		requiredAddons[]={};
		weapons[]={};
		units[]=
		{
			"FST_venator_zeus",
			"FST_venator_base",
			"FST_venator_base_2",
			"FST_venator_base_3",
			"FST_venator_base_4",
			"FST_venator_base_5",
			"FST_venator_base_6",
			"FST_ven_body1_1",
			"FST_ven_body1_2",
			"ven_body2_1",
			"ven_body2_2",
			"ven_body2_3",
			"ven_body3",
			"FST_ven_body4",
			"FST_ven_body5",
			"FST_ven_body6",
			"FST_ven_body7",
			"ven_body8",
			"FST_ven_body9",
			"ven_body10",
			"FST_ven_door",
			"FST_ven_door2",
			"ven_engine",
			"ven_interior1",
			"ven_interior2",
			"ven_interior3",
			"FST_ven_interior4",
			"ven_interior5",
			"ven_interior6",
			"ven_interior7",
			"ven_interior8",
			"FST_Ven_bridge_White"
		};
		author="kripto202 adapted by Viz";
	};
};
class Eventhandlers;
class CfgVehicles
{
	class NonStrategic;
	class StaticShip;
	class Ship;
	class Building;
	class House_F;
	class FloatingStructure_F;
	class thingx;
	class LandVehicle;
	class Motorcycle;
	class FlagCarrier;
	class Items_base_F;
	class FST_venator_zeus: House_F
	{
		author="kripto202 adapted by Viz";
		model="\ls\core\addons\props_staticships\venator\ls_venator_zeus.p3d";
		scope=2;
		scopecurator=2;
		editorpreview="";
		editorcategory="FST_Venator_Category";
		editorsubcategory="FST_Venator_Category_S";
		icon="iconObject_1x1";
		displayname="[41st] Venator (Zeus)";
		hiddenselections[]=
		{
			"body1",
			"body2",
			"body3",
			"body4",
			"body5",
			"body6",
			"body7",
			"body8",
			"body9",
			"body10",
			"door1",
			"engine",
			"interior1",
			"interior2",
			"interior3",
			"interior4",
			"interior5",
			"interior6",
			"interior7",
			"interior8",
			"bridge"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Venator\data\body1_co.paa",
			"\ls\core\addons\props_staticships\venator\data\body2_co.paa",
			"\ls\core\addons\props_staticships\venator\data\body3_co.paa",
			"41st_Vehicles\Venator\data\body4_co.paa",
			"41st_Vehicles\Venator\data\body5_co.paa",
			"41st_Vehicles\Venator\data\body6_co.paa",
			"41st_Vehicles\Venator\data\body7_co.paa",
			"\ls\core\addons\props_staticships\venator\data\body8_co.paa",
			"41st_Vehicles\Venator\data\body9_co.paa",
			"\ls\core\addons\props_staticships\venator\data\body10_co.paa",
			"41st_Vehicles\Venator\data\door_co.paa",
			"\ls\core\addons\props_staticships\venator\data\engine_co.paa",
			"\ls\core\addons\props_staticships\venator\data\interior1_co.paa",
			"\ls\core\addons\props_staticships\venator\data\interior2_co.paa",
			"\ls\core\addons\props_staticships\venator\data\interior3_co.paa",
			"41st_Vehicles\Venator\data\FST_interior_4_co.paa",
			"\ls\core\addons\props_staticships\venator\data\interior5_co.paa",
			"\ls\core\addons\props_staticships\venator\data\interior6_co.paa",
			"\ls\core\addons\props_staticships\venator\data\interior7_co.paa",
			"41st_Vehicles\Venator\data\FST_interior_8_co.paa",
			"41st_Vehicles\Venator\data\FST_Bridge_White_co.paa"
		};
	};
	class FST_venator_base: StaticShip
	{
		author="kripto202";
		model="\ls\core\addons\props_staticships\venator\ls_venator.p3d";
		reversed=0;
		scope=2;
		scopecurator=1;
		editorpreview="";
		editorcategory="FST_Venator_Category";
		editorsubcategory="FST_Venator_Category_S";
		vehicleClass="Structures_Military";
		icon="iconObject_1x1";
		displayname="[41st] Venator";
		mapsize=1326;
		destrType=0;
		featureType=2;
		multistructureparts[]=
		{
			
			{
				"FST_ven_body1_1",
				"body1_1"
			},
			
			{
				"FST_ven_body1_2",
				"body1_2"
			},
			
			{
				"ls_staticShipPart_venator_body2_1",
				"body2_1"
			},
			
			{
				"ls_staticShipPart_venator_body2_2",
				"body2_2"
			},
			
			{
				"ls_staticShipPart_venator_body2_3",
				"body2_3"
			},
			
			{
				"ls_staticShipPart_venator_body3",
				"body3"
			},
			
			{
				"FST_ven_body4",
				"body4"
			},
			
			{
				"FST_ven_body5",
				"body5"
			},
			
			{
				"FST_ven_body6",
				"body6"
			},
			
			{
				"FST_ven_body7",
				"body7"
			},
			
			{
				"ls_staticShipPart_venator_body8",
				"body8"
			},
			
			{
				"FST_ven_body9",
				"body9"
			},
			
			{
				"ven_body10",
				"body10"
			},
			
			{
				"FST_ven_door",
				"door"
			},
			
			{
				"ls_staticShipPart_venator_engine",
				"engine"
			},
			
			{
				"ls_staticShipPart_venator_interior1",
				"interior1"
			},
			
			{
				"ls_staticShipPart_venator_interior2",
				"interior2"
			},
			
			{
				"ls_staticShipPart_venator_interior3",
				"interior3"
			},
			
			{
				"FST_Ven_Interior_4",
				"interior4"
			},
			
			{
				"ls_staticShipPart_venator_interior5",
				"interior5"
			},
			
			{
				"ls_staticShipPart_venator_interior6",
				"interior6"
			},
			
			{
				"ls_staticShipPart_venator_interior7",
				"interior7"
			},
			
			{
				"FST_Ven_Interior_8",
				"interior8"
			},
			
			{
				"FST_Ven_bridge_White",
				"bridge"
			}
		};
		class Eventhandlers
		{
			init="_this call BIS_fnc_Destroyer01Init;";
			attributesChanged3DEN="_this call BIS_fnc_Destroyer01PosUpdate;";
			dragged3DEN="_this call BIS_fnc_Destroyer01PosUpdate;";
			registeredToWorld3DEN="_this call BIS_fnc_Destroyer01EdenInit;";
			unregisteredFromWorld3DEN="_this call BIS_fnc_Destroyer01EdenDelete;";
		};
	};
	class FST_venator_base_2: FST_venator_base
	{
		displayname="[41st] Venator (Open)";
		multistructureparts[]=
		{
			
			{
				"FST_ven_body1_1",
				"body1_1"
			},
			
			{
				"FST_ven_body1_2",
				"body1_2"
			},
			
			{
				"ven_body2_1",
				"body2_1"
			},
			
			{
				"ven_body2_2",
				"body2_2"
			},
			
			{
				"ven_body2_3",
				"body2_3"
			},
			
			{
				"ven_body3",
				"body3"
			},
			
			{
				"FST_ven_body4",
				"body4"
			},
			
			{
				"FST_ven_body5",
				"body5"
			},
			
			{
				"FST_ven_body6",
				"body6"
			},
			
			{
				"FST_ven_body7",
				"body7"
			},
			
			{
				"ven_body8",
				"body8"
			},
			
			{
				"FST_ven_body9",
				"body9"
			},
			
			{
				"ven_body10",
				"body10"
			},
			
			{
				"FST_ven_door2",
				"door"
			},
			
			{
				"ven_engine",
				"engine"
			},
			
			{
				"ven_interior1",
				"interior1"
			},
			
			{
				"ven_interior2",
				"interior2"
			},
			
			{
				"ven_interior3",
				"interior3"
			},
			
			{
				"FST_ven_interior_4",
				"interior4"
			},
			
			{
				"ven_interior5",
				"interior5"
			},
			
			{
				"ven_interior6",
				"interior6"
			},
			
			{
				"ven_interior7",
				"interior7"
			},
			
			{
				"FST_ven_interior_8",
				"interior8"
			},
			
			{
				"FST_Ven_bridge_White",
				"bridge"
			}
		};
	};
	class FST_venator_base_3: FST_venator_base
	{
		displayname="[41st] Venator (Hollowed)";
		multistructureparts[]=
		{
			
			{
				"FST_ven_body1_1",
				"body1_1"
			},
			
			{
				"FST_ven_body1_2",
				"body1_2"
			},
			
			{
				"ven_body2_1",
				"body2_1"
			},
			
			{
				"ven_body2_2",
				"body2_2"
			},
			
			{
				"ven_body2_3",
				"body2_3"
			},
			
			{
				"ven_body3",
				"body3"
			},
			
			{
				"FST_ven_body4",
				"body4"
			},
			
			{
				"FST_ven_body5",
				"body5"
			},
			
			{
				"FST_ven_body6",
				"body6"
			},
			
			{
				"FST_ven_body7",
				"body7"
			},
			
			{
				"ven_body8",
				"body8"
			},
			
			{
				"FST_ven_body9",
				"body9"
			},
			
			{
				"ven_body10",
				"body10"
			},
			
			{
				"FST_ven_door",
				"door"
			},
			
			{
				"ven_engine",
				"engine"
			},
			
			{
				"ven_interior1",
				"interior1"
			},
			
			{
				"ven_interior2",
				"interior2"
			},
			
			{
				"ven_interior3",
				"interior3"
			},
			
			{
				"FST_Ven_Interior_4",
				"interior4"
			},
			
			{
				"ven_interior5",
				"interior5"
			},
			
			{
				"ven_interior6",
				"interior6"
			},
			
			{
				"ven_interior7",
				"interior7"
			},
			
			{
				"FST_Ven_Interior_8",
				"interior8"
			},
			
			{
				"FST_Ven_bridge_White",
				"bridge"
			}
		};
	};
	class FST_venator_base_4: FST_venator_base
	{
		displayname="[41st] Venator (Open Hollowed)";
		multistructureparts[]=
		{
			
			{
				"FST_ven_body1_1",
				"body1_1"
			},
			
			{
				"FST_ven_body1_2",
				"body1_2"
			},
			
			{
				"ven_body2_1",
				"body2_1"
			},
			
			{
				"ven_body2_2",
				"body2_2"
			},
			
			{
				"ven_body2_3",
				"body2_3"
			},
			
			{
				"ven_body3",
				"body3"
			},
			
			{
				"FST_ven_body4",
				"body4"
			},
			
			{
				"FST_ven_body5",
				"body5"
			},
			
			{
				"FST_ven_body6",
				"body6"
			},
			
			{
				"FST_ven_body7",
				"body7"
			},
			
			{
				"ven_body8",
				"body8"
			},
			
			{
				"FST_ven_body9",
				"body9"
			},
			
			{
				"ven_body10",
				"body10"
			},
			
			{
				"FST_ven_door2",
				"door"
			},
			
			{
				"ven_engine",
				"engine"
			},
			
			{
				"ven_interior1",
				"interior1"
			},
			
			{
				"ven_interior2",
				"interior2"
			},
			
			{
				"ven_interior3",
				"interior3"
			},
			
			{
				"FST_Ven_Interior_4",
				"interior4"
			},
			
			{
				"ven_interior5",
				"interior5"
			},
			
			{
				"ven_interior6",
				"interior6"
			},
			
			{
				"ven_interior7",
				"interior7"
			},
			
			{
				"FST_Ven_Interior_8",
				"interior8"
			},
			
			{
				"FST_Ven_bridge_White",
				"bridge"
			}
		};
	};
	class FST_venator_base_5: FST_venator_base
	{
		displayname="[41st] Venator (Open Fully Hollowed)";
		multistructureparts[]=
		{
			
			{
				"FST_ven_body1_1",
				"body1_1"
			},
			
			{
				"FST_ven_body1_2",
				"body1_2"
			},
			
			{
				"ven_body2_1",
				"body2_1"
			},
			
			{
				"ven_body2_2",
				"body2_2"
			},
			
			{
				"ven_body2_3",
				"body2_3"
			},
			
			{
				"ven_body3",
				"body3"
			},
			
			{
				"FST_ven_body4",
				"body4"
			},
			
			{
				"FST_ven_body5",
				"body5"
			},
			
			{
				"FST_ven_body6",
				"body6"
			},
			
			{
				"FST_ven_body7",
				"body7"
			},
			
			{
				"ven_body8",
				"body8"
			},
			
			{
				"FST_ven_body9",
				"body9"
			},
			
			{
				"ven_body10",
				"body10"
			},
			
			{
				"FST_ven_door2",
				"door"
			},
			
			{
				"ven_engine",
				"engine"
			},
			
			{
				"FST_Ven_bridge_White",
				"bridge"
			}
		};
	};
	class FST_venator_base_6: FST_venator_base
	{
		displayname="[41st] Venator (Fully Hollowed)";
		multistructureparts[]=
		{
			
			{
				"FST_ven_body1_1",
				"body1_1"
			},
			
			{
				"FST_ven_body1_2",
				"body1_2"
			},
			
			{
				"ven_body2_1",
				"body2_1"
			},
			
			{
				"ven_body2_2",
				"body2_2"
			},
			
			{
				"ven_body2_3",
				"body2_3"
			},
			
			{
				"ven_body3",
				"body3"
			},
			
			{
				"FST_ven_body4",
				"body4"
			},
			
			{
				"FST_ven_body5",
				"body5"
			},
			
			{
				"FST_ven_body6",
				"body6"
			},
			
			{
				"FST_ven_body7",
				"body7"
			},
			
			{
				"ven_body8",
				"body8"
			},
			
			{
				"FST_ven_body9",
				"body9"
			},
			
			{
				"ven_body10",
				"body10"
			},
			
			{
				"FST_ven_door",
				"door"
			},
			
			{
				"ven_engine",
				"engine"
			},
			
			{
				"FST_Ven_bridge_White",
				"bridge"
			}
		};
	};
	class ven_hull_base: House_F
	{
		reversed=0;
		scope=1;
		scopeCurator=0;
		author="kripto202";
		displayname="ven_hull_base";
		editorpreview="";
		editorcategory="FST_Venator_Category";
		editorsubcategory="FST_Venator_Category_P";
		icon="iconObject_1x1";
		mapsize=70;
		model="\ls\core\addons\props_staticships\venator\ls_venator.p3d";
		armor=1000000000000000000;
		hideUnitInfo=1;
		nameSound="ship";
		featureType=2;
		class Hitpoints{};
		class DestructionEffects{};
		class Damage
		{
			tex[]={};
			mat[]={};
		};
		class AnimationSources{};
		class UserActions{};
	};
	class FST_ven_body1_1: ven_hull_base
	{
		displayname="[41st] ven body1_1";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_body1_1.p3d";
		hiddenselections[]=
		{
			"body1"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Venator\data\body1_co.paa"
		};
	};
	class FST_ven_body1_2: ven_hull_base
	{
		displayname="[41st] ven body1_2";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_body1_2.p3d";
		hiddenselections[]=
		{
			"body1"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Venator\data\body1_co.paa"
		};
	};
	class ven_body2_1: ven_hull_base
	{
		displayname="ven body2_1";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_body2_1.p3d";
		hiddenSelections[]=
		{
			"body2"
		};
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\props_staticships\venator\data\body2_co.paa"
		};
	};
	class ven_body2_2: ven_hull_base
	{
		displayname="ven body2_2";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_body2_2.p3d";
		hiddenselections[]=
		{
			"body2"
		};
		hiddenselectionstextures[]=
		{
			"\ls\core\addons\props_staticships\venator\data\body2_co.paa"
		};
	};
	class ven_body2_3: ven_hull_base
	{
		displayname="ven body2_3";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_body2_3.p3d";
		hiddenselections[]=
		{
			"body2"
		};
		hiddenselectionstextures[]=
		{
			"ls\core\addons\props_staticships\venator\data\body2_co.paa"
		};
	};
	class ven_body3: ven_hull_base
	{
		displayname="ven body_3";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_body3.p3d";
		hiddenSelections[]=
		{
			"body3"
		};
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\props_staticships\venator\data\body3_co.paa"
		};
	};
	class FST_ven_body4: ven_hull_base
	{
		displayname="[41st] ven body4";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_body4.p3d";
		hiddenSelections[]=
		{
			"body4"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Venator\data\body4_co.paa"
		};
	};
	class FST_ven_body5: ven_hull_base
	{
		displayname="[41st] ven body5";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_body5.p3d";
		hiddenSelections[]=
		{
			"body5"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Venator\data\body5_co.paa"
		};
	};
	class FST_ven_body6: ven_hull_base
	{
		displayname="[41st] ven body6";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_body6.p3d";
		hiddenselections[]=
		{
			"body6"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Venator\data\body6_co.paa"
		};
	};
	class FST_ven_body7: ven_hull_base
	{
		displayname="[41st] ven body7";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_body7.p3d";
		hiddenselections[]=
		{
			"body7"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Venator\data\body7_co.paa"
		};
	};
	class ven_body8: ven_hull_base
	{
		displayname="ven body8";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_body8.p3d";
		hiddenselections[]=
		{
			"body8"
		};
		hiddenselectionstextures[]=
		{
			"\ls\core\addons\props_staticships\venator\data\body8_co.paa"
		};
	};
	class FST_ven_body9: ven_hull_base
	{
		displayname="[41st] ven body9";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_body9.p3d";
		hiddenselections[]=
		{
			"body9"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Venator\data\body9_co.paa"
		};
	};
	class ven_body10: ven_hull_base
	{
		displayname="ven body10";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_body10.p3d";
		hiddenselections[]=
		{
			"body10"
		};
		hiddenselectionstextures[]=
		{
			"\ls\core\addons\props_staticships\venator\data\body10_co.paa"
		};
	};
	class FST_ven_door: ven_hull_base
	{
		displayname="[41st] ven door";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_door.p3d";
		hiddenselections[]=
		{
			"door1",
			"door2"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Venator\data\door_co.paa",
			""
		};
	};
	class FST_ven_door2: ven_hull_base
	{
		displayname="[41st] ven door";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_door.p3d";
		hiddenselections[]=
		{
			"door1",
			"door2"
		};
		hiddenselectionstextures[]=
		{
			"",
			"41st_Vehicles\Venator\data\door_co.paa"
		};
	};
	class ven_engine: ven_hull_base
	{
		displayname="ven engine";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_engine.p3d";
		hiddenselections[]=
		{
			"engine"
		};
		hiddenselectionstextures[]=
		{
			"\ls\core\addons\props_staticships\venator\data\engine_co.paa"
		};
	};
	class ven_interior1: ven_hull_base
	{
		displayname="ven interior1";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_interior1.p3d";
		hiddenSelections[]=
		{
			"interior1"
		};
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\props_staticships\venator\data\interior1_co.paa"
		};
	};
	class ven_interior2: ven_hull_base
	{
		displayname="ven interior2";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_interior2.p3d";
		hiddenSelections[]=
		{
			"interior2"
		};
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\props_staticships\venator\data\interior2_co.paa"
		};
	};
	class ven_interior3: ven_hull_base
	{
		displayname="ven interior3";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_interior3.p3d";
		hiddenSelections[]=
		{
			"interior3"
		};
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\props_staticships\venator\data\interior3_co.paa"
		};
	};
	class FST_Ven_Interior_4: ven_hull_base
	{
		displayname="[41st] Ven Interior 4";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_interior4.p3d";
		hiddenSelections[]=
		{
			"interior4"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\Venator\data\FST_Interior_4_co.paa"
		};
	};
	class ven_interior5: ven_hull_base
	{
		displayname="ven interior5";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_interior5.p3d";
		hiddenSelections[]=
		{
			"interior5"
		};
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\props_staticships\venator\data\interior5_co.paa"
		};
	};
	class ven_interior6: ven_hull_base
	{
		displayname="ven interior6";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_interior6.p3d";
		hiddenSelections[]=
		{
			"interior6"
		};
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\props_staticships\venator\data\interior6_co.paa"
		};
	};
	class ven_interior7: ven_hull_base
	{
		displayname="ven interior7";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_ventator_interior7.p3d";
		hiddenSelections[]=
		{
			"interior7"
		};
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\props_staticships\venator\data\interior7_co.paa"
		};
	};
	class FST_Ven_Interior_8: ven_hull_base
	{
		displayname="[41st] Ven Interior 8";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_interior8.p3d";
		hiddenSelections[]=
		{
			"interior8"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\Venator\data\FST_Interior_8_co.paa"
		};
	};
	class FST_Ven_bridge_White: ven_hull_base
	{
		displayname="[41st] Ven Bridge (White)";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_bridge.p3d";
		hiddenSelections[]=
		{
			"bridge"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\Venator\data\FST_Bridge_White_co.paa"
		};
	};
};
class cfgMods
{
	author="";
	timepacked="1637225106";
};
