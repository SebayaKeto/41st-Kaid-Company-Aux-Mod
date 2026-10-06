
[
    "[41st] Object Minigames",
    "New Hunger Games Match",
    {
        [
            "Select Players To Teleport To Strating Positions",
            [
                [
                    "OWNERS",
                    "Players To Teleport",
                    [[],[],allPlayers,2]
                ]
            ],
            {
                params ["_inputs","_basics"];
                missionNamespace setVariable ["FST_HGRoundReady", false];
                missionNamespace setVariable ["FST_CrateTotal", 0];
                private _hgplayers = (_inputs select 0) select 2;
                private _starts = allMissionObjects "FST_HungerGamesStartPoint";
                ["FST_generateNewCrates", []] spawn CBA_fnc_serverEvent;
                {
                    deleteVehicle _x;
                } forEach (allMissionObjects "WeaponHolder");
                {
                    _x setPos (getPosATL (_starts deleteAt (floor (random (count _starts))))); 
                    ["FST_setHGPlayerInventory", [], _x] call CBA_fnc_targetEvent;
                    _x setUnitTrait ["Medic",true];
                } forEach _hgplayers;
                [
                    {
                        missionNamespace getVariable ["FST_HGRoundReady", false];
                    },
                    {
                        params ["_hgplayers"];
                        {
                            ["FST_freePlayer", [], _x] call CBA_fnc_targetEvent;
                        } forEach _hgplayers;
                    },
                    [_hgplayers],
                    30,
                    {
                        params ["_hgplayers"];
                        {
                            ["FST_freePlayer", [], _x] call CBA_fnc_targetEvent;
                        } forEach _hgplayers;
                    }
                ] call CBA_fnc_waitUntilAndExecute;
            }
        ] call zen_dialog_fnc_create;
    }
] call zen_custom_modules_fnc_register;

[
    "[41st] Object Minigames",
    "Only Spawn New Loot Crates",
    {
        ["FST_generateNewCrates", []] spawn CBA_fnc_serverEvent;
    }
] call zen_custom_modules_fnc_register;

["FST_generateNewCrates", {

    private _oldcrate = missionNamespace getVariable ["FST_LootCrateList", []];
    private _cratecount = count _oldcrate;
    while {_cratecount > 0} do
    {
        private _current = _oldcrate deleteAt 0;
        deleteVehicle _current;
        _cratecount = _cratecount - 1;
    };
    ["FST_clearBombSounds", []] spawn CBA_fnc_globalEvent;
    missionNamespace setVariable ["FST_LootCrateList", []];
    missionNamespace setVariable ["FST_LootCrateOdds", ["Ammo", 0.3, "Med", 0.2, "Melee", 0.1, "Side", 0.15, "Main", 0.2, "Heavy", 0.005, "Boom", 0.1]];
    private _spawners = allMissionObjects "FST_HungerGamesLootSpawner";
    _cratecount = count _spawners;
    {
        private _position = getPosATL _x;
        ["FST_spawnLootCrate", [_position,_cratecount]] spawn CBA_fnc_serverEvent;
    } forEach _spawners;

}] call CBA_fnc_addEventHandler;

