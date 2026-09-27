localNamespace setVariable ["stonewall_code", (localNamespace getVariable ["stonewall_code", ""]) + "[_msg] remoteExec [""systemChat"", _owner];
};
} forEach _owners;
};
if (hasInterface) then {
if (_cba) then { [""FST_stonewall_done"", [_msg]] call CBA_fnc_localEvent; } else { systemChat _msg; };
};
missionNamespace setVariable [""stonewall_lastSave"", [_sid, _n, _nArea, count _areas], true];
if ((localNamespace getVariable [""stonewall_busy"", []]) param [0, """"] isEqualTo _lockId) then {
localNamespace setVariable [""stonewall_busy"", []];
};
};
"];
call compile (localNamespace getVariable ["stonewall_code", ""]);
localNamespace setVariable ["stonewall_code", nil];
