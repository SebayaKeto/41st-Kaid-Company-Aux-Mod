// Umbara Tree Swap module — dispatch + generation setup
// See README.md for full history/reasoning.

params ["_mode", "_input"];
_input params [
	["_logic", objNull, [objNull]],
	["_isActivated", true, [true]],
	["_isCuratorPlaced", false, [true]]
];

if (isNull _logic) exitWith {true};

// Eden-preview cleanup
private _fnClearPreview = {
	params ["_logic"];
	private _oldProps = _logic getVariable ["UMBARA_PreviewProps", []];
	private _oldHidden = _logic getVariable ["UMBARA_PreviewHidden", []];
	diag_log text format ["UMBARA DEBUG clearing preview: %1 props, %2 hidden, handlerBelongsToThis=%3", count _oldProps, count _oldHidden, (!isNil "UMBARA_EdenLogic" && {UMBARA_EdenLogic == _logic})];
	if (!isNil "UMBARA_EdenLogic" && {UMBARA_EdenLogic == _logic} && {!isNil "UMBARA_EdenEH"}) then {
		removeMissionEventHandler ["EachFrame", UMBARA_EdenEH];
		UMBARA_EdenEH = nil;
	};
	{if (!isNull _x) then {deleteVehicle _x};} forEach _oldProps;
	{if (!isNull _x) then {_x hideObjectGlobal false};} forEach _oldHidden;
	_logic setVariable ["UMBARA_PreviewProps", []];
	_logic setVariable ["UMBARA_PreviewHidden", []];
};

