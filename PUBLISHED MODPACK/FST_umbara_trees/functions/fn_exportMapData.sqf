// Offline per-map export tool — NOT run by end users, see README.md
// Run once via Debug Console after loading a map in Eden.
// Results land in the RPT as "UMBARA EXPORT LINE" entries.

#define LINE_BATCH_SIZE 30

params [["_chunkSize", 1000]];

private _worldSizeVal = worldSize;
diag_log text format ["UMBARA EXPORT START world=%1 worldSize=%2 chunkSize=%3", worldName, _worldSizeVal, _chunkSize];

[_chunkSize, _worldSizeVal] spawn {
	params ["_chunkSize", "_worldSizeVal"];

	private _chunkIndex = 0;
	private _lineIndex = 0;
	private _totalFound = 0;
	private _cx = 0;
	while {_cx < _worldSizeVal} do {
		private _cy = 0;
		while {_cy < _worldSizeVal} do {
			private _chunkCenter = [(_cx + (_chunkSize / 2)), (_cy + (_chunkSize / 2)), 0];
			private _candidates = nearestTerrainObjects [_chunkCenter, ["Tree", "Small Tree", "Bush"], (_chunkSize * 0.75), false, true];

			private _pairs = [];
			{
				private _objPos = getPosATL _x;
				private _ox = _objPos select 0;
				private _oy = _objPos select 1;
				if (_ox >= _cx && {_ox < (_cx + _chunkSize)} && {_oy >= _cy} && {_oy < (_cy + _chunkSize)}) then {
					_pairs pushBack format ["%1,%2", _ox, _oy];
					_totalFound = _totalFound + 1;

					// Flush in fixed-size batches, not one line per chunk
					if ((count _pairs) >= LINE_BATCH_SIZE) then {
						diag_log text format ["UMBARA EXPORT LINE %1 %2", _lineIndex, (_pairs joinString ";")];
						_lineIndex = _lineIndex + 1;
						_pairs = [];
					};
				};
			} forEach _candidates;

			if ((count _pairs) > 0) then {
				diag_log text format ["UMBARA EXPORT LINE %1 %2", _lineIndex, (_pairs joinString ";")];
				_lineIndex = _lineIndex + 1;
			};

			_chunkIndex = _chunkIndex + 1;
			_cy = _cy + _chunkSize;
			sleep 0;
		};
		_cx = _cx + _chunkSize;
	};

	diag_log text format ["UMBARA EXPORT DONE total=%1 chunks=%2 lines=%3", _totalFound, _chunkIndex, _lineIndex];
	systemChat format ["Umbara map export done: %1 positions across %2 chunks — see RPT for UMBARA EXPORT lines", _totalFound, _chunkIndex];
};
