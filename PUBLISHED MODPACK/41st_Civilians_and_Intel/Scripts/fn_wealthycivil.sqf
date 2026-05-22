
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
private _rollmid0 = selectRandomWeighted _midrollarray;
private _rollmid1 = selectRandomWeighted _midrollarray;
private _rollmid2 = selectRandomWeighted _midrollarray;
private _rollhigh0 = selectRandomWeighted _highrollarray;
private _rollhigh1 = selectRandomWeighted _highrollarray;

private _list_41creditsitemslow = [
	"JLTS_credits_10", 0.2,
	"JLTS_credits_50", 0.6,
	"JLTS_credits_100", 0.6,
	"", 0.1
];

private _pocket0 = selectRandomWeighted _list_41creditsitemslow;
private _pocket1 = selectRandomWeighted _list_41creditsitemslow;
private _pocket2 = selectRandomWeighted _list_41creditsitemslow;

private _list_41creditsitemshigh = [
	"FST_CreditChip", 0.6,
	"JLTS_credits_500", 0.4,
	"JLTS_credits_1000", 0.1,
	"JLTS_credits_5000", 0.05
];

private _rich0 = selectRandomWeighted _list_41creditsitemshigh;
private _rich1 = selectRandomWeighted _list_41creditsitemshigh;
private _rich2 = selectRandomWeighted _list_41creditsitemshigh;

private _list_41creditcases = [
	"", 0.2,
	"FST_CreditCase_Lock", 0.6,
	"FST_CreditCase_Chip", 0.1,
	"FST_CreditCase_Low", 0.4,
	"FST_CreditCase_Med", 0.3,
	"FST_CreditCase_High", 0.1,
	"FST_CreditCase_Rare", 0.05
];

private _case0 = selectRandomWeighted _list_41creditcases;
private _case1 = selectRandomWeighted _list_41creditcases;

private _list_41civdatapad = [
	"FST_CivData_Normal", 0.6, 
	"FST_CivData_Abnormal", 0.04,
	"FST_CivData_Betting", 0.3,
	"FST_CivData_Cat", 0.1,
	"FST_CivData_Costly", 0.3,
	"FST_CivData_Gamer", 0.1,
	"FST_CivData_Idiot", 0.5,
	"FST_CivData_Illegal", 0.3,
	"FST_CivData_Interface", 0.05,
	"FST_CivData_IR", 0.05,
	"FST_CivData_Lang", 0.3,
	"FST_CivData_Meme", 0.05,
	"FST_CivData_Off", 0.1,
	"FST_CivData_Selfie", 0.3,
	"FST_CivData_UV", 0.05,
	"FST_CivData_UwU", 0.1,
	"FST_CivData_Work", 0.3,
	"FST_SpaceData_Normal", 0.1,
	"FST_SpaceData_Abnormal", 0.05,
	"FST_SpaceData_Aqua", 0.05,
	"FST_SpaceData_Chem", 0.1,
	"FST_SpaceData_Child", 0.3,
	"FST_SpaceData_Fire", 0.05,
	"FST_StylusData_Normal", 0.6,
	"FST_StylusData_Abnormal", 0.04,
	"FST_StylusData_Alien", 0.1,
	"FST_StylusData_Check", 0.3,
	"FST_StylusData_Chew", 0.05,
	"FST_StylusData_Draw", 0.1,
	"FST_StylusData_Form", 0.1,
	"FST_StylusData_Game", 0.3,
	"FST_StylusData_Lost", 0.1,
	"FST_StylusData_Note", 0.3,
	"FST_CivMiniData_Normal", 0.6,
	"FST_CivMiniData_Abnormal", 0.04,
	"FST_CivMiniData_Built", 0.05,
	"FST_CivMiniData_Camera", 0.3,
	"FST_CivMiniData_Chem", 0.05,
	"FST_CivMiniData_Droid", 0.05,
	"FST_CivMiniData_GPS", 0.1,
	"FST_CivMiniData_Huh", 0.05,
	"FST_CivMiniData_Music", 0.3,
	"FST_CivMiniData_Notes", 0.3

];

private _datapad0 = selectRandomWeighted _list_41civdatapad;
private _datapad1 = selectRandomWeighted _list_41civdatapad;

