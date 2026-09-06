// postInit — registers Addon Options settings + starts the per-frame ticks

["UMBARA_Stream_NearDensity", "SLIDER", ["Umbara Density: Near", "Fraction of eligible props rendered within Near Cutoff distance of you. 1.0 = full density, 0 = none."], "Umbara Trees", [0, 1, 1, 2]] call CBA_fnc_addSetting;
["UMBARA_Stream_MidDensity", "SLIDER", ["Umbara Density: Mid", "Fraction of eligible props rendered between Near and Mid Cutoff distance. Fades linearly down to 0 by Far Cutoff."], "Umbara Trees", [0, 1, 0.5, 2]] call CBA_fnc_addSetting;
["UMBARA_Stream_NearCutoff", "SLIDER", ["Umbara Near Cutoff (m)", "Distance within which Near Density applies at full strength."], "Umbara Trees", [100, 3000, 1500, 0]] call CBA_fnc_addSetting;
["UMBARA_Stream_MidCutoff", "SLIDER", ["Umbara Mid Cutoff (m)", "Distance out to which Mid Density applies; beyond this it fades linearly to 0 at Far Cutoff."], "Umbara Trees", [200, 6000, 2500, 0]] call CBA_fnc_addSetting;
["UMBARA_Stream_FarCutoff", "SLIDER", ["Umbara Far Cutoff (m)", "Distance beyond which no Umbara props render at all. 6000m matches the engine's own maximum object draw distance."], "Umbara Trees", [500, 6000, 6000, 0]] call CBA_fnc_addSetting;

// Prop streaming tick — client-side only. Handle kept global for Debug
// Console isolation testing: [UMBARA_StreamPFH] call CBA_fnc_removePerFrameHandler;
if (!isDedicated) then {
	UMBARA_StreamPFH = [{call umbara_trees_fnc_streamTick;}, 0, []] call CBA_fnc_addPerFrameHandler;
};

// Native-tree hide re-broadcast — server-only. Same isolation-test pattern
// via UMBARA_HidePFH.
if (isServer) then {
	UMBARA_HidePFH = [{call umbara_trees_fnc_hideTick;}, 0, []] call CBA_fnc_addPerFrameHandler;
};
