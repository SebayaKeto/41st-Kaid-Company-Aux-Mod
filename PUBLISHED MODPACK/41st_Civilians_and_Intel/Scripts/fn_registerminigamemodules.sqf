
[
    "[41st] Object Minigames",
    "Add Hack/Repair Minigame",
    {
        params ["_location","_target"];
        if (isNull _target) exitWith {};
        [
            "Add Hack/Repair Minigame",
            [
                [
                    "CHECKBOX",
                    "Break Device?",
                    false
                ],
                [
                    "CHECKBOX",
                    "Enable Training Mode?",
                    false
                ]
            ],
            {
                params ["_inputs","_basics"];
                _inputs params ["_break","_test"];
                _basics params ["_location","_target"];
                if (_break) then {_target setVariable ["FST_DeviceBroken",true,true];};
                if !(_target getVariable ["FST_AddedHR",false]) then 
                {
                    _target setVariable ["FST_AddedHR",true,true];
                    [_target,['Hack Device', {[_this select 0, _this select 1, _this select 2] call FST_CivilRandomizers_fnc_hackingterminal;}, nil,6,true,true,"","!(_target getVariable ['FST_DeviceBroken', false])",3]] remoteExec ["addAction", 0, true];
                    [_target,['Repair Device', {[_this select 0, _this select 1, _this select 2] call FST_CivilRandomizers_fnc_hackingterminal;}, nil,6,true,true,"","_target getVariable ['FST_DeviceBroken', false]",3]] remoteExec ["addAction", 0, true];
                };
                if (!(_target getVariable ["FST_AddedHRDebug",false]) && _test) then 
                {
                    _target setVariable ["FST_AddedHRDebug",true,true];
                    [_target,['Reset Hack/Repair State', {[_this select 0, _this select 1] call FST_CivilRandomizers_fnc_testingbuttons;}, nil,5,true,true,"","true",3]] remoteExec ["addAction", 0, true];
                };
            },
            {},
            [_location,_target]
        ] call zen_dialog_fnc_create;
    }
] call zen_custom_modules_fnc_register;