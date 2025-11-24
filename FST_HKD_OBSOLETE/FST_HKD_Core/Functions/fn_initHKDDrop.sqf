/*
    Author: Maldova Engineering Corp.
    Function: HKD_fnc_initHKDDrop
    Description: Handles the physics, thrusters, and impact of a gravity-dropped object.
    
    Params:
    0: OBJECT - The object being dropped
    1: BOOL - Enable Thruster Effects (True/False)
*/

params ["_object", "_enableThrusters"];

if (isNull _object) exitWith {};
private _helper = createVehicle ["Land_Can_V3_F", getPosATL _object, [], 0, "CAN_COLLIDE"];
_helper setPosATL (getPosATL _object);
_helper setMass 1000; // Give it weight
_object attachTo [_helper, [0,0,0]]; 

hideObjectGlobal _helper;

[_object, _helper, _enableThrusters] spawn {
    params ["_obj", "_physHelper", "_useThrusters"];
    
    private _hasThrust = false;
    private _impact = false;
    private _particleSource = objNull;
    
    while {alive _obj && !_impact} do {
        private _alt = (getPosATL _obj) select 2;
        private _vel = velocity _physHelper;
        
        // --- THRUSTER LOGIC (300m Activation) ---
        if (_useThrusters && _alt < 300 && _alt > 5 && !_hasThrust) then {
            _hasThrust = true;
            
            // Visual: Fire Effect at Memory Point
            _particleSource = "#particlesource" createVehicleLocal (getPos _obj);
            _particleSource attachTo [_obj, [0,0,0], "HKD_GravDropThruster"];
            
            // Use a blue-ish flame for CIS Ion engines
            _particleSource setParticleClass "ObjectDestructionFire1Small"; 
            
            // Audio: Thruster burn
            playSound3D ["A3\Sounds_F\vehicles\air\noises\jet_engine_high_1.wss", _obj, false, getPosASL _obj, 3, 1, 300];
        };
        
        // Physics: Apply braking force if thrusters active
        if (_hasThrust && _alt > 10) then {
            // Apply upward force to slow descent
            _physHelper addForce [[0,0, 8000], [0,0,0]]; 
        };
        
        // --- IMPACT CHECK ---
        // If speed is near zero or altitude is near zero (Ground Hit)
        if ((getPosATL _obj) select 2 < 0.5) then {
            _impact = true;
        };
        
        sleep 0.01;
    };
    
    // 3. Impact & Cleanup
    detach _obj;
    deleteVehicle _physHelper;
    if (!isNull _particleSource) then { deleteVehicle _particleSource; };
    
    // Lock object to ground (prevent sliding)
    _obj setVelocity [0,0,0];
    _obj setVectorUp (surfaceNormal (getPos _obj));
    
    // Effects
    playSound3D ["A3\Sounds_F\sfx\missions\vehicle_collision.wss", _obj, false, getPosASL _obj, 5, 0.8, 200];
    
    // Dust Cloud
    private _dust = "#particlesource" createVehicleLocal (getPos _obj);
    _dust setParticleClass "HouseDestrSmokeSmall";
    _dust setDropInterval 0.05;
    sleep 2;
    deleteVehicle _dust;
};