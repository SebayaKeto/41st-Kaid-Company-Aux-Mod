FST_KitMenuUpdateKits = compile preprocessFileLineNumbers "41st_KitMenu\41st_Kit_System.sqf"; 
if (isNil "FST_RegularKits") then { FST_RegularKits = []; };
if (isNil "FST_AirborneKits") then { FST_AirborneKits = []; };
if (isNil "FST_RangerKits") then { FST_RangerKits = []; };
Wbk_equip_load = {
_obj = _this;
if ((isNil {_obj getVariable "WBK_kitMenuPresent"})) then { 
	_obj setVariable ["WBK_kitMenuPresent",0];
	_obj addAction ["<t color='#0093FF' size='1.45' font = 'PuristaSemibold'><img size='2' image='a3\ui_f\data\GUI\Cfg\Hints\Gear_ca.paa'/> Open kit menu</t>", {
		_obj = _this select 0;
		WBK_GlobalKitBoxRn = _obj;
		[] exec "\41st_KitMenu\WBK_Kit_Camera.sqs";
		if (getText (configfile >> 'CfgVehicles' >> typeOf player >> 'moves') == 'CfgMovesMaleSdr' || getText (configfile >> 'CfgVehicles' >> typeOf player >> 'moves') == 'CfgMovesMaleSevenFoot' || getText (configfile >> 'CfgVehicles' >> typeOf player >> 'moves') == 'CfgMovesMaleSpaceMarine') then {
			player switchMove selectRandom ["Acts_AidlPercMstpSloWWrflDnon_warmup_1","Acts_AidlPercMstpSloWWrflDnon_warmup_2","Acts_AidlPercMstpSloWWrflDnon_warmup_3","Acts_AidlPercMstpSloWWrflDnon_warmup_4","Acts_AidlPercMstpSloWWrflDnon_warmup_5"];
		};
		_dirToObj = [player, _obj] call BIS_fnc_dirTo;
		_actDir = _dirToObj - 180;
		player setDir _actDir;
	}];
}else{
systemChat "Object already have a kit menu";
};
};
FST_ApplyCamoPreset = {
    params [["_camo","Woodland"]];
    private _unit = player;
    private _camoLower = toLower _camo;
    private _camoCap = switch (_camoLower) do {
        case "desert":   {"Desert"};
        case "urban":    {"Urban"};
        case "midnight": {"Midnight"};
        default          {"Woodland"};
    };
    missionNamespace setVariable ["FST_LastCamoPreset", _camoCap];
    private _swapUniform = {
        params ["_new"];
        if !(isClass (configFile >> "CfgWeapons" >> _new)) exitWith {};
        private _uItems = uniformItems _unit;
        removeUniform _unit;
        _unit forceAddUniform _new;
        { _unit addItemToUniform _x } forEach _uItems;
    };
    private _swapVest = {
        params ["_new"];
        if !(isClass (configFile >> "CfgWeapons" >> _new)) exitWith {};
        private _vItems = vestItems _unit;
        if (vest _unit != "") then { removeVest _unit; };
        _unit addVest _new;
        { _unit addItemToVest _x } forEach _vItems;
    };
    private _swapBackpack = {
        params ["_new"];
        if !(isClass (configFile >> "CfgVehicles" >> _new)) exitWith {};
        private _bItems = backpackItems _unit;
        if (backpack _unit != "") then { removeBackpack _unit; };
        _unit addBackpack _new;
        { _unit addItemToBackpack _x } forEach _bItems;
    };
    private _helmet = format ["FST_P2_Helmet_%1", _camoCap];
    if (isClass (configFile >> "CfgWeapons" >> _helmet)) then {
        removeHeadgear _unit;
        _unit addHeadgear _helmet;
    };
    private _uniform = format ["FST_Uniform_%1", _camoCap];
    [_uniform] call _swapUniform;
    private _newBino = format ["FST_%1_Electrobinoculars", _camoCap];
    if (isClass (configFile >> "CfgWeapons" >> _newBino)) then {
        private _curBino = binocular _unit;
        if (_curBino != "") then { _unit removeWeapon _curBino; };
        _unit addWeapon _newBino;
    };
    private _curHmd = hmd _unit;
    if (_curHmd != "") then {
        private _newHmd = "";
        if (_curHmd find "FST_Visor_" == 0) then {
            _newHmd = format ["FST_Visor_%1", _camoCap];
        } else {
            if (_curHmd find "FST_NVG_" == 0) then {
                _newHmd = format ["FST_NVG_%1", _camoCap];
            };
        };
        if (_newHmd != "" && isClass (configFile >> "CfgWeapons" >> _newHmd)) then {
            _unit unlinkItem _curHmd;
            _unit linkItem   _newHmd;
        };
    };
    private _curVest = vest _unit;
    if (_curVest != "") then {
        private _vestNew = "";
        if (_curVest find "FST_Vest_NCO_Kama" == 0) then {
            _vestNew = format ["FST_Vest_NCO_Kama_%1", _camoCap];
        } else {
            if (_curVest find "FST_Vest_NCO" == 0) then {
                _vestNew = format ["FST_Vest_NCO_%1", _camoCap];
            } else {
                if (_curVest find "FST_pauldron_kama" == 0) then {
                    _vestNew = format ["FST_pauldron_kama_%1", _camoCap];
                };
            };
        };
        if (_vestNew != "" && isClass (configFile >> "CfgWeapons" >> _vestNew)) then {
            [_vestNew] call _swapVest;
        };
    };
	private _curBp = backpack _unit;
	if (_curBp != "") then {
		private _bpNew = "";
		if (_curBp find "FST_Backpack_Jumppack" == 0) then {
			_bpNew = format ["FST_Backpack_Jumppack_%1", _camoCap];
		} else {
			if (_curBp find "FST_Clone_backpack_RTO" == 0) then {
				_bpNew = format ["FST_Clone_backpack_RTO_%1", _camoCap];
			} else {
				if (_curBp find "FST_Backpack_Antenna" == 0) then {
					_bpNew = format ["FST_Backpack_Antenna_%1", _camoCap];
				} else {
					if (_curBp find "FST_Clone_backpack" == 0) then {
						_bpNew = format ["FST_Clone_backpack_%1", _camoCap];
					};
				};
			};
		};
		if (_bpNew != "" && isClass (configFile >> "CfgVehicles" >> _bpNew)) then {
			[_bpNew] call _swapBackpack;
		};
	};
    [] call FST_fnc_updateAditionalListCamo;
    playSoundUI ["41st_KitMenu\sounds\select_default.ogg", 0.85, 1];
};
FST_fnc_updateAditionalListCamo = {
    private _disp = findDisplay 2000;
    if (isNull _disp) exitWith {};
    private _lb = _disp displayCtrl 1731;
    if (isNull _lb) exitWith {};

    private _camoCap = missionNamespace getVariable ["FST_LastCamoPreset","Woodland"];
    private _rows = lbSize _lb;
    for "_i" from 0 to (_rows - 1) do {
        private _dataStr = lbData [_lb, _i];
        if (_dataStr isEqualTo "") then { continue; };
        private _arr = call compile _dataStr;
        if (!(_arr isEqualType [])) then { continue; };
        private _item = _arr param [0, ""];
        if !(_item isEqualType "") then { continue; };
        private _new = "";
		if (_item == "FST_NVG")           then { _new = format ["FST_NVG_%1", _camoCap]; };
		if (_item == "FST_Visor")         then { _new = format ["FST_Visor_%1", _camoCap]; };
		if (_item find "FST_NVG_"   == 0) then { _new = format ["FST_NVG_%1",   _camoCap]; };
		if (_item find "FST_Visor_" == 0) then { _new = format ["FST_Visor_%1", _camoCap]; };
		if (_item find "FST_Vest_NCO_Kama"      == 0) then { _new = format ["FST_Vest_NCO_Kama_%1", _camoCap]; };
		if (_item find "FST_Vest_NCO"           == 0) then { _new = format ["FST_Vest_NCO_%1",      _camoCap]; };
		if (_item find "FST_pauldron_kama"      == 0) then { _new = format ["FST_pauldron_kama_%1", _camoCap]; };
		if (_item find "FST_Backpack_Antenna"   == 0) then { _new = format ["FST_Backpack_Antenna_%1", _camoCap]; };
		if (_item find "FST_Clone_backpack_RTO" == 0) then { _new = format ["FST_Clone_backpack_RTO_%1", _camoCap]; };
		if (_item find "FST_Clone_backpack"     == 0) then { _new = format ["FST_Clone_backpack_%1", _camoCap]; };
		if (_item == "FST_Backpack_Jumppack")          then { _new = format ["FST_Backpack_Jumppack_%1", _camoCap]; };
		if (_item find "FST_Backpack_Jumppack_" == 0)   then { _new = format ["FST_Backpack_Jumppack_%1", _camoCap]; };
        if (_new != "" && { _new != _item }) then {
            _arr set [0, _new];
            _lb lbSetData [_i, str _arr];

            private _cfgW = configFile >> "CfgWeapons"  >> _new;
            private _cfgV = configFile >> "CfgVehicles" >> _new;
            private _pic  = if (isClass _cfgW) then { getText (_cfgW >> "picture") }
                            else { if (isClass _cfgV) then { getText (_cfgV >> "picture") } else { "" } };
            private _dn   = if (isClass _cfgW) then { getText (_cfgW >> "displayName") }
                            else { if (isClass _cfgV) then { getText (_cfgV >> "displayName") } else { "" } };
            if (_pic != "") then { _lb lbSetPicture [_i, _pic]; };
            if (_dn  != "") then { _lb lbSetText    [_i, _dn];  };
        };
    };
};
FST_fnc_toggleJumppack = {
    private _unit = player;
    private _camo = missionNamespace getVariable ["FST_LastCamoPreset","Woodland"];
    private _jpClass = format ["FST_Backpack_Jumppack_%1", _camo];
    if !(isClass (configFile >> "CfgVehicles" >> _jpClass)) exitWith {
        systemChat format ["[KitMenu] Jumppack class not found: %1", _jpClass];
        playSoundUI ["41st_KitMenu\sounds\select_cantTake.ogg", 0.4, 1];
    };
    private _cur = backpack _unit;
    private _swapBackpack = {
        params ["_new"];
        private _items = backpackItems _unit;
        if (backpack _unit != "") then { removeBackpack _unit; };
        _unit addBackpack _new;
        { _unit addItemToBackpack _x } forEach _items;
    };
    if (_cur find "FST_Backpack_Jumppack_" == 0) then {
        private _saved = missionNamespace getVariable ["FST_JP_SavedBackpack", ["",[]]];
        private _prevClass = _saved param [0, ""];
        private _prevItems = _saved param [1, []];

        removeBackpack _unit;
        if (_prevClass != "" && isClass (configFile >> "CfgVehicles" >> _prevClass)) then {
            _unit addBackpack _prevClass;
            { _unit addItemToBackpack _x } forEach _prevItems;
        };
        playSoundUI ["41st_KitMenu\sounds\select_backpack_2.ogg", 0.95, 1];
    } else {
        missionNamespace setVariable ["FST_JP_SavedBackpack", [_cur, backpackItems _unit]];
        [_jpClass] call _swapBackpack;
        playSoundUI ["41st_KitMenu\sounds\select_backpack_1.ogg", 0.95, 1];
    };
    call WBK_UpdatePlayerKitOnMenu;
};
FST_fnc_gearIndex = {
    private _idx = createHashMapFromArray [
        ["uniforms",  []],
        ["vests",     []],
        ["helmets",   []],
        ["backpacks", []],
        ["facewear",  []],
        ["nvgs",      []]
    ];
    {
        private _cls = configName _x;
        if (!(["FST_", _cls] call BIS_fnc_inString)) then { continue };
        private _ii = _x >> "ItemInfo";
        if !(isClass _ii) then { continue };
        private _type = getNumber (_ii >> "type");
        switch (_type) do {
            case 801: { (_idx get "uniforms")  pushBack _cls; };
            case 701: { (_idx get "vests")     pushBack _cls; };
            case 605: { (_idx get "helmets")   pushBack _cls; };
            case 616: { (_idx get "nvgs")      pushBack _cls; };
            default {};
        };
    } forEach ("true" configClasses (configFile >> "CfgWeapons"));
    {
        private _cls = configName _x;
        if (!(["FST", _cls] call BIS_fnc_inString)) then { continue };
        if (getNumber (_x >> "isBackpack") == 1) then {
            (_idx get "backpacks") pushBack _cls;
        };
    } forEach ("true" configClasses (configFile >> "CfgVehicles"));
    {
        private _cls = configName _x;
        if (!(["FST", _cls] call BIS_fnc_inString)) then { continue };
        private _scopeOk = (getNumber (_x >> "scopeArsenal") == 2) || (getNumber (_x >> "scope") > 1);
        if (_scopeOk) then { (_idx get "facewear") pushBack _cls; };
    } forEach ("true" configClasses (configFile >> "CfgGlasses"));
    uiNamespace setVariable ["FST_GearIndex", _idx];
    private _all = +(_idx get "uniforms")
                + (_idx get "vests")
                + (_idx get "helmets")
                + (_idx get "backpacks")
                + (_idx get "facewear")
                + (_idx get "nvgs");
    uiNamespace setVariable ["FST_AllHelmetClasses", _all];
};
FST_fnc_showCategory = {
    params [ ["_cats", ["helmets"], ["", []]] ];
    if (_cats isEqualType "") then { _cats = [_cats]; };
    uiNamespace setVariable ["FST_CurrentCategories", _cats];
    [] call FST_fnc_refreshGearList;
    [] call FST_fnc_scrollListTop;
};
FST_fnc_refreshGearList = {
    private _display = uiNamespace getVariable ["FST_HelmetOverlay_Display", displayNull];
    if (isNull _display) exitWith {};
    private _listCtrl = _display displayCtrl 4102;
    private _inputLower = toLower (ctrlText (_display displayCtrl 4103));
    private _idx  = uiNamespace getVariable ["FST_GearIndex", createHashMap];
    private _cats = uiNamespace getVariable ["FST_CurrentCategories", ["helmets"]];
    private _classes = [];
    { _classes append (_idx getOrDefault [_x, []]); } forEach _cats;
    private _filtered = _classes select {
        private _cls = _x;
        private _cfgW = configFile >> "CfgWeapons"  >> _cls;
        private _cfgV = configFile >> "CfgVehicles" >> _cls;
        private _cfgG = configFile >> "CfgGlasses"  >> _cls;
        private _cfg  = if (isClass _cfgW) then {_cfgW} else { if (isClass _cfgV) then {_cfgV} else {_cfgG} };
        private _dn   = toLower getText (_cfg >> "displayName");
        (_dn find _inputLower) > -1 || ((toLower _cls) find _inputLower) > -1
    };
    lbClear _listCtrl;
    {
        private _cls = _x;
        private _cfgW = configFile >> "CfgWeapons"  >> _cls;
        private _cfgV = configFile >> "CfgVehicles" >> _cls;
        private _cfgG = configFile >> "CfgGlasses"  >> _cls;
        private _cfg  = if (isClass _cfgW) then {_cfgW} else { if (isClass _cfgV) then {_cfgV} else {_cfgG} };
        private _dn = getText (_cfg >> "displayName"); if (_dn == "") then { _dn = _cls; };
        private _pic = getText (_cfg >> "picture");
        private _i = _listCtrl lbAdd _dn;
        if (_pic != "") then { _listCtrl lbSetPicture [_i, _pic]; };
        _listCtrl lbSetData [_i, format ["[%1]", str _cls]];
    } forEach _filtered;
    [] spawn {
        uiSleep 0;
        private _display = uiNamespace getVariable ["FST_HelmetOverlay_Display", displayNull];
        if (isNull _display) exitWith {};
        private _lb = _display displayCtrl 4102;
        if (isNull _lb) exitWith {};
        if ((lbSize _lb) > 0) then { lbSetCurSel [_lb, 0]; };
        uiSleep 0;
        if ((lbSize _lb) > 0) then { lbSetCurSel [_lb, 0]; };
    };
};
FST_fnc_scrollListTop = {
    private _display = uiNamespace getVariable ["FST_HelmetOverlay_Display", displayNull];
    if (isNull _display) exitWith {};
    private _lb = _display displayCtrl 4102;
    if (isNull _lb) exitWith {};
    uiNamespace setVariable ["FST_SuppressSelect", true];
    ctrlSetFocus _lb;
    if ((lbSize _lb) > 0) then {
        lbSetCurSel [_lb, 0];
        0 spawn {
            uiSleep 0;
            private _display = uiNamespace getVariable ["FST_HelmetOverlay_Display", displayNull];
            if (isNull _display) exitWith {};
            private _lb = _display displayCtrl 4102;
            if (isNull _lb) exitWith {};
            if ((lbSize _lb) > 0) then { lbSetCurSel [_lb, 0]; };
            uiNamespace setVariable ["FST_SuppressSelect", false];
        };
    } else {
        uiNamespace setVariable ["FST_SuppressSelect", false];
    };
};
FST_fnc_selectHelmet = {
	if (uiNamespace getVariable ["FST_SuppressSelect", false]) exitWith {
        uiNamespace setVariable ["FST_SuppressSelect", false];
    };
    playSoundUI [selectRandom ["41st_KitMenu\sounds\select_helmet_1.ogg","41st_KitMenu\sounds\select_helmet_2.ogg"], 0.85, 1];
    private _display  = uiNamespace getVariable ["FST_HelmetOverlay_Display", displayNull];
    private _listCtrl = _display displayCtrl 4102;
    private _index    = lbCurSel _listCtrl;
    private _ctrlId   = ctrlIDC _listCtrl;

    private _dataStr  = lbData [_ctrlId, _index];
    private _gearArr  = call compile _dataStr;
    private _gearClass = _gearArr select 0;

    private _cfgW = configFile >> "CfgWeapons"  >> _gearClass;
    private _cfgV = configFile >> "CfgVehicles" >> _gearClass;
    private _cfgG = configFile >> "CfgGlasses"  >> _gearClass;
    if (isClass _cfgG) exitWith {
        if (goggles player == _gearClass) then {
            removeGoggles player;
        } else {
            removeGoggles player;
            player addGoggles _gearClass;
        };
    };

    private _isWeapon  = isClass _cfgW;
    private _isVehicle = isClass _cfgV;
    private _cfg = if (_isWeapon) then {_cfgW} else {_cfgV};

    private _type = -1;
    if (_isWeapon) then {
        private _itemInfo = _cfg >> "ItemInfo";
        _type = getNumber (_itemInfo >> "type");
    } else {
        _type = 302;
    };
    switch (_type) do {
        case 605: { removeHeadgear player; player addHeadgear _gearClass; };
        case 801: { private _it = uniformItems player;  removeUniform player;  player forceAddUniform _gearClass; { player addItemToUniform _x; } forEach _it; };
        case 701: { private _it = vestItems player;     removeVest player;     player addVest _gearClass;         { player addItemToVest _x;    } forEach _it; };
        case 302: { private _it = backpackItems player; removeBackpack player; player addBackpack _gearClass;     { player addItemToBackpack _x;} forEach _it; };
        case 901;
        case 616;
        case 101: { player linkItem _gearClass; };
        default   { systemChat format ["[ERROR] Unrecognized gear type: %1", _type]; };
    };
};
FST_fnc_filterHelmets = {
    [] call FST_fnc_refreshGearList;
};
Wbk_AssignAditionalGear = {
private _typeOfKit = player getVariable ["WBK_Kit_Name", ""];
params ["_control", "_index"];
private ["_lbData", "_itemClass", "_itemCount"];
_lbData = call compile (lbData [ctrlIDC _control, _index]);
_item = _lbData select 0;
private _isCQB = (count _lbData > 1) && {(_lbData select 1) == "CQB_MAGIC"};
if ((missionNamespace getVariable ["FST_CurrentKitCategory","regular"]) isEqualTo "ranger") then {
    private _camo = missionNamespace getVariable ["FST_LastCamoPreset","Woodland"];
    switch (true) do {
        case (_item == "FST_NVG"):              { _item = format ["FST_NVG_%1", _camo]; };
        case (_item == "FST_Visor"):            { _item = format ["FST_Visor_%1", _camo]; };
        case (_item == "FST_Vest_NCO"):         { _item = format ["FST_Vest_NCO_%1", _camo]; };
        case (_item == "FST_Vest_NCO_Kama"):    { _item = format ["FST_Vest_NCO_Kama_%1", _camo]; };
        case (_item == "FST_pauldron_kama"):    { _item = format ["FST_pauldron_kama_%1", _camo]; };
        case (_item == "FST_Backpack_Antenna"): { _item = format ["FST_Backpack_Antenna_%1", _camo]; };
        case (_item == "FST_Clone_backpack_RTO"): { _item = format ["FST_Clone_backpack_RTO_%1", _camo]; };
        case (_item == "FST_Clone_backpack"):     { _item = format ["FST_Clone_backpack_%1", _camo]; };
		case (_item == "FST_Backpack_Jumppack"):         { _item = format ["FST_Backpack_Jumppack_%1", _camo]; };
		case (_item find "FST_Backpack_Jumppack_" == 0): { _item = format ["FST_Backpack_Jumppack_%1", _camo]; };

        default {
        };
    };
};
switch true do {
        case (_item == "any"): {};
		case (_item == "REMOVE_PRIMARY"): {
			private _pw = primaryWeapon player;
			if (_pw != "") then {
				private _pwMags = [_pw] call CBA_fnc_compatibleMagazines;
				{ player removeMagazines _x; } forEach _pwMags;
				player removeWeapon _pw;
			};
			{
				player removeMagazines _x;
			} forEach [
				"IDA_grenade_Sonic_mag",
				"FST_grenade_emp_mag"
			];
			private _det = "FST_grenade_Detonator_mag";
			private _detCount = { _x == _det } count magazines player;
			if (_detCount > 3) then {
				private _extra = _detCount - 3 min 2;
				for "_i" from 1 to _extra do { player removeMagazine _det; };
			};
			playSoundUI ["41st_KitMenu\sounds\select_default.ogg", 0.85, 1];
		};
		case (_item == "FST_Antenna"): {
			playSoundUI ["41st_KitMenu\sounds\select_nvg.ogg", 0.85, 1];
			if (hmd player == "FST_Antenna") then {
				player unlinkItem "FST_Antenna";
			} else {
				if !("FST_Antenna" in (assignedItems player)) then {
					player linkItem "FST_Antenna";
				} else {
					player linkItem "FST_Antenna";
				};
			};
		};

	case (_item == "FST_NVG" || {_item find "FST_NVG_" == 0}): {
		playSoundUI ["41st_KitMenu\sounds\select_nvg.ogg", 0.85, 1];
		private _cls = _item;
		if (hmd player == _cls) then {
			player unlinkItem _cls;
		} else {
			player linkItem _cls;
		};
	};
		case (_isCQB): {
			playSoundUI [selectRandom [
				"41st_KitMenu\sounds\select_weapon_1.ogg",
				"41st_KitMenu\sounds\select_weapon_2.ogg"
			], 0.85, 1];

			_weaponStuff = primaryWeaponItems player;
			_mags = [primaryWeapon player] call CBA_fnc_compatibleMagazines;
			{player removeMagazines _x;} forEach _mags;
			player removeWeapon primaryWeapon player;
			player addWeapon "FST_DC15S";
			player addPrimaryWeaponItem "FST_Attachment_Optic_Holo_DC15";
			player selectWeapon "FST_DC15S";
			{player addPrimaryWeaponItem _x;} forEach _weaponStuff;

			private _magClass = (["FST_DC15S"] call CBA_fnc_compatibleMagazines) select 0;
			for "_i" from 1 to 15 do {
				if (player canAddItemToVest _magClass) then {
					player addItemToVest _magClass;
				} else {
					if (player canAddItemToBackpack _magClass) then {
						player addItemToBackpack _magClass;
					} else {
						player addItemToUniform _magClass;
					};
				};
			};

			{
				private _grenade = _x;
				player removeMagazines _grenade;
				for "_i" from 1 to 5 do {
					if (player canAddItemToVest _grenade) then {
						player addItemToVest _grenade;
					} else {
						if (player canAddItemToUniform _grenade) then {
							player addItemToUniform _grenade;
						} else {
							player addItemToBackpack _grenade;
						};
					};
				};
			} forEach [
				"IDA_grenade_Sonic_mag",
				"FST_grenade_emp_mag",
				"FST_grenade_Detonator_mag"
			];
		};
		case (_item == "JLTS_STATIC_OPTION" && {count _lbData > 1 && _lbData select 1 == "STATIC_MAGIC"}): {
			playSoundUI ["41st_KitMenu\sounds\select_generic_3.ogg", 0.85, 1];
			private _magClass = "JLTS_stun_mag_long";

			private _allowedWeapons = [
				"FST_DC15A",
				"FST_DC15A_ugl",
				"FST_DC15S",
				"FST_DC15S_UGL",
				"FST_DC15C_F"
			];

			private _currentWeapon = currentWeapon player;

			if (_allowedWeapons findIf { _currentWeapon isEqualTo _x } != -1) then {
				private _hasAny = { _x == _magClass } count magazines player;

				if (_hasAny > 0) then {
					player removeMagazines _magClass;
				} else {
					for "_i" from 1 to 5 do {
						if (player canAddItemToVest _magClass) then {
							player addItemToVest _magClass;
						} else {
							if (player canAddItemToBackpack _magClass) then {
								player addItemToBackpack _magClass;
							} else {
								player addItemToUniform _magClass;
							};
						};
					};
				};
			} else {
				systemChat "Selected weapon doesn't allow stuns";
			};
		};
		case ( isClass (configFile >> "CfgUnitInsignia" >> _item)): {
		    playSoundUI [selectRandom ["41st_KitMenu\sounds\select_generic_1.ogg","41st_KitMenu\sounds\select_generic_2.ogg","41st_KitMenu\sounds\select_generic_3.ogg","41st_KitMenu\sounds\select_generic_4.ogg","41st_KitMenu\sounds\select_generic_5.ogg","41st_KitMenu\sounds\select_generic_6.ogg"], 0.85, 1];
		    player setVariable ["BIS_fnc_setUnitInsignia_class", nil];
		    [player, _item] call BIS_fnc_setUnitInsignia;
		};
		case (_item isKindOf ["Binocular", configFile >> "CfgWeapons"]): {
			player removeWeapon binocular player;
			player addWeapon _item;
			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_generic_1.ogg","41st_KitMenu\sounds\select_generic_2.ogg","41st_KitMenu\sounds\select_generic_3.ogg","41st_KitMenu\sounds\select_generic_4.ogg","41st_KitMenu\sounds\select_generic_5.ogg","41st_KitMenu\sounds\select_generic_6.ogg"], 0.85, 1];
		};
		case (getNumber(configFile >> "CfgWeapons" >> _item >> 'ItemInfo' >> 'type' ) isEqualTo 616): {
			player linkItem _item;
			playSoundUI ["41st_KitMenu\sounds\select_nvg.ogg", 0.85, 1];
		};
		case (getNumber(configFile >> "CfgWeapons" >> _item >> 'ItemInfo' >> 'type' ) isEqualTo 302 || getNumber(configFile >> "CfgWeapons" >> _item >> 'ItemInfo' >> 'type' ) isEqualTo 301 || getNumber(configFile >> "CfgWeapons" >> _item >> 'ItemInfo' >> 'type' ) isEqualTo 201 || getNumber(configFile >> "CfgWeapons" >> _item >> 'ItemInfo' >> 'type' ) isEqualTo 101): {
			player addPrimaryWeaponItem _item;
			player addHandgunItem _item;
			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_attachment_1.ogg","41st_KitMenu\sounds\select_attachment_2.ogg"], 0.65, 1];
		};
		case (getNumber(configFile >> "CfgWeapons" >> _item >> 'ItemInfo' >> 'type' ) isEqualTo 801): {
			_insignia = [player] call BIS_fnc_getUnitInsignia;
		    playSoundUI [selectRandom ["41st_KitMenu\sounds\select_cloth_1.ogg","41st_KitMenu\sounds\select_cloth_2.ogg","41st_KitMenu\sounds\select_cloth_3.ogg"], 0.85, 1];
		   _items = uniformItems player;
			removeUniform player;
			player forceAddUniform _item;
			{player addItemToUniform _x;} forEach _items;
			player setVariable ["BIS_fnc_setUnitInsignia_class", nil];
			[player, _insignia] call BIS_fnc_setUnitInsignia;
		};
		case (getNumber(configFile >> "CfgWeapons" >> _item >> 'ItemInfo' >> 'type' ) isEqualTo 701): {
		   playSoundUI [selectRandom ["41st_KitMenu\sounds\select_cloth_1.ogg","41st_KitMenu\sounds\select_cloth_2.ogg","41st_KitMenu\sounds\select_cloth_3.ogg"], 0.85, 1];
		   _items = vestItems player;
			removeVest player;
			player addVest _item;
			{player addItemToVest _x;} forEach _items;
			if (_item == "FST_Vest_NCO" && !([player, "itemAndroid"] call BIS_fnc_hasItem)) then {
				player addItem "itemAndroid";
			};
			if (_item == "FST_CloneVestAirborneNCO" && !([player, "itemAndroid"] call BIS_fnc_hasItem)) then {
				player addItem "itemAndroid";
			};
			if (_item == "FST_CloneVestAirborneNCO_Veteran" && !([player, "itemAndroid"] call BIS_fnc_hasItem)) then {
				player addItem "itemAndroid";
			};
			if (_item == "FST_Vest_HeavyBag" && !([player, "itemAndroid"] call BIS_fnc_hasItem)) then {
				player addItem "itemAndroid";
			};
			if (_item == "FST_Vest_NCO_Veteran" && !([player, "itemAndroid"] call BIS_fnc_hasItem)) then {
				player addItem "itemAndroid";
			};
			if (_item == "FST_Vest_HeavyBag_Veteran" && !([player, "itemAndroid"] call BIS_fnc_hasItem)) then {
				player addItem "itemAndroid";
			};
			if (_item == "FST_Vest_NCO_Kama" && !([player, "itemAndroid"] call BIS_fnc_hasItem)) then {
				player addItem "itemAndroid";
			};
			if (_item == "FST_Vest_NCO_Kama_Veteran" && !([player, "itemAndroid"] call BIS_fnc_hasItem)) then {
				player addItem "itemAndroid";
			};
			if (_item == "FST_Vest_Base" && [player, "itemAndroid"] call BIS_fnc_hasItem && !(_typeOfKit in ["Crewman", "Crewman Medic"]) && {(player getVariable ["WBK_Kit_Category",""]) != "ranger"}) then {
				player removeItem "itemAndroid";
			};
			if (_item == "FST_Vest_Base") then {
				private _pistol   = "FST_DC17";
				private _magClass = "FST_blaster_cell_low_Blue";
				if (_pistol in weapons player) then {
					player removeWeapon _pistol;
				};
				player removeMagazines _magClass;
			};
		};
		case (getNumber(configFile >> "CfgWeapons" >> _item >> 'ItemInfo' >> 'type' ) isEqualTo 605): {
		    playSoundUI [selectRandom ["41st_KitMenu\sounds\select_helmet_1.ogg","41st_KitMenu\sounds\select_helmet_2.ogg"], 0.85, 1];
			removeHeadgear player;
			player addHeadgear _item;
		};
case (isClass (configFile >> "CfgVehicles" >> _item)): {
    playSoundUI [selectRandom ["41st_KitMenu\sounds\select_backpack_1.ogg", "41st_KitMenu\sounds\select_backpack_2.ogg"], 0.95, 1];
	private _equipClass = _item;
	private _isRanger   = toLower (player getVariable ["WBK_Kit_Category",""]) isEqualTo "ranger";
	private _isSL       = (player getVariable ["WBK_Kit_Name",""]) in ["Squad Leader","Squad Leader "];
	if (_isRanger && _isSL) then {
		private _camo = missionNamespace getVariable ["FST_LastCamoPreset","Woodland"];
		if (_item == "FST_Backpack_Antenna") then {
			private _cand = format ["FST_Backpack_Antenna_%1", _camo];
			if (isClass (configFile >> "CfgVehicles" >> _cand)) then { _equipClass = _cand; };
		};
		if (_item == "FST_Backpack_Jumppack_LR") then {
			private _cand2 = format ["FST_Backpack_Jumppack_LR_%1", _camo];
			if (isClass (configFile >> "CfgVehicles" >> _cand2)) then { _equipClass = _cand2; };
		};
	};
	removeBackpack player;
	player addBackpack _equipClass;

    removeBackpack player;
    player addBackpack _item;

    private _grenadeClass = "FST_grenade_Detonator_mag";
    private _grenadesCurrent = { _x == _grenadeClass } count magazines player;

		private _rawData = lbData [ctrlIDC _control, _index];
		private _lbData = [];
		try {
			_lbData = call compile _rawData;
		} catch {
			_lbData = [_rawData];
		};
		private _item = _lbData select 0;
		private _desc = if (count _lbData > 1) then {_lbData select 1} else {""};

    switch (_item) do {
        case "FST_Backpack_Antenna";
        case "FST_Backpack_Jumppack_LR": {
            switch (_desc) do {
                case "10x DC15L Battery": {
                    for "_i" from 1 to 10 do { player addItemToBackpack "FST_blaster_battery_DC15L_Blue"; };
                };
                case "3x RPS6 + 1x HE Rocket": {
                    for "_i" from 1 to 3 do { player addItemToBackpack "FST_RPS6_rocket"; };
                    player addItemToBackpack "FST_RPS6_rocket_HE";
                };
                case "7x Z6 Battery": {
                    for "_i" from 1 to 7 do { player addItemToBackpack "FST_blaster_battery_Blue"; };
                };
                case "Standard Ammo + 3x Detonators": {
                    for "_i" from 1 to 12 do { player addItemToBackpack "FST_blaster_cell_High_Blue"; };
                    for "_i" from 1 to 18 do { player addItemToBackpack "FST_blaster_cell_Blue"; };
                    for "_i" from 1 to 4 do {
                        player addItemToBackpack "FST_blaster_cell_LE_Blue";
                        player addItemToBackpack "FST_blaster_scatter_cell_DP23_Blue";
                    };
                    if (_grenadesCurrent < 6) then {
                        for "_i" from 1 to (6 - _grenadesCurrent) do {
                            if (player canAddItemToVest _grenadeClass) then {
                                player addItemToVest _grenadeClass;
                            } else {
                                player addItemToUniform _grenadeClass;
                            };
                        };
                    };
                };
                case "2x LP Coil + 4x T15 Coil": {
                    for "_i" from 1 to 2 do { player addItemToBackpack "FST_thermal_coil_LP_Blue"; };
                    for "_i" from 1 to 4 do { player addItemToBackpack "FST_thermal_coil_T15_Blue"; };
                };
                case "3x PLX Rockets": {
                    for "_i" from 1 to 3 do { player addItemToBackpack "FST_PLX1_Rocket"; };
                };
            };
        };

        // REGULAR BACKPACKS
        case "FST_Clone_Backpack_Invisible_15L": {
            for "_i" from 1 to 10 do { player addItemToBackpack "FST_blaster_battery_DC15L_Blue"; };
        };
        case "FST_Clone_Backpack_Invisible_RPS": {
            for "_i" from 1 to 3 do { player addItemToBackpack "FST_RPS6_rocket"; };
            player addItemToBackpack "FST_RPS6_rocket_HE";
        };
        case "FST_Clone_Backpack_Invisible_Z6": {
            for "_i" from 1 to 7 do { player addItemToBackpack "FST_blaster_battery_Blue"; };
        };
        case "FST_Clone_Backpack_Invisible_STD": {
            for "_i" from 1 to 12 do { player addItemToBackpack "FST_blaster_cell_High_Blue"; };
            for "_i" from 1 to 18 do { player addItemToBackpack "FST_blaster_cell_Blue"; };
            for "_i" from 1 to 4 do {
                player addItemToBackpack "FST_blaster_cell_LE_Blue";
                player addItemToBackpack "FST_blaster_scatter_cell_DP23_Blue";
            };
            // Ensure player has exactly 6 grenades total
            if (_grenadesCurrent < 6) then {
                for "_i" from 1 to (6 - _grenadesCurrent) do {
                    if (player canAddItemToVest _grenadeClass) then {
                        player addItemToVest _grenadeClass;
                    } else {
                        player addItemToUniform _grenadeClass;
                    };
                };
            };
        };
        case "FST_Clone_Backpack_Invisible_RifleAT": {
            for "_i" from 1 to 2 do { player addItemToBackpack "FST_thermal_coil_LP_Blue"; };
            for "_i" from 1 to 4 do { player addItemToBackpack "FST_thermal_coil_T15_Blue"; };
        };
        case "FST_Clone_Backpack_Invisible_PLX": {
            for "_i" from 1 to 3 do { player addItemToBackpack "FST_PLX1_Rocket"; };
        };

        // JUMP PACK BACKPACKS
        case "FST_Backpack_Jumppack_15L_Ammo": {
            for "_i" from 1 to 10 do { player addItemToBackpack "FST_blaster_battery_DC15L_Blue"; };
        };
        case "FST_Backpack_Jumppack_STD_Ammo": {
            for "_i" from 1 to 12 do { player addItemToBackpack "FST_blaster_cell_High_Blue"; };
            for "_i" from 1 to 18 do { player addItemToBackpack "FST_blaster_cell_Blue"; };
            for "_i" from 1 to 4 do {
                player addItemToBackpack "FST_blaster_cell_LE_Blue";
                player addItemToBackpack "FST_blaster_scatter_cell_DP23_Blue";
            };
            // Ensure player has exactly 6 grenades total
            if (_grenadesCurrent < 6) then {
                for "_i" from 1 to (6 - _grenadesCurrent) do {
                    if (player canAddItemToVest _grenadeClass) then {
                        player addItemToVest _grenadeClass;
                    } else {
                        player addItemToUniform _grenadeClass;
                    };
                };
            };
        };
        case "FST_Backpack_Jumppack_RifleAT_Ammo": {
            for "_i" from 1 to 2 do { player addItemToBackpack "FST_thermal_coil_LP_Blue"; };
            for "_i" from 1 to 4 do { player addItemToBackpack "FST_thermal_coil_T15_Blue"; };
        };
        case "FST_Backpack_Jumppack_Z6_Ammo": {
            for "_i" from 1 to 7 do { player addItemToBackpack "FST_blaster_battery_Blue"; };
        };
        case "FST_Backpack_Jumppack_PLX_Ammo": {
            for "_i" from 1 to 3 do { player addItemToBackpack "FST_PLX1_Rocket"; };
        };
        case "FST_Backpack_Jumppack_RPS_Ammo": {
            for "_i" from 1 to 3 do { player addItemToBackpack "FST_RPS6_rocket"; };
            player addItemToBackpack "FST_RPS6_rocket_HE";
        };
    };

    if !(_item in [
        "FST_Clone_Backpack_Invisible_STD",
        "FST_Backpack_Jumppack_STD_Ammo",
        "FST_Backpack_Antenna",
        "FST_Backpack_Jumppack_LR"
    ]) then {
        if (_grenadesCurrent > 3) then {
            player removeMagazines _grenadeClass;
            for "_i" from 1 to 3 do {
                if (player canAddItemToVest _grenadeClass) then {
                    player addItemToVest _grenadeClass;
                } else {
                    player addItemToUniform _grenadeClass;
                };
            };
        };
    };
};
		case (_item == "FST_RPS6_Disposable"): {
			playSoundUI [selectRandom [
				"41st_KitMenu\sounds\select_launcher_1.ogg",
				"41st_KitMenu\sounds\select_launcher_2.ogg"
			], 0.85, 1];
			private _currentLauncher = secondaryWeapon player;
			if (
				(backpack player == "FST_Backpack_Jumppack_RPS") ||
				(backpack player == "FST_Clone_Backpack_RPS") ||
				(backpack player == "FST_Backpack_Jumppack_PLX") ||
				(backpack player == "FST_Clone_Backpack_PLX")
			) then {
				removeBackpack player;
			};

			if (_currentLauncher == "FST_RPS6_Base") then {
				player removeWeapon _currentLauncher;
			} else {
				player addWeapon _item;
			};
		};
		case (_item == "FST_RPS6HP"): {
			if (secondaryWeapon player == "FST_RPS6HP") then {
				player removeWeapon "FST_RPS6HP";
				removeBackpack player;
				playSoundUI ["41st_KitMenu\sounds\select_launcher_1.ogg", 0.85, 1];
			} else {
				if (primaryWeapon player == "FST_T15") then {
					playSoundUI ["41st_KitMenu\sounds\select_cantTake.ogg", 0.4, 1];
					systemChat "You can't carry both the T15 and your selected launcher. Change primary weapon first.";
				} else {
					playSoundUI [selectRandom [
						"41st_KitMenu\sounds\select_launcher_1.ogg",
						"41st_KitMenu\sounds\select_launcher_2.ogg"
					], 0.85, 1];
					private _existingLauncher = secondaryWeapon player;
					private _launcherMags = [secondaryWeapon player] call CBA_fnc_compatibleMagazines;
					player removeWeapon _existingLauncher;
					{ player removeMagazines _x; } forEach _launcherMags;
					player addWeapon "FST_RPS6HP";
					player addSecondaryWeaponItem "FST_RPS6_rocket";
					removeBackpack player;
					if ((player getVariable ["WBK_Kit_Name",""]) == "Howler") then {
						player addBackpack "FST_Backpack_Jumppack_RPS";
					} else {
						private _isRanger = toLower (player getVariable ["WBK_Kit_Category",""]) isEqualTo "ranger";
						private _bpClass  = "FST_Clone_Backpack_RPS";
						if (_isRanger) then {
							private _camo  = missionNamespace getVariable ["FST_LastCamoPreset","Woodland"];
							private _cand  = format ["FST_Clone_backpack_%1", _camo];
							if (isClass (configFile >> "CfgVehicles" >> _cand)) then { _bpClass = _cand; };
						};
						player addBackpack _bpClass;
					};
					for "_i" from 1 to 3 do { player addItemToBackpack "FST_RPS6_rocket"; };
					player addItemToBackpack "FST_RPS6_rocket_HE";
				};
			};
		};
		case (_item == "FST_PLX1"): {
			if (secondaryWeapon player == "FST_PLX1") then {
				player removeWeapon "FST_PLX1";
				removeBackpack player;
				playSoundUI ["41st_KitMenu\sounds\select_launcher_1.ogg", 0.85, 1];
			} else {
				if (primaryWeapon player == "FST_T15") then {
					playSoundUI ["41st_KitMenu\sounds\select_cantTake.ogg", 0.4, 1];
					systemChat "You can't carry both the T15 and your selected launcher. Change primary weapon first.";
				} else {
					playSoundUI [selectRandom [
						"41st_KitMenu\sounds\select_launcher_1.ogg",
						"41st_KitMenu\sounds\select_launcher_2.ogg"
					], 0.85, 1];
					private _existingLauncher = secondaryWeapon player;
					private _launcherMags = [secondaryWeapon player] call CBA_fnc_compatibleMagazines;
					player removeWeapon _existingLauncher;
					{ player removeMagazines _x; } forEach _launcherMags;
					player addWeapon "FST_PLX1";
					player addSecondaryWeaponItem "FST_PLX1_Rocket";
					removeBackpack player;
					if ((player getVariable ["WBK_Kit_Name",""]) == "Howler") then {
						player addBackpack "FST_Backpack_Jumppack_PLX";
					} else {
						player addBackpack "FST_Clone_Backpack_PLX";
					};
					for "_i" from 1 to 2 do {
						player addItemToBackpack "FST_PLX1_Rocket";
						player addItemToBackpack "FST_PLX1_AA_mag";
					};
				};
			};
		};
		case (_item == "FST_PLX1_Guided"): {
			if (secondaryWeapon player == "FST_PLX1_Guided") then {
				player removeWeapon "FST_PLX1_Guided";
				removeBackpack player;
				playSoundUI ["41st_KitMenu\sounds\select_launcher_1.ogg", 0.85, 1];
			} else {
				if (primaryWeapon player == "FST_T15") then {
					playSoundUI ["41st_KitMenu\sounds\select_cantTake.ogg", 0.4, 1];
					systemChat "You can't carry both the T15 and your selected launcher. Change primary weapon first.";
				} else {
					playSoundUI [selectRandom [
						"41st_KitMenu\sounds\select_launcher_1.ogg",
						"41st_KitMenu\sounds\select_launcher_2.ogg"
					], 0.85, 1];
					private _existingLauncher = secondaryWeapon player;
					private _launcherMags = [secondaryWeapon player] call CBA_fnc_compatibleMagazines;
					player removeWeapon _existingLauncher;
					{ player removeMagazines _x; } forEach _launcherMags;
					player addWeapon "FST_PLX1_Guided";
					player addSecondaryWeaponItem "FST_PLX1_Rocket";
					removeBackpack player;
					if ((player getVariable ["WBK_Kit_Name",""]) == "Howler") then {
						player addBackpack "FST_Backpack_Jumppack_PLX";
					} else {
						player addBackpack "FST_Clone_Backpack_PLX";
					};
					for "_i" from 1 to 2 do {
						player addItemToBackpack "FST_PLX1_Rocket";
						player addItemToBackpack "FST_PLX1_AA_mag";
					};
				};
			};
		};
		case (_item isKindOf ["LauncherCore", configFile >> "CfgWeapons"]): {
			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_launcher_1.ogg","41st_KitMenu\sounds\select_launcher_2.ogg"], 0.85, 1];
			_weaponStuff = secondaryWeaponItems player;
			_mags = [secondaryWeapon player] call CBA_fnc_compatibleMagazines;
			_availableMagCount = {_x in _mags} count magazines player;
			{player removeMagazines _x;} forEach _mags;
			player removeWeapon secondaryWeapon player;
			_weap = [player, _item, _availableMagCount + 1] call BIS_fnc_addWeapon;
			{player addSecondaryWeaponItem _x;} forEach _weaponStuff;
		};
		case (_item == "FST_DC17"): {
			private _allowedVests = [
				"FST_CloneVestSuspenders_Ranger_Urban",
				"FST_CloneVestSuspenders_Ranger_Woodland",
				"FST_CloneVestSuspenders_Ranger_Midnight",
				"FST_CloneVestSuspenders_Ranger_Desert",
				"FST_CloneVestSuspenders_Urban",
				"FST_CloneVestSuspenders_Woodland",
				"FST_CloneVestSuspenders_Midnight",
				"FST_CloneVestSuspenders_Desert",
				"FST_CloneVestLieutenant_Urban",
				"FST_CloneVestLieutenant_Woodland",
				"FST_CloneVestLieutenant_Midnight",
				"FST_CloneVestLieutenant_Desert",
				"FST_pauldron_kama_Urban",
				"FST_pauldron_kama_Woodland",
				"FST_pauldron_kama_Midnight",
				"FST_pauldron_kama_Desert",
				"FST_Vest_NCO_Kama_Urban",
				"FST_Vest_NCO_Kama_Woodland",
				"FST_Vest_NCO_Kama_Midnight",
				"FST_Vest_NCO_Kama_Desert",
				"FST_Vest_NCO_Desert",
				"FST_Vest_NCO_Midnight",
				"FST_Vest_NCO_Woodland",
				"FST_Vest_NCO_Urban",
				"FST_vest_Woodland_holster",
				"FST_vest_Midnight_holster",
				"FST_vest_Urban_holster",
				"FST_vest_Desert_holster",
				"FST_pauldron_kama",
				"FST_pauldron_kama_reversed",
				"FST_CloneVestAirborneNCO",
				"FST_Vest_NCO_Kama",
				"FST_Vest_NCO_Kama_Veteran",
				"FST_CloneVestAirborneNCO_Veteran",
				"FST_Vest_HeavyBag",
				"FST_Vest_HeavyBag_Veteran",
				"FST_Vest_NCO",
				"FST_Vest_NCO_Veteran",
				"FST_CloneVestMerrik",
				"FST_CloneVestARC",
				"FST_CloneVestARC_Camo",
				"FST_CloneVestARC_Tally",
				"FST_CloneVestARC_Burns",
				"FST_CloneVestARC_Major",
				"FST_CloneVestARC_Mono",
				"FST_CloneVestARC_Squatch"
			];
			private _allowedFaces = [
				"FST_Heavy_Veteran_Face",
				"FST_FTL_Veteran_Face",
				"FST_FTL_Face",
				"FST_Heavy_Face"
			];

			private _kitName = player getVariable ["WBK_Kit_Name",""];
			private _isAllowed =
				((vest player) in _allowedVests) ||
				((goggles player) in _allowedFaces) ||
				(_kitName in ["Crew Chief","Pilot"]);

			if !_isAllowed then {
				playSoundUI ["41st_KitMenu\sounds\select_cantTake.ogg", 0.4, 1];
				systemChat "Only FTL+, Crew Chiefs or Pilots can use the pistol.";
				breakOut "switch";
			};

			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_pistol_1.ogg", "41st_KitMenu\sounds\select_pistol_2.ogg"], 0.85, 1];
			private _magClass = "FST_blaster_cell_low_Blue";
			private _knife = "UNSC_Knife";
			if (_knife in weapons player) then {
				player removeWeapon _knife;
			};
			if ("FST_DC17" in weapons player) then {
				player removeWeapon "FST_DC17";
				player removeMagazines _magClass;
			} else {
				player removeMagazines _magClass;
				player addWeapon "FST_DC17";
				player addHandgunItem _magClass;
				for "_i" from 1 to 6 do {
					player addMagazine _magClass;
				};
			};
		};
		case (_item == "FST_TwinDC17_Secondary"): {
			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_pistol_1.ogg", "41st_KitMenu\sounds\select_pistol_2.ogg"], 0.85, 1];
			private _magClass = "FST_blaster_cell_low_Blue";
			private _knife = "UNSC_Knife";

			if (_knife in weapons player) then {
				player removeWeapon _knife;
			};
			if ("FST_TwinDC17_Secondary" in weapons player) then {
				player removeWeapon "FST_TwinDC17_Secondary";
				player removeMagazines _magClass;
			} else {
				player removeMagazines _magClass;
				player addWeapon "FST_TwinDC17_Secondary";
				player addHandgunItem _magClass;
				for "_i" from 1 to 6 do {
					player addMagazine _magClass;
				};
			};
		};
		case (_item == "UNSC_Knife"): {
			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_pistol_1.ogg", "41st_KitMenu\sounds\select_pistol_2.ogg"], 0.85, 1];
			private _pistol = "FST_DC17";
			private _magClass = "FST_blaster_cell_low_Blue";
			private _hasKnife = _pistol in weapons player;

			if (_hasKnife) then {
				player removeWeapon _pistol;
				player removeMagazines _magClass;
			};

			if ("UNSC_Knife" in weapons player) then {
				player removeWeapon "UNSC_Knife";
			} else {
				player addWeapon "UNSC_Knife";
			};
		};
		case (_item == "FST_Hoster_Face"): {
			playSoundUI [selectRandom [
				"41st_KitMenu\sounds\select_cloth_1.ogg",
				"41st_KitMenu\sounds\select_cloth_2.ogg",
				"41st_KitMenu\sounds\select_cloth_3.ogg"
			], 0.85, 1];

			if (
    			(vest player == "FST_Vest_NCO") ||
    			(vest player == "FST_Vest_HeavyBag") ||
    			(vest player == "FST_Vest_NCO_Veteran") ||
    			(vest player == "FST_Vest_HeavyBag_Veteran") ||
				(vest player == "FST_CloneVestMerrik")
			) then {
				if (goggles player == "FST_Hoster_Face") then {
					removeGoggles player;
				} else {
					player addGoggles "FST_Hoster_Face";
				};
			} else {
				playSoundUI ["41st_KitMenu\sounds\select_cantTake.ogg", 0.4, 1];
				systemChat "You need to be an FTL to wear the holster.";
			};
		};
		case (_item isKindOf ["RifleCore", configFile >> "CfgWeapons"]): {
		if (_item in ["FST_Westar_M5_UGL", "FST_Westar_M5"]) then {
			if !("ARC-" in name player) then {
				systemChat "Only ARC troopers can use this weapon!";
				playSoundUI ["41st_KitMenu\sounds\select_cantTake.ogg", 0.4, 1];
				breakOut "switch";
			};
		};
		if (
			_item == "FST_T15" &&
			(
				secondaryWeapon player == "FST_PLX1" ||
				secondaryWeapon player == "FST_PLX1_Guided" ||
				secondaryWeapon player == "FST_RPS6HP"
			)
		) then {
			playSoundUI ["41st_KitMenu\sounds\select_cantTake.ogg", 0.4, 1];
			systemChat "You can't carry both the T15 and your selected launcher. Deselect it or grab a disposable.";
			breakOut "switch";
		};
			playSoundUI [selectRandom [
				"41st_KitMenu\sounds\select_weapon_1.ogg",
				"41st_KitMenu\sounds\select_weapon_2.ogg"
			], 0.85, 1];
			{
				player removeMagazines _x;
			} forEach [
				"FST_Smoke_LauncherGrenade",
				"FST_HE_LauncherGrenade",
				"ACE_HuntIR_M203",
				"ACE_40mm_Flare_white",
				"FST_SmokeBlue_LauncherGrenade",
				"FST_SmokeGreen_LauncherGrenade",
				"FST_SmokeRed_LauncherGrenade"
			];
			private _backpackClass = backpack player;
			private _backpackItems = backpackItems player;
			private _backpackInventory = [];
			{
				private _item = _x;
				private _existing = _backpackInventory findIf {(_x select 0) == _item};
				if (_existing == -1) then {
					_backpackInventory pushBack [_item, 1];
				} else {
					(_backpackInventory select _existing) set [1, (_backpackInventory select _existing select 1) + 1];
				};
			} forEach _backpackItems;

			private _weaponStuff = primaryWeaponItems player;
			private _mags = [primaryWeapon player] call CBA_fnc_compatibleMagazines;
			{player removeMagazines _x;} forEach _mags;
			player removeWeapon primaryWeapon player;
			player addWeapon _item;
			player selectWeapon _item;
			private _uglWeapons = ["FST_Westar_M5_UGL", "FST_DC15A_ugl", "FST_DC15S_UGL"];
			if !((primaryWeapon player) in _uglWeapons) then {
				if ([player, "ACE_HuntIR_monitor"] call BIS_fnc_hasItem) then {
					player removeItem "ACE_HuntIR_monitor";
				};
			};
			private _empMag = "FST_grenade_emp_mag";
			private _sonicMag = "IDA_grenade_Sonic_mag";
			private _detMag = "FST_grenade_Detonator_mag";
			player removeMagazines _empMag;
			player removeMagazines _sonicMag;
			player removeMagazines _detMag;
			for "_i" from 1 to 3 do {
				if (player canAddItemToVest _detMag) then {
					player addItemToVest _detMag;
				} else {
					if (player canAddItemToUniform _detMag) then {
						player addItemToUniform _detMag;
					} else {
						player addItemToBackpack _detMag;
					};
				};
			};

			{player addPrimaryWeaponItem _x;} forEach _weaponStuff;
			private _newMags = [_item] call CBA_fnc_compatibleMagazines;
			private _magType = if (count _newMags > 0) then {_newMags select 0} else {""};
			switch (_item) do {
				case "FST_DC15S": {
					private _curBP = backpack player;
					if (_curBP in ["FST_Backpack_Jumppack_STD_Ammo", "FST_Clone_Backpack_Invisible_STD"]) then {
						removeBackpack player;
						player addBackpack _curBP;
						for "_i" from 1 to 12 do { player addItemToBackpack "FST_blaster_cell_High_Blue"; };
						for "_i" from 1 to 18 do { player addItemToBackpack "FST_blaster_cell_Blue"; };
						for "_i" from 1 to 4 do {
							player addItemToBackpack "FST_blaster_cell_LE_Blue";
							player addItemToBackpack "FST_blaster_scatter_cell_DP23_Blue";
						};
						private _grenadeClass = "FST_grenade_Detonator_mag";
						private _grenadesCurrent = { _x == _grenadeClass } count magazines player;
						if (_grenadesCurrent < 6) then {
							for "_i" from 1 to (6 - _grenadesCurrent) do {
								if (player canAddItemToVest _grenadeClass) then {
									player addItemToVest _grenadeClass;
								} else {
									player addItemToUniform _grenadeClass;
								};
							};
						};
					};
					player addPrimaryWeaponItem "FST_blaster_cell_Blue";
					private _magCount = 16;
					for "_i" from 1 to _magCount do {
						if (player canAddItemToVest _magType) then {
							player addItemToVest _magType;
						} else {
							if (player canAddItemToBackpack _magType) then {
								player addItemToBackpack _magType;
							} else {
								player addItemToUniform _magType;
							};
						};
					};
					player addPrimaryWeaponItem "FST_Attachment_Optic_Holo_DC15";
				};

				case "FST_Westar_M5": {
					private _curBP = backpack player;
					if (_curBP in ["FST_Backpack_Jumppack_STD_Ammo", "FST_Clone_Backpack_Invisible_STD"]) then {
						removeBackpack player;
						player addBackpack _curBP;
						for "_i" from 1 to 12 do { player addItemToBackpack "FST_blaster_cell_High_Blue"; };
						for "_i" from 1 to 18 do { player addItemToBackpack "FST_blaster_cell_Blue"; };
						for "_i" from 1 to 4 do {
							player addItemToBackpack "FST_blaster_cell_LE_Blue";
							player addItemToBackpack "FST_blaster_scatter_cell_DP23_Blue";
						};
						private _grenadeClass = "FST_grenade_Detonator_mag";
						private _grenadesCurrent = { _x == _grenadeClass } count magazines player;
						if (_grenadesCurrent < 6) then {
							for "_i" from 1 to (6 - _grenadesCurrent) do {
								if (player canAddItemToVest _grenadeClass) then {
									player addItemToVest _grenadeClass;
								} else {
									player addItemToUniform _grenadeClass;
								};
							};
						};
					};
					player addPrimaryWeaponItem "FST_Scope_Westar_M5";
					player addPrimaryWeaponItem "FST_blaster_cell_Westar_Blue";
					for "_i" from 1 to 12 do {
						if (player canAddItemToVest "FST_blaster_cell_Westar_Blue") then {
							player addItemToVest "FST_blaster_cell_Westar_Blue";
						} else {
							player addItemToUniform "FST_blaster_cell_Westar_Blue";
						};
					};
				};

				case "FST_DC15A";
				case "FST_DC15C_F": {
					private _curBP = backpack player;
					if (_curBP in ["FST_Backpack_Jumppack_STD_Ammo", "FST_Clone_Backpack_Invisible_STD"]) then {
						removeBackpack player;
						player addBackpack _curBP;
						for "_i" from 1 to 12 do { player addItemToBackpack "FST_blaster_cell_High_Blue"; };
						for "_i" from 1 to 18 do { player addItemToBackpack "FST_blaster_cell_Blue"; };
						for "_i" from 1 to 4 do {
							player addItemToBackpack "FST_blaster_cell_LE_Blue";
							player addItemToBackpack "FST_blaster_scatter_cell_DP23_Blue";
						};
						private _grenadeClass = "FST_grenade_Detonator_mag";
						private _grenadesCurrent = { _x == _grenadeClass } count magazines player;
						if (_grenadesCurrent < 6) then {
							for "_i" from 1 to (6 - _grenadesCurrent) do {
								if (player canAddItemToVest _grenadeClass) then {
									player addItemToVest _grenadeClass;
								} else {
									player addItemToUniform _grenadeClass;
								};
							};
						};
					};
					player addPrimaryWeaponItem "FST_blaster_cell_High_Blue";
					for "_i" from 1 to 12 do {
						if (player canAddItemToVest _magType) then {
							player addItemToVest _magType;
						} else {
							player addItemToUniform _magType;
						};
					};
					player addPrimaryWeaponItem "FST_Attachment_Optic_Holo_DC15";
				};
				case "FST_DC15L_F": {
					removeBackpack player;
					player addBackpack "FST_Belt_Bag_15L";
					player addItemToBackpack "ACE_Tripod";
					private _magType = "FST_blaster_battery_DC15L_Blue";
					player addPrimaryWeaponItem "FST_blaster_battery_DC15L_Blue";
					for "_i" from 1 to 14 do {
						if (player canAddItemToBackpack _magType) then {
							player addItemToBackpack _magType;
						} else {
							player addItemToVest _magType;
						};
					};
					player addPrimaryWeaponItem "FST_Optic_DC15L";
				};

				case "FST_Valken38x": {
					removeBackpack player;
					player addBackpack "FST_Clone_backpack_Woodland";
					player addItemToBackpack "ACE_Tripod";
					private _magType = "FST_blaster_cell_Valken_Blue";
					player addPrimaryWeaponItem "FST_blaster_cell_Valken_Blue";
					for "_i" from 1 to 14 do {
						if (player canAddItemToBackpack _magType) then {
							player addItemToBackpack _magType;
						} else {
							player addItemToVest _magType;
						};
					};
					player addPrimaryWeaponItem "FST_optic_VK38X_1";
					player addPrimaryWeaponItem "3AS_Bipod_VK38X_f";
				};

				case "FST_Z6": {
					if ((player getVariable ["WBK_Kit_Name",""]) == "Howler") then {
						removeBackpack player;
						player addBackpack "FST_Backpack_Jumppack_Z6";
					} else {
						removeBackpack player;
						player addBackpack "FST_Belt_Bag_Z6";
					};
					player addPrimaryWeaponItem "FST_blaster_battery_Blue";
					player addItemToBackpack "ACE_Tripod";
					private _magType = "FST_blaster_battery_Blue";
					for "_i" from 1 to 6 do {
						if (player canAddItemToBackpack _magType) then {
							player addItemToBackpack _magType;
						} else {
							player addItemToVest _magType;
						};
					};
				};
				case "FST_DP23": {
					private _slugMag = "FST_thermal_slug_mag_Blue";
					private _scatterCell = "FST_blaster_scatter_cell_DP23_Blue";
					player addPrimaryWeaponItem "FST_blaster_scatter_cell_DP23_Blue";

					{
						private _mag = _x select 0;
						private _count = _x select 1;
						for "_i" from 1 to _count do {
							if (player canAddItemToVest _mag) then {
								player addItemToVest _mag;
							} else {
								if (player canAddItemToBackpack _mag) then {
									player addItemToBackpack _mag;
								} else {
									player addItemToUniform _mag;
								};
							};
						};
					} forEach [
						[_scatterCell, 16],
						[_slugMag, 4]
					];
					if ((player getVariable ["WBK_Kit_Name", ""]) == "Close Quarters Combatant") then {
						{
							private _grenade = _x;
							player removeMagazines _grenade;
							for "_i" from 1 to 5 do {
								if (player canAddItemToVest _grenade) then {
									player addItemToVest _grenade;
								} else {
									if (player canAddItemToUniform _grenade) then {
										player addItemToUniform _grenade;
									} else {
										player addItemToBackpack _grenade;
									};
								};
							};
						} forEach [
							"FST_grenade_emp_mag",
							"IDA_grenade_Sonic_mag",
							"FST_grenade_Detonator_mag"
						];
					};
				};
				case "FST_Westar_M5_UGL": {
					player addPrimaryWeaponItem "FST_blaster_cell_Westar_Blue";
					player addPrimaryWeaponItem "FST_Scope_Westar_M5";
					for "_i" from 1 to 12 do {
						if (player canAddItemToVest "FST_blaster_cell_Westar_Blue") then {
							player addItemToVest "FST_blaster_cell_Westar_Blue";
						} else {
							player addItemToUniform "FST_blaster_cell_Westar_Blue";
						};
					};

					for "_i" from 1 to 6 do { player removeItemFromBackpack "FST_Smoke_LauncherGrenade"; };
					for "_i" from 1 to 12 do { player removeItemFromBackpack "FST_HE_LauncherGrenade"; };
					for "_i" from 1 to 2 do { player removeItemFromBackpack "ACE_HuntIR_M203"; };
					for "_i" from 1 to 4 do { player removeItemFromBackpack "ACE_40mm_Flare_white"; };

					for "_i" from 1 to 6 do {
						if (player canAddItemToBackpack "FST_Smoke_LauncherGrenade") then {
							player addItemToBackpack "FST_Smoke_LauncherGrenade";
						} else {
							if (player canAddItemToVest "FST_Smoke_LauncherGrenade") then {
								player addItemToVest "FST_Smoke_LauncherGrenade";
							} else {
								player addItemToUniform "FST_Smoke_LauncherGrenade";
							};
						};
					};
					player addPrimaryWeaponItem "FST_HE_LauncherGrenade";
					for "_i" from 1 to 12 do {
						if (player canAddItemToBackpack "FST_HE_LauncherGrenade") then {
							player addItemToBackpack "FST_HE_LauncherGrenade";
						} else {
							if (player canAddItemToVest "FST_HE_LauncherGrenade") then {
								player addItemToVest "FST_HE_LauncherGrenade";
							} else {
								player addItemToUniform "FST_HE_LauncherGrenade";
							};
						};
					};

					for "_i" from 1 to 2 do {
						if (player canAddItemToBackpack "ACE_HuntIR_M203") then {
							player addItemToBackpack "ACE_HuntIR_M203";
						} else {
							if (player canAddItemToVest "ACE_HuntIR_M203") then {
								player addItemToVest "ACE_HuntIR_M203";
							} else {
								player addItemToUniform "ACE_HuntIR_M203";
							};
						};
					};

					for "_i" from 1 to 4 do {
						if (player canAddItemToBackpack "ACE_40mm_Flare_white") then {
							player addItemToBackpack "ACE_40mm_Flare_white";
						} else {
							if (player canAddItemToVest "ACE_40mm_Flare_white") then {
								player addItemToVest "ACE_40mm_Flare_white";
							} else {
								player addItemToUniform "ACE_40mm_Flare_white";
							};
						};
					};
					{
						private _smokeMag = _x;
						if (player canAddItemToBackpack _smokeMag) then {
							player addItemToBackpack _smokeMag;
						} else {
							if (player canAddItemToVest _smokeMag) then {
								player addItemToVest _smokeMag;
							} else {
								player addItemToUniform _smokeMag;
							};
						};
					} forEach [
						"FST_SmokeBlue_LauncherGrenade",
						"FST_SmokeGreen_LauncherGrenade",
						"FST_SmokeRed_LauncherGrenade"
					];
					if !([player, "ACE_HuntIR_monitor"] call BIS_fnc_hasItem) then {
						player addItem "ACE_HuntIR_monitor";
					};
				};

				case "FST_DC15A_ugl": {
					player addPrimaryWeaponItem "FST_blaster_cell_High_Blue";
					for "_i" from 1 to 12 do {
						if (player canAddItemToVest _magType) then {
							player addItemToVest _magType;
						} else {
							player addItemToUniform _magType;
						};
					};

					for "_i" from 1 to 6 do { player removeItemFromBackpack "FST_Smoke_LauncherGrenade"; };
					for "_i" from 1 to 12 do { player removeItemFromBackpack "FST_HE_LauncherGrenade"; };
					for "_i" from 1 to 2 do { player removeItemFromBackpack "ACE_HuntIR_M203"; };
					for "_i" from 1 to 4 do { player removeItemFromBackpack "ACE_40mm_Flare_white"; };

					for "_i" from 1 to 6 do {
						if (player canAddItemToBackpack "FST_Smoke_LauncherGrenade") then {
							player addItemToBackpack "FST_Smoke_LauncherGrenade";
						} else {
							if (player canAddItemToVest "FST_Smoke_LauncherGrenade") then {
								player addItemToVest "FST_Smoke_LauncherGrenade";
							} else {
								player addItemToUniform "FST_Smoke_LauncherGrenade";
							};
						};
					};
					player addPrimaryWeaponItem "FST_HE_LauncherGrenade";
					for "_i" from 1 to 12 do {
						if (player canAddItemToBackpack "FST_HE_LauncherGrenade") then {
							player addItemToBackpack "FST_HE_LauncherGrenade";
						} else {
							if (player canAddItemToVest "FST_HE_LauncherGrenade") then {
								player addItemToVest "FST_HE_LauncherGrenade";
							} else {
								player addItemToUniform "FST_HE_LauncherGrenade";
							};
						};
					};

					for "_i" from 1 to 2 do {
						if (player canAddItemToBackpack "ACE_HuntIR_M203") then {
							player addItemToBackpack "ACE_HuntIR_M203";
						} else {
							if (player canAddItemToVest "ACE_HuntIR_M203") then {
								player addItemToVest "ACE_HuntIR_M203";
							} else {
								player addItemToUniform "ACE_HuntIR_M203";
							};
						};
					};

					for "_i" from 1 to 4 do {
						if (player canAddItemToBackpack "ACE_40mm_Flare_white") then {
							player addItemToBackpack "ACE_40mm_Flare_white";
						} else {
							if (player canAddItemToVest "ACE_40mm_Flare_white") then {
								player addItemToVest "ACE_40mm_Flare_white";
							} else {
								player addItemToUniform "ACE_40mm_Flare_white";
							};
						};
					};
					{
						private _smokeMag = _x;
						if (player canAddItemToBackpack _smokeMag) then {
							player addItemToBackpack _smokeMag;
						} else {
							if (player canAddItemToVest _smokeMag) then {
								player addItemToVest _smokeMag;
							} else {
								player addItemToUniform _smokeMag;
							};
						};
					} forEach [
						"FST_SmokeBlue_LauncherGrenade",
						"FST_SmokeGreen_LauncherGrenade",
						"FST_SmokeRed_LauncherGrenade"
					];
					if !([player, "ACE_HuntIR_monitor"] call BIS_fnc_hasItem) then {
						player addItem "ACE_HuntIR_monitor";
					};
				};

				case "FST_DC15S_UGL": {
					player addPrimaryWeaponItem "FST_blaster_cell_Blue";
					for "_i" from 1 to 14 do {
						if (player canAddItemToVest _magType) then {
							player addItemToVest _magType;
						} else {
							player addItemToUniform _magType;
						};
					};

					for "_i" from 1 to 6 do { player removeItemFromBackpack "FST_Smoke_LauncherGrenade"; };
					for "_i" from 1 to 13 do { player removeItemFromBackpack "FST_HE_LauncherGrenade"; };
					for "_i" from 1 to 2 do { player removeItemFromBackpack "ACE_HuntIR_M203"; };
					for "_i" from 1 to 4 do { player removeItemFromBackpack "ACE_40mm_Flare_white"; };

					for "_i" from 1 to 6 do {
						if (player canAddItemToBackpack "FST_Smoke_LauncherGrenade") then {
							player addItemToBackpack "FST_Smoke_LauncherGrenade";
						} else {
							if (player canAddItemToVest "FST_Smoke_LauncherGrenade") then {
								player addItemToVest "FST_Smoke_LauncherGrenade";
							} else {
								player addItemToUniform "FST_Smoke_LauncherGrenade";
							};
						};
					};
					player addPrimaryWeaponItem "FST_HE_LauncherGrenade";
					for "_i" from 1 to 12 do {
						if (player canAddItemToBackpack "FST_HE_LauncherGrenade") then {
							player addItemToBackpack "FST_HE_LauncherGrenade";
						} else {
							if (player canAddItemToVest "FST_HE_LauncherGrenade") then {
								player addItemToVest "FST_HE_LauncherGrenade";
							} else {
								player addItemToUniform "FST_HE_LauncherGrenade";
							};
						};
					};

					for "_i" from 1 to 2 do {
						if (player canAddItemToBackpack "ACE_HuntIR_M203") then {
							player addItemToBackpack "ACE_HuntIR_M203";
						} else {
							if (player canAddItemToVest "ACE_HuntIR_M203") then {
								player addItemToVest "ACE_HuntIR_M203";
							} else {
								player addItemToUniform "ACE_HuntIR_M203";
							};
						};
					};

					for "_i" from 1 to 4 do {
						if (player canAddItemToBackpack "ACE_40mm_Flare_white") then {
							player addItemToBackpack "ACE_40mm_Flare_white";
						} else {
							if (player canAddItemToVest "ACE_40mm_Flare_white") then {
								player addItemToVest "ACE_40mm_Flare_white";
							} else {
								player addItemToUniform "ACE_40mm_Flare_white";
							};
						};
					};
					{
						private _smokeMag = _x;
						if (player canAddItemToBackpack _smokeMag) then {
							player addItemToBackpack _smokeMag;
						} else {
							if (player canAddItemToVest _smokeMag) then {
								player addItemToVest _smokeMag;
							} else {
								player addItemToUniform _smokeMag;
							};
						};
					} forEach [
						"FST_SmokeBlue_LauncherGrenade",
						"FST_SmokeGreen_LauncherGrenade",
						"FST_SmokeRed_LauncherGrenade"
					];
					if !([player, "ACE_HuntIR_monitor"] call BIS_fnc_hasItem) then {
						player addItem "ACE_HuntIR_monitor";
					};
				};
				case "FST_T15": {
					player addPrimaryWeaponItem "FST_Optic_MRCO_T15";
					player addPrimaryWeaponItem "3as_bipod_vk38x_f";
					removeBackpack player;
					private _bpClass = "FST_Clone_Backpack_RifleAT";
					if (toLower (player getVariable ["WBK_Kit_Category",""]) isEqualTo "ranger") then {
						private _camo = missionNamespace getVariable ["FST_LastCamoPreset","Woodland"];
						private _cand = format ["FST_Clone_backpack_%1", _camo];
						if (isClass (configFile >> "CfgVehicles" >> _cand)) then { _bpClass = _cand; };
					};
					player addBackpack _bpClass;
					player addPrimaryWeaponItem "FST_thermal_coil_LP_Blue";
					player addPrimaryWeaponItem "FST_thermal_coil_T15_Blue";
					for "_i" from 1 to 7 do {
						if (player canAddItemToVest "FST_thermal_coil_LP_Blue") then {
							player addItemToVest "FST_thermal_coil_LP_Blue";
						} else {
							if (player canAddItemToBackpack "FST_thermal_coil_LP_Blue") then {
								player addItemToBackpack "FST_thermal_coil_LP_Blue";
							} else {
								player addItemToUniform "FST_thermal_coil_LP_Blue";
							};
						};
					};
					for "_i" from 1 to 5 do {
						if (player canAddItemToVest "FST_thermal_coil_T15_Blue") then {
							player addItemToVest "FST_thermal_coil_T15_Blue";
						} else {
							if (player canAddItemToBackpack "FST_thermal_coil_T15_Blue") then {
								player addItemToBackpack "FST_thermal_coil_T15_Blue";
							} else {
								player addItemToUniform "FST_thermal_coil_T15_Blue";
							};
						};
					};
				};
				case "FST_DC15LE": {
					player addPrimaryWeaponItem "FST_blaster_cell_LE_Blue";
					for "_i" from 1 to 12 do {
						if (player canAddItemToVest "FST_blaster_cell_LE_Blue") then {
							player addItemToVest "FST_blaster_cell_LE_Blue";
						} else {
							if (player canAddItemToBackpack "FST_blaster_cell_LE_Blue") then {
								player addItemToBackpack "FST_blaster_cell_LE_Blue";
							} else {
								player addItemToUniform "FST_blaster_cell_LE_Blue";
							};
						};
					};
				};
				default {
					for "_i" from 1 to (_mags findIf {_x == _magType} + 1) do {
						if (player canAddItemToVest _magType) then {
							player addItemToVest _magType;
						} else {
							player addItemToUniform _magType;
						};
					};
					if (_backpackClass != "") then {
						removeBackpack player;
						player addBackpack _backpackClass;
						{
							for "_i" from 1 to (_x select 1) do {
								player addItemToBackpack (_x select 0);
							};
						} forEach _backpackInventory;
					};
				};
			};
		};

		case (_item isKindOf ["PistolCore", configFile >> "CfgWeapons"]): {
		    playSoundUI [selectRandom ["41st_KitMenu\sounds\select_pistol_1.ogg","41st_KitMenu\sounds\select_pistol_2.ogg"], 0.85, 1];
		    _weaponStuff = handgunItems player;
		    _mags = [handgunweapon player] call CBA_fnc_compatibleMagazines;
			_availableMagCount = {_x in _mags} count magazines player;
			{player removeMagazines _x;} forEach _mags;
			player removeWeapon handgunweapon player;
			_weap = [player, _item, _availableMagCount + 1] call BIS_fnc_addWeapon;
            player selectWeapon _weap;
			{player addHandgunItem _x;} forEach _weaponStuff;
		};
		case ( isClass (configFile >> "CfgGlasses" >> _item)): {
		    playSoundUI [selectRandom ["41st_KitMenu\sounds\select_generic_1.ogg","41st_KitMenu\sounds\select_generic_2.ogg","41st_KitMenu\sounds\select_generic_3.ogg","41st_KitMenu\sounds\select_generic_4.ogg","41st_KitMenu\sounds\select_generic_5.ogg","41st_KitMenu\sounds\select_generic_6.ogg"], 0.85, 1];
			removeGoggles player;
			player addGoggles _item;
		};
		default {
			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_generic_1.ogg","41st_KitMenu\sounds\select_generic_2.ogg","41st_KitMenu\sounds\select_generic_3.ogg","41st_KitMenu\sounds\select_generic_4.ogg","41st_KitMenu\sounds\select_generic_5.ogg","41st_KitMenu\sounds\select_generic_6.ogg"], 0.85, 1];
			player addItem _item;
		};
   };
call WBK_UpdatePlayerKitOnMenu;
};


