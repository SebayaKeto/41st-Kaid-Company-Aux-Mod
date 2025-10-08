private _display = findDisplay 4100;
uiNamespace setVariable ["FST_HelmetOverlay_Display", _display];
private _listCtrl   = _display displayCtrl 4102;
private _searchCtrl = _display displayCtrl 4103;
if (isNil "FST_arsenalBlacklist") then {
    FST_arsenalBlacklist = [
        "FST_NVG_Invisible_Thermals",
        "FST_NVG_Invisible",
        "FST_Fynock_LowLight",
        "FST_U_CIS_TS"
    ];
};
if (isNil "FST_arsenalPrefixBlacklist") then {
    FST_arsenalPrefixBlacklist = [
        "FST_DroidB1",
        "FST_DroidBX",
        "FST_DroidB2"
    ];
};
FST_fnc_isBlacklisted = {
    params ["_cls"];
    if (!(_cls isEqualType "")) exitWith { true };
    if (_cls isEqualTo "")       exitWith { true };
    if (_cls in FST_arsenalBlacklist) exitWith { true };
    private _blocked = false;
    {
        if (_x isEqualType "" && { _x != "" } && { _cls find _x == 0 }) exitWith { _blocked = true };
    } forEach FST_arsenalPrefixBlacklist;
    _blocked
};
lbClear _listCtrl;
call FST_fnc_gearIndex;

uiNamespace setVariable ["FST_CurrentCategories", ["helmets"]];
uiNamespace setVariable ["FST_SearchQuery", ""];
private _idx = uiNamespace getVariable ["FST_GearIndex", createHashMap];
private _all = +(_idx getOrDefault ["uniforms",  []])
            +  (_idx getOrDefault ["vests",     []])
            +  (_idx getOrDefault ["helmets",   []])
            +  (_idx getOrDefault ["backpacks", []])
            +  (_idx getOrDefault ["facewear",  []])
            +  (_idx getOrDefault ["nvgs",      []]);
uiNamespace setVariable ["FST_AllHelmetClasses", _all];
FST_fnc_renderGearList = {
    private _disp   = uiNamespace getVariable ["FST_HelmetOverlay_Display", displayNull];
    if (isNull _disp) exitWith {};
    private _list   = _disp displayCtrl 4102;
    private _query  = toLower (uiNamespace getVariable ["FST_SearchQuery",""]);
    private _cats   = uiNamespace getVariable ["FST_CurrentCategories", ["helmets"]];
    private _idxMap = uiNamespace getVariable ["FST_GearIndex", createHashMap];

    lbClear _list;
    private _pool = [];
    {
        _pool append (_idxMap getOrDefault [_x, []]);
    } forEach _cats;
    private _seen = createHashMap;
    _pool = _pool select {
        private _c = _x;
        if (isNil {_seen get _c}) then { _seen set [_c, true]; true } else { false };
    };
    _pool = _pool select { !([_x] call FST_fnc_isBlacklisted) };
    {
        private _cls = _x;
        private _cfg = configFile >> "CfgWeapons" >> _cls;
        if (!isClass _cfg) then { _cfg = configFile >> "CfgVehicles" >> _cls };
        if (!isClass _cfg) then { _cfg = configFile >> "CfgGlasses"  >> _cls };
        private _dn = if (isClass _cfg) then { getText (_cfg >> "displayName") } else { _cls };
        private _ic = if (isClass _cfg) then { getText (_cfg >> "picture") }     else { "" };
        if (
            _query isEqualTo "" ||
            { (toLower _cls) find _query > -1 } ||
            { (toLower _dn)  find _query > -1 }
        ) then {
            private _i = _list lbAdd _dn;
            _list lbSetData [_i, _cls];
            if (_ic != "") then { _list lbSetPicture [_i, _ic]; };
            _list lbSetPictureColor [_i, [1,1,1,1]];
        };
    } forEach _pool;
};
if (!isNull _searchCtrl) then {
    _searchCtrl ctrlRemoveAllEventHandlers "KeyUp";
    _searchCtrl ctrlAddEventHandler ["KeyUp", {
        params ["_ctrl"];
        uiNamespace setVariable ["FST_SearchQuery", ctrlText _ctrl];
        [] call FST_fnc_renderGearList;
    }];
};
FST_fnc_showCategory = {
    params ["_cat"];
    uiNamespace setVariable ["FST_CurrentCategories", [_cat]];
    [] call FST_fnc_renderGearList;
};
[] call FST_fnc_refreshGearList;
[] call FST_fnc_renderGearList;
private _btnHelmets   = _display displayCtrl 4201;
private _btnFacewear  = _display displayCtrl 4202;
private _btnVests     = _display displayCtrl 4203;
private _btnUniforms  = _display displayCtrl 4204;
private _btnBackpacks = _display displayCtrl 4205;
private _btnNVG       = _display displayCtrl 4206;
if (!isNull _btnNVG)       then { _btnNVG       ctrlAddEventHandler ["ButtonClick", { ["nvgs"]      call FST_fnc_showCategory; }]; };
if (!isNull _btnHelmets)   then { _btnHelmets   ctrlAddEventHandler ["ButtonClick", { ["helmets"]   call FST_fnc_showCategory; }]; };
if (!isNull _btnFacewear)  then { _btnFacewear  ctrlAddEventHandler ["ButtonClick", { ["facewear"]  call FST_fnc_showCategory; }]; };
if (!isNull _btnVests)     then { _btnVests     ctrlAddEventHandler ["ButtonClick", { ["vests"]     call FST_fnc_showCategory; }]; };
if (!isNull _btnUniforms)  then { _btnUniforms  ctrlAddEventHandler ["ButtonClick", { ["uniforms"]  call FST_fnc_showCategory; }]; };
if (!isNull _btnBackpacks) then { _btnBackpacks ctrlAddEventHandler ["ButtonClick", { ["backpacks"] call FST_fnc_showCategory; }]; };
