class CfgPatches
{
	class FST_Static_ProvidenceCannon
	{
		addonRootClass="3AS_Static";
		requiredAddons[]=
		{
			"3AS_Static"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_ProvidenceCannon"
		};
		weapons[]={};
	};
};
class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		FieldCannon_Gunner="FieldCannon_Gunner";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	skeletonName="OFP2_ManSkeleton";
	gestures="CfgGesturesMale";
	class States
	{
		class Crew;
		class FieldCannon_Gunner_Kia: DefaultDie
		{
			actions="DeadActions";
			file="3as\3as_UTAT\data\Anim\UTATDriver_KIA.rtm";
			speed=0.5;
			looped=0;
			terminal=1;
			soundEnabled=0;
			connectTo[]=
			{
				"Unconscious",
				0.1
			};
		};
		class FieldCannon_Gunner: Crew
		{
			file="3as\3as_Anims\anims\FieldCannon_Gunner.rtm";
			interpolateTo[]=
			{
				"",
				1
			};
			leftHandIKCurve[]={1};
			rightHandIKCurve[]={1};
		};
	};
};
class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class CfgDestructPos
{
	scope=1;
	class DelayedDestruction;
	class DelayedDestructionAmmo: DelayedDestruction
	{
		timeBeforeHiding="21";
		hideDuration="10";
	};
};
class WeaponCloudsMGun;
class CfgVehicles
{
	class All;
	class Strategic;
	class Land;
	class LandVehicle: Land
	{
		class ViewPilot;
		class ViewGunner;
		class NewTurret;
	};
	class StaticWeapon: LandVehicle
	{
		class Turrets
		{
			class MainTurret;
		};
	};
	class StaticMGWeapon: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics;
			};
		};
	};
	class FST_FieldCannon_Base: StaticMGWeapon
	{
		author="Daara";
		_generalMacro="HMG_01_base_F";
		scope=0;
		displayName="[41st] Providence Cannon";
		class Armory
		{
			description="";
		};
		model="3AS\3as_static\FieldCannon\3AS_FieldCannon.p3d";
		editorSubcategory="EdSubcat_Turrets";
		icon="3AS\3as_static\FieldCannon\Data\ui\FieldCannon_top_ca.paa";
		threat[]={1,0.30000001,0.30000001};
		cost=150000;
		getInAction="";
		getOutAction="";
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3as\3as_static\FieldCannon\data\Textures\base.rvmat",
				"3as\3as_static\FieldCannon\data\Textures\base.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_01_destruct.rvmat"
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				optics=1;
				discreteDistance[]={100,200,300,400,600,800,1000,1200,1500,1600,1700,1800,1900,2000};
				discreteDistanceInitIndex=2;
				turretInfoType="RscOptics_crows";
				gunnerOpticsModel="\a3\weapons_f_gamma\reticle\HMG_01_Optics_Gunner_F";
				minElev=-20;
				maxElev=15;
				minTurn=-360;
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\boat\Boat_Armed_01\servo_boat_comm",
					1.4125376,
					1,
					30
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\boat\Boat_Armed_01\servo_boat_comm_vertical",
					1.4125376,
					1,
					30
				};
				maxTurn=360;
				weapons[]=
				{
					"FST_Providence_Cannon_Gun"
				};
				magazines[]=
				{
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag"
				};
				gunnerAction="FieldCannon_Gunner";
				gunnergetInAction="";
				gunnergetOutAction="";
				memoryPointGunnerOptics="gunnerview";
				memoryPointsGetInGunner="pos_gunner";
				memoryPointsGetInGunnerDir="pos_gunner_dir";
				class ViewOptics: ViewOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.117;
					minFov=0.028999999;
					maxFov=0.117;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0,1};
				};
				gunnerRightHandAnimName="OtocHlaven_shake";
				gunnerLeftHandAnimName="OtocHlaven_shake";
				ejectDeadGunner=1;
			};
		};
		class AnimationSources
		{
			class muzzle_source
			{
				source="reload";
				weapon="3AS_AATCannon";
			};
			class muzzle_source_rot
			{
				source="ammorandom";
				weapon="3AS_AATCannon";
			};
			class ReloadAnim
			{
				source="reload";
				weapon="3AS_AATCannon";
			};
			class Reload1
			{
				source="reload";
				weapon="3AS_AATCannon";
			};
			class ReloadMagazine
			{
				source="reloadmagazine";
				weapon="3AS_AATCannon";
			};
			class Revolving
			{
				source="revolving";
				weapon="3AS_AATCannon";
			};
		};
		soundGetOut[]=
		{
			"A3\sounds_f\dummysound",
			0.001,
			1,
			5
		};
		soundGetIn[]=
		{
			"A3\sounds_f\dummysound",
			0.00031622799,
			1,
			5
		};
	};
	class FST_ProvidenceCannon: FST_FieldCannon_Base
	{
		author="Daara";
		editorPreview="\3as\3as_static\images\3AS_FieldCannon.jpg";
		_generalMacro="B_HMG_01_F";
		scope=2;
		side=0;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Droid_B1_E5";
		crewVulnerable=0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				magazines[]=
				{
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag",
					"FST_Providence_Cannon_Mag"
				};
			};
		};
	};
};
class Mode_SemiAuto;
class CfgWeapons
{
	class autocannon_Base_F;
	class FST_Providence_Cannon_Gun: autocannon_Base_F
	{
		displayName="Main Cannon";
		author="Daara";
		cursor="EmptyCursor";
		reloadTime=2;
		fireLightDiffuse[]={1,0,0};
		class GunParticles
		{
			class Effect
			{
				effectName="";
				positionName="";
				directionName="";
			};
			class Shell
			{
				positionName="";
				directionName="";
				effectName="";
			};
		};
		muzzles[]=
		{
			"HP",
		};
		class HP: autocannon_Base_F
		{
			displayName="Main Blaster cannon";
			cursor="EmptyCursor";
			magazines[]=
			{
				"FST_Providence_Cannon_Mag"
			};
			magazineReloadTime=1.5;
			modes[]=
			{
				"Fire",
			};
			class Fire: Mode_SemiAuto
			{
				sounds[]=
				{
					"StandardSound"
				};
				class BaseSoundModeType
				{
					weaponSoundEffect="DefaultRifle";
					closure1[]={};
					closure2[]={};
					soundClosure[]=
					{
						"closure1",
						0.5,
						"closure2",
						0.5
					};
				};
				class StandardSound
				{
					begin1[]=
					{
						"\41st_Weapons\Vehicle\Sounds\FST_AAT_Cannon.ogg",
						2.5118864,
						1,
						1500
					};
					begin2[]=
					{
						"\41st_Weapons\Vehicle\Sounds\FST_AAT_Cannon.ogg",
						2.5118864,
						1.015,
						1500
					};
					begin3[]=
					{
						"\41st_Weapons\Vehicle\Sounds\FST_AAT_Cannon.ogg",
						2.5118864,
						0.985,
						1500
					};
					begin4[]=
					{
						"\41st_Weapons\Vehicle\Sounds\FST_AAT_Cannon.ogg",
						2.5118864,
						1.01,
						1500
					};
					begin5[]=
					{
						"\41st_Weapons\Vehicle\Sounds\FST_AAT_Cannon.ogg",
						2.5118864,
						0.995,
						1500
					};
					soundBegin[]=
					{
						"begin1",
						1
					};
					dispersion=0.0018;
					reloadTime=0.2;
				};
			};
		};
	};
};
class CfgMagazines
{
	class 1Rnd_HE_Grenade_shell;
	class FST_Providence_Cannon_Mag: 1Rnd_HE_Grenade_shell
	{
		author="Daara";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		count=100;
		displayName="[41st] Providence Cannon Mag";
		displayNameShort="Anti-Ship Munition";
		descriptionShort="Blows Up Ships";
		ammo="FST_Providence_Cannon_Ammo";
		tracersEvery=1;
		initSpeed=600;
		mass=20;
	};
};
class CfgAmmo
{
	class IDA_thermal_shell;
	class FST_Providence_Cannon_Ammo: IDA_thermal_shell
	{
		hit=0;
		indirectHit=0;
		explosive=1;
		indirectHitRange=50;
		caliber=50;
		model="3as\3as_weapons\data\tracer_shell_red";
		CraterEffects="ArtyShellCrater";
		ExplosionEffects="MortarExplosion";
		whistleDist=60;
		effectFly="3AS_PlasmaBolt_Large_Red_Fly";
	};
};