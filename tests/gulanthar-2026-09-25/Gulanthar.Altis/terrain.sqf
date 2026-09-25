params["_node"];
if(_node!=0)exitWith{diag_log format["[GUL_TERRAIN_IDLE] %1",[_node,clientOwner]]};
private _check={params["_label","_pass",["_detail",[]]];diag_log format["[GUL_CHECK] %1",[_node,_label,_pass,_detail]]};
setDate[2035,6,15,12,0];0 setFog 0;0 setOvercast 0;
private _slope=[6500,18700,0];private _n=surfaceNormal _slope;private _up=vectorNormalized[-(_n select 0),-(_n select 1),0];
{
 private _case=_x;private _rows=[];
 {
  private _class=_x;private _base=_slope vectorAdd[12*_forEachIndex,0,0];
  private _start=if(_case=="uphill")then{_base}else{_base vectorAdd(_up vectorMultiply 85)};
  private _goal=if(_case=="uphill")then{_base vectorAdd(_up vectorMultiply 85)}else{_base};
  private _g=createGroup[east,true];_g setVariable["FST_HC_noTransfer",true,true];
  private _u=_g createUnit[_class,_start,[],0,"NONE"];_u setPosATL _start;_u allowDamage false;_u setDir(_u getDir _goal);
  private _tg=createGroup[west,true];_tg setVariable["FST_HC_noTransfer",true,true];_tg setVariable["BURNS_exempt",true,true];
  private _t=_tg createUnit["B_Soldier_F",_goal,[],0,"NONE"];_t setPosATL _goal;_t allowDamage false;_t disableAI "ALL";_g reveal[_t,4];
  _rows pushBack[_u,_t,_g,_tg,_start,[],_class];
 }forEach["JMSEF_animals_varren_o","JMSEF_animals_var_bers_o","JMSEF_animals_var_alpha_o"];
 for "_i" from 1 to 120 do{
  sleep 0.25;
  {
   _x params["_u","_t","_g","","_start","_samples","_class"];
   _g reveal[_t,4];private _row=[animationState _u,speed _u,_u distance2D _start,_u distance _t,_u checkAIFeature "ANIM",getPosATL _u];_samples pushBack _row;
   diag_log format["[GUL_TERRAIN_SAMPLE] %1",[_case,_class,_i,_row]];
  }forEach _rows;
 };
 {
  _x params["_u","_t","_g","_tg","_start","_samples","_class"];
  [_case+" advances "+_class,_u distance2D _start>20,[_u distance2D _start,_u distance _t]]call _check;
  [_case+" valid graph "+_class,(_samples findIf{(_x select 0)in["","<none>"]})<0]call _check;
  if(_case=="uphill")then{["climbing gait used "+_class,(_samples findIf{(_x select 0)=="burns_gulanthar_climb"})>=0]call _check};
  ["native coefficient on "+_case+" "+_class,getAnimSpeedCoef _u==1]call _check;
  deleteVehicle _u;deleteVehicle _t;deleteGroup _g;deleteGroup _tg;
 }forEach _rows;sleep 2;
}forEach["uphill","downhill"];
diag_log format["[GUL_TERRAIN_DONE] %1",[_node,clientOwner]];
