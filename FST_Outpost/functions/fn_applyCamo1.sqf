params ["_object", ["_mode", "texture"], ["_value", "default"]];

if (isNull _object) exitWith {};

private _typeName = toLowerANSI (typeOf _object);
private _resolvedMode = toLowerANSI _mode;
private _resolvedValue = toLowerANSI _value;

private _isMediumWall = (_typeName find "fst_outpost_mediumwall") > -1;
if (!_isMediumWall) exitWith {};

private _texturePath = "";
private _colorTexture = "";

if (_resolvedMode isEqualTo "texture") then {
	_texturePath = "FST\\FST_Outpost\\MediumWalls\\Data\\Textures\\Walls\\Camo_co.paa";

	_object setObjectTextureGlobal [1, _texturePath];
	_object setVariable ["FST_Outpost_Camo1_Mode", "texture", true];
	_object setVariable ["FST_Outpost_Camo1_Value", _resolvedValue, true];
};

if (_resolvedMode isEqualTo "color") then {
	private _rgba = switch (_resolvedValue) do {
		case "red": {[1, 0.1, 0.1, 1]};
		case "blue": {[0.1, 0.35, 1, 1]};
		case "green": {[0.1, 0.9, 0.25, 1]};
		case "yellow": {[1, 0.95, 0.2, 1]};
		case "black": {[0.05, 0.05, 0.05, 1]};
		default {[1, 1, 1, 1]};
	};

	_colorTexture = format ["#(argb,8,8,3)color(%1,%2,%3,%4)", _rgba # 0, _rgba # 1, _rgba # 2, _rgba # 3];
	_object setObjectTextureGlobal [1, _colorTexture];
	_object setVariable ["FST_Outpost_Camo1_Mode", "color", true];
	_object setVariable ["FST_Outpost_Camo1_Value", _resolvedValue, true];
};