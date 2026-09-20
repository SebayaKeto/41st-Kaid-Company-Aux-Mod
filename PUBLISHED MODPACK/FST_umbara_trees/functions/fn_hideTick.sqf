// Continuous native-tree hide re-broadcast -- server-only
// See README "Native trees not hiding" for why this exists.
//
// Perf rewrite (2026-09-20). The old tick ran EVERY FRAME and, for each of up
// to 3000 trees per frame, called getPosATL on the tree and then getPosATL on
// every connected player (150 players x 3000 trees = 450k command calls per
// frame on the dedicated server). Now:
//  - tree positions are cached once (terrain objects never move),
//  - player positions are read once per tick and collapsed onto a 1 km grid,
//    so a platoon standing together costs one distance check, not 30,
//  - the tick runs on an interval (default 0.1 s, UMBARA_HideTickInterval) with
//    a per-tick budget (default 1500, UMBARA_HideCandidatesPerTick).
// Semantics are unchanged: every candidate tree within HIDE_BROADCAST_RADIUS of
// any player is periodically re-hidden with hideObjectGlobal.

#define HIDE_BROADCAST_RADIUS 6500
#define PLAYER_CELL_SIZE 1000

if (!isServer) exitWith {};
if (isNil "UMBARA_HIDE_CANDIDATES") exitWith {};

private _total = count UMBARA_HIDE_CANDIDATES;
if (_total == 0) exitWith {};

private _players = allPlayers;
if (count _players == 0) exitWith {};

// Tree position cache. The candidate list only ever grows (pushBack in
// fn_swapTick), so extend the cache for any new entries; rebuild if it shrank.
private _posCache = missionNamespace getVariable ["UMBARA_HIDE_POSITIONS", []];
if ((count _posCache) > _total) then { _posCache = []; };
if ((count _posCache) < _total) then {
	for "_i" from (count _posCache) to (_total - 1) do {
		private _t = UMBARA_HIDE_CANDIDATES select _i;
		if (isNull _t) then {
			_posCache pushBack [];
		} else {
			private _p = getPosATL _t;
			_posCache pushBack [_p select 0, _p select 1];
		};
	};
	missionNamespace setVariable ["UMBARA_HIDE_POSITIONS", _posCache];
};

// Player positions once per tick, deduplicated on a coarse grid.
private _cells = createHashMap;
private _playerXY = [];
{
	private _p = getPosATL _x;
	private _key = ((floor ((_p select 0) / PLAYER_CELL_SIZE)) * 100000) + (floor ((_p select 1) / PLAYER_CELL_SIZE));
	if (isNil {_cells get _key}) then {
		_cells set [_key, true];
		_playerXY pushBack [_p select 0, _p select 1];
	};
} forEach _players;

// Cell diagonal (~1415 m) added to the radius so collapsing players onto a
// cell representative can never miss a tree the old per-player check found.
private _radius = HIDE_BROADCAST_RADIUS + (PLAYER_CELL_SIZE * 1.4143);
private _radiusSq = _radius * _radius;

if (isNil "UMBARA_HideCursor") then {UMBARA_HideCursor = 0;};
if (UMBARA_HideCursor >= _total) then {UMBARA_HideCursor = 0;};

private _budget = missionNamespace getVariable ["UMBARA_HideCandidatesPerTick", 1500];
private _count = 0;
while {_count < _budget && {UMBARA_HideCursor < _total}} do {
	private _tp = _posCache select UMBARA_HideCursor;

	if ((count _tp) == 2) then {
		private _tx = _tp select 0;
		private _ty = _tp select 1;
		private _nearPlayer = false;
		{
			private _dx = (_x select 0) - _tx;
			private _dy = (_x select 1) - _ty;
			if ((_dx * _dx) + (_dy * _dy) <= _radiusSq) exitWith {_nearPlayer = true;};
		} forEach _playerXY;

		if (_nearPlayer) then {
			private _treeObj = UMBARA_HIDE_CANDIDATES select UMBARA_HideCursor;
			if (!isNull _treeObj) then {
				_treeObj hideObjectGlobal true;
			};
		};
	};

	UMBARA_HideCursor = UMBARA_HideCursor + 1;
	_count = _count + 1;
};
