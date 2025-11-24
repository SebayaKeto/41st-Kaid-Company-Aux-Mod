params ["_logic","_units","_activated"];

if (_activated) then {
    // Ensure module has sensible defaults from CBA settings so the dialog shows expected values
    private _cba_defaultClass = missionNamespace getVariable ["cba_settings_fst_hkd_defaultdropobject", "FST_HKD_Blocker_Blank"];
    private _cba_defaultAlt = missionNamespace getVariable ["cba_settings_fst_hkd_defaultdropaltitude", 1000];
    private _cba_defaultRadius = missionNamespace getVariable ["cba_settings_fst_hkd_defaultdropradius", 100];
    private _cba_defaultCount = missionNamespace getVariable ["cba_settings_fst_hkd_defaultdropcount", 10];

    // Only set if module attributes are not already set by the mission maker
    if ((_logic getVariable ["Object_Class", ""]) isEqualTo "") then { _logic setVariable ["Object_Class", _cba_defaultClass, true]; };
    if ((_logic getVariable ["Drop_Altitude", -1]) == -1) then { _logic setVariable ["Drop_Altitude", _cba_defaultAlt, true]; };
    if ((_logic getVariable ["Drop_Radius", -1]) == -1) then { _logic setVariable ["Drop_Radius", _cba_defaultRadius, true]; };
    if ((_logic getVariable ["Drop_Count", -1]) == -1) then { _logic setVariable ["Drop_Count", _cba_defaultCount, true]; };

    // Save logic object to namespace so the dialog can find it (broadcast to clients)
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

        // Store activator for later reference and open the shared UI on that player's client
        missionNamespace setVariable ['HKD_Current_Drop_Module_Activator', _activator, true];
        ["INIT"] remoteExecCall ["HKD_fnc_dialogHandler", _activator];
};