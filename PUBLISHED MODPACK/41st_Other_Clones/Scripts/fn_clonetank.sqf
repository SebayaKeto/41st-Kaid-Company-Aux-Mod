
params ["_unit","_group"];

if (isNull _unit) exitWith {};
if (!local _unit) exitWith {}; 

if (_unit getVariable ["FST_Initialized", false]) exitWith {};
_unit setVariable ["FST_Initialized", true, true];

switch (_group) do
{
	case 501:
	{
		["FST_applyName", [ _unit, "501st Clone Tanker"]] call CBA_fnc_globalEvent;
	};
};

[_unit, _group] spawn {

params ["_unit","_group"];

if (isNull _unit) exitWith {};

sleep 0.05;

if (isNull _unit) exitWith {};
if (!local _unit) exitWith {};


private _list_41clonedatapad = [
	"FST_CivData_Normal", 0.5,
	"FST_CivData_Bulge", 0.02,
	"FST_CivData_Cat", 0.02,
	"FST_CivData_Damage", 0.1,
	"FST_CivData_Dead", 0.02,
	"FST_CivData_Gamer", 0.1,
	"FST_CivData_Idiot", 0.02,
	"FST_CivData_Interface", 0.1,
	"FST_CivData_Meme", 0.1,
	"FST_CivData_Off", 0.02,
	"FST_CivData_Overload", 0.02,
	"FST_CivData_Password", 0.02,
	"FST_CivData_Selfie", 0.02,
	"FST_CivData_UwU", 0.1,
	"FST_CivData_Virus", 0.02,
	"FST_SpaceData_Normal", 0.5,
	"FST_SpaceData_Aqua", 0.1,
	"FST_SpaceData_Blast", 0.3,
	"FST_SpaceData_Brick", 0.02,
	"FST_SpaceData_Droid", 0.1,
	"FST_SpaceData_Drop", 0.3,
	"FST_SpaceData_Fire", 0.1,
	"FST_SpaceData_Oil", 0.1,
	"FST_SpaceData_Press", 0.1,
	"FST_SpaceData_Radio", 0.1,
	"FST_SpaceData_SPACE", 0.3,
	"FST_SpaceData_Squish", 0.02,
	"FST_StylusData_Normal", 0.5,
	"FST_StylusData_Broken", 0.02,
	"FST_StylusData_Check", 0.1,
	"FST_StylusData_Chew", 0.02,
	"FST_StylusData_Engine", 0.02,
	"FST_StylusData_Flight", 0.02,
	"FST_StylusData_Form", 0.1,
	"FST_StylusData_Game", 0.1,
	"FST_StylusData_Lost", 0.02,
	"FST_StylusData_Note", 0.02,
	"FST_StylusData_Scratch", 0.02,
	"FST_StylusData_Stab", 0.02,
	"FST_CivMiniData_Normal", 0.5,
	"FST_CivMiniData_Atmos", 0.1,
	"FST_CivMiniData_Bio", 0.02,
	"FST_CivMiniData_Broken", 0.1,
	"FST_CivMiniData_Built", 0.3,
	"FST_CivMiniData_Camera", 0.1,
	"FST_CivMiniData_Chem", 0.02,
	"FST_CivMiniData_Diagnose", 0.1,
	"FST_CivMiniData_Droid", 0.1,
	"FST_CivMiniData_Drug", 0.02,
	"FST_CivMiniData_GPS", 0.1,
	"FST_CivMiniData_Huh", 0.02,
	"FST_CivMiniData_Music", 0.1,
	"FST_CivMiniData_Notes", 0.1,
	"FST_CivMiniData_Radio", 0.1,
	"FST_CivMiniData_Shot", 0.3,
	"FST_CivMiniData_Track", 0.3

];

private _list_41cloneintelitems = [
	"FST_ReadData_Normal", 0.5,
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
	"FST_ReadData_Medical", 0.1,
	"FST_ReadData_Mystery", 0.1,
	"FST_ReadData_News", 0.1,
	"FST_ReadData_Snap", 0.02,
	"FST_ReadData_Tabloid", 0.1,
	"FST_ReadData_Text", 0.02,
	"FST_ReadData_Youth", 0.1,
	"FST_CivDatacard_Normal", 0.5,
	"FST_CivDatacard_Blueprint", 0.02,
	"FST_CivDatacard_Broken", 0.02,
	"FST_CivDatacard_Corrupt", 0.02,
	"FST_CivDatacard_Empty", 0.02,
	"FST_CivDatacard_Fiction", 0.1,
	"FST_CivDatacard_Game", 0.1,
	"FST_CivDatacard_Journal", 0.1,
	"FST_CivDatacard_Medical", 0.02,
	"FST_CivDatacard_Mouse", 0.02,
	"FST_CivDatacard_Movie", 0.1,
	"FST_CivDatacard_Music", 0.02,
	"FST_CivDatacard_News", 0.1,
	"FST_CivDatacard_OwO", 0.1,
	"FST_CivDatacard_Troll", 0.02,
	"FST_CivDatacard_Virus", 0.1,
	"FST_CivDataCrystal_Normal", 0.5,
	"FST_CivDataCrystal_Archive", 0.3,
	"FST_CivDataCrystal_Blueprint", 0.02,
	"FST_CivDataCrystal_Data", 0.1,
	"FST_CivDataCrystal_Format", 0.1,
	"FST_CivDataCrystal_Galaxy", 0.3,
	"FST_CivDataCrystal_Library", 0.1,
	"FST_CivDataCrystal_Media", 0.1,
	"FST_CivDataCrystal_Melt", 0.02,
	"FST_CivDataCrystal_Old", 0.1,
	"FST_CivDataCrystal_Planet", 0.5,
	"FST_CivDataCrystal_Records", 0.3,
	"FST_CivDataCrystal_Rock", 0.02,
	"FST_CivDataCrystal_Shattered", 0.02,
	"FST_CivDataCrystal_Ship", 0.1,
	"FST_CivDataCrystal_Stun", 0.1,
	"FST_CivFlimsi_Normal", 0.5,
	"FST_CivFlimsi_Blank", 0.1,
	"FST_CivFlimsi_CCard", 0.1,
	"FST_CivFlimsi_Doc", 0.1,
	"FST_CivFlimsi_Doodle", 0.3,
	"FST_CivFlimsi_Form", 0.1,
	"FST_CivFlimsi_Gross", 0.02,
	"FST_CivFlimsi_List", 0.1,
	"FST_CivFlimsi_Note", 0.02,
	"FST_CivFlimsi_Picture", 0.1,
	"FST_CivFlimsi_Receipt", 0.02,
	"FST_CivFlimsi_Starchart", 0.1,
	"FST_CivFlimsi_Stick", 0.9,
	"FST_CivFlimsi_Trash", 0.02,
	"FST_CivFlimsi_Work", 0.3,
	"FST_CivFlimsiFile_Normal", 0.5,
	"FST_CivFlimsiFile_Photo", 0.1,
	"FST_CivFlimsiFile_Police", 0.02,
	"FST_CivFlimsiFile_Profile", 0.3,
	"FST_CivFlimsiFile_Project", 0.1,
	"FST_CivFlimsiFile_Record", 0.02,
	"FST_CivFlimsiFile_Starchart", 0.1,
	"FST_CivFlimsiFile_Work", 0.1,
	"FST_CivHoloprojector_Normal", 0.5,
	"FST_CivHoloprojector_Anatomy", 0.02,
	"FST_CivHoloprojector_Beast", 0.1,
	"FST_CivHoloprojector_Blueprint", 0.1,
	"FST_CivHoloprojector_Broken", 0.02,
	"FST_CivHoloprojector_Galaxy", 0.1,
	"FST_CivHoloprojector_Game", 0.1,
	"FST_CivHoloprojector_Ha", 0.02,
	"FST_CivHoloprojector_Land", 0.5,
	"FST_CivHoloprojector_Map", 0.3,
	"FST_CivHoloprojector_Movie", 0.3,
	"FST_CivHoloprojector_OwO", 0.02,
	"FST_CivHoloprojector_Record", 0.3,
	"FST_CivHoloprojector_Route", 0.02,
	"FST_CivHoloprojector_Solar", 0.1,
	"FST_CivHoloprojector_Sport", 0.1,
	"FST_TrackingFob_Normal", 0.3,
	"FST_TrackingFob_Bothan", 0.02,
	"FST_TrackingFob_Broken", 0.1,
	"FST_TrackingFob_Capital", 0.02,
	"FST_TrackingFob_Cargo", 0.02,
	"FST_TrackingFob_Chandrila", 0.02,
	"FST_TrackingFob_Core", 0.02,
	"FST_TrackingFob_Here", 0.3,
	"FST_TrackingFob_Huh", 0.1,
	"FST_TrackingFob_Inner", 0.02,
	"FST_TrackingFob_Ithor", 0.02,
	"FST_TrackingFob_Orbit", 0.1,
	"FST_TrackingFob_Planet", 0.1,
	"FST_TrackingFob_Range", 0.02,
	"FST_TrackingFob_Rodia", 0.02,
	"FST_TrackingFob_Sector", 0.02,
	"FST_TrackingFob_Shaddaa", 0.1,
	"FST_TrackingFob_Ship", 0.02,
	"FST_TrackingFob_Spine", 0.02,
	"FST_TrackingFob_Tatooine", 0.02,
	"FST_TrackingFob_Wookiee", 0.02,
	"FST_HoloComm_Normal", 0.1,
	"FST_Camtono_Data", 0.1,
	"", 6

];

private _datapad0 = selectRandomWeighted _list_41clonedatapad;
private _datapad1 = selectRandomWeighted _list_41clonedatapad;
private _intel0 = selectRandomWeighted _list_41cloneintelitems;
private _intel1 = selectRandomWeighted _list_41cloneintelitems;
private _intel2 = selectRandomWeighted _list_41cloneintelitems;
private _chance0 = selectRandom [0,1];

switch (_group) do
{
	case 501:
	{
		_unit setUnitLoadout [["FST_DC15S","","","FST_Attachment_Optic_Holo_DC15",["FST_blaster_cell_Blue",60],[],""],[],["FST_DC17","","","",["FST_blaster_cell_low_Blue",30],[],""],["FST_501_Uniform",[[_datapad0,1],[_datapad1,_chance0],[_intel0,1],[_intel1,1],[_intel2,1],["WBK_HeadLampItem_Narrow",1],["ACE_EntrenchingTool",1],["ACE_Chemlight_HiGreen",1,1]]],["FST_vest_holster",[["IDA_BactaBandage",10],["IDA_BattleStim",2],["ACE_splint",2],["ACE_tourniquet",2]]],["FST_Backpack_Antenna",[["FST_LargeToolkit",1],["FST_blaster_cell_low_Blue",10,30],["FST_blaster_cell_Blue",10,60],[["IDA_Clone_Knife","","","",[],[],""],1]]],"FST_P2_Helmet_501_Tank","",["FST_Electrobinoculars","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","FST_clone_comlink","ItemCompass","ItemWatch","FST_NVG_Invisible"]];
	};
};

_unit setSkill ['aimingAccuracy',0.5];
_unit setSkill ['aimingShake',0.6];
_unit setSkill ['aimingSpeed',0.6];
_unit setSkill ['spotDistance',0.5];
_unit setSkill ['spotTime',0.5];
_unit setSkill ['courage',1];
_unit setSkill ['commanding',0.6];
_unit setSkill ['reloadSpeed',0.6];
_unit setSkill ['general',0.6];
_unit allowFleeing 0;

["FST_applyIdentity", [ _unit, "FST_clone_Default_head", "Male04ENGB"]] call CBA_fnc_globalEvent;

_unit disableAI "RADIOPROTOCOL";

};