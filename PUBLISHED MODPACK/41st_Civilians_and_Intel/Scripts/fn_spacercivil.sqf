
params ["_unit"];

if (isNull _unit) exitWith {};
if (!local _unit) exitWith {}; 

if (_unit getVariable ["FST_Initialized", false]) exitWith {};
_unit setVariable ["FST_Initialized", true, true];

["FST_applyName", [ _unit, "Citizen"]] call CBA_fnc_globalEvent;

[_unit] spawn {

params ["_unit"];

if (isNull _unit) exitWith {};

sleep 0.05;

if (isNull _unit) exitWith {};
if (!local _unit) exitWith {};

private _lowrollarray = [1, 0.4, 2, 0.4, 3, 0.2];
private _midrollarray = [3, 0.4, 4, 0.4, 5, 0.2];
private _highrollarray = [4, 0.2, 5, 0.4, 6, 0.3, 7, 0.1];

private _rolllow0 = selectRandomWeighted _lowrollarray;
private _rolllow1 = selectRandomWeighted _lowrollarray;
private _rolllow2 = selectRandomWeighted _lowrollarray;
private _rolllow3 = selectRandomWeighted _lowrollarray;
private _rollmid0 = selectRandomWeighted _midrollarray;
private _rollmid1 = selectRandomWeighted _midrollarray;
private _rollmid2 = selectRandomWeighted _midrollarray;
private _rollhigh0 = selectRandomWeighted _highrollarray;

private _list_41creditsitemslow = [
	"JLTS_credits_10", 0.8,
	"JLTS_credits_50", 0.6,
	"JLTS_credits_100", 0.4,
	"", 0.2
];

private _pocket0 = selectRandomWeighted _list_41creditsitemslow;
private _pocket1 = selectRandomWeighted _list_41creditsitemslow;
private _pocket2 = selectRandomWeighted _list_41creditsitemslow;

private _list_41creditsitemshigh = [
	"FST_CreditChip", 0.6,
	"", 0.2,
	"JLTS_credits_500", 0.2,
	"JLTS_credits_1000", 0.05,
	"FST_CreditCase_Lock", 0.03,
	"FST_CreditCase_Low", 0.01
];

private _rich0 = selectRandomWeighted _list_41creditsitemshigh;
private _rich1 = selectRandomWeighted _list_41creditsitemshigh;

private _list_41civdatapad = [
	"FST_CivData_Normal", 0.6, 
	"FST_CivData_Abnormal", 0.06,
	"FST_CivData_Betting", 0.3,
	"FST_CivData_Bulge", 0.05,
	"FST_CivData_Cat", 0.3,
	"FST_CivData_Costly", 0.05,
	"FST_CivData_Damage", 0.3,
	"FST_CivData_Dead", 0.05,
	"FST_CivData_Ew", 0.1,
	"FST_CivData_Gamer", 0.3,
	"FST_CivData_Idiot", 0.1,
	"FST_CivData_Illegal", 0.1,
	"FST_CivData_Interface", 0.3,
	"FST_CivData_IR", 0.3,
	"FST_CivData_Lang", 0.6,
	"FST_CivData_Meme", 0.1,
	"FST_CivData_Off", 0.1,
	"FST_CivData_Old", 0.1,
	"FST_CivData_Overload", 0.3,
	"FST_CivData_Password", 0.05,
	"FST_CivData_Selfie", 0.1,
	"FST_CivData_Slow", 0.05,
	"FST_CivData_Spacer", 0.6,
	"FST_CivData_UV", 0.3,
	"FST_CivData_UwU", 0.3,
	"FST_CivData_Virus", 0.05,
	"FST_CivData_Work", 0.1,
	"FST_SpaceData_Normal", 0.6,
	"FST_SpaceData_Abnormal", 0.06,
	"FST_SpaceData_Aqua", 0.3,
	"FST_SpaceData_Blast", 0.1,
	"FST_SpaceData_Brick", 0.05,
	"FST_SpaceData_Chem", 0.05,
	"FST_SpaceData_Droid", 0.1,
	"FST_SpaceData_Drop", 0.1,
	"FST_SpaceData_Fire", 0.3,
	"FST_SpaceData_Oil", 0.3,
	"FST_SpaceData_Press", 0.3,
	"FST_SpaceData_Radio", 0.3,
	"FST_SpaceData_SPACE", 0.6,
	"FST_SpaceData_Squish", 0.05,
	"FST_StylusData_Normal", 0.6,
	"FST_StylusData_Abnormal", 0.06,
	"FST_StylusData_Alien", 0.6,
	"FST_StylusData_Broken", 0.05,
	"FST_StylusData_Check", 0.3,
	"FST_StylusData_Chew", 0.05,
	"FST_StylusData_Delivery", 0.3,
	"FST_StylusData_Draw", 0.1,
	"FST_StylusData_Engine", 0.6,
	"FST_StylusData_Flight", 0.6,
	"FST_StylusData_Form", 0.3,
	"FST_StylusData_Game", 0.3,
	"FST_StylusData_Lost", 0.05,
	"FST_StylusData_Note", 0.3,
	"FST_StylusData_Scratch", 0.05,
	"FST_StylusData_Stab", 0.05,
	"FST_CivMiniData_Normal", 0.6,
	"FST_CivMiniData_Abnormal", 0.06,
	"FST_CivMiniData_Atmos", 0.6,
	"FST_CivMiniData_Broken", 0.05,
	"FST_CivMiniData_Built", 0.1,
	"FST_CivMiniData_Camera", 0.3,
	"FST_CivMiniData_Chem", 0.1,
	"FST_CivMiniData_Diagnose", 0.6,
	"FST_CivMiniData_Droid", 0.1,
	"FST_CivMiniData_GPS", 0.1,
	"FST_CivMiniData_Huh", 0.3,
	"FST_CivMiniData_Music", 0.3,
	"FST_CivMiniData_Notes", 0.3,
	"FST_CivMiniData_Radio", 0.6,
	"FST_CivMiniData_Shot", 0.3,
	"FST_CivMiniData_Track", 0.6

];

private _datapad0 = selectRandomWeighted _list_41civdatapad;
private _datapad1 = selectRandomWeighted _list_41civdatapad;

private _list_41civintelitems = [
	"FST_ReadData_Normal", 0.6,
	"FST_ReadData_Abnormal", 0.06,
	"FST_ReadData_Action", 0.3,
	"FST_ReadData_Alien", 0.6,
	"FST_ReadData_Bad", 0.1,
	"FST_ReadData_Bio", 0.05,
	"FST_ReadData_Boring", 0.1,
	"FST_ReadData_Cook", 0.05,
	"FST_ReadData_Droid", 0.1,
	"FST_ReadData_Flicker", 0.05,
	"FST_ReadData_Horror", 0.3,
	"FST_ReadData_Jedi", 0.3,
	"FST_ReadData_Legal", 0.05,
	"FST_ReadData_Love", 0.3,
	"FST_ReadData_Mystery", 0.3,
	"FST_ReadData_News", 0.1,
	"FST_ReadData_Religion", 0.05,
	"FST_ReadData_Report", 0.1,
	"FST_ReadData_Snap", 0.05,
	"FST_ReadData_Tabloid", 0.05,
	"FST_ReadData_Text", 0.05,
	"FST_ReadData_Youth", 0.3,
	"FST_CivDatacard_Normal", 0.6,
	"FST_CivDatacard_Abnormal", 0.06,
	"FST_CivDatacard_Blueprint", 0.05,
	"FST_CivDatacard_Broken", 0.05,
	"FST_CivDatacard_Calendar", 0.1,
	"FST_CivDatacard_Care", 0.3,
	"FST_CivDatacard_Corrupt", 0.05,
	"FST_CivDatacard_Doc", 0.3,
	"FST_CivDatacard_Empty", 0.05,
	"FST_CivDatacard_Family", 0.3,
	"FST_CivDatacard_Fiction", 0.3,
	"FST_CivDatacard_Game", 0.3,
	"FST_CivDatacard_Journal", 0.3,
	"FST_CivDatacard_Manual", 0.05,
	"FST_CivDatacard_Money", 0.1,
	"FST_CivDatacard_Mouse", 0.05,
	"FST_CivDatacard_Movie", 0.3,
	"FST_CivDatacard_Music", 0.3,
	"FST_CivDatacard_News", 0.3,
	"FST_CivDatacard_OwO", 0.6,
	"FST_CivDatacard_Program", 0.3,
	"FST_CivDatacard_Report", 0.1,
	"FST_CivDatacard_Tax", 0.05,
	"FST_CivDatacard_Troll", 0.1,
	"FST_CivDatacard_Virus", 0.05,
	"FST_CivFlimsi_Normal", 0.6,
	"FST_CivFlimsi_Abnormal", 0.06,
	"FST_CivFlimsi_Ad", 0.6,
	"FST_CivFlimsi_BCard", 0.1,
	"FST_CivFlimsi_CCard", 0.3,
	"FST_CivFlimsi_Coupon", 0.05,
	"FST_CivFlimsi_Crazy", 0.1,
	"FST_CivFlimsi_Doc", 0.3,
	"FST_CivFlimsi_Doodle", 0.3,
	"FST_CivFlimsi_Flyer", 0.3,
	"FST_CivFlimsi_Food", 0.05,
	"FST_CivFlimsi_Form", 0.3,
	"FST_CivFlimsi_Gross", 0.1,
	"FST_CivFlimsi_Letter", 0.05,
	"FST_CivFlimsi_List", 0.1,
	"FST_CivFlimsi_Love", 0.1,
	"FST_CivFlimsi_Note", 0.3,
	"FST_CivFlimsi_Picture", 0.3,
	"FST_CivFlimsi_Receipt", 0.3,
	"FST_CivFlimsi_Starchart", 0.6,
	"FST_CivFlimsi_Stick", 0.1,
	"FST_CivFlimsi_Trash", 0.05,
	"FST_CivFlimsi_Wanted", 0.1,
	"FST_CivFlimsi_Work", 0.3,
	"FST_CivFlimsiFile_Normal", 0.2,
	"FST_CivFlimsiFile_Abnormal", 0.06,
	"FST_CivFlimsiFile_Alien", 0.3,
	"FST_CivFlimsiFile_Taxes", 0.05,
	"FST_CivFlimsiFile_Work", 0.3,
	"FST_CivFlimsiFile_Photo", 0.05,
	"FST_CivFlimsiFile_Profile", 0.05,
	"FST_CivFlimsiFile_Project", 0.1,
	"FST_CivFlimsiFile_Order", 0.1,
	"FST_CivFlimsiFile_Law", 0.05,
	"FST_CivFlimsiFile_Transport", 0.3,
	"FST_CivFlimsiFile_Record", 0.1,
	"FST_CivFlimsiFile_Starchart", 0.6,
	"FST_CivFlimsiFile_Starship", 0.6,
	"FST_CivHoloprojector_Normal", 0.6,
	"FST_CivHoloprojector_Abnormal", 0.06,
	"FST_CivHoloprojector_Alien", 0.3,
	"FST_CivHoloprojector_Beast", 0.3,
	"FST_CivHoloprojector_Blueprint", 0.05,
	"FST_CivHoloprojector_Broken", 0.05,
	"FST_CivHoloprojector_Design", 0.1,
	"FST_CivHoloprojector_Empty", 0.05,
	"FST_CivHoloprojector_Galaxy", 0.6,
	"FST_CivHoloprojector_Game", 0.3,
	"FST_CivHoloprojector_Ha", 0.1,
	"FST_CivHoloprojector_Land", 0.1,
	"FST_CivHoloprojector_Manual", 0.05,
	"FST_CivHoloprojector_Map", 0.3,
	"FST_CivHoloprojector_Movie", 0.3,
	"FST_CivHoloprojector_OwO", 0.3,
	"FST_CivHoloprojector_Record", 0.05,
	"FST_CivHoloprojector_Route", 0.6,
	"FST_CivHoloprojector_Solar", 0.6,
	"FST_CivHoloprojector_Sport", 0.3,
	"FST_CivHoloprojector_Video", 0.3,
	"FST_CivHoloprojector_Weird", 0.3,
	"", 0.2

];

private _intelitem0 = selectRandomWeighted _list_41civintelitems;
private _intelitem1 = selectRandomWeighted _list_41civintelitems;
private _intelitem2 = selectRandomWeighted _list_41civintelitems;
private _intelitem3 = selectRandomWeighted _list_41civintelitems;

private _list_41civcomms = [
	"FST_HoloComm_Normal", 0.5,
	"FST_HoloComm_Abnormal", 0.06,
	"FST_HandComm_Normal", 1,
	"FST_HandComm_Abnormal", 0.06,
	"FST_FlatComm_Normal", 1,
	"FST_FlatComm_Abnormal", 0.06

];

private _comm0 = selectRandomWeighted _list_41civcomms;
private _comm1 = selectRandomWeighted _list_41civcomms;

private _list_41breathinggasses = [
	"FST_BreathingGas_Flammable",
	"FST_BreathingGas_Oxygen",
	"FST_BreathingGas_Ozone",
	"FST_BreathingGas_Ammonia",
	"FST_BreathingGas_Corrosive",
	"FST_BreathingGas_Sulfur",
	"FST_BreathingGas_Chlorine",
	"FST_BreathingGas_Phosphine",
	"FST_BreathingGas_Dioxide"

];

private _gas0 = selectRandom _list_41breathinggasses;

private _list_41femaleheads = [
	"TCGM_Fem_Zhu",
	"TCGM_MakF_ZhuClub1",
	"TCGM_Fem_Stone",
	"TCGM_Fem_StoneBun",
    "TCGM_MakF_StoneClub1",
	"TCGM_Fem_Fox",
	"TCGM_Fem_FoxBun",
    "TCGM_MakF_FoxClub1",
	"TCGM_Fem_Eilish",
	"TCGM_Fem_EilishBun",
    "TCGM_MakF_EilishClub1",
	"TCGM_Fem_Ayres",
	"TCGM_MakF_AyresClub1",
	"TCGM_Fem_Portman",
	"TCGM_MakF_PortmanClub1",
	"TCGM_Fem_Lynch",
	"TCGM_MakF_LynchClub1",
	"TCGM_Fem_Liu",
	"TCGM_MakF_LiuClub1",
	"TCGM_Fem_Hobson",
	"TCGM_MakF_HobsonClub1",
	"TCGM_Fem_Gonzalez",
	"TCGM_MakF_GonzalezClub1",
	"TCGM_Fem_Fenty",
	"TCGM_MakF_FentyClub1",
	"FST_Navy_Face_Ruby",
	"FST_Navy_Face_Mustang"
];

private _list_41maleheads = [
	"GreekHead_A3_01",
	"GreekHead_A3_02",
	"GreekHead_A3_03",
    "GreekHead_A3_04",
    "GreekHead_A3_05",
    "GreekHead_A3_06",
    "GreekHead_A3_07",
    "GreekHead_A3_08",
    "GreekHead_A3_09",
    "GreekHead_A3_11",
    "GreekHead_A3_12",
    "GreekHead_A3_13",
    "GreekHead_A3_14",
	"PersianHead_A3_01",
	"PersianHead_A3_02",
	"PersianHead_A3_03",
	"WhiteHead_01",
    "WhiteHead_02",
	"WhiteHead_03",
	"WhiteHead_04",
	"WhiteHead_05",
	"WhiteHead_06",
	"WhiteHead_07",
	"WhiteHead_08",
	"WhiteHead_09",
	"WhiteHead_10",
	"WhiteHead_11",
	"WhiteHead_12",
	"WhiteHead_13",
	"WhiteHead_14",
	"WhiteHead_15",
	"WhiteHead_16",
	"WhiteHead_17",
	"WhiteHead_18",
	"WhiteHead_19",
	"WhiteHead_20",
	"WhiteHead_21",
	"WhiteHead_23",
	"WhiteHead_24",
	"WhiteHead_25",
	"WhiteHead_26",
	"WhiteHead_27",
	"WhiteHead_28",
	"WhiteHead_29",
	"WhiteHead_30",
	"WhiteHead_31",
	"WhiteHead_32",
	"RussianHead_1",
	"RussianHead_2",
	"RussianHead_3",
	"RussianHead_4",
	"RussianHead_5",
    "AfricanHead_01",
    "AfricanHead_02",
    "AfricanHead_03",
	"LivonianHead_1",
	"LivonianHead_2",
	"LivonianHead_3",
	"LivonianHead_4",
	"LivonianHead_5",
	"LivonianHead_6",
	"LivonianHead_7",
	"LivonianHead_8",
	"LivonianHead_9",
	"LivonianHead_10",
	"AsianHead_A3_01",
	"AsianHead_A3_02",
	"AsianHead_A3_03",
	"AsianHead_A3_04",
	"AsianHead_A3_05",
	"AsianHead_A3_06",
	"AsianHead_A3_07",
	"TanoanHead_A3_01",
	"TanoanHead_A3_02",
	"TanoanHead_A3_03",
	"TanoanHead_A3_04",
	"TanoanHead_A3_05",
	"TanoanHead_A3_06",
	"TanoanHead_A3_07",
	"TanoanHead_A3_08",
	"Mavros",
	"Sturrock",
	"Barklem",
	"Ioannou",
	"ls_mirialan_male1_green",
	"ls_mirialan_male1_sand",
	"ls_mirialan_male1_yellow",
	"ls_mirialan_male2_green",
	"ls_mirialan_male2_sand",
	"ls_mirialan_male2_yellow",
	"ls_mirialan_male3_green",
	"ls_mirialan_male3_sand",
	"ls_mirialan_male3_yellow"
];

private _list_41alienheads = [
	"Head_AbedDark",
	"Head_AbedGrey",
	"Head_AbedPink",
	"Head_AbedYellow",
	"Head_AqualishBrown",
	"Head_AqualishGreen",
	"Head_AqualishLight",
	"Head_DurosBlue",
	"Head_DurosBlue2",
	"Head_DurosGreen",
	"Head_DurosBGrey",
	"Head_IshiGreen",
	"Head_IshiGreen2",
	"Head_IshiGreen3",
	"Head_IshiOlive",
	"Head_IshiYellow",
	"Head_KeldorYelLow",
	"Head_MimbaneseDark",
	"Head_MimbaneseLines",
	"Head_MimbaneseOrange",
	"Head_MimbaneseRed",
	"Head_NiktoBrown",
	"Head_NiktoBrown2",
	"Head_NiktoDark",
	"Head_NiktoGreen",
	"Head_NiktoGrey",
	"Head_NiktoOrange",
	"Head_QuarrenBrown",
	"Head_QuarrenPink",
	"Head_QuarrenRed",
	"Head_QuarrenYellow",
	"Head_RodianBlue",
	"Head_RodianGreen",
	"Head_RodianOlive",
	"Head_RodianRed",
	"Head_RodianYellow",
	"Head_SullustanGreen",
	"Head_SullustanGrey",
	"Head_SullustanOrange",
	"Head_SullustanSkin",
	"Head_WeequayBrown",
	"Head_WeequayDark",
	"Head_WeequayGrey",
	"Head_WeequayBod",
	"ls_zabrak_male2t0_base",
	"ls_zabrak_male1t0_orange",
	"ls_zabrak_male2t0_orange",
	"ls_zabrak_male1t0_pale",
	"ls_zabrak_male2t0_pale",
	"ls_zabrak_male1t0_red",
	"ls_zabrak_male2t0_red"
];

private _list_41hiddenheads = [
	"dev_blankFace",
	"dev_blankFace",
	"dev_blankFace"
];

private _list_41civloads_female = [

	[[],[],[],["TCGM_F_Soldier_GEN_RollUp",[[ _pocket0, _rollhigh0],[ _pocket1, _rolllow0],[ _pocket2, _rollmid0],[ _datapad0,1],[ _rich0,1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],["ACE_Chemlight_UltraHiOrange",3,1]]],["JMSLLTE_c_GenVest_blue",[["WBK_HandFlashlight",1],[ _comm0,1],["FST_blaster_cell_SSP_Yellow",5,15],[["FST_DT12_Pistol","","","",[],[],""],1]]],[],"FST_Invisible_Civ_Helm","G_Tactical_Clear",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_RoyalG_red_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],["JLTS_drugs_deathstick", _rolllow2],["JLTS_drugs_stimulant_adrenal",1],[ _rich0,1]]],["V_DeckCrew_red_F",[[ _datapad0,1],["JLTS_intel_holoProjector",1],[ _intelitem0,1],[["WBK_BrassKnuckles","","","",[],[],""],1]]],[],"FST_Invisible_Civ_Helm","G_JMSLLTE_WeqFaceFmaskRed",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_BoPilot_blue_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _pocket2, _rollmid0],[ _datapad0,1],[ _rich0,1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],["ls_holoprojector_bountyPuck",1],["FST_blaster_cell_low_yellow",5,30],[["FST_DL18_Pistol","","","",[],[],""],2]]],[],[],"JMSLLTE_CommandoH_cloud_helmet","",["FST_Black_Electrobinoculars","","","",[],[],""],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumPilot_bl_F_CombatUniform",[["FST_blaster_cell_low_yellow",3,30],[["FST_SE14R","","","3AS_Imp_Optic_SE14R",[],[],""],1]]],["JMSLLTE_Jinata_pouches",[[ _pocket0, _rolllow0],[ _pocket1, _rollmid0],[ _rich0,1],["JLTS_drugs_deathstick",1],[ _datapad0,1],["JLTS_intel_holoProjector",1],[ _intelitem0,1]]],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["ls_orsfUniform_trooper",[[ _pocket0, _rollmid0],[ _pocket1, _rollhigh0],[ _rich0,1],["JLTS_intel_holoProjector",1],["JLTS_sabacc_deck",1],[ _datapad0,1],[ _intelitem0,1],[ _intelitem1,1]]],[],["3AS_B_CloneBags_F",[["FST_blaster_cell_low_Yellow_smg",2,120],[["FST_E11P","","","",[],[],""],1]]],"JMSLLTE_OfcapR_NR_helmet","G_JMSLLTE_Facecover_dark",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_PirShirtS2_blue_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _rich0,1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1]]],["JMSLLTE_BHcomBelt_armor",[[ _datapad0,1],["FST_blaster_cell_low_yellow",5,30],[["FST_A180","","","",[],[],""],1]]],[],"JMSLLTE_PirShell_hond_helmet","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_c_genshirt_beige_F_CombatUniform",[[ _pocket0, _rollhigh0],[ _pocket1, _rolllow0],[ _rich0,1],[ _datapad0,1]]],["JMSLLTE_c_GenVest_orange",[["JLTS_drugs_deathstick",2],["ls_holoprojector_bountyPuck",1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],[ _intelitem3,1],[ _datapad1,1]]],[],"FST_Invisible_Civ_Helm","G_JMSLLTE_OfficerTrooperGlas_1",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumPart_bl_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _pocket2, _rollmid0],[ _rich0,1]]],["V_TacChestrig_cbr_F",[[ _datapad0,1],[ _intelitem0,1],["JLTS_drugs_bacta",1],["JLTS_sabacc_deck",1],["JLTS_droidCaller",1],["WBK_HandFlashlight",1],["ACE_Banana",1],["ACE_Can_RedGull",1]]],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_C_WorkerCoveralls",[[ _pocket0, _rolllow0],[ _pocket1, _rollhigh0],["JLTS_drugs_deathstick", _rolllow1],[ _rich0,1],[ _rich1,1],["JLTS_drugs_medikit",1],["JLTS_drugs_protein", _rolllow2],["IDA_BattleStim", _rolllow3],["ACE_Can_RedGull",1]]],["V_Pocketed_coyote_F",[[ _datapad0,1],["WBK_HandFlashlight_Strong",1],["ls_holoprojector_bountyPuck",1],["FST_blaster_cell_SSP_Yellow",3,15],[["FST_DL44_Pistol","","","",[],[],""],1]]],[],"JMSLLTE_CommandoH_black_helmet","OPTRE_Glasses_Cigar",[],["ItemMap","","","ItemCompass","ItemWatch","lsd_gar_alphaRangefinder_nvg"]],

	[[],[],[],["U_C_Scientist",[[ _pocket0, _rollmid0],[ _pocket1, _rollmid1],[ _pocket2, _rollhigh0],["FST_CreditChip",1],[ _rich0,1]]],["JMSLLTE_NR_pouches_w_armor",[[ _datapad0,1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],["JLTS_intel_holoProjector",1],["JLTS_drugs_protein", _rolllow0],["ACE_Sunflower_Seeds", _rolllow1],["ACE_Banana",1],["IDA_BactaBandage", _rolllow2],["ls_holoprojector_bountyPuck",1],["ACE_painkillers",1,10]]],["JLTS_B1_antenna_training",[]],"JMSLLTE_EmpOfficerCap2_white_helmet","ls_imperial_earPiece",["IDA_Electrobinoculars_Rep","","","",[],[],""],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumPilotJack_blue_F_CombatUniform",[[ _pocket0, _rollmid0],[ _pocket1, _rollmid1],[ _pocket2, _rolllow0],[ _datapad0,1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],[ _intelitem3,1],["JLTS_intel_holoProjector",1],["JLTS_drugs_deathstick",1],["FST_CreditChip",1],[ _rich0,1],["JLTS_drugs_medikit",1],["JLTS_pazaak_deck",1],["ACE_Can_RedGull",1],["ACE_Sunflower_Seeds", _rollmid2]]],[],[],"JMSLLTE_OfcapR_NR_helmet","",[],["ItemMap","","","ItemCompass","ItemWatch","JMSLLTE_NV_MechGlass"]],

	[[],[],[],["JMSLLTE_HuttSkiff_black_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rollmid0],[ _rich0,1],[ _datapad0,1],["FST_CreditChip",1],["WBK_HandFlashlight_Weak",1],[ _intelitem0,1]]],[],["JMSLLTE_back_rebpack_v1_black",[[["WBK_SciFi_Sword_1","","","",[],[],""],1],[["IDA_VibroKnife","","","",[],[],""],1]]],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumTermo_w_F_CombatUniform",[[ _pocket0, _rollmid0],[ _pocket1, _rollmid1],[ _datapad0,1],["FST_CreditChip",1],[ _rich0,1],["IDA_BattleStim", _rolllow0],[ _intelitem0,1],[ _intelitem1,1]]],["ls_gar_holster_vest",[["FST_blaster_cell_low_yellow",3,30],[["FST_Westar35","","","",[],[],""],1]]],[],"JMSLLTE_Snow_cap_helmet","3AS_G_Engineer_3_F",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["OPTRE_CPD_Uniform_Rolled",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _rich0,1],["ACE_Chemlight_HiWhite",3,1],[ _intelitem0,1],[ _intelitem1,1]]],["V_DeckCrew_white_F",[["JLTS_drugs_medikit",1],[ _datapad0,1],[ _intelitem2,1],["JLTS_droidCaller",3],["WBK_HandFlashlight",1],["ls_holoprojector_bountyPuck",1],["ACE_painkillers",1,10],[["IDA_VibroKnife","","","",[],[],""],1]]],[],"JMSLLTE_Path_1_black_cap","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumPilot_red_F_CombatUniform",[[ _datapad0,1],["FST_CreditChip",1],[ _rich0,1],["JLTS_intel_holoProjector",1],["JLTS_drugs_medikit",1],["JLTS_drugs_protein", _rolllow0],["JLTS_droidCaller",1],["ls_holoprojector_bountyPuck",1],[ _intelitem0,1],[ _intelitem1,1]]],["JMSLLTE_PilotBreather_xwing",[["FST_BreathingGas_Oxygen",2]]],[],"JMSLLTE_Commando_termo_helmet","",[],["ItemMap","","","ItemCompass","ItemWatch","JMSLLTE_NV_MechGlass"]],

	[[],[],[],["OPTRE_Ins_ER_uniform_GAgreen",[[ _datapad0,1],["JLTS_intel_holoProjector",1],["JLTS_sabacc_deck",1],[ _intelitem0,1]]],["ls_vest_flakJacket_open",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _rich0,1],["FST_CreditChip",1],[ _intelitem1,1]]],["JMSLLTE_back_stormpouches_v1",[["ACE_Can_Spirit",1],["WBK_LampItem_Green",1],["ACE_SpraypaintGreen",1],[ _intelitem2,1],[ _intelitem3,1]]],"FST_Invisible_Civ_Helm","G_Combat_Goggles_tna_F",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_HuttSkiff_black_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _datapad0,1],["JLTS_drugs_deathstick", _rollhigh0],["JLTS_pazaak_deck",1],["JLTS_sabacc_deck",1],["WBK_HeadLampItem",1],["ls_holoprojector_bountyPuck",1],["ACE_Canteen",1],[ _intelitem0,1],[ _intelitem1,1]]],[],["JMSLLTE_back_stcape_dirty",[]],"JMSLLTE_CommandoH_termo_helmet","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumNavy_red_F_CombatUniform",[[ _pocket0, _rollmid0],[ _pocket1, _rollhigh0],[ _datapad0,1],[ _rich0,1],["FST_CreditChip",1],[ _intelitem0,1],[ _intelitem1,1],["JLTS_intel_holoProjector",1]]],["JMSLLTE_StormtrooperCapeHood_armor",[["JLTS_drugs_deathstick", _rolllow0],[["IDA_VibroKnife","","","",[],[],""],1]]],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]]

];

