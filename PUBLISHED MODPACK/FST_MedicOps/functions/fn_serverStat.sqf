// FST_medOps_fnc_serverStat
// Server. Aggregate one stat line. Arguments: 0: medic UID, 1: medic name, 2: keys <ARRAY>, 3: patient UID
// Store: FST_medOps_stats = uid -> [name, treat, patients(uids), bacta, bandage, revive, underFire, mists,
//                                    transfusions, jolts]

params ["_uid", "_name", "_keys", ["_patient", ""]];
if (!isServer) exitWith {};
if (isNil "FST_medOps_stats") then { FST_medOps_stats = createHashMap; };
private _s = FST_medOps_stats getOrDefault [_uid, [_name, 0, [], 0, 0, 0, 0, 0, 0, 0]];
while { count _s < 10 } do { _s pushBack 0; };   // entries from an older layout
_s set [0, _name];
{
    switch (_x) do {
        case "treat": { _s set [1, (_s select 1) + 1]; if (_patient != "") then { (_s select 2) pushBackUnique _patient; }; };
        case "bacta": { _s set [3, (_s select 3) + 1]; };
        case "bandage": { _s set [4, (_s select 4) + 1]; };
        case "revive": { _s set [5, (_s select 5) + 1]; if (_patient != "") then { (_s select 2) pushBackUnique _patient; }; };
        case "underFire": { _s set [6, (_s select 6) + 1]; };
        case "mist": { _s set [7, (_s select 7) + 1]; };
        case "transfusion": { _s set [8, (_s select 8) + 1]; if (_patient != "") then { (_s select 2) pushBackUnique _patient; }; };
        case "jolt": { _s set [9, (_s select 9) + 1]; if (_patient != "") then { (_s select 2) pushBackUnique _patient; }; };
    };
} forEach _keys;
FST_medOps_stats set [_uid, _s];
