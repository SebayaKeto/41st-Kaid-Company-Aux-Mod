/*
    BUZZ_fnc_zvSelect
    Zeus context menu: "Show Trooper Details" -> radius. Runs only on the
    Zeus's own machine. Takes a snapshot of the players inside the circle
    right now; they stay tagged (through respawns) until the Zeus picks
    again or clears it.

    Params: 0: centre position <ARRAY>, 1: radius in metres <NUMBER>
*/
params ["_position", "_radius"];

private _players = (allPlayers - entities "HeadlessClient_F") select {
    alive _x && { _x distance2D _position <= _radius }
};

// Keep the UID so a respawned player (new unit object) stays tracked.
BUZZ_zv_trackAll = false;
BUZZ_zv_tracked = _players apply { [getPlayerUID _x, _x] };
BUZZ_zv_nextRefresh = 0;

private _label = if (_radius >= 1000) then { format ["%1 km", _radius / 1000] } else { format ["%1 m", _radius] };
[format ["Trooper details: %1 trooper(s) within %2", count _players, _label]] call zen_common_fnc_showMessage;
