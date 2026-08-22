params ["_vehicle"];

private _sabreProfile = [
    "FST_SabreArmorStatus",
    "FST_SabreArmorStatus",
    "FST_sabreArmorStatusRunning",
    [
    [7101, 7122, "HitFrontArmor"],
    [7103, 7123, "HitLSideArmor"],
    [7105, 7124, "HitRSideArmor"],
    [7107, 7125, "HitRearArmor"]
    ],
    "HitHull",
    [
        ["MOB", 7130, [["L", "HitLTrack"], ["R", "HitRTrack"]]],
        ["PWR", 7131, [["ENG", "HitEngine"], ["FUEL", "HitFuel"]]],
        ["WPN", 7132, [["TUR", "HitTurret"], ["GUN", "HitGun"]]]
    ]
];

[_vehicle, _sabreProfile] execVM "\FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Functions\fn_showVehicleArmorStatus.sqf";