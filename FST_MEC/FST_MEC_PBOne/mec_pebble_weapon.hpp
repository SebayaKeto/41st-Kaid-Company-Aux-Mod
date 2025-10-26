class ItemCore;
class InventoryWeapon_Base_F;
class MEC_Battery_PBOne: ItemCore
{
	author = MEC_AUTHOR;
	scope = 2;
	model = "\FST\FST_MEC\FST_MEC_PBOne\MEC_PBOneUtilityPebble.p3d";
	displayName = "MEC-PB/1 Pebble";
	descriptionShort = "MEC-PB/1 Utility Pebble Power Cell";
	//picture = "\MRC\JLTS\contraband\Credits\data\ui\credit_10_ui_ca.paa";
    detectRange = -1;
	simulation = "ItemMineDetector";
	useAsBinocular = 0;
	type = 4096;
	class ItemInfo: InventoryWeapon_Base_F
	{
		mass = 1;
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
    class ACE_Actions
    {
        class ACE_Equipment
        {
            class MEC_CheckPebbleCharge
                {
                    displayName = "Check Charge Level";
                    statement = "[player, _target] call MEC_fnc_checkChargeState;";
                    condition = "[_target] call ace_common_fnc_inInventory"; 
                    showDisabled = 0;
                    distance = 1;
                };
        };
    };
};