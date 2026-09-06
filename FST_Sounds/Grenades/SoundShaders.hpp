#ifdef FST_SOUNDS_INCLUDE_SHADERS
	class FST_MK1Imploder_Explosion_Close
	{
		samples[]=
		{
			
			{
				"\FST\FST_Sounds\Grenades\Imploder_Explosion",
				1
			},
			
			{
				"\FST\FST_Sounds\Grenades\Imploder_Explosion2",
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
	class FST_MK1Imploder_Explosion_Far
	{
		samples[]=
		{
			
			{
				"\FST\FST_Sounds\Grenades\Imploder_Explosion",
				1
			},
			
			{
				"\FST\FST_Sounds\Grenades\Imploder_Explosion2",
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
	class FST_MK1Detonator_Explosion
	{
		samples[]=
		{
			
			{
				"\FST\FST_Sounds\Grenades\Thermal_Explosion01",
				1
			},
			
			{
				"\FST\FST_Sounds\Grenades\Thermal_Explosion02",
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
	class FST_D19Concussion_Explosion
	{
		samples[]=
		{
			
			{
				"\FST\FST_Sounds\Grenades\Concussion_Explosion1",
				1
			},
			{
				"\FST\FST_Sounds\Grenades\Concussion_Explosion2",
				1
			},
			{
				"\FST\FST_Sounds\Grenades\Concussion_Explosion3",
				1
			},
			{
				"\FST\FST_Sounds\Grenades\Concussion_Explosion4",
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
	class FST_C25Frag_Explosion
	{
		samples[]=
		{
			
			{
				"\FST\FST_Sounds\Grenades\Grenade_Explosion_General1",
				1
			},
			
			{
				"\FST\FST_Sounds\Grenades\Grenade_Explosion_General2",
				1
			},
			
			{
				"\FST\FST_Sounds\Grenades\Grenade_Explosion_General3",
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
	class FST_SMK_SmokeHiss
	{
		samples[]=
		{
			
			{
				"\FST\FST_Sounds\Grenades\Smoke_Grenade_Hiss",
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
#endif

#ifdef FST_SOUNDS_INCLUDE_SOUNDSETS
	class FST_MK1Imploder_Exp_Soundset
	{
		soundShaders[]=
		{
			"FST_MK1Imploder_Explosion_Close",
			"FST_MK1Imploder_Explosion_Far"
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
	class FST_MK1Detonator_Exp_Soundset
	{
		soundShaders[]=
		{
			"FST_MK1Detonator_Explosion"
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
	class FST_C25Frag_Exp_Soundset
	{
		soundShaders[]=
		{
			"FST_C25Frag_Explosion"
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
	class FST_D19Concussion_Exp_Soundset
	{
		soundShaders[]=
		{
			"FST_D19Concussion_Explosion"
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
	class FST_SMK3_SmokeTrail_Soundset
	{
		soundShaders[]=
		{
			"FST_SMK_SmokeHiss"
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
#endif
