params["_node"];
private _check={params["_label","_pass",["_detail",[]]];diag_log format["[GUL_CHECK] %1",[_node,_label,_pass,_detail]]};
private _base=[13000+_node*450,15400,0];
private _g=createGroup[east,true];_g setVariable["FST_HC_noTransfer",true,true];
private _units=[];private _starts=[];
for "_i" from 0 to 7 do{
 private _p=_base vectorAdd[4*(_i mod 4),-6*floor(_i/4),0];
 private _u=_g createUnit[["JMSEF_animals_varren_o","JMSEF_animals_var_bers_o","JMSEF_animals_var_alpha_o"]select(_i mod 3),_p,[],0,"NONE"];
 _u allowDamage false;_u setDir 0;_units pushBack _u;_starts pushBack _p;
};
private _tg=createGroup[west,true];_tg setVariable["FST_HC_noTransfer",true,true];_tg setVariable["BURNS_exempt",true,true];
private _t=_tg createUnit["B_Soldier_F",_base vectorAdd[0,80,0],[],0,"NONE"];_t allowDamage false;_t disableAI "ALL";
sleep 5;private _fast=[0,0,0,0,0,0,0,0];private _stop=+_fast;private _gait=+_fast;
for "_i" from 1 to 100 do{
 _t setPosATL((getPosATL leader _g)vectorAdd[0,80,0]);sleep 0.25;
 {
  if(speed _x>15)then{_fast set[_forEachIndex,(_fast select _forEachIndex)+1]};
  if(abs speed _x<1)then{_stop set[_forEachIndex,(_stop select _forEachIndex)+1]};
  if(animationState _x=="burns_gulanthar_run")then{_gait set[_forEachIndex,(_gait select _forEachIndex)+1]};
 }forEach _units;
};
private _distances=[];{_distances pushBack(_x distance2D(_starts select _forEachIndex))}forEach _units;
["eight-creature pack advances",(_distances findIf{_x<50})<0,_distances]call _check;
["bounded service reaches every pack member",(_gait findIf{_x==0})<0,[_fast,_stop,_gait]]call _check;
["pack keeps native animation speed",(_units findIf{getAnimSpeedCoef _x!=1})<0]call _check;
_g setVariable["FST_HC_heldBy",2,true];sleep 2;
["pack Zeus hold releases all custom gaits",(_units findIf{animationState _x in["burns_gulanthar_run","burns_gulanthar_climb"]})<0]call _check;
{deleteVehicle _x}forEach _units;deleteVehicle _t;deleteGroup _g;deleteGroup _tg;
diag_log format["[GUL_PACK_DONE] %1",[_node,clientOwner]];
