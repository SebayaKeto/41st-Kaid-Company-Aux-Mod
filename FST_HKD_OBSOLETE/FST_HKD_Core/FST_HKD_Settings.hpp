class CfgSettings {
    class CBA {
        class FST_HKD {
            class DroppableObjects {
                displayName = "HKD Droppable Objects";
                description = "Comma-separated list of object classnames that can be dropped via the HKD Drop modules.";
                type = "editbox";
                value = "FST_HKD_Blocker_Blank,FST_HKD_Blocker_CIS,FST_HKD_Blocker_HKD";
                isGlobal = 1;
            };
            class DefaultDropObject {
                displayName = "Default Drop Object";
                description = "Default object selected in the drop module (must be in DroppableObjects list).";
                type = "editbox";
                value = "FST_HKD_Blocker_Blank";
                isGlobal = 1;
            };
            class DefaultDropAltitude {
                displayName = "Default Drop Altitude (meters)";
                description = "Default altitude for drops.";
                type = "number";
                value = 1000;
                isGlobal = 1;
            };
            class DefaultDropRadius {
                displayName = "Default Radius Drop Spread (meters)";
                description = "Default radius for radius-based drops.";
                type = "number";
                value = 100;
                isGlobal = 1;
            };
            class DefaultDropCount {
                displayName = "Default Object Count";
                description = "Default number of objects for radius drops.";
                type = "number";
                value = 10;
                isGlobal = 1;
            };
            class SpawnBatchSize {
                displayName = "Spawn Batch Size";
                description = "Number of objects spawned per batch when executing radius drops. Set to 0 to use automatic sizing.";
                type = "number";
                value = 0;
                isGlobal = 1;
            };
            class SpawnSleepInterval {
                displayName = "Spawn Sleep Interval (s)";
                description = "Seconds to wait between spawn batches (smaller = faster but higher frame cost).";
                type = "number";
                value = 0.15;
                isGlobal = 1;
            };
        };
    };
};
