FST_KitMenuUpdateKits = compile preprocessFileLineNumbers "41st_KitMenu\41st_Kit_System.sqf"; 
if (isNil "FST_RegularKits") then { FST_RegularKits = []; };
if (isNil "FST_AirborneKits") then { FST_AirborneKits = []; };

Wbk_equip_load = {
_obj = _this;
if ((isNil {_obj getVariable "WBK_kitMenuPresent"})) then { 
	_obj setVariable ["WBK_kitMenuPresent",0];
	_obj addAction ["<t color='#0093FF' size='1.45' font = 'PuristaSemibold'><img size='2' image='a3\ui_f\data\GUI\Cfg\Hints\Gear_ca.paa'/> Open kit menu</t>", {
		_obj = _this select 0;
		WBK_GlobalKitBoxRn = _obj;
		[] exec "\41st_KitMenu\WBK_Kit_Camera.sqs";
		if (getText (configfile >> 'CfgVehicles' >> typeOf player >> 'moves') == 'CfgMovesMaleSdr' || getText (configfile >> 'CfgVehicles' >> typeOf player >> 'moves') == 'CfgMovesMaleSevenFoot' || getText (configfile >> 'CfgVehicles' >> typeOf player >> 'moves') == 'CfgMovesMaleSpaceMarine') then {
			player switchMove selectRandom ["Acts_AidlPercMstpSloWWrflDnon_warmup_1","Acts_AidlPercMstpSloWWrflDnon_warmup_2","Acts_AidlPercMstpSloWWrflDnon_warmup_3","Acts_AidlPercMstpSloWWrflDnon_warmup_4","Acts_AidlPercMstpSloWWrflDnon_warmup_5"];
		};
		_dirToObj = [player, _obj] call BIS_fnc_dirTo;
		_actDir = _dirToObj - 180;
		player setDir _actDir;
	}];
}else{
systemChat "Object already have a kit menu";
};
};
FST_fnc_selectHelmet = {
    playSoundUI [selectRandom ["41st_KitMenu\sounds\select_helmet_1.ogg","41st_KitMenu\sounds\select_helmet_2.ogg"], 0.85, 1];
    private _display = uiNamespace getVariable ["FST_HelmetOverlay_Display", displayNull];
    private _listCtrl = _display displayCtrl 4102;
    private _index = lbCurSel _listCtrl;
    private _ctrlId = ctrlIDC _listCtrl;
    private _text = lbText [_ctrlId, _index];
    private _dataStr = lbData [_ctrlId, _index];
    private _gearArray = call compile _dataStr;
    private _gearClass = _gearArray select 0;
    private _cfgW = configFile >> "CfgWeapons" >> _gearClass;
    private _cfgV = configFile >> "CfgVehicles" >> _gearClass;
    private _isWeapon = isClass _cfgW;
    private _isVehicle = isClass _cfgV;
    private _cfg = if (_isWeapon) then {_cfgW} else {_cfgV};
    private _type = -1;
    if (_isWeapon) then {
        private _itemInfo = _cfg >> "ItemInfo";
        _type = getNumber (_itemInfo >> "type");
    } else {
        // Backpack detected (from CfgVehicles)
        _type = 302;
    };

    switch (_type) do {
        case 605: {
            removeHeadgear player;
            player addHeadgear _gearClass;
        };
        case 801: {
            private _items = uniformItems player;
            removeUniform player;
            player forceAddUniform _gearClass;
            { player addItemToUniform _x; } forEach _items;
        };
        case 701: {
            private _items = vestItems player;
            removeVest player;
            player addVest _gearClass;
            { player addItemToVest _x; } forEach _items;
        };
        case 302: {
            private _items = backpackItems player;
            removeBackpack player;
            player addBackpack _gearClass;
            { player addItemToBackpack _x; } forEach _items;
        };
        case 901: {
            player linkItem _gearClass;
        };
        default {
            systemChat format ["[ERROR] Unrecognized gear type: %1", _type];
        };
    };
};


FST_fnc_filterHelmets = {
	private _display = uiNamespace getVariable ["FST_HelmetOverlay_Display", displayNull];
	private _listCtrl = _display displayCtrl 4102;
	private _input = ctrlText (_display displayCtrl 4103);
	private _inputLower = toLower _input;
	private _allHelmets = uiNamespace getVariable ["FST_AllHelmetClasses", []];
	private _filtered = _allHelmets select {
		private _cfgW = configFile >> "CfgWeapons" >> _x;
		private _cfgV = configFile >> "CfgVehicles" >> _x;
		private _cfg = if (isClass _cfgW) then {_cfgW} else {_cfgV};
		private _displayName = toLower getText (_cfg >> "displayName");
		private _className = toLower _x;
		(_displayName find _inputLower) > -1 || (_className find _inputLower) > -1
	};
	lbClear _listCtrl;
	{
		private _cfgW = configFile >> "CfgWeapons" >> _x;
		private _cfgV = configFile >> "CfgVehicles" >> _x;
		private _cfg = if (isClass _cfgW) then {_cfgW} else {_cfgV};
		private _displayName = getText (_cfg >> "displayName");
		private _picture = getText (_cfg >> "picture");
		private _index = _listCtrl lbAdd _displayName;
		if (_picture != "") then {
			_listCtrl lbSetPicture [_index, _picture];
		};
		private _dataStr = format ["[%1]", str _x];
		_listCtrl lbSetData [_index, _dataStr];
	} forEach _filtered;
};


