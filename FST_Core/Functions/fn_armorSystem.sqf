/*
    Script: MYTAG_additionalArmorSystem
    Author: Your Name/AI Assistant
    Date: 2025-05-04
    Updated: 2025-05-04

    Description:
    Simulates additional, ablative armor based on a custom config property "FST_AdditionalArmor"
    found on a unit's equipped helmet and vest. This armor absorbs damage until depleted.
    When depleted, plays a sound and applies a broken visor visual effect locally.
    Also resets the additional armor and removes effects when the unit is fully healed (e.g., by Zeus).

    Initialization:
    - Call "MYTAG_fnc_initAdditionalArmor" on server and clients at mission start.
      Example (in init.sqf or CfgFunctions preInit): [] call MYTAG_fnc_initAdditionalArmor;
    - Ensure relevant helmets/vests have "FST_AdditionalArmor = <number>;" in their CfgWeapons entry.
    - Ensure ACE3 is NOT modifying damage handling in a way that conflicts (usually okay).
    - *** Define the sound "GlassBreak_Sound_Placeholder" in CfgSounds. ***
    - *** Define the PP Effect "MYTAG_BrokenVisorEffect" (see example below). ***

    Notes:
    - Replace "MYTAG" with your actual mod/mission tag.
    - Handles JIP players.
    - Visual/Audio effects are client-side. Damage/Heal logic is server-side.
*/

// --- Configuration ---
#define MYTAG_ARMOR_VAR_CURRENT "MYTAG_currentAddArmor" // Variable name for current armor HP
#define MYTAG_ARMOR_VAR_MAX "MYTAG_maxAddArmor"         // Variable name for max potential armor HP
#define MYTAG_ARMOR_BROKEN_VAR "MYTAG_addArmorBroken"   // Variable name to track if armor is broken (for effects)
#define MYTAG_MONITOR_INTERVAL 3                       // Seconds between equipment checks for players
#define MYTAG_BREAK_SOUND "GlassBreak_Sound_Placeholder" // <<<--- REPLACE THIS with CfgSounds classname!
#define MYTAG_VISOR_EFFECT "MYTAG_BrokenVisorEffect"     // <<<--- Needs definition (see below)

/* Example description.ext entry for the PP Effect:
class RscPostProcessTemplates
{
    class MYTAG_BrokenVisorEffect
    {
        type = "ChromAberration"; // Example effect type
        priority = 10; // Adjust as needed
        duration = 1e+011; // Effectively infinite until disabled
        parameters[] = {0.005, 0.005, true}; // Adjust values for desired intensity {offsetX, offsetY, randomDir}
    };
};
*/


// ====================================================================================
// SERVER-SIDE FUNCTIONS
// ====================================================================================

// --- Function: Handle Damage Event (Server Only) ---
MYTAG_fnc_handleAdditionalArmorDamage = {
    // Parameters passed by "HandleDamage" EH:
    params ["_unit", "_selectionName", "_damage", "_source", "_projectile", "_hitIndex", "_instigator", "_hitPoint", "_damageType", "_hitDirection"];

    // --- Initial Checks ---
    if !(_unit isKindOf "Man") exitWith {_damage}; // Only affect men
    if (!alive _unit) exitWith {_damage};           // Don't process for dead units
    if (_damage <= 0) exitWith {_damage};           // No damage to process

    // --- Get Current Armor State ---
    private _currentArmor = _unit getVariable [MYTAG_ARMOR_VAR_CURRENT, 0];

    // --- Apply Armor Absorption ---
    private _damageToReturn = _damage; // Default to original damage

    if (_currentArmor > 0) then {
        private _absorbedDamage = min [_damage, _currentArmor]; // Absorb up to current armor amount
        private _newArmor = _currentArmor - _damage; // Calculate remaining armor (can go below 0)

        // Update armor value on the unit (publicly)
        _unit setVariable [MYTAG_ARMOR_VAR_CURRENT, _newArmor max 0, true]; // Store new value, clamp at 0

        // Reduce the damage passed to the engine
        _damageToReturn = (_damage - _absorbedDamage) max 0; // Clamp damage reduction at 0

        diag_log format [
            "[MYTAG_ArmorSys SVR DMG] Unit %1: Armor %.1f -> %.1f. Absorbed %.2f, Passing %.2f damage.",
            _unit, _currentArmor, _newArmor max 0, _absorbedDamage, _damageToReturn
        ];

        // Check if the armor just broke on this hit
        if (_newArmor <= 0 && _currentArmor > 0) then { // Check _currentArmor > 0 ensures this only triggers once when breaking
            diag_log format ["[MYTAG_ArmorSys SVR DMG] Unit %1: Additional Armor Broken!", _unit];
            _unit setVariable [MYTAG_ARMOR_BROKEN_VAR, true, true]; // Mark armor as broken

            // If the unit is a player, trigger effects on their client
            if (!isNil {_unit getVariable "owner"}) then { // Check if player controlled
                 [_unit] remoteExecCall ["MYTAG_fnc_playArmorBreakEffect", _unit getVariable "owner"]; // Send to specific client
            };
        };
    };

    // Return the potentially modified damage value
    _damageToReturn;
};

