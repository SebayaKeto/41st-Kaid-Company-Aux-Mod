
#include "\a3\ui_f\hpp\defineCommonGrids.inc"

["FST_initializeWireButton", {
    params ["_display", "_term", "_num"];
    _button = _display displayCtrl (1900 + _num);
    _button setVariable ["FST_WireData",[_display,_term,_num]];
    _button ctrlAddEventHandler 
    [
        "MouseButtonDown",
        {
            params ["_control"];
            (_control getVariable "FST_WireData") params ["_display","_term","_num"];
            if ((!(_term getVariable ["FST_DeviceLocked", true])) or (_display getVariable ["FST_WireUnready",false]) or ((_display getVariable "FST_CurrentWireType") == _num)) exitWith {};
            switch (_display getVariable "FST_CurrentWireType") do
            {
                case 0:
                {
                    (_display displayCtrl 1895) ctrlSetText "\41st_Civilians_and_Intel\Data\RedSpool.paa";
                };
                case 1:
                {
                    (_display displayCtrl 1896) ctrlSetText "\41st_Civilians_and_Intel\Data\BlueSpool.paa";
                };
                case 2:
                {
                    (_display displayCtrl 1897) ctrlSetText "\41st_Civilians_and_Intel\Data\GreenSpool.paa";
                };
                case 3:
                {
                    (_display displayCtrl 1898) ctrlSetText "\41st_Civilians_and_Intel\Data\YellowSpool.paa";
                };
                case 4:
                {
                    (_display displayCtrl 1899) ctrlSetText "\41st_Civilians_and_Intel\Data\OrangeSpool.paa";
                };
            };
            _display setVariable ["FST_CurrentWireType", _num];
            switch (_num) do
            {
                case 0:
                {
                    (_display displayCtrl 1895) ctrlSetText "\41st_Civilians_and_Intel\Data\RedSpoolUse.paa";
                    (_display displayCtrl 1905) ctrlSetAngle [0,0.5,0.5];
                };
                case 1:
                {
                    (_display displayCtrl 1896) ctrlSetText "\41st_Civilians_and_Intel\Data\BlueSpoolUse.paa";
                    (_display displayCtrl 1905) ctrlSetAngle [45,0.5,0.5];
                };
                case 2:
                {
                    (_display displayCtrl 1897) ctrlSetText "\41st_Civilians_and_Intel\Data\GreenSpoolUse.paa";
                    (_display displayCtrl 1905) ctrlSetAngle [90,0.5,0.5];
                };
                case 3:
                {
                    (_display displayCtrl 1898) ctrlSetText "\41st_Civilians_and_Intel\Data\YellowSpoolUse.paa";
                    (_display displayCtrl 1905) ctrlSetAngle [135,0.5,0.5];
                };
                case 4:
                {
                    (_display displayCtrl 1899) ctrlSetText "\41st_Civilians_and_Intel\Data\OrangeSpoolUse.paa";
                    (_display displayCtrl 1905) ctrlSetAngle [180,0.5,0.5];
                };
            };
        }
    ];

}] call CBA_fnc_addEventHandler;

