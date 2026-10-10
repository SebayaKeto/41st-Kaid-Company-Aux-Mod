// =============================================================================
//  BUZZ AT-RT — init.sqf
// =============================================================================

private _atrt = _this;

// Damage Immunity
_atrt allowDamage false;

// Group Cleanup
if (local group _atrt) then { (group _atrt) deleteGroupWhenEmpty true; };

// Knockdown Recovery
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

// Careless Behaviour
_atrt setBehaviour "CARELESS";

// Map & GPS
_atrt linkItem "ItemMap";
_atrt linkItem "ItemGPS";

// Movement Speed
_atrt setVariable ["runSpeedScale",    1.40];
_atrt setVariable ["sprintSpeedScale", 2.33];

// Client Effects
if (hasInterface) then {
    // [_atrt] execVM "\BUZZ_Vehicles\ATRT\scripts\light.sqf";
    [_atrt] execVM "\BUZZ_Vehicles\ATRT\scripts\disco.sqf";
};



// ─────────────────────────────────────────────────────────────────────────────
//  SERVER SETUP  (server only)
// ─────────────────────────────────────────────────────────────────────────────
if (isServer) then {
    // Supply Box
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

        // Supply Box Resync
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

    // Power Cell & Night Vision
    _atrt setVariable ["BUZZ_powerCell", 300, true];
    _atrt linkItem "FST_NVG_Invisible";

    // Ammo Top-Up
    [_atrt] spawn {
        params ["_a"];
        waitUntil { time > 0 };
        if (!((magazines _a) isEqualTo [])) then { _a setAmmo ["BUZZ_ATRT_T15", 99999]; };
    };

    // Killed Handler
    _atrt addEventHandler ["Killed", {
        params ["_atrt"];
        if (_atrt getVariable ["BUZZ_dying", false]) then {
            // Intended Death
            deleteVehicle (_atrt getVariable ["supplyBox", objNull]);
            deleteVehicle (_atrt getVariable ["shield",    objNull]);
        } else {
            // External Kill
            _atrt setDamage 0;
            _atrt allowDamage false;
            _atrt setVariable ["ace_unconscious", false, true];
            _atrt setUnconscious false;
            _atrt setUnitPos "UP";
            [_atrt, ""] remoteExec ["switchMove", 0];
        };
    }];

    // Health
    _atrt setVariable ["BUZZ_hp", 1.0, true];
    _atrt setVariable ["ace_medical_enabled", false, true];

    // Damage Poll
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
// ─────────────────────────────────────────────────────────────────────────────
_atrt addEventHandler ["Fired", {
    params ["_unit", "_weapon", "", "", "", "", "_projectile"];

    // Shot Sound
    // Replaces the silent config sound. Every machine plays it LOCALLY (the Fired EH is
    // registered everywhere), so a shot costs no network message. The last
    // BUZZ_lowCellShots use the higher pitch pool (the cell is broadcast every shot in the
    // last 30, so remote machines pick the right pool). Skipped while reloading or empty.
    private _knownCell = _unit getVariable ["BUZZ_powerCell", 300];
    if (_knownCell > 0 && {!(_unit getVariable ["BUZZ_reloading", false])}) then {
        private _cfg   = configFile >> "CfgWeapons" >> _weapon;
        private _sound = getText (_cfg >> "BUZZ_shotSound");
        if (_sound != "") then {
            private _pitches = if (_knownCell <= getNumber (_cfg >> "BUZZ_lowCellShots")) then {
                getArray (_cfg >> "BUZZ_lowCellPitches")
            } else {
                getArray (_cfg >> "BUZZ_shotPitches")
            };
            playSound3D [
                _sound, _unit, false,
                (getPosASL _unit) vectorAdd [0, 0, 2],
                getNumber (_cfg >> "BUZZ_shotVolume"),
                selectRandom _pitches,
                getNumber (_cfg >> "BUZZ_shotDistance"),
                0, true
            ];
        };
    };

    // Locality Guard
    if (!local _unit) exitWith {};

    // if (asin ((_unit weaponDirection _weapon) select 2) < -15) exitWith {
    //     deleteVehicle _projectile;
    //     _unit setAmmo [_weapon, (_unit ammo _weapon) + 1];
    // };

    // Reload Lockout
    if (_unit getVariable ["BUZZ_reloading", false]) exitWith {
        deleteVehicle _projectile;
        _unit setAmmo [_weapon, (_unit ammo _weapon) + 1];
    };

    // Power Cell Drain
    private _prevCell = _unit getVariable ["BUZZ_powerCell", 300];
    private _cell     = _prevCell;
    if (_prevCell > 0) then {
        _cell = _prevCell - 1;
        _unit setVariable ["BUZZ_powerCell", _cell, (_cell % 10 == 0) || {_cell <= 30}];
    };

    // Shot Sound
    if (_prevCell > 0) then {
        private _cfg   = configFile >> "CfgWeapons" >> _weapon;
        private _sound = getText (_cfg >> "BUZZ_shotSound");
        if (_sound != "") then {
            private _pitches = if (_prevCell <= getNumber (_cfg >> "BUZZ_lowCellShots")) then {
                getArray (_cfg >> "BUZZ_lowCellPitches")
            } else {
                getArray (_cfg >> "BUZZ_shotPitches")
            };
            playSound3D [
                _sound, _unit, false,
                (getPosASL _unit) vectorAdd [0, 0, 2],
                getNumber (_cfg >> "BUZZ_shotVolume"),
                selectRandom _pitches,
                getNumber (_cfg >> "BUZZ_shotDistance")
            ];
        };
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
// ─────────────────────────────────────────────────────────────────────────────
_atrt addEventHandler ["HandleDamage", {
    params ["_unit", "_selection", "_damage", "_source", "_projectile"];

    if (_unit getVariable ["BUZZ_dying", false]) exitWith { 0 };

    // Immunity Refresh
    _unit allowDamage false;

    // Own-Weapon Splash
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
    // Physics Hits
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

    // Hit Classification
    private _ammoCfg       = configFile >> "CfgAmmo" >> _projectile;
    private _indirect      = getNumber (_ammoCfg >> "indirectHit");
    private _hit           = getNumber (_ammoCfg >> "hit");
    private _indirectRange = getNumber (_ammoCfg >> "indirectHitRange");
    private _isExplosive      = (_indirect > 5 || _projectile == "");
    private _isHeavyExplosive = _isExplosive && (_indirect > 100 || _hit > 100);

    // Clear Unconscious
    if (_unit getVariable ["ace_unconscious", false]) then {
        _unit setVariable ["ace_unconscious", false, true];
        _unit setUnconscious false;
    };

    // Hit Throttle
    private _lastHit = _unit getVariable ["BUZZ_lastHit", -1.0];
    if (time - _lastHit < 0.200) exitWith { 0 };
    _unit setVariable ["BUZZ_lastHit", if (_isExplosive) then { time + 2.5 } else { time }];

    // Stagger Recovery
    if (_isExplosive) then {
        [_unit] spawn {
            params ["_u"];
            sleep 0.5;
            if (!(_u getVariable ["BUZZ_dying", false]) && alive _u) then {
                _u setVariable ["ace_unconscious", false, true];
                _u setUnconscious false;
                _u setUnitPos "UP";
                [_u, ""] remoteExec ["switchMove", 0];
                // Physics Unfreeze
                _u allowDamage false;
            };
        };
    };

    // HP Cost per Hit
    private _hpDelta =
        if     (_isHeavyExplosive) then { 0.80  }
        else { if (_isExplosive)   then { 0.32  }
        else { if (_hit > 150)     then { 0.10  }
        else                            { 0.04 }}};

    // HP Update
    private _hp = ((_unit getVariable ["BUZZ_hp", 1.0]) - _hpDelta) max 0;
    _unit setVariable ["BUZZ_hp", _hp];

    private _lastBcast = _unit getVariable ["BUZZ_lastBcast", -1.0];
    if (_hp <= 0 || time - _lastBcast >= 0.1) then {
        _unit setVariable ["BUZZ_hp", _hp, true];
        _unit setVariable ["BUZZ_lastBcast", time];
    };

    // Death Sequence
    if (_hp <= 0) then {
        _unit setVariable ["BUZZ_dying", true, true];
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

                // Rider Release

                // ACE Stuck-Camera Watcher
                private _fnAceWatch = {
                    params ["_a", "_r"];
                    private _timeout = time + 30;
                    waitUntil {
                        sleep 0.3;
                        private _stuck = vehicle _r isEqualTo _a || cameraOn isEqualTo _a;
                        !_stuck || !alive _r || time > _timeout
                    };
                    // Already Resolved
                    if (!alive _r || !(vehicle _r isEqualTo _a || cameraOn isEqualTo _a)) exitWith {};
                    // Forced Release
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
// ─────────────────────────────────────────────────────────────────────────────
[_atrt] spawn {
    params ["_atrt"];
    // addAction is local and only players use scroll actions: skip the forever
    // re-install loop on the dedicated server and headless clients.
    if (!hasInterface) exitWith {};
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

        // Take Control
        objNull remoteControl driver _rider;
        player remoteControl _atrt;

        if (cameraOn != vehicle _atrt) then { (vehicle _atrt) switchCamera cameraView; };
        _atrt enableStamina false;
        _atrt forceWalk false;

        _atrt setVariable ["ace_unconscious", false, true];

        // Auto Light
        _atrt setVariable ["BUZZ_lightOn", sunOrMoon < 0.5, true];

        // Mounted Poll
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
                // Blast Recovery
                _a setUnconscious false;
                if (behaviour _a != "CARELESS") then { _a setBehaviour "CARELESS"; };
                if (_a getVariable ["ace_unconscious", false]) then {
                    _a setVariable ["ace_unconscious", false, true];
                    [_a, ""] remoteExec ["switchMove", 0];
                };

                // Stuck Animation Fix
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

                // Launch Angle Clamp
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

                // Arc Preview
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
                    // Arc Drawing
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
        };

        // Auto-Eject
        [_atrt, _rider] spawn {
            params ["_atrt", "_rider"];

            waitUntil {
                sleep 0.25;
                !alive _rider ||
                lifeState _rider == "INCAPACITATED" ||
                _rider getVariable ["ace_unconscious", false] ||
                !alive _atrt
            };

            // Already Dismounted
            if (isNull (_atrt getVariable ["rider", objNull])) exitWith {};
            // Walker Died
            if (!alive _atrt) then {
                private _dt = time + 1.0;
                waitUntil { isNull (_atrt getVariable ["rider", objNull]) || time > _dt };
                if (isNull (_atrt getVariable ["rider", objNull])) exitWith {};
            };

            [_rider, ""] remoteExec ["switchMove", 0];
            detach _rider;
            // Safe Reposition
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
        // Box Resync
        [_atrt] remoteExecCall ["BUZZ_fnc_resyncBoxServer", 2];
        [_atrt, _caller] spawn {
            params ["_atrt", "_caller"];
            private _tWait = time;
            waitUntil { !isNull (_atrt getVariable ["supplyBox", objNull]) || time - _tWait > 5 };
            private _box = _atrt getVariable ["supplyBox", objNull];
            if (isNull _box) exitWith { hint "Inventory not available yet — try again in a moment."; };
            // Cargo Wait
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
    // Periodic Re-Install
    while { alive _atrt } do {
        sleep 60;
        [_atrt] call _fnInstall;
    };
}; // end spawn


// ── ACE REPAIR INTERACTION ─────────────────────────────────────────────────────
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
                && (((items _player) findIf { _x isKindOf ["ToolKit", configFile >> "CfgWeapons"] }) > -1)
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