// --- Function: Handle Heal Event (Server Only) ---
MYTAG_fnc_handleHealEH = {
    // Parameters passed by "HandleHeal" EH:
    // _unit, _healer, _instigator
    params ["_unit", "_healer", "_instigator"];

    // --- Initial Checks ---
    if !(_unit isKindOf "Man") exitWith {}; // Only affect men
    if (!alive _unit) exitWith {};           // Don't process for dead units

    // --- Check if Unit is Fully Healed ---
    // We check shortly after the event fires, as damage might not be zero *exactly* when the EH triggers
    [_unit] spawn {
        params ["_targetUnit"];
        sleep 0.1; // Short delay to allow engine damage state to update

        if (isNull _targetUnit || !alive _targetUnit) exitWith {}; // Target became invalid

        if (damage _targetUnit == 0) then { // Check if fully healed
            // --- Get Max Armor ---
            private _maxArmor = _targetUnit getVariable [MYTAG_ARMOR_VAR_MAX, 0];

            // --- Reset Armor State if Max Armor > 0 ---
            if (_maxArmor > 0) then {
                private _currentArmor = _targetUnit getVariable [MYTAG_ARMOR_VAR_CURRENT, 0];
                private _isBroken = _targetUnit getVariable [MYTAG_ARMOR_BROKEN_VAR, false];

                // Only reset if armor wasn't already full or state needs changing
                if (_currentArmor < _maxArmor || _isBroken) then {
                    diag_log format [
                        "[MYTAG_ArmorSys SVR HEAL] Unit %1 fully healed. Resetting additional armor to max (%2).",
                        _targetUnit, _maxArmor
                    ];
                    _targetUnit setVariable [MYTAG_ARMOR_VAR_CURRENT, _maxArmor, true]; // Reset current HP to max
                    _targetUnit setVariable [MYTAG_ARMOR_BROKEN_VAR, false, true];      // Mark as not broken
                };
            } else {
                 // Ensure broken state is true if they have no potential max armor
                 _targetUnit setVariable [MYTAG_ARMOR_BROKEN_VAR, true, true];
            }
        };
    };
};


// ====================================================================================
// CLIENT-SIDE FUNCTIONS
// ====================================================================================

// --- Function: Play Armor Break Effects (Client Only) ---
MYTAG_fnc_playArmorBreakEffect = {
    params ["_unit"]; // Unit whose armor broke is passed (though usually just 'player')
    if (!hasInterface || _unit != player) exitWith {}; // Ensure runs only for the correct player

    // Only play/apply if the armor is actually marked as broken
    if !(player getVariable [MYTAG_ARMOR_BROKEN_VAR, false]) exitWith {
        diag_log "[MYTAG_ArmorSys CLI] Play effect called, but armor not marked broken. Ignoring.";
    };

    diag_log "[MYTAG_ArmorSys CLI] Playing armor break effects.";

    // 1. Play Sound
    if (MYTAG_BREAK_SOUND != "GlassBreak_Sound_Placeholder") then {
        playSound MYTAG_BREAK_SOUND;
    } else {
        diag_log "[MYTAG_ArmorSys CLI] WARNING: GlassBreak_Sound_Placeholder not replaced!";
    };

    // 2. Apply Visual Effect (if not already active)
    if (isNil {missionNamespace getVariable "MYTAG_visorEffectHandle"} || {ppEffectEnabled (missionNamespace getVariable ["MYTAG_visorEffectHandle", -1]) == false}) then {
        missionNamespace setVariable ["MYTAG_visorEffectHandle", ppEffectCreate [MYTAG_VISOR_EFFECT, 1500]]; // Adjust priority if needed
        if !(isNil {missionNamespace getVariable "MYTAG_visorEffectHandle"}) then {
             (missionNamespace getVariable "MYTAG_visorEffectHandle") ppEffectEnable true;
             (missionNamespace getVariable "MYTAG_visorEffectHandle") ppEffectCommit 0; // Commit immediately
             diag_log "[MYTAG_ArmorSys CLI] Broken visor effect applied.";
        } else {
             diag_log "[MYTAG_ArmorSys CLI] ERROR: Failed to create visor PP effect.";
        }
    };
};

