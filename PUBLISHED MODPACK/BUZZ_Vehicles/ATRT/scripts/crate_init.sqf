// =============================================================================
//  BUZZ AT-RT — crate_init.sqf
//  Called via CfgVehicles EventHandlers { init } on every machine.
//  Registers the Unpack AT-RT scroll-wheel action.
// =============================================================================
private _crate = _this;

_crate addAction [
    "Unpack AT-RT",
    {
        params ["_crate", "_caller"];

        if (_crate getVariable ["BUZZ_packing", false]) exitWith {};

        _crate setVariable ["BUZZ_packing", true, true];

        [_crate, _caller, 10, "UNPACKING AT-RT"] execVM "\BUZZ_Vehicles\ATRT\scripts\pack_hud.sqf";
        [_caller, "AinvPercMstpSnonWrflDnon_medic_1"] remoteExec ["switchMove", 0];

        [_crate, _caller] spawn {
            params ["_crate", "_caller"];
            private _start = time;

            waitUntil {
                !alive _caller ||
                !(_crate getVariable ["BUZZ_packing", false]) ||
                time - _start >= 10
            };

            private _cancelled = !alive _caller || !(_crate getVariable ["BUZZ_packing", false]);
            _crate setVariable ["BUZZ_packing", false, true];
            if (_cancelled) exitWith { [_caller, ""] remoteExec ["switchMove", 0]; };

            private _hp       = _crate getVariable ["BUZZ_packed_hp",       1.0];
            private _cell     = _crate getVariable ["BUZZ_packed_cell",     300];
            private _reserves = _crate getVariable ["BUZZ_packed_reserves",   3];
            private _class    = _crate getVariable ["BUZZ_packed_class", "BUZZ_ATRT"];
            private _pos      = getPosASL _crate;
            private _dir      = getDir _crate;

            [_pos, _dir, _hp, _cell, _reserves, _crate, _class] remoteExecCall ["BUZZ_fnc_unpackServer", 2];
            [_caller, ""] remoteExec ["switchMove", 0];
        };
    },
    [],
    1.5,
    true,
    true,
    "",
    "vehicle _this isEqualTo _this && !(_this getVariable ['BUZZ_packing', false])",
    5,
    false,
    "",
    ""
];
