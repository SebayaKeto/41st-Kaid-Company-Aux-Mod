
params ["_unit"];

if (isNull _unit) exitWith {};
if (!local _unit) exitWith {}; 

if (_unit getVariable ["FST_Initialized", false]) exitWith {};
_unit setVariable ["FST_Initialized", true, true];

["FST_applyName", [ _unit, "Nyvar Reprogrammed B1 Battledroid"]] call CBA_fnc_globalEvent;

[_unit] spawn {

params ["_unit"];

if (isNull _unit) exitWith {};

sleep 0.05;

if (isNull _unit) exitWith {};
if (!local _unit) exitWith {};

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

private _wanted0 = selectRandom _list_41nyvarwanted;
private _wanted1 = selectRandom _list_41nyvarwanted;

private _wantarray = [0, 0.7, 1, 0.3];
private _wantchoice = selectRandomWeighted _wantarray;

private _ammoarray = [5, 0.2, 6, 0.4, 7, 0.4, 8, 0.4, 9, 0.2, 10, 0.1];

private _pweaponchoice = "hold";
private _pammochoice = "hold";
private _pammoamount = selectRandomWeighted _ammoarray;
private _proundamount = 0;

private _weparray = [0, 0.6, 1, 0.3, 2, 0.1];

private _ptypechoice = selectRandomWeighted _weparray;

if ( _ptypechoice == 0) then { _pweaponchoice = "FST_E5"; _pammochoice = "FST_Droid_blaster_cell_Red"; _proundamount = 60;};
if ( _ptypechoice == 1) then { _pweaponchoice = "FST_E5C_Stock"; _pammochoice = "FST_Droid_blaster_battery_Red"; _proundamount = 300;};
if ( _ptypechoice == 2) then { _pweaponchoice = "FST_E5S"; _pammochoice = "FST_Droid_blaster_cell_Overcharged_Red"; _proundamount = 10;};

_unit setUnitLoadout [[ _pweaponchoice,"","","",[ _pammochoice, _proundamount],[],""],[],[],["FST_U_Nyvar_B1_Armor",[[ _pammochoice, _pammoamount, _proundamount],[ _wanted0,1],[ _wanted1, _wantchoice]]],[],[],"","",[],["ItemMap","","JLTS_droid_comlink","ItemCompass","","JLTS_NVG_droid_chip_1"]];

_unit setSkill ['aimingAccuracy',0.5];
_unit setSkill ['aimingShake',0.5];
_unit setSkill ['aimingSpeed',0.7];
_unit setSkill ['spotDistance',0.5];
_unit setSkill ['spotTime',0.7];
_unit setSkill ['courage',0.3];
_unit setSkill ['commanding',0.5];
_unit setSkill ['reloadSpeed',0.5];
_unit setSkill ['general',0.5];
_unit allowFleeing 0;

};
