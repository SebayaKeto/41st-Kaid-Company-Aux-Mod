class CfgSounds {
    class BUZZ_Radiation_geiger_0 {
        name = "Geiger (background)";
        sound[] = {"\BUZZ_Radiation\sounds\BUZZ_Radiation_geiger_0.ogg", db+20, 1};
        titles[] = {};
    };
    class BUZZ_Radiation_geiger_1: BUZZ_Radiation_geiger_0 {
        name = "Geiger (dangerous)";
        sound[] = {"\BUZZ_Radiation\sounds\BUZZ_Radiation_geiger_1.ogg", db+20, 1};
    };
    class BUZZ_Radiation_geiger_2: BUZZ_Radiation_geiger_0 {
        name = "Geiger (lethal)";
        sound[] = {"\BUZZ_Radiation\sounds\BUZZ_Radiation_geiger_2.ogg", db+20, 1};
    };
    class BUZZ_Radiation_cough_0: BUZZ_Radiation_geiger_0 {
        name = "Radiation cough 1";
        sound[] = {"\BUZZ_Radiation\sounds\BUZZ_Radiation_cough_0.ogg", db+20, 1};
    };
    class BUZZ_Radiation_cough_1: BUZZ_Radiation_geiger_0 {
        name = "Radiation cough 2";
        sound[] = {"\BUZZ_Radiation\sounds\BUZZ_Radiation_cough_1.ogg", db+20, 1};
    };
    class BUZZ_Radiation_cough_2: BUZZ_Radiation_geiger_0 {
        name = "Radiation cough 3";
        sound[] = {"\BUZZ_Radiation\sounds\BUZZ_Radiation_cough_2.ogg", db+20, 1};
    };
};
