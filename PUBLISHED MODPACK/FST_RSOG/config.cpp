/*
    FST_RSOG/config.cpp
    Standalone 41st aux extension for RSOG equipment and infantry.

    Important design constraints:
    - Does NOT depend on SOG_Equipment or SOG_Units.
    - All playable soldiers inherit from 41st/FST base soldier classes first, so they keep 41st hitpoint behavior.
    - RSOG-owned texture paths are redirected from \Equipment\... to \FST_RSOG\Data\...
    - Public base mod classes such as JLTS/SEA/SWLB/3AS/LS are only used where the item model shape requires them.
      Infantry units do not inherit directly from those public role classes.
    - v4 removes injected `class ItemInfo: ItemInfo` protection blocks from external gear. Those blocks caused
      undefined nested base-class errors on SEA/JLTS gear that does not expose ItemInfo in the child inheritance chain.
    - v4 also remaps several old linkedItems/backpack references from the source unit config that did not have
      matching equipment definitions in the supplied equipment config.
    - v6 fixes RSOG P1/P2/custom helmet Arsenal visibility when inheriting from hidden 41st bases and restores
      the missing RSOG pilot/Henderson helmet classes from the source equipment config.
*/
class CfgPatches
{
	class FST_RSOG
	{
		author="41st / RSOG";
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"41st_Addon"
		};
		units[]=
		{
			"FST_RSOG_Covert_Ops_Backpack",
			"FST_RSOG_Covert_Ops_RTO",
			"FST_RSOG_Covert_Ops_Turret",
			"FST_RSOG_Covert_Ops_Shield",
			"FST_RSOG_Covert_Ops_Prowler",
			"FST_RSOG_Covert_Ops_RTO_Pack",
			"FST_RSOG_Stealth_Ops_Backpack",
			"FST_RSOG_Stealth_Ops_RTO",
			"FST_RSOG_Stealth_Ops_Turret",
			"FST_RSOG_Stealth_Ops_Shield",
			"FST_RSOG_Stealth_Ops_Prowler",
			"FST_RSOG_Stealth_Ops_Backpack_EOD",
			"FST_RSOG_Stealth_Ops_Backpack_Medic",
			"FST_RSOG_Stealth_Ops_RTO_Pack",
			"FST_RSOG_Stealth_Ops_Camo_Backpack",
			"FST_RSOG_Stealth_Ops_Camo_RTO",
			"FST_RSOG_Stealth_Ops_Camo_Turret",
			"FST_RSOG_Stealth_Ops_Camo_Shield",
			"FST_RSOG_Stealth_Ops_Camo_Prowler",
			"FST_RSOG_Stealth_Ops_Camo_Backpack_EOD",
			"FST_RSOG_Stealth_Ops_Camo_Backpack_Medic",
			"FST_RSOG_Rep_Intel_RTO_Pack_V1",
			"FST_RSOG_Rep_Intel_RTO_Pack_V2",
			"FST_RSOG_Rep_Intel_Backpack_V1",
			"FST_RSOG_Rep_Intel_RTO_V1",
			"FST_RSOG_Rep_Intel_Turret_V1",
			"FST_RSOG_Rep_Intel_Shield_V1",
			"FST_RSOG_Rep_Intel_Prowler_V1",
			"FST_RSOG_Rep_Intel_Backpack_V2",
			"FST_RSOG_Rep_Intel_RTO_V2",
			"FST_RSOG_Rep_Intel_Turret_V2",
			"FST_RSOG_Rep_Intel_Shield_V2",
			"FST_RSOG_Rep_Intel_Prowler_V2",
			"FST_RSOG_Rep_Intel_Backpack_V3",
			"FST_RSOG_Rep_Intel_RTO_V3",
			"FST_RSOG_Rep_Intel_Turret_V3",
			"FST_RSOG_Rep_Intel_Shield_V3",
			"FST_RSOG_Rep_Intel_Prowler_V3",
			"FST_RSOG_Rep_Intel_Backpack_V4",
			"FST_RSOG_Rep_Intel_RTO_V4",
			"FST_RSOG_Rep_Intel_Turret_V4",
			"FST_RSOG_Rep_Intel_Shield_V4",
			"FST_RSOG_Rep_Intel_Prowler_V4",
			"FST_RSOG_Clone_belt_bag",
			"FST_RSOG_Covert_Ops_Backpack_AT_Pred",
			"FST_RSOG_Covert_Ops_Backpack_AA_Pred",
			"FST_RSOG_Covert_Ops_Backpack_EOD_Pred",
			"FST_RSOG_Covert_Ops_Backpack_Medic_Pred",
			"FST_RSOG_Stealth_Ops_Backpack_AT_Pred",
			"FST_RSOG_Stealth_Ops_Backpack_AA_Pred",
			"FST_RSOG_Stealth_Ops_Backpack_EOD_Pred",
			"FST_RSOG_Stealth_Ops_Backpack_Medic_Pred",
			"FST_RSOG_Stealth_Ops_Camo_Backpack_AT_Pred",
			"FST_RSOG_Stealth_Ops_Camo_Backpack_AA_Pred",
			"FST_RSOG_Stealth_Ops_Camo_Backpack_EOD_Pred",
			"FST_RSOG_Stealth_Ops_Camo_Backpack_Medic_Pred",
			"FST_RSOG_Intel_Ruck_Backpack_AT_Pred_V1",
			"FST_RSOG_Intel_Ruck_Backpack_AA_Pred_V1",
			"FST_RSOG_Intel_Ruck_Backpack_EOD_Pred_V1",
			"FST_RSOG_Intel_Ruck_Backpack_Medic_Pred",
			"FST_RSOG_Stealth_Ops_Jumppack_MC",
			"FST_RSOG_Stealth_Ops_Jumppack",
			"FST_RSOG_Stealth_Ops_Jumppack_JT12",
			"FST_RSOG_Stealth_Ops_Jumppack_Chicken",
			"FST_RSOG_Covert_Ops_Jumppack_MC",
			"FST_RSOG_Covert_Ops_Jumppack",
			"FST_RSOG_Covert_Ops_Jumppack_JT12",
			"FST_RSOG_Covert_Ops_Jumppack_Chicken",
			"FST_RSOG_Rep_Intel_Jumppack_MC_B",
			"FST_RSOG_Rep_Intel_Jumppack_B",
			"FST_RSOG_Rep_Intel_Jumppack_JT12_B",
			"FST_RSOG_Rep_Intel_Jumppack_Chicken_B",
			"FST_RSOG_Rep_Intel_Jumppack_MC_G",
			"FST_RSOG_Rep_Intel_Jumppack_G",
			"FST_RSOG_Rep_Intel_Jumppack_JT12_G",
			"FST_RSOG_Rep_Intel_Jumppack_Chicken_G",
			"FST_RSOG_Covert_Ops_Trooper_DC15A",
			"FST_RSOG_Covert_Ops_Trooper_Grenadier",
			"FST_RSOG_Covert_Ops_Trooper_DC15S",
			"FST_RSOG_Covert_Ops_Trooper_AB",
			"FST_RSOG_Covert_Ops_Trooper_DP23",
			"FST_RSOG_Covert_Ops_Trooper_Jump",
			"FST_RSOG_Covert_Ops_Trooper_Medic",
			"FST_RSOG_Covert_Ops_Trooper_Marksman",
			"FST_RSOG_Covert_Ops_Trooper_Sniper",
			"FST_RSOG_Covert_Ops_Trooper_EOD",
			"FST_RSOG_Covert_Ops_Trooper_RTO",
			"FST_RSOG_Covert_Ops_Trooper_Prowler",
			"FST_RSOG_Covert_Ops_Trooper_AT",
			"FST_RSOG_Covert_Ops_Trooper_AA",
			"FST_RSOG_Covert_Ops_Trooper_AR",
			"FST_RSOG_Covert_Ops_Trooper_Recon",
			"FST_RSOG_Covert_Ops_Trooper_CPL",
			"FST_RSOG_Covert_Ops_Trooper_ABNCO",
			"FST_RSOG_Covert_Ops_Trooper_SGT",
			"FST_RSOG_Covert_Ops_Trooper_SGM",
			"FST_RSOG_Covert_Ops_Trooper_LT",
			"FST_RSOG_Covert_Ops_Trooper_CPT",
			"FST_RSOG_Covert_Ops_Trooper_MAJ",
			"FST_RSOG_Covert_Ops_Trooper_CMD",
			"FST_RSOG_Stealth_Ops_Trooper_V1_DC15A",
			"FST_RSOG_Stealth_Ops_Trooper_V1_Grenadier",
			"FST_RSOG_Stealth_Ops_Trooper_V1_DC15S",
			"FST_RSOG_Stealth_Ops_Trooper_V1_AB",
			"FST_RSOG_Stealth_Ops_Trooper_V1_DP23",
			"FST_RSOG_Stealth_Ops_Trooper_V1_Jump",
			"FST_RSOG_Stealth_Ops_Trooper_V1_Medic",
			"FST_RSOG_Stealth_Ops_Trooper_V1_Marksman",
			"FST_RSOG_Stealth_Ops_Trooper_V1_Sniper",
			"FST_RSOG_Stealth_Ops_Trooper_V1_EOD",
			"FST_RSOG_Stealth_Ops_Trooper_V1_RTO",
			"FST_RSOG_Stealth_Ops_Trooper_V1_Prowler",
			"FST_RSOG_Stealth_Ops_Trooper_V1_AT",
			"FST_RSOG_Stealth_Ops_Trooper_V1_AA",
			"FST_RSOG_Stealth_Ops_Trooper_V1_AR",
			"FST_RSOG_Stealth_Ops_Trooper_V1_Recon",
			"FST_RSOG_Stealth_Ops_Trooper_V1_CPL",
			"FST_RSOG_Stealth_Ops_Trooper_V1_ABNCO",
			"FST_RSOG_Stealth_Ops_Trooper_V1_SGT",
			"FST_RSOG_Stealth_Ops_Trooper_V1_SGM",
			"FST_RSOG_Stealth_Ops_Trooper_V1_LT",
			"FST_RSOG_Stealth_Ops_Trooper_V1_CPT",
			"FST_RSOG_Stealth_Ops_Trooper_V1_MAJ",
			"FST_RSOG_Stealth_Ops_Trooper_V1_CMD",
			"FST_RSOG_Stealth_Ops_Trooper_V2_DC15A",
			"FST_RSOG_Stealth_Ops_Trooper_V2_Grenadier",
			"FST_RSOG_Stealth_Ops_Trooper_V2_AR",
			"FST_RSOG_Stealth_Ops_Trooper_V2_Recon",
			"FST_RSOG_Stealth_Ops_Trooper_V3_DC15A",
			"FST_RSOG_Stealth_Ops_Trooper_V3_Grenadier",
			"FST_RSOG_Stealth_Ops_Trooper_V3_AR",
			"FST_RSOG_Stealth_Ops_Trooper_V3_Recon",
			"FST_RSOG_Stealth_Ops_Trooper_V4_DC15A",
			"FST_RSOG_Stealth_Ops_Trooper_V4_Grenadier",
			"FST_RSOG_Stealth_Ops_Trooper_V4_AR",
			"FST_RSOG_Stealth_Ops_Trooper_V4_Recon",
			"FST_RSOG_Stealth_Ops_Trooper_V5_DC15A",
			"FST_RSOG_Stealth_Ops_Trooper_V5_Grenadier",
			"FST_RSOG_Stealth_Ops_Trooper_V5_AR",
			"FST_RSOG_Stealth_Ops_Trooper_V5_Recon",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV1_DC15A",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV1_Grenadier",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV1_AR",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV1_Recon",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV2_DC15A",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV2_Grenadier",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV2_AR",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV2_Recon",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV3_DC15A",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV3_Grenadier",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV3_AR",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV3_Recon",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV4_DC15A",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV4_Grenadier",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV4_AR",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV4_Recon",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV5_DC15A",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV5_Grenadier",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV5_AR",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV5_Recon",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV6_DC15A",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV6_Grenadier",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV6_AR",
			"FST_RSOG_Stealth_Ops_Trooper_CamoV6_Recon",
			"FST_RSOG_Republic_Intel_MC_V1",
			"FST_RSOG_Republic_Intel_MC_V2",
			"FST_RSOG_Republic_Intel_MC_V3",
			"FST_RSOG_Republic_Intel_MC_V4",
			"FST_RSOG_Republic_Intel_Trooper_DC15A",
			"FST_RSOG_Republic_Intel_Trooper_Grenadier",
			"FST_RSOG_Republic_Intel_Trooper_V1_DC15S",
			"FST_RSOG_Republic_Intel_Trooper_V1_AB",
			"FST_RSOG_Republic_Intel_Trooper_V1_DP23",
			"FST_RSOG_Republic_Intel_Trooper_V1_Medic",
			"FST_RSOG_Republic_Intel_Trooper_V1_Marksman",
			"FST_RSOG_Republic_Intel_Trooper_V1_Sniper",
			"FST_RSOG_Republic_Intel_Trooper_V1_EOD",
			"FST_RSOG_Republic_Intel_Trooper_V1_RTO",
			"FST_RSOG_Republic_Intel_Trooper_V1_Prowler",
			"FST_RSOG_Republic_Intel_Trooper_V1_AT",
			"FST_RSOG_Republic_Intel_Trooper_V1_AA",
			"FST_RSOG_Republic_Intel_Trooper_AR",
			"FST_RSOG_Republic_Intel_Trooper_V1_Recon",
			"FST_RSOG_Republic_Intel_Trooper_V1_CPL",
			"FST_RSOG_Republic_Intel_Trooper_V1_ABNCO",
			"FST_RSOG_Republic_Intel_Trooper_V1_SGT",
			"FST_RSOG_Republic_Intel_Trooper_V1_SGM",
			"FST_RSOG_Republic_Intel_Trooper_V1_LT",
			"FST_RSOG_Republic_Intel_Trooper_V1_CPT",
			"FST_RSOG_Republic_Intel_Trooper_V1_MAJ",
			"FST_RSOG_Republic_Intel_Trooper_V1_CMD",
			"FST_RSOG_Republic_Intel_Trooper_V1_DC15A",
			"FST_RSOG_Republic_Intel_Trooper_V1_Grenadier",
			"FST_RSOG_Republic_Intel_Trooper_V1_AR",
			"FST_RSOG_Republic_Intel_Trooper_V2_DC15A",
			"FST_RSOG_Republic_Intel_Trooper_V2_Grenadier",
			"FST_RSOG_Republic_Intel_Trooper_V2_AR",
			"FST_RSOG_Republic_Intel_Trooper_V2_Recon",
			"FST_RSOG_Republic_Intel_Trooper_V3_DC15A",
			"FST_RSOG_Republic_Intel_Trooper_V3_Grenadier",
			"FST_RSOG_Republic_Intel_Trooper_V3_AR",
			"FST_RSOG_Republic_Intel_Trooper_V3_Recon",
			"FST_RSOG_Republic_Intel_Trooper_V4_DC15A",
			"FST_RSOG_Republic_Intel_Trooper_V4_Grenadier",
			"FST_RSOG_Republic_Intel_Trooper_V4_AR",
			"FST_RSOG_Republic_Intel_Trooper_V4_Recon",
			"FST_RSOG_Regular_Trooper_DC15A",
			"FST_RSOG_Custom_Trooper_Apathy"
		};
		weapons[]=
		{
			"FST_RSOG_SOG_Helmet_Covert",
			"FST_RSOG_SOG_Helmet_Stealth_LR",
			"FST_RSOG_SOG_Helmet_Stealth_V1_LR",
			"FST_RSOG_SOG_Helmet_Stealth_V2_LR",
			"FST_RSOG_SOG_Helmet_Stealth_V3_LR",
			"FST_RSOG_SOG_Helmet_Stealth_SR",
			"FST_RSOG_SOG_Helmet_Stealth_V1_SR",
			"FST_RSOG_SOG_Helmet_Stealth_V2_SR",
			"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
			"FST_RSOG_SOG_Helmet_Stealth_LR_IllumBase",
			"FST_RSOG_SOG_Helmet_Stealth_V1_LR_IllumBase",
			"FST_RSOG_SOG_Helmet_Stealth_V2_LR_IllumBase",
			"FST_RSOG_SOG_Helmet_Stealth_V3_LR_IllumBase",
			"FST_RSOG_SOG_Helmet_Stealth_SR_IllumBase",
			"FST_RSOG_SOG_Helmet_Stealth_V1_SR_IllumBase",
			"FST_RSOG_SOG_Helmet_Stealth_V2_SR_IllumBase",
			"FST_RSOG_SOG_Helmet_Stealth_V3_SR_IllumBase",
			"FST_RSOG_P2_AB_Helmet_Intel_V1",
			"FST_RSOG_P2_AB_Helmet_Intel_V2",
			"FST_RSOG_P2_BARC_Helmet_Intel_V1",
			"FST_RSOG_P2_BARC_Helmet_Intel_V2",
			"FST_RSOG_Rep_Intel_ARF_V1",
			"FST_RSOG_Rep_Intel_ARF_V2",
			"FST_RSOG_Rep_Intel_ARF_V3",
			"FST_RSOG_Rep_Intel_ARF_V4",
			"FST_RSOG_P1_Helmet_Intel_Base",
			"FST_RSOG_P1_Helmet_Intel_V1",
			"FST_RSOG_P1_Helmet_Intel_V2",
			"FST_RSOG_P1_Helmet_Intel_V3",
			"FST_RSOG_P1_Helmet_Intel_V4",
			"FST_RSOG_P1_Helmet_Intel_V5",
			"FST_RSOG_P1_Helmet_Intel_V6",
			"FST_RSOG_P1_Helmet_Intel_V7",
			"FST_RSOG_P2_Helmet_Intel_Base",
			"FST_RSOG_P2_Helmet_Intel_V1",
			"FST_RSOG_P2_Helmet_Intel_V2",
			"FST_RSOG_P2_Helmet_Intel_V3",
			"FST_RSOG_P2_Helmet_Intel_V4",
			"FST_RSOG_P2_Helmet_Intel_V5",
			"FST_RSOG_P2_Helmet_Intel_V6",
			"FST_RSOG_P2_Helmet_Intel_V7",
			"FST_RSOG_P2_Helmet_Intel_V8",
			"FST_RSOG_P2_Helmet_Intel_MC_V3",
			"FST_RSOG_P2_Helmet_Intel_MC_V1",
			"FST_RSOG_P2_Helmet_Intel_MC_V2",
			"FST_RSOG_P2_Helmet_White",
			"FST_RSOG_P2_Helmet_Custom_Baron",
			"FST_RSOG_P2_Helmet_Custom_Apathy",
			"FST_RSOG_P2_Helmet_Custom_Bendable",
			"FST_RSOG_P2_Helmet_Custom_Freezy",
			"FST_RSOG_P2_Helmet_Custom_Phoenix",
			"FST_RSOG_BARC_Helmet_Custom_Gabriel",
			"FST_RSOG_P2_Helmet_Pilot_V1",
			"FST_RSOG_P2_Helmet_Pilot_V2",
			"FST_RSOG_P2_Helmet_Custom_Henderson",
			"FST_RSOG_Covert_Officer_V1",
			"FST_RSOG_Covert_Officer_V2",
			"FST_RSOG_Covert_Heavy_NCO",
			"FST_RSOG_Covert_Heavy",
			"FST_RSOG_Covert_CMD_Vest",
			"FST_RSOG_Covert_Holster",
			"FST_RSOG_Covert_Kama",
			"FST_RSOG_Covert_LT_Vest",
			"FST_RSOG_Covert_Recon_NCO_Vest",
			"FST_RSOG_Covert_Recon_Vest",
			"FST_RSOG_Covert_Recon_Officer_Vest",
			"FST_RSOG_Covert_Suspenders",
			"FST_RSOG_Stealth_Officer_V1_1",
			"FST_RSOG_Stealth_Officer_V1_2",
			"FST_RSOG_Stealth_Heavy_NCO_V1",
			"FST_RSOG_Stealth_Heavy_V1",
			"FST_RSOG_Stealth_CMD_Vest_V1",
			"FST_RSOG_Stealth_Holster_V1",
			"FST_RSOG_Stealth_Kama_V1",
			"FST_RSOG_Stealth_LT_Vest_V1",
			"FST_RSOG_Stealth_Recon_NCO_Vest_V1",
			"FST_RSOG_Stealth_Recon_Vest_V1",
			"FST_RSOG_Stealth_Recon_Officer_Vest_V1",
			"FST_RSOG_Stealth_Suspenders_V1",
			"FST_RSOG_Stealth_Officer_V2_1",
			"FST_RSOG_Stealth_Officer_V2_2",
			"FST_RSOG_Stealth_Heavy_NCO_V2",
			"FST_RSOG_Stealth_Heavy_V2",
			"FST_RSOG_Stealth_CMD_Vest_V2",
			"FST_RSOG_Stealth_Holster_V2",
			"FST_RSOG_Stealth_Kama_V2",
			"FST_RSOG_Stealth_LT_Vest_V2",
			"FST_RSOG_Stealth_Recon_Officer_Vest_V2",
			"FST_RSOG_Stealth_Suspenders_V2",
			"FST_RSOG_Stealth_Officer_V3_1",
			"FST_RSOG_Stealth_Officer_V3_2",
			"FST_RSOG_Stealth_Heavy_NCO_V3",
			"FST_RSOG_Stealth_Heavy_V3",
			"FST_RSOG_Stealth_CMD_Vest_V3",
			"FST_RSOG_Stealth_Kama_V3",
			"FST_RSOG_Stealth_LT_Vest_V3",
			"FST_RSOG_Stealth_Recon_Officer_Vest_V3",
			"FST_RSOG_Stealth_Officer_V4_1",
			"FST_RSOG_Stealth_Officer_V4_2",
			"FST_RSOG_Stealth_CMD_Vest_V4",
			"FST_RSOG_Stealth_Kama_V4",
			"FST_RSOG_Stealth_LT_Vest_V4",
			"FST_RSOG_Stealth_Recon_Officer_Vest_V4",
			"FST_RSOG_Stealth_Officer_V5_1",
			"FST_RSOG_Stealth_Officer_V5_2",
			"FST_RSOG_Stealth_CMD_Vest_V5",
			"FST_RSOG_Stealth_Kama_V5",
			"FST_RSOG_Stealth_Recon_Officer_Vest_V5",
			"FST_RSOG_Stealth_Officer_V6_1",
			"FST_RSOG_Stealth_Officer_V6_2",
			"FST_RSOG_Stealth_CMD_Vest_V6",
			"FST_RSOG_Stealth_Kama_V6",
			"FST_RSOG_Stealth_Recon_Officer_Vest_V6",
			"FST_RSOG_Stealth_Officer_V7_1",
			"FST_RSOG_Stealth_Officer_V7_2",
			"FST_RSOG_Stealth_CMD_Vest_V7",
			"FST_RSOG_Stealth_Recon_Officer_Vest_V7",
			"FST_RSOG_Stealth_Officer_V8_1",
			"FST_RSOG_Stealth_Officer_V8_2",
			"FST_RSOG_Stealth_CMD_Vest_V8",
			"FST_RSOG_Stealth_Recon_Officer_Vest_V8",
			"FST_RSOG_Stealth_Officer_V9_1",
			"FST_RSOG_Stealth_Officer_V9_2",
			"FST_RSOG_Stealth_CMD_Vest_V9",
			"FST_RSOG_Stealth_Recon_Officer_Vest_V9",
			"FST_RSOG_Stealth_Officer_V10_1",
			"FST_RSOG_Stealth_Officer_V10_2",
			"FST_RSOG_Stealth_CMD_Vest_V10",
			"FST_RSOG_Stealth_Recon_Officer_Vest_V10",
			"FST_RSOG_Rep_Intel_AB_Vest_V1_1_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V1_2_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V1_3_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V1_4_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V1_5_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V1_6_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V1_7_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V1_8_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V2_1_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V2_2_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V2_3_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V2_4_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V2_5_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V2_6_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V2_7_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V2_8_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V3_1_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V3_2_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V3_3_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V3_4_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V3_5_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V3_6_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V3_7_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V3_8_NCO",
			"FST_RSOG_Rep_Intel_AB_Vest_V1_1",
			"FST_RSOG_Rep_Intel_AB_Vest_V1_2",
			"FST_RSOG_Rep_Intel_AB_Vest_V1_3",
			"FST_RSOG_Rep_Intel_AB_Vest_V1_4",
			"FST_RSOG_Rep_Intel_AB_Vest_V1_5",
			"FST_RSOG_Rep_Intel_AB_Vest_V1_6",
			"FST_RSOG_Rep_Intel_AB_Vest_V1_7",
			"FST_RSOG_Rep_Intel_AB_Vest_V1_8",
			"FST_RSOG_Rep_Intel_AB_Vest_V2_1",
			"FST_RSOG_Rep_Intel_AB_Vest_V2_2",
			"FST_RSOG_Rep_Intel_AB_Vest_V2_3",
			"FST_RSOG_Rep_Intel_AB_Vest_V2_4",
			"FST_RSOG_Rep_Intel_AB_Vest_V2_5",
			"FST_RSOG_Rep_Intel_AB_Vest_V2_6",
			"FST_RSOG_Rep_Intel_AB_Vest_V2_7",
			"FST_RSOG_Rep_Intel_AB_Vest_V2_8",
			"FST_RSOG_Rep_Intel_AB_Vest_V3_1",
			"FST_RSOG_Rep_Intel_AB_Vest_V3_2",
			"FST_RSOG_Rep_Intel_AB_Vest_V3_3",
			"FST_RSOG_Rep_Intel_AB_Vest_V3_4",
			"FST_RSOG_Rep_Intel_AB_Vest_V3_5",
			"FST_RSOG_Rep_Intel_AB_Vest_V3_6",
			"FST_RSOG_Rep_Intel_AB_Vest_V3_7",
			"FST_RSOG_Rep_Intel_AB_Vest_V3_8",
			"FST_RSOG_Rep_Intel_Suspenders_V1",
			"FST_RSOG_Rep_Intel_Suspenders_V2",
			"FST_RSOG_Republic_Intelligence_Holster",
			"FST_RSOG_Rep_Intel_Kama_V1",
			"FST_RSOG_Rep_Intel_Kama_V2",
			"FST_RSOG_Rep_Intel_Kama_V3",
			"FST_RSOG_Rep_Intel_Kama_V4",
			"FST_RSOG_Rep_Intel_LT_Vest_V1",
			"FST_RSOG_Rep_Intel_LT_Vest_V2",
			"FST_RSOG_Rep_Intel_Recon_NCO_Vest_V1",
			"FST_RSOG_Rep_Intel_Recon_NCO_Vest_V2",
			"FST_RSOG_Rep_Intel_Recon_NCO_Vest_V3",
			"FST_RSOG_Rep_Intel_Recon_Vest",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V1_1",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V1_2",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V1_3",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V1_4",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V1_5",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V1_6",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V1_7",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V1_8",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V2_1",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V2_2",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V2_3",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V2_4",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V2_5",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V2_6",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V2_7",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V2_8",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V3_1",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V3_2",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V3_3",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V3_4",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V3_5",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V3_6",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V3_7",
			"FST_RSOG_Rep_Intel_Recon_Off_Vest_V3_8",
			"FST_RSOG_Rep_Intel_Officer_V1_1",
			"FST_RSOG_Rep_Intel_Officer_V1_2",
			"FST_RSOG_Rep_Intel_CMD_Vest_V1",
			"FST_RSOG_Rep_Intel_Officer_V2_1",
			"FST_RSOG_Rep_Intel_Officer_V2_2",
			"FST_RSOG_Rep_Intel_CMD_Vest_V2",
			"FST_RSOG_Rep_Intel_Officer_V3_1",
			"FST_RSOG_Rep_Intel_Officer_V3_2",
			"FST_RSOG_Rep_Intel_CMD_Vest_V3",
			"FST_RSOG_Rep_Intel_Officer_V4_1",
			"FST_RSOG_Rep_Intel_Officer_V4_2",
			"FST_RSOG_Rep_Intel_CMD_Vest_V4",
			"FST_RSOG_Rep_Intel_Officer_V5_1",
			"FST_RSOG_Rep_Intel_Officer_V5_2",
			"FST_RSOG_Rep_Intel_CMD_Vest_V5",
			"FST_RSOG_Rep_Intel_Officer_V6_1",
			"FST_RSOG_Rep_Intel_Officer_V6_2",
			"FST_RSOG_Rep_Intel_CMD_Vest_V6",
			"FST_RSOG_Rep_Intel_Officer_V7_1",
			"FST_RSOG_Rep_Intel_Officer_V7_2",
			"FST_RSOG_Rep_Intel_CMD_Vest_V7",
			"FST_RSOG_Rep_Intel_Officer_V8_1",
			"FST_RSOG_Rep_Intel_Officer_V8_2",
			"FST_RSOG_Rep_Intel_CMD_Vest_V8",
			"FST_RSOG_Covert_Armor",
			"FST_RSOG_Covert_Armor_Recon",
			"FST_RSOG_Covert_Armor_Grenadier",
			"FST_RSOG_Covert_Armor_Support",
			"FST_RSOG_Stealth_Armor_BaseV1",
			"FST_RSOG_Stealth_Armor_BaseV1_Recon",
			"FST_RSOG_Stealth_Armor_BaseV1_Grenadier",
			"FST_RSOG_Stealth_Armor_BaseV1_Support",
			"FST_RSOG_Stealth_Armor_BaseV2",
			"FST_RSOG_Stealth_Armor_BaseV2_Recon",
			"FST_RSOG_Stealth_Armor_BaseV2_Grenadier",
			"FST_RSOG_Stealth_Armor_BaseV2_Support",
			"FST_RSOG_Stealth_Armor_BaseV3",
			"FST_RSOG_Stealth_Armor_BaseV3_Recon",
			"FST_RSOG_Stealth_Armor_BaseV3_Grenadier",
			"FST_RSOG_Stealth_Armor_BaseV3_Support",
			"FST_RSOG_Stealth_Armor_BaseV4",
			"FST_RSOG_Stealth_Armor_BaseV4_Recon",
			"FST_RSOG_Stealth_Armor_BaseV4_Grenadier",
			"FST_RSOG_Stealth_Armor_BaseV4_Support",
			"FST_RSOG_Stealth_Armor_BaseV5",
			"FST_RSOG_Stealth_Armor_BaseV5_Recon",
			"FST_RSOG_Stealth_Armor_BaseV5_Grenadier",
			"FST_RSOG_Stealth_Armor_BaseV5_Support",
			"FST_RSOG_Stealth_Armor_CamoV1",
			"FST_RSOG_Stealth_Armor_CamoV1_Recon",
			"FST_RSOG_Stealth_Armor_CamoV1_Grenadier",
			"FST_RSOG_Stealth_Armor_CamoV1_Support",
			"FST_RSOG_Stealth_Armor_CamoV2",
			"FST_RSOG_Stealth_Armor_CamoV2_Recon",
			"FST_RSOG_Stealth_Armor_CamoV2_Grenadier",
			"FST_RSOG_Stealth_Armor_CamoV2_Support",
			"FST_RSOG_Stealth_Armor_CamoV3",
			"FST_RSOG_Stealth_Armor_CamoV3_Recon",
			"FST_RSOG_Stealth_Armor_CamoV3_Grenadier",
			"FST_RSOG_Stealth_Armor_CamoV3_Support",
			"FST_RSOG_Stealth_Armor_CamoV4",
			"FST_RSOG_Stealth_Armor_CamoV4_Recon",
			"FST_RSOG_Stealth_Armor_CamoV4_Grenadier",
			"FST_RSOG_Stealth_Armor_CamoV4_Support",
			"FST_RSOG_Stealth_Armor_CamoV5",
			"FST_RSOG_Stealth_Armor_CamoV5_Recon",
			"FST_RSOG_Stealth_Armor_CamoV5_Grenadier",
			"FST_RSOG_Stealth_Armor_CamoV5_Support",
			"FST_RSOG_Stealth_Armor_CamoV6",
			"FST_RSOG_Stealth_Armor_CamoV6_Recon",
			"FST_RSOG_Stealth_Armor_CamoV6_Grenadier",
			"FST_RSOG_Stealth_Armor_CamoV6_Support",
			"FST_RSOG_Rep_Intel_MC_Armor_BaseV1",
			"FST_RSOG_Rep_Intel_MC_Armor_BaseV2",
			"FST_RSOG_Rep_Intel_MC_Armor_BaseV3",
			"FST_RSOG_Rep_Intel_MC_Armor_BaseV4",
			"FST_RSOG_Rep_Intel_Armor_V1",
			"FST_RSOG_Rep_Intel_Armor_V1_Recon",
			"FST_RSOG_Rep_Intel_Armor_V1_Grenadier",
			"FST_RSOG_Rep_Intel_Armor_V1_Support",
			"FST_RSOG_Rep_Intel_Armor_V2",
			"FST_RSOG_Rep_Intel_Armor_V2_Recon",
			"FST_RSOG_Rep_Intel_Armor_V2_Grenadier",
			"FST_RSOG_Rep_Intel_Armor_V2_Support",
			"FST_RSOG_Rep_Intel_Armor_V3",
			"FST_RSOG_Rep_Intel_Armor_V3_Recon",
			"FST_RSOG_Rep_Intel_Armor_V3_Grenadier",
			"FST_RSOG_Rep_Intel_Armor_V3_Support",
			"FST_RSOG_Rep_Intel_Armor_V4",
			"FST_RSOG_Rep_Intel_Armor_V4_Recon",
			"FST_RSOG_Rep_Intel_Armor_V4_Grenadier",
			"FST_RSOG_Rep_Intel_Armor_V4_Support",
			"FST_RSOG_Regular_Armor_V1",
			"FST_RSOG_Custom_Armor_Apathy",
			"FST_RSOG_Covert_NVG",
			"FST_RSOG_Covert_NVG_Spec",
			"FST_RSOG_Covert_Rangefinder",
			"FST_RSOG_Covert_NVGCC",
			"FST_RSOG_Covert_NVGMC",
			"FST_RSOG_Rep_Intel_Visor_V1",
			"FST_RSOG_Rep_Intel_Visor_V2",
			"FST_RSOG_Rep_Intel_Visor_V3",
			"FST_RSOG_Rep_Intel_Visor_V4",
			"FST_RSOG_Rep_Intel_Visor_V1_Spec",
			"FST_RSOG_Rep_Intel_Visor_V2_Spec",
			"FST_RSOG_Rep_Intel_Visor_V3_Spec",
			"FST_RSOG_Rep_Intel_Visor_V4_Spec",
			"FST_RSOG_Rep_Intel_Rangefinder_V1",
			"FST_RSOG_Rep_Intel_Rangefinder_V2",
			"FST_RSOG_Rep_Intel_Rangefinder_V3",
			"FST_RSOG_Rep_Intel_Rangefinder_V4",
			"FST_RSOG_Rep_Intel_MC_Visor_V1",
			"FST_RSOG_Rep_Intel_MC_Visor_V2",
			"FST_RSOG_RSOG_NVG_Chip",
			"FST_RSOG_RSOG_NVG_ChipThermal"
		};
	};
};

