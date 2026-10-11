// FST_medOps_fnc_onTreatment
// ACE event "ace_treatmentSucceded", on the medic's machine. Sends one stat line to the server for treatments a
// player gives to someone else. Keys: treat (always), bacta (PAK / bacta tank), bandage (any bandage-category
// action), underFire (an enemy within 75 m at the time).
// Arguments (ACE): 0: medic, 1: patient, 2: body part, 3: treatment classname

params ["_medic", "_patient", "", "_classname"];
if (!(missionNamespace getVariable ["FST_medOps_report", true])) exitWith {};
if (isNull _medic || {_medic == _patient} || {!isPlayer _medic} || {!local _medic}) exitWith {};
private _keys = ["treat"];
if (_classname in ["FST_Bacta_Tank", "PersonalAidKit"]) then { _keys pushBack "bacta"; };
if (getText (configFile >> "ACE_Medical_Treatment_Actions" >> _classname >> "category") == "bandage") then { _keys pushBack "bandage"; };
private _side = side group _medic;
if (((_medic nearEntities ["CAManBase", 75]) findIf { alive _x && {[_side, side group _x] call BIS_fnc_sideIsEnemy} }) >= 0) then {
    _keys pushBack "underFire";
};
["FST_medOps_stat", [getPlayerUID _medic, name _medic, _keys, getPlayerUID _patient]] call CBA_fnc_serverEvent;
