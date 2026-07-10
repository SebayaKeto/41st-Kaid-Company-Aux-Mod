params ["_veh"];
if (isNull _veh) exitWith {};
if (!local _veh) exitWith {};
if (_veh getVariable ["FST_forceSabreWaterHover_running", false]) exitWith {};

_veh setVariable ["FST_forceSabreWaterHover_running", true];

private _targetWaterHeightASL = 2;
private _hardResetDepth = 1.6;
private _orientationBlend = 0.06;
private _uprightMinZ = 0.75;

while {alive _veh} do {
    if (surfaceIsWater (getPosWorld _veh)) then {
        private _posASL = getPosASL _veh;
        private _zNow = _posASL select 2;

        // Keep the APC upright over water while preserving heading control.
        private _upNow = vectorUp _veh;
        if ((_upNow select 2) < _uprightMinZ) then {
            _veh setVectorUp [
                (_upNow select 0) * (1 - _orientationBlend),
                (_upNow select 1) * (1 - _orientationBlend),
                ((_upNow select 2) * (1 - _orientationBlend)) + _orientationBlend
            ];
        };

        if (_zNow < (_targetWaterHeightASL - _hardResetDepth)) then {
            private _velBeforeReset = velocity _veh;
            _veh setPosASL [
                _posASL select 0,
                _posASL select 1,
                _targetWaterHeightASL
            ];
            _veh setVelocity _velBeforeReset;
            if ((vectorUp _veh select 2) < 0.55) then {
                _veh setVectorUp [0,0,1];
            };
        };

        uiSleep 0.15;
    } else {
        uiSleep 0.25;
    };
};

_veh setVariable ["FST_forceSabreWaterHover_running", false];
