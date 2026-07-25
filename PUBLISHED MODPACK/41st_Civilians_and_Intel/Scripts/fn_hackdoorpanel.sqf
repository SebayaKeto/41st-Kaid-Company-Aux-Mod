
#include "\a3\ui_f\hpp\defineCommonGrids.inc"

params ["_term","_user","_origin"];

private _text = "";

if (isNil (_term getVariable ["FST_DeviceLocked", nil])) then {_term setVariable ["FST_DeviceLocked", true, true];}; 

if (_term getVariable ["FST_DeviceInUse", false]) exitWith {_text = "<t color='#990000'>This door is currently being interacted with</t>"; hintSilent parseText _text;};
if !(_term getVariable ["FST_DeviceLocked", true]) exitWith {_text = "<t color='#990000'>This door is not locked</t>"; hintSilent parseText _text;};
if (!("FST_Hacking_Datapad" in items _user) && handgunWeapon _user != "FST_Hacking_Datapad") exitWith {_text = "<t color='#990000'>You do not have a hacking datapad in your inventory</t>"; hintSilent parseText _text;};
if (handgunWeapon _user != "FST_Hacking_Datapad") exitWith {_text = "<t color='#990000'>You do not have a hacking datapad equipped</t>"; hintSilent parseText _text;};
if (currentWeapon _user != "FST_Hacking_Datapad") exitWith {_text = "<t color='#990000'>You are not currently using your hacking datapad</t>"; hintSilent parseText _text;};
if (_user getVariable ["FST_PlayerIsHacking", false]) exitWith {_text = "<t color='#990000'>You are already hacking something else</t>"; hintSilent parseText _text;};

_term setVariable ["FST_DeviceInUse",true,true];
_user setVariable ["FST_PlayerIsHacking",true,true];

