class FST_VW_AT_MissileLauncher: MissileLauncher
{
    scope = 1;
    displayName = "FST AT Missile Launcher";
    muzzles[] = {"this"};
    magazines[] = {"FST_VW_4Rnd_AT_Missiles"};
};

class FST_VW_Sabre_LG_MissileLauncher: MissileLauncher
{
    scope = 1;
    displayName = "FST Sabre Manual-Guided Missiles";
    muzzles[] = {"this"};
    magazines[] = {"FST_VW_4Rnd_SabreAPC_LG_Missiles"};
    canLock = 2;
    weaponLockSystem = 2;
    cursor = "EmptyCursor";
    cursorAim = "missile";
    showAimCursorInternal = 1;
};

class FST_VW_ATGM_Tandem_Launcher: MissileLauncher
{
    scope = 1;
    displayName = "FST ATGM Tandem Launcher";
    magazines[] = {"FST_VW_2Rnd_ATGM_Tandem_Missiles"};
};

class FST_VW_AA_MissileLauncher: MissileLauncher
{
    scope = 1;
    displayName = "FST AA Missile Launcher";
    magazines[] = {"FST_VW_8Rnd_AA_Missiles"};
};

class FST_VW_CruiseLauncher: MissileLauncher
{
    scope = 1;
    displayName = "FST Cruise Launcher";
    magazines[] = {"FST_VW_1Rnd_Cruise_Missile"};
};
