FST_HCSpawn_fnc_burnsArmorPulseEnd=compile preprocessFileLineNumbers "fn_burnsArmorPulseEnd.sqf";
FST_HCSpawn_fnc_burnsArmorAssist=compile preprocessFileLineNumbers "fn_burnsArmorAssist.sqf";
FST_HCSpawn_fnc_combatTaskTick=compile preprocessFileLineNumbers "fn_combatTaskTick.sqf";
Q_fnc_ownerProbe = {
 params ["_g","_label"];
 private _result=[_label,clientOwner,local _g,groupOwner _g,count units _g,formation _g];
 diag_log format ["[QUAL_OWNER] %1",_result];
 missionNamespace setVariable ["Q_owner_"+_label,_result]; publicVariableServer ("Q_owner_"+_label);
};
diag_log format ["[QUAL_INIT] server=%1 interface=%2 owner=%3",isServer,hasInterface,clientOwner];
if(isServer)then{[] execVM "run.sqf";};

[] spawn{sleep 15;diag_log format["[QUAL_SAFE_SETTING] owner=%1 AATassist=%2",clientOwner,BURNS_ArmorAssistEnabled]};
