if(!isServer)exitWith{};sleep 15;
["LAB_INIT",!isNil "FST_HCSpawn_fnc_labOriginal"] call {diag_log format["[DT_LAB_IDENTITY] %1",_this]};
Q_checks=[];Q_check={params["_name","_pass",["_detail",[]]];Q_checks pushBack[_name,_pass,_detail];diag_log format["[DT_CHECK] %1",[_name,_pass,_detail]]};
setDate[2035,6,15,12,0];0 setFog 0;0 setOvercast 0;
for "_repeat" from 1 to 2 do{
 {
  private _case=_x;private _rows=[];
  {
   private _variant=_x;private _p=[1200+1600*_forEachIndex,3000,0];
   private _v=createVehicle["FST_AAT",_p,[],0,"CAN_COLLIDE"];_v setDir(if(_case=="rear")then{180}else{0});createVehicleCrew _v;_v allowDamage false;
   private _g=group driver _v;_g setVariable["Q_variant",_variant];_g setVariable["FST_HC_blacklisted",true,true];_g setCombatMode "RED";{_x allowDamage false}forEach crew _v;
   if(_variant in ["no-attack","fire-only"])then{_g enableAttack false};
   if(_variant=="driver-no-target")then{driver _v disableAI "TARGET"};
   private _t=createVehicle["FST_Saber",_p vectorAdd[0,180,0],[],0,"NONE"];createVehicleCrew _t;_t allowDamage false;
   {group _x setVariable["FST_HC_blacklisted",true,true];group _x setVariable["BURNS_exempt",true,true];_x allowDamage false;_x disableAI "ALL"}forEach crew _t;
   private _blocks=[];if(_case=="obstacle")then{for "_i" from -1 to 1 do{private _w=createVehicle["Land_HBarrierBig_F",_p vectorAdd[_i*6,14,0],[],0,"CAN_COLLIDE"];_w allowDamage false;_blocks pushBack _w}};
   _v setVariable["Q_shots",0];_v addEventHandler["Fired",{params["_v"];_v setVariable["Q_shots",(_v getVariable["Q_shots",0])+1]}];
   _g reveal[_t,4];[_g,"rush",getPosATL _t,500]call FST_HCSpawn_fnc_setCombatTask;
   _rows pushBack[_variant,_v,_g,_t,_blocks,getPosATL _v,0,0,0,0,0];
  }forEach["candidate","no-attack","fire-only","driver-no-target"];
  for "_i" from 1 to 45 do{sleep 1;{
   _x params["_variant","_v","_g","_t"];
   private _angle=abs((((_v getDir _t)-(getDir _v)+540)mod 360)-180);
   private _los=[_v,"VIEW",_t]checkVisibility[eyePos gunner _v,aimPos _t];
   if(_angle<55)then{_x set[6,(_x select 6)+1]};
   if((velocityModelSpace _v select 1)<-0.5 && {_angle>90})then{_x set[7,(_x select 7)+1]};
   if(_los>0.5)then{_x set[8,(_x select 8)+1]};
   if(abs speed _v<1 && {_v distance2D _t>155})then{_x set[9,(_x select 9)+1]};
   if(_v distance2D _t<155 && {_angle<55})then{_x set[10,(_x select 10)+1]};
   if(_i mod 5==0)then{diag_log format["[DT_SAMPLE] %1",[_repeat,_case,_variant,_i,getPosATL _v,getDir _v,_angle,_los,_v getVariable["Q_shots",0],currentCommand driver _v,combatBehaviour driver _v,driver _v checkAIFeature "AUTOCOMBAT",attackEnabled _g,_v getVariable["BURNS_armorPulse",[]],_v getVariable["BURNS_driveDetour",[]]]]};
  }forEach _rows};
  {
   _x params["_variant","_v","_g","_t","_blocks","_start","_aligned","_reverse","_visible","_stalled","_band"];
   diag_log format["[DT_RESULT] %1",[_repeat,_case,_variant,_v getVariable["Q_shots",0],_v distance2D _start,_v distance2D _t,_aligned,_reverse,_visible,_stalled,_band]];
   [format["variant executed %1 %2 %3",_repeat,_case,_variant],(_g getVariable["Q_executedVariant",""])==_variant]call Q_check;
   [_g,"stop"]call FST_HCSpawn_fnc_setCombatTask;
  }forEach _rows;sleep 2;
  {
   _x params["_variant","_v","_g","_t","_blocks"];
   [format["turn cleanup %1 %2 %3",_repeat,_case,_variant],count(_v getVariable["BURNS_armorPulse",[]])==0]call Q_check;
   private _tg=group driver _t;{deleteVehicle _x}forEach crew _v;deleteVehicle _v;deleteGroup _g;{deleteVehicle _x}forEach crew _t;deleteVehicle _t;deleteGroup _tg;{deleteVehicle _x}forEach _blocks;
  }forEach _rows;sleep 2;
 }forEach["front","rear","obstacle"];
};
diag_log format["[DT_DONE] checks=%1 failed=%2",count Q_checks,{!(_x select 1)}count Q_checks];
