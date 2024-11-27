/*
 * Author: 3AS, Edited DartRuffian
 * Creates mount/dismount actions for an AT-RT object.
 *
 * Arguments:
 * atrt: Object - The AT-RT
 *
 * Return Value:
 * None
 *
 * Example:
 * init = "(_this select 0) call FST_fnc_initATRT";
 */


#define ATRT_BASE_HEALTH 50
params ["_atrt"];
if (isNull _atrt) exitWith {};

//_atrt setAnimSpeedCoef 1.5; // Used to increase movement speed //Might be better to set the Speed in the ATRT_Base Config class instead of this. ~Jek
_atrt disableAI "RADIOPROTOCOL"; // Stops ai from talking/sending messages

_atrt addEventHandler
[
    "HandleDamage",
    {
        params ["_atrt", "", "_damage", "", "", "", "", ""];
        private ["_atrtHealth"];

        _atrtHealth = _atrt getVariable ["FST_ATRT_Health", ATRT_BASE_HEALTH]; //Sets Variable to ATRT_BASE_HEALTH if Variable not Set
        _atrtHealth = _atrtHealth - _damage;
        _atrt setVariable ["FST_ATRT_Health", _atrtHealth, true];

		//Kill ATRT if health is 0 or less.
        if (_atrtHealth <= 0) then
        {
            _atrt call FST_fnc_spawnATRTSmoke;
            _atrt call FST_fnc_dismountATRT;
            _atrt setDamage 1;

            _atrt removeEventHandler [_thisEvent, _thisEventHandler];
        };

        0;
    }
];

_atrt addEventHandler
[
    "Deleted",
    {
        // Clears up particles that are spawned by BNAKC_fnc_spawnATRTSmoke before the object is deleted
        params ["_entity"];
        private _allEffects = _entity getVariable ["FST_ATRT_effects", []];
        { deleteVehicle _x; } forEach _allEffects;
    }
];

_atrt addAction
[
    "Drive",
    {
        //       _target, _caller
        params ["_atrt", "_rider", "", ""];

        _rider = _atrt getVariable ["FST_ATRT_rider", _rider]; //Sets Variable to _rider if Variable not set
        [_rider, _atrt] call FST_fnc_mountATRT;

        // Check if the player should be able to ride
        waitUntil
        {
            sleep 2;
            private _expression =
            (
                // Rider Checks
                !alive _rider or
                lifeState _rider == "INCAPACITATED" or
                _rider getVariable ["ACE_isUnconscious", false]
            );
            // See https://community.bistudio.com/wiki/waitUntil#Problems
            !isNil "_expression" and { _expression };
        };

        _atrt call FST_fnc_dismountATRT;
    },
    [],
    1.5,
    true,
    true,
    "",
    "_this != _originalTarget and alive _target", // Prevents rider from seeing mount action,
    4,                                            // and from players getting stuck on dead units
    false,
    "",
    ""
];

_atrt addAction
[
    "Dismount",
    {
        //       _target,  _caller
        params ["", "_atrt", "", ""];
        _atrt call FST_fnc_dismountATRT;
    },
    nil,
    1.5,
    false,
    true,
    "",
    "_this == _originalTarget", // Prevent multiple addActions
    2,
    false,
    "",
    ""
];
