class CfgPatches
{
	class FST_Medical
	{
		author="Daara";
		requiredAddons[]=
		{
			"A3_Data_F",
			"A3_anims_F",
			"A3_Weapons_F",
			"A3_Characters_F",
			"A3_Characters_F_Proxies",
			"ace_medical_status",
			"ace_medical_damage",
			"ace_apl"
		};
		units[]=
		{
			"FST_Bacta_Tank_Item"
		};
		weapons[]=
		{
			"FST_Bacta_Tank"
		};
	};
};
class CfgVehicles
{
	class Item_Base_F;
	class IDA_CauterizerItem: Item_Base_F
	{
		scope=2;
		scopeCurator=2;
		displayName="[41st] Bacta Tank";
		model="kobra\442_misc\medical\Cauterizer.p3d";
		author="Daara";
		vehicleClass="Items";
		class TransportItems
		{
			class _xx_FST_Bacta_Tank
			{
				name="FST_Bacta_Tank";
				count=1;
			};
		};
	};
};
class CfgWeapons
{
	class ItemCore;
	class ACE_ItemCore;
	class CBA_MiscItem_ItemInfo;
	class FST_Bacta_Tank: ACE_ItemCore
	{
		scope=2;
		author="Daara";
		displayName="[41st] Bacta Tank";
		model="kobra\442_misc\medical\Cauterizer.p3d";
		picture="\kobra\442_misc\medical\ui\cauterizer_ui.paa";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=15;
		};
	};
};
class ACE_medical_treatment_actions
{	
	class PersonalAidKit;
	class FST_Bacta_Tank: PersonalAidKit
	{
		displayName="Apply Bacta";
		displayNameProgress="Applying Bacta...";
		items[]=
		{
			"FST_Bacta_Tank"
		};
		litter[]={};
		condition = "([_this select 1] call ace_medical_status_fnc_isInStableCondition) && (speed (_this select 0) < 1)";

	};
};
