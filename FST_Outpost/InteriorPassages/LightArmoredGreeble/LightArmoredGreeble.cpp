// ===================================================================================
// Interior passage wall greeble definitions
// -----------------------------------------------------------------------------------
// Included from FST_Outpost/config.cpp under CfgVehicles.
// ===================================================================================
class FST_Outpost_InteriorWallGreeble_Base: House_F
{
    editorCategory = "FST_CatagoryMajorOutpost";
    editorSubcategory = "FST_Subcategory_OutpostInteriorGreebles";
    scope = 0;
    scopecurator = 0;
    placement = "vertical";
    mapSize = 1;
    destrType = "DestructNo";
    displayName = "Interior Wall Greeble (Base)";
    model = "FST\FST_Outpost\InteriorPassages\LightArmoredGreeble\FST_RepublicInteriorWalkway_SidePanel_1x1x3m.p3d";
    hiddenSelections[] = {"Camo"};
    hiddenSelectionsTextures[] =
    {
        "FST\FST_Outpost\InteriorPassages\LightArmoredGreeble\Data\Textures\Camo_InteriorHeavyWalls_Greeble_1x1x3M_co.paa"
    };
    hiddenSelectionsMaterials[] =
    {
        "FST\FST_Outpost\InteriorPassages\LightArmoredGreeble\Data\Textures\Camo_InteriorHeavyWalls_Greeble_1x1x3M.rvmat"
    };
    eden = 1;
    editorPreview = "\FST\FST_Outpost\InteriorPassages\LightArmoredGreeble\Data\Icons\FST_RepublicInteriorWalkway_SidePanel_1x1x3m_Icon.jpg";
};
class FST_Outpost_InteriorWallGreeble_1x1x3M: FST_Outpost_InteriorWallGreeble_Base
{
    scope = 2;
    scopecurator = 2;
    displayName = "Light Armored Interior Wall Greeble (1x1x3m)";
};
class FST_Outpost_InteriorWallGreeble_5Wide: FST_Outpost_InteriorWallGreeble_Base
{
    scope = 2;
    scopecurator = 2;
    displayName = "Light Armored Interior Wall Greeble (1x1x3m 5 Wide)";
    model = "FST\FST_Outpost\InteriorPassages\LightArmoredGreeble\FST_RepublicInteriorWalkway_SidePanel_1x1x3m_5Wide.p3d";
};
class FST_Outpost_InteriorWallGreeble_End: FST_Outpost_InteriorWallGreeble_Base
{
    scope = 2;
    scopecurator = 2;
    displayName = "Light Armored Interior Wall Greeble (1x1x3m End)";
    model = "FST\FST_Outpost\InteriorPassages\LightArmoredGreeble\FST_RepublicInteriorWalkway_SidePanel_1x1x3m_End.p3d";
    editorPreview = "\FST\FST_Outpost\InteriorPassages\LightArmoredGreeble\Data\Icons\FST_RepublicInteriorWalkway_SidePanel_1x1x3m_End_Icon.jpg";
    hiddenSelectionsTextures[] =
    {
        "FST\FST_Outpost\InteriorPassages\LightArmoredGreeble\Data\Textures\Camo_InteriorHeavyWalls_Greeble_1x1x3M_End_01_co.paa"
    };
    hiddenSelectionsMaterials[] =
    {
        "FST\FST_Outpost\InteriorPassages\LightArmoredGreeble\Data\Textures\Camo_InteriorHeavyWalls_Greeble_1x1x3M_End_01.rvmat"
    };
};
class FST_Outpost_InteriorWallGreeble_5Wide_End: FST_Outpost_InteriorWallGreeble_End
{
    scope = 2;
    scopecurator = 2;
    displayName = "Light Armored Interior Wall Greeble (1x1x3m 5 Wide End)";
    model = "FST\FST_Outpost\InteriorPassages\LightArmoredGreeble\FST_RepublicInteriorWalkway_SidePanel_1x1x3m_5Wide_End.p3d";
};
class FST_Outpost_InteriorFloorGreeble_1x0_5x5M: FST_Outpost_InteriorWallGreeble_Base
{
    scope = 2;
    scopecurator = 2;
    displayName = "Light Armored Interior Floor Greeble (1x0.5x5m)";
    model = "FST\FST_Outpost\InteriorPassages\LightArmoredGreeble\FST_RepublicInteriorWalkway_FloorPanel_1x0_5x5m.p3d";
    editorPreview = "\FST\FST_Outpost\InteriorPassages\LightArmoredGreeble\Data\Icons\FST_RepublicInteriorWalkway_FloorPanel_1x0.5x5m_Icon.jpg";
    hiddenSelectionsTextures[] =
    {
        "FST\FST_Outpost\InteriorPassages\LightArmoredGreeble\Data\Textures\FST_RepublicInteriorWalkway_FloorPanel_1x0.5x5m_co.paa"
    };
    hiddenSelectionsMaterials[] =
    {
        "FST\FST_Outpost\InteriorPassages\LightArmoredGreeble\Data\Textures\FST_RepublicInteriorWalkway_FloorPanel_1x0.5x5m.rvmat"
    };
};
class FST_Outpost_InteriorFloorGreeble_1x0_5x5M_02: FST_Outpost_InteriorFloorGreeble_1x0_5x5M
{
    scope = 2;
    scopecurator = 2;
    displayName = "Light Armored Interior Floor Greeble (1x0.5x5m 02)";
    model = "FST\FST_Outpost\InteriorPassages\LightArmoredGreeble\FST_RepublicInteriorWalkway_FloorPanel_1x0_5x5m_02.p3d";
    hiddenSelectionsTextures[] =
    {
        "FST\FST_Outpost\InteriorPassages\LightArmoredGreeble\Data\Textures\FST_RepublicInteriorWalkway_FloorPanel_1x0.5x5m_02_co.paa"
    };
    hiddenSelectionsMaterials[] =
    {
        "FST\FST_Outpost\InteriorPassages\LightArmoredGreeble\Data\Textures\FST_RepublicInteriorWalkway_FloorPanel_1x0.5x5m_02.rvmat"
    };
};
