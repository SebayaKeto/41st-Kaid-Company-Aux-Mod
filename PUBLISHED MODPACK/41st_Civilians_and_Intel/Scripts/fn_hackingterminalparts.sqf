    
["FST_resetHackRepairButtons", {
    params ["_term", "_display", "_source", "_attempttext"];

    private _pressed = ["FST_1600Pressed","FST_1601Pressed","FST_1602Pressed","FST_1603Pressed","FST_1604Pressed","FST_1605Pressed","FST_1606Pressed","FST_1607Pressed","FST_1608Pressed","FST_1609Pressed","FST_1610Pressed"];
    _term setVariable [ _pressed select ( _source - 1600), true, true];
    private _count = 1600;
    for "_count" from 1600 to 1610 do
    {
        if !(_term getVariable [( _pressed select (_count - 1600)), false]) then {(_display displayCtrl _count) ctrlEnable true;};
    };
	(_display displayCtrl 1611) ctrlEnable true;
    (_display displayCtrl 1613) ctrlSetStructuredText parsetext _attempttext;
	_term setVariable ["FST_LastAttempt", _attempttext,true];
	(_display displayCtrl _source) ctrlSetTextColor [0.4,0.4,0.4,1];
	(_display displayCtrl _source) ctrlSetTooltip "You have already performed this repair";

}] call CBA_fnc_addEventHandler;

["FST_winHackRepair", {
    params ["_term", "_user", "_origin"];

    _term setVariable ["FST_DeviceBroken",false,true]; 
    _term setVariable ["FST_DeviceRepaired",true,true];
    _term setVariable ["FST_DeviceInUse",false,true]; 
    _user setVariable ["FST_PlayerIsMeching",false,true]; 
    _term removeAction _origin;
    _term addAction ['Hack Device', {[_this select 0, _this select 1, _this select 2] call FST_CivilRandomizers_fnc_hackingterminal;}, nil,6,true,true,"","true",3];
    hintSilent parseText "<t color='#0074cc'>Device operational<br/>You may attempt to hack again</t>";
    closeDialog 0;

}] call CBA_fnc_addEventHandler;

["FST_loseHackRepair", {
    params ["_term", "_user", "_text"];
    
    hintSilent parseText _text;
    _term setVariable ["FST_DeviceFullBroken",true,true];
    _term setVariable ["FST_DeviceInUse",false,true];
    _user setVariable ["FST_PlayerIsMeching",false,true];
    closeDialog 0;

}] call CBA_fnc_addEventHandler;
