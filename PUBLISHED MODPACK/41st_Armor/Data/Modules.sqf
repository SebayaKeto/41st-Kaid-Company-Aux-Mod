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

            // NEW: Number of Turrets
            ["SLIDER", ["Number of Turrets", "Number of turrets that will spawn on the Munificent."], [0, 10, 2, 0]],

            // NEW: Custom turret classnames (pulls from CBA addon settings)
            ["CHECKBOX", ["Custom Turrets?", "If enabled, turret classnames will be pulled from the CBA addon settings instead of the faction default."], [false]],

            // NEW: Ship HP pool
            ["SLIDER", ["Ship HP", "HP pool for the ship. Stored as this value x100 internally (e.g. 25 = 2500 HP). Default is the CBA addon setting."], [1, 5000, 25, 0]],

            // NEW: Death condition
            ["TOOLBOX", ["Death Condition", "What happens when the ship is destroyed. Crash Ship = falls from the sky. Retreat = jumps out."], [0, 1, 2, ["Crash Ship", "Retreat (Jump Out)"], nil]]

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

                // NEW: turret count, custom turret, HP, death condition
                _NumberOfTurrets   = _values select 10;
                _UseCustomTurret   = _values select 11;
                _ShipHealthMult    = _values select 12;
                _DeathCondition    = _values select 13;

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
                    _ShipHealthMult,
                    _DeathCondition
                ] remoteExecCall ["FST_ScifiSupportPlus_fnc_SW_Munificent_QRF", 2];

            }, {}, [_pos, _logic]] call zen_dialog_fnc_create;
    },
    "\PHAN_ScifiSupportPlus\data\Droid.paa"
] call zen_custom_modules_fnc_register;


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
        ["_NumberOfTurrets", 1],       // Default if not passed
        ["_UseCustomTurret", false],   // Default if not passed
        ["_ShipHealthMult", 25],       // Default if not passed (matches slider default, = 2500 HP internally)
        ["_DeathCondition", 0]         // Default if not passed: 0 = crash, 1 = retreat
    ];

    // Convert ASL coords to ATL
    _position = ASLtoATL _position;

    // Our chosen ship & altitude
    _Ship     = "ls_munificent";
    _Altitude = 900;

    // -------------------------------------------------
    // 2) Spawn the ship in (no sleeps here!)
    // -------------------------------------------------
    _ReturnShip = [
        _position,
        _Ship_direction,
        _Altitude,
        _Ship,
        _dropside
    ] call SciFiSupportPLUS_fnc_JumpShipIn;

    // -------------------------------------------------
    // 3) Spawn a new scheduled block to handle sleeps
    // -------------------------------------------------
    [
        _ReturnShip,
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
        _ShipHealthMult,
        _DeathCondition
    ] spawn {
        // Re-parse in the scheduled environment
        params [
            "_ReturnShip",
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
            "_ShipHealthMult",
            "_DeathCondition"
        ];

        // Wait until the ship is fully spawned and alive before configuring it
        waitUntil { !isNull _ReturnShip && { alive _ReturnShip } };

        // If we want an armed Munificent, configure its turrets, HP, and death behavior.
        // Done here (in scheduled env) so the ship has fully initialized first.
        if (_ArmedShip) then {
            // Pass AddTurret=false so FTL_SupportShip only sets up HP, death condition,
            // and the missile targeting system -- we spawn turrets ourselves below so we
            // can place them at explicit world positions outside the CoreOBJ hitbox.
            // (FTL_SupportShip places all turrets at CoreOBJ origin [0,0,0] for count>1,
            // inside the hull where they have no line of sight.)
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

            // Spawn our own turrets at explicit world positions so they are:
            // - Outside the CoreOBJ hitbox (which blocks line of sight when at [0,0,0])
            // - Still inside the visual Munificent hull
            // We create each turret at a world position offset from the CoreOBJ,
            // then use BIS_fnc_attachToRelative with keepWorldPos=true so the
            // attachment offset is calculated correctly from that spawn position.
            // ls_munificent dirOffset=270: visual length runs along CoreOBJ X axis.
            [_ReturnShip, _NumberOfTurrets, _UseCustomTurret, _dropside] spawn {
                params ["_ship", "_count", "_useCustom", "_dropside"];
                if (_count < 1) exitWith {};

                // Prepare turret class list for per-turret selection
                private _turretClassList = [];
                if (_useCustom && (count ScifiSupportPlus_SupportShip_CustomTurretArray > 0)) then {
                    _turretClassList = ScifiSupportPlus_SupportShip_CustomTurretArray;
                } else {
                    _turretClassList = ["3AS_CIS_Naval_Gun_180"];
                };

                private _turrets = [];
                for "_i" from 0 to (_count - 1) do {
                    // Pick class per-turret so mixed arrays get variety
                    private _turretClass = selectRandom _turretClassList;

                    // Space turrets 80m apart along Y (ship length), centred on origin.
                    // X alternates +/-25m for port/starboard stagger.
                    // These offsets are in CoreOBJ model space; 25m+ clears the CoreOBJ hitbox.
                    private _offsetY = (_i - (_count - 1) / 2) * 80;
                    private _offsetX = [25, -25] select ((_i mod 2) != 0);
                    private _spawnPos = _ship modelToWorld [_offsetX, _offsetY, 0];

                    private _turret = createVehicle [_turretClass, _spawnPos, [], 0, "NONE"];
                    _turret setVectorUp [0, 0, 1];

                    // Attach keeping world position -- offset is auto-calculated from
                    // the spawn position we chose, so it lands where we want it.
                    [_turret, _ship, true] call BIS_fnc_attachToRelative;
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