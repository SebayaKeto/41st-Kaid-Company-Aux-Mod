// KAID_OPTRE_EliteFaceCheck_Off: stops OPTRE First Contact's Elite face-check scripts.
// OPTRE_FC_Units starts fn_Init AND fn_InitRespawn at postInit on every machine. On the
// dedicated server and every HC both sit in "waitUntil {alive player}" forever (no player
// there) - a per-frame scheduled check each - and on clients they loop every 5 s checking
// whether the player is an Elite. The 41st has no Elite players. Blanking the two CBA
// postInit entries means neither script starts; nothing else in Trebuchet changes.
class CfgPatches
{
	class KAID_OPTRE_EliteFaceCheck_Off
	{
		name = "KAID: OPTRE Elite face check off";
		author = "41st Aux Updater";
		units[] = {};
		weapons[] = {};
		requiredVersion = 2.0;
		requiredAddons[] = {"OPTRE_FC_Units","cba_xeh"};
		skipWhenMissingDependencies = 1;
	};
};
class Extended_PostInit_EventHandlers
{
	OPTRE_FC_EliteFaceCheck_fnc_Init = "";
	OPTRE_FC_EliteFaceCheck_fnc_InitRespawn = "";
};
