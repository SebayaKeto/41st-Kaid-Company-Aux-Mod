class CfgPatches
{
	class FST_Reoublic_Static_Keeradak
	{
		addonRootClass="3AS_Reoublic_Static";
		requiredAddons[]=
		{
			"3AS_VehicleWeapons"
		};
		units[]=
		{
			"FST_Keeradak_F",
		};
		weapons[]={};
	};
};
class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		FSTKeeradakGunner="FSTKeeradakGunner";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	skeletonName="OFP2_ManSkeleton";
	gestures="CfgGesturesMale";
	class States
	{
		class Crew;
		class FSTKeeradakGunner: Crew
		{
			file="3as\3AS_Republic_Static\Keeradak\data\anims\KeeradakGunner.rtm";
			looped=0;
			showWeaponAim=1;
			disableWeapons=1;
			disableWeaponsLong=1;
			variantsAI[]={};
			speed=0.40000001;
			ConnectTo[]=
			{
				"AmovPercMstpSnonWnonDnon",
				0.02
			};
			connectFrom[]={};
			interpolateFrom[]={};
			InterpolateTo[]=
			{
				"Unconscious",
				0.1
			};
			lefthandIKCurve[]={1};
			righthandIKCurve[]={1};
			preload=0;
		};
	};
};
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateNV;
class SensorTemplateDataLink;
class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftDriver: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightDriver: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftCommander: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightCommander: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftGunner: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightGunner: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class DefaultEventHandlers;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class CfgVehicles
{
	class Land;
	class LandVehicle: Land
	{
		class ViewPilot;
		class NewTurret;
	};
	class StaticWeapon: LandVehicle
	{
		class EventHandlers;
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
	class FST_Keeradak_Base_F: StaticMGWeapon
	{
		author="$STR_3as_Studio";
		_generalMacro="HMG_01_base_F";
		scope=0;
		displayName="[41st] Keeradak Anti-Air Gun";
		class Armory
		{
			description="One of the Republics most reliable anti-air turrets";
		};
		model="3as\3AS_Republic_Static\Keeradak\model\3AS_Keeradak.p3d";
		editorSubcategory="FST_Ground_Vehicle";
		cost=150000;
		getInAction="";
		getOutAction="";
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3as\3AS_Republic_Static\Keeradak\data\base.rvmat",
				"3as\3AS_Republic_Static\Keeradak\data\damage\base_damage.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_01_destruct.rvmat",
				"3as\3AS_Republic_Static\Keeradak\data\turret.rvmat",
				"3as\3AS_Republic_Static\Keeradak\data\damage\turret_damage.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_01_destruct.rvmat"
			};
		};
		class Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class LaserSensorComponent: SensorTemplateLaser
					{
						animDirection="mainTurret";
					};
					class DataLinkSensorComponent: SensorTemplateDataLink
					{
					};
					class ManSensorComponent: SensorTemplateMan
					{
						maxTrackableSpeed=15;
						angleRangeHorizontal=51;
						angleRangeVertical=37;
						animDirection="mainGun";
						aimDown=-0.5;
					};
					class IRSensorComponent: SensorTemplateIR
					{
						class AirTarget
						{
							minRange=0;
							maxRange=500;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=0;
							maxRange=250;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						maxTrackableSpeed=35;
						angleRangeHorizontal=51;
						angleRangeVertical=37;
						animDirection="mainGun";
						aimDown=-0.5;
					};
					class VisualSensorComponent: SensorTemplateVisual
					{
						class AirTarget
						{
							minRange=0;
							maxRange=1000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=0;
							maxRange=500;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						maxTrackableSpeed=35;
						angleRangeHorizontal=90;
						angleRangeVertical=90;
						animDirection="mainGun";
						aimDown=-0.5;
					};
				};
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
				minElev=-15;
				maxElev=70;
				minTurn=-180;
				maxTurn=180;
				memoryPointGun[]=
				{
					"usti hlavne",
					"usti hlavne1"
				};
				weapons[]=
				{
					"FST_Keeradak_30mm_AA_Cannon"
				};
				magazines[]=
				{
					"FST_500Rnd_Keeradak_shells",
					"FST_500Rnd_Keeradak_shells",
					"FST_500Rnd_Keeradak_shells",
					"FST_500Rnd_Keeradak_shells"
				};
				gunnerAction="KeeradakGunner";
				gunnergetInAction="GetInHigh";
				gunnergetOutAction="GetOutHigh";
				displayName="Gunner";
				disableSoundAttenuation=0;
				class ViewOptics: ViewOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.75;
					minFov=0.125;
					maxFov=1.25;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0,1};
				};
				gunnerRightHandAnimName="Heavygun";
				gunnerLeftHandAnimName="Heavygun";
				ejectDeadGunner=1;
				selectionFireAnim="zasleh";
				class Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftGunner
					{
						class Components: components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={800,400,200,1600};
								resource="RscCustomInfoSensors";
							};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightGunner
					{
						defaultDisplay="SensorDisplay";
						class Components: components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={800,400,200,1600};
								resource="RscCustomInfoSensors";
							};
						};
					};
				};
			};
		};
		class AnimationSources
		{
			class Muzzle_flash
			{
				source="ammorandom";
				weapon="3AS_Keeradak_30mm_AA_Cannon";
			};
			class recoil_source
			{
				source="reload";
				weapon="3AS_Keeradak_30mm_AA_Cannon";
			};
		};
		soundGetOut[]=
		{
			"A3\sounds_f\dummysound",
			0.00099999993,
			1,
			5
		};
		soundGetIn[]=
		{
			"A3\sounds_f\dummysound",
			0.00031622773,
			1,
			5
		};
		hiddenSelections[]=
		{
			"camo0",
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3as\3as_republic_static\keeradak\data\rep_aa_base_co.paa",
			"3as\3as_republic_static\keeradak\data\rep_aa_Gun_co.paa"
		};
		class TextureSources
		{
			class Imperial
			{
				displayName="Imperial";
				textures[]=
				{
					"3as\3as_republic_static\keeradak\data\Imp_aa_base_co.paa",
					"3as\3as_republic_static\keeradak\data\Imp_aa_Gun_co.paa"
				};
				factions[]=
				{
					"3AS_Imperial"
				};
			};
			class Rebel
			{
				displayName="Republic";
				textures[]=
				{
					"3as\3as_republic_static\keeradak\data\rep_aa_base_co.paa",
					"3as\3as_republic_static\keeradak\data\rep_aa_Gun_co.paa"
				};
				factions[]=
				{
					"3AS_Rep"
				};
			};
		};
		class Eventhandlers: EventHandlers
		{
			postInit="if (local (_this select 0)) then { [(_this select 0), """", [], false] call BIS_fnc_initVehicle; };";
		};
	};
	class FST_Keeradak_F: FST_Keeradak_Base_F
	{
		author="$STR_3as_Studio";
		editorPreview="\3as\3as_static\images\3AS_HeavyRepeater_Unarmoured.jpg";
		icon="3as\3AS_Republic_Static\Keeradak\data\ui\Keeradak_top_ca.paa";
		picture="3as\3AS_Republic_Static\Keeradak\data\ui\Keeradak_side_ca.paa";
		_generalMacro="B_HMG_01_F";
		scope=2;
		scopeCurator=2;
		side=1;
		armor=250;
		faction="FST_Faction";
		crew="FST_Pilot_P1";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				magazines[]=
				{
					"FST_500Rnd_Keeradak_shells",
					"FST_500Rnd_Keeradak_shells",
					"FST_500Rnd_Keeradak_shells",
					"FST_500Rnd_Keeradak_shells"
				};
			};
		};
	};
};
class CfgWeapons
{
	class CannonCore;
	class FST_Keeradak_30mm_AA_Cannon: CannonCore
	{
		scope=1;
		displayName="[41st] Keeradak AA Cannon";
		nameSound="cannon";
		cursor="EmptyCursor";
		cursorAim="mg";
		magazines[]=
		{
			"FST_500Rnd_Keeradak_shells"
		};
		magazineReloadTime=20;
		modes[]=
		{
			"manual",
			"close",
			"short",
			"medium",
			"far"
		};
		canLock=2;
		ballisticsComputer="2 + 4";
		class GunParticles
		{
		};
		class manual: CannonCore
		{
			displayName="[41st] Keeradak AA Cannon";
			textureType="fullAuto";
			autoFire=1;
			burst=2;
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_Keeradak_Shot_SoundSet"
				};
			};
			soundContinuous=0;
			soundBurst=0;
			reloadTime=0.16500001;
			dispersion=0.0044999998;
			aiRateOfFire=1;
			aiRateOfFireDistance=10;
			minRange=0;
			minRangeProbab=0.0099999998;
			midRange=1;
			midRangeProbab=0.0099999998;
			maxRange=2;
			maxRangeProbab=0.0099999998;
		};
		class close: manual
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=12;
			burstRangeMax=28;
			aiRateOfFire=0.5;
			aiRateOfFireDispersion=0.5;
			aiRateOfFireDistance=200;
			minRange=1;
			minRangeProbab=0.1;
			midRange=100;
			midRangeProbab=0.75;
			maxRange=400;
			maxRangeProbab=0.85000002;
		};
		class short: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=18;
			burstRangeMax=42;
			aiRateOfFire=1;
			aiRateOfFireDispersion=1;
			aiRateOfFireDistance=300;
			minRange=200;
			minRangeProbab=0.30000001;
			midRange=400;
			midRangeProbab=0.85000002;
			maxRange=750;
			maxRangeProbab=0.85000002;
		};
		class medium: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=18;
			burstRangeMax=42;
			aiRateOfFire=2;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=800;
			minRange=600;
			minRangeProbab=0.60000002;
			midRange=750;
			midRangeProbab=0.85000002;
			maxRange=1250;
			maxRangeProbab=0.60000002;
		};
		class far: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=18;
			burstRangeMax=42;
			aiRateOfFire=2;
			aiRateOfFireDispersion=3;
			aiRateOfFireDistance=1200;
			minRange=1000;
			minRangeProbab=0.69999999;
			midRange=1250;
			midRangeProbab=0.60000002;
			maxRange=2500;
			maxRangeProbab=0.1;
		};
	};
}
class CfgMagazines
{
	class VehicleMagazine;
	class FST_500Rnd_Keeradak_shells: VehicleMagazine
	{
		author="$STR_3as_Studio";
		scope=2;
		displayName="HEAA";
		displayNameShort="AA";
		ammo="FST_Keeradak_30mm_MP";
		count=500;
		initSpeed=1070;
		maxLeadSpeed=416.66699;
		tracersEvery=1;
		nameSound="cannon";
		muzzleImpulseFactor[]={0,0};
	};
};
class CfgAmmo
{
	class BulletBase;
	class FST_Keeradak_30mm_MP: BulletBase
	{
		hit=150;
		indirectHit=12;
		indirectHitRange=3;
		warheadName="AP";
		explosive=0.75;
		explosionSoundEffect="DefaultExplosion";
		explosionEffects="ExploAmmoExplosion";
		craterEffects="ExploAmmoCrater";
		visibleFire=32;
		audibleFire=200;
		visibleFireTime=3;
		dangerRadiusBulletClose=20;
		dangerRadiusHit=60;
		suppressionRadiusBulletClose=12;
		suppressionRadiusHit=24;
		cost=70;
		deflecting=2;
		airFriction=-9.9999997e-005;
		fuseDistance=3;
		typicalSpeed=1100;
		caliber=5.5;
		airlock=2;
		aiAmmoUsageFlags="64 + 256";
		allowAgainstInfantry=1;
		model="\3AS\3AS_Weapons\Data\tracer_green";
		tracerScale=2.5;
		tracerStartTime=0;
		tracerEndTime=10;
		effectFly="3AS_PlasmaBolt_Medium_green_Fly";
		soundSetSonicCrack[]=
		{
			"3AS_HeavyPlasma_Flyby_SoundSet"
		};
		soundFly[]=
		{
			"",
			1,
			1,
			50
		};
		soundHit1[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\30mm40mm_shell_explosion_01",
			1.7782794,
			1,
			1600
		};
		soundHit2[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\30mm40mm_shell_explosion_02",
			1.7782794,
			1,
			1600
		};
		soundHit3[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\30mm40mm_shell_explosion_03",
			1.7782794,
			1,
			1600
		};
		soundHit4[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\30mm40mm_shell_explosion_04",
			1.7782794,
			1,
			1600
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.25,
			"soundHit2",
			0.25,
			"soundHit3",
			0.25,
			"soundHit4",
			0.25
		};
		class HitEffects
		{
			hitMetal="ImpactMetalSabotSmall";
			hitMetalPlate="ImpactMetalSabotSmall";
			hitBuilding="ImpactConcreteSabotSmall";
			hitConcrete="ImpactConcreteSabotSmall";
			hitGroundSoft="ImpactEffectsGroundSabot";
			hitGroundHard="ImpactEffectsGroundSabot";
			Hit_Foliage_green="ImpactLeavesGreen";
			Hit_Foliage_Dead="ImpactLeavesDead";
			Hit_Foliage_Green_big="ImpactLeavesGreenBig";
			Hit_Foliage_Palm="ImpactLeavesPalm";
			Hit_Foliage_Pine="ImpactLeavesPine";
			hitFoliage="ImpactLeaves";
			hitGlass="ImpactGlass";
			hitGlassArmored="ImpactGlassThin";
			hitWood="ImpactWood";
			hitHay="ImpactHay";
			hitPlastic="ImpactPlastic";
			hitRubber="ImpactRubber";
			hitTyre="ImpactTyre";
			hitMan="ImpactEffectsBlood";
			hitWater="ImpactEffectsWater";
			default_mat="ImpactEffectsGroundSabot";
		};
		class CamShakeExplode
		{
			power=6;
			duration=1;
			frequency=20;
			distance=67.817802;
		};
		class CamShakeHit
		{
			power=30;
			duration=0.40000001;
			frequency=20;
			distance=1;
		};
		class CamShakeFire
		{
			power=2.2360699;
			duration=1;
			frequency=20;
			distance=40;
		};
		class CamShakePlayerFire
		{
			power=0.0099999998;
			duration=0.1;
			frequency=20;
			distance=1;
		};
	};
};