sleep 95;
Q_checks=[];Q_check={params["_name","_pass",["_detail",[]]];Q_checks pushBack[_name,_pass,_detail];diag_log format["[AF_CHECK] %1",[_name,_pass,_detail]]};
private _expected=0.65/1.05;private _fp=fogParams;
["Fog target remains after weather guard",abs((_fp select 0)-_expected)<0.005,_fp]call Q_check;
["Fog height and decay preserved",abs((_fp select 1)-0.017)<0.0001 && {abs((_fp select 2)-(missionNamespace getVariable["KAID_FogBase",-1000]))<0.1},_fp]call Q_check;
["Fog gain defaults to five percent",missionNamespace getVariable["KAID_Umbara_VisibilityGain",0]==1.05]call Q_check;
diag_log format["[AF_DONE] checks=%1 failed=%2",count Q_checks,{!(_x select 1)}count Q_checks];
