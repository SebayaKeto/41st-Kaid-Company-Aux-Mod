if(isNull _this) exitWith {};

_this call {		//This is our function to enter 'ATRT'
	_unit = _this;
	_unit addAction
	[
		"Drive",	//Climb on ATRT
		{
			params ["_atrt", "_rider", "_actionId", "_arguments"];
			
			private _r = _atrt getVariable "rider";
			private _og = typeOf _rider;
			if (!(isNil "_r") OR (_og isEqualTo "FST_ATRT")) exitWith{}; //block multiple riders and stacking
			
			_atrt setVariable ["rider",_rider,true];
			_atrt allowDamage false;
			
			[_rider, "driver_Quadbike"] remoteExec ["switchMove", 0];	//put rider in seated animation
			_rider attachTo [_atrt, [0,0,0],"seat"];		//Attach the user to the ATRT, to simulate them being on it
			
			
			_shield ="FST_ATRT_Collision" createVehicle position _atrt;
			_shield attachTo [_atrt,[0.0,0.3,-2.3],"seat"];

			//Move the player "into" ATRT using the remoteControl function
			objNull remoteControl driver _rider;
			player remoteControl _atrt;
			
			//We have to switch the camera to the ATRT now
			//player switchCamera "External";
			if (cameraon != (vehicle _atrt)) then {
				(vehicle _atrt) switchcamera cameraview;
				_atrt enableStamina false;
				_atrt forceWalk false;
			};
			
			inGameUISetEventHandler ["Action", "if ((_this select 3) isEqualTo ""BackFromUAV"") then {true};"];
			//_isPlayer = (_this select 0) getVariable ""rider"" isEqualTo player;
			
			/*_atrtHP = _atrt getVariable ["atrt_hp",100];
			
			//register hits on ATRT
			atrt_hit = _atrt addEventHandler ["HandleDamage", {
				params ["_unit", "_selection", "_damage", "_source", "_projectile", "_hitIndex", "_instigator", "_hitPoint"];
				_atrtHP = _atrt getVariable ["atrt_hp",100];
				//hint str _atrtHP;
				_atrtHP = _atrtHP - _damage;
				//hint format ["HP: %1\nDam: %2",_atrtHP,_damage];
				_atrt setVariable ["atrt_hp",_atrtHP,false];
				0
			}]; */
			
			waitUntil {
				sleep 2;
				//_ko = _rider getVariable ["ACE_isUnconscious", false];
				private _expression = (!(alive _rider or alive player or "INCAPACITATED" == lifeState _rider) /*or !_ko) or (_atrtHP < 1)*/);
				!isNil "_expression" and {_expression}
			};
			
			//hint format ["%1 is KO",_rider];
			//same as dismount
			[_rider, ""] remoteExec ["switchMove", 0];
			detach _rider;
			objNull remoteControl driver _atrt;
			player remoteControl _rider;
			if (cameraon != (vehicle _rider)) then {(vehicle _rider) switchcamera cameraview;};
			//atrt_hit = nil;
			//atrt_zeus = nil;
			_atrt setVariable ["rider",nil,true];
			deleteVehicle _shield;
			_atrt allowDamage true;
			_atrt setDamage 1;
			inGameUISetEventHandler ["Action", ""];
		},
		[],
		1.5,
		true,
		true,
		"",
		"_this != _originalTarget", //To prevent multiple addactions
		4,
		false,
		"",
		""
	];
};
_this call {		//Function to add dismount
	_unit = _this;
	_unit addAction
	[
		"Dismount",
		{
			params ["_rider", "_atrt", "_actionId", "_arguments"];
			
			//atrt_hit = nil;
			//atrt_zeus = nil;
			
			_rider = _atrt getVariable "rider";	//Returns player to their original unit
			
			//dismount animation
			[_rider, ""] remoteExec ["switchMove", 0];
			detach _rider;
			objNull remoteControl driver _atrt;
			player remoteControl _rider;
			if (cameraon != (vehicle _rider)) then {(vehicle _rider) switchcamera cameraview;};
			
			deleteVehicle _shield;
			_atrt setVariable ["rider",nil,true];
			_atrt allowDamage true;
			inGameUISetEventHandler ["Action", ""];
		},
		nil,
		1.5,
		true,
		true,
		"",
		"_this == _originalTarget", //To prevent multiple addactions
		2,
		false,
		"",
		""
	];
};