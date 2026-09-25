if (!isServer) exitWith {[]};

MEAP_Architect_blueprints = createHashMap;
private _root = configFile >> "CfgGroups" >> "West" >> "MEAP_Daidalos";
if (!isClass _root) exitWith {[]};

for "_index" from 0 to ((count _root) - 1) do
{
    private _composition = _root select _index;
    if (isClass _composition) then
    {
        private _entries = [];
        for "_entryIndex" from 0 to ((count _composition) - 1) do
        {
            private _entry = _composition select _entryIndex;
            if (isClass _entry) then
            {
                private _className = getText (_entry >> "vehicle");
                private _position = getArray (_entry >> "position");
                if (_className isNotEqualTo "" && {_position isEqualTypeParams [0, 0, 0]}) then
                {
                    _entries pushBack [_className, _position, getNumber (_entry >> "azimut")];
                };
            };
        };
        if (_entries isNotEqualTo []) then
        {
            private _name = configName _composition;
            private _displayName = getText (_composition >> "name");
            if (_displayName isEqualTo "") then {_displayName = _name;};
            MEAP_Architect_blueprints set [format ["CFG:%1", _name], [_displayName, "CONFIG", "", _entries]];
        };
    };
};
keys MEAP_Architect_blueprints
