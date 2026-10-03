// KAID_3AS_ParticleCannon_Fix: lets AI gunners on 3AS particle cannons engage targets below the gun.
// The 3AS turret allows only -10 deg depression, so cannons on mesa tops / raised walls never fire at
// infantry or vehicles in the valley (engine-probed 3 Oct: no shots at a ~24 deg drop over 350 m).
class CfgPatches
{
	class KAID_3AS_ParticleCannon_Fix
	{
		name = "KAID 3AS Particle Cannon depression fix";
		author = "41st Aux Updater";
		units[] = {};
		weapons[] = {};
		requiredVersion = 2.0;
		requiredAddons[] = {"3AS_Static_ParticleCannon"};
		skipWhenMissingDependencies = 1;
	};
};
class CfgVehicles
{
	class StaticWeapon;
	class StaticMGWeapon: StaticWeapon
	{
		class Turrets;
	};
	class 3as_ParticleCannon_Base: StaticMGWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class 3as_ParticleCannon: 3as_ParticleCannon_Base
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				minElev = -30;
			};
		};
	};
};
