params ["_veh"];
if (isNull _veh) exitWith {};
if (!local _veh) exitWith {};
if (_veh getVariable ["FST_forceSabreWaterHover_running", false]) exitWith {};

_veh setVariable ["FST_forceSabreWaterHover_running", true];

private _targetWaterHeightASL = 2;
private _smoothFactor = 0.35;
private _vzOld = 0;

while {alive _veh} do {
    if (surfaceIsWater (getPosWorld _veh)) then {
        private _posASL = getPosASL _veh;
        private _zNow = _posASL select 2;
        private _delta = _targetWaterHeightASL - _zNow;

        private _velMS = velocityModelSpace _veh;
        private _vx = _velMS select 0;
        private _vy = _velMS select 1;

        private _vzTarget = (_delta * 3) max -4 min 4;
        private _vz = (_vzOld * (1 - _smoothFactor)) + (_vzTarget * _smoothFactor);
        _vzOld = _vz;

        _veh setVelocityModelSpace [_vx, _vy, _vz];

        if (_zNow < (_targetWaterHeightASL - 0.75)) then {
            _veh setPosASL [
                _posASL select 0,
                _posASL select 1,
                _targetWaterHeightASL
            ];
        };

        uiSleep 0.05;
    } else {
        _vzOld = 0;
        uiSleep 0.2;
    };
};

_veh setVariable ["FST_forceSabreWaterHover_running", false];
