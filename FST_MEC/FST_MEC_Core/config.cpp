////////////////////////////////////////////////////////////////////
//DeRap: config.bin
//Produced from mikero's Dos Tools Dll version 9.45
//https://mikero.bytex.digital/Downloads
//'now' is Wed Apr 24 11:48:44 2024 : 'file' last modified on Wed Apr 17 19:43:44 2024
////////////////////////////////////////////////////////////////////
#include "functions.cpp"
#define _ARMA_

class CfgPatches
{
	class FST_MEC_Core
	{
		author = "Maldova";
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"A3_Data_F_Enoch_Loadorder","CBA_MAIN","FST_Core","FST_Common"};
		requiredversion = 0.1;
	};
};
class CfgEditorCategories
{
	class FST_MEC_CategoryStructures
	{
		displayname = "[MEC] Structures";
	};
	class FST_MEC_CategoryPowerSystems
	{
		displayname = "[MEC] Power Systems";
	};
	class FST_MEC_CategoryEquipment
	{
		displayname = "[MEC] Equipment";
	};
	class FST_MEC_CategoryAegisBarriers
	{
		displayname = "[MEC] Aegis";
	};
};
class CfgEditorSubcategories
{
	class FST_MEC_SubcategoryBarriers
	{
		displayName = "[MEC] Barriers";
	};
	class FST_MEC_SubcategoryPlatforms
	{
		displayName = "[MEC] Platforms";
	};
	class FST_MEC_SubcategoryBatteries
	{
		displayName = "[MEC] Batteries";
	};
	class FST_MEC_SubcategoryGenerators
	{
		displayName = "[MEC] Generators";
	};
	class FST_MEC_SubcategoryConduits
	{
		displayName = "[MEC] Power Conduits";
	};
	class FST_MEC_BreakerBoxes
	{
		displayName = "[MEC] Breaker Boxes";
	};
	class FST_MEC_AegisBarriers_Duracrete
	{
		displayName = "[MEC] Duracrete Barriers";
	};
};