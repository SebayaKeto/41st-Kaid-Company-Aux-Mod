/*
    Function: FST_fnc_getUnitHelmet
    Author: Maldova
    Date: 2025-05-04

    Description:
    Retrieves the classname of the helmet currently worn by a given unit.

    Parameter(s):
    _this select 0: OBJECT - The unit whose helmet is to be retrieved.

    Returns:
    ARRAY of STRING - An array containing the classname of the unit's helmet as a single element.
                      Returns an empty array ([]) if the unit is null or is not wearing a helmet.

    Example Usage:
    private _playerHelmetArray = [player] call FST_fnc_getUnitHelmet;
    if (count _playerHelmetArray > 0) then {
        hint format ["Player Helmet: %1", _playerHelmetArray select 0];
    } else {
        hint "Player is not wearing a helmet.";
    };

    // To call from within another script where _soldier is defined:
    private _soldierHelmetArray = [_soldier] call FST_fnc_getUnitHelmet;

    Notes:
    - Uses the 'hmd' command (Head Mounted Display), which returns the classname of worn headgear (helmets, hats, etc.).
*/

// Define the function using params for clarity and safety
params ["_unit"];

// --- Input Validation ---
// Check if the passed unit object is valid
if (isNull _unit) exitWith 
{
    diag_log "[FST_fnc_getUnitHelmet] ERROR: Input unit is null.";
    []; // Return empty array
};

// --- Get Helmet ---
// Use the 'hmd' command to get the classname of the worn headgear
private _helmetClass = hmd _unit;

// --- Prepare Return Value ---
private _helmetArray = [];

// Check if the returned classname is not an empty string (meaning a helmet is worn)
if (_helmetClass != "") then {
    // If a helmet exists, put its classname into the result array
    _helmetArray = [_helmetClass];
};

// --- Return Value ---
// Return the array (either empty or containing the helmet classname)
_helmetArray;
