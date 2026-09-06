// Distance-based Umbara prop streaming — one budget-limited slice per frame
// Client-side, one shared loop for every Swap module's candidates.
// Spatial-grid active-set design — see README.md "Sustained FPS drop" for
// the full history/reasoning.

#define GRID_CELL_SIZE 250
#define CANDIDATES_PER_TICK 3000
#define PROPS_CREATED_PER_TICK 40

if (isNull player) exitWith {};
if (isNil "UMBARA_STREAM_CANDIDATES") exitWith {};
if (isNil "UMBARA_STREAM_GRID") exitWith {};

private _nearDensity = missionNamespace getVariable ["UMBARA_Stream_NearDensity", 1];
private _midDensity = missionNamespace getVariable ["UMBARA_Stream_MidDensity", 0.5];
private _nearCutoff = missionNamespace getVariable ["UMBARA_Stream_NearCutoff", 1500];
private _midCutoff = missionNamespace getVariable ["UMBARA_Stream_MidCutoff", 2500];
private _farCutoff = missionNamespace getVariable ["UMBARA_Stream_FarCutoff", 6000];

private _exclusions = if (isNil "UMBARA_ACTIVE_EXCLUSIONS") then {[]} else {UMBARA_ACTIVE_EXCLUSIONS};

private _pPos = getPosATL player;
private _px = _pPos select 0;
private _py = _pPos select 1;

private _pcx = floor (_px / GRID_CELL_SIZE);
private _pcy = floor (_py / GRID_CELL_SIZE);
private _playerCellKey = (_pcx * 100000) + _pcy;

if (isNil "UMBARA_StreamActiveCellKeys") then {UMBARA_StreamActiveCellKeys = [];};
if (isNil "UMBARA_StreamActiveIndices") then {UMBARA_StreamActiveIndices = [];};
if (isNil "UMBARA_StreamActiveCursor") then {UMBARA_StreamActiveCursor = 0;};

// Recompute trigger: player crossed a cell, or Far Cutoff changed
private _forceRecompute = isNil "UMBARA_StreamLastPlayerCellKey" || {_farCutoff != (missionNamespace getVariable ["UMBARA_StreamLastFarCutoff", -1])};
UMBARA_StreamLastFarCutoff = _farCutoff;

// Deactivates one candidate by index, if currently active
private _fnDeactivate = {
	params ["_idx"];
	private _c = UMBARA_STREAM_CANDIDATES select _idx;
	private _activeObj = _c select 5;
	if (!(isNull _activeObj)) then {
		deleteVehicle _activeObj;
		_c set [5, objNull];
	};
};

if (_forceRecompute || {_playerCellKey != UMBARA_StreamLastPlayerCellKey}) then {
	// Active-set rebuild
	UMBARA_StreamLastPlayerCellKey = _playerCellKey;

	private _radiusCells = ceil (_farCutoff / GRID_CELL_SIZE) + 1;
	private _newCellKeys = [];
	private _newIndices = [];

	for "_dgx" from (-_radiusCells) to _radiusCells do {
		for "_dgy" from (-_radiusCells) to _radiusCells do {
			private _gcx = _pcx + _dgx;
			private _gcy = _pcy + _dgy;
			// Circular prune: closest point in cell's bbox vs Far Cutoff
			private _cellMinX = _gcx * GRID_CELL_SIZE;
			private _cellMinY = _gcy * GRID_CELL_SIZE;
			private _closestX = (_px max _cellMinX) min (_cellMinX + GRID_CELL_SIZE);
			private _closestY = (_py max _cellMinY) min (_cellMinY + GRID_CELL_SIZE);
			if ((((_closestX - _px)^2) + ((_closestY - _py)^2)) <= (_farCutoff^2)) then {
				private _key = (_gcx * 100000) + _gcy;
				private _list = UMBARA_STREAM_GRID getOrDefault [_key, []];
				if ((count _list) > 0) then {
					_newCellKeys pushBack _key;
					_newIndices append _list;
				};
			};
		};
	};

	// Sweep cells that dropped out of range
	private _exitingCellKeys = UMBARA_StreamActiveCellKeys - _newCellKeys;
	{
		private _list = UMBARA_STREAM_GRID getOrDefault [_x, []];
		{[_x] call _fnDeactivate;} forEach _list;
	} forEach _exitingCellKeys;

	UMBARA_StreamActiveCellKeys = _newCellKeys;
	UMBARA_StreamActiveIndices = _newIndices;
	UMBARA_StreamActiveCursor = 0;
};

private _total = count UMBARA_StreamActiveIndices;
if (_total == 0) exitWith {};
if (UMBARA_StreamActiveCursor >= _total) then {UMBARA_StreamActiveCursor = 0;};

// Budgeted create/destroy pass
private _count = 0;
private _created = 0;
while {_count < CANDIDATES_PER_TICK && {_created < PROPS_CREATED_PER_TICK} && {UMBARA_StreamActiveCursor < _total}} do {
	private _candIdx = UMBARA_StreamActiveIndices select UMBARA_StreamActiveCursor;
	private _cand = UMBARA_STREAM_CANDIDATES select _candIdx;
	_cand params ["_ox", "_oy", "_cls", "_dir", "_rank", "_activeObj", ["_placedIdx", -1]];

	private _dx = _ox - _px;
	private _dy = _oy - _py;
	private _dist = sqrt ((_dx * _dx) + (_dy * _dy));

	private _density = 0;
	if (_dist <= _nearCutoff) then {
		_density = _nearDensity;
	} else {
		if (_dist <= _midCutoff) then {
			_density = _midDensity;
		} else {
			if (_dist <= _farCutoff) then {
				_density = _midDensity * (1 - ((_dist - _midCutoff) / (_farCutoff - _midCutoff)));
			};
		};
	};

	private _excluded = false;
	if (_density > 0) then {
		{
			_x params ["_ecx0", "_ecy0", "_ea", "_eb", "_eangle", "_eisRect"];
			if ([_ox, _oy, _ecx0, _ecy0, _ea, _eb, _eangle, _eisRect] call umbara_trees_fnc_pointInArea) exitWith {_excluded = true;};
		} forEach _exclusions;
	};

	private _shouldBeActive = !_excluded && {_rank <= _density};
	private _isActive = !(isNull _activeObj);

	if (_shouldBeActive && !_isActive) then {
		private _objPosASL = [_ox, _oy, (getTerrainHeightASL [_ox, _oy])];
		private _newObj = createSimpleObject [_cls, _objPosASL, true];
		_newObj setDir _dir;
		_newObj setVectorUp (surfaceNormal [_ox, _oy, 0]);
		_cand set [5, _newObj];
		if (isNil "UMBARA_PLACED_PROPS") then {UMBARA_PLACED_PROPS = [];};
		// Reuse this candidate's own PLACED_PROPS slot if it has one
		if (_placedIdx < 0) then {
			_placedIdx = count UMBARA_PLACED_PROPS;
			UMBARA_PLACED_PROPS pushBack _newObj;
			_cand set [6, _placedIdx];
		} else {
			UMBARA_PLACED_PROPS set [_placedIdx, _newObj];
		};
		_created = _created + 1;
	};
	if (!_shouldBeActive && _isActive) then {
		deleteVehicle _activeObj;
		_cand set [5, objNull];
	};

	UMBARA_StreamActiveCursor = UMBARA_StreamActiveCursor + 1;
	_count = _count + 1;
};
