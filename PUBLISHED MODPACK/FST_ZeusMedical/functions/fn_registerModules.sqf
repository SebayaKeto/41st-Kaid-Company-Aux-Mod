// FST_zeusMed_fnc_registerModules
// Client-side. Zen custom modules under "41st Medical". Every effect is sent to the machine where the unit is local.

if (!hasInterface) exitWith {};
if (isNil "zen_custom_modules_fnc_register") exitWith {};
if (missionNamespace getVariable ["FST_zeusMed_modulesRegistered", false]) exitWith {};
FST_zeusMed_modulesRegistered = true;

private _cat = "41st Medical";
private _icons = "\a3\ui_f\data\igui\cfg\simpletasks\types\";

// AI on this server die when knocked out unless ACE "AI unconsciousness" is on; Plot Armor makes them stay down.
FST_zeusMed_fnc_aiNeedsPlotArmor = {
    params ["_unit"];
    !isPlayer _unit && {!(missionNamespace getVariable ["ace_medical_statemachine_AIUnconsciousness", false])}
        && {!(_unit getVariable ["FST_zeusMed_plotArmor", false])}
};

[_cat, "Wound Casualty", {
    params ["", "_attached"];
    private _unit = [_attached] call FST_zeusMed_fnc_unitFromModule;
    if (isNull _unit) exitWith {};
    ["41st Medical: wound casualty", [
        ["COMBO", "Body part", [["Random", "Head", "Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"],
            ["Random", "Head", "Torso", "Left arm", "Right arm", "Left leg", "Right leg"], 2]],
        ["COMBO", ["Wound source", "Plasma = E5/blaster bolts (mostly non-bleeding burns). Grenade/explosive/shell bleed more."],
            [["plasma", "plasmashell", "bullet", "grenade", "explosive", "shell", "stab", "burn", "falling", "vehiclecrash"],
            ["Blaster bolt (plasma)", "Blaster shell (plasmashell)", "Bullet", "Grenade / shrapnel", "Explosive", "Artillery shell", "Stab / blade", "Fire / burn", "Fall", "Vehicle crash"], 0]],
        ["SLIDER", ["Severity per hit", "ACE post-armour damage. Players: 0.37 torso (0.19 head) knocks down; around 0.5+ starts to risk death."], [0.05, 1, 0.3, 2]],
        ["SLIDER", "Hits", [1, 5, 1, 0]]
    ], {
        params ["_values", "_unit"];
        _values params ["_part", "_type", "_damage", "_hits"];
        private _parts = ["Head", "Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"];
        private _list = [];
        for "_i" from 1 to (round _hits) do {
            _list pushBack [_damage, [_part, selectRandom _parts] select (_part == "Random"), _type];
        };
        ["FST_zeusMed_apply", [_unit, "wound", _list, clientOwner], _unit] call CBA_fnc_targetEvent;
    }, {}, _unit] call zen_dialog_fnc_create;
}, _icons + "rifle_ca.paa"] call zen_custom_modules_fnc_register;

[_cat, "Set Blood Volume", {
    params ["", "_attached"];
    private _unit = [_attached] call FST_zeusMed_fnc_unitFromModule;
    if (isNull _unit) exitWith {};
    ["41st Medical: set blood volume", [
        ["SLIDER", ["Blood (litres)", "6.0 full. Below 5.1 no bacta and no waking until fluids. Below 3.6 ACE triggers cardiac arrest (players need CPR; AI die). Plot Armor holds 3.7."],
            [3.0, 6.0, (_unit getVariable ["ace_medical_bloodVolume", 6]) max 3, 1]]
    ], {
        params ["_values", "_unit"];
        ["FST_zeusMed_apply", [_unit, "blood", _values select 0, clientOwner], _unit] call CBA_fnc_targetEvent;
    }, {}, _unit] call zen_dialog_fnc_create;
}, _icons + "heal_ca.paa"] call zen_custom_modules_fnc_register;

[_cat, "Set Pain", {
    params ["", "_attached"];
    private _unit = [_attached] call FST_zeusMed_fnc_unitFromModule;
    if (isNull _unit) exitWith {};
    ["41st Medical: set pain", [
        ["SLIDER", ["Pain", "0 none - 1 maximum. Painkillers/morphine bring it down."], [0, 1, 0.5, 2]]
    ], {
        params ["_values", "_unit"];
        ["FST_zeusMed_apply", [_unit, "pain", _values select 0, clientOwner], _unit] call CBA_fnc_targetEvent;
    }, {}, _unit] call zen_dialog_fnc_create;
}, _icons + "danger_ca.paa"] call zen_custom_modules_fnc_register;

