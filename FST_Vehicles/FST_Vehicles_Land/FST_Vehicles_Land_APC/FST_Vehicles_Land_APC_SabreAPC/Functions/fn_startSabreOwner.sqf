// One controller on the vehicle owner. Called by Init and the Local handler.
params ["_vehicle",["_isLocal",true]];
if (isNull _vehicle) exitWith {false};
private _started=false;
isNil {
    private _handle=_vehicle getVariable ["FST_raiderOwnerScript",scriptNull];
    if (!_isLocal || {!local _vehicle} || {!alive _vehicle}) then {
        _vehicle setVariable ["FST_raiderOwnerEpoch",(_vehicle getVariable ["FST_raiderOwnerEpoch",0])+1];
        if (!scriptDone _handle) then {terminate _handle};
        _vehicle setVariable ["FST_raiderOwnerScript",nil];
        _vehicle setVariable ["FST_sabreArmorMonitorRunning",false];
    } else {
        if (scriptDone _handle) then {
            private _epoch=(_vehicle getVariable ["FST_raiderOwnerEpoch",0])+1;
            _vehicle setVariable ["FST_raiderOwnerEpoch",_epoch];
            _vehicle setVariable ["FST_sabreArmorMonitorRunning",true];
            // Refuel coordinates are authored once by the owner, not every JIP
            // machine. An unchanged value causes no new public write.
            private _hookPos=_vehicle selectionPosition ["ACE_Refuel_Point","Memory"];
            if !(_hookPos isEqualTo [0,0,0]) then {
                if !((_vehicle getVariable ["ace_refuel_hooks",[]]) isEqualTo [_hookPos]) then {
                    _vehicle setVariable ["ace_refuel_hooks",[_hookPos],true];
                };
            };
            _handle=[_vehicle,_epoch] spawn {
                params ["_vehicle","_epoch"];
                while {alive _vehicle && {local _vehicle} && {(_vehicle getVariable ["FST_raiderOwnerEpoch",-1])==_epoch}} do {
                    // Finish an update atomically; do not yield halfway through
                    // an ownership-sensitive animation or armor change.
                    isNil {[_vehicle,_epoch] call FST_Raider_fnc_updateSabreOwner};
                    uiSleep 0.1;
                };
                if (!isNull _vehicle && {(_vehicle getVariable ["FST_raiderOwnerEpoch",-1])==_epoch}) then {
                    _vehicle setVariable ["FST_raiderOwnerScript",nil];
                    _vehicle setVariable ["FST_sabreArmorMonitorRunning",false];
                };
            };
            _vehicle setVariable ["FST_raiderOwnerScript",_handle];
            _started=true;
        };
    };
};
_started
