////////////////////////////////////////////////////////////////////
//DeRap: config.bin
//Produced from mikero's Dos Tools Dll version 9.45
//https://mikero.bytex.digital/Downloads
//'now' is Wed Apr 24 11:48:44 2024 : 'file' last modified on Wed Apr 17 19:43:44 2024
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class FST_Core
	{
		author = "Maldova";
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"A3_Data_F_Enoch_Loadorder","CBA_MAIN"};
		requiredversion = 0.1;
	};
};
class CfgEditorCategories
{
	class FST_CatagoryStructures_GAR
	{
		displayname = "$STR_FST_CORE_CAT_STRUCTURES_GAR";
	};
	class FST_CatagoryBarricades
	{
		displayname = "$STR_FST_CORE_CAT_BARRICADES";
	};
	class FST_CatagoryTrenches
	{
		displayname = "$STR_FST_CORE_CAT_TRENCHES";
	};
	class FST_CatagoryMajorOutpost
	{
		displayname = "$STR_FST_CORE_CAT_OUTPOST_MAJOR";
	};
	class FST_CatagoryMinorOutpost
	{
		displayname = "$STR_FST_CORE_CAT_OUTPOST_MINOR";
	};
	class FST_CatagoryVegetationKashyyyk
	{
		displayname = "$STR_FST_CORE_CAT_KASHYYYK_VEGETATION";
	};
	class FST_CatagoryCECTypeOneCratesRSU
	{
		displayname = "$STR_FST_CORE_CAT_CEC_TYPE1_CRATES";
	};
	class FST_CatagoryCECTypeTwoCratesRSU
	{
		displayname = "$STR_FST_CORE_CAT_CEC_TYPE2_CRATES";
	};
	class FST_Catagory_Vehicles_Land
	{
		displayname = "$STR_FST_CORE_CAT_VEHICLES_LAND";
	};
};
class CfgEditorSubcategories
{
	class FST_Subcategory_SecurityBarricades
	{
		displayName = "$STR_FST_CORE_SUBCAT_SECURITY_BARRICADES";
	};
	class FST_Subcategory_TrenchesEntrenchingTool
	{
		displayName = "$STR_FST_CORE_SUBCAT_TRENCHES_ENTRENCHING";
	};
	class FST_Subcategory_TrenchesEngineered
	{
		displayName = "$STR_FST_CORE_SUBCAT_TRENCHES_ENGINEERED";
	};
	class FST_Subcategory_TrenchesBastion
	{
		displayName = "$STR_FST_CORE_SUBCAT_TRENCHES_BASTION";
	};
	class FST_Subcategory_OutpostWallsNeutral
	{
		displayName = "$STR_FST_CORE_SUBCAT_OUTPOST_WALLS_NEUTRAL_LIGHT";
	};
	class FST_Subcategory_OutpostWallsNeutral_Medium
	{
		displayName = "$STR_FST_CORE_SUBCAT_OUTPOST_WALLS_NEUTRAL_MEDIUM";
	};
	class FST_Subcategory_OutpostWallsGAR
	{
		displayName = "$STR_FST_CORE_SUBCAT_OUTPOST_WALLS_GAR";
	};
	class FST_Subcategory_OutpostWallsCIS
	{
		displayName = "$STR_FST_CORE_SUBCAT_OUTPOST_WALLS_CIS";
	};
	class FST_Subcategory_OutpostWallsPirates
	{
		displayName = "$STR_FST_CORE_SUBCAT_OUTPOST_WALLS_PIRATES";
	};
	class FST_Subcategory_OutpostWallsBlackSun
	{
		displayName = "$STR_FST_CORE_SUBCAT_OUTPOST_WALLS_BLACKSUN";
	};
	class FST_Subcategory_OutpostWallsHuttCartel
	{
		displayName = "$STR_FST_CORE_SUBCAT_OUTPOST_WALLS_HUTTCARTEL";
	};
	class FST_Subcategory_KashyyykVines
	{
		displayName = "$STR_FST_CORE_SUBCAT_KASHYYYK_VINES";
	};
	class FST_CatagoryCECGeneric
	{
		displayname = "$STR_FST_CORE_SUBCAT_CEC_GENERIC";
	};
	class FST_CatagoryCECForce
	{
		displayname = "$STR_FST_CORE_SUBCAT_CEC_FORCE_SUPPRESSANT";
	};
	class FST_CatagoryCECLiquid
	{
		displayname = "$STR_FST_CORE_SUBCAT_CEC_LIQUID";
	};
	class FST_CatagoryCECMedical
	{
		displayname = "$STR_FST_CORE_SUBCAT_CEC_MEDICAL";
	};
	class FST_CatagoryCECAmmunition
	{
		displayname = "$STR_FST_CORE_SUBCAT_CEC_AMMUNITION";
	};
	class FST_CatagoryCECResupplies
	{
		displayname = "$STR_FST_CORE_SUBCAT_CEC_RESUPPLIES";
	};
	class FST_Catagory_Vehicles_Land_APC
	{
		displayname = "$STR_FST_CORE_CAT_VEHICLES_APC";
	};
};
class CfgCloudlets
{
	class Default;
	class ExhaustSmoke: Default{};
	class FST_Proj_Blue_Emissive: Default
	{
		interval = 0.004;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 13;
		particleFSFrameCount = 1;
		particleFSLoop = 0;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 0.16;
		moveVelocity[] = {0,0.8,0};
		rotationVelocity = 1;
		weight = 1;
		volume = 0.9;
		rubbing = 0.05;
		size[] = {0.1,0.2,0.28};
		color[] = {{0.2,0.6,1,0.9},{0.35,0.8,1,0.45},{0.55,0.9,1,0.02}};
		animationSpeed[] = {1};
		randomDirectionPeriod = 0.03;
		randomDirectionIntensity = 0.02;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 0.05;
		positionVar[] = {0.02,0.02,0.02};
		moveVelocityVar[] = {0.08,0.08,0.08};
		rotationVelocityVar = 1;
		sizeVar = 0.04;
		colorVar[] = {0.03,0.03,0.03,0.02};
		randomDirectionPeriodVar = 0.01;
		randomDirectionIntensityVar = 0.01;
	};
	class FST_Proj_Blue_Emissive_Small: FST_Proj_Blue_Emissive
	{
		interval = 0.005;
		lifeTime = 0.12;
		size[] = {0.06,0.12,0.18};
		moveVelocity[] = {0,0.6,0};
		color[] = {{0.2,0.58,1,0.78},{0.32,0.74,1,0.32},{0.5,0.86,1,0.01}};
		sizeVar = 0.025;
	};
	class FST_Proj_Blue_Emissive_Heavy: FST_Proj_Blue_Emissive
	{
		interval = 0.003;
		lifeTime = 0.22;
		size[] = {0.16,0.32,0.46};
		moveVelocity[] = {0,1.1,0};
		color[] = {{0.22,0.65,1,1},{0.45,0.9,1,0.58},{0.7,0.97,1,0.04}};
		sizeVar = 0.06;
	};

