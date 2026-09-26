// GulHill run 3/4: climb + re-engagement on fixed Altis lanes. Server only. Aux Updater test, 2026-09-26.
// Variants come from variants.sqf (GH_variants). "*nohelper" disables the BURNS gait settings;
// "*loaded" adds 80 idle AI groups (live-op scheduler load). The addon's own controller is used.
if (!isServer) exitWith {};
call compile preprocessFileLineNumbers "variants.sqf";
[] spawn {
    waitUntil {time > 2};
    sleep 15;
    setDate [2035,6,15,12,0]; 0 setFog 0; 0 setOvercast 0; 0 setRain 0; forceWeatherChange;
    FST_HC_Enabled = false; publicVariable "FST_HC_Enabled";
    FST_HC_SafeModeUntil = time + 100000;
    GH_incl = {
        params ["_pos","_dir"];
        private _n = surfaceNormal _pos;
        atan (-((_n select 0)*(sin _dir) + (_n select 1)*(cos _dir)) / ((_n select 2) max 0.001))
    };
    // Lanes found in run 2 (bin, start, uphill azimuth, index within bin).
    GH_lanes = [
        [4,[23436.4,21792.9,0],113.963,0],[4,[10115.4,9741.6,0],-53.9727,1],[4,[22681.2,7160.24,0],-68.1986,2],
        [18,[4128.31,18249.4,0],170.714,0],[27,[7622.67,14808,0],118.744,0],[18,[7301.86,13150.7,0],-6.36588,1],
        [27,[8713.99,25025.2,0],-94.8706,1],[18,[6270.57,13914.4,0],29.7708,2],[27,[11887.5,7486.63,0],17.5108,2],
        [33,[4406.63,10660.9,0],-54.0729,0],[33,[6226.26,18456.6,0],-169.16,1],[33,[4330.02,15155.5,0],30.8633,2]
    ];
    diag_log format ["[GULHILL] begin run %1", GH_variants];
    private _classes = ["JMSEF_animals_varren_o","JMSEF_animals_var_bers_o","JMSEF_animals_var_alpha_o"];
    private _dummies = [];
    {
        private _variant = _x;
        if ((_variant find "loaded") >= 0) then {
            for "_i" from 1 to 80 do {
                private _dg = createGroup [east, true];
                _dg setVariable ["FST_HC_noTransfer", true, true];
                private _du = _dg createUnit ["O_Soldier_F", [3500 + (_i mod 10) * 6, 12950 + floor (_i / 10) * 6, 0], [], 0, "CAN_COLLIDE"];
                _du disableAI "ALL"; _du allowDamage false;
                _dummies pushBack _du;
            };
            sleep 3;
        };
        private _helper = (_variant find "nohelper") < 0;
        BURNS_GulantharSlopeEnabled = _helper;
        BURNS_GulantharRunEnabled = _helper;
        private _rows = [];
        {
            _x params ["_bin","_p","_dir","_k"];
            private _class = _classes select (_k mod 3);
            private _start = _p getPos [-3, _dir]; _start set [2, 0];
            private _goal = _p getPos [60, _dir]; _goal set [2, 0];
            private _g = createGroup [east, true];
            _g setVariable ["FST_HC_noTransfer", true, true];
            private _u = _g createUnit [_class, _start, [], 0, "CAN_COLLIDE"];
            _u setPosATL _start; _u setDir _dir; _u allowDamage false;
            private _tg = createGroup [west, true];
            _tg setVariable ["FST_HC_noTransfer", true, true]; _tg setVariable ["BURNS_exempt", true, true];
            private _t = _tg createUnit ["B_Soldier_F", _goal, [], 0, "CAN_COLLIDE"];
            _t setPosATL _goal; _t allowDamage false; _t disableAI "ALL";
            // [lane,bin,class,unit,target,start,dir,group,tgroup, reachT, jumpT, reengageT, returnT, distAtJump]
            _rows pushBack [_forEachIndex, _bin, _class, _u, _t, _start, _dir, _g, _tg, -1, -1, -1, -1, -1];
        } forEach GH_lanes;
        private _samples = _rows apply {[]};
        private _t0 = time;
        while {time - _t0 < 70} do {
            private _now = time - _t0;
            {
                private _row = _x;
                _row params ["_lane","_bin","_class","_u","_t","_start","_dir","_g","_tg","_reach","_jump","_re","_ret","_dJump"];
                if (isNull _u || {!alive _u}) then {continue};
                private _pos = getPosATL _u;
                private _prog = (_pos vectorDiff _start) vectorDotProduct [sin _dir, cos _dir, 0];
                private _d = _u distance2D _t;
                if (_reach < 0 && {_d < 6}) then {_row set [9, _now]; _reach = _now};
                if (_reach >= 0 && {_jump < 0} && {_now - _reach > 3}) then {
                    _t setPosATL _start; _row set [10, _now]; _jump = _now; _dJump = _u distance2D _start; _row set [13, _dJump];
                    // Then the target flees further downhill (a moving chase).
                    {_t enableAI _x} forEach ["MOVE","PATH","ANIM","TEAMSWITCH","FSM"];
                    _tg setBehaviour "CARELESS"; _tg setSpeedMode "FULL"; _t forceSpeed -1;
                    _t doMove (_start getPos [-150, _dir]);
                };
                if (_jump >= 0 && {_re < 0} && {(_u distance2D _t) < _dJump - 10}) then {_row set [11, _now - _jump]};
                if (_jump >= 0 && {_ret < 0} && {(_u distance2D _t) < 6}) then {_row set [12, _now - _jump]};
                (_samples select _forEachIndex) pushBack [_now, toLower animationState _u, speed _u, _prog, [_pos, getDir _u] call GH_incl, _u distance2D _t, currentCommand _u, _u getVariable ["mode",-1], round diag_fps];
            } forEach _rows;
            sleep 0.25;
        };
        {
            _x params ["_lane","_bin","_class","_u","_t","_start","_dir","_g","_tg","_reach","_jump","_re","_ret","_dJump"];
            private _s = _samples select _forEachIndex;
            private _t45 = -1; private _hist = createHashMap; private _stallUp = 0; private _nUp = 0; private _stallBack = 0; private _nBack = 0;
            {
                _x params ["_tt","_anim","_spd","_prog","_inc","_d"];
                if (_t45 < 0 && {_prog >= 45}) then {_t45 = _tt};
                _hist set [_anim, (_hist getOrDefault [_anim,0]) + 1];
                if (_reach < 0 || {_tt < _reach}) then {_nUp = _nUp + 1; if (abs _spd < 1) then {_stallUp = _stallUp + 1}};
                if (_jump >= 0 && {_tt >= _jump} && {_ret < 0 || {_tt < _jump + _ret}}) then {_nBack = _nBack + 1; if (abs _spd < 1) then {_stallBack = _stallBack + 1}};
            } forEach _s;
            private _n = count _s max 1;
            private _animFrac = (keys _hist) apply {[_x, round (100 * (_hist get _x) / _n)]};
            diag_log format ["[GULHILL_R3] %1", [_variant, _lane, _bin, _class, _t45, _reach, _jump, _re, _ret, round (100 * _stallUp / (_nUp max 1)), round (100 * _stallBack / (_nBack max 1)), _animFrac, _u getVariable ["BURNS_creatureGaitEntries",0]]];
            {diag_log format ["[GULHILL_SAMPLE] %1", [_variant, _lane] + _x]} forEach (_s select {(round ((_x select 0) * 4)) mod 4 == 0});
            deleteVehicle _u; deleteVehicle _t; deleteGroup _g; deleteGroup _tg;
        } forEach _rows;
        {deleteVehicle _x} forEach _dummies; _dummies = [];
        sleep 4;
        diag_log format ["[GULHILL] variant done %1", _variant];
    } forEach GH_variants;
    diag_log "[GULHILL] done";
};
