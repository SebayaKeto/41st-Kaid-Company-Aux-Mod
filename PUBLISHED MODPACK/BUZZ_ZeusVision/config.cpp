// =============================================================================
//  BUZZ Zeus Vision — trooper detail tags for Zeus.
//  Right-click in Zeus > Show Trooper Details > radius. Players inside that
//  circle get a tag (name / kit, rifle ammo, launcher ammo) coloured
//  Green / Yellow / Red / Black, drawn only on that Zeus's screen.
// =============================================================================

class CfgPatches
{
    class BUZZ_ZeusVision
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"A3_Functions_F", "A3_Ui_F", "cba_main", "zen_context_menu"};
        author = "BUZZ";
    };
};

class CfgFunctions
{
    class BUZZ
    {
        class ZeusVision
        {
            class zvCountRounds     { file = "BUZZ_ZeusVision\functions\fnc_zvCountRounds.sqf"; };
            class zvColour          { file = "BUZZ_ZeusVision\functions\fnc_zvColour.sqf"; };
            class zvPublish         { file = "BUZZ_ZeusVision\functions\fnc_zvPublish.sqf"; };
            class zvResetBaseline   { file = "BUZZ_ZeusVision\functions\fnc_zvResetBaseline.sqf"; };
            class zvSelect          { file = "BUZZ_ZeusVision\functions\fnc_zvSelect.sqf"; };
            class zvAddContextMenu  { file = "BUZZ_ZeusVision\functions\fnc_zvAddContextMenu.sqf"; };
            class zvRefreshCache    { file = "BUZZ_ZeusVision\functions\fnc_zvRefreshCache.sqf"; };
            class zvDraw            { file = "BUZZ_ZeusVision\functions\fnc_zvDraw.sqf"; };
            class zvKeySelect       { file = "BUZZ_ZeusVision\functions\fnc_zvKeySelect.sqf"; };
        };
    };
};

class Extended_PreInit_EventHandlers
{
    class BUZZ_ZeusVision
    {
        init = "call compile preprocessFileLineNumbers '\BUZZ_ZeusVision\XEH_preInit.sqf'";
    };
};

class Extended_PostInit_EventHandlers
{
    class BUZZ_ZeusVision
    {
        init = "call compile preprocessFileLineNumbers '\BUZZ_ZeusVision\XEH_postInit.sqf'";
    };
};