Wbk_AssignKit = {
params ["_control", "_index"];
private ["_lbData", "_itemClass", "_itemCount"];
_lbData = call compile (lbData [ctrlIDC _control, _index]);
_kit = _lbData select 0;
_typeOfKit = _lbData select 1;
private _kitCategory = if ((count _lbData) > 4) then { _lbData select 4 } else { "" };
player setVariable ["WBK_Kit_Category", toLower _kitCategory, true];
if (_typeOfKit == "CANTTAKEKIT") exitWith {
	playSoundUI ["41st_KitMenu\sounds\select_cantTake.ogg", 0.35, 1];
};
_aditionalGear = _lbData select 2;
_codeExecute = _lbData select 3;
_insignia = [player] call BIS_fnc_getUnitInsignia;
playSoundUI ["41st_KitMenu\sounds\select_default.ogg", 0.3, 1];
player setUnitLoadout _kit;
private _uniformToSet = "";
private _headgearToSet = "";
private _vestToSet = "";
private _backpackToSet = "";
private _nvgToSet="";
private _name = name player;

switch (true) do {
	case (_name find "CXC-" == 0): {
        _uniformToSet  = "FST_Uniform_SCT";
        _headgearToSet = "FST_Pilot_P1_Helmet";
    };
    case (_name find "CX-" == 0): {
        _uniformToSet  = "FST_Uniform_VCT";
        _headgearToSet = "FST_Pilot_P1_Helmet";
    };
    case (_name find "CXV-" == 0): {
        _uniformToSet  = "FST_Uniform_CLC";
        _headgearToSet = "FST_Pilot_P1_Helmet";
    };
    case (_name find "CXP-" == 0): {
        _uniformToSet  = "FST_Uniform_CPL";
        _headgearToSet = "FST_Pilot_P1_Helmet";
    };
    case (_name find "CXS-" == 0): {
        _uniformToSet  = "FST_Uniform_CS";
        _headgearToSet = "FST_Pilot_P1_Helmet";
    };
    case (_name find "CXL-" == 0): {
        _uniformToSet  = "FST_Uniform_CL";
        _headgearToSet = "FST_Pilot_P1_Helmet";
    };
    case (_name find "CXR" == 0): {
        _uniformToSet  = "FST_Uniform_CL";
        _headgearToSet = "FST_Pilot_P1_Helmet";
    };
	/*
	case (_name find ("CC-1861 " + '"' + "Annex" + '"') == 0): {
		_uniformToSet   = "FST_Uniform_Annex";
		_headgearToSet  = "FST_P2_Helmet_Annex";
		_vestToSet      = "FST_pauldron_kama";
		_backpackToSet  = "FST_Clone_LR_attachment";
		_nvgToSet       = "FST_Visor_Annex";
	};
	case (_name find ("CC-1227 " + '"' + "Cardinal" + '"') == 0): {
		_uniformToSet   = "FST_Uniform_Cardinal_Dirty";
		_headgearToSet  = "FST_P2_Helmet_Cardinal_V3";
		_vestToSet      = "FST_pauldron_kama";
		_backpackToSet  = "FST_Clone_LR_attachment";
		_nvgToSet       = "FST_Visor_Cardinal";
	};
	case (_name find ("BC-4973 " + '"' + "Merrik" + '"') == 0): {
		_uniformToSet   = "FST_Uniform_Merrik_BC";
		_headgearToSet  = "FST_BC_Helmet_Merrik";
		_vestToSet      = "FST_CloneVestMerrik";
		_backpackToSet  = "FST_Clone_LR_attachment";
		_nvgToSet       = "FST_Marshal_Commander_Visor";
	};
	case (_name find "ARC-" == 0): {
        _uniformToSet   = "FST_Uniform_CLC";
        _headgearToSet  = "FST_P2_ARC_Helmet";
        _vestToSet      = "FST_CloneVestARC";
        _backpackToSet  = "FST_Clone_Backpack_ARC";
		_nvgToSet       = "FST_Antenna";
    };
    case (_name find "CR-" == 0): {
        _uniformToSet = "FST_Uniform_Recruit";
        _headgearToSet = "FST_P2_Helmet_Recruit";
    };
	case (_name find "CT-" == 0
			|| _name find "ENS-" == 0
			|| _name find "LTJG-" == 0
			|| _name find "LT-" == 0
			|| _name find "LCDR-" == 0
			|| _name find "CDR-" == 0
			|| _name find "CAPT-" == 0): { 
			if (_typeOfKit == "Medic") then {
				_uniformToSet = "FST_Trooper_Medic";
			} else {
				_uniformToSet = "FST_Trooper_Uniform";
			};
			if (_typeOfKit == "Engineer") then {
				_uniformToSet = "FST_Uniform_EOD";
			};
		};
    case (_name find "SCT-" == 0): {
        if (_typeOfKit == "Medic") then {
            _uniformToSet = "FST_Uniform_SCT_Medic";
        } else {
            _uniformToSet = "FST_Uniform_SCT";
        };
        if (_typeOfKit == "Engineer") then {
            _uniformToSet = "FST_Uniform_EOD";
        };
    };
    case (_name find "VCT-" == 0
       || _name find "CLC-" == 0
       || _name find "CPL-" == 0
       || _name find "CS-" == 0
       || _name find "CSS-" == 0
       || _name find "CL-" == 0): {
        if (_typeOfKit == "Medic") then {
            _uniformToSet = "FST_Uniform_VCT_Medic";
        } else {
            if (_name find "VCT-" == 0) then { _uniformToSet = "FST_Uniform_VCT"; };
            if (_name find "CLC-" == 0) then { _uniformToSet = "FST_Uniform_CLC"; };
            if (_name find "CPL-" == 0) then { _uniformToSet = "FST_Uniform_CPL"; };
            if (_name find "CS-" == 0)  then { _uniformToSet = "FST_Uniform_CS"; };
            if (_name find "CSS-" == 0) then { _uniformToSet = "FST_Uniform_CSS"; };
            if (_name find "CL-" == 0)  then { _uniformToSet = "FST_Uniform_CL"; };
        };
        if (_typeOfKit == "Engineer") then {
            _uniformToSet = "FST_Uniform_EOD";
        };
    };
	*/
	default {
        _uniformToSet = "FST_Uniform_Recruit";
        _headgearToSet = "FST_P2_Helmet_Recruit";
    };
};

if (_uniformToSet != "" && (uniform player == "FST_Trooper_Uniform")) then {
    private _uniformItems = uniformItems player;
    removeUniform player;
    player forceAddUniform _uniformToSet;
    { player addItemToUniform _x; } forEach _uniformItems;
    if (_headgearToSet != "") then {
        removeHeadgear player;
        player addHeadgear _headgearToSet;
    };
};

if (_vestToSet != "" && {vest player != _vestToSet}) then {
    private _vestItems = vestItems player;
    removeVest player;
    player addVest _vestToSet;
    { player addItemToVest _x; } forEach _vestItems;
};

if (_backpackToSet != "" && {backpack player != _backpackToSet}) then {
    private _backpackItems = backpackItems player;
    removeBackpack player;
    player addBackpack _backpackToSet;
    { player addItemToBackpack _x; } forEach _backpackItems;
};

if (!isNil "_nvgToSet" && {_nvgToSet != ""}) then {
    if (hmd player == _nvgToSet) then {
        player unlinkItem _nvgToSet;
    } else {
        if !(_nvgToSet in (assignedItems player)) then {
            player linkItem _nvgToSet;
        } else {
            player linkItem _nvgToSet;
        };
    };
};

player setVariable ["WBK_Kit_Name",_typeOfKit,true];
[player,_kit,_typeOfKit,_aditionalGear] spawn _codeExecute;
player setVariable ["BIS_fnc_setUnitInsignia_class", nil];
[player, _insignia] call BIS_fnc_setUnitInsignia;
player setUnitTrait ["Medic", false];
player setUnitTrait ["engineer", false];
player setUnitTrait ["explosiveSpecialist", false];
switch (_typeOfKit) do {
	case "Medic": {
		player setUnitTrait ["Medic", true];
	};
	case "Platoon Medic": {
		player setUnitTrait ["Medic", true];
	};
		case "Squad Leader": {
		player setUnitTrait ["Medic", true];
	};
		case "Squad Leader ": {
		player setUnitTrait ["Medic", true];
	};
	case "Platoon Sergeant": {
		player setUnitTrait ["Medic", true];
		player setUnitTrait ["engineer", true];
		player setUnitTrait ["explosiveSpecialist", true];
	};
	case "Platoon Commander": {
		player setUnitTrait ["Medic", true];
		player setUnitTrait ["engineer", true];
		player setUnitTrait ["explosiveSpecialist", true];
	};
	case "Engineer": {
		player setUnitTrait ["engineer", true];
		player setUnitTrait ["explosiveSpecialist", true];
	};
	case "Pilot": {
		player setUnitTrait ["Medic", true];
		player setUnitTrait ["engineer", true];
	};
	case "Crew Chief": {
		player setUnitTrait ["Medic", true];
		player setUnitTrait ["engineer", true];
	};
	case "Crewman": {
	player setUnitTrait ["engineer", true];
	};
	case "Crewman Medic": {
	player setUnitTrait ["engineer", true];
	player setUnitTrait ["Medic", true];
	};
	default {};
};
call WBK_UpdatePlayerKitOnMenu;
player remoteExecCall ['FST_KitMenuUpdateKits',0];
(player getVariable "WBK_ClassHud") ctrlSetStructuredText parseText format["<t size='1.5' align='center' font='PuristaSemibold'>%1</t>", player getVariable "WBK_Kit_Name"];
WBK_KitSystem_PlayerTookKit = true;
_display = findDisplay 2000;
_listBox_AditionalStuff = _display displayCtrl 1731;
_listBox_AditionalStuff lbSetColor [0, [0,1,0,1]];
lbClear 1731;
if (count _aditionalGear > 0) then {
	_weapons = [];
	_attachments = [];
	_equipment = [];
	_backpacks = [];
	_glasses = [];
	_magazinesAndItems = [];
	_patches = [];
	{
	if !(_x == "") then {
		switch true do {
			case ( isClass (configFile >> "CfgUnitInsignia" >> _x)): {
				_patches pushBack _x;
			};
			case ((getNumber(configFile >> "CfgWeapons" >> _x >> 'ItemInfo' >> 'type' ) isEqualTo 302 || getNumber(configFile >> "CfgWeapons" >> _x >> 'ItemInfo' >> 'type' ) isEqualTo 301 || getNumber(configFile >> "CfgWeapons" >> _x >> 'ItemInfo' >> 'type' ) isEqualTo 201 || getNumber(configFile >> "CfgWeapons" >> _x >> 'ItemInfo' >> 'type' ) isEqualTo 101)): {
				_attachments pushBack _x;
			};
			case ((getNumber(configFile >> "CfgWeapons" >> _x >> 'ItemInfo' >> 'type' ) isEqualTo 605) || (getNumber(configFile >> "CfgWeapons" >> _x >> 'ItemInfo' >> 'type' ) isEqualTo 801) || (getNumber(configFile >> "CfgWeapons" >> _x >> 'ItemInfo' >> 'type' ) isEqualTo 701)): {
				_equipment pushBack _x;
			};
			case ( isClass (configFile >> "CfgVehicles" >> _x)): {
				_backpacks pushBack _x;
			};
			case ( isClass (configFile >> "CfgMagazines" >> _x)): {
				_magazinesAndItems pushBack _x;
			};
			case ( isClass (configFile >> "CfgGlasses" >> _x)): {
				_glasses pushBack _x;
			};
			case ((_x isKindOf ["LauncherCore", configFile >> "CfgWeapons"]) || (_x isKindOf ["PistolCore", configFile >> "CfgWeapons"]) || (_x isKindOf ["RifleCore", configFile >> "CfgWeapons"])): {
				_weapons pushBack _x;
			};
			default {
				_magazinesAndItems pushBack _x;
			};
	   };
	};
	} forEach _aditionalGear;
	_primaryWeapons = [];
	_secondaryWeapons = [];
	_launchers = [];

	{
	if (_x isKindOf ["Rifle", configFile >> "CfgWeapons"]) then {
		_primaryWeapons pushBack _x;
	} else {
		if (_x isKindOf ["Pistol", configFile >> "CfgWeapons"]) then {
			_secondaryWeapons pushBack _x;
		} else {
			if (_x isKindOf ["Launcher", configFile >> "CfgWeapons"]) then {
				_launchers pushBack _x;
			};
		};
	};
	} forEach _weapons;

	private _CQBKits = ["Close Quarters Combatant"];
	private _typeClean = toLower (trim _typeOfKit);
	if (_CQBKits findIf {toLower _x == _typeClean} != -1) then {
		_primaryWeapons pushBack "[41st]_dc15s_cqb";
	};
		if (count _primaryWeapons > 0) then {
			_pic = "a3\ui_f\data\GUI\Cfg\Hints\Rifle_ca.paa";
			_index = _listBox_AditionalStuff lbAdd " PRIMARY WEAPONS";
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			_listBox_AditionalStuff lbSetData [_index, "['any']"];
			{
				if (_x == "[41st]_dc15s_cqb") then {
					_pic = getText (configFile >> "CfgWeapons" >> "FST_DC15S" >> "picture");
					_index = _listBox_AditionalStuff lbAdd "[41st] DC-15S carbine (CQB)";
					_listBox_AditionalStuff lbSetPicture [_index, _pic];
					_listBox_AditionalStuff lbSetData [_index, "['FST_DC15S','CQB_MAGIC']"];
					_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
				} else {
					_pic = getText (configFile >> "CfgWeapons" >> _x >> "picture");
					_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgWeapons" >> _x >> "displayname");
					_listBox_AditionalStuff lbSetPicture [_index, _pic];
					_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
					_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
				};
			} forEach _primaryWeapons;
				if (_typeOfKit == "Pilot") then {
					_pic = "\a3\ui_f\data\igui\cfg\actions\delete_ca.paa";
					_index = _listBox_AditionalStuff lbAdd "REMOVE PRIMARY WEAPON";
					_listBox_AditionalStuff lbSetPicture [_index, _pic];
					_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
					_listBox_AditionalStuff lbSetData [_index, "['REMOVE_PRIMARY','PILOT_REMOVE']"];
				};
		};

		if (count _secondaryWeapons > 0) then {
			_pic = "";
			_index = _listBox_AditionalStuff lbAdd " ";
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];

			_pic = "a3\ui_f\data\GUI\Cfg\Hints\handgun_ca.paa";
			_index = _listBox_AditionalStuff lbAdd " SECONDARY WEAPONS";
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			_listBox_AditionalStuff lbSetData [_index, "['any']"];
			{
				_pic = getText (configFile >> "CfgWeapons" >> _x >> "picture");
				_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgWeapons" >> _x >> "displayname");
				_listBox_AditionalStuff lbSetPicture [_index, _pic];
				_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
				_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			} forEach _secondaryWeapons;
		};

		if (count _launchers > 0) then {
			_pic = "";
			_index = _listBox_AditionalStuff lbAdd " ";
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];

			_pic = "a3\ui_f\data\GUI\Cfg\Hints\launcher_ca.paa";
			_index = _listBox_AditionalStuff lbAdd " LAUNCHERS";
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			_listBox_AditionalStuff lbSetData [_index, "['any']"];
			{
				_pic = getText (configFile >> "CfgWeapons" >> _x >> "picture");
				_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgWeapons" >> _x >> "displayname");
				_listBox_AditionalStuff lbSetPicture [_index, _pic];
				_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
				_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			} forEach _launchers;
		};
		if (count _attachments > 0) then {
			_pic = "";
			_index = _listBox_AditionalStuff lbAdd " ";
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
			
			_pic = "a3\ui_f\data\GUI\Cfg\Hints\Optics_ca.paa";
			_index = _listBox_AditionalStuff lbAdd " ATTACHMENTS";
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
			{
				_pic = getText (configFile >> "CfgWeapons" >> _x >> "picture");
				_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgWeapons" >> _x >> "displayname");
				_listBox_AditionalStuff lbSetPicture [_index, _pic];
				_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
				_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			} forEach _attachments;
		};
		if (count _equipment > 0) then {
			_pic = "";
			_index = _listBox_AditionalStuff lbAdd " ";
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
			
			_pic = "a3\ui_f\data\GUI\Cfg\Hints\Stamina_CA.paa";
			_index = _listBox_AditionalStuff lbAdd " EQUIPMENT";
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
			{
				_pic = getText (configFile >> "CfgWeapons" >> _x >> "picture");
				_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgWeapons" >> _x >> "displayname");
				_listBox_AditionalStuff lbSetPicture [_index, _pic];
				_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
				_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			} forEach _equipment;
		};
		if (count _backpacks > 0) then {
			_pic = "";
			_index = _listBox_AditionalStuff lbAdd " ";
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
			
			_pic = "a3\ui_f\data\GUI\Cfg\Hints\Gear_ca.paa";
			_index = _listBox_AditionalStuff lbAdd " BACKPACKS";
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
			{
				_pic = getText (configFile >> "CfgVehicles" >> _x >> "picture");
				_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgVehicles" >> _x >> "displayname");
				_listBox_AditionalStuff lbSetPicture [_index, _pic];
				_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
				_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			} forEach _backpacks;
		};
		if (count _glasses > 0) then {
			_pic = "";
			_index = _listBox_AditionalStuff lbAdd " ";
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
			
			_pic = "a3\ui_f\data\GUI\Cfg\Hints\Pheripheal_vision_ca.paa";
			_index = _listBox_AditionalStuff lbAdd " FACEWEAR";
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
			{
				_pic = getText (configFile >> "CfgGlasses" >> _x >> "picture");
				_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgGlasses" >> _x >> "displayname");
				_listBox_AditionalStuff lbSetPicture [_index, _pic];
				_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
				_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			} forEach _glasses;
		};
		private _allowedKits = [
			"Rifleman","Ammo Bearer","Engineer","Medic","Grenadier","Close Quarters Combatant",
			"Squad Leader","RTO","Anti Tank","Squad Leader ","Ammo Bearer ","Emplaced Weapon",
			"Pilot","Crew Chief","Crewman","Howler","Platoon RTO","Platoon Medic",
			"Platoon Sergeant","Platoon Commander","Crewman Medic","Platoon RTO (UAV)"
		];
		private _canShowStuns = _typeOfKit in _allowedKits;

		if ((count _magazinesAndItems > 0) || _canShowStuns) then {
			_pic = "";
			_index = _listBox_AditionalStuff lbAdd " ";
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			_listBox_AditionalStuff lbSetData [_index, "['any']"];
			_pic = "a3\ui_f\data\GUI\Cfg\Hints\Reload_ca.paa";
			_index = _listBox_AditionalStuff lbAdd " MAGAZINES AND ITEMS";
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			_listBox_AditionalStuff lbSetData [_index, "['any']"];
			if (count _magazinesAndItems > 0) then {
				{
					if (isClass (configFile >> "CfgMagazines" >> _x)) then {
						_pic = getText (configFile >> "CfgMagazines" >> _x >> "picture");
						_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgMagazines" >> _x >> "displayname");
						_listBox_AditionalStuff lbSetPicture [_index, _pic];
						_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
						_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
					} else {
						_pic = getText (configFile >> "CfgWeapons" >> _x >> "picture");
						_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgWeapons" >> _x >> "displayname");
						_listBox_AditionalStuff lbSetPicture [_index, _pic];
						_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
						_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
					};
				} forEach _magazinesAndItems;
			};
			if (_canShowStuns) then {
				private _staticClass = "JLTS_stun_mag_long";
				if (isClass (configFile >> "CfgMagazines" >> _staticClass)) then {
					private _staticName = "5 x Stun mags";
					private _staticIcon = getText (configFile >> "CfgMagazines" >> _staticClass >> "picture");
					private _indexStatic = _listBox_AditionalStuff lbAdd _staticName;
					_listBox_AditionalStuff lbSetPicture [_indexStatic, _staticIcon];
					_listBox_AditionalStuff lbSetData [_indexStatic, "['JLTS_STATIC_OPTION','STATIC_MAGIC']"];
					_listBox_AditionalStuff lbSetPictureColor [_indexStatic, [1, 1, 1, 1]];
				};
			};
		};
		if (count _patches > 0) then {
			_pic = "";
			_index = _listBox_AditionalStuff lbAdd " ";
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
			
			_pic = "a3\ui_f\data\GUI\Cfg\Hints\UnitType_CA.paa";
			_index = _listBox_AditionalStuff lbAdd " PATCHES";
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
			{
				_pic = getText (configFile >> "CfgUnitInsignia" >> _x >> "texture");
				_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgUnitInsignia" >> _x >> "displayname");
				_listBox_AditionalStuff lbSetPicture [_index, _pic];
				_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
				_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			} forEach _patches;
		};
}else{
_pic = "";
_index = _listBox_AditionalStuff lbAdd "NONE";
_listBox_AditionalStuff lbSetPicture [_index, _pic];
_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
};
//backpacks start
if (_typeOfKit == "Ammo Bearer" || _typeOfKit == "Ammo Bearer ") then {
	private _backpacks = [];
	if (_typeOfKit == "Ammo Bearer ") then {
		// Airborne version
		_backpacks = [
			["FST_Backpack_Jumppack_15L_Ammo", "10x DC15L Battery"],
			["FST_Backpack_Jumppack_STD_Ammo", "Standard Ammo + 3x Detonators"],
			["FST_Backpack_Jumppack_RifleAT_Ammo", "2x LP Coil + 4x T15 Coil"]
		];
	} else {
		// Regular version
		_backpacks = [
			["FST_Clone_Backpack_Invisible_15L", "10x DC15L Battery"],
			["FST_Clone_Backpack_Invisible_RPS", "3x RPS6 + 1x HE Rocket"],
			["FST_Clone_Backpack_Invisible_Z6", "7x Z6 Battery"],
			["FST_Clone_Backpack_Invisible_STD", "Standard Ammo + 3x Detonators"],
			["FST_Clone_Backpack_Invisible_RifleAT", "2x LP Coil + 4x T15 Coil"],
			["FST_Clone_Backpack_Invisible_PLX", "3x PLX Rockets"]
		];
	};

	private _listBox_AditionalStuff = (findDisplay 2000) displayCtrl 1731;

	private _indexSpacer = _listBox_AditionalStuff lbAdd " ";
	_listBox_AditionalStuff lbSetData [_indexSpacer, "['any']"];

	private _indexHeader = _listBox_AditionalStuff lbAdd " AMMO BACKPACKS";
	_listBox_AditionalStuff lbSetPicture [_indexHeader, "a3\ui_f\data\GUI\Cfg\Hints\Gear_ca.paa"];
	_listBox_AditionalStuff lbSetData [_indexHeader, "['any']"];

	// Add each backpack
	{
		private _class = _x select 0;
		private _desc = _x select 1;

		private _pic = getText (configFile >> "CfgVehicles" >> _class >> "picture");
		private _disp = getText (configFile >> "CfgVehicles" >> _class >> "displayName");

		private _text = switch (_class) do {
			case "FST_Clone_Backpack_Invisible_15L";
			case "FST_Backpack_Jumppack_15L_Ammo": { "DC15L Pack" };
			case "FST_Clone_Backpack_Invisible_RPS": { "RPS6 Pack" };
			case "FST_Clone_Backpack_Invisible_Z6": { "Z6 Pack" };
			case "FST_Clone_Backpack_Invisible_STD";
			case "FST_Backpack_Jumppack_STD_Ammo": { "Standard Ammo Pack" };
			case "FST_Clone_Backpack_Invisible_RifleAT";
			case "FST_Backpack_Jumppack_RifleAT_Ammo": { "Rifle AT Pack" };
			case "FST_Clone_Backpack_Invisible_PLX": { "PLX Pack" };
			default { _disp };
		};
		private _index = _listBox_AditionalStuff lbAdd _text;

		_listBox_AditionalStuff lbSetPicture [_index, _pic];
		_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _class]];
		_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
	} forEach _backpacks;
};

