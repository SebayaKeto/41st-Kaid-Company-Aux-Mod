// =============================================================================
//  BUZZ AT-RT — debug_fire.sqf  (TEMPORARY DIAGNOSTIC — not wired into config.cpp)
//
//  Run this from the debug console (or execVM) WHILE MOUNTED on the AT-RT you
//  want to test:
//      [] execVM "\BUZZ_Vehicles\ATRT\scripts\debug_fire.sqf";
//
//  Then sprint and press Fire like you did when you saw the slowdown.
//  Every line is written with diag_log (check the .rpt) AND systemChat
//  (visible immediately in your chat window). Look for the [BUZZ DEBUG] tag.
//
//  What we're trying to learn:
//    1. Does "weapons _atrt" actually come back empty at the moment you're
//       testing, or is something re-adding a weapon after spawn?
//    2. Does our MouseButtonDown handler even see button 0 firing, and is it
//       the button actually bound to Fire?
//    3. What animation does the engine switch to the instant you click Fire —
//       this tells us whether it's even going through AnimChanged at all, or
//       some other path (e.g. a weapon-raise/lower state machine that doesn't
//       fire AnimChanged the way we assumed).
//    4. Exactly when (relative to the above) the speed actually drops.
// =============================================================================

private _fnLog = {
    params ["_msg"];
    diag_log text ("[BUZZ DEBUG] " + _msg);
    systemChat ("[BUZZ DEBUG] " + _msg);
};

// This mod mounts riders via remoteControl + attachTo, not moveInDriver, so
// "vehicle player" never changes and can't be used to detect mounting. Instead
// check whether "player" itself became the AT-RT (if remoteControl swapped it)
// or whether "player" is still the original body attachTo'd to one.
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

// Raw mouse button traffic on the interface display — confirms whether button 0
// is actually what's bound to Fire, and whether our handler even sees the click.
(findDisplay 46) displayAddEventHandler ["MouseButtonDown", {
    params ["_d", "_b"];
    [format ["MouseButtonDown button=%1 (debug logger — does NOT consume)", _b]] call
        { params ["_msg"]; diag_log text ("[BUZZ DEBUG] " + _msg); systemChat ("[BUZZ DEBUG] " + _msg); };
    false
}];

// Every animation transition, with the speed at that instant.
_atrt addEventHandler ["AnimChanged", {
    params ["_unit", "_anim"];
    [format ["AnimChanged -> %1   speed=%2", _anim, speed _unit]] call
        { params ["_msg"]; diag_log text ("[BUZZ DEBUG] " + _msg); systemChat ("[BUZZ DEBUG] " + _msg); };
}];

// AnimStateChanged is more granular than AnimChanged in some cases — log it too.
_atrt addEventHandler ["AnimStateChanged", {
    params ["_unit", "_anim"];
    [format ["AnimStateChanged -> %1   speed=%2", _anim, speed _unit]] call
        { params ["_msg"]; diag_log text ("[BUZZ DEBUG] " + _msg); systemChat ("[BUZZ DEBUG] " + _msg); };
}];

// Should never fire with no weapon — if it does, that's the smoking gun.
_atrt addEventHandler ["Fired", {
    ["Fired EH triggered (unit fired a shot!)"] call
        { diag_log text "[BUZZ DEBUG] Fired EH triggered (unit fired a shot!)"; systemChat "[BUZZ DEBUG] Fired EH triggered (unit fired a shot!)"; };
}];

// Continuous speed watch — logs on meaningful change, and once speed collapses
// to ~0 from a high value it dumps full state every second (damage, ace vars,
// lifeState, velocity, poll-loop heartbeat age) so we can see exactly what's
// stuck during a freeze, and whether the "poll while mounted" recovery loop in
// init.sqf (which sets BUZZ_pollHeartbeat every 0.25s) is still alive.
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

        // Freeze = was moving fast, now sitting at ~0, and it's been at least
        // 1s since our last full-state dump (avoid spamming every 0.1s tick).
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
