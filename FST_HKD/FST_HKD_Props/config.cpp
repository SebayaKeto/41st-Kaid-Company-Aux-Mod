
class CfgPatches
{
    class FST_HKD_Props
    {
        author = "FST";
        name = "FST HKD Props";
        requiredAddons[] = {"A3_Structures_F", "A3_Soft_F"};
        requiredVersion = 0.1;
        units[] = {
            // ===== CARGO CRATES =====
            "FST_HKD_Crate_CargoSmall_Blank",
            "FST_HKD_Crate_CargoSmall_Blue",
            "FST_HKD_Crate_CargoSmall_Orange",
            "FST_HKD_Crate_CargoSmall_White",
            "FST_HKD_Crate_CargoSmall_GeneralLogistics",
            
            // ===== SUPPLY CRATES =====
            "FST_HKD_Crate_SupplySmall_Blank",
            
            // ===== PORTABLE BARRICADES =====
            "FST_HKD_Barricade_Portable_Blank",
        };
        weapons[] = {};
    };
};

class CfgVehicles
{
    class House_F;
    class ReammoBox_F;
    class ThingX;
    #include "Crates/Crates.cpp"
    #include "Barricades/Barricades.cpp"
    #include "Posts/Posts.cpp"
    #include "Containers/Containers.cpp"
    #include "SignagePanels/SignagePanels.cpp"
    #include "Billboards/Billboards.cpp"
    #include "Furniture/Furniture.cpp"
};
