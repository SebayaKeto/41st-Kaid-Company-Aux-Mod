// FST_medOps_fnc_bactaCharge
// Consumable bacta (setting FST_medOps_bactaCharges; 0 = unlimited, today's behaviour, the default).
// Charges live on the medic (public unit variable FST_medOps_bactaLeft), starting full the first time it is read.
//   [medic, "has"]    -> BOOL   can apply bacta now
//   [medic, "use"]    -> spend one charge (medic's machine, from the action callback)
//   [medic, "left"]   -> NUMBER charges left (-1 = unlimited)
//   [medic, "reload"] -> spend one FST_BactaCartridge, add FST_medOps_bactaPerCartridge (capped at max)

params ["_medic", "_op"];
private _max = missionNamespace getVariable ["FST_medOps_bactaCharges", 0];
if (_max <= 0) exitWith { switch (_op) do { case "has": { true }; case "left": { -1 }; default { nil }; } };
private _left = _medic getVariable ["FST_medOps_bactaLeft", _max];
switch (_op) do {
    case "has": { _left > 0 };
    case "left": { _left };
    case "use": {
        _left = (_left - 1) max 0;
        _medic setVariable ["FST_medOps_bactaLeft", _left, true];
        if (hasInterface && {_medic == player}) then {
            hint format ["Bacta tank: %1 of %2 charges left%3", _left, _max, ["", ". Reload with a Bacta Cartridge."] select (_left == 0)];
        };
    };
    case "reload": {
        if !("FST_BactaCartridge" in items _medic) exitWith {};
        _medic removeItem "FST_BactaCartridge";
        _left = (_left + (missionNamespace getVariable ["FST_medOps_bactaPerCartridge", 4])) min _max;
        _medic setVariable ["FST_medOps_bactaLeft", _left, true];
        if (hasInterface && {_medic == player}) then { hint format ["Bacta tank reloaded: %1 of %2 charges", _left, _max]; };
    };
}