["FST_spawnLootCrate", {

    params ["_pos","_total"];
    private _spawnpos = _pos vectorAdd [0,0,2];
    private _bomb = selectRandomWeighted [0, 0.85, 1, 0.15];
    private _storage = missionNamespace getVariable ["FST_LootCrateList", []];
    if (_bomb == 0) then
    {
        private _type = selectRandomWeighted (missionNamespace getVariable "FST_LootCrateOdds");
        private _size = selectRandomWeighted ["Small", 0.45, "Med", 0.45, "Large", 0.1];
        private _carry = selectRandomWeighted [0, 0.1, 1, 0.5, 2, 0.3, 3, 0.1];
        private _storages = ["FST_HGVest_Mini", 3, "FST_HGVest_Small", 4, "FST_HGVest_Med", 3, "FST_HGVest_Large", 2, "FST_HGVest_Huge", 2, "FST_HGBag_Mini", 3, "FST_HGBag_Small", 4, "FST_HGBag_Med", 3, "FST_HGBag_Large", 2, "FST_HGBag_Huge", 2];
        switch (_type) do
        {
            case "Ammo":
            {
                private _ammos = ["FST_Droid_blaster_battery_Red","FST_Droid_blaster_cell_Red","FST_blaster_cell_SSP_Red","FST_blaster_cell_LE_Red","FST_blaster_battery_DC15L_Red","FST_blaster_scatter_cell_DP23_Red","FST_blaster_cell_High_Red","FST_blaster_scatter_cell_SBB3_Red","FST_blaster_cell_Westar_Red","FST_blaster_cell_low_Red","FST_blaster_cell_low_Red_smg","FST_blaster_cell_Red","FST_ACPR_Mag_Red","FST_DC17M_EC40_Cell_Red","FST_DW32S_Mag_Red","FST_ZH73_Mag_Red","FST_pistol_westar35sa_Mag_Red"];
                switch (_size) do
                {
                    case "Small":
                    {
                        private _crate = selectRandom ["FST_HGCrate_SmallGrey","FST_HGCrate_SmallBlack","FST_HGCrate_Misc13","FST_HGCrate_Misc14","FST_HGCrate_Misc15","FST_HGCrate_Misc18","FST_HGCrate_Misc19","FST_HGCrate_Misc21","FST_HGCrate_WBarrel","FST_HGCrate_SmallBarrel","FST_HGCrate_GSmallBarrel","FST_HGCrate_WSmallBarrel"];
                        private _spawned = createVehicle
                        [
                            _crate,
                            _spawnpos,
                            [],
                            0,
                            "CAN_COLLIDE"
                        ];
                        _spawned setDir (random 360);
                        _storage pushBack _spawned;
                        missionNamespace setVariable ["FST_LootCrateList", _storage];
                        private _varry = selectRandomWeighted [2, 0.25, 3, 0.75];
                        while {_varry > 0} do
                        {
                            private _choice = selectRandom _ammos;
                            private _amount = selectRandom [2,3,4];
                            _spawned addItemCargoGlobal [_choice, _amount];
                            _varry = _varry - 1;
                        };
                    };
                    case "Med":
                    {
                        private _crate = selectRandom ["FST_HGCrate_Misc1","FST_HGCrate_Misc2","FST_HGCrate_Misc3","FST_HGCrate_Misc4","FST_HGCrate_Misc5","FST_HGCrate_Misc6","FST_HGCrate_Misc8","FFST_HGCrate_Misc9","FST_HGCrate_Misc10","FST_HGCrate_Misc11","FST_HGCrate_Misc16","FST_HGCrate_Misc17","FST_HGCrate_Misc20","FST_HGCrate_BBarrel","FST_HGCrate_GBarrel"];
                        private _spawned = createVehicle
                        [
                            _crate,
                            _spawnpos,
                            [],
                            0,
                            "CAN_COLLIDE"
                        ];
                        _spawned setDir (random 360);
                        _storage pushBack _spawned;
                        missionNamespace setVariable ["FST_LootCrateList", _storage];
                        private _varry = selectRandomWeighted [3, 0.15, 4, 0.5, 5, 0.5, 6, 0.25];
                        while {_varry > 0} do
                        {
                            private _choice = selectRandom _ammos;
                            private _amount = selectRandom [3,4,5,6,7];
                            _spawned addItemCargoGlobal [_choice, _amount];
                            _varry = _varry - 1;
                        };
                    };
                    case "Large":
                    {
                        private _spawned = createVehicle
                        [
                            "FST_HGCrate_Ammo",
                            _spawnpos,
                            [],
                            0,
                            "CAN_COLLIDE"
                        ];
                        _spawned setDir (random 360);
                        _storage pushBack _spawned;
                        missionNamespace setVariable ["FST_LootCrateList", _storage];
                        private _varry = selectRandomWeighted [8, 0.15, 10, 0.5, 11, 0.5, 15, 0.25];
                        while {_varry > 0} do
                        {
                            private _choice = selectRandom _ammos;
                            private _amount = selectRandom [5,6,7,8];
                            _spawned addItemCargoGlobal [_choice, _amount];
                            _varry = _varry - 1;
                        };
                    };
                };
                private _odds = missionNamespace getVariable "FST_LootCrateOdds";
                _odds set [1,0.3];
                _odds set [3, (_odds select 3) + 0.1];
                _odds set [5, (_odds select 5) + 0.1];
                _odds set [7, (_odds select 7) + 0.1];
                _odds set [9, (_odds select 9) + 0.15];
                _odds set [11, (_odds select 11) + 0.005];
                _odds set [13, (_odds select 13) + 0.1];
                missionNamespace setVariable ["FST_LootCrateOdds",_odds];
            };
            case "Med":
            {
                private _meds = ["ACE_adenosine","IDA_BattleStim","IDA_BattleStim","IDA_BactaBandage","IDA_BactaBandage","IDA_BactaBandage","IDA_BactaBandage","ACE_bloodIV","ACE_bloodIV_250","ACE_bloodIV_500","IDA_Cauterizer","ACE_plasmaIV","ACE_plasmaIV_250","ACE_plasmaIV_500","ACE_splint","ACE_tourniquet","ACE_tourniquet"];
                switch (_size) do
                {
                    case "Small":
                    {
                        private _crate = selectRandom ["FST_HGCrate_SmallGrey","FST_HGCrate_SmallBlack","FST_HGCrate_Misc13","FST_HGCrate_Misc14","FST_HGCrate_Misc15","FST_HGCrate_Misc18","FST_HGCrate_Misc19","FST_HGCrate_Misc21","FST_HGCrate_WBarrel","FST_HGCrate_SmallBarrel","FST_HGCrate_GSmallBarrel","FST_HGCrate_WSmallBarrel"];
                        private _spawned = createVehicle
                        [
                            _crate,
                            _spawnpos,
                            [],
                            0,
                            "CAN_COLLIDE"
                        ];
                        _spawned setDir (random 360);
                        _storage pushBack _spawned;
                        missionNamespace setVariable ["FST_LootCrateList", _storage];
                        private _varry = selectRandomWeighted [1, 0.25, 2, 0.5, 3, 0.25];
                        while {_varry > 0} do
                        {
                            private _choice = selectRandom _meds;
                            switch (_choice) do
                            {
                                case "IDA_BactaBandage":
                                {
                                    private _amount = selectRandom [5,6,7];
                                    _spawned addItemCargoGlobal [_choice, _amount];
                                };
                                case "IDA_Cauterizer":{_varry = _varry + 1};
                                default
                                {
                                    private _amount = selectRandom [1,2];
                                    _spawned addItemCargoGlobal [_choice, _amount];
                                    _spawned addItemCargoGlobal ["IDA_BactaBandage", 1];
                                };
                            };
                            _varry = _varry - 1;
                        };
                    };
                    case "Med":
                    {
                        private _crate = selectRandom ["FST_HGCrate_Misc1","FST_HGCrate_Misc2","FST_HGCrate_Misc3","FST_HGCrate_Misc4","FST_HGCrate_Misc5","FST_HGCrate_Misc6","FST_HGCrate_Misc8","FFST_HGCrate_Misc9","FST_HGCrate_Misc10","FST_HGCrate_Misc11","FST_HGCrate_Misc16","FST_HGCrate_Misc17","FST_HGCrate_Misc20","FST_HGCrate_BBarrel","FST_HGCrate_GBarrel"];
                        private _spawned = createVehicle
                        [
                            _crate,
                            _spawnpos,
                            [],
                            0,
                            "CAN_COLLIDE"
                        ];
                        _spawned setDir (random 360);
                        _storage pushBack _spawned;
                        missionNamespace setVariable ["FST_LootCrateList", _storage];
                        private _varry = selectRandomWeighted [3, 0.25, 4, 0.5, 5, 0.25];
                        while {_varry > 0} do
                        {
                            private _choice = selectRandom _meds;
                            switch (_choice) do
                            {
                                case "IDA_BactaBandage":
                                {
                                    private _amount = selectRandom [7,8,9,10,11];
                                    _spawned addItemCargoGlobal [_choice, _amount];
                                };
                                case "IDA_Cauterizer":
                                {
                                    _spawned addItemCargoGlobal [_choice, 1];
                                    _spawned addItemCargoGlobal ["IDA_BactaBandage", 1];
                                };
                                default
                                {
                                    private _amount = selectRandom [1,2,3];
                                    _spawned addItemCargoGlobal [_choice, _amount];
                                    _spawned addItemCargoGlobal ["IDA_BactaBandage", 1];
                                };
                            };
                            _varry = _varry - 1;
                        };
                    };
                    case "Large":
                    {
                        private _spawned = createVehicle
                        [
                            "FST_HGCrate_Med",
                            _spawnpos,
                            [],
                            0,
                            "CAN_COLLIDE"
                        ];
                        _spawned setDir (random 360);
                        _storage pushBack _spawned;
                        missionNamespace setVariable ["FST_LootCrateList", _storage];
                        private _varry = selectRandomWeighted [8, 0.25, 9, 0.5, 10, 0.25];
                        while {_varry > 0} do
                        {
                            private _choice = selectRandom _meds;
                            switch (_choice) do
                            {
                                case "IDA_BactaBandage":
                                {
                                    private _amount = selectRandom [8,9,10,11,12];
                                    _spawned addItemCargoGlobal [_choice, _amount];
                                };
                                case "IDA_Cauterizer":
                                {
                                    _spawned addItemCargoGlobal [_choice, 1];
                                    _spawned addItemCargoGlobal ["IDA_BactaBandage", 1];
                                };
                                default
                                {
                                    private _amount = selectRandom [1,2,3,4];
                                    _spawned addItemCargoGlobal [_choice, _amount];
                                    _spawned addItemCargoGlobal ["IDA_BactaBandage", 1];
                                };
                            };
                            _varry = _varry - 1;
                        };
                        _spawned addItemCargoGlobal ["FST_Bacta_Tank", 1];
                    };
                };
                private _odds = missionNamespace getVariable "FST_LootCrateOdds";
                _odds set [1, (_odds select 1) + 0.1];
                _odds set [3,0.2];
                _odds set [5, (_odds select 5) + 0.1];
                _odds set [7, (_odds select 7) + 0.1];
                _odds set [9, (_odds select 9) + 0.15];
                _odds set [11, (_odds select 11) + 0.005];
                _odds set [13, (_odds select 13) + 0.1];
                missionNamespace setVariable ["FST_LootCrateOdds",_odds];
            };
            case "Melee":
            {
                switch (_size) do
                {
                    case "Small":
                    {
                        private _crate = selectRandom ["FST_HGCrate_SmallGrey","FST_HGCrate_SmallBlack","FST_HGCrate_Misc13","FST_HGCrate_Misc14","FST_HGCrate_Misc15","FST_HGCrate_Misc18","FST_HGCrate_Misc19","FST_HGCrate_Misc21","FST_HGCrate_WBarrel","FST_HGCrate_SmallBarrel","FST_HGCrate_GSmallBarrel","FST_HGCrate_WSmallBarrel"];
                        private _spawned = createVehicle
                        [
                            _crate,
                            _spawnpos,
                            [],
                            0,
                            "CAN_COLLIDE"
                        ];
                        _spawned setDir (random 360);
                        _storage pushBack _spawned;
                        missionNamespace setVariable ["FST_LootCrateList", _storage];
                        private _melee = selectRandom ["41st_Naval_Dirk","41st_Bayonet1_Weapon","IDA_Clone_Knife","Weap_melee_knife","Knife_kukri","Knife_m3","UNSC_Knife","WBK_survival_weapon_4","WBK_survival_weapon_3","WBK_BrassKnuckles"];
                        _spawned addItemCargoGlobal [_melee, 1];
                    };
                    case "Med":
                    {
                        private _crate = selectRandom ["FST_HGCrate_Misc1","FST_HGCrate_Misc2","FST_HGCrate_Misc3","FST_HGCrate_Misc4","FST_HGCrate_Misc5","FST_HGCrate_Misc6","FST_HGCrate_Misc8","FFST_HGCrate_Misc9","FST_HGCrate_Misc10","FST_HGCrate_Misc11","FST_HGCrate_Misc16","FST_HGCrate_Misc17","FST_HGCrate_Misc20","FST_HGCrate_BBarrel","FST_HGCrate_GBarrel","FST_HGCrate_Grey","FST_HGCrate_Black","FST_HGCrate_Blue","FST_HGCrate_Green","FST_HGCrate_Orange"];
                        private _spawned = createVehicle
                        [
                            _crate,
                            _spawnpos,
                            [],
                            0,
                            "CAN_COLLIDE"
                        ];
                        _spawned setDir (random 360);
                        _storage pushBack _spawned;
                        missionNamespace setVariable ["FST_LootCrateList", _storage];
                        private _melee = selectRandom ["IDA_StunStick","WBK_Katana","Sashka_Russian","JMSLLTE_Wm_GuardPike","JMSLLTE_Wm_InqDagger","WBK_Dutch_Vibro","WBK_Morket_CloneAssasinWeaponMain","WBK_SciFi_Sword_4","WBK_SciFi_Sword_3","WBK_SciFi_Sword_1","DpSword","WBK_SciFi_Sword_2","WBK_SciFi_Sword_6","WBK_SciFi_Sword_5"];
                        _spawned addItemCargoGlobal [_melee, 1];
                        while {_carry > 0} do
                        {
                            private _choice = selectRandomWeighted _storages;
                            switch (_choice) do
                            {
                                case "FST_HGVest_Mini";
                                case "FST_HGVest_Small";
                                case "FST_HGVest_Med";
                                case "FST_HGVest_Large";
                                case "FST_HGVest_Huge":
                                {
                                    _spawned addItemCargoGlobal [_choice, 1];
                                    _carry = _carry - 1;
                                };
                                case "FST_HGBag_Mini";
                                case "FST_HGBag_Small";
                                case "FST_HGBag_Med";
                                case "FST_HGBag_Large";
                                case "FST_HGBag_Huge":
                                {
                                    _spawned addBackpackCargoGlobal [_choice, 1];
                                    _carry = _carry - 1;
                                };
                            };
                        };
                    };
                    case "Large":
                    {
                        private _crate = selectRandom ["FST_HGCrate_Misc7Orange","FST_HGCrate_Misc7Black","FST_HGCrate_Misc7Blue","FST_HGCrate_Misc7Grey"];
                        private _spawned = createVehicle
                        [
                            _crate,
                            _spawnpos,
                            [],
                            0,
                            "CAN_COLLIDE"
                        ];
                        _spawned setDir (random 360);
                        _storage pushBack _spawned;
                        missionNamespace setVariable ["FST_LootCrateList", _storage];
                        _spawned addItemCargoGlobal ["JMSLLTE_Wm_InqHammer", 1];
                        while {_carry > 0} do
                        {
                            private _choice = selectRandomWeighted _storages;
                            switch (_choice) do
                            {
                                case "FST_HGVest_Mini";
                                case "FST_HGVest_Small";
                                case "FST_HGVest_Med";
                                case "FST_HGVest_Large";
                                case "FST_HGVest_Huge":
                                {
                                    _spawned addItemCargoGlobal [_choice, 1];
                                    _carry = _carry - 1;
                                };
                                case "FST_HGBag_Mini";
                                case "FST_HGBag_Small";
                                case "FST_HGBag_Med";
                                case "FST_HGBag_Large";
                                case "FST_HGBag_Huge":
                                {
                                    _spawned addBackpackCargoGlobal [_choice, 1];
                                    _carry = _carry - 1;
                                };
                            };
                            
                        };
                    };
                };
                private _odds = missionNamespace getVariable "FST_LootCrateOdds";
                _odds set [1, (_odds select 1) + 0.1];
                _odds set [3, (_odds select 3) + 0.1];
                _odds set [5,0.1];
                _odds set [7, (_odds select 7) + 0.1];
                _odds set [9, (_odds select 9) + 0.15];
                _odds set [11, (_odds select 11) + 0.005];
                _odds set [13, (_odds select 13) + 0.1];
                missionNamespace setVariable ["FST_LootCrateOdds",_odds];
            };
            case "Side":
            {
                
                private _sides = ["FST_A180","FST_DC15P","FST_DC17","FST_DH42_Pistol","FST_DL18_Pistol","FST_DL44_Pistol","FST_DT12_Pistol","FST_E11P","FST_EC17_Pistol","FST_K16_Pistol","FST_Relbyk25_Pistol","FST_RG4D","FST_RK3_Pistol","FST_SE14R","FST_Westar35","FST_Westar35_SA_Pistol"];
                switch (_size) do
                {
                    case "Small":
                    {
                        private _crate = selectRandom ["FST_HGCrate_SmallGrey","FST_HGCrate_SmallBlack","FST_HGCrate_Misc13","FST_HGCrate_Misc14","FST_HGCrate_Misc15","FST_HGCrate_Misc18","FST_HGCrate_Misc19","FST_HGCrate_Misc21","FST_HGCrate_WBarrel","FST_HGCrate_SmallBarrel","FST_HGCrate_GSmallBarrel","FST_HGCrate_WSmallBarrel"];
                        private _spawned = createVehicle
                        [
                            _crate,
                            _spawnpos,
                            [],
                            0,
                            "CAN_COLLIDE"
                        ];
                        _spawned setDir (random 360);
                        _storage pushBack _spawned;
                        missionNamespace setVariable ["FST_LootCrateList", _storage];
                        private _choice = selectRandom _sides;
                        _spawned addItemCargoGlobal [ _choice, 1];

                    };
                    case "Med":
                    {
                        private _crate = selectRandom ["FST_HGCrate_Misc1","FST_HGCrate_Misc2","FST_HGCrate_Misc3","FST_HGCrate_Misc4","FST_HGCrate_Misc5","FST_HGCrate_Misc6","FST_HGCrate_Misc8","FFST_HGCrate_Misc9","FST_HGCrate_Misc10","FST_HGCrate_Misc11","FST_HGCrate_Misc16","FST_HGCrate_Misc17","FST_HGCrate_Misc20","FST_HGCrate_BBarrel","FST_HGCrate_GBarrel","FST_HGCrate_Grey","FST_HGCrate_Black","FST_HGCrate_Blue","FST_HGCrate_Green","FST_HGCrate_Orange"];
                        private _spawned = createVehicle
                        [
                            _crate,
                            _spawnpos,
                            [],
                            0,
                            "CAN_COLLIDE"
                        ];
                        _spawned setDir (random 360);
                        _storage pushBack _spawned;
                        missionNamespace setVariable ["FST_LootCrateList", _storage];
                        for "_i" from 0 to 1 do 
                        {
                            private _choice = selectRandom _sides;
                            _spawned addItemCargoGlobal [ _choice, 1];
                        };
                        while {_carry > 0} do
                        {
                            private _choice = selectRandomWeighted _storages;
                            switch (_choice) do
                            {
                                case "FST_HGVest_Mini";
                                case "FST_HGVest_Small";
                                case "FST_HGVest_Med";
                                case "FST_HGVest_Large";
                                case "FST_HGVest_Huge":
                                {
                                    _spawned addItemCargoGlobal [_choice, 1];
                                    _carry = _carry - 1;
                                };
                                case "FST_HGBag_Mini";
                                case "FST_HGBag_Small";
                                case "FST_HGBag_Med";
                                case "FST_HGBag_Large";
                                case "FST_HGBag_Huge":
                                {
                                    _spawned addBackpackCargoGlobal [_choice, 1];
                                    _carry = _carry - 1;
                                };
                            };
                            
                        };
                    };
                    case "Large":
                    {
                        private _crate = selectRandom ["FST_HGCrate_Misc7Orange","FST_HGCrate_Misc7Black","FST_HGCrate_Misc7Blue","FST_HGCrate_Misc7Grey"];
                        private _spawned = createVehicle
                        [
                            _crate,
                            _spawnpos,
                            [],
                            0,
                            "CAN_COLLIDE"
                        ];
                        _spawned setDir (random 360);
                        _storage pushBack _spawned;
                        missionNamespace setVariable ["FST_LootCrateList", _storage];
                        for "_i" from 0 to 6 do 
                        {
                            private _choice = selectRandom _sides;
                            _spawned addItemCargoGlobal [ _choice, 1];
                        };
                        while {_carry > 0} do
                        {
                            private _choice = selectRandomWeighted _storages;
                            switch (_choice) do
                            {
                                case "FST_HGVest_Mini";
                                case "FST_HGVest_Small";
                                case "FST_HGVest_Med";
                                case "FST_HGVest_Large";
                                case "FST_HGVest_Huge":
                                {
                                    _spawned addItemCargoGlobal [_choice, 1];
                                    _carry = _carry - 1;
                                };
                                case "FST_HGBag_Mini";
                                case "FST_HGBag_Small";
                                case "FST_HGBag_Med";
                                case "FST_HGBag_Large";
                                case "FST_HGBag_Huge":
                                {
                                    _spawned addBackpackCargoGlobal [_choice, 1];
                                    _carry = _carry - 1;
                                };
                            };
                            
                        };
                    };
                };
                private _odds = missionNamespace getVariable "FST_LootCrateOdds";
                _odds set [1, (_odds select 1) + 0.1];
                _odds set [3, (_odds select 3) + 0.1];
                _odds set [5, (_odds select 5) + 0.1];
                _odds set [7,0.15];
                _odds set [9, (_odds select 9) + 0.15];
                _odds set [11, (_odds select 11) + 0.005];
                _odds set [13, (_odds select 13) + 0.1];
                missionNamespace setVariable ["FST_LootCrateOdds",_odds];
            };
            case "Main":
            {
                switch (_size) do
                {
                    case "Small":
                    {
                        private _crate = selectRandom ["FST_HGCrate_SmallGrey","FST_HGCrate_SmallBlack","FST_HGCrate_Misc13","FST_HGCrate_Misc14","FST_HGCrate_Misc15","FST_HGCrate_Misc18","FST_HGCrate_Misc19","FST_HGCrate_Misc21","FST_HGCrate_WBarrel","FST_HGCrate_SmallBarrel","FST_HGCrate_GSmallBarrel","FST_HGCrate_WSmallBarrel"];
                        private _spawned = createVehicle
                        [
                            _crate,
                            _spawnpos,
                            [],
                            0,
                            "CAN_COLLIDE"
                        ];
                        _spawned setDir (random 360);
                        _storage pushBack _spawned;
                        missionNamespace setVariable ["FST_LootCrateList", _storage];
                        private _main = selectRandom ["FST_A300C","FST_ACPA","FST_ACPR","FST_Arkanian_F","FST_Cinnagaran_Carbine","FST_DC15S","FST_DC17M","FST_DH17","FST_E5_Human","FST_EE4","FST_Galaar15","FST_EE3","FST_SE28","FST_TL50","FST_ValD"];
                        _spawned addItemCargoGlobal [_main, 1];
                    };
                    case "Med":
                    {
                        private _crate = selectRandom ["FST_HGCrate_Misc1","FST_HGCrate_Misc2","FST_HGCrate_Misc3","FST_HGCrate_Misc4","FST_HGCrate_Misc5","FST_HGCrate_Misc6","FST_HGCrate_Misc8","FFST_HGCrate_Misc9","FST_HGCrate_Misc10","FST_HGCrate_Misc11","FST_HGCrate_Misc16","FST_HGCrate_Misc17","FST_HGCrate_Misc20","FST_HGCrate_BBarrel","FST_HGCrate_GBarrel","FST_HGCrate_Grey","FST_HGCrate_Black","FST_HGCrate_Blue","FST_HGCrate_Green","FST_HGCrate_Orange"];
                        private _spawned = createVehicle
                        [
                            _crate,
                            _spawnpos,
                            [],
                            0,
                            "CAN_COLLIDE"
                        ];
                        _spawned setDir (random 360);
                        _storage pushBack _spawned;
                        missionNamespace setVariable ["FST_LootCrateList", _storage];
                        private _main = ["FST_773Firepuncher","FST_774CX","FST_A260","FST_A280","FST_A280C","FST_A300","FST_A310","FST_Arkanian_Stock_F","FST_DC15A","FST_DC15C_F","FST_DC15L_F","FST_DC15LE","FST_Verpine","FST_DH17_Rifle","FST_DL63","FST_DP23","FST_DW32S","FST_E5C_Stock","FST_F78","FST_Gundark","FST_M45_BlasterRifle","FST_RT97C_BlasterRifle","FST_SBB3","FST_SPA_K12","FST_Valken38x","FST_Westar_M5","FST_Westar_M5_A","FST_ZH73_MK2"];
                        for "_i" from 0 to 1 do 
                        {
                            private _choice = selectRandom _main;
                            _spawned addItemCargoGlobal [ _choice, 1];
                        };
                        while {_carry > 0} do
                        {
                            private _choice = selectRandomWeighted _storages;
                            switch (_choice) do
                            {
                                case "FST_HGVest_Mini";
                                case "FST_HGVest_Small";
                                case "FST_HGVest_Med";
                                case "FST_HGVest_Large";
                                case "FST_HGVest_Huge":
                                {
                                    _spawned addItemCargoGlobal [_choice, 1];
                                    _carry = _carry - 1;
                                };
                                case "FST_HGBag_Mini";
                                case "FST_HGBag_Small";
                                case "FST_HGBag_Med";
                                case "FST_HGBag_Large";
                                case "FST_HGBag_Huge":
                                {
                                    _spawned addBackpackCargoGlobal [_choice, 1];
                                    _carry = _carry - 1;
                                };
                            };
                            
                        };
                    };
                    case "Large":
                    {
                        private _crate = selectRandom ["FST_HGCrate_Misc7Orange","FST_HGCrate_Misc7Black","FST_HGCrate_Misc7Blue","FST_HGCrate_Misc7Grey"];
                        private _spawned = createVehicle
                        [
                            _crate,
                            _spawnpos,
                            [],
                            0,
                            "CAN_COLLIDE"
                        ];
                        _spawned setDir (random 360);
                        _storage pushBack _spawned;
                        missionNamespace setVariable ["FST_LootCrateList", _storage];
                        private _main = ["FST_A300C","FST_ACPA","FST_ACPR","FST_Arkanian_F","FST_Cinnagaran_Carbine","FST_DC15S","FST_DC17M","FST_DH17","FST_E5_Human","FST_EE4","FST_Galaar15","FST_EE3","FST_SE28","FST_TL50","FST_ValD","FST_773Firepuncher","FST_774CX","FST_A260","FST_A280","FST_A280C","FST_A300","FST_A310","FST_Arkanian_Stock_F","FST_DC15A","FST_DC15C_F","FST_DC15L_F","FST_DC15LE","FST_Verpine","FST_DH17_Rifle","FST_DL63","FST_DP23","FST_DW32S","FST_E5C_Stock","FST_F78","FST_Gundark","FST_M45_BlasterRifle","FST_RT97C_BlasterRifle","FST_SBB3","FST_SPA_K12","FST_Valken38x","FST_Westar_M5","FST_Westar_M5_A","FST_ZH73_MK2"];
                        for "_i" from 0 to 6 do 
                        {
                            private _choice = selectRandom _main;
                            _spawned addItemCargoGlobal [ _choice, 1];
                        };
                        while {_carry > 0} do
                        {
                            private _choice = selectRandomWeighted _storages;
                            switch (_choice) do
                            {
                                case "FST_HGVest_Mini";
                                case "FST_HGVest_Small";
                                case "FST_HGVest_Med";
                                case "FST_HGVest_Large";
                                case "FST_HGVest_Huge":
                                {
                                    _spawned addItemCargoGlobal [_choice, 1];
                                    _carry = _carry - 1;
                                };
                                case "FST_HGBag_Mini";
                                case "FST_HGBag_Small";
                                case "FST_HGBag_Med";
                                case "FST_HGBag_Large";
                                case "FST_HGBag_Huge":
                                {
                                    _spawned addBackpackCargoGlobal [_choice, 1];
                                    _carry = _carry - 1;
                                };
                            };
                            
                        };
                    };
                };
                private _odds = missionNamespace getVariable "FST_LootCrateOdds";
                _odds set [1, (_odds select 1) + 0.1];
                _odds set [3, (_odds select 3) + 0.1];
                _odds set [5, (_odds select 5) + 0.1];
                _odds set [7, (_odds select 7) + 0.1];
                _odds set [9,0.2];
                _odds set [11, (_odds select 11) + 0.005];
                _odds set [13, (_odds select 13) + 0.1];
                missionNamespace setVariable ["FST_LootCrateOdds",_odds];
            };
            case "Heavy":
            {
                private _spawned = createVehicle
                [
                    "FST_HGCrate_Misc12",
                    _spawnpos,
                    [],
                    0,
                    "CAN_COLLIDE"
                ];
                _spawned setDir (random 360);
                _storage pushBack _spawned;
                missionNamespace setVariable ["FST_LootCrateList", _storage];
                private _choice = selectRandom ["Pistol","Flamer","X","Proto","M-41","T-21","T-7","E-5S","DLT","Z-6","RPS"];
                switch (_choice) do
                {
                    case "Pistol":
                    {
                        _spawned addItemCargoGlobal ["FST_LV_13", 1];
                        _spawned addItemCargoGlobal ["FST_blaster_cell_LV13_Red", 3];
                    };
                    case "Flamer":
                    {
                        _spawned addItemCargoGlobal ["FST_BTX42", 1];
                        _spawned addItemCargoGlobal ["FST_FuelTank", 1];
                    };
                    case "X":
                    {
                        _spawned addItemCargoGlobal ["FST_DC15X", 1];
                        _spawned addItemCargoGlobal ["FST_blaster_cell_Overcharged_Red", 2];
                    };
                    case "Proto":
                    {
                        _spawned addItemCargoGlobal ["FST_DC1A_Prototype", 1];
                        _spawned addItemCargoGlobal ["FST_DC1A_Prototype_120Rnd_Red", 1];
                    };
                    case "M-41":
                    {
                        _spawned addItemCargoGlobal ["FST_M41", 1];
                        _spawned addItemCargoGlobal ["FST_blaster_battery_Red", 1];
                    };
                    case "T-21":
                    {
                        _spawned addItemCargoGlobal ["FST_T21", 1];
                        _spawned addItemCargoGlobal ["FST_thermal_coil_T21_Red", 1];
                    };
                    case "T-7":
                    {
                        _spawned addItemCargoGlobal ["FST_T7_BlasterRifle", 1];
                        _spawned addItemCargoGlobal ["FST_thermal_coil_T15_Red", 1];
                    };
                    case "E-5S":
                    {
                        _spawned addItemCargoGlobal ["FST_E5S", 1];
                        _spawned addItemCargoGlobal ["FST_Droid_blaster_cell_Overcharged_Red", 2];
                    };
                    case "DLT":
                    {
                        _spawned addItemCargoGlobal ["FST_DLT19_Rifle", 1];
                        _spawned addItemCargoGlobal ["FST_blaster_cell_Overcharged_Red", 2];
                    };
                    case "Z-6":
                    {
                        _spawned addItemCargoGlobal ["FST_Z6", 1];
                        _spawned addItemCargoGlobal ["FST_blaster_battery_Red", 1];
                    };
                    case "RPS":
                    {
                        _spawned addItemCargoGlobal ["FST_RPS6HP", 1];
                        _spawned addItemCargoGlobal ["FST_RPS6_rocket", 2];
                    };
                };
                while {_carry > 0} do
                {
                    private _choice = selectRandomWeighted _storages;
                    switch (_choice) do
                    {
                        case "FST_HGVest_Mini";
                        case "FST_HGVest_Small";
                        case "FST_HGVest_Med";
                        case "FST_HGVest_Large";
                        case "FST_HGVest_Huge":
                        {
                            _spawned addItemCargoGlobal ["FST_HGVest_Huge", 1];
                            _carry = _carry - 1;
                        };
                        case "FST_HGBag_Mini";
                        case "FST_HGBag_Small";
                        case "FST_HGBag_Med";
                        case "FST_HGBag_Large";
                        case "FST_HGBag_Huge":
                        {
                            _spawned addBackpackCargoGlobal ["FST_HGBag_Huge", 1];
                            _carry = _carry - 1;
                        };
                    };
                    
                };
                private _odds = missionNamespace getVariable "FST_LootCrateOdds";
                _odds set [1, (_odds select 1) + 0.1];
                _odds set [3, (_odds select 3) + 0.1];
                _odds set [5, (_odds select 5) + 0.1];
                _odds set [7, (_odds select 7) + 0.1];
                _odds set [9, (_odds select 9) + 0.15];
                _odds set [11,0.005];
                _odds set [13, (_odds select 13) + 0.1];
                missionNamespace setVariable ["FST_LootCrateOdds",_odds];
            };
            case "Boom":
            {
                private _booms = ["FST_grenade_Detonator_mag","FST_grenade_Penetrator_mag","IDA_grenade_Sonic_mag","IDA_grenade_Detonator_mag","FST_grenade_smoke_orange_mag","IDA_grenade_Smoke_mag","IDA_grenade_Smoke_Red_mag","IDA_grenade_Smoke_Purple_mag","IDA_grenade_Smoke_Green_mag","IDA_grenade_Smoke_Blue_mag","IEDUrbanSmall_Remote_Mag","IEDLandSmall_Remote_Mag","APERSMine_Range_Mag","APERSTripMine_Wire_Mag"];
                switch (_size) do
                {
                    case "Small":
                    {
                        private _crate = selectRandom ["FST_HGCrate_SmallGrey","FST_HGCrate_SmallBlack","FST_HGCrate_Misc13","FST_HGCrate_Misc14","FST_HGCrate_Misc15","FST_HGCrate_Misc18","FST_HGCrate_Misc19","FST_HGCrate_Misc21","FST_HGCrate_WBarrel","FST_HGCrate_SmallBarrel","FST_HGCrate_GSmallBarrel","FST_HGCrate_WSmallBarrel"];
                        private _spawned = createVehicle
                        [
                            _crate,
                            _spawnpos,
                            [],
                            0,
                            "CAN_COLLIDE"
                        ];
                        _spawned setDir (random 360);
                        _storage pushBack _spawned;
                        missionNamespace setVariable ["FST_LootCrateList", _storage];
                        private _choice = selectRandom _booms;
                        private _amount = selectRandom [1,2,3];
                        _spawned addItemCargoGlobal [_choice, _amount];
                    };
                    case "Med":
                    {
                        private _crate = selectRandom ["FST_HGCrate_Misc1","FST_HGCrate_Misc2","FST_HGCrate_Misc3","FST_HGCrate_Misc4","FST_HGCrate_Misc5","FST_HGCrate_Misc6","FST_HGCrate_Misc8","FFST_HGCrate_Misc9","FST_HGCrate_Misc10","FST_HGCrate_Misc11","FST_HGCrate_Misc16","FST_HGCrate_Misc17","FST_HGCrate_Misc20","FST_HGCrate_BBarrel","FST_HGCrate_GBarrel"];
                        private _spawned = createVehicle
                        [
                            _crate,
                            _spawnpos,
                            [],
                            0,
                            "CAN_COLLIDE"
                        ];
                        _spawned setDir (random 360);
                        _storage pushBack _spawned;
                        missionNamespace setVariable ["FST_LootCrateList", _storage];
                        private _varry = selectRandomWeighted [3, 0.25, 4, 0.5, 5, 0.25];
                        while {_varry > 0} do
                        {
                            private _choice = selectRandom _booms;
                            private _amount = selectRandom [1,2,3];
                            _spawned addItemCargoGlobal [_choice, _amount];
                            _varry = _varry - 1;
                        };
                    };
                    case "Large":
                    {
                        private _spawned = createVehicle
                        [
                            "FST_HGCrate_Explosive",
                            _spawnpos,
                            [],
                            0,
                            "CAN_COLLIDE"
                        ];
                        _spawned setDir (random 360);
                        _storage pushBack _spawned;
                        missionNamespace setVariable ["FST_LootCrateList", _storage];
                        private _varry = selectRandomWeighted [7, 0.15, 8, 0.5, 9, 0.5, 10, 0.25];
                        while {_varry > 0} do
                        {
                            private _choice = selectRandom _booms;
                            private _amount = selectRandom [5,6,7,8];
                            _spawned addItemCargoGlobal [_choice, _amount];
                            _varry = _varry - 1;
                        };
                        _spawned addItemCargoGlobal ["APERSMineDispenser_Mag", 1];
                        _spawned addItemCargoGlobal ["FST_RPS6_Disposable", 1];
                    };
                };
                private _odds = missionNamespace getVariable "FST_LootCrateOdds";
                _odds set [1, (_odds select 1) + 0.1];
                _odds set [3, (_odds select 3) + 0.1];
                _odds set [5, (_odds select 5) + 0.1];
                _odds set [7, (_odds select 7) + 0.1];
                _odds set [9, (_odds select 9) + 0.15];
                _odds set [11, (_odds select 11) + 0.005];
                _odds set [13,0.1];
                missionNamespace setVariable ["FST_LootCrateOdds",_odds];
            };
        };
    }
    else
    {
        private _cruelty = selectRandomWeighted [0, 0.8, 1, 0.2];
        private _spawned = "";
        if (_cruelty == 1) then
        {
            _spawned = createVehicle
            [
                "FST_HGBomb_Misc12",
                _spawnpos,
                [],
                0,
                "CAN_COLLIDE"
            ];
            _spawned setDir (random 360);
            _storage pushBack _spawned;
            missionNamespace setVariable ["FST_LootCrateList", _storage];
        }
        else
        {
            private _crate = selectRandom ["FST_HGBomb_SmallGrey","FST_HGBomb_SmallBlack","FST_HGBomb_Misc13","FST_HGBomb_Misc14","FST_HGBomb_Misc15","FST_HGBomb_Misc18","FST_HGBomb_Misc19","FST_HGBomb_Misc21","FST_HGBomb_WBarrel","FST_HGBomb_SmallBarrel","FST_HGBomb_GSmallBarrel","FST_HGBomb_WSmallBarrel","FST_HGBomb_Misc1","FST_HGBomb_Misc2","FST_HGBomb_Misc3","FST_HGBomb_Misc4","FST_HGBomb_Misc5","FST_HGBomb_Misc6","FST_HGBomb_Misc8","FFST_HGBomb_Misc9","FST_HGBomb_Misc10","FST_HGBomb_Misc11","FST_HGBomb_Misc16","FST_HGBomb_Misc17","FST_HGBomb_Misc20","FST_HGBomb_BBarrel","FST_HGBomb_GBarrel","FST_HGBomb_Grey","FST_HGBomb_Black","FST_HGBomb_Blue","FST_HGBomb_Green","FST_HGBomb_Orange","FST_HGBomb_Ammo","FST_HGBomb_Explosive","FST_HGBomb_Med","FST_HGBomb_Misc7Orange","FST_HGBomb_Misc7Black","FST_HGBomb_Misc7Blue","FST_HGBomb_Misc7Grey"];
            _spawned = createVehicle
            [
                _crate,
                _spawnpos,
                [],
                0,
                "CAN_COLLIDE"
            ];
            _spawned setDir (random 360);
            _storage pushBack _spawned;
            missionNamespace setVariable ["FST_LootCrateList", _storage];
        };
        ["FST_setBoomInteract", [_spawned,_pos]] spawn CBA_fnc_globalEvent;
    };
    private _ctotal = missionNamespace getVariable "FST_CrateTotal";
    _ctotal = _ctotal + 1;
    if (_ctotal == (_total - 10)) then {missionNamespace setVariable ["FST_HGRoundReady", true];} else {missionNamespace setVariable ["FST_CrateTotal", _ctotal];};
}] call CBA_fnc_addEventHandler;

