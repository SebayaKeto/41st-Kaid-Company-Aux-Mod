if (isNil "FST_CurrentKitCategory") then { FST_CurrentKitCategory = "regular"; };

WBK_fnc_populateKitList = {
    private _display = findDisplay 2000;
    private _listbox = _display displayCtrl 1732;
    lbClear _listbox;

    // --- Update Switch button icon ---
    private _iconButton = _display displayCtrl 1603;
    if (!isNull _iconButton) then {
        switch (FST_CurrentKitCategory) do {
            case "regular":   { _iconButton ctrlSetText "\41st_KitMenu\data\P2_base_helmet.paa";   _iconButton ctrlShow true; };
            case "airborne":  { _iconButton ctrlSetText "\41st_KitMenu\data\Airborne_base_helmet.paa";  _iconButton ctrlShow true; };
            case "pilot":     { _iconButton ctrlSetText "\41st_KitMenu\data\Pilot_base_helmet.paa";     _iconButton ctrlShow true; };
            default           { _iconButton ctrlShow false; };
        };
    };

    // Update category button text if you want (optional)
    // private _button = _display displayCtrl 1602;
    // if (!isNull _button) then {
    //     _button ctrlSetText (["Regular", "Airborne", "Pilot"] select (_order find FST_CurrentKitCategory));
    // };

    private _kits = switch (FST_CurrentKitCategory) do {
        case "airborne": { FST_AirborneKits };
        case "pilot":    { FST_PilotKits };
        default        { FST_RegularKits };
    };

    // Sort kits alphabetically
    _kits = +_kits;
    private _decorated = [];
    { _decorated pushBack [toLower (_x select 0), _forEachIndex]; } forEach _kits;
    _decorated sort true;
    private _sortedKits = [];
    { _sortedKits pushBack (_kits select (_x select 1)); } forEach _decorated;
    _kits = _sortedKits;

    {
        private _VAR_nameOfLoadout     = _x select 0;
        private _VAR_loadout           = _x select 1;
        private _VAR_AditionalGear     = _x select 2;
        private _VAR_CondtitionToMeet  = _x select 3;
        private _VAR_FunctionToSpawn   = _x select 4;
        private _cond   = _VAR_CondtitionToMeet;
        private _code   = compile _cond;
        private _outPut = call _code;
        if (_outPut isEqualTo true) then {
            _index = _listbox lbAdd _VAR_nameOfLoadout;
            _listbox lbSetData [_index, format ["[%1, '%2', %3, %4, '%5']", _VAR_loadout, _VAR_nameOfLoadout, _VAR_AditionalGear, _VAR_FunctionToSpawn, FST_CurrentKitCategory]];
            _listbox lbSetColor [_index, [1, 1, 1, 1]];
        } else {
            _index = _listbox lbAdd _VAR_nameOfLoadout;
            _listbox lbSetData [_index, format ["[%1, '%2', %3, %4, '%5']", _VAR_loadout, "CANTTAKEKIT", _VAR_AditionalGear, _VAR_FunctionToSpawn, FST_CurrentKitCategory]];
            _listbox lbSetColor [_index, [0.35, 0.35, 0.35, 1]];
        };
    } forEach _kits;
};

FST_ToggleKitCategory = {
    playSoundUI [selectRandom ["41st_KitMenu\sounds\select_helmet_1.ogg","41st_KitMenu\sounds\select_helmet_2.ogg"], 0.85, 1];
    private _order = ["regular", "airborne", "pilot"];
    private _idx = _order find FST_CurrentKitCategory;
    FST_CurrentKitCategory = _order select (((_idx + 1) mod count _order));
    call WBK_fnc_populateKitList;
};

call WBK_fnc_populateKitList;
