["FST_createXScreenLine", {
    params ["_display", "_ylayer", "_width", "_storage"];
    
    private _screen = _display getVariable ["FST_ScreenGrid", []];
    private _pixels = [];

    for "_pcount" from 0 to _width do
    {
        private _chosen = (_screen select _pcount) select _ylayer; 
        _pixels pushBack _chosen;
    };

    _display setVariable [_storage, _pixels];

}] call CBA_fnc_addEventHandler;

["FST_createGameGrid", {
    params ["_display", "_offset", "_mode", "_storage"];
    
    private _screen = _display getVariable ["FST_ScreenGrid", []];
    private _fullgrid = [];
    private _xcounter = _offset;
    private _alter = false;

    while {_xcounter <= 60} do
    {
        private _yarray = [];
        private _ycounter = 0;
        if (_mode) then { if !(_alter) then {_ycounter = 2;};} else {_ycounter = _offset;};
        while {_ycounter <= 48} do
        {
            private _pixel = ((_screen select _xcounter) select _ycounter);
            _yarray pushback _pixel;
            _ycounter = _ycounter + 4;
        };
        _fullgrid pushback _yarray;
        if (_mode) then 
        {
            _xcounter = _xcounter + 2;
            if (_alter) then {_alter = false} else {_alter = true;};
        } else {_xcounter = _xcounter + 4;};
    };

    _display setVariable [ _storage, _fullgrid];

}] call CBA_fnc_addEventHandler;