Wbk_AssignAditionalGear = {
params ["_control", "_index"];
private ["_lbData", "_itemClass", "_itemCount"];
_lbData = call compile (lbData [ctrlIDC _control, _index]);
_item = _lbData select 0;
switch true do {
        case (_item == "any"): {};
		case ( isClass (configFile >> "CfgUnitInsignia" >> _item)): {
		    playSoundUI [selectRandom ["41st_KitMenu\sounds\select_generic_1.ogg","41st_KitMenu\sounds\select_generic_2.ogg","41st_KitMenu\sounds\select_generic_3.ogg","41st_KitMenu\sounds\select_generic_4.ogg","41st_KitMenu\sounds\select_generic_5.ogg","41st_KitMenu\sounds\select_generic_6.ogg"], 0.85, 1];
		    player setVariable ["BIS_fnc_setUnitInsignia_class", nil];
		    [player, _item] call BIS_fnc_setUnitInsignia;
		};
		case (_item isKindOf ["Binocular", configFile >> "CfgWeapons"]): {
			player removeWeapon binocular player;
			player addWeapon _item;
			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_generic_1.ogg","41st_KitMenu\sounds\select_generic_2.ogg","41st_KitMenu\sounds\select_generic_3.ogg","41st_KitMenu\sounds\select_generic_4.ogg","41st_KitMenu\sounds\select_generic_5.ogg","41st_KitMenu\sounds\select_generic_6.ogg"], 0.85, 1];
		};
		case (getNumber(configFile >> "CfgWeapons" >> _item >> 'ItemInfo' >> 'type' ) isEqualTo 616): {
			player linkItem _item;
			playSoundUI ["41st_KitMenu\sounds\select_nvg.ogg", 0.85, 1];
		};
		case (getNumber(configFile >> "CfgWeapons" >> _item >> 'ItemInfo' >> 'type' ) isEqualTo 302 || getNumber(configFile >> "CfgWeapons" >> _item >> 'ItemInfo' >> 'type' ) isEqualTo 301 || getNumber(configFile >> "CfgWeapons" >> _item >> 'ItemInfo' >> 'type' ) isEqualTo 201 || getNumber(configFile >> "CfgWeapons" >> _item >> 'ItemInfo' >> 'type' ) isEqualTo 101): {
			player addPrimaryWeaponItem _item;
			player addHandgunItem _item;
			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_attachment_1.ogg","41st_KitMenu\sounds\select_attachment_2.ogg"], 0.65, 1];
		};
		case (getNumber(configFile >> "CfgWeapons" >> _item >> 'ItemInfo' >> 'type' ) isEqualTo 801): {
			_insignia = [player] call BIS_fnc_getUnitInsignia;
		    playSoundUI [selectRandom ["41st_KitMenu\sounds\select_cloth_1.ogg","41st_KitMenu\sounds\select_cloth_2.ogg","41st_KitMenu\sounds\select_cloth_3.ogg"], 0.85, 1];
		   _items = uniformItems player;
			removeUniform player;
			player forceAddUniform _item;
			{player addItemToUniform _x;} forEach _items;
			player setVariable ["BIS_fnc_setUnitInsignia_class", nil];
			[player, _insignia] call BIS_fnc_setUnitInsignia;
		};
		case (getNumber(configFile >> "CfgWeapons" >> _item >> 'ItemInfo' >> 'type' ) isEqualTo 701): {
		   playSoundUI [selectRandom ["41st_KitMenu\sounds\select_cloth_1.ogg","41st_KitMenu\sounds\select_cloth_2.ogg","41st_KitMenu\sounds\select_cloth_3.ogg"], 0.85, 1];
		   _items = vestItems player;
			removeVest player;
			player addVest _item;
			{player addItemToVest _x;} forEach _items;
			if (_item == "FST_Vest_NCO" && !([player, "itemAndroid"] call BIS_fnc_hasItem)) then {
				player addItem "itemAndroid";
			};
			if (_item == "FST_Vest_HeavyBag" && !([player, "itemAndroid"] call BIS_fnc_hasItem)) then {
				player addItem "itemAndroid";
			};
			if (_item == "FST_Vest_Base" && [player, "itemAndroid"] call BIS_fnc_hasItem) then {
				player removeItem "itemAndroid";
			};
		};
		case (getNumber(configFile >> "CfgWeapons" >> _item >> 'ItemInfo' >> 'type' ) isEqualTo 605): {
		    playSoundUI [selectRandom ["41st_KitMenu\sounds\select_helmet_1.ogg","41st_KitMenu\sounds\select_helmet_2.ogg"], 0.85, 1];
			removeHeadgear player;
			player addHeadgear _item;
		};
		case (isClass (configFile >> "CfgVehicles" >> _item)): {
			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_backpack_1.ogg", "41st_KitMenu\sounds\select_backpack_2.ogg"], 0.95, 1];
			removeBackpack player;
			player addBackpack _item;

			private _grenadeClass = "FST_grenade_Detonator_mag";
			private _grenadesCurrent = { _x == _grenadeClass } count magazines player;

			switch (_item) do {
				// REGULAR BACKPACKS
				case "FST_Clone_Backpack_Invisible_15L": {
					for "_i" from 1 to 10 do { player addItemToBackpack "FST_blaster_battery_DC15L_Blue"; };
				};
				case "FST_Clone_Backpack_Invisible_RPS": {
					for "_i" from 1 to 3 do { player addItemToBackpack "FST_RPS6_rocket"; };
					player addItemToBackpack "FST_RPS6_rocket_HE";
				};
				case "FST_Clone_Backpack_Invisible_Z6": {
					for "_i" from 1 to 7 do { player addItemToBackpack "FST_blaster_battery_Blue"; };
				};
				case "FST_Clone_Backpack_Invisible_STD": {
					for "_i" from 1 to 12 do { player addItemToBackpack "FST_blaster_cell_High_Blue"; };
					for "_i" from 1 to 18 do { player addItemToBackpack "FST_blaster_cell_Blue"; };
					for "_i" from 1 to 4 do {
						player addItemToBackpack "FST_blaster_cell_LE_Blue";
						player addItemToBackpack "FST_blaster_scatter_cell_DP23_Blue";
					};
					// Ensure player has exactly 6 grenades total
					if (_grenadesCurrent < 6) then {
						for "_i" from 1 to (6 - _grenadesCurrent) do {
							if (player canAddItemToVest _grenadeClass) then {
								player addItemToVest _grenadeClass;
							} else {
								player addItemToUniform _grenadeClass;
							};
						};
					};
				};
				case "FST_Clone_Backpack_Invisible_RifleAT": {
					for "_i" from 1 to 2 do { player addItemToBackpack "FST_thermal_coil_LP_Blue"; };
					for "_i" from 1 to 4 do { player addItemToBackpack "FST_thermal_coil_T15_Blue"; };
				};
				case "FST_Clone_Backpack_Invisible_PLX": {
					for "_i" from 1 to 3 do { player addItemToBackpack "FST_PLX1_Rocket"; };
				};

				// JUMP PACK BACKPACKS
				case "FST_Backpack_Jumppack_15L_Ammo": {
					for "_i" from 1 to 10 do { player addItemToBackpack "FST_blaster_battery_DC15L_Blue"; };
				};
				case "FST_Backpack_Jumppack_STD_Ammo": {
					for "_i" from 1 to 12 do { player addItemToBackpack "FST_blaster_cell_High_Blue"; };
					for "_i" from 1 to 18 do { player addItemToBackpack "FST_blaster_cell_Blue"; };
					for "_i" from 1 to 4 do {
						player addItemToBackpack "FST_blaster_cell_LE_Blue";
						player addItemToBackpack "FST_blaster_scatter_cell_DP23_Blue";
					};
					// Ensure player has exactly 6 grenades total
					if (_grenadesCurrent < 6) then {
						for "_i" from 1 to (6 - _grenadesCurrent) do {
							if (player canAddItemToVest _grenadeClass) then {
								player addItemToVest _grenadeClass;
							} else {
								player addItemToUniform _grenadeClass;
							};
						};
					};
				};
				case "FST_Backpack_Jumppack_RifleAT_Ammo": {
					for "_i" from 1 to 2 do { player addItemToBackpack "FST_thermal_coil_LP_Blue"; };
					for "_i" from 1 to 4 do { player addItemToBackpack "FST_thermal_coil_T15_Blue"; };
				};
				case "FST_Backpack_Jumppack_Z6_Ammo": {
					for "_i" from 1 to 7 do { player addItemToBackpack "FST_blaster_battery_Blue"; };
				};
				case "FST_Backpack_Jumppack_PLX_Ammo": {
					for "_i" from 1 to 3 do { player addItemToBackpack "FST_PLX1_Rocket"; };
				};
				case "FST_Backpack_Jumppack_RPS_Ammo": {
					for "_i" from 1 to 3 do { player addItemToBackpack "FST_RPS6_rocket"; };
					player addItemToBackpack "FST_RPS6_rocket_HE";
				};
			};
			if !(_item in ["FST_Clone_Backpack_Invisible_STD", "FST_Backpack_Jumppack_STD_Ammo"]) then {
				if (_grenadesCurrent > 3) then {
					player removeMagazines _grenadeClass;
					for "_i" from 1 to 3 do {
						if (player canAddItemToVest _grenadeClass) then {
							player addItemToVest _grenadeClass;
						} else {
							player addItemToUniform _grenadeClass;
						};
					};
				};
			};
		};
		case (_item == "FST_RPS6_Disposable"): {
			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_launcher_1.ogg","41st_KitMenu\sounds\select_launcher_2.ogg"], 0.85, 1];
			private _currentLauncher = secondaryWeapon player;
			if (_currentLauncher == "FST_RPS6_Base") then {
				player removeWeapon _currentLauncher;
			} else {
				player addWeapon _item;
			};
		};
		case (_item == "FST_RPS6HP"): {
			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_launcher_1.ogg", "41st_KitMenu\sounds\select_launcher_2.ogg"], 0.85, 1];
			private _existingLauncher = secondaryWeapon player;
			private _launcherMags = [secondaryWeapon player] call CBA_fnc_compatibleMagazines;
			player removeWeapon _existingLauncher;
			{ player removeMagazines _x; } forEach _launcherMags;
			player addWeapon "FST_RPS6HP";
			player addSecondaryWeaponItem "FST_RPS6_rocket";
			removeBackpack player;
			// If Howler kit, use jumppack RPS backpack
			if ((player getVariable ["WBK_Kit_Name",""]) == "Howler") then {
				player addBackpack "FST_Backpack_Jumppack_RPS";
			} else {
				player addBackpack "FST_Clone_Backpack_RPS";
			};
			for "_i" from 1 to 3 do { player addItemToBackpack "FST_RPS6_rocket"; };
			player addItemToBackpack "FST_RPS6_rocket_HE";
		};
		case (_item == "FST_PLX1"): {
			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_launcher_1.ogg", "41st_KitMenu\sounds\select_launcher_2.ogg"], 0.85, 1];
			private _existingLauncher = secondaryWeapon player;
			private _launcherMags = [secondaryWeapon player] call CBA_fnc_compatibleMagazines;
			player removeWeapon _existingLauncher;
			{ player removeMagazines _x; } forEach _launcherMags;
			player addWeapon "FST_PLX1";
			player addSecondaryWeaponItem "FST_PLX1_Rocket";
			removeBackpack player;
			// Check for Howler kit to use airborne backpack
			if ((player getVariable ["WBK_Kit_Name",""]) == "Howler") then {
				player addBackpack "FST_Backpack_Jumppack_PLX";
			} else {
				player addBackpack "FST_Clone_Backpack_PLX";
			};
			for "_i" from 1 to 2 do {
				player addItemToBackpack "FST_PLX1_Rocket";
				player addItemToBackpack "FST_PLX1_AA_mag";
			};
		};
		case (_item == "FST_PLX1_Guided"): {
			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_launcher_1.ogg", "41st_KitMenu\sounds\select_launcher_2.ogg"], 0.85, 1];
			private _existingLauncher = secondaryWeapon player;
			private _launcherMags = [secondaryWeapon player] call CBA_fnc_compatibleMagazines;
			player removeWeapon _existingLauncher;
			{ player removeMagazines _x; } forEach _launcherMags;
			player addWeapon "FST_PLX1_Guided";
			player addSecondaryWeaponItem "FST_PLX1_Rocket";
			removeBackpack player;
			// Check if player is using the Howler kit
			if ((player getVariable ["WBK_Kit_Name",""]) == "Howler") then {
				player addBackpack "FST_Backpack_Jumppack_PLX";
			} else {
				player addBackpack "FST_Clone_Backpack_PLX";
			};
			for "_i" from 1 to 2 do {
				player addItemToBackpack "FST_PLX1_Rocket";
				player addItemToBackpack "FST_PLX1_AA_mag";
			};
		};
		case (_item isKindOf ["LauncherCore", configFile >> "CfgWeapons"]): {
			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_launcher_1.ogg","41st_KitMenu\sounds\select_launcher_2.ogg"], 0.85, 1];
			_weaponStuff = secondaryWeaponItems player;
			_mags = [secondaryWeapon player] call CBA_fnc_compatibleMagazines;
			_availableMagCount = {_x in _mags} count magazines player;
			{player removeMagazines _x;} forEach _mags;
			player removeWeapon secondaryWeapon player;
			_weap = [player, _item, _availableMagCount + 1] call BIS_fnc_addWeapon;
			{player addSecondaryWeaponItem _x;} forEach _weaponStuff;
		};
		case (_item == "FST_DC17"): {
			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_pistol_1.ogg", "41st_KitMenu\sounds\select_pistol_2.ogg"], 0.85, 1];
			private _magClass = "FST_blaster_cell_low_Blue";
			private _knife = "UNSC_Knife";
			if (_knife in weapons player) then {
				player removeWeapon _knife;
			};
			if ("FST_DC17" in weapons player) then {
				player removeWeapon "FST_DC17";
				player removeMagazines _magClass;
			} else {
				player removeMagazines _magClass;
				player addWeapon "FST_DC17";
				player addHandgunItem _magClass;
				for "_i" from 1 to 6 do {
					player addMagazine _magClass;
				};
			};
		};
		case (_item == "FST_TwinDC17_Secondary"): {
			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_pistol_1.ogg", "41st_KitMenu\sounds\select_pistol_2.ogg"], 0.85, 1];
			private _magClass = "FST_blaster_cell_low_Blue";
			private _knife = "UNSC_Knife";

			if (_knife in weapons player) then {
				player removeWeapon _knife;
			};
			if ("FST_TwinDC17_Secondary" in weapons player) then {
				player removeWeapon "FST_TwinDC17_Secondary";
				player removeMagazines _magClass;
			} else {
				player removeMagazines _magClass;
				player addWeapon "FST_TwinDC17_Secondary";
				player addHandgunItem _magClass;
				for "_i" from 1 to 6 do {
					player addMagazine _magClass;
				};
			};
		};
		case (_item == "UNSC_Knife"): {
			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_pistol_1.ogg", "41st_KitMenu\sounds\select_pistol_2.ogg"], 0.85, 1];
			private _pistol = "FST_DC17";
			private _magClass = "FST_blaster_cell_low_Blue";
			private _hasKnife = _pistol in weapons player;

			if (_hasKnife) then {
				player removeWeapon _pistol;
				player removeMagazines _magClass;
			};

			if ("UNSC_Knife" in weapons player) then {
				player removeWeapon "UNSC_Knife";
			} else {
				player addWeapon "UNSC_Knife";
			};
		};
		case (_item isKindOf ["RifleCore", configFile >> "CfgWeapons"]): {
			playSoundUI [selectRandom [
				"41st_KitMenu\sounds\select_weapon_1.ogg",
				"41st_KitMenu\sounds\select_weapon_2.ogg"
			], 0.85, 1];
			{
				player removeMagazines _x;
			} forEach [
				"FST_Smoke_LauncherGrenade",
				"FST_HE_LauncherGrenade",
				"ACE_HuntIR_M203",
				"ACE_40mm_Flare_white",
				"FST_SmokeBlue_LauncherGrenade",
				"FST_SmokeGreen_LauncherGrenade",
				"FST_SmokeRed_LauncherGrenade"
			];
			// === Save current backpack and its contents ===
			private _backpackClass = backpack player;
			private _backpackItems = backpackItems player;
			private _backpackInventory = [];
			{
				private _item = _x;
				private _existing = _backpackInventory findIf {(_x select 0) == _item};
				if (_existing == -1) then {
					_backpackInventory pushBack [_item, 1];
				} else {
					(_backpackInventory select _existing) set [1, (_backpackInventory select _existing select 1) + 1];
				};
			} forEach _backpackItems;

			// === Remove current weapon and mags ===
			private _weaponStuff = primaryWeaponItems player;
			private _mags = [primaryWeapon player] call CBA_fnc_compatibleMagazines;
			{player removeMagazines _x;} forEach _mags;
			player removeWeapon primaryWeapon player;

			// === Add new weapon ===
			player addWeapon _item;
			player selectWeapon _item;
			{player addPrimaryWeaponItem _x;} forEach _weaponStuff;

			// === Magazine & backpack logic ===
			private _newMags = [_item] call CBA_fnc_compatibleMagazines;
			private _magType = if (count _newMags > 0) then {_newMags select 0} else {""};

			switch (_item) do {
				case "FST_DC15S": {
					// Backpack refresh for standard ammo backpacks
					private _curBP = backpack player;
					if (_curBP in ["FST_Backpack_Jumppack_STD_Ammo", "FST_Clone_Backpack_Invisible_STD"]) then {
						removeBackpack player;
						player addBackpack _curBP;
						for "_i" from 1 to 12 do { player addItemToBackpack "FST_blaster_cell_High_Blue"; };
						for "_i" from 1 to 18 do { player addItemToBackpack "FST_blaster_cell_Blue"; };
						for "_i" from 1 to 4 do {
							player addItemToBackpack "FST_blaster_cell_LE_Blue";
							player addItemToBackpack "FST_blaster_scatter_cell_DP23_Blue";
						};
						private _grenadeClass = "FST_grenade_Detonator_mag";
						private _grenadesCurrent = { _x == _grenadeClass } count magazines player;
						if (_grenadesCurrent < 6) then {
							for "_i" from 1 to (6 - _grenadesCurrent) do {
								if (player canAddItemToVest _grenadeClass) then {
									player addItemToVest _grenadeClass;
								} else {
									player addItemToUniform _grenadeClass;
								};
							};
						};
					};

					private _magCount = if ((player getVariable ["WBK_Kit_Name", ""]) == "Close Quarters Combatant") then {15} else {17};
					for "_i" from 1 to _magCount do {
						if (player canAddItemToVest _magType) then {
							player addItemToVest _magType;
						} else {
							if (player canAddItemToBackpack _magType) then {
								player addItemToBackpack _magType;
							} else {
								player addItemToUniform _magType;
							};
						};
					};
					player addPrimaryWeaponItem "FST_Attachment_Optic_Holo_DC15";
				};

				case "FST_DC15A";
				case "FST_DC15C_F": {
					// Backpack refresh for standard ammo backpacks
					private _curBP = backpack player;
					if (_curBP in ["FST_Backpack_Jumppack_STD_Ammo", "FST_Clone_Backpack_Invisible_STD"]) then {
						removeBackpack player;
						player addBackpack _curBP;
						for "_i" from 1 to 12 do { player addItemToBackpack "FST_blaster_cell_High_Blue"; };
						for "_i" from 1 to 18 do { player addItemToBackpack "FST_blaster_cell_Blue"; };
						for "_i" from 1 to 4 do {
							player addItemToBackpack "FST_blaster_cell_LE_Blue";
							player addItemToBackpack "FST_blaster_scatter_cell_DP23_Blue";
						};
						private _grenadeClass = "FST_grenade_Detonator_mag";
						private _grenadesCurrent = { _x == _grenadeClass } count magazines player;
						if (_grenadesCurrent < 6) then {
							for "_i" from 1 to (6 - _grenadesCurrent) do {
								if (player canAddItemToVest _grenadeClass) then {
									player addItemToVest _grenadeClass;
								} else {
									player addItemToUniform _grenadeClass;
								};
							};
						};
					};

					for "_i" from 1 to 13 do {
						if (player canAddItemToVest _magType) then {
							player addItemToVest _magType;
						} else {
							player addItemToUniform _magType;
						};
					};
					player addPrimaryWeaponItem "FST_Attachment_Optic_Holo_DC15";
				};
				case "FST_DC15L_F": {
					removeBackpack player;
					player addBackpack "FST_Belt_Bag_15L";
					player addItemToBackpack "ACE_Tripod";
					private _magType = "FST_blaster_battery_DC15L_Blue";
					for "_i" from 1 to 15 do {
						if (player canAddItemToBackpack _magType) then {
							player addItemToBackpack _magType;
						} else {
							player addItemToVest _magType;
						};
					};
					player addPrimaryWeaponItem "FST_Optic_DC15L";
				};
				case "FST_Z6": {
					// If Howler, give jumppack backpack. Else, regular.
					if ((player getVariable ["WBK_Kit_Name",""]) == "Howler") then {
						removeBackpack player;
						player addBackpack "FST_Backpack_Jumppack_Z6";
					} else {
						removeBackpack player;
						player addBackpack "FST_Belt_Bag_Z6";
					};
					player addItemToBackpack "ACE_Tripod";
					private _magType = "FST_blaster_battery_Blue";
					for "_i" from 1 to 7 do {
						if (player canAddItemToBackpack _magType) then {
							player addItemToBackpack _magType;
						} else {
							player addItemToVest _magType;
						};
					};
				};
				case "FST_DP23": {
					private _slugMag = "FST_thermal_slug_mag_Blue";
					private _scatterCell = "FST_blaster_scatter_cell_DP23_Blue";

					if ((player getVariable ["WBK_Kit_Name", ""]) == "Close Quarters Combatant") then {
						{
							private _mag = _x select 0;
							private _count = _x select 1;
							for "_i" from 1 to _count do {
								if (player canAddItemToVest _mag) then {
									player addItemToVest _mag;
								} else {
									if (player canAddItemToBackpack _mag) then {
										player addItemToBackpack _mag;
									} else {
										player addItemToUniform _mag;
									};
								};
							};
						} forEach [
							[_scatterCell, 17],
							[_slugMag, 4]
						];
					} else {
						{
							private _mag = _x select 0;
							private _count = _x select 1;
							for "_i" from 1 to _count do {
								if (player canAddItemToVest _mag) then {
									player addItemToVest _mag;
								} else {
									if (player canAddItemToBackpack _mag) then {
										player addItemToBackpack _mag;
									} else {
										player addItemToUniform _mag;
									};
								};
							};
						} forEach [
							[_scatterCell, 9],
							[_slugMag, 8]
						];
					};
				};
				case "FST_DC15A_ugl": {
					for "_i" from 1 to 13 do {
						if (player canAddItemToVest _magType) then {
							player addItemToVest _magType;
						} else {
							player addItemToUniform _magType;
						};
					};

					for "_i" from 1 to 6 do { player removeItemFromBackpack "FST_Smoke_LauncherGrenade"; };
					for "_i" from 1 to 12 do { player removeItemFromBackpack "FST_HE_LauncherGrenade"; };
					for "_i" from 1 to 2 do { player removeItemFromBackpack "ACE_HuntIR_M203"; };
					for "_i" from 1 to 4 do { player removeItemFromBackpack "ACE_40mm_Flare_white"; };

					for "_i" from 1 to 6 do {
						if (player canAddItemToBackpack "FST_Smoke_LauncherGrenade") then {
							player addItemToBackpack "FST_Smoke_LauncherGrenade";
						} else {
							if (player canAddItemToVest "FST_Smoke_LauncherGrenade") then {
								player addItemToVest "FST_Smoke_LauncherGrenade";
							} else {
								player addItemToUniform "FST_Smoke_LauncherGrenade";
							};
						};
					};

					for "_i" from 1 to 13 do {
						if (player canAddItemToBackpack "FST_HE_LauncherGrenade") then {
							player addItemToBackpack "FST_HE_LauncherGrenade";
						} else {
							if (player canAddItemToVest "FST_HE_LauncherGrenade") then {
								player addItemToVest "FST_HE_LauncherGrenade";
							} else {
								player addItemToUniform "FST_HE_LauncherGrenade";
							};
						};
					};

					for "_i" from 1 to 2 do {
						if (player canAddItemToBackpack "ACE_HuntIR_M203") then {
							player addItemToBackpack "ACE_HuntIR_M203";
						} else {
							if (player canAddItemToVest "ACE_HuntIR_M203") then {
								player addItemToVest "ACE_HuntIR_M203";
							} else {
								player addItemToUniform "ACE_HuntIR_M203";
							};
						};
					};

					for "_i" from 1 to 4 do {
						if (player canAddItemToBackpack "ACE_40mm_Flare_white") then {
							player addItemToBackpack "ACE_40mm_Flare_white";
						} else {
							if (player canAddItemToVest "ACE_40mm_Flare_white") then {
								player addItemToVest "ACE_40mm_Flare_white";
							} else {
								player addItemToUniform "ACE_40mm_Flare_white";
							};
						};
					};
					{
						private _smokeMag = _x;
						if (player canAddItemToBackpack _smokeMag) then {
							player addItemToBackpack _smokeMag;
						} else {
							if (player canAddItemToVest _smokeMag) then {
								player addItemToVest _smokeMag;
							} else {
								player addItemToUniform _smokeMag;
							};
						};
					} forEach [
						"FST_SmokeBlue_LauncherGrenade",
						"FST_SmokeGreen_LauncherGrenade",
						"FST_SmokeRed_LauncherGrenade"
					];
				};

				case "FST_DC15S_UGL": {
					for "_i" from 1 to 15 do {
						if (player canAddItemToVest _magType) then {
							player addItemToVest _magType;
						} else {
							player addItemToUniform _magType;
						};
					};

					for "_i" from 1 to 6 do { player removeItemFromBackpack "FST_Smoke_LauncherGrenade"; };
					for "_i" from 1 to 13 do { player removeItemFromBackpack "FST_HE_LauncherGrenade"; };
					for "_i" from 1 to 2 do { player removeItemFromBackpack "ACE_HuntIR_M203"; };
					for "_i" from 1 to 4 do { player removeItemFromBackpack "ACE_40mm_Flare_white"; };

					for "_i" from 1 to 6 do {
						if (player canAddItemToBackpack "FST_Smoke_LauncherGrenade") then {
							player addItemToBackpack "FST_Smoke_LauncherGrenade";
						} else {
							if (player canAddItemToVest "FST_Smoke_LauncherGrenade") then {
								player addItemToVest "FST_Smoke_LauncherGrenade";
							} else {
								player addItemToUniform "FST_Smoke_LauncherGrenade";
							};
						};
					};

					for "_i" from 1 to 12 do {
						if (player canAddItemToBackpack "FST_HE_LauncherGrenade") then {
							player addItemToBackpack "FST_HE_LauncherGrenade";
						} else {
							if (player canAddItemToVest "FST_HE_LauncherGrenade") then {
								player addItemToVest "FST_HE_LauncherGrenade";
							} else {
								player addItemToUniform "FST_HE_LauncherGrenade";
							};
						};
					};

					for "_i" from 1 to 2 do {
						if (player canAddItemToBackpack "ACE_HuntIR_M203") then {
							player addItemToBackpack "ACE_HuntIR_M203";
						} else {
							if (player canAddItemToVest "ACE_HuntIR_M203") then {
								player addItemToVest "ACE_HuntIR_M203";
							} else {
								player addItemToUniform "ACE_HuntIR_M203";
							};
						};
					};

					for "_i" from 1 to 4 do {
						if (player canAddItemToBackpack "ACE_40mm_Flare_white") then {
							player addItemToBackpack "ACE_40mm_Flare_white";
						} else {
							if (player canAddItemToVest "ACE_40mm_Flare_white") then {
								player addItemToVest "ACE_40mm_Flare_white";
							} else {
								player addItemToUniform "ACE_40mm_Flare_white";
							};
						};
					};
					{
						private _smokeMag = _x;
						if (player canAddItemToBackpack _smokeMag) then {
							player addItemToBackpack _smokeMag;
						} else {
							if (player canAddItemToVest _smokeMag) then {
								player addItemToVest _smokeMag;
							} else {
								player addItemToUniform _smokeMag;
							};
						};
					} forEach [
						"FST_SmokeBlue_LauncherGrenade",
						"FST_SmokeGreen_LauncherGrenade",
						"FST_SmokeRed_LauncherGrenade"
					];
				};
				case "FST_T15": {
					player addPrimaryWeaponItem "FST_Optic_MRCO_T15";
					player addPrimaryWeaponItem "3as_bipod_vk38x_f";
					removeBackpack player;
					player addBackpack "FST_Clone_Backpack_RifleAT";
					for "_i" from 1 to 8 do {
						if (player canAddItemToVest "FST_thermal_coil_LP_Blue") then {
							player addItemToVest "FST_thermal_coil_LP_Blue";
						} else {
							if (player canAddItemToBackpack "FST_thermal_coil_LP_Blue") then {
								player addItemToBackpack "FST_thermal_coil_LP_Blue";
							} else {
								player addItemToUniform "FST_thermal_coil_LP_Blue";
							};
						};
					};
					for "_i" from 1 to 7 do {
						if (player canAddItemToVest "FST_thermal_coil_T15_Blue") then {
							player addItemToVest "FST_thermal_coil_T15_Blue";
						} else {
							if (player canAddItemToBackpack "FST_thermal_coil_T15_Blue") then {
								player addItemToBackpack "FST_thermal_coil_T15_Blue";
							} else {
								player addItemToUniform "FST_thermal_coil_T15_Blue";
							};
						};
					};
				};
				case "FST_DC15LE": {
					for "_i" from 1 to 13 do {
						if (player canAddItemToVest "FST_blaster_cell_LE_Blue") then {
							player addItemToVest "FST_blaster_cell_LE_Blue";
						} else {
							if (player canAddItemToBackpack "FST_blaster_cell_LE_Blue") then {
								player addItemToBackpack "FST_blaster_cell_LE_Blue";
							} else {
								player addItemToUniform "FST_blaster_cell_LE_Blue";
							};
						};
					};
				};
				default {
					for "_i" from 1 to (_mags findIf {_x == _magType} + 1) do {
						if (player canAddItemToVest _magType) then {
							player addItemToVest _magType;
						} else {
							player addItemToUniform _magType;
						};
					};

					// Restore original backpack
					if (_backpackClass != "") then {
						removeBackpack player;
						player addBackpack _backpackClass;
						{
							for "_i" from 1 to (_x select 1) do {
								player addItemToBackpack (_x select 0);
							};
						} forEach _backpackInventory;
					};
				};
			};
		};

		case (_item isKindOf ["PistolCore", configFile >> "CfgWeapons"]): {
		    playSoundUI [selectRandom ["41st_KitMenu\sounds\select_pistol_1.ogg","41st_KitMenu\sounds\select_pistol_2.ogg"], 0.85, 1];
		    _weaponStuff = handgunItems player;
		    _mags = [handgunweapon player] call CBA_fnc_compatibleMagazines;
			_availableMagCount = {_x in _mags} count magazines player;
			{player removeMagazines _x;} forEach _mags;
			player removeWeapon handgunweapon player;
			_weap = [player, _item, _availableMagCount + 1] call BIS_fnc_addWeapon;
            player selectWeapon _weap;
			{player addHandgunItem _x;} forEach _weaponStuff;
		};
		case ( isClass (configFile >> "CfgGlasses" >> _item)): {
		    playSoundUI [selectRandom ["41st_KitMenu\sounds\select_generic_1.ogg","41st_KitMenu\sounds\select_generic_2.ogg","41st_KitMenu\sounds\select_generic_3.ogg","41st_KitMenu\sounds\select_generic_4.ogg","41st_KitMenu\sounds\select_generic_5.ogg","41st_KitMenu\sounds\select_generic_6.ogg"], 0.85, 1];
			removeGoggles player;
			player addGoggles _item;
		};
		default {
			playSoundUI [selectRandom ["41st_KitMenu\sounds\select_generic_1.ogg","41st_KitMenu\sounds\select_generic_2.ogg","41st_KitMenu\sounds\select_generic_3.ogg","41st_KitMenu\sounds\select_generic_4.ogg","41st_KitMenu\sounds\select_generic_5.ogg","41st_KitMenu\sounds\select_generic_6.ogg"], 0.85, 1];
			player addItem _item;
		};
   };
call WBK_UpdatePlayerKitOnMenu;
};


