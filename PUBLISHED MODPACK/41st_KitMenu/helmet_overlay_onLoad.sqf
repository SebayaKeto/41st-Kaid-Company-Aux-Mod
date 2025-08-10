private _display = findDisplay 4100;
uiNamespace setVariable ["FST_HelmetOverlay_Display", _display];
private _listCtrl = _display displayCtrl 4102;
lbClear _listCtrl;
call FST_fnc_gearIndex;
uiNamespace setVariable ["FST_CurrentCategories", ["helmets"]];
[] call FST_fnc_refreshGearList;
private _idx = uiNamespace getVariable ["FST_GearIndex", createHashMap];
private _all = +(_idx getOrDefault ["uniforms",  []])
            + (_idx getOrDefault ["vests",     []])
            + (_idx getOrDefault ["helmets",   []])
            + (_idx getOrDefault ["backpacks", []])
            + (_idx getOrDefault ["facewear",  []]);
uiNamespace setVariable ["FST_AllHelmetClasses", _all];
private _searchCtrl = _display displayCtrl 4103;
if (!isNull _searchCtrl) then {
    _searchCtrl ctrlAddEventHandler ["KeyUp", {
        [] call FST_fnc_filterHelmets;
    }];
};
private _btnHelmets   = _display displayCtrl 4201;
private _btnFacewear  = _display displayCtrl 4202;
private _btnVests     = _display displayCtrl 4203;
private _btnUniforms  = _display displayCtrl 4204;
private _btnBackpacks = _display displayCtrl 4205;
if (!isNull _btnHelmets)  then { _btnHelmets  ctrlAddEventHandler ["ButtonClick", { ["helmets"]   call FST_fnc_showCategory; }]; };
if (!isNull _btnFacewear) then { _btnFacewear ctrlAddEventHandler ["ButtonClick", { ["facewear"]  call FST_fnc_showCategory; }]; };
if (!isNull _btnVests)    then { _btnVests    ctrlAddEventHandler ["ButtonClick", { ["vests"]     call FST_fnc_showCategory; }]; };
if (!isNull _btnUniforms) then { _btnUniforms ctrlAddEventHandler ["ButtonClick", { ["uniforms"]  call FST_fnc_showCategory; }]; };
if (!isNull _btnBackpacks)then { _btnBackpacks ctrlAddEventHandler ["ButtonClick", { ["backpacks"] call FST_fnc_showCategory; }]; };
