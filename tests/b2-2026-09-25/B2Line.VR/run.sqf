params ["_node"];
private _check={params["_label","_pass",["_detail",[]]];diag_log format["[B2L_CHECK] %1",[_node,_label,_pass,_detail]]};
private _counts=[2,4,8,4,8];private _count=_counts select _node;
private _groups=[];private _targets=[];private _starts=[];
for "_pair" from 0 to 1 do {
 private _base=[3000+500*_node+180*_pair,6000,0];
 private _g=createGroup[east,true];_g setVariable["FST_HC_noTransfer",true,true];_g setVariable["BURNS_exempt",true,true];_g setFormation "WEDGE";_g setCombatMode "RED";_g setBehaviourStrong "AWARE";
 for "_i" from 0 to (_count-1) do {
  private _class=if(_i mod 4==0)then{"FST_B2_TL"}else{"FST_B2"};
  private _u=_g createUnit[_class,_base vectorAdd[(_i mod 2)*2,-2*floor(_i/2),0],[],0,"NONE"];
  _u disableAI "PATH";_u setDir 0;_u setVariable["Q_shots",0];_u addEventHandler["Fired",{params["_u"];_u setVariable["Q_shots",(_u getVariable["Q_shots",0])+1]}];
 };
 private _sg=createGroup[west,true];_sg setVariable["FST_HC_noTransfer",true,true];
 private _target=_sg createUnit["B_Soldier_F",_base vectorAdd[0,90,0],[],0,"NONE"];_target disableAI "ALL";_target allowDamage false;
 _groups pushBack _g;_targets pushBack _target;_starts pushBack _base;
};
sleep 7;
{diag_log format["[B2L_GEAR] %1",[_node,_forEachIndex,(units _x)apply{[typeOf _x,primaryWeapon _x,secondaryWeapon _x,handgunWeapon _x]}]]}forEach _groups;
{
 private _g=_x;private _target=_targets select _forEachIndex;private _base=_starts select _forEachIndex;
 {_x setPosATL(_base vectorAdd[(_forEachIndex mod 2)*2,-2*floor(_forEachIndex/2),0]);_x setDir 0;_x enableAI "PATH";_x reveal[_target,4];_x doTarget _target}forEach units _g;
 if(_forEachIndex==1)then{_g setVariable["BURNS_exempt",false,true]};
}forEach _groups;
private _begin=time;
for "_sample" from 1 to 60 do {
 sleep 2;
 {
  private _g=_x;
  diag_log format["[B2L_SAMPLE] %1",[_node,_forEachIndex,time-_begin,formation _g,combatMode _g,(units _g)apply{[getPosATL _x,_x getVariable["Q_shots",0],animationState _x,gestureState _x,currentCommand _x]},count(_g getVariable["BURNS_b2Line",[]])]];
 }forEach _groups;
};
private _g=_groups select 1;private _units=units _g;private _target=_targets select 1;
private _xs=_units apply{(getPosATL _x)select 0};_xs sort true;
private _ys=_units apply{(getPosATL _x)select 1};_ys sort true;
private _width=(_xs select(count _xs-1))-(_xs select 0);private _depth=(_ys select(count _ys-1))-(_ys select 0);
private _nearest=_units apply{private _u=_x;private _d=1000;{if(_x!=_u)then{_d=_d min(_u distance2D _x)}}forEach _units;_d};_nearest sort true;
private _shots=0;{_shots=_shots+(_x getVariable["Q_shots",0])}forEach _units;
["combat deploys native line",formation _g=="LINE",[formation _g,combatMode _g]]call _check;
["line spreads across the enemy front",_width>=3 && {_width>_depth},[_width,_depth,_nearest]]call _check;
["B2 nearest-neighbour spacing",(_nearest select floor(count _nearest/2))>=3,_nearest]call _check;
["B2 line advances",((getPosATL leader _g)select 1)-((_starts select 1)select 1)>8,(getPosATL leader _g)vectorDiff(_starts select 1)]call _check;
["native weapon firing continues",_shots>0,_units apply{[_x getVariable["Q_shots",0],primaryWeapon _x,_x getVariable["WBK_AmountOfAmmunition",-1]]}]call _check;
["WebKnight health and animation controls preserved",(_units findIf{(_x getVariable["Droid_Health",-1])<=0 || {getAnimSpeedCoef _x!=1} || {!(_x checkAIFeature "ANIM")} || {!(_x checkAIFeature "FIREWEAPON")} || {!(_x checkAIFeature "PATH")}})<0]call _check;
[_g,"stop"]call FST_HCSpawn_fnc_setCombatTask;sleep 2;
["stop restores original group controls",formation _g=="WEDGE" && {combatMode _g=="RED"} && {isNil{_g getVariable "BURNS_b2Line"}},[formation _g,combatMode _g]]call _check;
[_g,getPosATL leader _g,50]call FST_HCSpawn_fnc_burnsPatrol;sleep 3;
["new patrol clears stop intent and permits combat line",(_g getVariable["BURNS_b2TaskIntent","stop"])=="" && {!isNil{_g getVariable "BURNS_b2Line"}}]call _check;
[_g,"hunt",getPosATL _target,100]call FST_HCSpawn_fnc_setCombatTask;sleep 3;
["hunt replaces patrol without retaining recursive stop intent",(_g getVariable["BURNS_b2TaskIntent","stop"])=="hunt" && {!isNil{_g getVariable "BURNS_b2Line"}}]call _check;
[_g,"stop"]call FST_HCSpawn_fnc_setCombatTask;
{deleteVehicle _x}forEach _targets;{{deleteVehicle _x}forEach units _x}forEach _groups;
diag_log format["[B2L_DONE] %1",[_node,clientOwner,_count]];
[_node]call compile preprocessFileLineNumbers "guards.sqf";
