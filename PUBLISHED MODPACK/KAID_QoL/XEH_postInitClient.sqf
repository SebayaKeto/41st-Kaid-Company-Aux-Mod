/*
 * KAID_QoL client post-init (Aux Updater, 25 Nov 2026).
 * 1. Stamina off: once a second, if the player's stamina is on, turn it off (survives respawn, Zeus remote control ends,
 *    and anything that turns it back on).
 * 2. Aircraft panel: while the player flies a helicopter or plane as pilot or co-pilot, a small panel near the top left shows
 *    - ETA to the player's own map waypoint (shift-click), at current ground speed;
 *    - fuel time left, from the fuel used over the last minute.
 *    It stands down if the old "More Aircraft Displays" mod is loaded, so nobody gets two panels.
 * One CBA per-frame handler at 1 s does both. No onEachFrame (that slot is shared), no generic global names.
 * The panel control lives in uiNamespace ("KAID_QoL_panel"): a control in missionNamespace pops the engine box
 * "Variable ... does not support serialization" (seen 25 Nov qol24 cli75/cli71).
 */
if (!hasInterface) exitWith {};

uiNamespace setVariable ["KAID_QoL_panel", controlNull];
KAID_QoL_fuelLog = [];
KAID_QoL_panelVeh = objNull;
KAID_QoL_madLoaded = isClass (configFile >> "CfgPatches" >> "J3FF_MoreAircraftDisplaysElement");

KAID_QoL_fnc_isFlying = {
    private _veh = vehicle player;
    if (_veh == player || {!alive player} || {!(_veh isKindOf "Helicopter" || {_veh isKindOf "Plane"})}) exitWith {false};
    if (driver _veh == player) exitWith {true};
    private _turret = _veh unitTurret player;
    if (_turret isEqualTo []) exitWith {false};
    getNumber ([_veh, _turret] call BIS_fnc_turretConfig >> "isCopilot") == 1
};

KAID_QoL_fnc_panelText = {
    params ["_veh"];
    private _eta = "ETA --";
    private _wp = customWaypointPosition;
    if (_wp isNotEqualTo []) then {
        private _kmh = vectorMagnitude ((velocity _veh) select [0, 2]) * 3.6;
        if (_kmh > 1) then {
            private _secs = (_veh distance2D _wp) / (_kmh / 3.6);
            _eta = if (_secs > 3600) then {"ETA >60m"} else {
                format ["ETA %1m:%2s", floor (_secs / 60), [floor (_secs mod 60), 2] call CBA_fnc_formatNumber]
            };
        };
    };
    private _fuelTxt = "Fuel --";
    private _now = time;
    private _f = fuel _veh;
    private _log = KAID_QoL_fuelLog;
    if (_log isNotEqualTo [] && {_f > ((_log select (count _log - 1)) select 1) + 0.001}) then {_log resize 0};   // refuelled
    _log pushBack [_now, _f];
    while {count _log > 1 && {_now - ((_log select 0) select 0) > 60}} do {_log deleteAt 0};
    if (count _log > 1) then {
        (_log select 0) params ["_t0", "_f0"];
        private _rate = (_f0 - _f) / ((_now - _t0) max 0.001);          // fuel per second
        if (_rate > 0 && {_now - _t0 >= 20}) then {
            _fuelTxt = format ["Fuel %1m", round (_f / _rate / 60)];
        };
    };
    format ["%1<br/>%2", _eta, _fuelTxt]
};

KAID_QoL_fnc_panelClose = {
    private _ctrl = uiNamespace getVariable ["KAID_QoL_panel", controlNull];
    if (!isNull _ctrl) then {ctrlDelete _ctrl};
    uiNamespace setVariable ["KAID_QoL_panel", controlNull];
    KAID_QoL_panelVeh = objNull;
    KAID_QoL_fuelLog = [];
};

[{
    if (isStaminaEnabled player) then {player enableStamina false};

    if (KAID_QoL_madLoaded) exitWith {};
    if !(call KAID_QoL_fnc_isFlying) exitWith {call KAID_QoL_fnc_panelClose};
    private _veh = vehicle player;
    if (_veh != KAID_QoL_panelVeh) then {call KAID_QoL_fnc_panelClose; KAID_QoL_panelVeh = _veh};
    private _ctrl = uiNamespace getVariable ["KAID_QoL_panel", controlNull];
    if (isNull _ctrl) then {
        private _disp = findDisplay 46;
        if (isNull _disp) exitWith {};
        _ctrl = _disp ctrlCreate ["RscStructuredText", -1];
        _ctrl ctrlSetPosition [safeZoneX + safeZoneW * 0.14, safeZoneY + safeZoneH * 0.011, 0.15, 0.08];
        _ctrl ctrlSetBackgroundColor [0, 0, 0, 0.2];
        _ctrl ctrlCommit 0;
        uiNamespace setVariable ["KAID_QoL_panel", _ctrl];
    };
    if (!isNull _ctrl) then {
        _ctrl ctrlSetStructuredText parseText ([_veh] call KAID_QoL_fnc_panelText);
    };
}, 1] call CBA_fnc_addPerFrameHandler;