["FST_createWalls", {
    params ["_display"];
    
    private _screen = _display getVariable ["FST_ScreenGrid", []];
    private _rooms = _display getVariable ["FST_MovementGridCenters", []];
    private _walls = _display getVariable ["FST_WallCenters", []];

    private _gridx = 0;
    while {_gridx <= 60} do
    {
        {
            _x ctrlSetBackgroundColor [0.5,0.5,0.5,1];
        } forEach (_screen select _gridx);
        _gridx = _gridx + 4;
    };
    private _gridy = 0;
    while {_gridy <= 48} do
    {
        private _name = format ["FST_XLayer%1", _gridy];
        ["FST_createXScreenLine", [ _display, _gridy, 60, _name]] call CBA_fnc_localEvent;
        {
            _x ctrlSetBackgroundColor [0.5,0.5,0.5,1];
        } forEach (_display getVariable [_name, []]);
        _gridy = _gridy + 4;
    };

    private _xwallposition = 0;
    private _orientswitch = true;
    while {_xwallposition <= 30} do
    {
        private _ywallposition = 0;
        if (_orientswitch) then
        {
            while {_ywallposition <= 11} do
            {
                (_walls select (_xwallposition) select (_ywallposition)) setVariable ["FST_IsWall", true];
                if ((_ywallposition in [0,11]) or (_xwallposition in [0,30])) then {(_walls select (_xwallposition) select (_ywallposition)) setVariable ["FST_IsBorderWall", true];};
                _ywallposition = _ywallposition + 1;
            };
        }
        else
        {
            while {_ywallposition <= 12} do
            {
                (_walls select (_xwallposition) select (_ywallposition)) setVariable ["FST_IsWall", true];
                if ((_ywallposition in [0,12]) or (_xwallposition in [0,30])) then {(_walls select (_xwallposition) select (_ywallposition)) setVariable ["FST_IsBorderWall", true];};
                _ywallposition = _ywallposition + 1;
            };
        };
        _xwallposition = _xwallposition + 1;
        if (_orientswitch) then {_orientswitch = false} else {_orientswitch = true;};
    };

    private _xroomposition = 0;
    while {_xroomposition <= 14} do
    {
        private _yroomposition = 0;
        while {_yroomposition <= 11} do
        {
            private _north =  [(_xroomposition),(_yroomposition - 1)];
            private _east =  [(_xroomposition + 1),(_yroomposition)];
            private _south =  [(_xroomposition),(_yroomposition + 1)];
            private _west =  [(_xroomposition - 1),(_yroomposition)];
            (_rooms select (_xroomposition) select (_yroomposition)) setVariable ["FST_AttachedWalls", [[(_walls select (_xroomposition * 2 + 1) select (_yroomposition)), _north, 0],[(_walls select (_xroomposition * 2 + 2) select (_yroomposition)), _east, 1],[(_walls select (_xroomposition * 2 + 1) select (_yroomposition + 1)), _south, 2],[(_walls select (_xroomposition * 2) select (_yroomposition)), _west, 3]]];
            _yroomposition = _yroomposition + 1;
        };
        _xroomposition = _xroomposition + 1;
    };
    
    private _firstroom = (_rooms select (floor (random 15)) select (floor (random 12)));
    _firstroom setVariable ["FST_WasVisited", true];
    private _walllist = _firstroom getVariable ["FST_AttachedWalls", []];
    while {count _walllist > 0} do
    {
        private _wall = _walllist deleteAt (floor (random (count _walllist)));
        if !((_wall select 0) getVariable ["FST_IsBorderWall", false]) then
        {
            private _currentroom = (_rooms select ((_wall select 1) select 0)) select ((_wall select 1) select 1);
            if !(_currentroom getVariable ["FST_WasVisited", false]) then
            {
                _currentroom setVariable ["FST_WasVisited", true];
                {
                    _walllist pushBack _x;
                } forEach (_currentroom getVariable ["FST_AttachedWalls", []]);
                (_wall select 0) setVariable ["FST_IsWall", false];
                switch (_wall select 2) do
                {
                    case 0:
                    {
                        private _xposition = ((_wall select 1) select 0) * 4;
                        private _yposition = (((_wall select 1) select 1) + 1) * 4;
                        private _name = format ["FST_XLayer%1",(_yposition)];
                        private _xline = _display getVariable [_name, []];
                        for "_xpixel" from (_xposition + 1) to (_xposition + 3) do
                        {
                            (_xline select _xpixel) ctrlSetBackgroundColor [0,0,0,1];
                        };
                    };
                    case 1:
                    {
                        private _xposition = ((_wall select 1) select 0) * 4;
                        private _yposition = ((_wall select 1) select 1) * 4;
                        private _yline = _screen select (_xposition);
                        for "_ypixel" from (_yposition + 1) to (_yposition + 3) do
                        {
                            (_yline select _ypixel) ctrlSetBackgroundColor [0,0,0,1];
                        };
                    };
                    case 2:
                    {
                        private _xposition = ((_wall select 1) select 0) * 4;
                        private _yposition = ((_wall select 1) select 1) * 4;
                        private _name = format ["FST_XLayer%1",(_yposition)];
                        private _xline = _display getVariable [_name, []];
                        for "_xpixel" from (_xposition + 1) to (_xposition + 3) do
                        {
                            (_xline select _xpixel) ctrlSetBackgroundColor [0,0,0,1];
                        };
                    };
                    case 3:
                    {
                        private _xposition = (((_wall select 1) select 0) + 1) * 4;
                        private _yposition = ((_wall select 1) select 1) * 4;
                        private _yline = _screen select (_xposition);
                        for "_ypixel" from (_yposition + 1) to (_yposition + 3) do
                        {
                            (_yline select _ypixel) ctrlSetBackgroundColor [0,0,0,1];
                        };
                    };
                };
            };
        };
    };

    _xroomposition = 0;
    while {_xroomposition <= 14} do
    {
        private _yroomposition = 0;
        while {_yroomposition <= 11} do
        {
            if (((_rooms select (_xroomposition) select (_yroomposition)) getVariable ["FST_AttachedWalls", []]) isEqualTo []) then
            {
                private _north =  [(_xroomposition),(_yroomposition - 1)];
                private _east =  [(_xroomposition + 1),(_yroomposition)];
                private _south =  [(_xroomposition),(_yroomposition + 1)];
                private _west =  [(_xroomposition - 1),(_yroomposition)];
                (_rooms select (_xroomposition) select (_yroomposition)) setVariable ["FST_AttachedWalls", [[(_walls select (_xroomposition * 2 + 1) select (_yroomposition)), _north, 0],[(_walls select (_xroomposition * 2 + 2) select (_yroomposition)), _east, 1],[(_walls select (_xroomposition * 2 + 1) select (_yroomposition + 1)), _south, 2],[(_walls select (_xroomposition * 2) select (_yroomposition)), _west, 3]]];
            };
            _yroomposition = _yroomposition + 1;
        };
        _xroomposition = _xroomposition + 1;
    };

    for "_extra" from 0 to 50 do
    {
        private _extraroom = (_rooms select (floor (random 15)) select (floor (random 12)));
        private _direction = floor (random 4);
        private _wall = (_extraroom getVariable ["FST_AttachedWalls", []]) select _direction;
        if !((_wall select 0) getVariable ["FST_IsBorderWall", false]) then
        {
            if ((_wall select 0) getVariable ["FST_IsWall", false]) then
            {
                (_wall select 0) setVariable ["FST_IsWall", false];
                switch (_wall select 2) do
                {
                    case 0:
                    {
                        private _xposition = ((_wall select 1) select 0) * 4;
                        private _yposition = (((_wall select 1) select 1) + 1) * 4;
                        private _name = format ["FST_XLayer%1",(_yposition)];
                        private _xline = _display getVariable [_name, []];
                        for "_xpixel" from (_xposition + 1) to (_xposition + 3) do
                        {
                            (_xline select _xpixel) ctrlSetBackgroundColor [0,0,0,1];
                        };
                    };
                    case 1:
                    {
                        private _xposition = ((_wall select 1) select 0) * 4;
                        private _yposition = ((_wall select 1) select 1) * 4;
                        private _yline = _screen select (_xposition);
                        for "_ypixel" from (_yposition + 1) to (_yposition + 3) do
                        {
                            (_yline select _ypixel) ctrlSetBackgroundColor [0,0,0,1];
                        };
                    };
                    case 2:
                    {
                        private _xposition = ((_wall select 1) select 0) * 4;
                        private _yposition = ((_wall select 1) select 1) * 4;
                        private _name = format ["FST_XLayer%1",(_yposition)];
                        private _xline = _display getVariable [_name, []];
                        for "_xpixel" from (_xposition + 1) to (_xposition + 3) do
                        {
                            (_xline select _xpixel) ctrlSetBackgroundColor [0,0,0,1];
                        };
                    };
                    case 3:
                    {
                        private _xposition = (((_wall select 1) select 0) + 1) * 4;
                        private _yposition = ((_wall select 1) select 1) * 4;
                        private _yline = _screen select (_xposition);
                        for "_ypixel" from (_yposition + 1) to (_yposition + 3) do
                        {
                            (_yline select _ypixel) ctrlSetBackgroundColor [0,0,0,1];
                        };
                    };
                };
            };
        };
    };

}] call CBA_fnc_addEventHandler;

