// Smooth altitude clamp for FST_Saber_Fly
params ["_veh"];
if (!local _veh) exitWith {};

private _hoverHeight = 1;      // Desired hover height above terrain
private _smoothingFactor = 0.15;  // Lower = smoother; 0.15–0.25 recommended
private _vzOld = 0;

while {alive _veh} do {
    // Position & terrain
    private _posASL = getPosASL _veh;
    private _terrainASL = getTerrainHeightASL _posASL;
    private _targetASL = _terrainASL + _hoverHeight;
    private _deltaZ = _targetASL - (_posASL select 2);

    // Current velocity in model space
    private _velMS = velocityModelSpace _veh;
    private _vx = _velMS select 0;
    private _vy = _velMS select 1;

    // Inertia smoothing: blend vertical velocity toward target
    private _vzTarget = _deltaZ * 1.5;                      // force factor
    private _vz = (_vzOld * (1 - _smoothingFactor)) + (_vzTarget * _smoothingFactor);
    _vzOld = _vz;

    // Apply smoothed velocity
    _veh setVelocityModelSpace [_vx, _vy, _vz];

    sleep 0.2; // less aggressive correction for realism
};