Wbk_AssignKit = {
params ["_control", "_index"];
private ["_lbData", "_itemClass", "_itemCount"];
_lbData = call compile (lbData [ctrlIDC _control, _index]);
_kit = _lbData select 0;
_typeOfKit = _lbData select 1;
if (_typeOfKit == "CANTTAKEKIT") exitWith {
	playSoundUI ["41st_KitMenu\sounds\select_cantTake.ogg", 0.35, 1];
};
_aditionalGear = _lbData select 2;
_codeExecute = _lbData select 3;
_insignia = [player] call BIS_fnc_getUnitInsignia;
playSoundUI ["41st_KitMenu\sounds\select_default.ogg", 0.3, 1];
player setUnitLoadout _kit;
private _uniformToSet = "";
private _headgearToSet = "";
private _name = name player;

switch (true) do {
    case (_name find "CR-" == 0): {
        _uniformToSet = "FST_Uniform_Recruit";
        _headgearToSet = "FST_P2_Helmet_Recruit";
    };
    case (_name find "CT-" == 0): {
        _uniformToSet = "FST_Trooper_Uniform";
    };
    case (_name find "SCT-" == 0): {
        _uniformToSet = "FST_Uniform_SCT";
    };
    case (_name find "VCT-" == 0): {
        _uniformToSet = "FST_Uniform_VCT";
    };
    case (_name find "CLC-" == 0): {
        _uniformToSet = "FST_Uniform_CLC";
    };
    case (_name find "CPL-" == 0): {
        _uniformToSet = "FST_Uniform_CPL";
    };
    case (_name find "CS-" == 0): {
        _uniformToSet = "FST_Uniform_CS";
    };
    case (_name find "CSS-" == 0): {
        _uniformToSet = "FST_Uniform_CSS";
    };
    case (_name find "CL-" == 0): {
        _uniformToSet = "FST_Uniform_CL";
    };
};

if (_uniformToSet != "" && (uniform player == "FST_Trooper_Uniform")) then {
    private _uniformItems = uniformItems player;
    removeUniform player;
    player forceAddUniform _uniformToSet;
    { player addItemToUniform _x; } forEach _uniformItems;
    if (_headgearToSet != "") then {
        removeHeadgear player;
        player addHeadgear _headgearToSet;
    };
};
player setVariable ["WBK_Kit_Name",_typeOfKit,true];
[player,_kit,_typeOfKit,_aditionalGear] spawn _codeExecute;
player setVariable ["BIS_fnc_setUnitInsignia_class", nil];
[player, _insignia] call BIS_fnc_setUnitInsignia;
player setUnitTrait ["Medic", false];
player setUnitTrait ["engineer", false];
player setUnitTrait ["explosiveSpecialist", false];
switch (_typeOfKit) do {
	case "Medic": {
		player setUnitTrait ["Medic", true];
	};
	case "Engineer": {
		player setUnitTrait ["engineer", true];
		player setUnitTrait ["explosiveSpecialist", true];
	};
	default {};
};
call WBK_UpdatePlayerKitOnMenu;
player remoteExecCall ['FST_KitMenuUpdateKits',0];
(player getVariable "WBK_ClassHud") ctrlSetStructuredText parseText format["<t size='1.5' align='center' font='PuristaSemibold'>%1</t>", player getVariable "WBK_Kit_Name"];
WBK_KitSystem_PlayerTookKit = true;
_display = findDisplay 2000;
_listBox_AditionalStuff = _display displayCtrl 1731;
_listBox_AditionalStuff lbSetColor [0, [0,1,0,1]];
lbClear 1731;
if (count _aditionalGear > 0) then {
	_weapons = [];
	_attachments = [];
	_equipment = [];
	_backpacks = [];
	_glasses = [];
	_magazinesAndItems = [];
	_patches = [];
	{
	if !(_x == "") then {
		switch true do {
			case ( isClass (configFile >> "CfgUnitInsignia" >> _x)): {
				_patches pushBack _x;
			};
			case ((getNumber(configFile >> "CfgWeapons" >> _x >> 'ItemInfo' >> 'type' ) isEqualTo 302 || getNumber(configFile >> "CfgWeapons" >> _x >> 'ItemInfo' >> 'type' ) isEqualTo 301 || getNumber(configFile >> "CfgWeapons" >> _x >> 'ItemInfo' >> 'type' ) isEqualTo 201 || getNumber(configFile >> "CfgWeapons" >> _x >> 'ItemInfo' >> 'type' ) isEqualTo 101)): {
				_attachments pushBack _x;
			};
			case ((getNumber(configFile >> "CfgWeapons" >> _x >> 'ItemInfo' >> 'type' ) isEqualTo 605) || (getNumber(configFile >> "CfgWeapons" >> _x >> 'ItemInfo' >> 'type' ) isEqualTo 801) || (getNumber(configFile >> "CfgWeapons" >> _x >> 'ItemInfo' >> 'type' ) isEqualTo 701)): {
				_equipment pushBack _x;
			};
			case ( isClass (configFile >> "CfgVehicles" >> _x)): {
				_backpacks pushBack _x;
			};
			case ( isClass (configFile >> "CfgMagazines" >> _x)): {
				_magazinesAndItems pushBack _x;
			};
			case ( isClass (configFile >> "CfgGlasses" >> _x)): {
				_glasses pushBack _x;
			};
			case ((_x isKindOf ["LauncherCore", configFile >> "CfgWeapons"]) || (_x isKindOf ["PistolCore", configFile >> "CfgWeapons"]) || (_x isKindOf ["RifleCore", configFile >> "CfgWeapons"])): {
				_weapons pushBack _x;
			};
			default {
				_magazinesAndItems pushBack _x;
			};
	   };
	};
	} forEach _aditionalGear;
// === Split weapons by type ===
_primaryWeapons = [];
_secondaryWeapons = [];
_launchers = [];

{
	if (_x isKindOf ["Rifle", configFile >> "CfgWeapons"]) then {
		_primaryWeapons pushBack _x;
	} else {
		if (_x isKindOf ["Pistol", configFile >> "CfgWeapons"]) then {
			_secondaryWeapons pushBack _x;
		} else {
			if (_x isKindOf ["Launcher", configFile >> "CfgWeapons"]) then {
				_launchers pushBack _x;
			};
		};
	};
}
forEach _weapons;
	// === Display categories ===
	if (count _primaryWeapons > 0) then {
		_pic = "a3\ui_f\data\GUI\Cfg\Hints\Rifle_ca.paa";
		_index = _listBox_AditionalStuff lbAdd " PRIMARY WEAPONS";
		_listBox_AditionalStuff lbSetPicture [_index, _pic];
		_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		_listBox_AditionalStuff lbSetData [_index, "['any']"];
		{
			_pic = getText (configFile >> "CfgWeapons" >> _x >> "picture");
			_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgWeapons" >> _x >> "displayname");
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		} forEach _primaryWeapons;
	};

	if (count _secondaryWeapons > 0) then {
		_pic = "a3\ui_f\data\GUI\Cfg\Hints\handgun_ca.paa";
		_index = _listBox_AditionalStuff lbAdd " SECONDARY WEAPONS";
		_listBox_AditionalStuff lbSetPicture [_index, _pic];
		_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		_listBox_AditionalStuff lbSetData [_index, "['any']"];
		{
			_pic = getText (configFile >> "CfgWeapons" >> _x >> "picture");
			_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgWeapons" >> _x >> "displayname");
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		} forEach _secondaryWeapons;
	};

	if (count _launchers > 0) then {
		_pic = "a3\ui_f\data\GUI\Cfg\Hints\launcher_ca.paa";
		_index = _listBox_AditionalStuff lbAdd " LAUNCHERS";
		_listBox_AditionalStuff lbSetPicture [_index, _pic];
		_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		_listBox_AditionalStuff lbSetData [_index, "['any']"];
		{
			_pic = getText (configFile >> "CfgWeapons" >> _x >> "picture");
			_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgWeapons" >> _x >> "displayname");
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		} forEach _launchers;
	};
	if (count _attachments > 0) then {
		_pic = "";
		_index = _listBox_AditionalStuff lbAdd " ";
		_listBox_AditionalStuff lbSetPicture [_index, _pic];
		_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
		
		_pic = "a3\ui_f\data\GUI\Cfg\Hints\Optics_ca.paa";
		_index = _listBox_AditionalStuff lbAdd " ATTACHMENTS";
		_listBox_AditionalStuff lbSetPicture [_index, _pic];
		_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
		{
			_pic = getText (configFile >> "CfgWeapons" >> _x >> "picture");
			_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgWeapons" >> _x >> "displayname");
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		} forEach _attachments;
	};
	if (count _equipment > 0) then {
		_pic = "";
		_index = _listBox_AditionalStuff lbAdd " ";
		_listBox_AditionalStuff lbSetPicture [_index, _pic];
		_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
		
		_pic = "a3\ui_f\data\GUI\Cfg\Hints\Stamina_CA.paa";
		_index = _listBox_AditionalStuff lbAdd " EQUIPMENT";
		_listBox_AditionalStuff lbSetPicture [_index, _pic];
		_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
		{
			_pic = getText (configFile >> "CfgWeapons" >> _x >> "picture");
			_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgWeapons" >> _x >> "displayname");
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		} forEach _equipment;
	};
	if (count _backpacks > 0) then {
		_pic = "";
		_index = _listBox_AditionalStuff lbAdd " ";
		_listBox_AditionalStuff lbSetPicture [_index, _pic];
		_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
		
		_pic = "a3\ui_f\data\GUI\Cfg\Hints\Gear_ca.paa";
		_index = _listBox_AditionalStuff lbAdd " BACKPACKS";
		_listBox_AditionalStuff lbSetPicture [_index, _pic];
		_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
		{
			_pic = getText (configFile >> "CfgVehicles" >> _x >> "picture");
			_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgVehicles" >> _x >> "displayname");
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		} forEach _backpacks;
	};
	if (count _glasses > 0) then {
		_pic = "";
		_index = _listBox_AditionalStuff lbAdd " ";
		_listBox_AditionalStuff lbSetPicture [_index, _pic];
		_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
		
		_pic = "a3\ui_f\data\GUI\Cfg\Hints\Pheripheal_vision_ca.paa";
		_index = _listBox_AditionalStuff lbAdd " FACEWEAR";
		_listBox_AditionalStuff lbSetPicture [_index, _pic];
		_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
		{
			_pic = getText (configFile >> "CfgGlasses" >> _x >> "picture");
			_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgGlasses" >> _x >> "displayname");
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		} forEach _glasses;
	};
	if (count _magazinesAndItems > 0) then {
		_pic = "";
		_index = _listBox_AditionalStuff lbAdd " ";
		_listBox_AditionalStuff lbSetPicture [_index, _pic];
		_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
		
		_pic = "a3\ui_f\data\GUI\Cfg\Hints\Reload_ca.paa";
		_index = _listBox_AditionalStuff lbAdd " MAGAZINES AND ITEMS";
		_listBox_AditionalStuff lbSetPicture [_index, _pic];
		_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
		{
			if ( isClass (configFile >> "CfgMagazines" >> _x)) then {
				_pic = getText (configFile >> "CfgMagazines" >> _x >> "picture");
				_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgMagazines" >> _x >> "displayname");
				_listBox_AditionalStuff lbSetPicture [_index, _pic];
				_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
				_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			}else{
				_pic = getText (configFile >> "CfgWeapons" >> _x >> "picture");
				_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgWeapons" >> _x >> "displayname");
				_listBox_AditionalStuff lbSetPicture [_index, _pic];
				_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
				_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
			};
		} forEach _magazinesAndItems;
	};
	if (count _patches > 0) then {
		_pic = "";
		_index = _listBox_AditionalStuff lbAdd " ";
		_listBox_AditionalStuff lbSetPicture [_index, _pic];
		_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
		
		_pic = "a3\ui_f\data\GUI\Cfg\Hints\UnitType_CA.paa";
		_index = _listBox_AditionalStuff lbAdd " PATCHES";
		_listBox_AditionalStuff lbSetPicture [_index, _pic];
		_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		_listBox_AditionalStuff lbSetData [_index, format ["['%1']", any]];
		{
			_pic = getText (configFile >> "CfgUnitInsignia" >> _x >> "texture");
			_index = _listBox_AditionalStuff lbAdd getText (configFile >> "CfgUnitInsignia" >> _x >> "displayname");
			_listBox_AditionalStuff lbSetPicture [_index, _pic];
			_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
			_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
		} forEach _patches;
	};
}else{
_pic = "";
_index = _listBox_AditionalStuff lbAdd "NONE";
_listBox_AditionalStuff lbSetPicture [_index, _pic];
_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _x]];
};
//backpacks start
// === ADD STATIC BACKPACKS IF KIT IS AMMO BEARER (Regular or Airborne) ===
if (_typeOfKit == "Ammo Bearer" || _typeOfKit == "Ammo Bearer ") then {
	private _backpacks = [];
	if (_typeOfKit == "Ammo Bearer ") then {
		// Airborne version (extra space at end)
		_backpacks = [
			["FST_Backpack_Jumppack_15L_Ammo", "10x DC15L Battery"],
			["FST_Backpack_Jumppack_STD_Ammo", "Standard Ammo + 3x Detonators"],
			["FST_Backpack_Jumppack_RifleAT_Ammo", "2x LP Coil + 4x T15 Coil"]
		];
	} else {
		// Regular version
		_backpacks = [
			["FST_Clone_Backpack_Invisible_15L", "10x DC15L Battery"],
			["FST_Clone_Backpack_Invisible_RPS", "3x RPS6 + 1x HE Rocket"],
			["FST_Clone_Backpack_Invisible_Z6", "7x Z6 Battery"],
			["FST_Clone_Backpack_Invisible_STD", "Standard Ammo + 3x Detonators"],
			["FST_Clone_Backpack_Invisible_RifleAT", "2x LP Coil + 4x T15 Coil"],
			["FST_Clone_Backpack_Invisible_PLX", "3x PLX Rockets"]
		];
	};

	private _listBox_AditionalStuff = (findDisplay 2000) displayCtrl 1731;

	// Spacer
	private _indexSpacer = _listBox_AditionalStuff lbAdd " ";
	_listBox_AditionalStuff lbSetData [_indexSpacer, "['any']"];

	// Header
	private _indexHeader = _listBox_AditionalStuff lbAdd " AMMO BACKPACKS";
	_listBox_AditionalStuff lbSetPicture [_indexHeader, "a3\ui_f\data\GUI\Cfg\Hints\Gear_ca.paa"];
	_listBox_AditionalStuff lbSetData [_indexHeader, "['any']"];

	// Add each backpack
	{
		private _class = _x select 0;
		private _desc = _x select 1;

		private _pic = getText (configFile >> "CfgVehicles" >> _class >> "picture");
		private _disp = getText (configFile >> "CfgVehicles" >> _class >> "displayName");

		private _text = switch (_class) do {
			case "FST_Clone_Backpack_Invisible_15L";
			case "FST_Backpack_Jumppack_15L_Ammo": { "DC15L Pack" };
			case "FST_Clone_Backpack_Invisible_RPS": { "RPS6 Pack" };
			case "FST_Clone_Backpack_Invisible_Z6": { "Z6 Pack" };
			case "FST_Clone_Backpack_Invisible_STD";
			case "FST_Backpack_Jumppack_STD_Ammo": { "Standard Ammo Pack" };
			case "FST_Clone_Backpack_Invisible_RifleAT";
			case "FST_Backpack_Jumppack_RifleAT_Ammo": { "Rifle AT Pack" };
			case "FST_Clone_Backpack_Invisible_PLX": { "PLX Pack" };
			default { _disp };
		};
		private _index = _listBox_AditionalStuff lbAdd _text;

		_listBox_AditionalStuff lbSetPicture [_index, _pic];
		_listBox_AditionalStuff lbSetData [_index, format ["['%1']", _class]];
		_listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
	} forEach _backpacks;
};

