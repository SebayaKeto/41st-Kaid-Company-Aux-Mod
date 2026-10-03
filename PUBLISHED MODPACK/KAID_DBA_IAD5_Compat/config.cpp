// KAID_DBA_IAD5_Compat (optional): DBA's DBA_IAD5_MMissile (addon DBA_Aux_Mod_IPM5) declares weaponLockSystem[] = {"1+2+16"}
// (an array); the engine expects a scalar and logs "'weaponLockSystem/' is not a value" (client warning box). This sets the
// same lock mask as scalar text, the format of its sibling DBA_TAM91_SAM ("1 + 2 + 16").
// DBA is not edited; the addon is skipped when DBA_Aux_Mod_IPM5 is not loaded. Only this one class is touched.
class CfgPatches
{
	class KAID_DBA_IAD5_Compat
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"A3_Data_F","DBA_Aux_Mod_IPM5"};
		skipWhenMissingDependencies=1;
	};
};
class CfgAmmo
{
	class MissileBase;
	class DBA_IAD5_MMissile: MissileBase
	{
		weaponLockSystem="1 + 2 + 16";
	};
};
