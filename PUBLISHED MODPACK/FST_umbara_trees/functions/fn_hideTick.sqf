// Continuous native-tree hide re-broadcast — server-only
// See README "Native trees not hiding" for why this exists.

#define CANDIDATES_PER_TICK 3000
#define HIDE_BROADCAST_RADIUS 6500

if (!isServer) exitWith {};
if (isNil "UMBARA_HIDE_CANDIDATES") exitWith {};

private _total = count UMBARA_HIDE_CANDIDATES;
if (_total == 0) exitWith {};

private _players = allPlayers;
if (count _players == 0) exitWith {};

if (isNil "UMBARA_HideCursor") then {UMBARA_HideCursor = 0;};
if (UMBARA_HideCursor >= _total) then {UMBARA_HideCursor = 0;};

private _radiusSq = HIDE_BROADCAST_RADIUS * HIDE_BROADCAST_RADIUS;
private _count = 0;
while {_count < CANDIDATES_PER_TICK && {UMBARA_HideCursor < _total}} do {
	private _treeObj = UMBARA_HIDE_CANDIDATES select UMBARA_HideCursor;

	if (!isNull _treeObj) then {
		private _tPos = getPosATL _treeObj;
		private _tx = _tPos select 0;
		private _ty = _tPos select 1;

		private _nearPlayer = false;
		{
			private _pPos = getPosATL _x;
			private _dx = (_pPos select 0) - _tx;
			private _dy = (_pPos select 1) - _ty;
			if ((_dx * _dx) + (_dy * _dy) <= _radiusSq) exitWith {_nearPlayer = true;};
		} forEach _players;

		if (_nearPlayer) then {
			_treeObj hideObjectGlobal true;
		};
	};

	UMBARA_HideCursor = UMBARA_HideCursor + 1;
	_count = _count + 1;
};
