#define Private 0
#define Protected 1
#define Public 2

class CfgPatches
{
	class WPS_Weapons_Sounds_Grenades
	{
		author = "Maldova";
		requiredAddons[]=
		{
			"A3_Sounds_F"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]={};
		magazines[]=
		{
		};
		ammo[]=
		{
		};	
	};
};
class CfgSoundShaders
{
	class WPS_MK1Imploder_Explosion_Close
	{
		samples[]=
		{
			
			{
				"WPS\WPS_Weapons\Sounds\Grenades\Imploder_Explosion",
				1
			},
			
			{
				"WPS\WPS_Weapons\Sounds\Grenades\Imploder_Explosion2",
				1
			}
		};
		volume=1;
		range=100;
		rangeCurve[]=
		{
			{0,1},
			{50,0.75},
			{100,0.5}
		};
	};
	class WPS_MK1Imploder_Explosion_Far
	{
		samples[]=
		{
			
			{
				"WPS\WPS_Weapons\Sounds\Grenades\Imploder_Explosion",
				1
			},
			
			{
				"WPS\WPS_Weapons\Sounds\Grenades\Imploder_Explosion2",
				1
			}
		};
		volume=1;
		range=500;
		rangeCurve[]=
		{
			{100,0.5},
			{250,0.3},
			{500,0.1}
		};
	};
	class WPS_MK1Detonator_Explosion
	{
		samples[]=
		{
			
			{
				"WPS\WPS_Weapons\Sounds\Grenades\Thermal_Explosion01",
				1
			},
			
			{
				"WPS\WPS_Weapons\Sounds\Grenades\Thermal_Explosion02",
				1
			}
		};
		volume=3;
		range=100;
		rangeCurve[]=
		{
			{0,1},
			{50,0.75},
			{100,0.5}
		};
	};
	class WPS_D19Concussion_Explosion
	{
		samples[]=
		{
			
			{
				"WPS\WPS_Weapons\Sounds\Grenades\Concussion_Explosion1",
				1
			},
			{
				"WPS\WPS_Weapons\Sounds\Grenades\Concussion_Explosion2",
				1
			},
			{
				"WPS\WPS_Weapons\Sounds\Grenades\Concussion_Explosion3",
				1
			},
			{
				"WPS\WPS_Weapons\Sounds\Grenades\Concussion_Explosion4",
				1
			}
		};
		volume=3;
		range=100;
		rangeCurve[]=
		{
			{0,1},
			{50,0.75},
			{100,0.5}
		};
	};
	class WPS_C25Frag_Explosion
	{
		samples[]=
		{
			
			{
				"WPS\WPS_Weapons\Sounds\Grenades\Grenade_Explosion_General1",
				1
			},
			
			{
				"WPS\WPS_Weapons\Sounds\Grenades\Grenade_Explosion_General2",
				1
			},
			
			{
				"WPS\WPS_Weapons\Sounds\Grenades\Grenade_Explosion_General3",
				1
			}
		};
		volume=3;
		range=100;
		rangeCurve[]=
		{
			{0,1},
			{50,0.75},
			{100,0.5}
		};
	};
	class WPS_SMK_SmokeHiss
	{
		samples[]=
		{
			
			{
				"WPS\WPS_Weapons\Sounds\Grenades\Smoke_Grenade_Hiss",
				1
			}
		};
		volume=1;
		range=50;
		rangeCurve[]=
		{
			{0,1},
			{25,0.75},
			{50,0.5}
		};
	};
};
class CfgSoundSets
{
	class WPS_MK1Imploder_Exp_Soundset
	{
		soundShaders[]=
		{
			"WPS_MK1Imploder_Explosion_Close",
			"WPS_MK1Imploder_Explosion_Far"
		};
		volumeFactor=0.94999999;
		volumeCurve="InverseSquare2Curve";
		spatial=1;
		doppler=0;
		loop=0;
		soundShadersLimit=3;
		frequencyRandomizer=0.090000001;
		sound3DProcessingType="ExplosionLightTail3DProcessingType";
		distanceFilter="explosionTailDistanceFreqAttenuationFilter";
	};
	class WPS_MK1Detonator_Exp_Soundset
	{
		soundShaders[]=
		{
			"WPS_MK1Detonator_Explosion"
		};
		volumeFactor=2.1;
		volumeCurve="InverseSquare2Curve";
		spatial=1;
		doppler=1;
		loop=0;
		soundShadersLimit=3;
		frequencyRandomizer=0.090000001;
		sound3DProcessingType="ExplosionLightTail3DProcessingType";
		distanceFilter="explosionTailDistanceFreqAttenuationFilter";
	};
	class WPS_C25Frag_Exp_Soundset
	{
		soundShaders[]=
		{
			"WPS_C25Frag_Explosion"
		};
		volumeFactor=2.1;
		volumeCurve="InverseSquare2Curve";
		spatial=1;
		doppler=0;
		loop=0;
		soundShadersLimit=3;
		frequencyRandomizer=0.090000001;
		sound3DProcessingType="ExplosionLightTail3DProcessingType";
		distanceFilter="explosionTailDistanceFreqAttenuationFilter";
	};
	class WPS_D19Concussion_Exp_Soundset
	{
		soundShaders[]=
		{
			"WPS_D19Concussion_Explosion"
		};
		volumeFactor=3.1;
		volumeCurve="InverseSquare2Curve";
		spatial=1;
		doppler=1;
		loop=0;
		soundShadersLimit=3;
		frequencyRandomizer=0.090000001;
		sound3DProcessingType="ExplosionLightTail3DProcessingType";
		distanceFilter="explosionTailDistanceFreqAttenuationFilter";
	};
	class WPS_SMK3_SmokeTrail_Soundset
	{
		soundShaders[]=
		{
			"WPS_SMK_SmokeHiss"
		};
		volumeFactor=1.1;
		volumeCurve="InverseSquare2Curve";
		spatial=1;
		doppler=0;
		loop=1;
		soundShadersLimit=3;
		frequencyRandomizer=0.090000001;
		sound3DProcessingType="ExplosionLightTail3DProcessingType";
		distanceFilter="explosionTailDistanceFreqAttenuationFilter";
	};
};
