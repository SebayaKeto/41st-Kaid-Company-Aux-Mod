if(!isServer)exitWith{};sleep 15;
Q_checks=[];Q_check={params["_n","_p",["_d",[]]];Q_checks pushBack[_n,_p,_d];diag_log format["[QUAL_CHECK] %1",[_n,_p,_d]]};
["release-trial preset applied",BURNS_ArmorAssistEnabled]call Q_check;
if(!BURNS_ArmorAssistEnabled)exitWith{diag_log "[QUAL_ABORT] requested safe setting was not applied"};
["server-only release trial",isServer]call Q_check;
diag_log "[QUAL_RELEASE_TRIAL_BEGIN]";
{
 private _task=_x;
 {
  private _bearing=_x;private _v=createVehicle["FST_AAT",[5000,5000,0],[],0,"NONE"];_v setDir 0;createVehicleCrew _v;_v allowDamage false;
  private _g=group gunner _v;_g setVariable["FST_HC_blacklisted",true,true];_g setVariable["FST_HC_keepActive",true,true];_g setCombatMode "RED";
  private _t=createVehicle["B_MRAP_01_hmg_F",_v getPos[150,_bearing],[],0,"NONE"];createVehicleCrew _t;_t allowDamage false;{_x allowDamage false;_x disableAI "ALL"}forEach crew _t;
  private _tg=group driver _t;_tg setVariable["FST_HC_blacklisted",true,true];
  _v setVariable["Q_shots",[]];_v addEventHandler["Fired",{params["_v","_w"];private _s=_v getVariable["Q_shots",[]];_s pushBack _w;_v setVariable["Q_shots",_s]}];
  _g reveal[_t,4];if(_task!="")then{[_g,_task,getPosATL _t,500]call FST_HCSpawn_fnc_setCombatTask};
  private _samples=[];private _start=getPosATL _v;
  for "_j" from 1 to 70 do{sleep 0.5;_samples pushBack[abs((((_v getDir _t)-getDir _v+540)mod 360)-180),velocityModelSpace _v]};
  private _label=format["release-trial AAT %1 bearing %2",_task,_bearing];
  [_label+" firing",count(_v getVariable["Q_shots",[]])>0,[_v getVariable["Q_shots",[]],_v distance2D _start]]call Q_check;
  private _late=_samples select[50,20];
  [_label+" front presented",{(_x select 0)<55}count _late>=15,[{(_x select 0)<55}count _late,_samples]]call Q_check;
  BURNS_ArmorAssistEnabled=false;_g setCombatMode "BLUE";sleep 1;
  [_label+" turn cleanup",count(_v getVariable["BURNS_armorPulse",[]])==0]call Q_check;
  BURNS_ArmorAssistEnabled=true;
  {deleteVehicle _x}forEach crew _v;deleteVehicle _v;deleteGroup _g;{deleteVehicle _x}forEach crew _t;deleteVehicle _t;deleteGroup _tg;sleep 1;
 }forEach[0,90,180];
}forEach["","rush","hunt"];
diag_log format["[QUAL_FOLLOWUP_DONE] checks=%1 failures=%2",count Q_checks,Q_checks select{!(_x select 1)}];