if (_typeOfKit == "Howler") then {
    private _backpacks = [
        ["FST_Backpack_Jumppack_Z6_Ammo", "7x Z6 Battery"],
        ["FST_Backpack_Jumppack_PLX_Ammo", "3x PLX Rockets"],
        ["FST_Backpack_Jumppack_RPS_Ammo", "3x RPS6 + 1x HE Rocket"]
    ];

    private _listBox_AditionalStuff = (findDisplay 2000) displayCtrl 1731;

    private _indexSpacer = _listBox_AditionalStuff lbAdd " ";
    _listBox_AditionalStuff lbSetData [_indexSpacer, "['any']"];

    private _indexHeader = _listBox_AditionalStuff lbAdd " AMMO BACKPACKS";
    _listBox_AditionalStuff lbSetPicture [_indexHeader, "a3\ui_f\data\GUI\Cfg\Hints\Gear_ca.paa"];
    _listBox_AditionalStuff lbSetData [_indexHeader, "['any']"];

    {
        private _class = _x select 0;
        private _text = switch (_class) do {
            case "FST_Backpack_Jumppack_Z6_Ammo": { "Z6 Pack" };
            case "FST_Backpack_Jumppack_PLX_Ammo": { "PLX Pack" };
            case "FST_Backpack_Jumppack_RPS_Ammo": { "RPS6 Pack" };
            default { getText (configFile >> "CfgVehicles" >> _class >> "displayName") };
        };
        private _pic = getText (configFile >> "CfgVehicles" >> _class >> "picture");
        private _index = _listBox_AditionalStuff lbAdd _text;
        _listBox_AditionalStuff lbSetPicture [_index, _pic];
        _listBox_AditionalStuff lbSetData [_index, format ["['%1']", _class]];
        _listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
    } forEach _backpacks;
};
if (_typeOfKit == "Squad Leader") then {
    private _backpacks = [
        ["FST_Backpack_Antenna", "10x DC15L Battery"],
        ["FST_Backpack_Antenna", "3x RPS6 + 1x HE Rocket"],
        ["FST_Backpack_Antenna", "7x Z6 Battery"],
        ["FST_Backpack_Antenna", "Standard Ammo + 3x Detonators"],
        ["FST_Backpack_Antenna", "2x LP Coil + 4x T15 Coil"],
        ["FST_Backpack_Antenna", "3x PLX Rockets"]
    ];
    private _listBox_AditionalStuff = (findDisplay 2000) displayCtrl 1731;
    private _indexSpacer = _listBox_AditionalStuff lbAdd " ";
    _listBox_AditionalStuff lbSetData [_indexSpacer, "['any']"];
    private _indexHeader = _listBox_AditionalStuff lbAdd " AMMO BACKPACKS";
    _listBox_AditionalStuff lbSetPicture [_indexHeader, "a3\ui_f\data\GUI\Cfg\Hints\Gear_ca.paa"];
    _listBox_AditionalStuff lbSetData [_indexHeader, "['any']"];
    {
        private _class = _x select 0;
        private _desc = _x select 1;
        private _pic = getText (configFile >> "CfgVehicles" >> _class >> "picture");
        private _disp = getText (configFile >> "CfgVehicles" >> _class >> "displayName");
        private _text = switch (_desc) do {
            case "10x DC15L Battery": { "DC15L Pack" };
            case "3x RPS6 + 1x HE Rocket": { "RPS6 Pack" };
            case "7x Z6 Battery": { "Z6 Pack" };
            case "Standard Ammo + 3x Detonators": { "Standard Ammo Pack" };
            case "2x LP Coil + 4x T15 Coil": { "Rifle AT Pack" };
            case "3x PLX Rockets": { "PLX Pack" };
            default { _disp };
        };
        private _index = _listBox_AditionalStuff lbAdd _text;
        _listBox_AditionalStuff lbSetPicture [_index, _pic];
        _listBox_AditionalStuff lbSetData [_index, format ["['%1','%2']", _class, _desc]];
        _listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
    } forEach _backpacks;
};
if (_typeOfKit == "Squad Leader ") then {
    private _backpacks = [
        ["FST_Backpack_Jumppack_LR", "10x DC15L Battery"],
        ["FST_Backpack_Jumppack_LR", "3x RPS6 + 1x HE Rocket"],
        ["FST_Backpack_Jumppack_LR", "7x Z6 Battery"],
        ["FST_Backpack_Jumppack_LR", "Standard Ammo + 3x Detonators"],
        ["FST_Backpack_Jumppack_LR", "2x LP Coil + 4x T15 Coil"],
        ["FST_Backpack_Jumppack_LR", "3x PLX Rockets"]
    ];
    private _listBox_AditionalStuff = (findDisplay 2000) displayCtrl 1731;
    private _indexSpacer = _listBox_AditionalStuff lbAdd " ";
    _listBox_AditionalStuff lbSetData [_indexSpacer, "['any']"];
    private _indexHeader = _listBox_AditionalStuff lbAdd " AMMO BACKPACKS";
    _listBox_AditionalStuff lbSetPicture [_indexHeader, "a3\ui_f\data\GUI\Cfg\Hints\Gear_ca.paa"];
    _listBox_AditionalStuff lbSetData [_indexHeader, "['any']"];
    {
        private _class = _x select 0;
        private _desc = _x select 1;
        private _pic = getText (configFile >> "CfgVehicles" >> _class >> "picture");
        private _disp = getText (configFile >> "CfgVehicles" >> _class >> "displayName");
        private _text = switch (_desc) do {
            case "10x DC15L Battery": { "DC15L Pack" };
            case "3x RPS6 + 1x HE Rocket": { "RPS6 Pack" };
            case "7x Z6 Battery": { "Z6 Pack" };
            case "Standard Ammo + 3x Detonators": { "Standard Ammo Pack" };
            case "2x LP Coil + 4x T15 Coil": { "Rifle AT Pack" };
            case "3x PLX Rockets": { "PLX Pack" };
            default { _disp };
        };
        private _index = _listBox_AditionalStuff lbAdd _text;
        _listBox_AditionalStuff lbSetPicture [_index, _pic];
        _listBox_AditionalStuff lbSetData [_index, format ["['%1','%2']", _class, _desc]];
        _listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
    } forEach _backpacks;
};
private _roleClean = toLower (trim _typeOfKit);
private _selectedKitRole = switch (_roleClean) do {
    case "engineer":           { "eod" };
    case "rto";
    case "platoon rto":        { "rto" };
    case "medic";
    case "platoon medic";
    case "crewman medic":      { "medic" };
    default { "" };
};
private _helmetClass = _kit param [6, ""];
private _bpClass     = ((_kit param [5, ["",[]]]) param [0, ""]);
private _isAirborne  = (
    (_helmetClass != "" && {(toLower _helmetClass) find "airborne" > -1}) ||
    (_helmetClass isEqualTo "FST_Airborne_Helmet") ||
    (_bpClass     != "" && {_bpClass find "FST_Backpack_Jumppack" == 0})
);
private _selectedKitType = if (_isAirborne) then {"airborne"} else {
    if ((missionNamespace getVariable ["FST_CurrentKitCategory","regular"]) isEqualTo "ranger") then {"ranger"} else {""}
};
[player, _selectedKitRole, _selectedKitType] execVM "\41st_KitMenu\FST_autoCustoms.sqf";
private _lastCamo = missionNamespace getVariable ["FST_LastCamoPreset",""];
if (
    _lastCamo != "" &&
    {(player getVariable ["WBK_Kit_Category",""]) isEqualTo "ranger"}
) then {
    [_lastCamo] call FST_ApplyCamoPreset;
};
};
WBK_UpdatePlayerKitOnMenu = {
_display = findDisplay 2000;
_listBox = _display displayCtrl 1733;
_listBox lbSetColor [0, [0,1,0,1]];
lbClear 1733;
_pic = "";
_index = _listBox lbAdd "---------------WEAPONS---------------";
_listBox lbSetPicture [_index, _pic];
_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
{
	_weap = _x;
	if (!(_weap == "") and !(_weap == "Put") and !(_weap == "Throw") and !(_weap == binocular player)) then {
		_pic = getText (configFile >> "CfgWeapons" >> _weap >> "picture");
		_index = _listBox lbAdd getText (configFile >> "CfgWeapons" >> _weap >> "displayname");
		_listBox lbSetPicture [_index, _pic];
		_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
		{
			if !(_x == "") then {
				_pic1 = getText (configFile >> "CfgWeapons" >> _x >> "picture");
				_index1 = _listBox lbAdd getText (configFile >> "CfgWeapons" >> _x >> "displayname");
				_listBox lbSetPicture [_index1, _pic1];
				_listBox lbSetPictureColor [_index1, [1, 1, 1, 1]];
			};
		} forEach (player weaponAccessories _weap);
	};
} forEach weapons player;
_pic = "";
_index = _listBox lbAdd "---------------EQUIPMENT---------------";
_listBox lbSetPicture [_index, _pic];
_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
_itemsPlayer = [headgear player, goggles player, vest player, uniform player, backpack player];
{
if (!(_x == "")) then {
  switch true do {
    case (_x == backpack player): {
		_pic = getText (configFile >> "CfgVehicles" >> _x >> "picture");
		_index = _listBox lbAdd getText (configFile >> "CfgVehicles" >> _x >> "displayname");
		_listBox lbSetPicture [_index, _pic];
		_listBox lbSetData [_index, format ["['%1']", _x]];
		_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
	};
	case (_x == goggles player): {
		_pic = getText (configFile >> "CfgGlasses" >> _x >> "picture");
		_index = _listBox lbAdd getText (configFile >> "CfgGlasses" >> _x >> "displayname");
		_listBox lbSetPicture [_index, _pic];
		_listBox lbSetData [_index, format ["['%1']", _x]];
		_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
	};
	default {
		_pic = getText (configFile >> "CfgWeapons" >> _x >> "picture");
		_index = _listBox lbAdd getText (configFile >> "CfgWeapons" >> _x >> "displayname");
		_listBox lbSetPicture [_index, _pic];
		_listBox lbSetData [_index, format ["['%1']", _x]];
		_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
	};
  };
};
} forEach _itemsPlayer;
{
if (!(_x == "")) then {
if (_x isKindOf ["None", configFile >> "CfgGlasses"]) then {
_pic = getText (configFile >> "CfgGlasses" >> _x >> "picture");
_index = _listBox lbAdd getText (configFile >> "CfgGlasses" >> _x >> "displayname");
_listBox lbSetPicture [_index, _pic];
_listBox lbSetData [_index, format ["['%1']", _x]];
_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
}else{
_pic = getText (configFile >> "CfgWeapons" >> _x >> "picture");
_index = _listBox lbAdd getText (configFile >> "CfgWeapons" >> _x >> "displayname");
_listBox lbSetPicture [_index, _pic];
_listBox lbSetData [_index, format ["['%1']", _x]];
_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
};
};
} forEach assignedItems player;
_pic = "";
_index = _listBox lbAdd "---------------MAGAZINES AND ITEMS---------------";
_listBox lbSetPicture [_index, _pic];
_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
_currentMagArray = [];
_mags = magazines player;
{
if (!(_x == "") and !(_x in _currentMagArray)) then {
_crtMag = _x;
_currentMagArray pushBack _crtMag;
_count = { _x == _crtMag } count magazines player;
_pic = getText (configFile >> "CfgMagazines" >> _crtMag >> "picture");
_text = "X" +  str _count + " " + getText (configFile >> "CfgMagazines" >> _crtMag >> "displayname");
_index = _listBox lbAdd _text;
_listBox lbSetPicture [_index, _pic];
_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
};
} forEach _mags;
{
if (!(_x == "") and !(_x in _currentMagArray)) then {
_crtMag = _x;
_currentMagArray pushBack _crtMag;
_count = { _x == _crtMag } count items player;
if (_x isKindOf ["None", configFile >> "CfgGlasses"]) then {
_pic = getText (configFile >> "CfgGlasses" >> _x >> "picture");
_text = "X" +  str _count + " " + getText (configFile >> "CfgGlasses" >> _crtMag >> "displayname");
_index = _listBox lbAdd _text;
_listBox lbSetPicture [_index, _pic];
_listBox lbSetData [_index, format ["['%1']", _x]];
_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
}else{
_pic = getText (configFile >> "CfgWeapons" >> _x >> "picture");
_text = "X" +  str _count + " " + getText (configFile >> "CfgWeapons" >> _crtMag >> "displayname");
_index = _listBox lbAdd _text;
_listBox lbSetPicture [_index, _pic];
_listBox lbSetData [_index, format ["['%1']", _x]];
_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
};
};
} forEach items player;
};