if (_typeOfKit == "Howler") then {
    private _backpacks = [
        ["FST_Backpack_Jumppack_Z6_Ammo", "7x Z6 Battery"],
        ["FST_Backpack_Jumppack_PLX_Ammo", "3x PLX Rockets"],
        ["FST_Backpack_Jumppack_RPS_Ammo", "3x RPS6 + 1x HE Rocket"]
    ];

    private _listBox_AditionalStuff = (findDisplay 2000) displayCtrl 1731;

    // Spacer
    private _indexSpacer = _listBox_AditionalStuff lbAdd " ";
    _listBox_AditionalStuff lbSetData [_indexSpacer, "['any']"];

    // Header
    private _indexHeader = _listBox_AditionalStuff lbAdd " AMMO BACKPACKS";
    _listBox_AditionalStuff lbSetPicture [_indexHeader, "a3\ui_f\data\GUI\Cfg\Hints\Gear_ca.paa"];
    _listBox_AditionalStuff lbSetData [_indexHeader, "['any']"];

    // Add each backpack
    {
        private _class = _x select 0;
        private _text = switch (_class) do {
            case "FST_Backpack_Jumppack_Z6_Ammo": { "Z6 Pack" };
            case "FST_Backpack_Jumppack_PLX_Ammo": { "PLX Pack" };
            case "FST_Backpack_Jumppack_RPS_Ammo": { "RPS6 Pack" };
            default { getText (configFile >> "CfgVehicles" >> _class >> "displayName") };
        };
        private _pic = getText (configFile >> "CfgVehicles" >> _class >> "picture");
        private _index = _listBox_AditionalStuff lbAdd _text;
        _listBox_AditionalStuff lbSetPicture [_index, _pic];
        _listBox_AditionalStuff lbSetData [_index, format ["['%1']", _class]];
        _listBox_AditionalStuff lbSetPictureColor [_index, [1, 1, 1, 1]];
    } forEach _backpacks;
};
//backpacks end
};

