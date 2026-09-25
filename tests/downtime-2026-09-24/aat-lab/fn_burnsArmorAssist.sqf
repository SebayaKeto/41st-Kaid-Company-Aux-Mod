// TEST BUILD ONLY: register variants instead of overwriting final functions.
private _g=_this select 0;private _variant=_g getVariable["Q_variant","candidate"];
if((_g getVariable["Q_executedVariant",""])!=_variant)then{_g setVariable["Q_executedVariant",_variant];diag_log format["[DT_VARIANT_ACTIVE] %1",[_g,_variant]]};
switch(_variant)do{case "fire-only":{_this call FST_HCSpawn_fnc_labFireOnly};case "short-pulse":{_this call FST_HCSpawn_fnc_labShortPulse};default{_this call FST_HCSpawn_fnc_labOriginal}};
