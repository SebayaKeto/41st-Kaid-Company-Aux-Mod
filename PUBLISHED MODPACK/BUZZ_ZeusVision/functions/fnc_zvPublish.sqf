/*
    BUZZ_fnc_zvPublish
    Runs on every player's machine about once a second (CBA per-frame handler).
    Works out this player's ammo state and broadcasts it ONLY when it changes,
    so the network cost is a handful of tiny updates per fight.

    Broadcast: player getVariable "BUZZ_zv_state" =
        [rifle state, launcher state, launcher loaded, launcher spare]
        state: -1 no weapon, 0 Green, 1 Yellow, 2 Red, 3 Black

    "Full" is the ammo the player had when they spawned (or swapped weapon).
    It is kept locally per unit in "BUZZ_zv_baseline" and only ever grows, so a
    resupply above the starting load becomes the new full.
    Call BUZZ_fnc_zvResetBaseline after giving a new kit to re-snapshot it.
*/
private _unit = player;
if (isNull _unit || { !alive _unit }) exitWith {};

private _baseline = _unit getVariable ["BUZZ_zv_baseline", ["", 0, "", 0]];
_baseline params ["_baseRifle", "_fullRifle", "_baseLauncher", "_fullLauncher"];

private _rifle = primaryWeapon _unit;
private _launcher = secondaryWeapon _unit;
private _rifleRounds = [_unit, _rifle] call BUZZ_fnc_zvCountRounds;
private _launcherRounds = [_unit, _launcher] call BUZZ_fnc_zvCountRounds;

private _rifleState = -1;
if (_rifleRounds isNotEqualTo []) then {
    private _total = (_rifleRounds select 0) + (_rifleRounds select 1);
    if (_rifle != _baseRifle) then { _baseRifle = _rifle; _fullRifle = _total };   // new weapon or first run
    _fullRifle = _fullRifle max _total;
    _rifleState = [_total, _fullRifle] call BUZZ_fnc_zvColour;
};

private _launcherState = -1;
private _launcherLoaded = 0;
private _launcherSpare = 0;
if (_launcherRounds isNotEqualTo []) then {
    _launcherRounds params ["_loaded", "_spare"];
    private _total = _loaded + _spare;
    if (_launcher != _baseLauncher) then { _baseLauncher = _launcher; _fullLauncher = _total };
    _fullLauncher = _fullLauncher max _total;
    _launcherState = [_total, _fullLauncher] call BUZZ_fnc_zvColour;
    _launcherLoaded = _loaded;
    _launcherSpare = _spare;
};

_unit setVariable ["BUZZ_zv_baseline", [_baseRifle, _fullRifle, _baseLauncher, _fullLauncher]];   // local only

// Debug (Addon Options): print own counts to system chat whenever they change.
if (BUZZ_ZeusVision_debug) then {
    private _debug = [_rifleRounds, _fullRifle, _rifleState, _launcherRounds, _fullLauncher, _launcherState];
    if (_debug isNotEqualTo (missionNamespace getVariable ["BUZZ_zv_lastDebug", []])) then {
        BUZZ_zv_lastDebug = _debug;
        systemChat format ["[ZeusVision] Rifle %1 full %2 state %3 | Launcher %4 full %5 state %6", _rifleRounds, _fullRifle, _rifleState, _launcherRounds, _fullLauncher, _launcherState];
    };
};

private _state = [_rifleState, _launcherState, _launcherLoaded, _launcherSpare];
if (_state isNotEqualTo (_unit getVariable ["BUZZ_zv_state", []])) then {
    _unit setVariable ["BUZZ_zv_state", _state, true];
};
