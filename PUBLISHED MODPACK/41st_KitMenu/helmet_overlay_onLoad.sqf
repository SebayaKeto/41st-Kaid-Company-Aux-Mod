private _display = findDisplay 4100;
uiNamespace setVariable ["FST_HelmetOverlay_Display", _display];
private _listCtrl = _display displayCtrl 4102;
lbClear _listCtrl;
private _helmetClasses = [];

{
	private _className = configName _x;

	if (["FST_", _className] call BIS_fnc_inString) then {
		private _itemInfo = _x >> "ItemInfo";
		if (isClass _itemInfo) then {
			private _type = getNumber (_itemInfo >> "type");

			if (_type in [605, 701, 801, 901, 302, 616, 101]) then {
				private _displayName = getText (_x >> "displayName");
				private _picture = getText (_x >> "picture");

				if (_displayName != "") then {
					private _index = _listCtrl lbAdd _displayName;

					if (_picture != "") then {
						_listCtrl lbSetPicture [_index, _picture];
					};

					private _quotedClass = str _className;
					private _dataString = format ["[%1]", _quotedClass];
					_listCtrl lbSetData [_index, _dataString];
					_helmetClasses pushBack _className;
				};
			};
		};
	};
} forEach ("true" configClasses (configFile >> "CfgWeapons"));

{
	private _className = configName _x;

	if (["FST", _className] call BIS_fnc_inString && {getNumber (_x >> "isBackpack") == 1}) then {
		private _displayName = getText (_x >> "displayName");
		private _picture = getText (_x >> "picture");

		if (_displayName != "") then {
			private _index = _listCtrl lbAdd _displayName;
			if (_picture != "") then {
				_listCtrl lbSetPicture [_index, _picture];
			};

			private _quotedClass = str _className;
			private _dataString = format ["[%1]", _quotedClass];
			_listCtrl lbSetData [_index, _dataString];

			_helmetClasses pushBack _className;
		};
	};
} forEach ("true" configClasses (configFile >> "CfgVehicles"));

uiNamespace setVariable ["FST_AllHelmetClasses", _helmetClasses];