private _list_41civloads_male = [
	
	[[],[],[],["JMSLLTE_BHcom_yel_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _pocket2, _rolllow2],["FST_CreditChip",1],[ _datapad0,1],[ _intelitem0,1],["JLTS_drugs_stimulant_hyperAdrenal",1],["WBK_ShoulderLampItem_Strong",1],["ACE_Chemlight_HiYellow",2,1],["ACE_Chemlight_HiWhite",1,1],[["WBK_BrassKnuckles","","","",[],[],""],1],[["IDA_VibroKnife","","","",[],[],""],1]]],[],["FST_B1_Antenna",[]],"H_ShemagOpen_tan","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_BHcom_green_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rollhigh0],[ _rich0,1],["JLTS_drugs_stimulant_adrenal", _rolllow1],["442_MyoplexarilStim",1],["FST_pistol_westar35sa_Mag_Yellow",2,17],[["FST_Westar35_SA_Pistol","","","",[],[],""],1]]],[],["FST_Clone_LR_attachment",[[ _datapad0,1],["JLTS_intel_holoProjector",1],["ls_holoprojector_bountyPuck",1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],[ _intelitem3,1],[["IDA_VibroKnife","","","",[],[],""],1]]],"H_Shemag_olive","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_BoPilot_blue_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rollmid0],[ _datapad0,1],[ _rich0,2],["JLTS_drugs_medikit",1],["WBK_HeadLampItem_Narrow",1],["ACE_SpraypaintBlue",1],["ACE_Chemlight_HiRed",2,1],["ACE_Chemlight_HiGreen",1,1],["FST_blaster_cell_SSP_Yellow",4,15],[["FST_K16_Pistol","","","",[],[],""],2]]],[],[],"JMSLLTE_Desert_1_helmet","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_BoPilot_blue_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _pocket2, _rollmid0],[ _datapad0,1],[ _rich0,1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],["ls_holoprojector_bountyPuck",1],["FST_blaster_cell_low_yellow",5,30],[["FST_DL18_Pistol","","","",[],[],""],2]]],[],[],"JMSLLTE_CommandoH_cloud_helmet","",["FST_Black_Electrobinoculars","","","",[],[],""],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumPilot_bl_F_CombatUniform",[["FST_blaster_cell_low_yellow",3,30],[["FST_SE14R","","","3AS_Imp_Optic_SE14R",[],[],""],1]]],["JMSLLTE_Jinata_pouches",[[ _pocket0, _rolllow0],[ _pocket1, _rollmid0],[ _rich0,1],["JLTS_drugs_deathstick",1],[ _datapad0,1],["JLTS_intel_holoProjector",1],[ _intelitem0,1]]],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["ls_orsfUniform_trooper",[[ _pocket0, _rollmid0],[ _pocket1, _rollhigh0],[ _rich0,1],["JLTS_intel_holoProjector",1],["JLTS_sabacc_deck",1],[ _datapad0,1],[ _intelitem0,1],[ _intelitem1,1]]],[],["3AS_B_CloneBags_F",[["FST_blaster_cell_low_Yellow_smg",2,120],[["FST_E11P","","","",[],[],""],1]]],"JMSLLTE_OfcapR_NR_helmet","G_JMSLLTE_Facecover_dark",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_PirShirtS2_blue_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _rich0,1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1]]],["JMSLLTE_BHcomBelt_armor",[[ _datapad0,1],["FST_blaster_cell_low_yellow",5,30],[["FST_A180","","","",[],[],""],1]]],[],"JMSLLTE_PirShell_hond_helmet","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_c_genshirt_beige_F_CombatUniform",[[ _pocket0, _rollhigh0],[ _pocket1, _rolllow0],[ _rich0,1],[ _datapad0,1]]],["JMSLLTE_c_GenVest_orange",[["JLTS_drugs_deathstick",2],["ls_holoprojector_bountyPuck",1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],[ _intelitem3,1],[ _datapad1,1]]],[],"FST_Invisible_Civ_Helm","G_JMSLLTE_OfficerTrooperGlas_1",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumPart_bl_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _pocket2, _rollmid0],[ _rich0,1]]],["V_TacChestrig_cbr_F",[[ _datapad0,1],[ _intelitem0,1],["JLTS_drugs_bacta",1],["JLTS_sabacc_deck",1],["JLTS_droidCaller",1],["WBK_HandFlashlight",1],["ACE_Banana",1],["ACE_Can_RedGull",1]]],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_C_WorkerCoveralls",[[ _pocket0, _rolllow0],[ _pocket1, _rollhigh0],["JLTS_drugs_deathstick", _rolllow1],[ _rich0,1],[ _rich1,1],["JLTS_drugs_medikit",1],["JLTS_drugs_protein", _rolllow2],["IDA_BattleStim", _rolllow3],["ACE_Can_RedGull",1]]],["V_Pocketed_coyote_F",[[ _datapad0,1],["WBK_HandFlashlight_Strong",1],["ls_holoprojector_bountyPuck",1],["FST_blaster_cell_SSP_Yellow",3,15],[["FST_DL44_Pistol","","","",[],[],""],1]]],[],"JMSLLTE_CommandoH_black_helmet","OPTRE_Glasses_Cigar",[],["ItemMap","","","ItemCompass","ItemWatch","lsd_gar_alphaRangefinder_nvg"]],

	[[],[],[],["U_C_Scientist",[[ _pocket0, _rollmid0],[ _pocket1, _rollmid1],[ _pocket2, _rollhigh0],["FST_CreditChip",1],[ _rich0,1]]],["JMSLLTE_NR_pouches_w_armor",[[ _datapad0,1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],["JLTS_intel_holoProjector",1],["JLTS_drugs_protein", _rolllow0],["ACE_Sunflower_Seeds", _rolllow1],["ACE_Banana",1],["IDA_BactaBandage", _rolllow2],["ls_holoprojector_bountyPuck",1],["ACE_painkillers",1,10]]],["JLTS_B1_antenna_training",[]],"JMSLLTE_EmpOfficerCap2_white_helmet","ls_imperial_earPiece",["IDA_Electrobinoculars_Rep","","","",[],[],""],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumPilotJack_blue_F_CombatUniform",[[ _pocket0, _rollmid0],[ _pocket1, _rollmid1],[ _pocket2, _rolllow0],[ _datapad0,1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],[ _intelitem3,1],["JLTS_intel_holoProjector",1],["JLTS_drugs_deathstick",1],["FST_CreditChip",1],[ _rich0,1],["JLTS_drugs_medikit",1],["JLTS_pazaak_deck",1],["ACE_Can_RedGull",1],["ACE_Sunflower_Seeds", _rollmid2]]],[],[],"JMSLLTE_OfcapR_NR_helmet","",[],["ItemMap","","","ItemCompass","ItemWatch","JMSLLTE_NV_MechGlass"]],

	[[],[],[],["JMSLLTE_HuttSkiff_black_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rollmid0],[ _rich0,1],[ _datapad0,1],["FST_CreditChip",1],["WBK_HandFlashlight_Weak",1],[ _intelitem0,1]]],[],["JMSLLTE_back_rebpack_v1_black",[[["WBK_SciFi_Sword_1","","","",[],[],""],1],[["IDA_VibroKnife","","","",[],[],""],1]]],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumTermo_w_F_CombatUniform",[[ _pocket0, _rollmid0],[ _pocket1, _rollmid1],[ _datapad0,1],["FST_CreditChip",1],[ _rich0,1],["IDA_BattleStim", _rolllow0],[ _intelitem0,1],[ _intelitem1,1]]],["ls_gar_holster_vest",[["FST_blaster_cell_low_yellow",3,30],[["FST_Westar35","","","",[],[],""],1]]],[],"JMSLLTE_Snow_cap_helmet","3AS_G_Engineer_3_F",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["OPTRE_CPD_Uniform_Rolled",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _rich0,1],["ACE_Chemlight_HiWhite",3,1],[ _intelitem0,1],[ _intelitem1,1]]],["V_DeckCrew_white_F",[["JLTS_drugs_medikit",1],[ _datapad0,1],[ _intelitem2,1],["JLTS_droidCaller",3],["WBK_HandFlashlight",1],["ls_holoprojector_bountyPuck",1],["ACE_painkillers",1,10],[["IDA_VibroKnife","","","",[],[],""],1]]],[],"JMSLLTE_Path_1_black_cap","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumPilot_red_F_CombatUniform",[[ _datapad0,1],["FST_CreditChip",1],[ _rich0,1],["JLTS_intel_holoProjector",1],["JLTS_drugs_medikit",1],["JLTS_drugs_protein", _rolllow0],["JLTS_droidCaller",1],["ls_holoprojector_bountyPuck",1],[ _intelitem0,1],[ _intelitem1,1]]],["JMSLLTE_PilotBreather_xwing",[["FST_BreathingGas_Oxygen",2]]],[],"JMSLLTE_Commando_termo_helmet","",[],["ItemMap","","","ItemCompass","ItemWatch","JMSLLTE_NV_MechGlass"]],

	[[],[],[],["OPTRE_Ins_ER_uniform_GAgreen",[[ _datapad0,1],["JLTS_intel_holoProjector",1],["JLTS_sabacc_deck",1],[ _intelitem0,1]]],["ls_vest_flakJacket_open",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _rich0,1],["FST_CreditChip",1],[ _intelitem1,1]]],["JMSLLTE_back_stormpouches_v1",[["ACE_Can_Spirit",1],["WBK_LampItem_Green",1],["ACE_SpraypaintGreen",1],[ _intelitem2,1],[ _intelitem3,1]]],"FST_Invisible_Civ_Helm","G_Combat_Goggles_tna_F",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_HuttSkiff_black_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _datapad0,1],["JLTS_drugs_deathstick", _rollhigh0],["JLTS_pazaak_deck",1],["JLTS_sabacc_deck",1],["WBK_HeadLampItem",1],["ls_holoprojector_bountyPuck",1],["ACE_Canteen",1],[ _intelitem0,1],[ _intelitem1,1]]],[],["JMSLLTE_back_stcape_dirty",[]],"JMSLLTE_CommandoH_termo_helmet","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumNavy_red_F_CombatUniform",[[ _pocket0, _rollmid0],[ _pocket1, _rollhigh0],[ _datapad0,1],[ _rich0,1],["FST_CreditChip",1],[ _intelitem0,1],[ _intelitem1,1],["JLTS_intel_holoProjector",1]]],["JMSLLTE_StormtrooperCapeHood_armor",[["JLTS_drugs_deathstick", _rolllow0],[["IDA_VibroKnife","","","",[],[],""],1]]],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]]

];

