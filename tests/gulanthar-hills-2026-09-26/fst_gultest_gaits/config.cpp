// TEST-ONLY addon (Aux Updater, 2026-09-26). Never ships. Experimental Gulanthar uphill gaits.
class CfgPatches {
    class fst_gultest_gaits {
        name="Gulanthar uphill gait experiment (test only)";
        requiredVersion=2.18;
        requiredAddons[]={"FST_BURNS_Gulanthar","dev_mutant_form939"};
        units[]={}; weapons[]={};
    };
};
class CfgMovesBasicMutant { class Actions; };
class CfgMovesForm939: CfgMovesBasicMutant {
    class States {
        class form939_sprint;
        // Copy of BURNS_gulanthar_run for flat segments; the live helper ignores this name.
        class FSTTEST_flat_run: form939_sprint {
            speed=3;
            actions="FSTTEST_flatRunActions";
            connectFrom[]={"form939_walk",0.1,"form939_sprint",0.1,"form939_idle",0.1,"form939_idle2",0.1,"form939_idle3",0.1,"FSTTEST_gallop_run",0.1,"FSTTEST_gallop_fast",0.1};
        };
        // Gallop (run1) classified as an ordinary run: the sprint slope limit does not apply.
        class FSTTEST_gallop_run: form939_sprint {
            speed=2.5;
            actions="FSTTEST_gallopRunActions";
            connectFrom[]={"form939_walk",0.1,"form939_sprint",0.1,"form939_idle",0.1,"form939_idle2",0.1,"form939_idle3",0.1,"BURNS_gulanthar_run",0.1,"BURNS_gulanthar_climb",0.1,"FSTTEST_gallop_fast",0.1,"FSTTEST_flat_run",0.1};
        };
        // Same gallop flagged as a fast move, to observe the engine's sprint slope limit.
        class FSTTEST_gallop_fast: form939_sprint {
            speed=2.5;
            actions="FSTTEST_gallopFastActions";
            connectFrom[]={"form939_walk",0.1,"form939_sprint",0.1,"form939_idle",0.1,"form939_idle2",0.1,"form939_idle3",0.1,"BURNS_gulanthar_run",0.1,"BURNS_gulanthar_climb",0.1,"FSTTEST_gallop_run",0.1,"FSTTEST_flat_run",0.1};
        };
    };
    class Actions: Actions {
        class form939_actions;
        class FSTTEST_flatRunActions: form939_actions {
            WalkF="FSTTEST_flat_run";
            SlowF="FSTTEST_flat_run";
            TactF="FSTTEST_flat_run";
            FastF="FSTTEST_flat_run";
            EvasiveForward="FSTTEST_flat_run";
            useFastMove=1;
        };
        class FSTTEST_gallopRunActions: form939_actions {
            WalkF="FSTTEST_gallop_run";
            SlowF="FSTTEST_gallop_run";
            TactF="FSTTEST_gallop_run";
            FastF="FSTTEST_gallop_run";
            EvasiveForward="FSTTEST_gallop_run";
            useFastMove=0;
        };
        class FSTTEST_gallopFastActions: form939_actions {
            WalkF="FSTTEST_gallop_fast";
            SlowF="FSTTEST_gallop_fast";
            TactF="FSTTEST_gallop_fast";
            FastF="FSTTEST_gallop_fast";
            EvasiveForward="FSTTEST_gallop_fast";
            useFastMove=1;
        };
    };
};
