class FST_VW_FX_Emissive_Bolt
{
    class Light
    {
        simulation = "light";
        type = "FST_VW_EmissiveLight_Bolt";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
    };

    class Trail
    {
        simulation = "particles";
        type = "FST_VW_EmissiveCloudlet_Bolt";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
    };
};

class FST_VW_FX_Emissive_Bolt_10mm: FST_VW_FX_Emissive_Bolt
{
    class Light: Light
    {
        type = "FST_VW_EmissiveLight_Bolt_10mm";
    };

    class Trail: Trail
    {
        type = "FST_VW_EmissiveCloudlet_Bolt_10mm";
    };
};

class FST_VW_FX_Emissive_Bolt_20mm: FST_VW_FX_Emissive_Bolt
{
    class Light: Light
    {
        type = "FST_VW_EmissiveLight_Bolt_20mm";
    };

    class Trail: Trail
    {
        type = "FST_VW_EmissiveCloudlet_Bolt_20mm";
    };
};

class FST_VW_FX_Emissive_Bolt_30mm: FST_VW_FX_Emissive_Bolt
{
    class Light: Light
    {
        type = "FST_VW_EmissiveLight_Bolt_30mm";
    };

    class Trail: Trail
    {
        type = "FST_VW_EmissiveCloudlet_Bolt_30mm";
    };
};

class FST_VW_FX_Emissive_Bolt_40mm: FST_VW_FX_Emissive_Bolt
{
    class Light: Light
    {
        type = "FST_VW_EmissiveLight_Bolt_40mm";
    };

    class Trail: Trail
    {
        type = "FST_VW_EmissiveCloudlet_Bolt_40mm";
    };
};

class FST_VW_FX_Emissive_Missile
{
    class Light
    {
        simulation = "light";
        type = "FST_VW_EmissiveLight_Missile";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
    };

    class Trail
    {
        simulation = "particles";
        type = "FST_VW_EmissiveCloudlet_Missile";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
    };
};

class FST_VW_FX_Emissive_Ordnance
{
    class Light
    {
        simulation = "light";
        type = "FST_VW_EmissiveLight_Ordnance";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
    };

    class Trail
    {
        simulation = "particles";
        type = "FST_VW_EmissiveCloudlet_Ordnance";
        position[] = {0, 0, 0};
        intensity = 1;
        interval = 1;
    };
};
