class CfgPatches
{
	class FST_AMOS
	{
		units[]=
		{
			"FST_122mm_Republic_AMOS",
			"FST_122mm_Republic_Mortar_Bag"
		};
		weapons[]={};
		requiredAddons[]=
		{
			"A3_Data_F"
		};
		version=1.14;
		author="Ghostly Armoury";
	};
};
class CfgVehicles
{
	class LandVehicle;
	class StaticWeapon: LandVehicle
	{
		class Turrets
		{
			class MainTurret;
		};
	};
	class StaticMortar: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics;
			};
		};
	};
	class Mortar_01_base_F: StaticMortar
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics: ViewOptics
				{
				};
			};
		};
		class assembleInfo;
	};
	class FST_122mm_Republic_AMS: Mortar_01_base_F
	{
		displayname="[41st] 122mm Republic AMS";
		model = "\OPTRE_Weapons_Turrets\AU_44_Mortar\AU_44_Mortar.p3d";
		editorPreview = "\OPTRE_Misc\Image\OPTRE\Turrets\OPTRE_AU_44_Mortar.jpg";
		crew="FST_Trooper_P2_DC15S";
		icon="3AS\3as_static\Mortar\Data\ui\Mortar_top_ca.paa";
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		scopeCurator=2;
		scope=2;
		scopearsenal=2;
		side=1;
		armor=150;
		availableForSupportTypes[] = {"Artillery"};
		class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                elevationMode = 3;
                weapons[] = {"FST_122mm_Republic_AMOS"};
                magazines[] = 
				{
                    "FST_24Rnd_122mm_Mo_shells",
					"FST_8Rnd_122mm_Cluster_shells",
					"FST_8Rnd_82mm_Mo_Flare_white",
					"FST_8Rnd_82mm_Mo_Smoke_white",
					"FST_8Rnd_82mm_Mo_guided",
					"FST_8Rnd_82mm_Mo_LG"
                };
                minelev = -22.5;
                initelev = 0;
				maxelev = 22.5;
                maxHorizontalRotSpeed = 3;
				maxVerticalRotSpeed = 3;
                disableSoundAttenuation = 0;
                soundElevation[] = {"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP03", 0.316228, 1, 10};
				soundServo[] = {"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP03", 0.177828, 1, 10};
				soundServoVertical[] = {"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP03", 0.316228, 1, 30};
            };
        };
        class AnimationSources
        {
            class muzzle_hide_mortar
            {
                source = "reload";
                weapon = "FST_122mm_Republic_AMS";
            };
        };
		class assembleInfo
        {
            assembleTo = "";
            base = "";
            displayName = "";
            dissasembleTo[] = {"FST_122mm_Republic_Mortar_Bag","FST_122mm_Republic_Mortar_Support"};
            primary = 0;
        };
        hiddenSelections[] = 
		{
            "camo",
			"camoScreen"
        };
        hiddenSelectionsTextures[] = 
		{
            "\FST_Vehicles\Mortar\Data\FST_AMOS_CO.paa",
            "OPTRE_Weapons_Turrets\au_44_mortar\data\computer_screen.paa"
        };
        hiddenSelectionsMaterials[] = {
            "OPTRE_Weapons_Turrets\AU_44_Mortar\data\mortar.rvmat",
            "OPTRE_Weapons_Turrets\AU_44_Mortar\data\mfd.rvmat"
        };
		class MFD
		{
			class MFD_Gunner_Ready_To_Fire
			{
				topLeft = "mfd_rtf_cli_TL";
				topRight = "mfd_rtf_cli_TR";
				bottomLeft = "mfd_rtf_cli_BL";
				borderLeft = 0;
				borderRight = 0;
				borderTop = 0;
				borderBottom = 0;
				color[] = {0, 0, 0};
				alpha = 0.5;
				enableParallax = 0;
				font = "LCD14";
				class material
				{
					ambient[] = {1, 1, 1, 1};
					diffuse[] = {1, 1, 1, 1};
					emissive[] = {1000, 1000, 1000, 1};
				};
				class Bones
				{
				};
				class Draw
				{
					color[] = {0, 0, 0};
					alpha = 1;
					condition = "1";
					class Top_text
					{
						type = "text";
						source = "static";
						text = "READY TO FIRE";
						sourceScale = 1;
						sourceLength = 3;
						scale = 1;
						align = "center";
						refreshRate = 0.1;
						pos[] = {{0.45, 0.2}, 1};
						right[] = {{0.59, 0.2}, 1};
						down[] = {{0.45, 0.9}, 1};
					};
				};
			};
			class MFD_Mag_Name //mag name, elevation name, azimuth name
			{
				topLeft = "mfd_mag_cli_tl";
				topRight = "mfd_mag_cli_tr";
				bottomLeft = "mfd_mag_cli_bl";
				
				borderLeft = 0;
				borderRight = 0;
				borderTop = 0;
				borderBottom = 0;
				color[] = {0.84, 0.86, 0.84};
				alpha = 0.5;
				turret[] = {0};
				enableParallax = 0;
				font = "EtelkaMonospaceProBold";
				class material
				{
					ambient[] = {1, 1, 1, 1};
					diffuse[] = {1, 1, 1, 1};
					emissive[] = {1000, 1000, 1000, 1};
				};
				class Bones
				{
				};
				class Draw
				{
					color[] = {1, 1, 1};
					alpha = 1;
					condition = "1";
					class Gunner_AmmoType
					{
						type = "text";
						source = "ammoFormat";
						sourceScale = 1;
						sourceLength = 3;
						scale = 15;
						align = "right";
						refreshRate = 0.1;
						pos[] = {{0.1, 0.15}, 1};
						right[] = {{0.25, 0.15}, 1};
						down[] = {{0.1, 0.3}, 1};
					};
					class Gunner_Azimuth
					{
						type = "text";
						source = "static";
						text = "AZIMUTH";
						sourceScale = 1;
						sourceLength = 3;
						scale = 1;
						align = "right";
						refreshRate = 0.1;
						pos[] = {{0.1, 0.3}, 1};
						right[] = {{0.25, 0.3}, 1};
						down[] = {{0.1, 0.45}, 1};
					};
					class Gunner_Elevation
					{
						type = "text";
						source = "static";
						text = "ELEVATION";
						sourceScale = 1;
						sourceLength = 3;
						scale = 1;
						align = "right";
						refreshRate = 0.1;
						pos[] = {{0.1, 0.45}, 1};
						right[] = {{0.25, 0.45}, 1};
						down[] = {{0.1, 0.6}, 1};
					};
				};
			};
			class MFD_Mag_Ammo_Count //ammo counts for mags
			{
				topLeft = "mfd_ammocount_cli_tl";
				topRight = "mfd_ammocount_cli_tr";
				bottomLeft = "mfd_ammocount_cli_bl";
				borderLeft = 0;
				borderRight = 0;
				borderTop = 0;
				borderBottom = 0;
				color[] = {0.84, 0.86, 0.84};
				alpha = 0.5;
				enableParallax = 0;
				turret[] = {0};
				font = "EtelkaMonospaceProBold";
				class material
				{
					ambient[] = {1, 1, 1, 1};
					diffuse[] = {1, 1, 1, 1};
					emissive[] = {1000, 1000, 1000, 1};
				};
				class Bones
				{
				};
				class Draw
				{
					color[] = {1, 1, 1};
					alpha = 1;
					condition = "1";
					class Gunner_Ammo
					{
						type = "text";
						source = "ammo";
						sourceScale = 1;
						//sourceLength = 3;
						scale = 1;
						//sourceIndex = -1;
						align = "left";
						refreshRate = 0.1;
						pos[] = {{0.7, 0.15}, 1};
						right[] = {{0.85, 0.15}, 1};
						down[] = {{0.7, 0.3}, 1};
					};
				};
				
			};
			class MFD_Azimuth_And_Elevation
			{
				topLeft = "mfd_ammocount_cli_tl";
				topRight = "mfd_ammocount_cli_tr";
				bottomLeft = "mfd_ammocount_cli_bl";
				borderLeft = 0;
				borderRight = 0;
				borderTop = 0;
				borderBottom = 0;
				color[] = {0.84, 0.86, 0.84};
				alpha = 0.5;
				enableParallax = 0;
				font = "EtelkaMonospaceProBold";
				turret[] = {0};
				class Bones
				{
				};
				class material
				{
					ambient[] = {1, 1, 1, 1};
					diffuse[] = {1, 1, 1, 1};
					emissive[] = {1000, 1000, 1000, 1};
				};
				class Draw
				{
					color[] = {0.61, 0.62, 0};
					alpha = 1;
					condition = "1";
					class Azimuth
					{
						type = "text";
						source = "[x]turretworld";
						scale = 1;
						sourceScale = 1;
						sourcePrecision = 1;
						align = "left";
						pos[] = {{0.7, 0.3}, 1};
						right[] = {{0.85, 0.3}, 1};
						down[] = {{0.7, 0.45}, 1};
					};
					class AzimuthSymbol: Azimuth
					{
						type = "text";
						source = "static";
						text = "°";
						pos[] = {{0.8, 0.3}, 1};
						right[] = {{0.95, 0.3}, 1};
						down[] = {{0.8, 0.45}, 1};
					};
					class Elevation
					{
						type = "text";
						source = "[y]turretworld";
						scale = 2;
						sourceScale = 1;
						//sourceLength = 7;
						sourcePrecision = 2;
						align = "left";
						pos[] = {{0.7, 0.45}, 1};
						right[] = {{0.85, 0.45}, 1};
						down[] = {{0.7, 0.6}, 1};
					};
					class ElevationSymbol: Elevation
					{
						type = "text";
						source = "static";
						text = "°";
						pos[] = {{0.8, 0.45}, 1};
						right[] = {{0.95, 0.45}, 1};
						down[] = {{0.8, 0.6}, 1};
					};
				};
			};
		};
	};
	
	//for assembled versions
	class Weapon_Bag_Base;
	class B_Mortar_01_weapon_F: Weapon_Bag_Base
	{
		class assembleInfo;
	};
	class FST_122mm_Republic_Mortar_Bag: B_Mortar_01_weapon_F
	{
		faction="FST_Faction";
		author = "Ghostly";
		_generalMacro = "FST_122mm_Republic_Mortar_Bag";
		scopeCurator=2;
		scope=2;
		scopearsenal=2;
		editorCategory="FST_Crates";
		editorSubcategory="FST_Supplies";
		displayName = "[41st] 122mm Folded Mortar Tube";
		mass = 300;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpackStraps.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_Armor\Data\Equipment\FST_Clone_backpack_co.paa"
		};
		picture = "\OPTRE_Weapons_Turrets\AU_44_Mortar\data\icons\tube.paa";
		class assembleInfo: assembleInfo
		{
			displayName="Assemble 122mm Republic AMS";
			assembleTo="FST_122mm_Republic_AMS";
			base[] = {"FST_122mm_Republic_Mortar_Support"};
		};
	};
	class FST_122mm_Republic_AMS_Standalone: FST_122mm_Republic_AMS
    {
        displayName = "122mm Republic AMS (Standalone)";
        class assembleInfo: assembleInfo
        {
            dissasembleTo[] = {"FST_122mm_Republic_AMS_Single"};
        };
    };
	
	//Support Bag
	class B_Mortar_01_support_F;
	class FST_122mm_Republic_Mortar_Support: B_Mortar_01_support_F
	{
		scopeCurator=2;
		scope=2;
		scopearsenal=2;
		author = "Ghostly";
		_generalMacro = "FST_122mm_Republic_Mortar_Support";
		displayName = "[41st] 122mm Folded Mortar Support";
		faction="FST_Faction";
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpackStraps.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_Armor\Data\Equipment\FST_Clone_backpack_co.paa"
		};
		picture = "\OPTRE_Weapons_Turrets\AU_44_Mortar\data\icons\Plate1.paa";
		class assembleInfo
		{
			primary = 0;
			base = "";
			assembleTo = "";
			dissasembleTo[] = {};
			displayName = "";
		};
	};
	
	// Single Bag Deployable
	class FST_122mm_Republic_AMS_Single: FST_122mm_Republic_Mortar_Bag
	{
		displayName = "[41st] Standalone 122mm_Republic_AMS";
		picture = "\OPTRE_Weapons_Turrets\AU_44_Mortar\data\icons\both.paa";
		class assembleInfo
		{
			assembleTo = "FST_122mm_Republic_AMS_Standalone";
			base = "";
			displayName = "[41st] 122mm Republic AMS";
			dissasembleTo[] = {};
			primary = 1;
		};
	};
};
class Mode_Burst;
class Mode_SemiAuto;
class CfgWeapons
{
	class CannonCore;
	class Sh_155mm_AMOS;
	class OPTRE_SGM122_Mortar_122mm;
	class FST_122mm_Republic_AMOS: OPTRE_SGM122_Mortar_122mm
	{
		displayname = "[41st] 122mm Republic AMOS";
		cursor="mortar";
		scopeCurator=2;
		scope=2;
		scopearsenal=2;
		soundServo[]=
		{
			"",
			9.9999997e-005,
			1
		};
		reloadTime=7;
		magazineReloadTime=7;
		autoReload=1;
		canLock=0;
		magazines[]=
		{
			"FST_24Rnd_122mm_Mo_shells",
			"FST_8Rnd_122mm_Cluster_shells",
			"FST_8Rnd_82mm_Mo_Flare_white",
			"FST_8Rnd_82mm_Mo_Smoke_white",
			"FST_8Rnd_82mm_Mo_guided",
			"FST_8Rnd_82mm_Mo_LG"
		};
		ballisticsComputer=2;
		class GunParticles
		{
			class FirstEffect
			{
				effectName="MortarFired";
				positionName="Usti Hlavne";
				directionName="Konec Hlavne";
			};
		};
		modes[]=
		{
			"Single1",
			"Single2",
			"Single3",
			"Burst1",
			"Burst2",
			"Burst3"
		};
		class Single1: Mode_SemiAuto
		{
			displayName="$STR_A3_mortar_82mm_Single10";
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"OPTRE_Cannon90mm_Shot_SoundSet"
				};
			};
			reloadSound[]=
			{
				"A3\Sounds_F\vehicles\armor\noises\reload_tank_cannon_2",
				31.622778,
				1,
				15
			};
			reloadMagazineSound[] = {"A3\Sounds_F\arsenal\weapons_static\Mortar\reload_magazine_Mortar", 1, 1, 20};
			reloadTime=1.0;
			artilleryDispersion=1.9;
			artilleryCharge=0.34999999;
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
			displayName="$STR_A3_mortar_82mm_Single20";
			artilleryCharge=0.69999999;
		};
		class Single3: Single1
		{
			displayName="$STR_A3_mortar_82mm_Single30";
			artilleryCharge=1;
		};
		class Burst1: Mode_Burst
		{
			showToPlayer=0;
			displayName="$STR_A3_mortar_82mm_Burst10";
			burst=4;
			aiBurstTerminable=1;
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				begin1[]=
				{
					"A3\Sounds_F\arsenal\weapons_static\Mortar\mortar_01",
					1.2589254,
					1,
					250
				};
				begin2[]=
				{
					"A3\Sounds_F\arsenal\weapons_static\Mortar\mortar_02",
					1.2589254,
					1,
					250
				};
				soundBegin[]=
				{
					"begin1",
					0.5,
					"begin2",
					0.5
				};
			};
			reloadSound[]=
			{
				"A3\Sounds_F\arsenal\weapons_static\Mortar\reload_mortar",
				1,
				1,
				20
			};
			soundServo[]=
			{
				"",
				9.9999997e-005,
				1
			};
			soundBurst=0;
			reloadTime=1.0;
			artilleryDispersion=1.9;
			artilleryCharge=0.34999999;
			minRange=60;
			minRangeProbab=0.5;
			midRange=290;
			midRangeProbab=0.69999999;
			maxRange=665;
			maxRangeProbab=0.5;
		};
		class Burst2: Burst1
		{
			showToPlayer=0;
			displayName="$STR_A3_mortar_82mm_Burst20";
			artilleryCharge=0.69999999;
			minRange=230;
			minRangeProbab=0.40000001;
			midRange=1175;
			midRangeProbab=0.60000002;
			maxRange=2660;
			maxRangeProbab=0.40000001;
		};
		class Burst3: Burst1
		{
			showToPlayer=0;
			displayName="$STR_A3_mortar_82mm_Burst30";
			artilleryCharge=1;
			minRange=540;
			minRangeProbab=0.30000001;
			midRange=2355;
			midRangeProbab=0.40000001;
			maxRange=7000;
			maxRangeProbab=0.30000001;
		};
	};
};
class CfgMagazines
{
	class VehicleMagazine;
	class 8Rnd_82mm_Mo_shells;
	class OPTRE_5Rnd_122mm_Mo_Cluster_HE;
	class FST_24Rnd_122mm_Mo_shells: 8Rnd_82mm_Mo_shells
	{
		author="GA";
		displayName="[41st] 24Rnd 122mm HE Mortar Shells";
		displayNameShort="HE";
		displayNameMFDFormat="HE";
		scope=2;
		count=24;
		ammo="FST_122mm_Shell";
		nameSound="heat";
		muzzleImpulseFactor[]={0,0};
		initSpeed=200;
		ace_arsenal_hide=-0;
		ace_artillerytables_airFriction=-9.9999997e-005;
		picture = "\OPTRE_Weapons_Turrets\AU_44_Mortar\data\icons\shell.paa";
	};
	class FST_8Rnd_122mm_Cluster_shells: OPTRE_5Rnd_122mm_Mo_Cluster_HE
	{
		author="GA";
		displayName="[41st] 8Rnd 122mm Cluster Mortar Shells";
		displayNameShort="HE";
		displayNameMFDFormat="HE";
		scope=2;
		count=8;
		ammo="FST_122mm_Shell_Cluster";
		nameSound="heat";
		muzzleImpulseFactor[]={0,0};
		initSpeed=200;
		ace_arsenal_hide=-0;
		ace_artillerytables_airFriction=-9.9999997e-005;
		picture = "\OPTRE_Weapons_Turrets\AU_44_Mortar\data\icons\shell.paa";
	};
};
class CfgAmmo
{
	class SubmunitionBase;
	class Sh_155mm_AMOS;
	class Sh_82mm_AMOS;
	class 3AS_Cluster_300mm_AMOS;
	class FlareCore;
	class Flare_82mm_AMOS_White;
	class ShotDeployBase;
	class FST_122mm_Shell: Sh_155mm_AMOS
	{
		displayname="[41st] 122mm Republic HE Mortar Shell";
		model = "\OPTRE_Weapons_Turrets\AU_44_Mortar\shell_throwable.p3d";
		hit = 420;
		indirectHit = 125;
		indirectHitRange = 22;
		dangerRadiusHit=750;
		suppressionRadiusHit=75;
		typicalSpeed=400;
		caliber = 40
		deflecting=0;
		explosive=1;
		ace_frag_enabled = 1;
		ace_frag_classes[] = {"ace_frag_medium", "ace_frag_medium_HD","ace_frag_large", "ace_frag_large_HD"};
		ace_frag_metal = 9600;
		ace_frag_charge = 1024;
		ace_frag_gurney_c = 2440;
		ace_frag_gurney_k = "1/2";
		ace_rearm_caliber = 122;
		effectFly="3AS_PlasmaBolt_Large_Blue_Fly";
		soundHit1[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_tank_shell_155mm_explosion_01",
			2.5118864,
			1,
			1900
		};
		soundHit2[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_tank_shell_155mm_explosion_02",
			2.5118864,
			1,
			1900
		};
		soundHit3[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_tank_shell_155mm_explosion_03",
			2.5118864,
			1,
			1900
		};
		soundHit4[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_tank_shell_155mm_explosion_04",
			2.5118864,
			1,
			1900
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
	};
	class FST_122mm_Shell_Cluster: 3AS_Cluster_300mm_AMOS
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
		};
		cost=200;
		airFriction=0;
		muzzleEffect="";
		hit=400;
		effectFly="3AS_PlasmaBolt_Large_Purple_Fly";
		soundHit1[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_tank_shell_155mm_explosion_01",
			2.5118864,
			1,
			1900
		};
		soundHit2[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_tank_shell_155mm_explosion_02",
			2.5118864,
			1,
			1900
		};
		soundHit3[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_tank_shell_155mm_explosion_03",
			2.5118864,
			1,
			1900
		};
		soundHit4[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\Artillery_tank_shell_155mm_explosion_04",
			2.5118864,
			1,
			1900
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