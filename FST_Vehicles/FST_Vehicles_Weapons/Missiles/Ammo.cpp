class FST_VW_AT_Missile: MissileBase
{
    effectFly = "FST_VW_FX_Emissive_Missile";
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
    maxSpeed = 460;
    maneuvrability = 20;
    laserLock = 1;
    irLock = 0;
    airLock = 1;
    nvLock = 0;
    missileLockCone = 35;
    missileLockMaxDistance = 5000;
    missileLockMinDistance = 100;
    weaponLockSystem = 2;
    trackOversteer = 1;
    trackLead = 0.9;
};

class FST_VW_ATGM_Tandem_Missile: MissileBase
{
    effectFly = "FST_VW_FX_Emissive_Missile";
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
