// KAID_XEH_Compat_3P: adds CBA Extended Event Handler support to 420 unit/static classes whose own
// "class EventHandlers {...}" has no CBA_Extended_EventHandlers subclass. Without it CBA logs
// "Fall back to loop" and polls every unit on every machine. Generated from an engine probe
// (D:/AuxUpdater/xehcompat); each class keeps its exact parent, so no base class changes.
class CfgPatches
{
	class KAID_XEH_Compat_3P
	{
		name = "KAID XEH compat (3P)";
		author = "41st Aux Updater";
		units[] = {};
		weapons[] = {};
		requiredVersion = 2.0;
		requiredAddons[] = {"101st_Aux_Mod_Flags", "3AS_CIS_Walkers_Octopara", "3AS_Prop_Flags", "3AS_Prop_Generators", "3AS_Prop_Interiors", "3AS_Prop_Structures", "3AS_Prop_Sullust", "3AS_Props2_Terminals2", "41ST_ODST_FACTIONS", "442_misc_bottle", "442_misc_personal_locker", "442_misc_shield", "442_ships_coreship", "442_ships_hardcell", "442_ships_lucrehulk", "442_ships_mandator", "442_ships_recusant", "442_ships_subjugator", "442_ships_venator", "442_turrets_droideka", "A3_Boat_F_Destroyer_Destroyer_01", "A3_Boat_F_Jets_Carrier_01", "A3_Characters_F_Patrol", "A3_Props_F_AoW_Civilian_Gallery", "A3_Props_F_Decade_Objectives", "A3_Signs_F", "A3_Structures_F_AoW_Civilian_Gallery_01", "A3_Structures_F_Bootcamp_Training", "A3_Structures_F_EPB_Items_Documents", "A3_Structures_F_Enoch_Military_Camps", "A3_Structures_F_Enoch_Military_Flags", "A3_Structures_F_Exp_Military_Flags", "A3_Structures_F_Kart_Mil_Flags", "A3_Structures_F_Mark_Mil_Flags", "A3_Structures_F_Mark_Training", "A3_Structures_F_Mil_Flags", "A3_Structures_F_Orange_Humanitarian_Flags", "A3_Structures_F_Training", "AMT_DropPod", "CUP_CAMP_Armory_Misc", "CUP_CAMisc", "CUP_CAStructures_Misc_Powerlines", "CUP_Data_baf_Config", "CUP_Misc3_Config", "CUP_Misc_e_Config", "CUP_StandaloneTerrains_Core", "CUP_Terrains_opx_structures_c", "CUP_Terrains_structures_e_c", "DBA_GC_Assets", "DBA_Ground_Vehicles", "DBA_TroopDeploymentPod", "DSA_Spooks", "FIR_AirWeaponSystem_US", "FIR_DDGLibertyUpgrade_F", "FIR_PilotCrewPack_US", "GTM_structures_dev", "Indecisive_Armoury_units", "JLTS_characters_CloneArmor", "JMSLLTE_Props_flags", "Jbad_ConstructionCrane", "Jbad_Misc_Breadoven", "Jbad_Misc_Fountain", "Jbad_Misc_Powerline", "Jbad_Misc_Water", "Jbad_mil", "MyAddon", "OPTRE_ACE_Compat", "OPTRE_Buildings2_Industrial", "OPTRE_Corvette", "OPTRE_FC_ACE_Compat", "OPTRE_FC_Objects", "OPTRE_FC_Objects_Props", "OPTRE_FC_Scarab", "OPTRE_FC_Vehicles_Banshee", "OPTRE_FC_Vehicles_Locust", "OPTRE_FC_Vehicles_Spectre", "OPTRE_FC_Vehicles_Spirit", "OPTRE_FC_Vehicles_T26", "OPTRE_FR_Structures_Props", "OPTRE_UNSC_Structure_Military", "OPTRE_Vehicles_Air_Falcon", "OPTRE_Vehicles_Bison", "OPTRE_Vehicles_HEV", "OPTRE_Vehicles_M700_Viper", "OPTRE_Vehicles_M808B2", "OPTRE_Vehicles_Pelican", "OPTRE_Vehicles_Pod", "OPTRE_Vehicles_Sabre", "OPTRE_Vehicles_Sparrowhawk", "OPTRE_Vehicles_Warthog", "OPTRE_Vehicles_Warthog_RC", "OPTRE_Vehicles_Wombat", "PKV5CarrierUP", "PKV5MLRSUP", "Retirement", "TCGM_Girls", "ace_ballistics", "ace_common", "ace_respawn", "cba_xeh", "dev_mutant_zombie", "ibr_dinopark", "k_ships_acclamator2", "ls_props", "ls_props_staticships", "lsb_structures_deflector", "vt4_objects_c"};
		skipWhenMissingDependencies = 1;
	};
};
class CBA_Extended_EventHandlers_base;
class CfgVehicles
{
	class APC_Wheeled_01_base_F;
	class B_APC_Tracked_01_rcws_F;
	class B_CTRG_Soldier_AR_tna_F;
	class B_CTRG_Soldier_Exp_tna_F;
	class B_CTRG_Soldier_JTAC_tna_F;
	class B_CTRG_Soldier_LAT2_tna_F;
	class B_CTRG_Soldier_LAT_tna_F;
	class B_CTRG_Soldier_M_tna_F;
	class B_CTRG_Soldier_Medic_tna_F;
	class B_CTRG_Soldier_TL_tna_F;
	class B_CTRG_Soldier_tna_F;
	class B_GEN_Commander_F;
	class B_MBT_01_cannon_F;
	class B_Pilot_F;
	class B_Plane_CAS_01_F;
	class B_RangeMaster_F;
	class B_Soldier_F;
	class B_Soldier_SL_F;
	class B_Soldier_TL_F;
	class B_Soldier_lite_F;
	class B_Survivor_F;
	class B_T_diver_F;
	class B_T_diver_TL_F;
	class B_T_diver_exp_F;
	class B_T_engineer_F;
	class B_T_medic_F;
	class B_T_officer_F;
	class B_T_soldier_AR_F;
	class B_T_soldier_M_F;
	class B_T_soldier_SL_F;
	class B_T_soldier_TL_F;
	class B_T_soldier_UAV_F;
	class B_T_soldier_exp_F;
	class B_T_soldier_repair_F;
	class B_W_engineer_F;
	class B_W_medic_F;
	class B_W_officer_F;
	class B_W_soldier_AR_F;
	class B_W_soldier_M_F;
	class B_W_soldier_SL_F;
	class B_W_soldier_TL_F;
	class B_W_soldier_UAV_F;
	class B_W_soldier_exp_F;
	class B_W_soldier_repair_F;
	class B_diver_F;
	class B_diver_TL_F;
	class B_diver_exp_F;
	class B_engineer_F;
	class B_medic_F;
	class B_officer_F;
	class B_soldier_AR_F;
	class B_soldier_M_F;
	class B_soldier_UAV_F;
	class B_soldier_exp_F;
	class B_soldier_repair_F;
	class CUP_OPX_infrastructure_base;
	class C_IDAP_Man_AidWorker_05_F;
	class C_Journalist_01_War_F;
	class C_Man_ConstructionWorker_01_Blue_F;
	class C_Man_Paramedic_01_F;
	class C_Man_casual_1_F;
	class C_Man_casual_1_F_euro;
	class C_Man_casual_5_v2_F_afro;
	class C_Man_smart_casual_2_F_tanoan;
	class C_Marshal_F;
	class C_journalist_F;
	class C_man_1_1_F;
	class C_man_p_beggar_F_euro;
	class C_man_p_fugitive_F_euro;
	class C_man_pilot_F;
	class C_man_polo_2_F_afro;
	class C_man_sport_1_F_euro;
	class C_scientist_01_formal_F;
	class C_scientist_02_formal_F;
	class C_scientist_02_informal_F;
	class DSA_AnomalyBase;
	class DSA_SpookBase;
	class DSA_SpookBase2;
	class Fire;
	class FlagCarrier;
	class FlagCarrierCore;
	class FlagCarrier_Asym;
	class GTM_structure_base;
	class Grave;
	class Helicopter_Base_F;
	class House;
	class House_F;
	class House_Small_F;
	class I_E_Uniform_01_sweater_F;
	class I_G_Soldier_LAT_F;
	class I_L_Looter_Pistol_F;
	class I_L_Looter_Rifle_F;
	class I_L_Looter_SG_F;
	class I_L_Looter_SMG_F;
	class I_Soldier_02_F;
	class I_Soldier_AA_F;
	class I_Soldier_AR_F;
	class I_Soldier_A_F;
	class I_Soldier_SL_F;
	class I_Soldier_exp_F;
	class I_Soldier_lite_F;
	class I_Soldier_repair_F;
	class I_diver_F;
	class I_diver_TL_F;
	class I_diver_exp_F;
	class I_medic_F;
	class I_soldier_F;
	class Items_base_F;
	class Jbad_Kasna_base;
	class Jbad_Water_base_2;
	class Lamps_base_F;
	class Land_3AS_Generator_Shield_Small;
	class Land_AncientStatue_01_F;
	class Land_AncientStatue_02_F;
	class Land_Barrack2;
	class Land_Campfire;
	class Land_CampingChair_V1_F;
	class Land_Destroyer_01_hull_base_F;
	class Land_Fire;
	class Land_Fire_barrel;
	class Land_HelipadEmpty_F;
	class Land_Jbad_PowLines_Conc2L;
	class Land_PowLines_ConcL;
	class Land_Statue_01_F;
	class Land_Statue_02_F;
	class Land_TentDome_F;
	class Metal_Pole_F;
	class Motorcycle;
	class NonStrategic;
	class OPTRE_FC_Hull_AA;
	class OPTRE_FC_Hull_Cmdr;
	class OPTRE_FC_Hull_Cmdr_AA;
	class OPTRE_FC_Scarab_Hull_AT;
	class OPTRE_FC_extras_base;
	class OPTRE_M12_FAV;
	class OPTRE_M808B2;
	class OPTRE_Pelican_armed;
	class O_T_diver_F;
	class O_T_diver_TL_F;
	class O_T_diver_exp_F;
	class O_V_Soldier_Exp_ghex_F;
	class O_V_Soldier_Exp_hex_F;
	class O_V_Soldier_Medic_ghex_F;
	class O_V_Soldier_Medic_hex_F;
	class O_V_Soldier_TL_ghex_F;
	class O_V_Soldier_TL_hex_F;
	class O_V_Soldier_ghex_F;
	class O_V_Soldier_hex_F;
	class O_V_Soldier_jtac_ghex_F;
	class O_V_Soldier_jtac_hex_F;
	class O_V_Soldier_lat_ghex_F;
	class O_V_Soldier_lat_hex_F;
	class O_V_Soldier_m_ghex_F;
	class O_V_Soldier_m_hex_F;
	class O_diver_F;
	class O_diver_TL_F;
	class O_diver_exp_F;
	class PlaneWreck;
	class Plane_Base_F;
	class Plane_Fighter_03_base_F;
	class Poster_base_F;
	class PowerLines_Small_base_F;
	class Radar_System_01_base_F;
	class RuggedTerminal_Base_F;
	class Sign_F;
	class StaticMGWeapon;
	class StaticShip;
	class TCGM_f_Swimsuit_Maya_civil;
	class Tank_F;
	class TargetBase;
	class TargetBootcampHumanSimple_F;
	class Thing;
	class Underwear_F;
	class Wall_F;
	class Wreck;
	class Wreck_base_F;
	class b_soldier_survival_F;
	class land_3AS_ShieldGenerator;
	class ls_staticShip_base;
	class lsb_deflector_base;
	class thingX;
	class 101st_Warden_Tank: B_APC_Tracked_01_rcws_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 3AS_CIS_Hangar: StaticShip
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 3AS_Flag_CIS: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 3AS_Flag_GAR: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 3AS_Flag_Imp: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 3AS_Flag_Jedi: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 3AS_Flag_Man: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 3AS_Flag_Pir: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 3AS_Flag_Reb: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 3AS_Flag_Sith: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 3AS_Jukebox: thingX
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 3AS_Octuptarra_Base_F: APC_Wheeled_01_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 3as_City_Tower_5_Prop: StaticShip
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 442_coreship: House_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 442_first_shot: Items_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 442_hardcell_base: StaticShip
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 442_lucrehulk_base: StaticShip
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 442_mandator_base: StaticShip
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 442_providence: House_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 442_providence_d: House_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 442_quasar_shield: House_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 442_recusant_base: StaticShip
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 442_subjugator_base: StaticShip
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class 442_venator_base: StaticShip
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class ACE_Flag_Black: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class ACE_Flag_White: ACE_Flag_Black
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class ACE_LogicDummy: Land_HelipadEmpty_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class ACE_TargetWall: Sign_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class AMT_EscapePod_Base: Plane_Base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class B_Patrol_Respawn_tent_F: Land_TentDome_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Barrack2: Land_Barrack2
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class CUP_OPX_building_base: House_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class CUP_terrains_structures_e_building_base: House_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class CargoPlatform_01_base_F: House_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DBA_Flag_Black: ACE_Flag_Black
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DBA_Flag_CIS: ACE_Flag_Black
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DBA_Flag_CISAlt: ACE_Flag_Black
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DBA_Flag_CISRem: ACE_Flag_Black
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DBA_Flag_Formal: ACE_Flag_Black
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DBA_Flag_Green: ACE_Flag_Black
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DBA_Flag_Jerec: ACE_Flag_Black
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DBA_Flag_Logo: ACE_Flag_Black
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DBA_Flag_Republic: ACE_Flag_Black
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DBA_Flag_Republic_Blue: ACE_Flag_Black
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_US_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DBA_Flag_Seatie: Flag_US_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DBA_Flag_Senate: ACE_Flag_Black
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DBA_Flag_Senate_Red: ACE_Flag_Black
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DBA_Flag_White: ACE_Flag_Black
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DBA_TDP: Plane_Base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_411: DSA_SpookBase
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_Abomination: DSA_411
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_ActiveIdol: DSA_SpookBase
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_ActiveIdol2: DSA_ActiveIdol
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_Crazy: DSA_SpookBase2
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_DeltaX_CBRN: B_Soldier_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_DeltaX_Operator: B_Soldier_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_Shadowman: DSA_SpookBase
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_Hatman: DSA_Shadowman
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_Idol: Land_AncientStatue_01_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_Idol2: Land_AncientStatue_02_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_Launchpad: DSA_AnomalyBase
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_Leech: DSA_AnomalyBase
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_Mindflayer: DSA_SpookBase2
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_Rake: DSA_SpookBase
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_Snatcher: DSA_SpookBase
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_Statue: Land_Statue_01_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_Statue2: Land_Statue_02_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_Trapdoor: DSA_AnomalyBase
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_Vampire: DSA_SpookBase2
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_Wendigo: DSA_SpookBase
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class DSA_Zapper: DSA_AnomalyBase
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Droideka_wreck: Wreck
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FIR_ASM_Base: Plane_Fighter_03_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FIR_Aegis_Radar_Base: Radar_System_01_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FIR_Civ_Pilot: C_man_pilot_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FIR_ECM_Dummy_Base: Plane_Fighter_03_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FIR_USAF_Pilot: B_Pilot_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FireLit: Fire
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierArmex_EP1: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierBAF: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierUNO_EP1: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierBIS_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierBLUFOR_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierUSA: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierCDF: FlagCarrierUSA
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierCDFEnsign_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierCDF_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierChecked: FlagCarrierCore
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierCzechRepublic_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierGUE: FlagCarrierUSA
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierGermany_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierINDFOR_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierINS: FlagCarrierUSA
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierNATO_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierWest: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierSouth: FlagCarrierWest
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierNorth: FlagCarrierSouth
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierOPFOR_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierPOWMIA_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierRU: FlagCarrierUSA
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierRedCrescent_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierRedCross_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierRedCrystal_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierTFKnight_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierTKMilitia_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierTakistanKingdom_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierTakistan_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierUSA_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierUSArmy_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagCarrierWhite_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FlagChecked_F: FlagCarrierCore
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_AAF_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_ARMEX_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_AltisColonial_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Altis_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_BI_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Blue_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Blueking_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Blueking_inverted_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Burstkoke_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Burstkoke_inverted_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_CSAT_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_CTRG_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_EAF_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Enoch_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_FD_Blue_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_FD_Green_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_FD_Orange_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_FD_Purple_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_FD_Red_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_FIA_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Fuel_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Fuel_inverted_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Gendarmerie_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Green_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_HorizonIslands_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_IDAP_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_ION_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Vrana_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_JMSLLTE_Emp_black_F: Flag_Vrana_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_JMSLLTE_Emp_red_F: Flag_Vrana_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_JMSLLTE_NR_white_F: Flag_Vrana_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_JMSLLTE_NRc_white_F: Flag_Vrana_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_JMSLLTE_Reb_white_F: Flag_Vrana_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Larkin_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_NATO_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_POWMIA_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Quontrol_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_RedCrystal_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Red_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Redburger_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Redstone_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Suatmm_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Syndikat_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_UK_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_UNO_F: FlagCarrier_Asym
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_Viper_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Flag_White_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class GC_FT_Knight_base: B_MBT_01_cannon_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class GTM_structure_testHallway_base: GTM_structure_base
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class GalleryDioramaBase_01_base_F: NonStrategic
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class GalleryInterior_01_Base_F: House
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Hogosha_D77HTCI_A: OPTRE_Pelican_armed
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class IDA_Clone_Undersuit: Underwear_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class JLTS_Clone_Naked: Underwear_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Jbad_CraneCon: Tank_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Jbad_Lamps_base_powerline: PowerLines_Small_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_3AS_Generator_Shield_Large: land_3AS_ShieldGenerator
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_3AS_Generator_Shield_Small_Projector: Land_3AS_Generator_Shield_Small
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_3AS_Lava_Tile_5x5: House_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_CUP_OPX_Powerpole_Small: CUP_OPX_infrastructure_base
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_Campfire_burning: Land_Campfire
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_Carrier_01_base_F: StaticShip
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_Destroyer_01_base_F: StaticShip
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_Destroyer_01_hull_02_F: Land_Destroyer_01_hull_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_Fire_barrel_burning: Land_Fire_barrel
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_Fire_burning: Land_Fire
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_Jbad_Kasna_new: Jbad_Kasna_base
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_Jbad_Mil_Repair_center: House_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_Jbad_Pole_1: Jbad_Lamps_base_powerline
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_Jbad_Pole_Speaker: Land_Jbad_PowLines_Conc2L
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_Jbad_Pole_withlight: Land_Jbad_PowLines_Conc2L
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_Jbad_PowLineB: Jbad_Lamps_base_powerline
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_Jbad_WaterFall: Jbad_Water_base_2
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_Jbad_breadoven_base: House_Small_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_OPTRE_barrel_hydrogen: Items_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_OPTRE_fusion_coil: Items_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_Poster_04_F: Poster_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_PowLines_WoodL: Land_PowLines_ConcL
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_Puinen_katu_lamppu: Lamps_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_Target_Dueling_01_F: TargetBase
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Land_Target_Oval_F: TargetBase
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Mass_grave: Grave
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Metal_Pole_Skeet_F: Metal_Pole_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_EscapePod_Base: Plane_Base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_Wraith: B_MBT_01_cannon_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_AA_Wraith: OPTRE_FC_Wraith
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_AA_Wraith_NOFLAK: OPTRE_FC_AA_Wraith
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_AA_Wraith_Needle: OPTRE_FC_Wraith
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_Frnt_Thigh: OPTRE_FC_extras_base
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_Hull_AA_NoEH: OPTRE_FC_Hull_AA
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_Hull_Cmdr_AA_NoEH: OPTRE_FC_Hull_Cmdr_AA
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_Hull_Cmdr_NoEH: OPTRE_FC_Hull_Cmdr
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_Locust: B_MBT_01_cannon_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_Particle_Base: Thing
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_SAM_Wraith_Needle: OPTRE_FC_Wraith
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_Scarab_Hull_AT_NoEH: OPTRE_FC_Scarab_Hull_AT
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_Scarab_Hull_Base: B_MBT_01_cannon_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_Scarab_Hull_Base_NoEH: OPTRE_FC_Scarab_Hull_Base
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_Spectre_Base: B_MBT_01_cannon_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_Spirit_F: Helicopter_Base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_Type26B_Banshee: B_Plane_CAS_01_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_Type26N_Banshee: OPTRE_FC_Type26B_Banshee
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_Type27_Banshee: OPTRE_FC_Type26N_Banshee
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FC_Wraith_Tank: OPTRE_FC_Wraith
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_FR_FusionCoil: Items_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_HEV: StaticMGWeapon
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_M12_CIV: OPTRE_M12_FAV
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_M808B2A1: OPTRE_M808B2
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_Objects_Wreck_Bison: Wreck_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_Objects_Wreck_Falcon: PlaneWreck
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_Objects_Wreck_Pelican: PlaneWreck
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_Objects_Wreck_Sparrowhawk: PlaneWreck
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_Objects_Wreck_m700: Wreck_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_RCHog: OPTRE_M12_CIV
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_Sabre_Wreck_F: PlaneWreck
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class OPTRE_UNSC_Drake: House_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class PK_V5_ATGM_Carrier_UP: Tank_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class PK_V5_MLRS_Carrier_UP: Tank_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class RuggedTerminal_01_F: RuggedTerminal_Base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class RuggedTerminal_01_communications_F: RuggedTerminal_Base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class RuggedTerminal_01_communications_hub_F: RuggedTerminal_Base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class RuggedTerminal_02_communications_F: RuggedTerminal_Base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class SJU7_Ejection_Seat: Motorcycle
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class SZ_Chair: Land_CampingChair_V1_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class SZ_Sofa: Land_CampingChair_V1_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class SZ_stool: Land_CampingChair_V1_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class ShipFlag_US_F: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Bra_B_MTP_Soldier_SL: B_Soldier_SL_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Bra_B_MTP_soldier_TL: B_Soldier_TL_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Bra_B_TNA_Soldier_SL: B_T_soldier_SL_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Bra_B_TNA_soldier_TL: B_T_soldier_TL_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Bra_B_WDL_Soldier_SL: B_W_soldier_SL_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Bra_B_WDL_soldier_TL: B_W_soldier_TL_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Bra_I_M81_Looter_Pistol: I_L_Looter_Pistol_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Bra_I_M81_Looter_Rifle: I_L_Looter_Rifle_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Bra_I_M81_Looter_Shotgun: I_L_Looter_SG_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Bra_I_Sage_Looter_SMG: I_L_Looter_SMG_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_B_Mini_Range: B_RangeMaster_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_C_Mini_IDAP: C_IDAP_Man_AidWorker_05_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_C_Mini_Journalist: C_journalist_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_C_Mini_JournalistWar: C_Journalist_01_War_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_C_Mini_Marshal: C_Marshal_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_C_Mini_Navy: C_Man_casual_1_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_C_Sport_1: C_man_1_1_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_DiverShort_B: B_diver_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_DiverShort_B_T: B_T_diver_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_DiverShort_I: I_diver_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_DiverShort_O: O_diver_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_DiverShort_O_T: O_T_diver_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Diver_B: B_diver_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Diver_B_Exp: B_diver_exp_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Diver_B_T: B_T_diver_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Diver_B_TL: B_diver_TL_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Diver_B_T_Exp: B_T_diver_exp_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Diver_B_T_TL: B_T_diver_TL_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Diver_Blu_C: TCGM_f_Swimsuit_Maya_civil
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Diver_I: I_diver_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Diver_I_Exp: I_diver_exp_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Diver_I_TL: I_diver_TL_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Diver_O: O_diver_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Diver_O_Exp: O_diver_exp_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Diver_O_T: O_T_diver_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Diver_O_TL: O_diver_TL_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Diver_O_T_Exp: O_T_diver_exp_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Diver_O_T_TL: O_T_diver_TL_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Paramedic_C: C_Man_Paramedic_01_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Soldier02_I: I_soldier_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Soldier02_RollUp_AA_I: I_Soldier_AA_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Soldier02_RollUp_AR_I: I_Soldier_AR_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Soldier02_RollUp_A_I: I_Soldier_A_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Soldier02_RollUp_I: I_Soldier_02_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Soldier02_RollUp_SL_I: I_Soldier_SL_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Soldier02_RollUp_exp_I: I_Soldier_exp_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Soldier02_RollUp_lite_I: I_Soldier_lite_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Soldier02_RollUp_medic_I: I_medic_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Soldier02_RollUp_repair_I: I_Soldier_repair_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Soldier1_LAT_I: I_G_Soldier_LAT_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Soldier2_I: I_E_Uniform_01_sweater_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_F_Soldier_GEN_B: B_GEN_Commander_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_MTP_Medic: B_medic_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_MTP_Soldier_AR: B_soldier_AR_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_MTP_Soldier_LT: B_Soldier_lite_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_MTP_Soldier_M: B_soldier_M_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_MTP_engineer: B_engineer_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_MTP_officer: B_officer_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_MTP_soldier_UAV: B_soldier_UAV_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_MTP_soldier_exp: B_soldier_exp_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_MTP_soldier_repair: B_soldier_repair_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_TNA_Medic: B_T_medic_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_TNA_Soldier_AR: B_T_soldier_AR_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_TNA_Soldier_M: B_T_soldier_M_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_TNA_engineer: B_T_engineer_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_TNA_officer: B_T_officer_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_TNA_soldier_UAV: B_T_soldier_UAV_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_TNA_soldier_exp: B_T_soldier_exp_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_TNA_soldier_repair: B_T_soldier_repair_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_WDL_Medic: B_W_medic_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_WDL_Soldier_AR: B_W_soldier_AR_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_WDL_Soldier_M: B_W_soldier_M_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_WDL_engineer: B_W_engineer_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_WDL_officer: B_W_officer_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_WDL_soldier_UAV: B_W_soldier_UAV_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_WDL_soldier_exp: B_W_soldier_exp_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_RollUp_B_WDL_soldier_repair: B_W_soldier_repair_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Stealth_B_CTRG_Soldier_AR: B_CTRG_Soldier_AR_tna_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Stealth_B_CTRG_Soldier_Exp: B_CTRG_Soldier_Exp_tna_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Stealth_B_CTRG_Soldier_JTAC: B_CTRG_Soldier_JTAC_tna_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Stealth_B_CTRG_Soldier_LAT: B_CTRG_Soldier_LAT_tna_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Stealth_B_CTRG_Soldier_LAT2: B_CTRG_Soldier_LAT2_tna_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Stealth_B_CTRG_Soldier_M: B_CTRG_Soldier_M_tna_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Stealth_B_CTRG_Soldier_Medic: B_CTRG_Soldier_Medic_tna_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Stealth_B_CTRG_Soldier_SC: B_CTRG_Soldier_tna_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Stealth_B_CTRG_Soldier_TL: B_CTRG_Soldier_TL_tna_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Survival_Bra_B_MTP_Soldier: b_soldier_survival_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_AHex_Soldier: O_V_Soldier_hex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_Exp_GHex_Soldier: O_V_Soldier_Exp_ghex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_Exp_Hex_Soldier: O_V_Soldier_Exp_hex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_Exp_UHex_Soldier: O_V_Soldier_Exp_hex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_GHex_Soldier: O_V_Soldier_ghex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_Medic_GHex_Soldier: O_V_Soldier_Medic_ghex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_Medic_Hex_Soldier: O_V_Soldier_Medic_hex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_Medic_UHex_Soldier: O_V_Soldier_Medic_hex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_TL_GHex_Soldier: O_V_Soldier_TL_ghex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_TL_Hex_Soldier: O_V_Soldier_TL_hex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_TL_UHex_Soldier: O_V_Soldier_TL_hex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_UHex_Soldier: O_V_Soldier_hex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_jtac_GHex_Soldier: O_V_Soldier_jtac_ghex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_jtac_Hex_Soldier: O_V_Soldier_jtac_hex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_jtac_UHex_Soldier: O_V_Soldier_jtac_hex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_lat_GHex_Soldier: O_V_Soldier_lat_ghex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_lat_Hex_Soldier: O_V_Soldier_lat_hex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_lat_UHex_Soldier: O_V_Soldier_lat_hex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_m_GHex_Soldier: O_V_Soldier_m_ghex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_m_Hex_Soldier: O_V_Soldier_m_hex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_Viper_O_m_UHex_Soldier: O_V_Soldier_m_hex_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_f_PantiesBlack_soldier: C_Man_casual_1_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TCGM_f_underwear_soldier: B_Survivor_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TargetBootcampHuman_F: TargetBootcampHumanSimple_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TargetP_Inf_F: TargetBase
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TargetBootcamp_base_F: TargetP_Inf_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TargetEpopup: TargetBase
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class TargetPopUpTarget: TargetBase
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class Target_Swivel_01_base_F: NonStrategic
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class aces_ejection_seat: Motorcycle
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class bench_1: Land_CampingChair_V1_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class bench_2: Land_CampingChair_V1_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class bench_2B: Land_CampingChair_V1_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_b_zombie_ConstructionWorker_01_Blue_F: C_Man_ConstructionWorker_01_Blue_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_b_zombie_Journalist_01_War_F: C_Journalist_01_War_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_b_zombie_casual_5_v2_F_afro: C_Man_casual_5_v2_F_afro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_b_zombie_casual_i: C_Man_casual_1_F_euro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_b_zombie_engineer_i: B_engineer_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_b_zombie_p_beggar_F_euro: C_man_p_beggar_F_euro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_b_zombie_p_fugitive_F_euro: C_man_p_fugitive_F_euro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_b_zombie_polo_2_F_afro: C_man_polo_2_F_afro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_b_zombie_scientist2_i: C_scientist_02_formal_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_b_zombie_scientist3_i: C_scientist_02_informal_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_b_zombie_scientist_i: C_scientist_01_formal_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_b_zombie_smart_casual_2_F_tanoan: C_Man_smart_casual_2_F_tanoan
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_b_zombie_sport_1_F_euro: C_man_sport_1_F_euro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_c_zombie_ConstructionWorker_01_Blue_F: C_Man_ConstructionWorker_01_Blue_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_c_zombie_Journalist_01_War_F: C_Journalist_01_War_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_c_zombie_casual_5_v2_F_afro: C_Man_casual_5_v2_F_afro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_c_zombie_casual_i: C_Man_casual_1_F_euro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_c_zombie_engineer_i: B_engineer_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_c_zombie_p_beggar_F_euro: C_man_p_beggar_F_euro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_c_zombie_p_fugitive_F_euro: C_man_p_fugitive_F_euro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_c_zombie_polo_2_F_afro: C_man_polo_2_F_afro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_c_zombie_scientist2_i: C_scientist_02_formal_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_c_zombie_scientist3_i: C_scientist_02_informal_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_c_zombie_scientist_i: C_scientist_01_formal_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_c_zombie_smart_casual_2_F_tanoan: C_Man_smart_casual_2_F_tanoan
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_c_zombie_sport_1_F_euro: C_man_sport_1_F_euro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_i_zombie_ConstructionWorker_01_Blue_F: C_Man_ConstructionWorker_01_Blue_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_i_zombie_Journalist_01_War_F: C_Journalist_01_War_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_i_zombie_casual_5_v2_F_afro: C_Man_casual_5_v2_F_afro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_i_zombie_casual_i: C_Man_casual_1_F_euro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_i_zombie_engineer_i: B_engineer_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_i_zombie_p_beggar_F_euro: C_man_p_beggar_F_euro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_i_zombie_p_fugitive_F_euro: C_man_p_fugitive_F_euro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_i_zombie_polo_2_F_afro: C_man_polo_2_F_afro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_i_zombie_scientist2_i: C_scientist_02_formal_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_i_zombie_scientist3_i: C_scientist_02_informal_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_i_zombie_scientist_i: C_scientist_01_formal_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_i_zombie_smart_casual_2_F_tanoan: C_Man_smart_casual_2_F_tanoan
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_i_zombie_sport_1_F_euro: C_man_sport_1_F_euro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_o_zombie_ConstructionWorker_01_Blue_F: C_Man_ConstructionWorker_01_Blue_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_o_zombie_Journalist_01_War_F: C_Journalist_01_War_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_o_zombie_casual_5_v2_F_afro: C_Man_casual_5_v2_F_afro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_o_zombie_casual_i: C_Man_casual_1_F_euro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_o_zombie_engineer_i: B_engineer_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_o_zombie_p_beggar_F_euro: C_man_p_beggar_F_euro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_o_zombie_p_fugitive_F_euro: C_man_p_fugitive_F_euro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_o_zombie_polo_2_F_afro: C_man_polo_2_F_afro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_o_zombie_scientist2_i: C_scientist_02_formal_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_o_zombie_scientist3_i: C_scientist_02_informal_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_o_zombie_scientist_i: C_scientist_01_formal_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_o_zombie_smart_casual_2_F_tanoan: C_Man_smart_casual_2_F_tanoan
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class dev_o_zombie_sport_1_F_euro: C_man_sport_1_F_euro
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class k_acclamator2_full: House_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class k_personal_locker: House_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class land_OPTRE_FC_Methane_Station: House_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class land_Pipe_Cap: House_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class land_ibr_zoogate: Wall_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class ls_flag_base: FlagCarrier
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class ls_staticShip_multiPart_base: ls_staticShip_base
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class lsb_deflectorDestructible_base: lsb_deflector_base
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class unscdrone_wreck_F: PlaneWreck
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
};
