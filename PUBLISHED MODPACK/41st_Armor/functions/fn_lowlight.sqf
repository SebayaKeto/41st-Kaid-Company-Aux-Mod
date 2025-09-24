#include "\x\cba\addons\main\script_macros_common.hpp"
if (!hasInterface) exitWith {};
#define GET_NUMBER(config,default) (if (isNumber (config)) then {getNumber (config)} else {default})
private _hasLowLight = GET_NUMBER(configFile >> "CfgGlasses" >> (goggles ace_player) >> "FST_hasLowLight",0) == 1;

if (FST_disableLowlight) exitwith{};

if (!(ace_player getvariable ["FST_lowlight_on",false]) && _hasLowLight) then {
    playsoundui ["beep_target",1,10];
    setAperture FST_lowlight_aperture;
    ace_player setVariable ["FST_lowlight_on",true];
    ["FST_lowlight_switched", [true, FST_lowlight_aperture]] call CBA_fnc_localEvent;
} else {
    setAperture -1;
    if (_hasLowLight) then {
        playsoundui ["beep_target",1,10];
    };
    ace_player setVariable ["FST_lowlight_on",false];
    ["FST_lowlight_switched", [false, -1]] call CBA_fnc_localEvent;
};