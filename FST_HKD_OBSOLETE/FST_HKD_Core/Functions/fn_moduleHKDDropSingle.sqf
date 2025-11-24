/*
    Author: Maldova Engineering Corp.
    Function: HKD_fnc_moduleHKDDropSingle
    Description: Zeus Module execution for single object drop.
*/

params ["_logic","_units","_activated"];

if (_activated) then {
    // For the Single module, open the same dialog so the user can confirm/adjust parameters.
    // We set sensible defaults and set Drop_Count to 1 so the radius executor will spawn a single object.
    private _cba_defaultClass = missionNamespace getVariable ["cba_settings_fst_hkd_defaultdropobject", "FST_HKD_Blocker_Blank"];
    private _cba_defaultAlt = missionNamespace getVariable ["cba_settings_fst_hkd_defaultdropaltitude", 1000];

    if ((_logic getVariable ["Object_Class", ""]) isEqualTo "") then { _logic setVariable ["Object_Class", _cba_defaultClass, true]; };
    if ((_logic getVariable ["Drop_Altitude", -1]) == -1) then { _logic setVariable ["Drop_Altitude", _cba_defaultAlt, true]; };
    // Force single spawn
    _logic setVariable ["Drop_Count", 1, true];

    // Broadcast module reference for dialog and cancel handling
    missionNamespace setVariable ["HKD_Current_Drop_Module", _logic, true];

    // Determine activating player: prefer first player in _units, fall back to local 'player'
    private _activator = player;
    if (isArray _units && (count _units > 0)) then {
        {
            if (isPlayer _x) then { _activator = _x; exitWith {}; };
            private _owner = owner _x;
            if (!isNull _owner && isPlayer _owner) then { _activator = _owner; exitWith {}; };
        } forEach _units;
    };

    // Broadcast activator and open the shared UI on that player's client
    missionNamespace setVariable ['HKD_Current_Drop_Module_Activator', _activator, true];
    ["INIT"] remoteExecCall ["HKD_fnc_dialogHandler", _activator];
};