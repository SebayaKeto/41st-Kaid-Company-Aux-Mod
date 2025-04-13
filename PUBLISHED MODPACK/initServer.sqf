setMissionOptions createHashMapFromArray [["AIThinkOnlyLocal", true]];

private _val = getMissionOptions "AIThinkOnlyLocal";
diag_log format ["[CHECK] AIThinkOnlyLocal = %1", _val];

if (!isServer && !hasInterface) exitWith {};

private _b1Types = [
    "FST_Droid_B1_E5",
    "FST_Droid_B1_Sniper",
    "FST_Droid_B1_Commander",
    "FST_Droid_B1_GAT",
    "FST_Droid_B1_AT",
    "FST_Droid_B1_AA",
    "FST_Droid_B1_AR",
    "FST_Droid_B1_OOM"
];

[{
    {
        if (alive _x && {typeOf _x in _this}) then {
            if (stance _x != "STAND") then {
                _x setUnitPos "UP";
            };
            if (speaker _x != "SWdroidENG") then {
                _x setSpeaker "SWdroidENG";
            };
        };
    } forEach (allUnits select {local _x});
}, _b1Types, 1] call CBA_fnc_addPerFrameHandler;
