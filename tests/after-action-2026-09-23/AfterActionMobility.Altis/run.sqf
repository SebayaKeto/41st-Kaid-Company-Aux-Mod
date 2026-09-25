if(!isServer)exitWith{};sleep 15;
Q_checks=[];Q_check={params["_name","_pass",["_detail",[]]];Q_checks pushBack[_name,_pass,_detail];diag_log format["[MOB_CHECK] %1",[_name,_pass,_detail]]};
Q_delete={params["_g"];{deleteVehicle _x}forEach units _g;deleteGroup _g};
Q_candidateArmor=FST_HCSpawn_fnc_burnsArmorAssist;Q_candidateEnd=FST_HCSpawn_fnc_burnsArmorPulseEnd;Q_candidateTick=FST_HCSpawn_fnc_combatTaskTick;Q_candidateGait=FST_HCSpawn_fnc_burnsGulantharSlope;
Q_baselineArmor=compile preprocessFileLineNumbers "baseline_fn_burnsArmorAssist.sqf";Q_baselineEnd=compile preprocessFileLineNumbers "baseline_fn_burnsArmorPulseEnd.sqf";Q_baselineTick=compile preprocessFileLineNumbers "baseline_fn_combatTaskTick.sqf";Q_baselineGait=compile preprocessFileLineNumbers "baseline_fn_burnsGulantharSlope.sqf";
setDate[2035,6,15,12,0];0 setFog 0;0 setOvercast 0;
// Select clear natural terrain. No changes to terrain height in this run.
Q_slope=[];Q_up=[];
for "_px" from 6500 to 14500 step 100 do {
 if(count Q_slope>0)exitWith{};
 for "_py" from 11000 to 19000 step 100 do {
  private _p=[_px,_py,0];private _n=surfaceNormal _p;private _angle=acos(_n select 2);
  if(_angle>12 && {_angle<28} && {getTerrainHeightASL _p>20})then{
   private _up=vectorNormalized[-(_n select 0),-(_n select 1),0];
   private _end=_p vectorAdd(_up vectorMultiply 85);
   private _endAngle=acos((surfaceNormal _end)select 2);
   if(_endAngle>8 && {_endAngle<30} && {getTerrainHeightASL _end-getTerrainHeightASL _p>10} && {count(nearestTerrainObjects[_p,["TREE","SMALL TREE","BUSH","ROCK","ROCKS","HOUSE"],8,false,true])==0})exitWith{Q_slope=_p;Q_up=_up};
  };
 };
};
["clear natural slope found",count Q_slope==3,[Q_slope,Q_up]]call Q_check;
Q_flat=[14500,16000,0];

// Find a shared clear flat lane once; both variants reuse exactly that lane.
for "_px" from 13000 to 16000 step 100 do {private _found=false;for "_py" from 15000 to 18000 step 100 do {private _p=[_px,_py,0];if((surfaceNormal _p select 2)>0.998 && {!surfaceIsWater _p} && {count(nearestTerrainObjects[_p,["TREE","SMALL TREE","ROCK","ROCKS","HOUSE","WALL","FENCE"],35,false,true])==0})exitWith{Q_flat=_p;_found=true}};if(_found)exitWith{}};
diag_log format["[MOB_FLAT_LANE] %1",Q_flat];

