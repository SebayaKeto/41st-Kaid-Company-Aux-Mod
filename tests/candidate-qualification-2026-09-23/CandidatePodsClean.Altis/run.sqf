if(!isServer)exitWith{};sleep 15;
Q_checks=[];Q_check={params["_n","_p",["_d",[]]];Q_checks pushBack[_n,_p,_d];diag_log format["[QUAL_CHECK] %1",[_n,_p,_d]]};
Q_slope=[6500,18700,0];Q_up=[0.363938,0.931423,0];
["elevated dry test ground",getTerrainHeightASL Q_slope>50,[getTerrainHeightASL Q_slope,surfaceIsWater Q_slope]]call Q_check;
Q_created=[];Q_entityEH=addMissionEventHandler["EntityCreated",{params["_e"];if(_e isKindOf "CAManBase" && {!isPlayer _e})then{Q_created pushBack _e}}];
diag_log "[QUAL_PODS_BEGIN]";
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
 private _before=allMissionObjects "All";private _beforeUnits=allUnits;Q_created=[];
 private _p=if(count Q_slope==3)then{Q_slope}else{[10500,10500,0]};
 private _diamond=_fn find "Diamond">=0;
 private _params=if(_diamond)then{[ATLToASL _p,0,[east],24,false,0,0,0.5,false,false,0]}else{[ATLToASL _p,0,[east],0,24,false,0,0,0.5,false,false,0]};
 diag_log format["[QUAL_FAULT_BEGIN] %1",[_fault,_fn]];
 _params call(missionNamespace getVariable _fn);
 sleep 60;
diag_log format["[QUAL_POD_SURVIVAL] %1",[Q_fault,count Q_created,{alive _x}count Q_created,{!alive _x}count Q_created,count Q_podRequests,allDeadMen apply{[typeOf _x,getPosATL _x]}]];

 ["pod fault reached "+_fault,Q_faultApplied]call Q_check;
 ["pod fault request count "+_fault,if(_fault=="ship")then{count Q_podRequests<=1}else{count Q_podRequests==_expected},count Q_podRequests]call Q_check;
 if(_expected>0)then{
  ["elevated ship positions follow ground",(Q_podRequests findIf{abs(((ASLToATL(_x select 0))select 2))>0.1})<0,[getTerrainHeightASL _p,Q_podRequests apply{(_x select 0)select 2}]]call Q_check;
  ["partial anchors still deliver troops",{alive _x}count(allUnits-_beforeUnits)>=72,{alive _x}count(allUnits-_beforeUnits)]call Q_check;
 };
 {(if(!isPlayer _x)then{deleteVehicle _x})}forEach((allMissionObjects "All")-_before);sleep 2;
}forEach[["partial","FST_ScifiSupportPlus_fnc_SW_Munificent_QRF",24],["ship","FST_ScifiSupportPlus_fnc_SW_Diamond_QRF",0]];
FST_fnc_nextPodAnchor=Q_realAnchor;Q_podRequests=[];
private _before=allMissionObjects "All";private _beforeUnits=allUnits;Q_created=[];
{
 [ATLToASL[6500+_forEachIndex*1500,18700,0],0,[east],0,24,false,0,0,0.5,false,false,0]call(missionNamespace getVariable _x);
}forEach["FST_ScifiSupportPlus_fnc_SW_Munificent_QRF","FST_ScifiSupportPlus_fnc_SW_Providence_Jorge_QRF"];
sleep 60;
diag_log format["[QUAL_POD_SURVIVAL] %1",[Q_fault,count Q_created,{alive _x}count Q_created,{!alive _x}count Q_created,count Q_podRequests,allDeadMen apply{[typeOf _x,getPosATL _x]}]];

["concurrent ships submit 48",count Q_podRequests==48,count Q_podRequests]call Q_check;
["concurrent ships deliver living troops",{alive _x}count(allUnits-_beforeUnits)>=144,{alive _x}count(allUnits-_beforeUnits)]call Q_check;
FST_Droid_Dispenser=Q_realDispenser;
{if(!isPlayer _x)then{deleteVehicle _x}}forEach((allMissionObjects "All")-_before);
diag_log "[QUAL_EDGES_DONE]";

removeMissionEventHandler["EntityCreated",Q_entityEH];
diag_log format["[QUAL_FOLLOWUP_DONE] checks=%1 failures=%2",count Q_checks,Q_checks select{!(_x select 1)}];
