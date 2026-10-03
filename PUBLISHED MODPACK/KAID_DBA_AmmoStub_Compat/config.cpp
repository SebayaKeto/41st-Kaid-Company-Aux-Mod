// KAID_DBA_AmmoStub_Compat (optional): DBA Core's DBA_VehicleWeapons declares "class DefaultEventhandlers;" INSIDE CfgAmmo,
// which the engine loads as an ammo with no body -> "No entry ...CfgAmmo/DefaultEventhandlers.<prop>" cascade and
// "'weaponLockSystem/' is not a value" (client warning box). This gives that stub a valid ammo base. DBA is not edited;
// the addon is skipped when DBA_patch_vehicle_weapons is not loaded. Nothing else is touched.
class CfgPatches
{
	class KAID_DBA_AmmoStub_Compat
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"A3_Data_F","DBA_patch_vehicle_weapons"};
		skipWhenMissingDependencies=1;
	};
};
class CfgAmmo
{
	class Default;
	class DefaultEventhandlers: Default
	{
		scope=0;
	};
};
