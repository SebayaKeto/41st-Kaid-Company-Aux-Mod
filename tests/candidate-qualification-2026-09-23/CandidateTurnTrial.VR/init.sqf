Q_fnc_ownerProbe = {
 params ["_g","_label"];
 private _result=[_label,clientOwner,local _g,groupOwner _g,count units _g,formation _g];
 diag_log format ["[QUAL_OWNER] %1",_result];
 missionNamespace setVariable ["Q_owner_"+_label,_result]; publicVariableServer ("Q_owner_"+_label);
};
diag_log format ["[QUAL_INIT] server=%1 interface=%2 owner=%3",isServer,hasInterface,clientOwner];
if(isServer)then{[] execVM "run.sqf";};
