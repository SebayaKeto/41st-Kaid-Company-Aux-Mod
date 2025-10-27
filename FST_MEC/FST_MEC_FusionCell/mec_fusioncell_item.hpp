class MEC_FusionCell: Land_WoodenCrate_01_F
{
    author = MEC_AUTHOR;
    scope = 2;
    scopecurator = 2;
    displayName = "MEC-P1 M-Pulse Fusion Cell (Stationary)";
    model = "\FST\FST_MEC\FST_MEC_FusionCell\MEC_MPulseFusionCell.p3d";
	icon = "iconObject_circle";
    editorCategory = "FST_MEC_CategoryEquipment";
    editorSubcategory = "FST_MEC_SubcategoryBatteries";
    placement = "vertical";
    mapSize = 1;
    destrType = "DestructNo";
    ace_cargo_space = 2;
    ace_cargo_size = 4;
    MEC_PowerSystem = 1;
    MEC_PowerSystem_Type = "FusionCell";
    MEC_PowerSystem_MaxCharge = 10000; // Max Charge Capacity
    MEC_PowerSystem_InitialCharge = 10000; // Initial Charge on Spawn
    MEC_PowerSystem_ChargeRate = 500; // Charge Rate (units per second)
    MEC_PowerSystem_CanDischarge = 0; // Can't Discharge
    MEC_PowerSystem_DischargeRate = 0; // Discharge Rate (units per second)
};