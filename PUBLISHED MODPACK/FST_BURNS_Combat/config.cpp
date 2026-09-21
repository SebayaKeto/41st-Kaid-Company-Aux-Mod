// Original BURNS combat profiles, designed from native engine settings.
// No copied LAMBS implementation, FSM, assets or dependencies are included.
// Separate PBO so these fixed native profiles can be rolled back independently.
class CfgPatches {
    class FST_BURNS_Combat {
        name="BURNS Native Combat Profiles";
        author="41st Elite Corps";
        requiredVersion=2.18;
        requiredAddons[]={"FST_HCSpawn","A3_Weapons_F","A3_Weapons_F_Exp_Launchers_RPG7","A3_Weapons_F_Tank_Launchers_MRAWS","FST_EWEB_Mod","41st_Weapons_Vehicle","FST_Ammo","FST_Launchers"};
        units[]={}; weapons[]={};
    };
};
class Mode_FullAuto;
class Mode_SemiAuto;
class CfgWeapons {
    class MGun;
    class LMG_RCWS: MGun { aiDispersionCoefX=6; aiDispersionCoefY=4; };
    class HMG_127: LMG_RCWS { aiDispersionCoefX=6; aiDispersionCoefY=4; };
    class OPTRE_M247T_Coax;
    class FST_EWEB_RemoteTurret: OPTRE_M247T_Coax { aiDispersionCoefX=6; aiDispersionCoefY=4; };
    class FST_EWEB_MountedTurret: FST_EWEB_RemoteTurret {
        aiDispersionCoefX=6; aiDispersionCoefY=4;
        class FullAuto: Mode_FullAuto {
            // Correct the old ten-kilometre AI engagement curve. This is NOT an
            // Umbara fog limit: a visible target remains engageable to 900 m.
            minRange=5; minRangeProbab=0.55;
            midRange=250; midRangeProbab=0.8;
            maxRange=900; maxRangeProbab=0.05;
            aiRateOfFire=1; aiRateOfFireDistance=300;
            aiBurstTerminable=1;
        };
    };
    class Launcher_Base_F;
    class launch_RPG7_F: Launcher_Base_F {
        aiDispersionCoefX=3; aiDispersionCoefY=2;
        class Single: Mode_SemiAuto { aiRateOfFire=2; aiRateOfFireDistance=300; };
    };
    class IDA_RPS6HP;
    class FST_RPS6HP: IDA_RPS6HP {
        class Single: Mode_SemiAuto {
            minRange=60; minRangeProbab=0.65;
            midRange=200; midRangeProbab=0.95;
            maxRange=600; maxRangeProbab=0.2;
            aiRateOfFire=2; aiRateOfFireDistance=300;
        };
    };
};
class CfgAmmo {
    class RocketBase;
    // Native flags: infantry 64, light vehicles 128, aircraft 256, armour 512.
    // No synthetic targets, lock-on guidance, ammunition grants or forced shots.
    class R_PG7_F: RocketBase { allowAgainstInfantry=1; aiAmmoUsageFlags=960; airLock=1; cost=12; };
    class R_PG32V_F: RocketBase { allowAgainstInfantry=1; aiAmmoUsageFlags=960; airLock=1; cost=12; };
    class R_TBG32V_F: R_PG32V_F { allowAgainstInfantry=1; aiAmmoUsageFlags=448; airLock=1; };
    class R_MRAAWS_HEAT_F: RocketBase { allowAgainstInfantry=1; aiAmmoUsageFlags=704; cost=70; };
    class R_MRAAWS_HE_F: R_MRAAWS_HEAT_F { aiAmmoUsageFlags=192; cost=50; };
    class M_SPG9_HEAT: RocketBase { allowAgainstInfantry=1; aiAmmoUsageFlags=704; cost=70; };
    class M_SPG9_HE: M_SPG9_HEAT { aiAmmoUsageFlags=192; cost=50; };
    class FST_rocket: R_PG32V_F { allowAgainstInfantry=1; aiAmmoUsageFlags=960; airLock=1; cost=12; };
    class FST_rocket_HE: R_PG32V_F { allowAgainstInfantry=1; aiAmmoUsageFlags=192; airLock=0; cost=8; };
};
