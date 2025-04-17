setMissionOptions createHashMapFromArray [["AIThinkOnlyLocal", true]];

private _val = getMissionOptions "AIThinkOnlyLocal";
diag_log format ["[CHECK] AIThinkOnlyLocal = %1", _val];
