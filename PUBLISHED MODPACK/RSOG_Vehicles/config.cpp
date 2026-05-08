/*
    RSOG_Vehicles/config.cpp
    Standalone 41st aux extension for RSOG LAATs.

    v3 changes:
    - Restores the generic/base RSOG LAATs using the original full Base_Laat_* texture set.
    - Keeps the additional ARC, Medic, ODDS, Padme, Riyo, and Twi'lek hull-only skins.
    - All classes inherit from 41st LAAT classes in FST_LAAT.

    Design constraints:
    - Does NOT depend on Republic_Rotaries, SOG_Units, SOG_Equipment, 195th_Vehicles, or the original RSOG vehicle PBO.
    - All LAAT variants inherit from the 41st LAAT classes in FST_LAAT, so they keep 41st hitpoints,
      weapons, sensors, ACE cargo/fast-rope setup, TFAR intercom/radio setup, flight tuning, and pylon setup.
    - Only editor identity, crew/cargo, and textures are overridden.
    - RSOG-owned vehicle textures are expected under \RSOG_Vehicles\Data\.
*/
class CfgPatches
{
    class FST_RSOG_Vehicles
    {
        author="41st / RSOG";
        requiredVersion=0.1;
        requiredAddons[]=
        {
            "FST_LAAT"
        };
        units[]=
        {
            "FST_RSOG_LAAT_Mk2",
            "FST_RSOG_LAAT_Mk2_Lamps",
            "FST_RSOG_LAAT_Mk1_Balls",
            "FST_RSOG_LAAT_Mk1_Lamps",
            "FST_RSOG_LAAT_Mk2_ARC",
            "FST_RSOG_LAAT_Mk2_Lamps_ARC",
            "FST_RSOG_LAAT_Mk1_Balls_ARC",
            "FST_RSOG_LAAT_Mk1_Lamps_ARC",
            "FST_RSOG_LAAT_Mk2_Medic",
            "FST_RSOG_LAAT_Mk2_Lamps_Medic",
            "FST_RSOG_LAAT_Mk1_Balls_Medic",
            "FST_RSOG_LAAT_Mk1_Lamps_Medic",
            "FST_RSOG_LAAT_Mk2_ODDS",
            "FST_RSOG_LAAT_Mk2_Lamps_ODDS",
            "FST_RSOG_LAAT_Mk1_Balls_ODDS",
            "FST_RSOG_LAAT_Mk1_Lamps_ODDS",
            "FST_RSOG_LAAT_Mk2_Padme",
            "FST_RSOG_LAAT_Mk2_Lamps_Padme",
            "FST_RSOG_LAAT_Mk1_Balls_Padme",
            "FST_RSOG_LAAT_Mk1_Lamps_Padme",
            "FST_RSOG_LAAT_Mk2_Riyo",
            "FST_RSOG_LAAT_Mk2_Lamps_Riyo",
            "FST_RSOG_LAAT_Mk1_Balls_Riyo",
            "FST_RSOG_LAAT_Mk1_Lamps_Riyo",
            "FST_RSOG_LAAT_Mk2_Twilek",
            "FST_RSOG_LAAT_Mk2_Lamps_Twilek",
            "FST_RSOG_LAAT_Mk1_Balls_Twilek",
            "FST_RSOG_LAAT_Mk1_Lamps_Twilek"
        };
        weapons[]={};
    };
};

class CfgFactionClasses
{
    class FST_RSOG_Faction
    {
        displayName="[41st] RSOG Attachments";
        side=1;
        priority=2;
    };
};

class CfgEditorSubcategories
{
    class FST_RSOG_Republic_Rotaries
    {
        displayName="RSOG Rotary Assets";
    };
};

class CfgVehicles
{
    class FST_laati_Turret;
    class FST_laati_mk1Lights;
    class FST_laati_mk2;
    class FST_laati_mk2Lights;

