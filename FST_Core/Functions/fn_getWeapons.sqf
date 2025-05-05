/*
    Function: FST_fnc_getUnitWeapons
    Author: Maldova
    Date: 2025-05-04

    Description:
    Retrieves a list of all weapon classnames currently possessed by a given unit.
    This includes primary weapon, handgun, launcher, and potentially items
    like binoculars or rangefinders if they occupy weapon slots.

    Parameter(s):
    _this select 0: OBJECT - The unit whose weapons are to be retrieved.

    Returns:
    ARRAY of STRINGS - An array containing the classnames of the unit's weapons.
                       Returns an empty array ([]) if the unit is null or has no weapons.

    Example Usage:
    private _playerWeapons = [player] call FST_fnc_getUnitWeapons;
    hint format ["Player Weapons: %1", _playerWeapons];

    // To call from within another script where _soldier is defined:
    private _soldierWeapons = [_soldier] call FST_fnc_getUnitWeapons;

    Notes:
    - This function uses the 'weapons' command which returns all items considered
      weapons by the engine, potentially including non-firearm items.
      Filtering might be necessary depending on the specific use case.
*/

// Define the function using params for clarity and safety
params ["_unit"];

// --- Input Validation ---
// Check if the passed unit object is valid
if (isNull _unit) exitWith 
{
    diag_log "[FST_fnc_getUnitWeapons] ERROR: Input unit is null.";
    []; // Return empty array
};

// --- Get Weapons ---
// Use the 'weapons' command to get an array of weapon classnames
private _weaponList = weapons _unit;

// --- Return Value ---
// Return the array of weapon classnames
_weaponList;
