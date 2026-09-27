/*
    FST_stonewall_fnc_save                                               v1.2.4
    Project Stonewall - SAVE (server side).  Also shipped as the paste script
    sqf/stonewall_save.min.sqf (debug console, SERVER EXEC) for servers
    without the FST_Stonewall addon.

    Snapshots every built object to the server RPT, one line per object,
    prefix "STONEWALL|".  The keep-area part is copied to each Zeus's own RPT.
    Nothing in the mission is changed.

    Arguments (optional): 0: scope "all" | "areas" <STRING>
    Callers: remoteExecCall ["FST_stonewall_fnc_save", 2] (the requester is taken from remoteExecutedOwner and
    must be a Zeus or logged-in admin), a server-local call, or the debug console (admin).

    Keep areas, read from map markers:
      - Zeus-drawn Zen area markers (zen_area_markers_*)
      - Stonewall "Keep Area" module markers (stonewall_keep_*)
      - any marker whose text is "KEEP <radius> [name]", e.g. "KEEP 80 Ridge FOB"
        (an icon marker gives a circle of that radius; "Keep clear" does not count)
*/
if (!isServer) exitWith { systemChat "Stonewall: run this on the SERVER (SERVER EXEC)."; };

// Who asked: remoteExecutedOwner when the engine reports one (never a claimed ID); otherwise treated as the server.
private _req = if (isRemoteExecuted) then { remoteExecutedOwner } else { 2 };
private _reply = {
    params ["_msg"];
    private _viaCba = isClass (configFile >> "CfgPatches" >> "FST_Stonewall") && {!isNil "CBA_fnc_ownerEvent"};
    if (_req > 2) then {
        if (_viaCba) then { ["FST_stonewall_done", [_msg], _req] call CBA_fnc_ownerEvent; } else { [_msg] remoteExec ["systemChat", _req]; };
    } else {
        if (hasInterface) then {           // a listen-server host asked
            if (_viaCba) then { ["FST_stonewall_done", [_msg]] call CBA_fnc_localEvent; } else { systemChat _msg; };
        };
    };
};
// Zeus/admin check. NOTE (engine probe 27 Sep, Arma 2.22): a remoteExecCall from another machine can arrive with
// isRemoteExecuted=false and remoteExecutedOwner=0, which looks exactly like a server-local call and is allowed.
// So this check stops honest misuse and gives feedback; it is not a security boundary (under the default
// CfgRemoteExec a client that can run scripts can remoteExec any command anyway).
if (_req > 2 && {!((admin _req) == 2
    || {(allCurators findIf { private _u = getAssignedCuratorUnit _x; !isNull _u && {owner _u == _req} }) >= 0})}) exitWith {
    diag_log format ["STONEWALL: rejected save request from owner %1 (not a curator or admin)", _req];
    ["Stonewall: Zeus or admin only."] call _reply;
};
// the lock lives in localNamespace: a client's publicVariable cannot jam or clear it
private _lock = localNamespace getVariable ["stonewall_busy", []];
if (_lock isEqualType [] && {count _lock == 2} && {diag_tickTime - (_lock select 1) < 900}) exitWith {
    diag_log format ["STONEWALL: save %1 is still running - request from owner %2 ignored", _lock select 0, _req];
    ["Stonewall: a save is already running - wait for its confirmation."] call _reply;
};
private _lockId = str diag_tickTime + str random 1e6;
localNamespace setVariable ["stonewall_busy", [_lockId, diag_tickTime]];
["Stonewall: save started on the server - the confirmation follows when it is done."] call _reply;

private _args = if (isNil "_this") then { [] } else { if (_this isEqualType []) then { _this } else { [] } };
private _opts = missionNamespace getVariable ["stonewall_opts", createHashMap];
if !(_opts isEqualType createHashMap) then { _opts = createHashMap; };
private _scope = _args param [0, _opts getOrDefault ["scope", "all"]];
if !(_scope in ["all", "areas"]) then { _scope = "all"; };

private _owners = [];
if (_req > 2) then { _owners pushBackUnique _req; };
{
    private _u = getAssignedCuratorUnit _x;
    if (!isNull _u && {isPlayer _u} && {owner _u > 2}) then { _owners pushBackUnique (owner _u); };
} forEach allCurators;

private _reqInfo = format ["req=%1|reqAdmin=%2|reqRemote=%3", _req, [-1, admin _req] select (_req > 2), isRemoteExecuted];

