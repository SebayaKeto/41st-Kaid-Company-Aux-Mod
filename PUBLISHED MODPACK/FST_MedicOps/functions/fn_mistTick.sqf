// FST_medOps_fnc_mistTick
// Every machine, every 2 s: units LOCAL to this machine standing in an active Bacta Mist cloud (6 m) get one ACE
// medication adjustment: pain suppression 0.4 and flow +40 (peripheral resistance 140 => blood loss x ~0.7) for 60 s.
// One dose per unit per 45 s, so a cloud cannot stack. FST_medOps_mists = [[posATL, untilTime], ...] (global event).

if (isNil "FST_medOps_mists" || {FST_medOps_mists isEqualTo []}) exitWith {};
FST_medOps_mists = FST_medOps_mists select { (_x select 1) > CBA_missionTime };
if !(missionNamespace getVariable ["FST_medOps_mist", true]) exitWith {};
{
    private _pos = _x select 0;
    {
        if (local _x && {alive _x} && {(_x getVariable ["FST_medOps_mistNext", -1]) < CBA_missionTime}) then {
            _x setVariable ["FST_medOps_mistNext", CBA_missionTime + 45];
            [_x, "FST_BactaMist", 5, 60, 0, 0.4, 40, 0] call ace_medical_status_fnc_addMedicationAdjustment;
            if (hasInterface && {_x == player}) then { titleText ["<t color='#7fe0e0'>Bacta mist: pain eases, bleeding slows</t>", "PLAIN DOWN", 0.4, true, true]; };
        };
    } forEach (_pos nearEntities ["CAManBase", 6]);
} forEach FST_medOps_mists;
