class CfgPatches
{
	class FST_Daara_venator
	{
		requiredAddons[]={};
		weapons[]={};
		units[]=
		{
			"FST_Daara_venator_zeus",
			"FST_Daara_venator_base",
			"FST_Daara_venator_base_2",
			"FST_Daara_venator_base_3",
			"FST_Daara_venator_base_4",
			"FST_Daara_venator_base_5",
			"FST_Daara_venator_base_6",
			"FST_Daara_ven_body1_1",
			"FST_Daara_ven_body1_2",
			"FST_Daara_ven_body2_1",
			"FST_Daara_ven_body2_2",
			"FST_Daara_ven_body2_3",
			"FST_Daara_ven_body3",
			"FST_Daara_ven_body4",
			"FST_Daara_ven_body5",
			"FST_Daara_ven_body6",
			"FST_Daara_ven_body7",
			"FST_Daara_ven_body8",
			"FST_Daara_ven_body9",
			"FST_Daara_ven_body10",
			"FST_Daara_ven_door",
			"FST_Daara_ven_door2",
			"ven_engine",
			"ven_interior1",
			"ven_interior2",
			"ven_interior3",
			"FST_ven_interior4",
			"ven_interior5",
			"ven_interior6",
			"ven_interior7",
			"ven_interior8",
			"FST_Daara_ven_bridge"
		};
		author="kripto202 adapted by Viz";
	};
};
class Eventhandlers;
class CfgVehicles
{
	class NonStrategic;
	class StaticShip;
	class ls_staticShip_base;
	class Ship;
	class Building;
	class House_F;
	class FloatingStructure_F;
	class thingx;
	class LandVehicle;
	class Motorcycle;
	class FlagCarrier;
	class Items_base_F;
	class FST_Daara_venator_zeus: ls_staticShip_base
	{
		author="kripto202 adapted by Viz";
		model="\ls\core\addons\props_staticships\venator\ls_venator_zeus.p3d";
		scope=2;
		scopecurator=2;
		editorpreview="";
		editorcategory="FST_Venator_Category";
		editorsubcategory="FST_Venator_Category_S";
		icon="iconObject_1x1";
		displayname="[41st] Daara Venator (Zeus)";
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
			"41st_Vehicles\Venator\Daara Venator\body1_Daara_venator_co.paa",
			"41st_Vehicles\Venator\Daara Venator\body2_Daara_venator_co.paa",
			"41st_Vehicles\Venator\Daara Venator\body3_Daara_venator_co.paa",
			"41st_Vehicles\Venator\Daara Venator\body4_Daara_venator_co.paa",
			"41st_Vehicles\Venator\Daara Venator\body5_Daara_venator_co.paa",
			"41st_Vehicles\Venator\Daara Venator\body6_Daara_venator_co.paa",
			"41st_Vehicles\Venator\Daara Venator\body7_Daara_venator_co.paa",
			"41st_Vehicles\Venator\Daara Venator\body8_Daara_venator_co.paa",
			"41st_Vehicles\Venator\Daara Venator\body9_Daara_venator_co.paa",
			"41st_Vehicles\Venator\Daara Venator\body10_Daara_venator_co.paa",
			"41st_Vehicles\Venator\Daara Venator\door_Daara_venator_co.paa",
			"\ls\core\addons\props_staticships\venator\data\engine_co.paa",
			"\ls\core\addons\props_staticships\venator\data\interior1_co.paa",
			"\ls\core\addons\props_staticships\venator\data\interior2_co.paa",
			"\ls\core\addons\props_staticships\venator\data\interior3_co.paa",
			"41st_Vehicles\Venator\data\FST_interior4_co.paa",
			"\ls\core\addons\props_staticships\venator\data\interior5_co.paa",
			"\ls\core\addons\props_staticships\venator\data\interior6_co.paa",
			"\ls\core\addons\props_staticships\venator\data\interior7_co.paa",
			"\ls\core\addons\props_staticships\venator\data\interior8_co.paa",
			"41st_Vehicles\Venator\Daara Venator\bridge_Daara_venator_co.paa"
		};
	};
	class FST_Daara_venator_base: StaticShip
	{
		author="kripto202";
		model="\ls\core\addons\props_staticships\venator\ls_venator.p3d";
		reversed=0;
		scope=2;
		scopecurator=1;
		editorpreview="";
		editorcategory="FST_Venator_Category";
		editorsubcategory="FST_Venator_Category_S";
		icon="iconObject_1x1";
		displayname="[41st] Daara Venator";
		mapsize=1326;
		destrType=0;
		featureType=2;
		multistructureparts[]=
		{
			
			{
				"FST_Daara_ven_body1_1",
				"body1_1"
			},
				
			{
				"FST_Daara_ven_body1_2",
				"body1_2"
			},
			
			{
				"FST_Daara_ven_body2_1",
				"body2_1"
			},
			
			{
				"FST_Daara_ven_body2_2",
				"body2_2"
			},
			
			{
				"FST_Daara_ven_body2_3",
				"body2_3"
			},
			
			{
				"FST_Daara_ven_body3",
				"body3"
			},
			
			{
				"FST_Daara_ven_body4",
				"body4"
			},
			
			{
				"FST_Daara_ven_body5",
				"body5"
			},
			
			{
				"FST_Daara_ven_body6",
				"body6"
			},
			
			{
				"FST_Daara_ven_body7",
				"body7"
			},
			
			{
				"FST_Daara_ven_body8",
				"body8"
			},
			
			{
				"FST_Daara_ven_body9",
				"body9"
			},
			
			{
				"FST_Daara_ven_body10",
				"body10"
			},
			
			{
				"FST_Daara_ven_door",
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
				"ls_staticShipPart_venator_interior4",
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
				"ls_staticShipPart_venator_interior8",
				"interior8"
			},
			
			{
				"FST_Daara_ven_bridge",
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
	class FST_Daara_venator_base_2: FST_Daara_venator_base
	{
		displayname="[41st] Daara Venator (Open)";
		multistructureparts[]=
		{
			
			{
				"FST_Daara_ven_body1_1",
				"body1_1"
			},
			
			{
				"FST_Daara_ven_body1_2",
				"body1_2"
			},
			
			{
				"FST_Daara_ven_body2_1",
				"body2_1"
			},
			
			{
				"FST_Daara_ven_body2_2",
				"body2_2"
			},
			
			{
				"FST_Daara_ven_body2_3",
				"body2_3"
			},
			
			{
				"FST_Daara_ven_body3",
				"body3"
			},
			
			{
				"FST_Daara_ven_body4",
				"body4"
			},
			
			{
				"FST_Daara_ven_body5",
				"body5"
			},
			
			{
				"FST_Daara_ven_body6",
				"body6"
			},
			
			{
				"FST_Daara_ven_body7",
				"body7"
			},
			
			{
				"FST_Daara_ven_body8",
				"body8"
			},
			
			{
				"FST_Daara_ven_body9",
				"body9"
			},
			
			{
				"FST_Daara_ven_body10",
				"body10"
			},
			
			{
				"FST_Daara_ven_door2",
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
				"ls_staticShipPart_venator_interior4",
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
				"ls_staticShipPart_venator_interior8",
				"interior8"
			},
			
			{
				"FST_Daara_ven_bridge",
				"bridge"
			}
		};
	};
	class FST_Daara_venator_base_3: FST_Daara_venator_base
	{
		displayname="[41st] Daara Venator (Hollowed)";
		multistructureparts[]=
		{
			
			{
				"FST_Daara_ven_body1_1",
				"body1_1"
			},
			
			{
				"FST_Daara_ven_body1_2",
				"body1_2"
			},
			
			{
				"FST_Daara_ven_body2_1",
				"body2_1"
			},
			
			{
				"FST_Daara_ven_body2_2",
				"body2_2"
			},
			
			{
				"FST_Daara_ven_body2_3",
				"body2_3"
			},
			
			{
				"FST_Daara_ven_body3",
				"body3"
			},
			
			{
				"FST_Daara_ven_body4",
				"body4"
			},
			
			{
				"FST_Daara_ven_body5",
				"body5"
			},
			
			{
				"FST_Daara_ven_body6",
				"body6"
			},
			
			{
				"FST_Daara_ven_body7",
				"body7"
			},
			
			{
				"FST_Daara_ven_body8",
				"body8"
			},
			
			{
				"FST_Daara_ven_body9",
				"body9"
			},
			
			{
				"FST_Daara_ven_body10",
				"body10"
			},
			
			{
				"FST_Daara_ven_door",
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
				"ls_staticShipPart_venator_interior8",
				"interior8"
			},
			
			{
				"FST_Daara_ven_bridge",
				"bridge"
			}
		};
	};
	class FST_Daara_venator_base_4: FST_Daara_venator_base
	{
		displayname="[41st] Daara Venator (Open Hollowed)";
		multistructureparts[]=
		{
			
			{
				"FST_Daara_ven_body1_1",
				"body1_1"
			},
			
			{
				"FST_Daara_ven_body1_2",
				"body1_2"
			},
			
			{
				"FST_Daara_ven_body2_1",
				"body2_1"
			},
			
			{
				"FST_Daara_ven_body2_2",
				"body2_2"
			},
			
			{
				"FST_Daara_ven_body2_3",
				"body2_3"
			},
			
			{
				"FST_Daara_ven_body3",
				"body3"
			},
			
			{
				"FST_Daara_ven_body4",
				"body4"
			},
			
			{
				"FST_Daara_ven_body5",
				"body5"
			},
			
			{
				"FST_Daara_ven_body6",
				"body6"
			},
			
			{
				"FST_Daara_ven_body7",
				"body7"
			},
			
			{
				"FST_Daara_ven_body8",
				"body8"
			},
			
			{
				"FST_Daara_ven_body9",
				"body9"
			},
			
			{
				"FST_Daara_ven_body10",
				"body10"
			},
			
			{
				"FST_Daara_ven_door2",
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
				"ls_staticShipPart_venator_interior8",
				"interior8"
			},
			
			{
				"FST_Daara_ven_bridge",
				"bridge"
			}
		};
	};
	class FST_Daara_venator_base_5: FST_Daara_venator_base
	{
		displayname="[41st] Daara Venator (Open Fully Hollowed)";
		multistructureparts[]=
		{
			
			{
				"FST_Daara_ven_body1_1",
				"body1_1"
			},
			
			{
				"FST_Daara_ven_body1_2",
				"body1_2"
			},
			
			{
				"FST_Daara_ven_body2_1",
				"body2_1"
			},
			
			{
				"FST_Daara_ven_body2_2",
				"body2_2"
			},
			
			{
				"FST_Daara_ven_body2_3",
				"body2_3"
			},
			
			{
				"FST_Daara_ven_body3",
				"body3"
			},
			
			{
				"FST_Daara_ven_body4",
				"body4"
			},
			
			{
				"FST_Daara_ven_body5",
				"body5"
			},
			
			{
				"FST_Daara_ven_body6",
				"body6"
			},
			
			{
				"FST_Daara_ven_body7",
				"body7"
			},
			
			{
				"FST_Daara_ven_body8",
				"body8"
			},
			
			{
				"FST_Daara_ven_body9",
				"body9"
			},
			
			{
				"FST_Daara_ven_body10",
				"body10"
			},
			
			{
				"ls_staticShipPart_venator_engine",
				"engine"
			},
			
			{
				"ven_engine",
				"engine"
			},
			
			{
				"FST_Daara_ven_bridge",
				"bridge"
			}
		};
	};
	class FST_Daara_venator_base_6: FST_Daara_venator_base
	{
		displayname="[41st] Daara Venator (Fully Hollowed)";
		multistructureparts[]=
		{
			
			{
				"FST_Daara_ven_body1_1",
				"body1_1"
			},
			
			{
				"FST_Daara_ven_body1_2",
				"body1_2"
			},
			
			{
				"FST_Daara_ven_body2_1",
				"body2_1"
			},
			
			{
				"FST_Daara_ven_body2_2",
				"body2_2"
			},
			
			{
				"FST_Daara_ven_body2_3",
				"body2_3"
			},
			
			{
				"FST_Daara_ven_body3",
				"body3"
			},
			
			{
				"FST_Daara_ven_body4",
				"body4"
			},
			
			{
				"FST_Daara_ven_body5",
				"body5"
			},
			
			{
				"FST_Daara_ven_body6",
				"body6"
			},
			
			{
				"FST_Daara_ven_body7",
				"body7"
			},
			
			{
				"FST_Daara_ven_body8",
				"body8"
			},
			
			{
				"FST_Daara_ven_body9",
				"body9"
			},
			
			{
				"FST_Daara_ven_body10",
				"body10"
			},
			
			{
				"FST_Daara_ven_door",
				"door"
			},
			
			{
				"ven_engine",
				"engine"
			},
			
			{
				"FST_Daara_ven_bridge",
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
		class Hitpoints
		{
		};
		class DestructionEffects
		{
		};
		class Damage
		{
			tex[]={};
			mat[]={};
		};
		class AnimationSources
		{
		};
		class UserActions
		{
		};
	};
	class FST_Daara_ven_body1_1: ven_hull_base
	{
		displayname="[41st] Daara ven body1_1";
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
			"41st_Vehicles\Venator\Daara Venator\body1_Daara_venator_co.paa"
		};
	};
	class FST_Daara_ven_body1_2: ven_hull_base
	{
		displayname="[41st] Daara ven body1_2";
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
			"41st_Vehicles\Venator\Daara Venator\body1_Daara_venator_co.paa"
		};
	};
	class FST_Daara_ven_body2_1: ven_hull_base
	{
		displayname="[41st] Daara ven body2_1";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_body2_1.p3d";
		hiddenselections[]=
		{
			"body2"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Venator\Daara Venator\body2_Daara_venator_co.paa"
		};
	};
	class FST_Daara_ven_body2_2: ven_hull_base
	{
		displayname="[41st] Daara ven body2_2";
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
			"41st_Vehicles\Venator\Daara Venator\body2_Daara_venator_co.paa"
		};
	};
	class FST_Daara_ven_body2_3: ven_hull_base
	{
		displayname="[41st] Daara ven body2_3";
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
			"41st_Vehicles\Venator\Daara Venator\body2_Daara_venator_co.paa"
		};
	};
	class FST_Daara_ven_body3: ven_hull_base
	{
		displayname="[41st] Daara ven body_3";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_body3.p3d";
		hiddenselections[]=
		{
			"body3"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Venator\Daara Venator\body3_Daara_venator_co.paa"
		};
	};
	class FST_Daara_ven_body4: ven_hull_base
	{
		displayname="[41st] Daara ven body4";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_body4.p3d";
		hiddenselections[]=
		{
			"body4"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Venator\Daara Venator\body4_Daara_venator_co.paa"
		};
	};
	class FST_Daara_ven_body5: ven_hull_base
	{
		displayname="[41st] Daara ven body5";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_body5.p3d";
		hiddenselections[]=
		{
			"body5"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Venator\Daara Venator\body5_Daara_venator_co.paa"
		};
	};
	class FST_Daara_ven_body6: ven_hull_base
	{
		displayname="[41st] Daara ven body6";
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
			"41st_Vehicles\Venator\Daara Venator\body6_Daara_venator_co.paa"
		};
	};
	class FST_Daara_ven_body7: ven_hull_base
	{
		displayname="[41st] Daara ven body7";
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
			"41st_Vehicles\Venator\Daara Venator\body7_Daara_venator_co.paa"
		};
	};
	class FST_Daara_ven_body8: ven_hull_base
	{
		displayname="[41st] Daara ven body8";
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
			"41st_Vehicles\Venator\Daara Venator\body8_Daara_venator_co.paa"
		};
	};
	class FST_Daara_ven_body9: ven_hull_base
	{
		displayname="[41st] Daara ven body9";
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
			"41st_Vehicles\Venator\Daara Venator\body9_Daara_venator_co.paa"
		};
	};
	class FST_Daara_ven_body10: ven_hull_base
	{
		displayname="[41st] Daara ven body10";
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
			"41st_Vehicles\Venator\Daara Venator\body10_Daara_venator_co.paa"
		};
	};
	class FST_Daara_ven_door: ven_hull_base
	{
		displayname="[41st] Daara ven door";
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
			"41st_Vehicles\Venator\Daara Venator\door_Daara_venator_co.paa",
			""
		};
	};
	class FST_Daara_ven_door2: ven_hull_base
	{
		displayname="[41st] Daara ven door";
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
			"41st_Vehicles\Venator\Daara Venator\door_Daara_venator_co.paa"
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
	class FST_ven_interior4: ven_hull_base
	{
		displayname="[41st] ven interior4";
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
			"41st_Vehicles\Venator\data\FST_interior4_co.paa",
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
	class ven_interior8: ven_hull_base
	{
		displayname="ven interior8";
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
			"\ls\core\addons\props_staticships\venator\data\interior8_co.paa"
		};	
	};
	class FST_Daara_ven_bridge: ven_hull_base
	{
		displayname="[41st] Daara ven bridge";
		scope=2;
		scopecurator=2;
		editorpreview="";
		model="\ls\core\addons\props_staticships\venator\ls_venator_bridge.p3d";
		hiddenSelections[]=
		{
			"bridge"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\Venator\Daara Venator\bridge_Daara_venator_co.paa"
		};
	};
};
class cfgMods
{
	author="";
	timepacked="1637225106";
};