// --- Function: Monitor Equipment and Effects (Client Only) ---
MYTAG_fnc_monitorEquipmentLoop = {
    if (!hasInterface) exitWith {}; // Run only on clients with interface

    private _currentHelmet = "";
    private _currentVest = "";
    private _maxArmor = 0;
    private _effectActive = ppEffectEnabled (missionNamespace getVariable ["MYTAG_visorEffectHandle", -1]); // Check initial state

    while {alive player && !isNull player} do { // Loop while player is valid
        // --- Check Equipment ---
        private _newHelmet = headgear player;
        private _newVest = vest player;

        // --- Recalculate Max Armor if Equipment Changed ---
        if (_newHelmet != _currentHelmet || _newVest != _currentVest) then {
            _currentHelmet = _newHelmet;
            _currentVest = _newVest;

            private _helmetArmor = 0;
            private _vestArmor = 0;

            if (_currentHelmet != "") then {
                _helmetArmor = getNumber (configFile >> "CfgWeapons" >> _currentHelmet >> "FST_AdditionalArmor");
            };
            if (_currentVest != "") then {
                _vestArmor = getNumber (configFile >> "CfgWeapons" >> _currentVest >> "FST_AdditionalArmor");
            };

            _maxArmor = _helmetArmor + _vestArmor;

            // Inform the server about the new max armor potential and reset current armor
            // Server now primarily handles reset on heal, but client updates max potential
            player setVariable [MYTAG_ARMOR_VAR_MAX, _maxArmor, true];

            // If the new gear offers armor, assume it's not broken initially.
            // If it offers no armor, mark as broken.
            // Current armor value is mainly managed by server now (damage/heal).
            if (_maxArmor > 0) then {
                 // Check if armor was previously broken, if so, reset it now that capable gear is equipped
                 if (player getVariable [MYTAG_ARMOR_BROKEN_VAR, false]) then {
                     player setVariable [MYTAG_ARMOR_BROKEN_VAR, false, true];
                     // Optionally reset current armor to max here too, or let server handle via heal/damage
                     player setVariable [MYTAG_ARMOR_VAR_CURRENT, _maxArmor, true];
                     diag_log format ["[MYTAG_ArmorSys CLI] Equipment changed. New Max Armor: %1. Resetting broken state.", _maxArmor];
                 } else {
                      diag_log format ["[MYTAG_ArmorSys CLI] Equipment changed. New Max Armor: %1.", _maxArmor];
                 }
            } else {
                 // If new gear has no armor, ensure state reflects that
                 player setVariable [MYTAG_ARMOR_VAR_CURRENT, 0, true];
                 player setVariable [MYTAG_ARMOR_BROKEN_VAR, true, true]; // Consider it broken if no potential armor
                 diag_log "[MYTAG_ArmorSys CLI] Equipment changed. New gear provides no additional armor.";
            };
        };

        // --- Manage Visual Effect based on broadcasted state ---
        private _isArmorBroken = player getVariable [MYTAG_ARMOR_BROKEN_VAR, true]; // Default to broken if var missing

        // If armor is broken AND effect is not active, activate it
        if (_isArmorBroken && !_effectActive) then {
             if (isNil {missionNamespace getVariable "MYTAG_visorEffectHandle"} || {ppEffectEnabled (missionNamespace getVariable ["MYTAG_visorEffectHandle", -1]) == false}) then {
                missionNamespace setVariable ["MYTAG_visorEffectHandle", ppEffectCreate [MYTAG_VISOR_EFFECT, 1500]];
                 if !(isNil {missionNamespace getVariable "MYTAG_visorEffectHandle"}) then {
                     (missionNamespace getVariable "MYTAG_visorEffectHandle") ppEffectEnable true;
                     (missionNamespace getVariable "MYTAG_visorEffectHandle") ppEffectCommit 0;
                     _effectActive = true;
                     diag_log "[MYTAG_ArmorSys CLI] Visor effect enabled (monitor loop).";
                 } else {
                      diag_log "[MYTAG_ArmorSys CLI] ERROR: Failed to create visor PP effect on monitor loop.";
                 }
             } else {
                 // Effect handle might exist but is somehow disabled externally? Re-enable.
                 (missionNamespace getVariable "MYTAG_visorEffectHandle") ppEffectEnable true;
                 (missionNamespace getVariable "MYTAG_visorEffectHandle") ppEffectCommit 0;
                 _effectActive = true;
                 diag_log "[MYTAG_ArmorSys CLI] Visor effect re-enabled (monitor loop).";
             };
        };

        // If armor is NOT broken AND effect IS active, disable it
        if (!_isArmorBroken && _effectActive) then {
            if (!isNil {missionNamespace getVariable "MYTAG_visorEffectHandle"}) then {
                (missionNamespace getVariable "MYTAG_visorEffectHandle") ppEffectEnable false;
                (missionNamespace getVariable "MYTAG_visorEffectHandle") ppEffectCommit 1; // Commit over 1 second (fade out)
                 // ppEffectDestroy (missionNamespace getVariable "MYTAG_visorEffectHandle"); // Optional: Destroy instead of disable
                 // missionNamespace setVariable ["MYTAG_visorEffectHandle", nil];
            };
            _effectActive = false;
            diag_log "[MYTAG_ArmorSys CLI] Visor effect disabled.";
        };

        sleep MYTAG_MONITOR_INTERVAL;
    };

    // Cleanup PP effect if player becomes invalid while effect is active
    if (_effectActive && !isNil {missionNamespace getVariable "MYTAG_visorEffectHandle"}) then {
         (missionNamespace getVariable "MYTAG_visorEffectHandle") ppEffectEnable false;
         ppEffectDestroy (missionNamespace getVariable "MYTAG_visorEffectHandle");
         missionNamespace setVariable ["MYTAG_visorEffectHandle", nil];
         diag_log "[MYTAG_ArmorSys CLI] Player invalid, cleaning up visor effect.";
    };
};


