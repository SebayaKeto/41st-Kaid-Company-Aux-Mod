// Low-frequency owner-local setup. Never load or duplicate WebKnight code.
params ["_group"];
if (isNull _group || {!local _group} || {_group getVariable ["BURNS_exempt", false]}) exitWith {};
if ((units _group findIf {isPlayer _x}) >= 0 || {side _group == civilian}) exitWith {};
if ([_group] call FST_HCSpawn_fnc_isProtectedVehicleGroup) exitWith {};
private _b1Only = true;
private _any = false;
{
    private _unit = _x;
    if (!alive _unit || {!local _unit} || {_unit getVariable ["BURNS_exempt",false]}) then {_b1Only=false;continue};
    _any = true;
    private _role = [_unit] call FST_HCSpawn_fnc_burnsRole;
    if (_role != "b1") then {_b1Only = false};
    // Workshop initializes B2/BX via inherited class handlers. Re-running its
    // loaders here would stack event handlers and long-running animation loops.
    if (_role == "webknight" || {_role == "other"}) then {continue};
    if (isNil {_unit getVariable "BURNS_originalRole"}) then {
        _unit setVariable ["BURNS_originalRole",[unitPos _unit,getForcedSpeed _unit,["COVER","SUPPRESSION","AUTOCOMBAT"] apply {_unit checkAIFeature _x},["general","commanding","courage","reloadSpeed","spotTime","aimingAccuracy","aimingSpeed"] apply {_unit skill _x}],true];
    };
    if (_role == "b1") then {
        if !(missionNamespace getVariable ["FST_HC_DroidStanceEnabled", true]) then {continue};
        if (vehicle _unit == _unit && {lifeState _unit != "INCAPACITATED"}) then {
            private _signature = [clientOwner, missionNamespace getVariable ["BURNS_B1MarchSpeed", 2.5],missionNamespace getVariable ["BURNS_B1Reaction",0.85]];
            // The separate stance guard repairs animations. Do not re-send all
            // AI commands for every B1 each scheduler visit during large fights.
            if !((_unit getVariable ["BURNS_b1Applied", []]) isEqualTo _signature) then {
                _unit setUnitPos "UP";
                _unit setUnitPosWeak "UP";
                _unit disableAI "COVER";
                _unit disableAI "SUPPRESSION";
                _unit disableAI "AUTOCOMBAT";
                _unit forceSpeed (_signature select 1);
                // React and bring the rifle on target sooner. Do not improve
                // spotting range, accuracy or target knowledge.
                _unit setSkill ["spotTime",(_unit skill "spotTime") max (_signature select 2)];
                _unit setSkill ["aimingSpeed",(_unit skill "aimingSpeed") max ((_signature select 2) min 0.75)];
                _unit allowFleeing 0;
                _unit setVariable ["BURNS_b1Applied", _signature];
            };
        } else {
            _unit setVariable ["BURNS_b1Applied", nil];
        };
    } else {
        if !(_unit getVariable ["BURNS_suppressionHook",false]) then {
            _unit setVariable ["BURNS_suppressionHook",true];
            _unit addEventHandler ["Suppressed",{_this call FST_HCSpawn_fnc_burnsSuppressed}];
        };
        if (side _group == west) then {continue};
        private _skill = missionNamespace getVariable ["BURNS_HumanSkill", 0.7];
        private _accuracy = missionNamespace getVariable ["BURNS_HumanAccuracy", 0.25];
        private _signature = [clientOwner, _skill, _accuracy];
        if !((_unit getVariable ["BURNS_skillApplied", []]) isEqualTo _signature) then {
            { _unit setSkill [_x, (_unit skill _x) max _skill]; } forEach ["general","commanding","courage","reloadSpeed","spotTime"];
            _unit setSkill ["aimingAccuracy", (_unit skill "aimingAccuracy") max _accuracy];
            _unit setVariable ["BURNS_skillApplied", _signature];
        };
    };
} forEach units _group;
if (_b1Only && {_any} && {missionNamespace getVariable ["FST_HC_DroidStanceEnabled", true]}) then {
    if (formation _group != "LINE") then {_group setFormation "LINE"};
    if ((_group getVariable ["BURNS_b1GroupOwner", -1]) != clientOwner) then {
        _group setSpeedMode "LIMITED";
        _group enableAttack false;
        _group setBehaviourStrong "AWARE";
        _group setVariable ["BURNS_b1GroupOwner", clientOwner];
    };
};