{
 private _variant=_x;
 FST_HCSpawn_fnc_burnsArmorAssist=if(_variant=="candidate")then{Q_candidateArmor}else{Q_baselineArmor};
 FST_HCSpawn_fnc_burnsArmorPulseEnd=if(_variant=="candidate")then{Q_candidateEnd}else{Q_baselineEnd};
 FST_HCSpawn_fnc_combatTaskTick=if(_variant=="candidate")then{Q_candidateTick}else{Q_baselineTick};
 {
  private _case=_x;private _p=+Q_flat;private _bearing=if(_case=="side")then{90}else{if(_case=="rear")then{180}else{0}};
  if(_case=="slope" && {count Q_slope==3})then{_p=+Q_slope;_bearing=(_p getDir(_p vectorAdd Q_up))};
  private _v=createVehicle["FST_AAT",_p,[],0,"CAN_COLLIDE"];_v setDir 0;createVehicleCrew _v;_v allowDamage false;
  private _g=group driver _v;_g setVariable["FST_HC_blacklisted",true,true];_g setCombatMode "RED";{_x allowDamage false}forEach crew _v;
  private _t=createVehicle["B_MRAP_01_hmg_F",_p getPos[200,_bearing],[],0,"NONE"];createVehicleCrew _t;_t allowDamage false;
  {group _x setVariable["FST_HC_blacklisted",true,true];group _x setVariable["BURNS_exempt",true,true];_x allowDamage false;_x disableAI "ALL"}forEach crew _t;
  private _blocks=[];
  if(_case=="obstacle")then{for "_i" from -1 to 1 do{private _w=createVehicle["Land_HBarrierBig_F",_p vectorAdd[_i*6,14,0],[],0,"CAN_COLLIDE"];_w allowDamage false;_blocks pushBack _w}};
  _v setVariable["Q_shots",0];_v addEventHandler["Fired",{params["_v"];_v setVariable["Q_shots",(_v getVariable["Q_shots",0])+1]}];
  _g reveal[_t,4];[_g,"rush",getPosATL _t,500]call FST_HCSpawn_fnc_setCombatTask;
  diag_log format["[MOB_START] %1",[_variant,_case,getPosATL _v,getPosATL _t]];private _samples=[];private _turns=missionNamespace getVariable["BURNS_ArmorTurnPulses",0];private _start=getPosATL _v;
  for "_i" from 1 to 60 do{sleep 0.5;_samples pushBack[abs((((_v getDir _t)-(getDir _v)+540)mod 360)-180),velocityModelSpace _v select 1,getPosATL _v,_v getVariable["Q_shots",0],_v getVariable["BURNS_driveDetour",[]]]};
  private _late=_samples select[30,30];private _aligned={(_x select 0)<55}count _late;private _reverse={(_x select 1)<-0.5 && {(_x select 0)>90}}count _samples;
  diag_log format["[MOB_ARMOR] %1",[_variant,_case,_v distance2D _start,_aligned,_reverse,(missionNamespace getVariable["BURNS_ArmorTurnPulses",0])-_turns,_v getVariable["Q_shots",0],_samples]];
  ["AAT fires "+_variant+" "+_case,(_v getVariable["Q_shots",0])>0,_v getVariable["Q_shots",0]]call Q_check;
  BURNS_ArmorAssistEnabled=false;sleep 2;
  ["AAT turn cleanup "+_variant+" "+_case,count(_v getVariable["BURNS_armorPulse",[]])==0]call Q_check;
  [_g,"stop"]call FST_HCSpawn_fnc_setCombatTask;
  private _tg=group driver _t;{deleteVehicle _x}forEach crew _v;deleteVehicle _v;deleteGroup _g;{deleteVehicle _x}forEach crew _t;deleteVehicle _t;deleteGroup _tg;{deleteVehicle _x}forEach _blocks;
  BURNS_ArmorAssistEnabled=true;sleep 1;
 }forEach["front","side","rear","obstacle","slope"];
}forEach["baseline","candidate"];
FST_HCSpawn_fnc_burnsArmorAssist=Q_candidateArmor;FST_HCSpawn_fnc_burnsArmorPulseEnd=Q_candidateEnd;FST_HCSpawn_fnc_combatTaskTick=Q_candidateTick;
// All Gulanthar classes with real native controller, flat and natural slopes.
{
 private _case=_x;private _rows=[];
 {
  private _class=_x;private _offset=[_forEachIndex*8,0,0];private _p=if(_case=="flat")then{Q_flat}else{if(_case=="uphill")then{Q_slope}else{Q_slope vectorAdd(Q_up vectorMultiply 85)}};_p=_p vectorAdd _offset;
  private _goal=if(_case=="flat")then{_p vectorAdd[0,85,0]}else{if(_case=="uphill")then{_p vectorAdd(Q_up vectorMultiply 85)}else{_p vectorDiff(Q_up vectorMultiply 85)}};
  private _g=createGroup[east,true];_g setVariable["FST_HC_blacklisted",true,true];private _u=_g createUnit[_class,_p,[],0,"NONE"];_u allowDamage false;_u setDir(_u getDir _goal);
  private _tg=createGroup[west,true];_tg setVariable["FST_HC_blacklisted",true,true];_tg setVariable["BURNS_exempt",true,true];private _t=_tg createUnit["B_Soldier_F",_goal,[],0,"NONE"];_t allowDamage false;_t disableAI "ALL";_g reveal[_t,4];
  _rows pushBack[_class,_u,_t,_g,_tg,getPosATL _u,[]];
 }forEach["JMSEF_animals_varren_o","JMSEF_animals_var_bers_o","JMSEF_animals_var_alpha_o"];
 for "_i" from 1 to 30 do{sleep 1;{_x params["","_u"];(_x select 6)pushBack[animationState _u,speed _u,_u getVariable["mode",-1],_u checkAIFeature "ANIM",getPosATL _u]}forEach _rows};
 {
  _x params["_class","_u","_t","_g","_tg","_start","_samples"];
  ["Gulanthar moves "+_class+" "+_case,_u distance2D _start>10,[_u distance2D _start,_u getVariable["BURNS_creatureRecoveries",0],_samples]]call Q_check;
  ["Gulanthar graph valid "+_class+" "+_case,(_samples findIf{(_x select 0)=="<none>"})<0]call Q_check;
  if(_case=="uphill")then{["Gulanthar climb entered "+_class,(_samples findIf{toLower(_x select 0)=="burns_gulanthar_climb"})>=0]call Q_check};
  [_g]call Q_delete;[_tg]call Q_delete;
 }forEach _rows;
}forEach["flat","uphill","downhill"];
diag_log format["[MOB_DONE] checks=%1 failed=%2",count Q_checks,{!(_x select 1)}count Q_checks];
