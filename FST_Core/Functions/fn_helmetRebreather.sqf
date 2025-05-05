/*
    Function: FST_fnc_headgearRebreatherLoop
    Author: Your Name/AI Assistant
    Date: 2025-05-04
    Updated: 2025-05-04

    Description:
    Monitors the player locally. If the player is underwater (below sea level)
    and wearing a specific headgear defined with "FST_isRebreather = 1;" in its config,
    it simulates a rebreather effect:
    - Replenishes oxygen every 2 seconds.
    - Plays a specified sound every 2 seconds.
    - Disables the default underwater visual/audio effects.
    When the player surfaces or removes the specific headgear, the effects are restored.

    Parameter(s):
    None - Designed to be spawned locally for the player.

    Returns:
    Nothing

    Example Usage (in initPlayerLocal.sqf):
    if (hasInterface) then {
        [] spawn FST_fnc_headgearRebreatherLoop;
    };

    Notes:
    - *** IMPORTANT: Replace "Rebreather_Sound_Placeholder" with the actual classname
         of the sound you want to play (defined in CfgSounds). ***
    - Requires the headgear item in CfgWeapons to have a property: FST_isRebreather = 1;
    - Uses 'enableEnvironment [false, true]' to disable underwater effects.
    - Checks altitude and headgear status every 2 seconds.
    - Requires the function to be defined in CfgFunctions or compiled first.
*/

// Ensure this runs only where there's an interface (player's machine)
if (!hasInterface) exitWith {};

// --- Configuration ---
private _rebreatherSound = "Rebreather_Sound_Placeholder"; // <<<--- REPLACE THIS with your CfgSounds classname!
private _checkInterval = 2; // Seconds between checks/oxygen refill/sound play
private _activationDepth = -0.5; // Meters below sea level to activate (slight buffer)

// --- State Variable ---
private _rebreatherActive = false; // Tracks if the rebreather effect is currently active

// --- Main Loop ---
while {true} do {
    // Exit loop if player object becomes invalid (e.g., disconnect, scenario end)
    if (isNull player || !alive player) exitWith {
        // Ensure environment effects are re-enabled on exit if they were disabled
        if (_rebreatherActive) then {
            enableEnvironment [true, true];
            diag_log "[FST_fnc_headgearRebreatherLoop] Player invalid/dead, re-enabling environment and exiting.";
        };
    };

    // --- Get Current Status ---
    private _altitude = (getPosASL player) select 2; // Z-coordinate (Above Sea Level)
    private _headgear = hmd player; // Get current headgear classname

    // --- Determine Required State ---
    // Rebreather should be active if player is below activation depth AND wearing a helmet
    // that has "FST_isRebreather = 1;" defined in its CfgWeapons entry.
    private _shouldBeActive = (_altitude < _activationDepth) && (_headgear != "" && { getNumber (configFile >> "CfgWeapons" >> _headgear >> "FST_isRebreather") == 1 });

    // --- Handle State Transitions ---

    // Check if activating (Was inactive, should now be active)
    if (_shouldBeActive && !_rebreatherActive) then {
        _rebreatherActive = true;
        enableEnvironment [false, true]; // Disable underwater effects
        diag_log format ["[FST_fnc_headgearRebreatherLoop] Rebreather activated for headgear: %1", _headgear];
    };

    // Check if deactivating (Was active, should now be inactive)
    if (!_shouldBeActive && _rebreatherActive) then {
        _rebreatherActive = false;
        enableEnvironment [true, true]; // Re-enable underwater effects
        diag_log "[FST_fnc_headgearRebreatherLoop] Rebreather deactivated.";
    };

    // --- Apply Active Effects ---
    // If the rebreather is currently active, apply its effects
    if (_rebreatherActive) then {
        // Set oxygen to full (1 = 100%)
        player setOxygenRemaining 1;

        // Play the rebreather sound locally
        // Ensure the sound classname is valid in CfgSounds
        if (_rebreatherSound != "Rebreather_Sound_Placeholder") then {
            playSound _rebreatherSound;
        } else {
            // Optional: Warning if placeholder wasn't replaced
            // hintSilent "Rebreather sound placeholder not set!";
        };
    };

    // --- Wait ---
    sleep _checkInterval;
};

diag_log "[FST_fnc_headgearRebreatherLoop] Loop terminated.";
