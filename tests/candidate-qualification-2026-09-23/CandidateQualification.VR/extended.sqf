if(!isServer)exitWith{};
sleep 12;
Q_checks=[];
Q_check={params["_name","_pass",["_detail",[]]];Q_checks pushBack[_name,_pass,_detail];diag_log format["[QUAL_CHECK] %1",[_name,_pass,_detail]]};
diag_log "[QUAL_EXTENDED_BEGIN]";
// Terrain change exists only in this disposable test mission. Build a 20-degree ramp.
private _heights=[];
for "_x" from 7900 to 8200 step 25 do{for "_y" from 7900 to 8400 step 25 do{_heights pushBack[_x,_y,5+((_y-7900)max 0)*0.36]}};
setTerrainHeight[_heights,true];sleep 3;
["test ramp has slope",((surfaceNormal [8050,8100])select 2)<0.99,surfaceNormal[8050,8100]]call Q_check;
// Natural external controller pursuit; record exact mode/animation/position.
{
 private _class=_x;
 private _g=createGroup[east,true];private _tg=createGroup[west,true];
 private _u=_g createUnit[_class,[8050,8025,0],[],0,"NONE"];
 _u setDir 0;_u allowDamage false;_g setVariable["FST_HC_keepActive",true,true];
 private _t=_tg createUnit["B_Soldier_F",[8050,8110,0],[],0,"NONE"];
 _t allowDamage false;_t disableAI "ALL";
 _g reveal[_t,4];
 private _start=getPosATL _u;private _samples=[];
 for "_i" from 0 to 29 do{
  _samples pushBack[animationState _u,_u getVariable["mode",-1],getPosATL _u,speed _u,isTouchingGround _u];sleep 1;
 };
 private _climbs={toLower(_x select 0)=="burns_gulanthar_climb"}count _samples;
 ["natural uphill climb "+_class,_climbs>0,[_climbs,_u distance2D _start,_samples]]call Q_check;
 ["natural uphill progress "+_class,_u distance2D _start>8,_u distance2D _start]call Q_check;
 // Explicit state-boundary fixture exercises release without replacing controller code.
 _u setVariable["mode",2];_u switchMove "BURNS_gulanthar_climb";sleep 0.3;
 BURNS_GulantharSlopeEnabled=false;[_u]call FST_HCSpawn_fnc_burnsGulantharSlope;sleep 0.5;
 ["disabled gait releases "+_class,toLower animationState _u!="burns_gulanthar_climb",animationState _u]call Q_check;
 BURNS_GulantharSlopeEnabled=true;
 private _moves=getText(configOf _u>>"moves");
 private _base=configFile>>"CfgMovesForm939">>"States";
 private _derived=configFile>>_moves>>"States";
 private _attackClasses=("true"configClasses _base)select{(toLower configName _x)find"attack">=0 || {(toLower configName _x)find"eat">=0}};
 private _changed=_attackClasses select{getNumber(_x>>"speed")!=getNumber(_derived>>configName _x>>"speed") || {getText(_x>>"file")!=getText(_derived>>configName _x>>"file")}};
 ["attack and eating states unchanged "+_class,count _changed==0,[count _attackClasses,_changed apply{configName _x}]]call Q_check;
 deleteVehicle _u;deleteVehicle _t;deleteGroup _g;deleteGroup _tg;sleep 2;
}forEach["JMSEF_animals_varren_o","JMSEF_animals_var_bers_o","JMSEF_animals_var_alpha_o"];
// Observe complete ship-to-dispenser path. Wrapper records and delegates every request unchanged.
Q_realDispenser=FST_Droid_Dispenser;Q_podRequests=[];
FST_Droid_Dispenser={Q_podRequests pushBack[diag_tickTime,+_this];_this call Q_realDispenser};
private _functions=["FST_ScifiSupportPlus_fnc_SW_Munificent_QRF","FST_ScifiSupportPlus_fnc_SW_Providence_QRF","FST_ScifiSupportPlus_fnc_SW_Diamond_QRF","FST_ScifiSupportPlus_fnc_SW_Providence_Jorge_QRF"];
{
 private _name=_x;private _i=_forEachIndex;
 private _position=if(_i==3)then{[8050,8200,0]}else{[4500+_i*1400,6500,0]};
 private _existing=allMissionObjects "All";private _unitsBefore=allUnits;
 Q_podRequests=[];
 private _params=if(_i==2)then{[ATLToASL _position,0,[east],24,false,0,0,0.5,false,false,0]}else{[ATLToASL _position,0,[east],0,24,false,0,0,0.5,false,false,0]};
 diag_log format["[QUAL_SHIP_BEGIN] %1",[_name,_position,getTerrainHeightASL _position]];
 _params call(missionNamespace getVariable _name);
 private _deadline=diag_tickTime+110;
 waitUntil{sleep 1;count Q_podRequests>=24 || {diag_tickTime>_deadline}};
 sleep 22;
 private _new=(allMissionObjects "All")-_existing;
 private _pods=_new select{typeOf _x=="land_ShellCrater_02_small_F"};
 private _troops=allUnits-_unitsBefore;
 ["ship 24 requests "+_name,count Q_podRequests==24,count Q_podRequests]call Q_check;
 ["ship 24 impact craters "+_name,count _pods==24,count _pods]call Q_check;
 ["ship living troop delivery "+_name,{alive _x}count _troops>=72,[count _troops,{alive _x}count _troops]]call Q_check;
 ["pod coordinates follow elevated ground "+_name,(Q_podRequests findIf{abs(((ASLToATL((_x select 1)select 0))select 2))>0.1})<0]call Q_check;
 // Wait for the parent deployment to finish before deleting its test-only objects.
 sleep 30;
 {if(!isPlayer _x)then{deleteVehicle _x}}forEach _new;sleep 2;
}forEach _functions;
FST_Droid_Dispenser=Q_realDispenser;
diag_log format["[QUAL_EXTENDED_DONE] checks=%1 failures=%2 fps=%3",count Q_checks,Q_checks select{!(_x select 1)},diag_fps];
