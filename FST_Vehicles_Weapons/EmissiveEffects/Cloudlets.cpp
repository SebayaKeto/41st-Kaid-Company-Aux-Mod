class FST_VW_EmissiveCloudlet_Base: Default
{
    interval = 0.004;
    circleRadius = 0;
    circleVelocity[] = {0, 0, 0};
    particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
    particleFSNtieth = 16;
    particleFSIndex = 13;
    particleFSFrameCount = 2;
    particleFSLoop = 0;
    angleVar = 360;
    animationName = "";
    particleType = "Billboard";
    timerPeriod = 1;
    lifeTime = 0.08;
    moveVelocity[] = {0, 0, 0};
    rotationVelocity = 1;
    weight = 0.12;
    volume = 0.08;
    rubbing = 0.05;
    size[] = {0.12, 0};
    color[] = {{0.5, 0.8, 1, 0.18}, {0.5, 0.8, 1, 0.04}};
    colorCoef[] = {1, 1, 1, 1};
    emissiveColor[] = {{20, 32, 48, 1}};
    animationSpeed[] = {1};
    randomDirectionPeriod = 0;
    randomDirectionIntensity = 0;
    onTimerScript = "";
    beforeDestroyScript = "";
    blockAIVisibility = 0;
    bounceOnSurface = 0;
    bounceOnSurfaceVar = 0;
    lifeTimeVar = 0.02;
    position[] = {0, 0, 0};
    positionVar[] = {0, 0, 0};
    moveVelocityVar[] = {0.02, 0.02, 0.02};
    rotationVelocityVar = 0;
    sizeVar = 0.02;
    colorVar[] = {0.03, 0.03, 0.03, 0.03};
    randomDirectionPeriodVar = 0;
    randomDirectionIntensityVar = 0;
};

class FST_VW_EmissiveCloudlet_Bolt: FST_VW_EmissiveCloudlet_Base
{
    size[] = {0.1, 0};
    emissiveColor[] = {{25, 40, 65, 1}};
};

class FST_VW_EmissiveCloudlet_Bolt_10mm: FST_VW_EmissiveCloudlet_Bolt
{
    size[] = {0.08, 0};
    color[] = {{0.24, 0.52, 0.88, 0.16}, {0.24, 0.52, 0.88, 0.03}};
    emissiveColor[] = {{14, 26, 45, 1}};
};

class FST_VW_EmissiveCloudlet_Bolt_20mm: FST_VW_EmissiveCloudlet_Bolt
{
    size[] = {0.1, 0};
    color[] = {{0.25, 0.62, 0.98, 0.18}, {0.25, 0.62, 0.98, 0.03}};
    emissiveColor[] = {{20, 34, 55, 1}};
};

class FST_VW_EmissiveCloudlet_Bolt_30mm: FST_VW_EmissiveCloudlet_Bolt
{
    size[] = {0.12, 0};
    color[] = {{0.3, 0.72, 1, 0.2}, {0.3, 0.72, 1, 0.04}};
    emissiveColor[] = {{28, 44, 70, 1}};
};

class FST_VW_EmissiveCloudlet_Bolt_40mm: FST_VW_EmissiveCloudlet_Bolt
{
    size[] = {0.14, 0};
    color[] = {{0.42, 0.82, 1, 0.2}, {0.42, 0.82, 1, 0.04}};
    emissiveColor[] = {{35, 52, 82, 1}};
};

class FST_VW_EmissiveCloudlet_Missile: FST_VW_EmissiveCloudlet_Base
{
    interval = 0.007;
    lifeTime = 0.14;
    size[] = {0.22, 0};
    color[] = {{1, 0.72, 0.38, 0.16}, {1, 0.72, 0.38, 0.03}};
    emissiveColor[] = {{55, 26, 8, 1}};
};

class FST_VW_EmissiveCloudlet_Ordnance: FST_VW_EmissiveCloudlet_Base
{
    interval = 0.006;
    lifeTime = 0.1;
    size[] = {0.16, 0};
    color[] = {{0.9, 0.78, 0.42, 0.14}, {0.9, 0.78, 0.42, 0.03}};
    emissiveColor[] = {{40, 30, 10, 1}};
};