private _list_41civloads_alien = [

	[[],[],[],["JMSLLTE_ScumPilot_bl_F_CombatUniform",[["FST_blaster_cell_low_yellow",3,30],[["FST_SE14R","","","3AS_Imp_Optic_SE14R",[],[],""],1]]],["JMSLLTE_Jinata_pouches",[[ _pocket0, _rolllow0],[ _pocket1, _rollmid0],[ _rich0,1],["JLTS_drugs_deathstick",1],[ _datapad0,1],["JLTS_intel_holoProjector",1],[ _intelitem0,1]]],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumPart_bl_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _pocket2, _rollmid0],[ _rich0,1]]],["V_TacChestrig_cbr_F",[[ _datapad0,1],[ _intelitem0,1],["JLTS_drugs_bacta",1],["JLTS_sabacc_deck",1],["JLTS_droidCaller",1],["WBK_HandFlashlight",1],["ACE_Banana",1],["ACE_Can_RedGull",1]]],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_HuttSkiff_black_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rollmid0],[ _rich0,1],[ _datapad0,1],["FST_CreditChip",1],["WBK_HandFlashlight_Weak",1],[ _intelitem0,1]]],[],["JMSLLTE_back_rebpack_v1_black",[[["WBK_SciFi_Sword_1","","","",[],[],""],1],[["IDA_VibroKnife","","","",[],[],""],1]]],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_c_genshirt_beige_F_CombatUniform",[[ _pocket0, _rollhigh0],[ _pocket1, _rolllow0],[ _rich0,1],[ _datapad0,1]]],["JMSLLTE_c_GenVest_orange",[["JLTS_drugs_deathstick",2],["ls_holoprojector_bountyPuck",1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],[ _intelitem3,1],[ _datapad1,1]]],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["OPTRE_Ins_ER_uniform_GAgreen",[[ _datapad0,1],["JLTS_intel_holoProjector",1],["JLTS_sabacc_deck",1],[ _intelitem0,1]]],["ls_vest_flakJacket_open",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _rich0,1],["FST_CreditChip",1],[ _intelitem1,1]]],["JMSLLTE_back_stormpouches_v1",[["ACE_Can_Spirit",1],["WBK_LampItem_Green",1],["ACE_SpraypaintGreen",1],[ _intelitem2,1],[ _intelitem3,1]]],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_BoPilot_blue_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rollmid0],[ _datapad0,1],[ _rich0,2],["JLTS_drugs_medikit",1],["WBK_HeadLampItem_Narrow",1],["ACE_SpraypaintBlue",1],["ACE_Chemlight_HiRed",2,1],["ACE_Chemlight_HiGreen",1,1],["FST_blaster_cell_SSP_Yellow",4,15],[["FST_K16_Pistol","","","",[],[],""],2]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_PirShirtS2_blue_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _rich0,1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1]]],["JMSLLTE_BHcomBelt_armor",[[ _datapad0,1],["FST_blaster_cell_low_yellow",5,30],[["FST_A180","","","",[],[],""],1]]],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]]

];

