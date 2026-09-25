Q_hcAction={_this spawn {
 params ["_g","_mode","_key"];
 diag_log format["[AF_HC_REQUEST] %1",[_key,clientOwner,groupOwner _g,local _g,units _g apply{local _x}]];
 private _deadline=time+15;
 waitUntil{sleep 0.1;(local _g && {(units _g findIf{!local _x})<0}) || {time>_deadline}};
 if(_mode!="inspect" && {local _g})then{[_mode,_g,getPosATL leader _g,50,[],2]call FST_HCSpawn_fnc_burnsCommand};
 sleep 2;private _u=leader _g;
 private _r=[clientOwner,local _g,_g getVariable["FST_HC_combatTask",[]],unitPos _u,_u checkAIFeature "PATH",_u checkAIFeature "FIREWEAPON",_u getVariable["BURNS_bxOwned",[]]];
 missionNamespace setVariable[_key,_r];publicVariableServer _key;diag_log format["[AF_HC] %1",[_key,_r]];
};};
Q_fnc_ownerProbe = {
 params ["_g","_label"];
 private _result=[_label,clientOwner,local _g,groupOwner _g,count units _g,formation _g];
 diag_log format ["[QUAL_OWNER] %1",_result];
 missionNamespace setVariable ["Q_owner_"+_label,_result]; publicVariableServer ("Q_owner_"+_label);
};
diag_log format ["[QUAL_INIT] server=%1 interface=%2 owner=%3",isServer,hasInterface,clientOwner];
if(isServer)then{[] execVM "run.sqf";};