["FST_createPlayer", {
    params ["_display"];
    
    private _screen = _display getVariable ["FST_ScreenGrid", []];
    private _rooms = _display getVariable ["FST_MovementGridCenters", []];

    ((_rooms select 7) select 5) setVariable ["FST_PlayerIsHere", true];
    _display setVariable ["FST_PlayerGridLocation", [7,5]];
    ((_screen select 30) select 21) ctrlSetBackgroundColor [0,0.722,0.047,1];
    ((_screen select 29) select 22) ctrlSetBackgroundColor [0,0.722,0.047,1];
    ((_screen select 31) select 22) ctrlSetBackgroundColor [0,0.722,0.047,1];
    ((_screen select 30) select 23) ctrlSetBackgroundColor [0,0.722,0.047,1];

}] call CBA_fnc_addEventHandler;

["FST_MovePlayer", {
    params ["_display", "_direction"];
    
    private _screen = _display getVariable ["FST_ScreenGrid", []];
    private _rooms = _display getVariable ["FST_MovementGridCenters", []];
    private _player = _display getVariable ["FST_PlayerGridLocation", []];
    _player params ["_px", "_py"];

    if (_display getVariable ["FST_PlayerDead", false]) exitWith {};
    private _currentroom = ((_rooms select _px) select _py) getVariable ["FST_AttachedWalls", []];
    if (((_currentroom select _direction) select 0) getVariable ["FST_IsWall", false]) exitWith {};
    private _oldroom =  [_px, _py];
    switch (_direction) do
    {
        case 0:
        {
            ((_screen select (_px * 4 + 2)) select (_py * 4 + 1)) ctrlSetBackgroundColor [0,0,0,1];
            ((_screen select (_px * 4 + 1)) select (_py * 4 + 2)) ctrlSetBackgroundColor [0,0,0,1];
            ((_screen select (_px * 4 + 3)) select (_py * 4 + 2)) ctrlSetBackgroundColor [0,0,0,1];
            ((_screen select (_px * 4 + 2)) select (_py * 4 + 3)) ctrlSetBackgroundColor [0,0,0,1];
            ((_rooms select _px) select _py) setVariable ["FST_PlayerIsHere", false];
            _py = _py - 1;
            ((_screen select (_px * 4 + 2)) select (_py * 4 + 1)) ctrlSetBackgroundColor [0,0.722,0.047,1];
            ((_screen select (_px * 4 + 1)) select (_py * 4 + 2)) ctrlSetBackgroundColor [0,0.722,0.047,1];
            ((_screen select (_px * 4 + 3)) select (_py * 4 + 2)) ctrlSetBackgroundColor [0,0.722,0.047,1];
            ((_screen select (_px * 4 + 2)) select (_py * 4 + 3)) ctrlSetBackgroundColor [0,0.722,0.047,1];
            ((_rooms select _px) select _py) setVariable ["FST_PlayerIsHere", true];
            _display setVariable ["FST_PlayerGridLocation", [ _px, _py]];
        };
        case 1:
        {
            ((_screen select (_px * 4 + 2)) select (_py * 4 + 1)) ctrlSetBackgroundColor [0,0,0,1];
            ((_screen select (_px * 4 + 1)) select (_py * 4 + 2)) ctrlSetBackgroundColor [0,0,0,1];
            ((_screen select (_px * 4 + 3)) select (_py * 4 + 2)) ctrlSetBackgroundColor [0,0,0,1];
            ((_screen select (_px * 4 + 2)) select (_py * 4 + 3)) ctrlSetBackgroundColor [0,0,0,1];
            ((_rooms select _px) select _py) setVariable ["FST_PlayerIsHere", false];
            _px = _px + 1;
            ((_screen select (_px * 4 + 2)) select (_py * 4 + 1)) ctrlSetBackgroundColor [0,0.722,0.047,1];
            ((_screen select (_px * 4 + 1)) select (_py * 4 + 2)) ctrlSetBackgroundColor [0,0.722,0.047,1];
            ((_screen select (_px * 4 + 3)) select (_py * 4 + 2)) ctrlSetBackgroundColor [0,0.722,0.047,1];
            ((_screen select (_px * 4 + 2)) select (_py * 4 + 3)) ctrlSetBackgroundColor [0,0.722,0.047,1];
            ((_rooms select _px) select _py) setVariable ["FST_PlayerIsHere", true];
            _display setVariable ["FST_PlayerGridLocation", [ _px, _py]];
        };
        case 2:
        {
            ((_screen select (_px * 4 + 2)) select (_py * 4 + 1)) ctrlSetBackgroundColor [0,0,0,1];
            ((_screen select (_px * 4 + 1)) select (_py * 4 + 2)) ctrlSetBackgroundColor [0,0,0,1];
            ((_screen select (_px * 4 + 3)) select (_py * 4 + 2)) ctrlSetBackgroundColor [0,0,0,1];
            ((_screen select (_px * 4 + 2)) select (_py * 4 + 3)) ctrlSetBackgroundColor [0,0,0,1];
            ((_rooms select _px) select _py) setVariable ["FST_PlayerIsHere", false];
            _py = _py + 1;
            ((_screen select (_px * 4 + 2)) select (_py * 4 + 1)) ctrlSetBackgroundColor [0,0.722,0.047,1];
            ((_screen select (_px * 4 + 1)) select (_py * 4 + 2)) ctrlSetBackgroundColor [0,0.722,0.047,1];
            ((_screen select (_px * 4 + 3)) select (_py * 4 + 2)) ctrlSetBackgroundColor [0,0.722,0.047,1];
            ((_screen select (_px * 4 + 2)) select (_py * 4 + 3)) ctrlSetBackgroundColor [0,0.722,0.047,1];
            ((_rooms select _px) select _py) setVariable ["FST_PlayerIsHere", true];
            _display setVariable ["FST_PlayerGridLocation", [ _px, _py]];
        };
        case 3:
        {
            ((_screen select (_px * 4 + 2)) select (_py * 4 + 1)) ctrlSetBackgroundColor [0,0,0,1];
            ((_screen select (_px * 4 + 1)) select (_py * 4 + 2)) ctrlSetBackgroundColor [0,0,0,1];
            ((_screen select (_px * 4 + 3)) select (_py * 4 + 2)) ctrlSetBackgroundColor [0,0,0,1];
            ((_screen select (_px * 4 + 2)) select (_py * 4 + 3)) ctrlSetBackgroundColor [0,0,0,1];
            ((_rooms select _px) select _py) setVariable ["FST_PlayerIsHere", false];
            _px = _px - 1;
            ((_screen select (_px * 4 + 2)) select (_py * 4 + 1)) ctrlSetBackgroundColor [0,0.722,0.047,1];
            ((_screen select (_px * 4 + 1)) select (_py * 4 + 2)) ctrlSetBackgroundColor [0,0.722,0.047,1];
            ((_screen select (_px * 4 + 3)) select (_py * 4 + 2)) ctrlSetBackgroundColor [0,0.722,0.047,1];
            ((_screen select (_px * 4 + 2)) select (_py * 4 + 3)) ctrlSetBackgroundColor [0,0.722,0.047,1];
            ((_rooms select _px) select _py) setVariable ["FST_PlayerIsHere", true];
            _display setVariable ["FST_PlayerGridLocation", [ _px, _py]];
        };
    };
    private _newroom = ((_rooms select _px) select _py);
    private _colors = [[0.239,0.914,0.922,1],[1,0.973,0.22,1],[0.875,0.149,0.847,1]];
    if !(_newroom getVariable ["FST_OccupiedBySomething", false]) then 
    {
        private _playerkey = _display getVariable ["FST_PlayerHasKey", [false,3]];
        if !(_playerkey select 0) exitwith {};
        ((_screen select (_px * 4 + 2)) select (_py * 4 + 2)) ctrlSetBackgroundColor (_colors select (_playerkey select 1));
        if !(((((_rooms select (_oldroom select 0)) select (_oldroom select 1)) getVariable ["FST_Key0", [false,false]]) select 0) or ((((_rooms select (_oldroom select 0)) select (_oldroom select 1)) getVariable ["FST_Key1", [false,false]]) select 0) or ((((_rooms select (_oldroom select 0)) select (_oldroom select 1)) getVariable ["FST_Key2", [false,false]]) select 0)) then 
        {
            ((_screen select ((_oldroom select 0) * 4 + 2)) select ((_oldroom select 1) * 4 + 2)) ctrlSetBackgroundColor [0,0,0,1];
        }
        else
        {
            if ((((_rooms select (_oldroom select 0)) select (_oldroom select 1)) getVariable ["FST_Key0", [false,false]]) select 0) then
            {
                ((_screen select ((_oldroom select 0) * 4 + 2)) select ((_oldroom select 1) * 4 + 2)) ctrlSetBackgroundColor (_colors select 0);
            };
            if ((((_rooms select (_oldroom select 0)) select (_oldroom select 1)) getVariable ["FST_Key1", [false,false]]) select 0) then
            {
                ((_screen select ((_oldroom select 0) * 4 + 2)) select ((_oldroom select 1) * 4 + 2)) ctrlSetBackgroundColor (_colors select 1);
            };
            if ((((_rooms select (_oldroom select 0)) select (_oldroom select 1)) getVariable ["FST_Key2", [false,false]]) select 0) then
            {
                ((_screen select ((_oldroom select 0) * 4 + 2)) select ((_oldroom select 1) * 4 + 2)) ctrlSetBackgroundColor (_colors select 2);
            };
        };
    }
    else
    {
        if (_newroom getVariable ["FST_EnemyLocation", false]) then 
        {
            _display setVariable ["FST_PlayerDead", true];
        };
        private _playerkey = _display getVariable ["FST_PlayerHasKey", [false,3]];
        if ((_playerkey select 0) && ((_newroom getVariable ["FST_Goal0", false]) or (_newroom getVariable ["FST_Goal1", false]) or (_newroom getVariable ["FST_Goal2", false]))) then 
        {
            switch (_playerkey select 1) do
            {
                case 0:
                {
                    if (_newroom getVariable ["FST_Goal0", false]) then
                    {
                        playSoundUI [(selectRandom ["3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick1.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick2.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick3.ogg"]),4,1,true];
                        ((_screen select (_px * 4 + 2)) select (_py * 4 + 2)) ctrlSetBackgroundColor (_colors select 0);
                        ((_screen select ((_oldroom select 0) * 4 + 2)) select ((_oldroom select 1) * 4 + 2)) ctrlSetBackgroundColor [0,0,0,1];
                        _display setVariable ["FST_PlayerHasKey", [false,3]];
                        _newroom setVariable ["FST_Key0", [true,false]]; 
                        private _inc = _display getVariable ["FST_KeysDeposited", 0];
                        _display setVariable ["FST_KeysDeposited", (_inc + 1)];
                    };
                };
                case 1:
                {
                    if (_newroom getVariable ["FST_Goal1", false]) then
                    {
                        playSoundUI [(selectRandom ["3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick1.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick2.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick3.ogg"]),4,1,true];
                        ((_screen select (_px * 4 + 2)) select (_py * 4 + 2)) ctrlSetBackgroundColor (_colors select 1);
                        ((_screen select ((_oldroom select 0) * 4 + 2)) select ((_oldroom select 1) * 4 + 2)) ctrlSetBackgroundColor [0,0,0,1];
                        _display setVariable ["FST_PlayerHasKey", [false,3]];
                        _newroom setVariable ["FST_Key1", [true,false]]; 
                        private _inc = _display getVariable ["FST_KeysDeposited", 0];
                        _display setVariable ["FST_KeysDeposited", (_inc + 1)];
                    };
                };
                case 2:
                {
                    if (_newroom getVariable ["FST_Goal2", false]) then
                    {
                        playSoundUI [(selectRandom ["3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick1.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick2.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick3.ogg"]),4,1,true];
                        ((_screen select (_px * 4 + 2)) select (_py * 4 + 2)) ctrlSetBackgroundColor (_colors select 2);
                        ((_screen select ((_oldroom select 0) * 4 + 2)) select ((_oldroom select 1) * 4 + 2)) ctrlSetBackgroundColor [0,0,0,1];
                        _display setVariable ["FST_PlayerHasKey", [false,3]];
                        _newroom setVariable ["FST_Key2", [true,false]]; 
                        private _inc = _display getVariable ["FST_KeysDeposited", 0];
                        _display setVariable ["FST_KeysDeposited", (_inc + 1)];
                    };
                };
            };
        };
        if !(_playerkey select 0) then
        {
            if ((_newroom getVariable ["FST_Key0", [false,false]]) select 1) then
            {   
                playSoundUI [(selectRandom ["3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick1.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick2.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick3.ogg"]),4,1,true];
                _display setVariable ["FST_PlayerHasKey", [true,0]];
                _newroom setVariable ["FST_Key0", nil];
                _newroom setVariable ["FST_OccupiedBySomething", nil];
            };
            if ((_newroom getVariable ["FST_Key1", [false,false]]) select 1) then
            {   
                playSoundUI [(selectRandom ["3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick1.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick2.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick3.ogg"]),4,1,true];
                _display setVariable ["FST_PlayerHasKey", [true,1]];
                _newroom setVariable ["FST_Key1", nil];
                _newroom setVariable ["FST_OccupiedBySomething", nil];
            };
            if ((_newroom getVariable ["FST_Key2", [false,false]]) select 1) then
            {   
                playSoundUI [(selectRandom ["3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick1.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick2.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick3.ogg"]),4,1,true];
                _display setVariable ["FST_PlayerHasKey", [true,2]];
                _newroom setVariable ["FST_Key2", nil];
                _newroom setVariable ["FST_OccupiedBySomething", nil];
            };
        }
        else
        {
            ((_screen select (_px * 4 + 2)) select (_py * 4 + 2)) ctrlSetBackgroundColor (_colors select (_playerkey select 1));
            ((_screen select ((_oldroom select 0) * 4 + 2)) select ((_oldroom select 1) * 4 + 2)) ctrlSetBackgroundColor [0,0,0,1];
        };
    };
}] call CBA_fnc_addEventHandler;

