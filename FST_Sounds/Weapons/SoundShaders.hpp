#ifdef FST_SOUNDS_INCLUDE_SHADERS
	//Blaster Bolt Effects
	class FST_BlasterBolt_FlyBy
	{
		samples[] = {{"\FST\FST_Sounds\Weapons\Blaster_Fly-01.ogg",1},{"\FST\FST_Sounds\Weapons\Blaster_Fly-02.ogg",1},{"\FST\FST_Sounds\Weapons\Blaster_Fly-03.ogg",1},{"\FST\FST_Sounds\Weapons\Blaster_Fly-04.ogg",1},{"\FST\FST_Sounds\Weapons\Blaster_Fly-05.ogg",1},{"\FST\FST_Sounds\Weapons\Blaster_Fly-06.ogg",1},{"\FST\FST_Sounds\Weapons\Blaster_Fly-07.ogg",1},{"\FST\FST_Sounds\Weapons\Blaster_Fly-08.ogg",1},{"\FST\FST_Sounds\Weapons\Blaster_Fly-09.ogg",1},{"\FST\FST_Sounds\Weapons\Blaster_Fly-10.ogg",1}};
		volume = 1;
		range = 50;
	};
	class FST_DC15_ShotClose
	{
		samples[]=
		{
			{
				"\FST\FST_Sounds\Weapons\BlasterGenericOne",
				1
			},
			
			{
				"\FST\FST_Sounds\Weapons\BlasterGenericTwo",
				1
			}
		};
		volume=1;
		range=200;
		rangeCurve[]=
		{
			{0,1},
			{100,0.75},
			{200,0.5}
		};
	};
	class FST_DC15_ShotFar
	{
		samples[]=
		{
			{
				"\FST\FST_Sounds\Weapons\BlasterGenericOne",
				1
			},
			
			{
				"\FST\FST_Sounds\Weapons\BlasterGenericTwo",
				1
			}
		};
		volume=1;
		range=500;
		rangeCurve[]=
		{
			{200,0.5},
			{300,0.3},
			{500,0.1}
		};
	};
	class FST_DC17_ShotClose
	{
		samples[]=
		{
			
			{
				"\FST\FST_Sounds\Weapons\BlasterDC17One",
				1
			},
			
			{
				"\FST\FST_Sounds\Weapons\BlasterDC17Two",
				1
			}
		};
		volume=1;
		range=200;
		rangeCurve[]=
		{
			{0,1},
			{100,0.75},
			{200,0.5}
		};
	};
	class FST_DC17_ShotFar
	{
		samples[]=
		{
			
			{
				"\FST\FST_Sounds\Weapons\BlasterDC17One",
				1
			},
			
			{
				"\FST\FST_Sounds\Weapons\BlasterDC17Two",
				1
			}
		};
		volume=1;
		range=400;
		rangeCurve[]=
		{
			{200,0.5},
			{300,0.3},
			{400,0.1}
		};
	};
	//Flamethrower Effects
	class FST_BTX42_FlamesClose
	{
		samples[]=
		{
			{
				"\FST\FST_Sounds\Weapons\BTX42Fire",
				1
			}
		};
		volume=1;
		range=200;
		rangeCurve[]=
		{
			{0,1},
			{100,0.75},
			{150,0.5}
		};
	};
	// Shotgun Sound Effects
	class FST_Shotgun_Close
	{
		samples[]=
		{
			{
				"\FST\FST_Sounds\Weapons\DLT18Shotgun-01",
				1
			},
			{
				"\FST\FST_Sounds\Weapons\DLT18Shotgun-02",
				1
			},
			{
				"\FST\FST_Sounds\Weapons\DLT18Shotgun-03",
				1
			}
		};
		volume=1;
		range=200;
		rangeCurve[]=
		{
			{0,1},
			{100,0.70},
			{200,0.5}
		};
	};
	//PLX Missile Effects
	class FST_PLX_RocketFly
	{
		samples[]=
		{
			{
				"\FST\FST_Sounds\Weapons\PLX_MissileFly",
				1
			}
		};
		volume=1;
		range=300;
		rangeCurve[]=
		{
			{0,1},
			{150,0.70},
			{300,0.25}
		};
	};
	class FST_Sabre_Missile_Explosion
	{
		samples[] =
		{
			{"\FST\FST_Sounds\Weapons\Explosion_RangeMedium-01.ogg",1},
			{"\FST\FST_Sounds\Weapons\Explosion_RangeMedium-01-2.ogg",1},
			{"\FST\FST_Sounds\Weapons\Explosion_RangeMedium-02.ogg",1},
			{"\FST\FST_Sounds\Weapons\Explosion_RangeMedium-03.ogg",1}
		};
		volume = 1.5;
		range = 1800;
		rangeCurve[] = {{0,1},{100,0.9},{500,0.45},{1000,0.18},{1800,0}};
	};
	class FST_Sabre_Commander_BlasterBody
	{
		samples[] =
		{
			{"\FST\FST_Sounds\Weapons\BlasterGenericOne.wss",1},
			{"\FST\FST_Sounds\Weapons\BlasterGenericTwo.wss",1},
			{"\FST\FST_Sounds\Weapons\BlasterGenericThree.wss",1}
		};
		volume = 1;
		range = 700;
		rangeCurve[] = {{0,1},{100,0.82},{350,0.4},{700,0}};
	};
	class FST_Sabre_Commander_BlasterTransient
	{
		samples[] =
		{
			{"\FST\FST_Sounds\Weapons\BlasterGenericFour.wss",1},
			{"\FST\FST_Sounds\Weapons\BlasterGenericFive.wss",1}
		};
		volume = 0.65;
		range = 450;
		rangeCurve[] = {{0,1},{75,0.75},{225,0.3},{450,0}};
	};
	class FST_Sabre_MainCannon_EWEB
	{
		samples[] =
		{
			{"\FST\FST_Sounds\Weapons\EWEB_Shot_-01.ogg",1},
			{"\FST\FST_Sounds\Weapons\EWEB_Shot_-01-2.ogg",1},
			{"\FST\FST_Sounds\Weapons\EWEB_Shot_-01-3.ogg",1},
			{"\FST\FST_Sounds\Weapons\EWEB_Shot_-01-4.ogg",1}
		};
		volume = 1.25;
		range = 1400;
		rangeCurve[] = {{0,1},{150,0.85},{500,0.45},{900,0.2},{1400,0}};
	};
