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
#define MEC_CONDUIT_MODEL_BASE "FST\FST_MEC\FST_MEC_PowerConduit"
#define MEC_CONDUIT_TEXTURE_PATH "FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\"
#define MEC_POWERSYSTEM_BREAKERBOX_CLASS(_NAME, _MODEL_SUFFIX, _DESIGNATION, _TEX_NAME, _MAT_NAME) \
class _NAME : House_F \
{ \
    scope = 2; \
    scopeCurator = 2; \
    displayName = _DESIGNATION; \
    author = MEC_FULL_NAME; \
    simulation = "static"; \
    destructType = "DestructNo"; \
    editorCategory = "FST_MEC_CategoryPowerSystems"; \
    editorSubcategory = "FST_MEC_BreakerBoxes"; \
    model = MEC_CONDUIT_MODEL_BASE _MODEL_SUFFIX; \
    hiddenSelections[] = {"Camo"}; \
    hiddenSelectionsTextures[] = \
    { \
        MEC_CONDUIT_TEXTURE_PATH _TEX_NAME; \
    }; \
    hiddenSelectionsMaterials[] = \
    { \
        MEC_CONDUIT_TEXTURE_PATH _MAT_NAME; \
    }; \
    \
    descriptionShort = "MEC Power Conduit. Design: "_DESIGNATION ". Marked with " MEC_RLS_POWER ". Constructed using Layered, Insulated containment doctrine for zero-surge power transfer in extreme thermal environments."; \
} \

class House_F; // Base class for Breaker Boxes