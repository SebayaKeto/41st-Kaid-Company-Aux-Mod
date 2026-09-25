// =============================================================================
//  BUZZ AT-RT — init.sqf
//  Called via class EventHandlers { init = "..."; } in config.cpp.
//  That class replaces the grandparent (3AS_ATRT_Man) EventHandlers entirely,
//  so the parent Drive/Dismount EH never fires.  This script is the sole
//  source of actions for the BUZZ_ATRT.
// =============================================================================

private _atrt = _this;

// Blocks ArmA's standard damage pathway on every machine. Note: setDamage
// bypasses this flag (scripted calls always land), which is why the polling
// guard and HandleDamage EH both exist alongside it.
_atrt allowDamage false;

// AnimChanged fires on the locality-owning machine. During remoteControl the
// client holds locality, so the EH must be registered on ALL machines to
// guarantee it fires on the machine that can call setUnconscious / setUnitPos.
// The `local _unit` guard on remoteExec prevents duplicate switchMove broadcasts
// when both server and client have the EH registered.
_atrt addEventHandler ["AnimChanged", {
    params ["_unit", "_anim"];
    if (isNil { _unit getVariable "rider" }) exitWith {};
    if (toLower (_anim select [0, 4]) == "ainv") then {
        _unit setVariable ["ace_unconscious", false, true];
        _unit setUnconscious false;
        _unit setUnitPos "UP";
        if (local _unit) then { [_unit, ""] remoteExec ["switchMove", 0]; };
    };
}];

// CARELESS prevents the AI system from reacting to blasts (going prone / seeking
// cover). Default AWARE causes the walker to freeze mid-animation when explosions
// occur nearby. setBehaviour is local-effect; calling it here on every machine
// ensures it lands on whichever machine holds locality at the time.
_atrt setBehaviour "CARELESS";

// linkItem is local-effect; init.sqf fires on all machines so each machine
// links these locally. hasMap/hasGPS during remoteControl checks the controlled
// unit's local state — linkedItems[] in config is the definitive source, this
// is a belt-and-suspenders call in case the config entry is overridden by a
// parent mod at runtime.
_atrt linkItem "ItemMap";
_atrt linkItem "ItemGPS";

_atrt setVariable ["runSpeedScale",    1.40];
_atrt setVariable ["sprintSpeedScale", 2.33];

// Aim-following spotlight (light.sqf) is disabled for now — the weapon's own light is used.
// Re-enable by uncommenting the execVM below.
if (hasInterface) then {
    // [_atrt] execVM "\BUZZ_Vehicles\ATRT\scripts\light.sqf";
    [_atrt] execVM "\BUZZ_Vehicles\ATRT\scripts\disco.sqf";
};



// ─────────────────────────────────────────────────────────────────────────────
//  SUPPLY BOX  (server only — attachTo + setVariable true syncs to all clients)
// ─────────────────────────────────────────────────────────────────────────────
if (isServer) then {
    // Defer box creation/attachment by one scheduler tick instead of doing it
    // synchronously in the same frame as the unit's own creation. Repeatedly
    // re-issuing attachTo later (both a 2s delayed resync and a click-time resync)
    // never corrected it once it was wrong, which rules out a lost network
    // broadcast — the attachment itself is resolving to a bad transform because
    // it's established before the freshly createUnit'd walker has had a single
    // simulation frame to settle its pose/skeleton. Confirmed via Zeus's
    // editable-object list: the box ends up sitting at world origin ("Debug
    // Corner") instead of tracking the walker. Zeus-placed AT-RTs don't hit this
    // because their own init.sqf run isn't nested inside another script's
    // synchronous createUnit call the way fn_unpackServer.sqf's is, so they get a
    // little more natural settling time before this same code runs. A single
    // `sleep 0` also has fn_unpackServer.sqf's later `_atrt setPosASL _pos` (which
    // corrects createUnit's terrain-snapped spawn position) run *before* the box
    // ever attaches, instead of racing it.
    [_atrt] spawn {
        params ["_atrt"];
        sleep 0;
        if (isNull _atrt) exitWith {};

        private _box = "Box_NATO_Ammo_F" createVehicle (position _atrt);

        _box attachTo [_atrt, [0, 0, 0]];

        _box hideObjectGlobal true;
        clearWeaponCargoGlobal   _box;
        clearMagazineCargoGlobal _box;
        clearItemCargoGlobal     _box;
        clearBackpackCargoGlobal _box;

        private _crateMagCount = getNumber (configFile >> "CfgVehicles" >> typeOf _atrt >> "BUZZ_crateMagCount");
        if (_crateMagCount <= 0) then { _crateMagCount = 3; };
        _box addMagazineCargoGlobal ["BUZZ_ATRT_T15ReserveMag", _crateMagCount];

        _atrt setVariable ["supplyBox", _box, true];

        // Re-broadcast after a further delay in case a client still missed the
        // variable/cargo/attach broadcasts above.
        [_atrt, _box] spawn {
            params ["_a", "_box"];
            sleep 2;
            if (isNull _a || isNull _box) exitWith {};
            _box attachTo [_a, [0, 0, 0]];
            _a setVariable ["supplyBox", _box, true];
            private _cargo  = getMagazineCargo _box;
            private _magIdx = (_cargo select 0) find "BUZZ_ATRT_T15ReserveMag";
            private _count  = if (_magIdx < 0) then { 0 } else { (_cargo select 1) select _magIdx };
            clearMagazineCargoGlobal _box;
            if (_count > 0) then { _box addMagazineCargoGlobal ["BUZZ_ATRT_T15ReserveMag", _count]; };
        };
    };

    _atrt setVariable ["BUZZ_powerCell", 300, true];
    _atrt linkItem "FST_NVG_Invisible";
    // Belt-and-suspenders: config count is already 9999; this reinforces it after
    // full unit initialisation in case the EH fires before weapons are loaded.
    // Guarded on an actual magazine being present — the Ammo Bearer carries the
    // T-15 with no magazine[] configured specifically so it can't fire, and
    // setAmmo must never be the thing that quietly arms it.
    [_atrt] spawn {
        params ["_a"];
        waitUntil { time > 0 };
        if (!((magazines _a) isEqualTo [])) then { _a setAmmo ["BUZZ_ATRT_T15", 99999]; };
    };

    _atrt addEventHandler ["Killed", {
        params ["_atrt"];
        if (_atrt getVariable ["BUZZ_dying", false]) then {
            // BUZZ_dying is set — the death spawn triggered this kill intentionally.
            // Do not revive; let the death animation and particles play.
            // Supply box and shield are cleaned up here in case the death spawn
            // hasn't reached that point yet (Killed fires on the same frame).
            deleteVehicle (_atrt getVariable ["supplyBox", objNull]);
            deleteVehicle (_atrt getVariable ["shield",    objNull]);
        } else {
            // External kill (3AS cleanup script or engine-triggered death).
            // Revive the walker: reset damage, re-assert immunity, and clear any
            // prone/unconscious state the engine latched on kill.
            _atrt setDamage 0;
            _atrt allowDamage false;
            _atrt setVariable ["ace_unconscious", false, true];
            _atrt setUnconscious false;
            _atrt setUnitPos "UP";
            [_atrt, ""] remoteExec ["switchMove", 0];
        };
    }];

    _atrt setVariable ["BUZZ_hp", 1.0, true];
    _atrt setVariable ["ace_medical_enabled", false, true];

    // setDamage bypasses allowDamage false (ArmA engine design — scripted damage
    // ignores the flag).  ACE Medical calls setDamage 1 when it decides the unit
    // is fatally wounded, which spawns the 3AS model's looping death particles
    // before our Killed EH can revive the walker.  Polling getDamage at 100 ms
    // catches the assignment and resets it before the engine finalises the death
    // state and the particle system starts.
    [_atrt] spawn {
        params ["_a"];
        while { alive _a } do {
            sleep 0.1;
            private _d = damage _a;
            if (_a getVariable ["BUZZ_dying", false]) exitWith {};
            if (_d > 0) then { _a setDamage 0; _a allowDamage false; };
        };
    };
};


