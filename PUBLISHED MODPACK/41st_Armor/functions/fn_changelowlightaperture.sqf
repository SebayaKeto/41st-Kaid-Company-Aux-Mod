#define GET_NUMBER(config,default) (if (isNumber (config)) then {getNumber (config)} else {default})


private _goggles = goggles ace_player;
private _hasLowLight = GET_NUMBER(configFile >> "CfgGlasses" >> (_goggles) >> "FST_hasLowLight",0) == 1;

if (FST_disableLowlight OR !_hasLowlight) exitwith{};

params ["_activate","_increase"];

if (_activate) then {
	FST_lowlight_adjustment_handle = [{
		params ["_args","_handle"];
		_args params ["_increase"];
		if (!(ace_player getVariable ["FST_lowlight_on",false])) exitwith {
			[_handle] call CBA_fnc_removePerFrameHandler;
		};
		private _coef = [1,-1] select _increase;
		FST_lowlight_aperture = ((FST_lowlight_aperture + (_coef *diag_deltatime)) max 0.1) min 3;
		setAperture FST_lowlight_aperture;
		private _percent = round (linearConversion [0.1,3,FST_lowlight_aperture,100,0]);
		hintSilent format ["Lowlight Intensity: %1/100",_percent];
	}, 0, [_increase]] call CBA_fnc_addPerFrameHandler;
} else {
	[FST_lowlight_adjustment_handle] call CBA_fnc_removePerFrameHandler;
	[{hintSilent ""}, [], 1] call CBA_fnc_waitAndExecute;
};
