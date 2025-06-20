class CfgPatches
{
	class FST_PAC
	{
		author = "Laer";
		requiredAddons[] =
		{
			"A3_Armor_F_Beta",
			"3AS_Main",
			"3AS_VehicleWeapons",
			"3AS_APC_Jug",
			"3AS_Animations"
		};
		units[] = { "FST_PAC_41st" };
		weapons[] = {};
	};
};

class CfgVehicles
{
	class 3AS_PAC_F;

	class FST_PAC_41st : 3AS_PAC_F
	{
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;

		displayName = "[41st] Platoon Assault Craft";
		author = "Laer";
		faction = "FST_BattleDroids_Faction";
		editorSubcategory = "FST_Ground_Vehicle";
		side = 0;

		crew = "FST_Droid_B1_OOM";
		typicalCargo[] = { "FST_Droid_B1_OOM" };

		armor = 500;
		armorStructural = 2;
		damageResistance = 0;

		maximumLoad = 6000;
		ace_cargo_space = 40;
		ace_cargo_hasCargo = 1;

		class Wheels
		{
			class L1
			{
				boneName = "wheel_1_1_damper";
				steering = 1;
				side = "left";
				center = "wheel_1_1_axis";
				boundary = "wheel_1_1_bound";
				width = "0.2";
				mass = 30;
				MOI = 14;
				dampingRate = 1.75;
				dampingRateDamaged = 1;
				dampingRateDestroyed = 0;
				maxBrakeTorque = 9000;
				maxHandBrakeTorque = 0;
				suspTravelDirection[] = {0,-1,0};
				suspForceAppPointOffset = "wheel_1_1_axis";
				tireForceAppPointOffset = "wheel_1_1_axis";
				maxCompression = 0.25;
				maxDroop = 0.25;
				sprungMass = 2375;
				springStrength = 116375;
				springDamperRate = 33250;
				longitudinalStiffnessPerUnitGravity = 10000;
				latStiffX = 25;
				latStiffY = 180;
				frictionVsSlipGraph[] = {{0,1},{0.5,1},{1,1}};
			};
			class R1 : L1
			{
				steering = 1;
				boneName = "wheel_2_1_damper";
				center = "wheel_2_1_axis";
				boundary = "wheel_2_1_bound";
				suspForceAppPointOffset = "wheel_2_1_axis";
				tireForceAppPointOffset = "wheel_2_1_axis";
				side = "right";
			};
			class L2 : L1
			{
				boneName = "wheel_1_2_damper";
				steering = 1;
				maxHandBrakeTorque = 4000;
				center = "wheel_1_2_axis";
				boundary = "wheel_1_2_bound";
				suspForceAppPointOffset = "wheel_1_2_axis";
				tireForceAppPointOffset = "wheel_1_2_axis";
			};
			class L3 : L1
			{
				boneName = "wheel_1_3_damper";
				steering = 0;
				maxHandBrakeTorque = 4000;
				center = "wheel_1_3_axis";
				boundary = "wheel_1_3_bound";
				suspForceAppPointOffset = "wheel_1_3_axis";
				tireForceAppPointOffset = "wheel_1_3_axis";
			};
			class L4 : L1
			{
				boneName = "wheel_1_4_damper";
				steering = 0;
				center = "wheel_1_4_axis";
				boundary = "wheel_1_4_bound";
				maxHandBrakeTorque = 4000;
				suspForceAppPointOffset = "wheel_1_4_axis";
				tireForceAppPointOffset = "wheel_1_4_axis";
			};
			class R2 : R1
			{
				boneName = "wheel_2_2_damper";
				steering = 1;
				maxHandBrakeTorque = 4000;
				center = "wheel_2_2_axis";
				boundary = "wheel_2_2_bound";
				suspForceAppPointOffset = "wheel_2_2_axis";
				tireForceAppPointOffset = "wheel_2_2_axis";
			};
			class R3 : R1
			{
				boneName = "wheel_2_3_damper";
				steering = 0;
				maxHandBrakeTorque = 4000;
				center = "wheel_2_3_axis";
				boundary = "wheel_2_3_bound";
				suspForceAppPointOffset = "wheel_2_3_axis";
				tireForceAppPointOffset = "wheel_2_3_axis";
			};
			class R4 : R1
			{
				boneName = "wheel_2_4_damper";
				steering = 0;
				center = "wheel_2_4_axis";
				boundary = "wheel_2_4_bound";
				maxHandBrakeTorque = 4000;
				suspForceAppPointOffset = "wheel_2_4_axis";
				tireForceAppPointOffset = "wheel_2_4_axis";
			};
		};

		class HitPoints {
			class HitHull {
				armor = 1;
				material = -1;
				name = "hit_hull_point";
				visual = "zbytek";
				passThrough = 1;
				minimalHit = 0.1;
				explosionShielding = 0.7;
				radius = 0.33;
			};

			class HitEngine {
				armor = 0.01;
				material = -1;
				name = "hit_engine_point";
				visual = "engine";
				passThrough = 1;
				minimalHit = 0.01;
				explosionShielding = 0.1;
				radius = 0.33;
			};

			class HitFuel {
				armor = 1;
				material = -1;
				name = "hit_fuel_point";
				passThrough = 0.5;
				explosionShielding = 1.5;
				minimalHit = 0.1;
				radius = 0.33;
			};
		};
	};
};
