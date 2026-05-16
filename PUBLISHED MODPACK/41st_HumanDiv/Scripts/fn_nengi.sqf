
params ["_unit"];

if (isNull _unit) exitWith {};
if (!local _unit) exitWith {}; 

if (_unit getVariable ["FST_Initialized", false]) exitWith {};
_unit setVariable ["FST_Initialized", true, true];

["FST_applyName", [ _unit, "CIS Naval Engineer"]] call CBA_fnc_globalEvent;

[_unit] spawn {

params ["_unit"];

if (isNull _unit) exitWith {};

sleep 0.05;

if (isNull _unit) exitWith {};
if (!local _unit) exitWith {};

private _list_41humanheads = [
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
	"FST_Navy_Face_Mustang",
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

private _list_41hddatapad = [
	"FST_CivData_Normal", 0.5, 
	"FST_CivData_Abnormal", 0.3,
	"FST_CivData_Betting", 0.02,
	"FST_CivData_Bulge", 0.02,
	"FST_CivData_Cat", 0.1,
	"FST_CivData_Damage", 0.1,
	"FST_CivData_Dead", 0.02,
	"FST_CivData_Gamer", 0.1,
	"FST_CivData_Idiot", 0.1,
	"FST_CivData_Illegal", 0.1,
	"FST_CivData_Interface", 2,
	"FST_CivData_Meme", 0.1,
	"FST_CivData_Off", 0.1,
	"FST_CivData_Overload", 0.1,
	"FST_CivData_Selfie", 0.1,
	"FST_CivData_Slow", 0.02,
	"FST_CivData_Spacer", 2,
	"FST_CivData_UwU", 0.02,
	"FST_CivData_Virus", 0.02,
	"FST_SpaceData_Normal", 1,
	"FST_SpaceData_Abnormal", 0.3,
	"FST_SpaceData_Aqua", 0.02,
	"FST_SpaceData_Blast", 0.1,
	"FST_SpaceData_Brick", 0.02,
	"FST_SpaceData_Droid", 2,
	"FST_SpaceData_Drop", 0.1,
	"FST_SpaceData_Fire", 0.02,
	"FST_SpaceData_Oil", 2,
	"FST_SpaceData_Press", 0.02,
	"FST_SpaceData_Radio", 2,
	"FST_SpaceData_Squish", 0.02,
	"FST_SpaceData_SPACE", 2,
	"FST_StylusData_Normal", 0.5,
	"FST_StylusData_Abnormal", 0.3,
	"FST_StylusData_Check", 0.1,
	"FST_StylusData_Chew", 0.02,
	"FST_StylusData_Engine", 2,
	"FST_StylusData_Flight", 2,
	"FST_StylusData_Form", 0.02,
	"FST_StylusData_Game", 0.1,
	"FST_StylusData_Lost", 0.02,
	"FST_StylusData_Note", 0.02,
	"FST_StylusData_Scratch", 0.02,
	"FST_CivMiniData_Normal", 0.5,
	"FST_CivMiniData_Abnormal", 0.3,
	"FST_CivMiniData_Atmos", 2,
	"FST_CivMiniData_Broken", 0.02,
	"FST_CivMiniData_Built", 0.1,
	"FST_CivMiniData_Camera", 0.02,
	"FST_CivMiniData_Chem", 0.1,
	"FST_CivMiniData_Diagnose", 2,
	"FST_CivMiniData_Droid", 2,
	"FST_CivMiniData_Huh", 0.1,
	"FST_CivMiniData_Music", 0.1,
	"FST_CivMiniData_Notes", 0.1,
	"FST_CivMiniData_Radio", 2,
	"FST_CivMiniData_Shot", 0.3,
	"FST_CivMiniData_Track", 0.6

];

private _list_41hdintelitems = [
	"FST_ReadData_Normal", 0.5,
	"FST_ReadData_Abnormal", 0.3,
	"FST_ReadData_Action", 0.1,
	"FST_ReadData_Bad", 0.1,
	"FST_ReadData_Bio", 0.02,
	"FST_ReadData_Boring", 0.1,
	"FST_ReadData_Cook", 0.02,
	"FST_ReadData_Droid", 2,
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
	"FST_CivDatacard_Abnormal", 0.3,
	"FST_CivDatacard_Blueprint", 2,
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
	"FST_CivFlimsi_Normal", 0.5,
	"FST_CivFlimsi_Abnormal", 0.3,
	"FST_CivFlimsi_Blank", 0.1,
	"FST_CivFlimsi_CCard", 0.02,
	"FST_CivFlimsi_Doc", 0.1,
	"FST_CivFlimsi_Doodle", 0.1,
	"FST_CivFlimsi_Flyer", 0.02,
	"FST_CivFlimsi_Form", 0.1,
	"FST_CivFlimsi_Gross", 0.1,
	"FST_CivFlimsi_Letter", 0.02,
	"FST_CivFlimsi_List", 0.1,
	"FST_CivFlimsi_Love", 0.02,
	"FST_CivFlimsi_Note", 0.02,
	"FST_CivFlimsi_Picture", 0.02,
	"FST_CivFlimsi_Receipt", 0.02,
	"FST_CivFlimsi_Starchart", 0.5,
	"FST_CivFlimsi_Stick2", 0.1,
	"FST_CivFlimsi_Trash", 0.02,
	"FST_CivFlimsi_Wanted", 0.02,
	"FST_CivFlimsi_Work", 0.1,
	"FST_CivFlimsiFile_Normal", 0.5,
	"FST_CivFlimsiFile_Abnormal", 0.3,
	"FST_CivFlimsiFile_Work", 0.1,
	"FST_CivFlimsiFile_Photo", 0.02,
	"FST_CivFlimsiFile_Police", 0.02,
	"FST_CivFlimsiFile_Profile", 0.1,
	"FST_CivFlimsiFile_Project", 0.1,
	"FST_CivFlimsiFile_Law", 0.02,
	"FST_CivFlimsiFile_Record", 0.02,
	"FST_CivFlimsiFile_Starchart", 0.5,
	"FST_CivHoloprojector_Normal", 0.5,
	"FST_CivHoloprojector_Abnormal", 0.3,
	"FST_CivHoloprojector_Beast", 0.1,
	"FST_CivHoloprojector_Broken", 0.02,
	"FST_CivHoloprojector_Design", 0.1,
	"FST_CivHoloprojector_Galaxy", 0.5,
	"FST_CivHoloprojector_Game", 0.1,
	"FST_CivHoloprojector_Map", 0.1,
	"FST_CivHoloprojector_Movie", 0.1,
	"FST_CivHoloprojector_OwO", 0.02,
	"FST_CivHoloprojector_Record", 0.02,
	"FST_CivHoloprojector_Route", 0.5,
	"FST_CivHoloprojector_Solar", 0.5,
	"FST_CivHoloprojector_Sport", 0.1,
	"FST_CivHoloprojector_Video", 0.1,
	"", 6

];

private _selectdatapad = selectRandomWeighted _list_41hddatapad;
_unit addItemToUniform _selectdatapad;

private _intel0 = selectRandomWeighted _list_41hdintelitems;
private _intel1 = selectRandomWeighted _list_41hdintelitems;
private _intel2 = selectRandomWeighted _list_41hdintelitems;
_unit addItemToUniform _intel0;
_unit addItemToUniform _intel1;
_unit addItemToUniform _intel2;

private _10array = [0, 0.1, 1, 0.4, 2, 0.3, 3, 0.2];
private _50array = [0, 0.4, 1, 0.4, 2, 0.2];
private _100array = [0, 0.5, 1, 0.5];
private _chiparray = [0, 0.2, 1, 0.8];

private _10amount = selectRandomWeighted _10array;
private _50amount = selectRandomWeighted _50array;
private _100choice = selectRandomWeighted _100array;
private _chipchoice = selectRandomWeighted _chiparray;

while { _10amount > 0} do { _unit addItemToUniform "JLTS_credits_10"; _10amount = _10amount - 1;};
while { _50amount > 0} do { _unit addItemToUniform "JLTS_credits_50"; _50amount = _50amount - 1;};
if ( _100choice == 1) then { _unit addItemToUniform "JLTS_credits_100"};
if ( _chipchoice == 1) then { _unit addItemToUniform "FST_CreditChip"};

_unit addItemToVest 'IDA_BactaBandage';
_unit addItemToVest 'IDA_BactaBandage';
_unit addItemToVest 'IDA_BactaBandage';
_unit addItemToVest 'IDA_BactaBandage';
_unit addItemToVest 'IDA_BactaBandage';
_unit addItemToVest 'IDA_BattleStim';
_unit addItemToVest 'IDA_BattleStim';
_unit addItemToVest 'ACE_splint';
_unit addItemToVest 'ACE_splint';
_unit addItemToVest 'ACE_tourniquet';
_unit addItemToVest 'ACE_tourniquet';
_unit addItemToVest 'IDA_VibroKnife';

_unit setSkill ['aimingAccuracy',0.5];
_unit setSkill ['aimingShake',0.55];
_unit setSkill ['aimingSpeed',0.65];
_unit setSkill ['spotDistance',0.65];
_unit setSkill ['spotTime',0.7];
_unit setSkill ['courage',0.7];
_unit setSkill ['commanding',0.5];
_unit setSkill ['reloadSpeed',0.5];
_unit setSkill ['general',0.6];

private _chosenhead = selectRandom _list_41humanheads;

["FST_applyIdentity", [ _unit, _chosenhead, "ACE_NoVoice"]] call CBA_fnc_globalEvent;

};