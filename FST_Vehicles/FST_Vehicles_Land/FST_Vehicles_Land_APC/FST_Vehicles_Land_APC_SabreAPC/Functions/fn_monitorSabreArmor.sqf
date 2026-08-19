params ["_vehicle"];

if (isNull _vehicle || {!local _vehicle}) exitWith {};
if (_vehicle getVariable ["FST_sabreArmorMonitorRunning", false]) exitWith {};

_vehicle setVariable ["FST_sabreArmorMonitorRunning", true];

private _externalArmorHitpoints = ["HitLSideArmor", "HitRSideArmor", "HitRearArmor"];

while {alive _vehicle} do {
    if ({(_vehicle getHitPointDamage _x) >= 1} count _externalArmorHitpoints > 0) then {
        if ((_vehicle getHitPointDamage "HitHull") > 0.5) then {
            _vehicle setHitPointDamage ["HitHull", 0.5];
        };
    };

    uiSleep 0.1;
};

_vehicle setVariable ["FST_sabreArmorMonitorRunning", false];