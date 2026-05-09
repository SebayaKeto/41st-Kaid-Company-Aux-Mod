
params ["_unit"];

if (!local _unit) exitWith {}; 

[_unit, "Civilian"] remoteExec ["setName", 0, _unit];

[_unit] spawn {

params ["_unit"];

sleep 0.05;

private _lowrollarray = [1, 0.4, 2, 0.4, 3, 0.2];
private _midrollarray = [3, 0.4, 4, 0.4, 5, 0.2];
private _highrollarray = [4, 0.2, 5, 0.4, 6, 0.3, 7, 0.1];

private _rolllow0 = selectRandomWeighted _lowrollarray;
private _rolllow1 = selectRandomWeighted _lowrollarray;
private _rolllow2 = selectRandomWeighted _lowrollarray;
private _rollmid0 = selectRandomWeighted _midrollarray;
private _rollmid1 = selectRandomWeighted _midrollarray;
private _rollhigh0 = selectRandomWeighted _highrollarray;

private _list_41creditsitemslow = [
	"JLTS_credits_10", 0.8,
	"JLTS_credits_50", 0.2,
	"JLTS_credits_100", 0.05,
	"", 0.6
];

private _pocket0 = selectRandomWeighted _list_41creditsitemslow;
private _pocket1 = selectRandomWeighted _list_41creditsitemslow;
private _pocket2 = selectRandomWeighted _list_41creditsitemslow;

private _list_41creditsitemshigh = [
	"FST_CreditChip", 0.1,
	"", 0.9
];

private _rich0 = selectRandomWeighted _list_41creditsitemshigh;

private _list_41civdatapad = [
	"FST_CivData_Normal", 0.6, 
	"FST_CivData_Abnormal", 0.02,
	"FST_CivData_Betting", 0.3,
	"FST_CivData_Bulge", 0.3,
	"FST_CivData_Cat", 0.05,
	"FST_CivData_Damage", 0.3,
	"FST_CivData_Dead", 0.3,
	"FST_CivData_Ew", 0.3,
	"FST_CivData_Idiot", 0.05,
	"FST_CivData_Illegal", 0.1,
	"FST_CivData_Interface", 0.05,
	"FST_CivData_Lang", 0.1,
	"FST_CivData_Off", 0.3,
	"FST_CivData_Old", 0.3,
	"FST_CivData_Overload", 0.3,
	"FST_CivData_Password", 0.05,
	"FST_CivData_Slow", 0.3,
	"FST_CivData_Virus", 0.3,
	"FST_CivData_Work", 0.1,
	"FST_SpaceData_Normal", 0.05,
	"FST_SpaceData_Abnormal", 0.05,
	"FST_SpaceData_Blast", 0.1,
	"FST_SpaceData_Brick", 0.1,
	"FST_SpaceData_Child", 0.05,
	"FST_SpaceData_Drop", 0.3,
	"FST_SpaceData_Oil", 0.1,
	"FST_SpaceData_Squish", 0.1,
	"FST_StylusData_Normal", 0.1,
	"FST_StylusData_Abnormal", 0.02,
	"FST_StylusData_Alien", 0.05,
	"FST_StylusData_Broken", 0.3,
	"FST_StylusData_Check", 0.05,
	"FST_StylusData_Chew", 0.3,
	"FST_StylusData_Lost", 0.1,
	"FST_StylusData_Note", 0.3,
	"FST_StylusData_Scratch", 0.3,
	"FST_StylusData_Stab", 0.3,
	"", 0.05

];

private _datapad0 = selectRandomWeighted _list_41civdatapad;

private _list_41civintelitems = [
	"FST_ReadData_Normal", 0.6,
	"FST_ReadData_Abnormal", 0.02,
	"FST_ReadData_Action", 0.1,
	"FST_ReadData_Alien", 0.1,
	"FST_ReadData_Bad", 0.3,
	"FST_ReadData_Cook", 0.1,
	"FST_ReadData_Flicker", 0.3,
	"FST_ReadData_Horror", 0.1,
	"FST_ReadData_Jedi", 0.1,
	"FST_ReadData_Love", 0.3,
	"FST_ReadData_Mystery", 0.1,
	"FST_ReadData_News", 0.3,
	"FST_ReadData_Religion", 0.3,
	"FST_ReadData_Snap", 0.3,
	"FST_ReadData_Tabloid", 0.3,
	"FST_ReadData_Youth", 0.1,
	"FST_CivDatacard_Normal", 0.3,
	"FST_CivDatacard_Abnormal", 0.02,
	"FST_CivDatacard_Broken", 0.3,
	"FST_CivDatacard_Corrupt", 0.3,
	"FST_CivDatacard_Doc", 0.1,
	"FST_CivDatacard_Empty", 0.1,
	"FST_CivDatacard_Family", 0.3,
	"FST_CivDatacard_Fiction", 0.1,
	"FST_CivDatacard_Game", 0.1,
	"FST_CivDatacard_Journal", 0.3,
	"FST_CivDatacard_Movie", 0.3,
	"FST_CivDatacard_Music", 0.1,
	"FST_CivDatacard_News", 0.3,
	"FST_CivDatacard_OwO", 0.3,
	"FST_CivDatacard_Program", 0.1,
	"FST_CivDatacard_Troll", 0.1,
	"FST_CivDatacard_Virus", 0.3,
	"FST_CivFlimsi_Normal", 0.6,
	"FST_CivFlimsi_Abnormal", 0.02,
	"FST_CivFlimsi_Ad", 0.1,
	"FST_CivFlimsi_Blank", 0.05,
	"FST_CivFlimsi_CCard", 0.05,
	"FST_CivFlimsi_Coupon", 0.3,
	"FST_CivFlimsi_Crazy", 0.3,
	"FST_CivFlimsi_Doodle", 0.1,
	"FST_CivFlimsi_Flyer", 0.3,
	"FST_CivFlimsi_Food", 0.05,
	"FST_CivFlimsi_Gross", 0.6,
	"FST_CivFlimsi_Letter", 0.1,
	"FST_CivFlimsi_Love", 0.05,
	"FST_CivFlimsi_Note", 0.3,
	"FST_CivFlimsi_Picture", 0.3,
	"FST_CivFlimsi_Receipt", 0.3,
	"FST_CivFlimsi_Stick", 0.3,
	"FST_CivFlimsi_Trash", 0.3,
	"FST_CivFlimsi_Wanted", 0.05,
	"FST_CivFlimsi_Work", 0.1,
	"FST_CivFlimsiFile_Normal", 0.1,
	"FST_CivFlimsiFile_Abnormal", 0.04,
	"FST_CivFlimsiFile_Work", 0.05,
	"FST_CivFlimsiFile_Paranoid", 0.3,
	"FST_CivFlimsiFile_Photo", 0.05,
	"FST_CivFlimsiFile_Project", 0.05,
	"FST_CivFlimsiFile_Record", 0.05,
	"FST_CivFlimsiFile_Ruin", 0.3,
	"FST_CivFlimsiFile_Um", 0.3,
	"", 0.2

];

private _intelitem0 = selectRandomWeighted _list_41civintelitems;
private _intelitem1 = selectRandomWeighted _list_41civintelitems;
private _intelitem2 = selectRandomWeighted _list_41civintelitems;
private _intelitem3 = selectRandomWeighted _list_41civintelitems;


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
	[[],[],[],["U_C_Mechanic_01_F",[[ _pocket0, _rolllow0],[ _datapad0,1],[ _intelitem0,1]]],[],[],"H_Hat_Tinfoil_F","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_PirShirt_bg_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _datapad0,1],[ _intelitem0,1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_PirShirt_white_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _datapad0,1],["ACE_Sunflower_Seeds", _rollmid0],[ _intelitem0,1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumTroopHeavy_wood_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _intelitem0,1],[ _datapad0,1],[ _rich0,1]]],[],[],"H_Cap_oli","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_BG_Guerilla3_1",[[ _pocket0, _rollhigh0],[ _pocket1, _rolllow0],[ _datapad0,1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],[ _intelitem3,1]]],[],["B_Kitbag_cbr",[["JLTS_drugs_medikit",1],["JLTS_sabacc_deck",1],["IDA_BattleStim",2],["IDA_BactaBandage",2],["ACE_Canteen",1],["ACE_Can_RedGull",2],["ACE_MRE_SteakVegetables",1],["ACE_Banana",2],["WBK_LampItem_Green",1],["dev_enzymeCapsule",2]]],"JMSLLTE_PathL_brown_cap","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_PirShirt_red_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _rich0,1],[ _datapad0,1],["JLTS_sabacc_deck",1]]],["JMSLLTE_TermoRifleVest_armor",[["ACE_Canteen",1],[ _intelitem0,1],[ _intelitem1,1]]],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumAlCommando_desert_F_CombatUniform",[[ _pocket0, _rollmid0],[ _pocket1, _rolllow0],[ _datapad0,1],[ _rich0,1]]],[],["JMSLLTE_back_rebpack_v1_desert",[["ACE_WaterBottle", _rolllow1],["ACE_MRE_SteakVegetables",2],["ACE_MRE_MeatballsPasta",2],["ACE_MRE_LambCurry",2],["ACE_MRE_CreamTomatoSoup",1],["ACE_MRE_CreamChickenSoup",3],["ACE_MRE_ChickenHerbDumplings",1],["ACE_MRE_ChickenTikkaMasala",1],["ACE_MRE_BeefStew",1],["ACE_Can_Spirit",2],["ACE_Can_Franta",2],["ACE_Can_RedGull",1],["ACE_Banana",2],["ACE_Sunflower_Seeds", _rolllow2]]],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_C_WorkerCoveralls",[[ _pocket0, _rollmid0],[ _pocket1, _rolllow0],[ _pocket2, _rolllow1],[ _datapad0,1],[ _rich0,1]]],[],["JMSLLTE_back_rebsmall_v1",[[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],["ACE_Can_RedGull",1],["ACE_Banana",1],["ACE_WaterBottle",1],["JLTS_drugs_protein", _rolllow2]]],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_PirShirtS_blue_F_CombatUniform",[[ _pocket0, _rollmid0],[ _pocket1, _rollmid1],[ _pocket2, _rolllow0]]],["JMSLLTE_CommandoBelt_armor",[[ _datapad0,1],[ _intelitem0,1],[ _intelitem1,1]]],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_O_R_Gorka_01_F",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _intelitem0,1],[ _datapad0,1],[ _rich0,1]]],[],[],"JMSLLTE_PirSkiff_helmet","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_HuttSkiff_blue_F_CombatUniform",[[ _datapad0,1],[ _intelitem0,1],[ _pocket0, _rolllow0],["IDA_BactaBandage", _rolllow1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]]

];