["FST_initializeFuseButton", {
    params ["_display", "_image", "_clicked", "_coords"];
    _clicked setVariable ["FST_FuseData", [_display,_image,_coords]];
    _clicked ctrlAddEventHandler
    [
        "MouseButtonDown",
        {
            params ["_control", "_button"];
            (_control getVariable "FST_FuseData") params ["_display","_image","_coords"];
            (_display getVariable "FST_HotwireData") params ["_term", "_user"];
            if ((!(_term getVariable ["FST_DeviceLocked", true])) or (_display getVariable ["FST_WireUnready",false])) exitWith {};
            if ((_button == 1) && !((_control getVariable ["FST_ConnectedFuse", 0]) isEqualTo 0)) exitWith 
            {
                (_control getVariable "FST_ConnectedFuse") params ["_otherctrl","_otherimg"];
                (_control getVariable "FST_Wire") params ["_wirectrls"];
                _image ctrlSetText (_image getVariable "FST_UnpluggedImg");
                _otherimg ctrlSetText (_otherimg getVariable "FST_UnpluggedImg");
                for "_i" from 1 to (count _wirectrls) do
                {
                    ctrlDelete (_wirectrls deleteAt 0);
                };
                _control setVariable ["FST_ConnectedFuse", nil];
                _otherctrl setVariable ["FST_ConnectedFuse", nil];
                _control setVariable ["FST_Wire", nil];
                _otherctrl setVariable ["FST_Wire", nil];
            };
            if (_button == 1) exitWith {};
            if (((_display getVariable ["FST_FirstButton",[0,0,0]]) select 1) isEqualTo _control) exitWith 
            {
                _image ctrlSetText (_image getVariable "FST_UnpluggedImg");
                _display setVariable ["FST_ConnectWire", false];
                _display setVariable ["FST_FirstButton", nil];
            };
            if ((_display getVariable ["FST_ConnectWire", false]) && ((_control getVariable ["FST_ConnectedFuse", 0]) isEqualTo 0)) exitWith 
            {
                (_display getVariable "FST_FirstButton") params ["_firstcoords","_firstclicked","_firstimage"];
                _control setVariable ["FST_ConnectedFuse", [_firstclicked,_firstimage]];
                _firstclicked setVariable ["FST_ConnectedFuse", [_control,_image]];
                _display setVariable ["FST_ConnectWire", false];
                _display setVariable ["FST_FirstButton", nil];
                ["FST_createWire", [_display,_control,_image,_coords,_firstclicked,_firstimage,_firstcoords]] spawn CBA_fnc_localEvent;
            };
            if ((_control getVariable ["FST_ConnectedFuse", 0]) isEqualTo 0) exitWith 
            {
                _image ctrlSetText "\41st_Civilians_and_Intel\Data\WireBase.paa";
                _display setVariable ["FST_ConnectWire", true];
                _display setVariable ["FST_FirstButton", [_coords,_control,_image]];
            };
        }
    ];
}] call CBA_fnc_addEventHandler;

