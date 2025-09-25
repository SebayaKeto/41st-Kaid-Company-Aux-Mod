if (!hasInterface) exitWith {};
["41st Elite Corps","FST_lowlight", "Toggle Low-Light Vision", {call FST_fnc_lowlight}, "", []] call CBA_fnc_addKeybind;
FST_disableLowlight = false;

[
    "41st Elite Corps",
    "FST_lowlight_increase",
    "Increase Lowlight Aperture",
    {
        [true,true] call FST_fnc_changeLowlightAperture;
    },
    {
        [false,true] call FST_fnc_changeLowlightAperture;
    },
    [201,[false,false,false]]
] call CBA_fnc_addKeybind;

[
    "41st Elite Corps",
    "FST_lowlight_decrease",
    "Decrease Lowlight Aperture",
    {
        [true,false] call FST_fnc_changeLowlightAperture;
    },
    {
        [false,false] call FST_fnc_changeLowlightAperture;
    },
    [209,[false,false,false]]
] call CBA_fnc_addKeybind;