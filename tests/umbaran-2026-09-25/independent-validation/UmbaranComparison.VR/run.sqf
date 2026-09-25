if(!isServer)exitWith{};sleep 15;
Q_checks=[];Q_check={params["_name","_pass",["_data",[]]];Q_checks pushBack[_name,_pass,_data];diag_log format["[UMB_CHECK] %1",[_name,_pass,_data]]};
FST_HC_CombatTasksEnabled=true;FST_HC_Enabled=false;publicVariable "FST_HC_Enabled";
private _classes=(getArray(configFile>>"CfgPatches">>"41st_UmbaranUnits">>"units"));
if(count _classes==0)then{_classes=["FST_UmbaranInf_SL","FST_UmbaranInf_Standard","FST_UmbaranInf_Autorifle","FST_UmbaranInf_RTO","FST_UmbaranInf_Medic","FST_UmbaranInf_Marksman","FST_UmbaranInf_EOD","FST_UmbaranInf_AT","FST_UmbaranInf_AA","FST_UmbaranInf_Comm","FST_UmbaranInf_SO"]};
private _samples=[];
{private _g=createGroup[east,true];_g setVariable["FST_HC_noTransfer",true,true];private _u=_g createUnit[_x,[2000+20*_forEachIndex,2000,0],[],0,"NONE"];_samples pushBack _u;}forEach _classes;
private _b1g=createGroup[east,true];_b1g setVariable["FST_HC_noTransfer",true,true];private _b1=_b1g createUnit["FST_Droid_B1_E5",[2000,2200,0],[],0,"NONE"];
sleep 6;
["unique addon identity",isClass(configFile>>"CfgPatches">>"41st_UmbaranUnits")]call Q_check;
["OPFOR faction matches units and groups",getNumber(configFile>>"CfgFactionClasses">>"FST_Umbaran_Faction">>"side")==0]call Q_check;
{
 private _u=_x;private _type=typeOf _u;private _cfg=configOf _u;
 ["unit loads with weapon and ammo "+_type,alive _u && {(primaryWeapon _u!="" && {count primaryWeaponMagazine _u>0}) || {handgunWeapon _u!="" && {count handgunMagazine _u>0}}},[primaryWeapon _u,primaryWeaponMagazine _u,handgunWeapon _u,handgunMagazine _u,uniform _u,vest _u,backpack _u]]call Q_check;
 ["BURNS human classification "+_type,([_u]call FST_HCSpawn_fnc_burnsRole)=="human"]call Q_check;
 [group _u]call FST_HCSpawn_fnc_burnsApplyRole;
 ["human AI remains enabled "+_type,(_u checkAIFeature "COVER") && {_u checkAIFeature "SUPPRESSION"} && {_u checkAIFeature "AUTOCOMBAT"} && {_u getVariable["BURNS_suppressionHook",false]}]call Q_check;
 diag_log format["[UMB_PROFILE] %1",[_type,["general","aimingAccuracy","aimingShake","aimingSpeed","spotTime","spotDistance","commanding","courage","reloadSpeed"]apply{_u skill _x},[getNumber(_cfg>>"armor"),getNumber(_cfg>>"armorStructural"),getNumber(_cfg>>"HitPoints">>"HitChest">>"armor")],getAllHitPointsDamage _u]];
}forEach _samples;
diag_log format["[UMB_B1] %1",[typeOf _b1,primaryWeapon _b1,["general","aimingAccuracy","spotTime","commanding"]apply{_b1 skill _x},[getNumber(configOf _b1>>"armor"),getNumber(configOf _b1>>"armorStructural"),getNumber(configOf _b1>>"HitPoints">>"HitChest">>"armor")]]];
private _groupCfg=configFile>>"CfgGroups">>"East">>"FST_Umbaran_Faction">>"FST_Umbaran";
{private _c=_x;private _g=[[3000+100*_forEachIndex,2000,0],east,_c]call BIS_fnc_spawnGroup;sleep 2;
 private _expected=count("true"configClasses _c);private _us=units _g;
 ["group spawns armed "+configName _c,count _us==_expected && {_us findIf{!alive _x || {primaryWeapon _x==""} || {count primaryWeaponMagazine _x==0}}<0},[count _us,_expected,_us apply{typeOf _x}]]call Q_check;
 {deleteVehicle _x}forEach _us;deleteGroup _g;
}forEach("true"configClasses _groupCfg);
{diag_log format["[UMB_DEP] %1",[_x,configSourceAddonList(configFile>>(_x select 0)>>(_x select 1))]]}forEach[["CfgWeapons","ls_imperialVest_isb_heavy_h"],["CfgVehicles","JMSLLTE_back_snowpack_med"],["CfgVehicles","FST_bodyGlove"]];
private _std=_samples select 1;private _spec=_samples select 10;
["SpecOps wears its armored bodysuit",uniform _spec=="FST_UmbaranBodysuit_SO"]call Q_check;
["medic specialty",(_samples select 4)getUnitTrait "medic"]call Q_check;
["EOD specialty",(_samples select 6)getUnitTrait "engineer" && {(_samples select 6)getUnitTrait "explosiveSpecialist"}]call Q_check;
["Umbaran cognition above B1",(_std skill "general")>(_b1 skill "general") && {(_std skill "commanding")>(_b1 skill "commanding")},[[_std skill "general",_std skill "commanding"],[_b1 skill "general",_b1 skill "commanding"]]]call Q_check;
private _deadline=diag_tickTime+100;waitUntil{sleep 1;count((entities "HeadlessClient_F")select{isPlayer _x && {owner _x>2}})>=4 || diag_tickTime>_deadline};
private _hcs=(entities "HeadlessClient_F")select{isPlayer _x && {owner _x>2}};
["four headless clients available",count _hcs>=4]call Q_check;
FST_HC_SafeModeUntil=time+10000;
if(count _hcs>0)then{
 private _hc=owner(_hcs select 0);
 private _nativeGroup=createGroup[east,true];_nativeGroup setVariable["FST_HC_blacklisted",true,true];
 private _control=_nativeGroup createUnit["O_Soldier_F",[3900,4000,0],[],0,"NONE"];
 private _g=[[4000,4000,0],east,_groupCfg>>"FST_S_UM_Fireteam"]call BIS_fnc_spawnGroup;
 _g setVariable["FST_HC_blacklisted",true,true];sleep 1;
 private _saved=units _g apply{[typeOf _x,getUnitLoadout _x]};
 private _a=_nativeGroup setGroupOwner _hc;private _b=_g setGroupOwner _hc;
 private _end=diag_tickTime+40;
 waitUntil{sleep 1;((groupOwner _g)==_hc && {(groupOwner _nativeGroup)==_hc}) || diag_tickTime>_end};
 diag_log format["[UMB_TRANSFER_CONTROL] %1",[_hc,_a,_b,groupOwner _nativeGroup,groupOwner _g]];
 if(groupOwner _g==_hc)then{
  ["HC",[_g,[4200,4000,0]]]remoteExecCall["Q_fnc_umbLocal",_hc];sleep 8;
  private _result=_g getVariable["Q_HCResult",[]];
  ["HC adopts transferred human BURNS task",count _result>=3 && {_result select 0} && {_result select 1} && {_result select 2},_result]call Q_check;
  ["HC transfer preserves loadouts",(units _g apply{[typeOf _x,getUnitLoadout _x]})isEqualTo _saved]call Q_check;
 }else{diag_log "[UMB_LIMITATION] Native group transfer did not settle; see vanilla control. Testing direct HC spawn separately.";};
 // Use the actual HCSpawn construction path, as used by the Zeus modules.
 ["NATIVE",[]]remoteExec["Q_fnc_umbLocal",_hc];sleep 8;
 private _ng=missionNamespace getVariable["Q_nativeGroup",grpNull];
 ["production HC spawn creates Umbaran group",!isNull _ng && {count units _ng==4} && {groupOwner _ng==_hc},[str _ng,groupOwner _ng]]call Q_check;
 private _nstart=getPosATL leader _ng;sleep 16;
 ["production HC BURNS assault advances",!isNull _ng && {leader _ng distance2D _nstart>10},[_nstart,getPosATL leader _ng]]call Q_check;
 private _r=_ng getVariable["Q_HCResult",[]];
 ["production HC retains human skills and loadouts",count _r>=4 && {_r select 3},_r]call Q_check;
};
[]call compile preprocessFileLineNumbers "engagement.sqf";
// Native projectile damage, not setDamage or synthetic ACE calls.
private _ammo=getText(configFile>>"CfgMagazines">>"FST_blaster_cell_High_Blue">>"ammo");
private _durability=[];
{
 private _class=_x;private _trials=[];
 for "_trial" from 1 to 12 do{
  private _g=createGroup[east,true];private _u=_g createUnit[_class,[6000+20*_trial,6000,0],[],0,"NONE"];
  sleep 1;_u disableAI "ALL";_u setUnitPos "UP";_u setDir 180;_u allowDamage true;
  _u setVariable["Q_hits",0];_u addEventHandler["Hit",{params["_u"];_u setVariable["Q_hits",(_u getVariable["Q_hits",0])+1]}];
  private _shots=0;private _history=[];
  while{alive _u && {lifeState _u!="INCAPACITATED"} && {_shots<16}}do{
   private _target=(getPosASL _u)vectorAdd[0,0,1.15];private _start=_target vectorAdd[0,-5,0];
   private _p=createVehicle[_ammo,ASLToATL _start,[],0,"CAN_COLLIDE"];_p setPosASL _start;_p setVelocity[0,300,0];
   _shots=_shots+1;sleep 0.4;_history pushBack[damage _u,lifeState _u];
  };
  _trials pushBack[_shots,_u getVariable["Q_hits",0],alive _u,lifeState _u];
  deleteVehicle _u;deleteGroup _g;
 };
 _durability pushBack[_class,_trials];diag_log format["[UMB_PROJECTILES] %1",[_class,_ammo,_trials]];
}forEach["FST_Droid_B1_E5","FST_UmbaranInf_Standard","FST_UmbaranInf_SO"];
diag_log format["[UMB_DURABILITY] %1",_durability];
diag_log format["[UMB_DONE] checks=%1 failures=%2",count Q_checks,Q_checks select{!(_x select 1)}];

[] call compile preprocessFileLineNumbers "comparison.sqf";
