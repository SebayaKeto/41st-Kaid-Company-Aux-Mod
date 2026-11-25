// KAID_QoL (Aux Updater, 25 Nov 2026; Miran: "Can do em for by the weekend"). Our own versions of three small mods from the
// live list, written for the Aux (no files copied from them):
//   - Remove stamina        -> stamina stays off for the player (XEH_postInitClient.sqf)
//   - No Weapon Sway        -> CfgImprecision radii 0 (below; same values the live mod uses)
//   - More Aircraft Displays -> pilot/co-pilot ETA + fuel panel (XEH_postInitClient.sqf; CBA per-frame handler, no onEachFrame)
// The fourth, Remove stamina - ACE 3, is ace\config.cpp in this PBO (skipped without ACE).
// Safe while the old mods are still loaded: same sway values, stamina off twice, and the aircraft panel stands down if
// More Aircraft Displays is loaded (no double panel).
class CfgPatches
{
	class KAID_QoL
	{
		name="41st Kaid QoL";
		author="41st Kaid Company";
		units[]={};
		weapons[]={};
		requiredVersion=2.14;
		requiredAddons[]={"A3_Data_F","cba_main","cba_xeh"};
	};
};
class CfgImprecision
{
	class Primary
	{
		verticalRadius=0;
		horizontalRadius=0;
	};
	class Secondary
	{
		verticalRadius=0;
		horizontalRadius=0;
	};
};
class Extended_PostInit_EventHandlers
{
	class KAID_QoL
	{
		clientInit="call compileScript ['\KAID_QoL\XEH_postInitClient.sqf']";
	};
};
