/*
    BUZZ_ZeusVision — XEH postInit
    Every player: publish own ammo state. Every player who could be Zeus:
    context menu + tag drawing (both do nothing until the Zeus picks a radius).
*/
if (!hasInterface) exitWith {};

BUZZ_zv_tracked = [];       // [[uid, unit], ...] chosen by this Zeus
BUZZ_zv_trackAll = false;   // "All players" mode
BUZZ_zv_cache = [];         // what the Draw3D handler draws
BUZZ_zv_nextRefresh = 0;
BUZZ_zv_hasAceMedical = isClass (configFile >> "CfgPatches" >> "ace_medical");   // optional, no hard dependency

// Ammo state, checked once a second, only broadcast when it changes.
[{ call BUZZ_fnc_zvPublish }, 1] call CBA_fnc_addPerFrameHandler;

call BUZZ_fnc_zvAddContextMenu;

// Keybind (unbound by default; set it in Configure > Controls > Configure Addons).
[
    "BUZZ Zeus Vision", "BUZZ_zv_keySelect",
    ["Show troopers in zone", "In Zeus: tag every player within the zone radius (Addon Options) of the mouse cursor."],
    { call BUZZ_fnc_zvKeySelect },
    {}
] call CBA_fnc_addKeybind;

addMissionEventHandler ["Draw3D", { call BUZZ_fnc_zvDraw }];