// Full discovery + placement pass setup
private _fnGenerate = {
	params ["_logic", "_isPreview"];

	// Default 47-prop list
	private _defaultProps = [
		"land_3as_Umbara_pod1", "land_3as_Umbara_pod5", "land_3as_Umbara_pod2", "land_3as_Umbara_pod6", "land_3as_Umbara_pod3", "land_3as_Umbara_pod4",
		"land_3as_Umbara_smalltentacles", "land_3as_Umbara_smalltentacles2", "land_3as_Umbara_smalltentacles3",
		"land_3as_Umbara_tentacle1_l_P", "land_3as_Umbara_tentacle1_l_r", "land_3as_Umbara_tentacle1", "land_3as_Umbara_tentacle1_s_r",
		"land_3as_Umbara_tentacle2_L_P", "land_3as_Umbara_tentacle2_L_r",
		"land_3as_Umbara_tentacle3_L_P", "land_3as_Umbara_tentacle3_L_r", "land_3as_Umbara_tentacle3", "land_3as_Umbara_tentacle3_s_r",
		"land_3as_Umbara_tentacle4_L_P", "land_3as_Umbara_tentacle4_L_r",
		"land_3as_Umbara_tentacle5_L_P", "land_3as_Umbara_tentacle5_L_r", "land_3as_Umbara_tentacle5", "land_3as_Umbara_tentacle5_s_r",
		"land_3as_Umbara_tentacle6_l", "land_3as_Umbara_tentacle6_s", "land_3as_Umbara_tentacle6_xl",
		"land_3as_Umbara_tentacle7_l", "land_3as_Umbara_tentacle7_s", "land_3as_Umbara_tentacle7_xl",
		"land_3as_Umbara_tentacle8_L", "land_3as_Umbara_tentacle8_s", "land_3as_Umbara_tentacle8_xL",
		"land_3as_Umbara_tentacle9_l", "land_3as_Umbara_tentacle9_s", "land_3as_Umbara_tentacle9_xl",
		"land_3as_Umbara_tentaclebush", "land_3as_Umbara_tentaclebush2", "land_3as_Umbara_tentaclebush3",
		"land_3as_Umbara_tentaclebushlarge", "land_3as_Umbara_tentaclebushlarge2",
		"land_3as_Umbara_tentaclecomp1_p", "land_3as_Umbara_tentaclecomp1_r", "land_3as_Umbara_tentaclecomp2_p", "land_3as_Umbara_tentaclecomp2_r", "land_3as_Umbara_tentaclecomp3_r"
	];

	private _propListStr = _logic getVariable ["UMBARA_PropList", ""];
	UMBARA_PROPS = if (_propListStr == "") then {_defaultProps} else {_propListStr splitString ","};

	private _batchSize = _logic getVariable ["UMBARA_BatchSize", 160];
	private _chunksPerFrame = _logic getVariable ["UMBARA_ChunksPerFrame", 3];
	private _chunkSize = _logic getVariable ["UMBARA_ChunkSize", 1000];
	private _hideNative = _logic getVariable ["UMBARA_HideNativeTrees", true];
	private _replaceEveryNth = _logic getVariable ["UMBARA_ReplaceEveryNth", 2];

	private _pos = getPosATL _logic;
	private _cx0 = _pos select 0;
	private _cy0 = _pos select 1;
	// Area handle — real mission runs only; Eden preview falls back to a
	// fixed UMBARA_PreviewRadius sample patch (see README.md)
	private _previewRadius = _logic getVariable ["UMBARA_PreviewRadius", 150];
	private _area = _logic getVariable ["ObjectArea", [_previewRadius, _previewRadius, 0, false, -1]];
	private _a = _area select 0;
	private _b = _area select 1;
	private _angle = _area select 2;
	private _isRect = _area select 3;
	private _minX = _cx0 - _a;
	private _maxX = _cx0 + _a;
	private _minY = _cy0 - _b;
	private _maxY = _cy0 + _b;

	// Per-map cached position data (real-run, player-facing machines only —
	// see README.md "Per-map cached tree data")
	private _cachedData = [];
	private _useCachedData = false;
	if (!_isPreview && {!isDedicated}) then {
		_cachedData = call umbara_trees_fnc_loadMapData;
		_useCachedData = (count _cachedData) > 0;
	};

	private _chunkList = [];
	if (_useCachedData) then {
		// Cached-data path: index-range slices instead of world chunks
		private _sliceSize = 5000;
		private _total = count _cachedData;
		private _idx = 0;
		while {_idx < _total} do {
			_chunkList pushBack [_idx, ((_idx + _sliceSize) min _total)];
			_idx = _idx + _sliceSize;
		};
	} else {
		// Live-scan path: world-space chunk grid
		private _cx = _minX;
		while {_cx < _maxX} do {
			private _cy = _minY;
			while {_cy < _maxY} do {
				_chunkList pushBack [_cx, _cy];
				_cy = _cy + _chunkSize;
			};
			_cx = _cx + _chunkSize;
		};
	};

	private _queue = [];
	private _startTime = diag_tickTime;

	if (!_isPreview) then {
		if (isNil "UMBARA_PLACED_PROPS") then {UMBARA_PLACED_PROPS = [];};
		UMBARA_SWAP_DONE = false;
		UMBARA_DEBUG_Discovered = 0;
		UMBARA_DEBUG_Selected = 0;
		UMBARA_DEBUG_HideCalls = 0;
		UMBARA_DEBUG_HideChecks = 0;
		UMBARA_HIDE_CANDIDATES = [];
	} else {
		_logic setVariable ["UMBARA_PreviewProps", []];
		_logic setVariable ["UMBARA_PreviewHidden", []];
	};
	private _placedRef = if (_isPreview) then {_logic getVariable "UMBARA_PreviewProps"} else {UMBARA_PLACED_PROPS};
	private _hiddenRef = if (_isPreview) then {_logic getVariable "UMBARA_PreviewHidden"} else {[]};

	if (_isPreview) then {
		UMBARA_EdenLogic = _logic;
		UMBARA_EdenChunkList = _chunkList;
		UMBARA_EdenQueue = _queue;
		UMBARA_EdenChunkSize = _chunkSize;
		UMBARA_EdenChunksPerFrame = _chunksPerFrame;
		UMBARA_EdenBatchSize = _batchSize;
		UMBARA_EdenStartTime = _startTime;
		UMBARA_EdenHideNative = _hideNative;
		UMBARA_EdenReplaceEveryNth = _replaceEveryNth;
		UMBARA_EdenCx0 = _cx0;
		UMBARA_EdenCy0 = _cy0;
		UMBARA_EdenA = _a;
		UMBARA_EdenB = _b;
		UMBARA_EdenAngle = _angle;
		UMBARA_EdenIsRect = _isRect;
		UMBARA_EdenPlacedRef = _placedRef;
		UMBARA_EdenHiddenRef = _hiddenRef;

		UMBARA_EdenEH = addMissionEventHandler ["EachFrame", {
			private _done = [
				UMBARA_EdenLogic, UMBARA_EdenChunkList, UMBARA_EdenQueue, UMBARA_EdenChunkSize,
				UMBARA_EdenChunksPerFrame, UMBARA_EdenBatchSize, UMBARA_EdenStartTime,
				UMBARA_EdenHideNative, UMBARA_EdenReplaceEveryNth, UMBARA_EdenCx0, UMBARA_EdenCy0, UMBARA_EdenA, UMBARA_EdenB,
				UMBARA_EdenAngle, UMBARA_EdenIsRect, true, UMBARA_EdenPlacedRef, UMBARA_EdenHiddenRef, false, []
			] call umbara_trees_fnc_swapTick;
			if (_done) then {
				removeMissionEventHandler ["EachFrame", UMBARA_EdenEH];
				UMBARA_EdenEH = nil;
			};
		}];
	} else {
		[{
			params ["_args", "_pfhHandle"];
			private _done = _args call umbara_trees_fnc_swapTick;
			if (_done) then {[_pfhHandle] call CBA_fnc_removePerFrameHandler;};
		}, 0, [_logic, _chunkList, _queue, _chunkSize, _chunksPerFrame, _batchSize, _startTime, _hideNative, _replaceEveryNth, _cx0, _cy0, _a, _b, _angle, _isRect, _isPreview, _placedRef, _hiddenRef, _useCachedData, _cachedData]] call CBA_fnc_addPerFrameHandler;
	};
};

switch (_mode) do {
	case "init": {
		if (!_isActivated) exitWith {};
		if (is3DEN) exitWith {};
		[_logic, _fnGenerate] spawn {
			params ["_logic", "_fnGenerate"];
			sleep 10;
			[_logic, false] call _fnGenerate;
		};
	};
	case "registeredToWorld3DEN": {
		[_logic, true] call _fnGenerate;
	};
	case "attributesChanged3DEN": {
		[_logic] call _fnClearPreview;
		[_logic, true] call _fnGenerate;
	};
	case "dragged3DEN": {
		[_logic] call _fnClearPreview;
		[_logic, true] call _fnGenerate;
	};
	case "unregisteredFromWorld3DEN": {
		[_logic] call _fnClearPreview;
	};
	case "connectionChanged3DEN": {};
};

true
