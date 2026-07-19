
params ["_term","_user","_origin"];

private _text = "";

if (_term getVariable ["FST_DeviceInUse", false]) exitWith {_text = "<t color='#990000'>This device is currently being interacted with</t>"; hintSilent parseText _text;};
if (_user getVariable ["FST_PlayerIsMeching", false]) exitWith {_text = "<t color='#990000'>You are already working on something else</t>"; hintSilent parseText _text;};
if (_term getVariable ["FST_DeviceFullBroken", false]) exitWith {_text = "<t color='#990000'>This device no longer functions and is beyond repair</t>"; hintSilent parseText _text;};
if (_term getVariable ["FST_DeviceBroken", false] && !(("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))) exitWith {_text = "<t color='#990000'>This device currently does not function<br/>You require a toolbox to attempt repairs</t>"; hintSilent parseText _text;};
if (_term getVariable ["FST_DeviceBroken", false] && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))) exitWith
{
	
	_term setVariable ["FST_DeviceInUse",true,true];
	_user setVariable ["FST_PlayerIsMeching",true,true];
	if !(_term getVariable ["FST_DeviceAssessed", false]) then 
	{
		[
			"ASSESSING DAMAGE...",
			3, 
			{
				params ["_arguments"];
				_arguments params ["_term", "_user", "_origin"];
				_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
			},
			{
				params ["_arguments"];
				_arguments params ["_term", "_user", "_origin"];
				private _assessment = selectRandomWeighted [0, 19, 1, 1];
				if (_assessment == 1) exitWith 
				{
					private _itfucked = "<t color='#990000'>The device is clearly damaged beyond being field repaired</t>"; 
					hintSilent parseText _itfucked;
					_term setVariable ["FST_DeviceFullBroken",true,true];
					_term setVariable ["FST_DeviceInUse",false,true];
					_user setVariable ["FST_PlayerIsMeching",false,true];
				};
				if (_assessment == 0) then
				{
					_term setVariable ["FST_DeviceAssessed", true, true];
					_term setVariable ["FST_CurrentError", (floor (random 12)),true];
				};
			},
			{
				params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
				_arguments params ["_term", "_user", "_origin"]; 
				if (_failureCode == 1) then 
				{
					private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
					hintSilent parseText _esctxt0;
				};
				if (_failureCode == 2) then 
				{
					private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
					hintSilent parseText _errortxt0;
				}; 
				_term setVariable ["FST_DeviceInUse",false,true];
				_user setVariable ["FST_PlayerIsMeching",false,true];
				closeDialog 0;
			},
			[_term, _user, _origin]
		] call CBA_fnc_progressBar;
	};
	if !(_term getVariable ["FST_DeviceAssessed", false]) then
	{
		sleep 3.1;
	};
	if !(_term getVariable ["FST_DeviceAssessed", false]) exitwith {_term setVariable ["FST_DeviceInUse",false,true]; _user setVariable ["FST_PlayerIsMeching",false,true];};
	createDialog "FST_RepairDeviceDialog";
	private _display = findDisplay 6969;
	_display displayAddEventHandler
	[
		"KeyDown",
		{
			params ["_display", "_key"];
			if (_key == 1) then {true} else {false};
		}
	];
	private _errortextarray = 
	[
		"You have no clue what is wrong with it.",
		"The device is throwing error codes at you.",
		"The device is extremely sluggish.",
		"It only shows the BIOS screen.",
		"The device refuses to connect to anything.",
		"The lights and displays are flickering on and off and the device fails to stay on repeatedly.",
		"The device is frozen. Not the cold kind of frozen, the ""It's not doing anything"" kind of frozen.",
		"You smell burning electronics from inside it.",
		"Several parts appear blackened inside it.",
		"There is a blaster hole in it.",
		"It will not turn on.",
		"One or more of the parts inside is radiating intense heat."

	];
	private _error = _term getVariable ["FST_CurrentError", 0];
	(_display displayCtrl 1612) ctrlSetStructuredText parsetext (_errortextarray select _error);
	(_display displayCtrl 1613) ctrlSetStructuredText parsetext ( _term getVariable ["FST_LastAttempt", ""]);
	private _button1600 = _display displayCtrl 1600;
	_button1600 setVariable ["FST_RepairData", [_term, _user, _origin, _error]];
	if (_term getVariable ["FST_1600Pressed", false]) then
	{
		_button1600 ctrlEnable false;
		_button1600 ctrlSetTextColor [0.4,0.4,0.4,1];
		_button1600 ctrlSetTooltip "You have already performed this repair";
	} 
	else
	{
		_button1600 ctrlAddEventHandler 
		[
			"ButtonClick",
			{
				private _display = findDisplay 6969;
				{
					_x ctrlEnable false;
				} forEach [
					_display displayCtrl 1600,
					_display displayCtrl 1601,
					_display displayCtrl 1602,
					_display displayCtrl 1603,
					_display displayCtrl 1604,
					_display displayCtrl 1605,
					_display displayCtrl 1606,
					_display displayCtrl 1607,
					_display displayCtrl 1608,
					_display displayCtrl 1609,
					_display displayCtrl 1610,
					_display displayCtrl 1611
				];
				params ["_control"];
				private _repairData = _control getVariable "FST_RepairData";
				_repairData params ["_term", "_user", "_origin", "_error"];
				if (_error == 0) then
				{
					playSound3D ["a3\missions_f_oldman\data\sound\beep.ogg", _term,false, getPosASL _term,5,1,20];
					[
						"RUNNING SYSTEM CHECK SOFTWARE...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 10, 1, 10];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1600, "The device did not respond to that repair."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1600, "That appears to have improved the device somewhat, but it is not fixed."]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 1) then
				{
					playSound3D ["a3\missions_f_oldman\data\sound\beep.ogg", _term,false, getPosASL _term,5,1,20];
					[
						"RUNNING SYSTEM CHECK SOFTWARE...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 18, 1, 2];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1600, "That did not clear all the errors, but appears to have greatly helped."]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 2) then
				{
					playSound3D ["a3\missions_f_oldman\data\sound\beep.ogg", _term,false, getPosASL _term,5,1,20];
					[
						"ATTEMPTING TO RUN SYSTEM CHECK SOFTWARE...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 10, 1, 10];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1600, "The device is too sluggish to run the program properly. That did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1600, "That appears to have improved the device somewhat, but it is not fixed."]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 3) then
				{
					playSound3D ["a3\missions_f_oldman\data\sound\beep.ogg", _term,false, getPosASL _term,5,1,20];
					[
						"RUNNING SYSTEM CHECK SOFTWARE...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 10, 1, 5, 2, 5];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1600, "That appears to have done something, but it is not fixed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1600, "That did not appear to help."]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 4) then
				{
					playSound3D ["a3\missions_f_oldman\data\sound\beep.ogg", _term,false, getPosASL _term,5,1,20];
					[
						"RUNNING SYSTEM CHECK SOFTWARE...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 10, 1, 5, 2, 5];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1600, "That appears to have helped, but it is still not connecting."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1600, "That did not appear to do anything."]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 5) then
				{
					["FST_resetHackRepairButtons", [_term, _display, 1600, "The device cannot stay powered long enough to run the software. That did nothing."]] call CBA_fnc_localEvent;
				};
				if (_error == 6) then
				{
					["FST_resetHackRepairButtons", [_term, _display, 1600, "It would appear a frozen computer cannot run more software. That did nothing."]] call CBA_fnc_localEvent;
				};
				if (_error in [7,8,9]) then
				{
					["FST_resetHackRepairButtons", [_term, _display, 1600, "Appears that trying to run software while the hardware is burnt out does not work. That did nothing."]] call CBA_fnc_localEvent;
				};
				if (_error == 10) then
				{
					["FST_resetHackRepairButtons", [_term, _display, 1600, "Surprisingly, software does not work when the device is off. That did nothing."]] call CBA_fnc_localEvent;
				};
				if (_error == 11) then
				{
					playSound3D ["a3\missions_f_oldman\data\sound\beep.ogg", _term,false, getPosASL _term,5,1,20];
					[
						"RUNNING SYSTEM CHECK SOFTWARE...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 19, 1, 1];
								if ( _checkfail == 0) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>Adding additional strain to the device by running more software has melted down the overheated parts and completely broke the device</t>"]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1600, "That appears to have helped somewhat, but the internals are still overheating."]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
			}
		];
	};
	private _button1601 = _display displayCtrl 1601;
	_button1601 setVariable ["FST_RepairData", [_term, _user, _origin, _error]];
	if (_term getVariable ["FST_1601Pressed", false]) then
	{
		_button1601 ctrlEnable false;
		_button1601 ctrlSetTextColor [0.4,0.4,0.4,1];
		_button1601 ctrlSetTooltip "You have already performed this repair";
	} 
	else
	{
		_button1601 ctrlAddEventHandler 
		[
			"ButtonClick",
			{
				private _display = findDisplay 6969;
				{
					_x ctrlEnable false;
				} forEach [
					_display displayCtrl 1600,
					_display displayCtrl 1601,
					_display displayCtrl 1602,
					_display displayCtrl 1603,
					_display displayCtrl 1604,
					_display displayCtrl 1605,
					_display displayCtrl 1606,
					_display displayCtrl 1607,
					_display displayCtrl 1608,
					_display displayCtrl 1609,
					_display displayCtrl 1610,
					_display displayCtrl 1611
				];
				params ["_control"];
				private _repairData = _control getVariable "FST_RepairData";
				_repairData params ["_term", "_user", "_origin", "_error"];
				if (_error == 0) then
				{
					playSound3D ["a3\missions_f_oldman\data\sound\beep.ogg", _term,false, getPosASL _term,5,1,20];
					[
						"RUNNING DEFRAGMENTATION SOFTWARE...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 10, 1, 10];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1601, "The device did not respond to that repair."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1601, "That appears to have improved the device somewhat, but it is not fixed."]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 1) then
				{
					playSound3D ["a3\missions_f_oldman\data\sound\beep.ogg", _term,false, getPosASL _term,5,1,20];
					[
						"RUNNING DEFRAGMENTATION SOFTWARE...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 18, 1, 2];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1601, "That did not clear all the errors, but appears to have greatly helped."]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 2) then
				{
					playSound3D ["a3\missions_f_oldman\data\sound\beep.ogg", _term,false, getPosASL _term,5,1,20];
					[
						"ATTEMPTING TO RUN DEFRAGMENTATION SOFTWARE...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 10, 1, 10];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1601, "The device is too sluggish to run the program properly. That did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1601, "That appears to have improved the device somewhat, but it is not fixed."]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 3) then
				{
					playSound3D ["a3\missions_f_oldman\data\sound\beep.ogg", _term,false, getPosASL _term,5,1,20];
					[
						"RUNNING DEFRAGMENTATION SOFTWARE...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 10, 1, 5, 2, 5];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1601, "That appears to have done something, but it is not fixed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1601, "That did not appear to help."]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 4) then
				{
					playSound3D ["a3\missions_f_oldman\data\sound\beep.ogg", _term,false, getPosASL _term,5,1,20];
					[
						"RUNNING DEFRAGMENTATION SOFTWARE...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 10, 1, 5, 2, 5];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1601, "That appears to have helped, but it is still not connecting."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1601, "That did not appear to do anything."]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 5) then
				{
					["FST_resetHackRepairButtons", [_term, _display, 1601, "The device cannot stay powered long enough to run the software. That did nothing."]] call CBA_fnc_localEvent;
				};
				if (_error == 6) then
				{
					["FST_resetHackRepairButtons", [_term, _display, 1601, "It would appear a frozen computer cannot run more software. That did nothing."]] call CBA_fnc_localEvent;
				};
				if (_error in [7,8,9]) then
				{
					["FST_resetHackRepairButtons", [_term, _display, 1601, "Appears that trying to run software while the hardware is burnt out does not work. That did nothing."]] call CBA_fnc_localEvent;
				};
				if (_error == 10) then
				{
					["FST_resetHackRepairButtons", [_term, _display, 1601, "Surprisingly, software does not work when the device is off. That did nothing."]] call CBA_fnc_localEvent;
				};
				if (_error == 11) then
				{
					playSound3D ["a3\missions_f_oldman\data\sound\beep.ogg", _term,false, getPosASL _term,5,1,20];
					[
						"RUNNING DEFRAGMENTATION SOFTWARE...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 19, 1, 1];
								if ( _checkfail == 0) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>Adding additional strain to the device by running more software has melted down the overheated parts and completely broke the device</t>"]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1601, "That appears to have helped somewhat, but the internals are still overheating."]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
			}
		];
	};
	private _button1602 = _display displayCtrl 1602;
	_button1602 setVariable ["FST_RepairData", [_term, _user, _origin, _error]];
	if (_term getVariable ["FST_1602Pressed", false]) then
	{
		_button1602 ctrlEnable false;
		_button1602 ctrlSetTextColor [0.4,0.4,0.4,1];
		_button1602 ctrlSetTooltip "You have already performed this repair";
	} 
	else
	{
		_button1602 ctrlAddEventHandler 
		[
			"ButtonClick",
			{
				private _display = findDisplay 6969;
				{
					_x ctrlEnable false;
				} forEach [
					_display displayCtrl 1600,
					_display displayCtrl 1601,
					_display displayCtrl 1602,
					_display displayCtrl 1603,
					_display displayCtrl 1604,
					_display displayCtrl 1605,
					_display displayCtrl 1606,
					_display displayCtrl 1607,
					_display displayCtrl 1608,
					_display displayCtrl 1609,
					_display displayCtrl 1610,
					_display displayCtrl 1611
				];
				params ["_control"];
				private _repairData = _control getVariable "FST_RepairData";
				_repairData params ["_term", "_user", "_origin", "_error"];
				if (_error == 0) then
				{
					[
						"REPAIRING DATALINK...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 10, 1, 9, 2, 1];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1602, "The device did not respond to that repair."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1602, "That appears to have improved the device somewhat, but it is not fixed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the datalink beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 1) then
				{
					[
						"REPAIRING DATALINK...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 10, 1, 9, 2, 1];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1602, "Apparently the datalink was not one of the things throwing an error, so that did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1602, "That appears to have removed some error codes, but it is not fixed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the datalink beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 2) then
				{
					[
						"REPAIRING DATALINK...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 19, 1, 1];
							if ( _checkfail == 0) then
							{
								["FST_resetHackRepairButtons", [_term, _display, 1602, "The datalink was not the thing slowing down the device, so that did nothing."]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the datalink beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 3) then
				{
					[
						"REPAIRING DATALINK...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 19, 1, 1];
							if ( _checkfail == 0) then
							{
								["FST_resetHackRepairButtons", [_term, _display, 1602, "This may surprise you, but repairing the datalink did not in fact help with this issue."]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the datalink beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 4) then
				{
					[
						"REPAIRING DATALINK...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 19, 1, 1];
							if ( _checkfail == 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the datalink beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 5) then
				{
					[
						"REPAIRING DATALINK...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 19, 1, 1];
							if ( _checkfail == 0) then
							{
								["FST_resetHackRepairButtons", [_term, _display, 1602, "The datalink does not appear to have anything to do with this issue. That did nothing."]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the datalink beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 6) then
				{
					[
						"REPAIRING DATALINK...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 19, 1, 1];
							if ( _checkfail == 0) then
							{
								["FST_resetHackRepairButtons", [_term, _display, 1602, "After repairing the datalink, the device does not unfreeze."]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the datalink beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error in [7,8,9]) then
				{
					[
						"REPAIRING DATALINK...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 8, 1, 11, 2, 1];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1602, "The datalink was not a damaged part."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1602, "The datalink was damaged, and you have fixed it, but other components are still damaged."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the datalink beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 10) then
				{
					[
						"REPAIRING DATALINK...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 19, 1, 1];
							if ( _checkfail == 0) then
							{
								["FST_resetHackRepairButtons", [_term, _display, 1602, "It would appear the datalink was not keeping the device turned off. That did nothing."]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the datalink beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 11) then
				{
					[
						"REPAIRING DATALINK...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 13, 1, 6, 2, 1];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1602, "The datalink was not a part that was overheating."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1602, "The datalink was slightly overheating, and you have fixed it, but other components are overheating worse."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{ 
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the datalink beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
			}
		];
	};
	private _button1603 = _display displayCtrl 1603;
	_button1603 setVariable ["FST_RepairData", [_term, _user, _origin, _error]];
	if (_term getVariable ["FST_1603Pressed", false]) then
	{
		_button1603 ctrlEnable false;
		_button1603 ctrlSetTextColor [0.4,0.4,0.4,1];
		_button1603 ctrlSetTooltip "You have already performed this repair";
	} 
	else
	{
		_button1603 ctrlAddEventHandler 
		[
			"ButtonClick",
			{
				private _display = findDisplay 6969;
				{
					_x ctrlEnable false;
				} forEach [
					_display displayCtrl 1600,
					_display displayCtrl 1601,
					_display displayCtrl 1602,
					_display displayCtrl 1603,
					_display displayCtrl 1604,
					_display displayCtrl 1605,
					_display displayCtrl 1606,
					_display displayCtrl 1607,
					_display displayCtrl 1608,
					_display displayCtrl 1609,
					_display displayCtrl 1610,
					_display displayCtrl 1611
				];
				params ["_control"];
				private _repairData = _control getVariable "FST_RepairData";
				_repairData params ["_term", "_user", "_origin", "_error"];
				if (_error == 0) then
				{
					[
						"REPAIRING POWER SUPPLY UNIT...",
						16,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 10, 1, 9, 2, 1];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1603, "The device did not improve with that repair."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1603, "That did something to help, but it is not fixed yet."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the PSU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 1) then
				{
					[
						"REPAIRING POWER SUPPLY UNIT...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 10, 1, 9, 2, 1];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1603, "The power supply unit was not one of the things throwing an error, so that did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1603, "Some error codes appear to have been solved, but the device is not fixed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the PSU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 2) then
				{
					[
						"REPAIRING POWER SUPPLY UNIT...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 19, 1, 1];
							if ( _checkfail == 0) then
							{
								["FST_resetHackRepairButtons", [_term, _display, 1603, "The power supply unit did not affect processing speeds, so that did nothing."]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the PSU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 3) then
				{
					[
						"REPAIRING POWER SUPPLY UNIT...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 19, 1, 1];
							if ( _checkfail == 0) then
							{
								["FST_resetHackRepairButtons", [_term, _display, 1603, "A lack of power was not the issue, so that did nothing."]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the PSU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 4) then
				{
					[
						"REPAIRING POWER SUPPLY UNIT...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 19, 1, 1];
							if ( _checkfail == 0) then
							{
								["FST_resetHackRepairButtons", [_term, _display, 1603, "To clarify, it could still connect to its power supply, so that did nothing."]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the PSU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 5) then
				{
					[
						"REPAIRING POWER SUPPLY UNIT...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 19, 1, 1];
							if ( _checkfail == 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the PSU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 6) then
				{
					[
						"REPAIRING POWER SUPPLY UNIT...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 19, 1, 1];
							if ( _checkfail == 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the PSU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error in [7,8,9]) then
				{
					[
						"REPAIRING POWER SUPPLY UNIT...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 7, 1, 12, 2, 1];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1603, "The power supply unit was not a damaged component."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1603, "The power supply is fixed, but the device is still damaged."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the PSU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 10) then
				{
					[
						"REPAIRING POWER SUPPLY UNIT...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 19, 1, 1];
							if ( _checkfail == 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the PSU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 11) then
				{
					[
						"REPAIRING POWER SUPPLY UNIT...",
						12,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 7, 1, 12, 2, 1];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1603, "The power supply unit was not overheating."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1603, "The power supply is fixed, but other components are still overheating."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the PSU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
			}
		];
	};
	private _button1604 = _display displayCtrl 1604;
	_button1604 setVariable ["FST_RepairData", [_term, _user, _origin, _error]];
	if (_term getVariable ["FST_1604Pressed", false]) then
	{
		_button1604 ctrlEnable false;
		_button1604 ctrlSetTextColor [0.4,0.4,0.4,1];
		_button1604 ctrlSetTooltip "You have already performed this repair";
	} 
	else
	{
		_button1604 ctrlAddEventHandler 
		[
			"ButtonClick",
			{
				private _display = findDisplay 6969;
				{
					_x ctrlEnable false;
				} forEach [
					_display displayCtrl 1600,
					_display displayCtrl 1601,
					_display displayCtrl 1602,
					_display displayCtrl 1603,
					_display displayCtrl 1604,
					_display displayCtrl 1605,
					_display displayCtrl 1606,
					_display displayCtrl 1607,
					_display displayCtrl 1608,
					_display displayCtrl 1609,
					_display displayCtrl 1610,
					_display displayCtrl 1611
				];
				params ["_control"];
				private _repairData = _control getVariable "FST_RepairData";
				_repairData params ["_term", "_user", "_origin", "_error"];
				if (_error == 0) then
				{
					[
						"REPAIRING CENTRAL PROCESSOR UNIT...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 9, 1, 9, 2, 2];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1604, "The central processor was not the issue apparently. That did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1604, "Device appears somewhat improved by your repair, but it is not fixed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the CPU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 1) then
				{
					[
						"REPAIRING CENTRAL PROCESSOR UNIT...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 9, 1, 9, 2, 2];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1604, "The central processor was not making error codes. That did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1604, "The central processor was apparently one of the things causing errors, but the device is not fixed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the CPU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 2) then
				{
					[
						"REPAIRING CENTRAL PROCESSOR UNIT...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 2, 1, 16, 2, 2];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1604, "The central processor was running the best it could already, so that repair did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1604, "The central processor is now running properly, but the device is not fixed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the CPU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 3) then
				{
					[
						"REPAIRING CENTRAL PROCESSOR UNIT...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 2, 2, 15, 3, 2];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1604, "The central processor was running the best it could already, so that repair did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1604, "The central processor is now running properly, but the device is not fixed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the CPU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 4) then
				{
					[
						"REPAIRING CENTRAL PROCESSOR UNIT...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 10, 2, 7, 3, 2];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1604, "The central processor appears to have had nothing to do with the connection issues."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1604, "That seems to have helped a bit, but the device is not fixed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the CPU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 5) then
				{
					[
						"REPAIRING CENTRAL PROCESSOR UNIT...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 18, 1, 2];
							if ( _checkfail == 0) then
							{
								["FST_resetHackRepairButtons", [_term, _display, 1604, "The central processor appears to have had nothing to do with the power issue."]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the CPU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 6) then
				{
					[
						"REPAIRING CENTRAL PROCESSOR UNIT...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 18, 1, 2];
							if ( _checkfail == 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the CPU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error in [7,8,9]) then
				{
					[
						"REPAIRING CENTRAL PROCESSOR UNIT...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 6, 1, 12, 2, 2];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1604, "The central processor was fully unharmed, so that did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1604, "The central processor was one of the damaged parts, but the device still has more."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the CPU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 10) then
				{
					[
						"REPAIRING CENTRAL PROCESSOR UNIT...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 18, 1, 2];
							if ( _checkfail == 0) then
							{
								["FST_resetHackRepairButtons", [_term, _display, 1604, "The central processor appears to have had nothing to do with the power issue."]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the CPU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 11) then
				{
					[
						"REPAIRING CENTRAL PROCESSOR UNIT...",
						15,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 2, 2, 15, 3, 2];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1604, "The central processor was surprisingly not the part overheating. That did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1604, "The central processor is now running much cooler, but other components are also overheating."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You completely broke the CPU beyond what you can repair in the field while trying to repair it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
			}
		];
	};
	private _button1605 = _display displayCtrl 1605;
	_button1605 setVariable ["FST_RepairData", [_term, _user, _origin, _error]];
	if (_term getVariable ["FST_1605Pressed", false]) then
	{
		_button1605 ctrlEnable false;
		_button1605 ctrlSetTextColor [0.4,0.4,0.4,1];
		_button1605 ctrlSetTooltip "You have already performed this repair";
	} 
	else
	{
		_button1605 ctrlAddEventHandler 
		[
			"ButtonClick",
			{
				private _display = findDisplay 6969;
				{
					_x ctrlEnable false;
				} forEach [
					_display displayCtrl 1600,
					_display displayCtrl 1601,
					_display displayCtrl 1602,
					_display displayCtrl 1603,
					_display displayCtrl 1604,
					_display displayCtrl 1605,
					_display displayCtrl 1606,
					_display displayCtrl 1607,
					_display displayCtrl 1608,
					_display displayCtrl 1609,
					_display displayCtrl 1610,
					_display displayCtrl 1611
				];
				params ["_control"];
				private _repairData = _control getVariable "FST_RepairData";
				_repairData params ["_term", "_user", "_origin", "_error"];
				if (_error == 0) then
				{
					[
						"REPLACING FUSES...",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 8, 1, 9, 2, 3];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1605, "You replaced many fuses, but none of them were burnt out, so that did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1605, "A couple fuses were broken so that helped, but it is still not fixed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 1) then
				{
					[
						"REPLACING FUSES...",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 11, 1, 6, 2, 3];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1605, "You replaced many fuses, but none of them were burnt out, so that did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1605, "A couple fuses were broken so that cleared some error codes, but it still has more errors."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 2) then
				{
					[
						"REPLACING FUSES...",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 17, 1, 3];
							if ( _checkfail == 0) then
							{
								["FST_resetHackRepairButtons", [_term, _display, 1605, "You replaced many fuses, but none of them were burnt out, so that did nothing."]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 3) then
				{
					[
						"REPLACING FUSES...",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 9, 2, 7, 3, 3];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1605, "You replaced many fuses, but none of them were burnt out, so that did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1605, "A couple fuses were broken so that should help, but the device is still not working."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 4) then
				{
					[
						"REPLACING FUSES...",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 9, 2, 7, 3, 3];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1605, "You replaced many fuses, but none of them were burnt out, so that did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1605, "A couple fuses were broken so that should help, but the device is still not working."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 5) then
				{
					[
						"REPLACING FUSES...",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 9, 2, 7, 3, 3];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1605, "You replaced many fuses, but none of them were burnt out, so that did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1605, "A couple fuses were damaged so that should help, but the device is still not working."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 6) then
				{
					[
						"REPLACING FUSES...",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 17, 1, 3];
							if ( _checkfail == 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error in [7,8]) then
				{
					[
						"REPLACING FUSES...",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 5, 1, 2, 2, 10, 3, 3];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1605, "You replaced many fuses, but none of them were burnt out, so that did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1605, "Many fuses were burnt out, but there is still more damage."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 9) then
				{
					[
						"REPLACING FUSES...",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 17, 1, 3];
							if ( _checkfail == 0) then
							{
								["FST_resetHackRepairButtons", [_term, _display, 1605, "You replaced many fuses, but none of them were damaged by the blaster, so that did nothing."]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 10) then
				{
					[
						"REPLACING FUSES...",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 5, 1, 17, 2, 3];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1605, "Some fuses were burnt out, but the device will not turn on still."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 11) then
				{
					[
						"REPLACING FUSES...",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 17, 1, 3];
							if ( _checkfail == 0) then
							{
								["FST_resetHackRepairButtons", [_term, _display, 1605, "Fuses are designed to melt when they overheat, not stay hot. So none of them are damaged."]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
			}
		];
	};
	private _button1606 = _display displayCtrl 1606;
	_button1606 setVariable ["FST_RepairData", [_term, _user, _origin, _error]];
	if (_term getVariable ["FST_1606Pressed", false]) then
	{
		_button1606 ctrlEnable false;
		_button1606 ctrlSetTextColor [0.4,0.4,0.4,1];
		_button1606 ctrlSetTooltip "You have already performed this repair";
	} 
	else
	{
		_button1606 ctrlAddEventHandler 
		[
			"ButtonClick",
			{
				private _display = findDisplay 6969;
				{
					_x ctrlEnable false;
				} forEach [
					_display displayCtrl 1600,
					_display displayCtrl 1601,
					_display displayCtrl 1602,
					_display displayCtrl 1603,
					_display displayCtrl 1604,
					_display displayCtrl 1605,
					_display displayCtrl 1606,
					_display displayCtrl 1607,
					_display displayCtrl 1608,
					_display displayCtrl 1609,
					_display displayCtrl 1610,
					_display displayCtrl 1611
				];
				params ["_control"];
				private _repairData = _control getVariable "FST_RepairData";
				_repairData params ["_term", "_user", "_origin", "_error"];
				if (_error == 0) then
				{
					[
						"REPLACING CAPACITORS...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 8, 1, 9, 2, 3];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1606, "You replaced several capacitors, but none of them had failed, so that did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1606, "A couple capacitors had failed so that helped, but the device is still not fixed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 1) then
				{
					[
						"REPLACING CAPACITORS...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 12, 1, 5, 2, 3];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1606, "You replaced several capacitors, but none of them had failed, so that did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1606, "A couple capacitors had failed so that cleared a few error codes, but many still remain."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 2) then
				{
					[
						"REPLACING CAPACITORS...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 17, 1, 3];
							if ( _checkfail == 0) then
							{
								["FST_resetHackRepairButtons", [_term, _display, 1606, "Capacitors have nothing to do with processing speed so that did nothing."]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error in [3,5]) then
				{
					[
						"REPLACING CAPACITORS...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 14, 1, 1, 2, 2, 3, 3];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1606, "You replaced several capacitors, but none of them had failed, so that did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1606, "A couple capacitors had failed that you replaced, but the device still is not fixed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 4) then
				{
					[
						"REPLACING CAPACITORS...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 6, 1, 3, 2, 8, 3, 3];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1606, "You replaced several capacitors, but none of them had failed, so that did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1606, "A couple capacitors had failed which you replaced, but the device still is not fixed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 6) then
				{
					[
						"REPLACING CAPACITORS...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 17, 1, 3];
							if ( _checkfail == 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error in [7,8]) then
				{
					[
						"REPLACING CAPACITORS...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 1, 2, 15, 3, 3];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1606, "You replaced several capacitors, but oddly none of them had failed, so that did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1606, "You replace the damaged capacitors, but several components remain damaged."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 9) then
				{
					[
						"REPLACING CAPACITORS...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 8, 1, 9, 2, 3];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1606, "You replaced several capacitors, but none of them had been hit, so that did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1606, "You replaced several destroyed capacitors, but not fixed the device fully."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 10) then
				{
					[
						"REPLACING CAPACITORS...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 10, 1, 7, 2, 3];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1606, "You replaced several damaged capacitors, but have not fixed the device fully."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 11) then
				{
					[
						"REPLACING CAPACITORS...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 7, 1, 10, 2, 3];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1606, "The capacitors you replaced were stable, so that had no effect."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1606, "You replaced several overheated capacitors, but other components are still hot."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up while trying to repair the device and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
			}
		];
	};
	private _button1607 = _display displayCtrl 1607;
	_button1607 setVariable ["FST_RepairData", [_term, _user, _origin, _error]];
	if (_term getVariable ["FST_1607Pressed", false]) then
	{
		_button1607 ctrlEnable false;
		_button1607 ctrlSetTextColor [0.4,0.4,0.4,1];
		_button1607 ctrlSetTooltip "You have already performed this repair";
	} 
	else
	{
		_button1607 ctrlAddEventHandler 
		[
			"ButtonClick",
			{
				private _display = findDisplay 6969;
				{
					_x ctrlEnable false;
				} forEach [
					_display displayCtrl 1600,
					_display displayCtrl 1601,
					_display displayCtrl 1602,
					_display displayCtrl 1603,
					_display displayCtrl 1604,
					_display displayCtrl 1605,
					_display displayCtrl 1606,
					_display displayCtrl 1607,
					_display displayCtrl 1608,
					_display displayCtrl 1609,
					_display displayCtrl 1610,
					_display displayCtrl 1611
				];
				params ["_control"];
				private _repairData = _control getVariable "FST_RepairData";
				_repairData params ["_term", "_user", "_origin", "_error"];
				if (_error == 0) then
				{
					[
						"TURNING OFF AND BACK ON AGAIN...",
						8,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 10, 1, 10];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1607, "Nothing changed after the restart."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1607, "Device appears somewhat improved, but it is not fixed."]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 1) then
				{
					[
						"TURNING OFF AND BACK ON AGAIN...",
						8,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 15, 1, 5];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1607, "No error codes have disappeared after the restart."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1607, "Some error codes have cleared up, but some remain to be fixed."]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 2) then
				{
					[
						"TURNING OFF AND ATTEMPTING TO TURN ON AGAIN...",
						25,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 10, 1, 9, 2, 1];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1607, "The device is still as sluggish as before. That did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1607, "Device speed has improved since the restart, but it is still very slow."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>...it is not restarting, it is not doing anything anymore... you have clearly completely broke it beyond repair</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 3) then
				{
					_term setVariable ["FST_1607Pressed", true, true];
					private _display = findDisplay 6969;
					private _attempttext = _display displayCtrl 1613;
					private _atext = "The boot screen showed up again. What were you expecting to happen?";
					_attempttext ctrlSetStructuredText parsetext _atext;
					_term setVariable ["FST_LastAttempt", _atext,true];
					["FST_resetHackRepairButtons", [_term, _display, 1607]] call CBA_fnc_localEvent;
				};
				if (_error == 4) then
				{
					[
						"TURNING OFF AND BACK ON AGAIN...",
						8,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 15, 1, 4, 2, 1];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1607, "Something seems better, but the lack of connection remains."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1607, "Nothing seems to have changed after the restart."]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
				if (_error == 5) then
				{
					_term setVariable ["FST_1607Pressed", true, true];
					private _display = findDisplay 6969;
					private _attempttext = _display displayCtrl 1613;
					_attempttext ctrlSetStructuredText parsetext "The device was already turning off and on, so that added nothing to your repair.";
					["FST_resetHackRepairButtons", [_term, _display, 1607]] call CBA_fnc_localEvent;
				};
				if (_error == 6) then
				{
					[
						"TURNING OFF AND BACK ON AGAIN...",
						8,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if ( _error in [7,8,9,10]) then
				{
					_term setVariable ["FST_1607Pressed", true, true];
					private _display = findDisplay 6969;
					private _attempttext = _display displayCtrl 1613;
					private _atext = "The device was already off, and it definitely did not turn on. That did nothing.";
					_attempttext ctrlSetStructuredText parsetext _atext;
					_term setVariable ["FST_LastAttempt", _atext,true];
					["FST_resetHackRepairButtons", [_term, _display, 1607]] call CBA_fnc_localEvent;
				};
				if (_error == 11) then
				{
					[
						"TURNING OFF, LETTING COOL DOWN, AND TURNING BACK ON AGAIN...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 5, 1, 14, 2, 1];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1607, "The device is much cooler now, but the parts are slowly regaining heat, more repairs are needed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1607, "The parts reheat with minimal delay upon reboot. That did nothing."]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;
				};
			}
		];
	};
	private _button1608 = _display displayCtrl 1608;
	_button1608 setVariable ["FST_RepairData", [_term, _user, _origin, _error]];
	if (_term getVariable ["FST_1608Pressed", false]) then
	{
		_button1608 ctrlEnable false;
		_button1608 ctrlSetTextColor [0.4,0.4,0.4,1];
		_button1608 ctrlSetTooltip "You have already performed this repair";
	} 
	else
	{
		_button1608 ctrlAddEventHandler 
		[
			"ButtonClick",
			{
				private _display = findDisplay 6969;
				{
					_x ctrlEnable false;
				} forEach [
					_display displayCtrl 1600,
					_display displayCtrl 1601,
					_display displayCtrl 1602,
					_display displayCtrl 1603,
					_display displayCtrl 1604,
					_display displayCtrl 1605,
					_display displayCtrl 1606,
					_display displayCtrl 1607,
					_display displayCtrl 1608,
					_display displayCtrl 1609,
					_display displayCtrl 1610,
					_display displayCtrl 1611
				];
				params ["_control"];
				private _repairData = _control getVariable "FST_RepairData";
				_repairData params ["_term", "_user", "_origin", "_error"];
				if (_error == 0) then
				{
					[
						"ATTEMPTING TO BYPASS POTENTIALLY DAMAGED CIRCUITRY...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 10, 1, 5, 2, 5];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1608, "You did not get any closer to fixing the issue, but at least you did not make it worse."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1608, "Device appears to be somewhat more functional, but it is not fixed yet."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up badly while rerouting delicate components and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 1) then
				{
					[
						"ATTEMPTING TO BYPASS POTENTIALLY DAMAGED CIRCUITRY...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 13, 1, 2, 2, 5];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1608, "No error codes went away."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1608, "You cleared a few error codes, but many remain."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up badly while rerouting delicate components and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 2) then
				{
					[
						"ATTEMPTING TO BYPASS POTENTIALLY DAMAGED CIRCUITRY...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 14, 1, 1, 2, 5];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1608, "That accomplished nothing for this issue."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1608, "You managed to get a little more speed out of it, but it is still very slow."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up badly while rerouting delicate components and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 3) then
				{
					[
						"ATTEMPTING TO BYPASS POTENTIALLY DAMAGED CIRCUITRY...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 14, 1, 1, 2, 5];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1608, "You could not bypass whatever is preventing it from loading. That did nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1608, "You did...something. Seems to maybe have helped?"]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up badly while rerouting delicate components and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error in [4,6]) then
				{
					[
						"ATTEMPTING TO BYPASS POTENTIALLY DAMAGED CIRCUITRY...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 15, 1, 5];
							if ( _checkfail == 0) then
							{
								["FST_resetHackRepairButtons", [_term, _display, 1608, "This does not appear to be a bypassable issue. At least you did not make it worse."]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up badly while rerouting delicate components and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 5) then
				{
					[
						"ATTEMPTING TO BYPASS POTENTIALLY DAMAGED CIRCUITRY...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 10, 1, 5, 2, 5];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1608, "You could not bypass whatever is causing this issue."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1608, "It seems to be functioning better now, but the issue persists."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up badly while rerouting delicate components and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error in [7,8,9]) then
				{
					[
						"ATTEMPTING TO BYPASS POTENTIALLY DAMAGED CIRCUITRY...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 5, 1, 10, 2, 5];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1608, "You failed to bypass the damaged components."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1608, "You did it, but there is still more that needs to be fixed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up badly while rerouting delicate components and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 10) then
				{
					[
						"ATTEMPTING TO BYPASS POTENTIALLY DAMAGED CIRCUITRY...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 10, 2, 4, 3, 5];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1608, "You failed to make it able to start up."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1608, "Maybe that has helped, but you will have to do more to fix it."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up badly while rerouting delicate components and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 11) then
				{
					[
						"ATTEMPTING TO BYPASS POTENTIALLY DAMAGED CIRCUITRY...",
						20,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 5, 1, 10, 2, 5];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1608, "You failed to bypass the damaged components."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1608, "You did it, but there is still more that needs to be fixed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_loseHackRepair", [_term, _user,  "<t color='#990000'>You messed up badly while rerouting delicate components and broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
			}
		];
	};
	private _button1609 = _display displayCtrl 1609;
	_button1609 setVariable ["FST_RepairData", [_term, _user, _origin, _error]];
	if (_term getVariable ["FST_1609Pressed", false]) then
	{
		_button1609 ctrlEnable false;
		_button1609 ctrlSetTextColor [0.4,0.4,0.4,1];
		_button1609 ctrlSetTooltip "You have already performed this repair";
	} 
	else
	{
		_button1609 ctrlAddEventHandler 
		[
			"ButtonClick",
			{
				private _display = findDisplay 6969;
				{
					_x ctrlEnable false;
				} forEach [
					_display displayCtrl 1600,
					_display displayCtrl 1601,
					_display displayCtrl 1602,
					_display displayCtrl 1603,
					_display displayCtrl 1604,
					_display displayCtrl 1605,
					_display displayCtrl 1606,
					_display displayCtrl 1607,
					_display displayCtrl 1608,
					_display displayCtrl 1609,
					_display displayCtrl 1610,
					_display displayCtrl 1611
				];
				params ["_control"];
				private _repairData = _control getVariable "FST_RepairData";
				_repairData params ["_term", "_user", "_origin", "_error"];
				if (_error == 0) then
				{
					[
						"I GOT IT!",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 3) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 5, 1, 6, 2, 2, 3, 7];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "You caused some sparks, but otherwise accomplished nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "Ouch."]] call CBA_fnc_localEvent;
									hintSilent parseText "<t color='#990000'>You have been electrocuted by the device you were repairing</t>";
									_term setVariable ["FST_DeviceInUse",false,true];
									_user setVariable ["FST_PlayerIsMeching",false,true];
									closeDialog 0;
									playSound3D ["a3\missions_f_epa\data\sounds\electricity_loop.wss", _term,false, getPosASL _term,5,1,20];
									[_user, 0.5, "LeftArm",  "plasma"] call ace_medical_fnc_addDamageToUnit;
									[_user, 0.5, "RightArm", "plasma"] call ace_medical_fnc_addDamageToUnit;
									[ _user, true, 3, true] call ace_medical_fnc_setUnconscious;
									_user addForce [ _user vectorModelToWorld [0,-200,800], _user selectionPosition "face"]; 
								};
								if ( _checkfail == 2) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1609, "Somehow random wire crossing appears to have improved the device, but it is not fixed yet."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>Crossing random live wires broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 1) then
				{
					[
						"I GOT IT!",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 3) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 6, 1, 6, 2, 1, 3, 7];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "You caused some sparks, but otherwise accomplished nothing."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "Ouch."]] call CBA_fnc_localEvent;
									hintSilent parseText "<t color='#990000'>You have been electrocuted by the device you were repairing</t>";
									_term setVariable ["FST_DeviceInUse",false,true];
									_user setVariable ["FST_PlayerIsMeching",false,true];
									closeDialog 0;
									playSound3D ["a3\missions_f_epa\data\sounds\electricity_loop.wss", _term,false, getPosASL _term,5,1,20];
									[_user, 0.5, "LeftArm",  "plasma"] call ace_medical_fnc_addDamageToUnit;
									[_user, 0.5, "RightArm", "plasma"] call ace_medical_fnc_addDamageToUnit;
									[ _user, true, 3, true] call ace_medical_fnc_setUnconscious;
									_user addForce [ _user vectorModelToWorld [0,-200,800], _user selectionPosition "face"]; 
								};
								if ( _checkfail == 2) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1609, "Somehow random wire crossing has cleared some error codes, but it is not fixed yet."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>Crossing random live wires broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 2) then
				{
					[
						"I GOT IT!",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _checkfail = selectRandomWeighted [0, 6, 1, 7, 2, 7];
							if ( _checkfail == 0) then
							{
								["FST_resetHackRepairButtons", [_term, _display, 1609, "You caused some sparks, but had no effect on the device's speed."]] call CBA_fnc_localEvent;
							};
							if ( _checkfail == 1) then
							{
								["FST_resetHackRepairButtons", [_term, _display, 1609, "Ouch."]] call CBA_fnc_localEvent;
								hintSilent parseText "<t color='#990000'>You have been electrocuted by the device you were repairing</t>";
								_term setVariable ["FST_DeviceInUse",false,true];
								_user setVariable ["FST_PlayerIsMeching",false,true];
								closeDialog 0;
								playSound3D ["a3\missions_f_epa\data\sounds\electricity_loop.wss", _term,false, getPosASL _term,5,1,20];
								[_user, 0.5, "LeftArm",  "plasma"] call ace_medical_fnc_addDamageToUnit;
								[_user, 0.5, "RightArm", "plasma"] call ace_medical_fnc_addDamageToUnit;
								[ _user, true, 3, true] call ace_medical_fnc_setUnconscious;
								_user addForce [ _user vectorModelToWorld [0,-200,800], _user selectionPosition "face"]; 
							};
							if ( _checkfail == 2) then
							{
								["FST_loseHackRepair", [_term, _user, "<t color='#990000'>Crossing random live wires broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 3) then
				{
					[
						"I GOT IT!",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 3) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 6, 1, 6, 2, 1, 3, 7];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "You crossed a bunch of wires and surprisingly that did not help at all."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "Ouch."]] call CBA_fnc_localEvent;
									hintSilent parseText "<t color='#990000'>You have been electrocuted by the device you were repairing</t>";
									_term setVariable ["FST_DeviceInUse",false,true];
									_user setVariable ["FST_PlayerIsMeching",false,true];
									closeDialog 0;
									playSound3D ["a3\missions_f_epa\data\sounds\electricity_loop.wss", _term,false, getPosASL _term,5,1,20];
									[_user, 0.5, "LeftArm",  "plasma"] call ace_medical_fnc_addDamageToUnit;
									[_user, 0.5, "RightArm", "plasma"] call ace_medical_fnc_addDamageToUnit;
									[ _user, true, 3, true] call ace_medical_fnc_setUnconscious;
									_user addForce [ _user vectorModelToWorld [0,-200,800], _user selectionPosition "face"]; 
								};
								if ( _checkfail == 2) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1609, "Somehow your reckless wire crossing has improved something, but it is not fixed yet."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>Crossing random live wires broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 4) then
				{
					[
						"I GOT IT!",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 4, 1, 6, 2, 3, 3, 7];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "Nope, that did not help."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "Ouch."]] call CBA_fnc_localEvent;
									hintSilent parseText "<t color='#990000'>You have been electrocuted by the device you were repairing</t>";
									_term setVariable ["FST_DeviceInUse",false,true];
									_user setVariable ["FST_PlayerIsMeching",false,true];
									closeDialog 0;
									playSound3D ["a3\missions_f_epa\data\sounds\electricity_loop.wss", _term,false, getPosASL _term,5,1,20];
									[_user, 0.5, "LeftArm",  "plasma"] call ace_medical_fnc_addDamageToUnit;
									[_user, 0.5, "RightArm", "plasma"] call ace_medical_fnc_addDamageToUnit;
									[ _user, true, 3, true] call ace_medical_fnc_setUnconscious;
									_user addForce [ _user vectorModelToWorld [0,-200,800], _user selectionPosition "face"]; 
								};
								if ( _checkfail == 2) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1609, "The wires you crossed caused lights to turn on. Probably a good sign?"]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>Crossing random live wires broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 5) then
				{
					[
						"I GOT IT!",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 5, 1, 4, 2, 4, 3, 7];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "Good job, seems to be worse now."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "Ouch."]] call CBA_fnc_localEvent;
									hintSilent parseText "<t color='#990000'>You have been electrocuted by the device you were repairing</t>";
									_term setVariable ["FST_DeviceInUse",false,true];
									_user setVariable ["FST_PlayerIsMeching",false,true];
									closeDialog 0;
									playSound3D ["a3\missions_f_epa\data\sounds\electricity_loop.wss", _term,false, getPosASL _term,5,1,20];
									[_user, 0.5, "LeftArm",  "plasma"] call ace_medical_fnc_addDamageToUnit;
									[_user, 0.5, "RightArm", "plasma"] call ace_medical_fnc_addDamageToUnit;
									[ _user, true, 3, true] call ace_medical_fnc_setUnconscious;
									_user addForce [ _user vectorModelToWorld [0,-200,800], _user selectionPosition "face"]; 
								};
								if ( _checkfail == 2) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1609, "The flickering has decreased from your random rewiring."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>Crossing random live wires broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 6) then
				{
					[
						"I GOT IT!",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 6, 2, 6, 3, 7];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "It is still frozen, but with wires crossed now."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "Ouch."]] call CBA_fnc_localEvent;
									hintSilent parseText "<t color='#990000'>You have been electrocuted by the device you were repairing</t>";
									_term setVariable ["FST_DeviceInUse",false,true];
									_user setVariable ["FST_PlayerIsMeching",false,true];
									closeDialog 0;
									playSound3D ["a3\missions_f_epa\data\sounds\electricity_loop.wss", _term,false, getPosASL _term,5,1,20];
									[_user, 0.5, "LeftArm",  "plasma"] call ace_medical_fnc_addDamageToUnit;
									[_user, 0.5, "RightArm", "plasma"] call ace_medical_fnc_addDamageToUnit;
									[ _user, true, 3, true] call ace_medical_fnc_setUnconscious;
									_user addForce [ _user vectorModelToWorld [0,-200,800], _user selectionPosition "face"]; 
								};
								if ( _checkfail == 3) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>Crossing random live wires broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 7) then
				{
					[
						"I GOT IT!",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 5, 2, 1, 3, 6, 4, 7];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "The burning smell seems worse after your efforts."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "Ouch."]] call CBA_fnc_localEvent;
									hintSilent parseText "<t color='#990000'>You have been electrocuted by the device you were repairing</t>";
									_term setVariable ["FST_DeviceInUse",false,true];
									_user setVariable ["FST_PlayerIsMeching",false,true];
									closeDialog 0;
									playSound3D ["a3\missions_f_epa\data\sounds\electricity_loop.wss", _term,false, getPosASL _term,5,1,20];
									[_user, 0.5, "LeftArm",  "plasma"] call ace_medical_fnc_addDamageToUnit;
									[_user, 0.5, "RightArm", "plasma"] call ace_medical_fnc_addDamageToUnit;
									[ _user, true, 3, true] call ace_medical_fnc_setUnconscious;
									_user addForce [ _user vectorModelToWorld [0,-200,800], _user selectionPosition "face"]; 
								};
								if ( _checkfail == 3) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1609, "You have wired the connections in a way that might help, but have not fixed it."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 4) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>Crossing random live wires broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 8) then
				{
					[
						"I GOT IT!",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 5, 2, 1, 3, 6, 4, 7];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "Several more parts seem blackened now."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "Ouch."]] call CBA_fnc_localEvent;
									hintSilent parseText "<t color='#990000'>You have been electrocuted by the device you were repairing</t>";
									_term setVariable ["FST_DeviceInUse",false,true];
									_user setVariable ["FST_PlayerIsMeching",false,true];
									closeDialog 0;
									playSound3D ["a3\missions_f_epa\data\sounds\electricity_loop.wss", _term,false, getPosASL _term,5,1,20];
									[_user, 0.5, "LeftArm",  "plasma"] call ace_medical_fnc_addDamageToUnit;
									[_user, 0.5, "RightArm", "plasma"] call ace_medical_fnc_addDamageToUnit;
									[ _user, true, 3, true] call ace_medical_fnc_setUnconscious;
									_user addForce [ _user vectorModelToWorld [0,-200,800], _user selectionPosition "face"]; 
								};
								if ( _checkfail == 3) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1609, "You have wired the connections in a way that might help, but have not fixed it."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 4) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>Crossing random live wires broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 9) then
				{
					[
						"I GOT IT!",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 5, 2, 1, 3, 6, 4, 7];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "After that repair, being shot is only the second worst thing to happen to this device."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "Ouch."]] call CBA_fnc_localEvent;
									hintSilent parseText "<t color='#990000'>You have been electrocuted by the device you were repairing</t>";
									_term setVariable ["FST_DeviceInUse",false,true];
									_user setVariable ["FST_PlayerIsMeching",false,true];
									closeDialog 0;
									playSound3D ["a3\missions_f_epa\data\sounds\electricity_loop.wss", _term,false, getPosASL _term,5,1,20];
									[_user, 0.5, "LeftArm",  "plasma"] call ace_medical_fnc_addDamageToUnit;
									[_user, 0.5, "RightArm", "plasma"] call ace_medical_fnc_addDamageToUnit;
									[ _user, true, 3, true] call ace_medical_fnc_setUnconscious;
									_user addForce [ _user vectorModelToWorld [0,-200,800], _user selectionPosition "face"]; 
								};
								if ( _checkfail == 3) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1609, "You have wired the connections in a way that might help, but have not fixed it."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 4) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>Crossing random live wires broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 10) then
				{
					[
						"I GOT IT!",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 2) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 5, 2, 1, 3, 6, 4, 7];
								if ( _checkfail == 0) then
								{
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "It did not turn on, and now it might never again."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "Ouch."]] call CBA_fnc_localEvent;
									hintSilent parseText "<t color='#990000'>You have been electrocuted by the device you were repairing</t>";
									_term setVariable ["FST_DeviceInUse",false,true];
									_user setVariable ["FST_PlayerIsMeching",false,true];
									closeDialog 0;
									playSound3D ["a3\missions_f_epa\data\sounds\electricity_loop.wss", _term,false, getPosASL _term,5,1,20];
									[_user, 0.5, "LeftArm",  "plasma"] call ace_medical_fnc_addDamageToUnit;
									[_user, 0.5, "RightArm", "plasma"] call ace_medical_fnc_addDamageToUnit;
									[ _user, true, 3, true] call ace_medical_fnc_setUnconscious;
									_user addForce [ _user vectorModelToWorld [0,-200,800], _user selectionPosition "face"]; 
								};
								if ( _checkfail == 3) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1609, "You have wired the connections in a way that might help, but have not fixed it."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 4) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>Crossing random live wires broke it beyond what you can repair in the field. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 11) then
				{
					[
						"I GOT IT!",
						10,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							if ((_term getVariable ["FST_GoodRepair", 0]) > 3) then
							{
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 6, 2, 1, 3, 12];
								if ( _checkfail == 0) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "The heat seems to have gotten worse from your efforts."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									["FST_resetHackRepairButtons", [_term, _display, 1609, "Ouch."]] call CBA_fnc_localEvent;
									hintSilent parseText "<t color='#990000'>You have been electrocuted by the device you were repairing</t>";
									_term setVariable ["FST_DeviceInUse",false,true];
									_user setVariable ["FST_PlayerIsMeching",false,true];
									closeDialog 0;
									playSound3D ["a3\missions_f_epa\data\sounds\electricity_loop.wss", _term,false, getPosASL _term,5,1,20];
									[_user, 0.5, "LeftArm",  "plasma"] call ace_medical_fnc_addDamageToUnit;
									[_user, 0.5, "RightArm", "plasma"] call ace_medical_fnc_addDamageToUnit;
									[ _user, true, 3, true] call ace_medical_fnc_setUnconscious;
									_user addForce [ _user vectorModelToWorld [0,-200,800], _user selectionPosition "face"]; 
								};
								if ( _checkfail == 2) then
								{
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1609, "Amazingly, it seems to be cooling down a little from your rewiring, but it is not fixed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>Crossing random live wires triggered a meltdown in several parts you overcharged. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
			}
		];
	};
	private _button1610 = _display displayCtrl 1610;
	_button1610 setVariable ["FST_RepairData", [_term, _user, _origin, _error]];
	if (_term getVariable ["FST_1610Pressed", false]) then
	{
		_button1610 ctrlEnable false;
		_button1610 ctrlSetTextColor [0.4,0.4,0.4,1];
		_button1610 ctrlSetTooltip "You have already performed this repair";
	} 
	else
	{
		_button1610 ctrlAddEventHandler 
		[
			"ButtonClick",
			{
				private _display = findDisplay 6969;
				{
					_x ctrlEnable false;
				} forEach [
					_display displayCtrl 1600,
					_display displayCtrl 1601,
					_display displayCtrl 1602,
					_display displayCtrl 1603,
					_display displayCtrl 1604,
					_display displayCtrl 1605,
					_display displayCtrl 1606,
					_display displayCtrl 1607,
					_display displayCtrl 1608,
					_display displayCtrl 1609,
					_display displayCtrl 1610,
					_display displayCtrl 1611
				];
				params ["_control"];
				private _repairData = _control getVariable "FST_RepairData";
				_repairData params ["_term", "_user", "_origin", "_error"];
				if (_error == 0) then
				{
					[
						"APPLYING PERCUSSIVE MAINTENANCE...",
						2,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _injury = floor (random 2);
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 11, 2, 1, 3, 7];
								if ( _checkfail == 0) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_resetHackRepairButtons", [_term, _display, 1610, "Well, you dented the casing, but that did not seem to help."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1610, "You did something to help with that strike, but it is not fixed yet."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>There were several concerning crunching noises and brief flashes of light inside it, and now smoke is drifting out of its vents. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 1) then
				{
					[
						"APPLYING PERCUSSIVE MAINTENANCE...",
						2,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _injury = floor (random 2);
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 11, 2, 1, 3, 7];
								if ( _checkfail == 0) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_resetHackRepairButtons", [_term, _display, 1610, "Besides the device looking a bit dented now the situation has not changed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1610, "Amazingly you cleared up a few error codes with that impact, but the device is not fixed yet."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>The device is no longer displaying error codes, as that impact rendered the device beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 2) then
				{
					[
						"APPLYING PERCUSSIVE MAINTENANCE...",
						2,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _injury = floor (random 2);
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 11, 2, 1, 3, 7];
								if ( _checkfail == 0) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_resetHackRepairButtons", [_term, _display, 1610, "You successfully made a dent in the device. You did not make a dent in the problem however."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1610, "Physical abuse has convinced the device to function marginally faster, but it still needs more repairs."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>There were several concerning crunching noises and brief flashes of light inside it, and now smoke is drifting out of its vents. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 3) then
				{
					[
						"APPLYING PERCUSSIVE MAINTENANCE...",
						2,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _injury = floor (random 2);
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 11, 2, 1, 3, 7];
								if ( _checkfail == 0) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_resetHackRepairButtons", [_term, _display, 1610, "The device was not intimidated by your attack."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1610, "That might have done more than just add a dent in the casing, but it still needs more repairs."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>The device is no longer showing the BIOS sceen. It is not displaying anything at all, as the device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 4) then
				{
					[
						"APPLYING PERCUSSIVE MAINTENANCE...",
						2,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _injury = floor (random 2);
							if ((_term getVariable ["FST_GoodRepair", 0]) > 1) then
							{
								if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 11, 2, 1, 3, 7];
								if ( _checkfail == 0) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_resetHackRepairButtons", [_term, _display, 1610, "The device still refuses to connect."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1610, "It looks like you might have scared it into trying to connect, but it still needs more repairs to do so."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>There was a very loud crunch noise... the device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 5) then
				{
					[
						"APPLYING PERCUSSIVE MAINTENANCE...",
						2,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _injury = floor (random 2);
							if ((_term getVariable ["FST_GoodRepair", 0]) > 0) then
							{
								if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 4, 1, 5, 2, 4, 3, 7];
								if ( _checkfail == 0) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_resetHackRepairButtons", [_term, _display, 1610, "You have successfully made it worse."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									_term setVariable ["FST_GoodRepair", ((_term getVariable ["FST_GoodRepair", 0]) + 1),true];
									["FST_resetHackRepairButtons", [_term, _display, 1610, "Something inside shifted back into position, but it still is not fixed."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 3) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>You fixed it turning on and off, as it is now only off. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 6) then
				{
					[
						"APPLYING PERCUSSIVE MAINTENANCE...",
						2,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _injury = floor (random 2);
							if ((_term getVariable ["FST_GoodRepair", 0]) > 3) then
							{
								if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 12, 2, 7];
								if ( _checkfail == 0) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_resetHackRepairButtons", [_term, _display, 1610, "Still frozen, and now dented."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>There was a very loud crunch noise... the device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error in [7,8]) then
				{
					[
						"APPLYING PERCUSSIVE MAINTENANCE...",
						2,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _injury = floor (random 2);
							if ((_term getVariable ["FST_GoodRepair", 0]) > 3) then
							{
								if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 13, 1, 7];
								if ( _checkfail == 0) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_resetHackRepairButtons", [_term, _display, 1610, "Did not help, may have made it worse."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>There was a very loud electric shorting noise and flash of light from inside the device. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 9) then
				{
					[
						"APPLYING PERCUSSIVE MAINTENANCE...",
						2,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _injury = floor (random 2);
							if ((_term getVariable ["FST_GoodRepair", 0]) > 3) then
							{
								if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 13, 1, 7];
								if ( _checkfail == 0) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_resetHackRepairButtons", [_term, _display, 1610, "Now there is both a blaster hole and a giant dent in it."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>There was a very loud electric shorting noise and flash of light from inside the device. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 10) then
				{
					[
						"APPLYING PERCUSSIVE MAINTENANCE...",
						2,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _injury = floor (random 2);
							if ((_term getVariable ["FST_GoodRepair", 0]) > 3) then
							{
								if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 12, 2, 7];
								if ( _checkfail == 0) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_resetHackRepairButtons", [_term, _display, 1610, "Nope, still not on."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>There was a loud crunch noise and the sound of small objects clattering down inside it. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
				if (_error == 11) then
				{
					[
						"APPLYING PERCUSSIVE MAINTENANCE...",
						2,
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user", "_origin", "_error"];
							private _display = findDisplay 6969;
							private _injury = floor (random 2);
							if ((_term getVariable ["FST_GoodRepair", 0]) > 3) then
							{
								if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
								["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
							} else
							{
								private _checkfail = selectRandomWeighted [0, 1, 1, 12, 2, 7];
								if ( _checkfail == 0) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_winHackRepair", [_term, _user, _origin]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 1) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_resetHackRepairButtons", [_term, _display, 1610, "You getting heated with the device did not make it cool down."]] call CBA_fnc_localEvent;
								};
								if ( _checkfail == 2) then
								{
									if ( _injury == 1) then {[_user, 0.2, (["LeftArm","RightArm"] select (floor (random 2))),  "punch"] call ace_medical_fnc_addDamageToUnit;};
									["FST_loseHackRepair", [_term, _user, "<t color='#990000'>The heat-softened part easily compresses under your impact. The device is beyond fixing now</t>"]] call CBA_fnc_localEvent;
								};
							};
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user", "_origin", "_error"]; 
							if (_failureCode == 1) then 
							{
								private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
								hintSilent parseText _esctxt0;
							};
							if (_failureCode == 2) then 
							{
								private _errortxt0 = "<t color='#990000'>Could not complete the repair<br/> Stay within 3 meters of the target and do not drop your tools</t>"; 
								hintSilent parseText _errortxt0;
							}; 
							private _display = findDisplay 6969;
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsMeching",false,true];
							closeDialog 0;
						},
						[_term, _user, _origin, _error]
					] call CBA_fnc_progressBar;;
				};
			}
		];
	};
	private _button1611 = _display displayCtrl 1611;
	_button1611 setVariable ["FST_RepairData", [_term, _user, _origin, _error]];
	_button1611 ctrlAddEventHandler 
	[
		"ButtonClick",
		{
			params ["_control"];
			private _repairData = _control getVariable "FST_RepairData";
			_repairData params ["_term", "_user", "_origin", "_error"];
			private _esctxt0 = "<t color='#d67e09'>Repair cancelled</t>";
			hintSilent parseText _esctxt0;
			_term setVariable ["FST_DeviceInUse",false,true];
			_user setVariable ["FST_PlayerIsMeching",false,true];
			closeDialog 2;
		}
	];
};

if (_term getVariable ["FST_DeviceLocked", false]) exitWith {_text = "<t color='#990000'>This device has locked down and cannot be hacked again</t>"; hintSilent parseText _text;};
if (_term getVariable ["FST_DeviceHacked", false]) exitWith {_text = "<t color='#990000'>This device has already been hacked</t>"; hintSilent parseText _text;};
if (!("FST_Hacking_Datapad" in items _user) && handgunWeapon _user != "FST_Hacking_Datapad") exitWith {_text = "<t color='#990000'>You do not have a hacking datapad in your inventory</t>"; hintSilent parseText _text;};
if (handgunWeapon _user != "FST_Hacking_Datapad") exitWith {_text = "<t color='#990000'>You do not have a hacking datapad equipped</t>"; hintSilent parseText _text;};
if (currentWeapon _user != "FST_Hacking_Datapad") exitWith {_text = "<t color='#990000'>You are not currently using your hacking datapad</t>"; hintSilent parseText _text;};
if (currentMagazine _user != "FST_HackDatacard_Empty") exitWith {_text = "<t color='#990000'>You need an empty datacard in your datapad to perform a download</t>"; hintSilent parseText _text;};
if (_user getVariable ["FST_PlayerIsHacking", false]) exitWith {_text = "<t color='#990000'>You are already hacking something else</t>"; hintSilent parseText _text;};

_term setVariable ["FST_DeviceInUse",true,true];
_user setVariable ["FST_PlayerIsHacking",true,true];

if (_term getVariable ["FST_DeviceAccessed", false]) exitWith 
{
	playSoundUI ["3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\dataprocess\datapadprocess1.ogg",4,1,true];
	[
		"DOWNLOADING ACCESSED DATA, STANDBY",
		15, 
		{
			params ["_arguments"];
			_arguments params ["_term", "_user"];
			_user distance _term <= 3 && currentWeapon _user == "FST_Hacking_Datapad" && currentMagazine _user == "FST_HackDatacard_Empty"
		},
		{
			params ["_arguments"];
			_arguments params ["_term", "_user"];
			_user removeHandgunItem "FST_HackDatacard_Empty";
			if ((_term getVariable ["FST_DiffPassed", 2]) == 2) then
			{
				_user addHandgunItem (selectRandomWeighted ["FST_HackDatacard_Abnormal", 4, "FST_HackDatacard_Normal", 4, "FST_HackDatacard_Corrupt", 4, "FST_HackDatacard_Virus", 4, "FST_HackDatacard_Troll", 4]); 
			};
			if ((_term getVariable ["FST_DiffPassed", 2]) == 6) then
			{
				_user addHandgunItem (selectRandomWeighted ["FST_HackDatacard_Abnormal", 14, "FST_HackDatacard_Normal", 3, "FST_HackDatacard_Corrupt", 1, "FST_HackDatacard_Virus", 1, "FST_HackDatacard_Troll", 1]); 
			};
			if ((_term getVariable ["FST_DiffPassed", 2]) == 10) then
			{
				_user addHandgunItem (selectRandomWeighted ["FST_HackDatacard_Abnormal", 19, "FST_HackDatacard_Troll", 1]); 
			};
			_term setVariable ["FST_DeviceHacked",true,true]; 
			_term setVariable ["FST_DeviceInUse",false,true]; 
			_user setVariable ["FST_PlayerIsHacking",false,true];
			hintSilent parseText "<t color='#0074cc'>Hack complete<br/> It is now safe to remove the datacard from your datapad</t>";
		},
		{
			params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
			_arguments params ["_term", "_user"]; 
			if (_failureCode == 1) then 
			{
				hintSilent parseText "<t color='#d67e09'>Download cancelled</t>";
			};
			if (_failureCode == 2) then 
			{
				hintSilent parseText "<t color='#990000'>Could not complete the download<br/> Stay within 3 meters of the target and do not swap your datapad or datacard out</t>";
			}; 
			_term setVariable ["FST_DeviceInUse",false,true];
			_user setVariable ["FST_PlayerIsHacking",false,true];
		},
		[_term, _user],
		false,
		false
	] call CBA_fnc_progressBar;
};
createDialog "FST_HackDeviceDisplay";
private _display = findDisplay 6970;
_display setVariable ["FST_HackingData", [_term, _user]];
{
	_x ctrlShow false;
} forEach 
[
	_display displayCtrl 1811,
	_display displayCtrl 1812,
	_display displayCtrl 1813,
	_display displayCtrl 1814,
	_display displayCtrl 1815,
	_display displayCtrl 1816,
	_display displayCtrl 1817,
	_display displayCtrl 1818,
	_display displayCtrl 1819,
	_display displayCtrl 1820,
	_display displayCtrl 1821,
	_display displayCtrl 1822,
	_display displayCtrl 1823,
	_display displayCtrl 1824,
	_display displayCtrl 1825,
	_display displayCtrl 1826,
	_display displayCtrl 1827,
	_display displayCtrl 1828,
	_display displayCtrl 1829,
	_display displayCtrl 1830,
	_display displayCtrl 1831,
	_display displayCtrl 1832,
	_display displayCtrl 1833,
	_display displayCtrl 1834,
	_display displayCtrl 1835,
	_display displayCtrl 1836,
	_display displayCtrl 6000,
	_display displayCtrl 6001
];
{
	_x ctrlShow false;
	_x ctrlSetText (selectRandom ["\41st_Civilians_and_Intel\Data\CircleIcon.paa","\41st_Civilians_and_Intel\Data\DiamondIcon.paa","\41st_Civilians_and_Intel\Data\SquareIcon.paa","\41st_Civilians_and_Intel\Data\TriangleIcon.paa","\41st_Civilians_and_Intel\Data\TriangleIcon2.paa"]);
} forEach 
[
	_display displayCtrl 1700,
	_display displayCtrl 1701,
	_display displayCtrl 1702,
	_display displayCtrl 1703,
	_display displayCtrl 1704,
	_display displayCtrl 1705,
	_display displayCtrl 1706,
	_display displayCtrl 1707,
	_display displayCtrl 1708,
	_display displayCtrl 1709,
	_display displayCtrl 1710,
	_display displayCtrl 1711,
	_display displayCtrl 1712,
	_display displayCtrl 1713,
	_display displayCtrl 1714,
	_display displayCtrl 1715,
	_display displayCtrl 1716,
	_display displayCtrl 1717,
	_display displayCtrl 1718,
	_display displayCtrl 1719,
	_display displayCtrl 1720,
	_display displayCtrl 1721,
	_display displayCtrl 1722,
	_display displayCtrl 1723,
	_display displayCtrl 1724,
	_display displayCtrl 1725,
	_display displayCtrl 1726,
	_display displayCtrl 1727,
	_display displayCtrl 1728,
	_display displayCtrl 1729,
	_display displayCtrl 1730,
	_display displayCtrl 1731,
	_display displayCtrl 1732,
	_display displayCtrl 1733,
	_display displayCtrl 1734,
	_display displayCtrl 1735,
	_display displayCtrl 1736,
	_display displayCtrl 1737,
	_display displayCtrl 1738,
	_display displayCtrl 1739,
	_display displayCtrl 1740,
	_display displayCtrl 1741,
	_display displayCtrl 1742,
	_display displayCtrl 1743,
	_display displayCtrl 1744,
	_display displayCtrl 1745,
	_display displayCtrl 1746,
	_display displayCtrl 1747,
	_display displayCtrl 1748,
	_display displayCtrl 1749,
	_display displayCtrl 1750,
	_display displayCtrl 1751,
	_display displayCtrl 1752,
	_display displayCtrl 1753,
	_display displayCtrl 1754,
	_display displayCtrl 1755,
	_display displayCtrl 1756,
	_display displayCtrl 1757,
	_display displayCtrl 1758,
	_display displayCtrl 1759,
	_display displayCtrl 1760,
	_display displayCtrl 1761,
	_display displayCtrl 1762,
	_display displayCtrl 1763,
	_display displayCtrl 1764,
	_display displayCtrl 1765,
	_display displayCtrl 1766,
	_display displayCtrl 1767,
	_display displayCtrl 1768,
	_display displayCtrl 1769,
	_display displayCtrl 1770,
	_display displayCtrl 1771,
	_display displayCtrl 1772,
	_display displayCtrl 1773,
	_display displayCtrl 1774,
	_display displayCtrl 1775,
	_display displayCtrl 1776,
	_display displayCtrl 1777,
	_display displayCtrl 1778,
	_display displayCtrl 1779,
	_display displayCtrl 1780
];
_display setVariable ["FST_TFARKeys", [["tfar", "NextRadio"] call CBA_fnc_getKeybind, ["tfar", "NextRadioSW"] call CBA_fnc_getKeybind]];
_display displayAddEventHandler
[
	"KeyDown",
	{
		params ["_display", "_key", "_shift", "_ctrl", "_alt"];
		private _hackingdata = _display getVariable "FST_HackingData";
		_hackingdata params ["_term", "_user"];
		private _keys = _display getVariable "FST_TFARKeys";
		private _srData = _keys select 0;
		private _lrData = _keys select 1;
		private _srkey =  (_srData select 0) select 0;
		private _srmods = [(_srData select 0) select 1, (_srData select 0) select 2, (_srData select 0) select 3];
		private _lrkey =  (_lrData select 0) select 0;
		private _lrmods = [(_lrData select 0) select 1, (_lrData select 0) select 2, (_lrData select 0) select 3];
		if (_key == _srkey && ((_srmods isEqualTo [false,false,false]) or ((_shift isEqualTo (_srmods select 0)) && (_ctrl isEqualTo (_srmods select 1)) && (_alt isEqualTo (_srmods select 2))))) then {
			if !(_user getVariable ["FST_SROn", false]) then {
				_user setVariable ["FST_SROn",true];
				[_user, false] call TFAR_fnc_processRadioOnKeyDown;
			};
		};
		if (_key == _lrkey && ((_lrmods isEqualTo [false,false,false]) or ((_shift isEqualTo (_lrmods select 0)) && (_ctrl isEqualTo (_lrmods select 1)) && (_alt isEqualTo (_lrmods select 2))))) then {
			if !(_user getVariable ["FST_LROn", false]) then {
				_user setVariable ["FST_LROn",true];
				[_user, true] call TFAR_fnc_processRadioOnKeyDown;
			};
		};
		if (_key in [1, 219, 220]) then 
		{
			hintSilent parseText "<t color='#d67e09'>Hack cancelled</t>";
			_term setVariable ["FST_DeviceInUse",false,true];
			_user setVariable ["FST_PlayerIsHacking",false,true];
		};
	}
];
_display displayAddEventHandler
[
	"KeyUp",
	{
		params ["_display", "_key"];
		private _hackingdata = _display getVariable "FST_HackingData";
		_hackingdata params ["_term", "_user"];
		private _srData = ["tfar", "NextRadio"] call CBA_fnc_getKeybind;
		private _lrData = ["tfar", "NextRadioSW"] call CBA_fnc_getKeybind;
		private _srkey =  (_srData select 0) select 0;
		private _lrkey =  (_lrData select 0) select 0;
		if (_key == _srkey) then {
			_user setVariable ["FST_SROn",false];
			[_user, false] call TFAR_fnc_processRadioOnKeyUp;
		};
		if (_key == _lrkey) then {
			_user setVariable ["FST_LROn",false];
			[_user, true] call TFAR_fnc_processRadioOnKeyUp;
		};
	}
];
private _button1903 = _display displayCtrl 1903;
_button1903 setVariable ["FST_HackingData", [_term, _user]];
_button1903 ctrlAddEventHandler 
[
	"ButtonClick",
	{
		params ["_control"];
		private _hackingdata = _control getVariable "FST_HackingData";
		_hackingdata params ["_term", "_user"];
		playsound (selectRandom ["3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick1.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick2.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick3.ogg"]);
		hintSilent parseText "<t color='#d67e09'>Hack cancelled</t>";
		_term setVariable ["FST_DeviceInUse",false,true];
		_user setVariable ["FST_PlayerIsHacking",false,true];
		closeDialog 2;
	}
];
private _button1900 = _display displayCtrl 1900;
_button1900 setVariable ["FST_HackingData", [_term, _user]];
_button1900 ctrlAddEventHandler 
[
	"ButtonClick",
	{
		
		params ["_control"];
		private _hackingData = _control getVariable "FST_HackingData";
		_hackingData params ["_term", "_user"];
		if ((_term getVariable ["FST_AttemptsLeft",3]) == 3) then {_term setVariable ["FST_AttemptsLeft",2,true];};
		playSoundUI [(selectRandom ["3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick1.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick2.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick3.ogg"]),4,1,true];
		private _display = findDisplay 6970;
		{
			_x ctrlShow false;
		} forEach 
		[
			_display displayCtrl 1802,
			_display displayCtrl 1807,
			_display displayCtrl 1808,
			_display displayCtrl 1809,
			_display displayCtrl 1810,
			_display displayCtrl 1900,
			_display displayCtrl 1901,
			_display displayCtrl 1902,
			_display displayCtrl 1903,
			_display displayCtrl 1904,
			_display displayCtrl 1905
		];
		{
			_x ctrlShow true;
		} forEach 
		[
			_display displayCtrl 1811,
			_display displayCtrl 1814,
			_display displayCtrl 1815,
			_display displayCtrl 1816,
			_display displayCtrl 1817,
			_display displayCtrl 1818,
			_display displayCtrl 1819,
			_display displayCtrl 1820,
			_display displayCtrl 1821,
			_display displayCtrl 1822,
			_display displayCtrl 1823,
			_display displayCtrl 1824,
			_display displayCtrl 1825,
			_display displayCtrl 1826,
			_display displayCtrl 1827,
			_display displayCtrl 1828,
			_display displayCtrl 1829,
			_display displayCtrl 1830,
			_display displayCtrl 1831,
			_display displayCtrl 1832
		];
		["FST_setGridRelations", [_display, 0]] call CBA_fnc_localEvent;
		["FST_setUpMinefieldGame", [_display, 0]] call CBA_fnc_localEvent;
		{
			_x ctrlShow true;
			["FST_initializeMinefieldButton", [_term, _user, _x, 2]] call CBA_fnc_localEvent;
		} forEach 
		[
			_display displayCtrl 1700,
			_display displayCtrl 1701,
			_display displayCtrl 1702,
			_display displayCtrl 1703,
			_display displayCtrl 1704,
			_display displayCtrl 1705,
			_display displayCtrl 1706,
			_display displayCtrl 1707,
			_display displayCtrl 1708,
			_display displayCtrl 1709,
			_display displayCtrl 1710,
			_display displayCtrl 1711,
			_display displayCtrl 1712,
			_display displayCtrl 1713,
			_display displayCtrl 1714,
			_display displayCtrl 1715,
			_display displayCtrl 1716,
			_display displayCtrl 1717,
			_display displayCtrl 1718,
			_display displayCtrl 1719,
			_display displayCtrl 1720,
			_display displayCtrl 1721,
			_display displayCtrl 1722,
			_display displayCtrl 1723,
			_display displayCtrl 1724
		];
		[
			"TIME UNTIL FAILSAFE DISCONNECT",
			120, 
			{
				params ["_arguments"];
				_arguments params ["_term", "_user"];
				!(_term getVariable ["FST_DeviceAccessed", false]) && _term getVariable ["FST_DeviceInUse", false] && !(_term getVariable ["FST_DeviceBroken", false]) && !(_term getVariable ["FST_DeviceLocked", false])
			},
			{
				params ["_arguments"];
				_arguments params ["_term", "_user"];
				hintSilent parseText "<t color='#990000'>Session terminated by timeout failsafe, another attempt is required</t>";
				_term setVariable ["FST_DeviceInUse",false,true];
				_user setVariable ["FST_PlayerIsHacking",false,true];
				closeDialog 0;
			},
			{
				params ["_arguments"];
				_arguments params ["_term", "_user"];
				_term setVariable ["FST_DeviceInUse",false,true]; 
				_user setVariable ["FST_PlayerIsHacking",false,true];
				if (_term getVariable ["FST_DeviceAccessed", false]) then 
				{
					playSoundUI ["3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\dataprocess\datapadprocess1.ogg",4,1,true];
					[
						"DOWNLOADING ACCESSED DATA, STANDBY",
						15, 
						{
							params ["_arguments"];
							_arguments params ["_term", "_user"];
							_user distance _term <= 3 && currentWeapon _user == "FST_Hacking_Datapad" && currentMagazine _user == "FST_HackDatacard_Empty"
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user"];
							_user removeHandgunItem "FST_HackDatacard_Empty";
							_user addHandgunItem (selectRandomWeighted ["FST_HackDatacard_Abnormal", 4, "FST_HackDatacard_Normal", 4, "FST_HackDatacard_Corrupt", 4, "FST_HackDatacard_Virus", 4, "FST_HackDatacard_Troll", 4]); 
							_term setVariable ["FST_DeviceHacked",true,true]; 
							_term setVariable ["FST_DeviceInUse",false,true]; 
							_user setVariable ["FST_PlayerIsHacking",false,true];
							hintSilent parseText "<t color='#0074cc'>Hack complete<br/> It is now safe to remove the datacard from your datapad</t>";
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user"]; 
							if (_failureCode == 1) then 
							{
								hintSilent parseText "<t color='#d67e09'>Download cancelled</t>";
							};
							if (_failureCode == 2) then 
							{
								hintSilent parseText "<t color='#990000'>Could not complete the download<br/> Stay within 3 meters of the target and do not swap your datapad or datacard out</t>";
							}; 
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsHacking",false,true];
						},
						[_term, _user],
						false,
						false
					] call CBA_fnc_progressBar;
				};
			},
			[_term, _user]
		] call CBA_fnc_progressBar;
	}
];
private _button1901 = _display displayCtrl 1901;
_button1901 setVariable ["FST_HackingData", [_term, _user]];
_button1901 ctrlAddEventHandler 
[
	"ButtonClick",
	{
		
		params ["_control"];
		private _hackingData = _control getVariable "FST_HackingData";
		_hackingData params ["_term", "_user"];
		if ((_term getVariable ["FST_AttemptsLeft",2]) > 1) then {_term setVariable ["FST_AttemptsLeft",1,true];};
		playSoundUI [(selectRandom ["3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick1.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick2.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick3.ogg"]),4,1,true];
		private _display = findDisplay 6970;
		{
			_x ctrlShow false;
		} forEach 
		[
			_display displayCtrl 1802,
			_display displayCtrl 1807,
			_display displayCtrl 1808,
			_display displayCtrl 1809,
			_display displayCtrl 1810,
			_display displayCtrl 1900,
			_display displayCtrl 1901,
			_display displayCtrl 1902,
			_display displayCtrl 1903,
			_display displayCtrl 1904,
			_display displayCtrl 1905
		];
		{
			_x ctrlShow true;
		} forEach 
		[
			_display displayCtrl 1812,
			_display displayCtrl 1814,
			_display displayCtrl 1815,
			_display displayCtrl 1816,
			_display displayCtrl 1817,
			_display displayCtrl 1818,
			_display displayCtrl 1819,
			_display displayCtrl 1820,
			_display displayCtrl 1821,
			_display displayCtrl 1822,
			_display displayCtrl 1823,
			_display displayCtrl 1824,
			_display displayCtrl 1825,
			_display displayCtrl 1826,
			_display displayCtrl 1827,
			_display displayCtrl 1828,
			_display displayCtrl 1829,
			_display displayCtrl 1830,
			_display displayCtrl 1831,
			_display displayCtrl 1832
		];
		["FST_setGridRelations", [_display, 1]] call CBA_fnc_localEvent;
		["FST_setUpMinefieldGame", [_display, 1]] call CBA_fnc_localEvent;
		{
			_x ctrlShow true;
			["FST_initializeMinefieldButton", [_term, _user, _x, 6]] call CBA_fnc_localEvent;
		} forEach 
		[
			_display displayCtrl 1700,
			_display displayCtrl 1701,
			_display displayCtrl 1702,
			_display displayCtrl 1703,
			_display displayCtrl 1704,
			_display displayCtrl 1705,
			_display displayCtrl 1706,
			_display displayCtrl 1707,
			_display displayCtrl 1708,
			_display displayCtrl 1709,
			_display displayCtrl 1710,
			_display displayCtrl 1711,
			_display displayCtrl 1712,
			_display displayCtrl 1713,
			_display displayCtrl 1714,
			_display displayCtrl 1715,
			_display displayCtrl 1716,
			_display displayCtrl 1717,
			_display displayCtrl 1718,
			_display displayCtrl 1719,
			_display displayCtrl 1720,
			_display displayCtrl 1721,
			_display displayCtrl 1722,
			_display displayCtrl 1723,
			_display displayCtrl 1724,
			_display displayCtrl 1725,
			_display displayCtrl 1726,
			_display displayCtrl 1727,
			_display displayCtrl 1728,
			_display displayCtrl 1729,
			_display displayCtrl 1730,
			_display displayCtrl 1731,
			_display displayCtrl 1732,
			_display displayCtrl 1733,
			_display displayCtrl 1734,
			_display displayCtrl 1735,
			_display displayCtrl 1736,
			_display displayCtrl 1737,
			_display displayCtrl 1738,
			_display displayCtrl 1739,
			_display displayCtrl 1740,
			_display displayCtrl 1741,
			_display displayCtrl 1742,
			_display displayCtrl 1743,
			_display displayCtrl 1744,
			_display displayCtrl 1745,
			_display displayCtrl 1746,
			_display displayCtrl 1747,
			_display displayCtrl 1748
		];
		[
			"TIME UNTIL FAILSAFE DISCONNECT",
			105, 
			{
				params ["_arguments"];
				_arguments params ["_term", "_user"];
				!(_term getVariable ["FST_DeviceAccessed", false]) && _term getVariable ["FST_DeviceInUse", false] && !(_term getVariable ["FST_DeviceBroken", false]) && !(_term getVariable ["FST_DeviceLocked", false])
			},
			{
				params ["_arguments"];
				_arguments params ["_term", "_user"];
				hintSilent parseText "<t color='#990000'>Session terminated by timeout failsafe, another attempt is required</t>";
				_term setVariable ["FST_DeviceInUse",false,true];
				_user setVariable ["FST_PlayerIsHacking",false,true];
				closeDialog 0;
			},
			{
				params ["_arguments"];
				_arguments params ["_term", "_user"];
				_term setVariable ["FST_DeviceInUse",false,true]; 
				_user setVariable ["FST_PlayerIsHacking",false,true];
				if (_term getVariable ["FST_DeviceAccessed", false]) then 
				{
					playSoundUI ["3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\dataprocess\datapadprocess1.ogg",4,1,true];
					[
						"DOWNLOADING ACCESSED DATA, STANDBY",
						15, 
						{
							params ["_arguments"];
							_arguments params ["_term", "_user"];
							_user distance _term <= 3 && currentWeapon _user == "FST_Hacking_Datapad" && currentMagazine _user == "FST_HackDatacard_Empty"
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user"];
							_user removeHandgunItem "FST_HackDatacard_Empty";
							_user addHandgunItem (selectRandomWeighted ["FST_HackDatacard_Abnormal", 14, "FST_HackDatacard_Normal", 3, "FST_HackDatacard_Corrupt", 1, "FST_HackDatacard_Virus", 1, "FST_HackDatacard_Troll", 1]); 
							_term setVariable ["FST_DeviceHacked",true,true]; 
							_term setVariable ["FST_DeviceInUse",false,true]; 
							_user setVariable ["FST_PlayerIsHacking",false,true];
							hintSilent parseText "<t color='#0074cc'>Hack complete<br/> It is now safe to remove the datacard from your datapad</t>";
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user"]; 
							if (_failureCode == 1) then 
							{
								hintSilent parseText "<t color='#d67e09'>Download cancelled</t>";
							};
							if (_failureCode == 2) then 
							{
								hintSilent parseText "<t color='#990000'>Could not complete the download<br/> Stay within 3 meters of the target and do not swap your datapad or datacard out</t>";
							}; 
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsHacking",false,true];
						},
						[_term, _user],
						false,
						false
					] call CBA_fnc_progressBar;
				};
			},
			[_term, _user]
		] call CBA_fnc_progressBar;
	}
];
private _button1902 = _display displayCtrl 1902;
_button1902 setVariable ["FST_HackingData", [_term, _user]];
_button1902 ctrlAddEventHandler 
[
	"ButtonClick",
	{
		
		params ["_control"];
		private _hackingData = _control getVariable "FST_HackingData";
		_hackingData params ["_term", "_user"];
		if ((_term getVariable ["FST_AttemptsLeft",2]) > 0) then {_term setVariable ["FST_AttemptsLeft",0,true];};
		playSoundUI [(selectRandom ["3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick1.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick2.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick3.ogg"]),4,1,true];
		private _display = findDisplay 6970;
		{
			_x ctrlShow false;
		} forEach 
		[
			_display displayCtrl 1802,
			_display displayCtrl 1807,
			_display displayCtrl 1808,
			_display displayCtrl 1809,
			_display displayCtrl 1810,
			_display displayCtrl 1900,
			_display displayCtrl 1901,
			_display displayCtrl 1902,
			_display displayCtrl 1903,
			_display displayCtrl 1904,
			_display displayCtrl 1905
		];
		{
			_x ctrlShow true;
		} forEach 
		[
			_display displayCtrl 1813,
			_display displayCtrl 1814,
			_display displayCtrl 1815,
			_display displayCtrl 1816,
			_display displayCtrl 1817,
			_display displayCtrl 1818,
			_display displayCtrl 1819,
			_display displayCtrl 1820,
			_display displayCtrl 1821,
			_display displayCtrl 1822,
			_display displayCtrl 1823,
			_display displayCtrl 1824,
			_display displayCtrl 1825,
			_display displayCtrl 1826,
			_display displayCtrl 1827,
			_display displayCtrl 1828,
			_display displayCtrl 1829,
			_display displayCtrl 1830,
			_display displayCtrl 1831,
			_display displayCtrl 1832
		];
		["FST_setGridRelations", [_display, 2]] call CBA_fnc_localEvent;
		["FST_setUpMinefieldGame", [_display, 2]] call CBA_fnc_localEvent;
		{
			_x ctrlShow true;
			["FST_initializeMinefieldButton", [_term, _user, _x, 10]] call CBA_fnc_localEvent;
		} forEach 
		[
			_display displayCtrl 1700,
			_display displayCtrl 1701,
			_display displayCtrl 1702,
			_display displayCtrl 1703,
			_display displayCtrl 1704,
			_display displayCtrl 1705,
			_display displayCtrl 1706,
			_display displayCtrl 1707,
			_display displayCtrl 1708,
			_display displayCtrl 1709,
			_display displayCtrl 1710,
			_display displayCtrl 1711,
			_display displayCtrl 1712,
			_display displayCtrl 1713,
			_display displayCtrl 1714,
			_display displayCtrl 1715,
			_display displayCtrl 1716,
			_display displayCtrl 1717,
			_display displayCtrl 1718,
			_display displayCtrl 1719,
			_display displayCtrl 1720,
			_display displayCtrl 1721,
			_display displayCtrl 1722,
			_display displayCtrl 1723,
			_display displayCtrl 1724,
			_display displayCtrl 1725,
			_display displayCtrl 1726,
			_display displayCtrl 1727,
			_display displayCtrl 1728,
			_display displayCtrl 1729,
			_display displayCtrl 1730,
			_display displayCtrl 1731,
			_display displayCtrl 1732,
			_display displayCtrl 1733,
			_display displayCtrl 1734,
			_display displayCtrl 1735,
			_display displayCtrl 1736,
			_display displayCtrl 1737,
			_display displayCtrl 1738,
			_display displayCtrl 1739,
			_display displayCtrl 1740,
			_display displayCtrl 1741,
			_display displayCtrl 1742,
			_display displayCtrl 1743,
			_display displayCtrl 1744,
			_display displayCtrl 1745,
			_display displayCtrl 1746,
			_display displayCtrl 1747,
			_display displayCtrl 1748,
			_display displayCtrl 1749,
			_display displayCtrl 1750,
			_display displayCtrl 1751,
			_display displayCtrl 1752,
			_display displayCtrl 1753,
			_display displayCtrl 1754,
			_display displayCtrl 1755,
			_display displayCtrl 1756,
			_display displayCtrl 1757,
			_display displayCtrl 1758,
			_display displayCtrl 1759,
			_display displayCtrl 1760,
			_display displayCtrl 1761,
			_display displayCtrl 1762,
			_display displayCtrl 1763,
			_display displayCtrl 1764,
			_display displayCtrl 1765,
			_display displayCtrl 1766,
			_display displayCtrl 1767,
			_display displayCtrl 1768,
			_display displayCtrl 1769,
			_display displayCtrl 1770,
			_display displayCtrl 1771,
			_display displayCtrl 1772,
			_display displayCtrl 1773,
			_display displayCtrl 1774,
			_display displayCtrl 1775,
			_display displayCtrl 1776,
			_display displayCtrl 1777,
			_display displayCtrl 1778,
			_display displayCtrl 1779,
			_display displayCtrl 1780
		];
		[
			"TIME UNTIL FAILSAFE DISCONNECT",
			90, 
			{
				params ["_arguments"];
				_arguments params ["_term", "_user"];
				!(_term getVariable ["FST_DeviceAccessed", false]) && _term getVariable ["FST_DeviceInUse", false] && !(_term getVariable ["FST_DeviceBroken", false]) && !(_term getVariable ["FST_DeviceLocked", false])
			},
			{
				params ["_arguments"];
				_arguments params ["_term", "_user"];
				hintSilent parseText "<t color='#990000'>Session terminated by timeout failsafe, another attempt is required</t>";
				_term setVariable ["FST_DeviceInUse",false,true];
				_user setVariable ["FST_PlayerIsHacking",false,true];
				closeDialog 0;
			},
			{
				params ["_arguments"];
				_arguments params ["_term", "_user"];
				_term setVariable ["FST_DeviceInUse",false,true]; 
				_user setVariable ["FST_PlayerIsHacking",false,true];
				if (_term getVariable ["FST_DeviceAccessed", false]) then 
				{
					playSoundUI ["3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\dataprocess\datapadprocess1.ogg",4,1,true];
					[
						"DOWNLOADING ACCESSED DATA, STANDBY",
						15, 
						{
							params ["_arguments"];
							_arguments params ["_term", "_user"];
							_user distance _term <= 3 && currentWeapon _user == "FST_Hacking_Datapad" && currentMagazine _user == "FST_HackDatacard_Empty"
						},
						{
							params ["_arguments"];
							_arguments params ["_term", "_user"];
							_user removeHandgunItem "FST_HackDatacard_Empty";
							_user addHandgunItem (selectRandomWeighted ["FST_HackDatacard_Abnormal", 19, "FST_HackDatacard_Troll", 1]); 
							_term setVariable ["FST_DeviceHacked",true,true]; 
							_term setVariable ["FST_DeviceInUse",false,true]; 
							_user setVariable ["FST_PlayerIsHacking",false,true];
							hintSilent parseText "<t color='#0074cc'>Hack complete<br/> It is now safe to remove the datacard from your datapad</t>";
						},
						{
							params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
							_arguments params ["_term", "_user"]; 
							if (_failureCode == 1) then 
							{
								hintSilent parseText "<t color='#d67e09'>Download cancelled</t>";
							};
							if (_failureCode == 2) then 
							{
								hintSilent parseText "<t color='#990000'>Could not complete the download<br/> Stay within 3 meters of the target and do not swap your datapad or datacard out</t>";
							}; 
							_term setVariable ["FST_DeviceInUse",false,true];
							_user setVariable ["FST_PlayerIsHacking",false,true];
						},
						[_term, _user],
						false,
						false
					] call CBA_fnc_progressBar;
				};
			},
			[_term, _user]
		] call CBA_fnc_progressBar;
	}
];