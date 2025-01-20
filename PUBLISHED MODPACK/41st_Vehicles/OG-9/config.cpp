class CfgPatches
{
	class FST_OG9_Static
	{
		requiredAddons[]=
		{
			"3AS_Static"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_OG9Turret"
		};
		weapons[]={};
	};
};
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
	class 3AS_OG9Turret: StaticMGWeapon {};
	class FST_OG9Turret: 3AS_OG9Turret
	{
		author="Adapted from 3AS Mod Team by Viz";
		_generalMacro="HMG_01_base_F";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=0;
		faction="FST_BattleDroids_Faction";
		crew="FST_Droid_B1_OOM";
		displayName="[41st] OG-9";
		model="3AS\3as_static\OG9\3AS_OG9.p3d";
		editorSubcategory="EdSubcat_Turrets";
		icon="3AS\3as_static\OG9\Data\ui\OG9_top_ca.paa";
		picture="3AS\3as_static\OG9\Data\ui\OG9_side_ca.paa";
		threat[]={1,0.30000001,0.30000001};
		cost=150000;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				displayName="Bottom Gun";
				optics=1;
				discreteDistance[]={100,200,300,400,600,800,1000,1200,1500,1600,1700,1800,1900,2000};
				discreteDistanceInitIndex=2;
				turretInfoType="RscOptics_crows";
				gunnerforceoptics=1;
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
					"ParticleBeamCannon_R"
				};
				magazines[]=
				{
					"Laser_Battery_F",
					"Laser_Battery_F",
					"Laser_Battery_F",
					"Laser_Battery_F"
				};
			};
			class Top_Turret: MainTurret
			{
				displayName="Top Gun";
				optics=1;
				discreteDistance[]={100,200,300,400,600,800,1000,1200,1500,1600,1700,1800,1900,2000};
				discreteDistanceInitIndex=2;
				turretInfoType="RscOptics_crows";
				gunnerforceoptics=1;
				gunnerOpticsModel="\a3\weapons_f_gamma\reticle\HMG_01_Optics_Gunner_F";
				minElev=-25;
				maxElev=45;
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
				body="mainTurret_2";
				gun="mainGun_2";
				animationSourceBody="mainTurret_2";
				animationSourceGun="mainGun_2";
				weapons[]=
				{
					"ParticleBeamCannon_R"
				};
				magazines[]=
				{
					"Laser_Battery_F",
					"Laser_Battery_F",
					"Laser_Battery_F",
					"Laser_Battery_F"
				};
				memoryPointGun="Muzzle_T";
				selectionFireAnim="zasleh2";
				gunBeg="Muzzle_T";
				gunEnd="Chamber_T";
				gunnerAction="FieldCannon_Gunner";
				viewGunnerInExternal=0;
				gunnergetInAction="";
				gunnergetOutAction="";
				memoryPointsGetInGunner="pos_gunner";
				memoryPointsGetInGunnerDir="pos_gunner_dir";
				memorypointgunneroptics="gunnerview_T";
				gunnerRightHandAnimName="OtocHlaven_shake";
				gunnerLeftHandAnimName="OtocHlaven_shake";
				ejectDeadGunner=0;
			};
		};
		class AnimationSources
		{
		};
	};
};