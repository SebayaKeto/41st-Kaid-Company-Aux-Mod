class CfgPatches
{
	class FST_Ammo
	{
		author="Gold";
		name="FST Ammo";
		requiRedAddons[]={"JLTS_weapons_core"};
		units[]={};
		magazines[]={};
		weapons[]={};
	};
};
class CfgFunctions {
    class FST {
        class EMP {
            file = "\41st_Ammo\functions";
            class onHit {};
            class onHitEMP {};
        };
    };
};
class Extended_HitPart_EventHandlers {
    class CAManBase {
		JLTS_weapons_core = "";
        FST_weapons_core = "if (JLTS_settings_EMP_mainSwitch == 1) then {(_this select 0) call FST_fnc_onHit;};";
    };
};

class CfgSoundShaders
{
    class FST_GrenadeEMP_Exp_SoundShader
    {
        samples[] = {
			{"\41st_Weapons\Grenades\Data\droidpopper.ogg",3,0.9},
			{"\41st_Weapons\Grenades\Data\droidpopper.ogg",3,1.0},
			{"\41st_Weapons\Grenades\Data\droidpopper.ogg",3,1.1},
			{"\41st_Weapons\Grenades\Data\droidpopper.ogg",3,1.2},
		};
        volume = 3;
        range = 150;
        rangeCurve = "InverseSquare2Curve";
    };
};
class CfgSoundSets
{
    class FST_GrenadeEMP_Exp_SoundSet
    {
        soundShaders[] = {"FST_GrenadeEMP_Exp_SoundShader"};
        volumeFactor = 3;
        frequencyRandomizer = 1;
        frequencyFactor = 1;
        spatial = 1;
        doppler = 0;
        loop = 0;
    };
};
class CfgAmmo
{
	class BulletBase;
	class IDA_blasterbolt;
	class FST_blasterbolt: IDA_Blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		ACE_damageType="plasma";
		cartridge="";
		lightcolor[]={0,0.30000001,1};
		hit=28; //28
		indirectHit=0;
		explosive=1;
		indirectHitRange=0.5;
		caliber=1.8; //1.6
		coefGravity=0.02;
		timetolive=6;
		waterFriction=-0.0099999998;
		deflecting=0;
		airfriction=0;
		tracerstarttime=0.050000001;
		tracerendtime=10;
		nvgonly=0;
		airlock=1;
		irtarget=1;
		brightness=1000;
		flaresize=5;
		tracerscale=1;
		effectflare="FlareShell";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		ExplosionEffects="IDA_ImpactEffect";
		cratereffects="";
		class HitEffects
		{
			Hit_Foliage_Green="IDA_ImpactEffect";
			Hit_Foliage_Dead="IDA_ImpactEffect";
			Hit_Foliage_Green_big="IDA_ImpactEffect";
			Hit_Foliage_Palm="IDA_ImpactEffect";
			Hit_Foliage_Pine="IDA_ImpactEffect";
			hitFoliage="IDA_ImpactEffect";
			hitGlass="IDA_ImpactEffect";
			hitGlassArmoRed="IDA_ImpactEffect";
			hitWood="IDA_ImpactEffect";
			hitMetal="IDA_ImpactEffect";
			hitMetalPlate="IDA_ImpactEffect";
			hitBuilding="IDA_ImpactEffect";
			hitPlastic="IDA_ImpactEffect";
			hitRubber="IDA_ImpactEffect";
			hitTyre="IDA_ImpactEffect";
			hitConcrete="IDA_ImpactEffect";
			hitMan="IDA_ImpactEffect";
			hitGroundSoft="IDA_ImpactEffect";
			hitGroundRed="IDA_ImpactEffect";
			hitGroundHard="IDA_ImpactEffect";
			hitWater="IDA_ImpactEffect";
			hitVirtual="IDA_ImpactEffect";
			default_mat="IDA_ImpactEffect";
		};
		soundHitBody1[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_1.ogg",
			3,
			1,
			200
		};
		soundHitBody2[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_2.ogg",
			3,
			1,
			200
		};
		soundHitBody3[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_3.ogg",
			3,
			1,
			200
		};
		soundHitBody4[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_4.ogg",
			3,
			1,
			200
		};
		soundHitBody5[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_5.ogg",
			3,
			1,
			200
		};
		hitMan[]=
		{
			"soundHitBody1",
			0.1,
			"soundHitBody2",
			0.1,
			"soundHitBody3",
			0.1,
			"soundHitBody4",
			0.1,
			"soundHitBody5",
			0.1,
		};
		soundDefault1[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_1.ogg",
			2,
			1,
			165
		};
		soundDefault2[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_2.ogg",
			2,
			1,
			165
		};
		soundDefault3[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_3.ogg",
			2,
			1,
			165
		};
		soundDefault4[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_4.ogg",
			2,
			1,
			165
		};
		soundDefault5[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_5.ogg",
			2,
			1,
			165
		};
		hitDefault[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
		};
		hitFoliage[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
		};
		hitPlastic[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
		};
		hitRubber[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
		};
		hitTyre[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
		};
		hitWood[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
		};
		hitBuilding[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
		};
		soundHit1[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_1.ogg",
			2,
			1,
			165
		};
		soundHit2[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_2.ogg",
			2,
			1,
			165
		};
		soundHit3[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_3.ogg",
			2,
			1,
			165
		};
		soundHit4[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_4.ogg",
			2,
			1,
			165
		};
		soundHit5[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_5.ogg",
			2,
			1,
			165
		};
		hitGround[]=
		{
			"soundHit1",
			0.090899996,
			"soundHit2",
			0.090899996,
			"soundHit3",
			0.090899996,
			"soundHit4",
			0.090899996,
			"soundHit5",
			0.090899996,
		};
		hitGroundHard[]=
		{
			"soundHit1",
			0.090899996,
			"soundHit2",
			0.090899996,
			"soundHit3",
			0.090899996,
			"soundHit4",
			0.090899996,
			"soundHit5",
			0.090899996,
		};
		hitGroundSoft[]=
		{
			"soundHit1",
			0.090899996,
			"soundHit2",
			0.090899996,
			"soundHit3",
			0.090899996,
			"soundHit4",
			0.090899996,
			"soundHit5",
			0.090899996,
		};
		hitConcrete[]=
		{
			"soundHit1",
			0.090899996,
			"soundHit2",
			0.090899996,
			"soundHit3",
			0.090899996,
			"soundHit4",
			0.090899996,
			"soundHit5",
			0.090899996,
		};
		soundMetal1[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_1.ogg",
			2,
			1,
			165
		};
		soundMetal2[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_2.ogg",
			2,
			1,
			165
		};
		soundMetal3[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_3.ogg",
			2,
			1,
			165
		};
		soundMetal4[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_4.ogg",
			2,
			1,
			165
		};
		soundMetal5[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_5.ogg",
			2,
			1,
			165
		};
		hitMetal[]=
		{
			"soundMetal1",
			0.066600002,
			"soundMetal2",
			0.066600002,
			"soundMetal3",
			0.066600002,
			"soundMetal4",
			0.066600002,
			"soundMetal5",
			0.066600002,
		};
		hitIron[]=
		{
			"soundMetal1",
			0.066600002,
			"soundMetal2",
			0.066600002,
			"soundMetal3",
			0.066600002,
			"soundMetal4",
			0.066600002,
			"soundMetal5",
			0.066600002,
		};
		hitMetalInt[]=
		{
			"soundMetal1",
			0.066600002,
			"soundMetal2",
			0.066600002,
			"soundMetal3",
			0.066600002,
			"soundMetal4",
			0.066600002,
			"soundMetal5",
			0.066600002,
		};
		hitMetalPlate[]=
		{
			"soundMetal1",
			0.066600002,
			"soundMetal2",
			0.066600002,
			"soundMetal3",
			0.066600002,
			"soundMetal4",
			0.066600002,
			"soundMetal5",
			0.066600002,
		};
		hitArmor[]=
		{
			"soundMetal1",
			0.066600002,
			"soundMetal2",
			0.066600002,
			"soundMetal3",
			0.066600002,
			"soundMetal4",
			0.066600002,
			"soundMetal5",
			0.066600002,
		};
		hitArmorInt[]=
		{
			"soundMetal1",
			0.066600002,
			"soundMetal2",
			0.066600002,
			"soundMetal3",
			0.066600002,
			"soundMetal4",
			0.066600002,
			"soundMetal5",
			0.066600002,
		};
		bulletFly1[]=
		{
			"\Indecisive_Armoury_Sounds\plasma_flyby_1.wss",
			2.2387211,
			1,
			100
		};
		bulletFly2[]=
		{
			"\Indecisive_Armoury_Sounds\plasma_flyby_2.wss",
			2.2387211,
			1,
			100
		};
		bulletFly3[]=
		{
			"\Indecisive_Armoury_Sounds\plasma_flyby_3.wss",
			2.2387211,
			1,
			100
		};
		bulletFly4[]=
		{
			"\Indecisive_Armoury_Sounds\plasma_flyby_4.wss",
			2.2387211,
			1,
			100
		};
		bulletFly5[]=
		{
			"\Indecisive_Armoury_Sounds\plasma_flyby_5.wss",
			2.2387211,
			1,
			100
		};
		bulletFly[]=
		{
			"bulletFly1",
			0.2,
			"bulletFly2",
			0.2,
			"bulletFly3",
			0.2,
			"bulletFly4",
			0.2,
			"bulletFly5",
			0.2
		};
		soundSetBulletFly[]=
		{
			"IDA_plasma_bullet_flyby_soundSet"
		};
		supersoniccracknear[]={};
		supersoniccrackfar[]={};
		soundSetSonicCrack[]={};
	};
	class FST_blasterbolt_Green: FST_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Green.p3d";
		effectfly="IDA_BlasterBoltGlow_Green_Fly";
		hit=28; //28
		caliber=1.6; //1.6
	};
	class FST_blasterbolt_Yellow: FST_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Yellow_Fly";
		hit=28; //28
		caliber=1.6; //1.6
	};
	class FST_blasterbolt_Red: FST_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
		effectfly="IDA_BlasterBoltGlow_Red_Fly";
		hit=28; //28
		caliber=1.6; //1.6
	};
	class FST_LV13_blasterbolt_Blue: FST_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		hit=50;
		caliber=2.2;
		coefGravity=0;
	};
	class FST_LV13_blasterbolt_Green: FST_LV13_blasterbolt_Blue
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Green.p3d";
		effectfly="IDA_BlasterBoltGlow_Green_Fly";
	};
	class FST_LV13_blasterbolt_Yellow: FST_LV13_blasterbolt_Blue
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Yellow_Fly";
	};
	class FST_LV13_blasterbolt_Red: FST_LV13_blasterbolt_Blue
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
		effectfly="IDA_BlasterBoltGlow_Red_Fly";
	};
	class FST_B54_blasterbolt_Blue: FST_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		hit=60;
		caliber=2.2;
		coefGravity=0;
	};
	class FST_B54_blasterbolt_Green: FST_B54_blasterbolt_Blue
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Green.p3d";
		effectfly="IDA_BlasterBoltGlow_Green_Fly";
	};
	class FST_B54_blasterbolt_Yellow: FST_B54_blasterbolt_Blue
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Yellow_Fly";
	};
	class FST_B54_blasterbolt_Red: FST_B54_blasterbolt_Blue
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
		effectfly="IDA_BlasterBoltGlow_Red_Fly";
	};
	class FST_blasterbolt_High_Blue: FST_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		hit=35;
		caliber=2.2;
		coefGravity=0.02;
	};
	class FST_blasterbolt_High_Green: FST_blasterbolt_High_Blue
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Green.p3d";
		effectfly="IDA_BlasterBoltGlow_Green_Fly";
	};
	class FST_blasterbolt_High_Yellow: FST_blasterbolt_High_Blue
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Yellow_Fly";
	};
	class FST_blasterbolt_High_Red: FST_blasterbolt_High_Blue
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
		effectfly="IDA_BlasterBoltGlow_Red_Fly";
	};
	class FST_blasterbolt_Overcharged_Blue: FST_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		hit=100;
		caliber=2.2;
		coefGravity=1;
		ACE_ammoTempMuzzleVelocityShifts="[-26.55,-25.47,-22.85,-20.12,-16.98,-12.8,-7.64,-1.53,5.96,15.17,26.19]";
		ACE_ballisticCoefficients="[0.317]";
		ACE_barrelLengths="[254,406.4,508,609.6,660.4]";
		ACE_bulletLength=36.220001;
		ACE_bulletMass=9.0719995;
		ACE_caliber=6.7059999;
		ACE_dragModel=7;
		ACE_muzzleVelocities="[500]";
		ACE_muzzleVelocityVariationSD=0;
		ACE_standardAtmosphere="ICAO";
		ACE_velocityBoundaries="[]";
	};
	class FST_blasterbolt_Overcharged_Green: FST_blasterbolt_Overcharged_Blue
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Green.p3d";
		effectfly="IDA_BlasterBoltGlow_Green_Fly";
	};
	class FST_blasterbolt_Overcharged_Yellow: FST_blasterbolt_Overcharged_Blue
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Yellow_Fly";
	};
	class FST_blasterbolt_Overcharged_Red: FST_blasterbolt_Overcharged_Blue
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
		effectfly="IDA_BlasterBoltGlow_Red_Fly";
	};
	class FST_blasterbolt_DMR_Blue: FST_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		hit=55;
		caliber=2.2;
		coefGravity=0.02;
	};
	class FST_blasterbolt_DMR_Green: FST_blasterbolt_DMR_Blue
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Green_Fly";
	};
	class FST_blasterbolt_DMR_Yellow: FST_blasterbolt_DMR_Blue
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Yellow_Fly";
	};
	class FST_blasterbolt_DMR_Red: FST_blasterbolt_DMR_Blue
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Red_Fly";
	};	
	class FST_blasterbolt_scatter_Blue: FST_blasterbolt
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		hit=30;
		submunitionAmmo="FST_blasterbolt";
		submunitionConeType[]=
		{
			"random",
			6
		};
		submunitionConeAngle=0.34999999;
		triggerTime=9.9999997e-010;
	};
	class FST_blasterbolt_scatter_Green: FST_blasterbolt_scatter_Blue
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Green.p3d";
		effectfly="IDA_BlasterBoltGlow_Green_Fly";
		submunitionAmmo="FST_blasterbolt_Green";
	};
	class FST_blasterbolt_scatter_Yellow: FST_blasterbolt_scatter_Blue
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Yellow_Fly";
		submunitionAmmo="FST_blasterbolt_Yellow";
	};
	class FST_blasterbolt_scatter_Red: FST_blasterbolt_scatter_Blue
	{
		effectfly="IDA_BlasterBoltGlow_Red_Fly";
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
		submunitionAmmo="FST_blasterbolt_Red";
	};
	class FST_blasterbolt_scatter_flechette_Blue: FST_Blasterbolt
	{
		coefGravity=1.25;
	};
	class FST_blasterbolt_scatter_flechette_Green: FST_Blasterbolt_Green
	{
		coefGravity=1.25;
	};
	class FST_blasterbolt_scatter_flechette_Yellow: FST_Blasterbolt_Yellow
	{
		coefGravity=1.25;
	};
	class FST_blasterbolt_scatter_flechette_Red: FST_Blasterbolt_Red
	{
		coefGravity=1.25;
	};
	class FST_blasterbolt_scatter_DP23_Blue: FST_blasterbolt
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		hit=25;
		submunitionAmmo="FST_blasterbolt_scatter_flechette_Blue";
		submunitionConeType[]=
		{
			"random",
			8
		};
		submunitionConeAngle=0.34999999;
		triggerTime=9.9999997e-010;
	};
	class FST_blasterbolt_scatter_DP23_Green: FST_blasterbolt_Green
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Green.p3d";
		effectfly="IDA_BlasterBoltGlow_Green_Fly";
		hit=25;
		submunitionAmmo="FST_blasterbolt_scatter_flechette_Green";
		submunitionConeType[]=
		{
			"random",
			8
		};
		submunitionConeAngle=0.34999999;
		triggerTime=9.9999997e-010;
	};
	class FST_blasterbolt_scatter_DP23_Yellow: FST_blasterbolt_Yellow
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Yellow_Fly";
		hit=25;
		submunitionAmmo="FST_blasterbolt_scatter_flechette_Yellow";
		submunitionConeType[]=
		{
			"random",
			8
		};
		submunitionConeAngle=0.34999999;
		triggerTime=9.9999997e-010;
	};
	class FST_blasterbolt_scatter_DP23_Red: FST_blasterbolt_Red
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
		effectfly="IDA_BlasterBoltGlow_Red_Fly";
		hit=25;
		submunitionAmmo="FST_blasterbolt_scatter_flechette_Red";
		submunitionConeType[]=
		{
			"random",
			8
		};
		submunitionConeAngle=0.34999999;
		triggerTime=9.9999997e-010;
	};
	class FST_blasterbolt_Underbarel_scatter_Blue: FST_blasterbolt
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		hit=10;
		submunitionAmmo="FST_blasterbolt";
		submunitionConeType[]=
		{
			"random",
			10
		};
		submunitionConeAngle=2;
		triggerTime=9.9999997e-010;
	};
	class FST_blasterbolt_Underbarel_scatter_Green: FST_blasterbolt_Underbarel_scatter_Blue
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Green.p3d";
		effectfly="IDA_BlasterBoltGlow_Green_Fly";
		submunitionAmmo="FST_blasterbolt_Green";
	};
	class FST_blasterbolt_Underbarel_scatter_Yellow: FST_blasterbolt_Underbarel_scatter_Blue
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Yellow_Fly";
		submunitionAmmo="FST_blasterbolt_Yellow";
	};
	class FST_blasterbolt_Underbarel_scatter_Red: FST_blasterbolt_Underbarel_scatter_Blue
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
		effectfly="IDA_BlasterBoltGlow_Red_Fly";
		submunitionAmmo="FST_blasterbolt_Red";
	};
	class FST_thermal_slug_Blue: FST_blasterbolt
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Blue_Fly";
		ACE_damageType="plasma";
		hit=200;
		indirectHit=1;
		explosive=1;
		indirectHitRange=0.5;
		caliber=10;
		coefGravity=1;
	};
	class FST_thermal_slug_Green: FST_thermal_slug_Blue
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Green.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Green_Fly";
	};
	class FST_thermal_slug_Yellow: FST_thermal_slug_Blue
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Yellow_Fly";
	};
	class FST_thermal_slug_Red: FST_thermal_slug_Blue
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Red_Fly";
	};
	class FST_thermal_shell_LP_Blue: IDA_blasterbolt
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Medium_Blue_Fly";
		ACE_damageType="plasma";
		hit=120; // Initial hit before submunitions trigger
		indirectHit=1;
		explosive=1;
		indirectHitRange=0.5;
		caliber=5;
		submunitionAmmo="FST_blasterbolt"; // Submunition ammo class
		submunitionConeType[]=
		{
			"random",
			12
		};
		submunitionConeAngle=0.05;
		triggerDistance = 50;
	};
	class FST_thermal_shell_LP_Green: FST_thermal_shell_LP_Blue
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Green.p3d";
		effectfly="IDA_BlasterBoltGlow_Medium_Green_Fly";
	};
	class FST_thermal_shell_LP_Yellow: FST_thermal_shell_LP_Blue
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Medium_Yellow_Fly";
	};
	class FST_thermal_shell_LP_Red: FST_thermal_shell_LP_Blue
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
		effectfly="IDA_BlasterBoltGlow_Medium_Red_Fly";
		hit=30;
		caliber=2;
		submunitionAmmo="FST_blasterbolt"; // Submunition ammo class
		submunitionConeType[]=
		{
			"random",
			6
		};
		submunitionConeAngle=0.05;
		triggerDistance = 50;
	};
	class FST_thermal_shell_T15_Blue: FST_blasterbolt
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Blue_Fly";
		ACE_damageType="plasma";
		hit=400;
		indirectHit=1;
		explosive=1;
		indirectHitRange=0.5;
		caliber=20;
	};
	class FST_thermal_shell_T15_Green: FST_thermal_shell_T15_Blue
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Green.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Green_Fly";
	};
	class FST_thermal_shell_T15_Yellow: FST_thermal_shell_T15_Blue
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Yellow_Fly";
	};
	class FST_thermal_shell_T15_Red: FST_thermal_shell_T15_Blue
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Red_Fly";
	};
	class GrenadeHand_stone;
	class G_40mm_HE;
	class FST_HE_RifleGrenade: G_40mm_HE
	{
		ace_frag_enabled=1;
		indirectHitRange=7;
		indirectHit=30;
		effectflare="FlareShell";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		fuseDistance=7;
		ExplosionEffects="SWLW_plasma_he_impact";
		CraterEffects="SWLW_plasma_he_impact";
		lightcolor[]={0,0,1};
	};
	class FST_TDHE_RifleGrenade: G_40mm_HE
	{
		ace_frag_enabled=1;
		indirectHitRange=7;
		indirectHit=30;
		effectflare="FlareShell";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		ExplosionEffects="SWLW_plasma_he_impact";
		CraterEffects="SWLW_plasma_he_impact";
		lightcolor[]={0,0,1};
		fuseDistance=0;
		timetolive=5;
		simulation = "shotShell";
	};
	class FST_HE_WristRocket: G_40mm_HE
	{
		ace_frag_enabled=1;
		indirectHitRange=7;
		indirectHit=30;
		effectflare="FlareShell";
		effectfly="IDA_BlasterBoltGlow_Red_Fly";
		fuseDistance=7;
		ExplosionEffects="SWLW_plasma_he_impact";
		CraterEffects="SWLW_plasma_he_impact";
		lightcolor[]={0,0,1};
	};
	class FST_grenade_emp_ammo: GrenadeHand_stone
	{
		JLTS_isEMPAmmo=1;
		ace_frag_enabled=0;
		ace_grenades_pullPinSound[]=
		{
			"\Indecisive_Armoury_Sounds\Detonator_Pin.ogg",
			6,
			1,
			10
		};
		author="Adapted from JLTS";
		hit=0.0099999998;
		indirectHit=0.0099999998;
		explosive=0.0099999998;
		indirectHitRange=7;
		model="\Indecisive_Armoury_Ammos\Data\Thermal_Detonator\IDA_Thermal_Detonator.p3d";
		explosionEffects="JLTS_fx_exp_EMP";
		grenadeBurningSound[]=
		{
			"EMPSoundLoop1",
			0.5
		};
		EMPSoundLoop1[]=
		{
			"MRC\JLTS\weapons\Grenades\sounds\grenade_burning.wss",
			0.125893,
			1,
			70
		};
		SoundSetExplosion[]=
		{
			"FST_GrenadeEMP_Exp_SoundSet",
			"Explosion_Debris_SoundSet"
		};
		soundFly[]=
		{
			"41st_Weapons\Grenades\Data\droidpoppertimer.ogg",
			6,
			1,
			90
		};
		aiAmmoUsageFlags=0;
		class CamShakeExplode
		{
			distance=10;
			duration=1;
			frequency=20;
			power=0;
		};
	};
	class IDA_grenade_Detonator_ammo;
	class FST_grenade_Detonator_ammo: IDA_grenade_Detonator_ammo
	{
		hit=40;
		indirectHit=30;
		indirectHitRange=10;
		dangerRadiusHit=80;
		suppressionRadiusHit=40;
		explosionEffectsRadius=30;
		explosionEffects="VehicleExplosionEffects";
		effectsSmoke="ACE_Incendiary";
	};
    class FST_HE_RifleGrenade_Delayed_5: FST_grenade_Detonator_ammo
	{
		// Basic behavior
		simulation = "shotGrenade";
		timeToLive = 10; 				 //Set time before the projectile is deleted. 
		explosionTime = 5;               // Explodes after X seconds

		// Bouncing
		deflecting = 1000;         		 // Always deflect (0 = No bouncing — round always sticks or explodes) (45 = Only glancing (shallow angle) hits will bounce) (100 = Most angles will bounce) (1000 = Always tries to bounce, even on direct hits)
		deflectionSlowDown = 0.05;       // Retain speed after bounce / lower = faster

		// Movement
		airFriction = -0.001;
		sideAirFriction = 0.1;
		typicalSpeed = 75;
        initSpeed = 75;
        maxSpeed = 100;
		caliber = 1;
		gravityCoef = 0.9; // Optional: makes it fall more slowly
		friction = 0.1;    // Low friction to reduce energy loss
    };
	class R_PG32V_F;
	class ACE_Javelin_FGM148;
	class PLX_Javelin;
	class 442_nlaw_AT;
	class FST_rocket: R_PG32V_F
	{
		hit=500;
		indirectHit=100;
		indirectHitRange=4;
		maxSpeed=165;
		thrust=165;
		thrustTime=0.1;
		timeToLive=10;
		sideAirFriction=0.075000003;
	};
 	class FST_rocket_HE: R_PG32V_F
	{
		hit=250;
		indirectHit=200;
		indirectHitRange=10;
		maxSpeed=160;
		thrust=160;
		thrustTime=0.1;
		timeToLive=10;
		sideAirFriction=0.075000003;
	}; 
	class IDA_grenade_Penetrator_ammo;
	class FST_grenade_Penetrator_ammo: IDA_grenade_Penetrator_ammo
	{
		indirectHit=4000;
		indirectHitRange=2;
	};
	class FST_grenade_rock_ammo: GrenadeHand_stone
	{
		indirectHit=1;
		indirectHitRange=1;
		soundFly[]=
		{
			"\41st_Ammo\Data\itsarock.ogg",
			6,
			1,
			100
		};
	};
	class FST_Missile: ACE_Javelin_FGM148
	{
		author = "Viz";
		airLock=1;
		ace_frag_enabled=0;
		class ace_missileguidance
		{
			attackProfiles[]=
			{
				"JAV_TOP",
				"JAV_DIR"
			};
			canVanillaLock=0;
			defaultAttackProfile="JAV_TOP";
			defaultSeekerLockMode="LOBL";
			defaultSeekerType="Optic";
			defaultNavigationType = "Direct";
			navigationTypes[] = 
			{
				"Direct"
			};
			enabled=1;
			pitchRate = 60;
            yawRate = 60;
			seekerAccuracy=1;
			seekerAngle=180;
			seekerLockModes[]=
			{
				"LOBL",
				"LOAL"
			};
			seekerMinRange=0;
			seekerMaxRange=3000;
			seekerTypes[]=
			{
				"Optic",
				"IR"
			};
			seekLastTargetPos=1;
			useModeForAttackProfile=1;
		};
		caliber=60;
		effectsMissile="3AS_Rocket_effect_Blue_fly";
		hit=1000;
		indirectHit=300;
		indirectHitRange=4;
		irLock = 1;
        laserLock = 1;
        lockSeekRadius= 75;
		maxSpeed=180;
        manualControl=1;
        missileLockCone = 45;
		missileLockMaxSpeed = 40;
		missileLockMaxDistance = 3000;
		missileLockMinDistance = 0;
		thrust = 50;
		weaponLockSystem = "2 + 8 + 16";
	};
	class FlameRound;
	class FST_Fire: FlameRound
	{
		submunitionAmmo="FST_Fire_sub";
		submunitionConeType[]=
		{
			"poissondisc",
			4
		};
		submunitionConeAngle=1;
		triggerTime=0.050000001;
		ACE_damageType="plasma";
		hit=25;
		indirectHit=25;
		indirectHitRange=1;
		cartridge="";
		cost=2;
		visibleFire=32;
		audibleFire=12;
		visibleFireTime=20;
		airFriction=0.1;
		timetolive=1.6;
		maxSpeed=25;
		typicalSpeed=0.12;
		coefGravity=0;
		deflecting=0;
		explosive=1;
		fuseDistance=1;
		caliber=0.5;
		tracerScale=0.001;
		tracerStartTime=0.0099999998;
		tracerEndTime=0.1;
		craterEffects="";
		effectFly="FST_FireEffect";
		explosionEffects="";
		model="\A3\Weapons_f\Data\bullettracer\tracer_Red";
		bulletFly1[]={};
		bulletFly2[]={};
		bulletFly3[]={};
		bulletFly4[]={};
		bulletFly5[]={};
		bulletFly[]={};
		hitArmor[]={};
		hitArmorInt[]={};
		soundHitBody1[]={};
		soundHitBody2[]={};
		soundHitBody3[]={};
		soundHitBody4[]={};
		soundHitBody5[]={};
		soundHitBody6[]={};
		soundHitBody7[]={};
		soundHitBody8[]={};
		soundHitBody9[]={};
		soundHitBody10[]={};
		hitMan[]={};
		hitBuilding[]={};
		soundDefault1[]={};
		soundDefault2[]={};
		soundDefault3[]={};
		soundDefault4[]={};
		soundDefault5[]={};
		soundDefault6[]={};
		soundDefault7[]={};
		soundDefault8[]={};
		hitDefault[]={};
		soundHit1[]={};
		soundHit2[]={};
		soundHit3[]={};
		soundHit4[]={};
		soundHit5[]={};
		hitGround[]={};
		hitGroundHard[]={};
		hitGroundSoft[]={};
		hitFoliage[]={};
		hitIron[]={};
		soundMetal1[]={};
		soundMetal2[]={};
		soundMetal3[]={};
		soundMetal4[]={};
		soundMetal5[]={};
		soundMetal6[]={};
		soundMetal7[]={};
		soundMetal8[]={};
		soundMetal9[]={};
		soundMetal10[]={};
		hitMetal[]={};
		hitMetalInt[]={};
		hitMetalPlate[]={};
		hitPlastic[]={};
		hitRubber[]={};
		soundConcrete1[]={};
		soundConcrete2[]={};
		soundConcrete3[]={};
		soundConcrete4[]={};
		soundConcrete5[]={};
		soundConcrete6[]={};
		soundConcrete7[]={};
		soundConcrete8[]={};
		hitConcrete[]={};
		hitTyre[]={};
		soundWater1[]={};
		soundWater2[]={};
		soundWater3[]={};
		hitWater[]={};
		soundWood1[]={};
		soundWood2[]={};
		soundWood3[]={};
		soundWood4[]={};
		soundWood5[]={};
		soundWood6[]={};
		soundWood7[]={};
		soundWood8[]={};
		soundWood9[]={};
		hitWood[]={};
		supersoniccracknear[]={};
		supersoniccrackfar[]={};
		soundSetSonicCrack[]={};
		soundSetBulletFly[]={};
	};
	class FlameRound_sub;
	class FST_Fire_sub: FlameRound_sub
	{
		ACE_damageType="plasma";
		hit=10;
		indirectHit=25;
		indirectHitRange=1;
		cartridge="";
		cost=2;
		visibleFire=32;
		audibleFire=12;
		visibleFireTime=20;
		airFriction=0;
		timetolive=1.6;
		maxSpeed=25;
		typicalSpeed=0.12;
		coefGravity=0;
		deflecting=0;
		explosive=1;
		fuseDistance=1;
		caliber=0.5;
		tracerScale=0.0099999998;
		tracerStartTime=0.0099999998;
		tracerEndTime=0.1;
		craterEffects="";
		effectFly="FST_FireEffect";
		explosionEffects="";
		bulletFly1[]={};
		bulletFly2[]={};
		bulletFly3[]={};
		bulletFly4[]={};
		bulletFly5[]={};
		bulletFly[]={};
		hitArmor[]={};
		hitArmorInt[]={};
		soundHitBody1[]={};
		soundHitBody2[]={};
		soundHitBody3[]={};
		soundHitBody4[]={};
		soundHitBody5[]={};
		soundHitBody6[]={};
		soundHitBody7[]={};
		soundHitBody8[]={};
		soundHitBody9[]={};
		soundHitBody10[]={};
		hitMan[]={};
		hitBuilding[]={};
		soundDefault1[]={};
		soundDefault2[]={};
		soundDefault3[]={};
		soundDefault4[]={};
		soundDefault5[]={};
		soundDefault6[]={};
		soundDefault7[]={};
		soundDefault8[]={};
		hitDefault[]={};
		soundHit1[]={};
		soundHit2[]={};
		soundHit3[]={};
		soundHit4[]={};
		soundHit5[]={};
		hitGround[]={};
		hitGroundHard[]={};
		hitGroundSoft[]={};
		hitFoliage[]={};
		hitIron[]={};
		soundMetal1[]={};
		soundMetal2[]={};
		soundMetal3[]={};
		soundMetal4[]={};
		soundMetal5[]={};
		soundMetal6[]={};
		soundMetal7[]={};
		soundMetal8[]={};
		soundMetal9[]={};
		soundMetal10[]={};
		hitMetal[]={};
		hitMetalInt[]={};
		hitMetalPlate[]={};
		hitPlastic[]={};
		hitRubber[]={};
		soundConcrete1[]={};
		soundConcrete2[]={};
		soundConcrete3[]={};
		soundConcrete4[]={};
		soundConcrete5[]={};
		soundConcrete6[]={};
		soundConcrete7[]={};
		soundConcrete8[]={};
		hitConcrete[]={};
		hitTyre[]={};
		soundWater1[]={};
		soundWater2[]={};
		soundWater3[]={};
		hitWater[]={};
		soundWood1[]={};
		soundWood2[]={};
		soundWood3[]={};
		soundWood4[]={};
		soundWood5[]={};
		soundWood6[]={};
		soundWood7[]={};
		soundWood8[]={};
		soundWood9[]={};
		hitWood[]={};
		supersoniccracknear[]={};
		supersoniccrackfar[]={};
		soundSetSonicCrack[]={};
		soundSetBulletFly[]={};
	};
	class IDA_smoke_Impact;
	class FST_smoke_Impact: IDA_smoke_Impact
	{
		model="\A3\weapons_f\Ammo\UGL_slug";
		smokeColor[]={1,1,1,1};
		caliber=2;
		simulation="shotSmoke";
		effectsSmoke="IDA_SmokeEffect";
		explosionTime=-1;
		deflectionSlowDown=0.1;
		timeToLive=120;
		ace_frag_enabled=0;
		hit=1;
		indirectHitRange=0;
		indirectHit=1;
		fuseDistance=1;
		ExplosionEffects="";
		CraterEffects="";
		SoundSetExplosion[]=
		{
			""
		};
	};
	class FST_smoke_Impact_Red: FST_smoke_Impact
	{
		smokeColor[]={0.5,0,0,1};
	};
	class FST_smoke_Impact_Green: FST_smoke_Impact
	{
		smokeColor[]={0,0.5,0,1};
	};
	class FST_smoke_Impact_blue: FST_smoke_Impact
	{
		smokeColor[]={0,0,0.5,1};
	};
	class FST_smoke_Impact_purple: FST_smoke_Impact
	{
		smokeColor[]={0.5,0,0.5,1};
	};	
};	
class CfgMagazines
{
	class IDA_Blaster_Cell_Power1_300Rnd_Blue;
	class IDA_Blaster_Cell_Power2_20Rnd_Blue;
	class IDA_Blaster_Cell_Power3_40Rnd_Blue;
	class IDA_Blaster_Cell_Power3_80Rnd_Blue;
	class IDA_Blaster_Cell_Power4_10Rnd_Blue;
	class IDA_Blaster_Cell_Scatter_6Rnd_Blue;
	class 100Rnd_65x39_caseless_mag;
	
