/*
    FST_fnc_RRR_addAction
    Adds the service action to a unit if it is missing.
*/
params ["_unit"];

if (isNull _unit) exitWith {};

private _title = "<t color='#00ff00'>[Initiate Repairs]</t>";
private _id    = _unit getVariable ["VR_ActionID", -1];
if (_id in actionIDs _unit && {((_unit actionParams _id) select 0) isEqualTo _title}) exitWith {};

_unit setVariable ["VR_RepairActive", false];

private _newId = _unit addAction [
    _title,
    {
        params ["_target", "_caller", "_id"];

        if (_target getVariable ["VR_RepairActive", false]) exitWith {};

        private _vehicle = vehicle _caller;
        private _pilot   = _caller;

        if (_vehicle == _caller)         exitWith {};
        if !(driver _vehicle == _caller) exitWith {};

        _target setVariable ["VR_RepairActive", true];

        private _hitPoints = (getAllHitPointsDamage _vehicle) select 0;

        private _worstDamage = 0;
        {
            private _dmg = _vehicle getHitPointDamage _x;
            if (_dmg > _worstDamage) then { _worstDamage = _dmg; };
        } forEach _hitPoints;

        private _startingFuel = fuel _vehicle;
        private _fuelNeeded   = 1 - _startingFuel;
        private _repairTime   = 1 max (20 * _worstDamage);
        private _refuelTime   = 1 max (20 * _fuelNeeded);

        private _missingMags  = [_vehicle] call ace_rearm_fnc_getneedrearmmagazines;
        private _totalMissing = count _missingMags;
        private _rearmTime    = 1 max (20 * (_totalMissing / (1 max (_totalMissing + 1))));

        private _buildBar = {
            params ["_progress", "_length"];
            private _bar    = "";
            private _filled = round (_progress * _length);
            for "_i" from 1 to _length do {
                if (_i <= _filled) then { _bar = _bar + "|"; } else { _bar = _bar + "."; };
            };
            _bar
        };

        [_vehicle, _pilot, _repairTime, _refuelTime, _rearmTime, _buildBar, _startingFuel, _fuelNeeded, _missingMags, _target, _hitPoints] spawn {
            params ["_vehicle", "_pilot", "_repairTime", "_refuelTime", "_rearmTime", "_buildBar", "_startingFuel", "_fuelNeeded", "_missingMags", "_target", "_hitPoints"];

            private _elapsed   = 0;
            private _lastTick  = time;
            private _rearmDone = false;
            private _wasActive = false;
            private _running   = true;

            while {_running} do {
                private _inZone = [getPosATL _vehicle] call FST_fnc_RRR_isInZone;

                if (!_inZone || !((driver _vehicle) == _pilot)) then {
                    if (player == _pilot) then { hintSilent ""; };
                    _target setVariable ["VR_RepairActive", false];
                    _running = false;
                } else {
                    if (isEngineOn _vehicle) then {
                        _wasActive = false;
                        if (player == _pilot) then { hintSilent parseText "<t size='1.3' align='center' color='#ffffff'>- Republic ATC -</t><br/><br/><t align='center' color='#ffff00'>SERVICING PAUSED</t><br/><br/><t align='center' color='#aaaaaa'>Engine detected. Power down to resume servicing.</t>"; };
                        sleep 1;
                    } else {
                        if (!_wasActive) then { _lastTick = time; };
                        _wasActive = true;

                        _elapsed  = _elapsed + (time - _lastTick);
                        _lastTick = time;

                        private _repairProgress = 0 max (1 min (_elapsed / _repairTime));
                        private _refuelProgress = 0 max (1 min ((_elapsed - _repairTime) / _refuelTime));
                        private _rearmProgress  = 0 max (1 min ((_elapsed - _repairTime - _refuelTime) / _rearmTime));

                        private _repairPct = round (_repairProgress * 100);
                        private _refuelPct = round (_refuelProgress * 100);
                        private _rearmPct  = round (_rearmProgress  * 100);

                        private _repairBar = [_repairProgress, 15] call _buildBar;
                        private _refuelBar = [_refuelProgress, 15] call _buildBar;
                        private _rearmBar  = [_rearmProgress,  15] call _buildBar;

                        private _repairColor = if (_repairProgress >= 1) then {"#44ff44"} else {"#ffff00"};
                        private _refuelColor = if (_refuelProgress >= 1) then {"#44ff44"} else {"#4488ff"};
                        private _rearmColor  = if (_rearmProgress  >= 1) then {"#44ff44"} else {"#ff4444"};

                        private _allDone = (_repairProgress >= 1) && (_refuelProgress >= 1) && (_rearmProgress >= 1);

                        private _bottomText = if (_allDone) then {
                            "<t align='center' size='1.4' color='#44ff44'>- GO GO GO -</t>"
                        } else {
                            "<t align='center' color='#aaaaaa'>Stand by. Service in progress...</t>"
                        };

                        {
                            private _currentDmg = _vehicle getHitPointDamage _x;
                            if (_currentDmg > 0) then {
                                _vehicle setHitPointDamage [_x, _currentDmg * (1 - _repairProgress)];
                            };
                        } forEach _hitPoints;

                        _vehicle setFuel (_startingFuel + (_fuelNeeded * _refuelProgress));

                        if ((_rearmProgress >= 1) && !_rearmDone) then {
                            _rearmDone = true;
                            {
                                _x params ["_magazineClass", "_turretPath", "_isPylonMag", "_pylonIndex", "_maxMagazines", "_currentMagazines", "_maxRoundsPerMag", "_currentRounds"];
                                if (_isPylonMag) then {
                                    _vehicle setAmmoOnPylon [_pylonIndex, _maxRoundsPerMag];
                                } else {
                                    private _fullRounds = [];
                                    for "_i" from 1 to _maxMagazines do { _fullRounds pushBack _maxRoundsPerMag; };
                                    [_vehicle, _turretPath, _magazineClass, _fullRounds] call ace_rearm_fnc_setturretmagazineammo;
                                };
                            } forEach _missingMags;
                        };

                        if (player == _pilot) then {
                            hintSilent parseText format [
                                "<t size='1.3' align='center' color='#ffffff'>- Republic ATC -</t><br/><br/><t align='center' color='#aaaaaa'>Your vessel is currently being serviced.<br/>Do not power down systems.</t><br/><br/><t color='%1'>Repairs:  [%2] %3%%</t><br/><br/><t color='%4'>Refuel:   [%5] %6%%</t><br/><br/><t color='%7'>Rearm:    [%8] %9%%</t><br/><br/>%10",
                                _repairColor, _repairBar, _repairPct,
                                _refuelColor, _refuelBar, _refuelPct,
                                _rearmColor,  _rearmBar,  _rearmPct,
                                _bottomText
                            ];
                        };

                        if (_allDone) then {
                            _vehicle setDamage 0;
                            _vehicle setFuel 1;
                            _vehicle setVehicleAmmo 1;
                            _target setVariable ["VR_RepairActive", false];
                            _running = false;
                        } else {
                            sleep 0.1;
                        };
                    };
                };
            };
        };
    },
    [],
    1.5,
    true,
    false,
    "",
    "[_this] call FST_fnc_RRR_checkCondition"
];

_unit setVariable ["VR_ActionID", _newId];