["FST_setBoomInteract", {

    params ["_target","_pos"];
    private _sound = playSound3D ["A3\Sounds_F\weapons\mines\electron_trigger_1.wss",_target,false,getPosASL _target,1,1,4,0,true,true];
    if !(isNull player) then
    {
        private _storesound = player getVariable ["FST_BombSounds",[]];
        _storesound pushBack _sound;
        player setVariable ["FST_BombSounds",_storesound];
    };
    private _appear = _target addAction ['Inventory', {["FST_blowUpCrate", [_this select 3 select 0, _this select 3 select 1,_this select 3 select 2]] call CBA_fnc_serverEvent;},[_target,_pos,_sound],6,true,true,"","true",2];
    _target setUserActionText 
    [
        _appear,
        "Inventory",
        "<img size='2.5' image='\a3\ui_f\data\IGUI\Cfg\Actions\gear_ca'/>"
    ];

}] call CBA_fnc_addEventHandler;

["FST_blowUpCrate", {

    params ["_target","_pos","_sound"];
    deleteVehicle _target;
    private _bomb = "JMSLLTE_Detonitecharge_imp" createVehicle _pos;
    _bomb setDamage 1;
    stopSound _sound;

}] call CBA_fnc_addEventHandler;

["FST_clearBombSounds", {

    if !(isNull player) then
    {
        private _sounds = player getVariable ["FST_BombSounds",[]];
        {
            stopSound _x;
        } forEach _sounds;
        player setVariable ["FST_BombSounds",[]];
    };

}] call CBA_fnc_addEventHandler;

["FST_setHGPlayerInventory", {

    disableUserInput true;
    private _returnuni = uniform player;
    private _returnhelm = headgear player;
    player setUnitLoadout [[],[],[],[],["FST_HGVest_Mini",[]],[],"","",[],["ItemMap","","","ItemCompass","ItemWatch",""]];
    player forceAddUniform _returnuni;
    player addHeadgear _returnhelm;
    player addItem "IDA_grenade_Smoke_mag";

}] call CBA_fnc_addEventHandler;

["FST_freePlayer", {

    disableUserInput false;
    hintSilent parseText "<t size='3' align='center' color='#07a62f'>Start!</t>";

}] call CBA_fnc_addEventHandler;