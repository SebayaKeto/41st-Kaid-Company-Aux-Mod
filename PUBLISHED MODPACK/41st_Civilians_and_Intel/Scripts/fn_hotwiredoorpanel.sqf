
#include "\a3\ui_f\hpp\defineCommonGrids.inc"

params ["_term","_user","_origin"];

private _text = "";

if (isNil (_term getVariable ["FST_DeviceLocked", nil])) then {_term setVariable ["FST_DeviceLocked", true, true];}; 

if (_term getVariable ["FST_DeviceInUse", false]) exitWith {_text = "<t color='#990000'>This door is currently being interacted with</t>"; hintSilent parseText _text;};
if !(_term getVariable ["FST_DeviceLocked", true]) exitWith {_text = "<t color='#990000'>This door is not locked</t>"; hintSilent parseText _text;};
if !(("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user)) exitWith {_text = "<t color='#990000'>You require a toolbox to attempt to hotwire</t>"; hintSilent parseText _text;};
if (_user getVariable ["FST_PlayerIsMeching", false]) exitWith {_text = "<t color='#990000'>You are already interacting with something else</t>"; hintSilent parseText _text;};

_term setVariable ["FST_DeviceInUse",true,true];
_user setVariable ["FST_PlayerIsMeching",true,true];

createDialog "FST_HotwireDoorDisplay";
private _display = findDisplay 6966;
_display setVariable ["FST_HotwireData", [_term, _user]];
_display setVariable ["FST_WireIDs", 10000];
_display setVariable ["FST_TFARKeys", [["tfar", "NextRadio"] call CBA_fnc_getKeybind, ["tfar", "NextRadioSW"] call CBA_fnc_getKeybind]];
_display displayAddEventHandler
[
	"KeyDown",
	{
		params ["_display", "_key", "_shift", "_ctrl", "_alt"];
		private _hotwiredata = _display getVariable "FST_HotwireData";
		_hotwiredata params ["_term", "_user"];
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
        if (_key == 14) then
        {

        };
		if (_key in [1, 219, 220]) then 
		{
			hintSilent parseText "<t color='#d67e09'>Hotwire cancelled</t>";
			_term setVariable ["FST_DeviceInUse",false,true];
			_user setVariable ["FST_PlayerIsMeching",false,true];
            closeDialog 0;
		};
    }
];
_display displayAddEventHandler
[
	"KeyUp",
	{
		params ["_display", "_key"];
		private _hotwiredata = _display getVariable "FST_HotwireData";
		_hotwiredata params ["_term", "_user"];
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

_display setVariable ["FST_ScreenUnready", true];
[_display, 6, 6, 3, 4999, nil, "RscPicture","FST_FuseGrid"] spawn FST_CivilRandomizers_fnc_createscreen;
[
    {
        params ["_display"];
        !(_display getVariable ["FST_ScreenUnready", true]);
    },
    {
        params ["_display", "_term", "_user"];
        _display setVariable ["FST_ScreenUnready", true];
        [_display, 6, 6, 3, 5999, [0,0,0,0], "FST_HotwireButton","FST_ButtonGrid"] spawn FST_CivilRandomizers_fnc_createscreen;
        [
            {
                params ["_display"];
                !(_display getVariable ["FST_ScreenUnready", true]);
            },
            {
                params ["_display", "_term", "_user"];
                _display setVariable ["FST_CurrentWireType",0];
                _display setVariable ["FST_WireColors",[[[0.933,0,0,1],[0.49,0,0,1]],[[0.059,0,0.871,1],[0.063,0.031,0.475,1]],[[0.051,0.714,0,1],[0.027,0.408,0,1]],[[1,1,0,1],[0.628,0.628,0,1]],[[1,0.592,0,1],[0.533,0.318,0,1]]]];
                for "_i" from 0 to 4 do
                {
			        ["FST_initializeWireButton", [_display, _term, _i]] call CBA_fnc_localEvent;
                };
                private _hindgrid = _display getVariable ["FST_FuseGrid", []];
                private _foregrid = _display getVariable ["FST_ButtonGrid", []];
                private _balance = [];
                for "_i" from 1 to 10 do 
                {
                    _balance pushBack "Minimal";
                };
                for "_i" from 1 to 11 do 
                {
                    _balance pushBack "Low";
                };
                for "_i" from 1 to 5 do 
                {
                    _balance pushBack "Medium";
                };
                for "_i" from 1 to 4 do 
                {
                    _balance pushBack "High";
                };
                for "_i" from 1 to 15 do 
                {
                    _balance pushBack "Special";
                };
                for "_i" from 1 to 4 do 
                {
                    _balance pushBack (selectRandom ["Minimal","Low","Medium","High","Special"]);
                };
                _balance = _balance call BIS_fnc_arrayShuffle;
                private _fuseimgs = ["\41st_Civilians_and_Intel\Data\2Fuse.paa","\41st_Civilians_and_Intel\Data\3Fuse.paa","\41st_Civilians_and_Intel\Data\5Fuse.paa","\41st_Civilians_and_Intel\Data\10Fuse.paa","\41st_Civilians_and_Intel\Data\15Fuse.paa","\41st_Civilians_and_Intel\Data\20Fuse.paa","\41st_Civilians_and_Intel\Data\25Fuse.paa","\41st_Civilians_and_Intel\Data\30Fuse.paa","\41st_Civilians_and_Intel\Data\50Fuse.paa","\41st_Civilians_and_Intel\Data\75Fuse.paa","\41st_Civilians_and_Intel\Data\100Fuse.paa","\41st_Civilians_and_Intel\Data\Terminal.paa","\41st_Civilians_and_Intel\Data\Blank.paa",["\41st_Civilians_and_Intel\Data\Obscured1Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured2Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured3Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured4Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured5Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured6Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured7Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured8Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured9Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured10Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured11Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured12Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured13Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured14Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured15Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured16Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured17Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured18Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured19Fuse.paa","\41st_Civilians_and_Intel\Data\Obscured20Fuse.paa"]];
                private _totalpower = 0;
                private _fuse = "";
                private _mintypes = [0, 30, 1, 30, 2, 30];
                private _lowtypes = [0, 30, 0, 30, 2, 30, 3, 30];
                private _medtypes = [0, 30, 1, 30];
                private _hightypes = [0, 30, 1, 30];
                private _spectypes = [0, 20, 1, 20, 2, 80];
                for "_xselect" from 0 to 6 do
                {
                    for "_yselect" from 0 to 6 do
                    {
                        private _chosenhind = (_hindgrid select _xselect) select _yselect;
                        private _chosenfore = (_foregrid select _xselect) select _yselect;
                        private _type = _balance deleteAt 0;
                        private _noskip = true;
                        switch (_type) do
                        {
                            case "Minimal":
                            {
                                private _selection = selectRandomWeighted _mintypes;
                                switch (_selection) do
                                {
                                    case 0:
                                    {
                                        _chosenfore setVariable ["FST_PowerValue", 2];
                                        _totalpower = _totalpower + 2;
                                        _fuse = _fuseimgs select 0;
                                        _mintypes set [1,(_mintypes select 1) / 2];
                                    };
                                    case 1:
                                    {
                                        _chosenfore setVariable ["FST_PowerValue", 3];
                                        _totalpower = _totalpower + 3;
                                        _fuse = _fuseimgs select 1;
                                        _mintypes set [3,(_mintypes select 3) / 2];
                                    };
                                    case 2:
                                    {
                                        _chosenfore setVariable ["FST_PowerValue", 5];
                                        _totalpower = _totalpower + 5;
                                        _fuse = _fuseimgs select 2;
                                        _mintypes set [5,(_mintypes select 5) / 2];
                                    };
                                };
                            };
                            case "Low":
                            {
                                private _selection = selectRandomWeighted _lowtypes;
                                switch (_selection) do
                                {
                                    case 0:
                                    {
                                        _chosenfore setVariable ["FST_PowerValue", 10];
                                        _totalpower = _totalpower + 10;
                                        _fuse = _fuseimgs select 3;
                                        _lowtypes set [1,(_lowtypes select 1) / 2];
                                    };
                                    case 1:
                                    {
                                        _chosenfore setVariable ["FST_PowerValue", 15];
                                        _totalpower = _totalpower + 15;
                                        _fuse = _fuseimgs select 4;
                                        _lowtypes set [3,(_lowtypes select 3) / 2];
                                    };
                                    case 2:
                                    {
                                        _chosenfore setVariable ["FST_PowerValue", 20];
                                        _totalpower = _totalpower + 20;
                                        _fuse = _fuseimgs select 5;
                                        _lowtypes set [5,(_lowtypes select 5) / 2];
                                    };
                                    case 3:
                                    {
                                        _chosenfore setVariable ["FST_PowerValue", 25];
                                        _totalpower = _totalpower + 25;
                                        _fuse = _fuseimgs select 6;
                                        _lowtypes set [7,(_lowtypes select 7) / 2];
                                    };
                                };
                            };
                            case "Medium":
                            {
                                private _selection = selectRandomWeighted _medtypes;
                                switch (_selection) do
                                {
                                    case 0:
                                    {
                                        _chosenfore setVariable ["FST_PowerValue", 30];
                                        _totalpower = _totalpower + 30;
                                        _fuse = _fuseimgs select 7;
                                        _medtypes set [1,(_medtypes select 1) / 2];
                                    };
                                    case 1:
                                    {
                                        _chosenfore setVariable ["FST_PowerValue", 50];
                                        _totalpower = _totalpower + 50;
                                        _fuse = _fuseimgs select 8;
                                        _medtypes set [3,(_medtypes select 3) / 2];
                                    };
                                };
                            };
                            case "High":
                            {
                                private _selection = selectRandomWeighted _hightypes;
                                switch (_selection) do
                                {
                                    case 0:
                                    {
                                        _chosenfore setVariable ["FST_PowerValue", 75];
                                        _totalpower = _totalpower + 75;
                                        _fuse = _fuseimgs select 9;
                                        _hightypes set [1,(_hightypes select 1) / 2];
                                    };
                                    case 1:
                                    {
                                        _chosenfore setVariable ["FST_PowerValue", 100];
                                        _totalpower = _totalpower + 100;
                                        _fuse = _fuseimgs select 10;
                                        _hightypes set [3,(_hightypes select 3) / 2];
                                    };
                                };
                            };
                            case "Special":
                            {
                                private _selection = selectRandomWeighted _spectypes;
                                switch (_selection) do
                                {
                                    case 0:
                                    {
                                        private _power = selectRandom [4,6,7,9,11,12,16,22,28,35,40,41,45,65,90,111,120,150];
                                        _chosenfore setVariable ["FST_PowerValue", _power];
                                        _totalpower = _totalpower + _power;
                                        _fuse = _fuseimgs select 11;
                                        _spectypes set [1,(_spectypes select 1) / 2];
                                    };
                                    case 1:
                                    {
                                        _noskip = false;
                                        _fuse = _fuseimgs select 12;
                                        _spectypes set [3,(_spectypes select 3) / 2];
                                    };
                                    case 2:
                                    {
                                        private _power = selectRandom [4,6,7,9,11,12,16,22,28,35,40,41,45,65,90,111,120,150];
                                        _chosenfore setVariable ["FST_PowerValue", _power];
                                        _totalpower = _totalpower + _power;
                                        _fuse = (_fuseimgs select 13) deleteAt (floor (random (count (_fuseimgs select 13))));
                                        _spectypes set [5,(_spectypes select 5) / 2];
                                    };
                                };
                            };
                        };
                        _chosenhind setVariable ["FST_UnpluggedImg", _fuse];
                        _chosenhind ctrlSetText _fuse;
                        if (_noskip) then
                        {
                            ["FST_initializeFuseButton", [_display,_chosenhind,_chosenfore,[_xselect,_yselect]]] call CBA_fnc_localEvent;
                        };
                    };
                };
            },
            [_display,_term,_user]
        ] call CBA_fnc_waitUntilAndExecute;
    },
    [_display,_term,_user]
] call CBA_fnc_waitUntilAndExecute;