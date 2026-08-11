// All Credit for this Script goes to Viper/MatthewL. Used with Permission. 

["[41st] Droid Modules", "Munificent QRF Deployment",
    {
        params [["_pos", [0, 0, 0], [[]], 3], ["_logic", objNull, [objNull]]];
        _options = ["Basic", "Basic Dumb", "Geonosis", "Geonosis Dumb", "Commandos", "Jorge", "B2"];

        ["Quick Reaction Force Deployment (Munificent)", [
            // Direction / side / droid type
            ["TOOLBOX", ["Direction", "Select one or more directions."], [0, 1, 8, ["N", "NE", "E", "SE", "S", "SW", "W", "NW"]]],
            ["sideS",   ["Side select (ONLY ONE!)", "The side the spawned dropped units will be on."], [east]],
            ["TOOLBOX", ["Type select", "What type of Droids to spawn."], [3, 3, 3, _options, nil]],

            // Drop pods
            ["SLIDER",  ["Drop pod Amount", "How many drop pods will be Deployed"], [0, 24, 8, 0]],
            ["CHECKBOX", ["Linger", "Stays at the landing zone and spawns Droids unless destroyed."], [true]],

            // Vultures
            ["SLIDER",  ["Amount of Vultures", "How many Vultures will be Deployed"], [0, 16, 2, 0]],
            ["TOOLBOX", ["Vulture Type", "Select the type of Vultures to deploy."], [0, ["Standard", "AA Mixed"]]],
            ["TOOLBOX", ["Vulture Skill", "Select the skill level of the Vultures' crew."], [0, ["Default", "Maximum"]]],

            // Ship behavior
            ["CHECKBOX", ["Armed Ship?", "Should the Munificent have turrets spawned?"], [true]],
            ["CHECKBOX", ["Jump Ship Out Afterwards?", "The ship will leave after it has deployed the troops"], [true]],

            // Turret count
            ["SLIDER", ["Number of Turrets", "Number of turrets that will spawn on the Munificent. Ignored if Custom Turrets + Custom Turret Positions are both enabled and at least one per-type count below is set."], [0, 10, 2, 0]],

            // Custom turret classnames
            ["CHECKBOX", ["Custom Turrets?", "If enabled, turret classnames will be pulled from the CBA addon settings instead of the faction default."], [false]],

            // Custom turret positions
            ["CHECKBOX", ["Use Custom Turret Positions?", "If enabled, turrets spawn at fixed hand-placed mount points on the hull instead of being auto-spaced. Edit FST_Munificent_TurretPositions in Modules.sqf to tune them."], [false]],

            // Per-type turret counts
            ["SLIDER", ["DF9 Rocket Turrets", "Number of FST_DF9_Rocket turrets to spawn. Only used when Custom Turrets + Custom Turret Positions are both enabled."], [0, 10, 0, 0]],
            ["SLIDER", ["Inverted PD Turrets", "Number of FST_CIS_PD_Turret_Inverted turrets to spawn. Only used when Custom Turrets + Custom Turret Positions are both enabled."], [0, 10, 0, 0]],
            ["SLIDER", ["PD Turrets", "Number of FST_CIS_PD_Turret turrets to spawn. Only used when Custom Turrets + Custom Turret Positions are both enabled."], [0, 10, 0, 0]],

            // Placement bias
            ["COMBO", ["Placement Bias", "Which hull mount points are prioritised. Only affects turrets when Custom Turret Positions is enabled."], [
                [0, 1, 2, 3, 4, 5],
                ["Portside", "Starboard", "Underside", "TopSide", "Random", "Balanced"]
            ]],

            // Ship HP
            ["SLIDER", ["Ship HP", "HP pool for the ship. Stored as this value x100 internally (e.g. 25 = 2500 HP). Default is the CBA addon setting."], [1, 5000, 25, 0]],

            // Death condition
            ["TOOLBOX", ["Death Condition", "What happens when the ship is destroyed. Crash Ship = falls from the sky. Retreat = jumps out."], [0, 1, 2, ["Crash Ship", "Retreat (Jump Out)"], nil]],

            // Timing
            ["SLIDER", ["Deployment Delay", "Seconds before the ship jumps in. An early-warning message will broadcast a rounded ETA to all curators."], [0, 30, 0, 0]],
            ["SLIDER", ["Arming Delay", "Seconds after jump-in before the ship's weapons come online."], [0, 30, 0, 0]]

            ], {
                params ["_values", "_arguments"];

                // Original parameters
                _direction         = _values # 0;
                _Ship_direction    = [0, 45, 90, 135, 180, 225, 270, 315] # _direction;
                _dropside          = _values select 1;
                _LightPodSelection = _values select 2;
                _AmountofLightPods = _values select 3;
                _linger            = _values select 4;
                _AmountofBanshees  = _values select 5;
                _VultureType       = _values select 6;
                _VultureSkill      = _values select 7;
                _ArmedShip         = _values select 8;
                _EndWithJumpOut    = _values select 9;

                // Turret / ship settings
                _NumberOfTurrets          = _values select 10;
                _UseCustomTurret          = _values select 11;
                _UseCustomTurretPositions = _values select 12;
                _DF9RocketCount           = _values select 13;
                _InvertedPDCount          = _values select 14;
                _PDCount                  = _values select 15;
                _PlacementBias            = _values select 16;
                _ShipHealthMult           = _values select 17;
                _DeathCondition           = _values select 18;

                // Timing
                _DeploymentDelay = _values select 19;
                _ArmingDelay     = _values select 20;

                // Editor position
                _position = _arguments select 0;

                // We can still use remoteExecCall:
                [
                    _position,
                    _Ship_direction,
                    _dropside,
                    _LightPodSelection,
                    _AmountofLightPods,
                    _linger,
                    _AmountofBanshees,
                    _VultureType,
                    _VultureSkill,
                    _ArmedShip,
                    _EndWithJumpOut,
                    _NumberOfTurrets,
                    _UseCustomTurret,
                    _UseCustomTurretPositions,
                    _DF9RocketCount,
                    _InvertedPDCount,
                    _PDCount,
                    _PlacementBias,
                    _ShipHealthMult,
                    _DeathCondition,
                    _DeploymentDelay,
                    _ArmingDelay
                ] remoteExecCall ["FST_ScifiSupportPlus_fnc_SW_Munificent_QRF", 2];

            }, {}, [_pos, _logic]] call zen_dialog_fnc_create;
    },
    "\PHAN_ScifiSupportPlus\data\Droid.paa"
] call zen_custom_modules_fnc_register;


// Turret mount points, per classname, in CoreOBJ model space [x, y, z]
FST_Munificent_TurretPositions = [
    ["FST_DF9_Rocket", [
        [-41.0663, -58.5991, 377.5],
        [-41.0664, -83.5784, 377.506],
        [-68.7698, -83.5784, 376.765],
        [-41.0664, -104.707, 377.506],
        [-105.865, -83.5784, 376.245],
        [40.0502, -58.599, 377.506],
        [40.05, -83.5784, 377.506],
        [40.05, -104.707, 377.506],
        [-144.355, -83.5785, 375.633],
        [71.9941, -83.5787, 376.768],
        [-188.425, -66.4404, 375.133],
        [-188.425, -66.5181, 370.383],
        [-188.425, -90.4008, 375.133],
        [-188.425, -90.4786, 370.383],
        [109.09, -83.579, 376.245],
        [0.753418, -179.967, 464.508],
        [0.753418, -195.715, 464.508],
        [-5.36218, 103.941, 412.151],
        [4.88403, 103.941, 412.151],
        [0.75354, -212.712, 464.508],
        [-5.36206, 121.75, 412.151],
        [4.88403, 121.75, 412.148],
        [147.58, -83.579, 375.639],
        [-5.36206, 138.935, 412.151],
        [4.88416, 138.935, 412.151],
        [190.46, -66.4404, 375.133],
        [190.46, -66.5182, 370.383],
        [190.46, -90.4007, 375.133],
        [190.46, -90.4785, 370.383]
    ]],
    ["FST_CIS_PD_Turret_Inverted", [
        [-65.6879, -54.9559, 368.815],
        [-65.688, -99.2803, 368.765],
        [-90.7169, -61.322, 369.29],
        [-90.717, -95.1487, 369.29],
        [-116.804, -63.6015, 369.804],
        [-115.428, -92.9911, 369.79],
        [61.6709, -59.3992, 368.957],
        [-144.8, -66.9739, 370.345],
        [-144.346, -92.9913, 370.237],
        [61.8658, -99.2805, 368.775],
        [-175.312, -67.025, 370.906],
        [94.751, -61.4478, 369.797],
        [-174.33, -95.1486, 370.618],
        [95.6727, -96.5809, 369.326],
        [122.747, -63.6014, 370.253],
        [123.457, -94.0623, 369.719],
        [149.499, -65.8668, 370.69],
        [149.596, -94.0623, 370.142],
        [-0.299438, -179.742, 235.221],
        [-0.299561, -213.504, 235.221],
        [176.28, -68.0126, 369.82],
        [174.478, -94.0621, 370.772]
    ]],
    ["FST_CIS_PD_Turret", [
        [-70.1268, -64.2123, 376.297],
        [-70.1268, -101.737, 376.287],
        [-105.006, -64.2123, 375.953],
        [-105.006, -96.0816, 375.953],
        [-132.466, -93.2921, 375.35],
        [-140.728, -64.2123, 375.349],
        [62.3228, -64.2124, 376.297],
        [62.3229, -101.361, 376.297],
        [-154.957, -97.7153, 375.085],
        [-170.518, -64.2124, 375.095],
        [-174.472, -93.5244, 375.095],
        [101.202, -65.7638, 376.03],
        [101.202, -95.3251, 376.03],
        [131.818, -91.818, 375.389],
        [140.178, -65.7638, 375.383],
        [153.619, -100.037, 375.053],
        [175.884, -65.7637, 375.053],
        [175.884, -95.7954, 375.053],
        [-0.365234, 170.301, 414.78],
        [-0.365234, 209.548, 420.844],
        [-8.24243, 278.423, 446.367],
        [9.21265, 278.423, 446.36],
        [-8.24231, 293.219, 446.363],
        [9.21277, 293.218, 446.36]
    ]]
];

