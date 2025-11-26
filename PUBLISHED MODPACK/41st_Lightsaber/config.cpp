class CfgPatches 
{
    class FST_Lightsaber 
	{
        author = "Samurai";
        requiredAddons[]=
		{
			"A3_Data_F",
			"A3_anims_F",
			"A3_Weapons_F",
			"A3_Characters_F",
			"IDA_Ammo",
			"IDA_Republic",
			"A3_Characters_F_Proxies",
			"TCGM_Girls"
		};
        units[] = {};
        weapons[] = {};
    };
};
class CfgWeapons
{
    class WBK_lightsaber_jedi;
    class FST_Lightsaber_Daara: WBK_lightsaber_jedi
    {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        author = "Samurai"
        picture = "\WebKnight_StarWars_Weapons\ui\UI_Green.paa";
        displayName = "[41st] Lightsaber Halberd (Green)";
        model = "\41st_Lightsaber\data\daara_halbard.p3d";
        IMS_WeaponType = "LightSaber_TwoBlades";

        hiddenSelections[] =
        {
            "axe_heads",
            "brass_fittings",
            "pole",
            "wraps",
			"light",
			"gloving"
		
        };
        hiddenSelectionsMaterials[] =
        {
            "\41st_Lightsaber\data\axe_heads_daara.rvmat",
            "\41st_Lightsaber\data\brass_fittings_daara.rvmat",
            "\41st_Lightsaber\data\pole_daara.rvmat",
            "\41st_Lightsaber\data\wraps_daara.rvmat",
			"\41st_Lightsaber\data\neonnight.rvmat",
			"\41st_Lightsaber\data\neonnight_green.rvmat"
        };

        hiddenSelectionsTextures[] =
        {
            "\41st_Lightsaber\data\axe_heads_daara_co.paa",
            "\41st_Lightsaber\data\brass_fittings_daara_co.paa",
            "\41st_Lightsaber\data\pole_daara_co.paa",
            "\41st_Lightsaber\data\wraps_daara_co.paa",
			"\41st_Lightsaber\data\light_texture.paa",
			"\41st_Lightsaber\data\light_green_okantovka.paa"
        };
    };
};