createDialog "FST_DigitalScreenHack";
private _display = findDisplay 6967;
_display setVariable ["FST_HackingData", [_term, _user]];
_display setVariable ["FST_TFARKeys", [["tfar", "NextRadio"] call CBA_fnc_getKeybind, ["tfar", "NextRadioSW"] call CBA_fnc_getKeybind]];
(_display displayCtrl 1901) ctrlShow false;
(_display displayCtrl 1902) ctrlShow false;
_display displayAddEventHandler
[
	"KeyDown",
	{
		params ["_display", "_key", "_shift", "_ctrl", "_alt"];
		private _hackingdata = _display getVariable "FST_HackingData";
		_hackingdata params ["_term", "_user"];
		private _keys = _display getVariable "FST_TFARKeys";
		private _srData = _keys select 0;
		private _lrData = _keys select 1;
		private _srkey =  (_srData select 0) select 0;
		private _srmods = [(_srData select 0) select 1, (_srData select 0) select 2, (_srData select 0) select 3];
		private _lrkey =  (_lrData select 0) select 0;
		private _lrmods = [(_lrData select 0) select 1, (_lrData select 0) select 2, (_lrData select 0) select 3];
		if (_key == _srkey && ((_srmods isEqualTo [false,false,false]) or ((_shift isEqualTo (_srmods select 0)) && (_ctrl isEqualTo (_srmods select 1)) && (_alt isEqualTo (_srmods select 2))))) then {
			if !(_user getVariable ["FST_SROn", false]) then {
				_user setVariable ["FST_SROn",true];
				[_user, false] call TFAR_fnc_processRadioOnKeyDown;
			};
		};
		if (_key == _lrkey && ((_lrmods isEqualTo [false,false,false]) or ((_shift isEqualTo (_lrmods select 0)) && (_ctrl isEqualTo (_lrmods select 1)) && (_alt isEqualTo (_lrmods select 2))))) then {
			if !(_user getVariable ["FST_LROn", false]) then {
				_user setVariable ["FST_LROn",true];
				[_user, true] call TFAR_fnc_processRadioOnKeyDown;
			};
		};
		if (_key in [1, 219, 220]) then 
		{
			hintSilent parseText "<t color='#d67e09'>Hack cancelled</t>";
			_term setVariable ["FST_DeviceInUse",false,true];
			_user setVariable ["FST_PlayerIsHacking",false,true];
            closeDialog 0;
		};
        if (_display getVariable ["FST_GameStart",false]) then
        {
            switch (_key) do
            {
                case 17: {["FST_MovePlayer", [_display, 0]] call CBA_fnc_localEvent;};
                case 30: {["FST_MovePlayer", [_display, 3]] call CBA_fnc_localEvent;};
                case 31: {["FST_MovePlayer", [_display, 2]] call CBA_fnc_localEvent;};
                case 32: {["FST_MovePlayer", [_display, 1]] call CBA_fnc_localEvent;};
                case 200: {["FST_MovePlayer", [_display, 0]] call CBA_fnc_localEvent;};
                case 203: {["FST_MovePlayer", [_display, 3]] call CBA_fnc_localEvent;};
                case 208: {["FST_MovePlayer", [_display, 2]] call CBA_fnc_localEvent;};
                case 205: {["FST_MovePlayer", [_display, 1]] call CBA_fnc_localEvent;};
            };
        }; 
}
];
_display displayAddEventHandler
[
	"KeyUp",
	{
		params ["_display", "_key"];
		private _hackingdata = _display getVariable "FST_HackingData";
		_hackingdata params ["_term", "_user"];
		private _srData = ["tfar", "NextRadio"] call CBA_fnc_getKeybind;
		private _lrData = ["tfar", "NextRadioSW"] call CBA_fnc_getKeybind;
		private _srkey =  (_srData select 0) select 0;
		private _lrkey =  (_lrData select 0) select 0;
		if (_key == _srkey) then {
			_user setVariable ["FST_SROn",false];
			[_user, false] call TFAR_fnc_processRadioOnKeyUp;
		};
		if (_key == _lrkey) then {
			_user setVariable ["FST_LROn",false];
			[_user, true] call TFAR_fnc_processRadioOnKeyUp;
		};
	}
];
private _button1903 = _display displayCtrl 1903;
_button1903 setVariable ["FST_HackingData", [_term, _user]];
_button1903 ctrlAddEventHandler 
[
	"ButtonClick",
	{
		params ["_control"];
		private _hackingdata = _control getVariable "FST_HackingData";
		_hackingdata params ["_term", "_user"];
		playsound (selectRandom ["3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick1.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick2.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick3.ogg"]);
		hintSilent parseText "<t color='#d67e09'>Hack cancelled</t>";
		_term setVariable ["FST_DeviceInUse",false,true];
		_user setVariable ["FST_PlayerIsHacking",false,true];
		closeDialog 2;
	}
];
private _button1900 = _display displayCtrl 1900;
_button1900 setVariable ["FST_HackingData", [_term, _user]];
_button1900 ctrlSetText "START DOOR HACK";
_button1900 ctrlSetTooltip "Begin Minigame";
_button1900 ctrlAddEventHandler 
[
	"ButtonClick",
	{
		
		params ["_control"];
		private _hackingData = _control getVariable "FST_HackingData";
		_hackingData params ["_term", "_user"];
        playSoundUI [(selectRandom ["3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick1.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick2.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick3.ogg"]),4,1,true];
		private _display = findDisplay 6967;
        {
			_x ctrlShow false;
		} forEach 
		[
			_display displayCtrl 1807,
			_display displayCtrl 1808,
			_display displayCtrl 1809,
			_display displayCtrl 1810,
			_display displayCtrl 1811,
			_display displayCtrl 1900,
			_display displayCtrl 1903,
			_display displayCtrl 1904,
			_display displayCtrl 1905
		];
        _display setVariable ["FST_ScreenUnready", true];
        [_display, 60, 48, 0.41] spawn FST_CivilRandomizers_fnc_createscreen;
        [
            {
                params ["_display"];
                !(_display getVariable ["FST_ScreenUnready", true]);
            },
            {
                params ["_display","_term","_user"];
                ["FST_createGameGrid", [ _display, 2, false, "FST_MovementGridCenters"]] call CBA_fnc_localEvent;
                ["FST_createGameGrid", [ _display, 0, true, "FST_WallCenters"]] call CBA_fnc_localEvent;
                ["FST_createWalls", [_display]] call CBA_fnc_localEvent;
                ["FST_createPlayer", [_display]] call CBA_fnc_localEvent;
                private _colors = [[0.239,0.914,0.922,1],[1,0.973,0.22,1],[0.875,0.149,0.847,1]];
                for "_i" from 0 to 2 do
                {
                    ["FST_createGoals", [_display, (_colors select _i), _i]] call CBA_fnc_localEvent;
                    ["FST_createKeys", [_display, (_colors select _i), _i]] call CBA_fnc_localEvent;
                };
                ["FST_runEnemy", [_display,2,2]] spawn CBA_fnc_localEvent;
                ["FST_runEnemy", [_display,2,8]] spawn CBA_fnc_localEvent;
                ["FST_runEnemy", [_display,11,2]] spawn CBA_fnc_localEvent;
                ["FST_runEnemy", [_display,11,8]] spawn CBA_fnc_localEvent;
                _display setVariable ["FST_KeysDeposited", 0];
                _display setVariable ["FST_GameStart",true];
                [
                    {
                        params ["_display"];
                        ((_display getVariable ["FST_PlayerDead", false]) or ((_display getVariable ["FST_KeysDeposited", 0]) == 3));
                    },
                    {
                        params ["_display","_term","_user"];
                        _display setVariable ["FST_GameStart",false];
                        _term setVariable ["FST_DeviceInUse",false,true]; 
                        _user setVariable ["FST_PlayerIsHacking",false,true];
                        if (_display getVariable ["FST_PlayerDead", false]) then
                        {
                            private _finish = _display ctrlCreate ["RscStructuredText", 4998];
                            _finish ctrlSetPosition
                            [
                                18.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                                12 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                                4 * GUI_GRID_CENTER_W,
                                2 * GUI_GRID_CENTER_H
                            ];
                            _finish ctrlSetBackgroundColor [0,0,0,1];
                            _finish ctrlSetStructuredText parsetext "<t align='center' font='RobotoCondensedBold' color='#990000'>HACK DETECTED</t>";
                            _finish ctrlCommit 0;
                        };
                        if ((_display getVariable ["FST_KeysDeposited", 0]) == 3) then 
                        {
                            private _finish = _display ctrlCreate ["RscStructuredText", 4998];
                            _finish ctrlSetPosition
                            [
                                18.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                                12 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                                4 * GUI_GRID_CENTER_W,
                                2 * GUI_GRID_CENTER_H
                            ];
                            _finish ctrlSetBackgroundColor [0,0,0,1];
                            _finish ctrlSetStructuredText parsetext "<t align='center' font='RobotoCondensedBold' color='#2ecc71'>DOOR UNLOCKED</t>";
                            _finish ctrlCommit 0;
                        };
                        [
                            {
                                closeDialog 0;
                            },
                            [],
                            5
                        ] call CBA_fnc_waitAndExecute;
                    },
                    [_display,_term,_user]
                ] call CBA_fnc_waitUntilAndExecute;
            },
            [_display,_term,_user]
        ] call CBA_fnc_waitUntilAndExecute;
    }
];