#endif

#ifdef FST_SOUNDS_INCLUDE_SOUNDSETS
	class FST_DC15Soundset_Shot
	{
		soundShaders[]=
		{
			"FST_DC15_ShotClose",
			"FST_DC15_ShotFar"
		};
		volumeFactor=0.94999999;
		volumeCurve="InverseSquare2Curve";
		spatial=0;
		doppler=0;
		loop=0;
		soundShadersLimit=3;
		frequencyRandomizer=0.090000001;
		sound3DProcessingType = "WeaponMediumShot3DProcessingType";
		distanceFilter = "weaponShotDistanceFreqAttenuationFilter";
	};
	class FST_BTX42Soundset_Shot
	{
		soundShaders[]=
		{
			"FST_BTX42_FlamesClose"
		};
		volumeFactor=0.90999999;
		volumeCurve="InverseSquare2Curve";
		spatial=1;
		doppler=0;
		loop=0;
		soundShadersLimit=3;
		frequencyRandomizer=0.090000001;
		sound3DProcessingType = "WeaponMediumShot3DProcessingType";
		distanceFilter = "weaponShotDistanceFreqAttenuationFilter";
	};
	class FST_DC15Soundset_Shot_Suppressed
	{
		soundShaders[]=
		{
			"FST_DC15_ShotClose"
		};
		volumeFactor=0.74999999;
		volumeCurve="InverseSquare2Curve";
		spatial=0;
		doppler=0;
		loop=0;
		soundShadersLimit=3;
		frequencyRandomizer=0.090000001;
		sound3DProcessingType = "WeaponMediumShot3DProcessingType";
		distanceFilter = "weaponShotDistanceFreqAttenuationFilter";
	};
	class FST_DC17Soundset_Shot
	{
		soundShaders[]=
		{
			"FST_DC17_ShotClose",
			"FST_DC17_ShotFar"
		};
		volumeFactor=0.94999999;
		volumeCurve="InverseSquare2Curve";
		spatial=1;
		doppler=1;
		loop=0;
		soundShadersLimit=4;
		frequencyRandomizer=0.090000001;
		sound3DProcessingType = "WeaponMediumShot3DProcessingType";
		distanceFilter = "weaponShotDistanceFreqAttenuationFilter";
	};
	class FST_DC17Soundset_Shot_Suppressed
	{
		soundShaders[]=
		{
			"FST_DC17_ShotClose"
		};
		volumeFactor=0.74999999;
		volumeCurve="InverseSquare2Curve";
		spatial=0;
		doppler=0;
		loop=0;
		soundShadersLimit=3;
		frequencyRandomizer=0.090000001;
		sound3DProcessingType = "WeaponMediumShot3DProcessingType";
		distanceFilter = "weaponShotDistanceFreqAttenuationFilter";
	};
	class FST_BlasterBolt_FlyBy_Soundset
	{
		soundShaders[] = {"FST_BlasterBolt_FlyBy"};
		volumeFactor = 1.0;
		volumeCurve = "InverseSquare2Curve";
		sound3DProcessingType = "WeaponMediumShot3DProcessingType";
		distanceFilter = "weaponShotDistanceFreqAttenuationFilter";
		occlusionFactor = 0.5;
		obstructionFactor = 0.3;
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
	class FST_ShotgunBase_Soundset
	{
		soundShaders[] = {"FST_Shotgun_Close"};
		volumeFactor = 1.0;
		volumeCurve = "InverseSquare2Curve";
		sound3DProcessingType = "WeaponMediumShot3DProcessingType";
		distanceFilter = "weaponShotDistanceFreqAttenuationFilter";
		occlusionFactor = 0.5;
		obstructionFactor = 0.3;
		spatial = 1;
		doppler = 0;
		loop = 0;

	};
	class FST_PLX_MissileFlyBy_Soundset
	{
		soundShaders[] = {"FST_PLX_RocketFly"};
		volumeFactor = 1.0;
		volumeCurve = "InverseSquare2Curve";
		sound3DProcessingType = "WeaponMediumShot3DProcessingType";
		distanceFilter = "weaponShotDistanceFreqAttenuationFilter";
		occlusionFactor = 0.5;
		obstructionFactor = 0.3;
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
	class FST_Sabre_Missile_Explosion_SoundSet
	{
		soundShaders[] = {"FST_Sabre_Missile_Explosion"};
		volumeFactor = 1;
		volumeCurve = "InverseSquare2Curve";
		sound3DProcessingType = "ExplosionLightTail3DProcessingType";
		distanceFilter = "explosionTailDistanceFreqAttenuationFilter";
		occlusionFactor = 0.35;
		obstructionFactor = 0.2;
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
	class FST_Sabre_Commander_MG_SoundSet
	{
		soundShaders[] = {"FST_Sabre_Commander_BlasterBody","FST_Sabre_Commander_BlasterTransient"};
		volumeFactor = 0.95;
		volumeCurve = "InverseSquare2Curve";
		sound3DProcessingType = "WeaponMediumShot3DProcessingType";
		distanceFilter = "weaponShotDistanceFreqAttenuationFilter";
		occlusionFactor = 0.5;
		obstructionFactor = 0.3;
		spatial = 1;
		doppler = 0;
		loop = 0;
		soundShadersLimit = 4;
		frequencyRandomizer = 0.04;
	};
	class FST_Sabre_MainCannon_EWEB_SoundSet
	{
		soundShaders[] = {"FST_Sabre_MainCannon_EWEB"};
		volumeFactor = 1;
		volumeCurve = "InverseSquare2Curve";
		sound3DProcessingType = "WeaponMediumShot3DProcessingType";
		distanceFilter = "weaponShotDistanceFreqAttenuationFilter";
		occlusionFactor = 0.45;
		obstructionFactor = 0.25;
		spatial = 1;
		doppler = 0;
		loop = 0;
		soundShadersLimit = 2;
		frequencyRandomizer = 0.025;
	};
#endif