// Per-class turret spawn Z correction
FST_Munificent_TurretZCorrection = [
    ["FST_DF9_Rocket", -339],
    ["FST_CIS_PD_Turret_Inverted", -344],
    ["FST_CIS_PD_Turret", -339]
];

FST_ScifiSupportPlus_fnc_SW_Munificent_QRF = {
    // -------------------------------------------------
    // 1) Parse all parameters
    // -------------------------------------------------
    params [
        "_position",
        "_Ship_direction",
        "_dropside",
        "_LightPodSelection",
        "_AmountofLightPods",
        "_linger",
        "_AmountofBanshees",
        "_VultureType",
        "_VultureSkill",
        "_ArmedShip",
        "_EndWithJumpOut",
        ["_NumberOfTurrets", 1],
        ["_UseCustomTurret", false],
        ["_UseCustomTurretPositions", false],
        ["_DF9RocketCount", 0],
        ["_InvertedPDCount", 0],
        ["_PDCount", 0],
        ["_PlacementBias", 4],               // 4 = Random
        ["_ShipHealthMult", 25],             // x100 internally
        ["_DeathCondition", 0],              // 0 = crash, 1 = retreat
        ["_DeploymentDelay", 0],
        ["_ArmingDelay", 0]
    ];

    // Convert ASL coords to ATL
    _position = ASLtoATL _position;

    // -------------------------------------------------
    // 2) Spawn a scheduled block (deployment delay, jump-in, arming, sleeps)
    // -------------------------------------------------
    [
        _position,
        _Ship_direction,
        _dropside,
        _LightPodSelection,
        _AmountofLightPods,
        _linger,
        _AmountofBanshees,
        _VultureType,
        _VultureSkill,
        _EndWithJumpOut,
        _ArmedShip,
        _NumberOfTurrets,
        _UseCustomTurret,
        _UseCustomTurretPositions,
        _DF9RocketCount,
        _InvertedPDCount,
        _PDCount,
        _PlacementBias,
        _ShipHealthMult,
        _DeathCondition,
        _DeploymentDelay,
        _ArmingDelay
    ] spawn {
        params [
            "_position",
            "_Ship_direction",
            "_dropside",
            "_LightPodSelection",
            "_AmountofLightPods",
            "_linger",
            "_AmountofBanshees",
            "_VultureType",
            "_VultureSkill",
            "_EndWithJumpOut",
            "_ArmedShip",
            "_NumberOfTurrets",
            "_UseCustomTurret",
            "_UseCustomTurretPositions",
            "_DF9RocketCount",
            "_InvertedPDCount",
            "_PDCount",
            "_PlacementBias",
            "_ShipHealthMult",
            "_DeathCondition",
            "_DeploymentDelay",
            "_ArmingDelay"
        ];

        // Early-warning broadcast then wait
        if (_DeploymentDelay > 0) then {
            private _roundedTime = (round (_DeploymentDelay / 10)) * 10;
            private _etaStr = if (_roundedTime == 0) then {"imminent"} else {format ["%1 seconds", _roundedTime]};
            [[format ["<t color='#109600'>Serenity Actual: Munificent-class warship detected on long-range sensors — ETA approximately %1. Fynock, prepare yourselves!</t>", _etaStr]]] remoteExec ["BIS_fnc_typeText", 0];
            sleep _DeploymentDelay;
        };

        private _ReturnShip = [
            _position,
            _Ship_direction,
            900,
            "ls_munificent",
            _dropside
        ] call SciFiSupportPLUS_fnc_JumpShipIn;

        // Wait until the ship is fully spawned and alive before configuring it
        waitUntil { !isNull _ReturnShip && { alive _ReturnShip } };

        // Arming delay — weapons held until this elapses
        if (_ArmingDelay > 0) then { sleep _ArmingDelay; };

        // Armed ship setup
        if (_ArmedShip) then {
            [
                _ReturnShip,
                false,               // targetInfantry
                true,                // targetVehicle
                false,               // AddTurret: we handle this ourselves
                _NumberOfTurrets,    // param still needed for FTL_SupportShip internals
                false,               // AddTurret_UseCustom
                _ShipHealthMult,     // Custom HP pool (stored x100 internally)
                _DeathCondition      // 0 = crash gracefully, 1 = retreat (jump out)
            ] call ScifiSupportPLUS_FTL_SupportShip;

            // Turret spawning
            [_ReturnShip, _NumberOfTurrets, _UseCustomTurret, _UseCustomTurretPositions, _DF9RocketCount, _InvertedPDCount, _PDCount, _PlacementBias, _dropside] spawn {
                params ["_ship", "_count", "_useCustom", "_useCustomPositions", "_df9Count", "_invertedPDCount", "_pdCount", "_placementBias", "_dropside"];

                // Weighted turret class list
                private _turretClassList = [];
                if (_useCustom && (count ScifiSupportPlus_SupportShip_CustomTurretArray > 0)) then {
                    _turretClassList = ScifiSupportPlus_SupportShip_CustomTurretArray;
                } else {
                    _turretClassList = ["3AS_CIS_Naval_Gun_180"];
                };

                // Turret spawn queue
                private _turretQueue = [];
                if (_useCustom && _useCustomPositions && ((_df9Count + _invertedPDCount + _pdCount) > 0)) then {
                    for "_n" from 1 to _df9Count do { _turretQueue pushBack "FST_DF9_Rocket"; };
                    for "_n" from 1 to _invertedPDCount do { _turretQueue pushBack "FST_CIS_PD_Turret_Inverted"; };
                    for "_n" from 1 to _pdCount do { _turretQueue pushBack "FST_CIS_PD_Turret"; };
                } else {
                    for "_n" from 1 to _count do { _turretQueue pushBack (selectRandom _turretClassList); };
                };
                if (count _turretQueue < 1) exitWith {};

                // Placement bias helpers
                private _fnc_isPort = { (_this select 0) < 0 };
                private _fnc_isUnderside = {
                    params ["_cls", "_pos"];
                    switch (_cls) do {
                        case "FST_CIS_PD_Turret_Inverted": { true };
                        case "FST_DF9_Rocket": { (_pos select 2) < 400 };
                        default { false };
                    };
                };

                // Bias-ordered positions per class
                private _biasedPositionsByClass = [];
                {
                    _x params ["_cls", "_positions"];
                    private _ordered = switch (_placementBias) do {
                        case 4: { +_positions call BIS_fnc_arrayShuffle }; // Random
                        case 5: { // Balanced -- round robin across 4 quadrants
                            private _quad = [[], [], [], []]; // PortTop, PortUnder, StarTop, StarUnder
                            {
                                private _port = _x call _fnc_isPort;
                                private _under = [_cls, _x] call _fnc_isUnderside;
                                private _qi = (if (_port) then {0} else {2}) + (if (_under) then {1} else {0});
                                (_quad select _qi) pushBack _x;
                            } forEach _positions;
                            private _out = [];
                            private _more = true;
                            while {_more} do {
                                _more = false;
                                { if (count _x > 0) then { _out pushBack (_x deleteAt 0); _more = true; }; } forEach _quad;
                            };
                            _out
                        };
                        default { // Portside / Starboard / Underside / TopSide
                            private _match = [];
                            private _rest = [];
                            {
                                private _isMatch = switch (_placementBias) do {
                                    case 0: { _x call _fnc_isPort };
                                    case 1: { !(_x call _fnc_isPort) };
                                    case 2: { [_cls, _x] call _fnc_isUnderside };
                                    case 3: { !([_cls, _x] call _fnc_isUnderside) };
                                    default { true };
                                };
                                if (_isMatch) then { _match pushBack _x } else { _rest pushBack _x };
                            } forEach _positions;
                            _match + _rest
                        };
                    };
                    _biasedPositionsByClass pushBack [_cls, _ordered];
                } forEach FST_Munificent_TurretPositions;

                // Per-class position cursors
                private _classCursors = [];

                private _turrets = [];
                for "_i" from 0 to ((count _turretQueue) - 1) do {
                    private _turretClass = _turretQueue select _i;

                    // Target local position
                    private _localPos = [];
                    private _placed = false;
                    if (_useCustomPositions) then {
                        private _classEntryIdx = _biasedPositionsByClass findIf {(_x select 0) == _turretClass};
                        if (_classEntryIdx != -1) then {
                            private _classPositions = (_biasedPositionsByClass select _classEntryIdx) select 1;
                            if (count _classPositions > 0) then {
                                private _cursorIdx = _classCursors findIf {(_x select 0) == _turretClass};
                                private _cursor = 0;
                                if (_cursorIdx != -1) then { _cursor = (_classCursors select _cursorIdx) select 1; };

                                _localPos = _classPositions select (_cursor mod (count _classPositions));
                                _placed = true;

                                if (_cursorIdx != -1) then {
                                    (_classCursors select _cursorIdx) set [1, _cursor + 1];
                                } else {
                                    _classCursors pushBack [_turretClass, _cursor + 1];
                                };
                            };
                        };
                    };
                    if (!_placed) then {
                        // Auto-spacing fallback
                        private _offsetY = (_i - ((count _turretQueue) - 1) / 2) * 80;
                        private _offsetX = [25, -25] select ((_i mod 2) != 0);
                        _localPos = [_offsetX, _offsetY, 0];
                    };

                    // Z correction
                    private _zCorrIdx = FST_Munificent_TurretZCorrection findIf {(_x select 0) == _turretClass};
                    if (_zCorrIdx != -1) then {
                        _localPos = [_localPos#0, _localPos#1, (_localPos#2) + ((FST_Munificent_TurretZCorrection select _zCorrIdx) select 1)];
                    };

                    // Spawn and attach
                    private _turret = createVehicle [_turretClass, (_ship modelToWorld _localPos), [], 0, "NONE"];
                    _turret setVectorUp [0, 0, 1];
                    _turret attachTo [_ship, _localPos];
                    [_turret, _ship] remoteExecCall ["disableCollisionWith", 0];

                    createVehicleCrew _turret;
                    [_turret] joinSilent (group _ship);
                    _turret allowCrewInImmobile [true, true];

                    // Full radar so turrets detect air targets
                    _turret setVehicleRadar 15;
                    vehicle _turret setVehicleReportRemoteTargets true;
                    vehicle _turret setVehicleReceiveRemoteTargets true;
                    vehicle _turret setVehicleReportOwnPosition true;
                    { vehicle _turret enableVehicleSensor [(_x select 0), true]; } forEach (listVehicleSensors _turret);

                    // Skills
                    _turret setSkill ["courage", 1];
                    _turret setSkill ["aimingAccuracy", 0];
                    _turret setSkill ["aimingSpeed", 1];
                    _turret setSkill ["spotDistance", 1];
                    _turret setSkill ["spotTime", 1];

                    // DS and AI -- JumpShipIn disables DS on the ship group globally.
                    // Since we run server-side we must re-enable it explicitly.
                    [_turret, true] remoteExec ["enableDynamicSimulation", 0];
                    { [_x, true] remoteExec ["enableDynamicSimulation", 0]; } forEach crew _turret;

                    // Turret AI firing loop (mirrors FTL_SupportShip behaviour)
                    [_turret, _ship] spawn {
                        params ["_turret", "_ship"];
                        while {alive _turret} do {
                            if (isNil {_ship getVariable "FTL_stopFiring"}) then {
                                if (combatMode (group _turret) != "RED") then {
                                    (group _turret) setCombatMode "RED";
                                    (group _turret) setBehaviour "AWARE";
                                    { [_x, "AUTOCOMBAT"] remoteExecCall ["enableAI", 0]; [_x, "AUTOTARGET"] remoteExecCall ["enableAI", 0]; [_x, "TARGET"] remoteExecCall ["enableAI", 0]; [_x, "FIREWEAPON"] remoteExecCall ["enableAI", 0]; } forEach crew _turret;
                                };
                            };
                            sleep 1;
                        };
                    };

                    _turrets pushBack _turret;
                    sleep 0.1;
                };

                // Store on ship for Killed/Deleted EH cleanup
                _ship setVariable ["FTL_ExtraTurretOBJ", _turrets, true];
            };
        };

        // ---- Now we can safely sleep: ----
        sleep 6;

        // Pod attachments
        _PodLocation1  = [50.123,   -100.456,  -85.789];
        _PodLocation2  = [-60.789,  -30.123,   -65.456];
        _PodLocation3  = [90.456,   -70.789,   -80.123];
        _PodLocation4  = [-110.789, -55.456,   -75.789];
        _PodLocation5  = [5.789,    15.123,    -70.456];
        _PodLocation6  = [-95.456,  -115.789,  -78.123];
        _PodLocation7  = [65.789,   -35.456,   -72.789];
        _PodLocation8  = [-20.456,  -80.789,   -85.456];
        _PodLocation9  = [85.123,   50.456,    -70.789];
        _PodLocation10 = [-75.789,  5.123,     -68.456];
        _PodLocation11 = [35.456,   -20.789,   -76.789];
        _PodLocation12 = [-70.123,  45.456,    -73.789];
        _PodLocation13 = [120.789,  -10.456,   -79.456];
        _PodLocation14 = [-40.456,  -90.789,   -81.123];
        _PodLocation15 = [75.789,   -55.456,   -77.789];
        _PodLocation16 = [-10.123,  80.789,    -69.456];

        _PodArray = [];

        // Function to attach a particle source to each "pod" point
        createandAttachParticleSource = {
            params ["_podobject", "_location"];
            _modelData = _podobject modelToWorld _location;
            _particleSource = "#particleSource" createVehicle _modelData;
            _particleSource attachTo [_podobject, _location];
            _particleSource
        };

        // Put them in an array
        _podLocations = [
            _PodLocation1, _PodLocation2, _PodLocation3, _PodLocation4,
            _PodLocation5, _PodLocation6, _PodLocation7, _PodLocation8,
            _PodLocation9, _PodLocation10,_PodLocation11,_PodLocation12,
            _PodLocation13,_PodLocation14,_PodLocation15,_PodLocation16
        ];

        // Attach each effect
        {
            _PodArray pushBack ([_ReturnShip, _x] call createandAttachParticleSource);
        } forEach _podLocations;

        // Clean them up if the ship dies
        [_ReturnShip, _PodArray] spawn {
            params ["_ReturnShip", "_PodArray"];
            waitUntil {
                sleep 1;
                !alive _ReturnShip || isNull _ReturnShip
            };
            {
                deleteVehicle _x;
                sleep 0.01;
            } forEach _PodArray;
        };

        // -------------------------------------------------
        // 4) Drop pods if any
        // -------------------------------------------------
        if (_AmountofLightPods > 0) then {
            for "_LightPoddropper" from 1 to _AmountofLightPods do {
                _randomIndex = floor (random (count _PodArray));
                _randomPodLocation = _PodArray select _randomIndex;
                _PodArray deleteAt _randomIndex;

                _currentposition = [
                    (getPosATL _randomPodLocation select 0),
                    (getPosATL _randomPodLocation select 1),
                    0
                ];

                if (_linger) then {
                    [_currentposition, _dropside, _LightPodSelection, true] call FST_Droid_Dispenser;
                } else {
                    [_currentposition, _dropside, _LightPodSelection, false] call FST_Droid_Dispenser;
                };
                sleep 1;
            };
        };

        // -------------------------------------------------
        // 5) Spawn Vultures if any
        // -------------------------------------------------
        if (_AmountofBanshees > 0) then {
            private _vultureClasses = [];
            if (_VultureType == 0) then {
                // Standard
                for "_i" from 1 to _AmountofBanshees do {
                    _vultureClasses pushBack "3AS_CIS_Vulture_F";
                };
            } else {
                // AA Mixed
                private _aaVultureCount = floor (_AmountofBanshees * 0.33);
                private _standardVultureCount = _AmountofBanshees - _aaVultureCount;
                for "_i" from 1 to _aaVultureCount do {
                    _vultureClasses pushBack "3AS_CIS_Vulture_AA_F";
                };
                for "_i" from 1 to _standardVultureCount do {
                    _vultureClasses pushBack "3AS_CIS_Vulture_F";
                };
                _vultureClasses = _vultureClasses call BIS_fnc_arrayShuffle;
            };

            {
                private _vultureClass = _x;
                [_ReturnShip, _dropside, _vultureClass, _VultureSkill] spawn {
                    params ["_ReturnShip", "_dropside", "_vultureClass", "_VultureSkill"];
                    _currentPosition = getPosATL _ReturnShip;

                    _Banshee = createVehicle [_vultureClass, _currentPosition, [], 0, "CAN_COLLIDE"];
                    (_dropside select 0) createVehicleCrew _Banshee;

                    // sleep 3: the DS fix fires ~15 remoteExec calls per turret all at once
                    // once FTL_ExtraTurretOBJ is populated. With 10 turrets that is ~150
                    // operations in a burst. Even though engineOn is local, the scheduler
                    // needs enough breathing room to process it cleanly. 3 seconds is
                    // safe -- the outer loop has sleep 5 between each vulture anyway.
                    sleep 3;

                    if (_VultureSkill == 1) then {
                        // "Maximum skill"
                        {
                            _x setSkill 1.0;
                        } forEach crew _Banshee;
                    };
                    (group _Banshee) setCombatMode "RED";
                    (group _Banshee) setBehaviour "AWARE";
                    _Banshee engineOn true;
                };
                sleep 5;
            } forEach _vultureClasses;
        };

        // -------------------------------------------------
        // 6) Wait, then optionally jump out
        // -------------------------------------------------
        // This line is often spelled incorrectly; ensure correct parentheses:
        sleep ((_AmountofLightPods * 1) + (_AmountofBanshees * 5) + 1);

        if (_EndWithJumpOut) then {
            [objNull, "Serenity Actual: Munificent overhead, they've dropped droids and are retreating!"] call BIS_fnc_showCuratorFeedbackMessage;

            // FIX: turrets end up at map edge when jumping out.
            // JumpOut calls deleteVehicle on the CoreOBJ. Arma detaches all attached
            // children before firing the Deleted EH. The EH's cleanup block is async
            // (spawned), so by the time it runs the entity is fully deleted and
            // getVariable returns nothing -- turrets are never cleaned up.
            // We capture the turret array NOW while the ship is still alive, then
            // watch for the ship to be deleted and clean up ourselves.
            private _turretArrayForCleanup = _ReturnShip getVariable ["FTL_ExtraTurretOBJ", []];
            [_ReturnShip, _turretArrayForCleanup] spawn {
                params ["_ship", "_turrets"];
                waitUntil { sleep 1; isNull _ship };
                { deleteVehicleCrew _x; deleteVehicle _x; } forEach _turrets;
            };

            [_ReturnShip] call SciFiSupportPLUS_fnc_JumpOut;
        } else {
            [objNull, "Serenity Actual: Munificent overhead, they've dropped droid pods!"] call BIS_fnc_showCuratorFeedbackMessage;
        };
    };
};




// =====================================================================
// PROVIDENCE QRF DEPLOYMENT
// =====================================================================

["[41st] Droid Modules", "Providence QRF Deployment",
    {
        params [["_pos", [0, 0, 0], [[]], 3], ["_logic", objNull, [objNull]]];
        _options = ["Basic", "Basic Dumb", "Geonosis", "Geonosis Dumb", "Commandos", "Jorge", "B2"];

        ["Quick Reaction Force Deployment (Providence)", [
            // Direction / side / droid type
            ["TOOLBOX", ["Direction", "Select one or more directions."], [0, 1, 8, ["N", "NE", "E", "SE", "S", "SW", "W", "NW"]]],
            ["sideS",   ["Side select (ONLY ONE!)", "The side the spawned dropped units will be on."], [east]],
            ["TOOLBOX", ["Type select", "What type of Droids to spawn."], [3, 3, 3, _options, nil]],

            // Drop pods
            ["SLIDER",  ["Drop pod Amount", "How many drop pods will be Deployed"], [0, 24, 8, 0]],
            ["CHECKBOX", ["Linger", "Stays at the landing zone and spawns Droids unless destroyed."], [true]],

            // Vultures
            ["SLIDER",  ["Amount of Vultures", "How many Vultures will be Deployed"], [0, 16, 2, 0]],
            ["TOOLBOX", ["Vulture Type", "Select the type of Vultures to deploy."], [0, ["Standard", "AA Mixed"]]],
            ["TOOLBOX", ["Vulture Skill", "Select the skill level of the Vultures' crew."], [0, ["Default", "Maximum"]]],

            // Ship behavior
            ["CHECKBOX", ["Armed Ship?", "Should the Providence have turrets spawned?"], [true]],
            ["CHECKBOX", ["Jump Ship Out Afterwards?", "The ship will leave after it has deployed the troops"], [true]],

            // Turret count
            ["SLIDER", ["Number of Turrets", "Number of turrets that will spawn on the Providence. Ignored if Custom Turrets + Custom Turret Positions are both enabled and at least one per-type count below is set."], [0, 15, 2, 0]],

            // Custom turret classnames
            ["CHECKBOX", ["Custom Turrets?", "If enabled, turret classnames will be pulled from the CBA addon settings instead of the faction default."], [false]],

            // Custom turret positions
            ["CHECKBOX", ["Use Custom Turret Positions?", "If enabled, turrets spawn at fixed hand-placed mount points on the hull instead of being auto-spaced. Edit FST_Providence_TurretPositions in Modules.sqf to tune them."], [false]],

            // Per-type turret counts
            ["SLIDER", ["DF9 Rocket Turrets", "Number of FST_DF9_Rocket turrets to spawn. Only used when Custom Turrets + Custom Turret Positions are both enabled."], [0, 15, 0, 0]],
            ["SLIDER", ["Inverted PD Turrets", "Number of FST_CIS_PD_Turret_Inverted turrets to spawn. Only used when Custom Turrets + Custom Turret Positions are both enabled."], [0, 15, 0, 0]],
            ["SLIDER", ["PD Turrets", "Number of FST_CIS_PD_Turret turrets to spawn. Only used when Custom Turrets + Custom Turret Positions are both enabled."], [0, 15, 0, 0]],

            // Placement bias
            ["COMBO", ["Placement Bias", "Which hull mount points are prioritised. Only affects turrets when Custom Turret Positions is enabled."], [
                [0, 1, 2, 3, 4, 5],
                ["Portside", "Starboard", "Underside", "TopSide", "Random", "Balanced"]
            ]],

            // Ship HP
            ["SLIDER", ["Ship HP", "HP pool for the ship. Stored as this value x100 internally (e.g. 25 = 2500 HP). Default is the CBA addon setting."], [1, 5000, 25, 0]],

            // Death condition
            ["TOOLBOX", ["Death Condition", "What happens when the ship is destroyed. Crash Ship = falls from the sky. Retreat = jumps out."], [0, 1, 2, ["Crash Ship", "Retreat (Jump Out)"], nil]],

            // Timing
            ["SLIDER", ["Deployment Delay", "Seconds before the ship jumps in. An early-warning message will broadcast a rounded ETA to all curators."], [0, 30, 0, 0]],
            ["SLIDER", ["Arming Delay", "Seconds after jump-in before the ship's weapons come online."], [0, 30, 0, 0]]

            ], {
                params ["_values", "_arguments"];

                _direction         = _values # 0;
                _Ship_direction    = [0, 45, 90, 135, 180, 225, 270, 315] # _direction;
                _dropside          = _values select 1;
                _LightPodSelection = _values select 2;
                _AmountofLightPods = _values select 3;
                _linger            = _values select 4;
                _AmountofBanshees  = _values select 5;
                _VultureType       = _values select 6;
                _VultureSkill      = _values select 7;
                _ArmedShip         = _values select 8;
                _EndWithJumpOut    = _values select 9;

                _NumberOfTurrets          = _values select 10;
                _UseCustomTurret          = _values select 11;
                _UseCustomTurretPositions = _values select 12;
                _DF9RocketCount           = _values select 13;
                _InvertedPDCount          = _values select 14;
                _PDCount                  = _values select 15;
                _PlacementBias            = _values select 16;
                _ShipHealthMult           = _values select 17;
                _DeathCondition           = _values select 18;

                // Timing
                _DeploymentDelay = _values select 19;
                _ArmingDelay     = _values select 20;

                _position = _arguments select 0;

                [
                    _position,
                    _Ship_direction,
                    _dropside,
                    _LightPodSelection,
                    _AmountofLightPods,
                    _linger,
                    _AmountofBanshees,
                    _VultureType,
                    _VultureSkill,
                    _ArmedShip,
                    _EndWithJumpOut,
                    _NumberOfTurrets,
                    _UseCustomTurret,
                    _UseCustomTurretPositions,
                    _DF9RocketCount,
                    _InvertedPDCount,
                    _PDCount,
                    _PlacementBias,
                    _ShipHealthMult,
                    _DeathCondition,
                    _DeploymentDelay,
                    _ArmingDelay
                ] remoteExecCall ["FST_ScifiSupportPlus_fnc_SW_Providence_QRF", 2];

            }, {}, [_pos, _logic]] call zen_dialog_fnc_create;
    },
    "\PHAN_ScifiSupportPlus\data\Droid.paa"
] call zen_custom_modules_fnc_register;


// Turret mount points for the Providence, per classname, in CoreOBJ model space [x, y, z]
// TODO: populate with actual mount-point coordinates once measured
FST_Providence_TurretPositions = [
    ["FST_DF9_Rocket",            []],
    ["FST_CIS_PD_Turret_Inverted", []],
    ["FST_CIS_PD_Turret",          []]
];

// Per-class turret spawn Z correction
// TODO: measure and fill in correct offsets for the Providence model
FST_Providence_TurretZCorrection = [
    ["FST_DF9_Rocket",            0],
    ["FST_CIS_PD_Turret_Inverted", 0],
    ["FST_CIS_PD_Turret",          0]
];

FST_ScifiSupportPlus_fnc_SW_Providence_QRF = {
    // -------------------------------------------------
    // 1) Parse all parameters
    // -------------------------------------------------
    params [
        "_position",
        "_Ship_direction",
        "_dropside",
        "_LightPodSelection",
        "_AmountofLightPods",
        "_linger",
        "_AmountofBanshees",
        "_VultureType",
        "_VultureSkill",
        "_ArmedShip",
        "_EndWithJumpOut",
        ["_NumberOfTurrets", 1],
        ["_UseCustomTurret", false],
        ["_UseCustomTurretPositions", false],
        ["_DF9RocketCount", 0],
        ["_InvertedPDCount", 0],
        ["_PDCount", 0],
        ["_PlacementBias", 4],
        ["_ShipHealthMult", 25],
        ["_DeathCondition", 0],
        ["_DeploymentDelay", 0],
        ["_ArmingDelay", 0]
    ];

    _position = ASLtoATL _position;

    // -------------------------------------------------
    // 2) Spawn a scheduled block (deployment delay, jump-in, arming, sleeps)
    // -------------------------------------------------
    [
        _position,
        _Ship_direction,
        _dropside,
        _LightPodSelection,
        _AmountofLightPods,
        _linger,
        _AmountofBanshees,
        _VultureType,
        _VultureSkill,
        _EndWithJumpOut,
        _ArmedShip,
        _NumberOfTurrets,
        _UseCustomTurret,
        _UseCustomTurretPositions,
        _DF9RocketCount,
        _InvertedPDCount,
        _PDCount,
        _PlacementBias,
        _ShipHealthMult,
        _DeathCondition,
        _DeploymentDelay,
        _ArmingDelay
    ] spawn {
        params [
            "_position",
            "_Ship_direction",
            "_dropside",
            "_LightPodSelection",
            "_AmountofLightPods",
            "_linger",
            "_AmountofBanshees",
            "_VultureType",
            "_VultureSkill",
            "_EndWithJumpOut",
            "_ArmedShip",
            "_NumberOfTurrets",
            "_UseCustomTurret",
            "_UseCustomTurretPositions",
            "_DF9RocketCount",
            "_InvertedPDCount",
            "_PDCount",
            "_PlacementBias",
            "_ShipHealthMult",
            "_DeathCondition",
            "_DeploymentDelay",
            "_ArmingDelay"
        ];

        // Early-warning broadcast then wait
        if (_DeploymentDelay > 0) then {
            private _roundedTime = (round (_DeploymentDelay / 10)) * 10;
            private _etaStr = if (_roundedTime == 0) then {"imminent"} else {format ["%1 seconds", _roundedTime]};
            [[format ["<t color='#109600'>Serenity Actual: Providence-class warship detected on long-range sensors — ETA approximately %1. Fynock, prepare yourselves!</t>", _etaStr]]] remoteExec ["BIS_fnc_typeText", 0];
            sleep _DeploymentDelay;
        };

        // TODO: replace with actual Providence classname once known
        private _ReturnShip = [
            _position,
            _Ship_direction,
            900,
            "ls_providence",
            _dropside
        ] call SciFiSupportPLUS_fnc_JumpShipIn;

        waitUntil { !isNull _ReturnShip && { alive _ReturnShip } };

        // Arming delay — weapons held until this elapses
        if (_ArmingDelay > 0) then { sleep _ArmingDelay; };

        if (_ArmedShip) then {
            [
                _ReturnShip,
                false,
                true,
                false,
                _NumberOfTurrets,
                false,
                _ShipHealthMult,
                _DeathCondition
            ] call ScifiSupportPLUS_FTL_SupportShip;

            [_ReturnShip, _NumberOfTurrets, _UseCustomTurret, _UseCustomTurretPositions, _DF9RocketCount, _InvertedPDCount, _PDCount, _PlacementBias, _dropside] spawn {
                params ["_ship", "_count", "_useCustom", "_useCustomPositions", "_df9Count", "_invertedPDCount", "_pdCount", "_placementBias", "_dropside"];

                private _turretClassList = [];
                if (_useCustom && (count ScifiSupportPlus_SupportShip_CustomTurretArray > 0)) then {
                    _turretClassList = ScifiSupportPlus_SupportShip_CustomTurretArray;
                } else {
                    _turretClassList = ["3AS_CIS_Naval_Gun_180"];
                };

                private _turretQueue = [];
                if (_useCustom && _useCustomPositions && ((_df9Count + _invertedPDCount + _pdCount) > 0)) then {
                    for "_n" from 1 to _df9Count do { _turretQueue pushBack "FST_DF9_Rocket"; };
                    for "_n" from 1 to _invertedPDCount do { _turretQueue pushBack "FST_CIS_PD_Turret_Inverted"; };
                    for "_n" from 1 to _pdCount do { _turretQueue pushBack "FST_CIS_PD_Turret"; };
                } else {
                    for "_n" from 1 to _count do { _turretQueue pushBack (selectRandom _turretClassList); };
                };
                if (count _turretQueue < 1) exitWith {};

                private _fnc_isPort = { (_this select 0) < 0 };
                private _fnc_isUnderside = {
                    params ["_cls", "_pos"];
                    switch (_cls) do {
                        case "FST_CIS_PD_Turret_Inverted": { true };
                        case "FST_DF9_Rocket": { (_pos select 2) < 400 };
                        default { false };
                    };
                };

                private _biasedPositionsByClass = [];
                {
                    _x params ["_cls", "_positions"];
                    private _ordered = switch (_placementBias) do {
                        case 4: { +_positions call BIS_fnc_arrayShuffle };
                        case 5: {
                            private _quad = [[], [], [], []];
                            {
                                private _port = _x call _fnc_isPort;
                                private _under = [_cls, _x] call _fnc_isUnderside;
                                private _qi = (if (_port) then {0} else {2}) + (if (_under) then {1} else {0});
                                (_quad select _qi) pushBack _x;
                            } forEach _positions;
                            private _out = [];
                            private _more = true;
                            while {_more} do {
                                _more = false;
                                { if (count _x > 0) then { _out pushBack (_x deleteAt 0); _more = true; }; } forEach _quad;
                            };
                            _out
                        };
                        default {
                            private _match = [];
                            private _rest = [];
                            {
                                private _isMatch = switch (_placementBias) do {
                                    case 0: { _x call _fnc_isPort };
                                    case 1: { !(_x call _fnc_isPort) };
                                    case 2: { [_cls, _x] call _fnc_isUnderside };
                                    case 3: { !([_cls, _x] call _fnc_isUnderside) };
                                    default { true };
                                };
                                if (_isMatch) then { _match pushBack _x } else { _rest pushBack _x };
                            } forEach _positions;
                            _match + _rest
                        };
                    };
                    _biasedPositionsByClass pushBack [_cls, _ordered];
                } forEach FST_Providence_TurretPositions;

                private _classCursors = [];

                private _turrets = [];
                for "_i" from 0 to ((count _turretQueue) - 1) do {
                    private _turretClass = _turretQueue select _i;

                    private _localPos = [];
                    private _placed = false;
                    if (_useCustomPositions) then {
                        private _classEntryIdx = _biasedPositionsByClass findIf {(_x select 0) == _turretClass};
                        if (_classEntryIdx != -1) then {
                            private _classPositions = (_biasedPositionsByClass select _classEntryIdx) select 1;
                            if (count _classPositions > 0) then {
                                private _cursorIdx = _classCursors findIf {(_x select 0) == _turretClass};
                                private _cursor = 0;
                                if (_cursorIdx != -1) then { _cursor = (_classCursors select _cursorIdx) select 1; };

                                _localPos = _classPositions select (_cursor mod (count _classPositions));
                                _placed = true;

                                if (_cursorIdx != -1) then {
                                    (_classCursors select _cursorIdx) set [1, _cursor + 1];
                                } else {
                                    _classCursors pushBack [_turretClass, _cursor + 1];
                                };
                            };
                        };
                    };
                    if (!_placed) then {
                        private _offsetY = (_i - ((count _turretQueue) - 1) / 2) * 80;
                        private _offsetX = [25, -25] select ((_i mod 2) != 0);
                        _localPos = [_offsetX, _offsetY, 0];
                    };

                    private _zCorrIdx = FST_Providence_TurretZCorrection findIf {(_x select 0) == _turretClass};
                    if (_zCorrIdx != -1) then {
                        _localPos = [_localPos#0, _localPos#1, (_localPos#2) + ((FST_Providence_TurretZCorrection select _zCorrIdx) select 1)];
                    };

                    private _turret = createVehicle [_turretClass, (_ship modelToWorld _localPos), [], 0, "NONE"];
                    _turret setVectorUp [0, 0, 1];
                    _turret attachTo [_ship, _localPos];
                    [_turret, _ship] remoteExecCall ["disableCollisionWith", 0];

                    createVehicleCrew _turret;
                    [_turret] joinSilent (group _ship);
                    _turret allowCrewInImmobile [true, true];

                    _turret setVehicleRadar 15;
                    vehicle _turret setVehicleReportRemoteTargets true;
                    vehicle _turret setVehicleReceiveRemoteTargets true;
                    vehicle _turret setVehicleReportOwnPosition true;
                    { vehicle _turret enableVehicleSensor [(_x select 0), true]; } forEach (listVehicleSensors _turret);

                    _turret setSkill ["courage", 1];
                    _turret setSkill ["aimingAccuracy", 0];
                    _turret setSkill ["aimingSpeed", 1];
                    _turret setSkill ["spotDistance", 1];
                    _turret setSkill ["spotTime", 1];

                    [_turret, true] remoteExec ["enableDynamicSimulation", 0];
                    { [_x, true] remoteExec ["enableDynamicSimulation", 0]; } forEach crew _turret;

                    [_turret, _ship] spawn {
                        params ["_turret", "_ship"];
                        while {alive _turret} do {
                            if (isNil {_ship getVariable "FTL_stopFiring"}) then {
                                if (combatMode (group _turret) != "RED") then {
                                    (group _turret) setCombatMode "RED";
                                    (group _turret) setBehaviour "AWARE";
                                    { [_x, "AUTOCOMBAT"] remoteExecCall ["enableAI", 0]; [_x, "AUTOTARGET"] remoteExecCall ["enableAI", 0]; [_x, "TARGET"] remoteExecCall ["enableAI", 0]; [_x, "FIREWEAPON"] remoteExecCall ["enableAI", 0]; } forEach crew _turret;
                                };
                            };
                            sleep 1;
                        };
                    };

                    _turrets pushBack _turret;
                    sleep 0.1;
                };

                _ship setVariable ["FTL_ExtraTurretOBJ", _turrets, true];
            };
        };

        sleep 6;

        _PodLocation1  = [50.123,   -100.456,  -85.789];
        _PodLocation2  = [-60.789,  -30.123,   -65.456];
        _PodLocation3  = [90.456,   -70.789,   -80.123];
        _PodLocation4  = [-110.789, -55.456,   -75.789];
        _PodLocation5  = [5.789,    15.123,    -70.456];
        _PodLocation6  = [-95.456,  -115.789,  -78.123];
        _PodLocation7  = [65.789,   -35.456,   -72.789];
        _PodLocation8  = [-20.456,  -80.789,   -85.456];
        _PodLocation9  = [85.123,   50.456,    -70.789];
        _PodLocation10 = [-75.789,  5.123,     -68.456];
        _PodLocation11 = [35.456,   -20.789,   -76.789];
        _PodLocation12 = [-70.123,  45.456,    -73.789];
        _PodLocation13 = [120.789,  -10.456,   -79.456];
        _PodLocation14 = [-40.456,  -90.789,   -81.123];
        _PodLocation15 = [75.789,   -55.456,   -77.789];
        _PodLocation16 = [-10.123,  80.789,    -69.456];

        _PodArray = [];

        createandAttachParticleSource = {
            params ["_podobject", "_location"];
            _modelData = _podobject modelToWorld _location;
            _particleSource = "#particleSource" createVehicle _modelData;
            _particleSource attachTo [_podobject, _location];
            _particleSource
        };

        _podLocations = [
            _PodLocation1, _PodLocation2, _PodLocation3, _PodLocation4,
            _PodLocation5, _PodLocation6, _PodLocation7, _PodLocation8,
            _PodLocation9, _PodLocation10,_PodLocation11,_PodLocation12,
            _PodLocation13,_PodLocation14,_PodLocation15,_PodLocation16
        ];

        {
            _PodArray pushBack ([_ReturnShip, _x] call createandAttachParticleSource);
        } forEach _podLocations;

        [_ReturnShip, _PodArray] spawn {
            params ["_ReturnShip", "_PodArray"];
            waitUntil {
                sleep 1;
                !alive _ReturnShip || isNull _ReturnShip
            };
            {
                deleteVehicle _x;
                sleep 0.01;
            } forEach _PodArray;
        };

        // -------------------------------------------------
        // 4) Drop pods if any
        // -------------------------------------------------
        if (_AmountofLightPods > 0) then {
            for "_LightPoddropper" from 1 to _AmountofLightPods do {
                _randomIndex = floor (random (count _PodArray));
                _randomPodLocation = _PodArray select _randomIndex;
                _PodArray deleteAt _randomIndex;

                _currentposition = [
                    (getPosATL _randomPodLocation select 0),
                    (getPosATL _randomPodLocation select 1),
                    0
                ];

                if (_linger) then {
                    [_currentposition, _dropside, _LightPodSelection, true] call FST_Droid_Dispenser;
                } else {
                    [_currentposition, _dropside, _LightPodSelection, false] call FST_Droid_Dispenser;
                };
                sleep 1;
            };
        };

        // -------------------------------------------------
        // 5) Spawn Vultures if any
        // -------------------------------------------------
        if (_AmountofBanshees > 0) then {
            private _vultureClasses = [];
            if (_VultureType == 0) then {
                for "_i" from 1 to _AmountofBanshees do {
                    _vultureClasses pushBack "3AS_CIS_Vulture_F";
                };
            } else {
                private _aaVultureCount = floor (_AmountofBanshees * 0.33);
                private _standardVultureCount = _AmountofBanshees - _aaVultureCount;
                for "_i" from 1 to _aaVultureCount do {
                    _vultureClasses pushBack "3AS_CIS_Vulture_AA_F";
                };
                for "_i" from 1 to _standardVultureCount do {
                    _vultureClasses pushBack "3AS_CIS_Vulture_F";
                };
                _vultureClasses = _vultureClasses call BIS_fnc_arrayShuffle;
            };

            {
                private _vultureClass = _x;
                [_ReturnShip, _dropside, _vultureClass, _VultureSkill] spawn {
                    params ["_ReturnShip", "_dropside", "_vultureClass", "_VultureSkill"];
                    _currentPosition = getPosATL _ReturnShip;

                    _Banshee = createVehicle [_vultureClass, _currentPosition, [], 0, "CAN_COLLIDE"];
                    (_dropside select 0) createVehicleCrew _Banshee;

                    sleep 3;

                    if (_VultureSkill == 1) then {
                        {
                            _x setSkill 1.0;
                        } forEach crew _Banshee;
                    };
                    (group _Banshee) setCombatMode "RED";
                    (group _Banshee) setBehaviour "AWARE";
                    _Banshee engineOn true;
                };
                sleep 5;
            } forEach _vultureClasses;
        };

        // -------------------------------------------------
        // 6) Wait, then optionally jump out
        // -------------------------------------------------
        sleep ((_AmountofLightPods * 1) + (_AmountofBanshees * 5) + 1);

        if (_EndWithJumpOut) then {
            [objNull, "Serenity Actual: Providence overhead, they've dropped droids and are retreating!"] call BIS_fnc_showCuratorFeedbackMessage;

            private _turretArrayForCleanup = _ReturnShip getVariable ["FTL_ExtraTurretOBJ", []];
            [_ReturnShip, _turretArrayForCleanup] spawn {
                params ["_ship", "_turrets"];
                waitUntil { sleep 1; isNull _ship };
                { deleteVehicleCrew _x; deleteVehicle _x; } forEach _turrets;
            };

            [_ReturnShip] call SciFiSupportPLUS_fnc_JumpOut;
        } else {
            [objNull, "Serenity Actual: Providence overhead, they've dropped droid pods!"] call BIS_fnc_showCuratorFeedbackMessage;
        };
    };
};


FST_Droid_Dispenser =  {
    params ["_position", "_dropside", "_selection", "_linger"];
                        
    _position = ASLtoATL _position;
                                        
    _spawnpos = _position vectorAdd [random [-100, 0, 100], random [-100, 0, 100], 1000];
                                        
    _mainprojectile = createVehicle ["R_MRAAWS_HE_F", _spawnpos, [], 0, "NONE"];
                        
    _mainprojectile setShotParents [player, player];
                                        
    _angle = [(_position vectorFromTo _spawnpos)#0, (_position vectorFromTo _spawnpos)#1, ((_position vectorFromTo _spawnpos)#2)];
                        
    _projectile = createVehicle ["ls_droidDispenser", [0, 0, 0], [], 0, "NONE"];
    [_projectile, 0, 0] call BIS_fnc_setPitchBank;
    _projectile setPosATL (getPosATL _mainprojectile);
    [_projectile, _mainprojectile] call BIS_fnc_attachToRelative;
    _projectile allowDamage false;
                                        
    [_mainprojectile, _position, _projectile] spawn {
        params ["_mainprojectile", "_position", "_projectile"];
        while {alive _mainprojectile} do {
            _mainprojectile setVelocity ((_position vectorFromTo (getPosATL _mainprojectile)) vectorMultiply -100);
        };
    };
                                        
    [[_projectile], {
        params ["_projectile"];
        _FloodLight = "#lightpoint" createVehicleLocal [0, 0, 0];
        _FloodLight attachTo [_projectile, [0, 0, 1]];
        _FloodLight setLightColor [1, 0.8, 0.25];
        _FloodLight setLightAmbient [1, 0.8, 0.25];
        _FloodLight setLightBrightness 0.75;
        _FloodLight setLightDayLight true;
                                            
        waitUntil {
            !alive _projectile
        };
        deleteVehicle _FloodLight;
    }] remoteExec ["spawn"];
                                        
    [_mainprojectile, _position, _dropside, _projectile, _selection, _linger] spawn {
        params ["_mainprojectile", "_position", "_dropside", "_projectile", "_selection", "_linger"];
                                            
        _positionATL = _position;
                    
        waitUntil {
            if (alive _mainprojectile) then {
                _positionATL = getPosATL _mainprojectile;
            };
            !alive _mainprojectile;
        };
                                            
        [[_positionATL], {
            params ['_position'];
            _positionATL = _position;
            _positionATL set [2, 2];
                                            
            private _ps1 = "#particleSource" createVehicleLocal _positionATL;
            _ps1 setParticleParams [
                "\A3\Data_F\ParticleEffects\Pstone\Pstone", "", "SpaceObject",
                1, 10, [0, 0, 0], [0, 0, 10], 1, 20, 1, 0.2, [1, 1],
                [[1, 1, 1, 1]],
                [0, 1], 1, 0, "", "", _ps1];
            _ps1 setParticleRandom [0, [10, 10, 0], [5, 5, 10], 0, 1.5, [0, 0, 0, 0], 0, 0];
            _ps1 setParticleCircle [10, [0, 10, 10]];
            _ps1 setDropInterval 0.01;
                                                
            _ps1 spawn {
                sleep 1;
                deleteVehicle _this;
            };
        }] remoteExec ["spawn"];
                                            
        _craterpos = _positionATL;
        _craterpos set [2, 0];
        _DroidPodCrater = createVehicle ["land_ShellCrater_02_small_F", _craterpos, [], 0, "CAN_COLLIDE"];
                                            
        deleteVehicle _projectile;
        _projectile = createVehicle ["ls_droidDispenser", [0, 0, 0], [], 0, "NONE"];
        _projectile enableSimulation false;
        _projectile allowDamage false;
                    
        _projectile disableCollisionWith _DroidPodCrater;
        _DroidPodCrater disableCollisionWith _projectile;
                
        _projectile setVectorUp surfaceNormal position _projectile;
                
        _projectile setPosATL [(getPosATL _DroidPodCrater select 0), (getPosATL _DroidPodCrater select 1), 0];
                    
        _DroidPodCrater setVectorDir [(random 1), (random 1), (random 1)]; 
        _DroidPodCrater setPosWorld getPosWorld _DroidPodCrater;
        _projectile setVectorDir [(random 1), (random 1), (random 1)]; 
        _projectile setPosWorld getPosWorld _projectile;
                    
        _RotationNumber = (random 5);
        [_DroidPodCrater, _RotationNumber, _RotationNumber] call BIS_fnc_setPitchBank;
        [_projectile, _RotationNumber, _RotationNumber] call BIS_fnc_setPitchBank;
                    
        _position = _craterpos;
                                            
        _spawn = _position;
        _side = (_dropside select 0);
        _list = [
            // 0
            ["FST_Droid_B1_E5","FST_Droid_B1_E5","FST_Droid_B1_AR","FST_Droid_B1_Commander","FST_Droid_B1_AT"],
            // 1
            ["FST_Droid_B1_E5","FST_Droid_B1_AR","FST_Droid_B1_Commander"],
            // 2
            ["FST_Droid_B1_E5","FST_Droid_B1_AR","FST_Droid_B1_Commander"],
            // 3
            ["FST_Droid_B1_E5","FST_Droid_B1_AR","FST_Droid_B1_Commander"],
            // 4
            ["FST_BX","FST_BX","FST_BX"],
            // 5
            ["FST_Jorgetrooper","FST_Jorgetrooper_AT","FST_Jorgetrooper_AR"],
            // 6
            ["FST_B2_TL","FST_B2"]
        ] # _selection;
                                            
        _listout = [];
        for "_i" from 1 to ((random 3) + 3) do {
            _listout pushBack (selectRandom _list);
        };
                                            
        [_spawn, _side, _listout, _DroidPodCrater] spawn {
            params ["_spawn", "_side", "_listout", "_DroidPodCrater"];
            sleep 0.1;
            _FloodGroup = [_spawn, _side, _listout] call BIS_fnc_spawnGroup;    
        };
                    
        if (_linger) then {
            // Linger logic runs in its own spawn with all variables passed explicitly
            // via params. The outer spawn's non-private variables (_craterpos, _spawn,
            // _positionATL, etc.) can go stale inside deeply nested while/waitUntil
            // blocks after prolonged execution -- passing them through params ensures
            // they are properly scoped for the lifetime of this spawn.
            [_craterpos, _spawn, _side, _projectile, _listout] spawn {
                params ["_craterpos", "_spawn", "_side", "_projectile", "_listout"];
                sleep 1;
                _projectile allowDamage true;
                while {alive _projectile} do {
                    _time = time;
                    waitUntil {
                        (time - _time) > 20 or !(alive _projectile)
                    };
                    if (alive _projectile) then {
                        [_spawn, _side, [selectRandom _listout]] call BIS_fnc_spawnGroup;
                    } else {
                        sleep 1;
                        _munition = createVehicle ["M_Mo_82mm_AT_LG", _craterpos, [], 0, "CAN_COLLIDE"];
                        _munition setShotParents [player, player];
                        _munition setVectorDirAndUp ([[vectorDir _munition, vectorUp _munition], 0, -90, 0] call BIS_fnc_transformVectorDirAndUp);
                        _munition setVelocity [0, 0, -10];
                        sleep 1;
                        deleteVehicle _projectile;
                    };
                };
            };
        };
                    
        sleep 1;
        _projectile allowDamage true;
        sleep 1;
        deleteVehicle _projectile;
                    
    };
};

["[41st] Droid Modules", "Droid Dispenser",
    {
        params [["_pos", [0, 0, 0], [[]], 3], ["_logic", objNull, [objNull]]];
        _options = ["Basic", "Basic Dumb", "Geonosis", "Geonosis Dumb", "Commandos", "Jorge", "B2"];
        
        ["spawn Droid Dispenser", [
            ["sideS", ["Side select (ONLY ONE!)", "The side the spawned dropped units will be on."], [east]],
            ["TOOLBOX", ["Type select", "What type of Droids to spawn."], [3, 3, 3, _options, nil]],
            ["CHECKBOX", ["Linger", "Stays at the landing zone and spawns Droids unless destroyed."], [True]]
            ], {
                params ["_values", "_arguments"];
                _dropside = _values # 0;
                _selection = _values # 1;
                _linger = _values # 2;
                
                _position = _arguments select 0;

                [_position, _dropside, _selection, _linger] call FST_Droid_Dispenser;
        }, {}, [_pos, _logic]] call zen_dialog_fnc_create;
    }, "\PHAN_ScifiSupportPlus\data\COV_SDV.paa"] call zen_custom_modules_fnc_register;

{if (count units _x == 0) then {deleteGroup _x}} forEach allGroups;

	["[41st] Droid Modules", "HMP vehicle drop",
{
	params [["_pos", [0, 0, 0], [[]], 3], ["_logic", objNull, [objNull]]];

	["spawn HMP vehicle drop",
		[
			["COMBO", ["Choose Aircraft", "The aircraft that will deploy the vehicle"], [FST_SW_CIS_HMP_list, FST_SW_CIS_HMP_listDISPLAY]],
			["COMBO", ["Choose vehicle", "The vehicle that will be deployed"], [FST_SW_CIS_HMP_GV_list, FST_SW_CIS_HMP_GV_listDISPLAY]],
			["CHECKBOX",["Add Crew","Add crew to deployed vehicle"],[false]],
			["SLIDER",["Insert Distance","How far away the aircraft start it's flight path"],[1000,5000,2000,0]],
			["toOLBOX", "Insert Direction", [0, 1, 8, ["N", "NE", "E", "SE", "S", "SW", "W", "NW"]]]
		],
		{ 
			_this spawn {
			params["_values", "_arguments"];

				_Aircraft = _values # 0;
				_dropvehicle = _values # 1;
				_addcrew = _values # 2;
				_InsertDistance = _values # 3;
				_direction = _values # 4;

				_Ship_direction = [0, 45, 90, 135, 180, 225, 270, 315] # _direction;
										
				_position=_arguments select 0;
					
				[_position,_Aircraft,_dropvehicle,_addcrew,_InsertDistance,_Ship_direction] call FST_ScifiSupportPlus_fnc_SW_HMPVehicleDrop;
			};
		},
		{},
		[_pos]] call zen_dialog_fnc_create;
},
"\PHAN_ScifiSupportPlus\data\HMP.paa"] call zen_custom_modules_fnc_register;

FST_ScifiSupportPlus_fnc_SW_HMPVehicleDrop = {
params ["_position", "_Aircraft", "_dropvehicle", "_addcrew", "_insertdistance", "_Ship_direction"];

_logic = createVehicle ["land_AirHorn_01_F",ASLToATL _position,[],0,"CAN_COLLIDE"];
					hideObjectGlobal _logic;
					_logic setDir _Ship_direction;
					_logic setPosATL (getPosATL _logic);

					_position = (getPosATL _logic);
							
					_craterposNew = _logic getRelPos  [(_InsertDistance), (_direction)];
					_craterposdrop = _logic getRelPos  [-100, - (_direction)];
					_craterposOut = _logic getRelPos  [-5000, - (_direction)];

					_dropperAircraft = createvehicle [_Aircraft, _craterposNew, [], 0, "FLY"];
					createvehiclecrew _dropperAircraft;
					_dropperAircraft flyinHeight 15;
					_dropperAircraft limitSpeed 200;

					_droppervehicle = createvehicle [_dropvehicle, [0, 0, 15], [], 0, "CAN_COLLIDE"];

					sleep 0.1;

					if (_addcrew) then {
						createvehiclecrew _droppervehicle;
					};

					_droppervehicle attachto [_dropperAircraft, [0,-2,-((boundingBox _droppervehicle)#1#1)]];

					_droppervehicle disableCollisionWith _dropperAircraft;
					_dropperAircraft disableCollisionWith _droppervehicle;

					_dropperAircraft setCombatBehaviour "CARELESS";
					_dropperAircraft doMove (_craterposdrop);

					{
						[_x, [[_dropperAircraft], false]] remoteExec ["addCuratorEditableObjects", 0];
						[_x, [[_droppervehicle], false]] remoteExec ["addCuratorEditableObjects", 0];
					} forEach allCurators;


					waitUntil {((_dropperAircraft distance2D _craterposdrop) < 200) || (!alive _dropperAircraft)};
					if (!alive _dropperAircraft) exitwith {detach _droppervehicle;};

						_dropperAircraft spawn {_this allowdamage false; sleep 2; _this allowDamage true;};
						detach _droppervehicle;
						_dropperAircraft doMove (_craterposOut);
						_dropperAircraft flyinHeight 100;
						_dropperAircraft limitSpeed 300;

					waitUntil {((_dropperAircraft distance2D _craterposOut) < 250) || (!alive _dropperAircraft)};
					if (!alive _dropperAircraft) exitwith {};

						{deleteVehicle _x} forEach (crew _dropperAircraft);
						deleteVehicle _dropperAircraft;
						deleteVehicle _logic;
};

FST_SW_CIS_HMP_list_insert = [
"FST_HMP_Transport"
];

FST_SW_CIS_HMP_list=[];
{
	if (_x!="" && (gettext (configFile >> "Cfgvehicles" >> _x >> "displayname")) != "") then {
		FST_SW_CIS_HMP_list pushBack _x;
	}
}forEach FST_SW_CIS_HMP_list_insert;
FST_SW_CIS_HMP_list;

FST_SW_CIS_HMP_listDISPLAY=[];
{
if (_x!="" && (gettext (configFile >> "Cfgvehicles" >> _x >> "displayname")) != "") then {
	_colour=switch ((getNumber (configFile >> "Cfgvehicles" >> _x >> "side"))) do {
		case 0: {
			[255, 0, 0, 255]
		};
		case 1: {
			[0, 0, 255, 255]
		};
		case 2: {
			[0, 255, 0, 255]
		};
		case 3: {
			[255, 0, 255, 255]
		};
		default {
			[0, 0, 0, 255]
		};
	};
	FST_SW_CIS_HMP_listDISPLAY pushBack [(gettext (configFile >> "Cfgvehicles" >> _x >> "displayname")), "", (gettext (configFile >> "Cfgvehicles" >> _x >> "editorPreview")), _colour];
}
}forEach FST_SW_CIS_HMP_list;
FST_SW_CIS_HMP_listDISPLAY;


FST_SW_CIS_HMP_GV_list_insert = [
"FST_AAT", 
"FST_AAT_Tan", 
"FST_Advanced_DSD", 
"FST_GAT", 
"FST_Hailfire_AT", 
"FST_Hailfire_Rocket", 
"FST_Hailfire_SAM", 
"FST_King_AAT", 
"FST_N99", 
"FST_vehicle_agtRaptor",
"FST_vehicle_agtRaptor_Scorch",
"FST_Droideka", 
"FST_Sniper_Deka", 
"3AS_SAC_F"
];

FST_SW_CIS_HMP_GV_list=[];
{
if (_x!="" && (gettext (configFile >> "Cfgvehicles" >> _x >> "displayname")) != "") then {
	FST_SW_CIS_HMP_GV_list pushBack _x;
}
}forEach FST_SW_CIS_HMP_GV_list_insert;
FST_SW_CIS_HMP_GV_list;

FST_SW_CIS_HMP_GV_listDISPLAY=[];
{
if (_x!="" && (gettext (configFile >> "Cfgvehicles" >> _x >> "displayname")) != "") then {
	_colour=switch ((getNumber (configFile >> "Cfgvehicles" >> _x >> "side"))) do {
		case 0: {
			[255, 0, 0, 255]
		};
		case 1: {
			[0, 0, 255, 255]
		};
		case 2: {
			[0, 255, 0, 255]
		};
		case 3: {
			[255, 0, 255, 255]
		};
		default {
			[0, 0, 0, 255]
		};
	};
	FST_SW_CIS_HMP_GV_listDISPLAY pushBack [(gettext (configFile >> "Cfgvehicles" >> _x >> "displayname")), "", (gettext (configFile >> "Cfgvehicles" >> _x >> "editorPreview")), _colour];
}
}forEach FST_SW_CIS_HMP_GV_list;
FST_SW_CIS_HMP_GV_listDISPLAY;