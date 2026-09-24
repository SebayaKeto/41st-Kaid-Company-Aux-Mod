Q_fnc_request=compile preprocessFileLineNumbers "functions\fn_request.sqf";
if(isServer)then{
Q_fnc_simopen=compile preprocessFileLineNumbers "sim_open.sqf";Q_fnc_simaction=compile preprocessFileLineNumbers "sim_action.sqf";Q_fnc_simclose=compile preprocessFileLineNumbers "sim_close.sqf";
Q_fnc_replay={if(!isServer)exitWith{};params["_kind","_args","_qaSender"];switch(_kind)do{case "OPEN":{_args call Q_fnc_simopen};case "ACTION":{_args call Q_fnc_simaction};case "CLOSE":{_args call Q_fnc_simclose}}};
[]execVM "run.sqf";};