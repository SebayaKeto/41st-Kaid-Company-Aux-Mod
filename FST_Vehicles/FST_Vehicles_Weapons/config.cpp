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
            "A3_Weapons_F"
        };
    };
};

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
