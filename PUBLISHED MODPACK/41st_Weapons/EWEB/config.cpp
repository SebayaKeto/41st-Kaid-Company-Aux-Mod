class CfgPatches
{
	class FST_EWEB_Mod
	{
		requiredAddons[]=
		{
			"A3_Weapons_F",
		};
		units[]=
		{
			"FST_EWEB",
		};
		weapons[]=
		{
			"FST_EWEB_MountedTurret",
		};
	};
};
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class FST_EWEB_RemoteTurret;
	class FST_EWEB_MountedTurret: FST_EWEB_RemoteTurret
	{
		displayName="[41st] E-Web Blaster Turret";
		author="Daara";
		magazines[]=
		{
			"FST_EWEB_cell_Blue",
			"FST_EWEB_cell_Green",
			"FST_EWEB_cell_Yellow",
			"FST_EWEB_cell_Red"
		};
		modes[]=
		{
			"FullAuto",
		};
		magazineReloadTime=5;
		class FullAuto: Mode_FullAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect="";
				begin1[]=
				{
					"\41st_Weapons\EWEB\Sounds\EWEB.ogg",
					1,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_Weapons\EWEB\Sounds\EWEB.ogg",
					1,
					1.015,
					1800
				};
				begin3[]=
				{
					"\41st_Weapons\EWEB\Sounds\EWEB.ogg",
					1,
					0.985,
					1800
				};
				begin4[]=
				{
					"\41st_Weapons\EWEB\Sounds\EWEB.ogg",
					1,
					1.01,
					1800
				};
				begin5[]=
				{
					"\41st_Weapons\EWEB\Sounds\EWEB.ogg",
					1,
					0.995,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					0.20,
					"begin2",
					0.20,
					"begin3",
					0.20,
					"begin4",
					0.20,
					"begin5",
					0.20,
				};
			};
			reloadTime=0.075000003;
			dispersion=0.00073000003;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
	};
};
class CfgVehicles
{
	class Weapon_bag_base;
	class JLTS_UAV_prowler_gar_backpack: Weapon_bag_base{};
	class Land;
	class LandVehicle: Land
	{
		class ViewPilot;
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
	
	class FST_EWEB_Base: StaticMGWeapon
	{
		author="Daara";
		scope=0;
		displayName="[41st] E-Web Blaster Turret";
		class Armory
		{
			description="Mounted heavy repeating blaster turret";
		};
		model="3AS\3AS_Static\HeavyRepeater\3AS_HeavyRepeaterStatic.p3d";
		editorSubcategory="EdSubcat_Turrets";
		picture="\A3\Static_f_gamma\data\ui\gear_StaticTurret_MG_CA.paa";
		UiPicture="\A3\Static_f_gamma\data\ui\gear_StaticTurret_MG_CA.paa";
		cost=150000;
		gunnerAction="RepeaterGunner";
		getInAction="";
		getOutAction="";
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3as\3as_static\HeavyRepeater\data\Textures\Base.rvmat",
				"3as\3as_static\HeavyRepeater\data\Textures\Base.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_02_destruct.rvmat"
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
				minElev=-10;
				maxElev=40;
				minTurn=-85;
				maxTurn=85;
				weapons[]=
				{
					"FST_EWEB_MountedTurret"
				};
				magazines[]=
				{
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue"
				};
				gunnerAction="RepeaterGunner";
				gunnergetInAction="";
				gunnergetOutAction="";
				displayName="";
				disableSoundAttenuation=1;
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
			};
		};
		class AnimationSources
		{
			class muzzle_source
			{
				source="reload";
				weapon="3AS_HeavyRepeater_W";
			};
			class muzzle_source_rot
			{
				source="ammorandom";
				weapon="3AS_HeavyRepeater_W";
			};
			class minigun
			{
				source="revolving";
				weapon="3AS_HeavyRepeater_W";
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
	};
	
	class FST_EWEB: FST_EWEB_Base
	{
		editorPreview="\3as\3as_static\images\3AS_HeavyRepeater_Unarmoured.jpg";
		scope=2;
		scopeCurator=2;
		side=1;
		armor=500;
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Trooper_P2_DC15S";
		class assembleInfo
		{
			primary=0;
			base="";
			assembleTo="";
			dissasembleTo[]=
			{
				"FST_backpack_EWEB"
			};
			displayName="";
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				magazines[]=
				{
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue"
				};
			};
		};
	};
	class FST_backpack_EWEB: JLTS_UAV_prowler_gar_backpack
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] E-Web Backpack";
		maximumload=250;
		mass=450;
		class assembleInfo
		{
			primary=1;
			base="";
			displayName="[41st] E-Web";
			assembleTo="FST_EWEB";
		};
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_backpack_co.paa",
		};
	};
};
