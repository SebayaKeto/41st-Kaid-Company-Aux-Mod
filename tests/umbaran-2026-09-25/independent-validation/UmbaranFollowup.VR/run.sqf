if(!isServer)exitWith{};sleep 15;
FST_HC_CombatTasksEnabled=true;FST_HC_Enabled=false;publicVariable "FST_HC_Enabled";
FST_HC_SafeModeUntil=time+10000;
Q_check={params["_name","_pass",["_data",[]]];diag_log format["[FOLLOW_CHECK] %1",[_name,_pass,_data]]};
0 setFog 0;0 setOvercast 0;setDate[2035,6,15,12,0];setViewDistance 1800;
// Attribute hitpoint expression diagnostics instead of assuming the addon caused them.
{
 diag_log format["[FOLLOW_SPAWN_BEGIN] %1",_x];
 private _probeGroup=createGroup[east,true];private _probe=_probeGroup createUnit[_x,[2000,2000,0],[],0,"NONE"];
 sleep 3;
 diag_log format["[FOLLOW_HITPOINTS] %1",[_x,("true"configClasses(configOf _probe>>"HitPoints"))apply{[configName _x,getText(_x>>"depends")]}]];
 deleteVehicle _probe;deleteGroup _probeGroup;
 diag_log format["[FOLLOW_SPAWN_END] %1",_x];
}forEach["B_Soldier_F","FST_Droid_B1_E5","FST_UmbaranInf_Standard","FST_UmbaranInf_SO"];
private _cfg=configFile>>"CfgGroups">>"East">>"FST_Umbaran_Faction">>"FST_Umbaran";
private _cases=[];
for "_rep" from 0 to 2 do{
 {
  private _class=_x;private _base=[3000+3000*_rep,3000+4000*_forEachIndex,0];
  private _g=grpNull;
  if(_class=="UmbaranFireteam")then{_g=[_base,east,_cfg>>"FST_S_UM_Fireteam"]call BIS_fnc_spawnGroup}else{
   _g=createGroup[east,true];for "_i" from 0 to 5 do{_g createUnit["FST_Droid_B1_E5",_base vectorAdd[_i*3,0,0],[],0,"NONE"]};
  };
  _g setVariable["FST_HC_noTransfer",true,true];_g setVariable["FST_HC_blacklisted",true,true];
  private _eg=createGroup[west,true];private _target=_eg createUnit["B_Soldier_F",_base vectorAdd[0,140,0],[],0,"NONE"];
  _target allowDamage false;_target disableAI "ALL";_target setUnitPos "UP";
  {_x allowDamage false;_x enableSimulationGlobal false;_x setDir 0}forEach units _g;
  _cases pushBack[_rep,_class,_g,_target,_base];
 }forEach["UmbaranFireteam","B1Six"];
};
sleep 5;private _start=diag_tickTime;
{
 _x params["_rep","_class","_g","_target","_base"];
 {
  _x setVariable["Q_first",-1];_x setVariable["Q_shots",0];_x setVariable["Q_start",_start];
  _x addEventHandler["FiredMan",{params["_u"];_u setVariable["Q_shots",(_u getVariable["Q_shots",0])+1];if((_u getVariable["Q_first",-1])<0)then{_u setVariable["Q_first",diag_tickTime-(_u getVariable "Q_start")]}}];
  _x enableSimulationGlobal true;
 }forEach units _g;
 _g setCombatMode "RED";_g setBehaviourStrong "AWARE";
 [_g,"defend",_base,200]call FST_HCSpawn_fnc_setCombatTask;
}forEach _cases;
for "_i" from 1 to 18 do{
 sleep 5;
 {
  _x params["_rep","_class","_g","_target"];
  diag_log format["[FOLLOW_DETECT] %1",[_rep,_class,_i*5,leader _g knowsAbout _target,units _g apply{_x getVariable["Q_first",-1]},units _g apply{_x getVariable["Q_shots",0]}]];
 }forEach _cases;
};
{
 _x params["_rep","_class","_g","_target"];
 private _shots=0;private _first=[];
 {_shots=_shots+(_x getVariable["Q_shots",0]);private _f=_x getVariable["Q_first",-1];if(_f>=0)then{_first pushBack _f}}forEach units _g;
 diag_log format["[FOLLOW_DEFEND] %1",[_rep,_class,_shots,if(count _first>0)then{selectMin _first}else{-1},leader _g knowsAbout _target]];
 [format["defend eventually engages %1 repeat %2",_class,_rep],_shots>0]call Q_check;
 [_g,"stop"]call FST_HCSpawn_fnc_setCombatTask;
 {deleteVehicle _x}forEach units _g;deleteVehicle _target;deleteGroup _g;
}forEach _cases;
private _groups=[];
{
 private _base=[3000+1800*_forEachIndex,12000,0];
 private _g=[_base,east,_x]call BIS_fnc_spawnGroup;
 _g setVariable["FST_HC_noTransfer",true,true];_g setVariable["FST_HC_blacklisted",true,true];
 _groups pushBack[configName _x,_g,_base];
}forEach("true"configClasses _cfg);
sleep 5;
{
 _x params["_name","_g","_base"];
 ["assault order accepted "+_name,[_g,"assault",_base vectorAdd[0,120,0],50]call FST_HCSpawn_fnc_setCombatTask]call Q_check;
 _x pushBack(getPosATL leader _g);
 {
  if(typeOf _x in ["FST_UmbaranInf_AT","FST_UmbaranInf_AA"])then{
   ["launcher loaded "+typeOf _x,secondaryWeapon _x!="" && {count secondaryWeaponMagazine _x>0},[secondaryWeapon _x,secondaryWeaponMagazine _x]]call Q_check;
  };
 }forEach units _g;
}forEach _groups;
sleep 45;
{
 _x params["_name","_g","_base","_start"];
 ["group advances "+_name,leader _g distance2D _start>10,[leader _g distance2D _start]]call Q_check;
 [_g,"stop"]call FST_HCSpawn_fnc_setCombatTask;
 ["stop clears task and restores path "+_name,count([_g,["FST_HC_combatTask",[]]]call FST_HCSpawn_fnc_burnsStateGet)==0 && {units _g findIf{!(_x checkAIFeature "PATH")}<0}]call Q_check;
 {deleteVehicle _x}forEach units _g;deleteGroup _g;
}forEach _groups;
diag_log "[FOLLOW_DONE]";
