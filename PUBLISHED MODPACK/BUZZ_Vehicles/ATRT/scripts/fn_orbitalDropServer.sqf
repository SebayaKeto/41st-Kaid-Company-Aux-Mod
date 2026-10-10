// =============================================================================
//  BUZZ AT-RT — fn_orbitalDropServer.sqf
// =============================================================================
if (!isServer) exitWith {};

params [
    ["_centerASL", [0, 0, 0], [[]], 3],
    ["_count", 1, [0]],
    ["_dropHeight", 1000, [0]],
    ["_chuteHeight", 100, [0]]
];

private _fallSpeed    = 50;
private _landSpeed    = 5;
private _chuteDecel   = 30;   // m/s^2 applied under canopy
private _spread       = 50;
private _minGap       = 7;

_count       = ((round _count) max 1) min 8;
_dropHeight  = (_dropHeight max 500) min 3000;
_chuteHeight = (_chuteHeight max 100) min 1000;
// Chute height clamp
_chuteHeight = _chuteHeight min (_dropHeight - 50);
private _center = ASLtoATL _centerASL;

// -----------------------------------------------------------------------------
//  Pick landing points (uniform over the disc, spaced >= _minGap apart)
// -----------------------------------------------------------------------------
private _landings = [];
for "_i" from 1 to _count do {
    private _best    = [];
    private _bestGap = -1;
    for "_try" from 1 to 40 do {
        private _cand = _center getPos [_spread * sqrt random 1, random 360];
        private _gap  = 1e6;
        { _gap = _gap min (_cand distance2D _x); } forEach _landings;
        if (_gap > _bestGap) then { _bestGap = _gap; _best = _cand; };
        if (_gap >= _minGap) exitWith {};
    };
    _landings pushBack _best;
};

// -----------------------------------------------------------------------------
//  Release the crates, staggered
// -----------------------------------------------------------------------------
[_landings, _dropHeight, _chuteHeight, _fallSpeed, _landSpeed, _chuteDecel] spawn {
params ["_landings", "_dropHeight", "_chuteHeight", "_fallSpeed", "_landSpeed", "_chuteDecel"];
{
    [_x, _dropHeight, _chuteHeight, _fallSpeed, _landSpeed, _chuteDecel] spawn {
        params ["_land", "_dropHeight", "_chuteHeight", "_fallSpeed", "_landSpeed", "_chuteDecel"];

        private _crate = createVehicle ["BUZZ_ATRT_TransportCrate", [_land#0, _land#1, _dropHeight], [], 0, "CAN_COLLIDE"];
        _crate setPosATL [_land#0, _land#1, _dropHeight];
        private _dir = random 360;
        _crate setVectorDirAndUp [[sin _dir, cos _dir, 0], [0, 0, 1]];
        _crate setVelocity [0, 0, -_fallSpeed];

        // Zeus editable
        { _x addCuratorEditableObjects [[_crate], true]; } forEach allCurators;

        private _chute   = objNull;
        private _phase   = 0;   // fall phase
        private _vz      = -_fallSpeed;
        private _last    = time;

        while {!isNull _crate && {_phase < 2}} do {
            private _dt = (time - _last) max 0.001;
            _last = time;
            private _h = (getPosATL _crate) select 2;

            if (_phase == 0 && {_h <= _chuteHeight}) then {
                _chute = createVehicle ["B_Parachute_02_F", getPosATL _crate, [], 0, "CAN_COLLIDE"];
                _chute setPosATL (getPosATL _crate);
                _chute setVectorDirAndUp [[sin _dir, cos _dir, 0], [0, 0, 1]];
                _crate attachTo [_chute, [0, 0, 0]];
                _phase = 1;
            };

            if (_phase == 0) then {
                _crate setVelocity [0, 0, -_fallSpeed];
            } else {
                _vz = (_vz + _chuteDecel * _dt) min -_landSpeed;
                _chute setVelocity [0, 0, _vz];
                if (_h <= 1) then { _phase = 2; };
            };

            sleep 0.03;
        };

        if (isNull _crate) exitWith { deleteVehicle _chute; };

        // Touchdown
        detach _crate;
        _crate setVelocity [0, 0, -1];
        deleteVehicle _chute;

        sleep 2;
        if (isNull _crate) exitWith {};

        private _smoke = createVehicle ["SmokeShellGreen", getPosATL _crate, [], 0, "CAN_COLLIDE"];
    };

    sleep 1;
} forEach _landings;
};
