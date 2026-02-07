#include "\nsm_Main\_include\macros.hpp"

params["_unit"];

_attached_items=_unit getVariable ["NSM_jumppack_effects",[]];

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

_unit setVariable ["NSM_jumppack_effects",[],true];