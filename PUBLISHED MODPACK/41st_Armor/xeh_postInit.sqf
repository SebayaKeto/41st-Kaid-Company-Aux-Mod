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

["[41st] Droid Modules", "Global Broadcast",
{
    params [["_pos", [0, 0, 0], [[]], 3], ["_logic", objNull, [objNull]]];

    ["Display Subtitle Message", [
        ["EDIT", ["Speaker Name", "Name of the person or entity speaking"], ["CROSSROAD"]],
        ["EDIT:MULTI", ["Message", "The subtitle message to display"], ["Mission is a go, I repeat, mission is a go, Crossroad, out."]]
        ], {
            params["_values", "_arguments"];
            _speakerName = _values # 0;       // Speaker name
            _message = _values # 1;           // Subtitle message  
            
            // Display subtitle using the exact BIS function syntax to all clients
            [_speakerName, _message] remoteExec ["BIS_fnc_showSubtitle", 0];
            
       }, {}, [_pos]] call zen_dialog_fnc_create;
}, "\A3\ui_f\data\igui\cfg\actions\talk_ca.paa"] call zen_custom_modules_fnc_register;