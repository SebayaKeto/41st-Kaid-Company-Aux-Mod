/*
    Project Stonewall - mission integration (optional)                  v1.2.4
    Only for servers WITHOUT the FST_Stonewall addon; with the addon this file does nothing. Prefer the addon:
    this hook creates keep-area markers on the Zeus's PC (they can be lost if that Zeus disconnects before the save)
    and its Save module has no "no answer" notice.

    Copy stonewall_init.sqf + stonewall_save.sqf into <mission>\stonewall\ and add to init.sqf:
        [] execVM "stonewall\stonewall_init.sqf";
    It adds exact "built" / "zeus" tags and the Zen modules "Keep Area" and "Save Mission".
*/
if (isClass (configFile >> "CfgPatches" >> "FST_Stonewall")) exitWith {};  // the addon already does all of this

if (isNil "stonewall_fnc_save") then { stonewall_fnc_save = compileFinal preprocessFileLineNumbers "stonewall\stonewall_save.sqf"; };

// same rules as the addon: tag by the creating machine, skip battlefield litter, one broadcast per object
localNamespace setVariable ["stonewall_trackSkip", ["WeaponHolder", "WeaponHolderSimulated", "Ruins", "Crater",
    "CraterLong", "ACE_Explosives_Place", "MineBase", "CBA_NamespaceDummy", "ACE_bodyBagObject", "ACE_Grave"]];
localNamespace setVariable ["stonewall_trackTag", ["spawned", "built"] select (hasInterface && !isServer)];
addMissionEventHandler ["EntityCreated", {
    params ["_e"];
    if (time > 0 && {local _e} && {_e isKindOf "Static" || {_e isKindOf "Thing"} || {_e isKindOf "StaticWeapon"}}
        && {(localNamespace getVariable ["stonewall_trackSkip", []]) findIf { _e isKindOf _x } < 0}
        && {isNil { _e getVariable "stonewall_src" }}) then {
        private _tag = localNamespace getVariable ["stonewall_trackTag", "spawned"];
        if (_tag == "built" && {!isNull curatorCamera}) then { _tag = "zeus"; };
        _e setVariable ["stonewall_src", _tag, true];
        _e setVariable ["stonewall_born", time];
    };
}];

if (isServer || hasInterface) then {
    [] spawn {
        waitUntil { sleep 1; time > 0 };
        private _done = [];
        while { true } do {
            {
                if !(_x in _done) then {
                    _done pushBack _x;
                    _x addEventHandler ["CuratorObjectPlaced", { (_this#1) setVariable ["stonewall_src", "zeus", true]; }];
                };
            } forEach allCurators;
            sleep 30;
        };
    };
};

if (hasInterface && {!isNil "zen_custom_modules_fnc_register"}) then {
    ["Stonewall", "Keep Area", {
        params ["_pos"];
        ["Stonewall: keep this base", [
            ["EDIT", "Base name", ["FOB"]],
            ["SLIDER:RADIUS", "Radius (m)", [10, 400, 60, 0, ASLToAGL _pos, [0, 0.8, 0, 0.7]]]
        ], {
            params ["_values", "_pos"];
            _values params ["_name", "_radius"];
            private _id = format ["%1_%2", clientOwner, floor (diag_tickTime * 10) mod 100000];
            private _m = createMarker ["stonewall_keep_" + _id, _pos];
            _m setMarkerShape "ELLIPSE";
            _m setMarkerSize [_radius, _radius];
            _m setMarkerBrush "Border";
            _m setMarkerColor "ColorGreen";
            _m setMarkerText _name;
            private _l = createMarker ["stonewall_label_" + _id, _pos];
            _l setMarkerType "mil_flag";
            _l setMarkerColor "ColorGreen";
            _l setMarkerText format ["Stonewall: %1", _name];
            [objNull, format ["Stonewall keep area '%1' (%2 m)", _name, round _radius]] call BIS_fnc_showCuratorFeedbackMessage;
        }, {}, ASLToAGL _pos] call zen_dialog_fnc_create;
    }] call zen_custom_modules_fnc_register;

    ["Stonewall", "Save Mission", {
        ["all"] remoteExecCall ["stonewall_fnc_save", 2];
        [objNull, "Stonewall: saving on the server..."] call BIS_fnc_showCuratorFeedbackMessage;
    }] call zen_custom_modules_fnc_register;
};
