localNamespace setVariable ["stonewall_code", (localNamespace getVariable ["stonewall_code", ""]) + "private _def = (configSourceAddonList _cfg) param [0, """"];
_clsAddons set [_t, _def];
[format [""C|%1|%2"", _t, _def], true] call _emit;
};
private _v = vectorDir _o;
private _u = vectorUp _o;
[format [""O|%1|%2|%3|%4|%5|%6|%7|%8|%9|%10|%11|%12|%13|%14|%15|%16|%17|%18|%19|%20|%21|%22"", _n, _t,
_pos#0 toFixed 3, _pos#1 toFixed 3, _pos#2 toFixed 3,
_v#0 toFixed 5, _v#1 toFixed 5, _v#2 toFixed 5, _u#0 toFixed 5, _u#1 toFixed 5, _u#2 toFixed 5,
_src, _kind, [0, 1] select (alive _o), damage _o toFixed 2, [0, 1] select (isSimpleObject _o),
[0, 1] select (simulationEnabled _o), [0, 1] select (isObjectHidden _o), getObjectScale _o toFixed 3,
(_o getVariable [""stonewall_born"", -1]) toFixed 0, _in joinString "";"", vehicleVarName _o call _clean],
!(_in isEqualTo [])] call _emit;
_n = _n + 1;
if !(_in isEqualTo []) then { _nArea = _nArea + 1; };
if (_n % 150 == 0) then { sleep 0.01; };
};
"];
