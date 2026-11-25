// KAID_QoL_ACEFatigue (Aux Updater, 25 Nov 2026): our replacement for "Remove stamina - ACE 3".
// Turns ACE Advanced Fatigue off by blanking its four CBA event handlers (pre-start, pre-init, post-init and the stamina bar
// on the mission display), exactly the hooks ACE registers in ace_advanced_fatigue. Loads after ACE (requiredAddons);
// skipped if ACE is not loaded. Vanilla stamina is then kept off by KAID_QoL's client script.
class CfgPatches
{
	class KAID_QoL_ACEFatigue
	{
		name="41st Kaid QoL - ACE fatigue off";
		author="41st Kaid Company";
		units[]={};
		weapons[]={};
		requiredVersion=2.14;
		requiredAddons[]={"ace_advanced_fatigue"};
		skipWhenMissingDependencies=1;
	};
};
class Extended_PreStart_EventHandlers
{
	class ace_advanced_fatigue
	{
		init="";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_advanced_fatigue
	{
		init="";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_advanced_fatigue
	{
		init="";
	};
};
class Extended_DisplayLoad_EventHandlers
{
	class RscDisplayMission
	{
		ace_advanced_fatigue="";
	};
};