["FST_createWire", {
    params ["_display","_ctrla","_imga","_coordsa","_ctrlb","_imgb","_coordsb"];
    _display setVariable ["FST_WireUnready",true];
    
    ((_display getVariable "FST_WireColors") select (_display getVariable "FST_CurrentWireType")) params ["_pc","_sc"];
    private _anglea = (((_coordsa select 1) - (_coordsb select 1)) atan2 ((_coordsa select 0) - (_coordsb select 0)));
    _anglea = (_anglea + 360) % 360;
    _imgb ctrlSetText format (["\41st_Civilians_and_Intel\Data\Wire%1.paa",(floor ((round (_anglea / 22.5) % 16) * 22.5))]);
    private _angleb = (_anglea + 180) % 360;
    _imga ctrlSetText format (["\41st_Civilians_and_Intel\Data\Wire%1.paa",(floor ((round (_angleb / 22.5) % 16) * 22.5))]);
    private _wireoffset = [[2.8,1.25],[2.75,1.75],[2.5,2.25],[1.75,2.75],[1.25,2.8],[0.75,2.75],[0.5,2.25],[0.25,1.75],[0.2,1.75],[0.25,1.25],[0.5,0.25],[0.75,0.25],[1.75,0.2],[1.75,0.25],[2.5,0.25],[2.75,0.75]];
    private _xa = 7.5 + (_coordsa select 0) * 3 + ((_wireoffset select (round (_angleb / 22.5) % 16)) select 0);
    private _ya = 3.5 + (_coordsa select 1) * 3 + ((_wireoffset select (round (_angleb / 22.5) % 16)) select 1);
    private _xb = 7.5 + (_coordsb select 0) * 3 + ((_wireoffset select (round (_anglea / 22.5) % 16)) select 0);
    private _yb = 3.5 + (_coordsb select 1) * 3 + ((_wireoffset select (round (_anglea / 22.5) % 16)) select 1);
    private _wirectrls = [];
    switch (floor ((round (_anglea / 22.5) % 16) * 22.5)) do
    {
        case 0;
        case 180:
        {
            if ((_coordsa select 1) == (_coordsb select 1)) then
            {
                private _upperx = _xa min _xb;
                private _uppery = _ya min _yb;
                private _lowerx = _xa max _xb;
                private _lowery = _ya max _yb;
                private _id = _display getVariable "FST_WireIDs";
                private _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    _upperx * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    _uppery * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    (_lowerx - _upperx) * GUI_GRID_CENTER_W,
                    (_lowery - _uppery) * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _pc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
                _id = _id + 1;
                _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    _upperx * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    (_uppery - 0.05) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    (_lowerx - _upperx) * GUI_GRID_CENTER_W,
                    0.1 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _sc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
                _id = _id + 1;
                _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    _upperx * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    ((_uppery - 0.05) + (_lowery - _uppery)) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    (_lowerx - _upperx) * GUI_GRID_CENTER_W,
                    0.1 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _sc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
                _display setVariable ["FST_WireIDs", _id];
            }
            else
            {
                private _startx = _xa min _xb;
                private _endx = 0;
                private _starty = 0;
                private _endy = 0;
                if (_startx == _xa) then {_starty = _ya; _endx = _xb; _endy = _yb;} else {_starty = _yb; _endx = _xa; _endy = _ya;};
                private _dx = _endx - _startx;
                private _dy = (_endy - _starty) - 0.5;
                private _angle = _dy atan2 _dx;
                private _length = sqrt (_dx ^ 2 + _dy ^ 2);
                private _freq = (3 * 360) / _length;
                private _id = _display getVariable "FST_WireIDs";
                for "_x" from 0 to _length step 0.1 do
                {
                    private _thisy = 0.3 * sin (_x * _freq);
                    private _rx = _x * cos _angle - _thisy * sin _angle;
                    private _ry = _x * sin _angle + _thisy * cos _angle;
                    _id = (_id + (_x * 10));
                    private _wire = _display ctrlCreate ["RscText", _id];
                    _wire ctrlSetPosition
                    [
                        (_rx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                        (_ry + _starty) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                        0.12 * GUI_GRID_CENTER_W,
                        0.5 * GUI_GRID_CENTER_H
                    ];
                    _wire ctrlSetBackgroundColor _pc;
                    _wire ctrlCommit 0;
                    _wirectrls pushBack _wire;
                };
                for "_x" from 0 to _length step 0.1 do
                {
                    private _thisy = 0.3 * sin (_x * _freq);
                    private _rx = _x * cos _angle - _thisy * sin _angle;
                    private _ry = _x * sin _angle + _thisy * cos _angle;
                    _id = (_id + (_x * 10));
                    private _wire = _display ctrlCreate ["RscText", _id];
                    _wire ctrlSetPosition
                    [
                        (_rx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                        ((_ry + _starty) - 0.05) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                        0.12 * GUI_GRID_CENTER_W,
                        0.1 * GUI_GRID_CENTER_H
                    ];
                    _wire ctrlSetBackgroundColor _sc;
                    _wire ctrlCommit 0;
                    _wirectrls pushBack _wire;
                };
                for "_x" from 0 to _length step 0.1 do
                {
                    private _thisy = 0.3 * sin (_x * _freq);
                    private _rx = _x * cos _angle - _thisy * sin _angle;
                    private _ry = _x * sin _angle + _thisy * cos _angle;
                    _id = (_id + (_x * 10));
                    private _wire = _display ctrlCreate ["RscText", _id];
                    _wire ctrlSetPosition
                    [
                        (_rx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                        (((_ry + _starty) - 0.05) + 0.5) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                        0.12 * GUI_GRID_CENTER_W,
                        0.1 * GUI_GRID_CENTER_H
                    ];
                    _wire ctrlSetBackgroundColor _sc;
                    _wire ctrlCommit 0;
                    _wirectrls pushBack _wire;
                };
                _display setVariable ["FST_WireIDs", _id];
            };
        };
        case 22;
        case 202:
        {
            private _startx = _xa min _xb;
            private _endx = 0;
            private _starty = 0;
            private _endy = 0;
            if (_startx == _xa) then {_starty = _ya; _endx = _xb; _endy = _yb;} else {_starty = _yb; _endx = _xa; _endy = _ya;};
            private _dx = _endx - _startx;
            private _dy = (_endy - _starty) - 0.5;
            private _angle = _dy atan2 _dx;
            private _length = sqrt (_dx ^ 2 + _dy ^ 2);
            private _waves = 1;
            private _amp = 0;
            if (_dx == 3.5) then 
            {_amp = 0.1;};
            if (_dx in [6.5,9.5]) then 
            {_waves = 2; if ((_dy == 5) && (_dx == 6.5)) then {_amp = 0.1;} else {_amp = 0.2;};};
            if (_dx in [12.5,15.5]) then 
            {_waves = 3; if (((_dy == 8) && (_dx == 12.5)) or ((_dy == 11) && (_dx == 15.5))) then {_amp = 0.1;} else {_amp = 0.3;}};
            private _freq = (_waves * 360) / _length;
            private _id = _display getVariable "FST_WireIDs";
            for "_x" from 0 to _length step 0.1 do
            {
                private _thisy = _amp * sin (_x * _freq);
                private _rx = _x * cos _angle - _thisy * sin _angle;
                private _ry = _x * sin _angle + _thisy * cos _angle;
                _id = (_id + (_x * 10));
                private _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    (_rx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    (_ry + _starty) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.12 * GUI_GRID_CENTER_W,
                    0.5 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _pc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
            };
            for "_x" from 0 to _length step 0.1 do
            {
                private _thisy = _amp * sin (_x * _freq);
                private _rx = _x * cos _angle - _thisy * sin _angle;
                private _ry = _x * sin _angle + _thisy * cos _angle;
                _id = (_id + (_x * 10));
                private _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    (_rx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    ((_ry + _starty) - 0.05) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.12 * GUI_GRID_CENTER_W,
                    0.1 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _sc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
            };
            for "_x" from 0 to _length step 0.1 do
            {
                private _thisy = _amp * sin (_x * _freq);
                private _rx = _x * cos _angle - _thisy * sin _angle;
                private _ry = _x * sin _angle + _thisy * cos _angle;
                _id = (_id + (_x * 10));
                private _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    (_rx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    (((_ry + _starty) - 0.05) + 0.5) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.12 * GUI_GRID_CENTER_W,
                    0.1 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _sc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
            };
            _display setVariable ["FST_WireIDs", _id];
        };
        case 45;
        case 225:
        {
            private _startx = _xa min _xb;
            private _endx = 0;
            private _starty = 0;
            private _endy = 0;
            if (_startx == _xa) then {_starty = _ya; _endx = _xb; _endy = _yb;} else {_starty = _yb; _endx = _xa; _endy = _ya;};
            private _dx = _endx - _startx;
            private _dy = _endy - _starty;
            private _angle = _dy atan2 _dx;
            private _length = sqrt (_dx ^ 2 + _dy ^ 2);
            private _tempx = -0.1 * cos _angle - 0 * sin _angle;
            private _tempy = -0.1 * sin _angle + 0 * cos _angle;
            private _id = _display getVariable "FST_WireIDs";
            private _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                ((_tempy + _starty) + 0.125) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.25 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _pc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            _tempx = -0.2 * cos _angle - 0 * sin _angle;
            _tempy = -0.2 * sin _angle + 0 * cos _angle;
            _id = _id + 1;
            _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                ((_tempy + _starty) + 0.25) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.125 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _pc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            _tempx = -0.1 * cos _angle - 0 * sin _angle;
            _tempy = -0.1 * sin _angle + 0 * cos _angle;
            _id = _id + 1;
            _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                (((_tempy + _starty) - 0.05) + 0.5) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.1 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _sc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            _tempx = -0.2 * cos _angle - 0 * sin _angle;
            _tempy = -0.2 * sin _angle + 0 * cos _angle;
            _id = _id + 1;
            _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                (((_tempy + _starty) - 0.05) + 0.5) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.1 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _sc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            _tempx = -0.3 * cos _angle - 0 * sin _angle;
            _tempy = -0.3 * sin _angle + 0 * cos _angle;
            _id = _id + 1;
            _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                (((_tempy + _starty) - 0.05) + 0.5) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.1 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _sc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            _tempx = (_length + 0.1) * cos _angle - 0 * sin _angle;
            _tempy = (_length + 0.1) * sin _angle + 0 * cos _angle;
            _id = _id + 1;
            _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                (_tempy + _starty) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.25 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _pc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            _tempx = (_length + 0.2) * cos _angle - 0 * sin _angle;
            _tempy = (_length + 0.2) * sin _angle + 0 * cos _angle;
            _id = _id + 1;
            _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                (_tempy + _starty) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.125 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _pc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            _tempx = (_length + 0.1) * cos _angle - 0 * sin _angle;
            _tempy = (_length + 0.1) * sin _angle + 0 * cos _angle;
            _id = _id + 1;
            _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                ((_tempy + _starty) - 0.05) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.1 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _sc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            _tempx = (_length + 0.2) * cos _angle - 0 * sin _angle;
            _tempy = (_length + 0.2) * sin _angle + 0 * cos _angle;
            _id = _id + 1;
            _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                ((_tempy + _starty) - 0.05) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.1 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _sc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            _tempx = (_length + 0.3) * cos _angle - 0 * sin _angle;
            _tempy = (_length + 0.3) * sin _angle + 0 * cos _angle;
            _id = _id + 1;
            _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                ((_tempy + _starty) - 0.05) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.1 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _sc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            for "_x" from 0 to _length step 0.1 do
            {
                private _thisy = 0;
                private _rx = _x * cos _angle - _thisy * sin _angle;
                private _ry = _x * sin _angle + _thisy * cos _angle;
                _id = _id + 1;
                _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    (_rx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    (_ry + _starty) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.12 * GUI_GRID_CENTER_W,
                    0.5 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _pc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
            };
            for "_x" from 0 to _length step 0.1 do
            {
                private _thisy = 0;
                private _rx = _x * cos _angle - _thisy * sin _angle;
                private _ry = _x * sin _angle + _thisy * cos _angle;
                _id = _id + 1;
                _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    (_rx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    ((_ry + _starty) - 0.05) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.12 * GUI_GRID_CENTER_W,
                    0.1 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _sc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
            };
            for "_x" from 0 to _length step 0.1 do
            {
                private _thisy = 0;
                private _rx = _x * cos _angle - _thisy * sin _angle;
                private _ry = _x * sin _angle + _thisy * cos _angle;
                _id = _id + 1;
                _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    (_rx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    (((_ry + _starty) - 0.05) + 0.5) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.12 * GUI_GRID_CENTER_W,
                    0.1 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _sc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
            };
            _display setVariable ["FST_WireIDs", _id];
        };
        case 67;
        case 247:
        {
            private _starty = _ya min _yb;
            private _endx = 0;
            private _startx = 0;
            private _endy = 0;
            if (_starty == _ya) then {_startx = _xa; _endx = _xb; _endy = _yb;} else {_startx = _xb; _endx = _xa; _endy = _ya;};
            private _dx = _endx - _startx;
            private _dy = _endy - _starty;
            private _angle = _dy atan2 _dx;
            private _length = sqrt (_dx ^ 2 + _dy ^ 2);
            private _waves = 1;
            private _amp = 0;
            if (_dy == 3.5) then 
            {_amp = 0.1;};
            if (_dy in [6.5,9.5]) then 
            {_waves = 2; if ((_dx == 5) && (_dy == 6.5)) then {_amp = 0.1;} else {_amp = 0.2;};};
            if (_dy in [12.5,15.5]) then 
            {_waves = 3; if (((_dx == 8) && (_dy == 12.5)) or ((_dx == 11) && (_dy == 15.5))) then {_amp = 0.1;} else {_amp = 0.3;}};
            private _freq = (_waves * 360) / _length;
            private _id = _display getVariable "FST_WireIDs";
            for "_x" from 0 to _length step 0.1 do
            {
                private _thisy = _amp * sin (_x * _freq);
                private _rx = _x * cos _angle - _thisy * sin _angle;
                private _ry = _x * sin _angle + _thisy * cos _angle;
                _id = (_id + (_x * 10));
                private _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    (_rx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    (_ry + _starty) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.5 * GUI_GRID_CENTER_W,
                    0.12 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _pc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
            };
            for "_x" from 0 to _length step 0.1 do
            {
                private _thisy = _amp * sin (_x * _freq);
                private _rx = _x * cos _angle - _thisy * sin _angle;
                private _ry = _x * sin _angle + _thisy * cos _angle;
                _id = (_id + (_x * 10));
                private _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    ((_rx + _startx) - 0.05) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    (_ry + _starty) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.1 * GUI_GRID_CENTER_W,
                    0.12 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _sc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
            };
            for "_x" from 0 to _length step 0.1 do
            {
                private _thisy = _amp * sin (_x * _freq);
                private _rx = _x * cos _angle - _thisy * sin _angle;
                private _ry = _x * sin _angle + _thisy * cos _angle;
                _id = (_id + (_x * 10));
                private _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    (((_rx + _startx) - 0.05) + 0.5) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    (_ry + _starty) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.1 * GUI_GRID_CENTER_W,
                    0.12 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _sc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
            };
            _display setVariable ["FST_WireIDs", _id];
        };
        case 90;
        case 270:
        {
            if ((_coordsa select 0) == (_coordsb select 0)) then
            {
                private _upperx = _xa min _xb;
                private _uppery = _ya min _yb;
                private _lowerx = _xa max _xb;
                private _lowery = _ya max _yb;
                private _id = _display getVariable "FST_WireIDs";
                private _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    _upperx * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    _uppery * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    (_lowerx - _upperx) * GUI_GRID_CENTER_W,
                    (_lowery - _uppery) * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _pc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
                _id = _id + 1;
                _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    (_upperx - 0.05) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    _uppery * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.1 * GUI_GRID_CENTER_W,
                    (_lowery - _uppery) * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _sc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
                _id = _id + 1;
                _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    ((_upperx - 0.05) + (_lowerx - _upperx)) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    _uppery * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.1 * GUI_GRID_CENTER_W,
                    (_lowery - _uppery) * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _sc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
                _display setVariable ["FST_WireIDs", _id];
            }
            else
            {
                private _starty = _ya min _yb;
                private _endx = 0;
                private _startx = 0;
                private _endy = 0;
                if (_starty == _ya) then {_startx = _xa; _endx = _xb; _endy = _yb;} else {_startx = _xb; _endx = _xa; _endy = _ya;};
                private _dx = (_endx - _startx) - 0.5;
                private _dy = _endy - _starty;
                private _angle = _dy atan2 _dx;
                private _length = sqrt (_dx ^ 2 + _dy ^ 2);
                private _freq = (3 * 360) / _length;
                private _id = _display getVariable "FST_WireIDs";
                for "_x" from 0 to _length step 0.1 do
                {
                    private _thisy = 0.3 * sin (_x * _freq);
                    private _rx = _x * cos _angle - _thisy * sin _angle;
                    private _ry = _x * sin _angle + _thisy * cos _angle;
                    _id = _id + 1;
                        private _wire = _display ctrlCreate ["RscText", _id];
                    _wire ctrlSetPosition
                    [
                        (_rx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                        (_ry + _starty) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                        0.5 * GUI_GRID_CENTER_W,
                        0.12 * GUI_GRID_CENTER_H
                    ];
                    _wire ctrlSetBackgroundColor _pc;
                    _wire ctrlCommit 0;
                    _wirectrls pushBack _wire;
                };
                for "_x" from 0 to _length step 0.1 do
                {
                    private _thisy = 0.3 * sin (_x * _freq);
                    private _rx = _x * cos _angle - _thisy * sin _angle;
                    private _ry = _x * sin _angle + _thisy * cos _angle;
                    _id = _id + 1;
                    private _wire = _display ctrlCreate ["RscText", _id];
                    _wire ctrlSetPosition
                    [
                        ((_rx + _startx) - 0.05) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                        (_ry + _starty) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                        0.1 * GUI_GRID_CENTER_W,
                        0.12 * GUI_GRID_CENTER_H
                    ];
                    _wire ctrlSetBackgroundColor _sc;
                    _wire ctrlCommit 0;
                    _wirectrls pushBack _wire;
                };
                for "_x" from 0 to _length step 0.1 do
                {
                    private _thisy = 0.3 * sin (_x * _freq);
                    private _rx = _x * cos _angle - _thisy * sin _angle;
                    private _ry = _x * sin _angle + _thisy * cos _angle;
                    _id = _id + 1;
                    private _wire = _display ctrlCreate ["RscText", _id];
                    _wire ctrlSetPosition
                    [
                        (((_rx + _startx) - 0.05) + 0.5) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                        (_ry + _starty) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                        0.1 * GUI_GRID_CENTER_W,
                        0.12 * GUI_GRID_CENTER_H
                    ];
                    _wire ctrlSetBackgroundColor _sc;
                    _wire ctrlCommit 0;
                    _wirectrls pushBack _wire;
                };
                _display setVariable ["FST_WireIDs", _id];
            };
        };
        case 112;
        case 292:
        {
            private _starty = _ya min _yb;
            private _endx = 0;
            private _startx = 0;
            private _endy = 0;
            if (_starty == _ya) then {_startx = _xa; _endx = _xb; _endy = _yb;} else {_startx = _xb; _endx = _xa; _endy = _ya;};
            private _dx = _endx - _startx;
            private _dy = _endy - _starty;
            private _angle = _dy atan2 _dx;
            private _length = sqrt (_dx ^ 2 + _dy ^ 2);
            private _waves = 1;
            private _amp = 0;
            if (_dy == 3.5) then 
            {_amp = -0.1;};
            if (_dy in [6.5,9.5]) then 
            {_waves = 2; if ((_dx == -5) && (_dy == 6.5)) then {_amp = -0.1;} else {_amp = -0.2;};};
            if (_dy in [12.5,15.5]) then 
            {_waves = 3; if (((_dx == -8) && (_dy == 12.5)) or ((_dx == -11) && (_dy == 15.5))) then {_amp = -0.1;} else {_amp = -0.3;}};
            private _freq = (_waves * 360) / _length;
            private _id = _display getVariable "FST_WireIDs";
            for "_x" from 0 to _length step 0.1 do
            {
                private _thisy = _amp * sin (_x * _freq);
                private _rx = _x * cos _angle - _thisy * sin _angle;
                private _ry = _x * sin _angle + _thisy * cos _angle;
                _id = (_id + (_x * 10));
                private _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    (_rx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    (_ry + _starty) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.5 * GUI_GRID_CENTER_W,
                    0.12 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _pc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
            };
            for "_x" from 0 to _length step 0.1 do
            {
                private _thisy = _amp * sin (_x * _freq);
                private _rx = _x * cos _angle - _thisy * sin _angle;
                private _ry = _x * sin _angle + _thisy * cos _angle;
                _id = (_id + (_x * 10));
                private _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    ((_rx + _startx) - 0.05) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    (_ry + _starty) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.1 * GUI_GRID_CENTER_W,
                    0.12 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _sc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
            };
            for "_x" from 0 to _length step 0.1 do
            {
                private _thisy = _amp * sin (_x * _freq);
                private _rx = _x * cos _angle - _thisy * sin _angle;
                private _ry = _x * sin _angle + _thisy * cos _angle;
                _id = (_id + (_x * 10));
                private _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    (((_rx + _startx) - 0.05) + 0.5) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    (_ry + _starty) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.1 * GUI_GRID_CENTER_W,
                    0.12 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _sc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
            };
            _display setVariable ["FST_WireIDs", _id];
        };
        case 135;
        case 315:
        {
            private _startx = _xa min _xb;
            private _endx = 0;
            private _starty = 0;
            private _endy = 0;
            if (_startx == _xa) then {_starty = _ya; _endx = _xb; _endy = _yb;} else {_starty = _yb; _endx = _xa; _endy = _ya;};
            private _dx = _endx - _startx;
            private _dy = _endy - _starty;
            private _angle = _dy atan2 _dx;
            private _length = sqrt (_dx ^ 2 + _dy ^ 2);
            private _tempx = -0.1 * cos _angle - 0 * sin _angle;
            private _tempy = -0.1 * sin _angle + 0 * cos _angle;
            private _id = _display getVariable "FST_WireIDs";
            private _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                (_tempy + _starty) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.25 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _pc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            _tempx = -0.2 * cos _angle - 0 * sin _angle;
            _tempy = -0.2 * sin _angle + 0 * cos _angle;
            _id = _id + 1;
            _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                (_tempy + _starty) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.125 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _pc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            _tempx = (_length + 0.1) * cos _angle - 0 * sin _angle;
            _tempy = (_length + 0.1) * sin _angle + 0 * cos _angle;
            _id = _id + 1;
            _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                (((_tempy + _starty) - 0.05) + 0.5) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.1 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _sc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            _tempx = (_length + 0.2) * cos _angle - 0 * sin _angle;
            _tempy = (_length + 0.2) * sin _angle + 0 * cos _angle;
            _id = _id + 1;
            _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                (((_tempy + _starty) - 0.05) + 0.5) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.1 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _sc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            _tempx = (_length + 0.3) * cos _angle - 0 * sin _angle;
            _tempy = (_length + 0.3) * sin _angle + 0 * cos _angle;
            _id = _id + 1;
            _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                (((_tempy + _starty) - 0.05) + 0.5) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.1 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _sc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            _tempx = (_length + 0.1) * cos _angle - 0 * sin _angle;
            _tempy = (_length + 0.1) * sin _angle + 0 * cos _angle;
            _id = _id + 1;
            _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                ((_tempy + _starty) + 0.125) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.25 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _pc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            _tempx = (_length + 0.2) * cos _angle - 0 * sin _angle;
            _tempy = (_length + 0.2) * sin _angle + 0 * cos _angle;
            _id = _id + 1;
            _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                ((_tempy + _starty) + 0.25) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.125 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _pc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            _tempx = -0.1 * cos _angle - 0 * sin _angle;
            _tempy = -0.1 * sin _angle + 0 * cos _angle;
            _id = _id + 1;
            _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                ((_tempy + _starty) - 0.05) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.1 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _sc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            _tempx = -0.2 * cos _angle - 0 * sin _angle;
            _tempy = -0.2 * sin _angle + 0 * cos _angle;
            _id = _id + 1;
            _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                ((_tempy + _starty) - 0.05) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.1 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _sc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            _tempx = -0.3 * cos _angle - 0 * sin _angle;
            _tempy = -0.3 * sin _angle + 0 * cos _angle;
            _id = _id + 1;
            _wire = _display ctrlCreate ["RscText", _id];
            _wire ctrlSetPosition
            [
                (_tempx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                ((_tempy + _starty) - 0.05) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                0.12 * GUI_GRID_CENTER_W,
                0.1 * GUI_GRID_CENTER_H
            ];
            _wire ctrlSetBackgroundColor _sc;
            _wire ctrlCommit 0;
            _wirectrls pushBack _wire;
            for "_x" from 0 to _length step 0.1 do
            {
                private _thisy = 0;
                private _rx = _x * cos _angle - _thisy * sin _angle;
                private _ry = _x * sin _angle + _thisy * cos _angle;
                _id = _id + 1;
                _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    (_rx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    (_ry + _starty) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.12 * GUI_GRID_CENTER_W,
                    0.5 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _pc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
            };
            for "_x" from 0 to _length step 0.1 do
            {
                private _thisy = 0;
                private _rx = _x * cos _angle - _thisy * sin _angle;
                private _ry = _x * sin _angle + _thisy * cos _angle;
                _id = _id + 1;
                _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    (_rx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    ((_ry + _starty) - 0.05) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.12 * GUI_GRID_CENTER_W,
                    0.1 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _sc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
            };
            for "_x" from 0 to _length step 0.1 do
            {
                private _thisy = 0;
                private _rx = _x * cos _angle - _thisy * sin _angle;
                private _ry = _x * sin _angle + _thisy * cos _angle;
                _id = _id + 1;
                _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    (_rx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    (((_ry + _starty) - 0.05) + 0.5) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.12 * GUI_GRID_CENTER_W,
                    0.1 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _sc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
            };
            _display setVariable ["FST_WireIDs", _id];
        };
        case 157;
        case 337:
        {
            
            private _startx = _xa min _xb;
            private _endx = 0;
            private _starty = 0;
            private _endy = 0;
            if (_startx == _xa) then {_starty = _ya; _endx = _xb; _endy = _yb;} else {_starty = _yb; _endx = _xa; _endy = _ya;};
            private _dx = _endx - _startx;
            private _dy = _endy - _starty;
            private _angle = _dy atan2 _dx;
            private _length = sqrt (_dx ^ 2 + _dy ^ 2);
            private _waves = 1;
            private _amp = 0;
            if (_dx == 3.5) then 
            {_amp = -0.1;};
            if (_dx in [6.5,9.5]) then 
            {_waves = 2; if ((_dy == -5) && (_dx == 6.5)) then {_amp = -0.1;} else {_amp = -0.2;};};
            if (_dx in [12.5,15.5]) then 
            {_waves = 3; if (((_dy == -8) && (_dx == 12.5)) or ((_dy == -11) && (_dx == 15.5))) then {_amp = -0.1;} else {_amp = -0.3;}};
            private _freq = (_waves * 360) / _length;
            private _id = _display getVariable "FST_WireIDs";
            for "_x" from 0 to _length step 0.1 do
            {
                private _thisy = _amp * sin (_x * _freq);
                private _rx = _x * cos _angle - _thisy * sin _angle;
                private _ry = _x * sin _angle + _thisy * cos _angle;
                _id = (_id + (_x * 10));
                private _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    (_rx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    (_ry + _starty) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.12 * GUI_GRID_CENTER_W,
                    0.5 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _pc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
            };
            for "_x" from 0 to _length step 0.1 do
            {
                private _thisy = _amp * sin (_x * _freq);
                private _rx = _x * cos _angle - _thisy * sin _angle;
                private _ry = _x * sin _angle + _thisy * cos _angle;
                _id = (_id + (_x * 10));
                private _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    (_rx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    ((_ry + _starty) - 0.05) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.12 * GUI_GRID_CENTER_W,
                    0.1 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _sc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
            };
            for "_x" from 0 to _length step 0.1 do
            {
                private _thisy = _amp * sin (_x * _freq);
                private _rx = _x * cos _angle - _thisy * sin _angle;
                private _ry = _x * sin _angle + _thisy * cos _angle;
                _id = (_id + (_x * 10));
                private _wire = _display ctrlCreate ["RscText", _id];
                _wire ctrlSetPosition
                [
                    (_rx + _startx) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                    (((_ry + _starty) - 0.05) + 0.5) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                    0.12 * GUI_GRID_CENTER_W,
                    0.1 * GUI_GRID_CENTER_H
                ];
                _wire ctrlSetBackgroundColor _sc;
                _wire ctrlCommit 0;
                _wirectrls pushBack _wire;
            };
            _display setVariable ["FST_WireIDs", _id];
        };
    };
    _ctrla setVariable ["FST_Wire",[_wirectrls]];
    _ctrlb setVariable ["FST_Wire",[_wirectrls]];
    _display setVariable ["FST_WireUnready",false];
}] call CBA_fnc_addEventHandler;
