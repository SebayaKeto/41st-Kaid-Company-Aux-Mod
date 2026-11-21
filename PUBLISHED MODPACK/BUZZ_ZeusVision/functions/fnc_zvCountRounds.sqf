/*
    BUZZ_fnc_zvCountRounds
    Rounds a unit has for its primary or launcher weapon's main muzzle.

    Params: 0: unit <OBJECT>, 1: weapon class <STRING> (primaryWeapon or secondaryWeapon)
    Returns: [loaded rounds, spare rounds in inventory] <ARRAY>, or [] if no weapon.
*/
params ["_unit", "_weapon"];
if (_weapon == "") exitWith { [] };

private _compatible = (compatibleMagazines [_weapon, "this"]) apply { toLower _x };

// Spare mags: everything carried that isn't loaded in a weapon.
private _spare = 0;
{
    _x params ["_class", "_ammo", "_isLoaded"];
    if (!_isLoaded && { toLower _class in _compatible }) then { _spare = _spare + _ammo };
} forEach magazinesAmmoFull _unit;

// Loaded mag: read it from the weapon slot itself, which is cleared the moment
// the mag is pulled out or dropped (weaponsItems could keep reporting it).
// The main-muzzle mag is the one that fits the main muzzle (skips UGL rounds).
private _slotMags = if (_weapon == primaryWeapon _unit) then { primaryWeaponMagazine _unit } else { secondaryWeaponMagazine _unit };
private _hasMag = (_slotMags findIf { toLower _x in _compatible }) >= 0;
private _loaded = if (_hasMag) then { _unit ammo _weapon } else { 0 };

[_loaded, _spare]