WBK_UpdatePlayerKitOnMenu = {
_display = findDisplay 2000;
_listBox = _display displayCtrl 1733;
_listBox lbSetColor [0, [0,1,0,1]];
lbClear 1733;
_pic = "";
_index = _listBox lbAdd "---------------WEAPONS---------------";
_listBox lbSetPicture [_index, _pic];
_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
{
	_weap = _x;
	if (!(_weap == "") and !(_weap == "Put") and !(_weap == "Throw") and !(_weap == binocular player)) then {
		_pic = getText (configFile >> "CfgWeapons" >> _weap >> "picture");
		_index = _listBox lbAdd getText (configFile >> "CfgWeapons" >> _weap >> "displayname");
		_listBox lbSetPicture [_index, _pic];
		_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
		{
			if !(_x == "") then {
				_pic1 = getText (configFile >> "CfgWeapons" >> _x >> "picture");
				_index1 = _listBox lbAdd getText (configFile >> "CfgWeapons" >> _x >> "displayname");
				_listBox lbSetPicture [_index1, _pic1];
				_listBox lbSetPictureColor [_index1, [1, 1, 1, 1]];
			};
		} forEach (player weaponAccessories _weap);
	};
} forEach weapons player;
_pic = "";
_index = _listBox lbAdd "---------------EQUIPMENT---------------";
_listBox lbSetPicture [_index, _pic];
_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
_itemsPlayer = [headgear player, goggles player, vest player, uniform player, backpack player];
{
if (!(_x == "")) then {
  switch true do {
    case (_x == backpack player): {
		_pic = getText (configFile >> "CfgVehicles" >> _x >> "picture");
		_index = _listBox lbAdd getText (configFile >> "CfgVehicles" >> _x >> "displayname");
		_listBox lbSetPicture [_index, _pic];
		_listBox lbSetData [_index, format ["['%1']", _x]];
		_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
	};
	case (_x == goggles player): {
		_pic = getText (configFile >> "CfgGlasses" >> _x >> "picture");
		_index = _listBox lbAdd getText (configFile >> "CfgGlasses" >> _x >> "displayname");
		_listBox lbSetPicture [_index, _pic];
		_listBox lbSetData [_index, format ["['%1']", _x]];
		_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
	};
	default {
		_pic = getText (configFile >> "CfgWeapons" >> _x >> "picture");
		_index = _listBox lbAdd getText (configFile >> "CfgWeapons" >> _x >> "displayname");
		_listBox lbSetPicture [_index, _pic];
		_listBox lbSetData [_index, format ["['%1']", _x]];
		_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
	};
  };
};
} forEach _itemsPlayer;
{
if (!(_x == "")) then {
if (_x isKindOf ["None", configFile >> "CfgGlasses"]) then {
_pic = getText (configFile >> "CfgGlasses" >> _x >> "picture");
_index = _listBox lbAdd getText (configFile >> "CfgGlasses" >> _x >> "displayname");
_listBox lbSetPicture [_index, _pic];
_listBox lbSetData [_index, format ["['%1']", _x]];
_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
}else{
_pic = getText (configFile >> "CfgWeapons" >> _x >> "picture");
_index = _listBox lbAdd getText (configFile >> "CfgWeapons" >> _x >> "displayname");
_listBox lbSetPicture [_index, _pic];
_listBox lbSetData [_index, format ["['%1']", _x]];
_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
};
};
} forEach assignedItems player;
_pic = "";
_index = _listBox lbAdd "---------------MAGAZINES AND ITEMS---------------";
_listBox lbSetPicture [_index, _pic];
_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
_currentMagArray = [];
_mags = magazines player;
{
if (!(_x == "") and !(_x in _currentMagArray)) then {
_crtMag = _x;
_currentMagArray pushBack _crtMag;
_count = { _x == _crtMag } count magazines player;
_pic = getText (configFile >> "CfgMagazines" >> _crtMag >> "picture");
_text = "X" +  str _count + " " + getText (configFile >> "CfgMagazines" >> _crtMag >> "displayname");
_index = _listBox lbAdd _text;
_listBox lbSetPicture [_index, _pic];
_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
};
} forEach _mags;
{
if (!(_x == "") and !(_x in _currentMagArray)) then {
_crtMag = _x;
_currentMagArray pushBack _crtMag;
_count = { _x == _crtMag } count items player;
if (_x isKindOf ["None", configFile >> "CfgGlasses"]) then {
_pic = getText (configFile >> "CfgGlasses" >> _x >> "picture");
_text = "X" +  str _count + " " + getText (configFile >> "CfgGlasses" >> _crtMag >> "displayname");
_index = _listBox lbAdd _text;
_listBox lbSetPicture [_index, _pic];
_listBox lbSetData [_index, format ["['%1']", _x]];
_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
}else{
_pic = getText (configFile >> "CfgWeapons" >> _x >> "picture");
_text = "X" +  str _count + " " + getText (configFile >> "CfgWeapons" >> _crtMag >> "displayname");
_index = _listBox lbAdd _text;
_listBox lbSetPicture [_index, _pic];
_listBox lbSetData [_index, format ["['%1']", _x]];
_listBox lbSetPictureColor [_index, [1, 1, 1, 1]];
};
};
} forEach items player;
};



