class CfgPatches
{
	class FST_Scorponek
	{
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Static_F_Jets"
			
		};
		units[]=
		{
			"FST_Scorponek"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
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
		class Components;
	};
	class HitPoints;
	class DBA_Scorponek_Base: StaticMGWeapon{};
	class FST_Scorponek_Base: DBA_Scorponek_Base
	{
		author="Viz";
		scope=0;
		scopeCurator=0;
		faction="FST_BattleDroids_Faction";
		accuracy=1;
		armor=300;
		armorStructural=2;
		explosionshielding=1;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				memoryPointsGetInGunner="GunnerIn";
				memoryPointsGetInGunnerDir="GunnerIn_dir";
				turretinfotype="RscOptics_APC_Tracked_01_gunner";
				animationSourceBody="MainTurret";
				Body="MainTurret";
				animationSourceGun="MainGun";
				Gun="MainGun";
				optics=1;
				minElev=-15;
				maxElev=55;
				minTurn=-360;
				maxTurn=360;
				hasgunner=1;
				gunnerName="Scorponek AI";
				primary=1;
				primaryGunner=1;
				startEngine=0;
				enableManualFire=1;
				selectionFireAnim="zasleh";
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
				gunnerForceOptics=1;
				memoryPointGun[]=
				{
					"gun_left_Down",
					"gun_left_Up",
					"gun_Right_Down",
					"Gun_left_Up"
				};
				uavCameraGunnerPos="camera_pos";
				uavCameraGunnerDir="camera_dir";
				memoryPointGunnerOptics="camera_pos";
				forceHideGunner=1;
				gunnerOutForceOptics=1;
				viewgunnerinExternal=0;
				outGunnerMayFire=1;
				inGunnerMayFire=1;
				castGunnerShadow=0;
				showAllTargets=2;
				class OpticsIn
				{
					class Wide
					{
						opticsDisplayName="W";
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						initFov=0.46599999;
						minFov=0.46599999;
						maxFov=0.46599999;
						visionMode[]=
						{
							"Normal",
							"NVG",
							"Ti"
						};
						thermalMode[]={0,1};
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
					};
					class Medium: Wide
					{
						opticsDisplayName="M";
						initFov=0.093000002;
						minFov=0.093000002;
						maxFov=0.093000002;
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_m_F";
					};
					class Narrow: Wide
					{
						opticsDisplayName="N";
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_n_F";
						initFov=0.028999999;
						minFov=0.028999999;
						maxFov=0.028999999;
					};
				};
				weapons[]=
				{
					"DBA_65mw_Tonnerre_LC"
				};
				magazines[]=
				{
					"DBA_65mm_Fulmine_x800_mag",
					"DBA_65mm_Fulmine_x800_mag"
				};
			};
		};
		class animationsources
		{
			class ScorponekShieldHide
			{
				animPeriod=0.001;
				initPhase=0;
				source="user";
			};
		};
	};
	class FST_Scorponek: FST_Scorponek_Base
	{
		class SimpleObject
		{
			eden=1;
			verticalOffset=2.467;
			verticalOffsetWorld=-0.039000001;
			init="''";
		};
		author="Viz";
		scope=2;
		scopeCurator=2;
		side=0;
		displayName="[41st] Scorponek";
		crew="B_UAV_AI";
		typicalCargo[]=
		{
			"B_UAV_AI"
		};
	};
};
class Extended_Init_EventHandlers
{
	class FST_Scorponek
	{
		class FST_Scorponek_Init_Eh
		{
			init="_this execVM 'DBA_CIS\Addons\DBA_Vehicles\DBA_GroundVehicles\DBA_Scorponek\ScorponekShieldRegen.sqf'";
		};
	};
};
class Extended_HitPart_EventHandlers
{
	class FST_Scorponek
	{
		class FST_Scorponek_HitPart_Eh
		{
			hitpart="_this select 0 execVM 'DBA_CIS\Addons\DBA_Vehicles\DBA_GroundVehicles\DBA_Scorponek\ScorponekShieldHit.sqf'";
		};
	};
};