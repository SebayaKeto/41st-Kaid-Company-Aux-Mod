
    #include "\a3\ui_f\hpp\defineCommonGrids.inc"

    params ["_display", "_width", "_height", "_res", "_idstart", "_background", "_type", "_storage"];

    disableSerialization;

    _screen = [];
    _xnumber = 7.5;
    _idnum = _idstart;

    for "_xcoord" from 0 to _width do
    {
        _ystring = [];
        _ynumber = 3.5;
        for "_ycoord" from 0 to _height do
        {
            _idnum = _idnum + 1;
            private _pixel = _display ctrlCreate [_type, _idnum];
            _pixel ctrlSetPosition
            [
                _xnumber * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                _ynumber * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                _res * GUI_GRID_CENTER_W,
                _res * GUI_GRID_CENTER_H
            ];
            if !(isNil {_background}) then 
            {
                _pixel ctrlSetBackgroundColor _background;
            };
            _pixel ctrlCommit 0;
            _ystring pushBack _pixel;
            _ynumber = _ynumber + _res;
        };
        _screen pushback _ystring;
        _xnumber = _xnumber + _res;
    };

    _display setVariable [ _storage, _screen];
    _display setVariable ["FST_ScreenUnready", false];