["FST_createGoals", {
    params ["_display", "_color", "_count"];
    
    private _screen = _display getVariable ["FST_ScreenGrid", []];
    private _rooms = _display getVariable ["FST_MovementGridCenters", []];
    private _placed = false;

    while {_placed != true} do
    {
        private _randomx = floor (random 15);
        private _randomy = floor (random 12);
        if !([_randomx,_randomy] isEqualTo [7,5] or [_randomx,_randomy] isEqualTo [2,2] or [_randomx,_randomy] isEqualTo [2,8] or [_randomx,_randomy] isEqualTo [11,2] or [_randomx,_randomy] isEqualTo [11,8]) then 
        {
            private _roomtargeted = ((_rooms select _randomx) select _randomy);
            if !(_roomtargeted getVariable ["FST_OccupiedBySomething", false]) then 
            {
                private _found = false;
                for "_checkx" from (_randomx - 2) to (_randomx + 2) do
                {
                    for "_checky" from (_randomy - 2) to (_randomy + 2) do
                    {
                        if !((_checkx in [-2,-1,15,16]) or (_checky in [-2,-1,12,13])) then 
                        {
                            if (((_rooms select _checkx) select _checky) getVariable ["FST_OccupiedBySomething", false]) then {_found = true;};
                        };
                    };
                };
                if !(_found) then 
                {
                    _roomtargeted setVariable ["FST_OccupiedBySomething", true];
                    private _name = format ["FST_Goal%1", _count];
                    _roomtargeted setVariable [ _name ,true];
                    ((_screen select (_randomx * 4 + 1)) select (_randomy * 4 + 1)) ctrlSetBackgroundColor _color;
                    ((_screen select (_randomx * 4 + 3)) select (_randomy * 4 + 1)) ctrlSetBackgroundColor _color;
                    ((_screen select (_randomx * 4 + 1)) select (_randomy * 4 + 3)) ctrlSetBackgroundColor _color;
                    ((_screen select (_randomx * 4 + 3)) select (_randomy * 4 + 3)) ctrlSetBackgroundColor _color;
                    _placed = true;
                };
            };
        };
    };
}] call CBA_fnc_addEventHandler;

