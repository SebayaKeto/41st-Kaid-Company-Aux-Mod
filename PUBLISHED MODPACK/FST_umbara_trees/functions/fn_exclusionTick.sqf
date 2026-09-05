// Exclusion Zone: one frame's worth of discovery/cleanup
// Real run: deletes matched props. Eden preview: hides them (reversible).

params [
	"_logic", "_chunkList", "_propScanQueue", "_actionQueue", "_chunkSize", "_chunksPerFrame",
	"_scanPerFrame", "_batchSize", "_startTime", "_cx0", "_cy0", "_a", "_b", "_angle", "_isRect",
	"_isPreview", "_previewHiddenProps", "_previewHiddenTerrain"
];

// Fresh area read
private _freshPos = getPosATL _logic;
_cx0 = _freshPos select 0;
_cy0 = _freshPos select 1;
private _freshPreviewRadius = _logic getVariable ["UMBARA_PreviewRadius", 75];
private _freshArea = _logic getVariable ["ObjectArea", [_freshPreviewRadius, _freshPreviewRadius, 0, false, -1]];
_a = _freshArea select 0;
_b = _freshArea select 1;
_angle = _freshArea select 2;
_isRect = _freshArea select 3;

if ((count _chunkList) > 0) then {
	// Phase 1: chunked terrain clutter discovery
	private _m = 0;
	while {_m < _chunksPerFrame && {(count _chunkList) > 0}} do {
		private _c = _chunkList deleteAt (count _chunkList - 1);
		private _chCx = _c select 0;
		private _chCy = _c select 1;
		private _chunkCenter = [(_chCx + (_chunkSize / 2)), (_chCy + (_chunkSize / 2)), 0];
		private _terrainObjs = nearestTerrainObjects [_chunkCenter, [], (_chunkSize * 0.75), false, true];
		{
			private _objPos = getPosATL _x;
			private _ox = _objPos select 0;
			private _oy = _objPos select 1;
			if ([_ox, _oy, _cx0, _cy0, _a, _b, _angle, _isRect] call umbara_trees_fnc_pointInArea && {_ox >= _chCx} && {_ox < (_chCx + _chunkSize)} && {_oy >= _chCy} && {_oy < (_chCy + _chunkSize)}) then {
				_actionQueue pushBack [0, _x];
			};
		} forEach _terrainObjs;
		_m = _m + 1;
	};
} else {
	if ((count _propScanQueue) > 0) then {
		// Phase 2: placed-props scan
		private _s = 0;
		while {_s < _scanPerFrame && {(count _propScanQueue) > 0}} do {
			private _p = _propScanQueue deleteAt (count _propScanQueue - 1);
			if (!isNull _p) then {
				private _pPos = getPosATL _p;
				if ([(_pPos select 0), (_pPos select 1), _cx0, _cy0, _a, _b, _angle, _isRect] call umbara_trees_fnc_pointInArea) then {
					_actionQueue pushBack [1, _p];
				};
			};
			_s = _s + 1;
		};
	} else {
		// Phase 3: action queue drain (hide terrain / delete-or-hide props)
		private _n = 0;
		while {_n < _batchSize && {(count _actionQueue) > 0}} do {
			private _e = _actionQueue deleteAt (count _actionQueue - 1);
			private _tag = _e select 0;
			private _obj = _e select 1;

			if (_tag == 0) then {
				if (isServer) then {_obj hideObjectGlobal true;};
				if (_isPreview) then {_previewHiddenTerrain pushBack _obj;};
			} else {
				if (_isPreview) then {
					_obj hideObjectGlobal true;
					_previewHiddenProps pushBack _obj;
				} else {
					deleteVehicle _obj;
				};
			};

			_n = _n + 1;
		};

		if ((count _actionQueue) == 0) then {
			if (!_isPreview) then {
				systemChat format ["Umbara exclusion cleanup done in %1s", (diag_tickTime - _startTime)];
			};
		};
	};
};

((count _chunkList) == 0) && ((count _propScanQueue) == 0) && ((count _actionQueue) == 0)