// ─────────────────────────────────────────────────────────────────────────────
//  FIRED EH  (all machines)
//  Fires on the locality-owning machine — client during remoteControl, server
//  otherwise.  Registered globally so the EH is present on whichever machine
//  holds locality when the shot is taken, blocking fire correctly in MP.
// ─────────────────────────────────────────────────────────────────────────────
_atrt addEventHandler ["Fired", {
    params ["_unit", "_weapon", "", "", "", "", "_projectile"];

    // This EH is registered on every machine (see comment above) so it's present
    // on whichever one holds locality at shot time, but locality itself doesn't
    // gate which machine's copy actually runs — without this guard, both the
    // server and the remoteControlling client's machine independently decrement
    // BUZZ_powerCell for the same shot, silently burning 2 rounds per 1 fired.
    if (!local _unit) exitWith {};

    // if (asin ((_unit weaponDirection _weapon) select 2) < -15) exitWith {
    //     deleteVehicle _projectile;
    //     _unit setAmmo [_weapon, (_unit ammo _weapon) + 1];
    // };

    if (_unit getVariable ["BUZZ_reloading", false]) exitWith {
        deleteVehicle _projectile;
        _unit setAmmo [_weapon, (_unit ammo _weapon) + 1];
    };

    private _prevCell = _unit getVariable ["BUZZ_powerCell", 300];
    private _cell     = _prevCell;
    if (_prevCell > 0) then {
        _cell = _prevCell - 1;
        _unit setVariable ["BUZZ_powerCell", _cell, true];
    };

    if (_cell <= 0) then {
        private _mag = "BUZZ_ATRT_T15ReserveMag";
        private _box = _unit getVariable ["supplyBox", objNull];

        private _cargo = if (!isNull _box) then { getMagazineCargo _box } else { [[], []] };
        private _magIdx = (_cargo select 0) find _mag;
        private _res = if (_magIdx < 0) then { 0 } else { (_cargo select 1) select _magIdx };

        if (_res > 0) then {
            _unit setVariable ["BUZZ_reloading",   true, true];
            _unit setVariable ["BUZZ_reloadStart", time, true];

            if (!isNull _box) then {
                clearMagazineCargoGlobal _box;
                if (_res - 1 > 0) then { _box addMagazineCargoGlobal [_mag, _res - 1]; };
            };

            [_unit] spawn {
                params ["_u"];
                sleep 5;
                _u setVariable ["BUZZ_powerCell", 300,   true];
                _u setVariable ["BUZZ_reloading", false, true];
            };

        } else {
            if (_prevCell <= 0) then {
                deleteVehicle _projectile;
                _unit setAmmo [_weapon, (_unit ammo _weapon) + 1];
            };
        };
    };
}];


// ─────────────────────────────────────────────────────────────────────────────
//  ANIM OVERRIDE  (all machines)
//  ArmA's animation state machine forces a walk/stop animation when a man-class
//  unit fires while running.  AnimChanged fires on the locality-owning machine
//  the instant the transition is selected.  If the unit is moving at jogging
//  speed or faster, we override back to the running+weapon-raised state.
//  AmovPercMrunSrasWrflDf is ArmA 3's standard run+rifle-raised animation;
//  if 3AS uses a different state name this value can be adjusted.
// ─────────────────────────────────────────────────────────────────────────────
_atrt addEventHandler ["AnimChanged", {
    params ["_unit", "_anim"];
    if (speed _unit < 5) exitWith {};
    private _low = toLower _anim;
    if ((_low find "mwlk" >= 0) || (_low find "mstp" >= 0)) then {
        _unit switchMove "AmovPercMrunSrasWrflDf";
    };
}];


