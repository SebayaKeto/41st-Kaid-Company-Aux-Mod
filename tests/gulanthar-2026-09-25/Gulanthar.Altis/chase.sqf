params["_node"];
private _check={params["_label","_pass",["_detail",[]]];diag_log format["[GUL_CHECK] %1",[_node,_label,_pass,_detail]]};
{
 private _variant=_x;private _base=[13000+_node*450,15400,0];
 private _g=createGroup[east,true];_g setVariable["FST_HC_noTransfer",true,true];if(_variant==0)then{_g setVariable["BURNS_exempt",true,true]};
 private _u=_g createUnit[["JMSEF_animals_varren_o","JMSEF_animals_var_bers_o","JMSEF_animals_var_alpha_o"]select(_node mod 3),_base,[],0,"NONE"];_u allowDamage false;_u setDir 0;_u setVariable["psych",false];
 private _tg=createGroup[west,true];_tg setVariable["FST_HC_noTransfer",true,true];_tg setVariable["BURNS_exempt",true,true];
 _tg setBehaviourStrong "CARELESS";_tg setSpeedMode "FULL";
 private _t=_tg createUnit["B_Soldier_F",_base vectorAdd[0,40,0],[],0,"NONE"];removeAllWeapons _t;_t allowDamage false;_t disableAI "PATH";_t enableStamina false;_t enableFatigue false;_t setDir 0;_t setUnitPos "UP";
 _u disableAI "PATH";sleep 5;
 _t enableAI "PATH";_t disableAI "AUTOCOMBAT";_t forceSpeed 4.5;_t doMove(_base vectorAdd[0,1000,0]);_u enableAI "PATH";
 private _begin=time;private _nearest=10000;private _attackSamples=0;private _first=-1;private _speeds=[];
 for "_i" from 1 to 300 do{
  sleep 0.25;
  private _distance=_u distance _t;_nearest=_nearest min _distance;
  if(animationState _u find "form939_attack"==0)then{_attackSamples=_attackSamples+1;if(_first<0)then{_first=time-_begin}};
  _speeds pushBack speed _t;
  diag_log format["[GUL_CHASE_SAMPLE] %1",[_node,_variant,time-_begin,_distance,speed _u,speed _t,animationState _u,getAnimSpeedCoef _u]];
 };
 diag_log format["[GUL_CHASE_METRIC] %1",[_node,_variant,_nearest,_attackSamples,_first,_t distance2D _base]];
 if(_variant==1)then{
  ["catches fleeing human",_nearest<6,[_nearest,_attackSamples,_first]]call _check;
  ["native melee follows natural pursuit",_attackSamples>0,[_nearest,_attackSamples,_first]]call _check;
  ["chase target really runs",{_x>10}count _speeds>80]call _check;
 };
 deleteVehicle _u;deleteVehicle _t;deleteGroup _g;deleteGroup _tg;sleep 2;
}forEach[1];
diag_log format["[GUL_CHASE_DONE] %1",[_node,clientOwner]];
[_node]call compile preprocessFileLineNumbers "pack.sqf";

[_node]call compile preprocessFileLineNumbers "guards.sqf";