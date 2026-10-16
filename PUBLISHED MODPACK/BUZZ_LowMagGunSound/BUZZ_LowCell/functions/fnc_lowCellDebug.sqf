/*
    Debug console (local exec):
        [] call BUZZ_fnc_lowCellDebug
*/

params [["_weapon", currentWeapon player, [""]], ["_percent", 0.20, [0]]];

if (_weapon == "") exitWith { systemChat "BUZZ LowCell: no weapon in hands"; "" };

private _cfgWeapons = configFile >> "CfgWeapons";
private _root       = _cfgWeapons >> _weapon;
if (!isClass _root) exitWith { systemChat format ["BUZZ LowCell: %1 not found in CfgWeapons", _weapon]; "" };

private _fnc_ownModes = { (configProperties [_this, "isClass _x", false]) apply { toLower configName _x } };
private _rootModes    = ["mode_semiauto", "mode_burst", "mode_fullauto"];   // declared in config.cpp

private _notes = [];
if (getNumber (_root >> "BUZZ_lowCell") == 1) then {
    _notes pushBack format ["// %1 is already covered by lowcell_weapons.hpp", _weapon];
};

// Gun -> [[mode, modeParent, parentKind], ...]
private _guns  = createHashMap;
private _queue = [[_weapon, getArray (_root >> "modes")]];

while { _queue isNotEqualTo [] } do {
    (_queue deleteAt 0) params ["_gun", "_modes"];
    private _cfg = _cfgWeapons >> _gun;
    private _own = _cfg call _fnc_ownModes;
    if !(_gun in _guns) then { _guns set [_gun, []] };
    private _args = _guns get _gun;

    {
        private _mode    = _x;
        private _modeCfg = _cfg >> _mode;

        if (_mode == "this" || { !isClass _modeCfg }) then {
            _notes pushBack format ["// %1: mode '%2' has no class of its own, skipped", _gun, _mode];
            continue;
        };

        // Inherited mode: list the gun that writes it instead
        if !(toLower _mode in _own) then {
            private _owner = inheritsFrom _cfg;
            while { isClass _owner && { !(toLower _mode in (_owner call _fnc_ownModes)) } } do {
                _owner = inheritsFrom _owner;
            };
            if (isClass _owner) then {
                _notes pushBack format ["// %1: mode '%2' is written in %3, line added for it", _gun, _mode, configName _owner];
                _queue pushBack [configName _owner, [_mode]];
            } else {
                _notes pushBack format ["// %1: couldn't find the class that writes mode '%2'", _gun, _mode];
            };
            continue;
        };

        if (getArray (_modeCfg >> "StandardSound" >> "soundBegin") isEqualTo []) then {
            _notes pushBack format ["// %1: mode '%2' has no begin sounds (sound set?), needs BUZZ_shotSounds[] on the gun", _gun, configName _modeCfg];
        };

        // Where the mode's parent lives: root class, an ancestor gun, or this gun
        private _modeParentCfg = inheritsFrom _modeCfg;
        private _hierarchy     = configHierarchy _modeParentCfg;
        private _kind = switch (true) do {
            case (count _hierarchy == 2): { "root" };
            case ((_hierarchy select (count _hierarchy - 2)) == _cfg): { "sibling" };
            default { "inherited" };
        };

        if (_kind == "root" && { !(toLower configName _modeParentCfg in _rootModes) }) then {
            _notes pushBack format ["// config.cpp: add 'class %1;' next to class Mode_SemiAuto;", configName _modeParentCfg];
        };
        if (_kind == "sibling") then {
            _notes pushBack format ["// %1: mode '%2' inherits from its sibling '%3', '%3' must come first in the line", _gun, configName _modeCfg, configName _modeParentCfg];
        };

        if (_args findIf { (_x select 0) == configName _modeCfg } == -1) then {
            _args pushBack [configName _modeCfg, configName _modeParentCfg, _kind];
        };
    } forEach _modes;
};

// Ancestors first, so their patched classes exist before the guns below them
private _order = [];
{ if (_y isNotEqualTo []) then { _order pushBack [count configHierarchy (_cfgWeapons >> _x), _x] } } forEach _guns;
_order sort true;
private _emitted = _order apply { toLower (_x select 1) };

private _parents = [];
private _lines   = [];
private _addons  = [];

{
    private _gun       = _x select 1;
    private _cfg       = _cfgWeapons >> _gun;
    private _parentCfg = inheritsFrom _cfg;
    private _parent    = configName _parentCfg;
    private _args      = _guns get _gun;
    private _count     = count _args;

    // Parent declaration
    if !(toLower _parent in _emitted) then {
        private _fwd = (_args select { (_x select 2) == "inherited" }) apply { _x select 1 };
        if (_fwd isEqualTo []) then {
            _parents pushBackUnique format ["class %1;", _parent];
        } else {
            // Mode parents that live in an ancestor gun need declaring inside the parent
            private _grand = configName inheritsFrom _parentCfg;
            _parents pushBackUnique format ["class %1;", _grand];
            _parents pushBackUnique format ["class %1: %2 { %3 };", _parent, _grand, (_fwd apply { format ["class %1;", _x] }) joinString " "];
            _notes pushBack format ["// %1: replaces any plain 'class %1;' already under PARENTS", _parent];
        };
    };

    // Gun line
    private _flat = [];
    { _flat append [_x select 0, _x select 1] } forEach _args;
    if (_count > 3) then { _notes pushBack format ["// %1: %2 modes, add a LOWCELL_%2 macro to lowcell_macros.hpp", _gun, _count] };
    _lines pushBack format ["LOWCELL_%1(%2,%3,%4,%5)", _count, _gun, _parent, _percent, _flat joinString ","];

    // Addon that defines the gun
    private _sources = (configSourceAddonList _cfg) select { _x != "BUZZ_LowCell" };
    if (_sources isEqualTo []) then {
        _notes pushBack format ["// %1: couldn't find its addon for requiredAddons[]", _gun];
    } else {
        _addons pushBackUnique format ["""%1"",", _sources select 0];
    };
} forEach _order;

private _out = [format ["// ===== LowCell: %1 (%2) =====", _weapon, getText (_root >> "displayName")]];
if (_notes isNotEqualTo []) then { _out append (_notes + [""]) };
if (_lines isEqualTo []) then {
    _out pushBack "// No fire modes could be added";
} else {
    _out append (["// PARENTS"] + _parents + ["", "// GUNS"] + _lines + ["", "// config.cpp requiredAddons[]"] + _addons);
};

{ diag_log text _x; systemChat _x } forEach _out;
private _text = _out joinString endl;
copyToClipboard _text;
systemChat "BUZZ LowCell: copied to clipboard";
_text
