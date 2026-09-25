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

diag_log "[QUAL_ALTIS_AAT_DONE]";