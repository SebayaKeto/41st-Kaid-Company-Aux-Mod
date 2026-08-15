// Perf fix: particle sparks only render on machines with a screen. Without
// this guard the dedicated server and HCs paid the config walk, the particle
// source and a scheduler thread for every AI-vs-AI blaster hit they can
// never display.
if (!hasInterface) exitWith {};

private _handled = false;
{
	if (!_handled) then
	{
		_x params
		[
			["_target", objNull],
			["_shooter", objNull],
			["_projectile", objNull],
			["_positionASL", [0, 0, 0]],
			["_velocity", [0, 0, 0]],
			["_selections", []],
			["_ammoData", []],
			["_surfaceNormal", [0, 0, 1]],
			["_radius", 0],
			["_surfaceType", ""],
			["_isDirect", false],
			["_instigator", objNull]
		];

		private _ammoClass =
			_ammoData param [4, ""];

		// Perf fix: the isKindOf/config verdict depends only on the ammo class,
		// but this handler fires per HIT. Cache per classname so sustained fire
		// costs one hashmap lookup instead of a config walk per impact.
		private _cache = missionNamespace getVariable "FST_ImpactSparksAmmoCache";
		if (isNil "_cache") then {
			_cache = createHashMap;
			missionNamespace setVariable ["FST_ImpactSparksAmmoCache", _cache];
		};
		private _isFSTBlaster = _cache get _ammoClass;
		if (isNil "_isFSTBlaster") then {
			private _ammoConfig =
				configFile >> "CfgAmmo" >> _ammoClass;
			_isFSTBlaster =
				_ammoClass != ""
				&& {isClass _ammoConfig}
				&&
				{
					_ammoClass isKindOf
					[
						"FST_blasterbolt",
						configFile >> "CfgAmmo"
					]
				};
			_cache set [_ammoClass, _isFSTBlaster];
		};

		if (_isDirect && _isFSTBlaster) then
		{
			_handled = true;
			private _normal =
				vectorNormalized _surfaceNormal;

			if (_normal isEqualTo [0, 0, 0]) then
			{
				_normal = [0, 0, 1];
			};
			private _effectPositionASL =
				_positionASL vectorAdd
					(_normal vectorMultiply 0.04);
			private _sparks =
				"#particlesource"
					createVehicleLocal [0, 0, 0];

			_sparks setPosASL _effectPositionASL;
			_sparks setParticleClass
				"FST_ImpactSparksPlasma1_Scripted";
			_sparks setDropInterval 0.012;
			// Perf fix: was `spawn { sleep 0.2; deleteVehicle }` -- one scheduler
			// thread per hit just to delete a particle source. waitAndExecute is
			// an unscheduled timer with no thread cost.
			[{
				params ["_source"];
				if (!isNull _source) then { deleteVehicle _source; };
			}, [_sparks], 0.2] call CBA_fnc_waitAndExecute;
		};
	};
}
forEach _this;