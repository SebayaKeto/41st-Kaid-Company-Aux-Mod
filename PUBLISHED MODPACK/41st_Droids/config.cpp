class CfgPatches
{
	class 41st_Droids
	{
		requiredAddons[]={"A3_Soft_F"};
		units[]=
		{
			"FST_Droid_B1_E5",
			"FST_Droid_B1_Sniper",
			"FST_Droid_B1_Commander",
			"FST_Droid_B1_AT",
			"FST_Droid_B1_GAT",
			"FST_Droid_B1_AR",
			"FST_Droid_B1_AA",
			"FST_Droid_B1_OOM",
			"FST_CIS_TS_F",
			"FST_BX",
			"FST_BX_Rusty",
			"FST_BX_Tukata",
			"FST_BX_AT",
			"FST_BX_AT_Rusty",
			"FST_BX_AA",
			"FST_BX_AA_Rusty",
			"FST_BX_Sniper",
			"FST_BX_Sniper_Rusty",
			"FST_BX_Sniper_Tukata",
			"FST_B2",
			"FST_B2_TL",
			"FST_B2_Flame",
			"FST_U_CIS_Heavy",
			"FST_U_CIS_Heavy_AT",
			"FST_U_CIS_Light",
			"FST_Jorgetrooper",
			"FST_Jorgetrooper_AT",
			"FST_Jorgetrooper_AR",
			"FST_Droid_B1_BMO",
			"FST_Droid_B1_Rodger",
			"FST_Droid_B1_Tumble",
			"FST_Droid_B1_PLAD",
			"FST_JMSLLTE_JinTrooper_armor_F",
			"FST_JMSLLTE_JinTrooper_armor_AR",
			"FST_JMSLLTE_JinTrooper_armor_AT",
			"FST_MSE_Droid",
			"FST_JARCtrooper"
		};
		weapons[]={};
	};
	author="Daara";
};
class CfgWeapons
{
	class U_I_CombatUniform;
	class UniformItem;
	class JLTS_DroidB1;
	class 3AS_CIS_Light_helmet;
	class VestItem;
	class Vest_Camo_Base;
	class GoG_HolsterSwordVestBack_Invis: Vest_Camo_Base
	{
		scope=2;
		displayName="B1 Invis Vest";
		picture="";
		model="\A3\Characters_F\blufor\equip_b_vest02.p3d";
		hiddenSelections[]=
			{
			"camo"
			};
		hiddenSelectionsTextures[]=
		{};
		class ItemInfo: VestItem
		{
			uniformModel="\A3\Characters_F\blufor\equip_b_vest02.p3d";
			containerClass="Supply100";
			mass=50;
			armor=200;
			passThrough=0.3;
			hiddenSelections[]=
				{
				"camo"
				};
		};
	};
	class FST_DroidB1_Test: U_I_CombatUniform
	{
		JLTS_isDroid=1;
		JLTS_hasEMPProtection=0;
		JLTS_deathSounds="DeathDroid";
		author="Runner";
		scope=2;
		displayName="[41st] B1 Combat Uniform Test";
		picture="\MRC\JLTS\characters\DroidArmor\data\ui\b1_uniform_ui_ca.paa";
		model="\41st_Droids\Data\DroidUniformB1.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Droid_B1_E5";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class FST_DroidB1: JLTS_DroidB1
	{
		author="Daara";
		scope=2;
		displayname="[41st] B1 Combat Uniform";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Droid_B1_E5";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class FST_CIS_Light_Helmet: 3AS_CIS_Light_helmet
    {
        author = "Ruby";
        displayname="[41st] CIS Human Divison Officer Helmet";
        hiddenSelections[]=
        {
            "camo"
        };
        hiddenSelectionsTextures[]=
        {
            "41st_Droids\Data\Extras\FST_Helmet_HumDiv_Officer.paa"
        };
    };
    class FST_HumanDiv_Pouches_Base: FST_DroidB1
    {
        author="Ruby";
        scope=0;
        displayname="[41st] Human Divison Pouches Base"
        JLTS_isDroid=0;
        hiddenselections[]=
        {
            "pouch1",
            "pouch2",
            "pouch3"
        };
        class ItemInfo: vestitem
        {
            hiddenselections[]=
            {
                "pouch1",
                "pouch2",
                "pouch3"
            };
            uniformmodel="kobra\442_equipment\vests\model\clone\scout_pouches.p3d";
        };
    };
    class FST_HumanDiv_Pouches: FST_HumanDiv_Pouches_Base
    {
        author="Ruby";
        scope=2;
        displayname="[41st] Human Divison Pouches"
        hiddenselectionstextures[]=
        {
            "41st_Droids\Data\Extras\FST_Pouches_HumDiv.paa",
            "41st_Droids\Data\Extras\FST_Pouches_HumDiv.paa",
            "41st_Droids\Data\Extras\FST_Pouches_HumDiv.paa"
        };
    };
	class FST_DroidB1_Muddy: JLTS_DroidB1
	{
		author="Gold";
		scope=2;
		displayname="[41st] B1 Combat Uniform (Muddy)";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Droid_B1_E5_Muddy";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class FST_DroidB1_Commander: FST_DroidB1
	{
		author="Daara";
		scope=2;
		displayName="[41st] B1 Combat Uniform (Commander)";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Droid_B1_Commander";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class FST_DroidB1_Sniper: FST_DroidB1
	{
		author="Daara";
		scope=2;
		displayName="[41st] B1 Combat Uniform (Sniper)";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Droid_B1_Sniper";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class FST_DroidB1_GAT: FST_DroidB1
	{
		author="Daara";
		scope=2;
		displayName="[41st] B1 Combat Uniform (GAT)";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Droid_B1_GAT";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class FST_DroidB1_AT: FST_DroidB1
	{
		author="Daara";
		scope=2;
		displayName="[41st] B1 Combat Uniform (AT)";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Droid_B1_AT";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class FST_DroidB1_AR: FST_DroidB1
	{
		author="Daara";
		scope=2;
		displayName="[41st] B1 Combat Uniform (LMG)";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Droid_B1_AR";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class FST_DroidB1_AA: FST_DroidB1
	{
		author="Daara";
		scope=2;
		displayName="[41st] B1 Combat Uniform (AA)";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Droid_B1_AA";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class FST_DroidB1_Scorch: FST_DroidB1
	{
		author="Daara";
		scope=2;
		displayName="[41st] B1 Combat Uniform (Scorch)";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Droid_B1_Scorch";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class FST_DroidB1_OOM: FST_DroidB1
	{
		author="Viz";
		scope=2;
		displayName="[41st] B1 Combat Uniform (OOM)";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Droid_B1_OOM";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class FST_DroidB1_BMO: JLTS_DroidB1
	{
		author="Viz";
		scope=2;
		displayname="[41st] B1 BMO";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Droid_B1_BMO";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class FST_DroidB1_Rodger: JLTS_DroidB1
	{
		author="Viz";
		scope=2;
		displayname="[41st] B1 Rodger";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Droid_B1_Rodger";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class FST_DroidB1_Tumble: JLTS_DroidB1
	{
		author="Gold";
		scope=2;
		displayname="[41st] B1 Tumble";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Droid_B1_Tumble";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class FST_DroidB1_PLAD: JLTS_DroidB1
	{
		author="Gold";
		scope=2;
		displayname="[41st] B1 (PLAD)";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Droid_B1_PLAD";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class Uniform_Base;
	class FST_U_CIS_TS: Uniform_Base
	{
		author="Viz";
		scope=2;
		displayName="[41st] Tactical Battledroid";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Characters\Droids\TSeries\data\3AS_TS_CO.paa"
		};
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_CIS_TS_F";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
			hiddenSelections[]=
			{
				"camo"
			};
		};
	};
	class FST_DroidBX: FST_DroidB1
	{
		author="Daara";
		scope=2;
		displayname="[41st] BX Combat Uniform";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
        JLTS_deathSounds="";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_BX";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class FST_DroidBX_Rusty: FST_DroidB1
	{
		author="Steel";
		scope=2;
		displayname="[41st] BX Combat Uniform (Rusty)";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
        JLTS_deathSounds="";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_BX_Rusty";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class FST_DroidBX_Tukata: FST_DroidB1
	{
		author="Gold";
		scope=2;
		displayname="[41st] BX Combat Uniform (Tukata)";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
        JLTS_deathSounds="";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_BX_Tukata";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class FST_DroidB2: FST_DroidB1
	{
		author="Daara";
		scope=2;
		displayname="[41st] B2 Armor";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
        JLTS_deathSounds="";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_B2";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class FST_DroidB2_TL: FST_DroidB1
	{
		author="Daara";
		scope=2;
		displayname="[41st] B2 Armor (TL)";
		JLTS_isDroid=1;
        JLTS_hasEMPProtection=0;
        JLTS_deathSounds="";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_B2_TL";
			containerClass="Supply200";
			uniformType="Neopren";
			mass=40;
		};
	};
	class ItemCore;
	class FST_Uniform_CIS_Heavy_Base: ItemCore
	{
		scope=0;
		allowedSlots[]={901};
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_Uniform_CIS_Heavy_Base";
			containerClass="Supply40";
			mass=40;
		};
	};
	class FST_U_CIS_Heavy_Armor: FST_Uniform_CIS_Heavy_Base
	{
		author="$STR_3AS_Studio";
		scope=2;
		displayName="[41st] CIS Human Division Armor (Heavy)";
		picture="\A3\characters_f\data\ui\icon_U_B_CombatUniform_mcam_ca.paa";
		model="3AS\3AS_CIS_Infantry\Model\CIS_Heavy.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_CIS_Infantry\data\heavy\cis_heavy_texture_armour_co.paa"
		};
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_U_CIS_Heavy";
			containerClass="Supply150";
			mass=40;
		};
	};
	class 3AS_Uniform_CIS_Human_Base;
	class FST_U_CIS_Light_Armor: 3AS_Uniform_CIS_Human_Base
	{
		author="Gold";
		displayName="[41st] CIS Human Division Armor (Light)";
		scope=2;
		picture="\A3\characters_f\data\ui\icon_U_B_CombatUniform_mcam_ca.paa";
		model="3AS\3AS_CIS_Infantry\Model\CIS_Inf.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\FST_Armor_HumDiv_Veteran.paa"
		};
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_U_CIS_Light";
			containerClass="Supply150";
			mass=40;
		};
	};
	class FST_JMSLLTE_JinTrooper_armor_F_CombatUniform: Uniform_Base
	{
		author="JMax";
		scope=2;
		displayName="[41st] Tukata PMC Armor";
		picture="\JMSLLTE_empire\data\ico\ico_u_jinT.paa";
		nakedUniform="U_BasicBody";
		model="\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		allowedSlots[]={901};
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_JMSLLTE_JinTrooper_armor_F";
			modelSides[]={6};
			containerClass="Supply40";
			mass=40;
		};
	};
	class FST_Jorgetrooper_Uniform: FST_Uniform_CIS_Heavy_Base
	{
		author="$STR_3AS_Studio";
		scope=2;
		displayName="[41st] Brainwashed Clone Armor";
		picture="\A3\characters_f\data\ui\icon_U_B_CombatUniform_mcam_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper_Jorge.Paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_Jorge.Paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_Armor_P2_Upper.rvmat",
			"41st_Armor\Data\Other\Clone_Armor_P2_Lower.rvmat",
		};
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_Jorgetrooper";
			containerClass="Supply150";
			mass=40;
		};
	};
	class FST_Jorgetrooper_Uniform_AT: FST_Uniform_CIS_Heavy_Base
	{
		author="$STR_3AS_Studio";
		scope=2;
		displayName="[41st] Brainwashed Clone Armor (AT)";
		picture="\A3\characters_f\data\ui\icon_U_B_CombatUniform_mcam_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper_Jorge.Paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_Jorge.Paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_Armor_P2_Upper.rvmat",
			"41st_Armor\Data\Other\Clone_Armor_P2_Lower.rvmat",
		};
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_Jorgetrooper_AT";
			containerClass="Supply150";
			mass=40;
		};
	};
	class FST_Jorgetrooper_Uniform_AR: FST_Uniform_CIS_Heavy_Base
	{
		author="$STR_3AS_Studio";
		scope=2;
		displayName="[41st] Brainwashed Clone Armor (AR)";
		picture="\A3\characters_f\data\ui\icon_U_B_CombatUniform_mcam_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper_Jorge.Paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_Jorge.Paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_Armor_P2_Upper.rvmat",
			"41st_Armor\Data\Other\Clone_Armor_P2_Lower.rvmat",
		};
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_Jorgetrooper_AR";
			containerClass="Supply150";
			mass=40;
		};
	};
};
class UniformSlotInfo
{
	slotType=0;
	linkProxy="-";
};
class CfgVehicles
{
	class JLTS_B1_Backpack;
	class JLTS_B1_antenna;
	class FST_Backpack_RTO_Hidden;
	class 3AS_B_CloneGM_Base_F;
	class FST_B1_Backpack: JLTS_B1_Backpack
	{
		author="Daara";
		scope=2;
		picture="\MRC\JLTS\characters\DroidArmor\data\ui\b1_Backpack_ui_ca.paa";
		displayName="[41st] B1 Backpack";
		model="\MRC\JLTS\characters\DroidArmor\DroidBackpackB1.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\DroidArmor\data\b1_Backpack_co.paa"
		};
		tf_dialog="JLTS_droid_lr_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_east_radio_code";
		tf_hasLRradio=1;
		tf_range=15000;
		tf_subtype="digital_lr";
	};
	class FST_B1_Backpack_PLAD: JLTS_B1_Backpack
	{
		author="Gold";
		scope=2;
		picture="\MRC\JLTS\characters\DroidArmor\data\ui\b1_Backpack_ui_ca.paa";
		displayName="[41st] B1 Backpack (PLAD)";
		model="\MRC\JLTS\characters\DroidArmor\DroidBackpackB1.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\Kaid_Droids\FST_B1_Backpack_PLAD.paa"
		};
		tf_dialog="JLTS_droid_lr_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_east_radio_code";
		tf_hasLRradio=1;
		tf_range=15000;
		tf_subtype="digital_lr";
	};
	class FST_B1_Backpack_Kaid: FST_B1_Backpack
	{
		author="Viz";
		displayName="[41st] B1 Backpack";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\Kaid_Droids\FST_B1_Backpack.paa"
		};
	};
	class FST_Backpack_HumanDiv: FST_B1_Backpack
    {
        author = "Ruby";
        displayname = "[41st] Human Divison Backpack"
        model="\3AS\3AS_Republic_Characters\Backpacks\3AS_Clonetrooper_Backpack_GM.p3d";
        picture="\A3\Weapons_F\Ammoboxes\Bags\data\ui\backpack_CA.paa";
        hiddenSelections[]=
        {
            "Backpack"
        };
        hiddenSelectionsTextures[]=
        {
            "41st_Droids\Data\Extras\FST_Backpack_GM_HumDiv.paa"
        };
    };
	class FST_B1_Antenna: JLTS_B1_antenna
	{
		author="Daara";
		scope=2;
		picture="\MRC\JLTS\characters\DroidArmor\data\ui\b1_antenna_ui_ca.paa";
		displayName="[41st] B1 Antenna";
		model="\MRC\JLTS\characters\DroidArmor\DroidAntennaB1.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\DroidArmor\data\b1_antenna_co.paa"
		};
		tf_dialog="JLTS_droid_lr_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_east_radio_code";
		tf_hasLRradio=1;
		tf_range=15000;
		tf_subtype="digital_lr";
	};
	class FST_B1_Antenna_Muddy: FST_B1_Antenna
	{
		author="Gold";
		scope=2;
		displayName="[41st] B1 Antenna (Muddy)";
		model="\MRC\JLTS\characters\DroidArmor\DroidAntennaB1.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\FST_B1_Backpack_Muddy.paa"
		};
	};
	class FST_B1_Antenna_Kaid: FST_B1_Antenna
	{
		author="Viz";
		displayName="[41st] B1 Kaid Antenna";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\Kaid_Droids\FST_B1_Antenna.paa"
		};
	};
	class FST_B1_backpack_at_predef: FST_B1_backpack
	{
		scope=2;
		class TransportMagazines
		{
			class _xx_FST_RPS6_Rocket
			{
				count=2;
				magazine="FST_RPS6_Rocket";
			};
		};
	};
	class FST_HD_backpack_at_predef: FST_Backpack_HumanDiv
	{
		scope=2;
		model="";
		class TransportMagazines
		{
			class _xx_FST_RPS6_Rocket
			{
				count=3;
				magazine="FST_RPS6_Rocket";
			};
		};
	};
	class FST_B1_backpack_gat_predef: FST_B1_backpack
	{
		scope=2;
		class TransportMagazines
		{
			class _xx_JLTS_E60R_AT_mag
			{
				count=2;
				magazine="JLTS_E60R_AT_mag";
			};
		};
	};
	class FST_B1_backpack_aa_predef: FST_B1_backpack
	{
		scope=2;
		class TransportMagazines
		{
			class _xx_FST_E60R_AA_mag
			{
				count=2;
				magazine="FST_E60R_AA_mag";
			};
		};
	};
	class FST_B1_backpack_support_predef: FST_B1_backpack
	{
		scope=2;
		class TransportMagazines
		{
			class _xx_FST_Droid_blaster_battery_Red
			{
				count=10;
				magazine="FST_Droid_blaster_battery_Red";
			};
		};
	};
	class FST_BX_InvisAT: FST_Backpack_RTO_Hidden
	{
		scope=2;
		class TransportMagazines
		{
			class _xx_FST_RPS6_Rocket
			{
				count=2;
				magazine="FST_RPS6_Rocket";
			};
		};
	};
	class FST_BX_InvisAA: FST_Backpack_RTO_Hidden
	{
		scope=2;
		class TransportMagazines
		{
			class _xx_FST_E60R_AA_mag
			{
				count=2;
				magazine="FST_E60R_AA_mag";
			};
		};
	};
	class B_AssaultPack_blk;
	class FST_belt_bag_Tukata: B_AssaultPack_blk
	{
		author="Daara";
		scope=2;
		maximumload=250;
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_belt_bag_ui_ca.paa";
		displayName="[41st] Belt Bag (Tukata)";
		model="\MRC\JLTS\characters\CloneArmor\CloneBeltBag.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneArmor\data\Clone_belt_bag_co.paa"
		};
		class TransportMagazines
		{
			class _xx_FST_RPS6_Rocket
			{
				count=2;
				magazine="FST_RPS6_Rocket";
			};
			class _xx_FST_Droid_blaster_battery_Red
			{
				count=12;
				magazine="FST_blaster_cell_Westar_Yellow";
			};
		};
	};
	class FST_belt_bag_Tukata_AR: B_AssaultPack_blk
	{
		author="Daara";
		scope=2;
		maximumload=250;
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_belt_bag_ui_ca.paa";
		displayName="[41st] AR Belt Bag (Tukata)";
		model="\MRC\JLTS\characters\CloneArmor\CloneBeltBag.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneArmor\data\Clone_belt_bag_co.paa"
		};
		class TransportMagazines
		{
			class _xx_FST_Droid_blaster_battery_Red
			{
				count=12;
				magazine="FST_blaster_battery_Yellow";
			};
		};
	};
	class JLTS_Droid_B1_E5;
	// Testing New Model Here
	class O_soldier_base_F;
	class O_Soldier_F: O_soldier_base_F
	{
		class HitPoints;
	};
	class FST_Droid_B1_E5: JLTS_Droid_B1_E5
	{
		scope=2;
		scopecurator = 2;
		side=0;
		author="Runner";
		displayName="[41st] B1 Battledroid";
		armor=75; 
		armorStructural=2;
		explosionshielding=10;
		backpack="FST_B1_backpack";
		uniformClass="FST_DroidB1";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\DroidArmor\data\b1_co.paa"
		};
		weapons[]=
		{
			"FST_E5",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_E5",
			"Throw",
			"Put"
		};
		Items[]={};
		respawnItems[]={};
		class HitPoints: O_Soldier_F
		{
			class HitFace
			{
				armor=1;
				explosionShielding=80; //Was 100
				minimalHit=0.01;
			};
			class HitNeck: HitFace
			{
				armor=1;
				explosionShielding=80;
				minimalHit=0.01;
			};
			class HitHead: HitNeck
			{
				armor=1;
				explosionShielding=80;
				minimalHit=0.01;
			};
			class HitPelvis: HitHead
			{
				armor=1;
				explosionShielding=80;
				minimalHit=0.01;
			};
			class HitAbdomen: HitPelvis
			{
				armor=1;
				explosionShielding=80;
				minimalHit=0.01;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor=1;
				explosionShielding=80;
				minimalHit=0.01;
			};
			class HitChest: HitDiaphragm
			{
				armor=1;
				explosionShielding=80;
				minimalHit=0.01;
			};
			class HitBody: HitChest
			{
				armor=1;
				passthrough=1;
				explosionShielding=80;
				minimalHit=0.01;
			};
			class HitArms: HitBody
			{
				armor=1;
				passthrough=1;
				explosionShielding=85;
				minimalHit=0.01;
			};
			class HitHands: HitArms
			{
				armor=1;
				passthrough=1;
				explosionShielding=85;
				minimalHit=0.01;
			};
			class HitLegs: HitHands
			{
				armor=1;
				explosionShielding=85;
				minimalHit=0.01;
			};
			class Incapacitated: HitLegs
			{
				armor=1000;
			};
			class HitLeftArm
			{
				armor=1;
				passthrough=1;
				explosionShielding=85;
				minimalHit=0.01;
			}; 
		};
		linkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		respawnLinkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		magazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
		};
		respawnMagazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
		};
	};
	class FST_Droid_B1_E5_Muddy: JLTS_Droid_B1_E5
	{
		author="Gold";
		displayName="[41st] B1 Battledroid (Muddy)";
		uniformClass="FST_DroidB1_Muddy";
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\Kaid_Droids\FST_B1_Muddy.paa"
		};
	};
	class FST_Droid_B1_Sniper: FST_Droid_B1_E5
	{
		scope=2;
		side=0;
		author="Daara";
		displayName="[41st] B1 Battledroid (Sniper)";
		armor=4;
		armorStructural=100;
		backpack="FST_B1_backpack";
		uniformClass="FST_DroidB1_Sniper";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\DroidArmor\data\b1_co.paa"
		};
		weapons[]=
		{
			"FST_E5S",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_E5S",
			"Throw",
			"Put"
		};
		Items[]={};
		respawnItems[]={};
		linkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		respawnLinkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		magazines[]=
		{
			"FST_Droid_blaster_cell_overcharged_red",
			"FST_Droid_blaster_cell_overcharged_red",
			"FST_Droid_blaster_cell_overcharged_red",
			"FST_Droid_blaster_cell_overcharged_red",
			"FST_Droid_blaster_cell_overcharged_red",
			"SmokeShell",
			"SmokeShellGreen",
			"Chemlight_green",
			"Chemlight_green",
		};
		respawnMagazines[]=
		{
			"FST_Droid_blaster_cell_overcharged_red",
			"FST_Droid_blaster_cell_overcharged_red",
			"FST_Droid_blaster_cell_overcharged_red",
			"FST_Droid_blaster_cell_overcharged_red",
			"FST_Droid_blaster_cell_overcharged_red",
			"SmokeShell",
			"SmokeShellGreen",
			"Chemlight_green",
			"Chemlight_green",
		};
	};
	class FST_Droid_B1_Commander: FST_Droid_B1_E5
	{
		scope=2;
		author="Daara";
		displayName="[41st] B1 Battledroid (Commander)";
		armor=4;
		armorStructural=100;
		Backpack="FST_B1_Antenna";
		uniformClass="FST_DroidB1_Commander";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\DroidArmor\data\b1_commander_co.paa"
		};
		weapons[]=
		{
			"FST_E5",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_E5",
			"Throw",
			"Put"
		};
		Items[]={};
		respawnItems[]={};
		linkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		respawnLinkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		magazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag"
		};
		respawnMagazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag"
		};
	};
	class FST_Droid_B1_GAT: FST_Droid_B1_E5
	{
		scope=2;
		author="Daara";
		backpack="FST_B1_backpack_gat_predef";
		displayName="[41st] B1 Battledroid (Guided Anti-Tank)";
		armor=4;
		armorStructural=100;
		uniformClass="FST_DroidB1_GAT";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\DroidArmor\data\b1_co.paa"
		};
		Items[]={};
		respawnItems[]={};
		linkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		respawnLinkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		weapons[]=
		{
			"FST_E5",
			"JLTS_E60R_AT",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_E5",
			"JLTS_E60R_AT",
			"Throw",
			"Put"
		};
		magazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
		};
		respawnMagazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
		};
	};
	class FST_Droid_B1_AT: FST_Droid_B1_E5
	{
		scope=2;
		author="Daara";
		backpack="FST_B1_backpack_at_predef";
		displayName="[41st] B1 Battledroid (Anti-Tank)";
		armor=4;
		armorStructural=100;
		uniformClass="FST_DroidB1_AT";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\DroidArmor\data\b1_co.paa"
		};
		Items[]={};
		respawnItems[]={};
		linkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		respawnLinkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		weapons[]=
		{
			"FST_E5",
			"FST_RPS6HP",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_E5",
			"FST_RPS6HP",
			"Throw",
			"Put"
		};
		magazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
		};
		respawnMagazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
		};
	};
	class FST_Droid_B1_AA: FST_Droid_B1_E5
	{
		scope=2;
		author="Daara";
		backpack="FST_B1_backpack_aa_predef";
		displayName="[41st] B1 Battledroid (Anti-Air)";
		armor=4;
		armorStructural=100;
		uniformClass="FST_DroidB1_AA";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\DroidArmor\data\b1_co.paa"
		};
		Items[]={};
		respawnItems[]={};
		linkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		respawnLinkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		weapons[]=
		{
			"FST_E5",
			"FST_E60R_AA",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_E5",
			"FST_E60R_AA",
			"Throw",
			"Put"
		};
		magazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
		};
		respawnMagazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
		};
	};
	class FST_Droid_B1_AR: FST_Droid_B1_E5
	{
		scope=2;
		author="Daara";
		backpack="FST_B1_backpack_support_predef";
		displayName="[41st] B1 Battledroid (LMG)";
		armor=4;
		armorStructural=100;
		uniformClass="FST_DroidB1_AR";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\DroidArmor\data\b1_co.paa"
		};
		weapons[]=
		{
			"FST_E5C_Stock",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_E5C_Stock",
			"Throw",
			"Put"
		};
		Items[]={};
		respawnItems[]={};
		linkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		respawnLinkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		magazines[]=
		{
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
		};
		respawnMagazines[]=
		{
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
		};
	};
	class FST_Droid_B1_Scorch: FST_Droid_B1_E5
	{
		scope=2;
		author="Daara";
		backpack="FST_B1_backpack_support_predef";
		displayName="[41st] B1 Battledroid (Scorch)";
		armor=4;
		armorStructural=100;
		uniformClass="FST_DroidB1_Scorch";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\DroidArmor\data\b1_co.paa"
		};
		weapons[]=
		{
			"IDA_BTX42",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"IDA_BTX42",
			"Throw",
			"Put"
		};
		Items[]={};
		respawnItems[]={};
		linkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		respawnLinkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		magazines[]=
		{
			"IDA_FuelTank",
			"IDA_FuelTank",
			"IDA_FuelTank",
		};
		respawnMagazines[]=
		{
			"IDA_FuelTank",
			"IDA_FuelTank",
			"IDA_FuelTank",
		};
	};
	class FST_Droid_B1_OOM: FST_Droid_B1_E5
	{
		scope=2;
		author="Viz";
		displayName="[41st] B1 Battledroid (OOM)";
		armor=4;
		armorStructural=100;
		Backpack="FST_B1_Antenna";
		uniformClass="FST_DroidB1_OOM";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\DroidArmor\data\b1_crew_co.paa"
		};
		weapons[]=
		{
			"FST_E5",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_E5",
			"Throw",
			"Put"
		};
		Items[]={};
		respawnItems[]={};
		linkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_2",
			"JLTS_NVG_droid_chip_2"
		};
		respawnLinkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_2",
			"JLTS_NVG_droid_chip_2"
		};
		magazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag"
		};
		respawnMagazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag"
		};
	};
	class FST_Droid_B1_BMO: FST_Droid_B1_E5
	{
		scope=2;
		author="Viz";
		displayName="[41st] B1 Battledroid BMO";
		armor=4;
		armorStructural=100;
		side=1;
		Backpack="FST_B1_Antenna_Kaid";
		uniformClass="FST_DroidB1_BMO";
		faction="FST_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\Kaid_Droids\FST_B1_BMO.paa"
		};
		weapons[]=
		{
			"FST_E5",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_E5",
			"Throw",
			"Put"
		};
		Items[]={};
		respawnItems[]={};
		linkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		respawnLinkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		magazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red"
		};
		respawnMagazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red"
		};
	};
	class FST_Droid_B1_Rodger: FST_Droid_B1_BMO
	{
		scope=2;
		author="Viz";
		displayName="[41st] B1 Battledroid Rodger";
		armor=4;
		armorStructural=100;
		Backpack="FST_B1_Antenna_Kaid";
		uniformClass="FST_DroidB1_Rodger";
		faction="FST_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\Kaid_Droids\FST_B1_Rodger.paa"
		};
	};
	class FST_Droid_B1_Tumble: FST_Droid_B1_BMO
	{
		scope=2;
		author="Gold";
		displayName="[41st] B1 Battledroid Tumble";
		armor=4;
		armorStructural=100;
		Backpack="FST_B1_Antenna_Kaid";
		uniformClass="FST_DroidB1_Tumble";
		faction="FST_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\Kaid_Droids\FST_B1_Tumble.paa"
		};
	};
	class FST_Droid_B1_PLAD: FST_Droid_B1_E5
	{
		scope=2;
		side=2;
		author="Gold";
		displayName="[41st] B1 Battledroid (PLAD)";
		armor=4;
		armorStructural=100;
		Backpack="FST_B1_Backpack_PLAD";
		uniformClass="FST_DroidB1_PLAD";
		faction="FST_Independent_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\Kaid_Droids\FST_B1_PLAD.paa"
		};
	};
	class FST_CIS_TS_F: FST_Droid_B1_E5
	{
		scope=2;
		author="Viz";
		displayName="[41st] T-Series Droid";
		model="\3AS\3AS_Characters\Droids\TSeries\3AS_TS.p3d";
		armor=4;
		armorStructural=100;
		Backpack="";
		uniformClass="FST_U_CIS_TS";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		identityTypes[]=
		{
			"LanguageENGVR_F",
			"O_3AS_head_F"
		};
		speaker="Male01ENGVR";
		hiddenSelections[]=
		{
			"Camo"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Characters\Droids\TSeries\data\3AS_TS_CO.paa"
		};
		hideProxySelections[]=
		{
			"ghillie_hide"
		};
		weapons[]=
		{
			"FST_E5",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_E5",
			"Throw",
			"Put"
		};
		Items[]={};
		respawnItems[]={};
		linkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		respawnLinkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1"
		};
		magazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag"
		};
		respawnMagazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag"
		};
	};
	class WBK_BX_Assasin_1;
	class FST_BX: WBK_BX_Assasin_1
	{
		scope=2;
		identityTypes[]={};
		author="Daara";
		Backpack="";
		displayName="[41st] BX Commando Droid";
		uniformClass="FST_DroidBX";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		armor=40;
		armorStructural=100;
		model="\ls\core\addons\characters_droid\uniforms\bx\ls_uniform_droid_bx.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\characters_droid\uniforms\bx\data\body_co.paa"
		};
		weapons[]=
		{
			"FST_E5",
			"WBK_Dutch_Vibro",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_E5",
			"WBK_Dutch_Vibro",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"JLTS_NVG_droid_chip_2",
			"GoG_HolsterSwordVestBack",
			"FST_HUD",
		};
		respawnLinkedItems[]=
		{
			"JLTS_NVG_droid_chip_2",
			"GoG_HolsterSwordVestBack",
			"FST_HUD",
		};
		Items[]={};
		respawnItems[]={};
		magazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag",
		};
		respawnMagazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag",
		};
	};
	class FST_BX_Sniper: FST_BX
	{
		scope=2;
		identityTypes[]={};
		author="Daara";
		Backpack="";
		displayName="[41st] BX Commando Droid (Sniper)";
		uniformClass="FST_DroidBX";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		armor=40;
		armorStructural=100;
		weapons[]=
		{
			"FST_E5S",
			"WBK_Dutch_Vibro",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_E5S",
			"WBK_Dutch_Vibro",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"JLTS_NVG_droid_chip_2",
			"GoG_HolsterSwordVestBack",
			"FST_HUD",
		};
		respawnLinkedItems[]=
		{
			"JLTS_NVG_droid_chip_2",
			"GoG_HolsterSwordVestBack",
			"FST_HUD",
		};
		Items[]={};
		respawnItems[]={};
		magazines[]=
		{
			"FST_Droid_blaster_cell_overcharged_red",
			"FST_Droid_blaster_cell_overcharged_red",
			"FST_Droid_blaster_cell_overcharged_red",
			"FST_Droid_blaster_cell_overcharged_red",
			"FST_Droid_blaster_cell_overcharged_red",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Detonator_mag",
		};
		respawnMagazines[]=
		{
			"FST_Droid_blaster_cell_overcharged_red",
			"FST_Droid_blaster_cell_overcharged_red",
			"FST_Droid_blaster_cell_overcharged_red",
			"FST_Droid_blaster_cell_overcharged_red",
			"FST_Droid_blaster_cell_overcharged_red",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Detonator_mag",
		};
	};
	class FST_BX_AT: FST_BX
	{
		scope=2;
		author="Steel";
		backpack="FST_BX_InvisAT";
		displayName="[41st] BX Commando Droid (Anti-Tank)";
		uniformClass="FST_DroidBX";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		armor=40;
		armorStructural=100;
		weapons[]=
		{
			"FST_E5",
			"WBK_Dutch_Vibro",
			"FST_RPS6HP",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_E5",
			"WBK_Dutch_Vibro",
			"FST_RPS6HP",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"JLTS_NVG_droid_chip_2",
			"GoG_HolsterSwordVestBack",
			"FST_HUD",
		};
		respawnLinkedItems[]=
		{
			"JLTS_NVG_droid_chip_2",
			"GoG_HolsterSwordVestBack",
			"FST_HUD",
		};
		Items[]={};
		respawnItems[]={};
		magazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag",
			"FST_RPS6_rocket_HE",
			"FST_RPS6_rocket_HE",
			"FST_RPS6_rocket_HE",

		};
		respawnMagazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag",
			"FST_RPS6_rocket_HE",
			"FST_RPS6_rocket_HE",
			"FST_RPS6_rocket_HE",
		};
	};
	class FST_BX_AA: FST_BX
	{
		scope=2;
		author="Steel";
		backpack="FST_BX_InvisAA";
		displayName="[41st] BX Commando Droid (Anti-Air)";
		uniformClass="FST_DroidBX";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		armor=40;
		armorStructural=100;
		weapons[]=
		{
			"FST_E5",
			"WBK_Dutch_Vibro",
			"FST_E60R_AA",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_E5",
			"WBK_Dutch_Vibro",
			"FST_E60R_AA",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"JLTS_NVG_droid_chip_2",
			"GoG_HolsterSwordVestBack",
			"FST_HUD",
		};
		respawnLinkedItems[]=
		{
			"JLTS_NVG_droid_chip_2",
			"GoG_HolsterSwordVestBack",
			"FST_HUD",
		};
		Items[]={};
		respawnItems[]={};
		magazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag",
			"FST_E60R_AA_mag",
			"FST_E60R_AA_mag",
			"FST_E60R_AA_mag",
		};
		respawnMagazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag",
			"FST_E60R_AA_mag",
			"FST_E60R_AA_mag",
			"FST_E60R_AA_mag",
		};
	};
	class FST_BX_Rusty: FST_BX
	{
		author="Steel";
		displayName="[41st] BX Commando Droid (Rusty)";
		model="\ls\core\addons\characters_droid\uniforms\bx\ls_uniform_droid_bx.p3d";
		uniformClass="FST_DroidBX_Rusty";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\FST_BX_Rusty_Body.paa"
		};
	};
	class FST_BX_Sniper_Rusty: FST_BX_Sniper
	{
		author="Steel";
		displayName="[41st] BX Commando Droid (Sniper/Rusty)";
		model="\ls\core\addons\characters_droid\uniforms\bx\ls_uniform_droid_bx.p3d";
		uniformClass="FST_DroidBX_Rusty";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\FST_BX_Rusty_Body.paa"
		};
	};
		class FST_BX_AT_Rusty: FST_BX_AT
	{
		author="Steel";
		displayName="[41st] BX Commando Droid (Anti-Tank/Rusty)";
		model="\ls\core\addons\characters_droid\uniforms\bx\ls_uniform_droid_bx.p3d";
		uniformClass="FST_DroidBX_Rusty";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\FST_BX_Rusty_Body.paa"
		};
	};
	class FST_BX_AA_Rusty: FST_BX_AA
	{
		author="Steel";
		displayName="[41st] BX Commando Droid (Anti-Air/Rusty)";
		model="\ls\core\addons\characters_droid\uniforms\bx\ls_uniform_droid_bx.p3d";
		uniformClass="FST_DroidBX_Rusty";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\FST_BX_Rusty_Body.paa"
		};
	};
	class FST_BX_Tukata: FST_BX
	{
		author="Gold";
		displayName="[41st] BX Commando Droid (Tukata)";
		model="\ls\core\addons\characters_droid\uniforms\bx\ls_uniform_droid_bx.p3d";
		uniformClass="FST_DroidBX_Tukata";
		faction="FST_Tukata_Faction";
		editorSubcategory="FST_Tukata_Subfaction";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\FST_BX_Tukata_Body.paa"
		};
	};
	class FST_BX_Sniper_Tukata: FST_BX_Sniper
	{
		author="Gold";
		displayName="[41st] BX Commando Droid (Sniper/Tukata)";
		model="\ls\core\addons\characters_droid\uniforms\bx\ls_uniform_droid_bx.p3d";
		uniformClass="FST_DroidBX_Tukata";
		faction="FST_Tukata_Faction";
		editorSubcategory="FST_Tukata_Subfaction";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\FST_BX_Tukata_Body.paa"
		};
	};
	class WBK_B2_Mod_Standart;
	class FST_B2: WBK_B2_Mod_Standart
	{
		scope=2;
		identityTypes[]={};
		author="Daara";
		Backpack="";
		displayName="[41st] B2 Super Battledroid";
		uniformClass="FST_DroidB2";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelections[]=
		{
			"camo_arms",
			"legs",
			"torso"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\Kaid_Droids\FST_B2_Arms_black.paa",
			"41st_Droids\Data\Extras\Kaid_Droids\FST_B2_Legs_black.paa",
			"41st_Droids\Data\Extras\Kaid_Droids\FST_B2_Torso_black.paa"
		};
		weapons[]=
		{
			"FST_WristBlaster",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_WristBlaster",
			"Throw",
			"Put"
		};
		linkedItems[]={};
		respawnLinkedItems[]={};
		Items[]={};
		respawnItems[]={};
		magazines[]=
		{
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red"
		};
		respawnMagazines[]=
		{
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red"
		};
		armor=1000;
	};
	class FST_B2_TL: WBK_B2_Mod_Standart
	{
		scope=2;
		identityTypes[]={};
		author="Daara";
		Backpack="";
		displayName="[41st] B2 Super Battledroid Team Leader";
		uniformClass="FST_DroidB2_TL";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelections[]=
		{
			"camo_arms",
			"legs",
			"torso"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\Kaid_Droids\FST_B2_Arms_black.paa",
			"41st_Droids\Data\Extras\Kaid_Droids\FST_B2_Legs_black.paa",
			"41st_Droids\Data\Extras\Kaid_Droids\FST_B2_Torso_black.paa"
		};
		weapons[]=
		{
			"FST_WristBlaster",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_WristBlaster",
			"Throw",
			"Put"
		};
		linkedItems[]={};
		respawnLinkedItems[]={};
		Items[]={};
		respawnItems[]={};
		magazines[]=
		{
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_HE_LauncherWristRocket",
			"FST_HE_LauncherWristRocket"
		};
		respawnMagazines[]=
		{
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_HE_LauncherWristRocket",
			"FST_HE_LauncherWristRocket"
		};
		armor=1000;
	};
	class FST_B2_Flame: WBK_B2_Mod_Standart
	{
		scope=2;
		identityTypes[]={};
		author="Daara";
		Backpack="";
		displayName="[41st] B2 Super Battledroid (Flame)";
		uniformClass="FST_DroidB2";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		hiddenSelections[]=
		{
			"camo_arms",
			"legs",
			"torso"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\Kaid_Droids\FST_B2_Arms_black.paa",
			"41st_Droids\Data\Extras\Kaid_Droids\FST_B2_Legs_black.paa",
			"41st_Droids\Data\Extras\Kaid_Droids\FST_B2_Torso_black.paa"
		};
		weapons[]=
		{
			"IDA_BTX42",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"IDA_BTX42",
			"Throw",
			"Put"
		};
		linkedItems[]={};
		respawnLinkedItems[]={};
		Items[]={};
		respawnItems[]={};
		magazines[]=
		{
			"IDA_FuelTank",
			"IDA_FuelTank",
			"IDA_FuelTank",
			"IDA_FuelTank",
			"IDA_FuelTank",
			"IDA_FuelTank",
			"IDA_FuelTank",
			"IDA_FuelTank",
			"IDA_FuelTank",
			"IDA_FuelTank"
		};
		respawnMagazines[]=
		{
			"IDA_FuelTank",
			"IDA_FuelTank",
			"IDA_FuelTank",
			"IDA_FuelTank",
			"IDA_FuelTank",
			"IDA_FuelTank",
			"IDA_FuelTank",
			"IDA_FuelTank",
			"IDA_FuelTank",
			"IDA_FuelTank"

		};
	};
	class FST_CIS_Heavy_Base_F: FST_Droid_B1_E5
	{
		author="Adapted from 3AS";
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
			"G_NATO_default"
		};
		faceType="Man_A3";
		backpack="FST_HD_backpack_at_predef";
		side=0;
		faction="FST_BattleDroids_Faction";
		genericNames="NATOMen";
		vehiclesClass="Men";
		editorSubcategory="FST_BattleDroids_Subfaction";
		portrait="";
		picture="";
		icon="iconMan";
		accuracy=2.3;
		camouflage=1.4;
		minFireTime=7;
		canCarryBackPack=1;
		scope=0;
		class Wounds
		{
			tex[]={};
			mat[]=
			{
				"A3\Characters_F\BLUFOR\Data\clothing1.rvmat",
				"A3\Characters_F\BLUFOR\Data\clothing1_injury.rvmat",
				"A3\Characters_F\BLUFOR\Data\clothing1_injury.rvmat",
				"A3\Characters_F\Common\Data\basicbody.rvmat",
				"A3\Characters_F\Common\Data\basicbody_injury.rvmat",
				"A3\Characters_F\Common\Data\basicbody_injury.rvmat",
				"A3\characters_f\common\data\coveralls.rvmat",
				"A3\Characters_F\Common\Data\coveralls_injury.rvmat",
				"A3\Characters_F\Common\Data\coveralls_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"
			};
		};
		model="\3AS\3AS_CIS_Infantry\Model\CIS_Heavy.p3d";
		modelSides[]={2};
		nakedUnifrom="U_BasicBody";
		uniformClass="FST_Uniform_CIS_Heavy_Base";
		class HitPoints
		{
			class HitFace
			{
				armor=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitNeck: HitFace
			{
				armor=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitHead: HitNeck
			{
				armor=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitPelvis: HitHead
			{
				armor=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitAbdomen: HitPelvis
			{
				armor=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitDiaphragm: HitAbdomen
			{
				armor=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitChest: HitDiaphragm
			{
				armor=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitBody: HitChest
			{
				armor=1;
				passthrough=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitArms: HitBody
			{
				armor=1;
				passthrough=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitHands: HitArms
			{
				armor=1;
				passthrough=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitLegs: HitHands
			{
				armor=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class Incapacitated: HitLegs
			{
				armor=1000;
			};
			class HitLeftArm
			{
				armor=1;
				passthrough=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
		};
		armor=125; 
		armorStructural=2;
		explosionshielding=15;
		HiddenSelections[]=
		{
			"Camo"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_CIS_Infantry\data\heavy\cis_heavy_texture_armour_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_CIS_Infantry\data\heavy\cis_heavy.rvmat"
		};
		class EventHandlers;
		weapons[]=
		{
			"FST_E5C_Stock",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_E5C_Stock",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1",
			"3AS_CIS_Light_helmet"
		};
		respawnLinkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1",
			"3AS_CIS_Light_helmet"
		};
		magazines[]=
		{
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag",
		};
		respawnMagazines[]=
		{
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag",
		};
	};
	class FST_U_CIS_Heavy: FST_CIS_Heavy_Base_F
	{
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopecurator=2;
		displayName="[41st] CIS Human Division (Heavy)";
		author="Adapted from 3AS";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_CIS_Heavy_Armor";
		role="Rifleman";
		backpack="";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_CIS_Infantry\data\heavy\cis_heavy_texture_armour_co.paa"
		};
		linkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1",
			"3AS_CIS_Light_helmet"
		};
		respawnLinkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1",
			"3AS_CIS_Light_helmet"
		};
	};
	class FST_U_CIS_Heavy_AT: FST_CIS_Heavy_Base_F
	{
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopecurator=2;
		displayName="[41st] CIS Human Division (AT)";
		author="Adapted from 3AS";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_CIS_Heavy_Armor";
		role="Rifleman";
		backpack="FST_HD_backpack_at_predef";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_CIS_Infantry\data\heavy\cis_heavy_texture_armour_co.paa"
		};
		class EventHandlers;
		weapons[]=
		{
			"FST_E5C_Stock",
			"FST_RPS6HP",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_E5C_Stock",
			"FST_RPS6HP",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1",
			"3AS_CIS_Light_helmet"
		};
		respawnLinkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1",
			"3AS_CIS_Light_helmet"
		};
		magazines[]=
		{
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag",
		};
		respawnMagazines[]=
		{
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"FST_Droid_blaster_battery_Red",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag",
		};
	};
	class 3AS_U_CIS_Light;
	class FST_U_CIS_Light: 3AS_U_CIS_Light
	{
		author="Gold";
		displayName="[41st] CIS Human Division (Light)";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_CIS_Light_Armor";
		role="Rifleman";
		class HitPoints
		{
			class HitFace
			{
				armor=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitNeck: HitFace
			{
				armor=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitHead: HitNeck
			{
				armor=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitPelvis: HitHead
			{
				armor=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitAbdomen: HitPelvis
			{
				armor=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitDiaphragm: HitAbdomen
			{
				armor=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitChest: HitDiaphragm
			{
				armor=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitBody: HitChest
			{
				armor=1;
				passthrough=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitArms: HitBody
			{
				armor=1;
				passthrough=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitHands: HitArms
			{
				armor=1;
				passthrough=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class HitLegs: HitHands
			{
				armor=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
			class Incapacitated: HitLegs
			{
				armor=1000;
			};
			class HitLeftArm
			{
				armor=1;
				passthrough=1;
				explosionShielding	= 100;	
				minimalHit			= 0.01;	
			};
		};
		class UniformInfo
		{
			class SlotsInfo
			{
				class NVG: UniformSlotInfo
				{
					slotType=602;
				};
				class Scuba: UniformSlotInfo
				{
					slotType=604;
				};
				class Headgear: UniformSlotInfo
				{
					slotType=605;
				};
			};
		};
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_CIS_Infantry\data\cis_inf_texture_armour_co.paa"
		};
		linkedItems[]=
		{
			"FST_CIS_Light_Helmet",
			"ItemMap",
			"ItemCompass",
			"ItemWatch",
			"ItemRadio"
		};
		respawnLinkedItems[]=
		{
			"FST_CIS_Light_Helmet",
			"ItemMap",
			"ItemCompass",
			"ItemWatch",
			"ItemRadio"
		};
	};
	class FST_JMSLLTE_JinTrooper_armor_F: FST_CIS_Heavy_Base_F
	{
		author="JMax";
		scope=2;
		scopecurator=2;
		modelSides[]={6};
		displayName="[41st] Tukata PMC Trooper";
		model="\JMSLLTE_empire_m\jin_trooper.p3d";
		nakedUniform="FST_Uniform_Bodyglove";
		uniformclass="FST_JMSLLTE_JinTrooper_armor_F_CombatUniform";
		backpack="FST_belt_bag_Tukata";
		faction="FST_Tukata_Faction";
		editorSubcategory="FST_Tukata_Subfaction";
		hiddenSelections[]=
		{
			"Camo1",
			"Camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\jin_suit_co.paa",
			"JMSLLTE_empire\data\body\jin_armor_co.paa"
		};
		class Wounds
		{
			tex[]={};
			mat[]=
			{
				"JMSLLTE_empire\data\body\jin_suit_clo.rvmat",
				"JMSLLTE_empire\data\body\jin_suit_clo_injury.rvmat",
				"JMSLLTE_empire\data\body\jin_suit_clo_injury.rvmat",
				"JMSLLTE_empire\data\body\jin_suit.rvmat",
				"JMSLLTE_empire\data\body\jin_suit_injury.rvmat",
				"JMSLLTE_empire\data\body\jin_suit_injury.rvmat",
				"JMSLLTE_empire\data\body\jin_armor.rvmat",
				"JMSLLTE_empire\data\body\jin_armor_injury.rvmat",
				"JMSLLTE_empire\data\body\jin_armor_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"
			};
		};
		weapons[]=
		{
			"FST_Westar_M5_A",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_Westar_M5_A",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1",
			"FST_P2_Invisible_Helmet"
		};
		respawnLinkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1",
			"FST_P2_Invisible_Helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Westar_Yellow",
			"FST_blaster_cell_Westar_Yellow",
			"FST_blaster_cell_Westar_Yellow",
			"FST_blaster_cell_Westar_Yellow",
			"FST_blaster_cell_Westar_Yellow",
			"FST_blaster_cell_Westar_Yellow",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag",
		};
		respawnMagazines[]=
		{
			"FST_blaster_cell_Westar_Yellow",
			"FST_blaster_cell_Westar_Yellow",
			"FST_blaster_cell_Westar_Yellow",
			"FST_blaster_cell_Westar_Yellow",
			"FST_blaster_cell_Westar_Yellow",
			"FST_blaster_cell_Westar_Yellow",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag",
		};
	};
	class FST_JMSLLTE_JinTrooper_armor_AT: FST_JMSLLTE_JinTrooper_armor_F
	{
		author="JMax";
		scope=2;
		scopecurator=2;
		modelSides[]={6};
		displayName="[41st] Tukata PMC Trooper (AT)";
		model="\JMSLLTE_empire_m\jin_trooper.p3d";
		nakedUniform="FST_Uniform_Bodyglove";
		uniformclass="FST_JMSLLTE_JinTrooper_armor_F_CombatUniform";
		backpack="FST_belt_bag_Tukata";
		faction="FST_Tukata_Faction";
		editorSubcategory="FST_Tukata_Subfaction";
		hiddenSelections[]=
		{
			"Camo1",
			"Camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\jin_suit_co.paa",
			"JMSLLTE_empire\data\body\jin_armor_co.paa"
		};
		class Wounds
		{
			tex[]={};
			mat[]=
			{
				"JMSLLTE_empire\data\body\jin_suit_clo.rvmat",
				"JMSLLTE_empire\data\body\jin_suit_clo_injury.rvmat",
				"JMSLLTE_empire\data\body\jin_suit_clo_injury.rvmat",
				"JMSLLTE_empire\data\body\jin_suit.rvmat",
				"JMSLLTE_empire\data\body\jin_suit_injury.rvmat",
				"JMSLLTE_empire\data\body\jin_suit_injury.rvmat",
				"JMSLLTE_empire\data\body\jin_armor.rvmat",
				"JMSLLTE_empire\data\body\jin_armor_injury.rvmat",
				"JMSLLTE_empire\data\body\jin_armor_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"
			};
		};
		weapons[]=
		{
			"FST_Westar_M5_A",
			"FST_RPS6HP",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_Westar_M5_A",
			"FST_RPS6HP",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1",
			"FST_P2_Invisible_Helmet"
		};
		respawnLinkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1",
			"FST_P2_Invisible_Helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Westar_Yellow",
			"FST_blaster_cell_Westar_Yellow",
			"FST_blaster_cell_Westar_Yellow",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag",
		};
		respawnMagazines[]=
		{
			"FST_blaster_cell_Westar_Yellow",
			"FST_blaster_cell_Westar_Yellow",
			"FST_blaster_cell_Westar_Yellow",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag",
		};
	};
	class FST_JMSLLTE_JinTrooper_armor_AR: FST_JMSLLTE_JinTrooper_armor_F
	{
		author="JMax";
		scope=2;
		scopecurator=2;
		modelSides[]={6};
		displayName="[41st] Tukata PMC Trooper (AR)";
		model="\JMSLLTE_empire_m\jin_trooper.p3d";
		nakedUniform="FST_Uniform_Bodyglove";
		uniformclass="FST_JMSLLTE_JinTrooper_armor_F_CombatUniform";
		backpack="FST_belt_bag_Tukata_AR";
		faction="FST_Tukata_Faction";
		editorSubcategory="FST_Tukata_Subfaction";
		hiddenSelections[]=
		{
			"Camo1",
			"Camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\jin_suit_co.paa",
			"JMSLLTE_empire\data\body\jin_armor_co.paa"
		};
		class Wounds
		{
			tex[]={};
			mat[]=
			{
				"JMSLLTE_empire\data\body\jin_suit_clo.rvmat",
				"JMSLLTE_empire\data\body\jin_suit_clo_injury.rvmat",
				"JMSLLTE_empire\data\body\jin_suit_clo_injury.rvmat",
				"JMSLLTE_empire\data\body\jin_suit.rvmat",
				"JMSLLTE_empire\data\body\jin_suit_injury.rvmat",
				"JMSLLTE_empire\data\body\jin_suit_injury.rvmat",
				"JMSLLTE_empire\data\body\jin_armor.rvmat",
				"JMSLLTE_empire\data\body\jin_armor_injury.rvmat",
				"JMSLLTE_empire\data\body\jin_armor_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"
			};
		};
		weapons[]=
		{
			"FST_Z6",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_Z6",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1",
			"FST_P2_Invisible_Helmet"
		};
		respawnLinkedItems[]=
		{
			"FST_HUD",
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"ItemWatch",
			"JLTS_NVG_droid_chip_1",
			"JLTS_NVG_droid_chip_1",
			"FST_P2_Invisible_Helmet"
		};
		magazines[]=
		{
			"FST_blaster_battery_Yellow",
			"FST_blaster_battery_Yellow",
			"FST_blaster_battery_Yellow",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag",
		};
		respawnMagazines[]=
		{
			"FST_blaster_battery_Yellow",
			"FST_blaster_battery_Yellow",
			"FST_blaster_battery_Yellow",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag",
		};
	};
	class FST_Jorgetrooper: FST_CIS_Heavy_Base_F
	{
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopecurator=2;
		displayName="[41st] Brainwashed Clone Trooper";
		author="Daara";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		role="Rifleman";
		backpack="";
		uniformclass="FST_Jorgetrooper_Uniform";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		allowedFacewear[] = {""};
		faceType = "Man_A3";
		identityTypes[] = {"FST_Jorge_FaceOnly"};
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper_Jorge.Paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_Jorge.Paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_Armor_P2_Upper.rvmat",
			"41st_Armor\Data\Other\Clone_Armor_P2_Lower.rvmat",
		};
		weapons[]=
		{
			"FST_DC15A",
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_DC15A",
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet_Jorge",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet_Jorge",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		magazines[]=
		{
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue"
		};
		respawnMagazines[]=
		{
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue"
		};
		armor=4; 
		armorStructural=3;
		explosionshielding=6;
		class HitPoints: HitPoints
		{
			class HitFace: HitFace
			{
				armor=1;
				material=-1;
				name="face_hub";
				passThrough=0.80000001;
				radius=0.079999998;
				explosionShielding=0.1;
				minimalHit=0.0099999998;
			};
			class HitNeck: HitNeck
			{
				armor=1;
				material=-1;
				name="neck";
				passThrough=0.80000001;
				radius=0.1;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
			};
			class HitHead: HitNeck
			{
				armor=1;
				material=-1;
				name="head";
				passThrough=0.80000001;
				radius=0.2;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
				depends="HitFace max HitNeck";
			};
			class HitPelvis: HitHead
			{
				armor=8;
				material=-1;
				name="pelvis";
				passThrough=0.80000001;
				radius=0.23999999;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="";
			};
			class HitAbdomen: HitPelvis
			{
				armor=6;
				material=-1;
				name="spine1";
				passThrough=0.80000001;
				radius=0.16;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor=6;
				material=-1;
				name="spine2";
				passThrough=0.33000001;
				radius=0.18000001;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitChest: HitDiaphragm
			{
				armor=8;
				material=-1;
				name="spine3";
				passThrough="0.33000001radius = 0.18";
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitBody: HitBody
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=1;
				radius=0;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
			};
			class HitArms: HitBody
			{
				armor=6;
				material=-1;
				name="arms";
				passThrough=1;
				radius=0.1;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="0";
			};
			class HitHands: HitArms
			{
				armor=6;
				material=-1;
				name="hands";
				passThrough=1;
				radius=0.1;
				explosionShielding=1;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="HitArms";
			};
			class HitLegs: HitHands
			{
				armor=6;
				material=-1;
				name="legs";
				passThrough=1;
				radius=0.14;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
				depends="0";
			};
			class Incapacitated: HitLegs
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=1;
				radius=0;
				explosionShielding=3;
				visual="";
				minimalHit=0;
				depends="(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
			};
			class HitLeftArm: HitLegs
			{
				armor=6;
				material=-1;
				name="hand_l";
				passThrough=1;
				radius=0.079999998;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
			};
			class HitRightArm: HitLeftArm
			{
				name="hand_r";
			};
			class HitLeftLeg: HitLegs
			{
				armor=6;
				material=-1;
				name="leg_l";
				passThrough=1;
				radius=0.1;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
			};
			class HitRightLeg: HitLeftLeg
			{
				name="leg_r";
			};
		};
		class EventHandlers{init = "if (local _this) then { (_this select 0) setFace 'FST_Clone_Head_Jorge'; };";};
	};
	class FST_Jorgetrooper_AT: FST_Jorgetrooper
	{
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopecurator=2;
		displayName="[41st] Brainwashed Clone Trooper (AT)";
		author="Daara";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		role="Rifleman";
		backpack="FST_HD_backpack_at_predef";
		uniformclass="FST_Jorgetrooper_Uniform_AT";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		allowedFacewear[] = {""};
		faceType = "Man_A3";
		identityTypes[] = {"FST_Jorge_FaceOnly"};
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper_Jorge.Paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_Jorge.Paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_Armor_P2_Upper.rvmat",
			"41st_Armor\Data\Other\Clone_Armor_P2_Lower.rvmat",
		};
		weapons[]=
		{
			"FST_DC15A",
			"FST_RPS6HP",
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_DC15A",
			"FST_RPS6HP",
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet_Jorge",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet_Jorge",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		magazines[]=
		{
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag",
		};
		respawnMagazines[]=
		{
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Blue",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag",
		};
		class EventHandlers{init = "if (local _this) then { (_this select 0) setFace 'FST_Clone_Head_Jorge'; };";};
	};
	class FST_Jorgetrooper_AR: FST_Jorgetrooper
	{
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopecurator=2;
		displayName="[41st] Brainwashed Clone Trooper (AR)";
		author="Daara";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		role="Rifleman";
		backpack="";
		uniformclass="FST_Jorgetrooper_Uniform_AR";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		allowedFacewear[] = {""};
		faceType = "Man_A3";
		identityTypes[] = {"FST_Jorge_FaceOnly"};
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper_Jorge.Paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_Jorge.Paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_Armor_P2_Upper.rvmat",
			"41st_Armor\Data\Other\Clone_Armor_P2_Lower.rvmat",
		};
		weapons[]=
		{
			"FST_Z6",
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"FST_Z6",
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet_Jorge",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet_Jorge",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		magazines[]=
		{
			"FST_blaster_battery_blue",
			"FST_blaster_battery_blue",
			"FST_blaster_battery_blue",
			"FST_blaster_battery_blue",
			"FST_blaster_battery_blue",
			"FST_blaster_battery_blue",
			"FST_blaster_battery_blue",
		};
		respawnMagazines[]=
		{
			"FST_blaster_battery_blue",
			"FST_blaster_battery_blue",
			"FST_blaster_battery_blue",
			"FST_blaster_battery_blue",
			"FST_blaster_battery_blue",
			"FST_blaster_battery_blue",
			"FST_blaster_battery_blue",
		};
		class EventHandlers{init = "if (local _this) then { (_this select 0) setFace 'FST_Clone_Head_Jorge'; };";};
	};
		class FST_JARCtrooper: WBK_BX_Assasin_1
	{
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopecurator=2;
		displayName="[41st] Brainwashed ARC Trooper";
		author="Laer";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_BattleDroids_Subfaction";
		nakedUniform="U_BasicBody";
		canBleed = 1;
		role="Rifleman";
		backpack="FST_Clone_Backpack_ARC";
		uniformClass="FST_Uniform_JARC";
		genericNames="NATOMen";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		allowedFacewear[] = {""};
		faceType = "Man_A3";
		identityTypes[] = {"FST_Jorge_FaceOnly"};
		hiddenSelections[]={"camo1", "camo2"};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper_JARC.paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_JARC.Paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_Armor_P2_Upper.rvmat",
			"41st_Armor\Data\Other\Clone_Armor_P2_Lower.rvmat"
		};
		weapons[]={"FST_Westar_M5", "UNSC_Knife", "JLTS_CloneBinocular", "Throw", "Put"};
		respawnWeapons[]={"FST_Westar_M5", "UNSC_Knife", "JLTS_CloneBinocular", "Throw", "Put"};
		linkedItems[]=
		{
			"FST_P2_ARC_Helmet_Jorge",
			"FST_CloneVestARC_Jorge",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_ARC_Helmet_Jorge",
			"FST_CloneVestARC_Jorge",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		magazines[]=
		{
			"FST_blaster_cell_Westar_Blue",
			"FST_blaster_cell_Westar_Blue",
			"FST_blaster_cell_Westar_Blue",
			"FST_blaster_cell_Westar_Blue",
			"FST_blaster_cell_Westar_Blue",
			"FST_blaster_cell_Westar_Blue",
			"FST_blaster_cell_Westar_Blue",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag"
		};
		respawnMagazines[]=
		{
			"FST_blaster_cell_Westar_Blue",
			"FST_blaster_cell_Westar_Blue",
			"FST_blaster_cell_Westar_Blue",
			"FST_blaster_cell_Westar_Blue",
			"FST_blaster_cell_Westar_Blue",
			"FST_blaster_cell_Westar_Blue",
			"FST_blaster_cell_Westar_Blue",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Detonator_mag",
			"IDA_grenade_Detonator_mag"
		};
		class SoundEnvironExt {
			generic[] = {};
		};
		class SoundEquipment {
			soldier[] = {};
		};
		armor=35;
		armorStructural=100;
		explosionshielding=8;
	};
 };
class cfgGroups
{
	class EAST
	{
		name="OPFOR";
		
		class FST_CIS
		{
			name="41st Battledroids";
			
			class FST_Droid_Standard
			{
				name="Infantry";
				
				class FST_Droid_B1_E5_Squad
				{
					name="[41st] B1 Squad (STD)";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_Droid_B1_Commander";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
				class FST_Droid_B1_E5_Platoon
				{
					name="[41st] B1 Squad (Platoon)";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_Droid_B1_Commander";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
					class Unit12
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit13
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit14
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit15
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit16
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit17
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit18
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit19
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit20
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit21
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit22
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
					class Unit23
					{
						side=0;
						vehicle="FST_Droid_B1_Commander";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit24
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit25
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit26
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit27
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit28
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit29
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit30
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit31
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit32
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit33
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit34
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
					class Unit35
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit36
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit37
					{
						side=0;
						vehicle="FST_Droid_B1_AT";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit38
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit39
					{
						side=0;
						vehicle="FST_Droid_B1_AT";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit40
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit41
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit42
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit43
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit44
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit45
					{
						side=0;
						vehicle="FST_Droid_B1_Commander";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
				class FST_Droid_B1_E5_Squad_Sniper
				{
					name="[41st] B1 Squad (w/ Sniper)";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_Droid_B1_Commander";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_Droid_B1_Sniper";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
				class FST_Droid_B1_E5_Squad_AT
				{
					name="[41st] B1 Squad (w/ AT)";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_Droid_B1_Commander";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_Droid_B1_AT";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
				class FST_Droid_B1_E5_Squad_AA
				{
					name="[41st] B1 Squad (w/ AA)";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_Droid_B1_Commander";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_Droid_B1_AA";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
				class FST_Droid_B1_E5_Squad_Both
				{
					name="[41st] B1 Squad (AT/AA)";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_Droid_B1_Commander";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_Droid_B1_AT";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_Droid_B1_AA";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
				class FST_Droid_B1_E5_FireTeam
				{
					name="[41st] B1 Fireteam";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_Droid_B1_AR";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
				};
				class FST_Droid_B1_E5_GATeam
				{
					name="[41st] B1 Guided AT Team";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_Droid_B1_E5";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_Droid_B1_GAT";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
				};
				class FST_BX_KillTeam
				{
					name="[41st] BX Kill Team";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_BX";
						rank="SERGEANT";
						position[]={0,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_BX";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_BX";
						rank="PRIVATE";
						position[]={1,-0,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_BX";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
				};
				class FST_BX_SniperTeam
				{
					name="[41st] BX Sniper Team";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_BX_Sniper";
						rank="SERGEANT";
						position[]={0,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_BX_Sniper";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
				};
				class FST_BX_AntiTankTeam
				{
					name="[41st] BX Anti-Tank Team";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_BX_AT";
						rank="SERGEANT";
						position[]={0,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_BX_AT";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
				};
				class FST_BX_AntiAirTeam
				{
					name="[41st] BX Anti-Air Team";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_BX_AA";
						rank="SERGEANT";
						position[]={0,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_BX_AA";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
				};
				class FST_BX_KillTeam_Rusty
				{
					name="[41st] BX Kill Team (Rusty)";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_BX_Rusty";
						rank="SERGEANT";
						position[]={0,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_BX_Rusty";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_BX_Rusty";
						rank="PRIVATE";
						position[]={1,-0,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_BX_Rusty";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
				};
				class FST_BX_SniperTeam_Rusty
				{
					name="[41st] BX Sniper Team (Rusty)";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_BX_Sniper_Rusty";
						rank="SERGEANT";
						position[]={0,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_BX_Sniper_Rusty";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
				};
				class FST_BX_AntiTankTeam_Rusty
				{
					name="[41st] BX Anti-Tank Team (Rusty)";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_BX_AT_Rusty";
						rank="SERGEANT";
						position[]={0,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_BX_AT_Rusty";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
				};
				class FST_BX_AntiAirTeam_Rusty
				{
					name="[41st] BX Anti-Air Team (Rusty)";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_BX_AA_Rusty";
						rank="SERGEANT";
						position[]={0,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_BX_AA_Rusty";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
				};
				class FST_B2_Team
				{
					name="[41st] B2 Team";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_B2_TL";
						rank="SERGEANT";
						position[]={0,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_B2";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
				};
				class FST_B2_Squad
				{
					name="[41st] B2 Squad";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_B2_TL";
						rank="SERGEANT";
						position[]={0,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_B2";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_B2_TL";
						rank="SERGEANT";
						position[]={0,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_B2";
						rank="PRIVATE";
						position[]={1,-0,-0};
					};
				};
				class FST_U_CIS_Heavy_FireTeam
				{
					name="[41st] Human Division Fireteam";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_U_CIS_Heavy";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_U_CIS_Heavy";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_U_CIS_Heavy_AT";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_U_CIS_Heavy";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_U_CIS_Heavy";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_U_CIS_Heavy";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
				};
				class FST_U_CIS_Heavy_Squad
				{
					name="[41st] Human Division Squad";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_U_CIS_Heavy";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_U_CIS_Heavy";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_U_CIS_Heavy";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_U_CIS_Heavy_AT";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_U_CIS_Heavy";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_U_CIS_Heavy";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_U_CIS_Heavy";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_U_CIS_Heavy";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_U_CIS_Heavy_AT";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_U_CIS_Heavy";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_U_CIS_Heavy";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_U_CIS_Heavy";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
				class FST_Jorgetrooper_Squad
				{
					name="[41st] Brainwashed Clonetrooper Squad";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_Jorgetrooper";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_Jorgetrooper";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_Jorgetrooper";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_Jorgetrooper_AT";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_Jorgetrooper_AR";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_Jorgetrooper";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_Jorgetrooper";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_Jorgetrooper";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_Jorgetrooper_AT";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_Jorgetrooper_AR";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_Jorgetrooper";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_Jorgetrooper";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
				class FST_Zombie_Pack_Walker
				{
					name="[41st] Zombie Clonetrooper Walker Pack";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_41st_Walker";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_41st_Walker";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_41st_Walker";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_41st_Walker";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_41st_Walker";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_41st_Walker";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_41st_Walker";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_41st_Walker";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_41st_Walker";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_41st_Walker";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_41st_Walker";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_41st_Walker";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
				class FST_Zombie_Pack_Runner_Walker
				{
					name="[41st] Zombie Clonetrooper With Runners Pack";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_41st_Walker";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_41st_Runner";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_41st_Walker";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_41st_Runner";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_41st_Walker";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_41st_Runner";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_41st_Walker";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_41st_Runner";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_41st_Walker";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_41st_Runner";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_41st_Walker";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_41st_Runner";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
				class FST_Zombie_Pack_Runner
				{
					name="[41st] Zombie Clonetrooper  Runners Pack";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_41st_Runner";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_41st_Runner";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_41st_Runner";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_41st_Runner";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_41st_Runner";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_41st_Runner";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_41st_Runner";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_41st_Runner";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_41st_Runner";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_41st_Runner";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_41st_Runner";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_41st_Runner";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
				class FST_Tukata_Squad
				{
					name="[41st] Tukata PMC Squad";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_JMSLLTE_JinTrooper_armor_F";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_JMSLLTE_JinTrooper_armor_F";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_JMSLLTE_JinTrooper_armor_F";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_JMSLLTE_JinTrooper_armor_AT";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_JMSLLTE_JinTrooper_armor_AR";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_JMSLLTE_JinTrooper_armor_F";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_JMSLLTE_JinTrooper_armor_F";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_JMSLLTE_JinTrooper_armor_F";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_JMSLLTE_JinTrooper_armor_AT";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_JMSLLTE_JinTrooper_armor_AR";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_JMSLLTE_JinTrooper_armor_F";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_JMSLLTE_JinTrooper_armor_F";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
				class FST_Zombie_Pack_Runner_Tukata
				{
					name="[41st] Tukata Zombies Runners Pack";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_41st_Runner_Tukata";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_41st_Runner_Tukata";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_41st_Runner_Tukata";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_41st_Runner_Tukata";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_41st_Runner_Tukata";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_41st_Runner_Tukata";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_41st_Runner_Tukata";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_41st_Runner_Tukata";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_41st_Runner_Tukata";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_41st_Runner_Tukata";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_41st_Runner_Tukata";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_41st_Runner_Tukata";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
				class FST_Zombie_Pack_Runner_Walker_Tukata
				{
					name="[41st] Tukata Zombies With Runners Pack";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_41st_Runner_Tukata";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_41st_Runner_Tukata";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_41st_Runner_Tukata";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_41st_Runner_Tukata";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_41st_Runner_Tukata";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
				class FST_Zombie_Pack_Walker_Tukata
				{
					name="[41st] Tukata Zombies Walker Pack";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_41st_Walker_Tukata";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
			};
		};
	};
};
