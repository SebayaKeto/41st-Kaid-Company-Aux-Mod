if (!isServer) exitWith {};
sleep 10;
Q_checks=[];
Q_check={params ["_name","_pass",["_detail",[]]];Q_checks pushBack [_name,_pass,_detail];diag_log format ["[QUAL_CHECK] %1",[_name,_pass,_detail]];};
Q_delete={params ["_g"];{if(vehicle _x!=_x)then{private _v=vehicle _x;{deleteVehicle _x}forEach crew _v;deleteVehicle _v}else{deleteVehicle _x}}forEach units _g;deleteGroup _g;};
diag_log format ["[QUAL_BEGIN] version=%1 fps=%2",productVersion,diag_fps];
{
 [_x,isClass(configFile>>"CfgPatches">>_x)] call Q_check;
}forEach ["FST_HCSpawn","FST_BURNS_Combat","FST_BURNS_Gulanthar","FST_AAT"];
{
 [_x,!isNil _x]call Q_check;
}forEach ["FST_HCSpawn_fnc_burnsArmorAssist","FST_HCSpawn_fnc_burnsB1Advance","FST_HCSpawn_fnc_burnsGulantharSlope","FST_fnc_nextPodAnchor","FST_Droid_Dispenser","FST_ScifiSupportPlus_fnc_SW_Munificent_QRF","FST_ScifiSupportPlus_fnc_SW_Providence_QRF","FST_ScifiSupportPlus_fnc_SW_Diamond_QRF","FST_ScifiSupportPlus_fnc_SW_Providence_Jorge_QRF"];
{
 private _moves=getText(configFile>>"CfgVehicles">>_x>>"moves");
 private _states=configFile>>_moves>>"States";
 ["gait config "+_x,_moves=="CfgMovesBURNSGulanthar" && {isClass(_states>>"BURNS_gulanthar_climb")} && {getNumber(_states>>"BURNS_gulanthar_climb">>"speed")==1.8},[_moves,getText(_states>>"BURNS_gulanthar_climb">>"file")]]call Q_check;
}forEach ["JMSEF_animals_varren_o","JMSEF_animals_var_bers_o","JMSEF_animals_var_alpha_o"];
private _mode=configFile>>"CfgWeapons">>"FST_AAT_Cannon">>"HP">>"Fire";
["AAT cannon merged profile",getNumber(_mode>>"maxRange")>=1000,[getNumber(_mode>>"maxRange"),getNumber(_mode>>"aiRateOfFire"),getNumber(configFile>>"CfgAmmo">>"FST_thermal_shell_HP">>"allowAgainstInfantry")]]call Q_check;
diag_log format ["[QUAL_CLASSES] %1",("getNumber(_x >> 'scope')==2 && {(toLower configName _x) find 'raider'>=0}" configClasses(configFile>>"CfgVehicles"))apply{configName _x}];
private _deadline=diag_tickTime+150;
waitUntil{sleep 1;count(missionNamespace getVariable ["FST_HC_Ids",[]])==4 || {diag_tickTime>_deadline}};
private _hcs=missionNamespace getVariable ["FST_HC_Array",[]];
["four real HCs registered",count _hcs==4,_hcs apply{[vehicleVarName _x,owner _x,_x getVariable ["FST_HC_slot",-1]]}]call Q_check;
private _vhc=[]call FST_HCSpawn_fnc_getVehicleHC;
["vehicle HC is slot four",(_vhc select 0)>2 && {(_vhc select 0)==owner HC4},_vhc]call Q_check;
// Loaded full-PBO helper checks. No replacement helper or dispenser is compiled.
if(!isNil "FST_fnc_nextPodAnchor")then{
 private _anchors=[];for "_i" from 0 to 15 do{_anchors pushBack("#particleSource" createVehicleLocal [4000+_i*8,4000,20])};
 private _pool=[];private _chosen=[];
 for "_i" from 1 to 24 do{private _r=[_anchors,_pool]call FST_fnc_nextPodAnchor;if(count _r==2)then{_chosen pushBack(_r select 0);_pool=_r select 1}};
 ["loaded helper selects 24 from 16",count _chosen==24]call Q_check;
 ["loaded helper first pass unique",count((_chosen select[0,16])arrayIntersect(_chosen select[0,16]))==16]call Q_check;
 ["loaded helper second pass unique",count((_chosen select[16,8])arrayIntersect(_chosen select[16,8]))==8]call Q_check;
 ["loaded helper empty rejection",([[],[]]call FST_fnc_nextPodAnchor)isEqualTo []]call Q_check;
 {deleteVehicle _x}forEach _anchors;sleep 0.2;
 ["loaded helper deleted anchors",([_anchors,_pool]call FST_fnc_nextPodAnchor)isEqualTo []]call Q_check;
 {private _r=_x call FST_Droid_Dispenser;[format["loaded dispenser reject %1",_forEachIndex],_r isEqualTo false]call Q_check}forEach [[],[[],[east],0,false],[[1,2],[east],0,false],[[1,2,3],[],0,false],[[1,2,3],[east],6,false],[[1,2,3],[east],0.5,false],[[1,2,3],[east],0,"bad"]];
};
// B1 live travel and contact transition, then explicit stop and guards.
private _g=createGroup[east,true];_g setVariable["FST_HC_blacklisted",true,true];
for "_i" from 0 to 11 do{private _u=_g createUnit["FST_Droid_B1_E5",[4000,4000-_i*3.5,0],[],0,"NONE"];_u allowDamage false;_u setDir 0};
_g setVariable["FST_HC_keepActive",true,true];_g setCombatMode "YELLOW";
[_g]call FST_HCSpawn_fnc_burnsApplyRole;
["B1 classified and eligible",[_g]call FST_HCSpawn_fnc_burnsB1Eligible]call Q_check;
private _origin=getPosATL leader _g;
[_g,[4000,4300,0]]call FST_HCSpawn_fnc_burnsB1Advance;
sleep 0.2;
["B1 starts COLUMN",formation _g=="COLUMN",formation _g]call Q_check;
sleep 12;
["B1 column actually advances",leader _g distance2D _origin>5,[leader _g distance2D _origin,units _g apply{getPosATL _x}]]call Q_check;
private _targetGroup=createGroup[west,true];private _target=_targetGroup createUnit["B_Soldier_F",[4000,4210,0],[],0,"NONE"];
_target allowDamage false;_target disableAI "ALL";_g reveal[_target,4];
_g setVariable["BURNS_rushTarget",_target,true];
[_g,[4000,4300,0]]call FST_HCSpawn_fnc_burnsB1Advance;
sleep 0.2;
private _frame=+(_g getVariable["BURNS_localDeployFrame",[]]);
["B1 contact changes to LINE",formation _g=="LINE",formation _g]call Q_check;
private _goals=units _g apply{_x getVariable["BURNS_formationGoal",[]]};
["B1 12 distinct line slots",count(_goals arrayIntersect _goals)==12,_goals]call Q_check;
sleep 1;[_g,[4000,4300,0]]call FST_HCSpawn_fnc_burnsB1Advance;
["B1 deployment front stays fixed",(_g getVariable["BURNS_localDeployFrame",[]])isEqualTo _frame,_frame]call Q_check;
private _end=diag_tickTime+24;
while{diag_tickTime<_end}do{[_g,[4000,4300,0]]call FST_HCSpawn_fnc_burnsB1Advance;sleep 1};
diag_log format["[QUAL_B1_POSITIONS] %1",units _g apply{[getPosATL _x,_x getVariable["BURNS_formationGoal",[]],getForcedSpeed _x]}];
[_g,"stop"]call FST_HCSpawn_fnc_setCombatTask;sleep 0.5;
["B1 stop releases movement speed",(units _g findIf{count(_x getVariable["BURNS_advanceSpeed",[]])>0})<0,units _g apply{getForcedSpeed _x}]call Q_check;
_g setVariable["BURNS_exempt",true];["B1 exemption respected",!([_g]call FST_HCSpawn_fnc_burnsB1Eligible)]call Q_check;_g setVariable["BURNS_exempt",false];
// Roundtrip a real group through every HC, verify owner acknowledgement.
{
 private _id=owner _x;private _label=vehicleVarName _x;_g setGroupOwner _id;
 private _limit=diag_tickTime+12;waitUntil{sleep 0.2;groupOwner _g==_id || {diag_tickTime>_limit}};
 [_g,_label]remoteExecCall["Q_fnc_ownerProbe",_id];sleep 2;
 private _r=missionNamespace getVariable["Q_owner_"+_label,[]];
 ["ownership roundtrip "+_label,count _r>=4 && {_r select 2} && {(_r select 1)==_id} && {groupOwner _g==_id},_r]call Q_check;
 _g setGroupOwner 2;_limit=diag_tickTime+12;waitUntil{sleep 0.2;local _g || {diag_tickTime>_limit}};
}forEach _hcs;
[_g]call Q_delete;[_targetGroup]call Q_delete;sleep 2;
// AAT actual firing without task, then Rush and Hunt against a hostile vehicle.
{
 private _task=_x;
 private _aat=createVehicle["FST_AAT",[5000,5000,0],[],0,"NONE"];_aat setDir 0;createVehicleCrew _aat;_aat allowDamage false;
 private _ag=group gunner _aat;_ag setVariable["FST_HC_keepActive",true,true];_ag setCombatMode "RED";
 private _enemy=createVehicle["B_MRAP_01_hmg_F",[5000,5200,0],[],0,"NONE"];createVehicleCrew _enemy;_enemy allowDamage false;{_x allowDamage false;_x disableAI "ALL"}forEach crew _enemy;
 _aat setVariable["Q_shots",[]];_aat addEventHandler["Fired",{params["_v","_weapon","_muzzle","_mode","_ammo"];private _s=_v getVariable["Q_shots",[]];_s pushBack[_weapon,_muzzle,_ammo];_v setVariable["Q_shots",_s]}];
 _ag reveal[_enemy,4];
 if(_task!="")then{[_ag,_task,[5000,5200,0],500]call FST_HCSpawn_fnc_setCombatTask};
 private _start=getPosATL _aat;private _until=diag_tickTime+40;
 while{diag_tickTime<_until}do{diag_log format["[QUAL_AAT_SAMPLE] %1",[_task,getPosATL _aat,getDir _aat,velocityModelSpace _aat,count(_aat getVariable["Q_shots",[]]),assignedTarget gunner _aat,weaponState _aat]];sleep 5};
 private _shots=_aat getVariable["Q_shots",[]];
 ["AAT firing task="+_task,count _shots>0,[count _shots,getPosATL _aat,_aat distance2D _start]]call Q_check;
 ["AAT cannon firing task="+_task,(_shots findIf{(_x select 0)=="FST_AAT_Cannon"})>=0,{(_x select 0)=="FST_AAT_Cannon"}count _shots]call Q_check;
 [_ag,"stop"]call FST_HCSpawn_fnc_setCombatTask;sleep 1;
 ["AAT pulse released task="+_task,count(_aat getVariable["BURNS_armorPulse",[]])==0]call Q_check;
 [group driver _enemy]call Q_delete;[_ag]call Q_delete;sleep 2;
}forEach ["","rush","hunt"];
// Full loaded dispenser: 24 real falling pods on separate points.
if(!isNil "FST_Droid_Dispenser")then{
 private _beforeUnits=allUnits;private _beforePods=allMissionObjects "land_ShellCrater_02_small_F";
 for "_i" from 0 to 23 do{[ATLToASL[7000+(_i mod 6)*45,7000+(floor(_i/6))*45,0],[east],0,false]call FST_Droid_Dispenser;sleep 0.2};
 sleep 35;
 private _pods=(allMissionObjects "land_ShellCrater_02_small_F")-_beforePods;private _troops=allUnits-_beforeUnits;
 ["24 real pod impacts",count _pods==24,count _pods]call Q_check;
 ["real pods produce living troops",count(_troops select{alive _x})>=72,[count _troops,{alive _x}count _troops]]call Q_check;
 {_x setVariable["BURNS_exempt",true];deleteVehicle _x}forEach _troops;{deleteVehicle _x}forEach _pods;
};
diag_log format["[QUAL_DONE] checks=%1 failures=%2 fps=%3 engagementMaxMs=%4",count Q_checks,Q_checks select{!(_x select 1)},diag_fps,missionNamespace getVariable["BURNS_EngagementMaxMs",-1]];
private _guards=[]execVM "guards.sqf";waitUntil{sleep 1;scriptDone _guards};
[]execVM "extended.sqf";
