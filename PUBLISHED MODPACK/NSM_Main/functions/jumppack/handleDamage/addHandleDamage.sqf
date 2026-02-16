#include "\nsm_Main\_include\macros.hpp"
//copy of aces addons\medical_engine\XEH_postInit.sqf, that just passes to nsm handler
params [["_unit",ace_player,[ace_player]]];

if (unitIsUAV _unit) exitWith {;};
if (getNumber (configOf _unit >> "isPlayableLogic") == 1) exitWith {;};

private _allHitPoints = getAllHitPointsDamage _unit param [0, []];
if ((ace_medical_engine_customHitpoints arrayIntersect _allHitPoints) isNotEqualTo ace_medical_engine_customHitpoints) exitWith {
	diag_log text format ['[%1] (%2) %3: %4', toUpper 'ace', 'medical_engine', 'ERROR', format["Bad hitpoints for unit type ""%1""", typeOf _unit]];
};

if(_unit getVariable["NSM_Jumppack_handleDamageEHID",-1] == -1) then {
	_unit setVariable [
		"NSM_Jumppack_handleDamageEHID",
		_unit addEventHandler ["HandleDamage", {
			_this call NSM_jumppack_fnc_handle_damage;
		}]
	];
};