class CfgPatches
{
	class FST_Static_DefenseCannon
	{
		addonRootClass="3AS_Static";
		requiredAddons[]=
		{
			"3AS_Static"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_DefenseCannonn"
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
	class FST_DefenseCannon_Base: StaticMGWeapon
	{
		author="Daara";
		_generalMacro="HMG_01_base_F";
		scope=0;
		displayName="[41st] Defensive Artillery Cannon";
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
				minElev=-45;
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
					"FST_HAGM_mortar"
				};
				magazines[]=
				{
					"FST_32Rnd_155mm_HAGM_Mortar_shells_Cinematic",
					"FST_32Rnd_155mm_HAGM_Mortar_shells_Cinematic",
					"FST_32Rnd_155mm_HAGM_Mortar_shells_Cinematic",
					"FST_32Rnd_155mm_HAGM_Mortar_shells_Cinematic"
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
	class FST_DefenseCannon: FST_DefenseCannon_Base
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
					"FST_32Rnd_155mm_HAGM_Mortar_shells_Cinematic",
					"FST_32Rnd_155mm_HAGM_Mortar_shells_Cinematic",
					"FST_32Rnd_155mm_HAGM_Mortar_shells_Cinematic",
					"FST_32Rnd_155mm_HAGM_Mortar_shells_Cinematic"
				};
			};
		};
	};
};
class Mode_SemiAuto;
class CfgWeapons
{
	class CannonCore
	{
		class player;
	};
	class mortar_155mm_AMOS: CannonCore
	{
	};
	class FST_HAGM_mortar: mortar_155mm_AMOS
	{
		scope=2;
		displayName="HAGM Cannon";
		nameSound="cannon";
		cursor="mortar";
		cursorAim="EmptyCursor";
		reloadTime=0.1;
		magazineReloadTime=1;
		magazines[]=
		{
			"FST_32Rnd_155mm_HAGM_Mortar_shells_Cinematic",
		};
		class GunParticles
		{
		};
	};
};
class CfgMagazines
{
	class VehicleMagazine;
	class 32Rnd_155mm_Mo_shells: VehicleMagazine
	{
	};
	class FST_32Rnd_155mm_HAGM_Mortar_shells_Cinematic: 32Rnd_155mm_Mo_shells
	{
		displayNameShort="HE";
		scope=2;
		displayName="(Cinematic) 155 mm HE Shells";
		ammo="FST_HAGM_155mm_AMOS_Mortar_Ammo_Cinematic";
		count=32;
		nameSound="heat";
		muzzleImpulseFactor[]={0.5,0.5};
	};
};
class CfgAmmo
{
	class Sh_155mm_AMOS;
	class FST_HAGM_155mm_AMOS_Mortar_Ammo_Cinematic: Sh_155mm_AMOS
	{
		hit=0;
		indirectHit=0;
		indirectHitRange=30;
		dangerRadiusHit=750;
		suppressionRadiusHit=75;
		explosive=0.80000001;
		cost=300;
		model="3as\3as_weapons\data\tracer_shell_red";
		CraterEffects="ArtyShellCrater";
		ExplosionEffects="MortarExplosion";
		whistleDist=60;
		artilleryLock=1;
		thrust=0;
		timeToLive=180;
		effectFly="3AS_PlasmaBolt_Large_Red_Fly";
	};
};