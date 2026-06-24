
params ["_unit"];

if (isNull _unit) exitWith {};
if (!local _unit) exitWith {}; 

if (_unit getVariable ["FST_Initialized", false]) exitWith {};
_unit setVariable ["FST_Initialized", true, true];

["FST_applyName", [ _unit, "Nyvar Insurgent Trooper"]] call CBA_fnc_globalEvent;

[_unit] spawn {

params ["_unit"];

if (isNull _unit) exitWith {};

sleep 0.05;

if (isNull _unit) exitWith {};
if (!local _unit) exitWith {};

private _list_41nyvarhumanheads = [
	"TCGM_Fem_Zhu",
	"TCGM_MakF_ZhuClub1",
	"TCGM_Fem_StoneBun",
    "TCGM_MakF_StoneClub1",
	"TCGM_Fem_FoxBun",
	"TCGM_Fem_EilishBun",
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
	"Ioannou"

];

private _list_41nyvardatapad = [
	"FST_CivData_Normal", 0.5, 
	"FST_CivData_Abnormal", 0.15,
	"FST_CivData_Betting", 0.02,
	"FST_CivData_Bulge", 0.02,
	"FST_CivData_Cat", 0.1,
	"FST_CivData_Damage", 0.1,
	"FST_CivData_Dead", 0.02,
	"FST_CivData_Gamer", 0.1,
	"FST_CivData_Idiot", 0.1,
	"FST_CivData_Illegal", 0.1,
	"FST_CivData_Interface", 0.02,
	"FST_CivData_Meme", 0.1,
	"FST_CivData_Off", 0.1,
	"FST_CivData_Overload", 0.1,
	"FST_CivData_Selfie", 0.1,
	"FST_CivData_Slow", 0.02,
	"FST_CivData_UwU", 0.02,
	"FST_CivData_Virus", 0.02,
	"FST_SpaceData_Normal", 0.5,
	"FST_SpaceData_Abnormal", 0.15,
	"FST_SpaceData_Aqua", 0.02,
	"FST_SpaceData_Blast", 0.1,
	"FST_SpaceData_Brick", 0.02,
	"FST_SpaceData_Droid", 0.1,
	"FST_SpaceData_Drop", 0.1,
	"FST_SpaceData_Fire", 0.02,
	"FST_SpaceData_Oil", 0.02,
	"FST_SpaceData_Press", 0.02,
	"FST_SpaceData_Squish", 0.02,
	"FST_StylusData_Normal", 0.5,
	"FST_StylusData_Abnormal", 0.15,
	"FST_StylusData_Check", 0.1,
	"FST_StylusData_Chew", 0.02,
	"FST_StylusData_Form", 0.02,
	"FST_StylusData_Game", 0.1,
	"FST_StylusData_Lost", 0.02,
	"FST_StylusData_Note", 0.02,
	"FST_StylusData_Scratch", 0.02,
	"FST_CivMiniData_Normal", 0.5,
	"FST_CivMiniData_Abnormal", 0.15,
	"FST_CivMiniData_Atmos", 0.02,
	"FST_CivMiniData_Broken", 0.02,
	"FST_CivMiniData_Built", 0.02,
	"FST_CivMiniData_Camera", 0.1,
	"FST_CivMiniData_Diagnose", 0.02,
	"FST_CivMiniData_Droid", 0.02,
	"FST_CivMiniData_GPS", 0.1,
	"FST_CivMiniData_Huh", 0.02,
	"FST_CivMiniData_Music", 0.1,
	"FST_CivMiniData_Notes", 0.02,
	"FST_CivMiniData_Radio", 0.02,
	"FST_CivMiniData_Shot", 0.3

];

private _list_41nyvarintelitems = [
	"FST_ReadData_Normal", 0.5,
	"FST_ReadData_Abnormal", 0.15,
	"FST_ReadData_Action", 0.1,
	"FST_ReadData_Bad", 0.1,
	"FST_ReadData_Bio", 0.02,
	"FST_ReadData_Boring", 0.1,
	"FST_ReadData_Cook", 0.02,
	"FST_ReadData_Droid", 0.1,
	"FST_ReadData_Flicker", 0.02,
	"FST_ReadData_Horror", 0.1,
	"FST_ReadData_Jedi", 0.1,
	"FST_ReadData_Love", 0.1,
	"FST_ReadData_Mystery", 0.1,
	"FST_ReadData_News", 0.1,
	"FST_ReadData_Religion", 0.02,
	"FST_ReadData_Snap", 0.02,
	"FST_ReadData_Tabloid", 0.1,
	"FST_ReadData_Text", 0.02,
	"FST_ReadData_Youth", 0.1,
	"FST_CivDatacard_Normal", 0.5,
	"FST_CivDatacard_Abnormal", 0.15,
	"FST_CivDatacard_Blueprint", 0.02,
	"FST_CivDatacard_Calendar", 0.1,
	"FST_CivDatacard_Care", 0.02,
	"FST_CivDatacard_Corrupt", 0.02,
	"FST_CivDatacard_Empty", 0.02,
	"FST_CivDatacard_Family", 0.3,
	"FST_CivDatacard_Fiction", 0.1,
	"FST_CivDatacard_Game", 0.1,
	"FST_CivDatacard_Journal", 0.1,
	"FST_CivDatacard_Manual", 0.02,
	"FST_CivDatacard_Mouse", 0.1,
	"FST_CivDatacard_Movie", 0.1,
	"FST_CivDatacard_Music", 0.02,
	"FST_CivDatacard_News", 0.1,
	"FST_CivDatacard_OwO", 0.02,
	"FST_CivDatacard_Program", 0.02,
	"FST_CivDatacard_Troll", 0.02,
	"FST_CivDatacard_Virus", 0.1,
	"FST_CivDataCrystal_Normal", 0.5,
	"FST_CivDataCrystal_Abnormal", 0.15,
	"FST_CivDataCrystal_Format", 0.02,
	"FST_CivDataCrystal_Galaxy", 0.02,
	"FST_CivDataCrystal_Library", 0.1,
	"FST_CivDataCrystal_Media", 0.1,
	"FST_CivDataCrystal_Melt", 0.5,
	"FST_CivDataCrystal_Planet", 0.5,
	"FST_CivDataCrystal_Rock", 0.5,
	"FST_CivDataCrystal_Shattered", 0.5,
	"FST_CivDataCrystal_Stun", 0.5,
	"FST_CivFlimsi_Normal", 0.5,
	"FST_CivFlimsi_Abnormal", 0.15,
	"FST_CivFlimsi_Blank", 0.1,
	"FST_CivFlimsi_CCard", 0.02,
	"FST_CivFlimsi_Doc", 0.1,
	"FST_CivFlimsi_Doodle", 0.1,
	"FST_CivFlimsi_Flyer", 0.02,
	"FST_CivFlimsi_Form", 0.1,
	"FST_CivFlimsi_Gross", 0.02,
	"FST_CivFlimsi_Letter", 0.02,
	"FST_CivFlimsi_List", 0.1,
	"FST_CivFlimsi_Love", 0.02,
	"FST_CivFlimsi_Note", 0.02,
	"FST_CivFlimsi_Picture", 0.02,
	"FST_CivFlimsi_Receipt", 0.02,
	"FST_CivFlimsi_Starchart", 0.02,
	"FST_CivFlimsi_Stick2", 0.1,
	"FST_CivFlimsi_Trash", 0.02,
	"FST_CivFlimsi_Wanted", 0.02,
	"FST_CivFlimsi_Work", 0.1,
	"FST_CivFlimsiFile_Normal", 0.5,
	"FST_CivFlimsiFile_Abnormal", 0.15,
	"FST_CivFlimsiFile_Work", 0.1,
	"FST_CivFlimsiFile_Photo", 0.02,
	"FST_CivFlimsiFile_Police", 0.02,
	"FST_CivFlimsiFile_Profile", 0.1,
	"FST_CivFlimsiFile_Project", 0.1,
	"FST_CivFlimsiFile_Law", 0.02,
	"FST_CivFlimsiFile_Record", 0.02,
	"FST_CivFlimsiFile_Starchart", 0.02,
	"FST_CivHoloprojector_Normal", 0.5,
	"FST_CivHoloprojector_Abnormal", 0.15,
	"FST_CivHoloprojector_Beast", 0.1,
	"FST_CivHoloprojector_Blueprint", 0.02,
	"FST_CivHoloprojector_Broken", 0.02,
	"FST_CivHoloprojector_Galaxy", 0.02,
	"FST_CivHoloprojector_Game", 0.1,
	"FST_CivHoloprojector_Land", 0.5,
	"FST_CivHoloprojector_Map", 0.1,
	"FST_CivHoloprojector_Movie", 0.1,
	"FST_CivHoloprojector_OwO", 0.02,
	"FST_CivHoloprojector_Record", 0.02,
	"FST_CivHoloprojector_Solar", 0.02,
	"FST_CivHoloprojector_Sport", 0.1,
	"FST_CivHoloprojector_Video", 0.1,
	"", 6

];

private _list_41nyvarcomms = [
	"FST_HoloComm_Normal", 0.05,
	"FST_HoloComm_Abnormal", 0.1,
	"FST_HandComm_Normal", 0.5,
	"FST_HandComm_Abnormal", 0.15,
	"FST_FlatComm_Normal", 0.5,
	"FST_FlatComm_Abnormal", 0.15,
	"", 2

];

private _list_41nyvarwanted = [
	"FST_WantTeam_Sly",
	"FST_WantTeam_Sigs",
	"FST_WantTeam_Preacher",
	"FST_WantTeam_Ampersand",
	"FST_WantTeam_Mav",
	"FST_WantTeam_Pecan",
	"FST_WantTeam_Buddah",
	"FST_WantTeam_Burns",
	"FST_WantTeam_Major",
	"FST_WantTeam_Gold"

];

private _list_41standardwep = [
	"FST_A260",
	"FST_A280",
	"FST_A280C",
	"FST_A300",
	"FST_Arkanian_F",
	"FST_Arkanian_Stock_F",
	"FST_DC15S",
	"FST_EE3",
	"FST_Galaar15",
	"FST_Mercenary_DC15S_UGL_Wood",
	"FST_SPA_K15",
	"FST_TL50",
	"FST_ValD"

];

private _list_41scatterwep = [
	"FST_A300C",
	"FST_ACPA",
	"FST_SBB3"

];

private _list_41rapidwep = [
	"FST_Cinnagaran_Carbine",
	"FST_EE4",
	"FST_SE28"

];

private _list_41lowsidewep = [
	"FST_A180",
	"FST_DC17",
	"FST_DH42_Pistol",
	"FST_DL18_Pistol",
	"FST_EC17_Pistol",
	"FST_RK3_Pistol",
	"FST_SE14R",
	"FST_Westar35"

];

private _list_41highsidewep = [
	"FST_DC15P",
	"FST_DL44_Pistol",
	"FST_DT12_Pistol",
	"FST_K16_Pistol",
	"FST_Relbyk25_Pistol",
	"FST_RG4D"

];

private _lowrollarray = [1, 0.4, 2, 0.4, 3, 0.2];
private _highrollarray = [4, 0.2, 5, 0.4, 6, 0.3, 7, 0.1];

private _rolllow0 = selectRandomWeighted _lowrollarray;
private _rolllow1 = selectRandomWeighted _lowrollarray;
private _rolllow2 = selectRandomWeighted _lowrollarray;
private _rollhigh0 = selectRandomWeighted _highrollarray;

private _selectdatapad = selectRandomWeighted _list_41nyvardatapad;
private _selectcomm = selectRandomWeighted _list_41nyvarcomms;
private _wanted0 = selectRandom _list_41nyvarwanted;
private _wanted1 = selectRandom _list_41nyvarwanted;
private _intel0 = selectRandomWeighted _list_41nyvarintelitems;
private _intel1 = selectRandomWeighted _list_41nyvarintelitems;

private _nadearray = [0, 0.7, 1, 0.2, 2, 0.1];
private _10array = [0, 0.1, 1, 0.4, 2, 0.3, 3, 0.2];
private _50array = [0, 0.8, 1, 0.2];
private _chiparray = [0, 0.75, 1, 0.25];
private _wantarray = [0, 0.7, 1, 0.3];

private _smokeamount = selectRandomWeighted _nadearray;
private _thermalamount = selectRandomWeighted _nadearray;
private _flashamount = selectRandomWeighted _nadearray;
private _10amount = selectRandomWeighted _10array;
private _50choice = selectRandomWeighted _50array;
private _chipchoice = selectRandomWeighted _chiparray;
private _wantchoice = selectRandomWeighted _wantarray;

private _armorchoice = "hold";
private _helmetchoice = "hold";
private _armbandchoice = "hold";
private _setchoice = floor (random 4);

if ( _setchoice == 0) then { _armorchoice = "FST_Uniform_Recruit"; _helmetchoice = "FST_P2_Helmet_Recruit"; _armbandchoice = "Armband_Red_Large";};
if ( _setchoice == 1) then { _armorchoice = "JMSLLTE_JinTrooper_armor_F_CombatUniform"; _helmetchoice = "JMSLLTE_Tanktrooper_jin_helmet"; _armbandchoice = "Armband_Red_Large";};
if ( _setchoice == 2) then { _armorchoice = "FST_U_CIS_Light_Armor"; _helmetchoice = "3AS_CIS_Light_helmet"; _armbandchoice = "Armband_Red_medium";};
if ( _setchoice == 3) then { _armorchoice = "JMSLLTE_BoPilot_blue_F_CombatUniform"; _helmetchoice = "JMSLLTE_Commando_cloud_helmet"; _armbandchoice = "Armband_Red";};

private _ammoarray = [5, 0.2, 6, 0.4, 7, 0.4, 8, 0.4, 9, 0.2, 10, 0.1];

private _pweaponchoice = "hold";
private _pammochoice = "hold";
private _pammoamount = selectRandomWeighted _ammoarray;
private _proundamount = 0;
private _sweaponchoice = "hold";
private _sammochoice = "hold";
private _sammoamount = selectRandomWeighted _ammoarray;
private _sroundamount = 0;

private _weparray = [0, 0.8, 1, 0.1, 2, 0.1, 3, 0.05, 4, 0.05];

private _ptypechoice = selectRandomWeighted _weparray;
private _stypechoice = floor (random 2);

if ( _ptypechoice == 0) then { _pweaponchoice = selectRandom _list_41standardwep; _pammochoice = "FST_blaster_cell_Red"; _proundamount = 60;};
if ( _ptypechoice == 1) then { _pweaponchoice = selectRandom _list_41scatterwep; _pammochoice = "FST_blaster_scatter_cell_SBB3_Red"; _proundamount = 8;};
if ( _ptypechoice == 2) then { _pweaponchoice = selectRandom _list_41rapidwep; _pammochoice = "FST_blaster_cell_low_Red_smg"; _proundamount = 120;};
if ( _ptypechoice == 3) then { _pweaponchoice = "FST_DP23"; _pammochoice = "FST_blaster_scatter_cell_DP23_Red"; _proundamount = 8;};
if ( _ptypechoice == 4) then { _pweaponchoice = "FST_ACPR"; _pammochoice = "FST_ACPR_Mag_Red"; _proundamount = 60;};
if ( _stypechoice == 0) then { _sweaponchoice = selectRandom _list_41lowsidewep; _sammochoice = "FST_blaster_cell_low_Red"; _sroundamount = 30;};
if ( _stypechoice == 1) then { _sweaponchoice = selectRandom _list_41highsidewep; _sammochoice = "FST_blaster_cell_SSP_Red"; _sroundamount = 15;};

_unit setUnitLoadout [[ _pweaponchoice,"","","",[ _pammochoice, _proundamount],[],""],[],[ _sweaponchoice,"","","",[ _sammochoice, _sroundamount],[],""],[ _armorchoice,[["JLTS_credits_10", _10amount],["JLTS_credits_50", _50choice],["FST_CreditChip", _chipchoice],[ _selectdatapad,1],[ _selectcomm,1],[ _wanted0,1],[ _wanted1, _wantchoice],[ _intel0,1],[ _intel1,1]]],["FST_CIS_HolsterVest",[["IDA_BactaBandage", _rollhigh0],["IDA_BattleStim", _rolllow0],["ACE_splint", _rolllow1],["ACE_tourniquet", _rolllow2]]],["FST_CIS_Backpack_Invisible",[["IDA_grenade_Detonator_mag", _thermalamount,1],["IDA_grenade_Sonic_mag", _flashamount,1],["FST_grenade_smoke_orange_mag", _smokeamount,1],[ _pammochoice, _pammoamount, _proundamount],[ _sammochoice, _sammoamount, _sroundamount]]], _helmetchoice, _armbandchoice,[],["ItemMap","","ls_radios_hush98_aurebesh","ItemCompass","","k_nvg_ti"]];

_unit setSkill ['aimingAccuracy',0.5];
_unit setSkill ['aimingShake',0.5];
_unit setSkill ['aimingSpeed',0.7];
_unit setSkill ['spotDistance',0.6];
_unit setSkill ['spotTime',0.7];
_unit setSkill ['courage',0.6];
_unit setSkill ['commanding',0.6];
_unit setSkill ['reloadSpeed',0.5];
_unit setSkill ['general',0.5];
_unit allowFleeing 0.3;

private _chosenhead = selectRandom _list_41nyvarhumanheads;

["FST_applyIdentity", [ _unit, _chosenhead, "ACE_NoVoice"]] call CBA_fnc_globalEvent;

};
