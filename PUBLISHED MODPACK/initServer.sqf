setMissionOptions createHashMapFromArray [["AIThinkOnlyLocal", true]];

diag_log "[CHECK] Starting AIThinkOnlyLocal debug";
private _val = getMissionOptions "AIThinkOnlyLocal";
diag_log format ["[CHECK] AIThinkOnlyLocal = %1", _val];
diag_log "[CHECK] Done.";