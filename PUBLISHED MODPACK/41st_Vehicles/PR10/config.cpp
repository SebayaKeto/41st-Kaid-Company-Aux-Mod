class CfgPatches
{
	class FST_PR10
	{
		author="Daara";
		requiredaddons[]=
		{
			"OPTRE_Vehicles"
		};
		requiredversion=1;
		units[]=
		{
			
			"FST_PR10_APC_Woodland",
			"FST_PR10_APC_Midnight",
			"FST_PR10_APC_Urban",
			"FST_PR10_APC_Desert"
		};
		addonRootClass="OPTRE_Vehicles";
		weapons[]={};
	};
};

class CfgVehicles
{
	
	class LandVehicle;
	class Car: LandVehicle
	{
		class NewTurret;
		class ACE_SelfActions;
	};
	class Car_F: Car
	{
		class AnimationSources
		{
			class HitLFWheel;
			class HitRFWheel;
			class HitLBWheel;
			class HitRBWheel;
			class HitLF2Wheel;
			class HitRF2Wheel;
			class HitLMWheel;
			class HitRMWheel;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
			class Gatling;
			class Gatling_flash;
		};
		TFAR_hasIntercom=1;
		class ACE_SelfActions: ACE_SelfActions
		{
			class TFAR_IntercomChannel
			{
				displayName="$STR_tfar_core_Intercom_ACESelfAction_Name";
				condition="true";
				statement="";
				icon="";
				class TFAR_IntercomChannel_disabled
				{
					displayName="Disabled";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 0";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],0,true];";
				};
				class TFAR_IntercomChannel_1
				{
					displayName="$STR_tfar_core_Intercom_ACESelfAction_Channel1";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != -1";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-1,true];";
				};
				class TFAR_IntercomChannel_2
				{
					displayName="$STR_tfar_core_Intercom_ACESelfAction_Channel2";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 1";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],1,true];";
				};
				class TFAR_IntercomChannel_Misc_1
				{
					displayName="Misc channel 1";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 2";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],2,true];";
				};
				class TFAR_IntercomChannel_Misc_2
				{
					displayName="Misc channel 2";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 3";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],3,true];";
				};
				class TFAR_IntercomChannel_Misc_3
				{
					displayName="Misc channel 3";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 4";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],4,true];";
				};
			};
		};
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewOptics;
			};
		};
		class HitPoints
		{
			class HitLFWheel;
			class HitLBWheel;
			class HitRFWheel;
			class HitRBWheel;
			class HitLF2Wheel;
			class HitRF2Wheel;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
			class HitFuel;
			class HitEngine;
			class HitBody;
		};
		class EventHandlers;
	};
	class OPTRE_M12_FAV_APC;
    class FST_PR10_APC_Woodland: OPTRE_M12_FAV_APC
    {
        scope = 2;
        scopecurator = 2;
        side = 1;
		faction="FST_Faction";
		ace_cargo_hasCargo   = 1;
        ace_cargo_space      = 1000;
        tf_range             = 5000;
        tf_isolatedAmount    = 0.4;
        tf_dialogUpdate      = "call TFAR_fnc_updateLRDialogToChannel;";
        tf_hasLRradio        = 1;
        displayname = "[41st] PR-10 'Puma' (Woodland)";
        editorSubcategory="FST_Ground_Vehicle";
        tas_canBlift=1;
		tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]";
        author = "Ruby";
        crew = "FST_Trooper_P2_DC15S";
        model="\OPTRE_Vehicles\Warthog\M12_MAAV_APC.p3d";
		crewCrashProtection=9.9999997e-005;
		damageResistance=0.02;
		armor=450;
		armorStructural=6.0;
        hiddenSelections[]=
		{
			"Camo1",
			"Camo2",
			"Camo3",
			"Camo4",
			"camo_details",
			"camo_interior",
			"camo_transport_details",
			"camo_net"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\PR10\Data\FST_M12_Front_Woodland.paa",
			"41st_Vehicles\PR10\Data\FST_M12_Under_Woodland.paa",
			"41st_Vehicles\PR10\Data\FST_M12_Cage_Woodland.paa",
			"41st_Vehicles\PR10\Data\FST_M12_Rear_Woodland.paa",
			"41st_Vehicles\PR10\Data\Main_Decals.paa",
			"41st_Vehicles\PR10\Data\FST_M12_Interior_Woodland.paa",
			"41st_Vehicles\PR10\Data\Ranger_Decals.paa",
			"\OPTRE_Vehicles\warthog\data\warthog_transport_net_ca.paa"
		};
	};
	class FST_PR10_APC_Desert: OPTRE_M12_FAV_APC
    {
        scope = 2;
        scopecurator = 2;
        side = 1;
		faction="FST_Faction";
        displayname = "[41st] PR-10 'Puma' (Desert)";
		ace_cargo_hasCargo   = 1;
        ace_cargo_space      = 1000;
        tf_range             = 5000;
        tf_isolatedAmount    = 0.4;
        tf_dialogUpdate      = "call TFAR_fnc_updateLRDialogToChannel;";
        tf_hasLRradio        = 1;
        editorSubcategory="FST_Ground_Vehicle";
        tas_canBlift=1;
		tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]";
        author = "Ruby";
        crew = "FST_Trooper_P2_DC15S";
        model="\OPTRE_Vehicles\Warthog\M12_MAAV_APC.p3d";
		crewCrashProtection=9.9999997e-005;
		damageResistance=0.02;
		armor=450;
		armorStructural=6.0;
        hiddenSelections[]=
		{
			"Camo1",
			"Camo2",
			"Camo3",
			"Camo4",
			"camo_details",
			"camo_interior",
			"camo_transport_details",
			"camo_net"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\PR10\Data\FST_M12_Front_Desert.paa",
			"41st_Vehicles\PR10\Data\FST_M12_Under_Desert.paa",
			"41st_Vehicles\PR10\Data\FST_M12_Cage_Desert.paa",
			"41st_Vehicles\PR10\Data\FST_M12_Rear_Desert.paa",
			"41st_Vehicles\PR10\Data\Main_Decals.paa",
			"41st_Vehicles\PR10\Data\FST_M12_Interior_Desert.paa",
			"41st_Vehicles\PR10\Data\Ranger_Decals.paa",
			"\OPTRE_Vehicles\warthog\data\warthog_transport_net_ca.paa"
		};
	};
	class FST_PR10_APC_Midnight: OPTRE_M12_FAV_APC
    {
        scope = 2;
        scopecurator = 2;
        side = 1;
		faction="FST_Faction";
        displayname = "[41st] PR-10 'Puma' (Midnight)";
		ace_cargo_hasCargo   = 1;
        ace_cargo_space      = 1000;
        tf_range             = 5000;
        tf_isolatedAmount    = 0.4;
        tf_dialogUpdate      = "call TFAR_fnc_updateLRDialogToChannel;";
        tf_hasLRradio        = 1;
        editorSubcategory="FST_Ground_Vehicle";
        tas_canBlift=1;
		tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]";
        author = "Ruby";
        crew = "FST_Trooper_P2_DC15S";
        model="\OPTRE_Vehicles\Warthog\M12_MAAV_APC.p3d";
		crewCrashProtection=9.9999997e-005;
		damageResistance=0.02;
		armor=450;
		armorStructural=6.0;
        hiddenSelections[]=
		{
			"Camo1",
			"Camo2",
			"Camo3",
			"Camo4",
			"camo_details",
			"camo_interior",
			"camo_transport_details",
			"camo_net"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\PR10\Data\FST_M12_Front_Midnight.paa",
			"41st_Vehicles\PR10\Data\FST_M12_Under_Midnight.paa",
			"41st_Vehicles\PR10\Data\FST_M12_Cage_Midnight.paa",
			"41st_Vehicles\PR10\Data\FST_M12_Rear_Midnight.paa",
			"41st_Vehicles\PR10\Data\Main_Decals.paa",
			"41st_Vehicles\PR10\Data\FST_M12_Interior_Midnight.paa",
			"41st_Vehicles\PR10\Data\Ranger_Decals.paa",
			"\OPTRE_Vehicles\warthog\data\warthog_transport_net_ca.paa"
		};
	};
	class FST_PR10_APC_Urban: OPTRE_M12_FAV_APC
    {
        scope = 2;
        scopecurator = 2;
        side = 1;
		faction="FST_Faction";
        displayname = "[41st] PR-10 'Puma' (Urban)";
		ace_cargo_hasCargo   = 1;
        ace_cargo_space      = 1000;
        tf_range             = 5000;
        tf_isolatedAmount    = 0.4;
        tf_dialogUpdate      = "call TFAR_fnc_updateLRDialogToChannel;";
		tf_hasLRradio        = 1;
        editorSubcategory="FST_Ground_Vehicle";
        tas_canBlift=1;
		tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]";
        author = "Ruby";
        crew = "FST_Trooper_P2_DC15S";
        model="\OPTRE_Vehicles\Warthog\M12_MAAV_APC.p3d";
		crewCrashProtection=9.9999997e-005;
		damageResistance=0.02;
		armor=450;
		armorStructural=6.0;
        hiddenSelections[]=
		{
			"Camo1",
			"Camo2",
			"Camo3",
			"Camo4",
			"camo_details",
			"camo_interior",
			"camo_transport_details",
			"camo_net"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\PR10\Data\FST_M12_Front_Urban.paa",
			"41st_Vehicles\PR10\Data\FST_M12_Under_Urban.paa",
			"41st_Vehicles\PR10\Data\FST_M12_Cage_Urban.paa",
			"41st_Vehicles\PR10\Data\FST_M12_Rear_Urban.paa",
			"41st_Vehicles\PR10\Data\Main_Decals.paa",
			"41st_Vehicles\PR10\Data\FST_M12_Interior_Urban.paa",
			"41st_Vehicles\PR10\Data\Ranger_Decals.paa",
			"\OPTRE_Vehicles\warthog\data\warthog_transport_net_ca.paa"
		};
	};
};



