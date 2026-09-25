if(!isServer)exitWith{};sleep 15;
Q_checks=[];Q_check={params["_n","_p",["_d",[]]];Q_checks pushBack[_n,_p,_d];diag_log format["[QUAL_CHECK] %1",[_n,_p,_d]]};
Q_originalArmorAssist=FST_HCSpawn_fnc_burnsArmorAssist;
Q_feedbackArmorAssist=compile preprocessFileLineNumbers "experimentalArmorAssist.sqf";
diag_log "[QUAL_TURN_TRIAL_BEGIN]";
{
 private _variant=_x;
 FST_HCSpawn_fnc_burnsArmorAssist=if(_variant=="feedback")then{Q_feedbackArmorAssist}else{Q_originalArmorAssist};
 BURNS_ArmorAssistEnabled=_variant!="disabled";
 {
  private _bearing=_x;private _v=createVehicle["FST_AAT",[5000,5000,0],[],0,"NONE"];_v setDir 0;createVehicleCrew _v;_v allowDamage false;
  private _g=group gunner _v;_g setVariable["FST_HC_blacklisted",true,true];_g setVariable["FST_HC_keepActive",true,true];_g setCombatMode "RED";
  private _target=createVehicle["B_MRAP_01_hmg_F",_v getPos[150,_bearing],[],0,"NONE"];createVehicleCrew _target;_target allowDamage false;{_x allowDamage false;_x disableAI "ALL"}forEach crew _target;
  private _tg=group driver _target;_tg setVariable["FST_HC_blacklisted",true,true];
  _v setVariable["Q_shots",0];_v addEventHandler["Fired",{params["_v"];_v setVariable["Q_shots",1+(_v getVariable["Q_shots",0])]}];
  _g reveal[_target,4];[_g,"rush",getPosATL _target,500]call FST_HCSpawn_fnc_setCombatTask;
  private _start=getPosATL _v;private _samples=[];private _turns=missionNamespace getVariable["BURNS_ArmorTurnPulses",0];
  for "_j" from 1 to 40 do{
   sleep 0.5;
   private _angle=(((_v getDir _target)-getDir _v+540)mod 360)-180;
   _samples pushBack[_angle,velocityModelSpace _v,getPosATL _v,_v getVariable["Q_shots",0]];
  };
  private _late=_samples select[20,20];private _aligned={abs(_x select 0)<55}count _late;
  diag_log format["[QUAL_TURN_RESULT] %1",[_variant,_bearing,_aligned,count _late,(missionNamespace getVariable["BURNS_ArmorTurnPulses",0])-_turns,_v getVariable["Q_shots",0],_v distance2D _start,_samples]];
  ["turn trial firing "+_variant+" "+str _bearing,(_v getVariable["Q_shots",0])>0]call Q_check;
  BURNS_ArmorAssistEnabled=false;_g setCombatMode "BLUE";sleep 1;
  ["turn trial latch release "+_variant+" "+str _bearing,count(_v getVariable["BURNS_armorPulse",[]])==0]call Q_check;
  {deleteVehicle _x}forEach crew _v;deleteVehicle _v;deleteGroup _g;
  {deleteVehicle _x}forEach crew _target;deleteVehicle _target;deleteGroup _tg;sleep 1;
  BURNS_ArmorAssistEnabled=_variant!="disabled";
 }forEach[0,90,180];
}forEach["original","feedback","disabled"];
FST_HCSpawn_fnc_burnsArmorAssist=Q_originalArmorAssist;BURNS_ArmorAssistEnabled=true;
diag_log format["[QUAL_FOLLOWUP_DONE] checks=%1 failures=%2",count Q_checks,Q_checks select{!(_x select 1)}];
