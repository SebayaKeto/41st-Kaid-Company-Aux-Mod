diag_log "[CHECK] Starting AIThinkOnlyLocal debug";

private _options = getMissionOptions;
private _value = _options get "AIThinkOnlyLocal";

diag_log format ["[CHECK] AIThinkOnlyLocal = %1", _value];

diag_log "[CHECK] Done.";