// ====================================================================================
// INITIALIZATION FUNCTION (Run on Server and Clients)
// ====================================================================================
MYTAG_fnc_initAdditionalArmor = {
    // --- Server-Side Initialization ---
    if (isServer) then {
        // Damage Handler
        if (isNil "MYTAG_addArmorDamageEH_ID") then {
            MYTAG_addArmorDamageEH_ID = addMissionEventHandler ["HandleDamage", MYTAG_fnc_handleAdditionalArmorDamage];
            diag_log "[MYTAG_ArmorSys SVR] HandleDamage Event Handler added.";
        } else {
            diag_log "[MYTAG_ArmorSys SVR] HandleDamage Event Handler already added.";
        };

        // Heal Handler (New)
        if (isNil "MYTAG_addArmorHealEH_ID") then {
            MYTAG_addArmorHealEH_ID = addMissionEventHandler ["HandleHeal", MYTAG_fnc_handleHealEH];
            diag_log "[MYTAG_ArmorSys SVR] HandleHeal Event Handler added.";
        } else {
            diag_log "[MYTAG_ArmorSys SVR] HandleHeal Event Handler already added.";
        };

        // Optional: Cleanup EHs on mission end
        /*
        addMissionEventHandler ["Ended", {
            if (!isNil "MYTAG_addArmorDamageEH_ID") then {
                removeMissionEventHandler ["HandleDamage", MYTAG_addArmorDamageEH_ID];
                MYTAG_addArmorDamageEH_ID = nil;
                diag_log "[MYTAG_ArmorSys SVR] HandleDamage Event Handler removed on mission end.";
            };
            if (!isNil "MYTAG_addArmorHealEH_ID") then {
                removeMissionEventHandler ["HandleHeal", MYTAG_addArmorHealEH_ID];
                MYTAG_addArmorHealEH_ID = nil;
                diag_log "[MYTAG_ArmorSys SVR] HandleHeal Event Handler removed on mission end.";
            };
        }];
        */
    };

    // --- Client-Side Initialization ---
    if (hasInterface) then {
        // Wait until player object exists and is assigned locally
        waitUntil {!isNull player && player == player};

        // Spawn the equipment monitoring loop for the player
        [] spawn MYTAG_fnc_monitorEquipmentLoop;
        diag_log "[MYTAG_ArmorSys CLI] Player equipment monitor loop spawned.";
    };
};

// --- Make functions available (if not using CfgFunctions) ---
/*
missionNamespace setVariable ["MYTAG_fnc_handleAdditionalArmorDamage", MYTAG_fnc_handleAdditionalArmorDamage];
missionNamespace setVariable ["MYTAG_fnc_handleHealEH", MYTAG_fnc_handleHealEH]; // Add new EH function
missionNamespace setVariable ["MYTAG_fnc_playArmorBreakEffect", MYTAG_fnc_playArmorBreakEffect];
missionNamespace setVariable ["MYTAG_fnc_monitorEquipmentLoop", MYTAG_fnc_monitorEquipmentLoop];
missionNamespace setVariable ["MYTAG_fnc_initAdditionalArmor", MYTAG_fnc_initAdditionalArmor];
*/
