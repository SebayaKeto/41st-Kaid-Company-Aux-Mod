// Zeus module
params ["_posASL", "_attached"];
[
    "Radiation Zone",
    [
        ["COMBO", "Zone type", [[0, 1, 2, -1], ["Background (30 min to death)", "Dangerous (15 min to death)", "Lethal (3 min to death)", "Decontamination (clears dose)"], 1]],
        ["SLIDER", "Radius (m)", [5, 2000, 50, 0]]
    ],
    {
        params ["_values", "_posASL"];
        _values params ["_tier", "_radius"];
        private _obj = createVehicle ["Land_HelipadEmpty_F", ASLToAGL _posASL, [], 0, "CAN_COLLIDE"];
        ["BUZZ_Radiation_zeusZoneCreated", [_obj, _tier, round _radius]] call CBA_fnc_serverEvent;
    },
    {},
    _posASL
] call zen_dialog_fnc_create;
