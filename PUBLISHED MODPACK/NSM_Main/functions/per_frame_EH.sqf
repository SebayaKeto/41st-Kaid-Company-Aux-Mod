#include "\nsm_Main\_include\macros.hpp"

[
	{
		params["_args","_id"];
		[_args,_id] spawn NSM_jumppack_fnc_add_cba_per_frame;
	}
	, 0, [0]

] call CBA_fnc_addPerFrameHandler;