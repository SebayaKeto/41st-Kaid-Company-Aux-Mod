// KAID_ConfigShim: gives the empty root CfgVehicles stubs left by third-party (DBA, AMT, Kobra, IDA) and stray
// forward declarations a defined body, so the config-load "No entry ... CfgVehicles/<name>.scope" warning storm
// (and its modal on clients) stops. Nothing is renamed or removed; real definitions from later/earlier addons merge over these.
class CfgPatches
{
	class KAID_ConfigShim
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"A3_Data_F","A3_Weapons_F","A3_Weapons_F_Tank"};
	};
};
class CfgVehicles
{
	class All;
	class CargoTurret_01: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class Components: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class CopilotTurret: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class HitPoints: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class ItemInfo: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class MFD: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class MainTurret: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class NewTurret: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class SimpleObject: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class Static_F: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class SupplyDC15X: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class SupplyE11D: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class Turrets: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class Venator_MK2: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class WBK_B2_Mod_Standart: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class WBK_BX_Assasin_1: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class k_clone_unit_104thWolfpack_Dirty: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class k_clone_unit_104th_Dirty: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class k_clone_unit_13th_Dirty: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class k_clone_unit_187th_Dirty: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class k_clone_unit_212th_Dirty: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class k_clone_unit_327th_Dirty: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class k_clone_unit_332nd_Dirty: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class k_clone_unit_41stGC_Dirty: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class k_clone_unit_442nd_Dirty: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class k_clone_unit_501st_Dirty: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class k_clone_unit_5th_Dirty: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class k_clone_unit_CG_Dirty: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class k_clone_unit_KS_Dirty: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class kat_AEDItem: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class kat_X_AEDItem: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
	class ls_redforDroid_base: All
	{
		scope=0;
		scopeCurator=0;
		scopeArsenal=0;
	};
};
class CfgWeapons
{
	class Default;
	class ItemInfo: Default
	{
		scope=1;
	};
	class WeaponSlotsInfo: Default
	{
		scope=1;
	};
};
class CfgAmmo
{
	class MissileBase;
	class R_MRAAWS_HEAT_F;
	class PLX_Javelin: MissileBase
	{
		scope=0;
	};
	class MRAWS_HEAT_F: R_MRAAWS_HEAT_F
	{
		scope=0;
	};
};