class CfgFactionClasses
{
	class FST_RSOG_Faction
	{
		displayName="[41st] RSOG Attachments";
		side=1;
		priority=2;
	};
};

class CfgEditorSubcategories
{
	class FST_RSOG_Covert_Ops
	{
		displayName="RSOG Covert Operations";
	};
	class FST_RSOG_Stealth_Ops
	{
		displayName="RSOG Stealth Operations";
	};
	class FST_RSOG_Republic_Intel
	{
		displayName="RSOG Republic Intelligence";
	};
	class FST_RSOG_Republic_Rotaries
	{
		displayName="RSOG Rotary Assets";
	};
};

class CfgWeapons
{
	// 41st/FST bases first; specialized model bases remain public-mod bases, not SOG aux bases.
	class FST_P2_Helmet_Base;
	class FST_Trooper_Uniform;
	class FST_Uniform_Merrik_BC;
	class FST_Vest_Base;
	class HeadgearItem;
	class JLTS_CloneArmor;
	class JLTS_CloneArmorGrenadier;
	class JLTS_CloneArmorMC;
	class JLTS_CloneArmorRecon;
	class JLTS_CloneArmorSupport;
	class JLTS_CloneHelmetAB;
	class JLTS_CloneHelmetBARC;
	class JLTS_CloneHelmetP2;
	class JLTS_CloneHelmetP2MC;
	class 3as_P2_Pilot_helmet;
	class JLTS_CloneNVG;
	class JLTS_CloneNVGCC;
	class JLTS_CloneNVGMC;
	class JLTS_CloneNVGRange;
	class JLTS_CloneNVG_spec;
	class JLTS_CloneVestARC;
	class JLTS_CloneVestARCCadet;
	class JLTS_CloneVestAirborne;
	class JLTS_CloneVestAirborneNCO;
	class JLTS_CloneVestCommander;
	class JLTS_CloneVestHolster;
	class JLTS_CloneVestKama;
	class JLTS_CloneVestLieutenant;
	class JLTS_CloneVestOfficer;
	class JLTS_CloneVestOfficer2;
	class JLTS_CloneVestRecon;
	class JLTS_CloneVestReconNCO;
	class JLTS_CloneVestReconOfficer;
	class JLTS_CloneVestSuspender;
	class JLTS_NVG_droid_chip_1;
	class JLTS_NVG_droid_chip_2;
	class SEA_Helmet_ARC;
	class SEA_Helmet_ARF_base;
	class SEA_Helmet_Engineer_Base;
	class SEA_Helmet_Hazard_Base;
	class SEA_Helmet_P1_Base;
	class SEA_Helmet_SpecOps_LR_Base;
	class SEA_Helmet_SpecOps_LR_IllumBase;
	class SEA_Helmet_SpecOps_SR_Base;
	class SEA_Helmet_SpecOps_SR_IllumBase;
	class UniformItem;
	class VestItem;

