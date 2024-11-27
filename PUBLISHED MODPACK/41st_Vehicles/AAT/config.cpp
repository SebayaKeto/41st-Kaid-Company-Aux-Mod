class CfgPatches
{
	class FST_AAT
	{
		author="Daara";
		requiredaddons[]=
		{
			"41st_Addon",
		};
		requiredversion=1;
		units[]=
		{
			"FST_AAT",
			"FST_AAT_Tan",
			"FST_King_AAT",
			"FST_ISV_AAT",
			"FST_Blaze_AAT",
			"FST_Looted_AAT",
			"FST_Shockcap_AAT",
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
	class 3AS_AAT_base_F: Tank_F{};
	class 3AS_CIS_AAT_base_F: 3AS_AAT_base_F{};
	class 3AS_CIS_AAT_F: 3AS_CIS_AAT_base_F{};
	class 3AS_AAT: 3AS_CIS_AAT_F{};
	class FST_AAT: 3AS_AAT
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		tas_canBlift=1;
        tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]"; 
		maximumLoad=5000;
		ace_cargo_space=30;
        ace_cargo_hasCargo=1;
		displayName="[41st] AAT Main Battle Tank";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Droid_B1_E5";
		crewVulnerable=0;
		author="Daara";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						body="Obsturret";
						gun="Obsgun";
						proxyIndex=1;
						viewGunnerInExternal=0;
						proxytype="CPCommander";
						gunnername="Commander";
						animationSourceBody="Obsturret";
						animationSourceGun="Obsgun";
						minOutElev=-25;
						maxOutElev=45;
						initOutElev=0;
						minOutTurn=-90;
						maxOutTurn=90;
						initOutTurn=0;
						maxHorizontalRotSpeed=1.8;
						maxVerticalRotSpeed=1.8;
						stabilizedInAxes=3;
						soundServo[]=
						{
							"A3\Sounds_F\vehicles\armor\noises\servo_best",
							"db-40",
							1,
							50
						};
						minElev=-30;
						maxElev=30;
						initElev=0;
						minTurn=-45;
						maxTurn=45;
						initTurn=0;
						gunnerAction="";
						gunnerInAction="mbt2_slot2b_in";
						forceHideGunner=0;
						outGunnerMayFire=1;
						inGunnerMayFire=1;
						gunnerRightHandAnimName="konec hlavne3";
						gunnerLeftHandAnimName="konec hlavne3";
						soundAttenuationTurret="HeliAttenuationGunner";
						isPersonTurret=1;
						personTurretAction="vehicle_turnout_1";
						memoryPointGun[]=
						{
							"z_gunL_muzzle",
							"z_gunR_muzzle"
						};
						weapons[]=
						{
							"FST_AAT_Side",
							"SmokeLauncher"
						};
						magazines[]=
						{
							"FST_500Rnd_127x99_mag_red",
							"FST_500Rnd_127x99_mag_red",
							"SmokeLauncherMag"
						};
						turretInfoType="RscWeaponRangeZeroing";
						discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
						discreteDistanceInitIndex=2;
						memoryPointGunnerOptics="CommanderView";
						memoryPointGunnerOutOptics="commanderview";
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
						gunnerOutOpticsModel="";
						gunnerOpticsEffect[]={};
						gunnerHasFlares=1;
						turretFollowFreeLook=1;
						commanding=1;
						class ViewOptics: ViewOptics
						{
							initAngleX=0;
							minAngleX=-15;
							maxAngleX=15;
							initAngleY=0;
							minAngleY=-10;
							maxAngleY=60;
							initFov=0.155;
							minFov=0.034000002;
							maxFov=0.155;
							visionMode[]=
							{
								"Normal",
								"NVG",
								"Ti"
							};
							thermalMode[]={2,3,4};
						};
						gunnerGetInAction="GetInHigh";
						gunnerGetOutAction="GetOutHigh";
						startEngine=0;
						LODTurnedOut="VIEW_GUNNER";
						LODTurnedIn="VIEW_GUNNER";
						class HitPoints
						{
							class HitTurret
							{
								armor=0.60000002;
								material=-1;
								name="Commander_Turret";
								visual="commander_turret";
								passThrough=0;
								minimalHit=0.029999999;
								explosionShielding=0.60000002;
								radius=0.15000001;
							};
							class HitGun
							{
								armor=0.60000002;
								material=-1;
								name="Commander_Gun";
								visual="Commander_Gun";
								passThrough=0;
								minimalHit=0.029999999;
								explosionShielding=0.60000002;
								radius=0.15000001;
							};
						};
						selectionFireAnim="ZaslehCommander";
					};
				};
				startEngine=0;
				memoryPointGun="usti hlavne";
				gunBeg="usti hlavne";
				gunEnd="konec hlavne";
				weapons[]=
				{
					"FST_AAT_Cannon",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"FST_thermal_coil_HP",
					"SmokeLauncherMag"
				};
				turretInfoType="RscWeaponRangeZeroing";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				selectionFireAnim="zasleh1";
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
				gunnerName="Gunner";
				proxytype="CPGunner";
				isPersonTurret=0;
				personTurretAction="vehicle_turnout_1";
				minOutElev=-10;
				maxOutElev=15;
				initOutElev=0;
				minOutTurn=-90;
				maxOutTurn=90;
				initOutTurn=0;
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_best",
					"db-40",
					1,
					50
				};
				minElev=-9;
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
						visual="vez";
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
						visual="";
						passThrough=0;
						minimalHit=0;
						explosionShielding=1;
						radius=0.15000001;
					};
				};
			};
		};
	}; 
	class FST_AAT_Tan: FST_AAT
	{
		displayName="[41st] AAT Main Battle Tank (Tan)";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Droid_B1_E5";
		author="Daara";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_AAT\data\Tan_AAT_CO.paa"
		};
		class TransportMagazines{};
		class TransportItems{};
		class TransportWeapons{};
		class TransportBackpacks{};
	}
	class FST_King_AAT: FST_AAT
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] King AAT Heavy Tank";
		crew="FST_Droid_B1_E5";
		author="Daara";
		armor=1000;
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_AAT\data\Red_AAT_CO.paa"
		};
	};
	class FST_Looted_AAT: FST_AAT
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Civilian Looted AAT";
		crew="FST_Droid_B1_E5";
		author="Daara";
		armor=1000;
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\AAT\Data\CIS_AAT_CO_Looted.paa"
		};
	};
	class FST_Shockcap_AAT: FST_AAT
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Shockcap Looted AAT";
		crew="FST_Droid_B1_E5";
		author="Daara";
		armor=1000;
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\AAT\Data\CIS_AAT_CO_Shockcap.paa"
		};
	};
	class FST_ISV_AAT: FST_AAT
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Light AAT Infantry Support Tank";
		crew="FST_Droid_B1_E5";
		author="Daara";
		armor=400;
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_AAT\data\Green_AAT_CO.paa"
		};
				class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						body="Obsturret";
						gun="Obsgun";
						proxyIndex=1;
						viewGunnerInExternal=0;
						proxytype="CPCommander";
						gunnername="Commander";
						animationSourceBody="Obsturret";
						animationSourceGun="Obsgun";
						minOutElev=-25;
						maxOutElev=45;
						initOutElev=0;
						minOutTurn=-90;
						maxOutTurn=90;
						initOutTurn=0;
						maxHorizontalRotSpeed=1.8;
						maxVerticalRotSpeed=1.8;
						stabilizedInAxes=3;
						soundServo[]=
						{
							"A3\Sounds_F\vehicles\armor\noises\servo_best",
							"db-40",
							1,
							50
						};
						minElev=-30;
						maxElev=30;
						initElev=0;
						minTurn=-45;
						maxTurn=45;
						initTurn=0;
						gunnerAction="";
						gunnerInAction="mbt2_slot2b_in";
						forceHideGunner=0;
						outGunnerMayFire=1;
						inGunnerMayFire=1;
						gunnerRightHandAnimName="konec hlavne3";
						gunnerLeftHandAnimName="konec hlavne3";
						soundAttenuationTurret="HeliAttenuationGunner";
						isPersonTurret=1;
						personTurretAction="vehicle_turnout_1";
						memoryPointGun[]=
						{
							"z_gunL_muzzle",
							"z_gunR_muzzle"
						};
						weapons[]=
						{
							"FST_AAT_Side",
							"SmokeLauncher"
						};
						magazines[]=
						{
							"FST_500Rnd_127x99_mag_red",
							"FST_500Rnd_127x99_mag_red",
							"SmokeLauncherMag"
						};
						turretInfoType="RscWeaponRangeZeroing";
						discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
						discreteDistanceInitIndex=2;
						memoryPointGunnerOptics="CommanderView";
						memoryPointGunnerOutOptics="commanderview";
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
						gunnerOutOpticsModel="";
						gunnerOpticsEffect[]={};
						gunnerHasFlares=1;
						turretFollowFreeLook=1;
						commanding=1;
						class ViewOptics: ViewOptics
						{
							initAngleX=0;
							minAngleX=-15;
							maxAngleX=15;
							initAngleY=0;
							minAngleY=-10;
							maxAngleY=60;
							initFov=0.155;
							minFov=0.034000002;
							maxFov=0.155;
							visionMode[]=
							{
								"Normal",
								"NVG",
								"Ti"
							};
							thermalMode[]={2,3,4};
						};
						gunnerGetInAction="GetInHigh";
						gunnerGetOutAction="GetOutHigh";
						startEngine=0;
						LODTurnedOut="VIEW_GUNNER";
						LODTurnedIn="VIEW_GUNNER";
						class HitPoints
						{
							class HitTurret
							{
								armor=0.60000002;
								material=-1;
								name="Commander_Turret";
								visual="commander_turret";
								passThrough=0;
								minimalHit=0.029999999;
								explosionShielding=0.60000002;
								radius=0.15000001;
							};
							class HitGun
							{
								armor=0.60000002;
								material=-1;
								name="Commander_Gun";
								visual="Commander_Gun";
								passThrough=0;
								minimalHit=0.029999999;
								explosionShielding=0.60000002;
								radius=0.15000001;
							};
						};
						selectionFireAnim="ZaslehCommander";
					};
				};
				startEngine=0;
				memoryPointGun="usti hlavne";
				gunBeg="usti hlavne";
				gunEnd="konec hlavne";
				weapons[]=
				{
					"FST_ATTE_Turret",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"FST_thermal_coil_Red",
					"FST_thermal_coil_Red",
					"FST_thermal_coil_Red",
					"FST_thermal_coil_Red",
					"FST_thermal_coil_Red",
					"FST_thermal_coil_Red",
					"FST_thermal_coil_Red",
					"FST_thermal_coil_Red",
					"FST_thermal_coil_Red",
					"FST_thermal_coil_Red",
					"SmokeLauncherMag"
				};
				turretInfoType="RscWeaponRangeZeroing";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				selectionFireAnim="zasleh1";
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
				gunnerName="Gunner";
				proxytype="CPGunner";
				isPersonTurret=0;
				personTurretAction="vehicle_turnout_1";
				minOutElev=-20;
				maxOutElev=45;
				initOutElev=0;
				minOutTurn=-90;
				maxOutTurn=90;
				initOutTurn=0;
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_best",
					"db-40",
					1,
					50
				};
				minElev=-20;
				maxElev=70;
				initElev=0;
				inGunnerMayFire=1;
				class HitPoints
				{
					class HitTurret
					{
						armor=0.80000001;
						material=-1;
						name="otocvez";
						visual="vez";
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
						visual="";
						passThrough=0;
						minimalHit=0;
						explosionShielding=1;
						radius=0.15000001;
					};
				};
			};
		};
	};
	class FST_Blaze_AAT: FST_AAT
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Blaze AAT Flame Tank";
		crew="FST_Droid_B1_E5";
		author="Daara";
		armor=400;
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_AAT\data\Geonosis_AAT_CO.paa"
		};
				class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						body="Obsturret";
						gun="Obsgun";
						proxyIndex=1;
						viewGunnerInExternal=0;
						proxytype="CPCommander";
						gunnername="Commander";
						animationSourceBody="Obsturret";
						animationSourceGun="Obsgun";
						minOutElev=-25;
						maxOutElev=45;
						initOutElev=0;
						minOutTurn=-90;
						maxOutTurn=90;
						initOutTurn=0;
						maxHorizontalRotSpeed=1.8;
						maxVerticalRotSpeed=1.8;
						stabilizedInAxes=3;
						soundServo[]=
						{
							"A3\Sounds_F\vehicles\armor\noises\servo_best",
							"db-40",
							1,
							50
						};
						minElev=-30;
						maxElev=30;
						initElev=0;
						minTurn=-45;
						maxTurn=45;
						initTurn=0;
						gunnerAction="";
						gunnerInAction="mbt2_slot2b_in";
						forceHideGunner=0;
						outGunnerMayFire=1;
						inGunnerMayFire=1;
						gunnerRightHandAnimName="konec hlavne3";
						gunnerLeftHandAnimName="konec hlavne3";
						soundAttenuationTurret="HeliAttenuationGunner";
						isPersonTurret=1;
						personTurretAction="vehicle_turnout_1";
						memoryPointGun[]=
						{
							"z_gunL_muzzle",
							"z_gunR_muzzle"
						};
						weapons[]=
						{
							"FST_AAT_Side",
							"SmokeLauncher"
						};
						magazines[]=
						{
							"FST_500Rnd_127x99_mag_red",
							"FST_500Rnd_127x99_mag_red",
							"SmokeLauncherMag"
						};
						turretInfoType="RscWeaponRangeZeroing";
						discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
						discreteDistanceInitIndex=2;
						memoryPointGunnerOptics="CommanderView";
						memoryPointGunnerOutOptics="commanderview";
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
						gunnerOutOpticsModel="";
						gunnerOpticsEffect[]={};
						gunnerHasFlares=1;
						turretFollowFreeLook=1;
						commanding=1;
						class ViewOptics: ViewOptics
						{
							initAngleX=0;
							minAngleX=-15;
							maxAngleX=15;
							initAngleY=0;
							minAngleY=-10;
							maxAngleY=60;
							initFov=0.155;
							minFov=0.034000002;
							maxFov=0.155;
							visionMode[]=
							{
								"Normal",
								"NVG",
								"Ti"
							};
							thermalMode[]={2,3,4};
						};
						gunnerGetInAction="GetInHigh";
						gunnerGetOutAction="GetOutHigh";
						startEngine=0;
						LODTurnedOut="VIEW_GUNNER";
						LODTurnedIn="VIEW_GUNNER";
						class HitPoints
						{
							class HitTurret
							{
								armor=0.60000002;
								material=-1;
								name="Commander_Turret";
								visual="commander_turret";
								passThrough=0;
								minimalHit=0.029999999;
								explosionShielding=0.60000002;
								radius=0.15000001;
							};
							class HitGun
							{
								armor=0.60000002;
								material=-1;
								name="Commander_Gun";
								visual="Commander_Gun";
								passThrough=0;
								minimalHit=0.029999999;
								explosionShielding=0.60000002;
								radius=0.15000001;
							};
						};
						selectionFireAnim="ZaslehCommander";
					};
				};
				startEngine=0;
				memoryPointGun="usti hlavne";
				gunBeg="usti hlavne";
				gunEnd="konec hlavne";
				weapons[]=
				{
					"IDA_BTX42",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"IDA_FuelTank",
					"IDA_FuelTank",
					"IDA_FuelTank",
					"IDA_FuelTank",
					"IDA_FuelTank",
					"IDA_FuelTank",
					"IDA_FuelTank",
					"IDA_FuelTank",
					"IDA_FuelTank",
					"IDA_FuelTank",
					"SmokeLauncherMag"
				};
				turretInfoType="RscWeaponRangeZeroing";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				selectionFireAnim="zasleh1";
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
				gunnerName="Gunner";
				proxytype="CPGunner";
				isPersonTurret=0;
				personTurretAction="vehicle_turnout_1";
				minOutElev=-20;
				maxOutElev=45;
				initOutElev=0;
				minOutTurn=-90;
				maxOutTurn=90;
				initOutTurn=0;
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_best",
					"db-40",
					1,
					50
				};
				minElev=-20;
				maxElev=70;
				initElev=0;
				inGunnerMayFire=1;
				class HitPoints
				{
					class HitTurret
					{
						armor=0.80000001;
						material=-1;
						name="otocvez";
						visual="vez";
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
						visual="";
						passThrough=0;
						minimalHit=0;
						explosionShielding=1;
						radius=0.15000001;
					};
				};
			};
		};
	};
};