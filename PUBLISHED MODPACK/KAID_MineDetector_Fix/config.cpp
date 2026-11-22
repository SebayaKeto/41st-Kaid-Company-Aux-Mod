// KAID_MineDetector_Fix (candidate b, 8 Nov 2026). Client-side UI config only; no scripts.
// The vanilla MineDetector panel draws mines that the player's side already KNOWS (revealMine, e.g. ACE Zeus
// "Reveal mines") at sizeMine: a red pip a few pixels wide, unreadable in play. Unknown mines get a large glow.
// Vanilla values: A3_Ui_F sizeMine 1 / sizeMineUnknown 2, then A3_Ui_F_Orange (Contact UI) sizeMine 1.5 / sizeMineUnknown 4.
// This draws known mines at the same size as unknown ones, so the EOD always sees them.
class CfgPatches
{
	class KAID_MineDetector_Fix
	{
		name = "KAID Mine Detector: known mines drawn full size";
		author = "41st Kaid Co Aux";
		units[] = {};
		weapons[] = {};
		requiredVersion = 2.0;
		requiredAddons[] = {"A3_Ui_F", "A3_Ui_F_Orange"};
	};
};
class RscCustomInfoMineDetect
{
	sizeMine = 4;
};
