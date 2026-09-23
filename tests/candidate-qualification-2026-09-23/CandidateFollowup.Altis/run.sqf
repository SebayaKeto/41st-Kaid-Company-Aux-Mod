if(!isServer)exitWith{};
sleep 15;
Q_checks=[];
Q_check={params["_name","_pass",["_detail",[]]];Q_checks pushBack[_name,_pass,_detail];diag_log format["[QUAL_CHECK] %1",[_name,_pass,_detail]]};
Q_delete={params["_g"];{deleteVehicle _x}forEach units _g;deleteGroup _g};
diag_log "[QUAL_FOLLOWUP_BEGIN]";
private _deadline=diag_tickTime+120;
waitUntil{sleep 1;count(missionNamespace getVariable["FST_HC_Ids",[]])==4 || {diag_tickTime>_deadline}};
["four HCs in followup",count(missionNamespace getVariable["FST_HC_Ids",[]])==4]call Q_check;
// Select clear natural terrain. No changes to terrain height in this run.
Q_slope=[];Q_up=[];
for "_px" from 10500 to 12500 step 100 do {
 if(count Q_slope>0)exitWith{};
 for "_py" from 10500 to 12500 step 100 do {
  private _p=[_px,_py,0];private _n=surfaceNormal _p;private _angle=acos(_n select 2);
  if(_angle>14 && {_angle<25} && {getTerrainHeightASL _p>20})then{
   private _up=vectorNormalized[-(_n select 0),-(_n select 1),0];
   private _end=_p vectorAdd(_up vectorMultiply 85);
   private _endAngle=acos((surfaceNormal _end)select 2);
   if(_endAngle>8 && {_endAngle<30} && {getTerrainHeightASL _end-getTerrainHeightASL _p>15} && {count(nearestTerrainObjects[_p,["TREE","SMALL TREE","BUSH","ROCK","ROCKS","HOUSE"],95,false,true])<3})exitWith{Q_slope=_p;Q_up=_up};
  };
 };
};
["clear natural slope found",count Q_slope==3,[Q_slope,Q_up]]call Q_check;
Q_flat=[14500,16000,0];
if(count Q_slope==3)then{
 {
  private _class=_x;
  {
   private _case=_x;
   private _start=if(_case=="flat")then{Q_flat}else{if(_case=="uphill")then{Q_slope}else{Q_slope vectorAdd(Q_up vectorMultiply 85)}};
   private _end=if(_case=="flat")then{_start vectorAdd[0,85,0]}else{if(_case=="uphill")then{Q_slope vectorAdd(Q_up vectorMultiply 85)}else{Q_slope}};
   private _g=createGroup[east,true];_g setVariable["FST_HC_blacklisted",true,true];_g setVariable["FST_HC_keepActive",true,true];
   private _tg=createGroup[west,true];_tg setVariable["FST_HC_blacklisted",true,true];
   private _u=_g createUnit[_class,_start,[],0,"NONE"];_u allowDamage false;_u setDir(_u getDir _end);
   private _t=_tg createUnit["B_Soldier_F",_end,[],0,"NONE"];_t allowDamage false;_t disableAI "ALL";
   _g reveal[_t,4];sleep 3;private _samples=[];private _startPos=getPosATL _u;
   for "_sample" from 0 to 29 do{_samples pushBack[animationState _u,_u getVariable["mode",-1],speed _u,getPosATL _u,local _u,acos((surfaceNormal getPosATL _u)select 2)];sleep 1};
   private _climbs={toLower(_x select 0)=="burns_gulanthar_climb"}count _samples;
   private _distance=_u distance2D _startPos;
   ["natural movement "+_class+" "+_case,_distance>10,[_distance,_climbs,_samples]]call Q_check;
   ["valid movement graph "+_class+" "+_case,(_samples findIf{(_x select 0)=="<none>"})<0]call Q_check;
   if(_case=="uphill")then{["uphill gait observed "+_class,_climbs>0,_climbs]call Q_check};
   if(_case=="flat")then{["flat gait stays native "+_class,_climbs==0]call Q_check};
   // Exercise the feature switch on the same local creature.
   _u switchMove "BURNS_gulanthar_climb";sleep 0.3;
   BURNS_GulantharSlopeEnabled=false;[_u]call FST_HCSpawn_fnc_burnsGulantharSlope;sleep 1;
   ["gait disable releases "+_class+" "+_case,toLower animationState _u!="burns_gulanthar_climb",animationState _u]call Q_check;
   BURNS_GulantharSlopeEnabled=true;
   if(_case=="flat")then{
    _t setPosATL(_u getPos[2,getDir _u]);private _attack=[];
    for "_j" from 1 to 12 do{_attack pushBack animationState _u;sleep 0.5};
    ["external attack transition "+_class,(_attack findIf{toLower _x find "attack">=0})>=0,_attack]call Q_check;
   };
   [_g]call Q_delete;[_tg]call Q_delete;sleep 1;
  }forEach["flat","uphill","downhill"];
 }forEach["JMSEF_animals_varren_o","JMSEF_animals_var_bers_o","JMSEF_animals_var_alpha_o"];
};
diag_log "[QUAL_CREATURES_DONE]";
private _h=[]execVM "edges.sqf";waitUntil{sleep 1;scriptDone _h};
diag_log format["[QUAL_FOLLOWUP_DONE] checks=%1 failures=%2 fps=%3 maxMs=%4",count Q_checks,Q_checks select{!(_x select 1)},diag_fps,missionNamespace getVariable["BURNS_EngagementMaxMs",-1]];
