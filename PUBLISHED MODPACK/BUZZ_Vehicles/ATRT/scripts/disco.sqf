// =============================================================================
//  BUZZ AT-RT — disco.sqf
// =============================================================================

params ["_atrt"];

if (!hasInterface) exitWith {};

addMissionEventHandler ["EachFrame", {
    // Shared lamp array
    _thisArgs params ["_atrt", "_lamps"];

    if (isNull _atrt) exitWith {
        { deleteVehicle _x } forEach _lamps;
        removeMissionEventHandler ["EachFrame", _thisEventHandler];
    };

    private _duration = 3;
    private _stamp    = _atrt getVariable ["BUZZ_discoStart", -1e9];
    private _elapsed  = serverTime - _stamp;
    private _running  = _elapsed >= 0 && _elapsed < _duration && alive _atrt;

    if (!_running) exitWith {
        if (_lamps isNotEqualTo []) then {
            { deleteVehicle _x } forEach _lamps;
            _lamps resize 0;
        };
    };

    if (_lamps isEqualTo []) then {
        private _colours = [
            [1.0, 0.0, 0.0], [1.0, 0.5, 0.0], [1.0, 1.0, 0.0], [0.5, 1.0, 0.0], [0.0, 1.0, 0.0],
            [0.0, 1.0, 0.8], [0.0, 0.5, 1.0], [0.2, 0.2, 1.0], [0.7, 0.0, 1.0], [1.0, 0.0, 0.7]
        ];
        {
            private _l = "#lightreflector" createVehicleLocal [0, 0, 0];
            _l setLightColor   _x;
            _l setLightAmbient _x;
            _l setLightUseFlare false;
            _l setLightDayLight false;
            _l setLightAttenuation [0.5, 0, 0, 0.0004, 0, 60];
            _l setLightConePars [45, 15, 1];
            _l setLightIntensity 0;
            _lamps pushBack _l;
        } forEach _colours;
    };

    {
        private _i = _forEachIndex;
        private _ang = _i * 36;
        private _ringPos = _atrt modelToWorldVisualWorld [1.5 * sin _ang, 1.5 * cos _ang, 4.5];

        // Sweep direction
        private _yaw   = _ang + _elapsed * (if (_i % 2 == 0) then { 220 } else { -160 }) * (1 + _i * 0.05);
        // Tilt
        private _pitch = -55 + 20 * sin (_elapsed * 300 + _i * 50);

        private _dir = [sin _yaw * cos _pitch, cos _yaw * cos _pitch, sin _pitch];
        private _right = _dir vectorCrossProduct [0, 0, 1];
        private _up = _right vectorCrossProduct _dir;

        // Blink
        private _on = (_i % 3 == 0) || { (floor (_elapsed * (3 + _i % 4) + _i)) % 2 == 0 };

        _x setPosASL _ringPos;
        _x setVectorDirAndUp [_dir, _up];
        _x setLightIntensity (if (_on) then { 7500 } else { 0 });
    } forEach _lamps;
}, [_atrt, []]];