private _list_41civintelitems = [
	"FST_ReadData_Normal", 0.6,
	"FST_ReadData_Abnormal", 0.04,
	"FST_ReadData_Action", 0.3,
	"FST_ReadData_Alien", 0.1,
	"FST_ReadData_Bad", 0.1,
	"FST_ReadData_Bio", 0.3,
	"FST_ReadData_Boring", 0.3,
	"FST_ReadData_Cook", 0.05,
	"FST_ReadData_Horror", 0.1,
	"FST_ReadData_Jedi", 0.3,
	"FST_ReadData_Legal", 0.3,
	"FST_ReadData_Love", 0.3,
	"FST_ReadData_Medical", 0.05,
	"FST_ReadData_Mystery", 0.3,
	"FST_ReadData_News", 0.3,
	"FST_ReadData_Report", 0.3,
	"FST_ReadData_Tabloid", 0.3,
	"FST_ReadData_Text", 0.1,
	"FST_ReadData_Youth", 0.1,
	"FST_CivDatacard_Normal", 0.6,
	"FST_CivDatacard_Abnormal", 0.04,
	"FST_CivDatacard_Blueprint", 0.1,
	"FST_CivDatacard_Calendar", 0.3,
	"FST_CivDatacard_Care", 0.3,
	"FST_CivDatacard_Doc", 0.3,
	"FST_CivDatacard_Family", 0.05,
	"FST_CivDatacard_Fiction", 0.05,
	"FST_CivDatacard_Game", 0.3,
	"FST_CivDatacard_Medical", 0.1,
	"FST_CivDatacard_Money", 0.3,
	"FST_CivDatacard_Mouse", 0.05,
	"FST_CivDatacard_Movie", 0.3,
	"FST_CivDatacard_Music", 0.3,
	"FST_CivDatacard_News", 0.3,
	"FST_CivDatacard_OwO", 0.05,
	"FST_CivDatacard_Program", 0.05,
	"FST_CivDatacard_Report", 0.3,
	"FST_CivDatacard_Tax", 0.3,
	"FST_CivFlimsi_Normal", 0.3,
	"FST_CivFlimsi_Abnormal", 0.04,
	"FST_CivFlimsi_BCard", 0.3,
	"FST_CivFlimsi_Blank", 0.1,
	"FST_CivFlimsi_CCard", 0.05,
	"FST_CivFlimsi_Doc", 0.3,
	"FST_CivFlimsi_Flyer", 0.05,
	"FST_CivFlimsi_Form", 0.3,
	"FST_CivFlimsi_Letter", 0.05,
	"FST_CivFlimsi_List", 0.3,
	"FST_CivFlimsi_Love", 0.05,
	"FST_CivFlimsi_Note", 0.3,
	"FST_CivFlimsi_Picture", 0.05,
	"FST_CivFlimsi_Receipt", 0.3,
	"FST_CivFlimsi_Starchart", 0.05,
	"FST_CivFlimsi_Wanted", 0.05,
	"FST_CivFlimsi_Work", 0.05,
	"FST_CivFlimsiFile_Normal", 0.6,
	"FST_CivFlimsiFile_Abnormal", 0.04,
	"FST_CivFlimsiFile_Alien", 0.3,
	"FST_CivFlimsiFile_Taxes", 0.3,
	"FST_CivFlimsiFile_Work", 0.3,
	"FST_CivFlimsiFile_Med", 0.05,
	"FST_CivFlimsiFile_Order", 0.3,
	"FST_CivFlimsiFile_Photo", 0.05,
	"FST_CivFlimsiFile_Plan", 0.3,
	"FST_CivFlimsiFile_Police", 0.05,
	"FST_CivFlimsiFile_Profile", 0.05,
	"FST_CivFlimsiFile_Project", 0.3,
	"FST_CivFlimsiFile_Law", 0.3,
	"FST_CivFlimsiFile_Transport", 0.3,
	"FST_CivFlimsiFile_Record", 0.1,
	"FST_CivFlimsiFile_Starchart", 0.05,
	"FST_CivFlimsiFile_Starship", 0.05,
	"FST_CivHoloprojector_Normal", 0.6,
	"FST_CivHoloprojector_Abnormal", 0.04,
	"FST_CivHoloprojector_Alien", 0.05,
	"FST_CivHoloprojector_Beast", 0.3,
	"FST_CivHoloprojector_Blueprint", 0.1,
	"FST_CivHoloprojector_Design", 0.1,
	"FST_CivHoloprojector_Galaxy", 0.1,
	"FST_CivHoloprojector_Game", 0.3,
	"FST_CivHoloprojector_Ha", 0.05,
	"FST_CivHoloprojector_Land", 0.05,
	"FST_CivHoloprojector_Manual", 0.1,
	"FST_CivHoloprojector_Map", 0.1,
	"FST_CivHoloprojector_Movie", 0.3,
	"FST_CivHoloprojector_OwO", 0.05,
	"FST_CivHoloprojector_Solar", 0.05,
	"FST_CivHoloprojector_Record", 0.05,
	"FST_CivHoloprojector_Route", 0.05,
	"FST_CivHoloprojector_Sport", 0.3,
	"FST_CivHoloprojector_Video", 0.1,
	"FST_TrackingFob_Normal", 0.1,
	"FST_TrackingFob_Abnormal", 0.04,
	"FST_TrackingFob_Here", 0.05,
	"FST_TrackingFob_Huh", 0.05,
	"FST_TrackingFob_Items", 0.3,
	"FST_TrackingFob_Orbit", 0.05,
	"FST_TrackingFob_Partner", 0.3,
	"FST_TrackingFob_Pet", 0.3,
	"FST_TrackingFob_Planet", 0.05,
	"FST_TrackingFob_Range", 0.05

];

