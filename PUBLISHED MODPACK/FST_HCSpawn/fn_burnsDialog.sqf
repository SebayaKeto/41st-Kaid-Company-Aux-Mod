// Common Zeus dialog. ZEN supplies context selection even on remote HC units.
params ["_mode",["_groups",[]],["_objects",[]],["_position",[]],["_pickDestination",false]];
if (!hasInterface) exitWith {};
_groups=+_groups;
_objects=_objects select {!isNull _x};
{private _g=group _x; if (isNull _g) then {_g=group effectiveCommander _x}; if (!isNull _g) then {_groups pushBackUnique _g}} forEach _objects;
if (count _position<2) then {_position=if (count _groups>0) then {getPosATL leader (_groups select 0)} else {[0,0,0]}};
if (_pickDestination && {_mode in ["rush","hunt","creep","assault","retreat","cqb","garrison","camp","defend","patrol","target","artillery_fire"]}) exitWith {
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
private _instant=["reset","target","artillery_register","artillery_remove","enable_group","disable_group","enable_unit","disable_unit","radio_on","radio_off","reinforce_on","reinforce_off"];
if (_mode in _instant) exitWith {
    ["BURNS_request",[_mode,_groups,_objects,_position,150,[],clientOwner]] call CBA_fnc_serverEvent;
};
private _fields=[];
private _building=_mode in ["garrison","camp","defend","cqb"];
if (_mode=="artillery_fire") then {
    _fields=[["SLIDER","Rounds per gun",[1,12,4,0]],["SLIDER","Dispersion (m)",[0,300,50,0]]];
} else {
    _fields pushBack ["SLIDER","Area radius (m)",[25,if (_building) then {250} else {3000},if (_building) then {100} else {500},0]];
    if (_building) then {
        _fields pushBack ["CHECKBOX",["Teleport into position","Off makes units walk to their assigned positions."],false];
        _fields pushBack ["CHECKBOX",["Release hold on contact","Allow movement when the group knows an enemy. Defenders remain inside their area."],true];
    } else {
        if (_mode in ["rush","hunt","creep"]) then {
            _fields pushBack ["CHECKBOX",["Track enemy players","Use player positions to direct this search task. Firing still requires the AI to detect its target."],true];
        };
    };
};
["BURNS - "+toUpper _mode,_fields,{
    params ["_values","_args"];
    _args params ["_mode","_groups","_objects","_position","_building"];
    private _radius=150;
    private _options=[];
    if (_mode=="artillery_fire") then {_options=_values} else {
        _radius=_values select 0;
        _options=[false,true,false];
        if (_building) then {_options=[_values select 1,_values select 2,false]} else {
            if (_mode in ["rush","hunt","creep"]) then {_options set [2,_values select 1]};
        };
    };
    ["BURNS_request",[_mode,_groups,_objects,_position,_radius,_options,clientOwner]] call CBA_fnc_serverEvent;
},{},[_mode,_groups,_objects,_position,_building]] call zen_dialog_fnc_create;
