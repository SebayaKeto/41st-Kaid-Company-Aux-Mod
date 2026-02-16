#include "\nsm_Main\_include\macros.hpp"

//detach arsenal open/close
[missionNamespace,"arsenalClosed", {
	ace_player call NSM_jumppack_fnc_arsenal_closed;

}] call bis_fnc_addScriptedEventhandler;

["ACE_arsenal_displayClosed", {	
	ace_player call NSM_jumppack_fnc_arsenal_closed;

}] call CBA_fnc_addEventHandler;


[missionNamespace,"arsenalOpened", {	
	ace_player call NSM_jumppack_fnc_arsenal_opened;

}] call bis_fnc_addScriptedEventhandler;

["ACE_arsenal_displayOpened", {	
	ace_player call NSM_jumppack_fnc_arsenal_opened;

}] call CBA_fnc_addEventHandler;