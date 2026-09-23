// Local callback registry for our own CfgVehicles modules. No shared ZEN slots.
params ["_category","_label","_callback",["_icon",""]];
if (!hasInterface) exitWith {false};
if (isNil "FST_HC_ModuleCallbacks") then {FST_HC_ModuleCallbacks=createHashMap};
FST_HC_ModuleCallbacks set [_category+"|"+_label,_callback];
true
