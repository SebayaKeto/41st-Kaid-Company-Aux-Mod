[
    "FST_lowlight_DefaultAperture", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    "Low Light Default Aperture", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["41st Elite Corps","Low Light"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.2, 3, 2, 1], // data for this setting: [min, max, default, number of shown trailing decimals]
    false, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {  
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_fnc_addSetting;

if (isNil "FST_lowlight_aperture") then {
    FST_lowlight_aperture = missionNamespace getVariable ["FST_lowlight_DefaultAperture", 2];
};