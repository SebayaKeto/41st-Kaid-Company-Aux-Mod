// 41st main menu intro (runs inside the VR cutscene mission behind RscDisplayMain).
//
// Timeline problem this solves: the menu appears before the VR world and this
// mission are loaded, and once BIS_fnc_playVideo starts it shows a black
// backdrop until the Theora decoder has opened the file. Both gaps were visible
// as "empty background" before the video came up, and every loop restart showed
// a black flash. The menu display's background picture (idc 102, a solid black texture set in
// config.cpp) covers both gaps (the video opens from black anyway),
// is crossfaded out once the decoder is running, and faded back in just before
// each loop ends so the restart lands on the same frame.

#define VIDEO_PATH "41st_Menu\mainmenu.vr\videos\MenuBackground.ogv"
#define VIDEO_LENGTH 79.4
#define STILL_IDC 102
#define DECODER_WARMUP 1.5
#define CROSSFADE 1.0

enableEnvironment false;
showCinemaBorder false;

private _fnGetStill = {
	private _display = findDisplay 0;
	if (isNull _display) then { _display = uiNamespace getVariable ["RscDisplayMain", displayNull]; };
	if (isNull _display) then { controlNull } else { _display displayCtrl STILL_IDC };
};

while {true} do
{
	private _still = call _fnGetStill;
	if (!isNull _still) then { _still ctrlSetFade 0; _still ctrlCommit 0; };

	private _video = [VIDEO_PATH] spawn BIS_fnc_playVideo;
	private _started = time;

	// Let the decoder produce frames behind the still, then reveal the video.
	sleep DECODER_WARMUP;
	_still = call _fnGetStill;
	if (!isNull _still) then { _still ctrlSetFade 1; _still ctrlCommit CROSSFADE; };

	// Bring the still back just before the video ends so the loop restart is seamless.
	waitUntil { sleep 0.25; scriptDone _video || {(time - _started) >= (VIDEO_LENGTH - CROSSFADE)} };
	_still = call _fnGetStill;
	if (!isNull _still) then { _still ctrlSetFade 0; _still ctrlCommit CROSSFADE; };

	waitUntil { sleep 0.1; scriptDone _video };
};
