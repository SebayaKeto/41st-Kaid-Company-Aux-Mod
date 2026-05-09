/*
    FST IDA ACE Medical Compatibility Patch v2

    Purpose:
    - Temporary aux-side patch while IDA is being phased out.
    - Load after ACE medical damage and IDA_VFX.
    - Replace IDA plasma/plasmashell ACE damage types with a clean local
      woundHandlers class that does NOT inherit the global/default handler chain.
    - Bias plasma wounds back toward ThermalBurn / Avulsion and away from
      Contusion-only results.

    Why v2 exists:
    - v1 used `class woundHandlers: woundHandlers`, which can inherit handler
      entries added by other addons. If ace_medical_damage_fnc_woundsHandlerBase
      is not the final handler, ACE logs:
      Return for handler 'ace_medical_damage_woundsHandlerBase' invalid - '[]'
    - v2 uses a local `class woundHandlers` with only ACE's base wound handler.
*/

class CfgPatches
{
    class FST_IDA_ACE_Compat
    {
        author = "41st / FST";
        name = "FST IDA ACE Medical Compatibility v2";
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "ace_medical_damage",
            "IDA_VFX"
        };
        units[] = {};
        weapons[] = {};
        magazines[] = {};
    };
};

class ACE_Medical_Injuries
{
    class damageTypes
    {
        class plasma
        {
            // Similar wound counts to ACE bullet, but with a small low-end
            // no-wound chance so armor/near-misses do not create endless bruises.
            thresholds[] =
            {
                {20, 10},
                {4.5, 2},
                {2, 1},
                {0.35, 1},
                {0, 0}
            };
            selectionSpecific = 1;

            // IMPORTANT: Do not inherit from root woundHandlers here.
            // We want only the base ACE wound creator for this IDA plasma type.
            class woundHandlers
            {
                ace_medical_damage = "ace_medical_damage_fnc_woundsHandlerBase";
            };

            // Plasma should feel like hot penetrating energy, not mostly blunt trauma.
            class ThermalBurn
            {
                weighting[] =
                {
                    {2.0, 4.0},
                    {0.35, 2.5},
                    {0.05, 1.0},
                    {0, 0.5}
                };
                sizeMultiplier = 1.15;
                painMultiplier = 1.0;
            };
            class Avulsion
            {
                weighting[] =
                {
                    {2.0, 1.4},
                    {0.75, 0.8},
                    {0.25, 0.25},
                    {0, 0}
                };
            };
            class VelocityWound
            {
                weighting[] =
                {
                    {1.5, 0.9},
                    {0.5, 0.45},
                    {0.15, 0.15},
                    {0, 0}
                };
                sizeMultiplier = 0.85;
            };
            class Contusion
            {
                weighting[] =
                {
                    {1.0, 0.25},
                    {0.35, 0.15},
                    {0, 0.05}
                };
                sizeMultiplier = 1.2;
                painMultiplier = 0.8;
            };
        };

        class plasmashell
        {
            thresholds[] =
            {
                {20, 10},
                {10, 5},
                {4.5, 3},
                {2, 2},
                {0.8, 1},
                {0.2, 1},
                {0, 0}
            };
            selectionSpecific = 0;

            // Same local handler protection for shell/splash-style plasma.
            class woundHandlers
            {
                ace_medical_damage = "ace_medical_damage_fnc_woundsHandlerBase";
            };

            class ThermalBurn
            {
                weighting[] =
                {
                    {2.0, 3.5},
                    {0.8, 2.0},
                    {0.2, 0.8},
                    {0, 0.25}
                };
                sizeMultiplier = 1.25;
                painMultiplier = 0.95;
            };
            class Avulsion
            {
                weighting[] =
                {
                    {1.5, 1.4},
                    {1.1, 0.8},
                    {0.35, 0.2},
                    {0, 0}
                };
            };
            class VelocityWound
            {
                weighting[] =
                {
                    {1.5, 1.0},
                    {1.1, 0.7},
                    {0.35, 0.15},
                    {0, 0}
                };
            };
            class PunctureWound
            {
                weighting[] =
                {
                    {0.9, 0.45},
                    {0.35, 0.2},
                    {0, 0}
                };
            };
            class Cut
            {
                weighting[] =
                {
                    {0.7, 0.35},
                    {0.35, 0.15},
                    {0, 0}
                };
            };
            class Contusion
            {
                weighting[] =
                {
                    {0.8, 0.25},
                    {0.35, 0.1},
                    {0, 0.05}
                };
                sizeMultiplier = 1.4;
                painMultiplier = 0.8;
            };
        };
    };
};