private _list_41civloads_male = [
	
	[[],[],[],["U_C_Mechanic_01_F",[[ _pocket0, _rolllow0],[ _datapad0,1],[ _intelitem0,1]]],[],[],"H_Hat_Tinfoil_F","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_PirShirt_bg_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _datapad0,1],[ _intelitem0,1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_PirShirt_white_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _datapad0,1],["ACE_Sunflower_Seeds", _rollmid0],[ _intelitem0,1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumTroopHeavy_wood_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _intelitem0,1],[ _datapad0,1],[ _rich0,1]]],[],[],"H_Cap_oli","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_BG_Guerilla3_1",[[ _pocket0, _rollhigh0],[ _pocket1, _rolllow0],[ _datapad0,1],[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],[ _intelitem3,1]]],[],["B_Kitbag_cbr",[["JLTS_drugs_medikit",1],["JLTS_sabacc_deck",1],["IDA_BattleStim",2],["IDA_BactaBandage",2],["ACE_Canteen",1],["ACE_Can_RedGull",2],["ACE_MRE_SteakVegetables",1],["ACE_Banana",2],["WBK_LampItem_Green",1],["dev_enzymeCapsule",2]]],"JMSLLTE_PathL_brown_cap","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_PirShirt_red_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _rich0,1],[ _datapad0,1],["JLTS_sabacc_deck",1]]],["JMSLLTE_TermoRifleVest_armor",[["ACE_Canteen",1],[ _intelitem0,1],[ _intelitem1,1]]],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumAlCommando_desert_F_CombatUniform",[[ _pocket0, _rollmid0],[ _pocket1, _rolllow0],[ _datapad0,1],[ _rich0,1]]],[],["JMSLLTE_back_rebpack_v1_desert",[["ACE_WaterBottle", _rolllow1],["ACE_MRE_SteakVegetables",2],["ACE_MRE_MeatballsPasta",2],["ACE_MRE_LambCurry",2],["ACE_MRE_CreamTomatoSoup",1],["ACE_MRE_CreamChickenSoup",3],["ACE_MRE_ChickenHerbDumplings",1],["ACE_MRE_ChickenTikkaMasala",1],["ACE_MRE_BeefStew",1],["ACE_Can_Spirit",2],["ACE_Can_Franta",2],["ACE_Can_RedGull",1],["ACE_Banana",2],["ACE_Sunflower_Seeds", _rolllow2]]],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_C_WorkerCoveralls",[[ _pocket0, _rollmid0],[ _pocket1, _rolllow0],[ _pocket2, _rolllow1],[ _datapad0,1],[ _rich0,1]]],[],["JMSLLTE_back_rebsmall_v1",[[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],["ACE_Can_RedGull",1],["ACE_Banana",1],["ACE_WaterBottle",1],["JLTS_drugs_protein", _rolllow2]]],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_PirShirtS_blue_F_CombatUniform",[[ _pocket0, _rollmid0],[ _pocket1, _rollmid1],[ _pocket2, _rolllow0]]],["JMSLLTE_CommandoBelt_armor",[[ _datapad0,1],[ _intelitem0,1],[ _intelitem1,1]]],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_O_R_Gorka_01_F",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _intelitem0,1],[ _datapad0,1],[ _rich0,1]]],[],[],"JMSLLTE_PirSkiff_helmet","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_HuttSkiff_blue_F_CombatUniform",[[ _datapad0,1],[ _intelitem0,1],[ _pocket0, _rolllow0],["IDA_BactaBandage", _rolllow1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]]

];

