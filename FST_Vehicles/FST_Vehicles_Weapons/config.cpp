class CfgPatches
{
    class FST_Vehicles_Weapons
    {
        units[] = {};
        weapons[] = {};
        magazines[] = {};
        ammo[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "A3_Data_F",
            "A3_Weapons_F",
            "3AS_VehicleWeapons"
        };
    };
};

class CfgLights
{
    #include "EmissiveEffects\Lights.cpp"
};

class CfgCloudlets
{
    class Default;

    #include "EmissiveEffects\Cloudlets.cpp"
};

#include "EmissiveEffects\Effects.cpp"

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class BaseSoundModeType;
class SlotInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;

class CfgAmmo
{
    // Common Arma ammo bases used by this module.
    class BulletBase;
    class MissileBase;
    class RocketBase;
    class ShellBase;
    class Sh_120mm_HE;
    class SmokeShell;
    class GrenadeBase;
    class 3AS_PlasmaBase;
    class 3AS_Sabre_HE;
    class 3AS_Sabre_AT;
    class 3as_saber_GMG_ammo;

    #include "Bolts\Ammo.cpp"
    #include "Missiles\Ammo.cpp"
    #include "Rockets\Ammo.cpp"
    #include "MortarShells\Ammo.cpp"
    #include "Smokes\Ammo.cpp"
    #include "Grenades\Ammo.cpp"
    #include "Miscellaneous\Ammo.cpp"
};

class CfgWeapons
{
    // Common Arma weapon bases used by this module.
    class CannonCore;
    class MissileLauncher;
    class RocketPods;
    class GrenadeLauncher;
    class SmokeLauncher;
    class 3AS_Sabre_MG;
    class 3AS_Sabre_Cannons;
    class 3as_saber_gmg_40mm;
    class 3AS_Sabre_Missiles;

    #include "Bolts\Weapons.cpp"
    #include "Missiles\Weapons.cpp"
    #include "Rockets\Weapons.cpp"
    #include "MortarShells\Weapons.cpp"
    #include "Smokes\Weapons.cpp"
    #include "Grenades\Weapons.cpp"
    #include "Miscellaneous\Weapons.cpp"
};

class CfgMagazines
{
    // Common Arma magazine bases used by this module.
    class CA_Magazine;
    class VehicleMagazine: CA_Magazine {};

    #include "Bolts\Magazines.cpp"
    #include "Missiles\Magazines.cpp"
    #include "Rockets\Magazines.cpp"
    #include "MortarShells\Magazines.cpp"
    #include "Smokes\Magazines.cpp"
    #include "Grenades\Magazines.cpp"
    #include "Miscellaneous\Magazines.cpp"
};