	class FST_RSOG_SOG_Helmet_Covert: FST_P2_Helmet_Base
		{
			scope=2;
			scopecurator=2;
			scopearsenal=2;
			displayName="[41st/RSOG]  Cov.Ops. Helmet";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Covert_Helmet.paa"
			};
		};

	class FST_RSOG_SOG_Helmet_Stealth_LR: SEA_Helmet_SpecOps_LR_Base
		{
			scope=2;
			scopecurator=2;
			scopearsenal=2;
			displayName="[41st/RSOG]  Stealth.Ops. Helmet (Long Range)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Stealth_Helmet_Base.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\Antennas\LR_Antenna_co.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\SpecOpsHelmet_co.paa"
			};
		};

	class FST_RSOG_SOG_Helmet_Stealth_V1_LR: SEA_Helmet_SpecOps_LR_Base
		{
			scope=2;
			scopecurator=2;
			scopearsenal=2;
			displayName="[41st/RSOG]  Stealth.Ops. Helmet (White/Long Range)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Stealth_HelmetV1.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\Antennas\LR_Antenna_co.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\SpecOpsHelmet_co.paa"
			};
		};

	class FST_RSOG_SOG_Helmet_Stealth_V2_LR: SEA_Helmet_SpecOps_LR_Base
		{
			scope=2;
			scopecurator=2;
			scopearsenal=2;
			displayName="[41st/RSOG]  Stealth.Ops. Helmet (Red/Long Range)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Stealth_HelmetV2.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\Antennas\LR_Antenna_co.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\SpecOpsHelmet_co.paa"
			};
		};

	class FST_RSOG_SOG_Helmet_Stealth_V3_LR: SEA_Helmet_SpecOps_LR_Base
		{
			scope=2;
			scopecurator=2;
			scopearsenal=2;
			displayName="[41st/RSOG]  Stealth.Ops. Helmet (Black/Long Range)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Stealth_HelmetV3.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\Antennas\LR_Antenna_co.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\SpecOpsHelmet_co.paa"
			};
		};

	class FST_RSOG_SOG_Helmet_Stealth_SR: SEA_Helmet_SpecOps_SR_Base
		{
			scope=2;
			scopecurator=2;
			scopearsenal=2;
			displayName="[41st/RSOG]  Stealth.Ops. Helmet (Short Range)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Stealth_Helmet_Base.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\Antennas\SR_Antenna_co.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\SpecOpsHelmet_co.paa"
			};
		};

	class FST_RSOG_SOG_Helmet_Stealth_V1_SR: SEA_Helmet_SpecOps_SR_Base
		{
			scope=2;
			scopecurator=2;
			scopearsenal=2;
			displayName="[41st/RSOG]  Stealth.Ops. Helmet (White/Short Range)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Stealth_HelmetV1.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\Antennas\SR_Antenna_co.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\SpecOpsHelmet_co.paa"
			};
		};

	class FST_RSOG_SOG_Helmet_Stealth_V2_SR: SEA_Helmet_SpecOps_SR_Base
		{
			scope=2;
			scopecurator=2;
			scopearsenal=2;
			displayName="[41st/RSOG]  Stealth.Ops. Helmet (Red/Short Range)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Stealth_HelmetV2.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\Antennas\SR_Antenna_co.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\SpecOpsHelmet_co.paa"
			};
		};

	class FST_RSOG_SOG_Helmet_Stealth_V3_SR: SEA_Helmet_SpecOps_SR_Base
		{
			scope=2;
			scopecurator=2;
			scopearsenal=2;
			displayName="[41st/RSOG]  Stealth.Ops. Helmet (Black/Short Range)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Stealth_HelmetV3.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\Antennas\SR_Antenna_co.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\SpecOpsHelmet_co.paa"
			};
		};

	class FST_RSOG_SOG_Helmet_Stealth_LR_IllumBase: SEA_Helmet_SpecOps_LR_IllumBase
		{
			scope=1;
			displayName="[41st/RSOG]  Stealth.Ops. Helmet (Long Range)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Stealth_Helmet_Base.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\Antennas\LR_Antenna_co.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\SpecOpsHelmet_co.paa"
			};
		};

	class FST_RSOG_SOG_Helmet_Stealth_V1_LR_IllumBase: SEA_Helmet_SpecOps_LR_IllumBase
		{
			scope=1;
			displayName="[41st/RSOG]  Stealth.Ops. Helmet (White/Long Range)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Stealth_HelmetV1.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\Antennas\LR_Antenna_co.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\SpecOpsHelmet_co.paa"
			};
		};

	class FST_RSOG_SOG_Helmet_Stealth_V2_LR_IllumBase: SEA_Helmet_SpecOps_LR_IllumBase
		{
			scope=1;
			displayName="[41st/RSOG]  Stealth.Ops. Helmet (Red/Long Range)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Stealth_HelmetV2.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\Antennas\LR_Antenna_co.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\SpecOpsHelmet_co.paa"
			};
		};

	class FST_RSOG_SOG_Helmet_Stealth_V3_LR_IllumBase: SEA_Helmet_SpecOps_LR_IllumBase
		{
			scope=1;
			displayName="[41st/RSOG]  Stealth.Ops. Helmet (Black/Long Range)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Stealth_HelmetV3.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\Antennas\LR_Antenna_co.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\SpecOpsHelmet_co.paa"
			};
		};

	class FST_RSOG_SOG_Helmet_Stealth_SR_IllumBase: SEA_Helmet_SpecOps_SR_IllumBase
		{
			scope=1;
			displayName="[41st/RSOG]  Stealth.Ops. Helmet (Short Range)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Stealth_Helmet_Base.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\Antennas\SR_Antenna_co.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\SpecOpsHelmet_co.paa"
			};
		};

	class FST_RSOG_SOG_Helmet_Stealth_V1_SR_IllumBase: SEA_Helmet_SpecOps_SR_IllumBase
		{
			scope=1;
			displayName="[41st/RSOG]  Stealth.Ops. Helmet (White/Short Range)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Stealth_HelmetV1.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\Antennas\SR_Antenna_co.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\SpecOpsHelmet_co.paa"
			};
		};

	class FST_RSOG_SOG_Helmet_Stealth_V2_SR_IllumBase: SEA_Helmet_SpecOps_SR_IllumBase
		{
			scope=1;
			displayName="[41st/RSOG]  Stealth.Ops. Helmet (Red/Short Range)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Stealth_HelmetV2.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\Antennas\SR_Antenna_co.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\SpecOpsHelmet_co.paa"
			};
		};

	class FST_RSOG_SOG_Helmet_Stealth_V3_SR_IllumBase: SEA_Helmet_SpecOps_SR_IllumBase
		{
			scope=1;
			displayName="[41st/RSOG]  Stealth.Ops. Helmet (Black/Short Range)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Stealth_HelmetV3.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\Antennas\SR_Antenna_co.paa",
				"\JLTS_AE\Data\BaseTextures\SpecOps\SpecOpsHelmet_co.paa"
			};
		};

	class FST_RSOG_P2_AB_Helmet_Intel_V1: JLTS_CloneHelmetAB
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Airborne Helmet V1";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P2_AB_Helmet_Intel_V1.paa"
			};
		};

	class FST_RSOG_P2_AB_Helmet_Intel_V2: JLTS_CloneHelmetAB
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Airborne Helmet V2";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P2_AB_Helmet_Intel_V2.paa"
			};
		};

	class FST_RSOG_P2_BARC_Helmet_Intel_V1: JLTS_CloneHelmetBARC
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. BARC Helmet V1";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P2_BARC_Helmet_Intel_V1.paa"
			};
		};

	class FST_RSOG_P2_BARC_Helmet_Intel_V2: JLTS_CloneHelmetBARC
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. BARC Helmet V2";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P2_BARC_Helmet_Intel_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_ARF_V1: SEA_Helmet_ARF_base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. ARF Helmet V1";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Rep_Intel_ARF_V1.paa",
				"\JLTS_AE\Data\BaseTextures\ARF\Plates_CO.paa",
				"\JLTS_AE\Data\BaseTextures\ARF\ARF_Visor_CO.paa"
			};
		};

	class FST_RSOG_Rep_Intel_ARF_V2: SEA_Helmet_ARF_base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. ARF Helmet V2";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Rep_Intel_ARF_V2.paa",
				"\JLTS_AE\Data\BaseTextures\ARF\Plates_CO.paa",
				"\JLTS_AE\Data\BaseTextures\ARF\ARF_Visor_CO.paa"
			};
		};

	class FST_RSOG_Rep_Intel_ARF_V3: SEA_Helmet_ARF_base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. ARF Helmet V3";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Rep_Intel_ARF_V3.paa",
				"\JLTS_AE\Data\BaseTextures\ARF\Plates_CO.paa",
				"\JLTS_AE\Data\BaseTextures\ARF\ARF_Visor_CO.paa"
			};
		};

	class FST_RSOG_Rep_Intel_ARF_V4: SEA_Helmet_ARF_base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. ARF Helmet V4";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Rep_Intel_ARF_V4.paa",
				"\JLTS_AE\Data\BaseTextures\ARF\Plates_CO.paa",
				"\JLTS_AE\Data\BaseTextures\ARF\ARF_Visor_CO.paa"
			};
		};

	class FST_RSOG_P1_Helmet_Intel_Base: SEA_Helmet_P1_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Phase 1 Helmet";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P1_Helmet_Intel_Base.paa",
				"\JLTS_AE\Data\BaseTextures\P1\P1_Helmet_CO.paa"
			};
		};

	class FST_RSOG_P1_Helmet_Intel_V1: SEA_Helmet_P1_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Phase 1 Helmet V1";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P1_Helmet_Intel_V1.paa",
				"\JLTS_AE\Data\BaseTextures\P1\P1_Helmet_CO.paa"
			};
		};

	class FST_RSOG_P1_Helmet_Intel_V2: SEA_Helmet_P1_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Phase 1 Helmet V2";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P1_Helmet_Intel_V2.paa",
				"\JLTS_AE\Data\BaseTextures\P1\P1_Helmet_CO.paa"
			};
		};

	class FST_RSOG_P1_Helmet_Intel_V3: SEA_Helmet_P1_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Phase 1 Helmet V3";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P1_Helmet_Intel_V3.paa",
				"\JLTS_AE\Data\BaseTextures\P1\P1_Helmet_CO.paa"
			};
		};

	class FST_RSOG_P1_Helmet_Intel_V4: SEA_Helmet_P1_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Phase 1 Helmet V4";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P1_Helmet_Intel_V4.paa",
				"\JLTS_AE\Data\BaseTextures\P1\P1_Helmet_CO.paa"
			};
		};

	class FST_RSOG_P1_Helmet_Intel_V5: SEA_Helmet_P1_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Phase 1 Helmet V5";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P1_Helmet_Intel_V5.paa",
				"\JLTS_AE\Data\BaseTextures\P1\P1_Helmet_CO.paa"
			};
		};

	class FST_RSOG_P1_Helmet_Intel_V6: SEA_Helmet_P1_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Phase 1 Helmet V6";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P1_Helmet_Intel_V6.paa",
				"\JLTS_AE\Data\BaseTextures\P1\P1_Helmet_CO.paa"
			};
		};

	class FST_RSOG_P1_Helmet_Intel_V7: SEA_Helmet_P1_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Phase 1 Helmet V7";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P1_Helmet_Intel_V7.paa",
				"\JLTS_AE\Data\BaseTextures\P1\P1_Helmet_CO.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Intel_Base: FST_P2_Helmet_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Phase 2 Helmet";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P2_Helmet_Intel_Base.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Intel_V1: FST_P2_Helmet_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Phase 2 Helmet V1";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P2_Helmet_Intel_V1.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Intel_V2: FST_P2_Helmet_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Phase 2 Helmet V2";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P2_Helmet_Intel_V2.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Intel_V3: FST_P2_Helmet_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Phase 2 Helmet V3";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P2_Helmet_Intel_V3.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Intel_V4: FST_P2_Helmet_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Phase 2 Helmet V4";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P2_Helmet_Intel_V4.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Intel_V5: FST_P2_Helmet_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Phase 2 Helmet V5";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P2_Helmet_Intel_V5.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Intel_V6: FST_P2_Helmet_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Phase 2 Helmet V6";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P2_Helmet_Intel_V6.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Intel_V7: FST_P2_Helmet_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Phase 2 Helmet V7";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P2_Helmet_Intel_V7.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Intel_V8: FST_P2_Helmet_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Phase 2 Helmet V8";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P2_Helmet_Intel_V8.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Intel_MC_V3: JLTS_CloneHelmetP2MC
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Marshall Commander Helmet V3";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P2_Helmet_Intel_MC_V3.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Intel_MC_V1: JLTS_CloneHelmetP2MC
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Marshall Commander Helmet V1";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P2_Helmet_Intel_MC_V1.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Intel_MC_V2: JLTS_CloneHelmetP2MC
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Marshall Commander Helmet V2";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\P2_Helmet_Intel_MC_V2.paa"
			};
		};

	class FST_RSOG_P2_Helmet_White: FST_P2_Helmet_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  White Phase 2 Helmet";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\RSOG_P2_White.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Custom_Baron: FST_P2_Helmet_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Custom P2 Helmet (Baron)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Customs\RSOG_P2_Baron.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Custom_Apathy: FST_P2_Helmet_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Custom P2 Helmet (Apathy)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Customs\RSOG_MC_Apathy_White.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Custom_Bendable: FST_P2_Helmet_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Custom P2 Helmet (Bendable)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Customs\RSOG_P2_Bendable.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Custom_Freezy: FST_P2_Helmet_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Custom P2 Helmet (Freezy)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Customs\RSOG_P2_Freezy.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Custom_Phoenix: FST_P2_Helmet_Base
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Custom P2 Helmet (Phoenix)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Customs\RSOG_P2_Phoenix.paa"
			};
		};

	class FST_RSOG_BARC_Helmet_Custom_Gabriel: JLTS_CloneHelmetBARC
		{
			scope=2;
			scopeCurator=2;
			scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Custom BARC Helmet (Gabriel)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Customs\RSOG_BARC_Gabriel.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Pilot_V1: 3as_P2_Pilot_helmet
		{
			author="Apathy";
			scope=2;
			scopeCurator=2;
			scopeArsenal=2;
			displayName="[41st/RSOG] R.I. Pilot Helmet V1";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\RSOG_P2_Helmet_Pilot_V1.paa",
				"\FST_RSOG\Data\Helmet\RSOG_P2_Helmet_Pilot_V1.paa",
				"\FST_RSOG\Data\Helmet\RSOG_P2_Helmet_Pilot_V1.paa",
				"",
				"\FST_RSOG\Data\Helmet\RSOG_P2_Helmet_Pilot_V1.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Pilot_V2: 3as_P2_Pilot_helmet
		{
			author="Apathy";
			scope=2;
			scopeCurator=2;
			scopeArsenal=2;
			displayName="[41st/RSOG] R.I. Pilot Helmet V2";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\RSOG_P2_Helmet_Pilot_V2.paa",
				"\FST_RSOG\Data\Helmet\RSOG_P2_Helmet_Pilot_V2.paa",
				"\FST_RSOG\Data\Helmet\RSOG_P2_Helmet_Pilot_V2.paa",
				"",
				"\FST_RSOG\Data\Helmet\RSOG_P2_Helmet_Pilot_V2.paa"
			};
		};

	class FST_RSOG_P2_Helmet_Custom_Henderson: 3as_P2_Pilot_helmet
		{
			author="Apathy";
			scope=2;
			scopeCurator=2;
			scopeArsenal=2;
			displayName="[41st/RSOG] R.I. Custom Helmet (Henderson)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Helmet\Customs\RSOG_Pilot_Henderson.paa",
				"\FST_RSOG\Data\Helmet\Customs\RSOG_Pilot_Henderson.paa",
				"\FST_RSOG\Data\Helmet\Customs\RSOG_Pilot_Henderson.paa",
				"",
				"\FST_RSOG\Data\Helmet\Customs\RSOG_Pilot_Henderson.paa"
			};
		};

	class FST_RSOG_Covert_Officer_V1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Cov.Ops./V1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Covert_Officer.paa"
			};
		};

	class FST_RSOG_Covert_Officer_V2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Cov.Ops./V2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Covert_Officer.paa"
			};
		};

	class FST_RSOG_Covert_Heavy_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (Cov.Ops.)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Covert_Officer.paa",
				"\FST_RSOG\Data\Vest\Covert_Heavy.paa"
			};
		};

	class FST_RSOG_Covert_Heavy: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (Cov.Ops.)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Covert_Officer.paa",
				"\FST_RSOG\Data\Vest\Covert_Heavy.paa"
			};
		};

	class FST_RSOG_Covert_CMD_Vest: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (Cov.Ops.)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Covert_Officer.paa"
			};
		};

	class FST_RSOG_Covert_Holster: JLTS_CloneVestHolster
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Holster (Cov.Ops.)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Covert_Officer.paa"
			};
		};

	class FST_RSOG_Covert_Kama: JLTS_CloneVestKama
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Kama (Cov.Ops.)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Covert_Officer.paa"
			};
		};

	class FST_RSOG_Covert_LT_Vest: JLTS_CloneVestLieutenant
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Lieutenants Vest (Cov.Ops.)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Covert_Officer.paa"
			};
		};

	class FST_RSOG_Covert_Recon_NCO_Vest: JLTS_CloneVestReconNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon NCO Vest (Cov.Ops.)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Covert_Heavy.paa"
			};
		};

	class FST_RSOG_Covert_Recon_Vest: JLTS_CloneVestRecon
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Vest (Cov.Ops.)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Covert_Heavy.paa"
			};
		};

	class FST_RSOG_Covert_Recon_Officer_Vest: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (Cov.Ops.)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Covert_Officer.paa",
				"\FST_RSOG\Data\Vest\Covert_Heavy.paa"
			};
		};

	class FST_RSOG_Covert_Suspenders: JLTS_CloneVestSuspender
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Suspenders (Cov.Ops.)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Covert_Ops_Pouch.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V1_1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V1.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V1.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V1_2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V1.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V1.paa"
			};
		};

	class FST_RSOG_Stealth_Heavy_NCO_V1: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (Stealth.Ops./V1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V1.paa",
				"\FST_RSOG\Data\Vest\Stealth_Heavy.paa"
			};
		};

	class FST_RSOG_Stealth_Heavy_V1: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (Stealth.Ops./V1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V1.paa",
				"\FST_RSOG\Data\Vest\Stealth_Heavy.paa"
			};
		};

	class FST_RSOG_Stealth_CMD_Vest_V1: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (Stealth.Ops./V1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V1.paa"
			};
		};

	class FST_RSOG_Stealth_Holster_V1: JLTS_CloneVestHolster
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Holster (Stealth.Ops./V1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V1.paa"
			};
		};

	class FST_RSOG_Stealth_Kama_V1: JLTS_CloneVestKama
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Kama (Stealth.Ops./V1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V1.paa"
			};
		};

	class FST_RSOG_Stealth_LT_Vest_V1: JLTS_CloneVestLieutenant
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Lieutenants Vest (Stealth.Ops./V1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V1.paa"
			};
		};

	class FST_RSOG_Stealth_Recon_NCO_Vest_V1: JLTS_CloneVestReconNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon NCO Vest (Stealth.Ops./V1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Heavy.paa"
			};
		};

	class FST_RSOG_Stealth_Recon_Vest_V1: JLTS_CloneVestRecon
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Vest (Stealth.Ops./V1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Heavy.paa"
			};
		};

	class FST_RSOG_Stealth_Recon_Officer_Vest_V1: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (Stealth.Ops./V1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V1.paa",
				"\FST_RSOG\Data\Vest\Stealth_Heavy.paa"
			};
		};

	class FST_RSOG_Stealth_Suspenders_V1: JLTS_CloneVestSuspender
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Suspenders (Stealth.Ops./V1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Ops_Pouch_V1.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V2_1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V2.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V2.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V2_2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V2.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V2.paa"
			};
		};

	class FST_RSOG_Stealth_Heavy_NCO_V2: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (Stealth.Ops./V2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V9.paa",
				"\FST_RSOG\Data\Vest\Stealth_Heavy.paa"
			};
		};

	class FST_RSOG_Stealth_Heavy_V2: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (Stealth.Ops./V2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V9.paa",
				"\FST_RSOG\Data\Vest\Stealth_Heavy.paa"
			};
		};

	class FST_RSOG_Stealth_CMD_Vest_V2: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (Stealth.Ops./V2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V2.paa"
			};
		};

	class FST_RSOG_Stealth_Holster_V2: JLTS_CloneVestHolster
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Holster (Stealth.Ops./V2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V2.paa"
			};
		};

	class FST_RSOG_Stealth_Kama_V2: JLTS_CloneVestKama
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Kama (Stealth.Ops./V2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V2.paa"
			};
		};

	class FST_RSOG_Stealth_LT_Vest_V2: JLTS_CloneVestLieutenant
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Lieutenants Vest (Stealth.Ops./V2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V2.paa"
			};
		};

	class FST_RSOG_Stealth_Recon_Officer_Vest_V2: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (Stealth.Ops./V2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V2.paa",
				"\FST_RSOG\Data\Vest\Stealth_Heavy.paa"
			};
		};

	class FST_RSOG_Stealth_Suspenders_V2: JLTS_CloneVestSuspender
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Suspenders (Stealth.Ops./V2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Ops_Pouch_V2.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V3_1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V3.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V3.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V3_2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V3.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V3.paa"
			};
		};

	class FST_RSOG_Stealth_Heavy_NCO_V3: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (Stealth.Ops./V3)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V3.paa",
				"\FST_RSOG\Data\Vest\Stealth_Heavy.paa"
			};
		};

	class FST_RSOG_Stealth_Heavy_V3: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (Stealth.Ops./V3)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V3.paa",
				"\FST_RSOG\Data\Vest\Stealth_Heavy.paa"
			};
		};

	class FST_RSOG_Stealth_CMD_Vest_V3: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (Stealth.Ops./V3)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V3.paa"
			};
		};

	class FST_RSOG_Stealth_Kama_V3: JLTS_CloneVestKama
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Kama (Stealth.Ops./V3)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V3.paa"
			};
		};

	class FST_RSOG_Stealth_LT_Vest_V3: JLTS_CloneVestLieutenant
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Lieutenants Vest (Stealth.Ops./V3)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V5.paa"
			};
		};

	class FST_RSOG_Stealth_Recon_Officer_Vest_V3: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (Stealth.Ops./V3)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V3.paa",
				"\FST_RSOG\Data\Vest\Stealth_Heavy.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V4_1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V4.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V4.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V4_2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V4.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V4.paa"
			};
		};

	class FST_RSOG_Stealth_CMD_Vest_V4: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (Stealth.Ops./V4)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V4.paa"
			};
		};

	class FST_RSOG_Stealth_Kama_V4: JLTS_CloneVestKama
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Kama (Stealth.Ops./V4)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V4.paa"
			};
		};

	class FST_RSOG_Stealth_LT_Vest_V4: JLTS_CloneVestLieutenant
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Lieutenants Vest (Stealth.Ops./V4)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V6.paa"
			};
		};

	class FST_RSOG_Stealth_Recon_Officer_Vest_V4: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (Stealth.Ops./V4)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V4.paa",
				"\FST_RSOG\Data\Vest\Stealth_Heavy.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V5_1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V5.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V5.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V5_2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V5.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V5.paa"
			};
		};

	class FST_RSOG_Stealth_CMD_Vest_V5: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (Stealth.Ops./V5)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V5.paa"
			};
		};

	class FST_RSOG_Stealth_Kama_V5: JLTS_CloneVestKama
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Kama (Stealth.Ops./V5)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V9.paa"
			};
		};

	class FST_RSOG_Stealth_Recon_Officer_Vest_V5: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (Stealth.Ops./V5)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V5.paa",
				"\FST_RSOG\Data\Vest\Clone_vest_heavy_co.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V6_1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V6.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V6.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V6_2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V6.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V6.paa"
			};
		};

	class FST_RSOG_Stealth_CMD_Vest_V6: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (Stealth.Ops./V6)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V6.paa"
			};
		};

	class FST_RSOG_Stealth_Kama_V6: JLTS_CloneVestKama
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Kama (Stealth.Ops./V6)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V10.paa"
			};
		};

	class FST_RSOG_Stealth_Recon_Officer_Vest_V6: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (Stealth.Ops./V6)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V10.paa",
				"\FST_RSOG\Data\Vest\Stealth_Heavy.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V7_1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V7.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V7.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V7_2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V7.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V7.paa"
			};
		};

	class FST_RSOG_Stealth_CMD_Vest_V7: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (Stealth.Ops./V7)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V7.paa"
			};
		};

	class FST_RSOG_Stealth_Recon_Officer_Vest_V7: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (Stealth.Ops./V7)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V7.paa",
				"\FST_RSOG\Data\Vest\Clone_vest_heavy_co.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V8_1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V8.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V8.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V8_2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V8.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V8.paa"
			};
		};

	class FST_RSOG_Stealth_CMD_Vest_V8: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (Stealth.Ops./V8)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V8.paa"
			};
		};

	class FST_RSOG_Stealth_Recon_Officer_Vest_V8: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (Stealth.Ops./V8)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V10.paa",
				"\FST_RSOG\Data\Vest\Stealth_Heavy.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V9_1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V9.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V9.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V9_2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V9.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V9.paa"
			};
		};

	class FST_RSOG_Stealth_CMD_Vest_V9: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (Stealth.Ops./V9)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V9.paa"
			};
		};

	class FST_RSOG_Stealth_Recon_Officer_Vest_V9: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (Stealth.Ops./V9)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V9.paa",
				"\FST_RSOG\Data\Vest\Stealth_Heavy.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V10_1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V10.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V10.paa"
			};
		};

	class FST_RSOG_Stealth_Officer_V10_2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (Stealth.Ops./V10.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V10.paa"
			};
		};

	class FST_RSOG_Stealth_CMD_Vest_V10: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (Stealth.Ops./V10)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V10.paa"
			};
		};

	class FST_RSOG_Stealth_Recon_Officer_Vest_V10: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (Stealth.Ops./V10)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Stealth_Officer_V10.paa",
				"\FST_RSOG\Data\Vest\Stealth_Heavy.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V1_1_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V1.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V1.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V1_2_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V1.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V2.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V1_3_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V1.3)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V3.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V1_4_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V1.4)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V4.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V1_5_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V1.5)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V5.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V1_6_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V1.6)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V6.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V1_7_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V1.7)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V7.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V1_8_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V1.8)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V8.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V2_1_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V2.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V1.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V2_2_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V2.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V2.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V2_3_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V2.3)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V3.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V2_4_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V2.4)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V4.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V2_5_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V2.5)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V5.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V2_6_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V2.6)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V6.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V2_7_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V2.7)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V7.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V2_8_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V2.8)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V8.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V3_1_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V3.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V1.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V3_2_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V3.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V2.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V3_3_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V3.3)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V3.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V3_4_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V3.4)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V4.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V3_5_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V3.5)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V5.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V3_6_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V3.6)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V6.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V3_7_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V3.7)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V7.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V3_8_NCO: JLTS_CloneVestAirborneNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne NCO Vest (R.I./V3.8)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V8.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V1_1: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V1.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V1.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V1_2: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V1.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V2.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V1_3: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V1.3)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V3.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V1_4: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V1.4)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V4.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V1_5: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V1.5)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V5.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V1_6: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V1.6)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V6.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V1_7: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V1.7)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V7.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V1_8: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V1.8)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V8.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V2_1: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V2.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V1.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V2_2: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V2.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V2.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V2_3: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V2.3)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V3.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V2_4: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V2.4)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V4.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V2_5: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V2.5)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V5.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V2_6: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V2.6)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V6.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V2_7: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V2.7)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V7.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V2_8: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V2.8)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V8.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V3_1: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V3.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V1.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V3_2: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V3.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V2.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V3_3: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V3.3)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V3.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V3_4: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V3.4)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V4.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V3_5: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V3.5)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V5.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V3_6: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V3.6)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V6.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V3_7: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V3.7)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V7.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_AB_Vest_V3_8: JLTS_CloneVestAirborne
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Airborne Vest (R.I./V3.8)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V8.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Suspenders_V1: JLTS_CloneVestSuspender
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Suspenders (R.I./V1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Suspenders_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Suspenders_V2: JLTS_CloneVestSuspender
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Suspenders (R.I./V2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Suspenders_V2.paa"
			};
		};

	class FST_RSOG_Republic_Intelligence_Holster: JLTS_CloneVestHolster
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Holster (R.I.)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Kama_V1: JLTS_CloneVestKama
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Kama (R.I./V1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Kama_V2: JLTS_CloneVestKama
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Kama (R.I./V2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Kama_V3: JLTS_CloneVestKama
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Kama (R.I./V3)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Kama_V4: JLTS_CloneVestKama
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Kama (R.I./V4)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V4.paa"
			};
		};

	class FST_RSOG_Rep_Intel_LT_Vest_V1: JLTS_CloneVestLieutenant
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Lieutenants Vest (R.I./V1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_LT_Vest_V2: JLTS_CloneVestLieutenant
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Lieutenants Vest (R.I./V2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V5.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_NCO_Vest_V1: JLTS_CloneVestReconNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon NCO Vest (R.I./V1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_NCO_Vest_V2: JLTS_CloneVestReconNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon NCO Vest (R.I./V2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_NCO_Vest_V3: JLTS_CloneVestReconNCO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon NCO Vest (R.I./V3)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Vest: JLTS_CloneVestRecon
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Vest (R.I./V1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V1_1: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V1.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V1.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V1_2: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V1.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V2.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V1_3: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V1.3)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V3.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V1_4: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V1.4)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V4.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V1_5: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V1.5)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V5.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V1_6: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V1.6)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V6.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V1_7: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V1.7)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V7.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V1_8: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V1.8)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V8.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V2_1: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V2.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V1.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V2_2: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V2.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V2.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V2_3: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V2.3)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V3.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V2_4: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V2.4)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V4.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V2_5: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V2.5)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V5.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V2_6: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V2.6)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V6.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V2_7: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V2.7)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V7.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V2_8: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V2.8)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V8.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V3_1: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V3.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V1.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V3_2: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V3.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V2.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V3_3: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V3.3)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V3.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V3_4: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V3.4)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V4.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V3_5: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V3.5)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V5.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V3_6: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V3.6)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V6.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V3_7: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V3.7)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V7.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Recon_Off_Vest_V3_8: JLTS_CloneVestReconOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Recon Officers Vest (R.I./V3.8)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V8.paa",
				"\FST_RSOG\Data\Vest\Rep_Intel_Acc_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Officer_V1_1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (R.I./V1.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Officer_V1_2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (R.I./V1.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_CMD_Vest_V1: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (R.I./V1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Officer_V2_1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (R.I./V2.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Officer_V2_2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (R.I./V2.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_CMD_Vest_V2: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (R.I./V2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Officer_V3_1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (R.I./V3.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Officer_V3_2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (R.I./V3.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_CMD_Vest_V3: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (R.I./V3)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Officer_V4_1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (R.I./V4.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V4.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Officer_V4_2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (R.I./V4.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V4.paa"
			};
		};

	class FST_RSOG_Rep_Intel_CMD_Vest_V4: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (R.I./V4)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V4.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Officer_V5_1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (R.I./V5.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V5.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Officer_V5_2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (R.I./V5.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V5.paa"
			};
		};

	class FST_RSOG_Rep_Intel_CMD_Vest_V5: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (R.I./V5)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V5.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Officer_V6_1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (R.I./V6.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V6.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Officer_V6_2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (R.I./V6.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V6.paa"
			};
		};

	class FST_RSOG_Rep_Intel_CMD_Vest_V6: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (R.I./V6)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V6.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Officer_V7_1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (R.I./V7.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V7.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Officer_V7_2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (R.I./V7.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V7.paa"
			};
		};

	class FST_RSOG_Rep_Intel_CMD_Vest_V7: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (R.I./V7)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V7.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Officer_V8_1: JLTS_CloneVestOfficer
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (R.I./V8.1)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V8.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Officer_V8_2: JLTS_CloneVestOfficer2
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Officers Vest (R.I./V8.2)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V8.paa"
			};
		};

	class FST_RSOG_Rep_Intel_CMD_Vest_V8: JLTS_CloneVestCommander
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Commanders Vest (R.I./V8)";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Vest\Rep_Intel_Officer_Vest_V8.paa"
			};
		};

	class FST_RSOG_Covert_Armor: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Cov.Ops. Armor";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Covert_Ops_Trooper_DC15A";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Covert_Armor_Recon: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Cov.Ops. Armor (Recon)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Covert_Ops_Trooper_Recon";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Covert_Armor_Grenadier: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Cov.Ops. Armor (Grenadier)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Covert_Ops_Trooper_Grenadier";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Covert_Armor_Support: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Cov.Ops. Armor (Support)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Covert_Ops_Trooper_AR";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV1: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V1)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V1_DC15A";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV1_Recon: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V1/Recon)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V1_Recon";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV1_Grenadier: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V1/Grenadier)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V1_Grenadier";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV1_Support: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V1/Support)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V1_AR";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV2: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V2)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V2_DC15A";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV2_Recon: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V2/Recon)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V2_Recon";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV2_Grenadier: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V2/Grenadier)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V2_Grenadier";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV2_Support: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V2/Support)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V2_AR";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV3: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V3)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V3_DC15A";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV3_Recon: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V3/Recon)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V3_Recon";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV3_Grenadier: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V3/Grenadier)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V3_Grenadier";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV3_Support: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V3/Support)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V3_AR";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV4: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V4)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V4_DC15A";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV4_Recon: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V4/Recon)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V4_Recon";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV4_Grenadier: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V4/Grenadier)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V4_Grenadier";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV4_Support: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V4/Support)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V4_AR";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV5: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V5)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V5_DC15A";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV5_Recon: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V5/Recon)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V5_Recon";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV5_Grenadier: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V5/Grenadier)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V5_Grenadier";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_BaseV5_Support: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Armor (V5/Support)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_V5_AR";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV1: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V1)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV1_DC15A";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV1_Recon: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V1/Recon)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV1_Recon";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV1_Grenadier: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V1/Grenadier)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV1_Grenadier";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV1_Support: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V1/Support)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV1_AR";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV2: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V2)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV2_DC15A";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV2_Recon: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V2/Recon)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV2_Recon";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV2_Grenadier: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V2/Grenadier)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV2_Grenadier";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV2_Support: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V2/Support)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV2_AR";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV3: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V3)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV3_DC15A";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV3_Recon: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V3/Recon)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV3_Recon";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV3_Grenadier: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V3/Grenadier)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV3_Grenadier";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV3_Support: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V3/Support)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV3_AR";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV4: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V4)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV4_DC15A";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV4_Recon: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V4/Recon)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV4_Recon";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV4_Grenadier: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V4/Grenadier)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV4_Grenadier";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV4_Support: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V4/Support)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV4_AR";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV5: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V5)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV5_DC15A";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV5_Recon: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V5/Recon)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV5_Recon";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV5_Grenadier: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V5/Grenadier)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV5_Grenadier";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV5_Support: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V5/Support)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV5_AR";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV6: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V6)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV6_DC15A";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV6_Recon: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V6/Recon)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV6_Recon";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV6_Grenadier: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V6/Grenadier)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV6_Grenadier";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Stealth_Armor_CamoV6_Support: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Armor (V6/Support)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Stealth_Ops_Trooper_CamoV6_AR";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_MC_Armor_BaseV1: FST_Uniform_Merrik_BC
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Marshall Commanders Armor (V1)";
			model="\MRC\JLTS\characters\CloneArmor\CloneArmorMC.p3d";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_MC_V1";
				uniformType="Neopren";
				containerClass="Supply180";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_MC_Armor_BaseV2: FST_Uniform_Merrik_BC
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Marshall Commanders Armor (V2)";
			model="\MRC\JLTS\characters\CloneArmor\CloneArmorMC.p3d";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_MC_V2";
				uniformType="Neopren";
				containerClass="Supply180";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_MC_Armor_BaseV3: FST_Uniform_Merrik_BC
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Marshall Commanders Armor (V3)";
			model="\MRC\JLTS\characters\CloneArmor\CloneArmorMC.p3d";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_MC_V3";
				uniformType="Neopren";
				containerClass="Supply180";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_MC_Armor_BaseV4: FST_Uniform_Merrik_BC
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Marshall Commanders Armor (V4)";
			model="\MRC\JLTS\characters\CloneArmor\CloneArmorMC.p3d";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_MC_V4";
				uniformType="Neopren";
				containerClass="Supply180";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_Armor_V1: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Armor (V1)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_Trooper_V1_DC15A";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_Armor_V1_Recon: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Armor (V1/Recon)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_Trooper_V1_Recon";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_Armor_V1_Grenadier: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Armor (V1/Grenadier)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_Trooper_V1_Grenadier";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_Armor_V1_Support: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Armor (V1/Support)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_Trooper_V1_AR";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_Armor_V2: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Armor (V2)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_Trooper_V2_DC15A";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_Armor_V2_Recon: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Armor (V2/Recon)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_Trooper_V2_Recon";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_Armor_V2_Grenadier: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Armor (V2/Grenadier)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_Trooper_V2_Grenadier";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_Armor_V2_Support: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Armor (V2/Support)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_Trooper_V2_AR";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_Armor_V3: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Armor (V3)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_Trooper_V3_DC15A";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_Armor_V3_Recon: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Armor (V3/Recon)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_Trooper_V3_Recon";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_Armor_V3_Grenadier: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Armor (V3/Grenadier)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_Trooper_V3_Grenadier";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_Armor_V3_Support: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Armor (V3/Support)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_Trooper_V3_AR";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_Armor_V4: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Armor (V4)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_Trooper_V4_DC15A";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_Armor_V4_Recon: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Armor (V4/Recon)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_Trooper_V4_Recon";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_Armor_V4_Grenadier: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Armor (V4/Grenadier)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_Trooper_V4_Grenadier";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Rep_Intel_Armor_V4_Support: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Armor (V4/Support)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Republic_Intel_Trooper_V4_AR";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Regular_Armor_V1: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Regular Armor (V1)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Regular_Trooper_DC15A";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Custom_Armor_Apathy: FST_Trooper_Uniform
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Marshall Commanders Armor (Apathy)";
			picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
			class ItemInfo: UniformItem
			{
				uniformModel="-";
				uniformClass="FST_RSOG_Custom_Trooper_Apathy";
				containerClass="Supply150";
				mass=40;
			};
		};

	class FST_RSOG_Covert_NVG: JLTS_CloneNVG
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  Cov.Ops. Visor";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Covert_Visor.paa"
			};
		};

	class FST_RSOG_Covert_NVG_Spec: JLTS_CloneNVG_spec
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  Cov.Ops. Specialist Visor";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Covert_Visor.paa"
			};
		};

	class FST_RSOG_Covert_Rangefinder: JLTS_CloneNVGRange
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  Cov.Ops. Rangefinger";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Covert_Rangefinder.paa"
			};
		};

	class FST_RSOG_Covert_NVGCC: JLTS_CloneNVGCC
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  Cov.Ops. Commander Visor";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Covert_Helmet_Accessory.paa"
			};
		};

	class FST_RSOG_Covert_NVGMC: JLTS_CloneNVGMC
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  Cov.Ops. Marshall Commander Visor";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Covert_Helmet_Accessory.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Visor_V1: JLTS_CloneNVG
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Visor V1";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Rep_Intel_Visor_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Visor_V2: JLTS_CloneNVG
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Visor V2";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Rep_Intel_Visor_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Visor_V3: JLTS_CloneNVG
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Visor V3";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Rep_Intel_Visor_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Visor_V4: JLTS_CloneNVG
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Visor V4";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Rep_Intel_Visor_V4.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Visor_V1_Spec: JLTS_CloneNVG_spec
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Specialist Visor V1";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Rep_Intel_Visor_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Visor_V2_Spec: JLTS_CloneNVG_spec
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Specialist Visor V2";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Rep_Intel_Visor_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Visor_V3_Spec: JLTS_CloneNVG_spec
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Specialist Visor V3";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Rep_Intel_Visor_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Visor_V4_Spec: JLTS_CloneNVG_spec
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Specialist Visor V4";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Rep_Intel_Visor_V4.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Rangefinder_V1: JLTS_CloneNVGRange
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Rangefinger V1";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Rep_Intel_Rangefinder_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Rangefinder_V2: JLTS_CloneNVGRange
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Rangefinger V2";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Rep_Intel_Rangefinder_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Rangefinder_V3: JLTS_CloneNVGRange
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Rangefinger V3";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Rep_Intel_Rangefinder_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Rangefinder_V4: JLTS_CloneNVGRange
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Rangefinger V4";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Rep_Intel_Rangefinder_V4.paa"
			};
		};

	class FST_RSOG_Rep_Intel_MC_Visor_V1: JLTS_CloneNVGMC
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Marshall Commander Visor V1";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Rep_Intel_MC_Visor_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_MC_Visor_V2: JLTS_CloneNVGMC
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			displayName="[41st/RSOG]  R.I. Marshall Commander Visor V2";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Misc\Rep_Intel_MC_Visor_V2.paa"
			};
		};

	class FST_RSOG_RSOG_NVG_Chip: JLTS_NVG_droid_chip_1
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			author="Apathy";
			displayName="[41st/RSOG] Clone NVG Helmet Chip";
		};

	class FST_RSOG_RSOG_NVG_ChipThermal: JLTS_NVG_droid_chip_2
		{

				scope=2;

				scopeCurator=2;

				scopeArsenal=2;
			author="Apathy";
			displayName="[41st/RSOG] Clone NVG Chip (Thermal)";
			thermalMode[]={1};
		};
};

