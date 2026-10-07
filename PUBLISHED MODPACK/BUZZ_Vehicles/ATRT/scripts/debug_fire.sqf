// =============================================================================
//  BUZZ AT-RT — debug_fire.sqf
// =============================================================================

private _fnLog = {
    params ["_msg"];
    diag_log text ("[BUZZ DEBUG] " + _msg);
    systemChat ("[BUZZ DEBUG] " + _msg);
};

// Mount detection
private _atrt = objNull;
if (player isKindOf "FST_ATRT") then {
    _atrt = player;
} else {
    private _att = attachedTo player;
    if (!isNull _att && { _att isKindOf "FST_ATRT" }) then { _atrt = _att; };
};
if (isNull _atrt) exitWith { ["Not mounted on an AT-RT — Saddle Up first, then run this."] call _fnLog; };

[format ["detected AT-RT via %1", if (player isEqualTo _atrt) then {"player isKindOf FST_ATRT (remoteControl swapped player)"} else {"attachedTo player (player is still the original rider body)"}]] call _fnLog;

[format ["mounted: type=%1 weapons=%2 currentWeapon=%3 primaryWeapon=%4 handgunWeapon=%5",
    typeOf _atrt, weapons _atrt, currentWeapon _atrt, primaryWeapon _atrt, handgunWeapon _atrt
]] call _fnLog;

// Mouse button log
(findDisplay 46) displayAddEventHandler ["MouseButtonDown", {
    params ["_d", "_b"];
    [format ["MouseButtonDown button=%1 (debug logger — does NOT consume)", _b]] call
        { params ["_msg"]; diag_log text ("[BUZZ DEBUG] " + _msg); systemChat ("[BUZZ DEBUG] " + _msg); };
    false
}];

// Animation change log
_atrt addEventHandler ["AnimChanged", {
    params ["_unit", "_anim"];
    [format ["AnimChanged -> %1   speed=%2", _anim, speed _unit]] call
        { params ["_msg"]; diag_log text ("[BUZZ DEBUG] " + _msg); systemChat ("[BUZZ DEBUG] " + _msg); };
}];

// Animation state log
_atrt addEventHandler ["AnimStateChanged", {
    params ["_unit", "_anim"];
    [format ["AnimStateChanged -> %1   speed=%2", _anim, speed _unit]] call
        { params ["_msg"]; diag_log text ("[BUZZ DEBUG] " + _msg); systemChat ("[BUZZ DEBUG] " + _msg); };
}];

// Fired log
_atrt addEventHandler ["Fired", {
    ["Fired EH triggered (unit fired a shot!)"] call
        { diag_log text "[BUZZ DEBUG] Fired EH triggered (unit fired a shot!)"; systemChat "[BUZZ DEBUG] Fired EH triggered (unit fired a shot!)"; };
}];

// Speed watch
[_atrt] spawn {
    params ["_a"];
    private _fnLog2 = { params ["_msg"]; diag_log text ("[BUZZ DEBUG] " + _msg); systemChat ("[BUZZ DEBUG] " + _msg); };
    private _last = -1;
    private _wasHigh = false;
    private _frozenLogAt = -1000;
    while { alive _a } do {
        private _cur = speed _a;
        if (abs (_cur - _last) > 1.5) then {
            [format ["speed %1 -> %2", _last, _cur]] call _fnLog2;
            _last = _cur;
        };

        if (_cur > 20) then { _wasHigh = true; };

        // Freeze detection
        if (_wasHigh && _cur < 0.5 && (time - _frozenLogAt) > 1) then {
            _frozenLogAt = time;
            private _hb  = _a getVariable ["BUZZ_pollHeartbeat", -1];
            private _vel = velocity _a;
            [format [
                "FREEZE STATE DUMP: damage=%1 BUZZ_hp=%2 BUZZ_dying=%3 ace_unconscious=%4 lifeState=%5 velocity=%6 animationState=%7 heartbeatAge=%8s rider=%9",
                damage _a,
                _a getVariable ["BUZZ_hp", "<none>"],
                _a getVariable ["BUZZ_dying", "<none>"],
                _a getVariable ["ace_unconscious", "<none>"],
                lifeState _a,
                _vel,
                animationState _a,
                if (_hb < 0) then { "<never set>" } else { time - _hb },
                _a getVariable ["rider", objNull]
            ]] call _fnLog2;
        };

        sleep 0.1;
    };
};

["Debug hooks installed. Sprint + press Fire now, then send back everything tagged [BUZZ DEBUG]."] call _fnLog;
