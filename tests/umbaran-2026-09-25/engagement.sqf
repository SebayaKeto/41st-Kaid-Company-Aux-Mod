// Controlled engagement: exposed hostile AI targets, no reveal/doFire assistance.
private _cases=[];
private _groupCfg=configFile>>"CfgGroups">>"East">>"FST_Umbaran_Faction">>"FST_Umbaran";
{
 _x params["_preset","_mode"];
 private _base=[8000+600*_forEachIndex,8000,0];
 private _g=[_base,east,_groupCfg>>_preset]call BIS_fnc_spawnGroup;
 private _enemy=createGroup[west,true];private _target=_enemy createUnit["B_Soldier_F",_base vectorAdd[0,140,0],[],0,"NONE"];
 _target allowDamage false;_target disableAI "ALL";_target setUnitPos "UP";
 {_x allowDamage false;_x setDir 0;_x setVariable["Q_rounds",0];_x addEventHandler["FiredMan",{params["_u"];_u setVariable["Q_rounds",(_u getVariable["Q_rounds",0])+1]}]}forEach units _g;
 _g setCombatMode "RED";_g setBehaviourStrong "AWARE";
 [_g,_mode,if(_mode=="hunt")then{getPosATL _target}else{_base},200]call FST_HCSpawn_fnc_setCombatTask;
 _cases pushBack[_preset,_mode,_g,_target,_base];
}forEach[["FST_S_UM_Fireteam","defend"],["FST_S_UM_Standard","assault"],["FST_S_UM_SOTeam","hunt"]];
sleep 30;
{
 _x params["_preset","_mode","_g","_target","_base"];
 private _fired=0;{_fired=_fired+(_x getVariable["Q_rounds",0])}forEach units _g;
 ["engages exposed hostile "+_preset+" / "+_mode,_fired>0,[_fired,leader _g knowsAbout _target,_g getVariable["BURNS_lastTactic",""],getPosATL leader _g]]call Q_check;
 ["retains human cover policy "+_preset,units _g findIf{!(_x checkAIFeature "COVER") || {!isNil{_x getVariable "BURNS_b1Applied"}}}<0]call Q_check;
 [_g,"stop"]call FST_HCSpawn_fnc_setCombatTask;
 {deleteVehicle _x}forEach units _g;private _eg=group _target;deleteVehicle _target;deleteGroup _g;deleteGroup _eg;
}forEach _cases;