// ─────────────────────────────────────────────────────────────────────────────
//  DAMAGE HANDLER  (all machines)
//  Always returns 0 so ArmA's internal damage model never advances.
//  Registered globally so the EH is present on every machine; remoteControl
//  can transfer locality to the client and HandleDamage fires on whichever
//  machine currently holds it.
// ─────────────────────────────────────────────────────────────────────────────
_atrt addEventHandler ["HandleDamage", {
    params ["_unit", "_selection", "_damage", "_source", "_projectile"];

    if (_unit getVariable ["BUZZ_dying", false]) exitWith { 0 };

    // Re-assert allowDamage false on every hit — 3AS postInit scripts call
    // allowDamage true on the unit under certain conditions.  HandleDamage fires
    // on the locality-owning machine so this local call lands in the right place.
    _unit allowDamage false;

    // Block own-weapon splash — no HP cost, but still spawn a brief recovery so
    // the blast impulse doesn't leave the unit in an indefinite incapacitation
    // state.  Without this the own-weapon path exits here with no recovery code,
    // while a GL from another unit would unfreeze it via the full HandleDamage
    // path.  0.05 s is enough for the impulse to be applied before we clear it.
    if (!isNull _source && _source isEqualTo _unit) exitWith {
        [_unit] spawn {
            params ["_u"];
            sleep 0.05;
            if (!(_u getVariable ["BUZZ_dying", false]) && alive _u) then {
                _u setVariable ["ace_unconscious", false, true];
                _u setUnconscious false;
                _u setUnitPos "UP";
                if (local _u) then { [_u, ""] remoteExec ["switchMove", 0]; };
                _u allowDamage false;
            };
        };
        0
    };
    // Block pure physics hits: no projectile and no external source. This is
    // also what a hard landing from the jump ability looks like — same
    // indefinite-incapacitation risk as the own-weapon-splash case above, so
    // it gets the same recovery spawn rather than a bare exit.
    if (_projectile == "" && isNull _source) exitWith {
        [_unit] spawn {
            params ["_u"];
            sleep 0.05;
            if (!(_u getVariable ["BUZZ_dying", false]) && alive _u) then {
                _u setVariable ["ace_unconscious", false, true];
                _u setUnconscious false;
                _u setUnitPos "UP";
                if (local _u) then { [_u, ""] remoteExec ["switchMove", 0]; };
                _u allowDamage false;
            };
        };
        0
    };

    // Classify first — we need the type before we write the new throttle
    // timestamp, because explosives get a 2.5 s future stamp while regular hits
    // get the current time.  The check itself (< 0.200) works identically for both.
    private _ammoCfg       = configFile >> "CfgAmmo" >> _projectile;
    private _indirect      = getNumber (_ammoCfg >> "indirectHit");
    private _hit           = getNumber (_ammoCfg >> "hit");
    private _indirectRange = getNumber (_ammoCfg >> "indirectHitRange");
    private _isExplosive      = (_indirect > 5 || _projectile == "");
    // Heavy explosive: indirectHit > 100 (large-blast rockets like FST_rocket_HE: 180)
    //                  OR direct hit > 100 (AP/HEAT rockets like FST_rocket: 500).
    // GL grenades have indirectHit ~30 and hit ~4 — well below both thresholds.
    private _isHeavyExplosive = _isExplosive && (_indirect > 100 || _hit > 100);

    if (_unit getVariable ["ace_unconscious", false]) then {
        _unit setVariable ["ace_unconscious", false, true];
        _unit setUnconscious false;
    };

    // Throttle: 200 ms for regular hits.  For explosive hits, push the window
    // 2.5 s into the future — this absorbs all ACE frag fragments spawned by
    // one detonation into a single damage event so they cannot chain-kill.
    private _lastHit = _unit getVariable ["BUZZ_lastHit", -1.0];
    if (time - _lastHit < 0.200) exitWith { 0 };
    _unit setVariable ["BUZZ_lastHit", if (_isExplosive) then { time + 2.5 } else { time }];

    // Explosives trigger ACE concussion/stagger — schedule a one-shot animation
    // reset after the stagger duration so the walker can move again.
    if (_isExplosive) then {
        [_unit] spawn {
            params ["_u"];
            // 0.5 s gives ACE's own HandleDamage EH time to fire and set
            // ace_unconscious, then we immediately cancel the stagger animation.
            sleep 0.5;
            if (!(_u getVariable ["BUZZ_dying", false]) && alive _u) then {
                _u setVariable ["ace_unconscious", false, true];
                _u setUnconscious false;
                _u setUnitPos "UP";
                [_u, ""] remoteExec ["switchMove", 0];
                // Re-assert allowDamage false post-impulse.  The GL explosion
                // physics impulse is applied after HandleDamage returns, and
                // calling allowDamage forces the engine to clear any resulting
                // frozen physics state (mirrors the Zeus Damage toggle fix).
                _u allowDamage false;
            };
        };
    };

    // Flat HP cost per tier.  allowDamage false keeps _damage permanently 0
    // so we can no longer derive cost from _damage * scale — assign directly.
    // Tune these values to adjust AT-RT durability:
    //   small arms         0.04  → ~25 hits to kill
    //   heavy calibre      0.10  → ~10 hits to kill
    //   light explosive    0.32  →  ~4 GL direct impacts to kill
    //   heavy explosive    0.80  →  two rockets to kill
    // No min cap — the 2.5 s throttle window already absorbs ACE frags into one event.
    private _hpDelta =
        if     (_isHeavyExplosive) then { 0.80  }
        else { if (_isExplosive)   then { 0.32  }
        else { if (_hit > 150)     then { 0.10  }
        else                            { 0.04 }}};

    // Update BUZZ_hp; broadcast throttled to 10/sec (always immediate on death).
    private _hp = ((_unit getVariable ["BUZZ_hp", 1.0]) - _hpDelta) max 0;
    _unit setVariable ["BUZZ_hp", _hp];

    private _lastBcast = _unit getVariable ["BUZZ_lastBcast", -1.0];
    if (_hp <= 0 || time - _lastBcast >= 0.1) then {
        _unit setVariable ["BUZZ_hp", _hp, true];
        _unit setVariable ["BUZZ_lastBcast", time];
    };

    if (_hp <= 0) then {
        _unit setVariable ["BUZZ_dying", true, true];
        // Capture object references NOW before the spawn sleep — if the engine
        // kills _unit in the 0.05 s window, getVariable on a dead unit returns
        // objNull and the supply box would be orphaned in the world.
        private _dyingBox    = _unit getVariable ["supplyBox", objNull];
        private _dyingShield = _unit getVariable ["shield",    objNull];
        private _dyingRider  = _unit getVariable ["rider",     objNull];
        [_unit, _dyingBox, _dyingShield, _dyingRider] spawn {
            params ["_u", "_box", "_shield", "_rider"];
            sleep 0.05;
            deleteVehicle _box;
            if (!isNull _rider) then {
                [_rider, ""] remoteExec ["switchMove", owner _rider];
                detach _rider;
                _u setVariable ["rider",  nil, true];
                _u setVariable ["shield", nil, true];

                // HandleDamage fires on the locality owner; during remoteControl
                // that is the rider's client, so `local _rider` is true here.
                // Release remoteControl inline, BEFORE setDamage 1, so the AT-RT
                // is still alive when objNull remoteControl runs — calling it on a
                // dead (not deleted) unit is unreliable and causes the camera lock.
                // The server path (locality unexpectedly on server) sleeps 0.5 s to
                // give the remoteExec time to arrive before we kill the AT-RT.
                // Post-death watcher: runs on the rider's machine for up to 30 s.
                // Watches for vehicle _r == _atrt (remoteControl still or re-established)
                // OR camera stuck on _atrt.  ACE stores the player's control state when
                // they go unconscious and can RESTORE player remoteControl _atrt on
                // recovery — the watcher catches that and re-releases.
                private _fnAceWatch = {
                    params ["_a", "_r"];
                    private _timeout = time + 30;
                    waitUntil {
                        sleep 0.3;
                        private _stuck = vehicle _r isEqualTo _a || cameraOn isEqualTo _a;
                        !_stuck || !alive _r || time > _timeout
                    };
                    // Exit if player died or if everything is already resolved
                    if (!alive _r || !(vehicle _r isEqualTo _a || cameraOn isEqualTo _a)) exitWith {};
                    // Still stuck — force full release
                    _r setVariable ["ace_unconscious", false, true];
                    _r setUnconscious false;
                    objNull remoteControl _a;
                    _r remoteControl _r;
                    sleep 0.1;
                    if (cameraOn != vehicle _r) then { (vehicle _r) switchCamera cameraView; };
                    inGameUISetEventHandler ["Action", ""];
                };

                if (local _rider) then {
                    if (_rider getVariable ["ace_unconscious", false]) then {
                        _rider setVariable ["ace_unconscious", false, true];
                        _rider setUnconscious false;
                        sleep 0.2;
                    };
                    objNull remoteControl _u;
                    _rider remoteControl _rider;
                    private _camRetry = 0;
                    while { cameraOn != vehicle _rider && _camRetry < 8 } do {
                        sleep 0.1;
                        (vehicle _rider) switchCamera cameraView;
                        _camRetry = _camRetry + 1;
                    };
                    if (hasInterface) then {
                        private _dn   = _u getVariable ["BUZZ_jumpDnEH",   -1];
                        private _up   = _u getVariable ["BUZZ_jumpUpEH",   -1];
                        private _draw = _u getVariable ["BUZZ_jumpDrawEH", -1];
                        if (_dn   >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyDown", _dn]; };
                        if (_up   >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyUp",   _up]; };
                        if (_draw >= 0) then { removeMissionEventHandler ["Draw3D", _draw]; };
                        _u setVariable ["BUZZ_jumpDnEH",   nil];
                        _u setVariable ["BUZZ_jumpUpEH",   nil];
                        _u setVariable ["BUZZ_jumpDrawEH", nil];
                        uiNamespace setVariable ["BUZZ_jumpAiming", false];
                        uiNamespace setVariable ["BUZZ_jumpAtrt",   objNull];
                        private _ind = uiNamespace getVariable ["BUZZ_jumpInd", objNull];
                        if (!isNull _ind) then { deleteVehicle _ind; };
                        uiNamespace setVariable ["BUZZ_jumpInd", objNull];
                    };
                    inGameUISetEventHandler ["Action", ""];
                    [_u, _rider] spawn _fnAceWatch;
                } else {
                    [_u, _rider] remoteExec [{
                        params ["_a", "_r"];
                        if (_r getVariable ["ace_unconscious", false]) then {
                            _r setVariable ["ace_unconscious", false, true];
                            _r setUnconscious false;
                            sleep 0.2;
                        };
                        objNull remoteControl _a;
                        _r remoteControl _r;
                        private _camRetry = 0;
                        while { cameraOn != vehicle _r && _camRetry < 8 } do {
                            sleep 0.1;
                            (vehicle _r) switchCamera cameraView;
                            _camRetry = _camRetry + 1;
                        };
                        if (hasInterface) then {
                            private _dn   = _a getVariable ["BUZZ_jumpDnEH",   -1];
                            private _up   = _a getVariable ["BUZZ_jumpUpEH",   -1];
                            private _draw = _a getVariable ["BUZZ_jumpDrawEH", -1];
                            if (_dn   >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyDown", _dn]; };
                            if (_up   >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyUp",   _up]; };
                            if (_draw >= 0) then { removeMissionEventHandler ["Draw3D", _draw]; };
                            _a setVariable ["BUZZ_jumpDnEH",   nil];
                            _a setVariable ["BUZZ_jumpUpEH",   nil];
                            _a setVariable ["BUZZ_jumpDrawEH", nil];
                            uiNamespace setVariable ["BUZZ_jumpAiming", false];
                            uiNamespace setVariable ["BUZZ_jumpAtrt",   objNull];
                            private _ind = uiNamespace getVariable ["BUZZ_jumpInd", objNull];
                            if (!isNull _ind) then { deleteVehicle _ind; };
                            uiNamespace setVariable ["BUZZ_jumpInd", objNull];
                        };
                        inGameUISetEventHandler ["Action", ""];
                        [_a, _r] spawn {
                            params ["_a", "_r"];
                            private _timeout = time + 30;
                            waitUntil {
                                sleep 0.3;
                                private _stuck = vehicle _r isEqualTo _a || cameraOn isEqualTo _a;
                                !_stuck || !alive _r || time > _timeout
                            };
                            if (!alive _r || !(vehicle _r isEqualTo _a || cameraOn isEqualTo _a)) exitWith {};
                            _r setVariable ["ace_unconscious", false, true];
                            _r setUnconscious false;
                            objNull remoteControl _a;
                            _r remoteControl _r;
                            sleep 0.1;
                            if (cameraOn != vehicle _r) then { (vehicle _r) switchCamera cameraView; };
                            inGameUISetEventHandler ["Action", ""];
                        };
                    }, owner _rider];
                    sleep 0.2;
                };

                deleteVehicle _shield;
            };
            _u setDamage 1;
        };
    };

    0
}];


// ─────────────────────────────────────────────────────────────────────────────
//  ACTIONS
//  The parent FST/3AS mod re-stamps Drive/Dismount/Inventory via CfgFunctions
//  postInit on every client.  class EventHandlers {} only blocks their init EH,
//  not their CfgFunctions scripts.  Three passes guarantee our actions outlast
//  any delayed parent-mod scripts.
// ─────────────────────────────────────────────────────────────────────────────
[_atrt] spawn {
    params ["_atrt"];
    waitUntil { time > 0 };

    private _fnInstall = {
        params ["_v"];
        removeAllActions _v;


// ── SADDLE UP (Drive) ─────────────────────────────────────────────────────────
_v addAction [
    "Saddle Up",
    {
        params ["_atrt", "_rider"];

        if (!(isNil { _atrt getVariable "rider" })) exitWith {};

        _atrt setVariable ["rider", _rider, true];

        [_rider, "driver_Quadbike"] remoteExec ["switchMove", 0];
        _rider attachTo [_atrt, [0, 0, 0], "seat"];

        private _shield = "3AS_ATRT_Collision" createVehicle (position _atrt);
        [_shield, false] remoteExec ["allowDamage", 0];
        _shield attachTo [_atrt, [0.0, 0.3, -2.3], "seat"];
        _atrt setVariable ["shield", _shield, true];

        // Release the player from their own body before handing control to the AT-RT.
        objNull remoteControl driver _rider;
        player remoteControl _atrt;

        if (cameraOn != vehicle _atrt) then { (vehicle _atrt) switchCamera cameraView; };
        _atrt enableStamina false;
        _atrt forceWalk false;

        _atrt setVariable ["ace_unconscious", false, true];

        // Aim-following light switches on automatically when mounting in the dark.
        // (No effect while light.sqf is disabled in the init above.)
        _atrt setVariable ["BUZZ_lightOn", sunOrMoon < 0.5, true];

        // Poll while mounted: evict ACE/engine stagger states and prevent prone.
        [_atrt] spawn {
            params ["_a"];
            private _stuckAnimTicks = 0;
            while { !isNull (_a getVariable ["rider", objNull]) && alive _a } do {
                sleep 0.25;
                _a setVariable ["BUZZ_pollHeartbeat", time];
                _a forceWalk false;
                _a enableStamina false;
                _a setUnitPos "UP";
                _a allowDamage false;
                // Blast incapacitation sets ace_unconscious directly on the unit;
                // clearing it every tick ensures it resolves within 0.25 s on
                // whichever machine holds locality (the rider's client during
                // remoteControl).
                _a setUnconscious false;
                if (behaviour _a != "CARELESS") then { _a setBehaviour "CARELESS"; };
                if (_a getVariable ["ace_unconscious", false]) then {
                    _a setVariable ["ace_unconscious", false, true];
                    [_a, ""] remoteExec ["switchMove", 0];
                };

                // A hard collision (bounce off terrain at speed, not just a soft
                // landing) can wedge the walker's custom animation controller shut:
                // animationState returns "", velocity locks to [0,0,0], and nothing
                // else here catches it since damage/ace_unconscious/lifeState all
                // read as perfectly healthy. switchMove alone doesn't recover it —
                // confirmed by testing: forcing a known-good move name every 0.25s
                // produced zero AnimChanged/AnimStateChanged events for 12+ seconds
                // straight, meaning switchMove itself was silently failing, not just
                // picking the wrong state. So: try switchMove first (cheap, usually
                // enough for a plain empty-state blip), but if it hasn't taken effect
                // within one more tick, escalate to toggling enableSimulationGlobal —
                // the same "unstick a wedged unit" reset already used for the rider
                // in the force-eject path below — which fully resets the unit's
                // animation/physics object rather than asking its (apparently dead)
                // controller to pick a new move.
                if ((animationState _a) == "") then {
                    _stuckAnimTicks = _stuckAnimTicks + 1;
                    if (_stuckAnimTicks >= 2) then {
                        _a enableSimulationGlobal false;
                        _a enableSimulationGlobal true;
                        [_a, "walker_idle"] remoteExec ["switchMove", 0];
                    } else {
                        [_a, "walker_idle"] remoteExec ["switchMove", 0];
                    };
                } else {
                    _stuckAnimTicks = 0;
                };

            };
        };

        inGameUISetEventHandler ["Action", "if ((_this select 3) isEqualTo ""BackFromUAV"") then {true};"];

        if (hasInterface && player isEqualTo _rider) then {
            [_atrt, _rider] execVM "\BUZZ_Vehicles\ATRT\scripts\hud.sqf";

            // ── Variable jump system ──────────────────────────────────────────
            // Hold V to aim (arc indicator appears), release to fire.
            // Horizontal and vertical launch speeds are decoupled: Vh = 21 m/s, Vv = 13.5 m/s
            // (~25% below the original Vh=28/Vv=18, ratio kept constant).
            // Flat angle (~15°) gives ~15 m range; 45° gives ~29 m; 90° gives ~10 m height.
            // The ACTUAL launch angle (not the raw camera pitch — see the KeyUp
            // handler) is clamped to 15° minimum to prevent near-flat launches.
            // uiNamespace is used to share state across the three EH closures.
            uiNamespace setVariable ["BUZZ_jumpAiming", false];
            uiNamespace setVariable ["BUZZ_jumpAtrt",   _atrt];

            private _jumpInd = "VR_3DSelector_01_default_F" createVehicleLocal [0, 0, -1000];
            _jumpInd allowDamage false;
            _jumpInd enableSimulation false;
            uiNamespace setVariable ["BUZZ_jumpInd", _jumpInd];

            private _jumpDnEH = (findDisplay 46) displayAddEventHandler ["KeyDown", {
                params ["_d", "_k"];
                if (_k != 47) exitWith { false };
                private _a = uiNamespace getVariable ["BUZZ_jumpAtrt", objNull];
                if (isNull _a) exitWith { false };
                if (time >= (_a getVariable ["BUZZ_jumpCooldown", 0])) then {
                    uiNamespace setVariable ["BUZZ_jumpAiming", true];
                };
                true
            }];

            private _jumpUpEH = (findDisplay 46) displayAddEventHandler ["KeyUp", {
                params ["_d", "_k"];
                if (_k != 47) exitWith { false };
                if (!(uiNamespace getVariable ["BUZZ_jumpAiming", false])) exitWith { false };
                uiNamespace setVariable ["BUZZ_jumpAiming", false];
                private _ind = uiNamespace getVariable ["BUZZ_jumpInd", objNull];
                if (!isNull _ind) then { _ind setPosASL [0, 0, -1000]; };
                private _a = uiNamespace getVariable ["BUZZ_jumpAtrt", objNull];
                if (isNull _a) exitWith { false };
                if (time < (_a getVariable ["BUZZ_jumpCooldown", 0])) exitWith { false };

                private _camPos = positionCameraToWorld [0, 0, 0];
                private _camFwd = positionCameraToWorld [0, 0, 1];
                private _dir    = _camFwd vectorDiff _camPos;

                // Vh != Vv means the camera's raw pitch is NOT the actual launch
                // angle — clamping the camera direction's pitch (as before) still
                // lets the post-scale result come out far flatter than intended.
                // Clamp the ACTUAL resulting velocity angle instead: compute
                // unclamped, then top up vertical speed only if the real angle
                // is still under 15°. Horizontal speed/yaw is left untouched, so
                // normal (non-minimum) inputs are completely unaffected.
                private _vel  = [(_dir select 0) * 21, (_dir select 1) * 21, (_dir select 2) * 13.5];
                private _velH = sqrt ((_vel select 0)^2 + (_vel select 1)^2);
                if (_velH < 0.001) then {
                    _vel = [0, 0, 13.5];
                } else {
                    if (((_vel select 2) atan2 _velH) < 15) then {
                        _vel set [2, _velH * tan 15];
                    };
                };
                _a setVelocity _vel;
                [_a, _vel] remoteExec ["setVelocity", 2];
                _a setVariable ["BUZZ_jumpCooldown", time + 15, true];
                false
            }];

            private _jumpDrawEH = addMissionEventHandler ["Draw3D", {
                if (!(uiNamespace getVariable ["BUZZ_jumpAiming", false])) exitWith {};
                private _a = uiNamespace getVariable ["BUZZ_jumpAtrt", objNull];
                if (isNull _a) exitWith {};

                private _camPos = positionCameraToWorld [0, 0, 0];
                private _camFwd = positionCameraToWorld [0, 0, 1];
                private _dir    = _camFwd vectorDiff _camPos;

                // Same actual-angle clamp as the KeyUp launch handler — see the
                // comment there. Kept in sync so the preview arc matches the real
                // trajectory, including at the 15° floor.
                private _ind    = uiNamespace getVariable ["BUZZ_jumpInd", objNull];
                private _simPos = getPosASL _a;
                private _simVel = [(_dir select 0) * 21, (_dir select 1) * 21, (_dir select 2) * 13.5];
                private _simVelH = sqrt ((_simVel select 0)^2 + (_simVel select 1)^2);
                if (_simVelH < 0.001) then {
                    _simVel = [0, 0, 13.5];
                } else {
                    if (((_simVel select 2) atan2 _simVelH) < 15) then {
                        _simVel set [2, _simVelH * tan 15];
                    };
                };
                private _dt     = 0.12;
                private _prev   = _simPos;

                for "_i" from 1 to 80 do {
                    _simPos = _simPos vectorAdd (_simVel vectorMultiply _dt);
                    _simVel = _simVel vectorAdd [0, 0, -9.81 * _dt];

                    if ((_simPos select 2) <= getTerrainHeight [_simPos select 0, _simPos select 1]) exitWith {
                        if (!isNull _ind) then { _ind setPosASL _simPos; };
                    };
                    // Thin glow connector between steps, plus a visible dot at each step.
                    drawLine3D [ASLToAGL _prev, ASLToAGL _simPos, [0.65, 0.95, 1.00, 0.45]];
                    drawIcon3D [
                        "\A3\ui_f\data\map\markers\military\circle_CA.paa",
                        [0.35, 0.85, 1.00, 0.92],
                        ASLToAGL _simPos,
                        0.5, 0.5, 0, "", 0, 0, "PuristaMedium"
                    ];
                    _prev = _simPos;
                };
            }];

            _atrt setVariable ["BUZZ_jumpDnEH",   _jumpDnEH];
            _atrt setVariable ["BUZZ_jumpUpEH",   _jumpUpEH];
            _atrt setVariable ["BUZZ_jumpDrawEH", _jumpDrawEH];

            // ── Force eject (Ctrl+ESC) ───────────────────────────────────────────
            // Unconditional escape hatch: unlike Buck Off (blocked by ACE while
            // unconscious/incapacitated, since it's gated behind the action menu)
            // and the auto-eject watcher below (which depends on correctly
            // detecting death/unconscious state), this fires on a raw display key
            // press, so it works no matter what state the rider or the AT-RT are
            // in. Reuses BUZZ_jumpAtrt (already set above) rather than adding a
            // second uiNamespace variable.
            // Gated on Ctrl so plain ESC still opens the normal pause/debug menu —
            // a bare ESC binding here swallows that menu entirely while mounted.
            private _ejectEH = (findDisplay 46) displayAddEventHandler ["KeyDown", {
                params ["_d", "_k", "_shift", "_ctrl"];
                if (_k != 1 || {!_ctrl}) exitWith { false };
                private _a = uiNamespace getVariable ["BUZZ_jumpAtrt", objNull];
                if (isNull _a) exitWith { false };
                private _r = _a getVariable ["rider", objNull];
                if (isNull _r || { !local _r }) exitWith { false };

                [_r, ""] remoteExec ["switchMove", 0];
                _r setVariable ["ace_unconscious", false, true];
                _r setUnconscious false;
                _r enableSimulationGlobal false;
                detach _r;
                _r setVelocity [0, 0, 0];
                if (alive _a) then { _r setPosATL (_a modelToWorld [0.5, -4.0, 0]); };
                objNull remoteControl driver _a;
                _r remoteControl _r;
                _r enableSimulationGlobal true;
                if (cameraOn != vehicle _r) then { (vehicle _r) switchCamera cameraView; };

                deleteVehicle (_a getVariable ["shield", objNull]);
                _a setVariable ["rider",  nil, true];
                _a setVariable ["shield", nil, true];

                private _dn   = _a getVariable ["BUZZ_jumpDnEH",   -1];
                private _up   = _a getVariable ["BUZZ_jumpUpEH",   -1];
                private _draw = _a getVariable ["BUZZ_jumpDrawEH", -1];
                private _esc  = _a getVariable ["BUZZ_ejectEH",    -1];
                if (_dn   >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyDown", _dn]; };
                if (_up   >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyUp",   _up]; };
                if (_draw >= 0) then { removeMissionEventHandler ["Draw3D", _draw]; };
                if (_esc  >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyDown", _esc]; };
                _a setVariable ["BUZZ_jumpDnEH",   nil];
                _a setVariable ["BUZZ_jumpUpEH",   nil];
                _a setVariable ["BUZZ_jumpDrawEH", nil];
                _a setVariable ["BUZZ_ejectEH",    nil];
                uiNamespace setVariable ["BUZZ_jumpAiming", false];
                uiNamespace setVariable ["BUZZ_jumpAtrt",   objNull];
                private _ind = uiNamespace getVariable ["BUZZ_jumpInd", objNull];
                if (!isNull _ind) then { deleteVehicle _ind; };
                uiNamespace setVariable ["BUZZ_jumpInd", objNull];
                inGameUISetEventHandler ["Action", ""];

                true
            }];
            _atrt setVariable ["BUZZ_ejectEH", _ejectEH];
        };

        // Auto-eject when rider is killed or incapacitated
        [_atrt, _rider] spawn {
            params ["_atrt", "_rider"];

            waitUntil {
                sleep 0.25;
                !alive _rider ||
                lifeState _rider == "INCAPACITATED" ||
                _rider getVariable ["ace_unconscious", false] ||
                !alive _atrt
            };

            // Rider already dismounted voluntarily (Buck Off cleared the variable) —
            // no repositioning needed and modelToWorld on a deleted AT-RT would return origin.
            if (isNull (_atrt getVariable ["rider", objNull])) exitWith {};
            // AT-RT just died — give the server death spawn up to 1 s to set
            // rider=nil and handle camera teardown.  If it does, exit to avoid
            // double-cleanup racing the death remoteExec.
            if (!alive _atrt) then {
                private _dt = time + 1.0;
                waitUntil { isNull (_atrt getVariable ["rider", objNull]) || time > _dt };
                if (isNull (_atrt getVariable ["rider", objNull])) exitWith {};
            };

            [_rider, ""] remoteExec ["switchMove", 0];
            detach _rider;
            // Guard setPos: if AT-RT is deleted (e.g. repack fired while mounted),
            // modelToWorld returns world origin and would teleport the rider.
            if (alive _atrt && alive _rider) then { _rider setPos (_atrt modelToWorld [0, -4.0, 0]); };
            objNull remoteControl driver _atrt;
            _rider remoteControl _rider;
            if (cameraOn != vehicle _rider) then { (vehicle _rider) switchCamera cameraView; };

            deleteVehicle (_atrt getVariable ["shield", objNull]);
            _atrt setVariable ["rider",  nil, true];
            _atrt setVariable ["shield", nil, true];
            if (hasInterface) then {
                private _dn   = _atrt getVariable ["BUZZ_jumpDnEH",   -1];
                private _up   = _atrt getVariable ["BUZZ_jumpUpEH",   -1];
                private _draw = _atrt getVariable ["BUZZ_jumpDrawEH", -1];
                private _esc  = _atrt getVariable ["BUZZ_ejectEH",    -1];
                if (_dn   >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyDown", _dn]; };
                if (_up   >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyUp",   _up]; };
                if (_draw >= 0) then { removeMissionEventHandler ["Draw3D", _draw]; };
                if (_esc  >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyDown", _esc]; };
                _atrt setVariable ["BUZZ_jumpDnEH",   nil];
                _atrt setVariable ["BUZZ_jumpUpEH",   nil];
                _atrt setVariable ["BUZZ_jumpDrawEH", nil];
                _atrt setVariable ["BUZZ_ejectEH",    nil];
                uiNamespace setVariable ["BUZZ_jumpAiming", false];
                uiNamespace setVariable ["BUZZ_jumpAtrt",   objNull];
                private _ind = uiNamespace getVariable ["BUZZ_jumpInd", objNull];
                if (!isNull _ind) then { deleteVehicle _ind; };
                uiNamespace setVariable ["BUZZ_jumpInd", objNull];
            };
            inGameUISetEventHandler ["Action", ""];
        };
    },
    [],
    1.5,
    true,
    true,
    "",
    "alive _this && { isNil { _this getVariable 'rider' } } && { !(_this getVariable ['BUZZ_dying', false]) }",
    4,
    false,
    "",
    ""
];


// ── BUCK OFF (Dismount) ───────────────────────────────────────────────────────
_v addAction [
    "Buck Off",
    {
        params ["_atrt", "_caller"];

        private _rider = _atrt getVariable ["rider", objNull];
        if (isNull _rider) exitWith {};

        [_rider, ""] remoteExec ["switchMove", 0];
        private _behindPos = _atrt modelToWorld [0.5, -4.0, 0];
        detach _rider;
        _rider setPos _behindPos;
        objNull remoteControl driver _atrt;
        _rider remoteControl _rider;
        if (cameraOn != vehicle _rider) then { (vehicle _rider) switchCamera cameraView; };

        deleteVehicle (_atrt getVariable ["shield", objNull]);
        _atrt setVariable ["rider",  nil, true];
        _atrt setVariable ["shield", nil, true];
        if (hasInterface) then {
            private _dn   = _atrt getVariable ["BUZZ_jumpDnEH",   -1];
            private _up   = _atrt getVariable ["BUZZ_jumpUpEH",   -1];
            private _draw = _atrt getVariable ["BUZZ_jumpDrawEH", -1];
            private _esc  = _atrt getVariable ["BUZZ_ejectEH",    -1];
            if (_dn   >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyDown", _dn]; };
            if (_up   >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyUp",   _up]; };
            if (_draw >= 0) then { removeMissionEventHandler ["Draw3D", _draw]; };
            if (_esc  >= 0) then { (findDisplay 46) displayRemoveEventHandler ["KeyDown", _esc]; };
            _atrt setVariable ["BUZZ_jumpDnEH",   nil];
            _atrt setVariable ["BUZZ_jumpUpEH",   nil];
            _atrt setVariable ["BUZZ_jumpDrawEH", nil];
            _atrt setVariable ["BUZZ_ejectEH",    nil];
            uiNamespace setVariable ["BUZZ_jumpAiming", false];
            uiNamespace setVariable ["BUZZ_jumpAtrt",   objNull];
            private _ind = uiNamespace getVariable ["BUZZ_jumpInd", objNull];
            if (!isNull _ind) then { deleteVehicle _ind; };
            uiNamespace setVariable ["BUZZ_jumpInd", objNull];
        };
        inGameUISetEventHandler ["Action", ""];
    },
    [],
    1.5,
    true,
    true,
    "",
    "!isNil { _this getVariable 'rider' } && { local (_this getVariable ['rider', objNull]) }",
    2,
    false,
    "",
    ""
];



// ── REPACK AT-RT ──────────────────────────────────────────────────────────────
_v addAction [
    "Repack AT-RT",
    {
        params ["_atrt", "_caller"];

        if (_atrt getVariable ["BUZZ_packing", false]) exitWith {};
        if (!isNull (_atrt getVariable ["rider", objNull])) exitWith {};

        _atrt setVariable ["BUZZ_packing", true, true];

        [_atrt, _caller, 10, "PACKING AT-RT"] execVM "\BUZZ_Vehicles\ATRT\scripts\pack_hud.sqf";
        [_caller, "AinvPknlMstpSnonWrflDnon_medic_1"] remoteExec ["switchMove", 0];

        [_atrt, _caller] spawn {
            params ["_atrt", "_caller"];
            private _start = time;

            waitUntil {
                !alive _caller ||
                !alive _atrt  ||
                !(_atrt getVariable ["BUZZ_packing", false]) ||
                time - _start >= 10
            };

            private _cancelled = !alive _caller || !alive _atrt || !(_atrt getVariable ["BUZZ_packing", false]);
            _atrt setVariable ["BUZZ_packing", false, true];
            if (_cancelled) exitWith { [_caller, ""] remoteExec ["switchMove", 0]; };

            private _hp   = _atrt getVariable ["BUZZ_hp",        1.0];
            private _cell = _atrt getVariable ["BUZZ_powerCell",  300];
            private _box  = _atrt getVariable ["supplyBox",    objNull];

            private _reserves = 0;
            if (!isNull _box) then {
                private _cargo = getMagazineCargo _box;
                private _idx   = (_cargo select 0) find "BUZZ_ATRT_T15ReserveMag";
                if (_idx >= 0) then { _reserves = (_cargo select 1) select _idx; };
            };

            [getPosASL _atrt, getDir _atrt, _hp, _cell, _reserves, _atrt] remoteExecCall ["BUZZ_fnc_packServer", 2];
            [_caller, ""] remoteExec ["switchMove", 0];
        };
    },
    [],
    1.5,
    true,
    true,
    "",
    "(isNull (_this getVariable ['rider', objNull])) && { (_this getVariable ['BUZZ_hp', 1.0]) > 0.01 } && { !(_this getVariable ['BUZZ_packing', false]) } && { !(_this getVariable ['BUZZ_dying', false]) }",
    6,
    false,
    "",
    ""
];


// ── OPEN INVENTORY ────────────────────────────────────────────────────────────
_v addAction [
    "Open ATRT Inventory",
    {
        params ["_atrt", "_caller"];
        // supplyBox/cargo are created server-side and reach this client via global
        // setVariable/addMagazineCargoGlobal broadcasts fired in the same frame as
        // the box's own creation — those can race the box's network replication and
        // be silently dropped for a client that hadn't registered the object yet.
        // Ask the server to resync on every click — by definition the player can
        // only click this on an object they already know about, so a click-time
        // resync is far more reliable than a fixed-delay one. addAction code runs
        // unscheduled, so the poll for the resync to land is done in a spawned block.
        [_atrt] remoteExecCall ["BUZZ_fnc_resyncBoxServer", 2];
        [_atrt, _caller] spawn {
            params ["_atrt", "_caller"];
            private _tWait = time;
            waitUntil { !isNull (_atrt getVariable ["supplyBox", objNull]) || time - _tWait > 5 };
            private _box = _atrt getVariable ["supplyBox", objNull];
            if (isNull _box) exitWith { hint "Inventory not available yet — try again in a moment."; };
            // supplyBox being non-null only means the *reference* is known — it says
            // nothing about whether BUZZ_fnc_resyncBoxServer's cargo re-broadcast
            // (sent above) has made its client<->server round trip yet. Without this
            // wait, gear opens on whatever cargo state happened to already be cached
            // locally, which is exactly the empty/stale box this resync was meant to fix.
            sleep 0.3;
            _caller action ["gear", _box];
        };
    },
    [],
    1.5,
    true,
    true,
    "",
    "!(_this getVariable ['BUZZ_dying', false])",
    6,
    false,
    "",
    ""
];


// ── LOAD INTO LAAT/i ──────────────────────────────────────────────────────────
// Direct walk-in/walk-out LAAT/i loading system (this action, fn_laatiLoadAction/
// Anim/Server + the "Deploy AT-RT" action installed by fn_laatiInstallDeploy).
_v addAction [
    "Load into LAAT/i",
    "\BUZZ_Vehicles\ATRT\scripts\fn_laatiLoadAction.sqf",
    [],
    1.5,
    true,
    true,
    "",
    "!isNil { _this getVariable 'rider' } && { local (_this getVariable ['rider', objNull]) }",
    6,
    false,
    "",
    ""
];


    }; // end _fnInstall

    [_atrt] call _fnInstall;
    sleep 5;
    [_atrt] call _fnInstall;
    sleep 10;
    [_atrt] call _fnInstall;
    // Periodic re-stamp: 3AS CfgFunctions postInit can add its Drive/Dismount
    // actions at any time after mission load.  Refreshing every 60 s ensures our
    // actions stay on top even if postInit runs late.
    while { alive _atrt } do {
        sleep 60;
        [_atrt] call _fnInstall;
    };
}; // end spawn


// ── ACE REPAIR INTERACTION ─────────────────────────────────────────────────────
// Registered via ace_interact_menu_fnc_addActionToObject, which survives any
// removeAllActions call from the parent mod (3AS/FST).  ACE is a hard dependency.
if (hasInterface) then {
    [_atrt] spawn {
        params ["_atrt"];
        waitUntil { !isNil "ace_interact_menu_fnc_createAction" };

        private _repairAction = [
            "BUZZ_repairATRT",
            "Repair ATRT",
            "\a3\ui_f\data\igui\cfg\simpleTasks\types\repair_ca.paa",
            {
                params ["_target", "_player", "_params"];

                private _hp = _target getVariable ["BUZZ_hp", 1.0];
                private _repairTime = 7 + ((0.75 - (_hp max 0.01)) / 0.74) * 18;

                _target setVariable ["BUZZ_repairing",   true,        true];
                _target setVariable ["BUZZ_repairStart", time,        true];
                _target setVariable ["BUZZ_repairer",    _player,     true];

                [_target, _player, _repairTime] execVM "\BUZZ_Vehicles\ATRT\scripts\repair_hud.sqf";

                [_target, _repairTime, _player, _hp] spawn {
                    params ["_atrt", "_repTime", "_caller", "_startHp"];
                    private _startTime = _atrt getVariable ["BUZZ_repairStart", time];

                    while {
                        alive _caller &&
                        alive _atrt &&
                        (_atrt getVariable ["BUZZ_hp",        0    ]) > 0 &&
                        (_atrt getVariable ["BUZZ_repairing", false])
                    } do {
                        private _elapsed  = time - _startTime;
                        private _progress = (_elapsed / _repTime) min 1.0;
                        _atrt setVariable ["BUZZ_hp", (_startHp + _progress * (1.0 - _startHp)), true];

                        if (_progress >= 1.0) then {
                            _atrt setDamage 0;
                            _atrt allowDamage false;
                            _atrt setVariable ["BUZZ_hp",         1.0,   true];
                            _atrt setVariable ["BUZZ_repairing",  false,  true];
                            _atrt setVariable ["BUZZ_repairer",   nil,    true];
                            _atrt setVariable ["BUZZ_reloading",  false,  true];
                            _atrt setVariable ["BUZZ_dying",      false,  true];
                            _atrt setVariable ["ace_unconscious", false,  true];
                            [_atrt, ""] remoteExec ["switchMove", 0];
                        };

                        sleep 0.1;
                    };

                    _atrt setVariable ["BUZZ_repairing", false, true];
                    _atrt setVariable ["BUZZ_repairer",  nil,   true];
                };
            },
            {
                params ["_target", "_player", "_params"];
                (_target getVariable ["BUZZ_hp", 1.0]) < 0.75
                && !(_target getVariable ["BUZZ_repairing", false])
                && !((_target getVariable ["rider", objNull]) isEqualTo _player)
                && ((items _player) findAny ["ToolKit", "FST_SmallToolkit", "FST_LargeToolkit"] > -1)
                && ([_player] call ace_common_fnc_isEngineer)
            },
            {},
            []
        ] call ace_interact_menu_fnc_createAction;

        [_atrt, 0, [], _repairAction] call ace_interact_menu_fnc_addActionToObject;

        private _cancelAction = [
            "BUZZ_cancelRepairATRT",
            "Cancel Repair",
            "\a3\ui_f\data\igui\cfg\simpleTasks\types\repair_ca.paa",
            {
                params ["_target", "_player", "_params"];
                _target setVariable ["BUZZ_repairing", false, true];
                _target setVariable ["BUZZ_repairer",  nil,   true];
            },
            {
                params ["_target", "_player", "_params"];
                (_target getVariable ["BUZZ_repairing", false])
                && ((_target getVariable ["BUZZ_repairer", objNull]) isEqualTo _player)
            },
            {},
            []
        ] call ace_interact_menu_fnc_createAction;

        [_atrt, 0, [], _cancelAction] call ace_interact_menu_fnc_addActionToObject;
    };
};