    class FST_RSOG_LAAT_Mk2: FST_laati_mk2
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk II Gunship";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\Base_Laat_Hull_CO.paa",
            "\RSOG_Vehicles\Data\Base_Laat_Wings_CO.paa",
            "\RSOG_Vehicles\Data\Base_Laat_Weapons_CO.paa",
            "\RSOG_Vehicles\Data\Base_Laat_Weapon_Details_CO.paa",
            "\RSOG_Vehicles\Data\Base_Laat_Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk2_Lamps: FST_laati_mk2Lights
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk II Gunship (Lamps)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\Base_Laat_Hull_CO.paa",
            "\RSOG_Vehicles\Data\Base_Laat_Wings_CO.paa",
            "\RSOG_Vehicles\Data\Base_Laat_Weapons_CO.paa",
            "\RSOG_Vehicles\Data\Base_Laat_Weapon_Details_CO.paa",
            "\RSOG_Vehicles\Data\Base_Laat_Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk1_Balls: FST_laati_Turret
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk I Gunship (Balls)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\Base_Laat_Hull_CO.paa",
            "\RSOG_Vehicles\Data\Base_Laat_Wings_CO.paa",
            "\RSOG_Vehicles\Data\Base_Laat_Weapons_CO.paa",
            "\RSOG_Vehicles\Data\Base_Laat_Weapon_Details_CO.paa",
            "\RSOG_Vehicles\Data\Base_Laat_Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk1_Lamps: FST_laati_mk1Lights
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk I Gunship (Lamps)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\Base_Laat_Hull_CO.paa",
            "\RSOG_Vehicles\Data\Base_Laat_Wings_CO.paa",
            "\RSOG_Vehicles\Data\Base_Laat_Weapons_CO.paa",
            "\RSOG_Vehicles\Data\Base_Laat_Weapon_Details_CO.paa",
            "\RSOG_Vehicles\Data\Base_Laat_Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk2_ARC: FST_laati_mk2
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk II Gunship (ARC)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_arc_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk2_Lamps_ARC: FST_laati_mk2Lights
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk II Gunship (Lamps) (ARC)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_arc_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk1_Balls_ARC: FST_laati_Turret
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk I Gunship (Balls) (ARC)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_arc_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk1_Lamps_ARC: FST_laati_mk1Lights
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk I Gunship (Lamps) (ARC)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_arc_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk2_Medic: FST_laati_mk2
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk II Gunship (Medic)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_medic_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk2_Lamps_Medic: FST_laati_mk2Lights
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk II Gunship (Lamps) (Medic)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_medic_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk1_Balls_Medic: FST_laati_Turret
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk I Gunship (Balls) (Medic)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_medic_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk1_Lamps_Medic: FST_laati_mk1Lights
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk I Gunship (Lamps) (Medic)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_medic_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk2_ODDS: FST_laati_mk2
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk II Gunship (ODDS)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_odds_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk2_Lamps_ODDS: FST_laati_mk2Lights
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk II Gunship (Lamps) (ODDS)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_odds_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk1_Balls_ODDS: FST_laati_Turret
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk I Gunship (Balls) (ODDS)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_odds_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk1_Lamps_ODDS: FST_laati_mk1Lights
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk I Gunship (Lamps) (ODDS)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_odds_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk2_Padme: FST_laati_mk2
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk II Gunship (Padme)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_padme_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk2_Lamps_Padme: FST_laati_mk2Lights
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk II Gunship (Lamps) (Padme)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_padme_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk1_Balls_Padme: FST_laati_Turret
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk I Gunship (Balls) (Padme)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_padme_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk1_Lamps_Padme: FST_laati_mk1Lights
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk I Gunship (Lamps) (Padme)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_padme_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk2_Riyo: FST_laati_mk2
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk II Gunship (Riyo)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_riyo_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk2_Lamps_Riyo: FST_laati_mk2Lights
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk II Gunship (Lamps) (Riyo)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_riyo_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk1_Balls_Riyo: FST_laati_Turret
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk I Gunship (Balls) (Riyo)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_riyo_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk1_Lamps_Riyo: FST_laati_mk1Lights
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk I Gunship (Lamps) (Riyo)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_riyo_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk2_Twilek: FST_laati_mk2
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk II Gunship (Twi'lek)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_twilek_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk2_Lamps_Twilek: FST_laati_mk2Lights
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk II Gunship (Lamps) (Twi'lek)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_twilek_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk1_Balls_Twilek: FST_laati_Turret
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk I Gunship (Balls) (Twi'lek)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_twilek_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };

    class FST_RSOG_LAAT_Mk1_Lamps_Twilek: FST_laati_mk1Lights
    {
        author="41st / RSOG";
        scope=2;
        scopeCurator=2;
        scopeArsenal=2;
        side=1;
        displayName="[RSOG] LAAT/i Mk I Gunship (Lamps) (Twi'lek)";
        faction="FST_RSOG_Faction";
        editorSubcategory="FST_RSOG_Republic_Rotaries";
        crew="FST_Pilot_P1";
        typicalCargo[]={"FST_Pilot_P1"};
        hiddenSelectionsTextures[]=
        {
            "\RSOG_Vehicles\Data\v_laat_hull_twilek_co.paa",
            "41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
            "3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
            "3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
            "3AS\3as_Laat\LAATI\data\Interior_CO.paa"
        };
        textureList[]={};
    };
};
