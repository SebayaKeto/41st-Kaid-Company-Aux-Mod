diag_log format["[MEAP_PROXY_CONTEXT] %1",[isServer,hasInterface,remoteExecutedOwner]];
if(isServer || hasInterface || remoteExecutedOwner!=2)exitWith{};
params["_kind",["_args",[]]];
diag_log format["[MEAP_PROXY] kind=%1 player=%2 owner=%3 args=%4",_kind,player,clientOwner,_args];
switch(_kind)do{
case "OPEN":{["OPEN",[_args param[0,player]],clientOwner]remoteExecCall["Q_fnc_replay",2]};
case "ACTION":{["ACTION",_args,clientOwner]remoteExecCall["Q_fnc_replay",2]};
case "FOREIGNCLOSE":{["CLOSE",_args,clientOwner]remoteExecCall["Q_fnc_replay",2]};
case "REALOPEN":{[_args param[0,player]]remoteExecCall["MEAP_fnc_requestArchitectMode",2]};
case "REALCLOSE":{_args remoteExecCall["MEAP_fnc_closeArchitectMode",2]};
};
