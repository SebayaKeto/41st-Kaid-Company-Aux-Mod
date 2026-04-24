// FST_HCSpawn_fnc_setHCIndex
// HC-side. Called by server after registration.
// Starts the FPS monitor with the correct HC index label.
//
// Arguments:
//   0: NUMBER — HC index (0-based)

params ["_hcIndex"];

private _label = format ["HC%1", _hcIndex + 1];
private _posIndex = _hcIndex + 1;  // offset above server marker

[_label, 10, _posIndex] call FST_HCSpawn_fnc_fpsMonitor;

diag_log format ["[FST_HCSpawn] HC index set: %1 (%2)", _hcIndex, _label];
