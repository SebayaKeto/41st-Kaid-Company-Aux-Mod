//modified to remove ace medical allowDamage check, and do only jumppack check, //@@@@@

params ["_unit", "_selection", "_damage", "_shooter", "_ammo", "_hitPointIndex", "_instigator", "_hitpoint", "_directHit", "_context"];


if !(local _unit) exitWith {nil};


private _oldDamage = 0;
private _structuralDamage = _context == 0;

if (_structuralDamage) then {
    _hitPoint = "#structural";
    _oldDamage = damage _unit;
} else {
    _oldDamage = _unit getHitIndex _hitPointIndex;
};


if !(isDamageAllowed _unit) exitWith {_oldDamage};
// if !(isDamageAllowed _unit && {_unit getVariable ["ace_medical_allowDamage", true]}) exitWith {_oldDamage}; ////@@@@@




private _newDamage = _damage - _oldDamage;
if (_structuralDamage && {(abs (_newDamage - 1)) < 0.001 && _ammo == "" && isNull _shooter && isNull _instigator} && {(_unit isNotEqualTo (_unit getVariable ["ace_medical_engine_blockInstaKill", objNull]))}) exitWith {
    ;

    _damage
};




if (_context != 2 && {_context == 4 || _newDamage == 0}) exitWith {
    ;

    if ((_unit isNotEqualTo (_unit getVariable ["ace_medical_engine_blockInstaKill", objNull]))) then {
        _unit setVariable ["ace_medical_engine_blockInstaKill", _unit];
        [{_this setVariable ["ace_medical_engine_blockInstaKill", nil]}, _unit] call CBA_fnc_execNextFrame;
    };

    _oldDamage
};




[_unit, _hitpoint] call ace_medical_engine_fnc_getHitpointArmor params ["_armor", "_armorScaled"];
private _realDamage = _newDamage * _armor;
if (!_structuralDamage) then {
    private _armorCoef = _armor/_armorScaled;
    private _damageCoef = linearConversion [0, 1, ace_medical_engine_damagePassThroughEffect, 1, _armorCoef];
    _newDamage = _newDamage * _damageCoef;
};
;



if (
    _structuralDamage &&
    {getOxygenRemaining _unit <= 0.5} &&
    {_damage isEqualTo (_oldDamage + 0.005)}
) exitWith {
    ;
    ["ace_medical_woundReceived", [_unit, [[_newDamage, "Body", _newDamage]], _unit, "drowning"]] call CBA_fnc_localEvent;

    0
};


private _vehicle = objectParent _unit;
private _inVehicle = !isNull _vehicle;
private _environmentDamage = _ammo == "";



if (
    ace_medical_enableVehicleCrashes &&
    {_environmentDamage && _inVehicle && _structuralDamage} &&
    {vectorMagnitude (velocity _vehicle) > 5}

) exitWith {
    ;
    ["ace_medical_woundReceived", [_unit, [[_newDamage, _hitPoint, _newDamage]], _unit, "vehiclecrash"]] call CBA_fnc_localEvent;

    0
};



if (
    (!_environmentDamage && _inVehicle && _structuralDamage) &&
    {
        private _ammoCfg = configFile >> "CfgAmmo" >> _ammo;
        (if (isNumber (_ammoCfg >> "explosive")) then {getNumber (_ammoCfg >> "explosive")} else {0}) > 0 ||
        {(if (isNumber (_ammoCfg >> "indirectHit")) then {getNumber (_ammoCfg >> "indirectHit")} else {0}) > 0}
    }
) exitWith {
    ;

    _unit setVariable ["ace_medical_lastDamageSource", _shooter];
    _unit setVariable ["ace_medical_lastInstigator", _instigator];

    ["ace_medical_woundReceived", [_unit, [[_newDamage, _hitPoint, _newDamage]], _shooter, "vehiclehit"]] call CBA_fnc_localEvent;

    0
};


_unit setVariable [format ["ace_medical_engine_$%1", _hitPoint], [_realDamage, _newDamage]];




if (_context == 2) then {
    _unit setVariable ["ace_medical_lastDamageSource", _shooter];
    _unit setVariable ["ace_medical_lastInstigator", _instigator];

    private _damageStructural = _unit getVariable ["ace_medical_engine_$#structural", [0,0]];


    private _damageHead = [
        _unit getVariable ["ace_medical_engine_$HitFace", [0,0]],
        _unit getVariable ["ace_medical_engine_$HitNeck", [0,0]],
        _unit getVariable ["ace_medical_engine_$HitHead", [0,0]]
    ];
    _damageHead sort false;
    _damageHead = _damageHead select 0;


    private _damageBody = [
        _unit getVariable ["ace_medical_engine_$HitPelvis", [0,0]],
        _unit getVariable ["ace_medical_engine_$HitAbdomen", [0,0]],
        _unit getVariable ["ace_medical_engine_$HitDiaphragm", [0,0]],
        _unit getVariable ["ace_medical_engine_$HitChest", [0,0]]

    ];
    _damageBody sort false;
    _damageBody = _damageBody select 0;


    private _damageLeftArm = _unit getVariable ["ace_medical_engine_$HitLeftArm", [0,0]];
    private _damageRightArm = _unit getVariable ["ace_medical_engine_$HitRightArm", [0,0]];
    private _damageLeftLeg = _unit getVariable ["ace_medical_engine_$HitLeftLeg", [0,0]];
    private _damageRightLeg = _unit getVariable ["ace_medical_engine_$HitRightLeg", [0,0]];




    private _allDamages = [
        [_damageHead select 0,       3,       _damageHead select 1,       "Head"],
        [_damageBody select 0,       4,       _damageBody select 1,       "Body"],
        [_damageLeftArm select 0,    (1 + random 1),   _damageLeftArm select 1,    "LeftArm"],
        [_damageRightArm select 0,   (1 + random 1),  _damageRightArm select 1,   "RightArm"],
        [_damageLeftLeg select 0,    (1 + random 1),   _damageLeftLeg select 1,    "LeftLeg"],
        [_damageRightLeg select 0,   (1 + random 1),  _damageRightLeg select 1,   "RightLeg"],
        [_damageStructural select 0, 1, _damageStructural select 1, "#structural"]
    ];
    ;

    _allDamages sort false;
    _allDamages = _allDamages apply {[_x select 2, _x select 3, _x select 0]};



    if (_environmentDamage) then {


        if (isNull _shooter) then {

            _ammo = "fire";
            ;
        } else {

            if (_shooter == _unit && {(velocity _unit select 2) < -2}) then {
                _ammo = "falling";
                ;
            } else {
                _ammo = "collision";
                ;
            };
        };
    };



    if ((_allDamages select 0 select 0) > 1E-3) then {
        ;
        ["ace_medical_woundReceived", [_unit, _allDamages, _shooter, _ammo]] call CBA_fnc_localEvent;
    };



    {
        _unit setVariable [_x, nil];
    } forEach [
        "ace_medical_engine_$HitFace","ace_medical_engine_$HitNeck","ace_medical_engine_$HitHead",
        "ace_medical_engine_$HitPelvis","ace_medical_engine_$HitAbdomen","ace_medical_engine_$HitDiaphragm","ace_medical_engine_$HitChest","ace_medical_engine_$HitBody",
        "ace_medical_engine_$HitLeftArm","ace_medical_engine_$HitRightArm","ace_medical_engine_$HitLeftLeg","ace_medical_engine_$HitRightLeg",
        "ace_medical_engine_$#structural"
    ];
};




[0, _oldDamage] select (_hitPoint in ["hithead", "hitbody", "hithands", "hitlegs"])
