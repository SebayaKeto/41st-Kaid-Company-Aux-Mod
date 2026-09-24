// Count the current fight, including nearby Zeus forces. Distant static garrisons
// do not consume its budget. All living DAARA units still consume budget wherever
// they move, so leaving an objective cannot create an unlimited spawning pool.
DI_fnc_pressureEnemies = {
    params ["_ready","_hints"];
    private _centers = [];
    {
        private _center = _y get "position";
        if (!(_y get "complete") && {(_ready findIf {_x distance2D _center < DI_objectiveActivationDistance}) >= 0 || {_x in _hints}}) then {_centers pushBack _center};
    } forEach DI_objectives;
    private _all = allUnits select {alive _x && {!isPlayer _x} && {side group _x == east}};
    private _engaged = _all select {
        private _unit = _x;
        (group _unit getVariable ["DI_operation",""]) == DI_operation ||
        {(_ready findIf {_unit distance2D _x < DI_localForceRadius}) >= 0} ||
        {(_centers findIf {_unit distance2D _x < DI_localForceRadius}) >= 0}
    };
    [_all,_engaged]
};
DI_fnc_directorReport = {
    params ["_reason","_budget","_engaged","_world","_pending","_workers",["_rows",[]]];
    private _created = 0; private _units = 0;
    {if (_y getOrDefault ["actualCount",0] > 0) then {_created = _created + 1;_units = _units + (_y get "actualCount")}} forEach DI_actions;
    DI_directorTelemetry = [DI_operation,1,_reason,_budget,_engaged,_world,_pending,_workers,_created,_units,_rows];
    DI_directorText = format ["Director: %1 | engaged %2 / budget %3 | pending %4 | eligible HCs %5 | created %6 groups / %7 units this operation",_reason,_engaged,_budget,_pending,_workers,_created,_units];
};