[_owners, _scope, _opts, _lockId, _reqInfo] spawn {
    params ["_owners", "_scope", "_opts", "_lockId", "_reqInfo"];
    private _margin = _opts getOrDefault ["margin", 15];
    private _zenAreas = _opts getOrDefault ["zenAreas", missionNamespace getVariable ["FST_stonewall_zenAreas", true]];
    private _daidVars = [];
    private _dv = missionNamespace getVariable ["stonewall_daidalosVars", []];
    if (_dv isEqualType []) then { { if (_x isEqualType "") then { _daidVars pushBackUnique _x; }; } forEach _dv; };
    _dv = missionNamespace getVariable ["FST_stonewall_daidalosVars", ""];
    if (_dv isEqualType "") then {
        {
            private _v = (_x splitString " ") joinString "";
            if (_v != "") then { _daidVars pushBackUnique _v; };
        } forEach (_dv splitString ",");
    };
    if !(_margin isEqualType 0) then { _margin = 15; };
    if !(_zenAreas isEqualType true) then { _zenAreas = true; };
    private _cba = isClass (configFile >> "CfgPatches" >> "FST_Stonewall") && {!isNil "CBA_fnc_ownerEvent"};
    private _clean = { (_this splitString "|") joinString "/" };
    private _t0 = diag_tickTime;
    private _d = systemTimeUTC apply { if (_x < 10) then { "0" + str _x } else { str _x } };
    private _sid = format ["%1%2%3T%4%5%6-%7", _d#0, _d#1, _d#2, _d#3, _d#4, _d#5, floor random 10000];
    private _pre = "STONEWALL|" + _sid + "|";
    private _toCallers = [];
    private _emit = {
        params ["_line", "_share"];
        diag_log text (_pre + _line);
        if (_share) then { _toCallers pushBack (_pre + _line); };
    };

    [format ["H|v=1.2.4|world=%1|mission=%2|briefing=%3|time=%4|serverTime=%5|scope=%6|margin=%7|players=%8|addon=%9|%10",
        worldName, missionName, briefingName call _clean, time toFixed 1, serverTime toFixed 1, _scope, _margin,
        count allPlayers, [0, 1] select _cba, _reqInfo], true] call _emit;

    private _areas = [];
    {
        private _m = _x;
        private _nameL = toLower _m;
        private _text = markerText _m;
        private _kind = "";
        if (_nameL find "stonewall_keep" == 0) then { _kind = "stonewall"; };
        if (_kind == "" && {_zenAreas} && {_nameL find "zen_area_markers_" == 0}) then { _kind = "zen"; };
        private _words = _text splitString " ";
        private _r = if (count _words > 1) then { parseNumber (_words select 1) } else { 0 };
        if (_kind == "" && {count _words > 1} && {toUpper (_words select 0) == "KEEP"} && {_r > 0}) then { _kind = "text"; };
        if (_kind != "") then {
            private _shape = markerShape _m;
            private _size = markerSize _m;
            if !(_shape in ["RECTANGLE", "ELLIPSE"]) then {
                if (_r <= 0) then { _r = 50; };
                _size = [_r, _r];
                _shape = "ELLIPSE";
            };
            private _p = markerPos _m;
            _areas pushBack [_m, _kind, _shape, _p#0, _p#1, _size#0, _size#1, markerDir _m, _text];
        };
    } forEach allMapMarkers;
    {
        _x params ["_m", "_kind", "_shape", "_x0", "_y0", "_a", "_b", "_dir", "_text"];
        [format ["A|%1|%2|%3|%4|%5|%6|%7|%8|%9|%10", _forEachIndex, _m call _clean, _kind, _shape,
            _x0 toFixed 2, _y0 toFixed 2, _a toFixed 2, _b toFixed 2, _dir toFixed 2, _text call _clean], true] call _emit;
    } forEach _areas;

    private _fortCls = [];
    {
        if (_x find "ace_fortify_objects_" == 0) then {
            private _list = missionNamespace getVariable [_x, []];
            if (_list isEqualType []) then {
                { if (_x isEqualType [] && {count _x > 0}) then { _fortCls pushBackUnique toLower (_x#0); }; } forEach _list;
            };
        };
    } forEach allVariables missionNamespace;

    private _skipKinds = ["Man", "Animal", "Logic", "WeaponHolder", "WeaponHolderSimulated", "Crater", "CraterLong",
        "Ruins", "EmptyDetector", "CBA_NamespaceDummy", "ACE_Explosives_Place", "MineBase", "ACE_bodyBagObject", "ACE_Grave"];
    private _attached = 0;
    private _objs = (allMissionObjects "All") + (allSimpleObjects []);
    private _clsAddons = createHashMap;
    private _n = 0;
    private _nArea = 0;
    private _skipped = 0;
    private _noClass = 0;
    {
        private _o = _x;
        private _t = typeOf _o;
        call {
            if (isNull _o) exitWith {};
            if (_t == "") exitWith { _noClass = _noClass + 1; };
            if (_t select [0, 1] == "#") exitWith { _skipped = _skipped + 1; };
            if !(isClass (configFile >> "CfgVehicles" >> _t)) exitWith { _skipped = _skipped + 1; };
            if (_skipKinds findIf { _o isKindOf _x } >= 0) exitWith { _skipped = _skipped + 1; };
            if (getNumber (configFile >> "CfgVehicles" >> _t >> "scope") < 1) exitWith { _skipped = _skipped + 1; };
            if (!isNull attachedTo _o || {!isNull ropeAttachedTo _o} || {!(crew _o isEqualTo [])}) exitWith { _attached = _attached + 1; };
            private _pos = getPosWorld _o;
            private _in = [];
            {
                _x params ["", "", "_shape", "_x0", "_y0", "_a", "_b", "_dir"];
                if (_pos inArea [[_x0, _y0], _a + _margin, _b + _margin, _dir, _shape == "RECTANGLE"]) then { _in pushBack _forEachIndex; };
            } forEach _areas;
            if (_scope == "areas" && {_in isEqualTo []}) exitWith {};
            private _src = "unknown";
            call {
                if (!isNil { _o getVariable "ace_fortify_tokensUsed" }) exitWith { _src = "fortify"; };
                if (_daidVars findIf { !isNil { _o getVariable _x } } >= 0) exitWith { _src = "daidalos"; };
                private _tag = _o getVariable ["stonewall_src", ""];
                if (_tag != "") exitWith { _src = _tag; };
                if ((toLower _t) in _fortCls) exitWith { _src = "fortify_class"; };
            };
            private _kind = call {
                if (_o isKindOf "StaticWeapon") exitWith { "static_weapon" };
                if (_o isKindOf "LandVehicle") exitWith { "land_vehicle" };
                if (_o isKindOf "Air") exitWith { "air" };
                if (_o isKindOf "Ship") exitWith { "ship" };
                if (_o isKindOf "ReammoBox_F" || {_o isKindOf "ReammoBox"}) exitWith { "box" };
                if (_o isKindOf "Thing") exitWith { "thing" };
                if (_o isKindOf "Static") exitWith { "static" };
                "other"
            };
            if !(_t in _clsAddons) then {
                private _cfg = configFile >> "CfgVehicles" >> _t;
                // only the defining addon: patches (ACE compat, server-only) must not land in the next mission's addons[]
                private _def = (configSourceAddonList _cfg) param [0, ""];
                _clsAddons set [_t, _def];
                [format ["C|%1|%2", _t, _def], true] call _emit;
            };
            private _v = vectorDir _o;
            private _u = vectorUp _o;
            [format ["O|%1|%2|%3|%4|%5|%6|%7|%8|%9|%10|%11|%12|%13|%14|%15|%16|%17|%18|%19|%20|%21|%22", _n, _t,
                _pos#0 toFixed 3, _pos#1 toFixed 3, _pos#2 toFixed 3,
                _v#0 toFixed 5, _v#1 toFixed 5, _v#2 toFixed 5, _u#0 toFixed 5, _u#1 toFixed 5, _u#2 toFixed 5,
                _src, _kind, [0, 1] select (alive _o), damage _o toFixed 2, [0, 1] select (isSimpleObject _o),
                [0, 1] select (simulationEnabled _o), [0, 1] select (isObjectHidden _o), getObjectScale _o toFixed 3,
                (_o getVariable ["stonewall_born", -1]) toFixed 0, _in joinString ";", vehicleVarName _o call _clean],
                !(_in isEqualTo [])] call _emit;
            _n = _n + 1;
            if !(_in isEqualTo []) then { _nArea = _nArea + 1; };
            if (_n % 150 == 0) then { sleep 0.01; };
        };
    } forEach _objs;

    [format ["E|objects=%1|in_areas=%2|areas=%3|skipped=%4|no_class=%5|attached_or_crewed=%6|seconds=%7", _n, _nArea,
        count _areas, _skipped, _noClass, _attached, (diag_tickTime - _t0) toFixed 1], true] call _emit;

    private _msg = format ["Stonewall %1: saved %2 objects, %3 inside %4 keep areas. Data is in the server RPT and your RPT.",
        _sid, _n, _nArea, count _areas];
    if !(_owners isEqualTo []) then {
        private _chunks = [];
        for "_i" from 0 to (count _toCallers - 1) step 50 do { _chunks pushBack (_toCallers select [_i, 50]); };
        {
            private _owner = _x;
            if (_cba) then {
                { ["FST_stonewall_log", [_x], _owner] call CBA_fnc_ownerEvent; sleep 0.05; } forEach _chunks;
                ["FST_stonewall_done", [_msg], _owner] call CBA_fnc_ownerEvent;
            } else {
                { [_x] remoteExec ["diag_log", _owner]; if (_forEachIndex % 50 == 49) then { sleep 0.05; }; } forEach _toCallers;
                [_msg] remoteExec ["systemChat", _owner];
            };
        } forEach _owners;
    };
    if (hasInterface) then {               // listen-server host: tell the local Zeus too
        if (_cba) then { ["FST_stonewall_done", [_msg]] call CBA_fnc_localEvent; } else { systemChat _msg; };
    };
    missionNamespace setVariable ["stonewall_lastSave", [_sid, _n, _nArea, count _areas], true];
    if ((localNamespace getVariable ["stonewall_busy", []]) param [0, ""] isEqualTo _lockId) then {
        localNamespace setVariable ["stonewall_busy", []];
    };
};
