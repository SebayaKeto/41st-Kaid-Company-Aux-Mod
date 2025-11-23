_logic = param [0,objNull,[objNull]];
_activated = param [2,true,[true]];

if (_activated) then {
    // Save logic object to namespace so the dialog can find it
    missionNamespace setVariable ["HKD_Current_Drop_Module", _logic];
    
    // Open the UI
    ["INIT"] call HKD_fnc_dialogHandler;
};