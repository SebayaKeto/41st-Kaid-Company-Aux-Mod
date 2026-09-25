// Read-only preparation hints. Never passed to BURNS as player targets/intelligence.
DI_fnc_markerRowValid = {
    params ["_row"];
    if !(_row isEqualType [] && {count _row == 6}) exitWith {false};
    _row params ["_name","_text","_shape","_pos","_path","_color"];
    if !(_name isEqualType "" && {_text isEqualType ""} && {_shape isEqualType ""} && {_pos isEqualType []} && {_path isEqualType []}) exitWith {false};
    if !(_color isEqualType "" && {count _color <= 64}) exitWith {false};
    if (count _name > 160 || {count _text > 160} || {count _pos != 3} || {count _path > 128} || {count _path mod 2 != 0}) exitWith {false};
    if ((_name find "_USER_DEFINED") != 0) exitWith {false};
    if !(_shape in ["ICON","POLYLINE","RECTANGLE","ELLIPSE"]) exitWith {false};
    private _coords = _pos + _path;
    (_coords findIf {!(_x isEqualType 0) || {!finite _x} || {abs _x > 100000}}) < 0
};
DI_fnc_readMarkers = {
    private _rows = [];
    {
        if (count _rows >= DI_mapMarkerLimit) exitWith {};
        if ((_x find "_USER_DEFINED") != 0 || {markerAlpha _x <= 0}) then {continue};
        // Plotting-board drawing follows the board and is not a march route.
        if ((toLower _x find "ace_maptools") >= 0) then {continue};
        private _path = markerPolyline _x;
        // Retain both ends when downsampling long freehand strokes.
        if (count _path > 128) then {
            private _sample = [];
            private _points = floor (count _path / 2);
            for "_i" from 0 to 63 do {
                private _j = 2 * round (_i * (_points-1) / 63);
                _sample append [_path select _j,_path select (_j+1)];
            };
            _path = _sample;
        };
        private _row = [_x,(markerText _x) select [0,160],toUpper markerShape _x,markerPos _x,_path,markerColor _x];
        if ([_row] call DI_fnc_markerRowValid) then {_rows pushBack _row};
    } forEach allMapMarkers;
    _rows
};
DI_fnc_mapReport = {
    if (!isServer || {!isRemoteExecuted}) exitWith {};
    params ["_actor","_rows"];
    if (isNull _actor || {!isPlayer _actor} || {owner _actor != remoteExecutedOwner} || {side group _actor != west}) exitWith {};
    if !(_rows isEqualType [] && {count _rows <= DI_mapMarkerLimit}) exitWith {};
    if ((_rows findIf {!([_x] call DI_fnc_markerRowValid)}) >= 0) exitWith {};
    private _key = str remoteExecutedOwner;
    private _old = DI_mapReports getOrDefault [_key,[-100,objNull,[]]];
    if (time - (_old select 0) < 8) exitWith {};
    DI_mapReports set [_key,[time,_actor,_rows]];
};
DI_fnc_mapReporter = {
    waitUntil {sleep 1;!isNull player};
    private _last = "";
    private _sent = -100;
    while {true} do {
        private _rows = [] call DI_fnc_readMarkers;
        private _signature = str _rows;
        if (_signature != _last || {diag_tickTime - _sent > 45}) then {
            [player,_rows] remoteExecCall ["DI_fnc_mapReport",2];
            _last = _signature;_sent = diag_tickTime;
        };
        sleep 15;
    };
};
DI_fnc_segmentDistance = {
    params ["_p","_a","_b"];
    private _dx = (_b select 0)-(_a select 0);
    private _dy = (_b select 1)-(_a select 1);
    private _denom = _dx*_dx + _dy*_dy;
    private _t = if (_denom < 1) then {0} else {
        ((((_p select 0)-(_a select 0))*_dx + ((_p select 1)-(_a select 1))*_dy)/_denom) max 0 min 1
    };
    _p distance2D [(_a select 0)+_t*_dx,(_a select 1)+_t*_dy,0]
};
DI_fnc_markerAffinity = {
    params ["_row","_objective"];
    _row params ["_name","_text","_shape","_pos","_path"];
    private _label = toLower _text;
    // Negative orders and contact marks must not become intended destinations.
    if ((["avoid","do not","don't","no go","enemy","contact","mine"] findIf {_label find _x >= 0}) >= 0) exitWith {0};
    if (_shape == "POLYLINE" && {count _path >= 4}) exitWith {
        private _distance = 1e9;
        for "_i" from 0 to (count _path)-4 step 2 do {
            _distance = _distance min ([_objective,[_path select _i,_path select (_i+1),0],[_path select (_i+2),_path select (_i+3),0]] call DI_fnc_segmentDistance);
        };
        if (_distance < 250) then {1-(_distance/500)} else {0}
    };
    private _intent = (["attack","assault","route","advance","next","phase","rally","lz","objective","obj ","wp"] findIf {_label find _x >= 0}) >= 0;
    if (_intent && {_pos distance2D _objective < 350}) then {0.8} else {0}
};
DI_fnc_mapHints = {
    params ["_ready"];
    private _hints = createHashMap;
    private _perGroup = createHashMap;
    private _reports = [];
    {_reports pushBack [-(_y select 0),_x]} forEach DI_mapReports;
    _reports sort true;
    {
        (DI_mapReports get (_x select 1)) params ["_seen","_actor","_rows"];
        if (time-_seen > 90 || {isNull _actor} || {!isPlayer _actor}) then {continue};
        private _group = group _actor;
        private _key = netId _group;
        // Each connected squad contributes at most once, regardless of how many
        // clients can see the same global route marker.
        if (_key in _perGroup) then {continue};
        private _members = _ready select {group _x == _group};
        if (count _members < 2) then {continue};
        _perGroup set [_key,true];
        private _p = getPosATL (_members select 0);
        private _groupLabel = toLower groupId _group;
        private _otherLabels = (allGroups select {side _x == west && {_x != _group}}) apply {toLower groupId _x};
        private _relevantRows = _rows select {
            private _label = toLower (_x select 1);
            private _namesOther = (_otherLabels findIf {count _x > 3 && {_label find _x >= 0}}) >= 0;
            private _namesOwn = count _groupLabel > 3 && {_label find _groupLabel >= 0};
            !_namesOther || {_namesOwn}
        };
        private _previous = DI_mapPositions getOrDefault [_key,[time,_p]];
        private _best = "";private _bestScore = 0;
        {
            if (_y get "complete") then {continue};
            private _pos = _y get "position";
            private _distance = _p distance2D _pos;
            if (_distance > DI_mapLookaheadDistance) then {continue};
            private _affinity = 0;
            {
                private _a = [_x,_pos] call DI_fnc_markerAffinity;
                if (_a > 0 && {count _groupLabel > 3} && {(toLower (_x select 1)) find _groupLabel >= 0}) then {_a = _a + 0.3};
                _affinity = _affinity max _a;
            } forEach _relevantRows;
            if (_affinity == 0) then {continue};
            private _oldDistance = (_previous select 1) distance2D _pos;
            // Moving away contradicts the drawing; stationary planning remains a hint.
            if (_distance > _oldDistance + 30) then {continue};
            private _score = _affinity * 1000 - _distance * 0.15;
            if (_oldDistance > _distance + 20) then {_score = _score + 200};
            if (_score > _bestScore) then {_bestScore = _score;_best = _x};
        } forEach DI_objectives;
        if (_best != "") then {
            private _hint = _hints getOrDefault [_best,[]];
            {_hint pushBackUnique _x} forEach _members;
            _hints set [_best,_hint];
        };
        if (time-(_previous select 0) >= 15) then {DI_mapPositions set [_key,[time,_p]]};
        if !(_key in DI_mapPositions) then {DI_mapPositions set [_key,[time,_p]]};
    } forEach _reports;
    _hints
};
