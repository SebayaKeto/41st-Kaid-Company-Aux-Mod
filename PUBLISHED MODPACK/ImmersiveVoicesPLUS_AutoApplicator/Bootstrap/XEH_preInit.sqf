if (!(is3DEN)) then {
    systemChat "Applying Immersive Voices!";
    diag_log "Applying Immersive Voices!";
} else {
    diag_log "Applying Immersive Voices! (in 3DEN)";
};

//ensure radio is enabled!
enableRadio true;

// Configuration - Set to true to enable debug logging
PHEN_IVP_DEBUG_MODE = true;

PHEN_fnc_IVP_AutoAssign = {
        params ["_unit"];

        // Skip players and units that already have custom voices
        if (isPlayer _unit) exitWith {};
        if (gettext((configOf _unit) >> 'moves') != 'CfgmovesMaleSdr') exitWith {};
        if !((vehicle _unit) isKindOf "CAManBase") exitWith {};  
        
        // Get the faction they are a part of
        _faction = toLower getText ((configOf _unit) >> 'faction');
        // Get the_unitType of the unit
        _unitType = typeOf _unit;
        // Get the _editorSubcategory of the unit
        _editorSubcategory = toLower getText ((configOf _unit) >> 'editorSubcategory');
        // Get the display name of the unit
        _displayname = [configFile >> "CfgVehicles" >> _unitType] call BIS_fnc_displayName;

        private _bxDroidTypes = [
            "FST_BX", "FST_BX_Sniper"
        ];
        
        if (_unitType in _bxDroidTypes) exitWith {
            if (PHEN_IVP_DEBUG_MODE) then {
                systemChat format ["[IVP DEBUG] BX Droid detected - Setting voice: SWCMDdroidENG for %1 (%2)", _unit, _unitType];
            };
            [_unit, "SWCMDdroidENG"] remoteExec ['setSpeaker', 0];
        };
        
        // Voice assignment by faction and editor subcategory
        private _voiceAssigned = false;
        private _assignedVoice = "";
        
		switch (true) do {

			// Star Wars - CIS Battle Droids (faction or subcategory)
			case (
				(
					_faction in ["3as_cis", "ls_cis", "jlts_cis", "cis_fac", "sda", "fst_battledroids_faction"]
					||
					_editorSubcategory in [
						"o_dba_cis_b1_droids", "o_dba_cis_b1_droids_geonosis", "o_dba_cis_b1_droids_jungle",
						"o_dba_cis_b1_droids_winter", "o_dba_cis_b1_droids_training", "b_droids",
						"b_droids_geo", "jlts_droids_geonosis", "jlts_droids_training", "jlts_droids_normal",
						"ls_cis_standarddroids", "ls_cis_trainingdroids", "ls_cis_geonosisdroids",
						"442_battledroid_inf", "442_battledroid_inf_woodland", "442_battledroid_inf_desert",
						"442_battledroid_inf_winter", "442_battledroid_inf_geonosis", "fst_battledroids_subfaction"
					]
				)
				&&
				!(["B2", _displayname, false] call BIS_fnc_inString)
				&&
				((toLower _unitType) find "wbk_" == -1)
			): {
				_assignedVoice = "SWdroidENG";
				_voiceAssigned = true;
			};

			default {
				if (PHEN_IVP_DEBUG_MODE) then {
					systemChat format ["[IVP DEBUG] No voice match for %1 (Faction: %2, Subcategory: %3)", _unit, _faction, _editorSubcategory];
				};
			};
		};
        
        if (_voiceAssigned && _assignedVoice != "") then {
            if (PHEN_IVP_DEBUG_MODE) then {
                hint format ["[IVP DEBUG] <br/> Assigning voice %1 to %2 <br/> [type: %3, Faction: %4, Subcategory: %5]", 
                    _assignedVoice, _unit, _unitType, _faction, _editorSubcategory];
            };
            [_unit, _assignedVoice] remoteExec ['setSpeaker', 0]; //Set their new Voice
            [_unit, "RADIOPROTOCOL"] remoteExec ['enableAI ', 0]; //Ensure we can use the radio protocol to make 'em talk.
        };
};