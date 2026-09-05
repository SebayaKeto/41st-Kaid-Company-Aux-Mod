/*
    FST_fnc_initVehicleData
    Builds the vehicle/category/pad lists and resolves pad objects.
    Call once from your mission's init.sqf: call FST_fnc_initVehicleData;
*/
private _rotaryList = [
    ["LAAT/i Mk1",                      "FST_laati_Turret"],
    ["LAAT/i Mk2",                      "FST_laati_mk2"],
    ["LAAT/i Mk2 (Lamps)",              "FST_laati_mk2Lights"],
    ["LAAT/c",                          "FST_LAATC"],
    ["LAAT/c Pole",                     "FST_LAATC_Pole"],
    ["LAAT/le",                         "FST_LAAT_LE"],
    ["LAAT/i Mk1 'Q-Ball'",             "FST_laati_Turret_Qball"],
    ["LAAT/i Mk2 'Q-Ball'",             "FST_laati_mk2_Qball"],
    ["LAAT/i Mk2 'Q-Ball' (Lamps)",     "FST_laati_mk2Lights_Qball"],
    ["LAAT/i Mk1 'Grim'",               "FST_laati_Turret_Grim"],
    ["LAAT/i Mk2 'Grim'",               "FST_laati_mk2_Grim"],
    ["LAAT/i Mk2 'Grim' (Lamps)",       "FST_laati_mk2Lights_Grim"],
    ["LAAT/i Mk1 'Sierra'",             "FST_laati_Turret_Sierra"],
    ["LAAT/i Mk2 'Sierra'",             "FST_laati_mk2_Sierra"],
    ["LAAT/i Mk2 'Sierra' (Lamp)",      "FST_laati_mk2Lights_Sierra"],
    ["LAAT/i Mk1 'Aether'",            "FST_laati_Turret_Ouranos"],
    ["LAAT/i Mk2 'Aether'",            "FST_laati_mk2_Ouranos"],
    ["LAAT/i Mk2 'Aether' (Lamps)",    "FST_laati_mk2Lights_Ouranos"],
    ["LAAT/i Mk1 'Cait'",               "FST_laati_Turret_Cait"],
    ["LAAT/i Mk2 'Cait'",               "FST_laati_mk2_Cait"],
    ["LAAT/i Mk2 'Cait' (Lamps)",       "FST_laati_mk2Lights_Cait"],
    ["LAAT/i Mk1 'Fire'",               "FST_laati_Turret_Fire"],
    ["LAAT/i Mk2 'Fire'",               "FST_laati_mk2_Fire"],
    ["LAAT/i Mk2 'Fire' (Lamps)",       "FST_laati_mk2Lights_Fire"],
    ["LAAT/i Mk1 'Talisman'",           "FST_laati_Turret_Talisman"],
    ["LAAT/i Mk2 'Talisman'",            "FST_laati_mk2_Talisman"],
    ["LAAT/i Mk2 'Talisman' (Lamps)",   "FST_laati_mk2Lights_Talisman"],
    ["LAAT/i Mk1 'Pole'",               "FST_laati_Turret_Pole"],
    ["LAAT/i Mk2 'Pole'",               "FST_laati_mk2_Pole"],
    ["LAAT/i Mk2 'Pole' (Lamps)",       "FST_laati_mk2Lights_Pole"],
    ["LAAT/i Mk1 'Red'",                "FST_laati_Turret_Red"],
    ["LAAT/i Mk2 'Red'",                "FST_laati_mk2_Red"],
    ["LAAT/i Mk2 'Red' (Lamps)",        "FST_laati_mk2Lights_Red"]
];

private _fixedList = [
    ["ARC-170 Heavy Fighter",       "FST_Arc_170"],
    ["ARC_170 Pole",                "FST_ARC_170_Pole"],
    ["ARC_170 Rear",                "FST_Arc_170_Rear"],
    ["ARC_170 Pole Rear",           "FST_Arc_170_Pole_Rear"],
    ["Y-Wing Strategic Bomber",     "FST_Ywing_Bomber_Green"],
    ["Z-95 Headhunter",             "FST_Z95_Republic"],
    ["Z-95 Headhunter Q-Ball",      "FST_Z95_Qball"],
    ["Nu-Class Shuttle",            "FST_Nu_Shuttle"],
    ["Rho-Class Shuttle",           "FST_Rho_Shuttle"]
];

