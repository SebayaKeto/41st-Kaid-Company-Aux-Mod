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