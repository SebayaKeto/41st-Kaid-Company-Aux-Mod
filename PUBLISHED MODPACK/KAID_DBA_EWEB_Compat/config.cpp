// KAID_DBA_EWEB_Compat (optional): DBA CIS's E-Web (addon 101st_EWEB) declares DestructionEffects/SmokeSmall position[]={0,0,0}
// (an array); the engine expects the name of a Memory LOD point and logs "'position/' is not a value" (client warning box).
// This sets it to "destructionEffect", the point its sibling Sound effect already uses (present in eweb.p3d).
// DBA is not edited; the addon is skipped when 101st_EWEB is not loaded. Only this one value is touched.
class CfgPatches
{
	class KAID_DBA_EWEB_Compat
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"A3_Data_F","101st_EWEB"};
		skipWhenMissingDependencies=1;
	};
};
class CfgVehicles
{
	class StaticMGWeapon;
	class 101st_EWEB_base: StaticMGWeapon
	{
		class DestructionEffects
		{
			class SmokeSmall
			{
				position="destructionEffect";
			};
		};
	};
};
