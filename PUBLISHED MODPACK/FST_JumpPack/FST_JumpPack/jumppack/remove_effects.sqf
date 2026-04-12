

params["_unit"];

_attached_items=_unit getVariable ["FST_jumppack_effects",[]];

{
	detach  _x;
	deleteVehicle _x;
} forEach _attached_items;

{
	if((typeOf _x isEqualTo "#lightpoint") || (typeOf _x isEqualTo "#particlesource")) then
	{
	detach _x;
	deleteVehicle _x;
	};
	
} forEach attachedObjects _unit;

_unit setVariable ["FST_jumppack_effects",[],true];