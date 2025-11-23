/*
    Author: Maldova Engineering Corp.
    Function: HKD_fnc_moduleHKDDropSingle
    Description: Zeus Module execution for single object drop.
*/

_logic = param [0,objNull,[objNull]];
_units = param [1,[],[[]]];
_activated = param [2,true,[true]];

if (_activated) then {
    // 1. Get Module Arguments (Defined in Config)
    private _className = _logic getVariable ["Object_Class", "Land_HKD_VehicleBlocker"];
    private _altitude = _logic getVariable ["Drop_Altitude", 1000];
    private _randomDir = _logic getVariable ["Random_Dir", true];
    private _compassDir = _logic getVariable ["Compass_Dir", 0];
    private _useThrusters = _logic getVariable ["Enable_Thrusters", true];
    
    // 2. Determine Position
    private _spawnPos = getPos _logic;
    _spawnPos set [2, _altitude];
    
    // 3. Spawn Object
    private _object = createVehicle [_className, _spawnPos, [], 0, "CAN_COLLIDE"];
    
    // 4. Set Orientation
    if (_randomDir) then {
        _object setDir (random 360);
    } else {
        _object setDir _compassDir;
    };
    
    // 5. Verify "CanBeDropped" Variable
    // Note: If you want to enforce this strictly, check the config value.
    // For now, we assume the module list only contains valid objects.
    // private _canDrop = getNumber (configFile >> "CfgVehicles" >> _className >> "HKD_CanBeGravDropped");
    
    // 6. Initiate Drop Logic
    [_object, _useThrusters] call HKD_fnc_initHKDDrop;
    
    // Cleanup Module Logic
    deleteVehicle _logic;
};