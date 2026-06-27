
_this addAction ['Hack Device', {[_this select 0, _this select 1, _this select 2] call FST_CivilRandomizers_fnc_hackingterminal;}, nil,6,true,true,"","true",3];
_this addAction ['Repair Device', {[_this select 0, _this select 1, _this select 2] call FST_CivilRandomizers_fnc_hackingterminal;}, nil,6,true,true,"","true",3];

_this setVariable ["FST_DeviceHacked",false,true];
_this setVariable ["FST_DeviceBroken",true,true];


[_this,['Hack Device', {[_this select 0, _this select 1, _this select 2] call FST_CivilRandomizers_fnc_hackingterminal;}, nil,6,true,true,"","true",3]] remoteExec ["addAction", 0, true];