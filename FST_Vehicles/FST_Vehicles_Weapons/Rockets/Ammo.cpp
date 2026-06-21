class FST_VW_HE_Rocket: RocketBase
{
    effectFly = "FST_VW_FX_Emissive_Missile";
    lightColor[] = {1, 0.46, 0.15};
    hit = 180;
    indirectHit = 30;
    indirectHitRange = 4;
    maxSpeed = 320;
    thrustTime = 1.2;
    thrust = 140;
    ace_frag_enabled = 1;
    ace_frag_metal = 1000;
    ace_frag_charge = 420;
    ace_frag_gurney_c = 2440;
};

class FST_VW_AT_Rocket: RocketBase
{
    effectFly = "FST_VW_FX_Emissive_Missile";
    lightColor[] = {1, 0.5, 0.16};
    hit = 280;
    indirectHit = 16;
    indirectHitRange = 1.4;
    maxSpeed = 340;
    thrustTime = 1.4;
    thrust = 165;
    ace_frag_enabled = 1;
    ace_frag_metal = 900;
    ace_frag_charge = 780;
    ace_frag_gurney_c = 2440;
};

class FST_VW_Thermobaric_Rocket: RocketBase
{
    effectFly = "FST_VW_FX_Emissive_Missile";
    lightColor[] = {1, 0.58, 0.2};
    hit = 230;
    indirectHit = 95;
    indirectHitRange = 8;
    maxSpeed = 300;
    thrustTime = 1.5;
    thrust = 145;
    ace_frag_enabled = 1;
    ace_frag_metal = 550;
    ace_frag_charge = 1150;
    ace_frag_gurney_c = 2440;
};

class FST_VW_Illum_Rocket: RocketBase
{
    effectFly = "FST_VW_FX_Emissive_Ordnance";
    lightColor[] = {1, 0.85, 0.42};
    hit = 5;
    indirectHit = 0;
    indirectHitRange = 0;
    maxSpeed = 260;
    thrustTime = 0.8;
    thrust = 110;
    timeToLive = 45;
};
