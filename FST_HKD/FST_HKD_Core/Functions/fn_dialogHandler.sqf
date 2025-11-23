/*
    Author: Maldova Engineering Corp.
    Function: HKD_fnc_dialogHandler
    Description: UI Logic for the Drop Interface
*/

params ["_mode"];

switch (_mode) do {
    case "INIT": {
        createDialog "HKD_Drop_Dialog";
        
        // Search Config for drop-able objects
        private _configs = "getNumber (_x >> 'HKD_CanBeGravDropped') == 1" configClasses (configFile >> "CfgVehicles");
        
        {
            private _class = configName _x;
            private _name = getText (_x >> "displayName");
            
            private _index = lbAdd [1500, _name];
            lbSetData [1500, _index, _class];
        } forEach _configs;
    };
    
    case "ADD": {
        private _idx = lbCurSel 1500;
        if (_idx == -1) exitWith {};
        
        private _text = lbText [1500, _idx];
        private _data = lbData [1500, _idx];
        
        // Add to 'Selected' list (Right side)
        private _newIdx = lbAdd [1501, _text];
        lbSetData [1501, _newIdx, _data];
    };
    
    case "DROP": {
        // 1. Gather all selected classes
        private _size = lbSize 1501;
        if (_size == 0) exitWith { hint "No objects selected!"; };
        
        private _selectedClasses = [];
        for "_i" from 0 to (_size - 1) do {
            _selectedClasses pushBack (lbData [1501, _i]);
        };
        
        // 2. Get Module Position (Passed via variable namespace since dialog separates logic)
        private _logic = missionNamespace getVariable ["HKD_Current_Drop_Module", objNull];
        
        // 3. Execute the Radius Drop Logic with the Array
        // We pass the ARRAY of classes instead of a single string
        [_logic, _selectedClasses] call HKD_fnc_moduleHKDDropRadius_Execution;
        
        closeDialog 1;
    };
};