private _battalionList = [
    ["ITT",                             "FST_ITT"],
    ["ITT (Logistics)",                 "FST_ITT_Logistic"],
    ["Resupply Pod",                    "FST_Supplies_Pod"],
    ["Logistics Pod",                   "FST_Logistics_Pod"],
    ["AV-7 Field Cannon Artillery",     "FST_AV7"],
    ["HAVw A6 Juggernaut",              "FST_Jug"],
    ["PR-10 'Puma' (Desert)",           "FST_PR10_APC_Desert"],
    ["PR-10 'Puma' (Desert) Turreted",  "FST_Technical_Twin_Laser_Desert"],
    ["PR-10 'Puma' (Midnight)",         "FST_PR10_APC_Midnight"],
    ["PR-10 'Puma' (Midnight) Turreted","FST_Technical_Twin_Laser_Midnight"],
    ["PR-10 'Puma' (Urban)",            "FST_PR10_APC_Urban"],
    ["PR-10 'Puma' (Urban) Turreted",   "FST_Technical_Twin_Laser_Urban"],
    ["PR-10 'Puma' (Woodland)",         "FST_PR10_APC_Woodland"],
    ["PR-10 'Puma' (Woodland) Turreted","FST_Technical_Twin_Laser_Woodland"]
];

private _co1List = [
    ["Republic Mortar",         "FST_Republic_Mortar"],
    ["E-Web Blaster Turret",    "FST_EWEB"]
];

private _co2List = [
    ["AT-TE",                           "FST_ATTE_Base"],
    ["AT-TE (Rancor)",                  "FST_ATTE_Rancor"],
    ["AT-TE (Klanka Killa)",            "FST_ATTE_Klanka"],
    ["AT-TE (Grenner)",                 "FST_ATTE_gwenn"],
    ["AT-AP",                           "FST_ATAP_Base"],
    ["TX-130 Recon Saber",              "FST_Recon_Saber"],
    ["TX-130 Saber",                    "FST_Saber"],
    ["TX-130 Saber (Rancor)",           "FST_Saber_Rancor"],
    ["TX-130 Super Saber",              "FST_SuperSaber"],
    ["TX-130 Super Saber (Rancor)",     "FST_SuperSaber_Rancor"],
    ["TX-130 Recon Saber (TheClawMachine)", "FST_Recon_Saber_TheClawMachine"],
    ["TX-130 Saber (TheClawMachine)",       "FST_Saber_TheClawMachine"],
    ["TX-130 Super Saber (TheClawMachine)", "FST_SuperSaber_TheClawMachine"],
    ["ISP Swamp Speeder",               "FST_ISP"],
    ["ISP Swamp Speeder (Transport)",   "FST_ISP_Transport"],
    ["PK-V5 'Dewback' IFV",             "FST_PKV5_UP_Sickle"],
    ["PK-V5 'Dianoga' MLRS",            "FST_PKV5_MLRS_Carrier"],
    ["PK-V5 'Gundark' Light Tank",      "FST_PKV5_UP_Stormer"],
    ["PK-V5 'Massif' SPG",              "FST_PKV5_UP_Sceptre"],
    ["PK-V5 'Veractyl' SPAA",           "FST_PKV5_UP_Shredder"]
];

private _padList = [
    ["Pad 1", "Pad1_Spawn_Location"],
    ["Pad 2", "Pad2_Spawn_Location"],
    ["Pad 3", "Pad3_Spawn_Location"],
    ["Pad 4", "Pad4_Spawn_Location"],
    ["Pad 5", "Pad5_Spawn_Location"],
    ["Pad 6", "Pad6_Spawn_Location"],
    ["Pad 7", "Pad7_Spawn_Location"],
    ["Pad 8", "Pad8_Spawn_Location"],
    ["Pad 9", "Pad9_Spawn_Location"],
    ["Pad 10", "Pad10_Spawn_Location"]
];

private _categoryList = [
    ["Rotary Wing",      "GUI_RotaryList"],
    ["Fixed Wing",       "GUI_FixedList"],
    ["Battalion Assets", "GUI_BattalionList"],
    ["1st Company",      "GUI_Co1List"],
    ["2nd Company",      "GUI_Co2List"]
];

missionNamespace setVariable ["GUI_RotaryList",    _rotaryList];
missionNamespace setVariable ["GUI_FixedList",     _fixedList];
missionNamespace setVariable ["GUI_BattalionList", _battalionList];
missionNamespace setVariable ["GUI_Co1List",       _co1List];
missionNamespace setVariable ["GUI_Co2List",       _co2List];
missionNamespace setVariable ["GUI_PadList",       _padList];
missionNamespace setVariable ["GUI_CategoryList",  _categoryList];
uiNamespace setVariable ["GUI_SelectedClass", ""];
uiNamespace setVariable ["GUI_SelectedName",  ""];
uiNamespace setVariable ["GUI_ActiveListVar", "GUI_RotaryList"];

private _padCache = [];
{
    private _varName = _x select 1;
    private _padObj  = missionNamespace getVariable [_varName, objNull];
    if (isNull _padObj) then {
        { if (vehicleVarName _x == _varName) exitWith { _padObj = _x; }; } forEach allMissionObjects "Logic";
    };
    _padCache pushBack _padObj;
} forEach _padList;
missionNamespace setVariable ["GUI_PadCache", _padCache];
