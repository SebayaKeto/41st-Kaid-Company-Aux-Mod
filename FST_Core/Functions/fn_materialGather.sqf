    // File: description.ext (or your mission's CfgFunctions)
    // (No changes from the provided version)
    class CfgFunctions
    {
        class FST // Your unique prefix
        {
            tag = "FST"; // Tag for calling functions: FST_fnc_functionName
            class ResourceGathering // Renaming this class to "ResourceGathering" would be more accurate now
            {
                file = "scripts\resource_gathering"; // Path to the folder containing the .sqf files

                // Tree Cutting Functions
                class addTreeCutInteraction { postInit = 1; };
                class client_startCutTree {};
                class server_processTreeCut { serverOnly = 1; };

                // Rock Mining Functions
                class addRockMineInteraction { postInit = 1; };
                class client_startMineRock {};
                class server_processRockMine { serverOnly = 1; };
            };
        };
    };

    /*
    --------------------------------------------------------------------------------
    File: initPlayerLocal.sqf (if not using XEH postInit for interactions)
    (No changes from the provided version)
    --------------------------------------------------------------------------------

    if (hasInterface && !isDedicated) then {
        // Call the function to add the ACE3 tree cutting interaction
        [] call FST_fnc_addTreeCutInteraction;
        // Call the function to add the ACE3 rock mining interaction
        [] call FST_fnc_addRockMineInteraction;


        // Optional: Re-add actions on respawn if needed
        player addEventHandler ["Respawn", {
            if (hasInterface) then {
                [] call FST_fnc_addTreeCutInteraction;
                [] call FST_fnc_addRockMineInteraction;
            };
        }];
    };
    */

    /*
    --------------------------------------------------------------------------------
    File: scripts\tree_cutting\fn_addTreeCutInteraction.sqf
    Client-side: Adds the ACE3 self-interaction for Tree Cutting.
    (No changes from the provided version)
    --------------------------------------------------------------------------------
    */
    // Function: FST_fnc_addTreeCutInteraction
    // Adds the ACE3 self-interaction to cut down nearby trees.
    // Action only appears if player has required tools in inventory and is not on cooldown.

    if (!isClass (configFile >> "CfgPatches" >> "ace_interact_menu")) exitWith {
        diag_log "FST TreeCutting: ACE3 Interact Menu not found. Tree Action not added.";
    };

    private _actionId = "FST_CutNearbyTreeAction";
    private _eToolClassName = "ACE_EntrenchingTool";
    private _woodsmanToolClassName = "MYMOD_WoodsmansTool"; // !!! USER MUST CHANGE THIS placeholder !!!

    [_actionId, player] call ace_interact_menu_fnc_removeActionFromObject;

    private _cutTreeAction = [
        _actionId,
        "Cut Down Nearby Tree",
        "\a3\ui_f\data\igui\cfg\actions\axe_ca.paa",
        { call FST_fnc_client_startCutTree; },
        {
            private _playerObject = _this select 0;
            private _isOnCooldown = (_playerObject getVariable ["FST_lastTreeCutTime", 0]) + 5 > CBA_missionTime;
            if (_isOnCooldown) exitWith {false};

            private _playerItems = items _playerObject;
            private _hasETool = _eToolClassName in _playerItems;
            private _hasWoodsmansTool = _woodsmanToolClassName in _playerItems;
            if (!(_hasETool || _hasWoodsmansTool)) exitWith {false};

            private _nearbyTrees = nearestObjects [getPosATL _playerObject, ["Tree"], 5, true];
            (count _nearbyTrees > 0)
        },
        {}, [], [0,0,0], 1.5
    ] call ace_interact_menu_fnc_addSelfAction;

    diag_log "FST TreeCutting: Cut Down Tree action added to player (with inventory tool checks).";

    /*
    --------------------------------------------------------------------------------
    File: scripts\tree_cutting\fn_client_startCutTree.sqf
    Client-side: Handles the logic when the player selects the "Cut Down Tree" action.
    (No changes from the provided version)
    --------------------------------------------------------------------------------
    */
    // Function: FST_fnc_client_startCutTree
    // Executed when the player uses the "Cut Down Tree" ACE self-interaction.

    if (!hasInterface) exitWith {};

    private _searchRadius = 5;
    private _maxInteractionDist = 6;
    private _defaultCuttingDuration = 10;
    private _cooldownDuration = 5;

    private _eToolClassName = "ACE_EntrenchingTool";
    private _woodsmanToolClassName = "MYMOD_WoodsmansTool"; // !!! USER MUST CHANGE THIS placeholder !!!
    private _cuttingDuration = _defaultCuttingDuration;

    private _playerItems = items player;
    private _hasETool = _eToolClassName in _playerItems;
    private _hasWoodsmansTool = _woodsmanToolClassName in _playerItems;

    if (!(_hasETool || _hasWoodsmansTool)) exitWith {
        ["You need an Entrenching Tool or a Woodsman's Tool to cut trees.", false, player] call ace_common_fnc_displayTextLocalized;
        diag_log "FST TreeCutting Client: Attempted to cut tree without required tool.";
        false
    };

    if (_hasWoodsmansTool) then {
        _cuttingDuration = _defaultCuttingDuration / 2;
        ["Using Woodsman's Tool. Cutting faster...", false, player] call ace_common_fnc_displayTextLocalized;
    } else {
        if (_hasETool) then {
            ["Using Entrenching Tool...", false, player] call ace_common_fnc_displayTextLocalized;
        };
    };
    diag_log format ["FST TreeCutting Client: Using tool. Cutting duration set to %1s.", _cuttingDuration];

    if ((player getVariable ["FST_lastTreeCutTime", 0]) + _cooldownDuration > CBA_missionTime) exitWith {
        ["You are tired, wait a bit before cutting another tree.", false, player] call ace_common_fnc_displayTextLocalized;
    };

    private _playerPos = getPosATL player;
    private _potentialTrees = nearestObjects [_playerPos, [], _searchRadius + 1, true];
    private _validTrees = [];
    {
        if (player distanceSqr _x <= _searchRadius * _searchRadius && _x isKindOf "Tree" && simulationEnabled _x && !(_x getVariable ["FST_isCutDown", false])) then {
             _validTrees pushBack _x;
        }
    } forEach _potentialTrees;
    _validTrees sort {player distanceSqr _x < player distanceSqr _y};

    if (count _validTrees == 0) exitWith {
        ["No suitable tree found within " + str _searchRadius + " meters.", false, player] call ace_common_fnc_displayTextLocalized;
    };
    private _treeToCut = _validTrees select 0;

    [player, _cuttingDuration,
        { [_this select 1, _this select 0] remoteExecCall ["FST_fnc_server_processTreeCut", 2]; },
        { ["Tree cutting cancelled.", false, (_this select 0)] call ace_common_fnc_displayTextLocalized; },
        "Cutting Down Tree...",
        { (_this select 1 distance (_this select 0) > _maxInteractionDist) || isNull (_this select 0) || !alive (_this select 0) || ((_this select 0) getVariable ["FST_isCutDown", false]) },
        [_treeToCut, player], [player], [_treeToCut, player]
    ] call ace_common_fnc_progressBar;

    /*
    --------------------------------------------------------------------------------
    File: scripts\tree_cutting\fn_server_processTreeCut.sqf
    Server-side: Handles tree removal and wood distribution.
    (No changes from the provided version)
    --------------------------------------------------------------------------------
    */
    // Function: FST_fnc_server_processTreeCut
    params ["_player", "_treeObject"];
    if (isNull _player || !alive _player) exitWith { diag_log format ["FST TreeCutting Server: Invalid player (%1).", _player]; };
    if (isNull _treeObject || !(_treeObject isKindOf "Tree")) exitWith { diag_log format ["FST TreeCutting Server: Invalid tree (%1) for player %2.", _treeObject, name _player]; };
    if (_player distance _treeObject > 7) exitWith { diag_log format ["FST TreeCutting Server: Player %1 too far from tree %2.", name _player, _treeObject]; };
    if (_treeObject getVariable ["FST_isCutDown", false]) exitWith { diag_log format ["FST TreeCutting Server: Tree %1 already processed for %2.", _treeObject, name _player]; };
    _treeObject setVariable ["FST_isCutDown", true, true];

    private _woodClassName = "MYMOD_Item_WoodLog";
    private _woodAmountPerTree = 10;
    private _ironWoodClassName = "MYMOD_Item_IronWoodLog";
    private _ironWoodAmount = 10;
    private _minHeightForIronWood = 10;
    private _cooldownDuration = 5;

    private _currentWoodClassName = _woodClassName;
    private _currentWoodAmount = _woodAmountPerTree;
    private _boundingBox = boundingBox _treeObject;
    private _treeHeight = (_boundingBox select 1 select 2) - (_boundingBox select 0 select 2);

    if (_treeHeight > _minHeightForIronWood) then {
        _currentWoodClassName = _ironWoodClassName;
        _currentWoodAmount = _ironWoodAmount;
    };
    _treeObject setDamage [1, true]; hideObjectGlobal _treeObject;

    private _woodAddedToBackpack = 0;
    private _playerBackpack = backpack _player;
    private _treeGroundPos = ASLToAGL getPosASL _treeObject; _treeGroundPos set [2, (_treeGroundPos select 2) + 0.1];

    if (_playerBackpack != "" && _playerBackpack != "B_Parachute") then {
        private _magazinesInBackpack = magazineCargo (backpackContainer _player);
        private _initialWoodCount = {_x == _currentWoodClassName} count _magazinesInBackpack;
        for "_i" from 1 to _currentWoodAmount do { _player addItemToBackpack _currentWoodClassName; };
        _magazinesInBackpack = magazineCargo (backpackContainer _player);
        private _finalWoodCount = {_x == _currentWoodClassName} count _magazinesInBackpack;
        _woodAddedToBackpack = _finalWoodCount - _initialWoodCount;
        if (_woodAddedToBackpack > _currentWoodAmount) then { _woodAddedToBackpack = _currentWoodAmount; };
        if (_woodAddedToBackpack < 0) then { _woodAddedToBackpack = 0; };
    };
    private _woodToDrop = _currentWoodAmount - _woodAddedToBackpack;

    private _itemNameForMsg = getText (configFile >> "CfgMagazines" >> _currentWoodClassName >> "displayName");
    if (_itemNameForMsg == "") then { _itemNameForMsg = _currentWoodClassName; };
    if (_woodAddedToBackpack > 0) then { [_player, format["You received %1 %2 in your backpack.", _woodAddedToBackpack, _itemNameForMsg], false] remoteExecCall ["ace_common_fnc_displayTextLocalized", _player]; };
    if (_woodToDrop > 0) then {
        for "_i" from 1 to _woodToDrop do { createVehicle ["GroundWeaponHolder", _treeGroundPos, [], 0, "CAN_COLLIDE"] addMagazineCargoGlobal [_currentWoodClassName, 1]; };
        [_player, format["%1 %2 placed on the ground.", _woodToDrop, _itemNameForMsg], false] remoteExecCall ["ace_common_fnc_displayTextLocalized", _player];
    };
    _player setVariable ["FST_lastTreeCutTime", CBA_missionTime, true];
    diag_log format ["FST TreeCutting Server: Player %1 cut tree. Awarded: %2. BP: %3, Drop: %4.", name _player, _currentWoodClassName, _woodAddedToBackpack, _woodToDrop];

    /*
    --------------------------------------------------------------------------------
    File: scripts\tree_cutting\fn_addRockMineInteraction.sqf
    Client-side: Adds the ACE3 self-interaction for Rock Mining.
    (No changes from the provided version)
    --------------------------------------------------------------------------------
    */
    // Function: FST_fnc_addRockMineInteraction
    // Adds the ACE3 self-interaction to mine nearby rocks.
    // Action only appears if player has required tools (Pickaxe or E-Tool) in inventory and is not on cooldown.

    if (!isClass (configFile >> "CfgPatches" >> "ace_interact_menu")) exitWith {
        diag_log "FST RockMining: ACE3 Interact Menu not found. Rock Action not added.";
    };

    private _actionId = "FST_MineNearbyRockAction";

    // --- Configuration for Tools ---
    private _eToolClassName = "ACE_EntrenchingTool";
    private _pickaxeClassName = "MYMOD_Pickaxe";
    private _woodsmanToolClassName = "MYMOD_WoodsmansTool";

    [_actionId, player] call ace_interact_menu_fnc_removeActionFromObject;

    private _mineRockAction = [
        _actionId,
        "Mine Nearby Rock",
        "\a3\ui_f\data\igui\cfg\actions\repair_ca.paa",
        { call FST_fnc_client_startMineRock; },
        {
            private _playerObject = _this select 0;
            private _isOnMiningCooldown = (_playerObject getVariable ["FST_lastRockMineTime", 0]) + 5 > CBA_missionTime;
            if (_isOnMiningCooldown) exitWith {false};

            private _playerItems = items _playerObject;
            private _hasETool = _eToolClassName in _playerItems;
            private _hasPickaxe = _pickaxeClassName in _playerItems;
            if (!(_hasPickaxe || _hasETool)) exitWith {false};

            private _rockTypesToSearch = ["Rock_Base"];
            private _nearbyRocks = nearestObjects [getPosATL _playerObject, _rockTypesToSearch, 5, true];
            (count _nearbyRocks > 0)
        },
        {}, [], [0,0,0], 1.5
    ] call ace_interact_menu_fnc_addSelfAction;

    diag_log "FST RockMining: Mine Nearby Rock action added to player (with inventory tool checks).";

    /*
    --------------------------------------------------------------------------------
    File: scripts\tree_cutting\fn_client_startMineRock.sqf
    Client-side: Handles the logic when the player selects the "Mine Nearby Rock" action.
    (No changes from the provided version)
    --------------------------------------------------------------------------------
    */
    // Function: FST_fnc_client_startMineRock
    // Executed when the player uses the "Mine Nearby Rock" ACE self-interaction.

    if (!hasInterface) exitWith {};

    private _searchRadius = 5;
    private _maxInteractionDist = 6;
    private _defaultMiningDuration = 12;
    private _miningCooldownDuration = 5;

    private _eToolClassName = "ACE_EntrenchingTool";
    private _pickaxeClassName = "MYMOD_Pickaxe";
    private _miningDuration = _defaultMiningDuration;

    private _playerItems = items player;
    private _hasETool = _eToolClassName in _playerItems;
    private _hasPickaxe = _pickaxeClassName in _playerItems;

    if (!(_hasPickaxe || _hasETool)) exitWith {
        ["You need a Pickaxe or an Entrenching Tool to mine rocks.", false, player] call ace_common_fnc_displayTextLocalized;
        diag_log "FST RockMining Client: Attempted to mine rock without required tool.";
        false
    };

    if (_hasPickaxe) then {
        _miningDuration = _defaultMiningDuration / 2;
        ["Using Pickaxe. Mining faster...", false, player] call ace_common_fnc_displayTextLocalized;
    } else {
        ["Using Entrenching Tool for mining...", false, player] call ace_common_fnc_displayTextLocalized;
    };
    diag_log format ["FST RockMining Client: Using tool. Mining duration set to %1s.", _miningDuration];

    if ((player getVariable ["FST_lastRockMineTime", 0]) + _miningCooldownDuration > CBA_missionTime) exitWith {
        ["You are tired, wait a bit before mining another rock.", false, player] call ace_common_fnc_displayTextLocalized;
    };

    private _playerPos = getPosATL player;
    private _rockTypesToSearch = ["Rock_Base"];
    private _potentialRocks = nearestObjects [_playerPos, _rockTypesToSearch, _searchRadius + 1, true];
    private _validRocks = [];
    {
        if (player distanceSqr _x <= _searchRadius * _searchRadius && simulationEnabled _x && !(_x getVariable ["FST_isMinedOut", false])) then {
             _validRocks pushBack _x;
        }
    } forEach _potentialRocks;
    _validRocks sort {player distanceSqr _x < player distanceSqr _y};

    if (count _validRocks == 0) exitWith {
        ["No suitable rock found within " + str _searchRadius + " meters.", false, player] call ace_common_fnc_displayTextLocalized;
    };
    private _rockToMine = _validRocks select 0;

    [player, _miningDuration,
        { [_this select 1, _this select 0] remoteExecCall ["FST_fnc_server_processRockMine", 2]; },
        { ["Rock mining cancelled.", false, (_this select 0)] call ace_common_fnc_displayTextLocalized; },
        "Mining Rock...",
        { (_this select 1 distance (_this select 0) > _maxInteractionDist) || isNull (_this select 0) || !alive (_this select 0) || ((_this select 0) getVariable ["FST_isMinedOut", false]) },
        [_rockToMine, player], [player], [_rockToMine, player]
    ] call ace_common_fnc_progressBar;

    /*
    --------------------------------------------------------------------------------
    File: scripts\tree_cutting\fn_server_processRockMine.sqf
    Server-side: Handles rock removal and stone distribution.
    *** THIS FILE HAS BEEN MODIFIED FOR NEW ROCK RESOURCE OUTPUTS ***
    --------------------------------------------------------------------------------
    */
    // Function: FST_fnc_server_processRockMine
    // Called by the client via remoteExec after successful rock mining progress.
    // Handles rock removal, complex resource distribution (stone, iron, rares), and mining cooldown.
    // Params: [_player, _rockObject]
    // Runs on server only.

    params ["_player", "_rockObject"];

    // --- Validation ---
    if (isNull _player || !alive _player) exitWith {
        diag_log format ["FST RockMining Server: Invalid player object (%1).", _player];
    };
    if (isNull _rockObject || !(simulationEnabled _rockObject) ) exitWith {
        diag_log format ["FST RockMining Server: Invalid rock object (%1) for player %2.", _rockObject, name _player];
    };
    if (_player distance _rockObject > 7) exitWith {
        diag_log format ["FST RockMining Server: Player %1 too far from rock %2.", name _player, _rockObject];
    };
    if (_rockObject getVariable ["FST_isMinedOut", false]) exitWith {
        diag_log format ["FST RockMining Server: Rock %1 already processed for player %2.", _rockObject, name _player];
    };

    _rockObject setVariable ["FST_isMinedOut", true, true];

    // --- Configuration for Rock Resources ---
    private _stoneClassName = "MYMOD_Item_Stone";         // !!! USER MUST CHANGE THIS !!!
    private _ironOreClassName = "MYMOD_Item_IronOre";       // !!! USER MUST CHANGE THIS !!!
    private _copperOreClassName = "MYMOD_Item_CopperOre";   // !!! USER MUST CHANGE THIS !!!
    private _aluminumOreClassName = "MYMOD_Item_AluminumOre"; // !!! USER MUST CHANGE THIS !!!
    private _nickelOreClassName = "MYMOD_Item_NickelOre";   // !!! USER MUST CHANGE THIS !!!
    private _silverOreClassName = "MYMOD_Item_SilverOre";   // !!! USER MUST CHANGE THIS !!!

    private _baseStoneAmount = 7; // 10 total = 7 stone + 3 iron
    private _ironOreAmount = 3;

    private _rareOreChance = 0.10; // 10% chance for one rare ore
    private _rareCopperAmount = 2;
    private _rareAluminumAmount = 2;
    private _rareNickelAmount = 2;
    private _rareSilverAmount = 1;

    private _miningCooldownDuration = 5; // seconds

    // --- Rock Removal ---
    hideObjectGlobal _rockObject;
    diag_log format ["FST RockMining Server: Rock %1 processed for removal by player %2.", _rockObject, name _player];

    // --- Resource Distribution ---
    private _rockGroundPos = ASLToAGL getPosASL _rockObject;
    _rockGroundPos set [2, (_rockGroundPos select 2) + 0.1]; // Slightly above ground

    // Helper local function to distribute a single item type
    _fnc_distributeItem = {
        params ["_itemPlayer", "_itemClassName", "_amountToGive", "_itemGroundPos"];
        private _itemsAddedToBackpack = 0;
        private _playerBackpack = backpack _itemPlayer;

        if (isNil "_itemClassName" || _itemClassName == "" || _amountToGive <= 0) exitWith {
            diag_log format ["FST RockMining Server: Invalid item data for distribution: ClassN: %1, Amount: %2", _itemClassName, _amountToGive];
        };

        if (_playerBackpack != "" && _playerBackpack != "B_Parachute") then {
            private _magazinesInBackpack = magazineCargo (backpackContainer _playerBackpack); // Corrected: use backpackContainer _playerBackpack
            private _initialItemCount = {_x == _itemClassName} count _magazinesInBackpack;

            for "_i" from 1 to _amountToGive do {
                _itemPlayer addItemToBackpack _itemClassName;
            }

            _magazinesInBackpack = magazineCargo (backpackContainer _playerBackpack); // Corrected: use backpackContainer _playerBackpack
            private _finalItemCount = {_x == _itemClassName} count _magazinesInBackpack;
            _itemsAddedToBackpack = _finalItemCount - _initialItemCount;

            if (_itemsAddedToBackpack > _amountToGive) then { _itemsAddedToBackpack = _amountToGive; };
            if (_itemsAddedToBackpack < 0) then { _itemsAddedToBackpack = 0; };
        }

        private _itemsToDrop = _amountToGive - _itemsAddedToBackpack;
        private _actualItemName = getText (configFile >> "CfgMagazines" >> _itemClassName >> "displayName");
        if (_actualItemName == "") then { _actualItemName = _itemClassName; };

        if (_itemsAddedToBackpack > 0) then {
            [_itemPlayer, format["You received %1 %2 in your backpack.", _itemsAddedToBackpack, _actualItemName], false] remoteExecCall ["ace_common_fnc_displayTextLocalized", _itemPlayer];
            diag_log format ["FST RockMining Server: Gave %1 %2 of %3 to %4's backpack.", _itemsAddedToBackpack, _actualItemName, _itemClassName, name _itemPlayer];
        }
        if (_itemsToDrop > 0) then {
            for "_i" from 1 to _itemsToDrop do {
                private _itemHolder = createVehicle ["GroundWeaponHolder", _itemGroundPos, [], 0, "CAN_COLLIDE"];
                _itemHolder addMagazineCargoGlobal [_itemClassName, 1];
            }
            [_itemPlayer, format["%1 %2 placed on the ground.", _itemsToDrop, _actualItemName], false] remoteExecCall ["ace_common_fnc_displayTextLocalized", _itemPlayer];
            diag_log format ["FST RockMining Server: Dropped %1 of %2 (%3) at %4 for player %5.", _itemsToDrop, _actualItemName, _itemClassName, _itemGroundPos, name _itemPlayer];
        }
    };

    // Distribute guaranteed Stone
    [_player, _stoneClassName, _baseStoneAmount, _rockGroundPos] call _fnc_distributeItem;

    // Distribute guaranteed Iron Ore
    [_player, _ironOreClassName, _ironOreAmount, _rockGroundPos] call _fnc_distributeItem;

    // Chance for Rare Ores
    if (random 1 < _rareOreChance) then {
        private _rareOreTypeSelected = floor (random 4); // 0 for Copper, 1 for Aluminum, 2 for Nickel, 3 for Silver
        private _rareOreClassNameToGive = "";
        private _rareOreAmountToGive = 0;

        switch (_rareOreTypeSelected) do {
            case 0: { // Copper
                _rareOreClassNameToGive = _copperOreClassName;
                _rareOreAmountToGive = _rareCopperAmount;
            };
            case 1: { // Aluminum
                _rareOreClassNameToGive = _aluminumOreClassName;
                _rareOreAmountToGive = _rareAluminumAmount;
            };
            case 2: { // Nickel
                _rareOreClassNameToGive = _nickelOreClassName;
                _rareOreAmountToGive = _rareNickelAmount;
            };
            case 3: { // Silver
                _rareOreClassNameToGive = _silverOreClassName;
                _rareOreAmountToGive = _rareSilverAmount;
            };
            default {
                // Should not happen
                diag_log "FST RockMining Server: Error in rare ore selection.";
            };
        };

        if (_rareOreClassNameToGive != "" && _rareOreAmountToGive > 0) then {
            diag_log format ["FST RockMining Server: Player %1 rolled for rare ore and got %2 of %3.", name _player, _rareOreAmountToGive, _rareOreClassNameToGive];
            [_player, _rareOreClassNameToGive, _rareOreAmountToGive, _rockGroundPos] call _fnc_distributeItem;
        } else {
             diag_log format ["FST RockMining Server: Player %1 rolled for rare ore but selection was invalid. ClassN: %2, Amount: %3", name _player, _rareOreClassNameToGive, _rareOreAmountToGive];
        };
    } else {
        diag_log format ["FST RockMining Server: Player %1 did not roll a rare ore.", name _player];
    };

    // --- Set Mining Cooldown ---
    _player setVariable ["FST_lastRockMineTime", CBA_missionTime, true];

    diag_log format ["FST RockMining Server: Player %1 (UID: %2) successfully mined rock. Cooldown set.", name _player, getPlayerUID _player];