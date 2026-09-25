if(!isServer)exitWith{};sleep 15;
Q_checks=[];Q_check={params["_n","_p",["_d",[]]];Q_checks pushBack[_n,_p,_d];diag_log format["[QUAL_CHECK] %1",[_n,_p,_d]]};
Q_delete={params["_g"];{deleteVehicle _x}forEach units _g;deleteGroup _g};
private _deadline=diag_tickTime+120;waitUntil{sleep 1;count(missionNamespace getVariable["FST_HC_Ids",[]])==4 || {diag_tickTime>_deadline}};
diag_log "[QUAL_COMBAT_BEGIN]";
diag_log "[QUAL_EDGES_BEGIN]";
// Local AI fixtures: front/side/rear firing and cancellation without human clients.
{
 private _angle=_x;private _p=[5000,5000,0];
 private _aat=createVehicle["FST_AAT",_p,[],0,"NONE"];_aat setDir 0;createVehicleCrew _aat;_aat allowDamage false;
 private _g=group gunner _aat;_g setVariable["FST_HC_blacklisted",true,true];_g setVariable["FST_HC_keepActive",true,true];_g setCombatMode "RED";
 private _targetPos=_aat getPos[150,_angle];
 private _v=createVehicle["B_MRAP_01_hmg_F",_targetPos,[],0,"NONE"];createVehicleCrew _v;_v allowDamage false;
 { _x allowDamage false;_x disableAI "ALL" }forEach crew _v;
 _aat setVariable["Q_shots",[]];_aat addEventHandler["Fired",{params["_v","_w"];private _s=_v getVariable["Q_shots",[]];_s pushBack _w;_v setVariable["Q_shots",_s]}];
 _g reveal[_v,4];private _pulses=missionNamespace getVariable["BURNS_ArmorTurnPulses",0];
 [_g,"rush",_targetPos,500]call FST_HCSpawn_fnc_setCombatTask;
 for "_j" from 1 to 8 do {
 sleep 5;
 private _contact=[getPosATL _v,typeOf _v,west,1,_v];
 diag_log format["[QUAL_AAT_DETAIL] %1",[_angle,_j,local _aat,groupOwner _g,combatMode _g,[_g]call FST_HCSpawn_fnc_burnsEngagementAllowed,[_aat,"VIEW",_v]checkVisibility[eyePos gunner _aat,aimPos _v],_g in FST_HC_CombatGroups,gunner _aat checkAIFeature "TARGET",gunner _aat checkAIFeature "FIREWEAPON",count(_aat getVariable["Q_shots",[]]),count((leader _g)nearTargets 500),getPosATL _aat]];
 if(_j==4)then{["AAT native scheduler firing "+str _angle,count(_aat getVariable["Q_shots",[]])>0]call Q_check};
 if(_j>=4)then{[_g,[_contact]]call FST_HCSpawn_fnc_burnsArmorAssist};
};
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
private _u=_g createUnit["FST_Droid_B1_E5",[5000,5000,0],[],0,"NONE"];
_g setCombatMode "RED";_u allowDamage false;_u setDir 0;[_g]call FST_HCSpawn_fnc_burnsApplyRole;sleep 1;
private _tg=createGroup[west,true];_tg setVariable["FST_HC_blacklisted",true,true];
private _t=_tg createUnit["B_Soldier_F",[5000,5015,0],[],0,"NONE"];_t disableAI "ALL";_t allowDamage false;
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
private _replacement=createGroup[east,true];_replacement setVariable["FST_HC_blacklisted",true,true];[_u]joinSilent _replacement;sleep 1;
[_g]call FST_HCSpawn_fnc_burnsPointFire;
["group merge releases old rifle job",count(_g getVariable["BURNS_pointFire",[]])==0 && {getForcedSpeed _u!=0},[getForcedSpeed _u,_u getVariable["BURNS_pointFireLease",[]],count(_g getVariable["BURNS_pointFire",[]])]]call Q_check;
deleteGroup _g;[_replacement]call Q_delete;[_tg]call Q_delete;

diag_log format["[QUAL_FOLLOWUP_DONE] checks=%1 failures=%2",count Q_checks,Q_checks select{!(_x select 1)}];