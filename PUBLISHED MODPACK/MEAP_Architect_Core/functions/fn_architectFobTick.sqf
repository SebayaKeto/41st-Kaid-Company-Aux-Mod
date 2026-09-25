if (!isServer) exitWith {};
call MEAP_fnc_initializeArchitectState;

private _heartClass = missionNamespace getVariable ["MEAP_Architect_fobHeartClass", ""];
if (_heartClass isEqualTo "") exitWith {};

private _radius = missionNamespace getVariable ["MEAP_Architect_fobRadius", 250];
{
    if (typeOf _x isEqualTo _heartClass) then
    {
        private _fobKey = netId _x;
        if (_fobKey isNotEqualTo "" && {isNil {MEAP_Architect_fobs get _fobKey}}) then
        {
            MEAP_Architect_fobs set
            [
                _fobKey,
                [_x, missionNamespace getVariable ["MEAP_Architect_fobStartingFunds", 0], -1, -1]
            ];
            _x setVariable ["MEAP_Architect_fobHeart", _fobKey, true];
            _x setVariable ["MEAP_Economy_stockpile", true, true];
            if !((_x getVariable ["MEAP_Economy_stock", []]) isEqualTypeParams [0, 0, 0, 0]) then
            {
                _x setVariable ["MEAP_Economy_stock", [0, 0, 0, 0], true];
            };
        };
    };
} forEach (allMissionObjects "All");

private _now = diag_tickTime;
private _decayDelay = missionNamespace getVariable ["MEAP_Architect_fobDecayDelay", 900];
private _decayInterval = missionNamespace getVariable ["MEAP_Architect_fobDecayInterval", 30];
{
    private _fobKey = _x;
    private _fob = _y;
    _fob params ["_heart", "_funds", ["_lostAt", -1], ["_nextDecay", -1]];
    if (!isNull _heart && {alive _heart}) then
    {
        if (_lostAt >= 0) then
        {
            _fob set [2, -1];
            _fob set [3, -1];
            MEAP_Architect_fobs set [_fobKey, _fob];
        };
    }
    else
    {
        if (_lostAt < 0) then
        {
            _lostAt = _now;
            _nextDecay = _now + _decayDelay;
            _fob set [2, _lostAt];
            _fob set [3, _nextDecay];
            MEAP_Architect_fobs set [_fobKey, _fob];
        };
        if (_now >= _nextDecay) then
        {
            private _decayObject = objNull;
            {
                if ((_x getVariable ["MEAP_Architect_fobKey", ""]) isEqualTo _fobKey) exitWith
                {
                    private _replacement = [getPosASL _x, _radius] call MEAP_fnc_getArchitectFob;
                    _replacement params ["_replacementKey"];
                    if (_replacementKey isNotEqualTo "") then
                    {
                        _x setVariable ["MEAP_Architect_fobKey", _replacementKey, true];
                    }
                    else
                    {
                        _decayObject = _x;
                    };
                };
            } forEach (allMissionObjects "All");
            if (!isNull _decayObject) then {deleteVehicle _decayObject;};
            _fob set [3, _now + _decayInterval];
            MEAP_Architect_fobs set [_fobKey, _fob];
        };
    };
} forEach MEAP_Architect_fobs;