Wbk_AddKit = {
    _obj = _this select 0;
    _nameOfKit = _this select 1;
    _fullKit = _this select 2;
    _text = _this select 3;
    _condition = _this select 4;
    _code = _this select 5;
    _category = if (count _this > 6) then {_this select 6} else {"regular"}; // Get category or default

    _kitToTransfer = [_nameOfKit, _fullKit, _text, _condition, _code, _category];

    // Global arrays for menu (initialize once)
    if (isNil "FST_AllKits") then { FST_AllKits = []; };
    if (isNil "FST_RegularKits") then { FST_RegularKits = []; };
    if (isNil "FST_AirborneKits") then { FST_AirborneKits = []; };
	if (isNil "FST_PilotKits") then { FST_PilotKits = []; };

    // Store globally for menu system
    FST_AllKits pushBack _kitToTransfer;
    switch (_category) do {
        case "airborne": { FST_AirborneKits pushBack _kitToTransfer; };
		case "pilot":    { FST_PilotKits    pushBack _kitToTransfer; };
        default        { FST_RegularKits  pushBack _kitToTransfer; };
    };

    // Store on object as before (for actual equipping)
    if (isNil {_obj getVariable "FST_ActualKits"}) exitWith {
        _obj setVariable ["FST_ActualKits", [_kitToTransfer]];
        _obj spawn Wbk_equip_load;
    };
    _array = _obj getVariable "FST_ActualKits";
    _array pushBack _kitToTransfer;
    _obj setVariable ["FST_ActualKits", _array];
};


