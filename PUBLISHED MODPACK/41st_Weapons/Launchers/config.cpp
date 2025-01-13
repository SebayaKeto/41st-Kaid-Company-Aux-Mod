class CfgPatches
{
	class FST_Launchers
	{
		author="Daara";
		requiredAddons[]=
		{
			"A3_data_F",
			"A3_anims_F",
			"A3_weapons_F",
			"A3_characters_F",
			"ls_weapons",
			"A3_Characters_F_Proxies"
		};
		units[]={};
		weapons[]=
		{
			"FST_PLX1",
			"FST_PLX1_Guided",
			"FST_RPS6HP",
			"FST_RPS6_Disposable",
			"FST_RPS6_Used"
		};
		magazines[]=
		{
			"FST_RPS6_rocket_Disposable"
		};
	};
};
class CfgAmmo
{
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
};
class CfgMagazines
{
	class RPG32_F;
	class Titan_AT;
	class Titan_AA;
	class FST_RPS6_rocket: RPG32_F
	{
		author="Daara";
		Scope=2;
		displayName="[41st] RPS-6 Rocket (AP)";
		displayNameShort="RPS-6 Rocket";
		ammo="FST_rocket";
		descriptionShort="AT Rocket. Compatible with RPS-6 Rocket Launchers.";
		initSpeed=165;
		mass=40;
	};
	class FST_RPS6_rocket_HE: RPG32_F
	{
		author="Daara";
		Scope=2;
		displayName="[41st] RPS-6 Rocket (HE)";
		displayNameShort="RPS-6 Rocket";
		ammo="FST_rocket_HE";
		descriptionShort="HE Rocket. Compatible with RPS-6 Rocket Launchers.";
		initSpeed=160;
		mass=40;
	};
	class FST_RPS6_rocket_Disposable: RPG32_F
	{
		author="Adapted from the Indecisive Armoury Team";
		Scope=1;
		displayName="[41st] RPS-6 Rocket";
		displayNameShort="RPS-6 Rocket";
		ammo="FST_rocket";
		descriptionShort="HEAT Rocket. Compatible with RPS-6 Rocket Launchers.";
		mass=40;
		initSpeed=165;
	};
	class FST_PLX1_Rocket: Titan_AT
	{
		author="Viz";
		scope=2;
		displayName="[41st] PLX-1 Guided Missile [AT]";
		displayNameShort="PLX-1 AT Missile";
		count=1;
		model="SWLW_clones\launchers\rps6\rps6_mag.p3d";
		picture="\SWLW_clones\launchers\rps6\data\ui\rps6_mag_ui.paa";
		ammo="FST_Missile";
		initSpeed=30;
		maxLeadSpeed=30;
		type="6 * 256";
		mass=50;
	};
	class FST_PLX1_AA_mag: Titan_AA
	{
		JLTS_hasElectronics=1;
		JLTS_hasEMPProtection=1;
		author="Daara";
		displayName="[41st] PLX-1 Guided Missile [AA]";
		descriptionShort="PLX-1 AA Missile";
		ammo="FST_Stormfury_High_Velocity_Missile";
		mass=50;
	};
};
class CowsSlot;
class UnderBarrelSlot;
class MuzzleSlot;
class PointerSlot;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CBA_DisposableLaunchers
{
	FST_RPS6_Base[]=
	{
		"FST_RPS6_Disposable",
		"FST_RPS6_Used"
	};
};
class CfgWeapons
{
	class WeaponSlotsInfo;
	class Launcher_Base_F;
	class launch_RPG32_F: Launcher_Base_F
	{
		class WeaponSlotsInfo;
	};
	class launch_B_Titan_Short_F;
	class FST_PLX1_Base: launch_B_Titan_Short_F
	{
		class WeaponSlotsInfo;
		class Single;
		class TopDown;
		scope=1;
		author="Viz";
	};
	class FST_PLX1: FST_PLX1_Base
	{
		author = "Viz"
		displayName="[41st] PLX-1 Rocket launcher [Mk.V]";
		model="\MRC\JLTS\weapons\PLX1\PLX1.p3d";
		picture="\MRC\JLTS\weapons\PLX1\data\ui\PLX1_ui_ca.paa";
		uiPicture="MRC\JLTS\weapons\PLX1\data\ui\PLX1_ui_ca.paa";
		modelOptics="\A3\Weapons_F_Beta\acc\reticle_titan.p3d";
		scope=2;
		scopecurator=2;
		ace_overpressure_angle=45;
		ace_overpressure_damage=0.69999999;
		ace_overpresssure_priority=1;
		ace_overpressure_range=10;
		ace_reloadlaunchers_enabled=1;
		ace_javelin_enabled=1;
		canLock= 0;
		reloadAction="ReloadRPG";
		recoil="recoil_titan_short";
		maxZeroing=3000;
		shotPos="muzzlePos2";
		shotEnd="muzzleEnd2";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\MRC\JLTS\weapons\PLX1\anims\PLX1_handanim.rtm"
		};
		magazines[]=
		{
			"FST_PLX1_Rocket",
			"FST_PLX1_AA_mag"
		};
		magazineWell[]={};
		cameraDir="look";
		class Single: Single
		{
			class BaseSoundModeType
			{
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]=
				{
					"ls_sounds\weapons\launcher\PLX_shot.wss",
					10,
					1,
					2000
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
		};
		class TopDown: TopDown
		{
			class BaseSoundModeType
			{
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]=
				{
					"ls_sounds\weapons\launcher\PLX_shot.wss",
					10,
					1,
					2000
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
		};
		drySound[]=
		{
			"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Dry_Titan",
			0.15848932,
			1,
			18
		};
		reloadMagazineSound[]=
		{
			"A3\Sounds_F\arsenal\weapons\Launchers\Titan\reload_Titan",
			1,
			1,
			20
		};
		lockingTargetSound[]=
		{
			"A3\Sounds_F\arsenal\weapons\Launchers\Titan\locking_Titan",
			0.31622776,
			1
		};
		lockedTargetSound[]=
		{
			"A3\Sounds_F\arsenal\weapons\Launchers\Titan\locked_Titan",
			0.31622776,
			2.5
		};
		class GunParticles
		{
			class effect1
			{
				positionName="muzzleEnd2";
				directionName="muzzlePos2";
				effectName="RocketBackEffectsNLAWNT";
			};
		};
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"camo3"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\weapons\PLX1\data\PLX1_body_co.paa",
			"\MRC\JLTS\weapons\PLX1\data\PLX1_tube_co.paa",
			"\MRC\JLTS\weapons\PLX1\data\PLX1_mag_co.paa"
		};
		class Library
		{
			libTextDesc="";
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=200;
		};
		inertia=1.1;
		initSpeed=30;
	};
	class FST_PLX1_Guided: Launcher_Base_F
	{
		author = "Viz"
		displayName="[41st] PLX-1 Rocket launcher [Mk.A]";
		model="\MRC\JLTS\weapons\PLX1\PLX1.p3d";
		picture="\MRC\JLTS\weapons\PLX1\data\ui\PLX1_ui_ca.paa";
		uiPicture="MRC\JLTS\weapons\PLX1\data\ui\PLX1_ui_ca.paa";
		modelOptics="\A3\Weapons_F_Beta\acc\reticle_titan.p3d";
		scope=2;
		scopecurator=2;
		ace_overpressure_angle=45;
		ace_overpressure_damage=0.69999999;
		ace_overpresssure_priority=1;
		ace_overpressure_range=10;
		ace_reloadlaunchers_enabled=1;
		ace_javelin_enabled=1;
		canLock= 0;
		reloadAction="ReloadRPG";
		recoil="recoil_titan_short";
		maxZeroing=3000;
		shotPos="muzzlePos2";
		shotEnd="muzzleEnd2";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\MRC\JLTS\weapons\PLX1\anims\PLX1_handanim.rtm"
		};
		magazines[]=
		{
			"FST_PLX1_Rocket",
			"FST_PLX1_AA_mag"
		};
		magazineWell[]={};
		cameraDir="look";
		modes[]=
		{
			"Single",
			"TopDown"
		};
		class Single: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]=
				{
					"3AS\3AS_Weapons\PLX1\Sounds\PLX_Fire.ogg",
					3.1622777,
					1,
					2000
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			recoil="recoil_single_titan";
			aiRateOfFire=7;
			aiRateOfFireDistance=1500;
			minRange=70;
			minRangeProbab=0.89999998;
			midRange=300;
			midRangeProbab=0.80000001;
			maxRange=2000;
			maxRangeProbab=0.80000001;
		};
		class TopDown: Single
		{
			textureType="topDown";
			displayName="Top-down Attack";
			aiRateOfFire=7;
			aiRateOfFireDistance=1500;
			minRange=150;
			minRangeProbab=0.80000001;
			midRange=500;
			midRangeProbab=0.94999999;
			maxRange=2000;
			maxRangeProbab=0.94999999;
		};
		drySound[]=
		{
			"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Dry_Titan",
			0.15848932,
			1,
			18
		};
		reloadMagazineSound[]=
		{
			"A3\Sounds_F\arsenal\weapons\Launchers\Titan\reload_Titan",
			1,
			1,
			20
		};
		lockingTargetSound[]=
		{
			"A3\Sounds_F\arsenal\weapons\Launchers\Titan\locking_Titan",
			0.31622776,
			1
		};
		lockedTargetSound[]=
		{
			"A3\Sounds_F\arsenal\weapons\Launchers\Titan\locked_Titan",
			0.31622776,
			2.5
		};
		class GunParticles
		{
			class effect1
			{
				positionName="muzzleEnd2";
				directionName="muzzlePos2";
				effectName="RocketBackEffectsNLAWNT";
			};
		};
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"camo3"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\weapons\PLX1\data\PLX1_body_co.paa",
			"\MRC\JLTS\weapons\PLX1\data\PLX1_tube_co.paa",
			"\MRC\JLTS\weapons\PLX1\data\PLX1_mag_co.paa"
		};
		class Library
		{
			libTextDesc="";
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=200;
		};
		inertia=1.1;
		initSpeed=30;
		class OpticsModes
		{
			class StepScope
			{
				opticsID=1;
				useModelOptics=1;
				opticsPPEffects[]=
				{
					"OpticsCHAbera1",
					"OpticsBlur1"
				};
				opticsFlare=0;
				opticsZoomMin=0.083329998;
				opticsZoomMax=0.041669998;
				opticsZoomInit=0.083329998;
				distanceZoomMin=300;
				distanceZoomMax=300;
				memoryPointCamera="eye";
				cameraDir="look";
				visionMode[]=
				{
					"Normal",
					"Ti"
				};
				thermalMode[]={0,1};
				opticsDisablePeripherialVision=1;
				discretefov[]={0.083329998,0.041669998};
				discreteInitIndex=0;
			};
		};
	};
	class FST_RPS6_Base: launch_RPG32_F
	{
		author="Adapted from the Indecisive Armoury Team";
		_generalMacro="launch_RPG32_F";
		scope=1;
		baseWeapon="FST_RPS6_Disposable";
		autoReload="false";
		displayName="[41st] RPS-6 Disposable launcher";
		modelOptics="\A3\Weapons_F\acc\reticle_RPG_F";
		model="\3AS\3AS_Weapons\RPS6\3AS_RPS6_F.p3d";
		picture="\MRC\JLTS\weapons\RPS6\data\ui\rps6_ui_ca.paa";
		uiPicture="MRC\JLTS\weapons\RPS6\data\ui\rps6_ui_ca.paa";
		opticsZoomMin=0.1083;
		opticsZoomMax=0.1083;
		opticsZoomInit=0.1083;
		cameraDir="look";
		class OpticsModes
		{
			class optic
			{
				opticsID=1;
				useModelOptics=1;
				opticsZoomMin=0.1083;
				opticsZoomMax=0.1083;
				opticsZoomInit=0.1083;
				distanceZoomMin=300;
				distanceZoomMax=300;
				memoryPointCamera="eye";
				opticsFlare=1;
				opticsDisablePeripherialVision=1;
				cameraDir="look";
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
				opticsPPEffects[]=
				{
					"OpticsCHAbera1",
					"OpticsBlur1"
				};
			};
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"3as\3as_weapons\data\anim\rps6_hold.rtm"
		};
		recoil="recoil_rpg";
		magazineReloadSwitchPhase=0.30000001;
		magazineWell[]={};
		magazines[]=
		{
			"FST_RPS6_rocket_Disposable"
		};
		ace_overpressure_angle=30;
		ace_overpressure_range=3;
		ace_overpressure_damage=20;
		ace_nlaw_enabled=0;
		class EventHandlers
		{
			fired="_this call CBA_fnc_firedDisposable";
		};
		class Library
		{
			libTextDesc="$STR_A3_CfgWeapons_launch_LAW_Library0";
		};
		class Single: Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class StandardSound
			{
				weaponSoundEffect = "";
				begin1[] = {"\41st_weapons\Launchers\Data\Launcher 3-130.ogg", 4, 1, 1800};
				begin2[] = {"\41st_weapons\Launchers\Data\Launcher 3-130.ogg", 4, 1, 1800};
				soundBegin[] = {"begin1", 0.5, "begin2", 0.5};
			};
    };
	};
	class FST_RPS6_Disposable: FST_RPS6_Base
	{
		author="Adapted from the Indecisive Armoury Team";
		Scope=2;
		displayName="[41st] RPS-6 Disposable launcher";
		baseWeapon="FST_RPS6_Disposable";
		magazines[]=
		{
			"CBA_FakeLauncherMagazine"
		};
	};
	class FST_RPS6_Used: FST_RPS6_Disposable
	{
		scope=1;
		author="Adapted from the Indecisive Armoury Team";
		displayName="[41st] RPS-6 Disposable launcher (USED)";
		baseWeapon="FST_RPS6_Used";
		magazines[]=
		{
			"CBA_FakeLauncherMagazine"
		};
	};
	class FST_RPS6HP: FST_RPS6_Base
	{
		author="Adapted from the Indecisive Armoury Team";
		_generalMacro="launch_RPG32_F";
		scope=2;
		baseWeapon="FST_RPS6HP";
		autoReload="false";
		displayName="[41st] RPS-6HP Rocket launcher";
		model="\MRC\JLTS\weapons\RPS6\rps6.p3d";
		picture="\MRC\JLTS\weapons\RPS6\data\ui\rps6_ui_ca.paa";
		uiPicture="MRC\JLTS\weapons\RPS6\data\ui\rps6_ui_ca.paa";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\MRC\JLTS\weapons\RPS6\anims\RPS6_handanim.rtm"
		};
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\weapons\RPS6\data\rps6_co.paa"
		};
		reloadAction="GestureReloadRPG7";
		recoil="recoil_rpg";
		magazineReloadSwitchPhase=0.30000001;
		magazineWell[]={};
		magazines[]=
		{
			"FST_RPS6_rocket",
			"FST_RPS6_rocket_HE",
		};
		ace_overpressure_angle=30;
		ace_overpressure_range=3;
		ace_overpressure_damage=20;
	};
};