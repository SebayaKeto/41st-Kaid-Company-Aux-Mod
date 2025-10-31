class CfgPatches
{
	class 41st_HumanDiv
	{
		requiredAddons[]={"A3_Soft_F"};
		units[]=
		{
			
			"FST_U_CIS_Heavy",
			"FST_U_CIS_Heavy_AT",
			"FST_U_CIS_Light",
			"FST_U_CIS_Light_Veteran",
		};
		weapons[]={};
	};
	author="Tooka";
};
class CfgEditorSubcategories
{
	class FST_HumanDiv
	{
		displayName = "Human Division"; 
	};
};
class CfgWeapons
{
	class U_I_CombatUniform;
	class Uniform_Base;
	class UniformItem;
	class VestItem;
	class Vest_Camo_Base;
	class FST_CIS_HolsterVest: Vest_Camo_Base
	{
		author="Tooka";
		scope=2;
		displayName="[41st] CIS Human Division Vest";
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
	class 3AS_CIS_Light_helmet;
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
	class JMSLLTE_Ofcap_helmet;
	class FST_OfficerCap_CIS: JMSLLTE_Ofcap_helmet
    {
        author = "Steel";
        displayname="[41st] CIS Officer Cap";
        hiddenSelections[]=
        {
            "camo"
        };
        hiddenSelectionsTextures[]=
        {
            "41st_Droids\Data\Extras\FST_OfficerCap_CIS.paa"
        };
    };
	class HeadgearItem;
	class JMSLLTE_ISB_helmet;
	class FST_CIS_StaffHelmet: JMSLLTE_ISB_helmet
	{
		scope=2;
		author="Tooka";
		displayName="[41st] CIS Base Staff Helmet";
		picture="\JMSLLTE_empire\helmets\data\ico\ico_h_isb.paa";
		model="JMSLLTE_empire_m\helmets\ISB_helmet.p3d";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\vests\data\isb_armor_co.paa"
		};
		class ItemInfo: HeadgearItem
		{
			mass=30;
			uniformmodel="JMSLLTE_empire_m\helmets\ISB_helmet.p3d";
			modelSides[]={6};
			hiddenSelections[]=
			{
				"Camo1"
			};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName="HitHead";
					armor=20;
				};
				class Neck
				{
					hitpointName="HitNeck";
					armor=20;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=20;
				};
			};
		};
	};
    class V_rebreatherB;
    class FST_HumanDiv_Pouches_Base: V_rebreatherB
    {
        author="Ruby";
        displayname="[41st] Human Divison Pouches Base"
        model="kobra\442_equipment\vests\model\clone\scout_pouches.p3d";
        scope=0;
		scopecurator=0;
		scopearsenal=0;
        JLTS_isDroid=0;
		allowedSlots[]={901};
		picture="\41st_Armor\Logo.paa";
        hiddenselections[]=
        {
            "pouch1",
            "pouch2",
            "pouch3"
        };
        class ItemInfo: vestitem
        {
            uniformmodel="kobra\442_equipment\vests\model\clone\scout_pouches.p3d";
			containerclass="Supply200";
			mass=80;
			vesttype="Rebreather";
            hiddenselections[]=
            {
                "pouch1",
                "pouch2",
                "pouch3"
            };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=1;
					PassThrough=0.1;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=0;
					PassThrough=0.1;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=0;
					passThrough=0.1;
				};
			};
        };
    };
    class FST_HumanDiv_Pouches: FST_HumanDiv_Pouches_Base
    {
        author="Ruby";
        displayname="[41st] CIS Ammo Bearer Pouches"
        scope=2;
		scopecurator=2;
		scopearsenal=2;
        hiddenselectionstextures[]=
        {
            "41st_Droids\Data\Extras\FST_Pouches_HumDiv.paa",
            "41st_Droids\Data\Extras\FST_Pouches_HumDiv.paa",
            "41st_Droids\Data\Extras\FST_Pouches_HumDiv.paa"
        };
    };
	class 3AS_V_Imperial_Stormtrooper_Bandolier_Belt;
	class FST_CIS_CQB_Vest: 3AS_V_Imperial_Stormtrooper_Bandolier_Belt
	{
		author="Tooka";
		scope=2;
		displayName="[41st] CIS Close Quarters Bandolier/Pouches";
		picture="3AS\3AS_Characters\Commando\data\UI\Katarn_Tech_Vest_Unmarked_UI_ca.paa";
		model="3AS\3AS_Characters_Imperial\Vests\Model\3AS_Stormtrooper_vest_addons.p3d";
		hiddenSelections[]=
		{
		"camo_pouldron",
		"camo_bandolier",
		"camo_mudguard",
		"camo_ammo_shoulder",
		"camo_ammo_belt"
		};
		hiddenSelectionsTextures[]=
		{
		"",
		"3AS\3AS_Characters_Imperial\Vests\Data\Bandolier\Bandolier_CO.paa",
		"",
		"",
		"3AS\3AS_Characters_Imperial\Vests\data\Ammo_Pack_Belt\Ammo_Pack_2_co.paa"
		};
		class ItemInfo: VestItem
		{
			uniformModel="3AS\3AS_Characters_Imperial\Vests\Model\3AS_Stormtrooper_vest_addons.p3d";
			hiddenSelections[]=
			{
				"camo_pouldron",
				"camo_bandolier",
				"camo_mudguard",
				"camo_ammo_shoulder",
				"camo_ammo_belt"
			};
			containerClass="Supply150";
			mass=10;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					hitPointName="HitChest";
					armor=20;
					passThrough=0.30000001;
				};
			};
		};
	};
	class 3AS_CIS_Grenadier_Vest;
	class FST_CIS_AmmoVest: 3AS_CIS_Grenadier_Vest
	{
		author="Tooka";
		displayName="[41st] CIS Ammo Bandolier";
		scope=2;
		class ItemInfo: VestItem
		{
			uniformModel="3AS\3AS_CIS_Infantry\Model\CIS_Grenadier_Vest.p3d";
			containerClass="Supply150";
			mass=10;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					hitPointName="HitChest";
					armor=10;
					passThrough=0.30000001;
				};
			};
		};
	};
	class ls_sob_commando_eod_vest;
	class FST_CIS_EODVest: ls_sob_commando_eod_vest
	{
		author="Tooka";
		scope=2;
		displayName="[41st] CIS EOD Vest";
		model="\ls\core\addons\characters_clone_legacy\vests\commando\ls_vest_clone_commando_eod.p3d";
		picture="\ls\core\addons\characters_clone_legacy\_ui\commando_eod_vest_ui_ca.paa";
		class ItemInfo: VestItem
		{
			uniformModel="\ls\core\addons\characters_clone_legacy\vests\commando\ls_vest_clone_commando_eod.p3d";
			containerClass="Supply150";
			mass=10;
		};
	};
	class JMSLLTE_IsbChest_CIS_armor;
	class FST_CIS_OfficerVestH: JMSLLTE_IsbChest_CIS_armor
	{
		author="Tooka";
		scope=2;
		displayName="[41st] CIS Officer Blasterproof Vest (Heavy)";
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\vests\data\isb_armor_CIS_co.paa"
		};
		class ItemInfo: VestItem
		{
			uniformmodel="\JMSLLTE_empire_m\vests\isb_chestArmor.p3d";
			containerClass="Supply150";
			mass=15;
			modelsides[]={6};
			hiddenSelections[]=
			{
				"Camo1"
			};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName="HitHead";
					armor=5;
					passThrough=0.1;
				};
				class Diaphragm
				{
					hitpointName="HitDiaphragm";
					armor=40;
					passThrough=0.40000001;
				};
				class Chest
				{
					hitpointName="HitChest";
					armor=40;
					passThrough=0.40000001;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=20;
					passThrough=0.40000001;
				};
				class Pelvis
				{
					hitpointName="HitPelvis";
					armor=20;
					passThrough=0.40000001;
				};
				class Neck
				{
					hitpointName="HitNeck";
					armor=6;
					passThrough=0.2;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=20;
					passThrough=0.2;
				};
				class Body
				{
					hitpointName="HitBody";
					passThrough=0.40000001;
				};
			};
		};
	};
	class JMSLLTE_IsbChestL_armor;
	class FST_CIS_OfficerVestL: JMSLLTE_IsbChestL_armor
	{
		author="Tooka";
		scope=2;
		displayName="[41st] CIS Officer Blasterproof Vest (Light)";
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\vests\data\isb_armor_CIS_co.paa"
		};
		class ItemInfo: VestItem
		{
			uniformmodel="\JMSLLTE_empire_m\vests\isb_chestArmorL.p3d";
			containerClass="Supply150";
			mass=15;
			modelsides[]={6};
			hiddenSelections[]=
			{
				"Camo1"
			};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName="HitHead";
					armor=1;
					passThrough=0.1;
				};
				class Diaphragm
				{
					hitpointName="HitDiaphragm";
					armor=30;
					passThrough=0.40000001;
				};
				class Chest
				{
					hitpointName="HitChest";
					armor=30;
					passThrough=0.40000001;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=10;
					passThrough=0.40000001;
				};
				class Pelvis
				{
					hitpointName="HitPelvis";
					armor=10;
					passThrough=0.40000001;
				};
				class Neck
				{
					hitpointName="HitNeck";
					armor=3;
					passThrough=0.2;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=2;
					passThrough=0.2;
				};
				class Body
				{
					hitpointName="HitBody";
					passThrough=0.40000001;
				};
			};
		};
	};
	class JMSLLTE_NavytrooperHolster_armor;
	class FST_CIS_NavyHolster: JMSLLTE_NavytrooperHolster_armor
	{
		author="Tooka";
		scope=2;
		displayName="[41st] CIS Navy Holster";
		class ItemInfo: VestItem
		{
			uniformmodel="\JMSLLTE_scum_m\vests\Navytrooper_holster.p3d";
			containerClass="Supply150";
			mass=2;
			modelsides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName="HitHead";
					armor=2;
					passThrough=0.1;
				};
				class Diaphragm
				{
					hitpointName="HitDiaphragm";
					armor=5;
					passThrough=0.40000001;
				};
				class Chest
				{
					hitpointName="HitChest";
					armor=5;
					passThrough=0.40000001;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=1;
					passThrough=0.40000001;
				};
				class Pelvis
				{
					hitpointName="HitPelvis";
					armor=5;
					passThrough=0.40000001;
				};
				class Neck
				{
					hitpointName="HitNeck";
					armor=0;
					passThrough=0.2;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=2;
					passThrough=0.2;
				};
				class Body
				{
					hitpointName="HitBody";
					passThrough=0.40000001;
				};
			};
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
		displayName="[41st] CIS Human Division Heavy Armor";
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
			mass=200;
		};
	};
	class 3AS_Uniform_CIS_Human_Base;
	class FST_U_CIS_Light_Armor: 3AS_Uniform_CIS_Human_Base
	{
		author="Gold";
		displayName="[41st] CIS Human Division Light Armor";
		scope=2;
		picture="\A3\characters_f\data\ui\icon_U_B_CombatUniform_mcam_ca.paa";
		model="3AS\3AS_CIS_Infantry\Model\CIS_Inf.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_U_CIS_Light";
			containerClass="Supply150";
			mass=100;
		};
	};
	class FST_U_CIS_Light_Armor_Veteran: FST_U_CIS_Light_Armor
	{
		author="Gold";
		displayName="[41st] CIS Human Division Light Armor (Veteran)";
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
			uniformClass="FST_U_CIS_Light_Veteran";
			containerClass="Supply150";
			mass=100;
		};
	};
	class 3AS_U_CIS_Medic_Armor;
	class FST_U_CIS_Medic_Armor: 3AS_U_CIS_Medic_Armor
	{
		author="Tooka";
		displayName="[41st] CIS Human Division Light Armor (Medic)";
		scope=2;
		picture="\A3\characters_f\data\ui\icon_U_B_CombatUniform_mcam_ca.paa";
		model="3AS\3AS_CIS_Infantry\Model\CIS_Inf.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_U_CIS_Medic";
			containerClass="Supply150";
			mass=100;
		};
	};
	class 3AS_U_CIS_Officer_Armor;
	class FST_U_CIS_Officer_Armor: 3AS_U_CIS_Officer_Armor
	{
		author="Tooka";
		displayName="[41st] CIS Human Division Light Armor (Officer)";
		scope=2;
		picture="\A3\characters_f\data\ui\icon_U_B_CombatUniform_mcam_ca.paa";
		model="3AS\3AS_CIS_Infantry\Model\CIS_Inf.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_U_CIS_Combat_Officer";
			containerClass="Supply150";
			mass=100;
		};
	};
	class JMSLLTE_EmpOfficer_CIS_F_CombatUniform;
	class FST_CIS_OfficerUnifoirm: JMSLLTE_EmpOfficer_CIS_F_CombatUniform
	{
		author="Tooka";
		scope=2;
		displayName="[41st] CIS Officer Uniform";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_CIS_OfficerBase";
			Armor=5;
			modelSides[]={6};
			containerClass="Supply150";
			mass=10;
		};
	};
	class JMSLLTE_EmpOfficer_CISs_F_CombatUniform;
	class FST_CIS_StandardUniform: JMSLLTE_EmpOfficer_CISs_F_CombatUniform
	{
		author="Tooka";
		scope=2;
		displayName="[41st] CIS Standard Uniform";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_CIS_StandardBase";
			Armor=5;
			modelSides[]={6};
			containerClass="Supply150";
			mass=10;
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
	class FST_Clone_Backpack_Invisible;
	class FST_Backpack_HumanDiv: FST_Clone_Backpack_Invisible
    {
        author = "Ruby";
        displayname = "[41st] CIS Human Divison Standard Backpack"
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
	class FST_CIS_Backpack_Invisible: FST_Clone_Backpack_Invisible
	{
		author = "Tooka";
		displayname = "[41st] CIS Human Division Invisible Backpack"
		maximumLoad = 400
		mass = 5
	};
    class FST_CIS_Drone_Backpack: FST_Clone_Backpack_Invisible
    {
        author = "Tooka";
        displayname = "[41st] CIS Human Division Drone Backpack"
        model = "3AS\3AS_Drones\H3NR1\model\3AS_H3NRI_Pack_F.p3d";
        picture = "\A3\Supplies_F_Orange\Bags\Data\UI\icon_C_IDAP_UAV_ca";
        maximumLoad = 250
        mass = 100
        hiddenSelectionsTextures[]=
        {
            "3AS\3AS_Drones\H3NR1\data\camo_h3_nr1_imp_co.paa"
        };
    }
    class 3AS_B_Imperial_Stormtrooper_Backpack_F;
    class FST_CIS_Engineer_Backpack: 3AS_B_Imperial_Stormtrooper_Backpack_F
	{
		author="Tooka";
		scope=2;
		displayName="[41st] CIS Human Division Engineer Backpack";
		picture="\3AS\3AS_Characters\Clones\Backpacks\Data\UI\Cold_Assault_Backpack_Unmarked_UI_ca.paa";
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Characters_Imperial\Backpacks\data\Stormtrooper_Backpack\Backpack_CO.paa"
		};
	};
    class 3AS_B_Imperial_Stormtrooper_Backpack_Medic_F;
    class FST_CIS_Medic_Backpack: 3AS_B_Imperial_Stormtrooper_Backpack_Medic_F
	{
		author="Tooka";
		displayName="[41st] CIS Human Division Medic Backpack";
		picture="\3AS\3AS_Characters\Clones\Backpacks\Data\UI\Cold_Assault_Backpack_Unmarked_UI_ca.paa";
		model="3AS\3AS_Characters_Imperial\Backpacks\model\3AS_Stormtrooper_Backpack_Medic.p3d";
		hiddenSelections[]=
		{
			"Camo",
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Characters_Imperial\Backpacks\data\Stormtrooper_Backpack\Backpack_CO.paa",
			"3as\3as_characters_imperial\backpacks\data\stormtrooper_backpack_medic\backpack_addons_co.paa"
		};
	};
	class 3AS_B_CloneBags_L_F;
	class FST_CIS_Officer_Legbag: 3AS_B_CloneBags_L_F
	{
		author="Tooka";
		scope=2;
		displayName="[41st] CIS Officer's Legbag";
		picture="\A3\Weapons_F\Ammoboxes\Bags\data\ui\backpack_CA.paa";
		model="\3AS\3AS_Republic_Characters\Backpacks\3AS_Clonetrooper_Bag_Left.p3d";
		maximumLoad=250;
		mass=5;
	};
	class ls_gar_beltBag_leg;
	class FST_CIS_HumanDiv_Legbag: ls_gar_beltBag_leg
	{
		author="Tooka";
		scope=2;
		displayName="[41st] CIS Trooper's Legbag";
		maximumLoad=250;
		mass=5;
		hiddenSelectionsTextures[]=
		{
			"",
			"\ls\core\addons\characters_clone_legacy\vests\common\bag\bag_co.paa"
		};
	};
	class ls_imperialBackpack_satchel;
	class FST_CIS_Marksman_Satchel: ls_imperialBackpack_satchel
	{
		scope=2;
		author="Tooka";
		displayName="[41st] CIS Marksman Satchel";
		model="\ls\core\addons\characters_imperial\equipment\satchel\ls_equipment_imperial_satchel.p3d";
		maximumLoad=250;
		mass=5;
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\characters_imperial\equipment\satchel\data\camo1_co.paa"
		};
		picture="\ls\core\addons\characters_imperial\data\ui\backpack_satchel_ui_ca.paa";
	};
	class ls_gar_rto_mini_backpack_night;
	class FST_CIS_RTO_Backpack: ls_gar_rto_mini_backpack_night
	{
		author="Tooka";
		scope=2;
		displayName="[41st] CIS Radio Pack";
		maximumLoad=250;
		mass=7;
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\characters_clone_legacy\backpacks\rto\data\main_night_co.paa",
			"\ls\core\addons\characters_clone_legacy\backpacks\rto\data\accumulator_night_co.paa"
		};
	};
	class O_Soldier_F;
	class JMSLLTE_h_ISB_headgear;
	class FST_CIS_BaseHelmet: JMSLLTE_h_ISB_headgear
	{
		scope=2;
		scopeCurator=2;
		uniformClass="FST_CIS_StaffHelmet";
		displayName="[41st] CIS Base Staff Helmet";
		class HitPoints: O_Soldier_F
		{
			class HitFace
			{
				armor=20;
				material=-1;
				name="face_hub";
				passThrough=1;
				explosionShielding=80;
				radius=0.08;
				minimalHit=0.0099999998;
			};
			class HitNeck: HitFace
			{
				armor=20;
				material=-1;
				name="neck";
				passThrough=1;
				explosionShielding=80;
				radius=0.1;
				minimalHit=0.0099999998;
			};
			class HitHead: HitNeck
			{
				armor=20;
				material=-1;
				name="head";
				passThrough=1;
				explosionShielding=80;
				radius=0.4;
				minimalHit=0.0099999998;
			};
			class HitPelvis: HitHead
			{
				armor=0;
				material=-1;
				name="pelvis";
				passThrough=0.80000001;
				radius=0;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="";
			};
			class HitAbdomen: HitPelvis
			{
				armor=0;
				material=-1;
				name="spine1";
				passThrough=0.80000001;
				radius=0;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor=0;
				material=-1;
				name="spine2";
				passThrough=0.33000001;
				radius=0;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitChest: HitDiaphragm
			{
				armor=0;
				material=-1;
				name="spine3";
				passThrough=0.33000001;
				radius=0;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitBody: HitChest
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
				armor=0;
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
				armor=0;
				material=-1;
				name="hands";
				passThrough=1;
				radius=0;
				explosionShielding=1;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="HitArms";
			};
			class HitLegs: HitHands
			{
				armor=0;
				material=-1;
				name="legs";
				passThrough=1;
				radius=0;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
				depends="0";
			};
			class HitLeftArm
			{
				armor=0;
				material=-1;
				name="hand_l";
				passThrough=1;
				radius=0;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
			};
			class HitRightArm: HitLeftArm
			{
				name="hand_r";
			};
			class HitLeftLeg
			{
				armor=0;
				material=-1;
				name="leg_l";
				passThrough=1;
				radius=0;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
			};
			class HitRightLeg: HitLeftLeg
			{
				name="leg_r";
			};
		};
		armor=10; 
		armorStructural=0.4;
		explosionshielding=45;
		class TransportItems
		{
			class FST_CIS_StaffHelmet
			{
				name="FST_CIS_StaffHelmet";
				count=1;
			};
		};
	};
	class FST_Droid_B1_E5;
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
				material=-1;
				name="face_hub";
				passThrough=0.80000001;
				radius=0.079999998;
				explosionShielding=0.1;
				minimalHit=0.0099999998;
			};
			class HitNeck: HitFace
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
				passThrough=0.33000001;
				radius=0.18000001;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitBody: HitChest
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
			class HitLeftArm
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
			class HitLeftLeg
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
		armor=25; 
		armorStructural=7;
		explosionshielding=45;
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
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_HumanDiv";
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
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_HumanDiv";
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
				material=-1;
				name="face_hub";
				passThrough=0.80000001;
				radius=0.079999998;
				explosionShielding=0.1;
				minimalHit=0.0099999998;
			};
			class HitNeck: HitFace
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
				passThrough=0.33000001;
				radius=0.18000001;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitBody: HitChest
			{
				armor=300;
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
			};
			class HitLeftArm
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
			class HitLeftLeg
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
		armor=14; 
		armorStructural=4;
		explosionshielding=20;
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
	class FST_U_CIS_Light_Veteran: FST_U_CIS_Light
	{
		author="Gold";
		displayName="[41st] CIS Human Division (Light/Veteran)";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_CIS_Light_Armor_Veteran";
		role="Rifleman";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\FST_Armor_HumDiv_Veteran.paa"
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
	class FST_U_CIS_Medic: 3AS_U_CIS_Light
	{
		author="Tooka";
		displayName="[41st] CIS Human Division (Medic)";
		scope=2;
		uniformClass="FST_U_CIS_Medic_Armor";
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_CIS_Infantry\data\cis_inf_medic_texture_armour_co.paa"
		};
	};
	class FST_U_CIS_Combat_Officer: 3AS_U_CIS_Light
	{
		author="Tooka";
		displayName="[41st] CIS Human Division (Officer)";
		scope=2;
		uniformClass="FST_U_CIS_Officer_Armor";
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_CIS_Infantry\data\cis_inf_officer_texture_armour_co.paa"
		};
	};
	class JMSLLTE_EmpOfficer_black_F;
	class FST_CIS_OfficerBase: JMSLLTE_EmpOfficer_black_F
	{
		author="Tooka";
		scope=2;
		modelSides[]={6};
		model="\JMSLLTE_empire_m\officer.p3d";
		nakedUniform="U_BasicBody";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\of_body_CIS_co.paa"
		};
	};
	class FST_CIS_StandardBase: JMSLLTE_EmpOfficer_black_F
	{
		author="Tooka";
		scope=2;
		modelSides[]={6};
		model="\JMSLLTE_empire_m\officer.p3d";
		nakedUniform="U_BasicBody";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\of_body_CISs_co.paa"
		};
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
			};
		};
	};
};