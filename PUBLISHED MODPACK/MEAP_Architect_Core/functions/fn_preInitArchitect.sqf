if (isServer) then
{
    call MEAP_fnc_initializeArchitectState;
};

private _defaultClasses =
[
    "MEAP_SW_Props_Common_StoneBarrierOne_Sandstone",
    "MEAP_SW_Props_Common_StoneBarrierOneTall_Sandstone",
    "MEAP_SW_Props_Common_StoneBarrierOne_LimeStone",
    "MEAP_SW_Props_Common_StoneBarrierOneTall_LimeStone",
    "MEAP_SW_Props_Common_DuracreteBarrierOne_FiringPort",
    "MEAP_SW_Props_Common_DuracreteBarrierOne_NoFiringPort",
    "MEAP_SW_Props_Common_DuracreteBarrierTwo_NoFiringPort",
    "MEAP_SW_Structures_Desert_BP_Floor_ONE",
    "MEAP_SW_Structures_Desert_BP_PillarPristine_ONE",
    "MEAP_SW_Structures_RepublicFOBBB_WallJoint",
    "MEAP_SW_Structures_RepublicFOBBB_WallJoint_ConcreteBase",
    "Land_BagFence_Long_F",
    "Land_BagFence_Round_F",
    "Land_BagFence_Short_F",
    "Land_HBarrier_3_F",
    "Land_HBarrier_5_F",
    "Land_CncBarrier_F",
    "Land_CncBarrierMedium_F",
    "Land_Cargo_House_V1_F",
    "Land_Cargo_Patrol_V1_F",
    "Land_Cargo_Tower_V1_F"
];
MEAP_Architect_defaultClasses = _defaultClasses;
MEAP_Architect_defaultClassList = str _defaultClasses;
private _defaultBuildCosts = "[[""MEAP_SW_Props_Common_StoneBarrierOne_Sandstone"",3],[""MEAP_SW_Props_Common_StoneBarrierOneTall_Sandstone"",3],[""MEAP_SW_Props_Common_StoneBarrierOne_LimeStone"",3],[""MEAP_SW_Props_Common_StoneBarrierOneTall_LimeStone"",3],[""MEAP_SW_Props_Common_DuracreteBarrierOne_FiringPort"",5],[""MEAP_SW_Props_Common_DuracreteBarrierOne_NoFiringPort"",5],[""MEAP_SW_Props_Common_DuracreteBarrierTwo_NoFiringPort"",5],[""MEAP_SW_Structures_Desert_BP_Floor_ONE"",6],[""MEAP_SW_Structures_Desert_BP_PillarPristine_ONE"",8],[""MEAP_SW_Structures_RepublicFOBBB_WallJoint"",8],[""MEAP_SW_Structures_RepublicFOBBB_WallJoint_ConcreteBase"",10],[""Land_BagFence_Long_F"",2],[""Land_BagFence_Round_F"",2],[""Land_BagFence_Short_F"",2],[""Land_HBarrier_3_F"",10],[""Land_HBarrier_5_F"",15],[""Land_CncBarrier_F"",6],[""Land_CncBarrierMedium_F"",8],[""Land_Cargo_House_V1_F"",20],[""Land_Cargo_Patrol_V1_F"",25],[""Land_Cargo_Tower_V1_F"",30]]";

