
_this addAction ['Hack Device', {[_this select 0, _this select 1] call FST_CivilRandomizers_fnc_hackingterminal;}, nil,6,true,true,"","true",3];

_this setVariable ["FST_DeviceHacked",false,true];