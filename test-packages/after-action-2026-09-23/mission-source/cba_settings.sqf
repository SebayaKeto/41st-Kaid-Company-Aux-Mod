// Four-HC Umbara preset. HC1-3 infantry, named HC4 vehicles.
force FST_HC_PerHCSoftCap = 400;
force FST_HC_AICap = 1100;
force BURNS_AIThinkOnlyLocal = true;
force FST_HC_VehicleHCEnabled = true;
force FST_HC_VehicleHCSlot = 4;
force FST_HC_VehicleHCExclusive = true;
force FST_HC_BlockSpawnWhenAllHCSoftCapped = true;
force FST_HC_BlockHeavySpawnsWithoutHC = true;
force FST_HC_CombatTasksEnabled = true;
force FST_HC_CombatTaskInterval = 15;
force BURNS_DistanceScheduling = true;
force BURNS_NearDistance = 1200;
force BURNS_DistantInterval = 45;
// Existing HCSpawn garrison dispatcher: eight units per batch, gentler pacing.
force FST_HC_FillGarrisonBatchDelay = 2;
force FST_HC_FillGarrisonMaxUnits = 120;
force FST_HC_FillGarrisonMaxDuration = 60;
force FST_HC_FillGarrisonMaxScanPositions = 700;
force FST_HC_FillGarrisonCooldown = 20;
force BURNS_HumanSkill = 0.7;
force BURNS_HumanAccuracy = 0.25;
force BURNS_B1MarchSpeed = 2.5;

force BURNS_HumanBuildingCover = true;
force BURNS_HumanSuppression = true;

force BURNS_B1Reaction = 0.85;
force BURNS_LowVisibilityAssist = true;
force BURNS_VisibleContactRange = 125;

// Right click opens the selected unit's ZEN/BURNS menu; Shift-right-click
// retains native waypoint placement. ZEN's default otherwise places a waypoint.
force zen_context_menu_enabled = 2;
force zen_context_menu_overrideWaypoints = false;
