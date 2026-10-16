/*
    Dev tool — paste into the debug console (local exec) with the mods loaded.
    Prints the lowcell_weapons.hpp lines for a list of guns and copies them to
    the clipboard. Not used by the addon at runtime.
*/

private _weapons = [
    "FST_DC15A",
    "FST_DC15S"
];
private _percent = "0.20";

private _parents = [];
private _lines   = [];

{
    private _weapon = _x;
    private _cfg    = configFile >> "CfgWeapons" >> _weapon;

    if (!isClass _cfg) then {
        _lines pushBack format ["// %1: class not found", _weapon];
        continue;
    };

    private _parent   = configName inheritsFrom _cfg;
    private _ownModes = (configProperties [_cfg, "isClass _x", false]) apply { toLower configName _x };
    private _args     = [];
    private _count    = 0;
    private _notes    = [];

    {
        private _modeCfg = _cfg >> _x;
        if (_x == "this" || { !isClass _modeCfg }) then {
            _notes pushBack format ["// %1: mode '%2' has no class of its own, skipped", _weapon, _x];
            continue;
        };
        if !(toLower _x in _ownModes) then {
            // Find the ancestor that writes this mode
            private _owner = inheritsFrom _cfg;
            while { isClass _owner && { !(toLower _x in ((configProperties [_owner, "isClass _x", false]) apply { toLower configName _x })) } } do {
                _owner = inheritsFrom _owner;
            };
            _notes pushBack format ["// %1: mode '%2' is inherited from %3, list that gun to cover it", _weapon, _x, configName _owner];
            continue;
        };
        if (getArray (_modeCfg >> "StandardSound" >> "soundBegin") isEqualTo []) then {
            _notes pushBack format ["// %1: mode '%2' has no begin sounds (sound set?), needs BUZZ_shotSounds[]", _weapon, _x];
        };
        _args append [configName _modeCfg, configName inheritsFrom _modeCfg];
        _count = _count + 1;
    } forEach getArray (_cfg >> "modes");

    _lines append _notes;
    if (_count > 0) then {
        _parents pushBackUnique _parent;
        if (_count > 3) then { _lines pushBack format ["// %1: %2 modes, add a LOWCELL_%2 macro", _weapon, _count] };
        _lines pushBack format ["LOWCELL_%1(%2,%3,%4,%5)", _count, _weapon, _parent, _percent, _args joinString ","];
    };
} forEach _weapons;

private _out = ((_parents apply { format ["class %1;", _x] }) + [""] + _lines) joinString endl;
copyToClipboard _out;
_out