[
    "MEAP_Architect_enabled",
    "CHECKBOX",
    ["Enable Daidalos Mode", "Allows eligible players to request the restricted Daidalos construction camera."],
    ["MEAP", "Daidalos"],
    true,
    1,
    {if (isServer) then {call MEAP_fnc_parseArchitectClassList;};}
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_allowAdvancedEngineers",
    "CHECKBOX",
    ["Allow Advanced Engineers", "Treats ACE advanced engineers as eligible Daidalos users when ACE is loaded."],
    ["MEAP", "Daidalos"],
    true,
    1,
    {if (isServer) then {call MEAP_fnc_parseArchitectClassList;};}
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_allowedClassList",
    "EDITBOX",
    ["Allowed Construction Classes", "Serialized array of CfgVehicles class names available in Daidalos mode."],
    ["MEAP", "Daidalos"],
    str _defaultClasses,
    1,
    {if (isServer) then {call MEAP_fnc_parseArchitectClassList;};}
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_includeDefaultClasses",
    "CHECKBOX",
    ["Include Bundled Construction Classes", "Merges the bundled MEAP and vanilla Daidalos presets with Allowed Construction Classes. Disable for a strict custom-only list."],
    ["MEAP", "Daidalos"],
    true,
    1,
    {if (isServer) then {call MEAP_fnc_parseArchitectClassList;};}
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_budgetEnabled",
    "CHECKBOX",
    ["Enable Build Budget", "Requires Daidalos construction objects to be paid for with the configured currency."],
    ["MEAP", "Daidalos Budget"],
    true,
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_currencyName",
    "EDITBOX",
    ["Currency Name", "Label shown for Daidalos construction funds."],
    ["MEAP", "Daidalos Budget"],
    "Republic Credits",
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_budgetFundingMode",
    "LIST",
    ["Funding Source", "Use a server-held player budget, consume inventory currency items, or spend from a nearby FOB pool."],
    ["MEAP", "Daidalos Budget"],
    [[0, 1, 2], ["Server Budget", "Player Inventory", "FOB Pool"], 0],
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_startingBudget",
    "SLIDER",
    ["Starting Budget", "Server-held currency assigned to each player when they first use Daidalos."],
    ["MEAP", "Daidalos Budget"],
    [0, 10000, 100, 0],
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_inventoryCurrencyClasses",
    "EDITBOX",
    ["Inventory Currency Classes", "Serialized array of item or magazine class names consumed when Funding Source is Player Inventory."],
    ["MEAP", "Daidalos Budget"],
    "[]",
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_inventoryCurrencyValue",
    "SLIDER",
    ["Inventory Currency Value", "Currency value represented by each configured inventory item or magazine."],
    ["MEAP", "Daidalos Budget"],
    [1, 100, 1, 0],
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_defaultBuildCost",
    "SLIDER",
    ["Default Object Cost", "Currency cost for allowed classes without a specific configured cost."],
    ["MEAP", "Daidalos Budget"],
    [0, 1000, 5, 0],
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_buildCosts",
    "EDITBOX",
    ["Object Costs", "Serialized [class name, cost] pairs that override Default Object Cost."],
    ["MEAP", "Daidalos Budget"],
    _defaultBuildCosts,
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_fobHeartClass",
    "EDITBOX",
    ["FOB Heart Class", "CfgVehicles class used as the Daidalos FOB heart. Leave empty until the custom heart object exists."],
    ["MEAP", "Daidalos FOB"],
    "",
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_fobRadius",
    "SLIDER",
    ["FOB Radius", "Radius in metres covered by an active FOB heart for construction and decay protection."],
    ["MEAP", "Daidalos FOB"],
    [25, 1000, 250, 0],
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_fobStartingFunds",
    "SLIDER",
    ["FOB Starting Funds", "Shared currency assigned when a newly discovered FOB heart is established."],
    ["MEAP", "Daidalos FOB"],
    [0, 100000, 0, 0],
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_fobDepositValues",
    "EDITBOX",
    ["FOB Deposit Values", "Serialized [item or magazine class, currency value] pairs accepted by a FOB heart."],
    ["MEAP", "Daidalos FOB"],
    "[]",
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_fobMaterialRecipes",
    "EDITBOX",
    ["FOB Material Recipes", "Serialized [input resource, input amount, output resource, output amount] recipes processed at an active FOB heart."],
    ["MEAP", "Daidalos FOB"],
    "[[""Stone"",2,""Supplies"",1],[""Lumber"",2,""Supplies"",1],[""Credits"",5,""Supplies"",1]]",
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_fobInteractionRange",
    "SLIDER",
    ["FOB Interaction Range", "Maximum distance in metres for depositing currency into or viewing an active FOB heart."],
    ["MEAP", "Daidalos FOB"],
    [1, 25, 5, 0],
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_fobDecayDelay",
    "SLIDER",
    ["FOB Decay Delay", "Seconds after a heart is lost before its Daidalos objects begin to disappear."],
    ["MEAP", "Daidalos FOB"],
    [0, 86400, 900, 0],
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_fobDecayInterval",
    "SLIDER",
    ["FOB Decay Interval", "Seconds between each disappearing Daidalos object after a heart is lost."],
    ["MEAP", "Daidalos FOB"],
    [1, 3600, 30, 0],
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_maxDistance",
    "SLIDER",
    ["Daidalos Radius", "Maximum three-dimensional distance in metres for the camera and construction actions around the Daidalos user."],
    ["MEAP", "Daidalos"],
    [25, 1000, 50, 0],
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_maxObjects",
    "SLIDER",
    ["Maximum Objects Per Daidalos User", "Maximum number of active objects placed by each Daidalos user."],
    ["MEAP", "Daidalos"],
    [1, 500, 100, 0],
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_maxPlacementSlope",
    "SLIDER",
    ["Maximum Placement Slope", "Maximum terrain-aligned object slope in degrees. Set to 90 to allow any orientation."],
    ["MEAP", "Daidalos"],
    [0, 90, 45, 0],
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_accessSide",
    "LIST",
    ["Construction Access Side", "Limits Daidalos mode to one playable side, or allows every side."],
    ["MEAP", "Daidalos Permissions"],
    [[0, 1, 2, 3], ["Any Side", "BLUFOR", "OPFOR", "Independent"], 0],
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_ownerMayMaintain",
    "CHECKBOX",
    ["Owners May Maintain", "Allows the original Daidalos builder to edit or delete objects they placed. Server administrators always retain access."],
    ["MEAP", "Daidalos Permissions"],
    true,
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_unownedMayMaintain",
    "CHECKBOX",
    ["Allow Unowned Object Maintenance", "Allows Daidalos users to edit or delete legacy and mission objects without Daidalos ownership data."],
    ["MEAP", "Daidalos Permissions"],
    true,
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_auditDepth",
    "SLIDER",
    ["Audit History Depth", "Maximum accepted Daidalos actions retained in the server-session audit trail."],
    ["MEAP", "Daidalos Permissions"],
    [25, 2000, 200, 0],
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_actionCooldown",
    "SLIDER",
    ["Action Cooldown", "Minimum server-enforced delay in seconds between construction mutations from one client."],
    ["MEAP", "Daidalos"],
    [0, 2, 0.2, 2],
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_undoWindow",
    "SLIDER",
    ["Undo Window", "Seconds during which the latest accepted construction action can be reversed."],
    ["MEAP", "Daidalos"],
    [10, 600, 120, 0],
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_historyDepth",
    "SLIDER",
    ["Undo History Depth", "Maximum recent inverse operations retained per Daidalos user."],
    ["MEAP", "Daidalos"],
    [1, 100, 25, 0],
    1
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_gridSize",
    "LIST",
    ["Default Grid Size", "Default world-space position increment used by the Daidalos preview."],
    ["MEAP", "Daidalos Camera"],
    [[0, 0.1, 0.5, 1, 5], ["Off", "0.1 m", "0.5 m", "1 m", "5 m"], 2],
    0
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_rotationStep",
    "LIST",
    ["Default Rotation Step", "Default heading increment used by Daidalos rotation controls."],
    ["MEAP", "Daidalos Camera"],
    [[1, 5, 15, 45], ["1 degree", "5 degrees", "15 degrees", "45 degrees"], 2],
    0
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_surfaceAlign",
    "CHECKBOX",
    ["Align To Surface", "Aligns the preview up vector with the placement surface by default."],
    ["MEAP", "Daidalos Camera"],
    true,
    0
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_verticalStep",
    "SLIDER",
    ["Vertical Offset Step", "Distance in metres applied by each vertical offset command."],
    ["MEAP", "Daidalos Camera"],
    [0.01, 5, 0.1, 2],
    0
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_mouseYawSensitivity",
    "SLIDER",
    ["Mouse Yaw Sensitivity", "Horizontal camera rotation applied while holding the right mouse button."],
    ["MEAP", "Daidalos Camera"],
    [10, 120, 45, 0],
    0
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_mousePitchSensitivity",
    "SLIDER",
    ["Mouse Pitch Sensitivity", "Vertical camera rotation applied while holding the right mouse button."],
    ["MEAP", "Daidalos Camera"],
    [10, 120, 35, 0],
    0
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_keyTurnSpeed",
    "SLIDER",
    ["Keyboard Turn Speed", "Camera rotation speed in degrees per second when using the arrow keys."],
    ["MEAP", "Daidalos Camera"],
    [10, 180, 70, 0],
    0
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_cameraMoveSpeed",
    "SLIDER",
    ["Camera Move Speed", "Camera movement speed in metres per second."],
    ["MEAP", "Daidalos Camera"],
    [1, 100, 10, 0],
    0
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_cameraFastMoveSpeed",
    "SLIDER",
    ["Camera Fast Move Speed", "Camera movement speed in metres per second while holding Shift."],
    ["MEAP", "Daidalos Camera"],
    [1, 200, 30, 0],
    0
] call CBA_fnc_addSetting;

[
    "MEAP_Architect_zoneRadius",
    "SLIDER",
    ["Private Zone Radius", "Default radius in metres for temporary Daidalos-only construction zones."],
    ["MEAP", "Daidalos Camera"],
    [2, 100, 15, 0],
    0
] call CBA_fnc_addSetting;

if (hasInterface) then
{
    [
        "MEAP",
        "MEAP_Architect_open",
        ["Open Daidalos Mode", "Requests the restricted MEAP Daidalos construction camera."],
        {
            if (missionNamespace getVariable ["MEAP_Architect_cameraOpen", false]) then
            {
                [] call MEAP_fnc_closeArchitectCamera;
            }
            else
            {
                [player] remoteExecCall ["MEAP_fnc_requestArchitectMode", 2];
            };
            true
        },
        {false},
        [48, [true, true, false]]
    ] call CBA_fnc_addKeybind;
};