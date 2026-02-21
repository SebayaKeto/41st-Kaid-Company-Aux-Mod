class CfgPatches
{
	class 41st_RSOG_Vehicles
	{
		requiredAddons[]=
		{
			"A3_Data_F",
			"A3_anims_F",
			"A3_Weapons_F",
			"A3_Characters_F",
			"IDA_Ammo",
			"IDA_Republic",
			"A3_Characters_F_Proxies",
			"JLTS_characters_CloneArmor",
			"3AS_Characters_Commando",
			"3AS_Characters_Clones_Headgear"
		};
        units[]=
        {
            "FST_RSOG_laati_Turret",
            "FST_RSOG_Laati_MK2"
        };
        weapons[]={};
    };
};

class cfgFactionClasses
{
    class FST_RSOG_Faction
    {
        displayname = "[41st/RSOG] Republic Special Operations Group";
        priority = 1;
        Side = 1;
    };
};
        class CfgEditorSubcategories
        {
            class FST_RSOG_Airvehicle
            {
            displayname = "[41st/RSOG] Air Vehicles";
            };
        };

class CfgVehicles
{
    class FST_laati_Turret;
	class FST_laati_mk2;
	class FST_laati_mk1Lights;
	class FST_laati_mk2Lights;
    
    class FST_RSOG_laati_Turret: FST_laati_Turret
    {
        author = "Ruby";
        displayname = "[41st/RSOG] LAAT/I MK I Gunship";
        scope = 2;
        scopecurator = 2;
        side = 1;
        faction = "FST_RSOG_Faction";
        editorsubcategory = "FST_RSOG_Airvehicle";
        crew="FST_Pilot_P1";
        hiddenSelectionsTextures[]=
        {
            "FST_Rsog_Vehicles\Data\Base_Laat_Hull_CO.paa",
            "FST_Rsog_Vehicles\Data\Base_Laat_Wings_CO.paa",
            "FST_Rsog_Vehicles\Data\Base_Laat_Weapons_CO.paa",
            "FST_Rsog_Vehicles\Data\Base_Laat_Weapon_Details_CO.paa",
            "FST_Rsog_Vehicles\Data\Base_Laat_Interior_CO.paa",
        };
    };
    class FST_RSOG_Laati_MK2: FST_Laati_mk2
    {
         author = "Ruby";
        displayname = "[41st/RSOG] LAAT/I MK II Gunship";
        scope = 2;
        scopecurator = 2;
        side = 1;
        faction = "FST_RSOG_Faction";
        editorsubcategory = "FST_RSOG_Airvehicle";
        crew="FST_Pilot_P1";
        hiddenSelectionsTextures[]=
        {
            "FST_Rsog_Vehicles\Data\Base_Laat_Hull_CO.paa",
            "FST_Rsog_Vehicles\Data\Base_Laat_Wings_CO.paa",
            "FST_Rsog_Vehicles\Data\Base_Laat_Weapons_CO.paa",
            "FST_Rsog_Vehicles\Data\Base_Laat_Weapon_Details_CO.paa",
            "FST_Rsog_Vehicles\Data\Base_Laat_Interior_CO.paa",
        };
    };
};