// Common Zeus dialog. ZEN supplies context selection even on remote HC units.
params ["_mode",["_groups",[]],["_objects",[]],["_position",[]],["_pickDestination",false]];
if (!hasInterface) exitWith {};
_groups=+_groups;
_objects=_objects select {!isNull _x};
{private _g=group _x; if (isNull _g) then {_g=group effectiveCommander _x}; if (!isNull _g) then {_groups pushBackUnique _g}} forEach _objects;
_groups=_groups select {!isNull _x && {count units _x>0}};
if (count _position<2) then {_position=if (count _groups>0) then {getPosATL leader (_groups select 0)} else {[0,0,0]}};
if (count _groups==0 && {!(_mode in ["artillery_fire"])}) exitWith {systemChat "[BURNS] Select an AI squad first."};
if (_pickDestination && {_mode in ["assault","retreat","target","artillery_fire"]}) exitWith {
    [{
        params ["_mode","_groups","_objects"];
        [_groups apply {leader _x}, {
            params ["_success","","_asl","_args"];
            if (!_success) exitWith {};
            _args params ["_mode","_groups","_objects"];
            [_mode,_groups,_objects,ASLToATL _asl,false] call FST_HCSpawn_fnc_burnsDialog;
        }, [_mode,_groups,_objects],"BURNS: click destination (Esc cancels)"] call zen_common_fnc_selectPosition;
    },[_mode,_groups,_objects]] call CBA_fnc_execNextFrame;
};
if (_mode in ["configure","set_radio"]) exitWith {
    if (count _groups==0) exitWith {systemChat "[BURNS] Select an AI group first."};
    private _g=_groups select 0;
    private _fields=if (_mode=="set_radio") then {
        [["CHECKBOX","Radio enabled",_g getVariable ["BURNS_hasRadio",false]]]
    } else {
        [["CHECKBOX","BURNS group AI enabled",!(_g getVariable ["BURNS_exempt",false])],
         ["CHECKBOX","Radio enabled",_g getVariable ["BURNS_hasRadio",false]],
         ["CHECKBOX","Available for reinforcement",_g getVariable ["BURNS_reinforcement",false]]]
    };
    ["BURNS - Configure Group AI",_fields,{
        params ["_values","_args"];
        _args params ["_mode","_groups","_objects","_position"];
        private _commands=if (_mode=="set_radio") then {
            [["radio_off","radio_on"] select (_values select 0)]
        } else {
            [["disable_group","enable_group"] select (_values select 0),
             ["radio_off","radio_on"] select (_values select 1),
             ["reinforce_off","reinforce_on"] select (_values select 2)]
        };
        {["BURNS_request",[_x,_groups,_objects,_position,150,[],clientOwner]] call CBA_fnc_serverEvent} forEach _commands;
    },{},[_mode,_groups,_objects,_position]] call zen_dialog_fnc_create;
};
private _tasks=["rush","hunt","creep","assault","retreat","patrol","cqb","garrison","camp","defend"];
if (_mode in _tasks) exitWith {
    if (count _groups==0) exitWith {systemChat "[BURNS] Select a squad or place the task module on an AI unit."};
    private _building=_mode in ["cqb","garrison","camp","defend"];
    private _radius=if (_building) then {100} else {500};
    private _options=[false,true,_mode in ["rush","hunt","creep"]];
    ["BURNS_request",[_mode,_groups,_objects,_position,_radius,_options,clientOwner]] call CBA_fnc_serverEvent;
};
private _instant=["reset","target","artillery_register","artillery_remove","enable_group","disable_group","enable_unit","disable_unit","radio_on","radio_off","reinforce_on","reinforce_off"];
if (_mode in _instant) exitWith {
    ["BURNS_request",[_mode,_groups,_objects,_position,150,[],clientOwner]] call CBA_fnc_serverEvent;
};
if (_mode!="artillery_fire") exitWith {systemChat "[BURNS] Unsupported action."};
["BURNS - Artillery Fire Mission",[
    ["SLIDER","Rounds per gun",[1,12,4,0]],
    ["SLIDER","Dispersion (m)",[0,300,50,0]]
],{
    params ["_values","_args"];
    _args params ["_groups","_objects","_position"];
    ["BURNS_request",["artillery_fire",_groups,_objects,_position,150,_values,clientOwner]] call CBA_fnc_serverEvent;
},{},[_groups,_objects,_position]] call zen_dialog_fnc_create;
