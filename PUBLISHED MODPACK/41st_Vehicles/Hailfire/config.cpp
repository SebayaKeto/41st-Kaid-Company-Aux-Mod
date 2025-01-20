class CfgPatches
{
	class FST_Hailfire
	{
		author="Viz";
		requiredaddons[]=
		{
			"3AS_Main",
			"3AS_Hailfire"
		};
		requiredversion=1;
		units[]=
		{
			"FST_Hailfire_SAM",
			"FST_Hailfire_AT",
			"FST_Hailfire_Rocket"
		};
		weapons[]={};
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
        class ViewPilot;
        class ViewOptics;
		class ViewCargo;
		class HeadLimits;
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitFuel;
			class HitEngine;
			class HitLTrack;
			class HitRTrack;
		};
		class Sounds: Sounds
		{
			class Engine;
			class Movement;
		};
    };
	class 3AS_Hailfire_Base: Tank_F{};
	class FST_Hailfire_Base:3AS_Hailfire_Base
    {
		author = "Viz";
        scope=0;
		scopecurator=0;
		side = 0;
		tas_canBlift=1;
        tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]"; 
		maximumLoad=5000;
		ace_cargo_space=30;
        ace_cargo_hasCargo=1;
        displayName = "[41st] Hailfire Droid Base";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Ground_Vehicle";
        crew="FST_Droid_B1_OOM";
		hiddenSelections[] = 
		{
			"Camo1",
			"Camo2"
		};
		crewVulnerable=0;
		class Turrets: Turrets
		{
			class Mainturret: MainTurret{};
			class Mainturret2: Mainturret
			{
				gunnerCompartments="Compartment1";
				memoryPointGun="usti hlavne";
				gunBeg="usti hlavne";
				gunEnd="konec hlavne";
				weapons[]=
				{
					"3AS_HailfireRepeater",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"3AS_500Rnd_ATT_RedPlasma",
					"3AS_500Rnd_ATT_RedPlasma",
					"3AS_500Rnd_ATT_RedPlasma",
					"3AS_500Rnd_ATT_RedPlasma",
					"3AS_500Rnd_ATT_RedPlasma",
					"3AS_500Rnd_ATT_RedPlasma",
					"3AS_500Rnd_ATT_RedPlasma",
					"3AS_500Rnd_ATT_RedPlasma",
					"3AS_500Rnd_ATT_RedPlasma",
					"3AS_500Rnd_ATT_RedPlasma",
					"3AS_500Rnd_ATT_RedPlasma",
					"SmokeLauncherMag"
				};
				turretInfoType="RscWeaponRangeZeroing";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				selectionFireAnim="zasleh";
				animationSourceBody="Mainturret";
				animationSourceGun="MainGun";
				body="Mainturret";
				gun="MainGun";
				discreteDistanceInitIndex=5;
				memoryPointGunnerOptics="gunnerview";
				gunnerOutOpticsModel="";
				gunnerOutOpticsEffect[]={};
				gunnerOpticsEffect[]={};
				gunnerForceOptics=1;
				visionMode[]=
				{
					"Normal"
				};
				thermalMode[]={};
				class OpticsIn
				{
					class Wide
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						initFov=0.155;
						minFov=0.155;
						maxFov=0.155;
						visionMode[]=
						{
							"Normal",
							"NVG",
							"Ti"
						};
						thermalMode[]={0,1};
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
						gunnerOpticsEffect[]={};
					};
					class Narrow: Wide
					{
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
						initFov=0.046999998;
						minFov=0.046999998;
						maxFov=0.046999998;
					};
				};
				gunnerAction="mbt2_slot2b_in";
				forceHideGunner=1;
				outGunnerMayFire=1;
				gunnerInAction="mbt2_slot2b_in";
				gunnerRightHandAnimName="";
				gunnerLeftHandAnimName="";
				gunnerFireAlsoInInternalCamera=1;
				gunnerOutFireAlsoInInternalCamera=1;
				proxyIndex=1;
				viewGunnerInExternal=0;
				gunnerName="Commander";
				proxytype="CPCommander";
				isPersonTurret=0;
				personTurretAction="vehicle_turnout_1";
				minOutElev=-10;
				maxOutElev=15;
				initOutElev=0;
				minTurn=-30;
				maxTurn=30;
				initOutTurn=0;
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_best",
					"db-40",
					1,
					50
				};
				minElev=-5;
				maxElev=20;
				initElev=0;
				inGunnerMayFire=1;
				class HitPoints
				{
					class HitTurret
					{
						armor=0.80000001;
						material=-1;
						name="otocvez";
						visual="Otocvez";
						passThrough=0;
						minimalHit=0.02;
						explosionShielding=1;
						radius=0.15000001;
					};
					class HitGun
					{
						armor=0.75;
						material=-1;
						name="otocvez";
						visual="OtocHlaven";
						passThrough=0;
						minimalHit=0;
						explosionShielding=1;
						radius=0.15000001;
					};
				};
			};
		};
    };
    class FST_Hailfire_SAM: FST_Hailfire_Base
    {
		author = "Viz";
        scope = 2;
        scopeCurator = 2;
		scopearsenal= 2;
		armor = 600;
        displayName = "[41st] Hailfire Droid (SAM)";
        hiddenSelectionsTextures[] = 
		{
			"3AS\3AS_hailfire\data\headgrey_co.paa",
			"3AS\3AS_hailfire\data\wheelsgrey_co.paa"
		};
    };
    class FST_Hailfire_AT: FST_Hailfire_Base
    {
		author = "Viz";
        scope = 2;
        scopeCurator = 2;
		scopearsenal= 2;
		armor = 600;
        displayName = "[41st] Hailfire Droid (AT)";
		class AnimationSources: AnimationSources
		{
			class Revolving
			{
				source="revolving";
				weapon="";
			};
		};
        class Turrets: Turrets
		{
			class Mainturret: Mainturret
			{
				memoryPointGun[]=
				{
					"DAGR_1",
					"DAGR_2"
				};
				weapons[]=
				{
					"3AS_Hailfire_Barrage_Weapon",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"3AS_30Rnd_Missile",
					"3AS_30Rnd_Missile",
					"3AS_30Rnd_Missile",
					"3AS_30Rnd_Missile",
					"SmokeLauncherMag"
				};
			};
			class mainturret2: Mainturret2
			{
			};
		};
		hiddenSelectionsTextures[] = 
		{
			"3AS\3AS_hailfire\data\headblue_co.paa",
			"3AS\3AS_hailfire\data\wheelsblue_co.paa"
		};
    };

    class FST_Hailfire_Rocket: FST_Hailfire_Base
    {
		author = "Viz";
        scope = 2;
        scopeCurator = 2;
		scopearsenal= 2;
		armor = 600;
        displayName = "[41st] Hailfire Droid (Rocket)";
		availableForSupportTypes[]=
		{
			"Artillery"
		};
		artilleryScanner=1;
		class Eventhandlers
		{
			fired="[_this select 0,_this select 6,'missile_move','ShellBase'] spawn BIS_fnc_missileLaunchPositionFix;";
		};
		class AnimationSources: AnimationSources
		{
			class Revolving
			{
				source="revolving";
				weapon="3AS_Hailfire_Rocket_Arty";
			};
		};
		class Turrets: Turrets
		{
			class Mainturret: Mainturret
			{
				weapons[]=
				{
					"3AS_Hailfire_Rocket_Arty",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"3AS_15Rnd_230mm_rockets",
					"3AS_15Rnd_230mm_rockets",
					"SmokeLauncherMag"
				};
				missileBeg="pos_missile";
				missileEnd="pos_missile_end";
				memoryPointGun[]=
				{
					"z_gunL_muzzle",
					"z_gunR_muzzle"
				};
				gunBeg="pos_missile";
				gunEnd="pos_missile_end";
			};
			class mainturret2: Mainturret2
			{
			};
		};
		hiddenSelectionsTextures[] = 
		{
			"3AS\3AS_hailfire\data\headred_co.paa",
			"3AS\3AS_hailfire\data\wheelsred_co.paa"
		};
	};
};
