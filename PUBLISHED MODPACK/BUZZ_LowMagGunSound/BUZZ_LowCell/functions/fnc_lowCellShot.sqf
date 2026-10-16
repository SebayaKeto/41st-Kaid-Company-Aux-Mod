/*
    BUZZ_fnc_lowCellShot
    FiredBIS handler on every infantry unit. Plays the shot sound of guns
    listed in lowcell_weapons.hpp, pitched up once the cell is nearly empty.
    Guns and fire modes that aren't silenced by the list are left alone.
*/

params ["_unit", "_weapon", "_muzzle", "_mode", "", "_magazine"];

// Locality Guard, main muzzle only
if (!local _unit || { _muzzle != _weapon }) exitWith {};

if (isNil "BUZZ_lowCell_cache") then {
    private _defaults = configFile >> "CfgBUZZ_LowCell";
    BUZZ_lowCell_cache       = createHashMap;
    BUZZ_lowCell_shotPitches = getArray (_defaults >> "shotPitches");
    BUZZ_lowCell_lowPitches  = getArray (_defaults >> "lowCellPitches");
    BUZZ_lowCell_volumeScale = getNumber (_defaults >> "volumeScale");
};

// Per weapon + mode: [] if not opted in, else [samples, weights, percent]
private _key  = _weapon + ":" + _mode;
private _data = BUZZ_lowCell_cache get _key;

if (isNil "_data") then {
    _data = [];
    private _cfg     = configFile >> "CfgWeapons" >> _weapon;
    private _modeCfg = _cfg >> _mode;

    if (getNumber (_cfg >> "BUZZ_lowCell") == 1 && { "BUZZ_SilentSound" in getArray (_modeCfg >> "sounds") }) then {
        private _samples = [];
        private _weights = [];

        private _override = getArray (_cfg >> "BUZZ_shotSounds");
        if (_override isNotEqualTo []) then {
            // Written out on the gun (needed for guns that use sound sets)
            private _volume   = if (isNumber (_cfg >> "BUZZ_shotVolume"))   then { getNumber (_cfg >> "BUZZ_shotVolume") }   else { 1 };
            private _distance = if (isNumber (_cfg >> "BUZZ_shotDistance")) then { getNumber (_cfg >> "BUZZ_shotDistance") } else { 1800 };
            {
                _samples pushBack [_x, _volume, 1, _distance];
                _weights pushBack 1;
            } forEach _override;
        } else {
            // Read from the gun's own StandardSound
            private _standard = _modeCfg >> "StandardSound";
            private _begin    = getArray (_standard >> "soundBegin");
            for "_i" from 0 to (count _begin - 2) step 2 do {
                private _entry = getArray (_standard >> (_begin select _i));
                private _path  = _entry param [0, ""];
                if (_path isEqualType "" && { _path != "" }) then {
                    if (_path select [0, 1] == "\") then { _path = _path select [1] };
                    if !("." in (_path select [count _path - 5])) then { _path = _path + ".wss" };
                    private _volume   = _entry param [1, 1];
                    private _pitch    = _entry param [2, 1];
                    private _distance = _entry param [3, 1800];
                    if !(_volume isEqualType 0) then { _volume = 1 };
                    if !(_pitch isEqualType 0)  then { _pitch = 1 };
                    _samples pushBack [_path, _volume, _pitch, _distance];
                    _weights pushBack (_begin select (_i + 1));
                };
            };
        };

        if (_samples isNotEqualTo []) then {
            _data = [_samples, _weights, getNumber (_cfg >> "BUZZ_lowCellPercent")];
        };
    };

    BUZZ_lowCell_cache set [_key, _data];
};

if (_data isEqualTo []) exitWith {};

_data params ["_samples", "_weights", "_percent"];

// Low Cell
private _capacity = getNumber (configFile >> "CfgMagazines" >> _magazine >> "count");
private _pitches  = if ((_unit ammo _muzzle) < ceil (_percent * _capacity)) then {
    BUZZ_lowCell_lowPitches
} else {
    BUZZ_lowCell_shotPitches
};

// Shot Sound
(_samples selectRandomWeighted _weights) params ["_path", "_volume", "_pitch", "_distance"];
playSound3D [
    _path, _unit, false,
    eyePos _unit,
    _volume * BUZZ_lowCell_volumeScale,
    _pitch * selectRandom _pitches,
    _distance
];
