class CfgPatches
{
	class MEAP_Core
	{
		author="Maldova";
		name="MEAP Core";
		units[]={};
		weapons[]={};
		requiredAddons[]=
		{
			"A3_Data_F_Enoch_Loadorder",
			"CBA_MAIN",
			"ace_interact_menu"
		};
		requiredVersion=0.1;
	};
};
class CfgFunctions
{
	class MEAP
	{
		class Snap
		{
			file="MEAP\MEAP_Core\functions\snap";
			class applySnapTransform
			{
			};
			class getCompatibleSnapPoints
			{
			};
			class getSnapCategory
			{
			};
			class isSnappable
			{
			};
			class pointNameFromSide
			{
			};
			class oppositeSide
			{
			};
			class registerAceActions
			{
				postInit=1;
			};
			class setSnapSource
			{
			};
			class snapSourceToTarget
			{
			};
		};
	};
};