["FST_createKeys", {
    params ["_display", "_color", "_count"];
    
    private _screen = _display getVariable ["FST_ScreenGrid", []];
    private _rooms = _display getVariable ["FST_MovementGridCenters", []];
    private _placed = false;

    while {_placed != true} do
    {
        private _randomx = floor (random 15);
        private _randomy = floor (random 12);
        if !([_randomx,_randomy] isEqualTo [7,5] or [_randomx,_randomy] isEqualTo [2,2] or [_randomx,_randomy] isEqualTo [2,8] or [_randomx,_randomy] isEqualTo [11,2] or [_randomx,_randomy] isEqualTo [11,8]) then 
        {
            private _roomtargeted = ((_rooms select _randomx) select _randomy);
            if !(_roomtargeted getVariable ["FST_OccupiedBySomething", false]) then 
            {
                private _found = false;
                for "_checkx" from (_randomx - 2) to (_randomx + 2) do
                {
                    for "_checky" from (_randomy - 2) to (_randomy + 2) do
                    {
                        if !((_checkx in [-2,-1,15,16]) or (_checky in [-2,-1,12,13])) then 
                        {
                            if (((_rooms select _checkx) select _checky) getVariable ["FST_OccupiedBySomething", false]) then {_found = true;};
                        };
                    };
                };
                if !(_found) then 
                {
                    _roomtargeted setVariable ["FST_OccupiedBySomething", true];
                    private _name = format ["FST_Key%1", _count];
                    _roomtargeted setVariable [ _name ,[true,true]];
                    ((_screen select (_randomx * 4 + 2)) select (_randomy * 4 + 2)) ctrlSetBackgroundColor _color;
                    _placed = true;
                };
            };
        };
    };
}] call CBA_fnc_addEventHandler;

