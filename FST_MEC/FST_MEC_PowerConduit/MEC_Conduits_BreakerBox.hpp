/*
    MEC_Conduits_BreakerBox.hpp
    FST_MEC Power Conduit Breaker Box Definitions
    * MALDOVA ENGINEERING CORPORATION (MEC)
    * STAR WARS POWER CONDUIT BREAKER BOX CORE HEADER
    * Provides a macro for defining various Breaker Box variants
    * within CfgVehicles for MEC's FST Power Conduit System.
    * Designed by MEC for standardized power distribution solutions.
*/

#define MEC_FULL_NAME "Maldova Engineering Corporation (MEC)"
#define MEC_SHORT_NAME "MEC"
#define MEC_RLS_POWER "RLS-C4 (Grid Power Conduit)"
#define MEC_POWERSYSTEM_BREAKERBOX_CLASS(_NAME, _MODEL_PATH, _DESIGNATION, _TEX_PATH, _MAT_PATH) \
class ##_NAME : House_F \
{ \
    scope = 2; \
    scopeCurator = 2; \
    displayName = _DESIGNATION; \
    author = MEC_FULL_NAME; \
    destructType = "DestructNo"; \
    editorCategory = "FST_MEC_CategoryPowerSystems"; \
    editorSubcategory = "FST_MEC_BreakerBoxes"; \
    model = _MODEL_PATH; \
    hiddenSelections[] = {"Camo"}; \
    hiddenSelectionsTextures[] = {## _TEX_PATH ##}; \
    hiddenSelectionsMaterials[] = {## _MAT_PATH ##}; \
    descriptionShort = "MEC Power Conduit. Design: "_DESIGNATION ". Marked with " MEC_RLS_POWER ". Constructed using Layered, Insulated containment doctrine for zero-surge power transfer in extreme thermal environments."; \
}; \