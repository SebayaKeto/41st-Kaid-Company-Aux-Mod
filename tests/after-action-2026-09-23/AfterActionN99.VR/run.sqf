if(!isServer)exitWith{};sleep 15;
Q_checks=[];Q_check={params["_name","_pass",["_detail",[]]];Q_checks pushBack[_name,_pass,_detail];diag_log format["[AF_CHECK] %1",[_name,_pass,_detail]]};
private _until=time+60;waitUntil{sleep 1;count(allPlayers select{_x isKindOf "HeadlessClient_F"})>=4 || {time>_until}};
private _owners=(allPlayers select{_x isKindOf "HeadlessClient_F"})apply{owner _x};
["N99 fixture has four HCs",count _owners==4,_owners]call Q_check;
private _rows=[];
for "_i" from 0 to 1 do{
 private _p=[1000+_i*1000,1000,0];private _v=createVehicle["FST_N99",_p,[],0,"NONE"];createVehicleCrew _v;_v allowDamage false;
 private _g=group driver _v;_g setVariable["FST_HC_blacklisted",true,true];_g setVariable["FST_HC_keepActive",true,true];
 ["BURNS_request",["assault",[_g],[_v],_p vectorAdd[0,120,0],500,[],2]]call CBA_fnc_serverEvent;
 _rows pushBack[_v,_g,_p];
};
sleep 25;
{
 _x params["_v","_g","_p"];["N99 initial advance "+str _forEachIndex,_v distance2D _p>30,getPosATL _v]call Q_check;
 private _start=getPosATL _v;_x set[2,_start];_g setGroupOwner(_owners param[_forEachIndex,2]);
 ["BURNS_request",["assault",[_g],[_v],_start vectorAdd[0,160,0],500,[],2]]call CBA_fnc_serverEvent;
}forEach _rows;
sleep 40;
{
 _x params["_v","_g","_p"];["N99 HC transfer replacement moves "+str _forEachIndex,_v distance2D _p>30,[groupOwner _g,_v distance2D _p,getPosATL _v,_g getVariable["FST_HC_combatTask",[]]]]call Q_check;
 private _start=getPosATL _v;_x set[2,_start];_g setGroupOwner 2;
 ["BURNS_request",["assault",[_g],[_v],_start vectorAdd[0,160,0],500,[],2]]call CBA_fnc_serverEvent;
}forEach _rows;
sleep 40;
{_x params["_v","_g","_p"];["N99 return-server replacement moves "+str _forEachIndex,_v distance2D _p>30,[groupOwner _g,_v distance2D _p,getPosATL _v,_g getVariable["FST_HC_combatTask",[]]]]call Q_check}forEach _rows;
diag_log format["[AF_DONE] checks=%1 failed=%2",count Q_checks,{!(_x select 1)}count Q_checks];
