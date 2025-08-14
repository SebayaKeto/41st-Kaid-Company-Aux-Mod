class CfgPatches
{
    class 41st_Hawkbat
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
			"TAC_VESTS_W",
			"TCGM_Girls"
		};
		units[]={};
		weapons[]={};
	};
	author="Daara";
};

class CfgVehicles
{
    class ls_gar_Hawkbat_backpack;
    class ls_parachute_hawkbat_steerable;
    class FST_Hawkbat_backpack: ls_gar_Hawkbat_backpack
    {
        scope = 2;
        author = "Ruby";
        displayname = "[41st] Hawkbat";
        hiddenSelectionsTextures[] =
        {
            "41st_Hawkbat\Data\FST_Hawkbat_Closed.paa"
        };
        parachuteclass = "FST_hawkbat_parachuteSteerable";
        ace_hasReserveParachute = 1;
        ace_reserveParachute = "FST_Hawkbat_backpack_reserve";
    };
    class FST_Hawkbat_backpack_LR: ls_gar_Hawkbat_backpack
    {
        scope = 2;
        author = "Ruby";
        displayname = "[41st] Hawkbat (LR)";
         hiddenSelectionsTextures[] =
        {
            "41st_Hawkbat\Data\FST_Hawkbat_Closed.paa"
        };
        parachuteclass = "FST_hawkbat_parachuteSteerable_LR";
        ace_hasReserveParachute = 1;
        ace_reserveParachute = "FST_Hawkbat_backpack_reserve_LR";
        tf_dialog="JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=50000;
		tf_subtype="digital_lr";
    };

    class FST_Hawkbat_backpack_reserve: FST_Hawkbat_backpack
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute";
        ace_hasReserveParachute = 1;
        ace_reserveParachute = "FST_Hawkbat_backpack_reserve_1";
    };

    class FST_Hawkbat_backpack_reserve_LR: FST_Hawkbat_backpack_LR
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute (LR)";
        ace_hasReserveParachute = 1;
        ace_reserveParachute = "FST_Hawkbat_backpack_reserve_LR_1";
    };
    class FST_Hawkbat_backpack_reserve_1: FST_Hawkbat_backpack
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute";
        ace_hasReserveParachute = 1;
        ace_reserveParachute = "FST_Hawkbat_backpack_reserve_2";
    };
    class FST_Hawkbat_backpack_reserve_LR_1: FST_Hawkbat_backpack_LR
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute (LR)";
        ace_hasReserveParachute = 1;
        ace_reserveParachute = "FST_Hawkbat_backpack_reserve_LR_2";
    };
    class FST_Hawkbat_backpack_reserve_2: FST_Hawkbat_backpack
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute";
        ace_hasReserveParachute = 1;
        ace_reserveParachute = "FST_Hawkbat_backpack_reserve_3";
    };
    class FST_Hawkbat_backpack_reserve_LR_2: FST_Hawkbat_backpack_LR
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute (LR)";
        ace_hasReserveParachute = 1;
        ace_reserveParachute = "FST_Hawkbat_backpack_reserve_LR_3";
    };
    class FST_Hawkbat_backpack_reserve_3: FST_Hawkbat_backpack
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute";
        ace_hasReserveParachute = 1;
        ace_reserveParachute = "FST_Hawkbat_backpack_reserve_4";
    };
    class FST_Hawkbat_backpack_reserve_LR_3: FST_Hawkbat_backpack_LR
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute (LR)";
        ace_hasReserveParachute = 1;
        ace_reserveParachute = "FST_Hawkbat_backpack_reserve_LR_4";
    };
    class FST_Hawkbat_backpack_reserve_4: FST_Hawkbat_backpack
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute";
        ace_hasReserveParachute = 1;
        ace_reserveParachute = "FST_Hawkbat_backpack_reserve_5";
    };
    class FST_Hawkbat_backpack_reserve_LR_4: FST_Hawkbat_backpack_LR
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute (LR)";
        ace_hasReserveParachute = 1;
        ace_reserveParachute = "FST_Hawkbat_backpack_reserve_5";
    };
    class FST_Hawkbat_backpack_reserve_5: FST_Hawkbat_backpack
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute";
        ace_hasReserveParachute = 0;
        ace_reserveParachute = "";
    };
    class FST_Hawkbat_backpack_reserve_LR_5: FST_Hawkbat_backpack_LR
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute (LR)";
        ace_hasReserveParachute = 0;
        ace_reserveParachute = "";
    };
    


    class FST_hawkbat_parachuteSteerable: ls_parachute_hawkbat_steerable
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat";
        hiddenSelectionsTextures[] =
        {
            "ls\core\addons\characters_clone_legacy\backpacks\hawkbat\data\parachute\camo1_co.paa",
            "ls\core\addons\characters_clone_legacy\backpacks\hawkbat\data\parachute\camo2_co.paa",
            "41st_Hawkbat\Data\FST_Hawkbat_Wings.paa"
        };
    };

    class FST_hawkbat_parachuteSteerable_LR: ls_parachute_hawkbat_steerable
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat (LR)";
        tf_dialog="JLTS_clone_rto_radio_dialog";
        tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
        tf_encryptionCode="tf_west_radio_code";
        tf_hasLRradio=1;
        tf_range=50000;
        tf_subtype="digital_lr";
        hiddenSelectionsTextures[] =
        {
            "ls\core\addons\characters_clone_legacy\backpacks\hawkbat\data\parachute\camo1_co.paa",
            "ls\core\addons\characters_clone_legacy\backpacks\hawkbat\data\parachute\camo2_co.paa",
            "41st_Hawkbat\Data\FST_Hawkbat_Wings.paa"
        };
    };

    class FST_hawkbat_parachuteSteerable_reserve: FST_hawkbat_parachuteSteerable
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute";
    };
    
    class FST_hawkbat_parachuteSteerable_reserve_LR: FST_hawkbat_parachuteSteerable_LR
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute (LR)";
    };
    class FST_hawkbat_parachuteSteerable_reserve_2: FST_hawkbat_parachuteSteerable
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute";
    };
    
    class FST_hawkbat_parachuteSteerable_reserve_LR_2: FST_hawkbat_parachuteSteerable_LR
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute (LR)";
    };
    class FST_hawkbat_parachuteSteerable_reserve_3: FST_hawkbat_parachuteSteerable
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute";
    };
    
    class FST_hawkbat_parachuteSteerable_reserve_LR_3: FST_hawkbat_parachuteSteerable_LR
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute (LR)";
    };
    class FST_hawkbat_parachuteSteerable_reserve_4: FST_hawkbat_parachuteSteerable
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute";
    };
    
    class FST_hawkbat_parachuteSteerable_reserve_5: FST_hawkbat_parachuteSteerable
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute";
    };
     class FST_hawkbat_parachuteSteerable_reserve_LR_5: FST_hawkbat_parachuteSteerable_LR
    {
        scope = 1;
        author = "Ruby";
        displayname = "[41st] Hawkbat Reserve Parachute (LR)";
    };
};