class FST_VW_BoltCannon_10mm: CannonCore
{
    scope = 1;
    displayName = "FST 10mm Bolt Cannon";
    magazines[] = {"FST_VW_2000Rnd_10mm_Ball_Bolts"};
};

class FST_VW_BoltCannon_20mm: CannonCore
{
    scope = 1;
    displayName = "FST 20mm Bolt Cannon";
    magazines[] = {"FST_VW_900Rnd_20mm_AP_Bolts"};
};

class FST_VW_BoltCannon_30mm: CannonCore
{
    scope = 1;
    displayName = "FST 30mm Bolt Cannon";
    magazines[] = {"FST_VW_120Rnd_30mm_HE_Bolts"};
};

class FST_VW_Sabre_30mm_Cannon: FST_VW_BoltCannon_30mm
{
    displayName = "FST Sabre 30mm Cannon";
    autoFire = 1;
    reloadTime = 1;
    burst = 1;
    magazines[] =
    {
        "FST_VW_120Rnd_30mm_HE_Bolts",
        "FST_VW_120Rnd_30mm_AP_Bolts"
    };
};

class FST_VW_BoltCannon_40mm: CannonCore
{
    scope = 1;
    displayName = "FST 40mm Bolt Cannon";
    magazines[] = {"FST_VW_60Rnd_40mm_HEI_Bolts"};
};
