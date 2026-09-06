class FST_VW_40mm_HE_Grenade: GrenadeBase
{
    effectFly = "FST_VW_FX_Emissive_Ordnance";
    explosionEffects = "3AS_ImpactPlasma";
    lightColor[] = {0.95, 0.8, 0.3};
    tracerStartTime = 0;
    tracerEndTime = 2;
    tracerScale = 0.8;
    hit = 80;
    indirectHit = 20;
    indirectHitRange = 4;
    timeToLive = 20;
    ace_frag_enabled = 1;
    ace_frag_metal = 160;
    ace_frag_charge = 55;
    ace_frag_gurney_c = 2440;
};

class FST_VW_40mm_HEDP_Grenade: GrenadeBase
{
    effectFly = "FST_VW_FX_Emissive_Ordnance";
    explosionEffects = "3AS_ImpactPlasma";
    lightColor[] = {1, 0.72, 0.24};
    tracerStartTime = 0;
    tracerEndTime = 2;
    tracerScale = 0.8;
    hit = 110;
    indirectHit = 14;
    indirectHitRange = 2.6;
    timeToLive = 20;
    ace_frag_enabled = 1;
    ace_frag_metal = 120;
    ace_frag_charge = 75;
    ace_frag_gurney_c = 2440;
};

class FST_VW_40mm_Airburst_Grenade: GrenadeBase
{
    effectFly = "FST_VW_FX_Emissive_Ordnance";
    explosionEffects = "3AS_ImpactPlasma";
    lightColor[] = {1, 0.88, 0.44};
    tracerStartTime = 0;
    tracerEndTime = 2;
    tracerScale = 0.8;
    hit = 62;
    indirectHit = 45;
    indirectHitRange = 6;
    timeToLive = 3;
    ace_frag_enabled = 1;
    ace_frag_metal = 190;
    ace_frag_charge = 70;
    ace_frag_gurney_c = 2440;
};

class FST_VW_40mm_Smoke_Grenade: GrenadeBase
{
    effectFly = "FST_VW_FX_Emissive_Ordnance";
    lightColor[] = {0.9, 0.9, 0.9};
    tracerStartTime = 0;
    tracerEndTime = 2;
    tracerScale = 0.6;
    hit = 1;
    indirectHit = 0;
    indirectHitRange = 0;
    timeToLive = 35;
    smokeColor[] = {0.9, 0.9, 0.9, 0.9};
};
