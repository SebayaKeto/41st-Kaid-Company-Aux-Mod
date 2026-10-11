/*
    FST IDA ACE Medical Compatibility Patch v3 (plasma wound mix B2, 10 Oct 2026)

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
        name = "FST IDA ACE Medical Compatibility v3";
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
            // v3 (10 Oct 2026). Command: "more wounds, more often, more variety"; Miran: "we dont really want to
            // change overall durability". Profile B2: nearly every hit wounds (1-2 wounds, 8 wound types), but trauma per
            // hit stays as v2 (+-11% in the ACE model, engine-verified): light hits mostly make grazes (Abrasion / Cut with
            // damageMultiplier 0.05) that need bandaging but barely count toward knock-down / death. ACE splits a hit's
            // damage across its wounds, so wound count alone does not add trauma. Bleeding ~1.3-2x v2, far below ACE's
            // blood-loss knock-out rate.
            // v4 (11 Oct 2026), after the first op on B2. Platoon/SL feedback: "Felt more pain knocks" and
            // "Bleeding increase a smidge, like 5% or maybe 10% ... but doesn't kill those with smaller wounds".
            // Pain knocks are off on Main (painUnconsciousChance 0) and B2 did not raise damage knock-downs (model), but
            // light hits carried 1.7x v2 pain: grazes (Abrasion) pain x0.25 -> light-hit pain back to v2. Big wounds
            // (Laceration/Puncture/Avulsion/Velocity) bleed x1.1 -> +8-11% bleeding on medium/heavy hits; grazes
            // (Abrasion/Cut) bleed x0.7. Trauma, wound count, types and knock-downs unchanged from v3.
            thresholds[] =
            {
                {20, 10},
                {4.5, 4},
                {2, 3},
                {1.0, 2},
                {0.1, 1},
                {0, 0}
            };
            selectionSpecific = 1;

            // IMPORTANT: Do not inherit from root woundHandlers here.
            // We want only the base ACE wound creator for this IDA plasma type.
            class woundHandlers
            {
                ace_medical_damage = "ace_medical_damage_fnc_woundsHandlerBase";
            };

            class ThermalBurn
            {
                weighting[] =
                {
                    {2.0, 3.0},
                    {0.35, 1.6},
                    {0.15, 1.0},
                    {0, 0.3}
                };
                sizeMultiplier = 1.15;
                painMultiplier = 1.0;
            };
            class Laceration
            {
                weighting[] =
                {
                    {1.0, 0.6},
                    {0.25, 0.6},
                    {0.1, 0.2},
                    {0, 0}
                };
                bleedingMultiplier = 1.1;
            };
            class PunctureWound
            {
                weighting[] =
                {
                    {1.0, 0.6},
                    {0.25, 0.45},
                    {0.1, 0.1},
                    {0, 0}
                };
                bleedingMultiplier = 1.1;
            };
            class Avulsion
            {
                weighting[] =
                {
                    {2.0, 1.4},
                    {0.75, 0.8},
                    {0.25, 0.35},
                    {0.1, 0.05},
                    {0, 0}
                };
                bleedingMultiplier = 1.1;
            };
            class VelocityWound
            {
                weighting[] =
                {
                    {1.5, 0.9},
                    {0.5, 0.45},
                    {0.15, 0.2},
                    {0, 0}
                };
                sizeMultiplier = 0.85;
                bleedingMultiplier = 1.1;
            };
            // grazes: common on light hits, trivial trauma (damageMultiplier), still need a bandage
            class Abrasion
            {
                weighting[] =
                {
                    {0.25, 0},
                    {0.15, 1.5},
                    {0, 4.0}
                };
                damageMultiplier = 0.05;
                painMultiplier = 0.25;
                bleedingMultiplier = 0.7;
            };
            class Cut
            {
                weighting[] =
                {
                    {0.25, 0},
                    {0.15, 1.2},
                    {0, 3.2}
                };
                damageMultiplier = 0.05;
                bleedingMultiplier = 0.7;
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
