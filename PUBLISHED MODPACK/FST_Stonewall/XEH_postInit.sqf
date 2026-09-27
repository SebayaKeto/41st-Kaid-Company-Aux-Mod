// FST_Stonewall postInit
// Save requests arrive by remoteExecCall ["FST_stonewall_fnc_save", 2]; the function checks remoteExecutedOwner itself.

// Every machine tags the objects IT creates and broadcasts the tag so the server's save can read it:
//   "built"   - created on a player's PC (ACE Fortify and player build mods create there)
//   "zeus"    - created on a player's PC while in the Zeus interface
//   "spawned" - created by the server or a headless client (mission scripts, HCSpawn, Zen compositions); opt-in in clean
// Dropped weapons, ruins, craters and mines are skipped: 800 AI deaths must not mean 800 network broadcasts.
if (missionNamespace getVariable ["FST_stonewall_trackBuilt", true]) then {
    localNamespace setVariable ["FST_stonewall_trackSkip", ["WeaponHolder", "WeaponHolderSimulated", "Ruins", "Crater",
        "CraterLong", "ACE_Explosives_Place", "MineBase", "CBA_NamespaceDummy", "ACE_bodyBagObject", "ACE_Grave"]];
    // a listen-server host has an interface but runs the mission scripts: only a pure client's objects are "built"
    localNamespace setVariable ["FST_stonewall_trackTag", ["spawned", "built"] select (hasInterface && !isServer)];
    addMissionEventHandler ["EntityCreated", {
        params ["_e"];
        if (time > 0 && {local _e} && {_e isKindOf "Static" || {_e isKindOf "Thing"} || {_e isKindOf "StaticWeapon"}}
            && {(localNamespace getVariable ["FST_stonewall_trackSkip", []]) findIf { _e isKindOf _x } < 0}
            && {isNil { _e getVariable "stonewall_src" }}) then {
            private _tag = localNamespace getVariable ["FST_stonewall_trackTag", "spawned"];
            if (_tag == "built" && {!isNull curatorCamera}) then { _tag = "zeus"; };
            _e setVariable ["stonewall_src", _tag, true];         // the one broadcast the server's save needs
            _e setVariable ["stonewall_born", time];              // local only
        };
    }];
};

if (isServer) then {
    // belt and braces for Fortify: ACE also stamps ace_fortify_tokensUsed (public) on every placed object
    ["acex_fortify_objectPlaced", {
        params ["", "", ["_object", objNull]];
        if (!isNull _object) then { _object setVariable ["stonewall_src", "fortify", true]; };
    }] call CBA_fnc_addEventHandler;
};

if (hasInterface) then {
    ["FST_stonewall_log", { { diag_log text _x; } forEach (_this select 0); }] call CBA_fnc_addEventHandler;
    ["FST_stonewall_done", {
        params ["_msg"];
        localNamespace setVariable ["FST_stonewall_lastReply", diag_tickTime];
        systemChat _msg;
        if (!isNull (findDisplay 312)) then { [objNull, _msg] call BIS_fnc_showCuratorFeedbackMessage; };
    }] call CBA_fnc_addEventHandler;
    [] call FST_stonewall_fnc_registerModules;
};

// Zeus-placed objects are tagged "zeus" (curators can appear later, so re-check every 30 s)
if (isServer || hasInterface) then {
    [] spawn {
        private _done = [];
        while { true } do {
            {
                if !(_x in _done) then {
                    _done pushBack _x;
                    _x addEventHandler ["CuratorObjectPlaced", { (_this select 1) setVariable ["stonewall_src", "zeus", true]; }];
                };
            } forEach allCurators;
            sleep 30;
        };
    };
};
