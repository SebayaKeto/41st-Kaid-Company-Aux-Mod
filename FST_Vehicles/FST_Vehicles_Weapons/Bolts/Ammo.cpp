class FST_VW_Bolt_10mm_Ball: 3AS_PlasmaBase
{
    effectFly = "FST_VW_FX_Emissive_Bolt_10mm";
    explosionEffects = "3AS_ImpactPlasma";
    tracerStartTime = 0;
    tracerEndTime = 8;
    tracerScale = 1.1;
    tracerColor[] = {0.2, 0.5, 0.9, 0.9};
    tracerColorR[] = {0.2, 0.5, 0.9, 0.9};
    lightColor[] = {0.18, 0.46, 0.86};
    hit = 18;
    indirectHit = 0;
    indirectHitRange = 0;
    caliber = 0.8;
    typicalSpeed = 900;
    airFriction = -0.0013;
    ACE_caliber = 10;
    ACE_bulletLength = 28.7;
    ACE_bulletMass = 11.8;
    ACE_muzzleVelocities[] = {780, 840, 900};
    ACE_barrelLengths[] = {254, 368, 508};
};

class FST_VW_Bolt_20mm_AP: 3AS_PlasmaBase
{
    effectFly = "FST_VW_FX_Emissive_Bolt_20mm";
    explosionEffects = "3AS_ImpactPlasma";
    tracerStartTime = 0;
    tracerEndTime = 10;
    tracerScale = 1.2;
    tracerColor[] = {0.22, 0.62, 1, 0.92};
    tracerColorR[] = {0.22, 0.62, 1, 0.92};
    lightColor[] = {0.2, 0.58, 0.98};
    hit = 42;
    indirectHit = 0;
    indirectHitRange = 0;
    caliber = 1.6;
    typicalSpeed = 1030;
    airFriction = -0.00095;
    ACE_caliber = 20;
    ACE_bulletLength = 100;
    ACE_bulletMass = 100;
    ACE_muzzleVelocities[] = {920, 980, 1030};
    ACE_barrelLengths[] = {700, 900, 1200};
};

class FST_VW_Bolt_30mm_HE: 3AS_Sabre_HE
{
    effectFly = "FST_VW_FX_Emissive_Bolt_30mm";
    tracerStartTime = 0;
    tracerEndTime = 10;
    tracerScale = 1.3;
    tracerColor[] = {0.3, 0.74, 1, 0.9};
    tracerColorR[] = {0.3, 0.74, 1, 0.9};
    lightColor[] = {0.28, 0.7, 1};
    hit = 75;
    indirectHit = 14;
    indirectHitRange = 1.8;
    caliber = 3.2;
    typicalSpeed = 1100;
    airFriction = -0.00072;
    ACE_caliber = 30;
    ACE_bulletLength = 173;
    ACE_bulletMass = 360;
    ACE_muzzleVelocities[] = {960, 1040, 1100};
    ACE_barrelLengths[] = {1200, 1600, 2000};
    ace_frag_enabled = 1;
    ace_frag_metal = 180;
    ace_frag_charge = 50;
    ace_frag_gurney_c = 2440;
};

class FST_VW_Bolt_30mm_AP: 3AS_Sabre_AT
{
    effectFly = "FST_VW_FX_Emissive_Bolt_30mm";
    tracerStartTime = 0;
    tracerEndTime = 10;
    tracerScale = 1.3;
    tracerColor[] = {0.28, 0.68, 1, 0.9};
    tracerColorR[] = {0.28, 0.68, 1, 0.9};
    lightColor[] = {0.24, 0.64, 1};
    hit = 275;
    indirectHit = 0;
    indirectHitRange = 0;
    caliber = 6.8;
    typicalSpeed = 1180;
    airFriction = -0.00068;
    ACE_caliber = 30;
    ACE_bulletLength = 173;
    ACE_bulletMass = 400;
    ACE_muzzleVelocities[] = {1020, 1110, 1180};
    ACE_barrelLengths[] = {1200, 1600, 2000};
};

class FST_VW_Bolt_40mm_HEI: 3as_saber_GMG_ammo
{
    effectFly = "FST_VW_FX_Emissive_Bolt_40mm";
    tracerStartTime = 0;
    tracerEndTime = 9;
    tracerScale = 1.4;
    tracerColor[] = {0.45, 0.84, 1, 0.88};
    tracerColorR[] = {0.45, 0.84, 1, 0.88};
    lightColor[] = {0.42, 0.8, 1};
    hit = 120;
    indirectHit = 26;
    indirectHitRange = 3.2;
    caliber = 4.2;
    typicalSpeed = 980;
    airFriction = -0.00066;
    ACE_caliber = 40;
    ACE_bulletLength = 223;
    ACE_bulletMass = 900;
    ACE_muzzleVelocities[] = {860, 920, 980};
    ACE_barrelLengths[] = {1600, 2000, 2400};
    ace_frag_enabled = 1;
    ace_frag_metal = 600;
    ace_frag_charge = 210;
    ace_frag_gurney_c = 2440;
};
