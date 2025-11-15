class MEC_CDP_Dock: Static_F
{
    scope = 2;
    scopeCurator = 2;
    displayName = "MEC-CD/P Pebble Dock";
    author = "Maldova Engineering Corp.";
    model = "\FST\FST_Outpost\LightWalls\FST_OutpostWall_Light.p3d";
    editorCategory = "FST_MEC_CategoryEquipment";
    editorSubcategory = "FST_MEC_SubcategoryBatteries";
    class ace_variables
    {
        class mec_cdp_internal_charge 
        {
            displayName = "Internal Power Pool";
            value = 0;
            typeName = "SCALAR";
            forceType = 1;
            isPublic = 1;
            modifier = "none";
        };
        class mec_accepted_cells
        {
            displayName = "Accepted Power Cells";
            value[] = {"MEC_PB1_Item"};
            typeName = "ARRAY";
            forceType = 1;
            isPublic = 1;
            modifier = "none";
        };
    };
    class ACE_Actions
    {
        class ACE_Components
        {
            class MEC_CDP_Charge
            {
                displayName = "Insert Power Cell";
                statement = "[_target, player] call MEC_fnc_startPebbleCharge;";
                condition = "private _acceptedCells = [_target, 'mec_accepted_cells'] call ace_common_fnc_getKindaCfg; _found = false; { if (([player, _x] call ace_common_fnc_objectInInventory) isNotEqualTo objNull) then { _found = true; }; } forEach _acceptedCells; _found"; 
                showDisabled = 0;
                distance = 2;
            };
        };
    };
};