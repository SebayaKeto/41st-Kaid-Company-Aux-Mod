params ["_logic", "_classList"];

// Retrieve settings from Module Attributes
private _count = _logic getVariable ["Drop_Count", 10];
private _radius = _logic getVariable ["Drop_Radius", 100];
private _altitude = _logic getVariable ["Drop_Altitude", 1000];
private _randomDir = _logic getVariable ["Random_Dir", true];
private _compassDir = _logic getVariable ["Compass_Dir", 0];
private _useThrusters = _logic getVariable ["Enable_Thrusters", true];

private _centerPos = getPos _logic;

for "_i" from 1 to _count do {
    // 1. Select Random Class from the chosen list
    private _className = selectRandom _classList;
    
    // 2. Random Position
    private _randomPos = [
        (_centerPos select 0) + ((random (_radius * 2)) - _radius),
        (_centerPos select 1) + ((random (_radius * 2)) - _radius),
        _altitude + (random 200)
    ];
    
    // 3. Spawn & Drop
    private _object = createVehicle [_className, _randomPos, [], 0, "CAN_COLLIDE"];
    
    if (_randomDir) then {
        _object setDir (random 360);
    } else {
        _object setDir _compassDir;
    };
    
    [_object, _useThrusters] spawn {
        sleep (random 2); 
        _this call HKD_fnc_initHKDDrop;
    };
};

deleteVehicle _logic;