// Umbara Tree Swap — one frame's worth of discovery/placement work
// Shared by the real-run (CBA PFH) and Eden-preview (EachFrame) drivers.
// See README.md for full history/reasoning.

#define GRID_CELL_SIZE 250

params [
	"_logic", "_chunkList", "_queue", "_chunkSize", "_chunksPerFrame", "_batchSize",
	"_startTime", "_hideNative", "_replaceEveryNth", "_cx0", "_cy0", "_a", "_b", "_angle", "_isRect",
	"_isPreview", "_placedRef", "_hiddenRef", "_useCachedData", "_cachedData"
];

// Fresh area read
private _freshPos = getPosATL _logic;
_cx0 = _freshPos select 0;
_cy0 = _freshPos select 1;
private _freshPreviewRadius = _logic getVariable ["UMBARA_PreviewRadius", 150];
private _freshArea = _logic getVariable ["ObjectArea", [_freshPreviewRadius, _freshPreviewRadius, 0, false, -1]];
_a = _freshArea select 0;
_b = _freshArea select 1;
_angle = _freshArea select 2;
_isRect = _freshArea select 3;

// Prop-candidate selection (1-in-N hash), shared by both discovery paths
private _fnConsiderProp = {
	params ["_ox", "_oy"];
	if (!_isPreview) then {UMBARA_DEBUG_Discovered = UMBARA_DEBUG_Discovered + 1;};
	private _hSkip = (sin((_ox * 39.234) + (_oy * 51.912) + 7.13) * 19349.336);
	private _fSkip = _hSkip - (floor _hSkip);
	if ((floor (_fSkip * _replaceEveryNth)) == 0) then {
		if (!_isPreview) then {UMBARA_DEBUG_Selected = UMBARA_DEBUG_Selected + 1;};
		_queue pushBack [1, _ox, _oy, 0];
	};
};

