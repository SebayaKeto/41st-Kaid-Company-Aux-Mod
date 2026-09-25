
params ["_unit"];

// Defer past native createUnit/BIS skill setup. Recheck ownership inside
// an unscheduled block; a Local event retries if transfer preceded setup.
sleep 0.05;
isNil {
if (isNull _unit) exitWith {};
if (!local _unit) exitWith {}; 

if (_unit getVariable ["FST_Initialized", false]) exitWith {};
_unit setVariable ["FST_Initialized", true, true];

["FST_applyName", [ _unit, "Umbaran Antitank Trooper"]] call CBA_fnc_globalEvent;

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
	"FST_CivData_Interface", 0.02,
	"FST_CivData_Meme", 0.1,
	"FST_CivData_Off", 0.1,
	"FST_CivData_Overload", 0.1,
	"FST_CivData_Selfie", 0.1,
	"FST_CivData_Slow", 0.02,
	"FST_CivData_UwU", 0.02,
	"FST_CivData_Virus", 0.02,
	"FST_SpaceData_Normal", 0.5,
	"FST_SpaceData_Abnormal", 0.3,
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
	"FST_StylusData_Abnormal", 0.3,
	"FST_StylusData_Check", 0.1,
	"FST_StylusData_Chew", 0.02,
	"FST_StylusData_Form", 0.02,
	"FST_StylusData_Game", 0.1,
	"FST_StylusData_Lost", 0.02,
	"FST_StylusData_Note", 0.02,
	"FST_StylusData_Scratch", 0.02,
	"FST_CivMiniData_Normal", 0.5,
	"FST_CivMiniData_Abnormal", 0.3,
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

private _list_41hdintelitems = [
	"FST_ReadData_Normal", 0.5,
	"FST_ReadData_Abnormal", 0.3,
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
	"FST_CivDatacard_Abnormal", 0.3,
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
	"FST_CivFlimsi_Normal", 0.5,
	"FST_CivFlimsi_Abnormal", 0.3,
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
	"FST_CivFlimsiFile_Abnormal", 0.3,
	"FST_CivFlimsiFile_Work", 0.1,
	"FST_CivFlimsiFile_Photo", 0.02,
	"FST_CivFlimsiFile_Police", 0.02,
	"FST_CivFlimsiFile_Profile", 0.1,
	"FST_CivFlimsiFile_Project", 0.1,
	"FST_CivFlimsiFile_Law", 0.02,
	"FST_CivFlimsiFile_Record", 0.02,
	"FST_CivFlimsiFile_Starchart", 0.02,
	"FST_CivHoloprojector_Normal", 0.5,
	"FST_CivHoloprojector_Abnormal", 0.3,
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

private _list_41hdcomms = [
	"FST_HoloComm_Normal", 0.5,
	"FST_HoloComm_Abnormal", 0.3,
	"FST_HandComm_Normal", 0.5,
	"FST_HandComm_Abnormal", 0.3,
	"FST_FlatComm_Normal", 0.5,
	"FST_FlatComm_Abnormal", 0.3,
	"", 2

];

private _selectdatapad = selectRandomWeighted _list_41hddatapad;
private _selectcomm = selectRandomWeighted _list_41hdcomms;
private _intel0 = selectRandomWeighted _list_41hdintelitems;
private _intel1 = selectRandomWeighted _list_41hdintelitems;
private _intel2 = selectRandomWeighted _list_41hdintelitems;

private _10array = [0, 0.1, 1, 0.4, 2, 0.3, 3, 0.2];
private _50array = [0, 0.9, 1, 0.1];
private _100array = [0, 0.7, 1, 0.3];
private _chiparray = [0, 0.9, 1, 0.1];
private _iarray = [0, 0.5, 1, 0.5];

private _10amount = selectRandomWeighted _10array;
private _50amount = selectRandomWeighted _50array;
private _100choice = selectRandomWeighted _100array;
private _chipchoice = selectRandomWeighted _chiparray;
private _intel1choice = selectRandomWeighted _iarray;
private _intel2choice = selectRandomWeighted _chiparray;

_unit setUnitLoadout [["FST_Galaar15","","","",["FST_blaster_cell_Green",60],[],""],["FST_RPS6HP_HD","","","",["FST_RPS6_rocket",1],[],""],[],["FST_UmbaranBodysuit",[["JLTS_credits_10", _10amount],["JLTS_credits_50", _50amount],["JLTS_credits_100", _100choice],["FST_CreditChip", _chipchoice],[ _selectdatapad,1],[ _selectcomm,1],[ _intel0,1],[ _intel1, _intel1choice],[ _intel2, _intel2choice]]],["FST_UmbaranVest_Inf",[["IDA_BactaBandage", 10],["IDA_BattleStim", 5],["ACE_splint", 4],["ACE_tourniquet", 4],["FST_BreathingGas_Oxygen",1],["FST_blaster_cell_Green",12,60]]],["FST_Clone_Backpack_Invisible_RPS",[["FST_RPS6_rocket",6,1]]],"OPTRE_ONI_Researcher_Headgear","",[],["ItemMap","ItemGPS","ls_radios_hush98_aurebesh","ItemCompass","","k_nvg_ti"]];

_unit setSkill ['aimingAccuracy',0.9];
_unit setSkill ['aimingShake',0.7];
_unit setSkill ['aimingSpeed',0.8];
_unit setSkill ['spotDistance',0.65];
_unit setSkill ['spotTime',0.9];
_unit setSkill ['courage',0.75];
_unit setSkill ['commanding',0.8];
_unit setSkill ['reloadSpeed',0.75];
_unit setSkill ['general',0.8];

["FST_applyIdentity", [ _unit, "DSA_MindflayerFace_01", "ACE_NoVoice"]] call CBA_fnc_globalEvent;

// Let BURNS apply its human policy after the authored loadout/skills are ready.
if (!isNil "FST_HCSpawn_fnc_burnsApplyRole") then {
    _unit setVariable ["BURNS_skillApplied", nil];
    [group _unit] call FST_HCSpawn_fnc_burnsApplyRole;
};
};
