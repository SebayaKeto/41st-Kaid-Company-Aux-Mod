// KAID_XEH_Compat_41st: adds CBA Extended Event Handler support to 90 unit/static classes whose own
// "class EventHandlers {...}" has no CBA_Extended_EventHandlers subclass. Without it CBA logs
// "Fall back to loop" and polls every unit on every machine. Generated from an engine probe
// (D:/AuxUpdater/xehcompat); each class keeps its exact parent, so no base class changes.
class CfgPatches
{
	class KAID_XEH_Compat_41st
	{
		name = "KAID XEH compat (41st)";
		author = "41st Aux Updater";
		units[] = {};
		weapons[] = {};
		requiredVersion = 2.0;
		requiredAddons[] = {"41st_Civilians", "41st_CorruptPDF", "41st_Droids", "41st_HumanDiv", "41st_Mandos", "53rd_CoagField", "BUZZ_ATRT", "FST_ADSD", "FST_Daara_venator", "FST_HCSpawn", "FST_HMP", "FST_Hailfire", "FST_MEC_ZeusModules_Patch", "FST_PKV5MLRSUP", "FST_Static_DF9", "FST_venator", "KAID_Disable_53rd_CoagField", "cba_xeh"};
		skipWhenMissingDependencies = 1;
	};
};
class CBA_Extended_EventHandlers_base;
class CfgVehicles
{
	class 3AS_AAT_base_F;
	class 3AS_Small_Box_9_Black_Prop;
	class 3AS_Supply_Large_Orange_Prop;
	class C_man_1;
	class FST_ATRT;
	class FST_DF9_Base;
	class FST_Droid_B1_E5;
	class FST_EmpOfficer_black_Base;
	class FST_Hailfire_Base;
	class FST_U_CIS_Light;
	class FST_U_CIS_Prisoner;
	class FST_U_CorruptPDF;
	class FST_U_CorruptPDFCold;
	class FST_U_CorruptPDFPilot;
	class FST_U_CorruptPDFTanker;
	class FST_U_MandoUndersuit;
	class Heli_Attack_01_base_F;
	class Module_F;
	class NonStrategic;
	class StaticShip;
	class Tank_F;
	class ace_csw_baseTripod;
	class BUZZ_ATRT: FST_ATRT
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class BUZZ_ATRT_ReserveCrate: 3AS_Supply_Large_Orange_Prop
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class BUZZ_ATRT_TransportCrate: 3AS_Small_Box_9_Black_Prop
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_ATM: NonStrategic
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_Advanced_DSD_Base: 3AS_AAT_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CIS_Clone_Prisoner: FST_U_CIS_Prisoner
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CIS_Heavy_Base_F: FST_Droid_B1_E5
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CIS_HumanDiv_AA: FST_CIS_Heavy_Base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CIS_HumanDiv_AT: FST_CIS_Heavy_Base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CIS_HumanDiv_AmmoB: FST_U_CIS_Light
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CIS_HumanDiv_Auto: FST_CIS_Heavy_Base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CIS_HumanDiv_CQC: FST_U_CIS_Light
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CIS_HumanDiv_DroneOp: FST_U_CIS_Light
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CIS_HumanDiv_EOD: FST_U_CIS_Light
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CIS_HumanDiv_Gren: FST_U_CIS_Light
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CIS_HumanDiv_Mark: FST_U_CIS_Light
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CIS_HumanDiv_Medic: FST_U_CIS_Light
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CIS_HumanDiv_Officer: FST_U_CIS_Light
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CIS_HumanDiv_RTO: FST_U_CIS_Light
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CIS_HumanDiv_Standard: FST_U_CIS_Light
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CIS_Prisoner: FST_U_CIS_Prisoner
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_Civilian_Basic: C_man_1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_Civilian_Poor: C_man_1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_Civilian_Spacer: C_man_1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_Civilian_Wealthy: C_man_1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDFCold_AA: FST_U_CorruptPDFCold
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDFCold_AT: FST_U_CorruptPDFCold
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDFCold_Auto: FST_U_CorruptPDFCold
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDFCold_CQB: FST_U_CorruptPDFCold
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDFCold_Commander: FST_U_CorruptPDFCold
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDFCold_Gren: FST_U_CorruptPDFCold
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDFCold_Mark: FST_U_CorruptPDFCold
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDFCold_Medic: FST_U_CorruptPDFCold
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDFCold_RTO: FST_U_CorruptPDFCold
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDFCold_Standard: FST_U_CorruptPDFCold
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDF_AA: FST_U_CorruptPDF
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDF_AT: FST_U_CorruptPDF
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDF_Auto: FST_U_CorruptPDF
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDF_CQB: FST_U_CorruptPDF
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDF_Commander: FST_U_CorruptPDF
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDF_Gren: FST_U_CorruptPDF
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDF_Mark: FST_U_CorruptPDF
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDF_Medic: FST_U_CorruptPDF
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDF_Pilot: FST_U_CorruptPDFPilot
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDF_RTO: FST_U_CorruptPDF
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDF_Standard: FST_U_CorruptPDF
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_CorruptPDF_Tanker: FST_U_CorruptPDFTanker
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_DF9_Rocket: FST_DF9_Base
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_Daara_venator_base: StaticShip
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_HC_ModuleBase: Module_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_HMP_Base: Heli_Attack_01_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_Hailfire_Rocket: FST_Hailfire_Base
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_HumanDiv_BComm: FST_EmpOfficer_black_Base
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_HumanDiv_BStaff: FST_EmpOfficer_black_Base
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_HumanDiv_NCaptain: FST_EmpOfficer_black_Base
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_HumanDiv_NEngi: FST_EmpOfficer_black_Base
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_HumanDiv_NOfficer: FST_EmpOfficer_black_Base
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_HumanDiv_NPerson: FST_EmpOfficer_black_Base
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_IDB: NonStrategic
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_Jorgetrooper: FST_CIS_Heavy_Base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_Jorgetrooper_AR: FST_Jorgetrooper
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_Jorgetrooper_AT: FST_Jorgetrooper
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoO_AA: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoO_AT: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoO_Auto: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoO_CQB: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoO_Commander: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoO_EOD: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoV_Commander: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoO_Flame: FST_MandoV_Commander
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoO_Grenadier: FST_MandoV_Commander
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoO_Marksman: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoO_RTO: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoO_Sniper: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoO_Standard: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoV_AA: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoV_AT: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoV_Auto: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoV_CQB: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoV_EOD: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoV_Flame: FST_MandoV_Commander
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoV_Grenadier: FST_MandoV_Commander
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoV_Marksman: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoV_RTO: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoV_Sniper: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_MandoV_Standard: FST_U_MandoUndersuit
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_PK_V5_MLRS_Carrier_UP: Tank_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class FST_venator_base: StaticShip
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class MEC_Power_Module: Module_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
	class StasisFieldStructure: ace_csw_baseTripod
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};
};
