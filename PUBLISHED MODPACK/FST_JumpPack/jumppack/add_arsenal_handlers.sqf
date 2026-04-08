

//detach arsenal open/close
[missionNamespace,"arsenalClosed", {
	player call FST_jumppack_fnc_arsenal_closed;

}] call bis_fnc_addScriptedEventhandler;

["ACE_arsenal_displayClosed", {	
	player call FST_jumppack_fnc_arsenal_closed;

}] call CBA_fnc_addEventHandler;


[missionNamespace,"arsenalOpened", {	
	player call FST_jumppack_fnc_arsenal_opened;

}] call bis_fnc_addScriptedEventhandler;

["ACE_arsenal_displayOpened", {	
	player call FST_jumppack_fnc_arsenal_opened;

}] call CBA_fnc_addEventHandler;