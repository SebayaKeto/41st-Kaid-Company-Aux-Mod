class FST_VW_EmissiveLight_Base
{
    color[] = {0, 0, 0, 0};
    diffuse[] = {18, 42, 90, 1};
    ambient[] = {0, 0, 0, 0.35};
    brightness = 6;
    intensity = 2200;
    drawLight = 0;
    dayLight = 1;
    useFlare = 1;
    flareSize = 0.28;
    flareMaxDistance = 4500;

    class Attenuation
    {
        start = 0;
        constant = 0;
        linear = 0;
        quadratic = 220;
        hardLimitStart = 45;
        hardLimitEnd = 120;
    };
};

class FST_VW_EmissiveLight_Bolt: FST_VW_EmissiveLight_Base
{
    diffuse[] = {26, 70, 145, 1};
    intensity = 2600;
};

class FST_VW_EmissiveLight_Bolt_10mm: FST_VW_EmissiveLight_Bolt
{
    diffuse[] = {20, 64, 125, 1};
    intensity = 2300;
    flareSize = 0.22;
};

class FST_VW_EmissiveLight_Bolt_20mm: FST_VW_EmissiveLight_Bolt
{
    diffuse[] = {24, 82, 160, 1};
    intensity = 2500;
    flareSize = 0.26;
};

class FST_VW_EmissiveLight_Bolt_30mm: FST_VW_EmissiveLight_Bolt
{
    diffuse[] = {36, 112, 190, 1};
    intensity = 2900;
    flareSize = 0.32;
};

class FST_VW_EmissiveLight_Bolt_40mm: FST_VW_EmissiveLight_Bolt
{
    diffuse[] = {54, 140, 230, 1};
    intensity = 3350;
    flareSize = 0.38;
};

class FST_VW_EmissiveLight_Missile: FST_VW_EmissiveLight_Base
{
    diffuse[] = {125, 62, 18, 1};
    intensity = 3100;
    flareSize = 0.4;
};

class FST_VW_EmissiveLight_Ordnance: FST_VW_EmissiveLight_Base
{
    diffuse[] = {110, 96, 38, 1};
    intensity = 2800;
    flareSize = 0.34;
};
