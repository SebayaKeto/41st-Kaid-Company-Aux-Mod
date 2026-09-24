DI_fnc_objectiveMapPicker = {
    if (!hasInterface || {isNull player}) exitWith {};
    if !((allCurators findIf {getAssignedCuratorUnit _x==player})>=0 || {serverCommandAvailable "#kick"}) exitWith {systemChat "DAARA controls are for Zeus/admin."};
    disableSerialization;
    private _d=findDisplay 46 createDisplay "RscDisplayEmpty";
    private _bg=_d ctrlCreate ["RscText",9400];
    _bg ctrlSetPosition [safeZoneX,safeZoneY,safeZoneW,safeZoneH];_bg ctrlSetBackgroundColor [0.02,0.03,0.04,1];_bg ctrlCommit 0;
    private _title=_d ctrlCreate ["RscText",9401];
    _title ctrlSetPosition [safeZoneX+0.02*safeZoneW,safeZoneY+0.02*safeZoneH,0.96*safeZoneW,0.05*safeZoneH];
    _title ctrlSetText "DAARA - Click the captured objective on the map, then confirm below";_title ctrlCommit 0;
    private _map=_d ctrlCreate ["RscMapControl",9402];
    _map ctrlSetPosition [safeZoneX+0.02*safeZoneW,safeZoneY+0.08*safeZoneH,0.96*safeZoneW,0.73*safeZoneH];_map ctrlCommit 0;
    _map ctrlMapSetPosition [];
    private _status=_d ctrlCreate ["RscText",9403];
    _status ctrlSetPosition [safeZoneX+0.02*safeZoneW,safeZoneY+0.82*safeZoneH,0.96*safeZoneW,0.05*safeZoneH];
    _status ctrlSetText "No objective selected. Zoom and click its numbered circle on the actual terrain map.";_status ctrlCommit 0;
    private _secure=_d ctrlCreate ["RscButton",9404];
    _secure ctrlSetPosition [safeZoneX+0.02*safeZoneW,safeZoneY+0.9*safeZoneH,0.65*safeZoneW,0.06*safeZoneH];
    _secure ctrlSetText "Select an objective first";_secure ctrlEnable false;_secure ctrlCommit 0;
    private _close=_d ctrlCreate ["RscButton",9405];
    _close ctrlSetPosition [safeZoneX+0.72*safeZoneW,safeZoneY+0.9*safeZoneH,0.26*safeZoneW,0.06*safeZoneH];
    _close ctrlSetText "Cancel / close";_close ctrlCommit 0;
    _close ctrlAddEventHandler ["ButtonClick",{(ctrlParent (_this select 0)) closeDisplay 2}];
    private _rows=DI_objectiveDefinitions apply {+_x};
    {
        private _id=_x select 0;
        private _original=(missionNamespace getVariable ["DI_originalObjectiveLabels",[]]) select {(_x select 0)==_id};
        if (count _original>0) then {_x set [1,(_original select 0) select 1]};
    } forEach _rows;
    _d setVariable ["DI_pickerRows",_rows];
    _d setVariable ["DI_pickerIndex",-1];
    _map ctrlAddEventHandler ["Draw",{
        params ["_map"];
        private _d=ctrlParent _map;
        private _selected=_d getVariable ["DI_pickerIndex",-1];
        private _done=missionNamespace getVariable ["DI_completed",[]];
        {
            _x params ["_id","_label","_pos"];
            private _color=if (_id in _done) then {[0.2,0.8,0.3,1]} else {[1,0.25,0.15,1]};
            if (_forEachIndex==_selected) then {_color=[1,0.85,0,1]};
            _map drawEllipse [_pos,65,65,0,_color,""];
            _map drawIcon ["",_color,_pos,0,0,0,format ["#%1 %2",_id select [10],_label],1,0.035,"RobotoCondensed","right"];
        } forEach (_d getVariable ["DI_pickerRows",[]]);
    }];
    _map ctrlAddEventHandler ["MouseButtonDown",{
        params ["_map","_button","_mx","_my"];
        if (_button!=0) exitWith {false};
        private _d=ctrlParent _map;
        private _rows=_d getVariable ["DI_pickerRows",[]];
        private _best=-1;private _distance=0.035;
        {
            private _screen=_map ctrlMapWorldToScreen (_x select 2);
            if (count _screen==2) then {
                private _dx=(_screen select 0)-_mx;private _dy=(_screen select 1)-_my;
                private _delta=sqrt (_dx*_dx+_dy*_dy);
                if (_delta<_distance) then {_distance=_delta;_best=_forEachIndex};
            };
        } forEach _rows;
        _d setVariable ["DI_pickerIndex",_best];
        _d setVariable ["DI_pickerArmed",""];
        private _b=_d displayCtrl 9404;
        if (_best<0) exitWith {_b ctrlEnable false;_b ctrlSetText "Select an objective first";(_d displayCtrl 9403) ctrlSetText "Click directly on a numbered objective circle. Zoom closer if markers overlap.";false};
        (_rows select _best) params ["_id","_label","_pos"];
        private _done=_id in (missionNamespace getVariable ["DI_completed",[]]);
        (_d displayCtrl 9403) ctrlSetText format ["Selected: #%1 %2 - highlighted YELLOW%3",_id select [10],_label,if (_done) then {" (already secured)"} else {""}];
        _b ctrlEnable (!_done);_b ctrlSetText format ["Mark #%1 %2 secured",_id select [10],_label];
        false
    }];
    _secure ctrlAddEventHandler ["ButtonClick",{
        params ["_b"];private _d=ctrlParent _b;private _index=_d getVariable ["DI_pickerIndex",-1];
        if (_index<0) exitWith {};
        ((_d getVariable ["DI_pickerRows",[]]) select _index) params ["_id","_label"];
        if (_id in (missionNamespace getVariable ["DI_completed",[]])) exitWith {_b ctrlEnable false;_b ctrlSetText "Already secured"};
        if ((_d getVariable ["DI_pickerArmed",""])!=_id) exitWith {
            _d setVariable ["DI_pickerArmed",_id];_b ctrlSetText format ["Confirm: secure #%1 %2",_id select [10],_label];
        };
        ["complete",_id] call DI_fnc_sendCommand;
        _b ctrlEnable false;_b ctrlSetText "Sent - waiting for mission confirmation";
        [_d,_id] spawn {
            disableSerialization; params ["_d","_id"];
            private _deadline = diag_tickTime + 15;
            waitUntil {uiSleep 0.2;isNull _d || {_id in (missionNamespace getVariable ["DI_completed",[]])} || {diag_tickTime > _deadline}};
            if (isNull _d) exitWith {};
            private _rows = _d getVariable ["DI_pickerRows",[]];
            private _index = _d getVariable ["DI_pickerIndex",-1];
            if (_index < 0 || {((_rows select _index) select 0) != _id}) exitWith {};
            private _ok = _id in (missionNamespace getVariable ["DI_completed",[]]);
            (_d displayCtrl 9404) ctrlSetText (if (_ok) then {"Mission confirmed: secured"} else {"No confirmation - click to retry"});
            (_d displayCtrl 9404) ctrlEnable (!_ok && {missionNamespace getVariable ["DI_phase",""] != "ended"});
            (_d displayCtrl 9403) ctrlSetText (if (_ok) then {format ["%1 secured in the mission. Reinforcements to this objective are blocked.",_id]} else {"Mission has not confirmed the capture. Check server connection / Zeus authorization."});
        };
        (_d displayCtrl 9403) ctrlSetText "Request sent. Check DAARA's objective count for confirmation.";
    }];
    private _center=[0,0,0];{_center=_center vectorAdd (_x select 2)} forEach _rows;
    if (count _rows>0) then {_center=_center vectorMultiply (1/count _rows)};
    _map ctrlMapAnimAdd [0,0.85,_center];ctrlMapAnimCommit _map;
};