	class FST_Proj_DarkBlue_Emissive_Medium: FST_Proj_Blue_Emissive
	{
		interval = 0.004;
		lifeTime = 0.18;
		size[] = {0.12,0.24,0.36};
		moveVelocity[] = {0,0.9,0};
		color[] = {{0.1,0.35,0.8,0.95},{0.25,0.6,1,0.5},{0.45,0.75,1,0.02}};
		sizeVar = 0.05;
	};

	class FST_Proj_LightBlue_Emissive_Medium: FST_Proj_Blue_Emissive
	{
		interval = 0.004;
		lifeTime = 0.18;
		size[] = {0.12,0.24,0.36};
		moveVelocity[] = {0,0.9,0};
		color[] = {{0.4,0.75,1,0.95},{0.6,0.9,1,0.55},{0.8,0.98,1,0.02}};
		sizeVar = 0.05;
	};

	class FST_Exhaust_IonBlue_Small: ExhaustSmoke
	{
		interval = 0.02;
		lifeTime = 0.9;
		size[] = {0.12,0.25,0.38};
		moveVelocity[] = {0,0.8,0};
		MoveVelocityVar[] = {0.2,0.35,0.2};
		color[] = {{0.3,0.6,1,0.5},{0.35,0.7,1,0.28},{0.45,0.8,1,0.04}};
		rubbing = 0.06;
	};
	class FST_Exhaust_IonBlue_Large: ExhaustSmoke
	{
		interval = 0.013;
		lifeTime = 1.3;
		size[] = {0.22,0.5,0.9};
		moveVelocity[] = {0,1.6,0};
		MoveVelocityVar[] = {0.35,0.5,0.35};
		color[] = {{0.22,0.52,1,0.6},{0.3,0.68,1,0.35},{0.45,0.82,1,0.06}};
		rubbing = 0.05;
	};
	class FST_Exhaust_IonWhiteHot: ExhaustSmoke
	{
		interval = 0.015;
		lifeTime = 0.85;
		size[] = {0.16,0.32,0.48};
		moveVelocity[] = {0,1.2,0};
		MoveVelocityVar[] = {0.25,0.42,0.25};
		color[] = {{1,0.98,0.9,0.62},{0.75,0.9,1,0.26},{0.6,0.85,1,0.02}};
		rubbing = 0.045;
	};
	class FST_Exhaust_CISRed_Small: ExhaustSmoke
	{
		interval = 0.02;
		lifeTime = 1.0;
		size[] = {0.13,0.3,0.44};
		moveVelocity[] = {0,0.95,0};
		MoveVelocityVar[] = {0.2,0.35,0.2};
		color[] = {{1,0.28,0.22,0.48},{1,0.42,0.3,0.25},{1,0.5,0.35,0.03}};
		rubbing = 0.06;
	};
	class FST_Exhaust_RepulsorDust_Blue: ExhaustSmoke
	{
		interval = 0.02;
		lifeTime = 1.5;
		size[] = {0.2,0.6,1.2};
		moveVelocity[] = {0,0.45,0};
		MoveVelocityVar[] = {0.5,0.25,0.5};
		color[] = {{0.5,0.57,0.68,0.32},{0.55,0.62,0.74,0.2},{0.65,0.72,0.82,0}};
		rubbing = 0.14;
	};
	class FST_Exhaust_TurbineHeat_HighFlow: ExhaustSmoke
	{
		interval = 0.01;
		lifeTime = 0.65;
		size[] = {0.12,0.2,0.28};
		moveVelocity[] = {0,2.4,0};
		MoveVelocityVar[] = {0.24,0.45,0.24};
		color[] = {{0.9,0.95,1,0.26},{0.8,0.9,1,0.11},{0.75,0.86,1,0.01}};
		rubbing = 0.03;
	};
	class FST_Exhaust_HeavyBlack_Soot: ExhaustSmoke
	{
		interval = 0.025;
		lifeTime = 2.2;
		size[] = {0.22,0.7,1.4};
		moveVelocity[] = {0,0.62,0};
		MoveVelocityVar[] = {0.35,0.2,0.35};
		color[] = {{0.08,0.08,0.08,0.64},{0.13,0.13,0.13,0.44},{0.2,0.2,0.2,0.08}};
		rubbing = 0.09;
	};	
	class FST_Exhaust_DamagedEngine_Sputter: ExhaustSmoke
	{
		interval = 0.045;
		lifeTime = 1.8;
		size[] = {0.14,0.36,0.78};
		moveVelocity[] = {0,0.56,0};
		MoveVelocityVar[] = {0.38,0.18,0.38};
		color[] = {{0.3,0.3,0.3,0.52},{0.42,0.42,0.42,0.3},{0.5,0.5,0.5,0.06}};
		rubbing = 0.12;
	};
};
class CfgVehicleExhausts
{
	class ExhaustsEffect;