private _list_41civloads_alien = [

	[[],[],[],["JMSLLTE_PirShirt_bg_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _datapad0,1],[ _intelitem0,1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_PirShirt_white_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _datapad0,1],["ACE_Sunflower_Seeds", _rollmid0],[ _intelitem0,1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_PirShirt_red_F_CombatUniform",[[ _pocket0, _rolllow0],[ _pocket1, _rolllow1],[ _rich0,1],[ _datapad0,1],["JLTS_sabacc_deck",1]]],["JMSLLTE_TermoRifleVest_armor",[["ACE_Canteen",1],[ _intelitem0,1],[ _intelitem1,1]]],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_ScumAlCommando_desert_F_CombatUniform",[[ _pocket0, _rollmid0],[ _pocket1, _rolllow0],[ _datapad0,1],[ _rich0,1]]],[],["JMSLLTE_back_rebpack_v1_desert",[["ACE_WaterBottle", _rolllow1],["ACE_MRE_SteakVegetables",2],["ACE_MRE_MeatballsPasta",2],["ACE_MRE_LambCurry",2],["ACE_MRE_CreamTomatoSoup",1],["ACE_MRE_CreamChickenSoup",3],["ACE_MRE_ChickenHerbDumplings",1],["ACE_MRE_ChickenTikkaMasala",1],["ACE_MRE_BeefStew",1],["ACE_Can_Spirit",2],["ACE_Can_Franta",2],["ACE_Can_RedGull",1],["ACE_Banana",2],["ACE_Sunflower_Seeds", _rolllow2]]],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["U_C_WorkerCoveralls",[[ _pocket0, _rollmid0],[ _pocket1, _rolllow0],[ _pocket2, _rolllow1],[ _datapad0,1],[ _rich0,1]]],[],["JMSLLTE_back_rebsmall_v1",[[ _intelitem0,1],[ _intelitem1,1],[ _intelitem2,1],["ACE_Can_RedGull",1],["ACE_Banana",1],["ACE_WaterBottle",1],["JLTS_drugs_protein", _rolllow2]]],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_PirShirtS_blue_F_CombatUniform",[[ _pocket0, _rollmid0],[ _pocket1, _rollmid1],[ _pocket2, _rolllow0]]],["JMSLLTE_CommandoBelt_armor",[[ _datapad0,1],[ _intelitem0,1],[ _intelitem1,1]]],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]],

	[[],[],[],["JMSLLTE_HuttSkiff_blue_F_CombatUniform",[[ _datapad0,1],[ _intelitem0,1],[ _pocket0, _rolllow0],["IDA_BactaBandage", _rolllow1]]],[],[],"FST_Invisible_Civ_Helm","",[],["ItemMap","","","ItemCompass","ItemWatch","k_nvg_ti"]]

];

private _combo = [
	[_list_41femaleheads, _list_41civloads_female],
	[_list_41maleheads, _list_41civloads_male],
	[_list_41alienheads, _list_41civloads_alien]

];

private _chosen = selectRandom _combo;
private _chosenhead = selectRandom (_chosen select 0);
private _chosenload = selectRandom (_chosen select 1);

[_unit, _chosenhead] remoteExec ["setFace", 0, _unit];
[_unit, "ACE_NoVoice"] remoteExec ["setSpeaker", 0, _unit];
_unit setUnitLoadout _chosenload;


};