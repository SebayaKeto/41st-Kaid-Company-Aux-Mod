// FST_medOps_fnc_medicTick
// Medic's client, every second: collect active calls in range for the Draw3D handler, keep map markers in step,
// and announce new calls. The Draw3D handler only reads FST_medOps_cache.

if (!hasInterface || {isNull player}) exitWith {};
private _sees = (missionNamespace getVariable ["FST_medOps_beacons", true])
    && {alive player}
    && {((missionNamespace getVariable ["FST_medOps_whoSees", 0]) == 1) || {[player] call ace_medical_treatment_fnc_isMedic}};
private _range = missionNamespace getVariable ["FST_medOps_range", 500];
private _list = [];
if (_sees) then {
    {
        if (_x != player && {alive _x} && {!isNil { _x getVariable "FST_medOps_call" }}
            && {(side group _x) isEqualTo (side group player)} && {(_x distance player) < _range}) then {
            _list pushBack [_x, [_x] call FST_medOps_fnc_severity];
        };
    } forEach allPlayers;
};
// most urgent first
_list =[_list, [], { (_x select 1) select 0 }, "DESCEND"] call BIS_fnc_sortBy;
FST_medOps_cache = _list;

// announce new calls (once per unit per call)
private _seen = missionNamespace getVariable ["FST_medOps_seen", createHashMap];
{
    _x params ["_u", "_sev"];
    private _key = (getPlayerUID _u) + str ((_u getVariable ["FST_medOps_call", ["", 0]]) select 1);
    if !(_key in _seen) then {
        _seen set [_key, true];
        systemChat format ["MEDIC: %1 needs help - %2, %3 m", name _u, _sev select 1, round (_u distance player)];
    };
} forEach _list;
missionNamespace setVariable ["FST_medOps_seen", _seen];

// local map markers for medics (one per casualty)
private _markers = missionNamespace getVariable ["FST_medOps_markers", []];
private _now = [];
{
    _x params ["_u", "_sev"];
    private _m = "FST_medOps_" + getPlayerUID _u;
    if !(_m in allMapMarkers) then {
        createMarkerLocal [_m, getPosATL _u];
        _m setMarkerTypeLocal "mil_triangle";
        _m setMarkerSizeLocal [0.8, 0.8];
    };
    _m setMarkerPosLocal getPosATL _u;
    _m setMarkerColorLocal (_sev select 3);
    _m setMarkerTextLocal format ["%1 (%2)", name _u, _sev select 1];
    _now pushBack _m;
} forEach _list;
{ if !(_x in _now) then { deleteMarkerLocal _x; }; } forEach _markers;
missionNamespace setVariable ["FST_medOps_markers", _now];
