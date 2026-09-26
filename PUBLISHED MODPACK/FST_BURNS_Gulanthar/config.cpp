
class CfgPatches {
    class FST_BURNS_Gulanthar {
        name="BURNS Gulanthar climbing gait";
        requiredVersion=2.18;
        requiredAddons[]={"FST_HCSpawn","JMSEF_animals_mod","dev_mutant_form939"};
        units[]={}; weapons[]={};
    };
};
class CfgMovesBasicMutant { class Actions; };
class CfgMovesForm939: CfgMovesBasicMutant {
    class States {
        class form939_walk;
        class form939_sprint;
        class BURNS_gulanthar_run: form939_sprint {
            speed=3;
            actions="BURNS_gulanthar_runActions";
            connectFrom[]={"form939_walk",0.1,"form939_sprint",0.1,"form939_idle",0.1,"form939_idle2",0.1,"form939_idle3",0.1};
        };
        class BURNS_gulanthar_climb: form939_walk {
            speed=2.2;
            actions="BURNS_gulanthar_climbActions";
            connectFrom[]={"form939_walk",0.1};
        };
    };
    class Actions: Actions {
        class form939_actions;
        class BURNS_gulanthar_runActions: form939_actions {
            WalkF="BURNS_gulanthar_run";
            SlowF="BURNS_gulanthar_run";
            TactF="BURNS_gulanthar_run";
            FastF="BURNS_gulanthar_run";
            EvasiveForward="BURNS_gulanthar_run";
            useFastMove=1;
        };
        class BURNS_gulanthar_climbActions: form939_actions {
            WalkF="BURNS_gulanthar_climb";
            SlowF="BURNS_gulanthar_climb";
            TactF="BURNS_gulanthar_climb";
        };
    };
};
