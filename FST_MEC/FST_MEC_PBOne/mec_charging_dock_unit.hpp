/*
    mec_charging_dock_unit.hpp
    Defines the MEC-CD/P 'Pebble Dock' stationary unit for inclusion into CfgVehicles.
    This file is intended to be #included in the master config.hpp.
*/
class MEC_CDP_Dock: Static_F
{
    scope = 2;
    scopeCurator = 2;
    displayName = "MEC-CD/P Pebble Dock";
    author = "Maldova Engineering Corp.";
    
    // --- Visual/Physical Properties ---
    model = "\FST\FST_Outpost\LightWalls\FST_OutpostWall_Light.p3d"; // Placeholder model
    editorCategory = "FST_MEC_CategoryEquipment"; // Custom editor category
    editorSubcategory = "FST_MEC_SubcategoryBatteries";   // Custom subcategory
    
    // --- CRITICAL: Custom variable for the Dock's internal charge (for transfer purposes) ---
    class ace_variables
    {
        class mec_cdp_internal_charge 
        {
            displayName = "Internal Power Pool";
            value = 0; // Starts uncharged
            typeName = "SCALAR";
            forceType = 1;
            isPublic = 1;
            modifier = "none";
        };
        // NEW: Array to hold all acceptable power cell item class names
        class mec_accepted_cells
        {
            displayName = "Accepted Power Cells";
            value[] = {"MEC_PB1_Item"}; // Defaulting to the 'Utility Pebble'
            typeName = "ARRAY";
            forceType = 1;
            isPublic = 1;
            modifier = "none";
        };
    };

    // --- ACE Interaction Definition (Dock actions) ---
    class ACE_Actions
    {
        class ACE_Components
        {
            class MEC_CDP_Charge
            {
                // This will be the action to insert the pebble for charging
                displayName = "Insert Power Cell"; // Generic display name
                // This function needs to check inventory and perform the transfer
                statement = "[_target, player] call MEC_fnc_startPebbleCharge;"; 
                
                // CRITICAL CHANGE: Checks if the player has ANY item defined in the mec_accepted_cells array
                condition = "private _acceptedCells = [_target, 'mec_accepted_cells'] call ace_common_fnc_getKindaCfg; _found = false; { if (([player, _x] call ace_common_fnc_objectInInventory) isNotEqualTo objNull) then { _found = true; }; } forEach _acceptedCells; _found"; 
                showDisabled = 0;
                distance = 2;
            };
        };
    };
};