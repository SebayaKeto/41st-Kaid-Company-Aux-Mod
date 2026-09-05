class CfgPatches
{
	class umbara_trees
	{
		units[] = {"UMBARA_Module_Swap", "UMBARA_Module_Exclusion"};
		weapons[] = {};
		requiredVersion = 2.10;
		requiredAddons[] = {"cba_main", "cba_settings"};
		author = "41st";
		authors[] = {"41st"};
	};
};

class CfgFunctions
{
	class umbara_trees
	{
		class trees
		{
			file = "umbara_trees\functions";
			class moduleSwap {};
			class moduleExclusion {};
			class pointInArea {};
			class swapTick {};
			class exclusionTick {};
			class streamTick {};
			class hideTick {};
			class loadMapData {};
			class exportMapData {};
			class postInit
			{
				postInit = 1;
			};
		};
	};
};

// Module category (CfgFactionClasses side=7, not CfgVehicleClasses — see README.md)
class CfgFactionClasses
{
	class UMBARA_Modules
	{
		displayName = "Umbara Modules";
		priority = 2;
		side = 7;
	};
};

class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
		class AttributesBase;
		class ModuleDescription;
	};

	class UMBARA_Module_Swap: Module_F
	{
		author = "41st";
		category = "UMBARA_Modules";
		displayName = "Umbara Tree Swap";

		scope = 2;
		scopeCurator = 2;

		function = "umbara_trees_fnc_moduleSwap";
		functionPriority = 1;

		isGlobal = 1;
		isTriggerActivated = 0;
		curatorCanAttach = 0;

		// Live Eden preview (see README.md)
		is3DEN = 1;

		// Area handle — authoritative for real runs; Eden preview can't read
		// its live size, falls back to UMBARA_PreviewRadius (see README.md)
		canSetArea = 1;
		canSetAreaShape = 1;
		canSetAreaHeight = 0;

		class Arguments
		{
			class UMBARA_PreviewRadius
			{
				displayName = "Eden Preview Sample Radius (m)";
				description = "Radius of the sample patch used ONLY for live Eden preview (to check Prop List/Hide Native Trees settings while editing) — has no effect on real mission runs, which always use this module's actual Area handle size correctly. The Area handle's live-dragged size cannot be read by script while editing (a confirmed Eden/engine limitation, not a bug here — see README.md), so this preview patch will not match the handle's real size or position boundary until you Preview/host the mission.";
				typeName = "NUMBER";
				defaultValue = 150;
			};
			class UMBARA_BatchSize
			{
				displayName = "Props Per Frame";
				description = "How many hide/create operations are performed per real frame once discovery finishes. Higher = faster completion, more per-frame cost, more stutter risk. (Trigger equivalent: UMBARA_T1_BATCH)";
				typeName = "NUMBER";
				defaultValue = 160;
			};
			class UMBARA_ChunksPerFrame
			{
				displayName = "Discovery Chunks Per Frame";
				description = "How many 1km discovery chunks are scanned per frame before placement begins. (Trigger equivalent: UMBARA_T1_CPF)";
				typeName = "NUMBER";
				defaultValue = 3;
			};
			class UMBARA_ChunkSize
			{
				displayName = "Discovery Chunk Size (m)";
				description = "Size of each discovery tile in meters. (Trigger equivalent: UMBARA_T1_CS)";
				typeName = "NUMBER";
				defaultValue = 1000;
			};
			class UMBARA_HideNativeTrees
			{
				displayName = "Hide Native Trees/Bushes";
				description = "If enabled, EVERY discovered tree/bush in the area is hidden (networked, server-only effect) — independent of Replace 1 In Every N Trees below, which only controls how many also get an Umbara prop. Disable to leave all native vegetation visible; props are still placed per the replace ratio either way.";
				typeName = "BOOL";
				defaultValue = 1;
			};
			class UMBARA_ReplaceEveryNth
			{
				displayName = "Replace 1 In Every N Trees";
				description = "Controls Umbara PROP placement only — hiding (see Hide Native Trees/Bushes above) always applies to every discovered tree/bush regardless of this setting. 1 = place a prop at every discovered tree/bush (heaviest). 2 = place a prop on roughly half, 3 = roughly a third, etc. Positions that don't get a prop become bare ground once hidden, not an untouched native tree. Selection is deterministic per-position (not true random), so every machine picks the exact same positions.";
				typeName = "NUMBER";
				defaultValue = 2;
			};
			class UMBARA_PropList
			{
				displayName = "Umbara Prop List (blank = use full default set)";
				description = "Comma-separated classnames to place. Leave blank to use the full default 47-prop set (defined in fn_moduleSwap.sqf); fill in your own comma-separated list to override it — this replaces manually editing the prop array in a trigger Condition field.";
				typeName = "STRING";
				defaultValue = "";
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description = "Place over the area to reskin with Umbara props. Resize using the Area handle (same as a trigger's Size A/B) — this is what real mission runs actually use. Every native tree/bush found inside it is hidden (if Hide Native Trees/Bushes is on); only 1 in every N of them (Replace 1 In Every N Trees) also gets an Umbara prop at the same position — never a blind grid fill, so open fields/roads/water are left alone, and unselected positions become bare ground once hidden. Live Eden preview cannot follow the handle's live size (a confirmed Eden engine limitation), so it instead shows a fixed-radius sample patch (Eden Preview Sample Radius Attribute) purely to preview Prop List/Hide Native Trees settings.";
			class Arguments: Arguments {};
		};
	};

	class UMBARA_Module_Exclusion: Module_F
	{
		author = "41st";
		category = "UMBARA_Modules";
		displayName = "Umbara Exclusion Zone";

		scope = 2;
		scopeCurator = 2;

		function = "umbara_trees_fnc_moduleExclusion";
		functionPriority = 1;

		isGlobal = 1;
		isTriggerActivated = 0;
		curatorCanAttach = 0;

		// Live Eden preview — hides matched props instead of deleting (see README.md)
		is3DEN = 1;

		// Area handle — same as UMBARA_Module_Swap above
		canSetArea = 1;
		canSetAreaShape = 1;
		canSetAreaHeight = 0;

		class Arguments
		{
			class UMBARA_PreviewRadius
			{
				displayName = "Eden Preview Sample Radius (m)";
				description = "Radius of the sample patch used ONLY for live Eden preview — has no effect on real mission runs, which always use this module's actual Area handle size correctly. See UMBARA_Module_Swap's matching Attribute description for why.";
				typeName = "NUMBER";
				defaultValue = 75;
			};
			class UMBARA_ChunksPerFrame
			{
				displayName = "Discovery Chunks Per Frame";
				description = "How many 1km discovery chunks are scanned per frame during the terrain-clutter hide pass. (Trigger equivalent: UMBARA_T2_CPF)";
				typeName = "NUMBER";
				defaultValue = 3;
			};
			class UMBARA_ChunkSize
			{
				displayName = "Discovery Chunk Size (m)";
				description = "Size of each discovery tile in meters. (Trigger equivalent: UMBARA_T2_CS)";
				typeName = "NUMBER";
				defaultValue = 1000;
			};
			class UMBARA_ScanPerFrame
			{
				displayName = "Placed Props Scanned Per Frame";
				description = "How many entries of the full placed-props list get checked per frame to find ones inside this zone. This has to walk the entire list regardless of this zone's size, so it can safely run much faster than the per-frame batch below. (Trigger equivalent: UMBARA_T2_SCANPF)";
				typeName = "NUMBER";
				defaultValue = 2000;
			};
			class UMBARA_BatchSize
			{
				displayName = "Items Per Frame";
				description = "How many hide/delete operations are performed per frame once scanning is done. (Trigger equivalent: UMBARA_T2_BATCH)";
				typeName = "NUMBER";
				defaultValue = 60;
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description = "Place over a sub-area (building interior, LZ, road, etc.) to force zero decoration there, overriding the Swap module. Resize using the Area handle — same real-run/preview split as the Swap module (see its description). Waits for the Swap module to finish before running in a real mission.";
			class Arguments: Arguments {};
		};
	};
};
