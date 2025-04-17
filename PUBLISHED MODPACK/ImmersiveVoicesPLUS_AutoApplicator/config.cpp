class CfgPatches
{
	class PHEN_ImmersiveVoicesPLUS_AutoApplicator
	{
		units[]={};
		weapons[]={};
		requiredAddons[]={};
		author="Phenosi, Elliot and Macho";
		authorUrl="";
		version="1.1.1";
		versionStr="1.1.1";
		versionAr[]={1,1,1};
	};
};
class Extended_PreInit_EventHandlers
{
	class PHEN_ImmersiveVoicesPLUS_AutoApplicator_PreInit
	{
		init="call compile preprocessFileLineNumbers 'ImmersiveVoicesPLUS_AutoApplicator\Bootstrap\XEH_preInit.sqf'";
	};
};
class Extended_PostInit_EventHandlers
{
	class PHEN_ImmersiveVoicesPLUS_AutoApplicator_PostInit
	{
		init="call compile preprocessFileLineNumbers 'ImmersiveVoicesPLUS_AutoApplicator\Bootstrap\XEH_postInit.sqf'";
	};
};
class Extended_InitPost_EventHandlers
{
	class CAManBase
	{
		class IVP_unit_Init
		{
			init="_unit = _this select 0; if (local _unit) then { [_unit] spawn PHEN_fnc_IVP_AutoAssign; };";
		};
	};
};
class cfgMods
{
	author="Phenosi";
	timepacked="1743860183";
};