if ((count _chunkList) > 0) then {
	private _m = 0;
	while {_m < _chunksPerFrame && {(count _chunkList) > 0}} do {
		if (_useCachedData) then {
			// Cached-data fast path — in-memory filter, no world queries
			private _slice = _chunkList deleteAt (count _chunkList - 1);
			private _startIdx = _slice select 0;
			private _endIdx = _slice select 1;
			for "_i" from _startIdx to (_endIdx - 1) do {
				private _pos = _cachedData select _i;
				private _ox = _pos select 0;
				private _oy = _pos select 1;
				if ([_ox, _oy, _cx0, _cy0, _a, _b, _angle, _isRect] call umbara_trees_fnc_pointInArea) then {
					[_ox, _oy] call _fnConsiderProp;
				};
			};
		} else {
			// Live-scan path
			private _c = _chunkList deleteAt (count _chunkList - 1);
			private _chCx = _c select 0;
			private _chCy = _c select 1;

			private _chunkCenter = [(_chCx + (_chunkSize / 2)), (_chCy + (_chunkSize / 2)), 0];
			private _candidates = nearestTerrainObjects [_chunkCenter, ["Tree", "Small Tree", "Bush"], (_chunkSize * 0.75), false, true];
			{
				private _objPos = getPosATL _x;
				private _ox = _objPos select 0;
				private _oy = _objPos select 1;
				if ([_ox, _oy, _cx0, _cy0, _a, _b, _angle, _isRect] call umbara_trees_fnc_pointInArea && {_ox >= _chCx} && {_ox < (_chCx + _chunkSize)} && {_oy >= _chCy} && {_oy < (_chCy + _chunkSize)}) then {
					// Hide + prop placement are independent decisions
					if (_hideNative) then {
						_queue pushBack [0, _x, 0, 0];
					};
					[_ox, _oy] call _fnConsiderProp;
				};
			} forEach _candidates;
		};

		_m = _m + 1;
	};
} else {
	private _n = 0;
	while {_n < _batchSize && {(count _queue) > 0}} do {
		private _e = _queue deleteAt (count _queue - 1);
		private _tag = _e select 0;

		if (_tag == 0) then {
			// Hide branch
			private _treeObj = _e select 1;
			if (isServer) then {
				_treeObj hideObjectGlobal true;
				if (!_isPreview) then {
					UMBARA_DEBUG_HideCalls = UMBARA_DEBUG_HideCalls + 1;
					if (isNil "UMBARA_HIDE_CANDIDATES") then {UMBARA_HIDE_CANDIDATES = [];};
					UMBARA_HIDE_CANDIDATES pushBack _treeObj;
				};
			};
			if (!_isPreview) then {
				if (isNil "UMBARA_DEBUG_HideChecks") then {UMBARA_DEBUG_HideChecks = 0;};
				UMBARA_DEBUG_HideChecks = UMBARA_DEBUG_HideChecks + 1;
				if ((UMBARA_DEBUG_HideChecks % 5000) == 0) then {
					diag_log text format ["UMBARA DEBUG hide sample (%1): obj=%2 type=%3 pos=%4 isObjectHidden=%5", ["client", "server"] select isServer, _treeObj, typeOf _treeObj, getPosATL _treeObj, isObjectHidden _treeObj];
				};
			};
			if (_isPreview) then {_hiddenRef pushBack _treeObj;};
		} else {
			// Prop-placement branch
			private _ox = _e select 1;
			private _oy = _e select 2;

			private _h1 = (sin((_ox * 12.9898) + (_oy * 78.233)) * 43758.5453);
			private _f1 = _h1 - (floor _h1);
			private _idx = (floor (_f1 * (count UMBARA_PROPS))) min ((count UMBARA_PROPS) - 1);
			private _cls = UMBARA_PROPS select _idx;
			private _h2 = (sin((_ox * 78.233) + (_oy * 12.9898) + 17.5) * 12543.789);
			private _f2 = _h2 - (floor _h2);
			private _dir = _f2 * 360;

			if (_isPreview) then {
				private _objPosASL = [_ox, _oy, (getTerrainHeightASL [_ox, _oy])];
				private _newObj = createSimpleObject [_cls, _objPosASL, true];
				_newObj setDir _dir;
				_newObj setVectorUp (surfaceNormal [_ox, _oy, 0]);
				_placedRef pushBack _newObj;
				if (isNil "UMBARA_PLACED_PROPS") then {UMBARA_PLACED_PROPS = [];};
				UMBARA_PLACED_PROPS pushBack _newObj;
			} else {
				// Real runs: register as a streaming candidate, don't create yet
				private _h3 = (sin((_ox * 269.5) + (_oy * 183.3) + 43.9) * 8532.123);
				private _rank = _h3 - (floor _h3);
				if (isNil "UMBARA_STREAM_CANDIDATES") then {UMBARA_STREAM_CANDIDATES = [];};
				private _candIdx = count UMBARA_STREAM_CANDIDATES;
				UMBARA_STREAM_CANDIDATES pushBack [_ox, _oy, _cls, _dir, _rank, objNull, -1];

				// Bucket into the spatial grid fn_streamTick.sqf reads from
				private _gcx = floor (_ox / GRID_CELL_SIZE);
				private _gcy = floor (_oy / GRID_CELL_SIZE);
				private _cellKey = (_gcx * 100000) + _gcy;
				if (isNil "UMBARA_STREAM_GRID") then {UMBARA_STREAM_GRID = createHashMap;};
				private _cellList = UMBARA_STREAM_GRID getOrDefault [_cellKey, [], true];
				_cellList pushBack _candIdx;
			};
		};

		_n = _n + 1;
	};

	if ((count _queue) == 0) then {
		if (!_isPreview) then {
			UMBARA_SWAP_DONE = true;
			private _candidateCount = if (isNil "UMBARA_STREAM_CANDIDATES") then {0} else {count UMBARA_STREAM_CANDIDATES};
			systemChat format ["Umbara swap done: %1 props registered for streaming in %2s", _candidateCount, (diag_tickTime - _startTime)];
			diag_log text format ["UMBARA DEBUG hide-pass counters: discovered=%1 selected=%2 hideObjectGlobal calls=%3 (hideCalls only increments on the machine where isServer is true)", UMBARA_DEBUG_Discovered, UMBARA_DEBUG_Selected, UMBARA_DEBUG_HideCalls];
		};
	};
};

((count _chunkList) == 0) && ((count _queue) == 0)
