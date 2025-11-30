
class CfgPatches
{
    class FST_HKD_Props
    {
        author = "FST";
        name = "FST HKD Props";
        requiredAddons[] = {"A3_Structures_F"};
        requiredVersion = 0.1;
        units[] = {
            // ===== SUPPLY CRATES =====
            "FST_HKD_Crate_SupplyMedium_Blank",
            "FST_HKD_Crate_SupplyMedium_Blue",
            "FST_HKD_Crate_SupplyMedium_Orange",
            "FST_HKD_Crate_SupplyMedium_White",
            "FST_HKD_Crate_SupplyMedium_GeneralLogistics"
        };
        weapons[] = {};
    };
};

class CfgVehicles
{
    class House_F;
    #include "Crates/Crates.cpp"
    #include "Posts/Posts.cpp"
    #include "Containers/Containers.cpp"
    #include "SignagePanels/SignagePanels.cpp"
    #include "Billboards/Billboards.cpp"
    #include "Furniture/Furniture.cpp"
};
