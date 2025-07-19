class CfgPatches
{
	class FST_Flags
	{
		author="Gold";
		requiredAddons[]=
		{
			"ace_common",
			"ace_interact_menu",
			"ace_interaction"
		};
		units[]=
		{
			"FST_Flags_Carrier_Banshee",
		};
		weapons[]=
		{
			"FST_Flags_Placeable_Banshee",
		};
	};
};
class CBA_Extended_EventHandlers;
class CfgVehicles
{
	class ace_flags_carrier_white;
	class FST_Flags_Carrier_Banshee: ace_flags_carrier_white
	{
		displayName="[41st] Banshee Carryable Flag";
		editorPreview="\z\ace\addons\flags\data\editorpreviews\ace_flags_carrier_black.jpg";
		class EventHandlers
		{
			init="(_this select 0) setFlagTexture '41st_Flags\Data\FST_Flag_Banshee_Carrier_co.paa';";
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		class ACE_Actions
		{
			class ace_flags_pickup
			{
				displayName="$STR_ace_flags_Pickup";
				icon="\z\ace\addons\flags\data\icons\place\white_pickup_icon.paa";
				position="[0, -0.45, 0.75]";
				distance=2;
				condition="(typeOf _target) in ace_flags_carrierItemMapping";
				statement="[_player, (ace_flags_carrierItemMapping get (typeOf _target)), _target] call ace_flags_fnc_pickupFlag";
				modifierFunction="call ace_flags_fnc_modifyPickupAction";
				exceptions[]=
				{
					"isNotSwimming",
					"isNotOnLadder"
				};
			};
		};
	};
};
class CfgWeapons
{
	class ace_flags_white;
	class FST_Flags_Placeable_Banshee: ace_flags_white
	{
		displayName="[41st] Banshee Placeable Flag";
		picture="\z\ace\addons\flags\data\pictures\red_item.paa";
		ace_flags_texture="41st_Flags\Data\FST_Flag_Banshee_Placeable_co.paa";
		ace_flags_carrier="FST_Flags_Carrier_Banshee";
		ace_flags_actionIconPlace="\z\ace\addons\flags\data\icons\place\red_place_icon.paa";
		ace_flags_actionIconCarry="\z\ace\addons\flags\data\icons\carry\red_carry_icon.paa";
	};
};
