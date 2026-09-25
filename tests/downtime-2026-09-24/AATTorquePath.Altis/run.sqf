Q_lanes=[["moderate",[6600,11400,0],[-0.585784,-0.810467,0],[[0,26.7998,9.43405],[10,28.6059,10.3357],[20,30.5135,10.3673],[30,32.2599,9.6843],[40,33.9679,9.66015],[50,35.6374,9.43494],[60,37.3702,11.5435],[70,39.2456,12.3492],[80,41.5119,17.1025]]],["steep",[6600,14400,0],[0.999804,-0.0197973,0],[[0,99.1702,22.0026],[10,103.204,22.042],[20,107.23,21.9856],[30,111.248,22.0009],[40,115.216,21.8934],[50,119.086,20.8255],[60,122.875,21.3045],[70,126.911,22.6444],[80,130.735,20.9379]]]];
if(!isServer)exitWith{};sleep 15;
Q_checks=[];Q_check={params["_name","_pass",["_detail",[]]];Q_checks pushBack[_name,_pass,_detail];diag_log format["[TQ_CHECK] %1",[_name,_pass,_detail]]};
setDate[2035,6,15,12,0];0 setFog 0;0 setOvercast 0;
private _base=configFile>>"CfgVehicles">>"FST_AAT";
{
 _x params["_class","_factor"];
 private _cfg=configFile>>"CfgVehicles">>_class;
 ["torque multiplier "+_class,abs(getNumber(_cfg>>"peakTorque")/getNumber(_base>>"peakTorque")-_factor)<0.001,getNumber(_cfg>>"peakTorque")]call Q_check;
 private _same=true;
 {if(getNumber(_cfg>>_x)!=getNumber(_base>>_x))then{_same=false}}forEach["enginePower","maxOmega","maxSpeed","tankTurnForce","clutchStrength"];
 {if(getArray(_cfg>>_x)isNotEqualTo getArray(_base>>_x))then{_same=false}}forEach["torqueCurve"];
 ["other powertrain settings unchanged "+_class,_same]call Q_check;
}forEach[["FST_AAT",1],["DT_AAT_Torque15",1.15],["DT_AAT_Torque30",1.3]];
for "_repeat" from 1 to 2 do{
 {
  _x params["_label","_p","_up","_grades"];
  private _end=_p vectorAdd(_up vectorMultiply 80);
  private _order=if(_repeat==1)then{["FST_AAT","DT_AAT_Torque15","DT_AAT_Torque30"]}else{["DT_AAT_Torque30","DT_AAT_Torque15","FST_AAT"]};
  {
   private _class=_x;private _v=createVehicle[_class,_p,[],0,"CAN_COLLIDE"];
   _v setDir(_p getDir _end);_v setVectorUp(surfaceNormal _p);_v setPosATL _p;createVehicleCrew _v;_v allowDamage false;
   private _g=group driver _v;_g setVariable["FST_HC_blacklisted",true,true];_g setVariable["BURNS_exempt",true,true];
   {_x allowDamage false;_x disableAI "AUTOCOMBAT"}forEach crew _v;_g setBehaviourStrong "CARELESS";_g setCombatMode "BLUE";_g setSpeedMode "FULL";
   sleep 3;private _origin=getPosASL _v;private _begin=time;private _arrival=-1;private _stalled=0;private _peak=0;
   {doStop _x}forEach crew _v;sleep 2;
   private _route=[];for "_d" from 10 to 80 step 10 do{private _point=_p vectorAdd(_up vectorMultiply _d);_point pushBack 8;_route pushBack _point};
   [format["steering component %1 %2 %3",_repeat,_label,_class],isAISteeringComponentEnabled _v]call Q_check;
   _v setDriveOnPath _route;_v engineOn true;_begin=time;
   diag_log format["[TQ_CASE] %1",[_repeat,_label,_class,_p,_end,_grades,getMass _v,getNumber(configFile>>"CfgVehicles">>_class>>"peakTorque")]];
   for "_i" from 1 to 35 do{
    sleep 1;private _pos=getPosASL _v;private _delta=_pos vectorDiff _origin;private _progress=_delta vectorDotProduct _up;private _cross=abs((_delta select 0)*(_up select 1)-(_delta select 1)*(_up select 0));
    _peak=_peak max speed _v;
    if(abs speed _v<1 && {_v distance2D _end>10})then{_stalled=_stalled+1};
    diag_log format["[TQ_SAMPLE] %1",[_repeat,_label,_class,_i,time-_begin,_progress,_cross,speed _v,(_pos select 2)-(_origin select 2),getPosATL _v,currentCommand driver _v,isEngineOn _v,canMove _v,getDir _v,velocityModelSpace _v,_v getSoundController "rpm",_v getSoundController "thrust"]];
    if(_progress>=60 && {_cross<12})exitWith{_arrival=time-_begin};
   };
   diag_log format["[TQ_RESULT] %1",[_repeat,_label,_class,_arrival,((getPosASL _v)vectorDiff _origin)vectorDotProduct _up,_stalled,_peak,_v distance2D _end]];
   [format["healthy local driver %1 %2 %3",_repeat,_label,_class],local _v && {alive driver _v} && {canMove _v}]call Q_check;
   {deleteVehicle _x}forEach crew _v;deleteVehicle _v;deleteGroup _g;sleep 1;
  }forEach _order;
 }forEach Q_lanes;
};
diag_log format["[TQ_DONE] checks=%1 failed=%2",count Q_checks,{!(_x select 1)}count Q_checks];
