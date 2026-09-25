class CfgPatches
{
	class MEAP_Architect_Core
	{
		author="Maldova";
		name="MEAP Daidalos";
		units[]=
		{
			"MEAP_ModuleAssignArchitect",
			"MEAP_ModuleRevokeArchitect"
		};
		weapons[]={};
		requiredAddons[]=
		{
			"A3_Modules_F_Curator_Curator",
			"A3_Structures_F",
			"CBA_MAIN",
			"cba_events",
			"cba_keybinding",
			"cba_settings",
			"MEAP_Core",
			"MEAP_Economy_Core",
			"MEAP_SW_Props",
			"MEAP_SW_Structures"
		};
		requiredVersion=0.1;
	};
};
class CfgFunctions
{
	class MEAP
	{
		class Architect
		{
			file="MEAP\MEAP_Architect\MEAP_Architect_Core\functions";
			class addArchitectZone
			{
			};
			class architectActionResult
			{
			};
			class architectApplyAction
			{
			};
			class architectAuthorizeObject
			{
			};
			class architectBlueprintAction
			{
			};
			class architectCameraTick
			{
			};
			class architectDeleteAction
			{
			};
			class architectFobAction
			{
			};
			class architectFobTick
			{
			};
			class architectMessage
			{
			};
			class architectPrimaryAction
			{
			};
			class architectPublishAction
			{
			};
			class architectRecordAudit
			{
			};
			class architectSelectEdit
			{
			};
			class architectServerAction
			{
			};
			class architectUndo
			{
			};
			class closeArchitectMode
			{
			};
			class closeArchitectCamera
			{
			};
			class clearArchitectPreview
			{
			};
			class clearArchitectZones
			{
			};
			class createArchitectGhost
			{
			};
			class drawArchitectRadius
			{
			};
			class getArchitectKey
			{
			};
			class getArchitectBuildCost
			{
			};
			class getArchitectPaletteMetadata
			{
			};
			class getArchitectFob
			{
			};
			class handleArchitectCameraKey
			{
			};
			class initializeArchitectState
			{
			};
			class isArchitectEligible
			{
			};
			class moduleAssignArchitect
			{
			};
			class openArchitectMode
			{
			};
			class openArchitectPaletteWheel
			{
			};
			class parseArchitectClassList
			{
			};
			class parseArchitectCompositions
			{
			};
			class postInitArchitect
			{
				postInit=1;
			};
			class preInitArchitect
			{
				preInit=1;
			};
			class requestArchitectMode
			{
			};
			class refreshArchitectPalette
			{
			};
			class selectArchitectPaletteItem
			{
			};
			class closeArchitectPaletteWheel
			{
			};
			class updateArchitectPaletteWheel
			{
			};
		};
	};
};
class CfgFactionClasses
{
	class NO_CATEGORY;
	class MEAP_Modules: NO_CATEGORY
	{
		displayName="MEAP";
	};
};
class CfgVehicles
{
	class Module_F;
	class MEAP_ModuleAssignArchitect: Module_F
	{
		author="Maldova";
		category="MEAP_Modules";
		curatorCanAttach=1;
		displayName="Assign MEAP Daidalos";
		function="MEAP_fnc_moduleAssignArchitect";
		functionPriority=1;
		isDisposable=1;
		isGlobal=1;
		isTriggerActivated=0;
		MEAP_grantArchitect=1;
		scope=1;
		scopeCurator=2;
	};
	class MEAP_ModuleRevokeArchitect: MEAP_ModuleAssignArchitect
	{
		displayName="Revoke MEAP Daidalos";
		MEAP_grantArchitect=0;
	};
};
class CfgRemoteExec
{
	class Functions
	{
		class MEAP_fnc_architectMessage
		{
			allowedTargets=1;
			jip=0;
		};
		class MEAP_fnc_architectActionResult
		{
			allowedTargets=1;
			jip=0;
		};
		class MEAP_fnc_architectServerAction
		{
			allowedTargets=2;
			jip=0;
		};
		class MEAP_fnc_architectFobAction
		{
			allowedTargets=2;
			jip=0;
		};
		class MEAP_fnc_closeArchitectMode
		{
			allowedTargets=2;
			jip=0;
		};
		class MEAP_fnc_closeArchitectCamera
		{
			allowedTargets=1;
			jip=0;
		};
		class MEAP_fnc_openArchitectMode
		{
			allowedTargets=1;
			jip=0;
		};
		class MEAP_fnc_requestArchitectMode
		{
			allowedTargets=2;
			jip=0;
		};
	};
};
class CfgGroups
{
	class West
	{
		class MEAP_Daidalos
		{
			name="MEAP Daidalos Compositions";
			class MEAP_Daidalos_BarrierPair
			{
				name="Duracrete Barrier Pair";
				class Unit0
				{
					name="Duracrete Barrier Left";
					vehicle="MEAP_SW_Props_Common_DuracreteBarrierOne_NoFiringPort";
					position[]={-2,0,0};
					azimut=0;
				};
				class Unit1: Unit0
				{
					name="Duracrete Barrier Right";
					position[]={2,0,0};
				};
			};
		};
	};
};
