d_EndSplashScreen = {
    for "_x" from 1 to 4 do {
        endLoadingScreen;
        sleep 3;
    };
};

[] spawn _EndSplashScreen;

CHVD_allowNoGrass = false; // Set 'false' if you want to disable "Low" option for terrain (default: true)
CHVD_maxView = 6000; // Set maximum view distance (default: 12000)
CHVD_maxObj = 6000; // Set maximimum object view distance (default: 12000)

[west, 5000, [
    ["3AS_Shield_C_prop", 20, "Shields"],
    ["3as_Shield_3_prop", 6, "Shields"],
    ["3AS_Shield_5_prop", 10, "Shields"],
	["FST_Barricade_SecurityBarrier", 20, "Barriers"],
    ["Land_lsb_fob_hBarrierwall_4", 30, "Barriers"],
    ["Land_lsb_fob_hBarrier_3", 20, "Barriers"],
    ["Land_DragonsTeeth_01_4x2_new_redwhite_F", 5, "Barriers"],
    ["Land_lsb_fob_hBarrier_ramp", 5, "Bridge"],
    ["FootBridge_0_ACR", 5, "Bridge"],
    ["land_optre_bootcamp_bridge", 5, "Bridge"],
    ["3AS_Prop_FOB_Modular_Wall_Door", 1, "FOB"],
    ["3AS_Prop_FOB_Modular_Bunker", 1, "FOB"],
    ["3AS_Prop_FOB_Modular_Wall_Bunker", 1, "FOB"],
    ["3AS_Prop_FOB_Modular_Wall_Corner_Inversed", 1, "FOB"],
    ["3AS_Prop_FOB_Modular_Wall_Corner", 1, "FOB"],
    ["3AS_Prop_FOB_Modular_Wall_Gate", 1, "FOB"],
    ["3AS_Prop_FOB_Modular_Wall_Ramp", 1, "FOB"],
    ["3AS_Prop_FOB_Modular_Wall_Straight", 1, "FOB"],
    ["3AS_Prop_FOB_Modular_Wall_Straight_Long", 1, "FOB"],
    ["3AS_Prop_FOB_Modular_Watchtower", 1, "FOB"],
    ["3AS_Prop_FOB_Modular_wall_Watchtower", 1, "FOB"]
]] call acex_fortify_fnc_registerObjects;

if(hasInterface) then 
{
  setMissionOptions createHashMapFromArray [["AIThinkOnlyLocal", true]];
};