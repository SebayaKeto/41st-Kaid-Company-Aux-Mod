
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
			private _outcome = 6;
			if (_term getVariable ["FST_DeviceAssessed", false]) then
			{
				private _outcomearray = [0, 4, 1, 4, 2, 4, 3, 4, 4, 4]; 
				_outcome = selectRandomWeighted _outcomearray;
			} else
			{
				private _outcomearray = [0, 3, 1, 3, 2, 3, 3, 3, 4, 3, 5, 5]; 
				_outcome = selectRandomWeighted _outcomearray;
				_term setVariable ["FST_DeviceAssessed", true, true];
			};
			if ( _outcome == 5) then
			{
				private _itfucked = "<t color='#990000'>The device is beyond your ability to repair</t>"; 
				hintSilent parseText _itfucked;
				_term setVariable ["FST_DeviceFullBroken",true,true];
				_term setVariable ["FST_DeviceInUse",false,true];
				_user setVariable ["FST_PlayerIsMeching",false,true];
			};
			if ( _outcome == 4) then
			{
				[
					"PERFORMING PERCUSSIVE MAINTENANCE...",
					3, 
					{
						params ["_arguments"];
						_arguments params ["_term", "_user", "_origin"];
						_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
					},
					{
						params ["_arguments"];
						_arguments params ["_term", "_user", "_origin"];
						private _failarray = [0, 10, 1, 10];
						private _checkfail = selectRandomWeighted _failarray;
						if ( _checkfail == 0) then
						{
							_term setVariable ["FST_DeviceBroken",false,true]; 
							_term setVariable ["FST_DeviceInUse",false,true]; 
							_term setVariable ["FST_DeviceAssessed", false, true];
							_user setVariable ["FST_PlayerIsMeching",false,true]; 
							_term removeAction _origin;
							_term addAction ['Hack Device', {[_this select 0, _this select 1, _this select 2] call FST_CivilRandomizers_fnc_hackingterminal;}, nil,6,true,true,"","true",3];
							private _didit = "<t color='#0074cc'>You got it working<br/>You may attempt to hack again</t>"; 
							hintSilent parseText _didit;
						};
						if ( _checkfail == 1) then
						{
							_term setVariable ["FST_DeviceFullBroken",true,true]; 
							_term setVariable ["FST_DeviceInUse",false,true]; 
							_user setVariable ["FST_PlayerIsMeching",false,true]; 
							private _oops = "<t color='#990000'>You completely broke the device</t>"; 
							hintSilent parseText _oops;
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
					},
					[_term, _user, _origin]
				] call CBA_fnc_progressBar;
			};
			if ( _outcome == 3) then
			{
				[
					"REPAIRING BROKEN DATALINK...",
					10, 
					{
						params ["_arguments"];
						_arguments params ["_term", "_user", "_origin"];
						_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
					},
					{
						params ["_arguments"];
						_arguments params ["_term", "_user", "_origin"];
						private _failarray = [0, 18, 1, 2];
						private _checkfail = selectRandomWeighted _failarray;
						if ( _checkfail == 0) then
						{
							_term setVariable ["FST_DeviceBroken",false,true]; 
							_term setVariable ["FST_DeviceInUse",false,true]; 
							_term setVariable ["FST_DeviceAssessed", false, true];
							_user setVariable ["FST_PlayerIsMeching",false,true]; 
							_term removeAction _origin;
							_term addAction ['Hack Device', {[_this select 0, _this select 1, _this select 2] call FST_CivilRandomizers_fnc_hackingterminal;}, nil,6,true,true,"","true",3];
							private _didit = "<t color='#0074cc'>Damage repaired<br/>You may attempt to hack again</t>"; 
							hintSilent parseText _didit;
						};
						if ( _checkfail == 1) then
						{
							_term setVariable ["FST_DeviceFullBroken",true,true]; 
							_term setVariable ["FST_DeviceInUse",false,true]; 
							_user setVariable ["FST_PlayerIsMeching",false,true]; 
							private _oops = "<t color='#990000'>You made a mistake in your repair and completely broke the device</t>"; 
							hintSilent parseText _oops;
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
					},
					[_term, _user, _origin]
				] call CBA_fnc_progressBar;
			};
			if ( _outcome == 2) then
			{
				[
					"BYPASSING DAMAGED CIRCUITS...",
					12, 
					{
						params ["_arguments"];
						_arguments params ["_term", "_user", "_origin"];
						_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
					},
					{
						params ["_arguments"];
						_arguments params ["_term", "_user", "_origin"];
						private _failarray = [0, 15, 1, 5];
						private _checkfail = selectRandomWeighted _failarray;
						if ( _checkfail == 0) then
						{
							_term setVariable ["FST_DeviceBroken",false,true]; 
							_term setVariable ["FST_DeviceInUse",false,true]; 
							_term setVariable ["FST_DeviceAssessed", false, true];
							_user setVariable ["FST_PlayerIsMeching",false,true]; 
							_term removeAction _origin;
							_term addAction ['Hack Device', {[_this select 0, _this select 1, _this select 2] call FST_CivilRandomizers_fnc_hackingterminal;}, nil,6,true,true,"","true",3];
							private _didit = "<t color='#0074cc'>Damage bypassed<br/>You may attempt to hack again</t>"; 
							hintSilent parseText _didit;
						};
						if ( _checkfail == 1) then
						{
							_term setVariable ["FST_DeviceFullBroken",true,true]; 
							_term setVariable ["FST_DeviceInUse",false,true]; 
							_user setVariable ["FST_PlayerIsMeching",false,true]; 
							private _oops = "<t color='#990000'>You made a mistake in your repair and completely broke the device</t>"; 
							hintSilent parseText _oops;
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
					},
					[_term, _user, _origin]
				] call CBA_fnc_progressBar;
			};
			if ( _outcome == 1) then
			{
				[
					"REPLACING BURNT CAPACITORS...",
					14, 
					{
						params ["_arguments"];
						_arguments params ["_term", "_user", "_origin"];
						_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
					},
					{
						params ["_arguments"];
						_arguments params ["_term", "_user", "_origin"];
						private _failarray = [0, 19, 1, 1];
						private _checkfail = selectRandomWeighted _failarray;
						if ( _checkfail == 0) then
						{
							_term setVariable ["FST_DeviceBroken",false,true]; 
							_term setVariable ["FST_DeviceInUse",false,true]; 
							_term setVariable ["FST_DeviceAssessed", false, true];
							_user setVariable ["FST_PlayerIsMeching",false,true]; 
							_term removeAction _origin;
							_term addAction ['Hack Device', {[_this select 0, _this select 1, _this select 2] call FST_CivilRandomizers_fnc_hackingterminal;}, nil,6,true,true,"","true",3];
							private _didit = "<t color='#0074cc'>Damage repaired<br/>You may attempt to hack again</t>"; 
							hintSilent parseText _didit;
						};
						if ( _checkfail == 1) then
						{
							_term setVariable ["FST_DeviceFullBroken",true,true]; 
							_term setVariable ["FST_DeviceInUse",false,true]; 
							_user setVariable ["FST_PlayerIsMeching",false,true]; 
							private _oops = "<t color='#990000'>You made a mistake in your repair and completely broke the device</t>"; 
							hintSilent parseText _oops;
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
					},
					[_term, _user, _origin]
				] call CBA_fnc_progressBar;
			};
			if ( _outcome == 0) then
			{
				[
					"HOTWIRING COMPONENTS...",
					14, 
					{
						params ["_arguments"];
						_arguments params ["_term", "_user", "_origin"];
						_user distance _term <= 3 && (("FST_LargeToolkit" in items _user) or ("FST_SmallToolkit" in items _user))
					},
					{
						params ["_arguments"];
						_arguments params ["_term", "_user", "_origin"];
						private _failarray = [0, 12, 1, 8];
						private _checkfail = selectRandomWeighted _failarray;
						if ( _checkfail == 0) then
						{
							_term setVariable ["FST_DeviceBroken",false,true]; 
							_term setVariable ["FST_DeviceInUse",false,true]; 
							_term setVariable ["FST_DeviceAssessed", false, true];
							_user setVariable ["FST_PlayerIsMeching",false,true]; 
							_term removeAction _origin;
							_term addAction ['Hack Device', {[_this select 0, _this select 1, _this select 2] call FST_CivilRandomizers_fnc_hackingterminal;}, nil,6,true,true,"","true",3];
							private _didit = "<t color='#0074cc'>Damage bypassed<br/>You may attempt to hack again</t>"; 
							hintSilent parseText _didit;
						};
						if ( _checkfail == 1) then
						{
							_term setVariable ["FST_DeviceFullBroken",true,true]; 
							_term setVariable ["FST_DeviceInUse",false,true]; 
							_user setVariable ["FST_PlayerIsMeching",false,true]; 
							private _oops = "<t color='#990000'>You made a mistake in your repair and completely broke the device</t>"; 
							hintSilent parseText _oops;
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
					},
					[_term, _user, _origin]
				] call CBA_fnc_progressBar;
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
		},
		[_term, _user, _origin]
	] call CBA_fnc_progressBar;
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

[
	"HACKING TARGET...",
	10,
	{
		params ["_arguments"];
		_arguments params ["_term", "_user", "_origin"];
		_user distance _term <= 3 && currentWeapon _user == "FST_Hacking_Datapad" && currentMagazine _user == "FST_HackDatacard_Empty"
	},
	{
		params ["_arguments"];
		_arguments params ["_term", "_user", "_origin"];
		private _hackarray = [0, 10, 1, 6, 2, 3, 3, 1];
		private _hackoutcome = selectRandomWeighted _hackarray;
		if (_hackoutcome == 3) then 
		{
			_term setVariable ["FST_DeviceLocked",true,true]; 
			_term setVariable ["FST_DeviceInUse",false,true]; 
			_user setVariable ["FST_PlayerIsHacking",false,true]; 
			private _locktxt = "<t color='#990000'>The target device detected the hacking attempt and has locked down</t>"; 
			hintSilent parseText _locktxt;
		}; 
		if (_hackoutcome == 2) then 
		{
			_term setVariable ["FST_DeviceBroken",true,true];
			_term setVariable ["FST_DeviceInUse",false,true];
			_user setVariable ["FST_PlayerIsHacking",false,true]; 
			_term removeAction _origin;
			_term addAction ['Repair Device', {[_this select 0, _this select 1, _this select 2] call FST_CivilRandomizers_fnc_hackingterminal;}, nil,6,true,true,"","true",3];
			private _deadtxt = "<t color='#990000'>You failed the hack and damaged the target device in the proccess<br/>It will require repairs to try again</t>"; 
			hintSilent parseText _deadtxt;
		}; 
		if (_hackoutcome == 1) then 
		{
			_term setVariable ["FST_DeviceInUse",false,true];
			_user setVariable ["FST_PlayerIsHacking",false,true]; 
			private _failtxt = "<t color='#d67e09'>You failed to get into the target device<br/> Another attempt is required</t>"; 
			hintSilent parseText _failtxt;
		};
		if (_hackoutcome == 0) then 
		{
			[
				"ATTEMPTING TO EXTRACT DATA...",
				15, 
				{
					params ["_arguments"];
					_arguments params ["_term", "_user", "_origin"];
					_user distance _term <= 3 && currentWeapon _user == "FST_Hacking_Datapad" && currentMagazine _user == "FST_HackDatacard_Empty"
				},
				{
					params ["_arguments"];
					_arguments params ["_term", "_user", "_origin"];
					private _dataarray = ["FST_HackDatacard_Abnormal", 10, "FST_HackDatacard_Normal", 4, "FST_HackDatacard_Corrupt", 2, "FST_HackDatacard_Virus", 2, "FST_HackDatacard_Troll", 2]; 
					private _data = selectRandomWeighted _dataarray;
					_user removeHandgunItem "FST_HackDatacard_Empty"; 
					_user addHandgunItem _data; 
					_term setVariable ["FST_DeviceHacked",true,true]; 
					_term setVariable ["FST_DeviceInUse",false,true]; 
					_user setVariable ["FST_PlayerIsHacking",false,true]; 
					private _didit = "<t color='#0074cc'>Hack complete<br/> It is now safe to remove the datacard from your datapad</t>"; 
					hintSilent parseText _didit;
				},
				{
					params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
					_arguments params ["_term", "_user", "_origin"]; 
					if (_failureCode == 1) then 
					{
						private _esctxt0 = "<t color='#d67e09'>Download cancelled</t>";
						hintSilent parseText _esctxt0;
					};
					if (_failureCode == 2) then 
					{
						private _errortxt0 = "<t color='#990000'>Could not complete the download<br/> Stay within 3 meters of the target and do not swap your datapad or datacard out</t>"; 
						hintSilent parseText _errortxt0;
					}; 
					_term setVariable ["FST_DeviceInUse",false,true];
					_user setVariable ["FST_PlayerIsHacking",false,true];
				},
				[_term, _user, _origin],
				false,
				false
			] call CBA_fnc_progressBar;
		};
	},
	{
		params ["_arguments", "_success", "_elapsedTime", "_totalTime", "_failureCode"];
		_arguments params ["_term", "_user", "_origin"]; 
		if (_failureCode == 1) then 
		{
			private _esctxt1 = "<t color='#d67e09'>Hack cancelled</t>";
			hintSilent parseText _esctxt1;
		};
		if (_failureCode == 2) then 
		{
			private _errortxt1 = "<t color='#990000'>You disrupted the hack<br/> Stay within 3 meters of the target and do not swap your datapad or datacard out</t>";
			hintSilent parseText _errortxt1;
		};
		_term setVariable ["FST_DeviceInUse",false,true];
		_user setVariable ["FST_PlayerIsHacking",false,true];
	},
	[_term, _user, _origin],
	false,
	false
] call CBA_fnc_progressBar;


