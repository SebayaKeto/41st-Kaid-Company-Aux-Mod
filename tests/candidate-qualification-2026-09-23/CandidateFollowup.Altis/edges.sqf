diag_log "[QUAL_EDGES_BEGIN]";
// Local AI fixtures: front/side/rear firing and cancellation without human clients.
{
 private _angle=_x;private _p=[14500,16000,0];
 private _aat=createVehicle["FST_AAT",_p,[],0,"NONE"];_aat setDir 0;createVehicleCrew _aat;_aat allowDamage false;
 private _g=group gunner _aat;_g setVariable["FST_HC_blacklisted",true,true];_g setVariable["FST_HC_keepActive",true,true];_g setCombatMode "RED";
 private _targetPos=_aat getPos[150,_angle];
 private _v=createVehicle["B_MRAP_01_hmg_F",_targetPos,[],0,"NONE"];createVehicleCrew _v;_v allowDamage false;
 { _x allowDamage false;_x disableAI "ALL" }forEach crew _v;
 _aat setVariable["Q_shots",[]];_aat addEventHandler["Fired",{params["_v","_w"];private _s=_v getVariable["Q_shots",[]];_s pushBack _w;_v setVariable["Q_shots",_s]}];
 _g reveal[_v,4];private _pulses=missionNamespace getVariable["BURNS_ArmorTurnPulses",0];
 [_g,"rush",_targetPos,500]call FST_HCSpawn_fnc_setCombatTask;
 sleep 40;
 ["AAT bearing fires "+str _angle,count(_aat getVariable["Q_shots",[]])>0,[getDir _aat,_aat getVariable["Q_shots",[]],(missionNamespace getVariable["BURNS_ArmorTurnPulses",0])-_pulses]]call Q_check;
 // STOP clears task intent but deliberately leaves the no-task assist enabled.
 // Disable assist and hold fire to test that an outstanding latch clears.
 BURNS_ArmorAssistEnabled=false;_g setCombatMode "BLUE";
 [_g,"stop"]call FST_HCSpawn_fnc_setCombatTask;sleep 2;
 ["AAT outstanding turn releases "+str _angle,count(_aat getVariable["BURNS_armorPulse",[]])==0,[_aat getVariable["BURNS_armorPulse",[]],local _aat]]call Q_check;
 private _wp=_g addWaypoint[_p vectorAdd[200,0,0],0];_wp setWaypointType "MOVE";_g setCurrentWaypoint _wp;_g setCombatMode "RED";BURNS_ArmorAssistEnabled=true;sleep 1;
 ["AAT native travel order protected "+str _angle,!([_g]call FST_HCSpawn_fnc_burnsEngagementAllowed)]call Q_check;
 [_g]call Q_delete;[group driver _v]call Q_delete;deleteVehicle _aat;deleteVehicle _v;sleep 1;
}forEach[0,90,180];
// Rifle/casualty boundary cases use real loaded functions and ordinary AI.
private _g=createGroup[east,true];_g setVariable["FST_HC_blacklisted",true,true];
private _u=_g createUnit["FST_Droid_B1_E5",[14500,16000,0],[],0,"NONE"];
_g setCombatMode "RED";_u allowDamage false;_u setDir 0;[_g]call FST_HCSpawn_fnc_burnsApplyRole;sleep 1;
private _tg=createGroup[west,true];_tg setVariable["FST_HC_blacklisted",true,true];
private _t=_tg createUnit["B_Soldier_F",[14500,16015,0],[],0,"NONE"];_t disableAI "ALL";_t allowDamage false;
_t setVariable["ACE_isUnconscious",true,true];_t setUnitPos "DOWN";sleep 1;
private _contacts=[[getPosATL _t,typeOf _t,west,1,_t]];
{
 _t setVariable[_x,true,true];[_g,_contacts]call FST_HCSpawn_fnc_burnsAcquirePointFire;
 ["casualty protection "+_x,count(_g getVariable["BURNS_pointFire",[]])==0]call Q_check;
 _t setVariable[_x,false,true];
}forEach["ace_captives_isHandcuffed","ace_captives_isSurrendering"];
_u forceSpeed -1;[_g,_contacts]call FST_HCSpawn_fnc_burnsAcquirePointFire;
["casualty job acquired",count(_g getVariable["BURNS_pointFire",[]])==10,_g getVariable["BURNS_pointFire",[]]]call Q_check;
_t setVariable["ACE_isUnconscious",false,true];[_g]call FST_HCSpawn_fnc_burnsPointFire;
["revival cancels casualty job",count(_g getVariable["BURNS_pointFire",[]])==0]call Q_check;
_t setVariable["ACE_isUnconscious",true,true];_u forceSpeed -1;[_g,_contacts]call FST_HCSpawn_fnc_burnsAcquirePointFire;
private _replacement=createGroup[east,true];_replacement setVariable["FST_HC_blacklisted",true,true];[_u]joinSilent _replacement;
[_g]call FST_HCSpawn_fnc_burnsPointFire;
["group merge releases old rifle job",count(_g getVariable["BURNS_pointFire",[]])==0 && {getForcedSpeed _u!=0}]call Q_check;
deleteGroup _g;[_replacement]call Q_delete;[_tg]call Q_delete;
// Full ship fault injection. Only disposable test anchors/ships are removed.
Q_realAnchor=FST_fnc_nextPodAnchor;Q_fault="";Q_faultApplied=false;Q_realDispenser=FST_Droid_Dispenser;Q_podRequests=[];
FST_fnc_nextPodAnchor={
 params["_anchors","_remaining"];
 if(!Q_faultApplied && {Q_fault!=""})then{
  Q_faultApplied=true;
  switch Q_fault do{
   case "partial":{{deleteVehicle _x}forEach(_anchors select[0,8])};
   case "all":{{deleteVehicle _x}forEach _anchors};
   case "ship":{deleteVehicle(attachedTo(_anchors select 0))};
  };
  sleep 0.2;
 };
 [_anchors,_remaining]call Q_realAnchor
};
FST_Droid_Dispenser={Q_podRequests pushBack(+_this);_this call Q_realDispenser};
{
 _x params["_fault","_fn","_expected"];
 Q_fault=_fault;Q_faultApplied=false;Q_podRequests=[];
 private _before=allMissionObjects "All";private _beforeUnits=allUnits;
 private _p=if(count Q_slope==3)then{Q_slope}else{[10500,10500,0]};
 private _diamond=_fn find "Diamond">=0;
 private _params=if(_diamond)then{[ATLToASL _p,0,[east],24,false,0,0,0.5,false,false,0]}else{[ATLToASL _p,0,[east],0,24,false,0,0,0.5,false,false,0]};
 diag_log format["[QUAL_FAULT_BEGIN] %1",[_fault,_fn]];
 _params call(missionNamespace getVariable _fn);
 sleep 60;
 ["pod fault reached "+_fault,Q_faultApplied]call Q_check;
 ["pod fault request count "+_fault,count Q_podRequests==_expected,count Q_podRequests]call Q_check;
 if(_expected>0)then{
  ["elevated ship positions follow ground",(Q_podRequests findIf{abs(((ASLToATL(_x select 0))select 2))>0.1})<0,[getTerrainHeightASL _p,Q_podRequests apply{(_x select 0)select 2}]]call Q_check;
  ["partial anchors still deliver troops",{alive _x}count(allUnits-_beforeUnits)>=72,{alive _x}count(allUnits-_beforeUnits)]call Q_check;
 };
 {(if(!isPlayer _x)then{deleteVehicle _x})}forEach((allMissionObjects "All")-_before);sleep 2;
}forEach[["partial","FST_ScifiSupportPlus_fnc_SW_Munificent_QRF",24],["all","FST_ScifiSupportPlus_fnc_SW_Providence_QRF",0],["ship","FST_ScifiSupportPlus_fnc_SW_Diamond_QRF",0]];
FST_fnc_nextPodAnchor=Q_realAnchor;Q_podRequests=[];
private _before=allMissionObjects "All";private _beforeUnits=allUnits;
{
 [ATLToASL[13000+_forEachIndex*1500,15000,0],0,[east],0,24,false,0,0,0.5,false,false,0]call(missionNamespace getVariable _x);
}forEach["FST_ScifiSupportPlus_fnc_SW_Munificent_QRF","FST_ScifiSupportPlus_fnc_SW_Providence_Jorge_QRF"];
sleep 60;
["concurrent ships submit 48",count Q_podRequests==48,count Q_podRequests]call Q_check;
["concurrent ships deliver living troops",{alive _x}count(allUnits-_beforeUnits)>=144,{alive _x}count(allUnits-_beforeUnits)]call Q_check;
FST_Droid_Dispenser=Q_realDispenser;
{if(!isPlayer _x)then{deleteVehicle _x}}forEach((allMissionObjects "All")-_before);
diag_log "[QUAL_EDGES_DONE]";
