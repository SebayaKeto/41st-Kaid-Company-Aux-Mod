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

		private _ammoConfig =
			configFile >> "CfgAmmo" >> _ammoClass;

		private _isFSTBlaster =
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
			_sparks spawn
			{
				params ["_source"];
				sleep 0.2;
				if (!isNull _source) then
				{
					deleteVehicle _source;
				};
			};
		};
	};
}
forEach _this;