/*
	File:
		\41st_Ammo\functions\fn_impactSparks.sqf

	Purpose:
		Spawns the primary 3AS terrain spark cloudlet when
		FST blaster ammunition hits a CAManBase unit.
*/

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
			/*
				Prevent additional hit records from this same
				HitPart event call from creating another effect.
			*/
			_handled = true;

			private _normal =
				vectorNormalized _surfaceNormal;

			if (_normal isEqualTo [0, 0, 0]) then
			{
				_normal = [0, 0, 1];
			};

			/*
				Place the source four centimetres outside the
				character model so the sparks are not hidden
				inside its geometry.
			*/
			private _effectPositionASL =
				_positionASL vectorAdd
					(_normal vectorMultiply 0.04);

			/*
				Primary 3AS terrain spark shower.

				Only this emitter is used. The secondary emitter
				was making each impact appear doubled.
			*/
			private _sparks =
				"#particlesource"
					createVehicleLocal [0, 0, 0];

			_sparks setPosASL _effectPositionASL;

			_sparks setParticleClass
				"FST_ImpactSparksPlasma1_Scripted";

			/*
				Reduced scripted emission density.
			*/
			_sparks setDropInterval 0.012;

			/*
				Keep the source alive long enough for the engine
				to process the particle burst.
			*/
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