private _intelitem0 = selectRandomWeighted _list_41civintelitems;
private _intelitem1 = selectRandomWeighted _list_41civintelitems;
private _intelitem2 = selectRandomWeighted _list_41civintelitems;
private _intelitem3 = selectRandomWeighted _list_41civintelitems;

private _list_41civcomms = [
	"FST_HoloComm_Normal", 2,
	"FST_HoloComm_Abnormal", 0.04,
	"FST_HandComm_Normal", 0.5,
	"FST_HandComm_Abnormal", 0.04,
	"FST_FlatComm_Normal", 1,
	"FST_FlatComm_Abnormal", 0.04

];

private _comm0 = selectRandomWeighted _list_41civcomms;

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

private _list_41civloads_female = [

	[[],[],[],["JMSLLTE_PirCapt_hond_F_CombatUniform",[[ _pocket0, _rollhigh0],[ _pocket1, _rollhigh1],[ _pocket2, _rollmid0],[ _datapad0,1],[ _datapad1,1],[ _rich0, _rolllow0],[ _rich1, _rolllow1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],[ _intelitem3,1],[ _comm0,1],[ _case0,1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],
	
	[[],[],[],["JMSLLTE_PirCapt_black_F_CombatUniform",[[ _pocket0, _rollhigh0],[ _pocket1, _rollhigh1],[ _pocket2, _rollmid0],[ _datapad0,1],[ _datapad1,1],[ _rich0, _rolllow0],[ _rich1, _rolllow1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],[ _intelitem3,1],[ _comm0,1],[ _case0,1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_C_FormalSuit_01_tshirt_gray_F",[[ _pocket0, _rollmid0],[ _pocket1, _rollhigh0],[ _datapad0,1],[ _rich0, _rolllow0],[ _rich1, _rolllow1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],["FST_CreditChip",1],[ _comm0,1]]],[],[],"FST_Invisible_Civ_Helm","G_Squares_Tinted",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_C_FormalSuit_01_tshirt_black_F",[[ _datapad0,1],[ _datapad1,1],[ _rich0, _rolllow0],[ _rich1, _rolllow1],[ _comm0,1]]],["FST_Vest_Base",[[ _case0,1],[ _case1,1]]],[],"FST_Invisible_Civ_Helm","OPTRE_HUD_r_Glasses",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["OPTRE_Ins_ER_rolled_OD_crimson",[[ _datapad0,1],["JLTS_drugs_deathstick", _rolllow0],[ _intelitem0,1],[ _comm0,1]]],[],["JLTS_Clone_belt_bag",[["JLTS_sabacc_deck",1],["JLTS_pazaak_deck",1],[ _rich0, _rollmid0],[ _rich1, _rollmid1],[ _pocket0, _rollhigh0],[ _pocket1, _rollhigh1],[ _pocket2, _rollmid2],[ _case0,1]]],"FST_Invisible_Civ_Helm","G_JMSLLTE_WeqGlas",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["OPTRE_Ins_URF_Combat_Flat_Uniform",[[ _pocket0, _rollhigh0],[ _rich0, _rollmid0],[ _datapad0,1],["FST_CreditChip",1],[ _comm0,1],[["Knife_m3","","","",[],[],""],1]]],[],[],"H_Beret_blk","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumCommando_green_F_CombatUniform",[[ _pocket0, _rollhigh0],[ _pocket1, _rollhigh1],[ _datapad0,1],[ _datapad1,1],[ _comm0,1],["FST_CreditChip",1],[ _rich0, _rolllow0]]],[],["OPTRE_ONI_Researcher_Suitcase",[[ _case0,1],[ _case1,1],[ _intelitem0,1],[ _intelitem1,1]]],"FIR_GroundCrew_Headset","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_RoyalG_black_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _datapad0,1],[ _rich0, _rolllow0],[ _rich1, _rolllow1],[ _intelitem0,1],[ _intelitem1,1],[ _comm0,1]]],[],[],"FST_Invisible_Civ_Helm","G_Bandanna_blk",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_C_E_LooterJacket_01_F",[[ _pocket0, _rollmid0],[ _pocket1, _rollmid1],[ _datapad0,1],[ _rich0, _rolllow0],[ _rich1, _rolllow1],[ "FST_CreditChip",1],["JLTS_drugs_protein", _rollhigh0],[ _comm0,1],[["Knife_m3","","","",[],[],""],1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]]

];

private _list_41civloads_male = [
	
	[[],[],[],["JMSLLTE_PirCapt_hond_F_CombatUniform",[[ _pocket0, _rollhigh0],[ _pocket1, _rollhigh1],[ _pocket2, _rollmid0],[ _datapad0,1],[ _datapad1,1],[ _rich0, _rolllow0],[ _rich1, _rolllow1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],[ _intelitem3,1],[ _comm0,1],[ _case0,1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],
	
	[[],[],[],["JMSLLTE_PirCapt_black_F_CombatUniform",[[ _pocket0, _rollhigh0],[ _pocket1, _rollhigh1],[ _pocket2, _rollmid0],[ _datapad0,1],[ _datapad1,1],[ _rich0, _rolllow0],[ _rich1, _rolllow1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],[ _intelitem3,1],[ _comm0,1],[ _case0,1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_C_FormalSuit_01_tshirt_gray_F",[[ _pocket0, _rollmid0],[ _pocket1, _rollhigh0],[ _datapad0,1],[ _rich0, _rolllow0],[ _rich1, _rolllow1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],["FST_CreditChip",1],[ _comm0,1]]],[],[],"FST_Invisible_Civ_Helm","G_Squares_Tinted",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_C_FormalSuit_01_tshirt_black_F",[[ _datapad0,1],[ _datapad1,1],[ _rich0, _rolllow0],[ _rich1, _rolllow1],[ _comm0,1]]],["FST_Vest_Base",[[ _case0,1],[ _case1,1]]],[],"FST_Invisible_Civ_Helm","OPTRE_HUD_r_Glasses",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["OPTRE_Ins_ER_rolled_OD_crimson",[[ _datapad0,1],["JLTS_drugs_deathstick", _rolllow0],[ _intelitem0,1],[ _comm0,1]]],[],["JLTS_Clone_belt_bag",[["JLTS_sabacc_deck",1],["JLTS_pazaak_deck",1],[ _rich0, _rollmid0],[ _rich1, _rollmid1],[ _pocket0, _rollhigh0],[ _pocket1, _rollhigh1],[ _pocket2, _rollmid2],[ _case0,1]]],"FST_Invisible_Civ_Helm","G_JMSLLTE_WeqGlas",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["OPTRE_Ins_URF_Combat_Flat_Uniform",[[ _pocket0, _rollhigh0],[ _rich0, _rollmid0],[ _datapad0,1],["FST_CreditChip",1],[ _comm0,1],[["Knife_m3","","","",[],[],""],1]]],[],[],"H_Beret_blk","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumCommando_green_F_CombatUniform",[[ _pocket0, _rollhigh0],[ _pocket1, _rollhigh1],[ _datapad0,1],[ _datapad1,1],[ _comm0,1],["FST_CreditChip",1],[ _rich0, _rolllow0]]],[],["OPTRE_ONI_Researcher_Suitcase",[[ _case0,1],[ _case1,1],[ _intelitem0,1],[ _intelitem1,1]]],"FIR_GroundCrew_Headset","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_RoyalG_black_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _datapad0,1],[ _rich0, _rolllow0],[ _rich1, _rolllow1],[ _intelitem0,1],[ _intelitem1,1],[ _comm0,1]]],[],[],"FST_Invisible_Civ_Helm","G_Bandanna_blk",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_C_E_LooterJacket_01_F",[[ _pocket0, _rollmid0],[ _pocket1, _rollmid1],[ _datapad0,1],[ _rich0, _rolllow0],[ _rich1, _rolllow1],[ "FST_CreditChip",1],["JLTS_drugs_protein", _rollhigh0],[ _comm0,1],[["Knife_m3","","","",[],[],""],1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]]

];

private _list_41civloads_alien = [

	[[],[],[],["JMSLLTE_PirCapt_hond_F_CombatUniform",[[ _pocket0, _rollhigh0],[ _pocket1, _rollhigh1],[ _pocket2, _rollmid0],[ _datapad0,1],[ _datapad1,1],[ _rich0, _rolllow0],[ _rich1, _rolllow1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],[ _intelitem3,1],[ _comm0,1],[ _case0,1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],
	
	[[],[],[],["JMSLLTE_PirCapt_black_F_CombatUniform",[[ _pocket0, _rollhigh0],[ _pocket1, _rollhigh1],[ _pocket2, _rollmid0],[ _datapad0,1],[ _datapad1,1],[ _rich0, _rolllow0],[ _rich1, _rolllow1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],[ _intelitem3,1],[ _comm0,1],[ _case0,1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_C_FormalSuit_01_tshirt_gray_F",[[ _pocket0, _rollmid0],[ _pocket1, _rollhigh0],[ _datapad0,1],[ _rich0, _rolllow0],[ _rich1, _rolllow1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],["FST_CreditChip",1],[ _comm0,1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_C_FormalSuit_01_tshirt_black_F",[[ _datapad0,1],[ _datapad1,1],[ _rich0, _rolllow0],[ _rich1, _rolllow1],[ _comm0,1]]],["FST_Vest_Base",[[ _case0,1],[ _case1,1]]],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["OPTRE_Ins_ER_rolled_OD_crimson",[[ _datapad0,1],["JLTS_drugs_deathstick", _rolllow0],[ _intelitem0,1],[ _comm0,1]]],[],["JLTS_Clone_belt_bag",[["JLTS_sabacc_deck",1],["JLTS_pazaak_deck",1],[ _rich0, _rollmid0],[ _rich1, _rollmid1],[ _pocket0, _rollhigh0],[ _pocket1, _rollhigh1],[ _pocket2, _rollmid2],[ _case0,1]]],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_C_E_LooterJacket_01_F",[[ _pocket0, _rollmid0],[ _pocket1, _rollmid1],[ _datapad0,1],[ _rich0, _rolllow0],[ _rich1, _rolllow1],[ "FST_CreditChip",1],["JLTS_drugs_protein", _rollhigh0],[ _comm0,1],[["Knife_m3","","","",[],[],""],1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]]

];

private _combo = [
	[_list_41femaleheads, _list_41civloads_female],
	[_list_41maleheads, _list_41civloads_male],
	[_list_41alienheads, _list_41civloads_alien]

];

private _chosen = selectRandom _combo;
private _chosenhead = selectRandom (_chosen select 0);
private _chosenload = selectRandom (_chosen select 1);

["FST_applyIdentity", [ _unit, _chosenhead, "ACE_NoVoice"]] call CBA_fnc_globalEvent;
_unit setUnitLoadout _chosenload;


};