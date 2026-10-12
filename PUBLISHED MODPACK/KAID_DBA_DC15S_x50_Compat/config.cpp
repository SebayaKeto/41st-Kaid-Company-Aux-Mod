// KAID_DBA_DC15S_x50_Compat (optional): DBA Republic's clone units (B_DBA_P2Clone_Base, B_DBA_GMClone_Base,
// B_DBA_Republic_Commando_Base_F, ...), ammo box and IFVs load "DBA_68x51_FMJ_x50_mag", which DBA never defines
// ("No entry ...CfgMagazines.DBA_68x51_FMJ_x50_mag" warning; the units spawn without those 5 mags).
// Those units carry DBA_DC15S_base (6.5x39, 50 rounds), so this adds the missing class as a real 50-round DC-15S magazine
// (inherits DBA_65x39_FMJ_x50_mag: same ammo, count 50) and lets every DBA DC-15S variant load it.
// Additions only: 1 new magazine; the weapons keep their existing magazines and get the new one appended.
// DBA is not edited; the addon is skipped when the DBA weapon patches are not loaded.
class CfgPatches
{
	class KAID_DBA_DC15S_x50_Compat
	{
		units[]={};
		weapons[]={};
		magazines[]={"DBA_68x51_FMJ_x50_mag"};
		requiredVersion=0.1;
		requiredAddons[]={"A3_Weapons_F","DBA_DC15A","DBA_Aux_Mod_DC15C","DBA_Aux_Mod_DC15SSHD"};
		skipWhenMissingDependencies=1;
	};
};
class CfgMagazines
{
	class DBA_65x39_FMJ_x50_mag;
	class DBA_68x51_FMJ_x50_mag: DBA_65x39_FMJ_x50_mag
	{
		scope=2;
		displayName="6.5x39mw DC-15S Mag (50 Rnd)";
		displayNameShort="50 Rnd";
		descriptionShort="50 Rnd DC-15S magazine";
		count=50;
	};
};
class CfgWeapons
{
	class JLTS_DC15S;
	class Pistol_Base_F;
	class DBA_DC15S_base: JLTS_DC15S
	{
		magazines[]={"DBA_65x39_FMJ_x50_mag","DBA_StunRound_Mag","DBA_68x51_FMJ_x50_mag"};
	};
	class DBA_DC15sGL: DBA_DC15S_base
	{
		magazines[]={"DBA_65x39_FMJ_x50_mag","DBA_StunRound_Mag","DBA_68x51_FMJ_x50_mag"};
	};
	class DBA_DC15S_Secondary_Base: Pistol_Base_F
	{
		magazines[]={"DBA_65x39_FMJ_x50_mag","DBA_StunRound_Mag","DBA_68x51_FMJ_x50_mag"};
	};
	class DBA_TC15S: JLTS_DC15S
	{
		magazines[]={"DBA_65x39_FMJ_x50_mag","DBA_68x51_FMJ_x50_mag"};
	};
	class DBA_DC15SSHD: Pistol_Base_F
	{
		magazines[]={"DBA_65x39_FMJ_x50_mag","DBA_StunRound_Mag","DBA_68x51_FMJ_x50_mag"};
	};
};