private _list_41civloads_hidden = [

	[[],[],[],["U_B_PilotCoveralls",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _rich0,1],["FST_CreditChip",1],["JLTS_drugs_deathstick", _rolllow2],["JLTS_pazaak_deck",1]]],[],["DBA_Snowpack_Base",[[ _datapad0,1],["WBK_HeadLampItem_Double",1],[ _comm0,1],["FST_blaster_cell_low_yellow", _rollhigh0,30],["FST_blaster_cell_low_Yellow_smg", _rollmid0,120],[ _intelitem0,1],[ _intelitem1,1],[ _gas0,2],[["IDA_VibroKnife","","","",[],[],""],1],[["FST_DH42_Pistol","","","",[],[],""],1],[["FST_EE4","","","",[],[],""],1]]],"JMSLLTE_MercSphere_white_helmet","3AS_G_Imperial_Army_Helmet_Mask_ISB_F",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_BHcom_green_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _pocket2, _rolllow2],["ItemcTabHCam",1],["WBK_HeadLampItem_Narrow",1],["JLTS_drugs_stimulant_adrenal",1],["JLTS_drugs_deathstick", _rolllow3],["JLTS_drugs_electrolit",1],["FST_blaster_cell_low_yellow",5,30],[["FST_DL18_Pistol","","","",[],[],""],1]]],[],["FST_Backpack_Antenna_Woodland",[[ _datapad0,1],[_datapad1,1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],[ _intelitem3,1],[ _comm0,1],[ _gas0,2]]],"H_HelmetO_ViperSP_ghex_F","G_JMSLLTE_JinataTranslator",[],["ItemMap","","","ItemCompass","ItemWatch",""]],

	[[],[],[],["U_O_V_Soldier_Viper_hex_F",[[ _gas0,2]]],["k_scout_pouches_heavy_desert2",[[ _datapad0,1],[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _pocket2, _rollhigh0],["FST_CreditChip",1],["JLTS_drugs_electrolit",2],[ _intelitem0,1],["WBK_HeadLampItem_Narrow",1],["ItemcTabHCam",1],[ _comm0,1],["ToolKit",1]]],[],"JMSLLTE_MercDisk_yel_helmet","G_JMSLLTE_TrooperMask_1_black",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_O_R_Gorka_01_black_F",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _rich0,1],[ _datapad0,1],["WBK_HeadLampItem_Long",1],["ItemcTabHCam",1],[ _comm0,1],[ _intelitem0,1],[ _intelitem1,1]]],["V_RebreatherB",[[ _gas0,2]]],[],"JMSLLTE_MercDisk_black_helmet","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_O_V_Soldier_Viper_F",[[ _pocket0, _rollmid0],[ _pocket1, _rollhigh0],[ _datapad0,1],[ _rich0,1],["ItemcTabHCam",1],[ _intelitem0,1],[ _comm0,1]]],["V_RebreatherIA",[]],["3AS_B_Imperial_Stormtrooper_Backpack_Respirator_2_F",[[ _gas0,2]]],"H_PilotHelmetFighter_I_E","",[],["ItemMap","","","ItemCompass","ItemWatch",""]],

	[[],[],[],["U_C_Driver_1_white",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],["FST_CreditChip",1],[ _datapad0,1],[ _comm0,1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1]]],[],["3AS_B_ColdAssault_Backpack",[[ _gas0,2],["JLTS_pazaak_deck",1],["WBK_HeadLampItem_Long",1],["ItemcTabHCam",1],["ToolKit",1],["ACE_Chemlight_HiWhite",5,1],["FST_blaster_cell_SSP_Yellow",4,15],[["FST_DC15P","","","",[],[],""],1]]],"JMSLLTE_MercLegio_grey_helmet","3AS_G_Marksman_6_F",[],["ItemMap","","","ItemCompass","ItemWatch","IDA_41st_Clone_NVG_flipped"]],

	[[],[],[],["JMSLLTE_GuavBlack_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _datapad0,1],["FST_CreditChip",2],["JLTS_drugs_electrolit",1],[ _comm0,1],[ _comm1,1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],["WBK_HeadLampItem_Double",1],["ItemcTabHCam",1],[["WBK_SciFi_Sword_4","","","",[],[],""],1]]],[],["JMSLLTE_back_magmapack_v1",[[ _gas0,2]]],"JMSLLTE_MercSphere_black_helmet","OPTRE_CBRN",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["ls_mandalorianUniform_traditionalWoman",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _datapad0,1],[ _intelitem0,1],[ _intelitem1,1],[ _comm0,1],[["IDA_VibroKnife","","","",[],[],""],1]]],["ls_vest_holster_maroon",[[ _intelitem2,1],["FST_blaster_cell_low_yellow",4,30],[["FST_A180","","","",[],[],""],1]]],["JMSLLTE_back_jumppack_black",[[ _gas0,2]]],"ls_mandalorianHelmet_stalker","ls_glasses_scarf",[],["ItemMap","","","ItemCompass","ItemWatch","OPTRE_NVG_UL"]]

];

private _combo = [
	[_list_41femaleheads, _list_41civloads_female], 0.6,
	[_list_41maleheads, _list_41civloads_male], 0.6,
	[_list_41alienheads, _list_41civloads_alien], 0.25,
	[_list_41hiddenheads, _list_41civloads_hidden], 0.25

];

private _chosen = selectRandomWeighted _combo;
private _chosenhead = selectRandom (_chosen select 0);
private _chosenload = selectRandom (_chosen select 1);

["FST_applyIdentity", [ _unit, _chosenhead, "ACE_NoVoice"]] call CBA_fnc_globalEvent;
_unit setUnitLoadout _chosenload;


};