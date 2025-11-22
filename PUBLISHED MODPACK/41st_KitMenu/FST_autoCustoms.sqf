params [["_unit", player], ["_roleName", ""], ["_kitTag", ""]];
if ((uniform _unit) isEqualTo "FST_Uniform_GM_Plastic") exitWith {};
if !(_roleName isEqualType "") then { _roleName = "" };
if !(_kitTag   isEqualType "") then { _kitTag   = "" };
private _roleNameTrim = trim _roleName;
private _roleLower    = toLower _roleNameTrim;
private _kitTagTrim   = trim _kitTag;
private _kitTagLower  = toLower _kitTagTrim;
missionNamespace setVariable ["FST_AutoCustoms_SkipPrompts", (_kitTagLower isEqualTo "ranger")];
private _nameFull      = name _unit;
private _split         = _nameFull splitString " ";
private _rankAndNumber = _split param [0, ""];
private _rankBase      = (_rankAndNumber splitString "-") param [0, ""];
private _rank          = _rankBase + "-";
private _playerNameRaw = _split param [1, ""];
private _playerName    = (_playerNameRaw splitString """") joinString "";
_playerName            = trim _playerName;
diag_log format ["[FST autoCustoms] Parsed name='%1' -> rank=%2, callsign=%3", _nameFull, _rank, _playerName];
private _pnameLower = toLower _playerName;
if (_pnameLower in ["merrik","annex","cardinal","sigs"]) exitWith {};
private _mem = _unit getVariable ["FST_CustomSel", createHashMap];
private _allowHelmet = false;
private _allowArmor  = false;
private _allowNVG    = false;
private _allowBack   = false;
private _allowVest   = false;
switch (_rank) do {
    case "CT-":   {};
    case "SCT-":  { _allowHelmet = true; };
    case "VCT-":  { _allowHelmet = true; };
    case "CLC-";
    case "CPL-";
    case "CS-";
    case "CSS-";
    case "CSM-";
    case "CSL-";
    case "CL-";
    case "ENS-";
    case "LTJG-";
    case "LT-";
    case "LCDR-";
    case "CDR-";
    case "CAPT-": { _allowHelmet = true; _allowArmor = true; _allowNVG = true; _allowBack = true; };
    case "CXC-":  { _allowHelmet = true; };
    case "CX-":   { _allowHelmet = true; };
    case "CXV-":  { _allowHelmet = true; _allowArmor = true; };
    case "CXP-":  { _allowHelmet = true; _allowArmor = true; };
    case "CXS-":  { _allowHelmet = true; _allowArmor = true; };
    case "CXL-":  { _allowHelmet = true; _allowArmor = true; };
    case "CXR-":  { _allowHelmet = true; _allowArmor = true; };
    case "ARC-":  { _allowHelmet = true; _allowArmor = true; _allowVest = true; _allowBack = true; _allowNVG = true; };
};
private _skipCustoms = (_kitTagLower isEqualTo "ranger");

missionNamespace setVariable ["FST_fnc_confirmCustomVariant", {
    disableSerialization;
    private _disp = uiNamespace getVariable ["FST_CustomVariantSelector_Display", displayNull];
    if (isNull _disp) exitWith {};
    private _lb = _disp displayCtrl 4201;
    private _sel = lbCurSel _lb;
    private _choice = "";
    if (_sel >= 0) then {
        _choice = _lb lbData _sel;
        if (_choice isEqualTo "") then { _choice = _lb lbText _sel; };
    };
    private _resVar = uiNamespace getVariable ["FST_VariantResultVar",""];
    if (_resVar != "") then { missionNamespace setVariable [_resVar, _choice]; };
    closeDialog 0;
}];

private _openVariantSelector = {
    disableSerialization;
    params ["_prompt", "_classes"];
    if (!hasInterface) exitWith { "" };

    private _resVar = format ["FST_CustomChoice_%1_%2", diag_tickTime, floor random 1e6];
    missionNamespace setVariable [_resVar, ""];
    uiNamespace setVariable ["FST_VariantResultVar", _resVar];

    if !(createDialog "FST_CustomVariantSelector") exitWith { "" };
    hintSilent _prompt;

    private _deadline = diag_tickTime + 5;
    private _display = displayNull;
    waitUntil {
        uiSleep 0.01;
        _display = uiNamespace getVariable ["FST_CustomVariantSelector_Display", displayNull];
        if (isNull _display) then { _display = findDisplay 4200; };
        !isNull _display || { diag_tickTime > _deadline }
    };
    if (isNull _display) exitWith { "" };

    private _lb = _display displayCtrl 4201;
    lbClear _lb;
    {
        private _cls = _x;
        private _cfgW = configFile >> "CfgWeapons"  >> _cls;
        private _cfgV = configFile >> "CfgVehicles" >> _cls;
        private _cfg  = if (isClass _cfgW) then {_cfgW} else {_cfgV};
        private _dn   = getText (_cfg >> "displayName");
        private _txt  = if (_dn == "") then {_cls} else {_dn};
        private _pic  = getText (_cfg >> "picture");
        private _i    = _lb lbAdd _txt;
        _lb lbSetData [_i, _cls];
        if (_pic != "") then { _lb lbSetPicture [_i, _pic]; };
    } forEach _classes;

    if ((lbSize _lb) > 0) then { lbSetCurSel [_lb, 0]; };
    _lb ctrlAddEventHandler ["LBDblClick", {
        [] call (missionNamespace getVariable ["FST_fnc_confirmCustomVariant",{}]);
    }];

    waitUntil {
        uiSleep 0.01;
        isNull _display || { (missionNamespace getVariable [_resVar,""]) != "" }
    };
    missionNamespace getVariable [_resVar, ""]
};

private _collectWeaponsByPrefixes = {
    params ["_prefixes"];
    private _out = [];
    {
        private _cls = configName _x;
        if (_prefixes findIf { _cls find _x == 0 } > -1) then { _out pushBackUnique _cls; };
    } forEach ("true" configClasses (configFile >> "CfgWeapons"));
    _out sort true;
    _out
};
private _collectVehiclesByPrefixes = {
    params ["_prefixes"];
    private _out = [];
    {
        private _cls = configName _x;
        if (_prefixes findIf { _cls find _x == 0 } > -1) then { _out pushBackUnique _cls; };
    } forEach ("true" configClasses (configFile >> "CfgVehicles"));
    _out sort true;
    _out
};
private _filterByNameBoundary = {
    params ["_classes","_prefixes"];
    private _out = [];
    {
        private _cls = _x;
        private _keep = false;
        {
            private _p = _x;
            if (_cls find _p == 0) then {
                private _len = count _p;
                _keep = ((count _cls) == _len) || { (_cls select [_len,1]) isEqualTo "_" };
            };
            if (_keep) exitWith {};
        } forEach _prefixes;
        if (_keep) then { _out pushBackUnique _cls; };
    } forEach _classes;
    _out
};
private _restoreUniformItems  = { params ["_unit","_items"]; { _unit addItemToUniform  _x; } forEach _items; };
private _restoreVestItems     = { params ["_unit","_items"]; { _unit addItemToVest     _x; } forEach _items; };
private _restoreBackpackItems = { params ["_unit","_items"]; { _unit addItemToBackpack _x; } forEach _items; };
if (!_skipCustoms && _allowHelmet) then {
    private _saved = _mem get "helmet";
    if (_rank isEqualTo "ARC-") then {
        private _arcPrefix = format ["FST_P2_ARC_Helmet_%1", _playerName];
        if (!isNil {_saved} && { _saved find _arcPrefix != 0 }) then { _saved = nil; };
    };

    if (!isNil {_saved} && { isClass (configFile >> "CfgWeapons" >> _saved) }) then {
        removeHeadgear _unit;
        _unit addHeadgear _saved;
    } else {
        private _helmetPrefixes = if (_rank isEqualTo "ARC-") then {
            [ format ["FST_P2_ARC_Helmet_%1", _playerName] ]
        } else {
            [
                format ["FST_P2_Helmet_%1", _playerName],
                format ["FST_Airborne_Helmet_%1", _playerName],
                format ["FST_Crewman_Helmet_%1", _playerName],
                format ["FST_Pilot_P1_Helmet_%1", _playerName],
                format ["FST_ARF_Helmet_WhiteGreen_%1", _playerName]
            ]
        };

        private _helms = [_helmetPrefixes] call _collectWeaponsByPrefixes;
        _helms = [_helms, _helmetPrefixes] call _filterByNameBoundary;

        if ((count _helms) == 1) then {
            private _chosen = _helms#0;
            removeHeadgear _unit;
            _unit addHeadgear _chosen;
            _mem set ["helmet", _chosen];
            _unit setVariable ["FST_CustomSel", _mem, true];
        } else {
            if ((count _helms) >= 2) then {
                private _chosen = ["Select a helmet", _helms] call _openVariantSelector;
                if (_chosen != "") then {
                    removeHeadgear _unit;
                    _unit addHeadgear _chosen;
                    _mem set ["helmet", _chosen];
                    _unit setVariable ["FST_CustomSel", _mem, true];
                };
            };
        };
    };
};
if (!_skipCustoms && _allowArmor) then {
    private _saved = _mem get "uniform";
    if (!isNil {_saved} && { isClass (configFile >> "CfgWeapons" >> _saved) }) then {
        private _uItems = uniformItems _unit;
        removeUniform _unit;
        _unit forceAddUniform _saved;
        [_unit, _uItems] call _restoreUniformItems;
    } else {
        private _uniformPrefixes = [format ["FST_Uniform_%1", _playerName]];
        private _unis = [_uniformPrefixes] call _collectWeaponsByPrefixes;
        _unis = [_unis, _uniformPrefixes] call _filterByNameBoundary;

        if ((count _unis) == 1) then {
            private _chosen = _unis#0;
            private _uItems = uniformItems _unit;
            removeUniform _unit;
            _unit forceAddUniform _chosen;
            [_unit, _uItems] call _restoreUniformItems;
            _mem set ["uniform", _chosen];
            _unit setVariable ["FST_CustomSel", _mem, true];
        } else {
            if ((count _unis) >= 2) then {
                private _chosen = ["Select a uniform", _unis] call _openVariantSelector;
                if (_chosen != "") then {
                    private _uItems = uniformItems _unit;
                    removeUniform _unit;
                    _unit forceAddUniform _chosen;
                    [_unit, _uItems] call _restoreUniformItems;
                    _mem set ["uniform", _chosen];
                    _unit setVariable ["FST_CustomSel", _mem, true];
                };
            };
        };
    };
};
if (!_skipCustoms && _allowVest) then {
    private _saved = _mem get "vest";
    if (!isNil {_saved} && { isClass (configFile >> "CfgWeapons" >> _saved) }) then {
        private _vItems = vestItems _unit;
        if (vest _unit != "") then { removeVest _unit; };
        _unit addVest _saved;
        [_unit, _vItems] call _restoreVestItems;
    } else {
        private _vestPrefixes = [];
        if (_rank isEqualTo "ARC-") then {
            _vestPrefixes pushBack format ["FST_CloneVestARC_%1", _playerName];
        };
        if (count _vestPrefixes > 0) then {
            private _vests = [_vestPrefixes] call _collectWeaponsByPrefixes;
            _vests = [_vests, _vestPrefixes] call _filterByNameBoundary;

            if ((count _vests) == 1) then {
                private _chosen = _vests#0;
                private _vItems = vestItems _unit;
                if (vest _unit != "") then { removeVest _unit; };
                _unit addVest _chosen;
                [_unit, _vItems] call _restoreVestItems;
                _mem set ["vest", _chosen];
                _unit setVariable ["FST_CustomSel", _mem, true];
            } else {
                if ((count _vests) >= 2) then {
                    private _chosen = ["Select a vest", _vests] call _openVariantSelector;
                    if (_chosen != "") then {
                        private _vItems = vestItems _unit;
                        if (vest _unit != "") then { removeVest _unit; };
                        _unit addVest _chosen;
                        [_unit, _vItems] call _restoreVestItems;
                        _mem set ["vest", _chosen];
                        _unit setVariable ["FST_CustomSel", _mem, true];
                    };
                };
            };
        };
    };
};
if (!_skipCustoms && _allowNVG) then {
    private _saved = _mem get "nvg";
    if (!isNil {_saved} && { isClass (configFile >> "CfgWeapons" >> _saved) }) then {
        _unit linkItem _saved;
    } else {
        private _nvgPrefixes = [
            format ["FST_NVG_%1", _playerName],
            format ["FST_NVG_Fixed_%1", _playerName]
        ];
        private _nvgs = [_nvgPrefixes] call _collectWeaponsByPrefixes;
        _nvgs = [_nvgs, _nvgPrefixes] call _filterByNameBoundary;

        if ((count _nvgs) == 1) then {
            private _chosen = _nvgs#0;
            _unit linkItem _chosen;
            _mem set ["nvg", _chosen];
            _unit setVariable ["FST_CustomSel", _mem, true];
        } else {
            if ((count _nvgs) >= 2) then {
                private _chosen = ["Select NVGs", _nvgs] call _openVariantSelector;
                if (_chosen != "") then {
                    _unit linkItem _chosen;
                    _mem set ["nvg", _chosen];
                    _unit setVariable ["FST_CustomSel", _mem, true];
                };
            };
        };
    };
};
if (!_skipCustoms && _allowBack) then {
private _saved = _mem get "backpack";
    if (!isNil {_saved} && { isClass (configFile >> "CfgVehicles" >> _saved) } && { _kitTagLower isEqualTo "airborne" }) then {
        private _bItems = backpackItems _unit;
        if (backpack _unit != "") then { removeBackpack _unit; };
        _unit addBackpack _saved;
        [_unit, _bItems] call _restoreBackpackItems;
    } else {
        private _bpPrefixes = [];
        if (_kitTagLower isEqualTo "airborne" && { !(_roleLower in ["eod","rto","medic"]) }) then {
            _bpPrefixes pushBack format ["FST_Backpack_Jumppack_%1", _playerName];
        };
        if (_rank isEqualTo "ARC-") then {
            _bpPrefixes pushBackUnique "FST_Clone_Backpack_ARC";
        };

        if (count _bpPrefixes > 0) then {
            private _bps = [_bpPrefixes] call _collectVehiclesByPrefixes;
            _bps = [_bps, _bpPrefixes] call _filterByNameBoundary;

            if ((count _bps) == 1) then {
                private _chosen = _bps#0;
                private _bItems = backpackItems _unit;
                if (backpack _unit != "") then { removeBackpack _unit; };
                _unit addBackpack _chosen;
                [_unit, _bItems] call _restoreBackpackItems;
                _mem set ["backpack", _chosen];
                _unit setVariable ["FST_CustomSel", _mem, true];
            } else {
                if ((count _bps) >= 2) then {
                    private _chosen = ["Select a backpack", _bps] call _openVariantSelector;
                    if (_chosen != "") then {
                        private _bItems = backpackItems _unit;
                        if (backpack _unit != "") then { removeBackpack _unit; };
                        _unit addBackpack _chosen;
                        [_unit, _bItems] call _restoreBackpackItems;
                        _mem set ["backpack", _chosen];
                        _unit setVariable ["FST_CustomSel", _mem, true];
                    };
                };
            };
        };
    };
};
_unit setVariable ["FST_CustomSel", _mem, true];
if (_rank isEqualTo "ARC-") then {
    _unit linkItem "FST_Antenna";
};
if (!isNil "WBK_UpdatePlayerKitOnMenu") then {
    [] call WBK_UpdatePlayerKitOnMenu;
};
