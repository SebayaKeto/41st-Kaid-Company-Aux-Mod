// Advances one local unit's dose by _dt seconds
params ["_unit", "_exposure", "_dt"];
_exposure params ["_tier", "_safe", "_decon"];

// Decontamination tents
private _inTent = BUZZ_Radiation_tentRate > 0 && {BUZZ_Radiation_tentList isNotEqualTo []} && {
    (nearestObjects [_unit, BUZZ_Radiation_tentList, 10]) findIf {
        private _tent = _x;
        // Tent footprint check
        (toLower typeOf _tent) in BUZZ_Radiation_tentList && {
        (boundingBoxReal _tent) params ["_p1", "_p2"];
        private _centre = _tent modelToWorld ((_p1 vectorAdd _p2) vectorMultiply 0.5);
        _unit inArea [_centre, (abs ((_p2 select 0) - (_p1 select 0))) / 2, (abs ((_p2 select 1) - (_p1 select 1))) / 2, getDir _tent, true, -1]}
    } > -1
};
_unit setVariable ["BUZZ_Radiation_exposure", [_tier, _safe, _decon || _inTent]];

private _dose = _unit getVariable ["BUZZ_Radiation_dose", 0];
private _sickRate = _unit getVariable ["BUZZ_Radiation_sickRate", 0];
private _treated = CBA_missionTime < (_unit getVariable ["BUZZ_Radiation_treatedUntil", -1]);
private _gear = [_unit] call BUZZ_Radiation_fnc_gearLevel;
_unit setVariable ["BUZZ_Radiation_gear", _gear];

// Vehicle shielding
private _inVehicle = !isNull objectParent _unit || {
    private _hits = lineIntersectsSurfaces [getPosASL _unit vectorAdd [0, 0, 0.3], getPosASL _unit vectorAdd [0, 0, -1.2], _unit, objNull, true, 1, "GEOM", "FIRE"];
    _hits isNotEqualTo [] && {
        private _obj = (_hits select 0) select 2;
        !isNull _obj && {_obj isKindOf "AllVehicles"} && {!(_obj isKindOf "Man")}
    }
};
// Vehicle pause option
private _vehiclePause = _inVehicle && {BUZZ_Radiation_vehiclePausesSickness};

// Shielding
if (_safe || _decon || _inTent) then {_tier = -1};

private _exposureRate = 0;
if (_tier >= 0) then {
    private _rate = 100 / (60 * ([BUZZ_Radiation_ttdBackground, BUZZ_Radiation_ttdDangerous, BUZZ_Radiation_ttdLethal] select _tier));
    private _mult = switch (_tier) do {
        case 0: {[1, BUZZ_Radiation_partialGear, 0] select _gear};
        case 1: {[1, 1, 1 - BUZZ_Radiation_gearProtectDangerous] select _gear};
        default {[1, 1, 1 - BUZZ_Radiation_gearProtectLethal] select _gear};
    };
    if (_inVehicle) then {_mult = _mult * (1 - BUZZ_Radiation_vehicleProtection)};
    if (_treated) then {_mult = _mult * (1 - BUZZ_Radiation_iodineZoneReduction)};
    _exposureRate = _rate * _mult;
};
_unit setVariable ["BUZZ_Radiation_exposureRate", _exposureRate];

if (_exposureRate > 0) then {
    _dose = _dose + _exposureRate * _dt;
    _sickRate = _sickRate max _exposureRate;
} else {
    switch (true) do {
        case (_decon): {
            _dose = _dose - (100 / (60 * BUZZ_Radiation_deconMinutes)) * _dt;
        };
        case (_inTent): {
            _dose = _dose - BUZZ_Radiation_tentRate * _dt;
        };
        case (_treated): {
            _dose = _dose - (100 / (60 * BUZZ_Radiation_iodineClearMinutes)) * _dt;
        };
        case (_vehiclePause): {};
        case (_dose >= BUZZ_Radiation_sickThreshold && {_sickRate > 0}): {
            // Dose change
            _dose = _dose + _sickRate * BUZZ_Radiation_progressOutside * _dt;
        };
        default {
            _dose = _dose - ((BUZZ_Radiation_sickThreshold max 1) / (60 * BUZZ_Radiation_recoveryMinutes)) * _dt;
        };
    };
};

// Radiation Flush IV
private _flush = _unit getVariable ["BUZZ_Radiation_flush", []];
if (_flush isNotEqualTo []) then {
    _flush params ["_start", "_fastAmount", "_fastTime", "_slowAmount", "_slowTime"];
    private _t = CBA_missionTime - _start;
    private _clear = 0;
    if (_t < _fastTime) then {_clear = _clear + _fastAmount / _fastTime};
    if (_t < _slowTime) then {_clear = _clear + _slowAmount / _slowTime};
    _dose = _dose - _clear * _dt;
    if (_t >= (_fastTime max _slowTime)) then {_unit setVariable ["BUZZ_Radiation_flush", nil, true]};
};

