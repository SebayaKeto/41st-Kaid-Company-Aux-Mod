class MEC_FusionCell: Land_WoodenCrate_01_F
{
    author = MEC_AUTHOR; // Author information
    scope = 2; // Publicly accessible
    scopecurator = 2; // Visible in Zeus
    displayName = "MEC-P1 M-Pulse Fusion Cell (Stationary)"; // Item name
    model = "\FST\FST_MEC\FST_MEC_FusionCell\MEC_MPulseFusionCell.p3d"; // 3D model path
	icon = "iconObject_circle"; // Map icon
    editorCategory = "FST_MEC_CategoryEquipment"; // Equipment Category
    editorSubcategory = "FST_MEC_SubcategoryBatteries"; // Battery Subcategory
    placement = "vertical"; // Placement orientation
    mapSize = 1; // Map icon size 
    destrType = "DestructNo"; // Indestructible
    ace_cargo_space = 2; // This item has 2 cargo space units
    ace_cargo_size = 4; // Takes up 4 slots in ace cargo system
    MEC_PowerSystem = 1; // Enable Power System
    MEC_PowerSystem_IsSupplier = 1; //Can Supply Power (set to 0 for consumer-only role)
    MEC_PowerSystem_IsConsumer = 0; //Can Consume Power (set to 0 for supplier-only role)
    MEC_PowerSystem_SupplierRadius = 10; // Supply Radius (meters)
    MEC_PowerSystem_SupplierRate = 200; // Supply Rate (units per second)
    MEC_PowerSystem_Type = "Battery"; // Power System Type
    MEC_PowerSystem_SupplierType = "FusionCell"; // Supplier Type (Defines behavior, compatability, etc.)
    MEC_PowerSystem_MaxCharge = 10000; // Max Charge Capacity 
    MEC_PowerSystem_InitialCharge = 10000; // Initial Charge on Spawn 
    MEC_PowerSystem_ChargeRate = 200; // Charge Rate (units per second)
    MEC_PowerSystem_CanDischarge = 0; // Can't discharge power over time
    MEC_PowerSystem_DischargeRate = 0; // Discharge Rate (units per second).  Needed if CanDischarge is 1
    picture = MEC_ICON_PATH; // Path to picture
};