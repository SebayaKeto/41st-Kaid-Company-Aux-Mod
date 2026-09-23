// Original narrow extension of the installed creature's movement classes.
// No Workshop models, animations or behavior scripts are redistributed here.
class CfgPatches {
    class FST_BURNS_Gulanthar {
        name="BURNS Gulanthar climbing gait";
        requiredVersion=2.18;
        requiredAddons[]={"FST_HCSpawn","JMSEF_animals_mod","dev_mutant_form939"};
        units[]={};weapons[]={};
    };
};
class CfgMovesBasicMutant;
class CfgMovesForm939: CfgMovesBasicMutant {
    class States {class form939_walk;};
    class Actions {class form939_actions;};
};
class CfgMovesBURNSGulanthar: CfgMovesForm939 {
    class States: States {
        class form939_walk;
        class BURNS_gulanthar_climb: form939_walk {
            speed=1.8;
            actions="BURNS_gulanthar_climbActions";
        };
    };
    class Actions: Actions {
        class form939_actions;
        class BURNS_gulanthar_climbActions: form939_actions {
            WalkF="BURNS_gulanthar_climb";
            SlowF="BURNS_gulanthar_climb";
            TactF="BURNS_gulanthar_climb";
        };
    };
};
class CfgVehicles {
    class dev_mutant_base;
    class JMSEF_animals_varren_o: dev_mutant_base {
        moves="CfgMovesBURNSGulanthar";
        movesFatigue="CfgMovesBURNSGulanthar";
    };
    class JMSEF_animals_var_bers_o: JMSEF_animals_varren_o {
        moves="CfgMovesBURNSGulanthar";
        movesFatigue="CfgMovesBURNSGulanthar";
    };
    class JMSEF_animals_var_alpha_o: JMSEF_animals_varren_o {
        moves="CfgMovesBURNSGulanthar";
        movesFatigue="CfgMovesBURNSGulanthar";
    };
};
