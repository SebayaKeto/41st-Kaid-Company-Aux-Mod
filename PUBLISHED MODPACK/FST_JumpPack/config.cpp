class CfgPatches
{
	class FST_JumpPack
	{
		author = "5CentNickel / Namenai — rewrite by 41st";
		requiredAddons[] =
		{
			"A3_Data_F_Enoch_Loadorder",
			"cba_common",
			"cba_events",
			"cba_keybinding",
			"cba_xeh",
			"ace_common"
		};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] = {};
	};
};

// ─── XEH Bootstrap ───────────────────────────────────────────────────────────

class Extended_PreInit_EventHandlers
{
	class FST_Jumppack_PREINIT
	{
		init = "call compile preprocessFileLineNumbers 'FST_JumpPack\XEH_preInit.sqf'";
	};
};

class Extended_PostInit_EventHandlers
{
	class FST_Jumppack_POSTINIT
	{
		init = "call compile preprocessFileLineNumbers 'FST_JumpPack\XEH_postinit.sqf'";
	};
};

class Extended_Deleted_EventHandlers
{
	class CAManBase
	{
		class FST_Jumppack_remove_effects
		{
			// Deleted EH still exists for safety, but it exits immediately for normal infantry.
			// No scheduled thread is spawned unless this unit actually has jump-pack effects.
			init = "private _unit = _this select 0; if ((count (_unit getVariable ['FST_jumppack_effects', []])) > 0) then {[_unit] call FST_jumppack_fnc_remove_effects};";
		};
	};
};

// ─── Base Jumppack Backpack ──────────────────────────────────────────────────
// Inherit from this in your main addon config to make any backpack a jumppack.
//
// Example usage in your 41st config.cpp:
//
//   class CfgVehicles
//   {
//       class FST_JumpPack_Base;   // forward declaration
//
//       class MyCustomJumppack: FST_JumpPack_Base
//       {
//           scope = 2;
//           displayName = "[41st] JT-12 Jetpack";
//           model = "path\to\model.p3d";
//           FST_jumppack_energy_capacity = 100;
//           FST_jumppack_recharge = 8;
//           FST_jumppack_jump_types[] =
//           {
//               // Each entry: { "Name", { forwardVelo, verticalVelo, cost, angle, directional, proneAllowed } }
//               { "Standard", { 15, 20, 30, 0, 0, 0 } },
//               { "High Jump", { 5, 35, 50, 0, 0, 0 } },
//               { "Directional", { 25, 12, 40, 0, 1, 0 } }
//           };
//           FST_jumppack_sound_ignite[] = { "path\to\ignite1.ogg", "path\to\ignite2.ogg" };
//           // Optional overrides (defaults shown):
//           // FST_jumppack_jump_effect_script = "FST_jumppack_effect_fnc_jt_21";
//           // FST_jumppack_effect_points[] = { { "spine3", { 0, -0.3, -0.1 } } };
//       };
//   };

class CfgVehicles
{
	class Bag_Base;

	class FST_JumpPack_Base: Bag_Base
	{
		author = "41st Legion";
		scope = 1;   // abstract — don't show in editor. Override to 2 in child classes.
		displayName = "Jumppack Base (DO NOT USE DIRECTLY)";

		// ── Jumppack system flag ─────────────────────────────────
		FST_jumppack_is_jumppack = 1;

		// ── Energy system ────────────────────────────────────────
		FST_jumppack_energy_capacity = 100;       // max energy
		FST_jumppack_recharge = 5;                // energy per second

		// ── In-flight damage ─────────────────────────────────────
		// Multiplier for combat damage while airborne (0.0 = god mode, 1.0 = full damage)
		// Fall damage is always blocked entirely during flight.
		FST_jumppack_air_damage_mult = 0.5;       // 50% combat damage in air

		// ── Jump types ───────────────────────────────────────────
		// Array of: { "DisplayName", { forwardVelo, verticalVelo, energyCost, angle, directionalFlag, proneFlag } }
		// forwardVelo    — horizontal speed on jump
		// verticalVelo   — vertical speed on jump
		// energyCost     — energy consumed per jump
		// angle          — rotation offset for non-directional jumps (BIS_fnc_rotateVector2D)
		// directionalFlag — 1 = camera-aimed jump, 0 = facing-direction jump
		// proneFlag       — 1 = can jump while prone, 0 = cannot
		FST_jumppack_jump_types[] =
		{
			{ "Standard Jump", { 12, 18, 25, 0, 0, 0 } }
		};

		// ── Effects ──────────────────────────────────────────────
		// Function name string — resolved at runtime via compile
		FST_jumppack_jump_effect_script = "FST_jumppack_effect_fnc_jt_21";

		// Array of { "boneName", { xOffset, yOffset, zOffset } } for particle attachment
		FST_jumppack_effect_points[] =
		{
			{ "spine3", { 0, -0.3, -0.1 } }
		};

		// ── Sound ────────────────────────────────────────────────
		// Array of sound file paths — one is randomly selected per jump
		FST_jumppack_sound_ignite[] = {};

		// Array of landing sound file paths (used by add_landing_effects if enabled)
		FST_jumppack_sound_land[] = {};
	};
};
