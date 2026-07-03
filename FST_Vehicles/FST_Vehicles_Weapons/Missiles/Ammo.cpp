class FST_VW_AT_Missile: MissileBase
{
    effectFly = "FST_VW_FX_Emissive_Missile";
    explosionEffects = "3AS_ImpactPlasmaExplosion_Blue";
    lightColor[] = {1, 0.45, 0.12};
    hit = 350;
    indirectHit = 40;
    indirectHitRange = 2;
    maxSpeed = 420;
    thrustTime = 3;
    thrust = 180;
    maneuvrability = 22;
    ace_frag_enabled = 1;
    ace_frag_metal = 2500;
    ace_frag_charge = 900;
    ace_frag_gurney_c = 2440;
    manualControl = 1;
    maxControlRange = 5000;
    missileManualControlCone = 180;
};

class FST_VW_AT_LG_Missile: FST_VW_AT_Missile
{
    hit = 390;
    indirectHit = 32;
    indirectHitRange = 1.6;
    maxSpeed = 480;
    maneuvrability = 30;
    thrustTime = 3.2;
    thrust = 210;
    laserLock = 1;
    irLock = 0;
    airLock = 1;
    nvLock = 0;
    missileLockCone = 45;
    missileLockMaxDistance = 5000;
    missileLockMinDistance = 100;
    weaponLockSystem = 2;
    trackOversteer = 0.85;
    trackLead = 1.1;
};

class FST_VW_SabreAPC_LG_Submunition: Sh_120mm_HE
{
    explosionEffects = "3AS_ImpactPlasmaExplosion_Blue";
    hit = 300;
    indirectHit = 50;
    indirectHitRange = 3;
    caliber = 11;
    timeToLive = 0.2;
};

class FST_VW_SabreAPC_LG_Missile: MissileBase
{
    effectFly = "FST_VW_FX_Emissive_Missile";
    explosionEffects = "3AS_ImpactPlasmaExplosion_Blue";
    lightColor[] = {0.92, 0.72, 0.22};
    hit = 560;
    indirectHit = 72;
    indirectHitRange = 2.4;
    maxSpeed = 520;
    thrustTime = 3.4;
    thrust = 250;
    maneuvrability = 48;
    ace_frag_enabled = 1;
    ace_frag_metal = 3200;
    ace_frag_charge = 1220;
    ace_frag_gurney_c = 2440;
    manualControl = 1;
    maxControlRange = 5200;
    missileManualControlCone = 180;
    laserLock = 0;
    irLock = 0;
    airLock = 0;
    nvLock = 0;
    missileLockCone = 0;
    missileLockMaxDistance = 5200;
    missileLockMinDistance = 80;
    weaponLockSystem = 0;
    trackOversteer = 1.1;
    trackLead = 1.35;
    triggerOnImpact = 1;
    deleteParentWhenTriggered = 1;
    submunitionAmmo = "FST_VW_SabreAPC_LG_Submunition";
    submunitionDirectionType = "SubmunitionModelDirection";
    submunitionInitSpeed = 140;
    submunitionParentSpeedCoef = 0;
    submunitionConeType[] = {"randomcenter",6};
    submunitionConeAngle = 20;
    submunitionConeRadius = 1.4;
    submunitionConeHeight = 0.6;
};

class FST_VW_ATGM_Tandem_Missile: MissileBase
{
    effectFly = "FST_VW_FX_Emissive_Missile";
    explosionEffects = "3AS_ImpactPlasmaExplosion_Blue";
    lightColor[] = {1, 0.48, 0.16};
    hit = 520;
    indirectHit = 36;
    indirectHitRange = 1.6;
    maxSpeed = 360;
    thrustTime = 3.5;
    thrust = 175;
    maneuvrability = 18;
    ace_frag_enabled = 1;
    ace_frag_metal = 1700;
    ace_frag_charge = 1100;
    ace_frag_gurney_c = 2440;
    manualControl = 1;
    maxControlRange = 4500;
    missileManualControlCone = 180;
};

class FST_VW_AA_Missile: MissileBase
{
    effectFly = "FST_VW_FX_Emissive_Missile";
    explosionEffects = "3AS_ImpactPlasmaExplosion_Blue";
    lightColor[] = {1, 0.5, 0.2};
    hit = 180;
    indirectHit = 18;
    indirectHitRange = 1.2;
    maxSpeed = 850;
    thrustTime = 2.4;
    thrust = 330;
    maneuvrability = 42;
    ace_frag_enabled = 1;
    ace_frag_metal = 1200;
    ace_frag_charge = 500;
    ace_frag_gurney_c = 2440;
    manualControl = 1;
    maxControlRange = 6000;
    missileManualControlCone = 180;
};

class FST_VW_Cruise_Missile: MissileBase
{
    effectFly = "FST_VW_FX_Emissive_Missile";
    explosionEffects = "3AS_ImpactPlasmaExplosion_Blue";
    lightColor[] = {1, 0.55, 0.2};
    hit = 900;
    indirectHit = 130;
    indirectHitRange = 12;
    maxSpeed = 300;
    thrustTime = 14;
    thrust = 150;
    maneuvrability = 8;
    ace_frag_enabled = 1;
    ace_frag_metal = 8000;
    ace_frag_charge = 2800;
    ace_frag_gurney_c = 2440;
    manualControl = 1;
    maxControlRange = 8000;
    missileManualControlCone = 180;
};
