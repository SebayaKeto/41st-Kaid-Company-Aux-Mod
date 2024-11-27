private ["_vic","_vicSpeed","_walkSpeed"];
private ["_animStart","_animStartLoop","_animEnd","_animEndLoop","_animStop"];

if (isServer) then 
{
	_vic = _this select 0;

	//Check to see if Vehicle is Null
	if (isNull _vic) exitWith {};

	while {alive _vic} do
	{
		while {isEngineOn _vic} do 
		{
			_vicSpeed = speed _vic; //Get Current Speed of Vehicle
			
			//Calculate Walk Speed
			_walkSpeed = 0.4;
			if (abs(_vicSpeed) >= 4) then
			{
				_walkSpeed = abs(_vicSpeed) / 16;
			};
			
			//Walk Forward
			if (_vicSpeed >= 0.5) then
			{
				_animStart = 0;
				_animStartLoop = 0.5;
				_animEndLoop = 1.5;
				_animEnd = 2;
				
				if (_vic animationSourcePhase "Walk" > _animEndLoop) then
				{
					_vic animateSource ["Walk",_animStartLoop,true];
					waitUntil {_vic animationSourcePhase "Walk" == _animStartLoop};
				};
				
				_vic animateSource ["Walk",_animEnd,_walkSpeed];
				//waitUntil {sleep 0.02; _vic animationSourcePhase "Walk" >= _animEndLoop};
			};
			
			//Walk Backwards
			if (_vicSpeed <= -0.5) then
			{
				_animStart = 2;
				_animStartLoop = 1.5;
				_animEndLoop = 0.5;
				_animEnd = 0;
				
				if (_vic animationSourcePhase "Walk" < _animEndLoop) then
				{
					_vic animateSource ["Walk",_animStartLoop,true];
					waitUntil {_vic animationSourcePhase "Walk" == _animStartLoop};
				};
				
				_vic animateSource ["Walk",_animEnd,_walkSpeed];
				//waitUntil {sleep 0.02; _vic animationSourcePhase "Walk" <= _animEndLoop};
			};
			
			if (abs(_vicSpeed) < 0.5) then
			{
				_animStop = round((_vic animationSourcePhase "Walk")*2)/2; //find closest standing animation (0, 0.5, 1, 1.5, 2)
				_vic animateSource ["Walk",_animStop,true];
				waitUntil {sleep 0.02; _vic animationSourcePhase "Walk" == _animStop};
			};
			
			//hint format ["S = %1, P = %2, W = %3", _vicSpeed, _vic animationSourcePhase "Walk", _walkSpeed];
			
		};
		
		sleep 1;	//Wait 1s while Engine is not on
		
	};
};