/*
    generic_power_management.sqf
    CORE FUNCTIONALITY: A modular, low-ACE-dependency power system for any object.
    Charge is tracked via object variables (e.g., _object getVariable "currentCharge").
    
    Note: This file must be broken into separate fn_*.sqf files and located
    in the MEC_ELECTRICITY_PATH folder as defined in the config.
*/

// --- Function 1: Initialize Power State on ANY Object ---
// Sets up all necessary default variables on the target object.
// Call: [itemObject, 1000, 10, "MEC_TAG_fnc_dischargeRate"] call MEC_TAG_fnc_initializeChargeState;
initializeChargeState = {
    params ["_object", "_maxCharge", "_baseDischargeRate", "_dischargeFunction"];

    // 1. Initial State Check (Do not overwrite variables if already present)
    if (isNil (_object getVariable ["currentCharge", nil])) then {
        // Set initial charge and maximum capacity
        _object setVariable ["currentCharge", _maxCharge, TRUE];
        _object setVariable ["maxCharge", _maxCharge, TRUE];
        
        // 2. Set Operational Parameters
        _object setVariable ["dischargeRate", _baseDischargeRate, TRUE]; // e.g., 10 (units per second)
        _object setVariable ["dischargeFunction", _dischargeFunction, TRUE]; // Function to run when draining
        _object setVariable ["isCharging", FALSE, TRUE]; // Boolean state
        _object setVariable ["isAttached", FALSE, TRUE]; // Boolean state
    };
    
    // Ensure variables are public for client synchronization
    if !(variableIsPublic _object "currentCharge") then {
        _object setVariable ["currentCharge", _object getVariable "currentCharge", TRUE];
    };
};

// --- Function 2: Check and Display Generic Charge Level ---
// Displays the charge status of any object with the correct variables.
// Called via the ACE Interaction menu.
// Call: [player, itemObject] call MEC_TAG_fnc_checkChargeState;
checkChargeState = {
    params ["_player", "_object"];
    
    private _charge = _object getVariable ["currentCharge", 0];
    private _maxCharge = _object getVariable ["maxCharge", 1];
    
    private _chargePercent = round (_charge / _maxCharge * 100);
    private _chargeColor = "";
    private _statusText = "";
    
    // Estimate based on a standardized unit of charge (using 10 units/hour standard)
    private _dischargeRate = _object getVariable ["dischargeRate", 1]; // units/sec
    private _unitsPerHour = _dischargeRate * 3600;
    
    private _estimatedHours = floor (_charge / _unitsPerHour);
    private _estimatedDays = floor (_estimatedHours / 24);
    private _remainingHours = _estimatedHours % 24;

    // Set color based on charge level
    if (_chargePercent > 80) then {
        _chargeColor = "<font color='#88FF88'>"; // Green (Optimal)
        _statusText = "STATUS: Stable Output";
    } else if (_chargePercent > 20) then {
        _chargeColor = "<font color='#FFFF88'>"; // Yellow (Normal)
        _statusText = "STATUS: Monitor Output";
    } else {
        _chargeColor = "<font color='#FF4444'>"; // Red (Critical)
        _statusText = "STATUS: POWER CORE CRITICAL";
    };

    private _message = format [
        "<t size='1.4'>%1 Power System Status</t><br/>" +
        "%2Charge: %3%</font><br/>" +
        "%4<br/>" +
        "Est. Life: %5 Days, %6 Hours<br/>" +
        "<t size='0.8' color='#AAAAAA'>Max Capacity: %7 Units</t>",
        MEC_PREFIX, // From mec_base_ddefines.hpp
        _chargeColor,
        _chargePercent,
        _statusText,
        _estimatedDays,
        _remainingHours,
        _maxCharge
    ];

    // Display the hint using core BIS function
    [_message, 4] call BIS_fnc_guiMessage;
};