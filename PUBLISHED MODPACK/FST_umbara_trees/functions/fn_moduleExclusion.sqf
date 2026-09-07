// Umbara Exclusion Zone module — dispatch + generation setup
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
	if (!isNil "UMBARA_EdenExclLogic" && {UMBARA_EdenExclLogic == _logic} && {!isNil "UMBARA_EdenExclEH"}) then {
		removeMissionEventHandler ["EachFrame", UMBARA_EdenExclEH];
		UMBARA_EdenExclEH = nil;
	};
	{if (!isNull _x) then {_x hideObjectGlobal false};} forEach (_logic getVariable ["UMBARA_PreviewHiddenProps", []]);
	{if (!isNull _x) then {_x hideObjectGlobal false};} forEach (_logic getVariable ["UMBARA_PreviewHiddenTerrain", []]);
	_logic setVariable ["UMBARA_PreviewHiddenProps", []];
	_logic setVariable ["UMBARA_PreviewHiddenTerrain", []];
};

// Full discovery + cleanup pass setup
private _fnGenerate = {
	params ["_logic", "_isPreview"];

	private _chunksPerFrame = _logic getVariable ["UMBARA_ChunksPerFrame", 3];
	private _chunkSize = _logic getVariable ["UMBARA_ChunkSize", 1000];
	private _scanPerFrame = _logic getVariable ["UMBARA_ScanPerFrame", 2000];
	private _batchSize = _logic getVariable ["UMBARA_BatchSize", 60];

	private _pos = getPosATL _logic;
	private _cx0 = _pos select 0;
	private _cy0 = _pos select 1;
	// Area handle — real runs only, Eden preview uses UMBARA_PreviewRadius
	private _previewRadius = _logic getVariable ["UMBARA_PreviewRadius", 75];
	private _area = _logic getVariable ["ObjectArea", [_previewRadius, _previewRadius, 0, false, -1]];
	private _a = _area select 0;
	private _b = _area select 1;
	private _angle = _area select 2;
	private _isRect = _area select 3;
	private _minX = _cx0 - _a;
	private _maxX = _cx0 + _a;
	private _minY = _cy0 - _b;
	private _maxY = _cy0 + _b;

	// Register zone so streamTick refuses new props here (real runs only)
	if (!_isPreview) then {
		if (isNil "UMBARA_ACTIVE_EXCLUSIONS") then {UMBARA_ACTIVE_EXCLUSIONS = [];};
		UMBARA_ACTIVE_EXCLUSIONS pushBack [_cx0, _cy0, _a, _b, _angle, _isRect];
	};

	private _chunkList = [];
	private _cx = _minX;
	while {_cx < _maxX} do {
		private _cy = _minY;
		while {_cy < _maxY} do {
			_chunkList pushBack [_cx, _cy];
			_cy = _cy + _chunkSize;
		};
		_cx = _cx + _chunkSize;
	};

	private _propScanQueue = if (isNil "UMBARA_PLACED_PROPS") then {[]} else {+UMBARA_PLACED_PROPS};
	private _actionQueue = [];
	private _startTime = diag_tickTime;

	if (_isPreview) then {
		_logic setVariable ["UMBARA_PreviewHiddenProps", []];
		_logic setVariable ["UMBARA_PreviewHiddenTerrain", []];
	};
	private _previewHiddenProps = if (_isPreview) then {_logic getVariable "UMBARA_PreviewHiddenProps"} else {[]};
	private _previewHiddenTerrain = if (_isPreview) then {_logic getVariable "UMBARA_PreviewHiddenTerrain"} else {[]};

	if (_isPreview) then {
		UMBARA_EdenExclLogic = _logic;
		UMBARA_EdenExclChunkList = _chunkList;
		UMBARA_EdenExclPropScanQueue = _propScanQueue;
		UMBARA_EdenExclActionQueue = _actionQueue;
		UMBARA_EdenExclChunkSize = _chunkSize;
		UMBARA_EdenExclChunksPerFrame = _chunksPerFrame;
		UMBARA_EdenExclScanPerFrame = _scanPerFrame;
		UMBARA_EdenExclBatchSize = _batchSize;
		UMBARA_EdenExclStartTime = _startTime;
		UMBARA_EdenExclCx0 = _cx0;
		UMBARA_EdenExclCy0 = _cy0;
		UMBARA_EdenExclA = _a;
		UMBARA_EdenExclB = _b;
		UMBARA_EdenExclAngle = _angle;
		UMBARA_EdenExclIsRect = _isRect;
		UMBARA_EdenExclHiddenProps = _previewHiddenProps;
		UMBARA_EdenExclHiddenTerrain = _previewHiddenTerrain;

		UMBARA_EdenExclEH = addMissionEventHandler ["EachFrame", {
			private _done = [
				UMBARA_EdenExclLogic, UMBARA_EdenExclChunkList, UMBARA_EdenExclPropScanQueue, UMBARA_EdenExclActionQueue,
				UMBARA_EdenExclChunkSize, UMBARA_EdenExclChunksPerFrame, UMBARA_EdenExclScanPerFrame, UMBARA_EdenExclBatchSize,
				UMBARA_EdenExclStartTime, UMBARA_EdenExclCx0, UMBARA_EdenExclCy0, UMBARA_EdenExclA, UMBARA_EdenExclB,
				UMBARA_EdenExclAngle, UMBARA_EdenExclIsRect, true, UMBARA_EdenExclHiddenProps, UMBARA_EdenExclHiddenTerrain
			] call umbara_trees_fnc_exclusionTick;
			if (_done) then {
				removeMissionEventHandler ["EachFrame", UMBARA_EdenExclEH];
				UMBARA_EdenExclEH = nil;
			};
		}];
	} else {
		[{
			params ["_args", "_pfhHandle"];
			private _done = _args call umbara_trees_fnc_exclusionTick;
			if (_done) then {[_pfhHandle] call CBA_fnc_removePerFrameHandler;};
		}, 0, [_logic, _chunkList, _propScanQueue, _actionQueue, _chunkSize, _chunksPerFrame, _scanPerFrame, _batchSize, _startTime, _cx0, _cy0, _a, _b, _angle, _isRect, _isPreview, _previewHiddenProps, _previewHiddenTerrain]] call CBA_fnc_addPerFrameHandler;
	};
};

switch (_mode) do {
	case "init": {
		if (!_isActivated) exitWith {};
		if (is3DEN) exitWith {};
		[_logic, _fnGenerate] spawn {
			params ["_logic", "_fnGenerate"];
			sleep 10;
			waitUntil {sleep 0.5; !isNil "UMBARA_SWAP_DONE" && {UMBARA_SWAP_DONE}};
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
