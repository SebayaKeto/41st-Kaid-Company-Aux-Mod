if(!isServer)exitWith{};sleep 15;
private _c=configFile>>"CfgVehicles">>"FST_AAT";
diag_log format["[TQ_CONFIG_SOURCE] %1",configSourceAddonList _c];
{diag_log format["[TQ_CONFIG] %1",[_x,getNumber(_c>>_x),getText(_c>>_x),getArray(_c>>_x)]]}forEach["simulation","peakTorque","enginePower","maxOmega","torqueCurve","maxSpeed","tankTurnForce","accelAidForceCoef","accelAidForceYOffset","accelAidForceSpd","clutchStrength","idleRpm","redRpm"];
{diag_log format["[TQ_GEARBOX] %1",[_x,getNumber(_c>>"GearboxRatios">>_x),getArray(_c>>"complexGearbox">>_x)]]}forEach["GearboxRatios","TransmissionRatios"];
private _v=createVehicle["FST_AAT",[6500,18700,0],[],0,"CAN_COLLIDE"];diag_log format["[TQ_MASS] %1",getMass _v];deleteVehicle _v;
Q_lanes=[];
{
 _x params["_label","_min","_max"];
 private _found=false;
 for "_px" from 6500 to 14500 step 100 do{if(_found)exitWith{};
  for "_py" from 11000 to 19000 step 100 do{if(_found)exitWith{};
   private _p=[_px,_py,0];private _n=surfaceNormal _p;private _a=acos(_n select 2);
   if(_a>=_min && {_a<=_max} && {getTerrainHeightASL _p>20})then{
    private _up=vectorNormalized[-(_n select 0),-(_n select 1),0];private _ok=true;private _samples=[];
    for "_d" from 0 to 80 step 10 do{
     private _s=_p vectorAdd(_up vectorMultiply _d);private _grade=acos(surfaceNormal _s select 2);
     if(surfaceIsWater _s || {_grade>_max+4} || {_grade<_min-4} || {count(nearestTerrainObjects[_s,["TREE","SMALL TREE","BUSH","ROCK","ROCKS","HOUSE","WALL"],8,false,true])>0})then{_ok=false};
     _samples pushBack[_d,getTerrainHeightASL _s,_grade];
    };
    if(_ok)then{Q_lanes pushBack[_label,_p,_up,_samples];_found=true};
   };
  };
 };
}forEach[["moderate",8,14],["steep",17,23]];
{diag_log format["[TQ_LANE] %1",_x]}forEach Q_lanes;
diag_log "[TQ_PROBE_DONE]";
