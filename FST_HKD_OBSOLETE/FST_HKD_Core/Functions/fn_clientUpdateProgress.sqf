params ["_spawned","_total","_pct","_text"];
private _disp = findDisplay 9876;
if (!isNull _disp) then {
    private _ctrlText = _disp displayCtrl 1520;
    private _ctrlBG = _disp displayCtrl 1521;
    private _ctrlFill = _disp displayCtrl 1522;
    if (!isNull _ctrlText) then { _ctrlText ctrlSetText _text; };
    if (!isNull _ctrlBG && !isNull _ctrlFill) then {
        private _bgPos = ctrlPosition _ctrlBG;
        private _bgW = _bgPos select 2;
        private _newW = _bgW * (_pct / 100);
        _ctrlFill ctrlSetPosition [(_bgPos select 0), (_bgPos select 1), _newW, (_bgPos select 3)];
    };
};