Q_fnc_peerSpeed={params["_u","_node"];diag_log format["[BXE_PEER] %1",[_node,clientOwner,local _u,getAnimSpeedCoef _u]];};


Q_fnc_stance=compile preprocessFileLineNumbers "guards.sqf";
if(isServer)then{[]spawn{sleep 15; FST_HC_Enabled=false;publicVariable "FST_HC_Enabled";FST_HC_SafeModeUntil=time+10000;private _deadline=time+60;waitUntil{sleep 1;count((entities "HeadlessClient_F")select{isPlayer _x && {owner _x>2}})>=4 || {time>_deadline}}; [0]spawn Q_fnc_stance;{[_forEachIndex+1]remoteExec["Q_fnc_stance",owner _x]}forEach((entities "HeadlessClient_F")select{isPlayer _x && {owner _x>2}});};};