/*
    FST_fnc_setStatus
    params ["_statusLbl", "_text", "_color"]
*/
params ["_statusLbl", "_text", "_color"];
_statusLbl ctrlSetText _text;
_statusLbl ctrlSetTextColor _color;
_statusLbl ctrlCommit 0;
