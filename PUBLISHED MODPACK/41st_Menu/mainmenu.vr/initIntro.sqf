cutText ["", "BLACK FADED", 69];
enableEnvironment false;
showCinemaBorder false;

while {true} do
{
	_video = ["41st_Menu\mainmenu.vr\videos\MenuBackground.ogv"] spawn BIS_fnc_playVideo;
	//_music = ["41st_Menu\mainmenu.altis\sounds\MMSSongStart.ogg", 10, 10] call BIS_fnc_playMusic;
	waitUntil {scriptDone _video};
};