	class FST_blaster_cell_High_Blue: IDA_Blaster_Cell_Power3_40Rnd_Blue 
	{
		author="Adapted from the Indecisive Armoury Team";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		displayName="[41st] High-Power Energy Cell (Blue)";
		displayNameShort="HP Energy Cell";
		descriptionShort="40 round capacity.";
		ammo="FST_blasterbolt_High_Blue";
		initSpeed=340;
	};
	class FST_blaster_cell_High_Green: FST_blaster_cell_High_Blue
	{
		ammo="FST_blasterbolt_High_Green";
		displayName="[41st] High-Power Energy Cell (Green)";
	};
	class FST_blaster_cell_High_Yellow: FST_blaster_cell_High_Blue
	{
		ammo="FST_blasterbolt_High_Yellow";
		displayName="[41st] High-Power Energy Cell (Yellow)";
	};
	class FST_blaster_cell_High_Red: FST_blaster_cell_High_Blue
	{
		ammo="FST_blasterbolt_High_Red";
		displayName="[41st] High-Power Energy Cell (Red)";
	};
	class FST_blaster_cell_Blue: IDA_Blaster_Cell_Power2_20Rnd_Blue
	{
		author="Adapted from the Indecisive Armoury Team";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		displayName="[41st] Standard Energy Cell (Blue)";
		displayNameShort="Energy Cell";
		descriptionShort="60 round capacity.";
		ammo="FST_blasterbolt";
		count=60;
		initSpeed=250;
		mass=8;
	};
	class FST_blaster_cell_Green: FST_blaster_cell_Blue
	{
		displayName="[41st] Standard Energy Cell (Green)";
		ammo="FST_blasterbolt_Green";
	};
	class FST_blaster_cell_Yellow: FST_blaster_cell_Blue
	{
		displayName="[41st] Standard Energy Cell (Yellow)";
		ammo="FST_blasterbolt_Yellow";
	};
	class FST_blaster_cell_Red: FST_blaster_cell_Blue
	{
		displayName="[41st] Standard Energy Cell (Red)";
		ammo="FST_blasterbolt_Red";
	};
	class FST_Droid_blaster_cell_Red: FST_blaster_cell_Blue
	{
		displayName="[41st] Droid Standard Energy Cell (Red)";
		ammo="FST_blasterbolt_Red";
	};
	class FST_blaster_cell_Westar_Blue: IDA_Blaster_Cell_Power3_40Rnd_Blue 
	{
		author="Daara";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		displayName="[41st] High-Power Westar Energy Cell (Blue)";
		displayNameShort="HP Energy Cell Westar";
		descriptionShort="60 round capacity.";
		ammo="FST_blasterbolt_high_Blue";
		JLTS_hasElectronics=0;
		JLTS_hasEMPProtection=1;
		count=60;
		initSpeed=340;
		mass=8;
	};
	class FST_blaster_cell_Westar_Green: FST_blaster_cell_Westar_Blue
	{
		author="Gold";
		displayName="[41st] High-Power Westar Energy Cell (Green)";
		ammo="FST_blasterbolt_high_Green";
	};
	class FST_blaster_cell_Westar_Yellow: FST_blaster_cell_Westar_Blue
	{
		author="Gold";
		displayName="[41st] High-Power Westar Energy Cell (Yellow)";
		ammo="FST_blasterbolt_high_Yellow";
	};
	class FST_blaster_cell_Westar_Red: FST_blaster_cell_Westar_Blue
	{
		author="Gold";
		displayName="[41st] High-Power Westar Energy Cell (Red)";
		ammo="FST_blasterbolt_high_Red";
	};
	class FST_blaster_cell_LE_Blue: IDA_Blaster_Cell_Power3_40Rnd_Blue 
	{
		author="Adapted from the Indecisive Armoury Team";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		displayName="[41st] High-Power DMR Blaster Cell (Blue)";
		displayNameShort="HP Energy Cell";
		descriptionShort="10 round capacity.";
		ammo="FST_blasterbolt_DMR_Blue";
		count=10;
		tracersEvery=1;
		initSpeed=410;
		mass=8;
	};
	class FST_blaster_cell_LE_Green: FST_blaster_cell_LE_Blue
	{
		displayName="[41st] High-Power DMR Blaster Cell (Green)";
		ammo="FST_blasterbolt_DMR_Green";
	};
	class FST_blaster_cell_LE_Yellow: FST_blaster_cell_LE_Blue
	{
		displayName="[41st] High-Power DMR Blaster Cell (Yellow)";
		ammo="FST_blasterbolt_DMR_Yellow";
	};
	class FST_blaster_cell_LE_Red: FST_blaster_cell_LE_Blue
	{
		displayName="[41st] High-Power DMR Blaster Cell (Red)";
		ammo="FST_blasterbolt_DMR_Red";
	};
	class FST_blaster_cell_Valken_Blue: IDA_Blaster_Cell_Power3_40Rnd_Blue 
	{
		author="Daara";
		picture="\MRC\JLTS\weapons\z6\data\ui\z6_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\z6\z6_mag.p3d";
		displayName="[41st] HP Valken Extended Capacity Magazine (Blue)";
		displayNameShort="HP Energy Battery";
		descriptionShort="60 round capacity.";
		ammo="FST_blasterbolt_High_Blue";
		JLTS_hasElectronics=0;
		JLTS_hasEMPProtection=1;
		count=60;
		tracersEvery=1;
		initSpeed=340;
		mass=20;
	};
	class FST_blaster_cell_Valken_Green: FST_blaster_cell_Valken_Blue
	{
		author="Gold";
		displayName="[41st] HP Valken Extended Capacity Magazine (Green)";
		ammo="FST_blasterbolt_High_Green";
	};
	class FST_blaster_cell_Valken_Yellow: FST_blaster_cell_Valken_Blue
	{
		author="Gold";
		displayName="[41st] HP Valken Extended Capacity Magazine (Yellow)";
		ammo="FST_blasterbolt_High_Yellow";
	};
	class FST_blaster_cell_Valken_Red: FST_blaster_cell_Valken_Blue
	{
		author="Gold";
		displayName="[41st] HP Valken Extended Capacity Magazine (Red)";
		ammo="FST_blasterbolt_High_Red";
	};
	class FST_blaster_battery_DC15L_Blue: IDA_Blaster_Cell_Power1_300Rnd_Blue
	{
		author="Daara";
		picture="\MRC\JLTS\weapons\z6\data\ui\z6_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\z6\z6_mag.p3d";
		displayName="[41st] Low-Power DC-15L Extended Capacity Magazine (Blue)";
		displayNameShort="LP Energy Battery";
		descriptionShort="150 round capacity.";
		ammo="FST_blasterbolt";
		JLTS_hasElectronics=0;
		JLTS_hasEMPProtection=1;
		count=120;
		initSpeed=250;
		mass=20;
	};
	class FST_blaster_battery_DC15L_Green: FST_blaster_battery_DC15L_Blue
	{
		displayName="[41st] Low-Power DC-15L Extended Capacity Magazine (Green)";
		ammo="FST_blasterbolt_Green";
	};
	class FST_blaster_battery_DC15L_Yellow: FST_blaster_battery_DC15L_Blue
	{
		displayName="[41st] Low-Power DC-15L Extended Capacity Magazine (Yellow)";
		ammo="FST_blasterbolt_Yellow";
	};
	class FST_blaster_battery_DC15L_Red: FST_blaster_battery_DC15L_Blue
	{
		displayName="[41st] Low-Power DC-15L Extended Capacity Magazine (Red)";
		ammo="FST_blasterbolt_Red";
	};
	class FST_blaster_battery_Blue: IDA_Blaster_Cell_Power3_40Rnd_Blue
	{
		author="Indecisive Armoury Team";
		displayName="[41st] High-Power Energy Battery (Blue)";
		picture="\MRC\JLTS\weapons\z6\data\ui\z6_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\z6\z6_mag.p3d";
		displayNameShort="HP Energy Battery";
		descriptionShort="300 round capacity.";
		ammo="FST_blasterbolt_high_Blue";
		count=300;
		initSpeed=250;
		mass=35;
	};
	class FST_blaster_battery_Green: FST_blaster_battery_Blue
	{
		author="Gold";
		displayName="[41st] High-Power Energy Battery (Green)";
		ammo="FST_blasterbolt_high_Green";
	};
	class FST_blaster_battery_Yellow: FST_blaster_battery_Blue
	{
		author="Gold";
		displayName="[41st] High-Power Energy Battery (Yellow)";
		ammo="FST_blasterbolt_high_Yellow";
	};
	class FST_blaster_battery_Red: FST_blaster_battery_Blue
	{
		author="Gold";
		displayName="[41st] High-Power Energy Battery (Red)";
		ammo="FST_blasterbolt_high_Red";
	};
	class FST_Droid_blaster_battery_Red: FST_blaster_battery_Blue
	{
		author="Gold";
		displayName="[41st] Droid High-Power Energy Battery (Red)";
		ammo="FST_blasterbolt_high_Red";
	};
	class FST_DC1A_Prototype_120Rnd_Blue: IDA_Blaster_Cell_Power3_40Rnd_Blue
	{
		displayname="[41st] DC1A Battery (Blue)";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="DBA Republic\Addons\DBA_Weapons\DBA_DC15A\Magazines\Mod0_120Rnd_Mag.p3d";
		ammo="FST_blasterbolt_high_Blue";
		scope=2;
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"DBA_Republic\Addons\DBA_Weapons\DBA_DC15A\Magazines\Mod0_120Rnd_Mag_CO.paa"
		};
		modelSpecial="DBA_Republic\Addons\DBA_Weapons\DBA_DC15A\Magazines\Mod0_120Rnd_Mag.p3d";
		modelSpecialIsProxy=1;
		mass=15;
		count=120;
		initspeed=909;
	};
	class FST_DC1A_Prototype_120Rnd_Green: FST_DC1A_Prototype_120Rnd_Blue
	{
		displayname="[41st] DC1A Battery (Green)";
		ammo="FST_blasterbolt_high_Green";
	};
	class FST_DC1A_Prototype_120Rnd_Yellow: FST_DC1A_Prototype_120Rnd_Blue
	{
		displayname="[41st] DC1A Battery (Yellow)";
		ammo="FST_blasterbolt_high_Yellow";
	};
	class FST_DC1A_Prototype_120Rnd_Red: FST_DC1A_Prototype_120Rnd_Blue
	{
		displayname="[41st] DC1A Battery (Red)";
		ammo="FST_blasterbolt_high_Red";
	};
	class FST_blaster_cell_low_Blue: IDA_Blaster_Cell_Power1_300Rnd_Blue
	{
		author="Adapted from the Indecisive Armoury Team";
		displayName="[41st] Low-Power Energy Cell (Blue)";
		displayNameShort="LP Energy Cell";
		descriptionShort="30 Rnds Low Power Pistol Ammo";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		ammo="FST_blasterbolt";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		count=30;
		tracersEvery=1;
		initSpeed=250;
		mass=4;
	};
	class FST_blaster_cell_low_green: FST_blaster_cell_low_Blue
	{
		displayName="[41st] Low-Power Energy Cell (Green)";
		ammo="FST_blasterbolt_green";
	};
	class FST_blaster_cell_low_yellow: FST_blaster_cell_low_Blue
	{
		displayName="[41st] Low-Power Energy Cell (Yellow)";
		ammo="FST_blasterbolt_yellow";
	};
	class FST_blaster_cell_low_Red: FST_blaster_cell_low_Blue
	{
		displayName="[41st] Low-Power Energy Cell (Red)";
		ammo="FST_blasterbolt_Red";
	};
	class FST_blaster_cell_LV13_Blue: 100Rnd_65x39_caseless_mag
	{
		author="Gold";
		displayName="[41st] LV-13 Energy Cell (Blue)";
		displayNameShort="LV-13 Energy Cell";
		descriptionShort="10 Rnds Pistol Ammo";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		ammo="FST_LV13_blasterbolt_Blue";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		count=10;
		tracersEvery=0.00001;
		initSpeed=2000;
		mass=1;
	};
	class FST_blaster_cell_LV13_Green: FST_blaster_cell_LV13_Blue
	{
		displayName="[41st] LV-13 Energy Cell (Green)";
		ammo="FST_LV13_blasterbolt_Green";
	};
	class FST_blaster_cell_LV13_Yellow: FST_blaster_cell_LV13_Blue
	{
		displayName="[41st] LV-13 Energy Cell (Yellow)";
		ammo="FST_LV13_blasterbolt_Yellow";
	};
	class FST_blaster_cell_LV13_Red: FST_blaster_cell_LV13_Blue
	{
		displayName="[41st] LV-13 Energy Cell (Red)";
		ammo="FST_LV13_blasterbolt_Red";
	};
	class FST_blaster_cell_B54_Blue: 100Rnd_65x39_caseless_mag
	{
		author="Gold";
		displayName="[41st] B54 Energy Cell (Blue)";
		displayNameShort="B54 Energy Cell";
		descriptionShort="8 Rnds Pistol Ammo";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		ammo="FST_B54_blasterbolt_Blue";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		count=8;
		tracersEvery=0.00001;
		initSpeed=2250;
		mass=1;
	};
	class FST_blaster_cell_B54_Green: FST_blaster_cell_B54_Blue
	{
		displayName="[41st] B54 Energy Cell (Green)";
		ammo="FST_B54_blasterbolt_Green";
	};
	class FST_blaster_cell_B54_Yellow: FST_blaster_cell_B54_Blue
	{
		displayName="[41st] B54 Energy Cell (Yellow)";
		ammo="FST_B54_blasterbolt_Yellow";
	};
	class FST_blaster_cell_B54_Red: FST_blaster_cell_B54_Blue
	{
		displayName="[41st] B54 Energy Cell (Red)";
		ammo="FST_B54_blasterbolt_Red";
	};
	class FST_pistol_westar35sa_Mag_Blue: 100Rnd_65x39_caseless_mag
	{
		author="Adapted from SW Legion Studios";
		displayName="Westar-35SA energy cell (Blue)";
		picture="\SWLW_merc_mando\pistols\westar35sa\data\ui\SWLW_westar35sa_mag_ui.paa";
		ammo="FST_blasterbolt";
		scope=2;
		tracersEvery=1;
		type=16;
		count=17;
		descriptionShort="";
		mass=6;
		initSpeed=300;
	};
	class FST_pistol_westar35sa_Mag_Green: FST_pistol_westar35sa_Mag_Blue
	{
		displayName="Westar-35SA energy cell (Green)";
		ammo="FST_blasterbolt_green";
	};
	class FST_pistol_westar35sa_Mag_Yellow: FST_pistol_westar35sa_Mag_Blue
	{
		displayName="Westar-35SA energy cell (Yellow)";
		ammo="FST_blasterbolt_yellow";
	};
	class FST_pistol_westar35sa_Mag_Red: FST_pistol_westar35sa_Mag_Blue
	{
		displayName="Westar-35SA energy cell (Red)";
		ammo="FST_blasterbolt_Red";
	};
	class FST_thermal_coil_LP_Blue: IDA_Blaster_Cell_Power1_300Rnd_Blue
	{
		author="Adapted From The Indecisive Armoury Team";
		displayName="[41st] Low-power Thermal coil (Blue)";
		displayNameShort="LP Thermal coil (Blue)";
		descriptionShort="20 round capacity.";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		ammo="FST_thermal_shell_LP_BLue";
		count=20;
		initSpeed=300;
		mass=35;
	};
	class FST_thermal_coil_LP_Green: FST_thermal_coil_LP_Blue
	{
		author="Gold";
		displayName="[41st] Low-power Thermal coil (Green)";
		ammo="FST_thermal_shell_LP_Green";
	};
	class FST_thermal_coil_LP_Yellow: FST_thermal_coil_LP_Blue
	{
		author="Gold";
		displayName="[41st] Low-power Thermal coil (Yellow)";
		ammo="FST_thermal_shell_LP_Yellow";
	};
	class FST_thermal_coil_LP_Red: FST_thermal_coil_LP_Blue
	{
		author="Gold";
		displayName="[41st] Low-power Thermal coil (Red)";
		ammo="FST_thermal_shell_LP_Red";
	};
	class FST_thermal_coil_T15_Blue: IDA_Blaster_Cell_Power3_40Rnd_Blue
	{
		author="Adapted From The Indecisive Armoury Team";
		displayName="[41st] High-power Thermal Coil";
		displayNameShort="HP Thermal coil";
		descriptionShort="5 round capacity.";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		ammo="FST_thermal_shell_T15_Blue";
		count=5;
		initSpeed=300;
		mass=35;
	};
	class FST_thermal_coil_T15_Green: FST_thermal_coil_T15_Blue
	{
		author="Gold";
		displayName="[41st] High-power Thermal Coil (Green)";
		ammo="FST_thermal_shell_T15_Green";
	};
	class FST_thermal_coil_T15_Yellow: FST_thermal_coil_T15_Blue
	{
		author="Gold";
		displayName="[41st] High-power Thermal Coil (Yellow)";
		ammo="FST_thermal_shell_T15_Yellow";
	};
	class FST_thermal_coil_T15_Red: FST_thermal_coil_T15_Blue
	{
		author="Gold";
		displayName="[41st] High-power Thermal Coil (Red)";
		ammo="FST_thermal_shell_T15_Red";
	};
	//IS THIS EVEN USED? AMMO ISNT CALLING ANYTHING THAT WORKS
	/*class FST_thermal_coil_Nexu_Blue: 100Rnd_65x39_caseless_mag
	{
		author="Adapted From The Indecisive Armoury Team";
		displayName="[41st] High-power Thermal Coil Nexu Edition";
		displayNameShort="HP Thermal coil";
		descriptionShort="5 round capacity.";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		ammo="FST_thermal_shell_HP";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		count=5;
		tracersEvery=1;
		initSpeed=300;
		mass=35;
	};
	class FST_thermal_coil_Nexu_Green: FST_thermal_coil_Nexu_Blue
	{
		author="Gold";
		displayName="[41st] High-power Thermal Coil Nexu Edition (Green)";
		ammo="FST_thermal_shell_HP_Green";
	};
	class FST_thermal_coil_Nexu_Yellow: FST_thermal_coil_Nexu_Blue
	{
		author="Gold";
		displayName="[41st] High-power Thermal Coil Nexu Edition (Yellow)";
		ammo="FST_thermal_shell_HP_Yellow";
	};
	class FST_thermal_coil_Nexu_Red: FST_thermal_coil_Nexu_Blue
	{
		author="Gold";
		displayName="[41st] High-power Thermal Coil Nexu Edition (Red)";
		ammo="FST_thermal_shell_HP_Red";
	};*/
	class FST_blaster_scatter_cell_DP23_Blue: IDA_Blaster_Cell_Power3_40Rnd_Blue
	{
		author="Adapted from the Indecisive Armoury Team";
		displayName="[41st] High-Power DP23 Scatter Cell (Blue)";
		displayNameShort="HP Scatter Cell";
		descriptionShort="8 round capacity";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		ammo="FST_blasterbolt_scatter_DP23_Blue";
		scopeArsenal=2;
		count=8;
		initSpeed=250;
		mass=8;
	};
	class FST_blaster_scatter_cell_DP23_Green: FST_blaster_scatter_cell_DP23_Blue
	{
		author="Gold";
		displayName="[41st] High-Power DP23 Scatter Cell (Green)";
		ammo="FST_blasterbolt_scatter_DP23_Green";
	};
	class FST_blaster_scatter_cell_DP23_Yellow: FST_blaster_scatter_cell_DP23_Blue
	{
		author="Gold";
		displayName="[41st] High-Power DP23 Scatter Cell (Yellow)";
		ammo="FST_blasterbolt_scatter_DP23_Yellow";
	};
	class FST_blaster_scatter_cell_DP23_Red: FST_blaster_scatter_cell_DP23_Blue
	{
		author="Gold";
		displayName="[41st] High-Power DP23 Scatter Cell (Red)";
		ammo="FST_blasterbolt_scatter_DP23_Red";
	};
	class FST_blaster_scatter_cell_SBB3_Blue: IDA_Blaster_Cell_Scatter_6Rnd_Blue
	{
		author="Gold";
		displayName="[41st] High-Power SBB3 Scatter Cell (Blue)";
		displayNameShort="HP Scatter Cell";
		descriptionShort="8 round capacity";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";	
		ammo="FST_blasterbolt_scatter_Blue";		
		scope=2;
		scopeArsenal=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		count=8;
		tracersEvery=1;
		initSpeed=250;
		mass=8;
	};
	class FST_blaster_scatter_cell_SBB3_Green: FST_blaster_scatter_cell_SBB3_Blue
	{
		author="Gold";
		displayName="[41st] High-Power SBB3 Scatter Cell (Green)";
		ammo="FST_blasterbolt_scatter_Green";
	};
	class FST_blaster_scatter_cell_SBB3_Yellow: FST_blaster_scatter_cell_SBB3_Blue
	{
		author="Gold";
		displayName="[41st] High-Power SBB3 Scatter Cell (Yellow)";
		ammo="FST_blasterbolt_scatter_Yellow";
	};
	class FST_blaster_scatter_cell_SBB3_Red: FST_blaster_scatter_cell_SBB3_Blue
	{
		author="Gold";
		displayName="[41st] High-Power SBB3 Scatter Cell (Red)";
		ammo="FST_blasterbolt_scatter_Red";
	};
	class FST_underbarrel_scatter_cell_Blue: IDA_Blaster_Cell_Power3_80Rnd_Blue
	{
		author="Gold";
		displayName="[41st] High-Power Underbarrel Scatter Cell (Blue)";
		displayNameShort="HP Scatter Cell";
		descriptionShort="5 round capacity";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";	
		ammo="FST_blasterbolt_Underbarel_scatter_Blue";
		scopeArsenal=2;
		count=5;
		initSpeed=250;
		mass=8;
	};
	class FST_underbarrel_scatter_cell_Green: FST_underbarrel_scatter_cell_Blue
	{
		author="Gold";
		displayName="[41st] High-Power Underbarrel Scatter Cell (Green)";
		ammo="FST_blasterbolt_Underbarel_scatter_Green";
	};
	class FST_underbarrel_scatter_cell_Yellow: FST_underbarrel_scatter_cell_Blue
	{
		author="Gold";
		displayName="[41st] High-Power Underbarrel Scatter Cell (Yellow)";
		ammo="FST_blasterbolt_Underbarel_scatter_Yellow";
	};
	class FST_underbarrel_scatter_cell_Red: FST_underbarrel_scatter_cell_Blue
	{
		author="Gold";
		displayName="[41st] High-Power Underbarrel Scatter Cell (Red)";
		ammo="FST_blasterbolt_Underbarel_scatter_Red";
	};
	class FST_thermal_slug_mag_Blue: IDA_Blaster_Cell_Power3_80Rnd_Blue
	{
		author="Adapted From The Indecisive Armoury Team";
		displayName="[41st] High-power Thermal Slug (Blue)";
		displayNameShort="Thermal Slug";
		descriptionShort="3 round capacity.";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		ammo="FST_thermal_slug_Blue";
		count=3;
		initSpeed=300;
		mass=8;
	};
	class FST_thermal_slug_mag_Green: FST_thermal_slug_mag_Blue
	{
		author="Gold";
		displayName="[41st] High-power Thermal Slug (Green)";
		ammo="FST_thermal_slug_Green";
	};
	class FST_thermal_slug_mag_Yellow: FST_thermal_slug_mag_Blue
	{
		author="Gold";
		displayName="[41st] High-power Thermal Slug (Yellow)";
		ammo="FST_thermal_slug_Yellow";
	};
	class FST_thermal_slug_mag_Red: FST_thermal_slug_mag_Blue
	{
		author="Gold";
		displayName="[41st] High-power Thermal Slug (Red)";
		ammo="FST_thermal_slug_Red";
	};
	class FST_EWEB_cell_Blue: IDA_Blaster_Cell_Power4_10Rnd_Blue
	{
		author="Adapted from the Indecisive Armoury Team";
		displayName="[41st] Overcharged E-Web Energy Cell (Blue)";
		displayNameShort="O/HP Energy Cell";
		descriptionShort="150 round capacity.";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		ammo="FST_blasterbolt_Overcharged_Blue";
		count=150;
		initSpeed=800;
		mass=10;
	};
	class FST_EWEB_cell_Green: FST_EWEB_cell_Blue
	{
		author="Gold";
		ammo="FST_blasterbolt_Overcharged_Green";
		displayName="[41st] Overcharged E-Web Energy Cell (Green)";
	};
	class FST_EWEB_cell_Yellow: FST_EWEB_cell_Blue
	{
		author="Gold";
		ammo="FST_blasterbolt_Overcharged_Yellow";
		displayName="[41st] Overcharged E-Web Energy Cell (Yellow)";
	};
	class FST_EWEB_cell_Red: FST_EWEB_cell_Blue
	{
		author="Gold";
		ammo="FST_blasterbolt_Overcharged_Red";
		displayName="[41st] Overcharged E-Web Energy Cell (Red)";
	};
	class FST_blaster_cell_Overcharged_Blue: IDA_Blaster_Cell_Power4_10Rnd_Blue
	{
		author="Adapted from the Indecisive Armoury Team";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		displayName="[41st] Overcharged High-Power Energy Cell (Blue)";
		displayNameShort="O/HP Energy Cell";
		descriptionShort="10 round capacity.";
		ammo="FST_blasterbolt_Overcharged_Blue";
		count=10;
		initSpeed=800;
		mass=10;
	};
	class FST_blaster_cell_Overcharged_Green: FST_blaster_cell_Overcharged_Blue
	{
		displayName="[41st] Overcharged High-Power Energy Cell (Green)";
		ammo="FST_blasterbolt_Overcharged_Green";
	};
	class FST_blaster_cell_Overcharged_Yellow: FST_blaster_cell_Overcharged_Blue
	{
		displayName="[41st] Overcharged High-Power Energy Cell (Yellow)";
		ammo="FST_blasterbolt_Overcharged_Yellow";
	};
	class FST_blaster_cell_Overcharged_Red: FST_blaster_cell_Overcharged_Blue
	{
		displayName="[41st] Overcharged High-Power Energy Cell (Red)";
		ammo="FST_blasterbolt_Overcharged_Red";
	};
	class FST_Droid_blaster_cell_Overcharged_Red: FST_blaster_cell_Overcharged_Blue
	{
		displayName="[41st] Droid Overcharged High-Power Energy Cell (Red)";
		ammo="FST_blasterbolt_Overcharged_Red";
	};
	class HandGrenade;
	class FST_grenade_emp_mag: HandGrenade
	{
		author="Adapted from JLTS";
		model="\MRC\JLTS\weapons\Grenades\grenade_emp.p3d";
		displayName="[41st] Droid Popper";
		picture="\MRC\JLTS\weapons\grenades\data\ui\grenade_emp_ui_ca.paa";
		descriptionShort="EMP Grenade";
		displayNameShort="[41st] Droid Popper";
		ammo="FST_grenade_emp_ammo";
		scope=2;
	};
	class IDA_grenade_Detonator_mag;
	class FST_grenade_Detonator_mag: IDA_grenade_Detonator_mag
	{
		author="Gold";
		displayName="[41st] Thermal Detonator";
		ammo="FST_grenade_Detonator_ammo";
		scope=2;
		mass=12;
	};
	class IDA_grenade_Penetrator_mag;
	class FST_grenade_Penetrator_mag: IDA_grenade_Penetrator_mag
	{
		author="Gold";
		displayName="[41st] Thermal Penetrator";
		ammo="FST_grenade_Penetrator_ammo";
		mass=12;
	};
	class FST_grenade_rock_mag: IDA_grenade_Penetrator_mag
	{
		author="Daara";
		displayName="[41st] ARC Major's Rock";
		descriptionShort="Major's Rock";
		ammo="FST_grenade_rock_ammo";
		mass=12;
	};
	class IDA_HE_LauncherGrenade;
	class FST_HE_LauncherGrenade: IDA_HE_LauncherGrenade
	{
		author="Adapted from the Indecisive Armoury Team";
		displayName="[41st] Impact Rifle Grenade";
		descriptionShort="Impact Grenade";
		ammo="FST_HE_RifleGrenade";
		count=1;
		mass=8;
	};
	class FST_HE_LauncherGrenade_Delayed_5: IDA_HE_LauncherGrenade
	{
		author="Gold";
		displayName="[41st] Delayed Rifle Grenade (5s)";
		descriptionShort="Delayed Grenade (5s)";
		ammo="FST_HE_RifleGrenade_Delayed_5";
		count=1;
		mass=8;
	};
	class FST_TDHE_LauncherGrenade: IDA_HE_LauncherGrenade
	{
		author="Adapted from the Indecisive Armoury Team";
		displayName="[41st] Time Delay Rifle Grenade";
		descriptionShort="Time Delay Grenade";
		ammo="FST_TDHE_RifleGrenade";
		count=1;
		mass=8;
	};
	class FST_HE_LauncherWristRocket: IDA_HE_LauncherGrenade
	{
		author="Adapted from the Indecisive Armoury Team";
		displayName="[41st] Wrist Rocket Grenade";
		descriptionShort="Impact Grenade";
		ammo="FST_HE_WristRocket";
		count=1;
		mass=8;
	};
	class IDA_Smoke_LauncherGrenade;
	class FST_Smoke_LauncherGrenade: IDA_Smoke_LauncherGrenade
	{ 
		author="Adler";
		count=1;
		displayName="[41st] 1Rnd Smoke grenade";
		displayNameShort="White Smoke";
		descriptionShort="Impact Smoke grenade";
		ammo="FST_smoke_Impact";
		mass=6;
	};
	class FST_SmokeRed_LauncherGrenade: FST_Smoke_LauncherGrenade
	{
		author="Adler";
		count=1;
		displayName="[41st] 1Rnd Smoke grenade (Red)";
		displayNameShort="Red Smoke";
		descriptionShort="Red Impact Smoke grenade";
		ammo="FST_smoke_Impact_Red";
		mass=6;
	};
	class FST_SmokeGreen_LauncherGrenade: FST_Smoke_LauncherGrenade
	{
		author="Adler";
		count=1;
		displayName="[41st] 1Rnd Smoke grenade (Green)";
		displayNameShort="Green Smoke";
		descriptionShort="Green Impact Smoke grenade";
		ammo="FST_smoke_Impact_Green";
		mass=6;
	};
	class FST_SmokeBlue_LauncherGrenade: FST_Smoke_LauncherGrenade
	{
		author="Adler";
		count=1;
		displayName="[41st] 1Rnd Smoke grenade (Blue)";
		displayNameShort="Blue Smoke";
		descriptionShort="Blue Impact Smoke grenade";
		ammo="FST_smoke_Impact_Blue";
		mass=6;
	};
	class FST_SmokePurple_LauncherGrenade: FST_Smoke_LauncherGrenade
	{
		author="Adler";
		count=1;
		displayName="[41st] 1Rnd Smoke grenade (Purple)";
		displayNameShort="Purple Smoke";
		descriptionShort="Purple Impact Smoke grenade";
		ammo="FST_smoke_Impact_Purple";
		mass=6;
	};
	class RPG32_F;
	class Titan_AT;
	class Titan_AA;
	class FST_E60R_AA_mag: Titan_AA
	{
		author="Daara";
		displayName="[41st] E60 AA Magazine";
		descriptionShort="E60 AA Missile";
		ammo="FST_Stormfury_High_Velocity_Missile";
		JLTS_hasElectronics=1;
		JLTS_hasEMPProtection=1;
	};
	class SWLW_plx1_at_mag;
	class FST_RPS6_rocket: RPG32_F
	{
		author="Daara";
		displayName="[41st] RPS-6 Rocket (AP)";
		displayNameShort="RPS-6 Rocket";
		descriptionShort="AT Rocket. Compatible with RPS-6 Rocket Launchers.";
		ammo="FST_rocket";
		Scope=2;
		initSpeed=165;
		mass=40;
	};
	class FST_RPS6_rocket_HE: RPG32_F
	{
		author="Daara";
		displayName="[41st] RPS-6 Rocket (HE)";
		displayNameShort="RPS-6 Rocket";
		descriptionShort="HE Rocket. Compatible with RPS-6 Rocket Launchers.";
		ammo="FST_rocket_HE";
		Scope=2;
		initSpeed=160;
		mass=40;
	};
	class FST_RPS6_rocket_Disposable: RPG32_F
	{
		author="Adapted from the Indecisive Armoury Team";
		displayName="[41st] RPS-6 Rocket";
		displayNameShort="RPS-6 Rocket";
		descriptionShort="HEAT Rocket. Compatible with RPS-6 Rocket Launchers.";
		ammo="FST_rocket";
		Scope=1;
		mass=40;
		initSpeed=165;
	};
	class FST_PLX1_Rocket: SWLW_plx1_at_mag
	{
		author="Adapted from the Indecisive Armoury Team";
		displayName="[41st] PLX-1 Guided Missile [AT]";
		displayNameShort="PLX-1 AT Missile";
		model="SWLW_clones\launchers\rps6\rps6_mag.p3d";
		picture="\SWLW_clones\launchers\rps6\data\ui\rps6_mag_ui.paa";
		ammo="FST_Missile";
		scope=2;
		count=1;
		initSpeed=125;
		maxLeadSpeed=57.7778;
		type=256;
		mass=50;
	};
	class FST_PLX1_AA_mag: Titan_AA
	{
		author="Daara";
		displayName="[41st] PLX-1 Guided Missile [AA]";
		descriptionShort="PLX-1 AA Missile";
		ammo="FST_Stormfury_High_Velocity_Missile";
		JLTS_hasElectronics=1;
		JLTS_hasEMPProtection=1;
		mass=50;
	};
	class IDA_FuelTank;
	class FST_FuelTank: IDA_FuelTank
	{
		author="Indecisive Armoury Team";
		picture="\MRC\JLTS\weapons\z6\data\ui\z6_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\z6\z6_mag.p3d";
		displayName="Fuel Tank";
		displayNameShort="Fuel Tank";
		descriptionShort="Liquid destruction.";
		ammo="FST_Fire";
	};
};
