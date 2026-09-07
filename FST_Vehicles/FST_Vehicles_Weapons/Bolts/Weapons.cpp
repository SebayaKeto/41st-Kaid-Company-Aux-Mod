class FST_VW_BoltCannon_10mm: 3AS_Sabre_MG
{
    scope = 1;
    displayName = "FST 10mm Bolt Cannon";
    magazines[] = {"FST_VW_2000Rnd_10mm_Ball_Bolts"};
};

class FST_VW_BoltCannon_20mm: 3AS_Sabre_MG
{
    scope = 1;
    displayName = "FST 20mm Bolt Cannon";
    magazines[] = {"FST_VW_900Rnd_20mm_AP_Bolts"};
};

class FST_VW_BoltCannon_30mm: 3AS_Sabre_Cannons
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
    discreteDistanceCameraPoint = "gunnerview";
    magazines[] = {"FST_VW_120Rnd_30mm_HE_Bolts"};
    modes[] = {"manual","close","short","medium","far"};
    class manual: MGun
    {
        displayName = "$STR_A3_LMG_RCWS0";
        sounds[] = {"StandardSound"};
        class StandardSound
        {
            soundSetShot[] = {"FST_Sabre_MainCannon_EWEB_SoundSet"};
        };
        soundContinuous = 0;
        soundBurst = 0;
        reloadTime = 0.5;
        dispersion = 0.0016;
        aiRateOfFire = 1;
        aiRateOfFireDistance = 10;
        minRange = 0;
        minRangeProbab = 0.01;
        midRange = 1;
        midRangeProbab = 0.01;
        maxRange = 2;
        maxRangeProbab = 0.01;
    };
    class close: manual
    {
        aiBurstTerminable = 1;
        showToPlayer = 0;
        burst = 8;
        burstRangeMax = 16;
        aiRateOfFire = 0.5;
        aiRateOfFireDispersion = 2;
        aiRateOfFireDistance = 50;
        minRange = 0;
        minRangeProbab = 0.8;
        midRange = 20;
        midRangeProbab = 0.7;
        maxRange = 50;
        maxRangeProbab = 0.2;
    };
    class short: close
    {
        burst = 6;
        burstRangeMax = 12;
        aiRateOfFire = 1;
        aiRateOfFireDistance = 150;
        minRange = 20;
        minRangeProbab = 0.7;
        midRange = 150;
        midRangeProbab = 0.7;
        maxRange = 300;
        maxRangeProbab = 0.2;
    };
    class medium: close
    {
        burst = 3;
        burstRangeMax = 12;
        aiRateOfFire = 2;
        aiRateOfFireDistance = 250;
        minRange = 150;
        minRangeProbab = 0.7;
        midRange = 600;
        midRangeProbab = 0.65;
        maxRange = 800;
        maxRangeProbab = 0.1;
    };
    class far: close
    {
        burst = 3;
        burstRangeMax = 8;
        aiRateOfFire = 4;
        aiRateOfFireDispersion = 4;
        aiRateOfFireDistance = 600;
        minRange = 600;
        minRangeProbab = 0.65;
        midRange = 800;
        midRangeProbab = 0.4;
        maxRange = 1200;
        maxRangeProbab = 0.1;
    };
};

class FST_VW_Sabre_30mm_AP_Cannon: FST_VW_Sabre_30mm_Cannon
{
    displayName = "FST Sabre 30mm AP Cannon";
    autoFire = 1;
    reloadTime = 1;
    burst = 1;
    discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
    discreteDistanceInitIndex = 2;
    discreteDistanceCameraPoint = "gunnerview";
    magazines[] = {"FST_VW_120Rnd_30mm_AP_Bolts"};
};

class FST_VW_Sabre_Commander_MG: 3AS_Sabre_MG
{
    displayName = "FST Sabre Commander MG";
    discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
    discreteDistanceInitIndex = 2;
    discreteDistanceCameraPoint = "commanderview";
    magazines[] = {"3AS_300Rnd_SabreMG_Mag"};
    modes[] = {"manual","close","short","medium","far"};
    class manual: MGun
    {
        displayName = "$STR_A3_LMG_RCWS0";
        sounds[] = {"StandardSound"};
        class StandardSound
        {
            soundSetShot[] = {"FST_Sabre_Commander_MG_SoundSet"};
        };
        soundContinuous = 0;
        soundBurst = 0;
        reloadTime = 0.105;
        dispersion = 0.0016;
        aiRateOfFire = 1;
        aiRateOfFireDistance = 10;
        minRange = 0;
        minRangeProbab = 0.01;
        midRange = 1;
        midRangeProbab = 0.01;
        maxRange = 2;
        maxRangeProbab = 0.01;
    };
    class close: manual
    {
        aiBurstTerminable = 1;
        showToPlayer = 0;
        burst = 8;
        burstRangeMax = 16;
        aiRateOfFire = 0.5;
        aiRateOfFireDispersion = 2;
        aiRateOfFireDistance = 50;
        minRange = 0;
        minRangeProbab = 0.8;
        midRange = 20;
        midRangeProbab = 0.7;
        maxRange = 50;
        maxRangeProbab = 0.2;
    };
    class short: close
    {
        burst = 6;
        burstRangeMax = 12;
        aiRateOfFire = 1;
        aiRateOfFireDistance = 150;
        minRange = 20;
        minRangeProbab = 0.7;
        midRange = 150;
        midRangeProbab = 0.7;
        maxRange = 300;
        maxRangeProbab = 0.2;
    };
    class medium: close
    {
        burst = 3;
        burstRangeMax = 12;
        aiRateOfFire = 2;
        aiRateOfFireDistance = 250;
        minRange = 150;
        minRangeProbab = 0.7;
        midRange = 600;
        midRangeProbab = 0.65;
        maxRange = 800;
        maxRangeProbab = 0.1;
    };
    class far: close
    {
        burst = 3;
        burstRangeMax = 8;
        aiRateOfFire = 4;
        aiRateOfFireDispersion = 4;
        aiRateOfFireDistance = 600;
        minRange = 600;
        minRangeProbab = 0.65;
        midRange = 800;
        midRangeProbab = 0.4;
        maxRange = 1200;
        maxRangeProbab = 0.1;
    };
};

class FST_VW_BoltCannon_40mm: 3as_saber_gmg_40mm
{
    scope = 1;
    displayName = "FST 40mm Bolt Cannon";
    magazines[] = {"FST_VW_60Rnd_40mm_HEI_Bolts"};
};