	class FST_ExhaustEffect_IonBlue_Small: ExhaustsEffect
	{
		simulation = "particles";
		type = "FST_Exhaust_IonBlue_Small";
	};
	class FST_ExhaustEffect_IonBlue_Large: ExhaustsEffect
	{
		simulation = "particles";
		type = "FST_Exhaust_IonBlue_Large";
	};
	class FST_ExhaustEffect_IonWhiteHot: ExhaustsEffect
	{
		simulation = "particles";
		type = "FST_Exhaust_IonWhiteHot";
	};
	class FST_ExhaustEffect_CISRed_Small: ExhaustsEffect
	{
		simulation = "particles";
		type = "FST_Exhaust_CISRed_Small";
	};
	class FST_ExhaustEffect_RepulsorDust_Blue: ExhaustsEffect
	{
		simulation = "particles";
		type = "FST_Exhaust_RepulsorDust_Blue";
	};
	class FST_ExhaustEffect_TurbineHeat_HighFlow: ExhaustsEffect
	{
		simulation = "particles";
		type = "FST_Exhaust_TurbineHeat_HighFlow";
	};
	class FST_ExhaustEffect_HeavyBlack_Soot: ExhaustsEffect
	{
		simulation = "particles";
		type = "FST_Exhaust_HeavyBlack_Soot";
	};
	class FST_ExhaustEffect_DamagedEngine_Sputter: ExhaustsEffect
	{
		simulation = "particles";
		type = "FST_Exhaust_DamagedEngine_Sputter";
	};
};
