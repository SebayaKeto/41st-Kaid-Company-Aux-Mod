params ["_unit"];

if (isNull _unit) exitWith {};

private _attachedItems = _unit getVariable ["FST_jumppack_effects", []];

{
	if (!isNull _x) then {
		detach _x;
		deleteVehicle _x;
	};
} forEach _attachedItems;

// Fallback cleanup for old versions / interrupted effect scripts. Only scan
// attachedObjects when the unit actually had tracked jump-pack effects.
if ((count _attachedItems) > 0) then {
	{
		if ((typeOf _x isEqualTo "#lightpoint") || {typeOf _x isEqualTo "#particlesource"}) then {
			detach _x;
			deleteVehicle _x;
		};
	} forEach attachedObjects _unit;
};

_unit setVariable ["FST_jumppack_effects", []];
