/*
    BUZZ_fnc_zvRefreshCache
    Rebuilds what the Draw3D handler draws (about twice a second, not every
    frame). Follows tracked players onto their new unit after a respawn.

    BUZZ_zv_cache rows: [unit, lines] where lines = [[text, colour], ...]
    top to bottom (name/kit, rifle, launcher, ACE medical).
*/
private _byUid = createHashMap;
{ _byUid set [getPlayerUID _x, _x] } forEach allPlayers;

// "All players" mode: rebuild the list from everyone currently connected.
if (BUZZ_zv_trackAll) then {
    BUZZ_zv_tracked = (allPlayers - entities "HeadlessClient_F") apply { [getPlayerUID _x, _x] };
};

private _colours = [
    [0.20, 0.90, 0.20, 1],   // Green
    [1.00, 0.85, 0.10, 1],   // Yellow
    [1.00, 0.15, 0.10, 1],   // Red
    [0.00, 0.00, 0.00, 1]    // Black
];
private _white = [1, 1, 1, 1];

private _cache = [];
{
    _x params ["_uid", "_unit"];
    if (_uid != "") then {
        private _current = _byUid getOrDefault [_uid, objNull];
        if (!isNull _current) then { _unit = _current; _x set [1, _current] };
    };

    if (!isNull _unit && { alive _unit }) then {
        (_unit getVariable ["BUZZ_zv_state", [-1, -1, 0, 0]]) params ["_rifle", "_launcher", "_loaded", "_spare"];

        private _kit = _unit getVariable ["BUZZ_kit", ""];
        private _title = if (_kit == "") then { name _unit } else { format ["%1 - %2", name _unit, _kit] };

        private _lines = [[_title, _white]];
        if (_rifle >= 0) then {
            _lines pushBack [["Rifle", "Rifle EMPTY"] select (_rifle == 3), _colours select _rifle];
        };
        if (_launcher >= 0) then {
            _lines pushBack [format ["Launcher %1+%2", _loaded, _spare], _colours select _launcher];
        };

        // ACE medical: same values Crows Zeus Additions' Ctrl+Shift+H text reads.
        // ACE already syncs these to every machine, so nothing extra is broadcast.
        // Note: ACE only re-syncs heart rate every 10-19 s, so HR can lag a little.
        if (BUZZ_ZeusVision_medical && { BUZZ_zv_hasAceMedical }) then {
            // openWounds is a hashmap: body part -> [[classID, amountOf, bleeding, damage], ...].
            // Sum amountOf across every body part (ceil, as bandaging can leave fractions).
            private _openWounds = _unit getVariable ["ace_medical_openWounds", createHashMap];
            private _wounds = 0;
            if (_openWounds isEqualType createHashMap) then {
                { { _wounds = _wounds + (_x select 1) } forEach _y } forEach _openWounds;
            };
            _wounds = ceil _wounds;
            private _hr = round (_unit getVariable ["ace_medical_heartRate", 80]);
            private _bleed = _unit getVariable ["ace_medical_woundBleeding", 0];
            private _arrest = _unit getVariable ["ace_medical_inCardiacArrest", false];
            private _uncon = _unit getVariable ["ACE_isUnconscious", false];

            // Wounds / heart rate line: Green fine, Yellow worrying, Red bad.
            private _vitals = 0;
            if (_wounds > 0 || { _hr > 90 } || { _hr < 70 }) then { _vitals = 1 };
            if (_wounds > 2 || { _hr > 100 } || { _hr < 60 }) then { _vitals = 2 };
            _lines pushBack [format ["Wounds %1 | HR %2", _wounds, _hr], _colours select _vitals];

            // Status line only when something needs the Zeus's attention.
            private _status = [];
            if (_arrest) then { _status pushBack "CARDIAC ARREST" } else { if (_uncon) then { _status pushBack "UNCONSCIOUS" } };
            if (_bleed > 0) then { _status pushBack format ["Bleeding %1", [_bleed, 3] call BIS_fnc_cutDecimals] };
            if (_status isNotEqualTo []) then {
                private _bad = _arrest || { _uncon } || { _bleed > 0.06 };
                _lines pushBack [_status joinString " | ", _colours select ([1, 2] select _bad)];
            };
        };

        _cache pushBack [_unit, _lines];
    };
} forEach BUZZ_zv_tracked;

BUZZ_zv_cache = _cache;
