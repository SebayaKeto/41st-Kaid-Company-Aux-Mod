class CfgPatches
{
	class FST_Vulture
	{
		units[]=
		{
			"FST_CIS_Vulture_Elite",
			"FST_CIS_Vulture_AA",
			"FST_CIS_Vulture_CAS",
			"FST_CIS_Vulture"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Data_F_Tank_Loadorder"
		};
	};
};
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateNV;
class SensorTemplateDataLink;
class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftPilot: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightPilot: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class Eventhandlers;
class CfgVehicles
{
	class 3AS_Vulture_Base_F;
	class FST_CIS_Vulture_Elite: 3AS_Vulture_Base_F
	{
		class SimpleObject
		{
			eden=1;
			verticalOffset=2.346;
			verticalOffsetWorld=-0.127;
			init="[this, '', []] call bis_fnc_initVehicle";
		};
		weapons[]=
		{
			"3AS_Vulture_Cannon",
			"FST_Rapture_AGM_Missile_AI",
			"FST_Stormfury_AA_Missile_AI",
			"CMFlareLauncher"
		};
		magazines[]=
		{
			"3AS_300Rnd_Vulture_Shells",
			"3AS_300Rnd_Vulture_Shells",
			"3AS_300Rnd_Vulture_Shells",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Rapture_12Rnd_AGM_Missile",
			"FST_Rapture_12Rnd_AGM_Missile",
			"240Rnd_CMFlare_Chaff_Magazine"
		};
		author="Daara";
		armor=100;
		armorStructural=8; //Was 5
		scope=2;
		side=0;
		forceInGarage=1;
		scopeCurator=2;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Droid_B1_OOM";
		displayName="[41st] Elite Vulture Droid";
		type="VAir";
		cost=10000000;
		threat[]={0.2,1,0.89999998};
	};
	class FST_CIS_Vulture_AA: 3AS_Vulture_Base_F
	{
		class SimpleObject
		{
			eden=1;
			verticalOffset=2.346;
			verticalOffsetWorld=-0.127;
			init="[this, '', []] call bis_fnc_initVehicle";
		};
		weapons[]=
		{
			"3AS_Vulture_Cannon",
			"FST_Stormfury_AA_Missile_AI",
			"FST_BTX42",
			"CMFlareLauncher"
		};
		magazines[]=
		{
			"3AS_300Rnd_Vulture_Shells",
			"3AS_300Rnd_Vulture_Shells",
			"3AS_300Rnd_Vulture_Shells",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Stormfury_12Rnd_AA_Missile",
			"240Rnd_CMFlare_Chaff_Magazine"
		};
		author="Daara";
		// armor=100;
		// armorStructural=5; //Was 5
		scope=2;
		side=0;
		forceInGarage=1;
		scopeCurator=2;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Droid_B1_OOM";
		displayName="[41st] Vulture Droid (AA)";
		type="VAir";
		cost=10000000;
		threat[]={0.2,1,0.89999998};
	};
	class FST_CIS_Vulture_CAS: 3AS_Vulture_Base_F
	{
		class SimpleObject
		{
			eden=1;
			verticalOffset=2.346;
			verticalOffsetWorld=-0.127;
			init="[this, '', []] call bis_fnc_initVehicle";
		};
		weapons[]=
		{
			"3AS_Vulture_Cannon",
			"FST_Rapture_AGM_Missile_AI",
			"FST_BTX42",
			"CMFlareLauncher"
		};
		magazines[]=
		{
			"3AS_300Rnd_Vulture_Shells",
			"3AS_300Rnd_Vulture_Shells",
			"3AS_300Rnd_Vulture_Shells",
			"FST_Rapture_12Rnd_AGM_Missile",
			"FST_Rapture_12Rnd_AGM_Missile",
			"240Rnd_CMFlare_Chaff_Magazine"
		};
		author="Daara";
		// armor=100;
		// armorStructural=5;
		scope=2;
		side=0;
		forceInGarage=1;
		scopeCurator=2;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Droid_B1_OOM";
		displayName="[41st] Vulture Droid (CAS)";
		type="VAir";
		cost=10000000;
		threat[]={0.2,1,0.89999998};
	};
	class FST_CIS_Vulture: 3AS_Vulture_Base_F
	{
		class SimpleObject
		{
			eden=1;
			verticalOffset=2.346;
			verticalOffsetWorld=-0.127;
			init="[this, '', []] call bis_fnc_initVehicle";
		};
		weapons[]=
		{
			"3AS_Vulture_Cannon",
			"FST_Rapture_AGM_Missile_AI",
			"FST_BTX42",
			"CMFlareLauncher"
		};
		magazines[]=
		{
			"3AS_300Rnd_Vulture_Shells",
			"3AS_300Rnd_Vulture_Shells",
			"3AS_300Rnd_Vulture_Shells",
			"240Rnd_CMFlare_Chaff_Magazine"
		};
		author="Daara";
		// armor=100;
		// armorStructural=5;
		scope=2;
		side=0;
		forceInGarage=1;
		scopeCurator=2;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Droid_B1_OOM";
		displayName="[41st] Vulture Droid (CAS)";
		type="VAir";
		cost=10000000;
		threat[]={0.2,1,0.89999998};
	};
};
