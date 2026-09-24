// Own module init event: only the placing client dispatches the command.
params ["_logic"];
if (!hasInterface || {!local _logic} || {is3DEN}) exitWith {};
if (_logic getVariable ["FST_HC_moduleQueued",false]) exitWith {};
_logic setVariable ["FST_HC_moduleQueued",true];
private _key=getText (configOf _logic >> "FST_HC_callbackKey");
private _position=getPosASL _logic;
private _hover=curatorMouseOver;
private _attached=if ((_hover param [0,""])=="OBJECT") then {_hover param [1,objNull]} else {objNull};
// Capture the drop position/object now, before another mouse movement.
// The callback runs after this module's init event, without reopening Zeus.
[{
    params ["_logic","_key","_position","_attached"];
    if (isNull _logic) exitWith {};
    deleteVehicle _logic;
    if (isNil "zen_dialog_fnc_create" || {isNil "zen_common_fnc_selectPosition"}) exitWith {
        systemChat "[FST] These Zeus tools require Zeus Enhanced (ZEN).";
    };
    if (_key find "41st Kaid Modules|"==0 && {!(missionNamespace getVariable ["FST_HC_Enabled",true])}) exitWith {
        systemChat "[FST] Spawn and HC tools are disabled in addon settings. BURNS task modules remain available.";
    };
    private _callbacks=missionNamespace getVariable ["FST_HC_ModuleCallbacks",createHashMap];
    if !(_key in _callbacks) exitWith {
        diag_log format ["[FST_MODULE_ERROR] Missing callback: %1",_key];
        systemChat format ["[FST] Module unavailable: %1. Check addon initialization.",_key];
    };
    diag_log format ["[FST_MODULE_DISPATCH] owner=%1 key=%2",clientOwner,_key];
    [_position,_attached] call (_callbacks get _key);
},[_logic,_key,_position,_attached]] call CBA_fnc_execNextFrame;