Wbk_AddKit = {
    _obj = _this select 0;
    _nameOfKit = _this select 1;
    _fullKit = _this select 2;
    _text = _this select 3;
    _condition = _this select 4;
    _code = _this select 5;
    _category = if (count _this > 6) then {_this select 6} else {"regular"};

    _kitToTransfer = [_nameOfKit, _fullKit, _text, _condition, _code, _category];

    if (isNil "FST_AllKits") then { FST_AllKits = []; };
    if (isNil "FST_RegularKits") then { FST_RegularKits = []; };
    if (isNil "FST_AirborneKits") then { FST_AirborneKits = []; };
    if (isNil "FST_PilotKits") then { FST_PilotKits = []; };
    if (isNil "FST_RangerKits") then { FST_RangerKits = []; };
    _kitNameExists = { (_x select 0) isEqualTo _nameOfKit };

    if ((FST_AllKits findIf _kitNameExists) == -1) then {
        FST_AllKits pushBack _kitToTransfer;
    };

switch (_category) do {
        case "airborne": { if ((FST_AirborneKits findIf _kitNameExists) == -1) then { FST_AirborneKits pushBack _kitToTransfer; }; };
        case "pilot":    { if ((FST_PilotKits    findIf _kitNameExists) == -1) then { FST_PilotKits    pushBack _kitToTransfer; }; };
        case "ranger":   { if ((FST_RangerKits   findIf _kitNameExists) == -1) then { FST_RangerKits   pushBack _kitToTransfer; }; };
        default          { if ((FST_RegularKits  findIf _kitNameExists) == -1) then { FST_RegularKits  pushBack _kitToTransfer; }; };
    };
    if (isNil {_obj getVariable "FST_ActualKits"}) exitWith {
        _obj setVariable ["FST_ActualKits", [_kitToTransfer]];
        _obj spawn Wbk_equip_load;
    };
    _array = _obj getVariable "FST_ActualKits";
    _kitNameExistsObj = _array findIf { (_x select 0) isEqualTo _nameOfKit } > -1;
    if (!_kitNameExistsObj) then {
        _array pushBack _kitToTransfer;
        _obj setVariable ["FST_ActualKits", _array];
    };
};