[_cat, "Casualty Scenario", {
    params ["", "_attached"];
    private _unit = [_attached] call FST_zeusMed_fnc_unitFromModule;
    if (isNull _unit) exitWith {};
    private _list = [] call FST_zeusMed_fnc_scenarios;
    private _ids = [];
    { _ids pushBack _forEachIndex; } forEach _list;
    ["41st Medical: casualty scenario", [
        ["COMBO", "Scenario", [_ids, _list apply { [_x select 0, _x select 1] }, 1]]
    ], {
        params ["_values", "_unit"];
        private _index = _values select 0;
        private _s = ([] call FST_zeusMed_fnc_scenarios) select _index;
        if ((_s select 2) && {!isPlayer _unit}) exitWith {
            [objNull, "41st Medical: that scenario is for players only (AI in cardiac arrest die on this server)"] call BIS_fnc_showCuratorFeedbackMessage;
        };
        if ([_unit] call FST_zeusMed_fnc_aiNeedsPlotArmor && {_index > 0}) then {
            ["FST_zeusMed_plotArmor", [_unit, true, clientOwner], _unit] call CBA_fnc_targetEvent;
            systemChat "41st Medical: Plot Armor turned on (an AI knocked out on this server would otherwise die)";
        };
        ["FST_zeusMed_apply", [_unit, "scenario", _index, clientOwner], _unit] call CBA_fnc_targetEvent;
    }, {}, _unit] call zen_dialog_fnc_create;
}, _icons + "help_ca.paa"] call zen_custom_modules_fnc_register;

[_cat, "Cardiac Arrest", {
    params ["", "_attached"];
    private _unit = [_attached] call FST_zeusMed_fnc_unitFromModule;
    if (isNull _unit) exitWith {};
    if (!isPlayer _unit && {!(missionNamespace getVariable ["ace_medical_statemachine_AIUnconsciousness", false])}) exitWith {
        [objNull, "41st Medical: players only - AI in cardiac arrest die at once with this server's ACE settings"] call BIS_fnc_showCuratorFeedbackMessage;
    };
    ["41st Medical: cardiac arrest", [
        ["TOOLBOX:YESNO", [format ["Put %1 into cardiac arrest?", name _unit], "Needs CPR. Dies when the ACE cardiac-arrest timer runs out unless Plot Armor is on."], false]
    ], {
        params ["_values", "_unit"];
        if !((_values select 0) in [true, 1]) exitWith {};
        ["FST_zeusMed_apply", [_unit, "arrest", 0, clientOwner], _unit] call CBA_fnc_targetEvent;
    }, {}, _unit] call zen_dialog_fnc_create;
}, _icons + "kill_ca.paa"] call zen_custom_modules_fnc_register;

[_cat, "Plot Armor", {
    params ["", "_attached"];
    private _unit = [_attached] call FST_zeusMed_fnc_unitFromModule;
    if (isNull _unit) exitWith {};
    private _on = _unit getVariable ["FST_zeusMed_plotArmor", false];
    ["41st Medical: Plot Armor", [
        ["TOOLBOX:YESNO", [format ["Plot Armor for %1 (now %2)", name _unit, ["OFF", "ON"] select _on],
            "ON: can be wounded and knocked down but will not die (blood held at 3.7 L+, no new wounds while down, cardiac-arrest timer frozen). AI: turn on BEFORE the fight; a single fatal hit can still kill an AI that is still up."], !_on]
    ], {
        params ["_values", "_unit"];
        ["FST_zeusMed_plotArmor", [_unit, (_values select 0) in [true, 1], clientOwner], _unit] call CBA_fnc_targetEvent;
    }, {}, _unit] call zen_dialog_fnc_create;
}, _icons + "defend_ca.paa"] call zen_custom_modules_fnc_register;

[_cat, "Spawn Wounded Trooper", {
    params ["_posASL"];
    if !(missionNamespace getVariable ["FST_zeusMed_enabled", true]) exitWith {
        [objNull, "41st Medical: disabled in Addon Options (FST_zeusMed_enabled)"] call BIS_fnc_showCuratorFeedbackMessage;
    };
    private _all = [] call FST_zeusMed_fnc_scenarios;
    private _ids = [];
    { if !(_x select 2) then { _ids pushBack _forEachIndex; }; } forEach _all;
    ["41st Medical: spawn wounded trooper", [
        ["COMBO", ["Injuries", "Spawns a friendly trooper (Addon Options class) with Plot Armor ON, staying put. Turn Plot Armor off if they may die."],
            [_ids, _ids apply { [(_all select _x) select 0, (_all select _x) select 1] }, 1]]
    ], {
        params ["_values", "_posASL"];
        ["FST_zeusMed_spawn", [_posASL, _values select 0, clientOwner]] call CBA_fnc_serverEvent;
    }, {}, _posASL] call zen_dialog_fnc_create;
}, _icons + "meet_ca.paa"] call zen_custom_modules_fnc_register;