_dose = 0 max _dose min 100;
if (_dose <= 0) then {_sickRate = 0};
_unit setVariable ["BUZZ_Radiation_sickRate", _sickRate];
_unit setVariable ["BUZZ_Radiation_dose", _dose];

// Publish dose
private _pub = _unit getVariable ["BUZZ_Radiation_dosePub", 0];
if (abs (_dose - _pub) >= 2 || {_dose == 0 && {_pub != 0}} || {_dose >= 100}) then {
    _unit setVariable ["BUZZ_Radiation_dose", _dose, true];
    _unit setVariable ["BUZZ_Radiation_sickRate", _sickRate, true];
    _unit setVariable ["BUZZ_Radiation_dosePub", _dose];
};

if (_dose >= 100) exitWith {[_unit] call BUZZ_Radiation_fnc_kill};

// Coughing
if (BUZZ_Radiation_cough && {_dose > BUZZ_Radiation_coughDose} && {BUZZ_Radiation_coughDose < 100}
    && {!(_unit getVariable ["ACE_isUnconscious", false])} && {lifeState _unit != "INCAPACITATED"}
    && {CBA_missionTime - (_unit getVariable ["BUZZ_Radiation_lastCough", -100]) > 5}) then {
    private _interval = linearConversion [BUZZ_Radiation_coughDose, 100, _dose, BUZZ_Radiation_coughInterval, BUZZ_Radiation_coughInterval / 4, true];
    if (random 1 < _dt / _interval) then {
        _unit setVariable ["BUZZ_Radiation_lastCough", CBA_missionTime];
        // Cough sound
        private _cls = format ["BUZZ_Radiation_cough_%1", floor random 3];
        private _pitch = 0.9 + random 0.2;
        if (_unit == player) then {playSoundUI [_cls, BUZZ_Radiation_coughVolume, _pitch]};
        private _near = allPlayers select {_x != _unit && {_x distance _unit <= BUZZ_Radiation_coughRange + 5}};
        if (_near isNotEqualTo []) then {["BUZZ_Radiation_say3D", [_unit, _cls, BUZZ_Radiation_coughRange, _pitch], _near] call CBA_fnc_targetEvent};
    };
};

// ACE symptoms
if (BUZZ_Radiation_symptoms && {!isNil "ace_medical_fnc_adjustPainLevel"}) then {
    // Pain
    if (_dose >= BUZZ_Radiation_painDose && {BUZZ_Radiation_painDose < 100}) then {
        private _target = linearConversion [BUZZ_Radiation_painDose, 100, _dose, 0.3, 0.8, true];
        private _pain = _unit getVariable ["ace_medical_pain", 0];
        if (_pain < _target) then {
            [_unit, (_target - _pain) min (0.05 * _dt)] call ace_medical_fnc_adjustPainLevel;
        };
    };

    // Fractures
    if (_dose >= BUZZ_Radiation_fractureDose && {BUZZ_Radiation_fractureDose < 100}) then {
        private _fractures = +(_unit getVariable ["ace_medical_fractures", [0, 0, 0, 0, 0, 0]]);
        private _intact = [2, 3, 4, 5] select {(_fractures select _x) == 0};
        private _first = !(_unit getVariable ["BUZZ_Radiation_fractured", false]);
        if (_intact isNotEqualTo [] && {_first || {random 1 < _dt / BUZZ_Radiation_fractureInterval}}) then {
            private _part = selectRandom _intact;
            _fractures set [_part, 1];
            _unit setVariable ["ace_medical_fractures", _fractures, true];
            ["ace_medical_fracture", [_unit, _part]] call CBA_fnc_localEvent;
            if (!isNil "ace_medical_engine_fnc_updateDamageEffects") then {[_unit] call ace_medical_engine_fnc_updateDamageEffects};
        };
        _unit setVariable ["BUZZ_Radiation_fractured", true];
    } else {
        _unit setVariable ["BUZZ_Radiation_fractured", false];
    };

    // Bleeding
    if (_dose >= BUZZ_Radiation_bleedDose && {BUZZ_Radiation_bleedDose < 100}) then {
        private _first = !(_unit getVariable ["BUZZ_Radiation_bleeding", false]);
        if (_first || {random 1 < _dt / BUZZ_Radiation_bleedInterval}) then {
            [_unit, 0.15 + random 0.15, selectRandom ["Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"], "stab"] call ace_medical_fnc_addDamageToUnit;
        };
        _unit setVariable ["BUZZ_Radiation_bleeding", true];
    } else {
        _unit setVariable ["BUZZ_Radiation_bleeding", false];
    };

    // Blackouts
    if (_dose >= BUZZ_Radiation_blackoutDose && {BUZZ_Radiation_blackoutDose < 100}
        && {random 1 < _dt / BUZZ_Radiation_blackoutInterval} && {!(_unit getVariable ["ACE_isUnconscious", false])}) then {
        [_unit, true, 8 + random 12, true] call ace_medical_fnc_setUnconscious;
    };
};
