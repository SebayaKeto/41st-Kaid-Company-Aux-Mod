if (!(hasInterface) or (isDedicated)) exitWith {};
[] spawn
{
	waitUntil { !isNull findDisplay 46 };
	if(isClass(configFile>>"cfgPatches">>"ace_main")) then {
		["ace_arsenal_displayOpened", {
			disableSerialization; 
			_curatorDisplay = _this select 0; 
			([] call BIS_fnc_GUIGrid) params ["", "", "_GUI_GRID_W", "_GUI_GRID_H"]; 
			_GUI_GRID_W = _GUI_GRID_W / 40; 
			_GUI_GRID_H = _GUI_GRID_H / 25; 
			_btn = _curatorDisplay ctrlCreate ["RscButton", 2020]; 
			_btn ctrlSetPosition [ 
			 safezoneX + safezoneW - 48.5 * _GUI_GRID_W, 
			 safeZoneY + 42.6 * _GUI_GRID_H, 
			 7.99 * _GUI_GRID_W, 
			 1.3 * _GUI_GRID_H 
			]; 
			_btn ctrlSetText "EXPORT AS A KIT"; 
			_btn ctrlCommit 0; 
			_btn ctrlAddEventHandler ["ButtonClick",
			{
				copyToClipboard str getUnitLoadout player;
				playSoundUI ["41st_KitMenu\sounds\select_default.ogg", 0.3, 1];
				playSoundUI ["Orange_Timeline_DateFadeIn", 0.3, 1];
				titleText ["<t size='2.4'>Data was copied to a clipboard.</t>", "PLAIN DOWN", -1, true, true];
			}];
		}] call CBA_fnc_addEventHandler; 
	};
};