class CfgVehicles
{
	class FST_P2_Medic;
	class FST_Trooper_ARF;
	class FST_Trooper_P2_CL;
	class FST_Trooper_P2_CPL;
	class FST_Trooper_P2_CS;
	class FST_Trooper_P2_CSS;
	class FST_Trooper_P2_DC15A;
	class FST_Trooper_P2_DC15S;
	class FST_Trooper_P2_EOD;
	class JLTS_Clone_P2_DC15A;
	class JLTS_Clone_RTO_pack;
	class JLTS_Clone_backpack;
	class JLTS_Clone_backpack_RTO;
	class JLTS_Clone_backpack_at_predef;
	class JLTS_Clone_backpack_eod_predef;
	class JLTS_Clone_backpack_medic_predef;
	class JLTS_Clone_backpack_s;
	class JLTS_Clone_belt_bag;
	class JLTS_Clone_belt_bag_medic_predef;
	class JLTS_Clone_belt_bag_ugl_predef;
	class JLTS_Clone_jumppack;
	class JLTS_Clone_jumppack_Chicken;
	class JLTS_Clone_jumppack_JT12;
	class JLTS_Clone_jumppack_mc;
	class JLTS_UAV_prowler_gar_backpack;
	class JLTS_UST_turret_GAR_backpack;
	class JLTS_portable_shield_gar_backpack;
	class SWLB_clone_backpack_predef_heavy;