[ missionNamespace, "arsenalOpened", { 
		disableSerialization; 
		_curatorDisplay = _this select 0; 
		([] call BIS_fnc_GUIGrid) params ["", "", "_GUI_GRID_W", "_GUI_GRID_H"]; 
		_GUI_GRID_W = _GUI_GRID_W / 40; 
		_GUI_GRID_H = _GUI_GRID_H / 25; 
		_btn = _curatorDisplay ctrlCreate ["RscButton", 2020]; 
		_btn ctrlSetPosition [ 
		 safezoneX + safezoneW - 32.5 * _GUI_GRID_W, 
		 safeZoneY + 42.6 * _GUI_GRID_H, 
		 7.99 * _GUI_GRID_W, 
		 1.3 * _GUI_GRID_H 
		]; 
		_btn ctrlSetText "EXPORT AS A KIT"; 
		_btn ctrlCommit 0; 
		_btn ctrlAddEventHandler ["ButtonClick",
		{
			_target = missionnamespace getvariable ["BIS_fnc_arsenal_center", player];
			copyToClipboard str getUnitLoadout _target;
			playSoundUI ["41st_KitMenu\sounds\select_default.ogg", 0.3, 1];
			playSoundUI ["Orange_Timeline_DateFadeIn", 0.3, 1];
			titleText ["<t size='2.4'>Data was copied to a clipboard.</t>", "PLAIN DOWN", -1, true, true];
		}];
} ] call BIS_fnc_addScriptedEventHandler;