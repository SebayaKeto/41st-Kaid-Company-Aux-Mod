class CfgPatches
{
	class FST_AV7
	{
		addonRootClass="a3_data_f";
		requiredAddons[]=
		{
			"a3_data_f"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_AV7",
			"FST_AV7_EdenOnly"
		};
		weapons[]={};
	};
};
class DefaultEventHandlers;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class RCWSOptics;
class Optics_Armored;
class Optics_Commander_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class Optics_Gunner_MBT_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class CfgAmmo
{
	class ShellBase;
	class SubmunitionBase;
	class Sh_155mm_AMOS;
	class FST_300mm_AMOS: ShellBase
	{
		hit=1200;
		indirectHit=800;
		indirectHitRange=30;
		warheadName="HE";
		dangerRadiusHit=1250;
		suppressionRadiusHit=120;
		typicalSpeed=800;
		caliber=10;
		deflecting=0;
		explosive=0.80000001;
		cost=300;
		model="\A3\weapons_f\ammo\shell";
		CraterEffects="HeavyBombCrater";
		ExplosionEffects="HeavyBombExplosion";
		whistleDist=60;
		artilleryLock=1;
		thrust=0;
		timeToLive=180;
		airFriction=0;
		sideairFriction=0;
		effectFly="3AS_PlasmaBolt_Large_Blue_Fly";
		soundSetSonicCrack[]=
		{
			"3AS_Cannon_Flyby_SoundSet"
		};
		soundHit1[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_01",
			1.7782794,
			1,
			2000
		};
		soundHit2[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_02",
			1.7782794,
			1,
			2000
		};
		soundHit3[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_03",
			1.7782794,
			1,
			2000
		};
		soundHit4[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_04",
			1.7782794,
			1,
			2000
		};
		soundHit5[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_05",
			1.7782794,
			1,
			2000
		};
		soundHit6[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_06",
			1.7782794,
			1,
			2000
		};
		soundHit7[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_07",
			1.7782794,
			1,
			2000
		};
		soundHit8[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_08",
			1.7782794,
			1,
			2000
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.125,
			"soundHit2",
			0.125,
			"soundHit3",
			0.125,
			"soundHit4",
			0.125,
			"soundHit5",
			0.125,
			"soundHit6",
			0.125,
			"soundHit7",
			0.125,
			"soundHit8",
			0.125
		};
		class CamShakeExplode
		{
			power=31;
			duration=2.4000001;
			frequency=20;
			distance=339.599;
		};
		class CamShakeHit
		{
			power=155;
			duration=0.80000001;
			frequency=20;
			distance=1;
		};
		class CamShakeFire
		{
			power=3.52844;
			duration=2.4000001;
			frequency=20;
			distance=99.599197;
		};
		class CamShakePlayerFire
		{
			power=0.0099999998;
			duration=0.1;
			frequency=20;
			distance=1;
		};
		ace_frag_charge=9979;
		ace_frag_classes[]=
		{
			"ace_frag_large",
			"ace_frag_large",
			"ace_frag_large_HD",
			"ace_frag_large",
			"ace_frag_huge",
			"ace_frag_huge_HD",
			"ace_frag_huge"
		};
		ace_frag_enabled=1;
		ace_frag_gurney_c=2440;
		ace_frag_gurney_k="1/2";
		ace_frag_metal=36000;
		ace_rearm_caliber=155;
	};
	class FST_Smoke_300mm_AMOS_White: SubmunitionBase
	{
		submunitionAmmo="SmokeShellArty";
		submunitionConeType[]=
		{
			"poissondisc",
			5
		};
		submunitionConeAngle=5;
		triggerDistance=100;
		cost=200;
		airFriction=0;
		muzzleEffect="";
		hit=300;
		soundHit1[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_01",
			1.7782794,
			1,
			2000
		};
		soundHit2[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_02",
			1.7782794,
			1,
			2000
		};
		soundHit3[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_03",
			1.7782794,
			1,
			2000
		};
		soundHit4[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_04",
			1.7782794,
			1,
			2000
		};
		soundHit5[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_05",
			1.7782794,
			1,
			2000
		};
		soundHit6[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_06",
			1.7782794,
			1,
			2000
		};
		soundHit7[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_07",
			1.7782794,
			1,
			2000
		};
		soundHit8[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_08",
			1.7782794,
			1,
			2000
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.125,
			"soundHit2",
			0.125,
			"soundHit3",
			0.125,
			"soundHit4",
			0.125,
			"soundHit5",
			0.125,
			"soundHit6",
			0.125,
			"soundHit7",
			0.125,
			"soundHit8",
			0.125
		};
		class CamShakeFire
		{
			power=3.3097501;
			duration=2.2;
			frequency=20;
			distance=87.635597;
		};
		class CamShakePlayerFire
		{
			power=0.02;
			duration=0.1;
			frequency=20;
			distance=1;
		};
	};
	class FST_300mm_AMOS_guided: SubmunitionBase
	{
		submunitionAmmo="M_Mo_155mm_AT";
		submunitionCount=1;
		submunitionConeAngle=0;
		laserLock=0;
		autoSeekTarget=1;
		cost=200;
		muzzleEffect="";
		triggerDistance=500;
		airFriction=0;
		hit=300;
		class CamShakeFire
		{
			power=3.0092199;
			duration=1.8;
			frequency=20;
			distance=72.4431;
		};
		class CamShakePlayerFire
		{
			power=0.0099999998;
			duration=0.1;
			frequency=20;
			distance=1;
		};
		soundHit1[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_01",
			1.7782794,
			1,
			2000
		};
		soundHit2[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_02",
			1.7782794,
			1,
			2000
		};
		soundHit3[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_03",
			1.7782794,
			1,
			2000
		};
		soundHit4[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_04",
			1.7782794,
			1,
			2000
		};
		soundHit5[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_05",
			1.7782794,
			1,
			2000
		};
		soundHit6[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_06",
			1.7782794,
			1,
			2000
		};
		soundHit7[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_07",
			1.7782794,
			1,
			2000
		};
		soundHit8[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_08",
			1.7782794,
			1,
			2000
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.125,
			"soundHit2",
			0.125,
			"soundHit3",
			0.125,
			"soundHit4",
			0.125,
			"soundHit5",
			0.125,
			"soundHit6",
			0.125,
			"soundHit7",
			0.125,
			"soundHit8",
			0.125
		};
	};
	class FST_300mm_AMOS_LG: SubmunitionBase
	{
		submunitionAmmo="M_Mo_155mm_AT_LG";
		submunitionCount=1;
		submunitionConeAngle=0;
		cost=500;
		laserLock=1;
		autoSeekTarget=1;
		irLock=0;
		muzzleEffect="";
		triggerDistance=500;
		airFriction=0;
		hit=300;
		soundHit1[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_01",
			1.7782794,
			1,
			2000
		};
		soundHit2[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_02",
			1.7782794,
			1,
			2000
		};
		soundHit3[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_03",
			1.7782794,
			1,
			2000
		};
		soundHit4[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_04",
			1.7782794,
			1,
			2000
		};
		soundHit5[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_05",
			1.7782794,
			1,
			2000
		};
		soundHit6[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_06",
			1.7782794,
			1,
			2000
		};
		soundHit7[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_07",
			1.7782794,
			1,
			2000
		};
		soundHit8[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_08",
			1.7782794,
			1,
			2000
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.125,
			"soundHit2",
			0.125,
			"soundHit3",
			0.125,
			"soundHit4",
			0.125,
			"soundHit5",
			0.125,
			"soundHit6",
			0.125,
			"soundHit7",
			0.125,
			"soundHit8",
			0.125
		};
		class CamShakeFire
		{
			power=3.0092199;
			duration=1.8;
			frequency=20;
			distance=72.4431;
		};
		class CamShakePlayerFire
		{
			power=0.0099999998;
			duration=0.1;
			frequency=20;
			distance=1;
		};
	};
	class FST_Mine_300mm_AMOS_range: SubmunitionBase
	{
		submunitionAmmo="Mo_ClassicMineRange";
		submunitionConeType[]=
		{
			"randomcenter",
			24
		};
		submunitionConeAngle=30;
		triggerDistance=100;
		cost=500;
		airFriction=0;
		muzzleEffect="";
		hit=300;
		soundHit1[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_01",
			1.7782794,
			1,
			2000
		};
		soundHit2[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_02",
			1.7782794,
			1,
			2000
		};
		soundHit3[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_03",
			1.7782794,
			1,
			2000
		};
		soundHit4[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_04",
			1.7782794,
			1,
			2000
		};
		soundHit5[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_05",
			1.7782794,
			1,
			2000
		};
		soundHit6[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_06",
			1.7782794,
			1,
			2000
		};
		soundHit7[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_07",
			1.7782794,
			1,
			2000
		};
		soundHit8[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_08",
			1.7782794,
			1,
			2000
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.125,
			"soundHit2",
			0.125,
			"soundHit3",
			0.125,
			"soundHit4",
			0.125,
			"soundHit5",
			0.125,
			"soundHit6",
			0.125,
			"soundHit7",
			0.125,
			"soundHit8",
			0.125
		};
		class CamShakeFire
		{
			power=3.52844;
			duration=2.4000001;
			frequency=20;
			distance=99.599197;
		};
		class CamShakePlayerFire
		{
			power=0.02;
			duration=0.1;
			frequency=20;
			distance=1;
		};
	};
	class FST_Cluster_300mm_AMOS: SubmunitionBase
	{
		triggerDistance=200;
		triggerSpeedCoef[]={0.5,1};
		submunitionConeAngle=15;
		submunitionConeType[]=
		{
			"randomcenter",
			35
		};
		submunitionAmmo[]=
		{
			"Mo_cluster_AP",
			0.93000001,
			"Mo_cluster_AP_UXO_deploy",
			0.07
		};
		cost=200;
		airFriction=0;
		muzzleEffect="";
		hit=300;
		soundHit1[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_01",
			1.7782794,
			1,
			2000
		};
		soundHit2[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_02",
			1.7782794,
			1,
			2000
		};
		soundHit3[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_03",
			1.7782794,
			1,
			2000
		};
		soundHit4[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_04",
			1.7782794,
			1,
			2000
		};
		soundHit5[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_05",
			1.7782794,
			1,
			2000
		};
		soundHit6[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_06",
			1.7782794,
			1,
			2000
		};
		soundHit7[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_07",
			1.7782794,
			1,
			2000
		};
		soundHit8[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_08",
			1.7782794,
			1,
			2000
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.125,
			"soundHit2",
			0.125,
			"soundHit3",
			0.125,
			"soundHit4",
			0.125,
			"soundHit5",
			0.125,
			"soundHit6",
			0.125,
			"soundHit7",
			0.125,
			"soundHit8",
			0.125
		};
		class CamShakeFire
		{
			power=3.52844;
			duration=2.4000001;
			frequency=20;
			distance=99.599197;
		};
		class CamShakePlayerFire
		{
			power=0.02;
			duration=0.1;
			frequency=20;
			distance=1;
		};
	};
	class FST_AT_Mine_300mm_AMOS_range: SubmunitionBase
	{
		submunitionAmmo="Mo_ATMineRange";
		submunitionConeType[]=
		{
			"randomcenter",
			12
		};
		submunitionConeAngle=30;
		triggerDistance=100;
		cost=500;
		airFriction=0;
		muzzleEffect="";
		hit=300;
		soundHit1[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_01",
			1.7782794,
			1,
			2000
		};
		soundHit2[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_02",
			1.7782794,
			1,
			2000
		};
		soundHit3[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_03",
			1.7782794,
			1,
			2000
		};
		soundHit4[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_04",
			1.7782794,
			1,
			2000
		};
		soundHit5[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_05",
			1.7782794,
			1,
			2000
		};
		soundHit6[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_06",
			1.7782794,
			1,
			2000
		};
		soundHit7[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_07",
			1.7782794,
			1,
			2000
		};
		soundHit8[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_shell_explosion_08",
			1.7782794,
			1,
			2000
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.125,
			"soundHit2",
			0.125,
			"soundHit3",
			0.125,
			"soundHit4",
			0.125,
			"soundHit5",
			0.125,
			"soundHit6",
			0.125,
			"soundHit7",
			0.125,
			"soundHit8",
			0.125
		};
		class CamShakeFire
		{
			power=3.52844;
			duration=2.4000001;
			frequency=20;
			distance=99.599197;
		};
		class CamShakePlayerFire
		{
			power=0.02;
			duration=0.1;
			frequency=20;
			distance=1;
		};
	};
};
class CfgMagazines
{
	class VehicleMagazine;
	class FST_32Rnd_300mm_Mo_shells: VehicleMagazine
	{
		author="$STR_3as_Studio";
		initSpeed=810;
		scope=2;
		displayName="[41st] AV7 High Explosive Shells";
		displayNameShort="HE";
		displayNameMFDFormat="HE";
		ammo="FST_300mm_AMOS";
		count=32;
		nameSound="heat";
		muzzleImpulseFactor[]={1.5,10};
	};
	class FST_12Rnd_300mm_Mo_smoke: FST_32Rnd_300mm_Mo_shells
	{
		author="$STR_3as_Studio";
		count=12;
		ammo="FST_Smoke_300mm_AMOS_White";
		displayName="[41st] AV7 White Smoke Shells";
		displayNameShort="[41st] Smoke (White)";
		displayNameMFDFormat="SMOKE";
	};
	class FST_4Rnd_300mm_Mo_guided: FST_12Rnd_300mm_Mo_smoke
	{
		author="$STR_3as_Studio";
		count=4;
		ammo="FST_300mm_AMOS_guided";
		displayName="[41st] AV7 Guided Explosive Shells";
		displayNameShort="[41st] Guided";
		displayNameMFDFormat="GUIDED";
	};
	class FST_4Rnd_300mm_Mo_LG: FST_12Rnd_300mm_Mo_smoke
	{
		author="$STR_3as_Studio";
		count=4;
		ammo="FST_300mm_AMOS_LG";
		displayName="[41st] AV7 Laser Guided Shell";
		displayNameShort="[41st] Laser Guided";
		displayNameMFDFormat="LASER GUID";
	};
	class FST_12Rnd_300mm_Mo_mine: FST_12Rnd_300mm_Mo_smoke
	{
		author="$STR_3as_Studio";
		ammo="FST_Mine_300mm_AMOS_range";
		displayName="[41st] AV7 Mine Cluster Shell";
		displayNameShort="[41st] Mine Cluster";
		displayNameMFDFormat="MINE";
	};
	class FST_4Rnd_300mm_Mo_Cluster: FST_12Rnd_300mm_Mo_smoke
	{
		author="$STR_3as_Studio";
		count=4;
		ammo="FST_Cluster_300mm_AMOS";
		displayName="[41st] AV7 Cluster Shell";
		displayNameShort="[41st] Cluster";
		displayNameMFDFormat="CLUSTER";
	};
	class FST_12Rnd_300mm_Mo_AT_mine: FST_12Rnd_300mm_Mo_smoke
	{
		author="$STR_3as_Studio";
		ammo="FST_AT_Mine_300mm_AMOS_range";
		displayName="[41st] AV7 Anti-Tank Mine Cluster Shell";
		displayNameShort="[41st] AT Mine Cluster";
		displayNameMFDFormat="AT MINE";
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class CfgWeapons
{
	class 3AS_AV7_300mm_AMOS;
	class BaseSoundModeType;
	class FST_AV7_Cannon: 3AS_AV7_300mm_AMOS{
		scope=1;
		displayName="[41st] AV7_300mm_Cannon";
		reloadSound[]=
		{
			"A3\Sounds_F\arsenal\weapons_vehicles\cannon_120mm\Cannon_120mm_Reload_01",
			2.5118864,
			1,
			10
		};
		reloadTime=7;
		magazineReloadTime=7;
		autoReload=1;
		canLock=0;
		magazines[]=
		{
			"FST_32Rnd_300mm_Mo_shells",
			"FST_12Rnd_300mm_Mo_smoke",
			"FST_4Rnd_300mm_Mo_guided",
			"FST_4Rnd_300mm_Mo_LG",
			"FST_12Rnd_300mm_Mo_mine",
			"FST_4Rnd_300mm_Mo_Cluster",
			"FST_12Rnd_300mm_Mo_AT_mine"
		};
		modes[]=
		{
			"Single1",
			"Single2",
			"Single3",
			"Single4",
			"Single5",
			"Burst1",
			"Burst2",
			"Burst3",
			"Burst4",
			"Burst5"
		};
		class GunParticles
		{
			class Effect1
			{
				effectName="ArtilleryFired1";
				positionName="MainCannon_Barrel";
				directionName="MainCannon_Barrel_Dir";
			};
		};
		class Single1: Mode_SemiAuto
		{
			displayName="$STR_A3_mortar_120mm_AMOS_Single10";
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[] = { "3AS_HeavyTurboLaser_SoundSet" };
			};
			reloadTime=4;
			artilleryDispersion=3.2;
			artilleryCharge=0.19;
			aiRateOfFire=1;
			aiRateOfFireDistance=10;
			minRange=0;
			minRangeProbab=0.0099999998;
			midRange=1;
			midRangeProbab=0.0099999998;
			maxRange=2;
			maxRangeProbab=0.0099999998;
		};
		class Single2: Single1
		{
			displayName="$STR_A3_mortar_120mm_AMOS_Single20";
			artilleryCharge=0.30000001;
		};
		class Single3: Single1
		{
			displayName="$STR_A3_mortar_120mm_AMOS_Single30";
			artilleryCharge=0.47999999;
		};
		class Single4: Single1
		{
			displayName="$STR_A3_mortar_120mm_AMOS_Single40";
			artilleryCharge=0.80000001;
		};
		class Single5: Single1
		{
			displayName="$STR_A3_mortar_120mm_AMOS_Single50";
			artilleryCharge=1;
		};
		class Burst1: Mode_Burst
		{
			showToPlayer=0;
			displayName="$STR_A3_mortar_120mm_AMOS_Burst10";
			burst=6;
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[] = { "3AS_HeavyTurboLaser_SoundSet" };
			};
			soundBurst=0;
			reloadTime=6;
			minRange=800;
			minRangeProbab=0.5;
			midRange=1500;
			midRangeProbab=0.69999999;
			maxRange=2000;
			maxRangeProbab=0.5;
			artilleryDispersion=5.3000002;
			artilleryCharge=0.19;
		};
		class Burst2: Burst1
		{
			showToPlayer=0;
			displayName="$STR_A3_mortar_120mm_AMOS_Burst20";
			minRange=2000;
			minRangeProbab=0.40000001;
			midRange=3000;
			midRangeProbab=0.60000002;
			maxRange=5200;
			maxRangeProbab=0.40000001;
			artilleryCharge=0.30000001;
		};
		class Burst3: Burst1
		{
			showToPlayer=0;
			displayName="$STR_A3_mortar_120mm_AMOS_Burst30";
			minRange=5200;
			minRangeProbab=0.30000001;
			midRange=8000;
			midRangeProbab=0.40000001;
			maxRange=13300;
			maxRangeProbab=0.30000001;
			artilleryCharge=0.47999999;
		};
		class Burst4: Burst1
		{
			showToPlayer=0;
			displayName="$STR_A3_mortar_120mm_AMOS_Burst40";
			minRange=14600;
			minRangeProbab=0.2;
			midRange=25000;
			midRangeProbab=0.30000001;
			maxRange=37000;
			maxRangeProbab=0.2;
			artilleryCharge=0.80000001;
		};
		class Burst5: Burst1
		{
			showToPlayer=0;
			displayName="$STR_A3_mortar_120mm_AMOS_Burst50";
			minRange=25000;
			minRangeProbab=0.1;
			midRange=40000;
			midRangeProbab=0.2;
			maxRange=58000;
			maxRangeProbab=0.1;
			artilleryCharge=1;
		};
	};
};
class CfgVehicles
{
	class LandVehicle;
	class Tank: LandVehicle
	{
		class NewTurret;
		class Sounds;
		class HitPoints;
	};
	class Tank_F: Tank
	{
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewGunner;
				class Turrets
				{
					class CommanderOptics;
				};
			};
		};
		class AnimationSources;
	};
	class MBT_01_base_F: Tank_F
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
				};
			};
		};
	};
	class 3AS_01_arty_base_F: MBT_01_base_F{};
	class FST_AV7: 3AS_01_arty_base_F
	{
		author="Adapted from 3AS";
		displayName="[41st] AV-7 Field Cannon Artillery";
		scope=2;
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		generalMacro="B_MBT_01_arty_base_F";
		tas_canBlift=1;
		tas_liftVars="[[[[0,-4,-6.5]]], [-0.001], [-0.4]]";
		crew="FST_Trooper_P2_DC15S";
		typicalCargo[]=
		{
			"FST_Trooper_P2_DC15S"
		};
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\AV-7\Data\av7_co.paa"
		};
		side=1;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
				};
				animationSourceHatch="";
				gunnerForceOptics=0;
				usePip=2;
				ejectDeadGunner=1;
				selectionFireAnim="zasleh";
				forceHideGunner=1;
				viewGunnerInExternal=1;
				gunBeg="MainCannon_Barrel";
				gunEnd="MainCannon_Chamber";
				gunnerAction="AV7_Driver";
				gunnerInAction="AV7_Driver";
				gunnerGetInAction="GetInHigh";
				gunnerGetOutAction="GetOutHigh";
				animationSourceStickX="turret_control_x";
				animationSourceStickY="turret_control_y";
				gunnerLeftHandAnimName="turret_control_y";
				gunnerRightHandAnimName="turret_control_y";
				memorypointsgetingunner="pos_driver";
				memorypointsgetingunnerdir="pos_driver_dir";
				LODTurnedIn=1000;
				LODOpticsIn=0;
				minElev=-5;
				maxElev=80;
				initElev=10;
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner",
					0.15848932,
					1,
					30
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner_vertical",
					0.15848932,
					1,
					30
				};
				weapons[]=
				{
					"FST_AV7_Cannon"
				};
				magazines[]=
				{
					"FST_32Rnd_300mm_Mo_shells",
					"FST_12Rnd_300mm_Mo_smoke",
					"FST_4Rnd_300mm_Mo_guided",
					"FST_4Rnd_300mm_Mo_LG",
					"FST_4Rnd_300mm_Mo_LG",
					"FST_12Rnd_300mm_Mo_mine",
					"FST_4Rnd_300mm_Mo_Cluster",
					"FST_4Rnd_300mm_Mo_Cluster",
					"FST_12Rnd_300mm_Mo_AT_mine"
				};
			};
		};
	};
	class FST_AV7_EdenOnly: 3AS_01_arty_base_F
	{
		author="Adapted from 3AS";
		forceingarage=0;
		displayName="[41st] AV-7 (Eden ONLY // Legs Deployed)";
		scope=2;
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		generalMacro="B_MBT_01_arty_base_F";
		tas_canBlift=1;
		tas_liftVars="[[[[0,-4,-6.5]]], [-0.001], [-0.4]]";
		crew="FST_Trooper_P2_DC15S";
		typicalCargo[]=
		{
			"FST_Trooper_P2_DC15S"
		};
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\AV-7\Data\av7_co.paa"
		};
		side=1;
		class AnimationSources: AnimationSources
		{
			class Legs
			{
				source="user";
				animPeriod=0;
				initPhase=1;
				mass=1;
				author="$STR_3AS_Studio";
				displayName="Toggle Legs";
				onPhaseChanged="_this call TAS_fnc_toggleLegs;";
			};
		};
	};
};
class CfgFunctions
{
	class TAS
	{
		class AV7Fncs
		{
			file="\3as\3AS_AV7\functions";
			class toggleLegs
			{
			};
		};
	};
};