	// RSOG backpacks and deployable packs copied into the 41st aux namespace.
	class FST_RSOG_Covert_Ops_Backpack: JLTS_Clone_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Cov.Ops. Ruck";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Covert_Ruck_Base.paa"
			};
		};

	class FST_RSOG_Covert_Ops_RTO: JLTS_Clone_backpack_RTO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Cov.Ops. Ruck (COMMS)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Covert_Ruck_Base.paa"
			};
		};

	class FST_RSOG_Covert_Ops_Turret: JLTS_UST_turret_GAR_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Cov.Ops. Ruck (Turret)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Covert_Ruck_Turret.paa"
			};
		};

	class FST_RSOG_Covert_Ops_Shield: JLTS_portable_shield_gar_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Cov.Ops. Ruck (Shield)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Covert_Ruck_Shield.paa"
			};
		};

	class FST_RSOG_Covert_Ops_Prowler: JLTS_UAV_prowler_gar_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Cov.Ops. Ruck (Prowler)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Covert_Ruck_Drone.paa"
			};
		};

	class FST_RSOG_Covert_Ops_RTO_Pack: JLTS_Clone_RTO_pack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Cov.Ops. Comms Module";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Covert_Ops_RTO_Module.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Backpack: JLTS_Clone_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Ruck";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_RTO: JLTS_Clone_backpack_RTO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Ruck (COMMS)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Turret: JLTS_UST_turret_GAR_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Ruck (Turret)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_Turret.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Shield: JLTS_portable_shield_gar_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Ruck (Shield)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_Shield.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Prowler: JLTS_UAV_prowler_gar_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Ruck (Prowler)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_Drone.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Backpack_EOD: JLTS_Clone_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Ruck (EOD)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_EOD.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Backpack_Medic: JLTS_Clone_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Ruck (Medical)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_Medical.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_RTO_Pack: JLTS_Clone_RTO_pack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Comms Module";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ops_RTO_Module.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Camo_Backpack: JLTS_Clone_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Ruck";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_Camo.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Camo_RTO: JLTS_Clone_backpack_RTO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Ruck (COMMS)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_Camo.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Camo_Turret: JLTS_UST_turret_GAR_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Ruck (Turret)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_Camo_Turret.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Camo_Shield: JLTS_portable_shield_gar_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Ruck (Shield)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_Camo_Shield.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Camo_Prowler: JLTS_UAV_prowler_gar_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Ruck (Prowler)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_Camo_Drone.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Camo_Backpack_EOD: JLTS_Clone_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Ruck (EOD)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_Camo_EOD.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Camo_Backpack_Medic: JLTS_Clone_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Ruck (Medical)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_Camo_Medical.paa"
			};
		};

	class FST_RSOG_Rep_Intel_RTO_Pack_V1: JLTS_Clone_RTO_pack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Comms Module V1";
			maximumload=150;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Rep_Intel_RTO_Module_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_RTO_Pack_V2: JLTS_Clone_RTO_pack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Comms Module V2";
			maximumload=150;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Rep_Intel_RTO_Module_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Backpack_V1: JLTS_Clone_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck V1";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_RTO_V1: JLTS_Clone_backpack_RTO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck (COMMS/V1)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V1.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Turret_V1: JLTS_UST_turret_GAR_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck (Turret/V1)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V1_Turret.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Shield_V1: JLTS_portable_shield_gar_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck (Shield/V1)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V1_Shield.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Prowler_V1: JLTS_UAV_prowler_gar_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck (Prowler/V1)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V1_Drone.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Backpack_V2: JLTS_Clone_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck V2";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_RTO_V2: JLTS_Clone_backpack_RTO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck (COMMS/V2)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V2.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Turret_V2: JLTS_UST_turret_GAR_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck (Turret/V2)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V2_Turret.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Shield_V2: JLTS_portable_shield_gar_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck (Shield/V2)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V2_Shield.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Prowler_V2: JLTS_UAV_prowler_gar_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck (Prowler/V2)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V2_Drone.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Backpack_V3: JLTS_Clone_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck V3";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_RTO_V3: JLTS_Clone_backpack_RTO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck (COMMS/V3)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V3.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Turret_V3: JLTS_UST_turret_GAR_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck (Turret/V3)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V3_Turret.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Shield_V3: JLTS_portable_shield_gar_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck (Shield/V3)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V3_Shield.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Prowler_V3: JLTS_UAV_prowler_gar_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck (Prowler/V3)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V3_Drone.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Backpack_V4: JLTS_Clone_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck V4";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V4.paa"
			};
		};

	class FST_RSOG_Rep_Intel_RTO_V4: JLTS_Clone_backpack_RTO
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck (COMMS/V4)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V4.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Turret_V4: JLTS_UST_turret_GAR_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck (Turret/V4)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V4_Turret.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Shield_V4: JLTS_portable_shield_gar_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck (Shield/V4)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V4_Shield.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Prowler_V4: JLTS_UAV_prowler_gar_backpack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Ruck (Prowler/V4)";
			maximumload=75;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V4_Drone.paa"
			};
		};

	class FST_RSOG_Clone_belt_bag: JLTS_Clone_belt_bag
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG] Clone belt bag";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Clone_belt_bag.paa"
			};
		};

	class FST_RSOG_Covert_Ops_Backpack_AT_Pred: JLTS_Clone_backpack_at_predef
		{
			author="Apathy";
			scope=1;
			displayName="[41st/RSOG]  Cov.Ops. Ruck (AT)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Covert_Ruck_Base.paa"
			};
		};

	class FST_RSOG_Covert_Ops_Backpack_AA_Pred: SWLB_clone_backpack_predef_heavy
		{
			author="Apathy";
			scope=1;
			displayName="[41st/RSOG]  Cov.Ops. Ruck (AA)";
			maximumload=350;
			model = "\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Covert_Ruck_Base.paa"
			};
		};

	class FST_RSOG_Covert_Ops_Backpack_EOD_Pred: JLTS_Clone_backpack_eod_predef
		{
			author="Apathy";
			scope=1;
			displayName="[41st/RSOG]  Cov.Ops. Ruck (EOD)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Covert_Ruck_Base.paa"
			};
		};

	class FST_RSOG_Covert_Ops_Backpack_Medic_Pred: JLTS_Clone_backpack_medic_predef
		{
			author="Apathy";
			scope=1;
			displayName="[41st/RSOG]  Cov.Ops. Ruck (Medical)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Covert_Ruck_Base.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Backpack_AT_Pred: JLTS_Clone_backpack_at_predef
		{
			author="Apathy";
			scope=1;
			displayName="[41st/RSOG]  Stealth.Ops. Ruck (AT)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_EOD.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Backpack_AA_Pred: SWLB_clone_backpack_predef_heavy
		{
			author="Apathy";
			scope=1;
			displayName="[41st/RSOG]  Stealth.Ops. Ruck (AA)";
			maximumload=350;
			model = "\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_EOD.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Backpack_EOD_Pred: JLTS_Clone_backpack_eod_predef
		{
			author="Apathy";
			scope=1;
			displayName="[41st/RSOG]  Stealth.Ops. Ruck (EOD)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_EOD.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Backpack_Medic_Pred: JLTS_Clone_backpack_medic_predef
		{
			author="Apathy";
			scope=1;
			displayName="[41st/RSOG]  Stealth.Ops. Ruck (Medical)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_Medical.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Camo_Backpack_AT_Pred: JLTS_Clone_backpack_at_predef
		{
			author="Apathy";
			scope=1;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Ruck (AT)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_Camo_EOD.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Camo_Backpack_AA_Pred: SWLB_clone_backpack_predef_heavy
		{
			author="Apathy";
			scope=1;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Ruck (AA)";
			maximumload=350;
			model = "\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_Camo_EOD.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Camo_Backpack_EOD_Pred: JLTS_Clone_backpack_eod_predef
		{
			author="Apathy";
			scope=1;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Ruck (EOD)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_Camo_EOD.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Camo_Backpack_Medic_Pred: JLTS_Clone_backpack_medic_predef
		{
			author="Apathy";
			scope=1;
			displayName="[41st/RSOG]  Stealth.Ops. Camo Ruck (Medical)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Ruck_Camo_Medical.paa"
			};
		};

	class FST_RSOG_Intel_Ruck_Backpack_AT_Pred_V1: JLTS_Clone_backpack_at_predef
		{
			author="Apathy";
			scope=1;
			displayName="[41st/RSOG]  R.I. Ruck (AT)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V1.paa"
			};
		};

	class FST_RSOG_Intel_Ruck_Backpack_AA_Pred_V1: SWLB_clone_backpack_predef_heavy
		{
			author="Apathy";
			scope=1;
			displayName="[41st/RSOG]  R.I. Ruck (AA)";
			maximumload=350;
			model = "\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V1.paa"
			};
		};

	class FST_RSOG_Intel_Ruck_Backpack_EOD_Pred_V1: JLTS_Clone_backpack_eod_predef
		{
			author="Apathy";
			scope=1;
			displayName="[41st/RSOG]  R.I. Ruck (EOD)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V1.paa"
			};
		};

	class FST_RSOG_Intel_Ruck_Backpack_Medic_Pred: JLTS_Clone_backpack_medic_predef
		{
			author="Apathy";
			scope=1;
			displayName="[41st/RSOG]  R.I. Ruck (Medical)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Intel_Ruck_V1.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Jumppack_MC: JLTS_Clone_jumppack_mc
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Jumppack (MC)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Jumppack_MC.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Jumppack: JLTS_Clone_jumppack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Jumppack";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Jumppack.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Jumppack_JT12: JLTS_Clone_jumppack_JT12
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Jumppack (JT12)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Jumppack_JT12.paa"
			};
		};

	class FST_RSOG_Stealth_Ops_Jumppack_Chicken: JLTS_Clone_jumppack_Chicken
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Stealth.Ops. Jumppack (Chicken)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Stealth_Jumppack_Chicken.paa"
			};
		};

	class FST_RSOG_Covert_Ops_Jumppack_MC: JLTS_Clone_jumppack_mc
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Cov.Ops. Jumppack (MC)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Covert_Jumppack_MC.paa"
			};
		};

	class FST_RSOG_Covert_Ops_Jumppack: JLTS_Clone_jumppack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Cov.Ops. Jumppack";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Covert_Jumppack.paa"
			};
		};

	class FST_RSOG_Covert_Ops_Jumppack_JT12: JLTS_Clone_jumppack_JT12
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Cov.Ops. Jumppack (JT12)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Covert_Jumppack_JT12.paa"
			};
		};

	class FST_RSOG_Covert_Ops_Jumppack_Chicken: JLTS_Clone_jumppack_Chicken
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  Cov.Ops. Jumppack (Chicken)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Covert_Jumppack_Chicken.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Jumppack_MC_B: JLTS_Clone_jumppack_mc
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Commanders Jumppack (Black)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Rep_Intel_Jumppack_MC_B.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Jumppack_B: JLTS_Clone_jumppack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Jumppack (Black)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Rep_Intel_Jumppack_B.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Jumppack_JT12_B: JLTS_Clone_jumppack_JT12
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Jumppack (JT12/Black)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Rep_Intel_Jumppack_JT12_B.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Jumppack_Chicken_B: JLTS_Clone_jumppack_Chicken
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Jumppack (Chicken/Black)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Rep_Intel_Jumppack_Chicken_B.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Jumppack_MC_G: JLTS_Clone_jumppack_mc
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Commanders Jumppack (Grey)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Rep_Intel_Jumppack_MC_G.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Jumppack_G: JLTS_Clone_jumppack
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Jumppack (Grey)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Rep_Intel_Jumppack_G.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Jumppack_JT12_G: JLTS_Clone_jumppack_JT12
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Jumppack (JT12/Grey)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Rep_Intel_Jumppack_JT12_G.paa"
			};
		};

	class FST_RSOG_Rep_Intel_Jumppack_Chicken_G: JLTS_Clone_jumppack_Chicken
		{
			author="Apathy";
			scope=2;
			displayName="[41st/RSOG]  R.I. Jumppack (Chicken/Grey)";
			maximumload=350;
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Backpack\Rep_Intel_Jumppack_Chicken_G.paa"
			};
		};

	// RSOG infantry. These inherit from 41st/FST soldier classes, not the old SOG aux.
	class FST_RSOG_Covert_Ops_Trooper_DC15A: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Trooper (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor";
			nakedUniform="FST_RSOG_Covert_Armor";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Holster"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Holster"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_Grenadier: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Grenadier (DC-15A/GL)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor_Grenadier";
			nakedUniform="FST_RSOG_Covert_Armor_Grenadier";
			backpack="JLTS_Clone_belt_bag_ugl_predef";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				"\FST_RSOG\Data\Misc\Covert_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor_Grenadier",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Holster"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor_Grenadier",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Holster"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_DC15S: FST_Trooper_P2_DC15S
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Trooper (DC-15S)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor";
			nakedUniform="FST_RSOG_Covert_Armor";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Suspenders"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Suspenders"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_AB: FST_Trooper_P2_DC15S
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Airborne";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor";
			nakedUniform="FST_RSOG_Covert_Armor";
			backpack="lsd_gar_hawkbat_backpack";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Heavy"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Heavy"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_DP23: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Trooper (DP-23)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor";
			nakedUniform="FST_RSOG_Covert_Armor";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Suspenders"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Suspenders"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_Jump: FST_Trooper_P2_DC15S
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Jumptrooper";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor";
			nakedUniform="FST_RSOG_Covert_Armor";
			backpack="FST_RSOG_Covert_Ops_Jumppack";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_NVG_Spec",
				"FST_RSOG_Covert_Holster"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_NVG_Spec",
				"FST_RSOG_Covert_Holster"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_Medic: FST_P2_Medic
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Medic";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_Medic.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor";
			nakedUniform="FST_RSOG_Covert_Armor";
			backpack="FST_RSOG_Covert_Ops_Backpack_Medic_Pred";
			identityTypes[]=
			{
				"JLTS_voice_clone",
				"JLTS_head_clone",
				"JLTS_Clone_P2"
			};
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper_MED.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			weapons[]=
			{
				"JLTS_DC15S",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_DC15S",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			respawnMagazines[]=
			{
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Heavy",
				"FirstAidKit"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Heavy",
				"FirstAidKit"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_Marksman: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Marksman";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor_Recon";
			nakedUniform="FST_RSOG_Covert_Armor_Recon";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Recon_Vest",
				"FST_RSOG_Covert_NVG_Spec"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Recon_Vest",
				"FST_RSOG_Covert_NVG_Spec"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_Sniper: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Sniper";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor_Recon";
			nakedUniform="FST_RSOG_Covert_Armor_Recon";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			weapons[]=
			{
				"JLTS_DC15X_scoped",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_DC15X_scoped",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			respawnMagazines[]=
			{
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Recon_Vest",
				"FST_RSOG_Covert_NVG_Spec"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Recon_Vest",
				"FST_RSOG_Covert_NVG_Spec"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_EOD: FST_Trooper_P2_EOD
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="EOD";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor";
			nakedUniform="FST_RSOG_Covert_Armor";
			backpack="FST_RSOG_Covert_Ops_Backpack_EOD_Pred";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper_EOD.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Suspenders"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Suspenders"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_RTO: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="RTO";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor_Recon";
			nakedUniform="FST_RSOG_Covert_Armor_Recon";
			backpack="FST_RSOG_Covert_Ops_RTO";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Holster"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Holster"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_Prowler: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Drone Operator";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor";
			nakedUniform="FST_RSOG_Covert_Armor";
			backpack="FST_RSOG_Covert_Ops_Prowler";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Holster"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Holster"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_AT: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Anti-Tank";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor";
			nakedUniform="FST_RSOG_Covert_Armor";
			backpack="FST_RSOG_Covert_Ops_Backpack_AT_Pred";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Suspenders"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Suspenders"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_AA: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Anti-Air";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor";
			nakedUniform="FST_RSOG_Covert_Armor";
			model = "\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
			backpack="FST_RSOG_Covert_Ops_Backpack_AA_Pred";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			weapons[]=
			{
				"JLTS_DC15A",
				"JLTS_DC17SA",
				"SWLW_PLX1_AA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_DC15A",
				"JLTS_DC17SA",
				"SWLW_PLX1_AA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC17SA_mag",
				"SWLW_plx1_aa_mag",
				"SWLW_plx1_aa_mag",
				"SWLW_plx1_aa_mag",
				"ls_mag_classA_thermalDet",
				"ls_mag_classA_thermalDet",
				"SmokeShell",
				"SmokeShellRed"
			};
			respawnMagazines[]=
			{
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC17SA_mag",
				"SWLW_plx1_aa_mag",
				"SWLW_plx1_aa_mag",
				"SWLW_plx1_aa_mag",
				"ls_mag_classA_thermalDet",
				"ls_mag_classA_thermalDet",
				"SmokeShell",
				"SmokeShellRed"
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Suspenders"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Suspenders"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_AR: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Support Gunner";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_AR.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor_Support";
			nakedUniform="FST_RSOG_Covert_Armor_Support";
			backpack="FST_RSOG_Covert_Ops_Backpack";
			identityTypes[]=
			{
				"JLTS_voice_clone",
				"JLTS_head_clone",
				"JLTS_Clone_P2"
			};
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3",
				"insignia"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				"\FST_RSOG\Data\Misc\Covert_Ops_Recon.paa",
				""
			};
			weapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			respawnMagazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor_Support",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Officer_V1",
				"FST_RSOG_Covert_NVGCC"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor_Support",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Officer_V1",
				"FST_RSOG_Covert_NVGCC"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_Recon: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Recon Marine";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor_Recon";
			nakedUniform="FST_RSOG_Covert_Armor_Recon";
			backpack="FST_RSOG_Covert_Ops_RTO";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				"\FST_RSOG\Data\Misc\Covert_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor_Recon",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Recon_Vest",
				"FST_RSOG_Covert_NVG_Spec"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor_Recon",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Recon_Vest"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_CPL: FST_Trooper_P2_CPL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Corporal";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor";
			nakedUniform="FST_RSOG_Covert_Armor";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Recon_Vest",
				"FST_RSOG_Covert_NVG"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Recon_Vest",
				"FST_RSOG_Covert_NVG"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_ABNCO: FST_Trooper_P2_CPL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Airborne NCO";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor";
			nakedUniform="FST_RSOG_Covert_Armor";
			backpack="lsd_gar_hawkbat_backpack";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Heavy_NCO"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Heavy_NCO"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_SGT: FST_Trooper_P2_CS
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Sergeant";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor";
			nakedUniform="FST_RSOG_Covert_Armor";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Recon_NCO_Vest",
				"FST_RSOG_Covert_NVG_Spec"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Recon_NCO_Vest",
				"FST_RSOG_Covert_NVG_Spec"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_SGM: FST_Trooper_P2_CSS
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Sergeant Major";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor";
			nakedUniform="FST_RSOG_Covert_Armor";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Recon_Officer_Vest",
				"FST_RSOG_Covert_NVG_Spec"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Recon_Officer_Vest",
				"FST_RSOG_Covert_NVG_Spec"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_LT: FST_Trooper_P2_CL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Lieutenant";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor";
			nakedUniform="FST_RSOG_Covert_Armor";
			backpack="JLTS_Clone_LR_attachment";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_LT_Vest",
				"FST_RSOG_Covert_NVG_Spec"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_LT_Vest",
				"FST_RSOG_Covert_NVG_Spec"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_CPT: FST_Trooper_P2_CL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Captain";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor";
			nakedUniform="FST_RSOG_Covert_Armor";
			backpack="JLTS_Clone_LR_attachment";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Officer_V1",
				"FST_RSOG_Covert_Rangefinder"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Officer_V1",
				"FST_RSOG_Covert_Rangefinder"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_MAJ: FST_Trooper_P2_CL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Major";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor";
			nakedUniform="FST_RSOG_Covert_Armor";
			backpack="JLTS_Clone_LR_attachment";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Officer_V2",
				"FST_RSOG_Covert_Rangefinder"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_Officer_V2",
				"FST_RSOG_Covert_Rangefinder"
			};
		};

	class FST_RSOG_Covert_Ops_Trooper_CMD: FST_Trooper_P2_CL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Commander";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Covert_Ops";
			uniformclass="FST_RSOG_Covert_Armor";
			nakedUniform="FST_RSOG_Covert_Armor";
			backpack="JLTS_Clone_LR_attachment";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Covert_Upper.paa",
				"\FST_RSOG\Data\Legs\Covert_Lower.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_CMD_Vest",
				"FST_RSOG_Covert_NVGCC"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Covert_Armor",
				"FST_RSOG_SOG_Helmet_Covert",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Covert_CMD_Vest",
				"FST_RSOG_Covert_NVGCC"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_DC15A: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Trooper (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V1_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V1_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_Grenadier: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Grenadier (DC-15A/GL)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1_Grenadier";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1_Grenadier";
			backpack="JLTS_Clone_belt_bag_ugl_predef";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_DC15S: FST_Trooper_P2_DC15S
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Trooper (DC-15S)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V1_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Suspenders_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V1_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Suspenders_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_AB: FST_Trooper_P2_DC15S
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Airborne";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			backpack="lsd_gar_hawkbat_backpack";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Heavy_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Heavy_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_DP23: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Trooper (DP-23)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V1_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Suspenders_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V1_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Suspenders_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_Jump: FST_Trooper_P2_DC15S
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Jumptrooper";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			backpack="FST_RSOG_Stealth_Ops_Jumppack";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Suspenders_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Suspenders_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_Medic: FST_P2_Medic
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Medic";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_Medic.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			backpack="FST_RSOG_Stealth_Ops_Backpack_Medic_Pred";
			identityTypes[]=
			{
				"JLTS_voice_clone",
				"JLTS_head_clone",
				"JLTS_Clone_P2"
			};
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			weapons[]=
			{
				"JLTS_DC15S",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_DC15S",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			respawnMagazines[]=
			{
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC15S_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V1_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Heavy_V1",
				"FirstAidKit"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V1_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Heavy_V1",
				"FirstAidKit"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_Marksman: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Marksman";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1_Recon";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1_Recon";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_Sniper: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Sniper";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1_Recon";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1_Recon";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV4.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				""
			};
			weapons[]=
			{
				"JLTS_DC15X_scoped",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_DC15X_scoped",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			respawnMagazines[]=
			{
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_EOD: FST_Trooper_P2_EOD
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="EOD";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			backpack="FST_RSOG_Stealth_Ops_Backpack_EOD_Pred";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Suspenders_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Suspenders_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_RTO: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="RTO";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			backpack="FST_RSOG_Stealth_Ops_RTO";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_Prowler: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Drone Operator";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			backpack="FST_RSOG_Stealth_Ops_Prowler";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_AT: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Anti-Tank";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			backpack="FST_RSOG_Stealth_Ops_Backpack_AT_Pred";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Suspenders_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Suspenders_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_AA: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Anti-Air";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			model = "\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
			backpack="FST_RSOG_Stealth_Ops_Backpack_AA_Pred";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			weapons[]=
			{
				"JLTS_DC15A",
				"JLTS_DC17SA",
				"SWLW_PLX1_AA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_DC15A",
				"JLTS_DC17SA",
				"SWLW_PLX1_AA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC17SA_mag",
				"SWLW_plx1_aa_mag",
				"SWLW_plx1_aa_mag",
				"SWLW_plx1_aa_mag",
				"ls_mag_classA_thermalDet",
				"ls_mag_classA_thermalDet",
				"SmokeShell",
				"SmokeShellRed"
			};
			respawnMagazines[]=
			{
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC17SA_mag",
				"SWLW_plx1_aa_mag",
				"SWLW_plx1_aa_mag",
				"SWLW_plx1_aa_mag",
				"ls_mag_classA_thermalDet",
				"ls_mag_classA_thermalDet",
				"SmokeShell",
				"SmokeShellRed"
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Suspenders_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Suspenders_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_AR: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Support Gunner";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_AR.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1_Support";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1_Support";
			backpack="FST_RSOG_Stealth_Ops_Backpack";
			identityTypes[]=
			{
				"JLTS_voice_clone",
				"JLTS_head_clone",
				"JLTS_Clone_P2"
			};
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3",
				"insignia"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			weapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			respawnMagazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_Recon: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Recon Marine";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1_Recon";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1_Recon";
			backpack="FST_RSOG_Stealth_Ops_RTO";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_CPL: FST_Trooper_P2_CPL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Corporal";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_ABNCO: FST_Trooper_P2_CPL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Airborne NCO";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			backpack="lsd_gar_hawkbat_backpack";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Heavy_NCO_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Heavy_NCO_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_SGT: FST_Trooper_P2_CS
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Sergeant";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_NCO_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_NCO_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_SGM: FST_Trooper_P2_CSS
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Sergeant Major";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Officer_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Officer_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_LT: FST_Trooper_P2_CL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Lieutenant";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			backpack="JLTS_Clone_LR_attachment";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V2_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_LT_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V2_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_LT_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_CPT: FST_Trooper_P2_CL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Captain";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			backpack="JLTS_Clone_LR_attachment";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V2_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Officer_V1_1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V2_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Officer_V1_1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_MAJ: FST_Trooper_P2_CL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Major";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			backpack="JLTS_Clone_LR_attachment";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V2_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Officer_V1_2"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V2_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Officer_V1_2"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V1_CMD: FST_Trooper_P2_CL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Commander";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV1";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV1";
			backpack="JLTS_Clone_LR_attachment";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V2_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Officer_V1_1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV1",
				"FST_RSOG_SOG_Helmet_Stealth_V2_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Officer_V1_1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V2_DC15A: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Trooper (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV2";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV2";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV2.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV2",
				"FST_RSOG_SOG_Helmet_Stealth_V2_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV2",
				"FST_RSOG_SOG_Helmet_Stealth_V2_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V2_Grenadier: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Grenadier (DC-15A/GL)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV2_Grenadier";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV2_Grenadier";
			backpack="JLTS_Clone_belt_bag_ugl_predef";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV2.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV2_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV2_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V2_AR: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Support Gunner";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_AR.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV2_Support";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV2_Support";
			backpack="FST_RSOG_Stealth_Ops_Backpack";
			identityTypes[]=
			{
				"JLTS_voice_clone",
				"JLTS_head_clone",
				"JLTS_Clone_P2"
			};
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3",
				"insignia"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV2.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			weapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			respawnMagazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV2_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV2_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V2_Recon: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Recon Marine";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV2_Recon";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV2_Recon";
			backpack="FST_RSOG_Stealth_Ops_RTO";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV2.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV2_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV2_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V3_DC15A: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Trooper (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV3";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV3";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV3.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV3",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV3",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V3_Grenadier: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Grenadier (DC-15A/GL)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV3_Grenadier";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV3_Grenadier";
			backpack="JLTS_Clone_belt_bag_ugl_predef";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV3.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV3_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV3_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V3_AR: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Support Gunner";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_AR.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV3_Support";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV3_Support";
			backpack="FST_RSOG_Stealth_Ops_Backpack";
			identityTypes[]=
			{
				"JLTS_voice_clone",
				"JLTS_head_clone",
				"JLTS_Clone_P2"
			};
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3",
				"insignia"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV3.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			weapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			respawnMagazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV3_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV3_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V3_Recon: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Recon Marine";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV3_Recon";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV3_Recon";
			backpack="FST_RSOG_Stealth_Ops_RTO";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV3.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV3_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV3_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V4_DC15A: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Trooper (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV4";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV4";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV4.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV4",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV4",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V4_Grenadier: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Grenadier (DC-15A/GL)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV4_Grenadier";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV4_Grenadier";
			backpack="JLTS_Clone_belt_bag_ugl_predef";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV4.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV4_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV4_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V4_AR: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Support Gunner";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_AR.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV4_Support";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV4_Support";
			backpack="FST_RSOG_Stealth_Ops_Backpack";
			identityTypes[]=
			{
				"JLTS_voice_clone",
				"JLTS_head_clone",
				"JLTS_Clone_P2"
			};
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3",
				"insignia"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV4.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			weapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			respawnMagazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV4_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV4_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V4_Recon: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Recon Marine";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV4_Recon";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV4_Recon";
			backpack="FST_RSOG_Stealth_Ops_RTO";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV4.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV4_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV4_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V5_DC15A: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Trooper (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV5";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV5";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV5.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV5",
				"FST_RSOG_SOG_Helmet_Stealth_V1_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV5",
				"FST_RSOG_SOG_Helmet_Stealth_V1_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V5_Grenadier: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Grenadier (DC-15A/GL)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV5_Grenadier";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV5_Grenadier";
			backpack="JLTS_Clone_belt_bag_ugl_predef";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV5.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV5_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV5_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V5_AR: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Support Gunner";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_AR.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV5_Support";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV5_Support";
			backpack="FST_RSOG_Stealth_Ops_Backpack";
			identityTypes[]=
			{
				"JLTS_voice_clone",
				"JLTS_head_clone",
				"JLTS_Clone_P2"
			};
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3",
				"insignia"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV5.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			weapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			respawnMagazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV5_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV5_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_V5_Recon: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Recon Marine";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_BaseV5_Recon";
			nakedUniform="FST_RSOG_Stealth_Armor_BaseV5_Recon";
			backpack="FST_RSOG_Stealth_Ops_RTO";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_BaseV5.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Base.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV5_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_BaseV5_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV1_DC15A: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Trooper (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV1";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV1",
				"FST_RSOG_SOG_Helmet_Stealth_V1_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV1",
				"FST_RSOG_SOG_Helmet_Stealth_V1_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV1_Grenadier: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Grenadier (DC-15A/GL)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV1_Grenadier";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV1_Grenadier";
			backpack="JLTS_Clone_belt_bag_ugl_predef";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV1_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV1_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV1_AR: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Support Gunner";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_AR.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV1_Support";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV1_Support";
			backpack="FST_RSOG_Stealth_Ops_Backpack";
			identityTypes[]=
			{
				"JLTS_voice_clone",
				"JLTS_head_clone",
				"JLTS_Clone_P2"
			};
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3",
				"insignia"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			weapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			respawnMagazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV1_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV1_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV1_Recon: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Recon Marine";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV1_Recon";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV1_Recon";
			backpack="FST_RSOG_Stealth_Ops_RTO";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV1.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV1_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV1_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV2_DC15A: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Trooper (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV2";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV2";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV2.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV2",
				"FST_RSOG_SOG_Helmet_Stealth_V2_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV2",
				"FST_RSOG_SOG_Helmet_Stealth_V2_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV2_Grenadier: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Grenadier (DC-15A/GL)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV2_Grenadier";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV2_Grenadier";
			backpack="JLTS_Clone_belt_bag_ugl_predef";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV2.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV2_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV2_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV2_AR: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Support Gunner";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_AR.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV2_Support";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV2_Support";
			backpack="FST_RSOG_Stealth_Ops_Backpack";
			identityTypes[]=
			{
				"JLTS_voice_clone",
				"JLTS_head_clone",
				"JLTS_Clone_P2"
			};
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3",
				"insignia"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV2.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			weapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			respawnMagazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV2_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV2_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV2_Recon: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Recon Marine";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV2_Recon";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV2_Recon";
			backpack="FST_RSOG_Stealth_Ops_RTO";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV2.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV2_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV2_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV3_DC15A: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Trooper (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV3";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV3";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV3.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV3",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV3",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV3_Grenadier: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Grenadier (DC-15A/GL)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV3_Grenadier";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV3_Grenadier";
			backpack="JLTS_Clone_belt_bag_ugl_predef";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV3.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV3_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV3_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV3_AR: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Support Gunner";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_AR.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV3_Support";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV3_Support";
			backpack="FST_RSOG_Stealth_Ops_Backpack";
			identityTypes[]=
			{
				"JLTS_voice_clone",
				"JLTS_head_clone",
				"JLTS_Clone_P2"
			};
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3",
				"insignia"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV3.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			weapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			respawnMagazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV3_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV3_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV3_Recon: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Recon Marine";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV3_Recon";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV3_Recon";
			backpack="FST_RSOG_Stealth_Ops_RTO";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV3.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV3_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV3_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV4_DC15A: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Trooper (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV4";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV4";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV4.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV4",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV4",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV4_Grenadier: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Grenadier (DC-15A/GL)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV4_Grenadier";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV4_Grenadier";
			backpack="JLTS_Clone_belt_bag_ugl_predef";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV4.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV4_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV4_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV4_AR: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Support Gunner";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_AR.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV4_Support";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV4_Support";
			backpack="FST_RSOG_Stealth_Ops_Backpack";
			identityTypes[]=
			{
				"JLTS_voice_clone",
				"JLTS_head_clone",
				"JLTS_Clone_P2"
			};
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3",
				"insignia"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV4.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			weapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			respawnMagazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV4_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV4_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV4_Recon: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Recon Marine";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV4_Recon";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV4_Recon";
			backpack="FST_RSOG_Stealth_Ops_RTO";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV4.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV4_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV4_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV5_DC15A: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Trooper (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV5";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV5";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV5.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV5",
				"FST_RSOG_SOG_Helmet_Stealth_V1_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV5",
				"FST_RSOG_SOG_Helmet_Stealth_V1_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV5_Grenadier: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Grenadier (DC-15A/GL)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV5_Grenadier";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV5_Grenadier";
			backpack="JLTS_Clone_belt_bag_ugl_predef";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV5.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV5_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV5_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV5_AR: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Support Gunner";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_AR.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV5_Support";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV5_Support";
			backpack="FST_RSOG_Stealth_Ops_Backpack";
			identityTypes[]=
			{
				"JLTS_voice_clone",
				"JLTS_head_clone",
				"JLTS_Clone_P2"
			};
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3",
				"insignia"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV5.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			weapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			respawnMagazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV5_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV5_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV5_Recon: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Recon Marine";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV5_Recon";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV5_Recon";
			backpack="FST_RSOG_Stealth_Ops_RTO";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV5.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV5_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV5_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV6_DC15A: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Trooper (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV6";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV6";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV6.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV6",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV6",
				"FST_RSOG_SOG_Helmet_Stealth_V3_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Holster_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV6_Grenadier: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Grenadier (DC-15A/GL)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV6_Grenadier";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV6_Grenadier";
			backpack="JLTS_Clone_belt_bag_ugl_predef";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV6.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV6_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV6_Grenadier",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV6_AR: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Support Gunner";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_AR.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV6_Support";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV6_Support";
			backpack="FST_RSOG_Stealth_Ops_Backpack";
			identityTypes[]=
			{
				"JLTS_voice_clone",
				"JLTS_head_clone",
				"JLTS_Clone_P2"
			};
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3",
				"insignia"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV6.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			weapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_Z6",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			respawnMagazines[]=
			{
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_Z6_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV6_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV6_Support",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Stealth_Ops_Trooper_CamoV6_Recon: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Recon Marine";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Stealth_Ops";
			uniformclass="FST_RSOG_Stealth_Armor_CamoV6_Recon";
			nakedUniform="FST_RSOG_Stealth_Armor_CamoV6_Recon";
			backpack="FST_RSOG_Stealth_Ops_RTO";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV6.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				"\FST_RSOG\Data\Misc\Stealth_Ops_Recon.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV6_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Stealth_Armor_CamoV6_Recon",
				"FST_RSOG_SOG_Helmet_Stealth_SR",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Republic_Intel_MC_V1: FST_Trooper_P2_CL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Marshall Commander V1";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			model="\MRC\JLTS\characters\CloneArmor\CloneArmorMC.p3d";
			icon="JLTS_iconManMarshalCMDR";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_marshalcommander.jpg";
			uniformclass="FST_RSOG_Rep_Intel_MC_Armor_BaseV1";
			nakedUniform="FST_RSOG_Rep_Intel_MC_Armor_BaseV1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_MC_V1.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				"\FST_RSOG\Data\Rank\MC_Rank.paa"
			};
			hiddenSelectionsMaterials[]=
			{
				"41st_Armor\Data\Other\Clone_armor1_mc.rvmat",
				"41st_Armor\Data\Other\Clone_Armor_P2_Lower.rvmat"
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_MC_Armor_BaseV1",
				"FST_RSOG_P2_Helmet_Intel_MC_V1",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster",
				"FST_RSOG_Rep_Intel_MC_Visor_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_MC_Armor_BaseV1",
				"FST_RSOG_P2_Helmet_Intel_MC_V1",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster",
				"FST_RSOG_Rep_Intel_MC_Visor_V1"
			};
		};

	class FST_RSOG_Republic_Intel_MC_V2: FST_Trooper_P2_CL
		{
			author="41st / RSOG";
			scopecurator=0;
			displayName="Marshall Commander V2";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			model="\MRC\JLTS\characters\CloneArmor\CloneArmorMC.p3d";
			icon="JLTS_iconManMarshalCMDR";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_marshalcommander.jpg";
			uniformclass="FST_RSOG_Rep_Intel_MC_Armor_BaseV2";
			nakedUniform="FST_RSOG_Rep_Intel_MC_Armor_BaseV2";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_MC_V1_1.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				"\FST_RSOG\Data\Rank\MC_Rank.paa"
			};
			hiddenSelectionsMaterials[]=
			{
				"41st_Armor\Data\Other\Clone_armor1_mc.rvmat",
				"41st_Armor\Data\Other\Clone_Armor_P2_Lower.rvmat"
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_MC_Armor_BaseV2",
				"FST_RSOG_P2_Helmet_Intel_MC_V1",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster",
				"FST_RSOG_Rep_Intel_MC_Visor_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_MC_Armor_BaseV2",
				"FST_RSOG_P2_Helmet_Intel_MC_V1",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster",
				"FST_RSOG_Rep_Intel_MC_Visor_V1"
			};
		};

	class FST_RSOG_Republic_Intel_MC_V3: FST_Trooper_P2_CL
		{
			author="41st / RSOG";
			scopecurator=0;
			displayName="Marshall Commander V3";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			model="\MRC\JLTS\characters\CloneArmor\CloneArmorMC.p3d";
			icon="JLTS_iconManMarshalCMDR";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_marshalcommander.jpg";
			uniformclass="FST_RSOG_Rep_Intel_MC_Armor_BaseV3";
			nakedUniform="FST_RSOG_Rep_Intel_MC_Armor_BaseV3";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_MC_V2.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				"\FST_RSOG\Data\Rank\MC_Rank.paa"
			};
			hiddenSelectionsMaterials[]=
			{
				"41st_Armor\Data\Other\Clone_armor1_mc.rvmat",
				"41st_Armor\Data\Other\Clone_Armor_P2_Lower.rvmat"
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_MC_Armor_BaseV3",
				"FST_RSOG_P2_Helmet_Intel_MC_V2",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster",
				"FST_RSOG_Rep_Intel_MC_Visor_V2"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_MC_Armor_BaseV3",
				"FST_RSOG_P2_Helmet_Intel_MC_V2",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster",
				"FST_RSOG_Rep_Intel_MC_Visor_V2"
			};
		};

	class FST_RSOG_Republic_Intel_MC_V4: FST_Trooper_P2_CL
		{
			author="41st / RSOG";
			scopecurator=0;
			displayName="Marshall Commander V4";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			model="\MRC\JLTS\characters\CloneArmor\CloneArmorMC.p3d";
			icon="JLTS_iconManMarshalCMDR";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_marshalcommander.jpg";
			uniformclass="FST_RSOG_Rep_Intel_MC_Armor_BaseV4";
			nakedUniform="FST_RSOG_Rep_Intel_MC_Armor_BaseV4";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_MC_V2_1.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				"\FST_RSOG\Data\Rank\MC_Rank.paa"
			};
			hiddenSelectionsMaterials[]=
			{
				"41st_Armor\Data\Other\Clone_armor1_mc.rvmat",
				"41st_Armor\Data\Other\Clone_Armor_P2_Lower.rvmat"
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_MC_Armor_BaseV4",
				"FST_RSOG_P2_Helmet_Intel_MC_V2",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster",
				"FST_RSOG_Rep_Intel_MC_Visor_V2"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_MC_Armor_BaseV4",
				"FST_RSOG_P2_Helmet_Intel_MC_V2",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster",
				"FST_RSOG_Rep_Intel_MC_Visor_V2"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_DC15A: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Trooper (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V4";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V4";
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_Grenadier: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Grenadier (DC-15A/GL)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V4";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V4";
			backpack="JLTS_Clone_belt_bag_ugl_predef";
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_DC15S: FST_Trooper_P2_DC15S
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Trooper (DC-15S)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V4";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V4";
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Suspenders_V1",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Suspenders_V1",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_AB: FST_Trooper_P2_DC15S
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Airborne";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V1";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V1";
			backpack="lsd_gar_hawkbat_backpack";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V1.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_AB_Helmet_Intel_V1",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_AB_Vest_V1_1",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_AB_Helmet_Intel_V1",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_AB_Vest_V1_1",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_DP23: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Trooper (DP-23)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V4";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V4";
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Suspenders_V1",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Suspenders_V1",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_Medic: FST_P2_Medic
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Medic";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_Medic.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V4";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V4";
			backpack="FST_RSOG_Intel_Ruck_Backpack_Medic_Pred";
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_AB_Vest_V1_1",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_AB_Vest_V1_1",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_Marksman: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Marksman";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V1_Recon";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V1_Recon";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V1.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1_Recon",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Recon_Vest",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1_Recon",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Recon_Vest",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_Sniper: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Sniper";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V1_Recon";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V1_Recon";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Stealth_Upper_CamoV4.paa",
				"\FST_RSOG\Data\Legs\Stealth_Lower_Camo.paa",
				""
			};
			weapons[]=
			{
				"JLTS_DC15X_scoped",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_DC15X_scoped",
				"JLTS_DC17SA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			respawnMagazines[]=
			{
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC15X_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"JLTS_DC17SA_mag",
				"SmokeShell",
				"SmokeShellGreen",
				"Chemlight_green",
				"Chemlight_green",
				"JLTS_stun_mag_long",
				"HandGrenade",
				"HandGrenade"
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1_Recon",
				"FST_RSOG_Rep_Intel_ARF_V1",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Recon_Vest"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1_Recon",
				"FST_RSOG_Rep_Intel_ARF_V1",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Recon_Vest"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_EOD: FST_Trooper_P2_EOD
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="EOD";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V4";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V4";
			backpack="FST_RSOG_Intel_Ruck_Backpack_EOD_Pred_V1";
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Suspenders_V1",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Suspenders_V1",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_RTO: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="RTO";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V4";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V4";
			backpack="FST_RSOG_Rep_Intel_RTO_V1";
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_Prowler: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Drone Operator";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V4";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V4";
			backpack="FST_RSOG_Rep_Intel_Prowler_V1";
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_AT: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Anti-Tank";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V4";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V4";
			backpack="FST_RSOG_Intel_Ruck_Backpack_AT_Pred_V1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V1.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Suspenders_V1",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Suspenders_V1",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_AA: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Anti-Air";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V4";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V4";
			model = "\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
			backpack="FST_RSOG_Intel_Ruck_Backpack_AA_Pred_V1";
			weapons[]=
			{
				"JLTS_DC15A",
				"JLTS_DC17SA",
				"SWLW_PLX1_AA",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"JLTS_DC15A",
				"JLTS_DC17SA",
				"SWLW_PLX1_AA",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC17SA_mag",
				"SWLW_plx1_aa_mag",
				"SWLW_plx1_aa_mag",
				"SWLW_plx1_aa_mag",
				"ls_mag_classA_thermalDet",
				"ls_mag_classA_thermalDet",
				"SmokeShell",
				"SmokeShellRed"
			};
			respawnMagazines[]=
			{
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC15A_mag",
				"JLTS_DC17SA_mag",
				"SWLW_plx1_aa_mag",
				"SWLW_plx1_aa_mag",
				"SWLW_plx1_aa_mag",
				"ls_mag_classA_thermalDet",
				"ls_mag_classA_thermalDet",
				"SmokeShell",
				"SmokeShellRed"
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Suspenders_V1",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Suspenders_V1",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_AR: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Support Gunner";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_AR.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V4";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V4";
			backpack="FST_RSOG_Rep_Intel_Backpack_V1";
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Recon_Vest",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_V8",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Recon_Vest",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_Recon: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Recon Marine";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V1_Recon";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V1_Recon";
			backpack="FST_RSOG_Rep_Intel_RTO_V1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V1.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				"\FST_RSOG\Data\Misc\Rep_Intel_Armor_Acc_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1_Recon",
				"FST_RSOG_Rep_Intel_ARF_V1",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Recon_Vest"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1_Recon",
				"FST_RSOG_Rep_Intel_ARF_V1",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Recon_Vest"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_CPL: FST_Trooper_P2_CPL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Corporal";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V1";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V1.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Recon_Vest",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Recon_Vest",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_ABNCO: FST_Trooper_P2_CPL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Airborne NCO";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V1";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V1";
			backpack="lsd_gar_hawkbat_backpack";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V1.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Recon_NCO_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Recon_NCO_Vest_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_SGT: FST_Trooper_P2_CS
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Sergeant";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V1";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V1.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Recon_NCO_Vest_V1",
				"FST_RSOG_Rep_Intel_Visor_V1_Spec"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Recon_NCO_Vest_V1",
				"FST_RSOG_Rep_Intel_Visor_V1_Spec"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_SGM: FST_Trooper_P2_CSS
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Sergeant Major";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V1";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V1.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Recon_Off_Vest_V1_1",
				"FST_RSOG_Rep_Intel_Visor_V1_Spec"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Recon_Off_Vest_V1_1",
				"FST_RSOG_Rep_Intel_Visor_V1_Spec"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_LT: FST_Trooper_P2_CL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Lieutenant";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V1";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V1";
			backpack="JLTS_Clone_LR_attachment";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V1.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_LT_Vest_V1",
				"FST_RSOG_Rep_Intel_Rangefinder_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_LT_Vest_V1",
				"FST_RSOG_Rep_Intel_Rangefinder_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_CPT: FST_Trooper_P2_CL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Captain";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V1";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V1";
			backpack="JLTS_Clone_LR_attachment";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V1.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Officer_V1_1",
				"FST_RSOG_Rep_Intel_Rangefinder_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Officer_V1_1",
				"FST_RSOG_Rep_Intel_Rangefinder_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_MAJ: FST_Trooper_P2_CL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Major";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V1";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V1";
			backpack="JLTS_Clone_LR_attachment";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V1.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Officer_V1_2",
				"FST_RSOG_Rep_Intel_Visor_V1_Spec"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Officer_V1_2",
				"FST_RSOG_Rep_Intel_Visor_V1_Spec"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_CMD: FST_Trooper_P2_CL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Commander";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V1";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V1";
			backpack="JLTS_Clone_LR_attachment";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V1.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_CMD_Vest_V1",
				"FST_RSOG_Rep_Intel_Visor_V1_Spec"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_CMD_Vest_V1",
				"FST_RSOG_Rep_Intel_Visor_V1_Spec"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_DC15A: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Trooper (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V1";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V1.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_Grenadier: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Grenadier (DC-15A/GL)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V1_Grenadier";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V1_Grenadier";
			backpack="JLTS_Clone_belt_bag_ugl_predef";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V1.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				"\FST_RSOG\Data\Misc\Rep_Intel_Armor_Acc_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1_Grenadier",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1_Grenadier",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V1_AR: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Support Gunner";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_AR.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V1_Support";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V1_Support";
			backpack="FST_RSOG_Rep_Intel_Backpack_V1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3",
				"insignia"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V1.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				"\FST_RSOG\Data\Misc\Rep_Intel_Armor_Acc_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1_Support",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V1_Support",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V2_DC15A: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Trooper (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V2";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V2";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V2.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V2",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V2",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V2_Grenadier: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Grenadier (DC-15A/GL)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V2_Grenadier";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V2_Grenadier";
			backpack="JLTS_Clone_belt_bag_ugl_predef";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V2.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				"\FST_RSOG\Data\Misc\Rep_Intel_Armor_Acc_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V2_Grenadier",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V2_Grenadier",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V2_AR: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Support Gunner";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_AR.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V2_Support";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V2_Support";
			backpack="FST_RSOG_Rep_Intel_Backpack_V1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3",
				"insignia"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V2.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				"\FST_RSOG\Data\Misc\Rep_Intel_Armor_Acc_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V2_Support",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V2_Support",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V2_Recon: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Recon Marine";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V2_Recon";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V2_Recon";
			backpack="FST_RSOG_Rep_Intel_RTO_V1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V2.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				"\FST_RSOG\Data\Misc\Rep_Intel_Armor_Acc_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V2_Recon",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V2_Recon",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V3_DC15A: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Trooper (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V3";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V3";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V3.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V3",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V3",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V3_Grenadier: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Grenadier (DC-15A/GL)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V3_Grenadier";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V3_Grenadier";
			backpack="JLTS_Clone_belt_bag_ugl_predef";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V3.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				"\FST_RSOG\Data\Misc\Rep_Intel_Armor_Acc_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V3_Grenadier",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V3_Grenadier",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V3_AR: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Support Gunner";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_AR.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V3_Support";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V3_Support";
			backpack="FST_RSOG_Rep_Intel_Backpack_V1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3",
				"insignia"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V3.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				"\FST_RSOG\Data\Misc\Rep_Intel_Armor_Acc_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V3_Support",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V3_Support",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V3_Recon: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Recon Marine";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V3_Recon";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V3_Recon";
			backpack="FST_RSOG_Rep_Intel_RTO_V1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V3.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V1.paa",
				"\FST_RSOG\Data\Misc\Rep_Intel_Armor_Acc_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V3_Recon",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V3_Recon",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V4_DC15A: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Trooper (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V4";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V4";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V4.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V2.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Republic_Intelligence_Holster"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V4_Grenadier: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Grenadier (DC-15A/GL)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V4_Grenadier";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V4_Grenadier";
			backpack="JLTS_Clone_belt_bag_ugl_predef";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V4.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V2.paa",
				"\FST_RSOG\Data\Misc\Rep_Intel_Armor_Acc_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4_Grenadier",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4_Grenadier",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V4_AR: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Support Gunner";
			editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_AR.jpg";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V4_Support";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V4_Support";
			backpack="FST_RSOG_Rep_Intel_Backpack_V1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3",
				"insignia"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V4.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V2.paa",
				"\FST_RSOG\Data\Misc\Rep_Intel_Armor_Acc_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4_Support",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4_Support",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Republic_Intel_Trooper_V4_Recon: FST_Trooper_ARF
		{
			author="41st / RSOG";
			scope=1;
			scopecurator=1;
			scopearsenal=2;
			displayName="Recon Marine";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Rep_Intel_Armor_V4_Recon";
			nakedUniform="FST_RSOG_Rep_Intel_Armor_V4_Recon";
			backpack="FST_RSOG_Rep_Intel_RTO_V1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Rep_Intel_Upper_V4.paa",
				"\FST_RSOG\Data\Legs\Rep_Intel_Lower_V2.paa",
				"\FST_RSOG\Data\Misc\Rep_Intel_Armor_Acc_V1.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4_Recon",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Rep_Intel_Armor_V4_Recon",
				"FST_RSOG_P2_Helmet_Intel_Base",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Stealth_Recon_Vest_V1"
			};
		};

	class FST_RSOG_Regular_Trooper_DC15A: FST_Trooper_P2_DC15A
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Regular Trooper (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Regular_Armor_V1";
			nakedUniform="FST_RSOG_Regular_Armor_V1";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\RSOG_Upper_White.paa",
				"\FST_RSOG\Data\Legs\RSOG_Lower_White.paa",
				""
			};
			linkedItems[]=
			{
				"FST_RSOG_Regular_Armor_V1",
				"RSOG_P2_White",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Suspenders_V1",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Regular_Armor_V1",
				"RSOG_P2_White",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Suspenders_V1",
				"FST_RSOG_Rep_Intel_Visor_V1"
			};
		};

	class FST_RSOG_Custom_Trooper_Apathy: FST_Trooper_P2_CL
		{
			author="41st / RSOG";
			scopecurator=2;
			displayName="Custom Trooper (Apathy) (DC-15A)";
			faction="FST_RSOG_Faction";
			editorSubcategory="FST_RSOG_Republic_Intel";
			uniformclass="FST_RSOG_Custom_Armor_Apathy";
			nakedUniform="FST_RSOG_Custom_Armor_Apathy";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			hiddenSelectionsTextures[]=
			{
				"\FST_RSOG\Data\Chest\Customs\Rep_Apathy_Upper_MC.paa",
				"\FST_RSOG\Data\Legs\Customs\Rep_Apathy_Lower.paa",
				"\FST_RSOG\Data\Rank\MC_Rank.paa"
			};
			linkedItems[]=
			{
				"FST_RSOG_Custom_Armor_Apathy",
				"FST_RSOG_P2_Helmet_Custom_Apathy",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Suspenders_V1"
			};
			respawnLinkedItems[]=
			{
				"FST_RSOG_Custom_Armor_Apathy",
				"FST_RSOG_P2_Helmet_Custom_Apathy",
				"ItemMap",
				"JLTS_CloneBinocular_black",
				"ItemCompass",
				"ItemWatch",
				"FST_RSOG_Rep_Intel_Suspenders_V1"
			};
		};
};
