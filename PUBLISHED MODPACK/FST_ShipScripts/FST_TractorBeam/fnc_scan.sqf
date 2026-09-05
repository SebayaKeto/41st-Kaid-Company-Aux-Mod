/*
    FST_fnc_scan
    Scans vehicles inside a trigger and reports their damage/fuel status to the driver.
    Call from the trigger's "On Activation" field: [thisList] call FST_fnc_scan;
*/
params ["_list"];

private _getStatus = {
    params ["_damage"];
    private _health = 1 - _damage;
    if (_health >= 0.9) then {
        "<t color='#4488ff'>Perfect</t>"
    } else {
        if (_health >= 0.51) then {
            "<t color='#44ff44'>Good</t>"
        } else {
            if (_health >= 0.26) then {
                "<t color='#ffff00'>In Need of Repair</t>"
            } else {
                "<t color='#ff4444'>F#CKED</t>"
            };
        };
    };
};

{
    private _vehicle = _x;

    {
        if ((_vehicle getHitPointDamage _x) > 0.5) then {
            _vehicle setHitPointDamage [_x, 0.5];
        };
    } forEach [
        "hitvrotor",
        "hitavionics",
        "hitengine",
        "hitengine_1",
        "hitengine_2",
        "hithrotor"
    ];
    _vehicle setHitPointDamage ["hitfuel", 0];
    private _currentFuel = fuel _vehicle;
    if (_currentFuel < 0.1) then { _vehicle setFuel 0.1; };

    private _hullDmg      = _vehicle getHitPointDamage "hithull";
    private _mainRotorDmg = _vehicle getHitPointDamage "hithrotor";
    private _tailRotorDmg = _vehicle getHitPointDamage "hitvrotor";
    private _engineDmg    = (_vehicle getHitPointDamage "hitengine") max (_vehicle getHitPointDamage "hitengine_1") max (_vehicle getHitPointDamage "hitengine_2");
    private _avionicsDmg  = _vehicle getHitPointDamage "hitavionics";
    private _fuelTankDmg  = _vehicle getHitPointDamage "hitfuel";

    private _needsAttention = (_hullDmg > 0.1) || (_mainRotorDmg > 0.1) || (_tailRotorDmg > 0.1) || (_engineDmg > 0.1) || (_avionicsDmg > 0.1) || (_fuelTankDmg > 0.1);

    if (_needsAttention) then {
        private _hull      = [_hullDmg] call _getStatus;
        private _mainRotor = [_mainRotorDmg] call _getStatus;
        private _tailRotor = [_tailRotorDmg] call _getStatus;
        private _engine    = [_engineDmg] call _getStatus;
        private _avionics  = [_avionicsDmg] call _getStatus;
        private _fuelTank  = [_fuelTankDmg] call _getStatus;

        private _fuelPct = round ((fuel _vehicle) * 100);
        private _fuelColor = if (_fuelPct >= 90) then {"#4488ff"} else {if (_fuelPct >= 51) then {"#44ff44"} else {if (_fuelPct >= 26) then {"#ffff00"} else {"#ff4444"}}};

        private _report = format [
            "<t size='1.3' align='center' color='#ffffff'>— Republic ATC —</t><br/><br/><t align='center' color='#aaaaaa'>Incoming Vessel Detected, Emergency Tractor Beam ENGAGED<br/>Maintain Heading and Standby. We're conducting a Multi-spectrum Scan of your Space Craft.</t><br/><br/><t align='center' color='#ffffff'>[SCANS COMPLETE]</t><br/><br/><t align='center' color='#aaaaaa'>Reports Show</t><br/><br/><t align='left'>Hull:          %1<br/>Main Rotor:    %2<br/>Anti-Torque:   %3<br/>Engines:       %4<br/>Instruments:   %5<br/>Fuel Tank:     %6<br/><br/><t color='%7'>Fuel Level: %8%%</t></t><br/><br/><t align='center' color='#aaaaaa'>Make your way to a service pad for immediate repairs.</t>",
            _hull, _mainRotor, _tailRotor, _engine, _avionics, _fuelTank, _fuelColor, _fuelPct
        ];

        if (player == driver _vehicle) then { hintSilent parseText _report; };
    };

} forEach _list;
