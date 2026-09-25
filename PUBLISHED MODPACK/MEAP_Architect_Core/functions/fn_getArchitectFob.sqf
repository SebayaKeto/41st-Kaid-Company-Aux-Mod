params [
    ["_position", [], [[]]],
    ["_radius", missionNamespace getVariable ["MEAP_Architect_fobRadius", 250], [0]]
];

if (!isServer || {!(_position isEqualTypeParams [0, 0, 0])}) exitWith {["", []]};
call MEAP_fnc_initializeArchitectState;

private _fobKey = "";
private _fob = [];
private _nearestDistance = _radius;
{
    private _candidate = _y;
    private _heart = _candidate param [0, objNull];
    if (!isNull _heart && {alive _heart}) then
    {
        private _distance = _position distance (getPosASL _heart);
        if (_distance <= _nearestDistance) then
        {
            _nearestDistance = _distance;
            _fobKey = _x;
            _fob = _candidate;
        };
    };
} forEach MEAP_Architect_fobs;

[_fobKey, _fob]