["FST_runEnemy", {
    params ["_display", "_xloc", "_yloc"];
    
    private _screen = _display getVariable ["FST_ScreenGrid", []];
    private _rooms = _display getVariable ["FST_MovementGridCenters", []];
    private _hackingdata = _display getVariable "FST_HackingData";
    _hackingdata params ["_term"];

    ((_rooms select _xloc) select _yloc) setVariable ["FST_OccupiedBySomething", true];
    ((_rooms select _xloc) select _yloc) setVariable ["FST_EnemyLocation", true];
    ((_screen select (_xloc * 4 + 2)) select (_yloc * 4 + 1)) ctrlSetBackgroundColor [0.851,0.071,0.071,1];
    ((_screen select (_xloc * 4 + 1)) select (_yloc * 4 + 3)) ctrlSetBackgroundColor [0.851,0.071,0.071,1];
    ((_screen select (_xloc * 4 + 3)) select (_yloc * 4 + 3)) ctrlSetBackgroundColor [0.851,0.071,0.071,1];

    while {!(_display getVariable ["FST_GameStart",false])} do {sleep 5};
    while {(!((_display getVariable ["FST_PlayerDead", false]) or ((_display getVariable ["FST_KeysDeposited", 0]) == 3)) && (_term getVariable ["FST_DeviceInUse",false]))} do
    {
        playSoundUI ["a3\missions_f_oldman\data\sound\beep.ogg",0.05,0.5,true];
        private _notplaced = true;
        private _movepotentials = [];
        while {_notplaced} do
        {
            if (_movepotentials isEqualTo []) then {_movepotentials = [[-1,-1],[0,-1],[1,-1],[-1,0],[1,0],[-1,1],[0,1],[1,1]]};
            private _move = _movepotentials deleteAt (floor (random (count _movepotentials)));
            _move params ["_xvar","_yvar"];
            if (((_xloc + _xvar) in [-1,15]) or ((_yloc + _yvar) in [-1,12])) exitWith {};
            if ((((_rooms select (_xloc + _xvar)) select (_yloc + _yvar)) getVariable ["FST_OccupiedBySomething", false]) or (((_rooms select (_xloc + _xvar)) select (_yloc + _yvar)) getVariable ["FST_PlayerIsHere", false])) exitWith {};
            ((_rooms select _xloc) select _yloc) setVariable ["FST_OccupiedBySomething", false];
            ((_rooms select _xloc) select _yloc) setVariable ["FST_EnemyLocation", false];
            ((_screen select (_xloc * 4 + 2)) select (_yloc * 4 + 1)) ctrlSetBackgroundColor [0,0,0,1];
            ((_screen select (_xloc * 4 + 1)) select (_yloc * 4 + 3)) ctrlSetBackgroundColor [0,0,0,1];
            ((_screen select (_xloc * 4 + 3)) select (_yloc * 4 + 3)) ctrlSetBackgroundColor [0,0,0,1];
            _xloc = _xloc + _xvar;
            _yloc = _yloc + _yvar;
            ((_rooms select _xloc) select _yloc) setVariable ["FST_OccupiedBySomething", true];
            ((_rooms select _xloc) select _yloc) setVariable ["FST_EnemyLocation", true];
            ((_screen select (_xloc * 4 + 2)) select (_yloc * 4 + 1)) ctrlSetBackgroundColor [0.851,0.071,0.071,1];
            ((_screen select (_xloc * 4 + 1)) select (_yloc * 4 + 3)) ctrlSetBackgroundColor [0.851,0.071,0.071,1];
            ((_screen select (_xloc * 4 + 3)) select (_yloc * 4 + 3)) ctrlSetBackgroundColor [0.851,0.071,0.071,1];
            sleep 2;
            _notplaced = false;
        };
    };

}] call CBA_fnc_addEventHandler;