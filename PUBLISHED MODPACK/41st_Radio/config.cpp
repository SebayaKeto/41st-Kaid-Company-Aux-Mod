class CfgPatches
{
	class FST_radios
	{
		author="MrClock";
		name="$STR_JLTS_names_PatchesTGWRadios";
		requiredAddons[]=
		{
			"A3_data_f",
			"A3_weapons_f"
		};
		units[]={};
		weapons[]=
		{
			"FST_clone_comlink",
		};
	};
};
class CfgFontFamilies
{
	class JLTS_republic
	{
		fonts[]=
		{
			"\MRC\JLTS\radios\fonts\republic\republic6",
			"\MRC\JLTS\radios\fonts\republic\republic7",
			"\MRC\JLTS\radios\fonts\republic\republic8",
			"\MRC\JLTS\radios\fonts\republic\republic9",
			"\MRC\JLTS\radios\fonts\republic\republic10",
			"\MRC\JLTS\radios\fonts\republic\republic11",
			"\MRC\JLTS\radios\fonts\republic\republic12",
			"\MRC\JLTS\radios\fonts\republic\republic13",
			"\MRC\JLTS\radios\fonts\republic\republic14",
			"\MRC\JLTS\radios\fonts\republic\republic15",
			"\MRC\JLTS\radios\fonts\republic\republic16",
			"\MRC\JLTS\radios\fonts\republic\republic17",
			"\MRC\JLTS\radios\fonts\republic\republic18",
			"\MRC\JLTS\radios\fonts\republic\republic19",
			"\MRC\JLTS\radios\fonts\republic\republic20",
			"\MRC\JLTS\radios\fonts\republic\republic21",
			"\MRC\JLTS\radios\fonts\republic\republic22",
			"\MRC\JLTS\radios\fonts\republic\republic23",
			"\MRC\JLTS\radios\fonts\republic\republic24",
			"\MRC\JLTS\radios\fonts\republic\republic25",
			"\MRC\JLTS\radios\fonts\republic\republic26",
			"\MRC\JLTS\radios\fonts\republic\republic27",
			"\MRC\JLTS\radios\fonts\republic\republic28",
			"\MRC\JLTS\radios\fonts\republic\republic29",
			"\MRC\JLTS\radios\fonts\republic\republic30",
			"\MRC\JLTS\radios\fonts\republic\republic31",
			"\MRC\JLTS\radios\fonts\republic\republic34",
			"\MRC\JLTS\radios\fonts\republic\republic35",
			"\MRC\JLTS\radios\fonts\republic\republic37",
			"\MRC\JLTS\radios\fonts\republic\republic46"
		};
		spaceWidth=0.60000002;
		spacing=0.15000001;
	};
	class JLTS_aurebesh
	{
		fonts[]=
		{
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh6",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh7",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh8",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh9",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh10",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh11",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh12",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh13",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh14",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh15",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh16",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh17",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh18",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh19",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh20",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh21",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh22",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh23",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh24",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh25",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh26",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh27",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh28",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh29",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh30",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh31",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh34",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh35",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh37",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh46"
		};
		spaceWidth=0.60000002;
		spacing=0.15000001;
	};
};
class CfgWeapons
{
	class ItemRadio;
	class FST_clone_comlink: ItemRadio
	{
		author="MrClock";
		displayName="[41st] CWP-8 Clone Comlink";
		descriptionShort="$STR_JLTS_descs_RadioCWP8";
		scope=2;
		scopeArsenal=2;
		scopeCurator=2;
		picture="\MRC\JLTS\radios\data\ui\clone_comlink_item_ui_ca.paa";
		model="\A3\weapons_F\ammo\mag_univ.p3d";
		tf_prototype=1;
		tf_range=1000;
		tf_dialog="JLTS_clone_comlink_dialog";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialogUpdate="call TFAR_fnc_updateSWDialogToChannel;";
		tf_subtype="digital";
		tf_parent="FST_clone_comlink";
		tf_additional_channel=1;
	};
	class FST_clone_comlink_1: FST_clone_comlink
	{
		displayName="CWP-8 1";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_2: FST_clone_comlink
	{
		displayName="CWP-8 2";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_3: FST_clone_comlink
	{
		displayName="CWP-8 3";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_4: FST_clone_comlink
	{
		displayName="CWP-8 4";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_5: FST_clone_comlink
	{
		displayName="CWP-8 5";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_6: FST_clone_comlink
	{
		displayName="CWP-8 6";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_7: FST_clone_comlink
	{
		displayName="CWP-8 7";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_8: FST_clone_comlink
	{
		displayName="CWP-8 8";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_9: FST_clone_comlink
	{
		displayName="CWP-8 9";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_10: FST_clone_comlink
	{
		displayName="CWP-8 10";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_11: FST_clone_comlink
	{
		displayName="CWP-8 11";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_12: FST_clone_comlink
	{
		displayName="CWP-8 12";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_13: FST_clone_comlink
	{
		displayName="CWP-8 13";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_14: FST_clone_comlink
	{
		displayName="CWP-8 14";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_15: FST_clone_comlink
	{
		displayName="CWP-8 15";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_16: FST_clone_comlink
	{
		displayName="CWP-8 16";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_17: FST_clone_comlink
	{
		displayName="CWP-8 17";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_18: FST_clone_comlink
	{
		displayName="CWP-8 18";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_19: FST_clone_comlink
	{
		displayName="CWP-8 19";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_20: FST_clone_comlink
	{
		displayName="CWP-8 20";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_21: FST_clone_comlink
	{
		displayName="CWP-8 21";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_22: FST_clone_comlink
	{
		displayName="CWP-8 22";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_23: FST_clone_comlink
	{
		displayName="CWP-8 23";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_24: FST_clone_comlink
	{
		displayName="CWP-8 24";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_25: FST_clone_comlink
	{
		displayName="CWP-8 25";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_26: FST_clone_comlink
	{
		displayName="CWP-8 26";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_27: FST_clone_comlink
	{
		displayName="CWP-8 27";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_28: FST_clone_comlink
	{
		displayName="CWP-8 28";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_29: FST_clone_comlink
	{
		displayName="CWP-8 29";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_30: FST_clone_comlink
	{
		displayName="CWP-8 30";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_31: FST_clone_comlink
	{
		displayName="CWP-8 31";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_32: FST_clone_comlink
	{
		displayName="CWP-8 32";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_33: FST_clone_comlink
	{
		displayName="CWP-8 33";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_34: FST_clone_comlink
	{
		displayName="CWP-8 34";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_35: FST_clone_comlink
	{
		displayName="CWP-8 35";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_36: FST_clone_comlink
	{
		displayName="CWP-8 36";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_37: FST_clone_comlink
	{
		displayName="CWP-8 37";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_38: FST_clone_comlink
	{
		displayName="CWP-8 38";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_39: FST_clone_comlink
	{
		displayName="CWP-8 39";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_40: FST_clone_comlink
	{
		displayName="CWP-8 40";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_41: FST_clone_comlink
	{
		displayName="CWP-8 41";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_42: FST_clone_comlink
	{
		displayName="CWP-8 42";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_43: FST_clone_comlink
	{
		displayName="CWP-8 43";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_44: FST_clone_comlink
	{
		displayName="CWP-8 44";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_45: FST_clone_comlink
	{
		displayName="CWP-8 45";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_46: FST_clone_comlink
	{
		displayName="CWP-8 46";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_47: FST_clone_comlink
	{
		displayName="CWP-8 47";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_48: FST_clone_comlink
	{
		displayName="CWP-8 48";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_49: FST_clone_comlink
	{
		displayName="CWP-8 49";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_50: FST_clone_comlink
	{
		displayName="CWP-8 50";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_51: FST_clone_comlink
	{
		displayName="CWP-8 51";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_52: FST_clone_comlink
	{
		displayName="CWP-8 52";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_53: FST_clone_comlink
	{
		displayName="CWP-8 53";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_54: FST_clone_comlink
	{
		displayName="CWP-8 54";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_55: FST_clone_comlink
	{
		displayName="CWP-8 55";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_56: FST_clone_comlink
	{
		displayName="CWP-8 56";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_57: FST_clone_comlink
	{
		displayName="CWP-8 57";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_58: FST_clone_comlink
	{
		displayName="CWP-8 58";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_59: FST_clone_comlink
	{
		displayName="CWP-8 59";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_60: FST_clone_comlink
	{
		displayName="CWP-8 60";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_61: FST_clone_comlink
	{
		displayName="CWP-8 61";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_62: FST_clone_comlink
	{
		displayName="CWP-8 62";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_63: FST_clone_comlink
	{
		displayName="CWP-8 63";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_64: FST_clone_comlink
	{
		displayName="CWP-8 64";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_65: FST_clone_comlink
	{
		displayName="CWP-8 65";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_66: FST_clone_comlink
	{
		displayName="CWP-8 66";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_67: FST_clone_comlink
	{
		displayName="CWP-8 67";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_68: FST_clone_comlink
	{
		displayName="CWP-8 68";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_69: FST_clone_comlink
	{
		displayName="CWP-8 69";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_70: FST_clone_comlink
	{
		displayName="CWP-8 70";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_71: FST_clone_comlink
	{
		displayName="CWP-8 71";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_72: FST_clone_comlink
	{
		displayName="CWP-8 72";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_73: FST_clone_comlink
	{
		displayName="CWP-8 73";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_74: FST_clone_comlink
	{
		displayName="CWP-8 74";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_75: FST_clone_comlink
	{
		displayName="CWP-8 75";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_76: FST_clone_comlink
	{
		displayName="CWP-8 76";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_77: FST_clone_comlink
	{
		displayName="CWP-8 77";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_78: FST_clone_comlink
	{
		displayName="CWP-8 78";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_79: FST_clone_comlink
	{
		displayName="CWP-8 79";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_80: FST_clone_comlink
	{
		displayName="CWP-8 80";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_81: FST_clone_comlink
	{
		displayName="CWP-8 81";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_82: FST_clone_comlink
	{
		displayName="CWP-8 82";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_83: FST_clone_comlink
	{
		displayName="CWP-8 83";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_84: FST_clone_comlink
	{
		displayName="CWP-8 84";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_85: FST_clone_comlink
	{
		displayName="CWP-8 85";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_86: FST_clone_comlink
	{
		displayName="CWP-8 86";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_87: FST_clone_comlink
	{
		displayName="CWP-8 87";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_88: FST_clone_comlink
	{
		displayName="CWP-8 88";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_89: FST_clone_comlink
	{
		displayName="CWP-8 89";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_90: FST_clone_comlink
	{
		displayName="CWP-8 90";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_91: FST_clone_comlink
	{
		displayName="CWP-8 91";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_92: FST_clone_comlink
	{
		displayName="CWP-8 92";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_93: FST_clone_comlink
	{
		displayName="CWP-8 93";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_94: FST_clone_comlink
	{
		displayName="CWP-8 94";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_95: FST_clone_comlink
	{
		displayName="CWP-8 95";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_96: FST_clone_comlink
	{
		displayName="CWP-8 96";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_97: FST_clone_comlink
	{
		displayName="CWP-8 97";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_98: FST_clone_comlink
	{
		displayName="CWP-8 98";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_99: FST_clone_comlink
	{
		displayName="CWP-8 99";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_100: FST_clone_comlink
	{
		displayName="CWP-8 100";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_101: FST_clone_comlink
	{
		displayName="CWP-8 101";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_102: FST_clone_comlink
	{
		displayName="CWP-8 102";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_103: FST_clone_comlink
	{
		displayName="CWP-8 103";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_104: FST_clone_comlink
	{
		displayName="CWP-8 104";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_105: FST_clone_comlink
	{
		displayName="CWP-8 105";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_106: FST_clone_comlink
	{
		displayName="CWP-8 106";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_107: FST_clone_comlink
	{
		displayName="CWP-8 107";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_108: FST_clone_comlink
	{
		displayName="CWP-8 108";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_109: FST_clone_comlink
	{
		displayName="CWP-8 109";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_110: FST_clone_comlink
	{
		displayName="CWP-8 110";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_111: FST_clone_comlink
	{
		displayName="CWP-8 111";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_112: FST_clone_comlink
	{
		displayName="CWP-8 112";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_113: FST_clone_comlink
	{
		displayName="CWP-8 113";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_114: FST_clone_comlink
	{
		displayName="CWP-8 114";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_115: FST_clone_comlink
	{
		displayName="CWP-8 115";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_116: FST_clone_comlink
	{
		displayName="CWP-8 116";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_117: FST_clone_comlink
	{
		displayName="CWP-8 117";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_118: FST_clone_comlink
	{
		displayName="CWP-8 118";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_119: FST_clone_comlink
	{
		displayName="CWP-8 119";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_120: FST_clone_comlink
	{
		displayName="CWP-8 120";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_121: FST_clone_comlink
	{
		displayName="CWP-8 121";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_122: FST_clone_comlink
	{
		displayName="CWP-8 122";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_123: FST_clone_comlink
	{
		displayName="CWP-8 123";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_124: FST_clone_comlink
	{
		displayName="CWP-8 124";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_125: FST_clone_comlink
	{
		displayName="CWP-8 125";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_126: FST_clone_comlink
	{
		displayName="CWP-8 126";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_127: FST_clone_comlink
	{
		displayName="CWP-8 127";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_128: FST_clone_comlink
	{
		displayName="CWP-8 128";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_129: FST_clone_comlink
	{
		displayName="CWP-8 129";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_130: FST_clone_comlink
	{
		displayName="CWP-8 130";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_131: FST_clone_comlink
	{
		displayName="CWP-8 131";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_132: FST_clone_comlink
	{
		displayName="CWP-8 132";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_133: FST_clone_comlink
	{
		displayName="CWP-8 133";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_134: FST_clone_comlink
	{
		displayName="CWP-8 134";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_135: FST_clone_comlink
	{
		displayName="CWP-8 135";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_136: FST_clone_comlink
	{
		displayName="CWP-8 136";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_137: FST_clone_comlink
	{
		displayName="CWP-8 137";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_138: FST_clone_comlink
	{
		displayName="CWP-8 138";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_139: FST_clone_comlink
	{
		displayName="CWP-8 139";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_140: FST_clone_comlink
	{
		displayName="CWP-8 140";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_141: FST_clone_comlink
	{
		displayName="CWP-8 141";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_142: FST_clone_comlink
	{
		displayName="CWP-8 142";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_143: FST_clone_comlink
	{
		displayName="CWP-8 143";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_144: FST_clone_comlink
	{
		displayName="CWP-8 144";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_145: FST_clone_comlink
	{
		displayName="CWP-8 145";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_146: FST_clone_comlink
	{
		displayName="CWP-8 146";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_147: FST_clone_comlink
	{
		displayName="CWP-8 147";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_148: FST_clone_comlink
	{
		displayName="CWP-8 148";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_149: FST_clone_comlink
	{
		displayName="CWP-8 149";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_150: FST_clone_comlink
	{
		displayName="CWP-8 150";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_151: FST_clone_comlink
	{
		displayName="CWP-8 151";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_152: FST_clone_comlink
	{
		displayName="CWP-8 152";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_153: FST_clone_comlink
	{
		displayName="CWP-8 153";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_154: FST_clone_comlink
	{
		displayName="CWP-8 154";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_155: FST_clone_comlink
	{
		displayName="CWP-8 155";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_156: FST_clone_comlink
	{
		displayName="CWP-8 156";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_157: FST_clone_comlink
	{
		displayName="CWP-8 157";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_158: FST_clone_comlink
	{
		displayName="CWP-8 158";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_159: FST_clone_comlink
	{
		displayName="CWP-8 159";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_160: FST_clone_comlink
	{
		displayName="CWP-8 160";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_161: FST_clone_comlink
	{
		displayName="CWP-8 161";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_162: FST_clone_comlink
	{
		displayName="CWP-8 162";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_163: FST_clone_comlink
	{
		displayName="CWP-8 163";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_164: FST_clone_comlink
	{
		displayName="CWP-8 164";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_165: FST_clone_comlink
	{
		displayName="CWP-8 165";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_166: FST_clone_comlink
	{
		displayName="CWP-8 166";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_167: FST_clone_comlink
	{
		displayName="CWP-8 167";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_168: FST_clone_comlink
	{
		displayName="CWP-8 168";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_169: FST_clone_comlink
	{
		displayName="CWP-8 169";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_170: FST_clone_comlink
	{
		displayName="CWP-8 170";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_171: FST_clone_comlink
	{
		displayName="CWP-8 171";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_172: FST_clone_comlink
	{
		displayName="CWP-8 172";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_173: FST_clone_comlink
	{
		displayName="CWP-8 173";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_174: FST_clone_comlink
	{
		displayName="CWP-8 174";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_175: FST_clone_comlink
	{
		displayName="CWP-8 175";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_176: FST_clone_comlink
	{
		displayName="CWP-8 176";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_177: FST_clone_comlink
	{
		displayName="CWP-8 177";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_178: FST_clone_comlink
	{
		displayName="CWP-8 178";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_179: FST_clone_comlink
	{
		displayName="CWP-8 179";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_180: FST_clone_comlink
	{
		displayName="CWP-8 180";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_181: FST_clone_comlink
	{
		displayName="CWP-8 181";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_182: FST_clone_comlink
	{
		displayName="CWP-8 182";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_183: FST_clone_comlink
	{
		displayName="CWP-8 183";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_184: FST_clone_comlink
	{
		displayName="CWP-8 184";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_185: FST_clone_comlink
	{
		displayName="CWP-8 185";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_186: FST_clone_comlink
	{
		displayName="CWP-8 186";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_187: FST_clone_comlink
	{
		displayName="CWP-8 187";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_188: FST_clone_comlink
	{
		displayName="CWP-8 188";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_189: FST_clone_comlink
	{
		displayName="CWP-8 189";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_190: FST_clone_comlink
	{
		displayName="CWP-8 190";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_191: FST_clone_comlink
	{
		displayName="CWP-8 191";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_192: FST_clone_comlink
	{
		displayName="CWP-8 192";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_193: FST_clone_comlink
	{
		displayName="CWP-8 193";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_194: FST_clone_comlink
	{
		displayName="CWP-8 194";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_195: FST_clone_comlink
	{
		displayName="CWP-8 195";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_196: FST_clone_comlink
	{
		displayName="CWP-8 196";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_197: FST_clone_comlink
	{
		displayName="CWP-8 197";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_198: FST_clone_comlink
	{
		displayName="CWP-8 198";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_199: FST_clone_comlink
	{
		displayName="CWP-8 199";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_200: FST_clone_comlink
	{
		displayName="CWP-8 200";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_201: FST_clone_comlink
	{
		displayName="CWP-8 201";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_202: FST_clone_comlink
	{
		displayName="CWP-8 202";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_203: FST_clone_comlink
	{
		displayName="CWP-8 203";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_204: FST_clone_comlink
	{
		displayName="CWP-8 204";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_205: FST_clone_comlink
	{
		displayName="CWP-8 205";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_206: FST_clone_comlink
	{
		displayName="CWP-8 206";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_207: FST_clone_comlink
	{
		displayName="CWP-8 207";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_208: FST_clone_comlink
	{
		displayName="CWP-8 208";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_209: FST_clone_comlink
	{
		displayName="CWP-8 209";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_210: FST_clone_comlink
	{
		displayName="CWP-8 210";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_211: FST_clone_comlink
	{
		displayName="CWP-8 211";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_212: FST_clone_comlink
	{
		displayName="CWP-8 212";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_213: FST_clone_comlink
	{
		displayName="CWP-8 213";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_214: FST_clone_comlink
	{
		displayName="CWP-8 214";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_215: FST_clone_comlink
	{
		displayName="CWP-8 215";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_216: FST_clone_comlink
	{
		displayName="CWP-8 216";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_217: FST_clone_comlink
	{
		displayName="CWP-8 217";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_218: FST_clone_comlink
	{
		displayName="CWP-8 218";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_219: FST_clone_comlink
	{
		displayName="CWP-8 219";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_220: FST_clone_comlink
	{
		displayName="CWP-8 220";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_221: FST_clone_comlink
	{
		displayName="CWP-8 221";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_222: FST_clone_comlink
	{
		displayName="CWP-8 222";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_223: FST_clone_comlink
	{
		displayName="CWP-8 223";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_224: FST_clone_comlink
	{
		displayName="CWP-8 224";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_225: FST_clone_comlink
	{
		displayName="CWP-8 225";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_226: FST_clone_comlink
	{
		displayName="CWP-8 226";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_227: FST_clone_comlink
	{
		displayName="CWP-8 227";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_228: FST_clone_comlink
	{
		displayName="CWP-8 228";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_229: FST_clone_comlink
	{
		displayName="CWP-8 229";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_230: FST_clone_comlink
	{
		displayName="CWP-8 230";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_231: FST_clone_comlink
	{
		displayName="CWP-8 231";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_232: FST_clone_comlink
	{
		displayName="CWP-8 232";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_233: FST_clone_comlink
	{
		displayName="CWP-8 233";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_234: FST_clone_comlink
	{
		displayName="CWP-8 234";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_235: FST_clone_comlink
	{
		displayName="CWP-8 235";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_236: FST_clone_comlink
	{
		displayName="CWP-8 236";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_237: FST_clone_comlink
	{
		displayName="CWP-8 237";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_238: FST_clone_comlink
	{
		displayName="CWP-8 238";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_239: FST_clone_comlink
	{
		displayName="CWP-8 239";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_240: FST_clone_comlink
	{
		displayName="CWP-8 240";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_241: FST_clone_comlink
	{
		displayName="CWP-8 241";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_242: FST_clone_comlink
	{
		displayName="CWP-8 242";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_243: FST_clone_comlink
	{
		displayName="CWP-8 243";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_244: FST_clone_comlink
	{
		displayName="CWP-8 244";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_245: FST_clone_comlink
	{
		displayName="CWP-8 245";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_246: FST_clone_comlink
	{
		displayName="CWP-8 246";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_247: FST_clone_comlink
	{
		displayName="CWP-8 247";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_248: FST_clone_comlink
	{
		displayName="CWP-8 248";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_249: FST_clone_comlink
	{
		displayName="CWP-8 249";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_250: FST_clone_comlink
	{
		displayName="CWP-8 250";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_251: FST_clone_comlink
	{
		displayName="CWP-8 251";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_252: FST_clone_comlink
	{
		displayName="CWP-8 252";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_253: FST_clone_comlink
	{
		displayName="CWP-8 253";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_254: FST_clone_comlink
	{
		displayName="CWP-8 254";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_255: FST_clone_comlink
	{
		displayName="CWP-8 255";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_256: FST_clone_comlink
	{
		displayName="CWP-8 256";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_257: FST_clone_comlink
	{
		displayName="CWP-8 257";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_258: FST_clone_comlink
	{
		displayName="CWP-8 258";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_259: FST_clone_comlink
	{
		displayName="CWP-8 259";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_260: FST_clone_comlink
	{
		displayName="CWP-8 260";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_261: FST_clone_comlink
	{
		displayName="CWP-8 261";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_262: FST_clone_comlink
	{
		displayName="CWP-8 262";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_263: FST_clone_comlink
	{
		displayName="CWP-8 263";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_264: FST_clone_comlink
	{
		displayName="CWP-8 264";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_265: FST_clone_comlink
	{
		displayName="CWP-8 265";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_266: FST_clone_comlink
	{
		displayName="CWP-8 266";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_267: FST_clone_comlink
	{
		displayName="CWP-8 267";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_268: FST_clone_comlink
	{
		displayName="CWP-8 268";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_269: FST_clone_comlink
	{
		displayName="CWP-8 269";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_270: FST_clone_comlink
	{
		displayName="CWP-8 270";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_271: FST_clone_comlink
	{
		displayName="CWP-8 271";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_272: FST_clone_comlink
	{
		displayName="CWP-8 272";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_273: FST_clone_comlink
	{
		displayName="CWP-8 273";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_274: FST_clone_comlink
	{
		displayName="CWP-8 274";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_275: FST_clone_comlink
	{
		displayName="CWP-8 275";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_276: FST_clone_comlink
	{
		displayName="CWP-8 276";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_277: FST_clone_comlink
	{
		displayName="CWP-8 277";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_278: FST_clone_comlink
	{
		displayName="CWP-8 278";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_279: FST_clone_comlink
	{
		displayName="CWP-8 279";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_280: FST_clone_comlink
	{
		displayName="CWP-8 280";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_281: FST_clone_comlink
	{
		displayName="CWP-8 281";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_282: FST_clone_comlink
	{
		displayName="CWP-8 282";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_283: FST_clone_comlink
	{
		displayName="CWP-8 283";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_284: FST_clone_comlink
	{
		displayName="CWP-8 284";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_285: FST_clone_comlink
	{
		displayName="CWP-8 285";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_286: FST_clone_comlink
	{
		displayName="CWP-8 286";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_287: FST_clone_comlink
	{
		displayName="CWP-8 287";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_288: FST_clone_comlink
	{
		displayName="CWP-8 288";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_289: FST_clone_comlink
	{
		displayName="CWP-8 289";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_290: FST_clone_comlink
	{
		displayName="CWP-8 290";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_291: FST_clone_comlink
	{
		displayName="CWP-8 291";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_292: FST_clone_comlink
	{
		displayName="CWP-8 292";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_293: FST_clone_comlink
	{
		displayName="CWP-8 293";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_294: FST_clone_comlink
	{
		displayName="CWP-8 294";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_295: FST_clone_comlink
	{
		displayName="CWP-8 295";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_296: FST_clone_comlink
	{
		displayName="CWP-8 296";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_297: FST_clone_comlink
	{
		displayName="CWP-8 297";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_298: FST_clone_comlink
	{
		displayName="CWP-8 298";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_299: FST_clone_comlink
	{
		displayName="CWP-8 299";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_300: FST_clone_comlink
	{
		displayName="CWP-8 300";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_301: FST_clone_comlink
	{
		displayName="CWP-8 301";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_302: FST_clone_comlink
	{
		displayName="CWP-8 302";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_303: FST_clone_comlink
	{
		displayName="CWP-8 303";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_304: FST_clone_comlink
	{
		displayName="CWP-8 304";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_305: FST_clone_comlink
	{
		displayName="CWP-8 305";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_306: FST_clone_comlink
	{
		displayName="CWP-8 306";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_307: FST_clone_comlink
	{
		displayName="CWP-8 307";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_308: FST_clone_comlink
	{
		displayName="CWP-8 308";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_309: FST_clone_comlink
	{
		displayName="CWP-8 309";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_310: FST_clone_comlink
	{
		displayName="CWP-8 310";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_311: FST_clone_comlink
	{
		displayName="CWP-8 311";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_312: FST_clone_comlink
	{
		displayName="CWP-8 312";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_313: FST_clone_comlink
	{
		displayName="CWP-8 313";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_314: FST_clone_comlink
	{
		displayName="CWP-8 314";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_315: FST_clone_comlink
	{
		displayName="CWP-8 315";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_316: FST_clone_comlink
	{
		displayName="CWP-8 316";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_317: FST_clone_comlink
	{
		displayName="CWP-8 317";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_318: FST_clone_comlink
	{
		displayName="CWP-8 318";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_319: FST_clone_comlink
	{
		displayName="CWP-8 319";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_320: FST_clone_comlink
	{
		displayName="CWP-8 320";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_321: FST_clone_comlink
	{
		displayName="CWP-8 321";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_322: FST_clone_comlink
	{
		displayName="CWP-8 322";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_323: FST_clone_comlink
	{
		displayName="CWP-8 323";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_324: FST_clone_comlink
	{
		displayName="CWP-8 324";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_325: FST_clone_comlink
	{
		displayName="CWP-8 325";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_326: FST_clone_comlink
	{
		displayName="CWP-8 326";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_327: FST_clone_comlink
	{
		displayName="CWP-8 327";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_328: FST_clone_comlink
	{
		displayName="CWP-8 328";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_329: FST_clone_comlink
	{
		displayName="CWP-8 329";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_330: FST_clone_comlink
	{
		displayName="CWP-8 330";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_331: FST_clone_comlink
	{
		displayName="CWP-8 331";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_332: FST_clone_comlink
	{
		displayName="CWP-8 332";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_333: FST_clone_comlink
	{
		displayName="CWP-8 333";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_334: FST_clone_comlink
	{
		displayName="CWP-8 334";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_335: FST_clone_comlink
	{
		displayName="CWP-8 335";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_336: FST_clone_comlink
	{
		displayName="CWP-8 336";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_337: FST_clone_comlink
	{
		displayName="CWP-8 337";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_338: FST_clone_comlink
	{
		displayName="CWP-8 338";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_339: FST_clone_comlink
	{
		displayName="CWP-8 339";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_340: FST_clone_comlink
	{
		displayName="CWP-8 340";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_341: FST_clone_comlink
	{
		displayName="CWP-8 341";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_342: FST_clone_comlink
	{
		displayName="CWP-8 342";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_343: FST_clone_comlink
	{
		displayName="CWP-8 343";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_344: FST_clone_comlink
	{
		displayName="CWP-8 344";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_345: FST_clone_comlink
	{
		displayName="CWP-8 345";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_346: FST_clone_comlink
	{
		displayName="CWP-8 346";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_347: FST_clone_comlink
	{
		displayName="CWP-8 347";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_348: FST_clone_comlink
	{
		displayName="CWP-8 348";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_349: FST_clone_comlink
	{
		displayName="CWP-8 349";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_350: FST_clone_comlink
	{
		displayName="CWP-8 350";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_351: FST_clone_comlink
	{
		displayName="CWP-8 351";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_352: FST_clone_comlink
	{
		displayName="CWP-8 352";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_353: FST_clone_comlink
	{
		displayName="CWP-8 353";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_354: FST_clone_comlink
	{
		displayName="CWP-8 354";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_355: FST_clone_comlink
	{
		displayName="CWP-8 355";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_356: FST_clone_comlink
	{
		displayName="CWP-8 356";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_357: FST_clone_comlink
	{
		displayName="CWP-8 357";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_358: FST_clone_comlink
	{
		displayName="CWP-8 358";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_359: FST_clone_comlink
	{
		displayName="CWP-8 359";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_360: FST_clone_comlink
	{
		displayName="CWP-8 360";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_361: FST_clone_comlink
	{
		displayName="CWP-8 361";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_362: FST_clone_comlink
	{
		displayName="CWP-8 362";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_363: FST_clone_comlink
	{
		displayName="CWP-8 363";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_364: FST_clone_comlink
	{
		displayName="CWP-8 364";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_365: FST_clone_comlink
	{
		displayName="CWP-8 365";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_366: FST_clone_comlink
	{
		displayName="CWP-8 366";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_367: FST_clone_comlink
	{
		displayName="CWP-8 367";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_368: FST_clone_comlink
	{
		displayName="CWP-8 368";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_369: FST_clone_comlink
	{
		displayName="CWP-8 369";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_370: FST_clone_comlink
	{
		displayName="CWP-8 370";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_371: FST_clone_comlink
	{
		displayName="CWP-8 371";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_372: FST_clone_comlink
	{
		displayName="CWP-8 372";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_373: FST_clone_comlink
	{
		displayName="CWP-8 373";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_374: FST_clone_comlink
	{
		displayName="CWP-8 374";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_375: FST_clone_comlink
	{
		displayName="CWP-8 375";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_376: FST_clone_comlink
	{
		displayName="CWP-8 376";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_377: FST_clone_comlink
	{
		displayName="CWP-8 377";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_378: FST_clone_comlink
	{
		displayName="CWP-8 378";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_379: FST_clone_comlink
	{
		displayName="CWP-8 379";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_380: FST_clone_comlink
	{
		displayName="CWP-8 380";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_381: FST_clone_comlink
	{
		displayName="CWP-8 381";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_382: FST_clone_comlink
	{
		displayName="CWP-8 382";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_383: FST_clone_comlink
	{
		displayName="CWP-8 383";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_384: FST_clone_comlink
	{
		displayName="CWP-8 384";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_385: FST_clone_comlink
	{
		displayName="CWP-8 385";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_386: FST_clone_comlink
	{
		displayName="CWP-8 386";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_387: FST_clone_comlink
	{
		displayName="CWP-8 387";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_388: FST_clone_comlink
	{
		displayName="CWP-8 388";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_389: FST_clone_comlink
	{
		displayName="CWP-8 389";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_390: FST_clone_comlink
	{
		displayName="CWP-8 390";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_391: FST_clone_comlink
	{
		displayName="CWP-8 391";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_392: FST_clone_comlink
	{
		displayName="CWP-8 392";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_393: FST_clone_comlink
	{
		displayName="CWP-8 393";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_394: FST_clone_comlink
	{
		displayName="CWP-8 394";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_395: FST_clone_comlink
	{
		displayName="CWP-8 395";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_396: FST_clone_comlink
	{
		displayName="CWP-8 396";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_397: FST_clone_comlink
	{
		displayName="CWP-8 397";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_398: FST_clone_comlink
	{
		displayName="CWP-8 398";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_399: FST_clone_comlink
	{
		displayName="CWP-8 399";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_400: FST_clone_comlink
	{
		displayName="CWP-8 400";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_401: FST_clone_comlink
	{
		displayName="CWP-8 401";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_402: FST_clone_comlink
	{
		displayName="CWP-8 402";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_403: FST_clone_comlink
	{
		displayName="CWP-8 403";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_404: FST_clone_comlink
	{
		displayName="CWP-8 404";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_405: FST_clone_comlink
	{
		displayName="CWP-8 405";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_406: FST_clone_comlink
	{
		displayName="CWP-8 406";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_407: FST_clone_comlink
	{
		displayName="CWP-8 407";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_408: FST_clone_comlink
	{
		displayName="CWP-8 408";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_409: FST_clone_comlink
	{
		displayName="CWP-8 409";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_410: FST_clone_comlink
	{
		displayName="CWP-8 410";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_411: FST_clone_comlink
	{
		displayName="CWP-8 411";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_412: FST_clone_comlink
	{
		displayName="CWP-8 412";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_413: FST_clone_comlink
	{
		displayName="CWP-8 413";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_414: FST_clone_comlink
	{
		displayName="CWP-8 414";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_415: FST_clone_comlink
	{
		displayName="CWP-8 415";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_416: FST_clone_comlink
	{
		displayName="CWP-8 416";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_417: FST_clone_comlink
	{
		displayName="CWP-8 417";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_418: FST_clone_comlink
	{
		displayName="CWP-8 418";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_419: FST_clone_comlink
	{
		displayName="CWP-8 419";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_420: FST_clone_comlink
	{
		displayName="CWP-8 420";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_421: FST_clone_comlink
	{
		displayName="CWP-8 421";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_422: FST_clone_comlink
	{
		displayName="CWP-8 422";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_423: FST_clone_comlink
	{
		displayName="CWP-8 423";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_424: FST_clone_comlink
	{
		displayName="CWP-8 424";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_425: FST_clone_comlink
	{
		displayName="CWP-8 425";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_426: FST_clone_comlink
	{
		displayName="CWP-8 426";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_427: FST_clone_comlink
	{
		displayName="CWP-8 427";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_428: FST_clone_comlink
	{
		displayName="CWP-8 428";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_429: FST_clone_comlink
	{
		displayName="CWP-8 429";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_430: FST_clone_comlink
	{
		displayName="CWP-8 430";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_431: FST_clone_comlink
	{
		displayName="CWP-8 431";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_432: FST_clone_comlink
	{
		displayName="CWP-8 432";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_433: FST_clone_comlink
	{
		displayName="CWP-8 433";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_434: FST_clone_comlink
	{
		displayName="CWP-8 434";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_435: FST_clone_comlink
	{
		displayName="CWP-8 435";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_436: FST_clone_comlink
	{
		displayName="CWP-8 436";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_437: FST_clone_comlink
	{
		displayName="CWP-8 437";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_438: FST_clone_comlink
	{
		displayName="CWP-8 438";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_439: FST_clone_comlink
	{
		displayName="CWP-8 439";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_440: FST_clone_comlink
	{
		displayName="CWP-8 440";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_441: FST_clone_comlink
	{
		displayName="CWP-8 441";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_442: FST_clone_comlink
	{
		displayName="CWP-8 442";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_443: FST_clone_comlink
	{
		displayName="CWP-8 443";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_444: FST_clone_comlink
	{
		displayName="CWP-8 444";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_445: FST_clone_comlink
	{
		displayName="CWP-8 445";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_446: FST_clone_comlink
	{
		displayName="CWP-8 446";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_447: FST_clone_comlink
	{
		displayName="CWP-8 447";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_448: FST_clone_comlink
	{
		displayName="CWP-8 448";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_449: FST_clone_comlink
	{
		displayName="CWP-8 449";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_450: FST_clone_comlink
	{
		displayName="CWP-8 450";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_451: FST_clone_comlink
	{
		displayName="CWP-8 451";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_452: FST_clone_comlink
	{
		displayName="CWP-8 452";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_453: FST_clone_comlink
	{
		displayName="CWP-8 453";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_454: FST_clone_comlink
	{
		displayName="CWP-8 454";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_455: FST_clone_comlink
	{
		displayName="CWP-8 455";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_456: FST_clone_comlink
	{
		displayName="CWP-8 456";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_457: FST_clone_comlink
	{
		displayName="CWP-8 457";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_458: FST_clone_comlink
	{
		displayName="CWP-8 458";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_459: FST_clone_comlink
	{
		displayName="CWP-8 459";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_460: FST_clone_comlink
	{
		displayName="CWP-8 460";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_461: FST_clone_comlink
	{
		displayName="CWP-8 461";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_462: FST_clone_comlink
	{
		displayName="CWP-8 462";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_463: FST_clone_comlink
	{
		displayName="CWP-8 463";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_464: FST_clone_comlink
	{
		displayName="CWP-8 464";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_465: FST_clone_comlink
	{
		displayName="CWP-8 465";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_466: FST_clone_comlink
	{
		displayName="CWP-8 466";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_467: FST_clone_comlink
	{
		displayName="CWP-8 467";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_468: FST_clone_comlink
	{
		displayName="CWP-8 468";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_469: FST_clone_comlink
	{
		displayName="CWP-8 469";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_470: FST_clone_comlink
	{
		displayName="CWP-8 470";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_471: FST_clone_comlink
	{
		displayName="CWP-8 471";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_472: FST_clone_comlink
	{
		displayName="CWP-8 472";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_473: FST_clone_comlink
	{
		displayName="CWP-8 473";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_474: FST_clone_comlink
	{
		displayName="CWP-8 474";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_475: FST_clone_comlink
	{
		displayName="CWP-8 475";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_476: FST_clone_comlink
	{
		displayName="CWP-8 476";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_477: FST_clone_comlink
	{
		displayName="CWP-8 477";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_478: FST_clone_comlink
	{
		displayName="CWP-8 478";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_479: FST_clone_comlink
	{
		displayName="CWP-8 479";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_480: FST_clone_comlink
	{
		displayName="CWP-8 480";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_481: FST_clone_comlink
	{
		displayName="CWP-8 481";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_482: FST_clone_comlink
	{
		displayName="CWP-8 482";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_483: FST_clone_comlink
	{
		displayName="CWP-8 483";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_484: FST_clone_comlink
	{
		displayName="CWP-8 484";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_485: FST_clone_comlink
	{
		displayName="CWP-8 485";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_486: FST_clone_comlink
	{
		displayName="CWP-8 486";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_487: FST_clone_comlink
	{
		displayName="CWP-8 487";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_488: FST_clone_comlink
	{
		displayName="CWP-8 488";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_489: FST_clone_comlink
	{
		displayName="CWP-8 489";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_490: FST_clone_comlink
	{
		displayName="CWP-8 490";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_491: FST_clone_comlink
	{
		displayName="CWP-8 491";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_492: FST_clone_comlink
	{
		displayName="CWP-8 492";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_493: FST_clone_comlink
	{
		displayName="CWP-8 493";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_494: FST_clone_comlink
	{
		displayName="CWP-8 494";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_495: FST_clone_comlink
	{
		displayName="CWP-8 495";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_496: FST_clone_comlink
	{
		displayName="CWP-8 496";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_497: FST_clone_comlink
	{
		displayName="CWP-8 497";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_498: FST_clone_comlink
	{
		displayName="CWP-8 498";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_499: FST_clone_comlink
	{
		displayName="CWP-8 499";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_500: FST_clone_comlink
	{
		displayName="CWP-8 500";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_501: FST_clone_comlink
	{
		displayName="CWP-8 501";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_502: FST_clone_comlink
	{
		displayName="CWP-8 502";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_503: FST_clone_comlink
	{
		displayName="CWP-8 503";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_504: FST_clone_comlink
	{
		displayName="CWP-8 504";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_505: FST_clone_comlink
	{
		displayName="CWP-8 505";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_506: FST_clone_comlink
	{
		displayName="CWP-8 506";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_507: FST_clone_comlink
	{
		displayName="CWP-8 507";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_508: FST_clone_comlink
	{
		displayName="CWP-8 508";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_509: FST_clone_comlink
	{
		displayName="CWP-8 509";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_510: FST_clone_comlink
	{
		displayName="CWP-8 510";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_511: FST_clone_comlink
	{
		displayName="CWP-8 511";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_512: FST_clone_comlink
	{
		displayName="CWP-8 512";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_513: FST_clone_comlink
	{
		displayName="CWP-8 513";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_514: FST_clone_comlink
	{
		displayName="CWP-8 514";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_515: FST_clone_comlink
	{
		displayName="CWP-8 515";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_516: FST_clone_comlink
	{
		displayName="CWP-8 516";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_517: FST_clone_comlink
	{
		displayName="CWP-8 517";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_518: FST_clone_comlink
	{
		displayName="CWP-8 518";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_519: FST_clone_comlink
	{
		displayName="CWP-8 519";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_520: FST_clone_comlink
	{
		displayName="CWP-8 520";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_521: FST_clone_comlink
	{
		displayName="CWP-8 521";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_522: FST_clone_comlink
	{
		displayName="CWP-8 522";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_523: FST_clone_comlink
	{
		displayName="CWP-8 523";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_524: FST_clone_comlink
	{
		displayName="CWP-8 524";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_525: FST_clone_comlink
	{
		displayName="CWP-8 525";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_526: FST_clone_comlink
	{
		displayName="CWP-8 526";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_527: FST_clone_comlink
	{
		displayName="CWP-8 527";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_528: FST_clone_comlink
	{
		displayName="CWP-8 528";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_529: FST_clone_comlink
	{
		displayName="CWP-8 529";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_530: FST_clone_comlink
	{
		displayName="CWP-8 530";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_531: FST_clone_comlink
	{
		displayName="CWP-8 531";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_532: FST_clone_comlink
	{
		displayName="CWP-8 532";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_533: FST_clone_comlink
	{
		displayName="CWP-8 533";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_534: FST_clone_comlink
	{
		displayName="CWP-8 534";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_535: FST_clone_comlink
	{
		displayName="CWP-8 535";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_536: FST_clone_comlink
	{
		displayName="CWP-8 536";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_537: FST_clone_comlink
	{
		displayName="CWP-8 537";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_538: FST_clone_comlink
	{
		displayName="CWP-8 538";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_539: FST_clone_comlink
	{
		displayName="CWP-8 539";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_540: FST_clone_comlink
	{
		displayName="CWP-8 540";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_541: FST_clone_comlink
	{
		displayName="CWP-8 541";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_542: FST_clone_comlink
	{
		displayName="CWP-8 542";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_543: FST_clone_comlink
	{
		displayName="CWP-8 543";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_544: FST_clone_comlink
	{
		displayName="CWP-8 544";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_545: FST_clone_comlink
	{
		displayName="CWP-8 545";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_546: FST_clone_comlink
	{
		displayName="CWP-8 546";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_547: FST_clone_comlink
	{
		displayName="CWP-8 547";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_548: FST_clone_comlink
	{
		displayName="CWP-8 548";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_549: FST_clone_comlink
	{
		displayName="CWP-8 549";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_550: FST_clone_comlink
	{
		displayName="CWP-8 550";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_551: FST_clone_comlink
	{
		displayName="CWP-8 551";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_552: FST_clone_comlink
	{
		displayName="CWP-8 552";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_553: FST_clone_comlink
	{
		displayName="CWP-8 553";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_554: FST_clone_comlink
	{
		displayName="CWP-8 554";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_555: FST_clone_comlink
	{
		displayName="CWP-8 555";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_556: FST_clone_comlink
	{
		displayName="CWP-8 556";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_557: FST_clone_comlink
	{
		displayName="CWP-8 557";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_558: FST_clone_comlink
	{
		displayName="CWP-8 558";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_559: FST_clone_comlink
	{
		displayName="CWP-8 559";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_560: FST_clone_comlink
	{
		displayName="CWP-8 560";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_561: FST_clone_comlink
	{
		displayName="CWP-8 561";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_562: FST_clone_comlink
	{
		displayName="CWP-8 562";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_563: FST_clone_comlink
	{
		displayName="CWP-8 563";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_564: FST_clone_comlink
	{
		displayName="CWP-8 564";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_565: FST_clone_comlink
	{
		displayName="CWP-8 565";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_566: FST_clone_comlink
	{
		displayName="CWP-8 566";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_567: FST_clone_comlink
	{
		displayName="CWP-8 567";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_568: FST_clone_comlink
	{
		displayName="CWP-8 568";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_569: FST_clone_comlink
	{
		displayName="CWP-8 569";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_570: FST_clone_comlink
	{
		displayName="CWP-8 570";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_571: FST_clone_comlink
	{
		displayName="CWP-8 571";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_572: FST_clone_comlink
	{
		displayName="CWP-8 572";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_573: FST_clone_comlink
	{
		displayName="CWP-8 573";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_574: FST_clone_comlink
	{
		displayName="CWP-8 574";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_575: FST_clone_comlink
	{
		displayName="CWP-8 575";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_576: FST_clone_comlink
	{
		displayName="CWP-8 576";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_577: FST_clone_comlink
	{
		displayName="CWP-8 577";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_578: FST_clone_comlink
	{
		displayName="CWP-8 578";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_579: FST_clone_comlink
	{
		displayName="CWP-8 579";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_580: FST_clone_comlink
	{
		displayName="CWP-8 580";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_581: FST_clone_comlink
	{
		displayName="CWP-8 581";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_582: FST_clone_comlink
	{
		displayName="CWP-8 582";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_583: FST_clone_comlink
	{
		displayName="CWP-8 583";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_584: FST_clone_comlink
	{
		displayName="CWP-8 584";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_585: FST_clone_comlink
	{
		displayName="CWP-8 585";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_586: FST_clone_comlink
	{
		displayName="CWP-8 586";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_587: FST_clone_comlink
	{
		displayName="CWP-8 587";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_588: FST_clone_comlink
	{
		displayName="CWP-8 588";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_589: FST_clone_comlink
	{
		displayName="CWP-8 589";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_590: FST_clone_comlink
	{
		displayName="CWP-8 590";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_591: FST_clone_comlink
	{
		displayName="CWP-8 591";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_592: FST_clone_comlink
	{
		displayName="CWP-8 592";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_593: FST_clone_comlink
	{
		displayName="CWP-8 593";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_594: FST_clone_comlink
	{
		displayName="CWP-8 594";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_595: FST_clone_comlink
	{
		displayName="CWP-8 595";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_596: FST_clone_comlink
	{
		displayName="CWP-8 596";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_597: FST_clone_comlink
	{
		displayName="CWP-8 597";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_598: FST_clone_comlink
	{
		displayName="CWP-8 598";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_599: FST_clone_comlink
	{
		displayName="CWP-8 599";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_600: FST_clone_comlink
	{
		displayName="CWP-8 600";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_601: FST_clone_comlink
	{
		displayName="CWP-8 601";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_602: FST_clone_comlink
	{
		displayName="CWP-8 602";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_603: FST_clone_comlink
	{
		displayName="CWP-8 603";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_604: FST_clone_comlink
	{
		displayName="CWP-8 604";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_605: FST_clone_comlink
	{
		displayName="CWP-8 605";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_606: FST_clone_comlink
	{
		displayName="CWP-8 606";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_607: FST_clone_comlink
	{
		displayName="CWP-8 607";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_608: FST_clone_comlink
	{
		displayName="CWP-8 608";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_609: FST_clone_comlink
	{
		displayName="CWP-8 609";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_610: FST_clone_comlink
	{
		displayName="CWP-8 610";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_611: FST_clone_comlink
	{
		displayName="CWP-8 611";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_612: FST_clone_comlink
	{
		displayName="CWP-8 612";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_613: FST_clone_comlink
	{
		displayName="CWP-8 613";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_614: FST_clone_comlink
	{
		displayName="CWP-8 614";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_615: FST_clone_comlink
	{
		displayName="CWP-8 615";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_616: FST_clone_comlink
	{
		displayName="CWP-8 616";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_617: FST_clone_comlink
	{
		displayName="CWP-8 617";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_618: FST_clone_comlink
	{
		displayName="CWP-8 618";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_619: FST_clone_comlink
	{
		displayName="CWP-8 619";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_620: FST_clone_comlink
	{
		displayName="CWP-8 620";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_621: FST_clone_comlink
	{
		displayName="CWP-8 621";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_622: FST_clone_comlink
	{
		displayName="CWP-8 622";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_623: FST_clone_comlink
	{
		displayName="CWP-8 623";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_624: FST_clone_comlink
	{
		displayName="CWP-8 624";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_625: FST_clone_comlink
	{
		displayName="CWP-8 625";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_626: FST_clone_comlink
	{
		displayName="CWP-8 626";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_627: FST_clone_comlink
	{
		displayName="CWP-8 627";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_628: FST_clone_comlink
	{
		displayName="CWP-8 628";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_629: FST_clone_comlink
	{
		displayName="CWP-8 629";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_630: FST_clone_comlink
	{
		displayName="CWP-8 630";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_631: FST_clone_comlink
	{
		displayName="CWP-8 631";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_632: FST_clone_comlink
	{
		displayName="CWP-8 632";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_633: FST_clone_comlink
	{
		displayName="CWP-8 633";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_634: FST_clone_comlink
	{
		displayName="CWP-8 634";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_635: FST_clone_comlink
	{
		displayName="CWP-8 635";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_636: FST_clone_comlink
	{
		displayName="CWP-8 636";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_637: FST_clone_comlink
	{
		displayName="CWP-8 637";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_638: FST_clone_comlink
	{
		displayName="CWP-8 638";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_639: FST_clone_comlink
	{
		displayName="CWP-8 639";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_640: FST_clone_comlink
	{
		displayName="CWP-8 640";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_641: FST_clone_comlink
	{
		displayName="CWP-8 641";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_642: FST_clone_comlink
	{
		displayName="CWP-8 642";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_643: FST_clone_comlink
	{
		displayName="CWP-8 643";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_644: FST_clone_comlink
	{
		displayName="CWP-8 644";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_645: FST_clone_comlink
	{
		displayName="CWP-8 645";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_646: FST_clone_comlink
	{
		displayName="CWP-8 646";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_647: FST_clone_comlink
	{
		displayName="CWP-8 647";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_648: FST_clone_comlink
	{
		displayName="CWP-8 648";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_649: FST_clone_comlink
	{
		displayName="CWP-8 649";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_650: FST_clone_comlink
	{
		displayName="CWP-8 650";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_651: FST_clone_comlink
	{
		displayName="CWP-8 651";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_652: FST_clone_comlink
	{
		displayName="CWP-8 652";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_653: FST_clone_comlink
	{
		displayName="CWP-8 653";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_654: FST_clone_comlink
	{
		displayName="CWP-8 654";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_655: FST_clone_comlink
	{
		displayName="CWP-8 655";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_656: FST_clone_comlink
	{
		displayName="CWP-8 656";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_657: FST_clone_comlink
	{
		displayName="CWP-8 657";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_658: FST_clone_comlink
	{
		displayName="CWP-8 658";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_659: FST_clone_comlink
	{
		displayName="CWP-8 659";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_660: FST_clone_comlink
	{
		displayName="CWP-8 660";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_661: FST_clone_comlink
	{
		displayName="CWP-8 661";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_662: FST_clone_comlink
	{
		displayName="CWP-8 662";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_663: FST_clone_comlink
	{
		displayName="CWP-8 663";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_664: FST_clone_comlink
	{
		displayName="CWP-8 664";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_665: FST_clone_comlink
	{
		displayName="CWP-8 665";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_666: FST_clone_comlink
	{
		displayName="CWP-8 666";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_667: FST_clone_comlink
	{
		displayName="CWP-8 667";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_668: FST_clone_comlink
	{
		displayName="CWP-8 668";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_669: FST_clone_comlink
	{
		displayName="CWP-8 669";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_670: FST_clone_comlink
	{
		displayName="CWP-8 670";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_671: FST_clone_comlink
	{
		displayName="CWP-8 671";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_672: FST_clone_comlink
	{
		displayName="CWP-8 672";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_673: FST_clone_comlink
	{
		displayName="CWP-8 673";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_674: FST_clone_comlink
	{
		displayName="CWP-8 674";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_675: FST_clone_comlink
	{
		displayName="CWP-8 675";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_676: FST_clone_comlink
	{
		displayName="CWP-8 676";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_677: FST_clone_comlink
	{
		displayName="CWP-8 677";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_678: FST_clone_comlink
	{
		displayName="CWP-8 678";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_679: FST_clone_comlink
	{
		displayName="CWP-8 679";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_680: FST_clone_comlink
	{
		displayName="CWP-8 680";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_681: FST_clone_comlink
	{
		displayName="CWP-8 681";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_682: FST_clone_comlink
	{
		displayName="CWP-8 682";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_683: FST_clone_comlink
	{
		displayName="CWP-8 683";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_684: FST_clone_comlink
	{
		displayName="CWP-8 684";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_685: FST_clone_comlink
	{
		displayName="CWP-8 685";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_686: FST_clone_comlink
	{
		displayName="CWP-8 686";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_687: FST_clone_comlink
	{
		displayName="CWP-8 687";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_688: FST_clone_comlink
	{
		displayName="CWP-8 688";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_689: FST_clone_comlink
	{
		displayName="CWP-8 689";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_690: FST_clone_comlink
	{
		displayName="CWP-8 690";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_691: FST_clone_comlink
	{
		displayName="CWP-8 691";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_692: FST_clone_comlink
	{
		displayName="CWP-8 692";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_693: FST_clone_comlink
	{
		displayName="CWP-8 693";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_694: FST_clone_comlink
	{
		displayName="CWP-8 694";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_695: FST_clone_comlink
	{
		displayName="CWP-8 695";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_696: FST_clone_comlink
	{
		displayName="CWP-8 696";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_697: FST_clone_comlink
	{
		displayName="CWP-8 697";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_698: FST_clone_comlink
	{
		displayName="CWP-8 698";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_699: FST_clone_comlink
	{
		displayName="CWP-8 699";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_700: FST_clone_comlink
	{
		displayName="CWP-8 700";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_701: FST_clone_comlink
	{
		displayName="CWP-8 701";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_702: FST_clone_comlink
	{
		displayName="CWP-8 702";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_703: FST_clone_comlink
	{
		displayName="CWP-8 703";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_704: FST_clone_comlink
	{
		displayName="CWP-8 704";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_705: FST_clone_comlink
	{
		displayName="CWP-8 705";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_706: FST_clone_comlink
	{
		displayName="CWP-8 706";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_707: FST_clone_comlink
	{
		displayName="CWP-8 707";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_708: FST_clone_comlink
	{
		displayName="CWP-8 708";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_709: FST_clone_comlink
	{
		displayName="CWP-8 709";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_710: FST_clone_comlink
	{
		displayName="CWP-8 710";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_711: FST_clone_comlink
	{
		displayName="CWP-8 711";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_712: FST_clone_comlink
	{
		displayName="CWP-8 712";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_713: FST_clone_comlink
	{
		displayName="CWP-8 713";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_714: FST_clone_comlink
	{
		displayName="CWP-8 714";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_715: FST_clone_comlink
	{
		displayName="CWP-8 715";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_716: FST_clone_comlink
	{
		displayName="CWP-8 716";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_717: FST_clone_comlink
	{
		displayName="CWP-8 717";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_718: FST_clone_comlink
	{
		displayName="CWP-8 718";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_719: FST_clone_comlink
	{
		displayName="CWP-8 719";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_720: FST_clone_comlink
	{
		displayName="CWP-8 720";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_721: FST_clone_comlink
	{
		displayName="CWP-8 721";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_722: FST_clone_comlink
	{
		displayName="CWP-8 722";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_723: FST_clone_comlink
	{
		displayName="CWP-8 723";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_724: FST_clone_comlink
	{
		displayName="CWP-8 724";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_725: FST_clone_comlink
	{
		displayName="CWP-8 725";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_726: FST_clone_comlink
	{
		displayName="CWP-8 726";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_727: FST_clone_comlink
	{
		displayName="CWP-8 727";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_728: FST_clone_comlink
	{
		displayName="CWP-8 728";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_729: FST_clone_comlink
	{
		displayName="CWP-8 729";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_730: FST_clone_comlink
	{
		displayName="CWP-8 730";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_731: FST_clone_comlink
	{
		displayName="CWP-8 731";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_732: FST_clone_comlink
	{
		displayName="CWP-8 732";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_733: FST_clone_comlink
	{
		displayName="CWP-8 733";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_734: FST_clone_comlink
	{
		displayName="CWP-8 734";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_735: FST_clone_comlink
	{
		displayName="CWP-8 735";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_736: FST_clone_comlink
	{
		displayName="CWP-8 736";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_737: FST_clone_comlink
	{
		displayName="CWP-8 737";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_738: FST_clone_comlink
	{
		displayName="CWP-8 738";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_739: FST_clone_comlink
	{
		displayName="CWP-8 739";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_740: FST_clone_comlink
	{
		displayName="CWP-8 740";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_741: FST_clone_comlink
	{
		displayName="CWP-8 741";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_742: FST_clone_comlink
	{
		displayName="CWP-8 742";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_743: FST_clone_comlink
	{
		displayName="CWP-8 743";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_744: FST_clone_comlink
	{
		displayName="CWP-8 744";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_745: FST_clone_comlink
	{
		displayName="CWP-8 745";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_746: FST_clone_comlink
	{
		displayName="CWP-8 746";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_747: FST_clone_comlink
	{
		displayName="CWP-8 747";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_748: FST_clone_comlink
	{
		displayName="CWP-8 748";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_749: FST_clone_comlink
	{
		displayName="CWP-8 749";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_750: FST_clone_comlink
	{
		displayName="CWP-8 750";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_751: FST_clone_comlink
	{
		displayName="CWP-8 751";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_752: FST_clone_comlink
	{
		displayName="CWP-8 752";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_753: FST_clone_comlink
	{
		displayName="CWP-8 753";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_754: FST_clone_comlink
	{
		displayName="CWP-8 754";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_755: FST_clone_comlink
	{
		displayName="CWP-8 755";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_756: FST_clone_comlink
	{
		displayName="CWP-8 756";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_757: FST_clone_comlink
	{
		displayName="CWP-8 757";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_758: FST_clone_comlink
	{
		displayName="CWP-8 758";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_759: FST_clone_comlink
	{
		displayName="CWP-8 759";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_760: FST_clone_comlink
	{
		displayName="CWP-8 760";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_761: FST_clone_comlink
	{
		displayName="CWP-8 761";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_762: FST_clone_comlink
	{
		displayName="CWP-8 762";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_763: FST_clone_comlink
	{
		displayName="CWP-8 763";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_764: FST_clone_comlink
	{
		displayName="CWP-8 764";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_765: FST_clone_comlink
	{
		displayName="CWP-8 765";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_766: FST_clone_comlink
	{
		displayName="CWP-8 766";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_767: FST_clone_comlink
	{
		displayName="CWP-8 767";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_768: FST_clone_comlink
	{
		displayName="CWP-8 768";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_769: FST_clone_comlink
	{
		displayName="CWP-8 769";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_770: FST_clone_comlink
	{
		displayName="CWP-8 770";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_771: FST_clone_comlink
	{
		displayName="CWP-8 771";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_772: FST_clone_comlink
	{
		displayName="CWP-8 772";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_773: FST_clone_comlink
	{
		displayName="CWP-8 773";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_774: FST_clone_comlink
	{
		displayName="CWP-8 774";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_775: FST_clone_comlink
	{
		displayName="CWP-8 775";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_776: FST_clone_comlink
	{
		displayName="CWP-8 776";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_777: FST_clone_comlink
	{
		displayName="CWP-8 777";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_778: FST_clone_comlink
	{
		displayName="CWP-8 778";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_779: FST_clone_comlink
	{
		displayName="CWP-8 779";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_780: FST_clone_comlink
	{
		displayName="CWP-8 780";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_781: FST_clone_comlink
	{
		displayName="CWP-8 781";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_782: FST_clone_comlink
	{
		displayName="CWP-8 782";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_783: FST_clone_comlink
	{
		displayName="CWP-8 783";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_784: FST_clone_comlink
	{
		displayName="CWP-8 784";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_785: FST_clone_comlink
	{
		displayName="CWP-8 785";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_786: FST_clone_comlink
	{
		displayName="CWP-8 786";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_787: FST_clone_comlink
	{
		displayName="CWP-8 787";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_788: FST_clone_comlink
	{
		displayName="CWP-8 788";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_789: FST_clone_comlink
	{
		displayName="CWP-8 789";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_790: FST_clone_comlink
	{
		displayName="CWP-8 790";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_791: FST_clone_comlink
	{
		displayName="CWP-8 791";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_792: FST_clone_comlink
	{
		displayName="CWP-8 792";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_793: FST_clone_comlink
	{
		displayName="CWP-8 793";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_794: FST_clone_comlink
	{
		displayName="CWP-8 794";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_795: FST_clone_comlink
	{
		displayName="CWP-8 795";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_796: FST_clone_comlink
	{
		displayName="CWP-8 796";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_797: FST_clone_comlink
	{
		displayName="CWP-8 797";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_798: FST_clone_comlink
	{
		displayName="CWP-8 798";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_799: FST_clone_comlink
	{
		displayName="CWP-8 799";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_800: FST_clone_comlink
	{
		displayName="CWP-8 800";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_801: FST_clone_comlink
	{
		displayName="CWP-8 801";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_802: FST_clone_comlink
	{
		displayName="CWP-8 802";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_803: FST_clone_comlink
	{
		displayName="CWP-8 803";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_804: FST_clone_comlink
	{
		displayName="CWP-8 804";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_805: FST_clone_comlink
	{
		displayName="CWP-8 805";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_806: FST_clone_comlink
	{
		displayName="CWP-8 806";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_807: FST_clone_comlink
	{
		displayName="CWP-8 807";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_808: FST_clone_comlink
	{
		displayName="CWP-8 808";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_809: FST_clone_comlink
	{
		displayName="CWP-8 809";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_810: FST_clone_comlink
	{
		displayName="CWP-8 810";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_811: FST_clone_comlink
	{
		displayName="CWP-8 811";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_812: FST_clone_comlink
	{
		displayName="CWP-8 812";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_813: FST_clone_comlink
	{
		displayName="CWP-8 813";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_814: FST_clone_comlink
	{
		displayName="CWP-8 814";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_815: FST_clone_comlink
	{
		displayName="CWP-8 815";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_816: FST_clone_comlink
	{
		displayName="CWP-8 816";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_817: FST_clone_comlink
	{
		displayName="CWP-8 817";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_818: FST_clone_comlink
	{
		displayName="CWP-8 818";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_819: FST_clone_comlink
	{
		displayName="CWP-8 819";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_820: FST_clone_comlink
	{
		displayName="CWP-8 820";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_821: FST_clone_comlink
	{
		displayName="CWP-8 821";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_822: FST_clone_comlink
	{
		displayName="CWP-8 822";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_823: FST_clone_comlink
	{
		displayName="CWP-8 823";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_824: FST_clone_comlink
	{
		displayName="CWP-8 824";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_825: FST_clone_comlink
	{
		displayName="CWP-8 825";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_826: FST_clone_comlink
	{
		displayName="CWP-8 826";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_827: FST_clone_comlink
	{
		displayName="CWP-8 827";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_828: FST_clone_comlink
	{
		displayName="CWP-8 828";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_829: FST_clone_comlink
	{
		displayName="CWP-8 829";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_830: FST_clone_comlink
	{
		displayName="CWP-8 830";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_831: FST_clone_comlink
	{
		displayName="CWP-8 831";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_832: FST_clone_comlink
	{
		displayName="CWP-8 832";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_833: FST_clone_comlink
	{
		displayName="CWP-8 833";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_834: FST_clone_comlink
	{
		displayName="CWP-8 834";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_835: FST_clone_comlink
	{
		displayName="CWP-8 835";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_836: FST_clone_comlink
	{
		displayName="CWP-8 836";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_837: FST_clone_comlink
	{
		displayName="CWP-8 837";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_838: FST_clone_comlink
	{
		displayName="CWP-8 838";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_839: FST_clone_comlink
	{
		displayName="CWP-8 839";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_840: FST_clone_comlink
	{
		displayName="CWP-8 840";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_841: FST_clone_comlink
	{
		displayName="CWP-8 841";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_842: FST_clone_comlink
	{
		displayName="CWP-8 842";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_843: FST_clone_comlink
	{
		displayName="CWP-8 843";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_844: FST_clone_comlink
	{
		displayName="CWP-8 844";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_845: FST_clone_comlink
	{
		displayName="CWP-8 845";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_846: FST_clone_comlink
	{
		displayName="CWP-8 846";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_847: FST_clone_comlink
	{
		displayName="CWP-8 847";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_848: FST_clone_comlink
	{
		displayName="CWP-8 848";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_849: FST_clone_comlink
	{
		displayName="CWP-8 849";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_850: FST_clone_comlink
	{
		displayName="CWP-8 850";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_851: FST_clone_comlink
	{
		displayName="CWP-8 851";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_852: FST_clone_comlink
	{
		displayName="CWP-8 852";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_853: FST_clone_comlink
	{
		displayName="CWP-8 853";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_854: FST_clone_comlink
	{
		displayName="CWP-8 854";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_855: FST_clone_comlink
	{
		displayName="CWP-8 855";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_856: FST_clone_comlink
	{
		displayName="CWP-8 856";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_857: FST_clone_comlink
	{
		displayName="CWP-8 857";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_858: FST_clone_comlink
	{
		displayName="CWP-8 858";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_859: FST_clone_comlink
	{
		displayName="CWP-8 859";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_860: FST_clone_comlink
	{
		displayName="CWP-8 860";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_861: FST_clone_comlink
	{
		displayName="CWP-8 861";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_862: FST_clone_comlink
	{
		displayName="CWP-8 862";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_863: FST_clone_comlink
	{
		displayName="CWP-8 863";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_864: FST_clone_comlink
	{
		displayName="CWP-8 864";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_865: FST_clone_comlink
	{
		displayName="CWP-8 865";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_866: FST_clone_comlink
	{
		displayName="CWP-8 866";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_867: FST_clone_comlink
	{
		displayName="CWP-8 867";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_868: FST_clone_comlink
	{
		displayName="CWP-8 868";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_869: FST_clone_comlink
	{
		displayName="CWP-8 869";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_870: FST_clone_comlink
	{
		displayName="CWP-8 870";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_871: FST_clone_comlink
	{
		displayName="CWP-8 871";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_872: FST_clone_comlink
	{
		displayName="CWP-8 872";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_873: FST_clone_comlink
	{
		displayName="CWP-8 873";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_874: FST_clone_comlink
	{
		displayName="CWP-8 874";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_875: FST_clone_comlink
	{
		displayName="CWP-8 875";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_876: FST_clone_comlink
	{
		displayName="CWP-8 876";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_877: FST_clone_comlink
	{
		displayName="CWP-8 877";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_878: FST_clone_comlink
	{
		displayName="CWP-8 878";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_879: FST_clone_comlink
	{
		displayName="CWP-8 879";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_880: FST_clone_comlink
	{
		displayName="CWP-8 880";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_881: FST_clone_comlink
	{
		displayName="CWP-8 881";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_882: FST_clone_comlink
	{
		displayName="CWP-8 882";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_883: FST_clone_comlink
	{
		displayName="CWP-8 883";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_884: FST_clone_comlink
	{
		displayName="CWP-8 884";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_885: FST_clone_comlink
	{
		displayName="CWP-8 885";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_886: FST_clone_comlink
	{
		displayName="CWP-8 886";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_887: FST_clone_comlink
	{
		displayName="CWP-8 887";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_888: FST_clone_comlink
	{
		displayName="CWP-8 888";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_889: FST_clone_comlink
	{
		displayName="CWP-8 889";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_890: FST_clone_comlink
	{
		displayName="CWP-8 890";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_891: FST_clone_comlink
	{
		displayName="CWP-8 891";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_892: FST_clone_comlink
	{
		displayName="CWP-8 892";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_893: FST_clone_comlink
	{
		displayName="CWP-8 893";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_894: FST_clone_comlink
	{
		displayName="CWP-8 894";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_895: FST_clone_comlink
	{
		displayName="CWP-8 895";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_896: FST_clone_comlink
	{
		displayName="CWP-8 896";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_897: FST_clone_comlink
	{
		displayName="CWP-8 897";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_898: FST_clone_comlink
	{
		displayName="CWP-8 898";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_899: FST_clone_comlink
	{
		displayName="CWP-8 899";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_900: FST_clone_comlink
	{
		displayName="CWP-8 900";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_901: FST_clone_comlink
	{
		displayName="CWP-8 901";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_902: FST_clone_comlink
	{
		displayName="CWP-8 902";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_903: FST_clone_comlink
	{
		displayName="CWP-8 903";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_904: FST_clone_comlink
	{
		displayName="CWP-8 904";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_905: FST_clone_comlink
	{
		displayName="CWP-8 905";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_906: FST_clone_comlink
	{
		displayName="CWP-8 906";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_907: FST_clone_comlink
	{
		displayName="CWP-8 907";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_908: FST_clone_comlink
	{
		displayName="CWP-8 908";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_909: FST_clone_comlink
	{
		displayName="CWP-8 909";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_910: FST_clone_comlink
	{
		displayName="CWP-8 910";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_911: FST_clone_comlink
	{
		displayName="CWP-8 911";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_912: FST_clone_comlink
	{
		displayName="CWP-8 912";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_913: FST_clone_comlink
	{
		displayName="CWP-8 913";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_914: FST_clone_comlink
	{
		displayName="CWP-8 914";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_915: FST_clone_comlink
	{
		displayName="CWP-8 915";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_916: FST_clone_comlink
	{
		displayName="CWP-8 916";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_917: FST_clone_comlink
	{
		displayName="CWP-8 917";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_918: FST_clone_comlink
	{
		displayName="CWP-8 918";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_919: FST_clone_comlink
	{
		displayName="CWP-8 919";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_920: FST_clone_comlink
	{
		displayName="CWP-8 920";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_921: FST_clone_comlink
	{
		displayName="CWP-8 921";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_922: FST_clone_comlink
	{
		displayName="CWP-8 922";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_923: FST_clone_comlink
	{
		displayName="CWP-8 923";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_924: FST_clone_comlink
	{
		displayName="CWP-8 924";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_925: FST_clone_comlink
	{
		displayName="CWP-8 925";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_926: FST_clone_comlink
	{
		displayName="CWP-8 926";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_927: FST_clone_comlink
	{
		displayName="CWP-8 927";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_928: FST_clone_comlink
	{
		displayName="CWP-8 928";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_929: FST_clone_comlink
	{
		displayName="CWP-8 929";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_930: FST_clone_comlink
	{
		displayName="CWP-8 930";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_931: FST_clone_comlink
	{
		displayName="CWP-8 931";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_932: FST_clone_comlink
	{
		displayName="CWP-8 932";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_933: FST_clone_comlink
	{
		displayName="CWP-8 933";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_934: FST_clone_comlink
	{
		displayName="CWP-8 934";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_935: FST_clone_comlink
	{
		displayName="CWP-8 935";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_936: FST_clone_comlink
	{
		displayName="CWP-8 936";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_937: FST_clone_comlink
	{
		displayName="CWP-8 937";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_938: FST_clone_comlink
	{
		displayName="CWP-8 938";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_939: FST_clone_comlink
	{
		displayName="CWP-8 939";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_940: FST_clone_comlink
	{
		displayName="CWP-8 940";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_941: FST_clone_comlink
	{
		displayName="CWP-8 941";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_942: FST_clone_comlink
	{
		displayName="CWP-8 942";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_943: FST_clone_comlink
	{
		displayName="CWP-8 943";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_944: FST_clone_comlink
	{
		displayName="CWP-8 944";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_945: FST_clone_comlink
	{
		displayName="CWP-8 945";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_946: FST_clone_comlink
	{
		displayName="CWP-8 946";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_947: FST_clone_comlink
	{
		displayName="CWP-8 947";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_948: FST_clone_comlink
	{
		displayName="CWP-8 948";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_949: FST_clone_comlink
	{
		displayName="CWP-8 949";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_950: FST_clone_comlink
	{
		displayName="CWP-8 950";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_951: FST_clone_comlink
	{
		displayName="CWP-8 951";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_952: FST_clone_comlink
	{
		displayName="CWP-8 952";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_953: FST_clone_comlink
	{
		displayName="CWP-8 953";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_954: FST_clone_comlink
	{
		displayName="CWP-8 954";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_955: FST_clone_comlink
	{
		displayName="CWP-8 955";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_956: FST_clone_comlink
	{
		displayName="CWP-8 956";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_957: FST_clone_comlink
	{
		displayName="CWP-8 957";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_958: FST_clone_comlink
	{
		displayName="CWP-8 958";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_959: FST_clone_comlink
	{
		displayName="CWP-8 959";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_960: FST_clone_comlink
	{
		displayName="CWP-8 960";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_961: FST_clone_comlink
	{
		displayName="CWP-8 961";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_962: FST_clone_comlink
	{
		displayName="CWP-8 962";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_963: FST_clone_comlink
	{
		displayName="CWP-8 963";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_964: FST_clone_comlink
	{
		displayName="CWP-8 964";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_965: FST_clone_comlink
	{
		displayName="CWP-8 965";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_966: FST_clone_comlink
	{
		displayName="CWP-8 966";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_967: FST_clone_comlink
	{
		displayName="CWP-8 967";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_968: FST_clone_comlink
	{
		displayName="CWP-8 968";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_969: FST_clone_comlink
	{
		displayName="CWP-8 969";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_970: FST_clone_comlink
	{
		displayName="CWP-8 970";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_971: FST_clone_comlink
	{
		displayName="CWP-8 971";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_972: FST_clone_comlink
	{
		displayName="CWP-8 972";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_973: FST_clone_comlink
	{
		displayName="CWP-8 973";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_974: FST_clone_comlink
	{
		displayName="CWP-8 974";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_975: FST_clone_comlink
	{
		displayName="CWP-8 975";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_976: FST_clone_comlink
	{
		displayName="CWP-8 976";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_977: FST_clone_comlink
	{
		displayName="CWP-8 977";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_978: FST_clone_comlink
	{
		displayName="CWP-8 978";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_979: FST_clone_comlink
	{
		displayName="CWP-8 979";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_980: FST_clone_comlink
	{
		displayName="CWP-8 980";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_981: FST_clone_comlink
	{
		displayName="CWP-8 981";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_982: FST_clone_comlink
	{
		displayName="CWP-8 982";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_983: FST_clone_comlink
	{
		displayName="CWP-8 983";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_984: FST_clone_comlink
	{
		displayName="CWP-8 984";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_985: FST_clone_comlink
	{
		displayName="CWP-8 985";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_986: FST_clone_comlink
	{
		displayName="CWP-8 986";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_987: FST_clone_comlink
	{
		displayName="CWP-8 987";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_988: FST_clone_comlink
	{
		displayName="CWP-8 988";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_989: FST_clone_comlink
	{
		displayName="CWP-8 989";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_990: FST_clone_comlink
	{
		displayName="CWP-8 990";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_991: FST_clone_comlink
	{
		displayName="CWP-8 991";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_992: FST_clone_comlink
	{
		displayName="CWP-8 992";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_993: FST_clone_comlink
	{
		displayName="CWP-8 993";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_994: FST_clone_comlink
	{
		displayName="CWP-8 994";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_995: FST_clone_comlink
	{
		displayName="CWP-8 995";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_996: FST_clone_comlink
	{
		displayName="CWP-8 996";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_997: FST_clone_comlink
	{
		displayName="CWP-8 997";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_998: FST_clone_comlink
	{
		displayName="CWP-8 998";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_999: FST_clone_comlink
	{
		displayName="CWP-8 999";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class FST_clone_comlink_1000: FST_clone_comlink
	{
		displayName="CWP-8 1000";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
};
