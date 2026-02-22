// ===================================================================================
// MASTER CONFIG: FST_Outpost_Structures
// -----------------------------------------------------------------------------------
// Purpose:
// - Serves as the single entry point for the FST Outpost structure package.
// - Pulls in wall variant definitions from subfolder include files.
// - Declares the addon patch metadata used by Arma's config loader.
//
// Build / load notes:
// - Compile this master config through your normal PBO pipeline.
// - Do not compile subfolder configs in isolation when they depend on this root context.
// - Keep engine base-class declarations centralized here to reduce duplication.
// ===================================================================================
#include "sounds.cpp"

class CfgPatches
{
    class FST_Outpost_Structures
    {
        // Metadata shown by tools and for internal tracking.
        author = "FST";
        name = "FST Outpost Structures";

        // Dependencies that must be loaded first.
        requiredAddons[] = {"A3_Structures_F"};

        // Minimum game config version expected.
        requiredVersion = 0.1;

        // Units defined in this package; used for editor placement and Zeus.
        units[] = {
            "FST_OutpostWall_Unmarked",
            "FST_OutpostWall_Unmarked_Curve",
            "FST_OutpostWall_Entrance_Unmarked",
            "FST_OutpostWall_Entrance_Hutt",
            "FST_OutpostWall_Entrance_BlackSun",
            "FST_OutpostWall_Entrance_GAROne"
        };

        // No weapon definitions in this package.
        weapons[] = {};
    };
};

class CfgFunctions
{
    class FST_Outpost
    {
        class Walls
        {
            file = "FST\FST_Outpost\functions";
            class applyCamo1 {};
        };
    };
};

class CfgVehicles
{
	// Engine base classes used for inheritance.
	// Included files below extend these classes.
	class House;
	class House_F: House
	{
		class DestructionEffects;
	};
	class Ruins_F;

	// Modular vehicle/object config includes.
	// Keep includes grouped by asset family for maintainability.
    #include "MediumWalls/MediumWalls.cpp"
    #include "LightWalls/LightWalls.cpp"
};
