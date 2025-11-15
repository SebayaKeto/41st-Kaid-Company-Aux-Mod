/*
    mec_pebble_item.hpp
    Defines the MEC-PB/1 'Utility Pebble' item for inclusion into CfgVehicles.
    This file is intended to be #included in the master config.hpp.
*/
class MEC_PB1_Item: Item_Base_F
{
    scope = 2;
    scopeCurator = 2;
    displayName = "MEC-PB/1 Pebble";
    author = MEC_AUTHOR;
    class TransportItems
    {
		class MEC_Battery_PBOne
		{
			count = 1;
			name = "MEC_Battery_PBOne";
		};
	};
    class ace_variables
    {
        class charge 
        {
            displayName = "Charge Level";
            value = 100;
            typeName = "SCALAR";
            forceType = 1;
            isPublic = 1;
            modifier = "none";
        };
    };
    // --- ACE Interaction Definition (Self-Interaction on the item) ---
    class ACE_Actions
    {
        class ACE_Equipment
        {
            class MEC_PB1_CheckCharge
            {
                displayName = "Check Charge Level";
                statement = "[player, _target] call MEC_fnc_checkMECCharge;"; 
                condition = "true";
                showDisabled = 0;
                distance = 3;
            };
        };
    };
};