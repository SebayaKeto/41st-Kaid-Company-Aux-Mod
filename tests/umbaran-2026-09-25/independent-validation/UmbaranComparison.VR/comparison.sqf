// Eighteen matched 4v4 fights: six contexts, three unit classes.
// All weapons fire through native AI; no reveal, forced fire or scripted damage.
// Cases run in separate lanes. Swap lanes to reduce placement bias.
diag_log "[CMP_START]";
private _allBefore=allUnits;
{if(!isPlayer _x)then{deleteVehicle _x}}forEach _allBefore;
sleep 3;
0 setFog 0;0 setOvercast 0;setDate[2035,6,15,12,0];setViewDistance 1800;
east setFriend[west,0];west setFriend[east,0];
private _classes=["FST_Droid_B1_E5","FST_UmbaranInf_Standard","FST_UmbaranInf_SO"];
private _scenarios=[["defend",120,false],["assault",120,false],["hunt",180,false],["defend",180,true],["assault",180,true],["hunt",120,true]];
{
 _x params["_mode","_range","_cover"];
 private _round=_forEachIndex;private _cases=[];
 {
  private _class=_x;private _lane=(_forEachIndex+_round)mod 3;
  private _base=[3000+3000*_lane,10000,0];private _goal=_base vectorAdd[0,_range,0];
  private _g=createGroup[east,true];private _enemy=createGroup[west,true];
  {_x setVariable["FST_HC_noTransfer",true,true];_x setVariable["FST_HC_blacklisted",true,true]}forEach[_g,_enemy];
  private _props=[];
  if(_cover)then{
   for "_i" from 0 to 3 do{
    private _p=createVehicle["Land_BagFence_Long_F",_base vectorAdd[(_i-1.5)*8,14,0],[],0,"CAN_COLLIDE"];
    _p setDir 0;_props pushBack _p;
   };
  };
  for "_i" from 0 to 3 do{
   private _u=_g createUnit[_class,_base vectorAdd[(_i-1.5)*6,0,0],[],0,"NONE"];
   private _v=_enemy createUnit["B_Soldier_F",_goal vectorAdd[(_i-1.5)*6,0,0],[],0,"NONE"];
   _u enableSimulationGlobal false;_v enableSimulationGlobal false;
   _u setDir 0;_v setDir 180;_v setSkill 0.5;
  };
  _cases pushBack[_class,_g,_enemy,_base,_goal,_props];
 }forEach _classes;
 sleep 5;
 private _start=diag_tickTime;
 {
  _x params["_class","_g","_enemy","_base","_goal"];
  {
   _x setVariable["CMP_shots",0];_x setVariable["CMP_firstShot",-1];_x setVariable["CMP_start",_start];
   _x addEventHandler["FiredMan",{params["_u"];_u setVariable["CMP_shots",(_u getVariable["CMP_shots",0])+1];if((_u getVariable["CMP_firstShot",-1])<0)then{_u setVariable["CMP_firstShot",diag_tickTime-(_u getVariable "CMP_start")]}}];
  }forEach(units _g+units _enemy);
  {_x enableSimulationGlobal true}forEach(units _g+units _enemy);
  _g setCombatMode "RED";_g setBehaviourStrong "AWARE";
  _enemy setCombatMode "RED";_enemy setBehaviourStrong "AWARE";
  [_g,_mode,if(_mode=="defend")then{_base}else{_goal},160]call FST_HCSpawn_fnc_setCombatTask;
  _x pushBack(units _g);_x pushBack(units _enemy);_x pushBack [];
  diag_log format["[CMP_PROFILE] %1",[_round,_class,units _g apply{[typeOf _x,primaryWeapon _x,_x skill "general",_x skill "aimingAccuracy",_x skill "spotTime",_x skill "aimingSpeed"]}]];
 }forEach _cases;
 for "_sample" from 1 to 15 do{
  sleep 5;
  {
   _x params["_class","_g","_enemy","_base","_goal","_props","_us","_vs","_tactics"];
   private _tactic=_g getVariable["BURNS_lastTactic",""];
   if(_tactic!="")then{_tactics pushBackUnique _tactic};
   diag_log format["[CMP_TICK] %1",[_round,_class,_sample,diag_fps,{alive _x && {lifeState _x!="INCAPACITATED"}}count _us,{alive _x && {lifeState _x!="INCAPACITATED"}}count _vs,_tactic,_us apply{stance _x},getPosATL leader _g]];
  }forEach _cases;
 };
 {
  _x params["_class","_g","_enemy","_base","_goal","_props","_us","_vs","_tactics"];
  private _shots=0;private _enemyShots=0;private _first=[];
  {_shots=_shots+(_x getVariable["CMP_shots",0]);private _s=_x getVariable["CMP_firstShot",-1];if(_s>=0)then{_first pushBack _s}}forEach _us;
  {_enemyShots=_enemyShots+(_x getVariable["CMP_shots",0])}forEach _vs;
  private _active={alive _x && {lifeState _x!="INCAPACITATED"}}count _us;
  private _enemyActive={alive _x && {lifeState _x!="INCAPACITATED"}}count _vs;
  diag_log format["[CMP_RESULT] %1",[_round,_mode,_range,_cover,_class,_active,_enemyActive,_shots,_enemyShots,if(count _first>0)then{selectMin _first}else{-1},_tactics,_us apply{_x distance2D _base}]];
  [_g,"stop"]call FST_HCSpawn_fnc_setCombatTask;
  {deleteVehicle _x}forEach(_us+_vs+_props);deleteGroup _g;deleteGroup _enemy;
 }forEach _cases;
 sleep 3;
}forEach _scenarios;
diag_log "[CMP_DONE]";
