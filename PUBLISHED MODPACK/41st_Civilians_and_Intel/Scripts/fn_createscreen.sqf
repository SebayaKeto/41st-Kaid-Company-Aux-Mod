
    #include "\a3\ui_f\hpp\defineCommonGrids.inc"

    params ["_display", "_width", "_height", "_res"];

    disableSerialization;

    _screen = [];
    _xnumber = 7.5;
    _idnum = 4999;

    for "_xcoord" from 0 to _width do
    {
        _ystring = [];
        _ynumber = 3.5;
        for "_ycoord" from 0 to _height do
        {
            _idnum = _idnum + 1;
            private _pixel = _display ctrlCreate ["RscText", _idnum];
            _pixel ctrlSetPosition
            [
                _xnumber * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X,
                _ynumber * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y,
                _res * GUI_GRID_CENTER_W,
                _res * GUI_GRID_CENTER_H
            ];
            _pixel ctrlSetBackgroundColor [0,0,0,1];
            _pixel ctrlCommit 0;
            _ystring pushBack _pixel;
            _ynumber = _ynumber + _res;
        };
        _screen pushback _ystring;
        _xnumber = _xnumber + _res;
    };

    _display setVariable ["FST_ScreenGrid", _screen];
    _display setVariable ["FST_ScreenUnready", false];