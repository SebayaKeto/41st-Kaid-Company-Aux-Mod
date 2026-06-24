
params ["_unit"];

if (isNull _unit) exitWith {};
if (!local _unit) exitWith {}; 

if (_unit getVariable ["FST_Initialized", false]) exitWith {};
_unit setVariable ["FST_Initialized", true, true];

["FST_applyName", [ _unit, "Clan Ordo Rusher"]] call CBA_fnc_globalEvent;

[_unit] spawn {

params ["_unit"];

if (isNull _unit) exitWith {};

sleep 0.05;

if (isNull _unit) exitWith {};
if (!local _unit) exitWith {};

private _list_41mandoheads = [
	"TCGM_Fem_Zhu",
	"TCGM_MakF_ZhuCommand",
	"TCGM_MakF_ZhuGothic1",
	"TCGM_MakF_ZhuClub1",
	"TCGM_MakF_ZhuClub2",
	"TCGM_MakF_ZhuPunk1",
	"TCGM_MakF_ZhuQuiet",
	"TCGM_MakF_ZhuViking1",
	"TCGM_Fem_StoneBun",
	"TCGM_Fem_FoxBun",
	"TCGM_Fem_EilishBun",
	"TCGM_Fem_Ayres",
	"TCGM_MakF_AyresCommand",
	"TCGM_MakF_AyresGothic1",
	"TCGM_MakF_AyresClub1",
	"TCGM_MakF_AyresClub2",
	"TCGM_MakF_AyresPunk1",
	"TCGM_MakF_AyresQuiet",
	"TCGM_MakF_AyresViking1",
	"TCGM_Fem_Portman",
	"TCGM_MakF_PortmanCommand",
	"TCGM_MakF_PortmanGothic1",
	"TCGM_MakF_PortmanClub1",
	"TCGM_MakF_PortmanClub2",
	"TCGM_MakF_PortmanPunk1",
	"TCGM_MakF_PortmanQuiet",
	"TCGM_MakF_PortmanViking1",
	"TCGM_Fem_Lynch",
	"TCGM_MakF_LynchCommand",
	"TCGM_MakF_LynchGothic1",
	"TCGM_MakF_LynchClub1",
	"TCGM_MakF_LynchClub2",
	"TCGM_MakF_LynchPunk1",
	"TCGM_MakF_LynchQuiet",
	"TCGM_MakF_LynchViking1",
	"TCGM_Fem_Liu",
	"TCGM_MakF_LiuCommand",
	"TCGM_MakF_LiuGothic1",
	"TCGM_MakF_LiuClub1",
	"TCGM_MakF_LiuClub2",
	"TCGM_MakF_LiuPunk1",
	"TCGM_MakF_LiuQuiet",
	"TCGM_MakF_LiuViking1",
	"TCGM_Fem_Hobson",
	"TCGM_MakF_HobsonCommand",
	"TCGM_MakF_HobsonGothic1",
	"TCGM_MakF_HobsonClub1",
	"TCGM_MakF_HobsonClub2",
	"TCGM_MakF_HobsonPunk1",
	"TCGM_MakF_HobsonQuiet",
	"TCGM_MakF_HobsonViking1",
	"TCGM_Fem_Gonzalez",
	"TCGM_MakF_GonzalezCommand",
	"TCGM_MakF_GonzalezGothic1",
	"TCGM_MakF_GonzalezClub1",
	"TCGM_MakF_GonzalezClub2",
	"TCGM_MakF_GonzalezPunk1",
	"TCGM_MakF_GonzalezQuiet",
	"TCGM_MakF_GonzalezViking1",
	"TCGM_Fem_Fenty",
	"TCGM_MakF_FentyCommand",
	"TCGM_MakF_FentyGothic1",
	"TCGM_MakF_FentyClub1",
	"TCGM_MakF_FentyClub2",
	"TCGM_MakF_FentyPunk1",
	"TCGM_MakF_FentyQuiet",
	"TCGM_MakF_FentyViking1",
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

private _list_41mandodatapad = [
	"FST_CivData_Normal", 0.5, 
	"FST_CivData_Betting", 0.02,
	"FST_CivData_Bulge", 0.02,
	"FST_CivData_Cat", 0.02,
	"FST_CivData_Costly", 0.1,
	"FST_CivData_Damage", 0.1,
	"FST_CivData_Dead", 0.02,
	"FST_CivData_Gamer", 0.1,
	"FST_CivData_Illegal", 0.3,
	"FST_CivData_Interface", 0.02,
	"FST_CivData_IR", 0.02,
	"FST_CivData_Lang", 0.02,
	"FST_CivData_Meme", 0.1,
	"FST_CivData_Off", 0.02,
	"FST_CivData_Old", 0.1,
	"FST_CivData_Overload", 0.02,
	"FST_CivData_Spacer", 0.1,
	"FST_CivData_UwU", 0.1,
	"FST_CivData_UV", 0.02,
	"FST_CivData_Virus", 0.02,
	"FST_SpaceData_Normal", 0.5,
	"FST_SpaceData_Aqua", 0.1,
	"FST_SpaceData_Blast", 0.3,
	"FST_SpaceData_Brick", 0.02,
	"FST_SpaceData_Chem", 0.1,
	"FST_SpaceData_Droid", 0.1,
	"FST_SpaceData_Drop", 0.3,
	"FST_SpaceData_Fire", 0.1,
	"FST_SpaceData_Oil", 0.1,
	"FST_SpaceData_Press", 0.1,
	"FST_SpaceData_Radio", 0.02,
	"FST_SpaceData_SPACE", 0.3,
	"FST_SpaceData_Squish", 0.02,
	"FST_StylusData_Normal", 0.5,
	"FST_StylusData_Alien", 0.02,
	"FST_StylusData_Check", 0.02,
	"FST_StylusData_Engine", 0.1,
	"FST_StylusData_Flight", 0.3,
	"FST_StylusData_Form", 0.02,
	"FST_StylusData_Game", 0.02,
	"FST_StylusData_Lost", 0.02,
	"FST_StylusData_Note", 0.02,
	"FST_StylusData_Scratch", 0.02,
	"FST_CivMiniData_Normal", 0.5,
	"FST_CivMiniData_Atmos", 0.02,
	"FST_CivMiniData_Bio", 0.02,
	"FST_CivMiniData_Broken", 0.02,
	"FST_CivMiniData_Built", 0.3,
	"FST_CivMiniData_Camera", 0.1,
	"FST_CivMiniData_Chem", 0.1,
	"FST_CivMiniData_Diagnose", 0.02,
	"FST_CivMiniData_Droid", 0.1,
	"FST_CivMiniData_Drug", 0.02,
	"FST_CivMiniData_GPS", 0.1,
	"FST_CivMiniData_Huh", 0.02,
	"FST_CivMiniData_Music", 0.02,
	"FST_CivMiniData_Notes", 0.1,
	"FST_CivMiniData_Radio", 0.02,
	"FST_CivMiniData_Shot", 0.3,
	"FST_CivMiniData_Track", 0.3

];

private _list_41mandointelitems = [
	"FST_ReadData_Normal", 0.5,
	"FST_ReadData_Action", 0.1,
	"FST_ReadData_Alien", 0.1,
	"FST_ReadData_Bad", 0.1,
	"FST_ReadData_Bio", 0.02,
	"FST_ReadData_Boring", 0.1,
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
	"FST_CivDatacard_Blueprint", 0.3,
	"FST_CivDatacard_Broken", 0.02,
	"FST_CivDatacard_Calendar", 0.1,
	"FST_CivDatacard_Care", 0.02,
	"FST_CivDatacard_Corrupt", 0.02,
	"FST_CivDatacard_Doc", 0.1,
	"FST_CivDatacard_Empty", 0.02,
	"FST_CivDatacard_Fiction", 0.1,
	"FST_CivDatacard_Game", 0.1,
	"FST_CivDatacard_Journal", 0.1,
	"FST_CivDatacard_Manual", 0.1,
	"FST_CivDatacard_Medical", 0.02,
	"FST_CivDatacard_Money", 0.02,
	"FST_CivDatacard_Mouse", 0.02,
	"FST_CivDatacard_Movie", 0.1,
	"FST_CivDatacard_Music", 0.02,
	"FST_CivDatacard_News", 0.1,
	"FST_CivDatacard_OwO", 0.1,
	"FST_CivDatacard_Program", 0.02,
	"FST_CivDatacard_Troll", 0.02,
	"FST_CivDatacard_Virus", 0.1,
	"FST_CivDataCrystal_Normal", 0.5,
	"FST_CivDataCrystal_Alien", 0.02,
	"FST_CivDataCrystal_Archive", 0.3,
	"FST_CivDataCrystal_Blueprint", 0.3,
	"FST_CivDataCrystal_Data", 0.1,
	"FST_CivDataCrystal_Droid", 0.02,
	"FST_CivDataCrystal_Format", 0.1,
	"FST_CivDataCrystal_Galaxy", 0.1,
	"FST_CivDataCrystal_Library", 0.1,
	"FST_CivDataCrystal_Media", 0.1,
	"FST_CivDataCrystal_Melt", 0.5,
	"FST_CivDataCrystal_Old", 0.02,
	"FST_CivDataCrystal_Planet", 0.5,
	"FST_CivDataCrystal_Rock", 0.02,
	"FST_CivDataCrystal_Shattered", 0.5,
	"FST_CivDataCrystal_Ship", 0.5,
	"FST_CivDataCrystal_Stun", 0.1,
	"FST_CivFlimsi_Normal", 0.5,
	"FST_CivFlimsi_Ad", 0.02,
	"FST_CivFlimsi_BCard", 0.3,
	"FST_CivFlimsi_Blank", 0.1,
	"FST_CivFlimsi_CCard", 0.02,
	"FST_CivFlimsi_Coupon", 0.02,
	"FST_CivFlimsi_Doc", 0.1,
	"FST_CivFlimsi_Doodle", 0.02,
	"FST_CivFlimsi_Flyer", 0.02,
	"FST_CivFlimsi_Form", 0.02,
	"FST_CivFlimsi_Gross", 0.02,
	"FST_CivFlimsi_Letter", 0.02,
	"FST_CivFlimsi_List", 0.1,
	"FST_CivFlimsi_Love", 0.02,
	"FST_CivFlimsi_Note", 0.1,
	"FST_CivFlimsi_Picture", 0.1,
	"FST_CivFlimsi_Receipt", 0.02,
	"FST_CivFlimsi_Starchart", 0.3,
	"FST_CivFlimsi_Trash", 0.02,
	"FST_CivFlimsi_Wanted", 0.1,
	"FST_CivFlimsi_Work", 0.3,
	"FST_CivFlimsiFile_Normal", 0.5,
	"FST_CivFlimsiFile_Alien", 0.02,
	"FST_CivFlimsiFile_Law", 0.02,
	"FST_CivFlimsiFile_Photo", 0.1,
	"FST_CivFlimsiFile_Plan", 0.02,
	"FST_CivFlimsiFile_Police", 0.02,
	"FST_CivFlimsiFile_Profile", 0.3,
	"FST_CivFlimsiFile_Project", 0.1,
	"FST_CivFlimsiFile_Record", 0.02,
	"FST_CivFlimsiFile_Starchart", 0.1,
	"FST_CivFlimsiFile_Starship", 0.1,
	"FST_CivFlimsiFile_Transport", 0.02,
	"FST_CivFlimsiFile_Work", 0.1,
	"FST_CivHoloprojector_Normal", 0.5,
	"FST_CivHoloprojector_Alien", 0.02,
	"FST_CivHoloprojector_Anatomy", 0.02,
	"FST_CivHoloprojector_Beast", 0.1,
	"FST_CivHoloprojector_Blueprint", 0.1,
	"FST_CivHoloprojector_Broken", 0.02,
	"FST_CivHoloprojector_Galaxy", 0.02,
	"FST_CivHoloprojector_Game", 0.1,
	"FST_CivHoloprojector_Ha", 0.02,
	"FST_CivHoloprojector_Land", 0.5,
	"FST_CivHoloprojector_Map", 0.1,
	"FST_CivHoloprojector_Manual", 0.02,
	"FST_CivHoloprojector_Movie", 0.1,
	"FST_CivHoloprojector_OwO", 0.02,
	"FST_CivHoloprojector_Record", 0.3,
	"FST_CivHoloprojector_Route", 0.02,
	"FST_CivHoloprojector_Solar", 0.02,
	"FST_CivHoloprojector_Sport", 0.02

];

private _list_41mandodevices = [
	"FST_BountyDisk_Normal", 0.5,
	"FST_BountyDisk_Addict", 0.3,
	"FST_BountyDisk_Catboy", 0.02,
	"FST_BountyDisk_CEO", 0.1,
	"FST_BountyDisk_Child", 0.05,
	"FST_BountyDisk_Done", 0.3,
	"FST_BountyDisk_Droid", 0.1,
	"FST_BountyDisk_Gamble", 0.3,
	"FST_BountyDisk_Jedi", 0.05,
	"FST_BountyDisk_Jump", 0.3,
	"FST_BountyDisk_Leader", 0.05,
	"FST_BountyDisk_Murder", 0.1,
	"FST_BountyDisk_Mystery", 0.1,
	"FST_BountyDisk_Politic", 0.05,
	"FST_BountyDisk_Revenge", 0.1,
	"FST_BountyDisk_Smug", 0.3,
	"FST_BountyDisk_Stalk", 0.05,
	"FST_BountyDisk_Thief", 0.3,
	"FST_BountyDisk_Traitor", 0.3,
	"FST_TrackingFob_Normal", 0.5,
	"FST_TrackingFob_Bothan", 0.1,
	"FST_TrackingFob_Broken", 0.05,
	"FST_TrackingFob_Capital", 0.1,
	"FST_TrackingFob_Cargo", 0.1,
	"FST_TrackingFob_Chandrila", 0.1,
	"FST_TrackingFob_Core", 0.1,
	"FST_TrackingFob_Here", 0.05,
	"FST_TrackingFob_Huh", 0.3,
	"FST_TrackingFob_Inner", 0.1,
	"FST_TrackingFob_Ithor", 0.1,
	"FST_TrackingFob_Orbit", 0.3,
	"FST_TrackingFob_Planet", 0.1,
	"FST_TrackingFob_Range", 0.05,
	"FST_TrackingFob_Rodia", 0.1,
	"FST_TrackingFob_Sector", 0.1,
	"FST_TrackingFob_Shaddaa", 0.1,
	"FST_TrackingFob_Ship", 0.3,
	"FST_TrackingFob_Spine", 0.1,
	"FST_TrackingFob_Tatooine", 0.1,
	"FST_TrackingFob_Wookiee", 0.1,
	"", 1

];

private _list_41mandocomms = [
	"FST_HoloComm_Normal", 0.6,
	"", 2

];

private _list_41creditcases = [
	"", 2,
	"FST_CreditCase_Lock", 0.6,
	"FST_CreditCase_Chip", 0.1,
	"FST_CreditCase_Low", 0.4,
	"FST_CreditCase_Med", 0.3,
	"FST_CreditCase_High", 0.1,
	"FST_CreditCase_Rare", 0.05
];

private _list_41camtonos = [
	"", 0.05,
	"FST_Camtono_Sealed", 0.05,
	"FST_Camtono_Aurodium", 0.1,
	"FST_Camtono_Beskar", 0.6,
	"FST_Camtono_Blaster", 0.6,
	"FST_Camtono_Corusca", 0.05,
	"FST_Camtono_Gemstones", 0.4,
	"FST_Camtono_Glitterstim", 0.01,
	"FST_Camtono_Kyber", 0.05,
	"FST_Camtono_Liquor", 0.6,
	"FST_Camtono_Metal", 0.1,
	"FST_Camtono_Nova", 0.05,
	"FST_Camtono_Pearl", 0.05,
	"FST_Camtono_Rainbow", 0.0001,
	"FST_Camtono_Vertex", 0.1,
	"FST_Camtono_Whiskey", 0.6

];

private _list_41creditsitemshigh = [
	"", 0.5,
	"FST_CreditChip", 0.8,
	"JLTS_credits_100", 0.6,
	"JLTS_credits_500", 0.4,
	"JLTS_credits_1000", 0.1,
	"JLTS_credits_5000", 0.05
];

private _case0 = selectRandomWeighted _list_41creditcases;
private _cam0 = selectRandomWeighted _list_41camtonos;
private _rich0 = selectRandomWeighted _list_41creditsitemshigh;
private _rich1 = selectRandomWeighted _list_41creditsitemshigh;
private _rich2 = selectRandomWeighted _list_41creditsitemshigh;
private _datapad0 = selectRandomWeighted _list_41mandodatapad;
private _datapad1 = selectRandomWeighted _list_41mandodatapad;
private _device0 = selectRandomWeighted _list_41mandodevices;
private _device1 = selectRandomWeighted _list_41mandodevices;
private _selectcomm = selectRandomWeighted _list_41mandocomms;
private _intel0 = selectRandomWeighted _list_41mandointelitems;
private _intel1 = selectRandomWeighted _list_41mandointelitems;
private _intel2 = selectRandomWeighted _list_41mandointelitems;

private _10array = [0, 0.1, 1, 0.4, 2, 0.3, 3, 0.2];
private _50array = [0, 0.4, 1, 0.4, 2, 0.2];
private _padarray = [0, 0.4, 1, 0.6];
private _dsarray = [0, 0.7, 1, 0.3];

private _10amount = selectRandomWeighted _10array;
private _50amount = selectRandomWeighted _50array;
private _padchoice = selectRandomWeighted _padarray;
private _intelchoice0 = selectRandomWeighted _padarray;
private _intelchoice1 = selectRandomWeighted _dsarray;
private _dschoice = selectRandomWeighted _dsarray;

private _loadoutarray = [1, 1, 2, 0.8, 3, 0.5, 4, 0.8];

private _loadoutchoice = selectRandomWeighted _loadoutarray;

if ( _loadoutchoice == 1) then { _unit setUnitLoadout [["FST_A300C","","","",["FST_blaster_scatter_cell_SBB3_Green",8],[],""],[],["WBK_SciFi_Sword_4","","","",["WBK_Cybercrystal",30],[],""],["FST_MandoUndersuitUni",[["JLTS_credits_10", _10amount],["JLTS_credits_50", _50amount],[ _rich0,1],[ _rich1,1],[ _rich2,1],[ _case0,1],[ _cam0,1],[ _datapad0,1],[ _datapad1, _padchoice],[ _device0,1],[ _device1,1],[ _intel0,1],[ _intel1, _intelchoice0],[ _intel2, _intelchoice1],["WBK_HeadLampItem_Double",1],[ _selectcomm,1],["JLTS_drugs_deathstick", _dschoice]]],["ls_mandalorianVest_ordoGrunt",[["IDA_BactaBandage",10],["IDA_BattleStim",2],["ACE_tourniquet",2],["ACE_splint",2],[["Weap_melee_knife","","","",[],[],""],1]]],["ls_mandalorianBackpack_demo",[["IDA_grenade_Sonic_mag",3,1],["IDA_grenade_Smoke_mag",3,1],["DBA_UT5_x3_Grenade",2,3],["JMSLLTE_C25_HandGrenade",2,1],["JMSLLTE_dioxis_HandGrenade",2,1],["ls_grenade_n20_magazine",2,1],["FST_blaster_scatter_cell_SBB3_Green",15,8],[["IDA_VibroKnife","","","",[],[],""],2]]],"ls_mandalorianHelmet_ordoGrunt","",[],["ItemMap","ItemGPS","ls_radios_hush98_aurebesh","","","ls_mandalorian_rangefinder"]]};
if ( _loadoutchoice == 2) then { _unit setUnitLoadout [["FST_ACPA","","","",["FST_blaster_scatter_cell_SBB3_Green",8],[],""],[],["WBK_SciFi_Sword_4","","","",["WBK_Cybercrystal",30],[],""],["FST_MandoUndersuitUni",[["JLTS_credits_10", _10amount],["JLTS_credits_50", _50amount],[ _rich0,1],[ _rich1,1],[ _rich2,1],[ _case0,1],[ _cam0,1],[ _datapad0,1],[ _datapad1, _padchoice],[ _device0,1],[ _device1,1],[ _intel0,1],[ _intel1, _intelchoice0],[ _intel2, _intelchoice1],["WBK_HeadLampItem_Double",1],[ _selectcomm,1],["JLTS_drugs_deathstick", _dschoice]]],["ls_mandalorianVest_ordoGrunt",[["IDA_BactaBandage",10],["IDA_BattleStim",2],["ACE_tourniquet",2],["ACE_splint",2],[["Weap_melee_knife","","","",[],[],""],1]]],["ls_mandalorianBackpack_demo",[["IDA_grenade_Sonic_mag",3,1],["IDA_grenade_Smoke_mag",3,1],["DBA_UT5_x3_Grenade",2,3],["JMSLLTE_C25_HandGrenade",2,1],["JMSLLTE_dioxis_HandGrenade",2,1],["ls_grenade_n20_magazine",2,1],["FST_blaster_scatter_cell_SBB3_Green",15,8],[["IDA_VibroKnife","","","",[],[],""],2]]],"ls_mandalorianHelmet_ordoGrunt","",[],["ItemMap","ItemGPS","ls_radios_hush98_aurebesh","","","ls_mandalorian_rangefinder"]]};
if ( _loadoutchoice == 3) then { _unit setUnitLoadout [["FST_SBB3","","","",["FST_blaster_scatter_cell_SBB3_Green",8],[],""],[],["WBK_SciFi_Sword_4","","","",["WBK_Cybercrystal",30],[],""],["FST_MandoUndersuitUni",[["JLTS_credits_10", _10amount],["JLTS_credits_50", _50amount],[ _rich0,1],[ _rich1,1],[ _rich2,1],[ _case0,1],[ _cam0,1],[ _datapad0,1],[ _datapad1, _padchoice],[ _device0,1],[ _device1,1],[ _intel0,1],[ _intel1, _intelchoice0],[ _intel2, _intelchoice1],["WBK_HeadLampItem_Double",1],[ _selectcomm,1],["JLTS_drugs_deathstick", _dschoice]]],["ls_mandalorianVest_ordoGrunt",[["IDA_BactaBandage",10],["IDA_BattleStim",2],["ACE_tourniquet",2],["ACE_splint",2],[["Weap_melee_knife","","","",[],[],""],1]]],["ls_mandalorianBackpack_demo",[["IDA_grenade_Sonic_mag",3,1],["IDA_grenade_Smoke_mag",3,1],["DBA_UT5_x3_Grenade",2,3],["JMSLLTE_C25_HandGrenade",2,1],["JMSLLTE_dioxis_HandGrenade",2,1],["ls_grenade_n20_magazine",2,1],["FST_blaster_scatter_cell_SBB3_Green",15,8],[["IDA_VibroKnife","","","",[],[],""],2]]],"ls_mandalorianHelmet_ordoGrunt","",[],["ItemMap","ItemGPS","ls_radios_hush98_aurebesh","","","ls_mandalorian_rangefinder"]]};
if ( _loadoutchoice == 4) then { _unit setUnitLoadout [["OPTRE_CQS48_Bulldog_Automatic_Green","OPTRE_M26_LMG_Comp","","",["OPTRE_12Rnd_12Gauge_Pellets_Tracer",12],[],""],[],["WBK_SciFi_Sword_4","","","",["WBK_Cybercrystal",30],[],""],["FST_MandoUndersuitUni",[["JLTS_credits_10", _10amount],["JLTS_credits_50", _50amount],[ _rich0,1],[ _rich1,1],[ _rich2,1],[ _case0,1],[ _cam0,1],[ _datapad0,1],[ _datapad1, _padchoice],[ _device0,1],[ _device1,1],[ _intel0,1],[ _intel1, _intelchoice0],[ _intel2, _intelchoice1],["WBK_HeadLampItem_Double",1],[ _selectcomm,1],["JLTS_drugs_deathstick", _dschoice]]],["ls_mandalorianVest_ordoGrunt",[["IDA_BactaBandage",10],["IDA_BattleStim",2],["ACE_tourniquet",2],["ACE_splint",2],[["Weap_melee_knife","","","",[],[],""],1]]],["ls_mandalorianBackpack_demo",[["IDA_grenade_Sonic_mag",3,1],["IDA_grenade_Smoke_mag",3,1],["DBA_UT5_x3_Grenade",2,3],["JMSLLTE_C25_HandGrenade",2,1],["JMSLLTE_dioxis_HandGrenade",2,1],["ls_grenade_n20_magazine",2,1],["OPTRE_12Rnd_12Gauge_Pellets_Tracer",15,12],[["IDA_VibroKnife","","","",[],[],""],2]]],"ls_mandalorianHelmet_ordoGrunt","",[],["ItemMap","ItemGPS","ls_radios_hush98_aurebesh","","","ls_mandalorian_rangefinder"]]};

_unit setSkill ['aimingAccuracy',0.7];
_unit setSkill ['aimingShake',0.7];
_unit setSkill ['aimingSpeed',0.7];
_unit setSkill ['spotDistance',0.7];
_unit setSkill ['spotTime',0.7];
_unit setSkill ['courage',0.9];
_unit setSkill ['commanding',0.5];
_unit setSkill ['reloadSpeed',0.7];
_unit setSkill ['general',0.7];
_unit allowFleeing 0;

private _chosenhead = selectRandom _list_41mandoheads;

["FST_applyIdentity", [ _unit, _chosenhead, "ACE_NoVoice"]] call CBA_fnc_globalEvent;
_unit disableAI "RADIOPROTOCOL";

};