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
    discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
    discreteDistanceInitIndex = 2;
    discreteDistanceCameraPoint = "eye";
    class manual: Mode_FullAuto
    {
        sounds[] = {"StandardSound"};
        class BaseSoundModeType;
        class StandardSound: BaseSoundModeType
        {
            soundSetShot[] = {"3AS_saber30_Shot_SoundSet"};
        };
    };
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
