// ===================================================================================
// Medium wall family
// -----------------------------------------------------------------------------------
// This file defines medium outpost wall objects intended for placement in Eden/Zeus.
// Structure pattern:
// - One hidden base class containing shared geometry + visual configuration.
// - Public child classes that expose placeable variants.
//
// Design intent:
// - Keep common setup centralized (model path, hidden selections, material setup).
// - Reduce copy/paste errors when adding future texture or faction variants.
// ===================================================================================
class FST_Outpost_MediumWall_Base: House_F
{
	// Eden category + subcategory placement tree.
	// Controls where this object appears in the editor browser hierarchy.
	editorCategory = "FST_CatagoryMajorOutpost";
	editorSubcategory = "FST_Subcategory_OutpostWallsNeutral";

	// scope=0 keeps this class hidden from direct editor placement.
	scope = 0;
	// scopecurator=0 keeps this base class hidden from Zeus.
	scopecurator = 0;

	// Preferred placement axis in editor tools.
	// Useful for snap/rotate workflows when composing wall lines.
	placement = "vertical";
	// Small map icon footprint.
	mapSize = 1;
	// Disable destruction behavior for this wall asset.
	destrType = "DestructNo";

	// Fallback display name (overridable by child classes).
	displayName = "Medium Outpost Wall (Short)";
	// Geometry/model path for this wall piece.
	model = "FST\FST_Outpost\MediumWalls\FST_OutpostWall_MediumShort.p3d";

	// Named model selection(s) that can receive runtime/variant visuals.
	// The selection names must match those exported in the P3D.
	hiddenSelections[]={"Camo","Decals"};
	// Texture applied to hidden selection(s).
	hiddenSelectionsTextures[]=
	{
		"FST\FST_Outpost\MediumWalls\Data\Textures\Walls\Camo_co.paa",
		"FST\FST_Core\TrimSheets\Republic_DecalSheet\Republic_DecalSheet_Green_CA.paa"
	};
	// Material (rvmat) applied to hidden selection(s).
	// Keep this aligned with texture channels expected by the rvmat.
	hiddenSelectionsMaterials[]=
	{
		"FST\FST_Outpost\MediumWalls\Data\Textures\Walls\Camo.rvmat",
		"FST\FST_Core\TrimSheets\Republic_DecalSheet\Republic_DecalSheet.rvmat"
	};
	/*
	class Attributes
		{
			class FST_Faction_DecalSelector
			{
				displayName = "Faction Decal";
				tooltip = "Set faction decals.";
				property = "FST_Faction_Decal";
				control = "combo";
				typeName = "STRING";
				defaultValue = """Empty""";
				expression = "[_this, _value] call FST_fnc_applyFactionDecal;";
				category = "FST_FactionDecalCategory";
				class Values
				{
					class Empty
					{
						name = "None";
						value = "Empty";
					};
					class Republic_Maroon
					{
						name = "Republic (Maroon)";
						value = "Republic_Maroon";
					};
					class Republic_Green
					{
						name = "Republic (Green)";
						value = "Republic_Green";
					};
				};
			};
		};
	*/

	// Enable appearance in Eden and define preview thumbnail.
	// Preview image improves quick visual identification during object placement.
	eden = 1;
	editorPreview = "\FST\FST_Outpost\MediumWalls\Data\Icons\FST_RepublicOutpostMediumShortPreview.jpg";
};
// Public, placeable variant derived from the shared base class.
// Extend this pattern for additional medium wall skins/markings.
class FST_Outpost_MediumWallShort_Unmarked: FST_Outpost_MediumWall_Base
{
	// scope=2 exposes class in Eden object browser.
	scope = 2;
	// scopecurator=2 exposes class in Zeus curator interface.
	scopecurator = 2;
	displayName = "Medium Outpost Wall (Short)";
};
class FST_Outpost_MediumWallSkinny_Unmarked: FST_Outpost_MediumWall_Base
{
	// scope=2 exposes class in Eden object browser.
	scope = 2;
	// scopecurator=2 exposes class in Zeus curator interface.
	scopecurator = 2;
	displayName = "Medium Outpost Wall (Skinny)";
	model = "FST\FST_Outpost\MediumWalls\FST_OutpostWall_MediumShortThin.p3d";
	editorPreview = "\FST\FST_Outpost\MediumWalls\Data\Icons\FST_RepublicOutpostMediumSkinnyPreview.jpg";
};
class FST_Outpost_MediumWallMedium_Unmarked: FST_Outpost_MediumWall_Base
{
	// scope=2 exposes class in Eden object browser.
	scope = 2;
	// scopecurator=2 exposes class in Zeus curator interface.
	scopecurator = 2;
	displayName = "Medium Outpost Wall (Medium)";
	model = "FST\FST_Outpost\MediumWalls\FST_OutpostWall_MediumMedium.p3d";
};
class FST_Outpost_MediumWallFoxhole: FST_Outpost_MediumWall_Base
{
	// scope=2 exposes class in Eden object browser.
	scope = 2;
	// scopecurator=2 exposes class in Zeus curator interface.
	scopecurator = 2;
	displayName = "Medium Outpost Wall (Foxhole)";
	model = "FST\FST_Outpost\MediumWalls\FST_OutpostWall_MediumFoxhole.p3d";
	editorPreview = "\FST\FST_Outpost\MediumWalls\Data\Icons\FST_RepublicOutpostMediumFoxholePreview.jpg";
	// Texture applied to hidden selection(s).
	hiddenSelectionsTextures[]=
	{
		"FST\FST_Outpost\MediumWalls\Data\Textures\Foxholes\Camo_co.paa",
		"FST\FST_Core\TrimSheets\Republic_DecalSheet\Republic_DecalSheet_Green_CA.paa"
	};
	// Material (rvmat) applied to hidden selection(s).
	// Keep this aligned with texture channels expected by the rvmat.
	hiddenSelectionsMaterials[]=
	{
		"FST\FST_Outpost\MediumWalls\Data\Textures\Foxholes\Camo.rvmat",
		"FST\FST_Core\TrimSheets\Republic_DecalSheet\Republic_DecalSheet.rvmat"
	};
};
class FST_Outpost_MediumWallRamp_Unmarked: FST_Outpost_MediumWall_Base
{
	// scope=2 exposes class in Eden object browser.
	scope = 2;
	// scopecurator=2 exposes class in Zeus curator interface.
	scopecurator = 2;
	displayName = "Medium Outpost Wall (Ramp)";
	model = "FST\FST_Outpost\MediumWalls\FST_OutpostWall_MediumRamp.p3d";
	editorPreview = "\FST\FST_Outpost\MediumWalls\Data\Icons\FST_RepublicOutpostMediumRampPreview.jpg";
	hiddenSelections[]={"Camo"};
	// Texture applied to hidden selection(s).
	hiddenSelectionsTextures[]=
	{
		"FST\FST_Outpost\MediumWalls\Data\Textures\Ramps\Camo_Ramp_co.paa"
	};
	// Material (rvmat) applied to hidden selection(s).
	// Keep this aligned with texture channels expected by the rvmat.
	hiddenSelectionsMaterials[]=
	{
		"FST\FST_Outpost\MediumWalls\Data\Textures\Ramps\Camo_Ramp.rvmat"
	};
};
class FST_Outpost_MediumWallRampSkinny_Unmarked: FST_Outpost_MediumWallRamp_Unmarked
{
	displayName = "Medium Outpost Wall (Ramp Skinny)";
	model = "FST\FST_Outpost\MediumWalls\FST_OutpostWall_MediumRampSkinny.p3d";
};


