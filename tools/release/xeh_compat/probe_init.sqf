// AuxXEHProbe: for every CfgVehicles class kind of CAManBase whose EventHandlers lack
// CBA_Extended_EventHandlers, walk the EventHandlers inheritance chain to its root and
// report the vehicle class that owns that root (the class to patch), the root's parent,
// and the owner's parent + source addons. Also re-checks support after any patch.
if (!isServer) exitWith {};
[] spawn {
    sleep 15;
    diag_log format ["XEHP|patches compat41=%1 compat3p=%2", isClass (configFile >> "CfgPatches" >> "KAID_XEH_Compat_41st"), isClass (configFile >> "CfgPatches" >> "KAID_XEH_Compat_3P")];
    private _owners = createHashMap;
    private _bad = 0;
    {
        private _cls = configName _x;
        if (getNumber (_x >> "scope") >= 0 && {isClass (_x >> "EventHandlers")}) then {
            private _eh = _x >> "EventHandlers";
            if (!isClass (_eh >> "CBA_Extended_EventHandlers")) then {
                _bad = _bad + 1;
                // walk to the root of the EventHandlers chain
                private _c = _eh;
                private _guard = 0;
                while {!isNull (inheritsFrom _c) && {_guard < 50}} do { _c = inheritsFrom _c; _guard = _guard + 1 };
                private _path = str _c;
                if !(_path in _owners) then { _owners set [_path, _cls] };
            };
        };
    } forEach ("true" configClasses (configFile >> "CfgVehicles"));
    diag_log format ["XEHP|unsupported=%1 roots=%2", _bad, count _owners];
    {
        // _x = root EventHandlers path like bin\config.bin/CfgVehicles/OWNER/EventHandlers
        private _parts = _x splitString "/";
        private _owner = if (count _parts >= 3 && {(_parts select (count _parts - 3)) == "CfgVehicles"}) then { _parts select (count _parts - 2) } else { "" };
        private _oc = configFile >> "CfgVehicles" >> _owner;
        diag_log format ["XEHP|root|%1|owner=%2|ownerParent=%3|ownerSrc=%4|example=%5|ehLocal=%6",
            _x, _owner, if (_owner != "") then { configName inheritsFrom _oc } else { "" },
            if (_owner != "") then { configSourceAddonList _oc } else { [] }, _y,
            if (_owner != "") then { configSourceAddonList (_oc >> "EventHandlers") } else { [] }];
    } forEach _owners;
    diag_log "XEHP_DONE";
};
