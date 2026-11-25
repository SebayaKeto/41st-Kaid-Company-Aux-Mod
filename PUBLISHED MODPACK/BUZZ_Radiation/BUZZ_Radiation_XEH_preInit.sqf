// BUZZ_Radiation CBA settings
#define CAT "BUZZ_Radiation"

BUZZ_Radiation_zones = [];

// List setting parser
BUZZ_Radiation_parseList = {
    params [["_value", "", [""]]];
    (_value splitString (", ;""'[]" + toString [9, 10, 13])) apply {toLower _x}
};

// 1. General
["BUZZ_Radiation_enabled", "CHECKBOX", ["Enable radiation", "Master switch for all radiation zones."], [CAT, "1. General"], true, 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_affectAI", "CHECKBOX", ["Affect AI", "When off, only players are affected. NPCs ignore radiation."], [CAT, "1. General"], false, 1] call CBA_fnc_addSetting;

// 2. ACE Symptoms
#define SYM [CAT, "2. ACE Symptoms (only used when enabled)"]
["BUZZ_Radiation_symptoms", "CHECKBOX", ["ACE symptoms", "Master switch for everything in this section. Off = radiation causes no pain or injuries, only death at 100%."], SYM, true, 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_painDose", "SLIDER", ["Pain from dose (%)", "Requires ACE symptoms. Pain starts at this dose and rises towards severe pain as the dose climbs. 100 = never."], SYM, [0, 100, 25, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_fractureDose", "SLIDER", ["Fractures from dose (%)", "Requires ACE symptoms. A random arm or leg fractures at this dose; more limbs may follow (see the next setting). 100 = never."], SYM, [0, 100, 50, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_fractureInterval", "SLIDER", ["Fractures: average seconds between", "Requires ACE symptoms. After the first fracture, roughly how often another limb fractures while above the threshold."], SYM, [10, 1800, 180, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_bleedDose", "SLIDER", ["Bleeding wounds from dose (%)", "Requires ACE symptoms. Above this dose bleeding wounds open, one straight away and then repeatedly (see the next setting). 100 = never."], SYM, [0, 100, 75, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_bleedInterval", "SLIDER", ["Bleeding: average seconds between wounds", "Requires ACE symptoms. After the first wound, roughly how often a new bleeding wound opens while above the threshold."], SYM, [10, 1800, 60, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_blackoutDose", "SLIDER", ["Blackouts from dose (%)", "Requires ACE symptoms. Above this dose the unit passes out for 8-20 seconds now and then (see the next setting). 100 = never."], SYM, [0, 100, 75, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_blackoutInterval", "SLIDER", ["Blackouts: average seconds between", "Requires ACE symptoms. Roughly how often the unit passes out while above the threshold."], SYM, [10, 1800, 90, 0], 1] call CBA_fnc_addSetting;

// 3. Lethality
["BUZZ_Radiation_ttdBackground", "SLIDER", ["Background: minutes to death", "Time an unprotected player survives in Background radiation."], [CAT, "3. Lethality"], [1, 240, 30, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_ttdDangerous", "SLIDER", ["Dangerous: minutes to death", "Time to death in a Dangerous zone without treatment."], [CAT, "3. Lethality"], [1, 120, 15, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_ttdLethal", "SLIDER", ["Lethal: minutes to death", "Time to death in a Lethal zone without treatment."], [CAT, "3. Lethality"], [0.5, 30, 3, 1], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_sickThreshold", "SLIDER", ["Poisoning threshold (% dose)", "Above this dose, poisoning keeps getting worse after leaving a zone until treated. Below it, the body recovers by itself."], [CAT, "3. Lethality"], [0, 100, 10, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_progressOutside", "SLIDER", ["Untreated progression after leaving", "How fast untreated poisoning keeps worsening after you leave, compared with the zone that caused it."], [CAT, "3. Lethality"], [0, 1, 0.5, 0, true], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_recoveryMinutes", "SLIDER", ["Natural recovery (minutes)", "Minutes for the body to clear a dose below the poisoning threshold."], [CAT, "3. Lethality"], [1, 240, 20, 0], 1] call CBA_fnc_addSetting;

// 4. Protection
["BUZZ_Radiation_gearHelmets", "EDITBOX", ["Protective helmets", "Helmet classnames, separated by commas."], [CAT, "4. Protection"], "FST_BARC_Helmet_Evox_Dirty, FST_BARC_Helmet_Evox, FST_P2_ARC_Helmet_Burns, FST_P2_ARC_Helmet_Dilham, FST_P2_ARC_Helmet_Dilham_Dirty, FST_P2_ARC_Helmet_Squatch, FST_P2_ARC_Helmet_Squatch_Dirty, FST_Crewman_Helmet_Mk2, FST_Crewman_Helmet_Mk2_Ace, FST_Crewman_Helmet_Mk2_Ace_Dirty, FST_Crewman_Helmet_Mk2_Nerd, FST_Crewman_Helmet_Mk2_Claw, FST_Crewman_Helmet_Mk2_Changeling, FST_Crewman_Helmet_Mk2_Seraph, FST_Crewman_Helmet_Mk2_Debt, FST_Crewman_Helmet_Mk2_Magma, FST_Crewman_Helmet_Mk2_Omen, FST_Crewman_Helmet_Mk2_Bogu, FST_Crewman_Helmet_Mk2_Flatline, FST_Crewman_Helmet_Mk2_Overwatch, FST_Crewman_Helmet_Mk2_Kare, FST_Pilot_P1_Helmet, FST_Pilot_P1_Helmet_Qball, FST_Pilot_P1_Helmet_Grim, FST_Pilot_P1_Helmet_Sierra, FST_Pilot_P1_Helmet_Monk, FST_Pilot_P1_Helmet_Sepie, FST_Pilot_P1_Helmet_Kwike, FST_Pilot_P1_Helmet_Corpse, FST_Pilot_P1_Helmet_Cait, FST_Pilot_P1_Helmet_Aether, FST_Pilot_P1_Helmet_Talisman, FST_Pilot_P1_Helmet_Pole, FST_Pilot_P1_Helmet_Heller, FST_Pilot_P1_Helmet_Raz, FST_Pilot_P1_Helmet_Cursed, FST_Pilot_P1_Helmet_Oak, FST_Environmental_Helmet, FST_Environmental_Helmet_NCO, FST_Environmental_Helmet_Woodland, FST_BC_Helmet_Merrik, FST_P2_Helmet_Merrik_V2, FST_P2_Helmet_Merrik", 1, {BUZZ_Radiation_helmetList = [_this] call BUZZ_Radiation_parseList}] call CBA_fnc_addSetting;
["BUZZ_Radiation_gearVests", "EDITBOX", ["Protective armour", "Armour (vest) classnames, separated by commas."], [CAT, "4. Protection"], "", 1, {BUZZ_Radiation_vestList = [_this] call BUZZ_Radiation_parseList}] call CBA_fnc_addSetting;
["BUZZ_Radiation_partialGear", "SLIDER", ["Background with only helmet OR armour", "Exposure rate in Background when wearing only one piece. 50% means they survive twice as long. Helmet AND armour together give full immunity."], [CAT, "4. Protection"], [0, 1, 0.5, 0, true], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_gearProtectDangerous", "SLIDER", ["Full gear protection in Dangerous", "Exposure reduction in Dangerous zones for helmet + armour."], [CAT, "4. Protection"], [0, 1, 0, 0, true], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_gearProtectLethal", "SLIDER", ["Full gear protection in Lethal", "Exposure reduction in Lethal zones for helmet + armour."], [CAT, "4. Protection"], [0, 1, 0, 0, true], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_vehicleProtection", "SLIDER", ["Vehicle protection", "Exposure reduction for anyone in any vehicle seat or riding on top of one. 100% = no radiation is gained. Sickness you already have still progresses unless the option below is on."], [CAT, "4. Protection"], [0, 1, 1, 0, true], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_vehiclePausesSickness", "CHECKBOX", ["Vehicles pause existing sickness", "When on, being in or on a vehicle also stops sickness you already have from getting worse."], [CAT, "4. Protection"], false, 1] call CBA_fnc_addSetting;

// 5. Treatment
["BUZZ_Radiation_iodineDuration", "SLIDER", ["Iodine: effect duration (minutes)", "How long one iodine tablet works."], [CAT, "5. Treatment"], [0.5, 60, 5, 1], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_iodineClearMinutes", "SLIDER", ["Iodine: minutes to clear a full dose", "While iodine works and you are out of radiation, dose falls at this rate (100% dose in this many minutes)."], [CAT, "5. Treatment"], [1, 120, 10, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_iodineZoneReduction", "SLIDER", ["Iodine: exposure reduction inside zones", "While iodine works, exposure inside a zone is reduced by this much."], [CAT, "5. Treatment"], [0, 1, 0.5, 0, true], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_deconMinutes", "SLIDER", ["Decontamination: minutes to clear a full dose", "Rate at which a Decontamination Zone clears dose."], [CAT, "5. Treatment"], [0.5, 60, 2, 1], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_tentRate", "SLIDER", ["Decon tent: % dose cleared per second", "Standing inside a decontamination tent shields you and clears this much dose every second. 0 = tents do nothing."], [CAT, "5. Treatment"], [0, 10, 1, 1], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_tentClasses", "EDITBOX", ["Decon tent classes", "Exact object classnames that act as decontamination tents, separated by commas. Other tent colours and variants are not affected."], [CAT, "5. Treatment"], "Land_DeconTent_01_yellow_F", 1, {BUZZ_Radiation_tentList = [_this] call BUZZ_Radiation_parseList}] call CBA_fnc_addSetting;
["BUZZ_Radiation_flushTime", "SLIDER", ["Flush IV: time to apply (s)", "How long it takes to give a Radiation Flush IV."], [CAT, "5. Treatment"], [1, 60, 5, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_flushFastAmount", "SLIDER", ["Flush IV: rapid clear amount (% dose)", "Dose removed in the rapid phase right after the flush is given."], [CAT, "5. Treatment"], [0, 100, 35, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_flushFastSeconds", "SLIDER", ["Flush IV: rapid clear time (s)", "The rapid phase removes its amount evenly over this many seconds."], [CAT, "5. Treatment"], [1, 300, 10, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_flushSlowAmount", "SLIDER", ["Flush IV: slow clear amount (% dose)", "Extra dose removed slowly, running alongside the rapid phase."], [CAT, "5. Treatment"], [0, 100, 20, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_flushSlowMinutes", "SLIDER", ["Flush IV: slow clear time (minutes)", "The slow phase removes its amount evenly over this many minutes."], [CAT, "5. Treatment"], [0.5, 60, 5, 1], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_flushFatalEffect", "SLIDER", ["Flush IV: effect on Fatal patients", "A patient at Fatal (see 7. ACE Medical Menu) gets only this much of the normal flush. 50% = half the amount cleared."], [CAT, "5. Treatment"], [0, 1, 0.5, 0, true], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_flushPain", "SLIDER", ["Flush IV: pain caused", "Pain added to the patient when the flush is given (ACE pain, 0-1)."], [CAT, "5. Treatment"], [0, 1, 0.3, 2], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_flushMedic", "LIST", ["Flush IV: who can give it", "Medical training needed to give a Radiation Flush IV."], [CAT, "5. Treatment"], [[0, 1, 2], ["Anyone", "Medics", "Doctors"], 1], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_flushLocation", "LIST", ["Flush IV: where it can be given", "Restrict the flush to medical vehicles and/or medical facilities."], [CAT, "5. Treatment"], [[0, 1, 2, 3], ["Anywhere", "Medical vehicles", "Medical facilities", "Medical vehicles and facilities"], 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_flushSelf", "LIST", ["Flush IV: self-treatment", "Whether someone can give the flush to themselves."], [CAT, "5. Treatment"], [[0, 1, 2], ["No", "Yes", "Doctors only"], 1], 1] call CBA_fnc_addSetting;

// 6. Detection
["BUZZ_Radiation_monitorItems", "EDITBOX", ["Detection device items", "Items that power the side-panel Radiation Monitor and the ACE 'Scan For Radiation' action. Leave empty to give everyone a monitor."], [CAT, "6. Detection"], "BUZZ_Radiation_Monitor", 1, {BUZZ_Radiation_monitorList = [_this] call BUZZ_Radiation_parseList}] call CBA_fnc_addSetting;
["BUZZ_Radiation_monitorClicks", "CHECKBOX", ["Detector clicks", "While a player has the Radiation Monitor panel open inside a zone, it clicks like a Geiger counter. Everyone nearby hears it."], [CAT, "6. Detection"], true, 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_monitorClickVolume", "SLIDER", ["Detector click volume (wearer)", "How loud the clicks are for the player holding the monitor. Nearby players hear a 3D copy."], [CAT, "6. Detection"], [0, 5, 1, 1], 0] call CBA_fnc_addSetting;
["BUZZ_Radiation_monitorClickRange", "SLIDER", ["Detector click range (m)", "How far away other players can hear the detector clicks."], [CAT, "6. Detection"], [1, 50, 10, 0], 1] call CBA_fnc_addSetting;

// 7. ACE Medical Menu
#define MED [CAT, "7. ACE Medical Menu"]
["BUZZ_Radiation_medicalMenu", "CHECKBOX", ["Show Radiation Sickness", "Adds a 'Radiation Sickness' line to the ACE medical menu overview. Only players carrying a detection device see it."], MED, true, 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_menuMinor", "SLIDER", ["Minor from (% dose)", "Dose above which the menu shows 'Radiation Sickness: Minor'."], MED, [0, 100, 3, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_menuModerate", "SLIDER", ["Moderate from (% dose)", "Dose above which the menu shows 'Radiation Sickness: Moderate'."], MED, [0, 100, 25, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_menuSevere", "SLIDER", ["Severe from (% dose)", "Dose above which the menu shows 'Radiation Sickness: Severe'."], MED, [0, 100, 66, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_menuFatal", "SLIDER", ["Fatal from (% dose)", "Dose above which the menu shows 'Radiation Sickness: Fatal'."], MED, [0, 100, 90, 0], 1] call CBA_fnc_addSetting;

// 8. Coughing
["BUZZ_Radiation_cough", "CHECKBOX", ["Coughing", "Players with radiation sickness cough now and then. Everyone nearby hears it."], [CAT, "8. Coughing"], true, 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_coughDose", "SLIDER", ["Cough from (% dose)", "Coughing starts above this dose."], [CAT, "8. Coughing"], [0, 100, 10, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_coughInterval", "SLIDER", ["Average seconds between coughs", "How often someone coughs just above the threshold. It gets up to 4x more frequent as the dose nears 100%."], [CAT, "8. Coughing"], [10, 600, 60, 0], 1] call CBA_fnc_addSetting;
["BUZZ_Radiation_coughVolume", "SLIDER", ["Cough volume (cougher)", "How loud the cough is for the player coughing. Nearby players hear a 3D copy."], [CAT, "8. Coughing"], [0, 5, 1, 1], 0] call CBA_fnc_addSetting;
["BUZZ_Radiation_coughRange", "SLIDER", ["Cough range (m)", "How far away other players can hear a cough."], [CAT, "8. Coughing"], [1, 100, 20, 0], 1] call CBA_fnc_addSetting;
