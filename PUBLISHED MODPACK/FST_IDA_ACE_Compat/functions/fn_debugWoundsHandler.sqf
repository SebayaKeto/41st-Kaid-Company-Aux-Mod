/*
    Function: FSTIDA_fnc_debugWoundsHandler

    Called by ACE Medical's ACE_Medical_Injuries >> damageTypes >> woundHandlers
    for the patched IDA plasma/plasmashell damage types.

    This is intentionally not a loop and not an event handler. It only runs when
    ACE is already processing a wound for one of the patched damage types.

    Purpose:
    - Keep ACE base wound behavior intact.
    - Emit throttled RPT breadcrumbs so remaining ACE wound-handler errors can be
      tied to exact unit class/ammo/damage type/body part.

    ACE wound handler args:
    0: Unit hit <OBJECT>
    1: Damage array <ARRAY>
    2: Damage type <STRING>
    3: Ammo classname or special ammo <STRING>

    Return:
    - Whatever ace_medical_damage_fnc_woundsHandlerBase returns.
*/

params [
    ["_unit", objNull, [objNull]],
    ["_allDamages", [], [[]]],
    ["_typeOfDamage", "", [""]],
    ["_ammo", "", [""]]
];

private _unitClass = if (isNull _unit) then {"<null>"} else {typeOf _unit};
private _unitCfg = configFile >> "CfgVehicles" >> _unitClass;
private _hasUnitCfg = isClass _unitCfg;

private _displayName = if (_hasUnitCfg) then {getText (_unitCfg >> "displayName")} else {"<missing CfgVehicles class>"};
private _faction = if (_hasUnitCfg) then {getText (_unitCfg >> "faction")} else {""};
private _editorSubcategory = if (_hasUnitCfg) then {getText (_unitCfg >> "editorSubcategory")} else {""};
private _vehicleClass = if (_hasUnitCfg) then {getText (_unitCfg >> "vehicleClass")} else {""};
private _simulation = if (_hasUnitCfg) then {getText (_unitCfg >> "simulation")} else {""};
private _model = if (_hasUnitCfg) then {getText (_unitCfg >> "model")} else {""};

private _ammoCfg = configFile >> "CfgAmmo" >> _ammo;
private _ammoExists = isClass _ammoCfg;
private _ammoAceType = if (_ammoExists) then {getText (_ammoCfg >> "ACE_damageType")} else {"<no CfgAmmo class>"};

private _firstDamage = if (_allDamages isEqualTo []) then {[]} else {_allDamages select 0};
private _firstDamageAmount = -1;
private _firstDamageBodyPart = "<none>";
private _firstDamageRaw = -1;

if (_firstDamage isEqualType []) then {
    if ((count _firstDamage) > 0) then {_firstDamageAmount = _firstDamage select 0;};
    if ((count _firstDamage) > 1) then {_firstDamageBodyPart = str (_firstDamage select 1);};
    if ((count _firstDamage) > 2) then {_firstDamageRaw = _firstDamage select 2;};
};

private _sideText = if (isNull _unit) then {"<null>"} else {str (side _unit)};
private _groupSideText = if (isNull _unit) then {"<null>"} else {str (side (group _unit))};
private _isLocal = if (isNull _unit) then {false} else {local _unit};
private _owner = if (isNull _unit) then {-1} else {owner _unit};
private _isPlayer = if (isNull _unit) then {false} else {isPlayer _unit};

private _key = format [
    "%1|%2|%3|%4",
    _unitClass,
    _typeOfDamage,
    _ammo,
    _firstDamageBodyPart
];

private _counts = missionNamespace getVariable ["FST_IDA_ACE_Compat_debugCounts", []];
private _idx = _counts findIf {(_x select 0) isEqualTo _key};
private _count = 1;

if (_idx < 0) then {
    _counts pushBack [_key, 1];
} else {
    _count = ((_counts select _idx) select 1) + 1;
    (_counts select _idx) set [1, _count];
};
missionNamespace setVariable ["FST_IDA_ACE_Compat_debugCounts", _counts];

// Log first sighting of each class/damage/ammo/bodypart combo, then sparse milestones.
// This avoids turning a 300-line ACE issue into a 10,000-line debug issue.
private _shouldLog = (_idx < 0) || {_count in [10, 25, 50, 100]} || {(_count % 250) == 0};

if (_shouldLog) then {
    diag_log format [
        "[FST_IDA_ACE_Compat DEBUG] count=%1 class='%2' display='%3' side=%4 groupSide=%5 faction='%6' editorSubcat='%7' vehicleClass='%8' sim='%9' model='%10' dmgType='%11' ammo='%12' ammoExists=%13 ammoACEType='%14' bodyPart=%15 dmg=%16 rawDmg=%17 local=%18 owner=%19 isPlayer=%20 allDamages=%21",
        _count,
        _unitClass,
        _displayName,
        _sideText,
        _groupSideText,
        _faction,
        _editorSubcategory,
        _vehicleClass,
        _simulation,
        _model,
        _typeOfDamage,
        _ammo,
        _ammoExists,
        _ammoAceType,
        _firstDamageBodyPart,
        _firstDamageAmount,
        _firstDamageRaw,
        _isLocal,
        _owner,
        _isPlayer,
        _allDamages
    ];
};

if (isNil "ace_medical_damage_fnc_woundsHandlerBase") exitWith {
    diag_log format [
        "[FST_IDA_ACE_Compat ERROR] ace_medical_damage_fnc_woundsHandlerBase missing; class='%1' dmgType='%2' ammo='%3' allDamages=%4",
        _unitClass,
        _typeOfDamage,
        _ammo,
        _allDamages
    ];

    // Returning _this keeps the handler chain valid if ACE function registration failed.
    _this
};

_this call ace_medical_damage_fnc_woundsHandlerBase
