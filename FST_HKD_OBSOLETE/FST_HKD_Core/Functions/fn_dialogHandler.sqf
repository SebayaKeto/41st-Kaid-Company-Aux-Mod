/*
    Author: Maldova Engineering Corp.
    Function: HKD_fnc_dialogHandler
    Description: UI Logic for the Drop Interface
*/

params ["_mode"];

switch (_mode) do {
    case "INIT": {
        createDialog "HKD_Drop_Dialog";

        // Acquire dialog controls safely
        private _display = findDisplay 9876;
        private _ctrlLeft = if (!isNull _display) then {_display displayCtrl 1500} else {nil};
        private _ctrlRight = if (!isNull _display) then {_display displayCtrl 1501} else {nil};

        // Populate left list from CBA settings (mission maker configurable)
        private _cba_droppable = missionNamespace getVariable ["cba_settings_fst_hkd_droppableobjects", "FST_HKD_Blocker_Blank,FST_HKD_Blocker_CIS,FST_HKD_Blocker_HKD"];
        private _classes = _cba_droppable splitString ",";

        // Filter classes by existence in config and collect invalid entries for a runtime hint
        private _validClasses = [];
        private _invalidClasses = [];
        {
            if ((configFile >> "CfgVehicles" >> _x) isNotEqualTo "") then { _validClasses pushBack _x; } else { _invalidClasses pushBack _x; };
        } forEach _classes;

        if ((count _validClasses) == 0) then {
            hint "HKD Drop: No valid droppable classes found in settings — please check mission settings.";
        } else {
            if (!isNull _ctrlLeft) then {
                {
                    private _class = _x;
                    private _name = "";
                    if ((configFile >> "CfgVehicles" >> _class) isNotEqualTo "") then {
                        _name = getText (configFile >> "CfgVehicles" >> _class >> "displayName");
                    };
                    if (_name isEqualTo "") then { _name = _class; };

                    private _index = _ctrlLeft lbAdd _name;
                    _ctrlLeft lbSetData [_index, _class];
                } forEach _validClasses;
            } else {
                // As a fallback, attempt to use lbAdd by idc (older syntax)
                {
                    private _class = _x;
                    private _name = "";
                    if ((configFile >> "CfgVehicles" >> _class) isNotEqualTo "") then {
                        _name = getText (configFile >> "CfgVehicles" >> _class >> "displayName");
                    };
                    if (_name isEqualTo "") then { _name = _class; };

                    private _index = lbAdd [1500, _name];
                    lbSetData [1500, _index, _class];
                } forEach _validClasses;
            };
        };

        if ((count _invalidClasses) > 0) then {
            hint format ["HKD Drop: %1 droppable class(es) are missing from config and were ignored: %2", count _invalidClasses, _invalidClasses];
        };

        // Pre-select CBA default object (add to the Selected list on the right)
        private _defaultClass = missionNamespace getVariable ["cba_settings_fst_hkd_defaultdropobject", "FST_HKD_Blocker_Blank"];
        if (!(_defaultClass in _validClasses)) then {
            if ((count _validClasses) > 0) then {
                hint format ["HKD Drop: Default '%1' not found or invalid. Using '%2' instead.", _defaultClass, _validClasses select 0];
                _defaultClass = _validClasses select 0;
            } else {
                // nothing valid to show
                exitWith {};
            };
        };

        if (!isNull _ctrlLeft && !isNull _ctrlRight) then {
            private _leftSize = _ctrlLeft lbSize;
            for "_i" from 0 to (_leftSize - 1) do {
                if ((_ctrlLeft lbData _i) isEqualTo _defaultClass) then {
                    _ctrlLeft lbSetCurSel _i;
                    private _txt = _ctrlLeft lbText _i;
                    private _newIdx = _ctrlRight lbAdd _txt;
                    _ctrlRight lbSetData [_newIdx, _defaultClass];
                    exitWith {};
                };
            };
        } else {
            // fallback using idc-based APIs
            private _leftSize = lbSize 1500;
            for "_i" from 0 to (_leftSize - 1) do {
                if ((lbData [1500, _i]) isEqualTo _defaultClass) then {
                    lbSetCurSel [1500, _i];
                    private _txt = lbText [1500, _i];
                    private _newIdx = lbAdd [1501, _txt];
                    lbSetData [1501, _newIdx, _defaultClass];
                    exitWith {};
                };
            };
        };
    };
    
    case "ADD": {
        private _display = findDisplay 9876;
        private _ctrlLeft = if (!isNull _display) then {_display displayCtrl 1500} else {nil};
        private _ctrlRight = if (!isNull _display) then {_display displayCtrl 1501} else {nil};

        if (!isNull _ctrlLeft && !isNull _ctrlRight) then {
            private _idx = _ctrlLeft lbCurSel;
            if (_idx == -1) exitWith {};
            private _text = _ctrlLeft lbText _idx;
            private _data = _ctrlLeft lbData _idx;
            private _newIdx = _ctrlRight lbAdd _text;
            _ctrlRight lbSetData [_newIdx, _data];
        } else {
            private _idx = lbCurSel 1500;
            if (_idx == -1) exitWith {};
            private _text = lbText [1500, _idx];
            private _data = lbData [1500, _idx];
            private _newIdx = lbAdd [1501, _text];
            lbSetData [1501, _newIdx, _data];
        };
    };
    
    case "DROP": {
        // 1. Gather all selected classes
        private _display = findDisplay 9876;
        private _ctrlRight = if (!isNull _display) then {_display displayCtrl 1501} else {nil};

        private _size = if (!isNull _ctrlRight) then {_ctrlRight lbSize} else { lbSize 1501 };
        if (_size == 0) exitWith { hint "No objects selected!"; };

        private _selectedClasses = [];
        for "_i" from 0 to (_size - 1) do {
            private _val = if (!isNull _ctrlRight) then {_ctrlRight lbData _i} else { lbData [1501, _i] };
            _selectedClasses pushBack _val;
        };
        
        // 2. Get Module Position (Passed via variable namespace since dialog separates logic)
        private _logic = missionNamespace getVariable ["HKD_Current_Drop_Module", objNull];
        
        // 3. Execute the Radius Drop Logic with the Array
        // We pass the ARRAY of classes instead of a single string
        [_logic, _selectedClasses] call HKD_fnc_moduleHKDDropRadius_Execution;
        
        closeDialog 1;
    };
};