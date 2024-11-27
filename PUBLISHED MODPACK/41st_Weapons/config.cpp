class CfgPatches
{
	class FST_Weapons
	{
		author="Daara";
		requiredAddons[]=
		{
			"A3_data_F",
			"A3_anims_F",
			"A3_weapons_F",
			"A3_characters_F",
			"A3_Characters_F_Proxies"
		};
		units[]={};
		weapons[]=
		{
		};
		magazines[]=
		{
		};
	};
};
class CfgRecoils
{
	class recoil_default;
	class FST_recoil_DC15A: recoil_default
	{
		muzzleOuter[]={0,0.34999999,0.2,0.050000001};
		kickBack[]={0.039999999,0.059999999};
		temporary=0.0080000004;
	};
	class FST_recoil_DC15S: recoil_default
	{
		muzzleOuter[]={0,0.30000001,0.25,0.075000003};
		kickBack[]={0.029999999,0.039999999};
		temporary=0.0080000004;
	};
	class FST_recoil_DC15S_dumb: recoil_default
	{
		muzzleOuter[]={0,0,0,0};
		kickBack[]={0.039999999,0.059999999};
		temporary=0.0080000004;
	};
	class FST_recoil_DC15SA: recoil_default
	{
		muzzleOuter[]={0,6,0.1,0.1};
		kickBack[]={0.039999999,0.039999999};
		permanent=0;
		temporary=0.0099999998;
	};
	class FST_recoil_DC15X: recoil_default
	{
		muzzleOuter[]={0,3,0.2,0.2};
		kickBack[]={0.059999999,0.059999999};
		permanent=0;
		temporary=0.0049999999;
	};
	class FST_recoil_DC17: recoil_default
	{
		muzzleOuter[]={0,0.35,0.2,0.075000003};
		kickBack[]={0.02,0.035};
		permanent=0;
		temporary=0.03;
	};
	class FST_recoil_DC17M: recoil_default
	{
		muzzleOuter[]=
		{
			0,
			"0.6.2",
			0.30000001,
			0.30000001
		};
		kickBack[]={0.029999999,0.039999999};
		temporary=0.0049999999;
	};
	class FST_recoil_DP23: recoil_default
	{
		muzzleOuter[]={0,6,0.80000001,0.40000001};
		kickBack[]={0.039999999,0.059999999};
		temporary=0.0080000004;
	};
	class FST_recoil_T15: recoil_default
	{
		muzzleOuter[]={0,2,0.80000001,0.80000001};
		kickBack[]={0.0099999998,0.12};
		temporary=0.029999999;
	};
	class FST_recoil_Valken38x: recoil_default
	{
		muzzleOuter[]={0,0.34999999,0.60000002,0.60000002};
		kickBack[]={0.029999999,0.039999999};
		temporary=0.0060000001;
	};
	class FST_recoil_Z6: recoil_default
	{
		muzzleOuter[]={0,0.050000001,0.60000002,0.60000002};
		kickBack[]={0.059999999,0.090000004};
		temporary=0.0060000001;
	};
};

