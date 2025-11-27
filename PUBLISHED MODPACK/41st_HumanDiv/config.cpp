class CfgPatches
{
	class 41st_HumanDiv
	{
		requiredAddons[]={"A3_Soft_F"};
		units[]=
		{
			
			"FST_U_CIS_Heavy",
			"FST_CIS_HumanDiv_Auto",
			"FST_CIS_HumanDiv_AT",
			"FST_CIS_HumanDiv_AA",
			"FST_CIS_HumanDiv_Standard",
			"FST_CIS_HumanDiv_AmmoB",
			"FST_CIS_HumanDiv_RTO",
			"FST_CIS_HumanDiv_CQC",
			"FST_CIS_HumanDiv_Gren",
			"FST_CIS_HumanDiv_Mark",
			"FST_CIS_HumanDiv_EOD",
			"FST_CIS_HumanDiv_DroneOp",
			"FST_CIS_HumanDiv_Medic",
			"FST_CIS_HumanDiv_Officer",
			"FST_HumanDiv_NOfficer",
			"FST_HumanDiv_BComm",
			"FST_HumanDiv_NCaptain",
			"FST_HumanDiv_BStaff",
			"FST_HumanDiv_NPerson",
			"FST_HumanDiv_NEngi"
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
class CfgMagazines
{
	class IDA_grenade_Smoke_mag;
	class FST_grenade_smoke_orange_mag: IDA_grenade_Smoke_mag
	{
		scope=2;
		author="Tooka";
		displayName="[41st] Smoke Canister (Orange)";
		descriptionShort="Smoke Canister (Orange)";
		displayNameShort="Orange Smoke";
		model="\Indecisive_Armoury_Ammos\Data\Smoke\IDA_smoke_grenade.p3d";
		ammo="FST_smoke_Orange";
	};
};
class CfgAmmo
{
	class IDA_smoke;
	class FST_smoke_Orange: IDA_smoke
	{
		smokeColor[]={1,0.45,0.1,1};
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
	class FST_CIS_HolsterVest_Medic: FST_CIS_HolsterVest
	{
		author="Tooka";
		scope=1;
		displayName="[41st] CIS Human Division Vest (Medic)";
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
			containerClass="Supply200";
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
					armor=70;
					passThrough=1;
				};
				class Neck
				{
					hitpointName="HitNeck";
					armor=70;
					passThrough=1;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=70;
					passThrough=1;
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
	class JMSLLTE_StormtrooperHolster_armor;
	class FST_CIS_CaptainHolster: JMSLLTE_StormtrooperHolster_armor
	{
		author="Tooka";
		scope=2;
		displayName="[41st] CIS Captain Holster";
		picture="\JMSLLTE_empire\vests\ico\ico_v_storm.paa";
		model="\JMSLLTE_empire_m\vests\StormtroperHolster.p3d";
		class ItemInfo: VestItem
		{
			uniformmodel="\JMSLLTE_empire_m\vests\StormtroperHolster.p3d";
			containerClass="Supply100";
			mass=20;
			modelsides[]={6};
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
					armor=15;
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
					armor=5;
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
	class FST_U_CIS_Medic_Armor: FST_U_CIS_Light_Armor
	{
		author="Tooka";
		displayName="[41st] CIS Human Division Light Armor (Medic)";
		scope=2;
		picture="\A3\characters_f\data\ui\icon_U_B_CombatUniform_mcam_ca.paa";
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_CIS_Infantry\data\cis_inf_medic_texture_armour_co.paa"
		};
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_U_CIS_Medic";
			containerClass="Supply150";
			mass=100;
		};
	};
	class FST_U_CIS_Officer_Armor: FST_U_CIS_Light_Armor
	{
		author="Tooka";
		displayName="[41st] CIS Human Division Light Armor (Officer)";
		scope=2;
		picture="\A3\characters_f\data\ui\icon_U_B_CombatUniform_mcam_ca.paa";
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_CIS_Infantry\data\cis_inf_officer_texture_armour_co.paa"
		};
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
			uniformClass="FST_CIS_OfficerUniformBase";
			Armor=5;
			modelSides[]={6};
			containerClass="Supply150";
			mass=10;
		};
	};
	class FST_CIS_OfficerUniformCommander: FST_CIS_OfficerUnifoirm
	{
		author="Tooka";
		scope=2;
		scopeCurator=2;
		scopeArsenal=0;
		displayName="[41st] CIS Officer Uniform (Base Commander)";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_HumanDiv_BComm";
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
			uniformClass="FST_CIS_StandardUniformBase";
			Armor=5;
			modelSides[]={6};
			containerClass="Supply150";
			mass=10;
		};
	};
	class FST_CIS_BaseStaffArmor: FST_CIS_StandardUniform
	{
		author="Tooka";
		scope=2;
		scopeCurator=2;
		scopeArsenal=0;
		displayName="[41st] CIS Standard Uniform (Base Staff)";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_HumanDiv_BStaff";
			Armor=5;
			modelSides[]={6};
			containerClass="Supply150";
			mass=10;
		};
	};
	class FST_ValD;
	class FST_ValD_Standard: FST_ValD
	{
		scope=1;
		class linkedItems
		{
			class Optic
			{
				slot="CowsSlot";
				item="DBA_MRCO_B";
			};
		};
	};
	class FST_Maalras_SMG;
	class FST_Maalras_SMG_Standard: FST_Maalras_SMG
	{
		scope=1;
		class linkedItems
		{
			class Optic
			{
				slot="CowsSlot";
				item="DBA_MRCO_B";
			};
		};
	};
	class FST_SE14R;
	class FST_SE14R_Opticed: FST_SE14R
	{
		scope=1;
		class linkedItems
		{
			class Optic
			{
				slot="CowsSlot";
				item="3AS_Imp_Optic_SE14R";
			};
		};
	};
	class FST_ZH73_MK2;
	class FST_ZK73_Standard: FST_ZH73_MK2
	{
		scope=1;
		class linkedItems
		{
			class Optic
			{
				slot="CowsSlot";
				item="ls_cows_zh73_scope";
			};
		};
	};
	class FST_Cinnagaran_Carbine;
	class FST_CC_Standard: FST_Cinnagaran_Carbine
	{
		scope=1;
		class linkedItems
		{
			class Pointer
			{
				slot="PointerSlot";
				item="3AS_Flashlight_Cinnagaran_1_F";
			};
		};
	};
	class GrenadeLauncher;
	class Throw: GrenadeLauncher
	{
		muzzles[]+=
		{
			"FST_grenade_Smoke_Orange_muzzle",
		};
		class ThrowMuzzle;
		class FST_grenade_Smoke_Orange_muzzle: ThrowMuzzle
		{
			magazines[]=
			{
				"FST_grenade_smoke_orange_mag"
			};
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
	class Vest_Base_F;
	class FST_HumanDiv_BasicVest: Vest_Base_F
	{
		scope=1;
		displayName="[41st] CIS Human Division Vest";
		uniformClass="FST_CIS_HolsterVest";
		class TransportWeapons
		{
			class _xx_IDA_VibroKnife
			{
				weapon="IDA_VibroKnife";
				count=1;
			};
		};
		class TransportItems
		{
			class _xx_IDA_BactaBandage
			{
				name="IDA_BactaBandage";
				count=10;
			};
			class _xx_IDA_BattleStim
			{
				name="IDA_BattleStim";
				count=2;
			};
			class _xx_ACE_splint
			{
				name="ACE_splint";
				count=2;
			};
			class _xx_ACE_touniquet
			{
				name="ACE_touniquet";
				count=2;
			};
		};
	};
	class FST_HumDivBack_Standard: FST_CIS_Backpack_Invisible
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportWeapons
		{
			class _xx_IDA_VibroKnife
			{
				weapon="IDA_VibroKnife";
				count=1;
			};
		};
		class TransportItems
		{
			class _xx_ACE_Chemlight_HiRed
			{
				name="ACE_Chemlight_HiRed";
				count=1;
			};
			class _xx_FST_grenade_smoke_orange_mag
			{
				name="FST_grenade_smoke_orange_mag";
				count=1;
			};
			class _xx_FST_blaster_cell_Red
			{
				name="FST_blaster_cell_Red";
				count=15;
			};
			class _xx_FST_blaster_cell_low_Red
			{
				name="FST_blaster_cell_low_Red";
				count=15;
			};
		};
	};
	class FST_CISCloneAmmoPack:FST_Backpack_HumanDiv
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_FST_blaster_cell_High_Blue
			{
				name="FST_blaster_cell_High_Blue";
				count=5;
			};
			class _xx_FST_blaster_scatter_cell_DP23_Blue
			{
				name="FST_blaster_scatter_cell_DP23_Blue";
				count=5;
			};
			class _xx_FST_blaster_cell_Blue
			{
				name="FST_blaster_cell_Blue";
				count=5;
			};
			class _xx_FST_blaster_cell_low_Blue
			{
				name="FST_blaster_cell_low_Blue";
				count=5;
			};
			class _xx_FST_blaster_battery_Blue
			{
				name="FST_blaster_battery_Blue";
				count=1;
			};
			class _xx_FST_blaster_battery_DC15L_Blue
			{
				name="FST_blaster_cell_DC15L_Blue";
				count=1;
			};
			class _xx_FST_thermal_coil_LP_Blue
			{
				name="FST_thermal_coil_LP_Blue";
				count=1;
			};
			class _xx_FST_blaster_cell_LE_Blue
			{
				name="FST_blaster_cell_LE_Blue";
				count=1;
			};
		};
	};
	class FST_HumDivBack_EOD:FST_Backpack_HumanDiv
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_FST_blaster_cell_Red
			{
				name="FST_blaster_cell_Red";
				count=15;
			};
			class _xx_FST_blaster_cell_low_Red
			{
				name="FST_blaster_cell_low_Red";
				count=15;
			};
			class _xx_JMSLLTE_Detonitecharge_imp_Mag
			{
				name="JMSLLTE_Detonitecharge_imp_Mag";
				count=3;
			};
			class _xx_APERSTripMine_Wire_Mag
			{
				name="APERSTripMine_Wire_Mag";
				count=3;
			};
			class _xx_APERSMine_Range_Mag
			{
				name="APERSMine_Range_Mag";
				count=3;
			};
			class _xx_ACE_Chemlight_HiRed
			{
				name="ACE_Chemlight_HiRed";
				count=1;
			};
			class _xx_FST_grenade_smoke_orange_mag
			{
				name="FST_grenade_smoke_orange_mag";
				count=1;
			};
		};
	};
	class FST_HumDivBack_Auto: FST_CIS_HumanDiv_Legbag
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_FST_blaster_battery_Red
			{
				name="FST_blaster_battery_Red";
				count=5;
			};
			class _xx_FST_blaster_cell_low_Red
			{
				name="FST_blaster_cell_low_Red";
				count=15;
			};
		};
	};
	class FST_HumDivBack_CQC: FST_CIS_HumanDiv_Legbag
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_FST_blaster_scatter_cell_SBB3_Red
			{
				name="FST_blaster_scatter_cell_SBB3_Red";
				count=15;
			};
			class _xx_IDA_grenade_Sonic_mag
			{
				name="IDA_grenade_Sonic_mag";
				count=4;
			};
			class _xx_ACE_Chemlight_HiRed
			{
				name="ACE_Chemlight_HiRed";
				count=1;
			};
			class _xx_FST_grenade_smoke_orange_mag
			{
				name="FST_grenade_smoke_orange_mag";
				count=4;
			};
			class _xx_IDA_grenade_Detonator_mag
			{
				name="IDA_grenade_Detonator_mag";
				count=2;
			};
		};
	};
	class FST_HumDivBack_Gren: FST_CIS_HumanDiv_Legbag
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_FST_ZH73_Mag_Red
			{
				name="FST_ZH73_Mag_Red";
				count=10;
			};
			class _xx_FST_blaster_cell_low_Red
			{
				name="FST_blaster_cell_low_Red";
				count=15;
			};
			class _xx_FST_thermal_slug_mag_Red
			{
				name="FST_thermal_slug_mag_Red";
				count=4;
			};
			class _xx_FST_HE_LauncherGrenade
			{
				name="FST_HE_LauncherGrenade";
				count=1;
			};
		};
	};
	class FST_HumDivBack_AT: FST_CIS_Backpack_Invisible
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_ACE_Chemlight_HiRed
			{
				name="ACE_Chemlight_HiRed";
				count=1;
			};
			class _xx_FST_grenade_smoke_orange_mag
			{
				name="FST_grenade_smoke_orange_mag";
				count=1;
			};
			class _xx_FST_blaster_cell_Red
			{
				name="FST_blaster_cell_Red";
				count=15;
			};
			class _xx_FST_blaster_cell_low_Red
			{
				name="FST_blaster_cell_low_Red";
				count=15;
			};
			class _xx_FST_RPS6_rocket
			{
				name="FST_RPS6_rocket";
				count=2;
			};
		};
	};
	class FST_HumDivBack_AA: FST_CIS_Backpack_Invisible
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_ACE_Chemlight_HiRed
			{
				name="ACE_Chemlight_HiRed";
				count=1;
			};
			class _xx_FST_grenade_smoke_orange_mag
			{
				name="FST_grenade_smoke_orange_mag";
				count=1;
			};
			class _xx_FST_blaster_cell_Red
			{
				name="FST_blaster_cell_Red";
				count=15;
			};
			class _xx_FST_blaster_cell_low_Red
			{
				name="FST_blaster_cell_low_Red";
				count=15;
			};
			class _xx_FST_E60R_AA_mag
			{
				name="FST_E60R_AA_mag";
				count=2;
			};
		};
	};
	class FST_HumDivBack_Radio: FST_CIS_RTO_Backpack
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_ACE_Chemlight_HiRed
			{
				name="ACE_Chemlight_HiRed";
				count=1;
			};
			class _xx_FST_grenade_smoke_orange_mag
			{
				name="FST_grenade_smoke_orange_mag";
				count=1;
			};
			class _xx_FST_blaster_cell_Red
			{
				name="FST_blaster_cell_Red";
				count=15;
			};
			class _xx_FST_blaster_cell_low_Red
			{
				name="FST_blaster_cell_low_Red";
				count=15;
			};
		};
	};
	class FST_HumDivBack_Medic: FST_CIS_Medic_Backpack
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportWeapons
		{
			class _xx_IDA_VibroKnife
			{
				weapon="IDA_VibroKnife";
				count=1;
			};
		};
		class TransportItems
		{
			class _xx_IDA_BactaBandage
			{
				name="IDA_BactaBandage";
				count=20;
			};
			class _xx_IDA_BattleStim
			{
				name="IDA_BattleStim";
				count=5;
			};
			class _xx_ACE_splint
			{
				name="ACE_splint";
				count=5;
			};
			class _xx_ACE_touniquet
			{
				name="ACE_touniquet";
				count=5;
			};
			class _xx_ACE_bloodIV
			{
				name="ACE_bloodIV";
				count=2;
			};
			class _xx_ACE_bloodIV_500
			{
				name="ACE_bloodIV_500";
				count=1;
			};
			class _xx_ACE_plasmaIV
			{
				name="ACE_plasmaIV";
				count=1;
			};
			class _xx_ACE_plasmaIV_500
			{
				name="ACE_plasmaIV_500";
				count=1;
			};
			class _xx_FST_Bacta_Tank
			{
				name="FST_Bacta_Tank";
				count=1;
			};
			class _xx_IDA_Cauterizer
			{
				name="IDA_Cauterizer";
				count=1;
			};
		};
	};
	class FST_HumDivBack_Mark: FST_CIS_Marksman_Satchel
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_ACE_Chemlight_HiRed
			{
				name="ACE_Chemlight_HiRed";
				count=1;
			};
			class _xx_FST_grenade_smoke_orange_mag
			{
				name="FST_grenade_smoke_orange_mag";
				count=1;
			};
			class _xx_FST_Droid_blaster_cell_Overcharged_Red
			{
				name="FST_Droid_blaster_cell_Overcharged_Red";
				count=15;
			};
			class _xx_FST_blaster_cell_low_Red
			{
				name="FST_blaster_cell_low_Red";
				count=15;
			};
		};
	};
	class FST_HumDivBack_DroneOp: FST_CIS_Drone_Backpack
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_ACE_Chemlight_HiRed
			{
				name="ACE_Chemlight_HiRed";
				count=1;
			};
			class _xx_FST_grenade_smoke_orange_mag
			{
				name="FST_grenade_smoke_orange_mag";
				count=1;
			};
			class _xx_FST_blaster_cell_Red
			{
				name="FST_blaster_cell_Red";
				count=15;
			};
			class _xx_FST_blaster_cell_low_Red
			{
				name="FST_blaster_cell_low_Red";
				count=15;
			};
		};
	};
	class FST_HumDivBack_BStaff: FST_CIS_Officer_Legbag
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_ACE_Chemlight_HiRed
			{
				name="ACE_Chemlight_HiRed";
				count=1;
			};
			class _xx_FST_grenade_smoke_orange_mag
			{
				name="FST_grenade_smoke_orange_mag";
				count=1;
			};
			class _xx_FST_blaster_cell_Red
			{
				name="FST_blaster_cell_Red";
				count=15;
			};
			class _xx_FST_blaster_cell_low_Red
			{
				name="FST_blaster_cell_low_Red";
				count=15;
			};
		};
	};
	class FST_HumDivBack_Navy: FST_CIS_Officer_Legbag
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_IDA_grenade_Sonic_mag
			{
				name="IDA_grenade_Sonic_mag";
				count=1;
			};
			class _xx_FST_grenade_smoke_orange_mag
			{
				name="FST_grenade_smoke_orange_mag";
				count=1;
			};
			class _xx_FST_blaster_cell_Red
			{
				name="FST_blaster_cell_Red";
				count=15;
			};
			class _xx_FST_blaster_cell_low_Red
			{
				name="FST_blaster_cell_low_Red";
				count=15;
			};
		};
	};
	class FST_HumDivBack_NCap: FST_CIS_Officer_Legbag
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_IDA_grenade_Sonic_mag
			{
				name="IDA_grenade_Sonic_mag";
				count=1;
			};
			class _xx_FST_grenade_smoke_orange_mag
			{
				name="FST_grenade_smoke_orange_mag";
				count=1;
			};
			class _xx_FST_blaster_cell_low_Red
			{
				name="FST_blaster_cell_low_Red";
				count=15;
			};
			class _xx_41st_Food_CakeSlice
			{
				name="41st_Food_CakeSlice";
				count=1;
			};
			class _xx_41st_Food_Crayons
			{
				name="41st_Food_Crayons";
				count=1;
			};
		};
	};
	class FST_HumDivBack_BComm: FST_CIS_Officer_Legbag
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_IDA_grenade_Sonic_mag
			{
				name="IDA_grenade_Sonic_mag";
				count=1;
			};
			class _xx_FST_grenade_smoke_orange_mag
			{
				name="FST_grenade_smoke_orange_mag";
				count=1;
			};
			class _xx_FST_blaster_cell_low_Red
			{
				name="FST_blaster_cell_low_Red";
				count=15;
			};
			class _xx_ACE_Banana
			{
				name="ACE_Banana";
				count=1;
			};
		};
	};
	class FST_HumDivBack_Engi: FST_CIS_Engineer_Backpack
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_Toolkit
			{
				name="Toolkit";
				count=1;
			};
			class _xx_IDA_grenade_Sonic_mag
			{
				name="IDA_grenade_Sonic_mag";
				count=1;
			};
			class _xx_FST_grenade_smoke_orange_mag
			{
				name="FST_grenade_smoke_orange_mag";
				count=1;
			};
			class _xx_FST_blaster_cell_Red
			{
				name="FST_blaster_cell_Red";
				count=15;
			};
			class _xx_FST_blaster_cell_low_Red
			{
				name="FST_blaster_cell_low_Red";
				count=15;
			};
			class _xx_ACE_SpraypaintRed
			{
				name="ACE_SpraypaintRed";
				count=1;
			};
			class _xx_ACE_SpraypaintYellow
			{
				name="ACE_SpraypaintYellow";
				count=1;
			};
		};
	};
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
				armor=50;
				material=-1;
				name="face_hub";
				passThrough=0;
				explosionShielding=80;
				radius=0.08;
				minimalHit=0;
			};
			class HitNeck: HitFace
			{
				armor=50;
				material=-1;
				name="neck";
				passThrough=0;
				explosionShielding=80;
				radius=0.1;
				minimalHit=0;
			};
			class HitHead: HitNeck
			{
				armor=50;
				material=-1;
				name="head";
				passThrough=0;
				explosionShielding=80;
				radius=0.4;
				minimalHit=0;
			};
			class HitPelvis: HitHead
			{
				armor=0;
				material=-1;
				name="pelvis";
				passThrough=1;
				radius=0;
				explosionShielding=0;
				visual="injury_body";
				minimalHit=0;
				depends="";
			};
			class HitAbdomen: HitPelvis
			{
				name="spine1";
				visual="injury_body";
			};
			class HitDiaphragm: HitAbdomen
			{
				name="spine2";
				visual="injury_body";
			};
			class HitChest: HitDiaphragm
			{
				name="spine3";
				visual="injury_body";
			};
			class HitBody: HitChest
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=0;
				radius=0;
				explosionShielding=0;
				visual="injury_body";
				minimalHit=0
				depends="HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
			};
			class HitArms: HitBody
			{
				armor=0;
				passThrough=1;
				name="arms";
				visual="injury_hands";
				depends="0";
			};
			class HitHands: HitArms
			{
				name="hands";
				visual="injury_hands";
				depends="HitArms";
			};
			class HitLegs: HitHands
			{
				name="legs";
				visual="injury_legs";
			};
			class HitLeftArm
			{
				armor=0;
				material=-1;
				name="hand_l";
				passThrough=0;
				radius=0;
				explosionShielding=0;
				visual="injury_hands";
				minimalHit=0;
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
				passThrough=0;
				radius=0;
				explosionShielding=0;
				visual="injury_legs";
				minimalHit=0;
			};
			class HitRightLeg: HitLeftLeg
			{
				name="leg_r";
			};
		};
		armor=10; 
		armorStructural=10;
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
		author="Tooka";
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
			"G_NATO_default"
		};
		faceType="Man_A3";
		backpack="";
		side=0;
		faction="FST_BattleDroids_Faction";
		genericNames="NATOMen";
		vehiclesClass="Men";
		editorSubcategory="FST_HumanDiv";
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
				passThrough=0.9;
				radius=0.08;
				explosionShielding=0.1;
				minimalHit=0;
			};
			class HitNeck: HitFace
			{
				armor=1;
				material=-1;
				name="neck";
				passThrough=0.9;
				radius=0.08;
				explosionShielding=0.5;
				minimalHit=0;
			};
			class HitHead: HitNeck
			{
				armor=6;
				material=-1;
				name="head";
				passThrough=0.5;
				radius=0.12;
				explosionShielding=0.5;
				minimalHit=0.002;
				depends="HitFace max HitNeck";
			};
			class HitPelvis
			{
				armor=6;
				material=-1;
				name="pelvis";
				passThrough=0.9;
				radius=0.3;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.005;
			};
			class HitAbdomen
			{
				armor=7;
				material=-1;
				name="spine1";
				passThrough=0.8;
				radius=0.2;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.005;
			};
			class HitDiaphragm
			{
				armor=8;
				material=-1;
				name="spine2";
				passThrough=0.7;
				radius=0.2;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.009;
			};
			class HitChest
			{
				armor=8;
				material=-1;
				name="spine3";
				passThrough=0.7;
				radius=0.18;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.009;
			};
			class HitBody
			{
				armor=6;
				material=-1;
				name="body";
				passThrough=0.99;
				radius=0;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0;
				depends="HitPelvis max HitAbdomen max HitDiaphragm max HitChest max HitLeftArm max HitRightArm max HitLeftLeg max HitRightLeg";
			};
			class HitArms: HitBody
			{
				armor=1;
				material=-1;
				name="arms";
				passThrough=1;
				radius=0;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.009;
				depends="0";
			};
			class HitHands: HitArms
			{
				armor=1;
				material=-1;
				name="hands";
				passThrough=1;
				radius=0;
				explosionShielding=1;
				visual="injury_hands";
				minimalHit=0.009;
				depends="HitArms";
			};
			class HitLegs: HitHands
			{
				armor=1;
				material=-1;
				name="legs";
				passThrough=1;
				radius=0.13;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.009;
				depends="0";
			};
			class HitLeftArm
			{
				armor=1;
				material=-1;
				name="hand_l";
				passThrough=1;
				radius=0;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.009;
			};
			class HitRightArm: HitLeftArm
			{
				name="hand_r";
			};
			class HitLeftLeg
			{
				armor=1;
				material=-1;
				name="leg_l";
				passThrough=1;
				radius=0.06;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.009;
			};
			class HitRightLeg: HitLeftLeg
			{
				name="leg_r";
			};
		};
		armor=8; 
		armorStructural=12;
		explosionshielding=45;
		ace_medical_allowDamage = 0;
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
            "Throw",
			"Put"
        };
		Items[]={};
		respawnItems[]={};
		linkedItems[]={};
		respawnLinkedItems[]={};
		magazines[]={};
		respawnMagazines[]={};
	};
	class FST_U_CIS_Heavy: FST_CIS_Heavy_Base_F
	{
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=1;
		scopecurator=1;
		displayName="[41st] CIS Human Division (Obsolete Retired Class)"; //Keep around as most custom NPCs use this as their base still
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_CIS_Heavy_Armor";
		role="Rifleman";
		backpack="FST_HumDivBack_Auto";
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
	};
	class FST_CIS_HumanDiv_Auto: FST_CIS_Heavy_Base_F
	{
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopeCurator=2;
		displayName="[41st] CIS Human Division (Autorifleman)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_CIS_Heavy_Armor";
		role="Rifleman";
		backpack="FST_HumDivBack_Auto";
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
		weapons[]=
		{
			"FST_M41",
			"FST_SE14R",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_50",
			"JLTS_intel_datapad_civ",
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"FST_CIS_AmmoVest",
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_2",
			"3AS_CIS_Light_helmet"
		};
		magazines[]=
		{
			"FST_blaster_battery_Red",
			"FST_blaster_cell_low_Red",
			"ACE_Chemlight_HiRed",
			"FST_grenade_smoke_orange_mag"
		};
		class EventHandlers
		{
			init="private _u = _this select 0; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'IDA_VibroKnife'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Human Division Autorifleman'; _unit suppressFor 999; [_unit, 0.2, 'body', 'stab'] call ace_medical_fnc_addDamageToUnit;}; _u setSkill ['aimingAccuracy',0.45]; _u setSkill ['aimingShake',0.55]; _u setSkill ['aimingSpeed',0.65]; _u setSkill ['spotDistance',0.7]; _u setSkill ['spotTime',0.7]; _u setSkill ['courage',0.8]; _u setSkill ['commanding',0.5]; _u setSkill ['reloadSpeed',0.7]; _u setSkill ['general',0.7];";
		};
	};
	class FST_CIS_HumanDiv_AT: FST_CIS_Heavy_Base_F
	{
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopeCurator=2;
		displayName="[41st] CIS Human Division (AT)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_CIS_Heavy_Armor";
		role="Rifleman";
		backpack="FST_HumDivBack_AT";
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
		weapons[]=
		{
			"FST_ValD_Standard",
			"FST_SE14R",
			"FST_RPS6HP",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_50",
			"JLTS_intel_datapad_civ",
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"FST_CIS_HolsterVest",
			"3AS_G_AT_4_F",
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_2",
			"3AS_CIS_Light_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Red",
			"FST_blaster_cell_low_Red",
			"FST_RPS6_rocket"
		};
		class EventHandlers
		{
			init="private _u = _this select 0; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'IDA_VibroKnife'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Human Division Antitank'; [_unit, 0.2, 'body', 'stab'] call ace_medical_fnc_addDamageToUnit;}; _u setSkill ['aimingAccuracy',0.6]; _u setSkill ['aimingShake',0.6]; _u setSkill ['aimingSpeed',0.65]; _u setSkill ['spotDistance',0.7]; _u setSkill ['spotTime',0.7]; _u setSkill ['courage',0.7]; _u setSkill ['commanding',0.5]; _u setSkill ['reloadSpeed',0.7]; _u setSkill ['general',0.7];";
		};
	};
	class FST_CIS_HumanDiv_AA: FST_CIS_Heavy_Base_F
	{
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopeCurator=2;
		displayName="[41st] CIS Human Division (AA)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_CIS_Heavy_Armor";
		role="Rifleman";
		backpack="FST_HumDivBack_AA";
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
		weapons[]=
		{
			"FST_ValD_Standard",
			"FST_SE14R",
			"FST_E60R_AA",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_50",
			"JLTS_intel_datapad_civ",
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"FST_CIS_HolsterVest",
			"3AS_G_AT_4_F",
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_2",
			"3AS_CIS_Light_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Red",
			"FST_blaster_cell_low_Red",
			"FST_E60R_AA_mag"
		};
		class EventHandlers
		{
			init="private _u = _this select 0; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'IDA_VibroKnife'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Human Division Antiair'; [_unit, 0.2, 'body', 'stab'] call ace_medical_fnc_addDamageToUnit;}; _u setSkill ['aimingAccuracy',0.55]; _u setSkill ['aimingShake',0.6]; _u setSkill ['aimingSpeed',0.65]; _u setSkill ['spotDistance',0.8]; _u setSkill ['spotTime',0.8]; _u setSkill ['courage',0.75]; _u setSkill ['commanding',0.5]; _u setSkill ['reloadSpeed',0.7]; _u setSkill ['general',0.7];";
		};
	};
	class O_soldier_base_F;
	class FST_U_CIS_Light: FST_Droid_B1_E5
	{
		author="Gold + Tooka";
		displayName="[41st] CIS Human Division (Light)";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=1;
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_CIS_Light_Armor";
		role="Rifleman";
		identityTypes[]={};
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
		class HitPoints
		{
			class HitFace
			{
				armor=1;
				material=-1;
				name="face_hub";
				passThrough=0.9;
				radius=0.08;
				explosionShielding=0.1;
				minimalHit=0;
			};
			class HitNeck: HitFace
			{
				armor=1;
				material=-1;
				name="neck";
				passThrough=0.9;
				radius=0.08;
				explosionShielding=0.5;
				minimalHit=0;
			};
			class HitHead: HitNeck
			{
				armor=6;
				material=-1;
				name="head";
				passThrough=0.5;
				radius=0.12;
				explosionShielding=0.5;
				minimalHit=0.002;
				depends="HitFace max HitNeck";
			};
			class HitPelvis
			{
				armor=6;
				material=-1;
				name="pelvis";
				passThrough=0.9;
				radius=0.3;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.005;
			};
			class HitAbdomen
			{
				armor=7;
				material=-1;
				name="spine1";
				passThrough=0.8;
				radius=0.2;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.005;
			};
			class HitDiaphragm
			{
				armor=7;
				material=-1;
				name="spine2";
				passThrough=0.7;
				radius=0.2;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.009;
			};
			class HitChest
			{
				armor=7;
				material=-1;
				name="spine3";
				passThrough=0.7;
				radius=0.18;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.009;
			};
			class HitBody
			{
				armor=15;
				material=-1;
				name="body";
				passThrough=0.99;
				radius=0;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0;
				depends="HitPelvis max HitAbdomen max HitDiaphragm max HitChest max HitLeftArm max HitRightArm max HitLeftLeg max HitRightLeg";
			};
			class HitArms: HitBody
			{
				armor=6;
				material=-1;
				name="arms";
				passThrough=0.99;
				radius=0;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.009;
				depends="0";
			};
			class HitHands: HitArms
			{
				armor=6;
				material=-1;
				name="hands";
				passThrough=1;
				radius=0;
				explosionShielding=1;
				visual="injury_hands";
				minimalHit=0.009;
				depends="HitArms";
			};
			class HitLegs: HitHands
			{
				armor=6;
				material=-1;
				name="legs";
				passThrough=0.99;
				radius=0.14;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.009;
				depends="0";
			};
			class HitLeftArm
			{
				armor=6;
				material=-1;
				name="hand_l";
				passThrough=0.99;
				radius=0;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.009;
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
				passThrough=0.99;
				radius=0.06;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.009;
			};
			class HitRightLeg: HitLeftLeg
			{
				name="leg_r";
			};
		};
		armor=7; 
		armorStructural=12;
		explosionshielding=45;
		model="3AS\3AS_CIS_Infantry\Model\CIS_Inf.p3d";
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
		weapons[]=
		{
            "Throw",
			"Put"
        };
		Items[]={};
		respawnItems[]={};
		linkedItems[]={};
		respawnLinkedItems[]={};
		magazines[]={};
		respawnMagazines[]={};
	};
	class FST_CIS_HumanDiv_Standard: FST_U_CIS_Light
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		faceType="Man_A3";
		backpack="FST_HumDivBack_Standard";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopeCurator=2;
		displayName="[41st] CIS Human Division (Standard)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_CIS_Light_Armor";
		role="Rifleman";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_HumanDiv";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_CIS_Infantry\data\cis_inf_texture_armour_co.paa"
		};
		weapons[]=
		{
			"FST_ValD_Standard",
			"FST_SE14R",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_50",
			"JLTS_intel_datapad_civ",
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"FST_CIS_HolsterVest",
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_2",
			"3AS_CIS_Light_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Red",
			"FST_blaster_cell_low_Red"
		};
		class EventHandlers
		{
			init= "private _u = _this select 0; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'ACE_tourniquet'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Human Division Standard Trooper'; [_unit, 0.2, 'body', 'stab'] call ace_medical_fnc_addDamageToUnit;}; _u setSkill ['aimingAccuracy',0.55]; _u setSkill ['aimingShake',0.6]; _u setSkill ['aimingSpeed',0.65]; _u setSkill ['spotDistance',0.7]; _u setSkill ['spotTime',0.7]; _u setSkill ['courage',0.75]; _u setSkill ['commanding',0.5]; _u setSkill ['reloadSpeed',0.7]; _u setSkill ['general',0.7];";
		};
	};
	class FST_CIS_HumanDiv_AmmoB: FST_U_CIS_Light
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		faceType="Man_A3";
		backpack="FST_CISCloneAmmoPack";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopeCurator=2;
		displayName="[41st] CIS Human Division (Ammo)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_CIS_Light_Armor";
		role="Rifleman";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_HumanDiv";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_CIS_Infantry\data\cis_inf_texture_armour_co.paa"
		};
		weapons[]=
		{
			"FST_ZK73_Standard",
			"IDA_VibroKnife",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_50",
			"JLTS_intel_datapad_civ",
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"FST_HumanDiv_Pouches",
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_2",
			"3AS_CIS_Light_helmet"
		};
		magazines[]=
		{
			"FST_ZH73_Mag_Red",
			"FST_thermal_slug_mag_Red",
			"ACE_Chemlight_HiRed",
			"FST_grenade_smoke_orange_mag"
		};
		class EventHandlers
		{
			init="private _u = _this select 0; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'FST_thermal_slug_mag_Red'; _u addItemToVest 'FST_ZH73_Mag_Red'; _u addItemToVest 'FST_ZH73_Mag_Red'; _u addItemToVest 'FST_ZH73_Mag_Red'; _u addItemToVest 'FST_ZH73_Mag_Red'; _u addItemToVest 'FST_ZH73_Mag_Red'; _u addItemToVest 'FST_ZH73_Mag_Red'; _u addItemToVest 'FST_ZH73_Mag_Red'; _u addItemToVest 'FST_ZH73_Mag_Red'; _u addItemToVest 'FST_ZH73_Mag_Red'; _u addItemToVest 'FST_ZH73_Mag_Red'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Human Division Ammo Bearer'; [_unit, 0.2, 'body', 'stab'] call ace_medical_fnc_addDamageToUnit;};  _u setSkill ['aimingAccuracy',0.55]; _u setSkill ['aimingShake',0.6]; _u setSkill ['aimingSpeed',0.65]; _u setSkill ['spotDistance',0.7]; _u setSkill ['spotTime',0.7]; _u setSkill ['courage',0.65]; _u setSkill ['commanding',0.5]; _u setSkill ['reloadSpeed',0.7]; _u setSkill ['general',0.7];";
		};
	};
	class FST_U_CIS_Light_Veteran: FST_U_CIS_Light
	{
		author="Gold";
		displayName="[41st] CIS Human Division (Light/Veteran)";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=1;
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
	};
	class FST_CIS_HumanDiv_RTO: FST_U_CIS_Light
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		faceType="Man_A3";
		backpack="FST_HumDivBack_Radio";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopeCurator = 2;
		displayName="[41st] CIS Human Division (RTO)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_CIS_Light_Armor_Veteran";
		role="Rifleman";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_HumanDiv";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\FST_Armor_HumDiv_Veteran.paa"
		};
		weapons[]=
		{
			"FST_ValD_Standard",
			"FST_SE14R",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_50",
			"JLTS_intel_datapad_civ",
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"FST_CIS_HolsterVest",
			"ls_imperial_earPiece",
			"JLTS_droid_comlink",
			"OPTRE_NVG_UL",
			"3AS_CIS_Light_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Red",
			"FST_blaster_cell_low_Red"
		};
		class EventHandlers
		{
			init= "private _u = _this select 0; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'IDA_VibroKnife'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Human Division RTO'; [_unit, 0.2, 'body', 'stab'] call ace_medical_fnc_addDamageToUnit;}; _u setSkill ['aimingAccuracy',0.55]; _u setSkill ['aimingShake',0.6]; _u setSkill ['aimingSpeed',0.65]; _u setSkill ['spotDistance',0.7]; _u setSkill ['spotTime',0.75]; _u setSkill ['courage',0.75]; _u setSkill ['commanding',0.8]; _u setSkill ['reloadSpeed',0.7]; _u setSkill ['general',0.7];";
		};
	};
	class FST_CIS_HumanDiv_CQC: FST_U_CIS_Light
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		faceType="Man_A3";
		backpack="FST_HumDivBack_CQC";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopeCurator=2;
		displayName="[41st] CIS Human Division (CQC)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_CIS_Light_Armor_Veteran";
		role="Rifleman";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_HumanDiv";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\FST_Armor_HumDiv_Veteran.paa"
		};
		weapons[]=
		{
			"FST_SBB3",
			"IDA_VibroKnife",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_50",
			"JLTS_intel_datapad_civ",
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"FST_CIS_CQB_Vest",
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_2",
			"3AS_CIS_Light_helmet"
		};
		magazines[]=
		{
			"FST_blaster_scatter_cell_SBB3_Red",
		};
		class EventHandlers
		{
			init= "private _u = _this select 0; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'ACE_tourniquet'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Human Division CQC'; [_unit, 0.2, 'body', 'stab'] call ace_medical_fnc_addDamageToUnit;}; _u setSkill ['aimingAccuracy',0.55]; _u setSkill ['aimingShake',0.6]; _u setSkill ['aimingSpeed',0.8]; _u setSkill ['spotDistance',0.7]; _u setSkill ['spotTime',0.7]; _u setSkill ['courage',0.8]; _u setSkill ['commanding',0.5]; _u setSkill ['reloadSpeed',0.7]; _u setSkill ['general',0.7];";
		};
	};
	class FST_CIS_HumanDiv_Gren: FST_U_CIS_Light
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		faceType="Man_A3";
		backpack="FST_HumDivBack_Gren";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopeCurator=2;
		displayName="[41st] CIS Human Division (Grenadier)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_CIS_Light_Armor_Veteran";
		role="Rifleman";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_HumanDiv";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\FST_Armor_HumDiv_Veteran.paa"
		};
		weapons[]=
		{
			"FST_ZK73_Standard",
			"FST_SE14R",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_50",
			"JLTS_intel_datapad_civ",
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"FST_CIS_AmmoVest",
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_2",
			"3AS_CIS_Light_helmet"
		};
		magazines[]=
		{
			"FST_ZH73_Mag_Red",
			"FST_HE_LauncherGrenade",
			"FST_blaster_cell_low_Red",
			"ACE_Chemlight_HiRed",
			"FST_grenade_smoke_orange_mag"
		};
		class EventHandlers
		{
			init= "private _u = _this select 0; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'IDA_VibroKnife'; (_this select 0) addItemToVest 'ACE_tourniquet'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Human Division Grenadier'; [_unit, 0.2, 'body', 'stab'] call ace_medical_fnc_addDamageToUnit;}; _u setSkill ['aimingAccuracy',0.5]; _u setSkill ['aimingShake',0.6]; _u setSkill ['aimingSpeed',0.65]; _u setSkill ['spotDistance',0.7]; _u setSkill ['spotTime',0.7]; _u setSkill ['courage',0.75]; _u setSkill ['commanding',0.5]; _u setSkill ['reloadSpeed',0.7]; _u setSkill ['general',0.7];";
		};
	};
	class FST_CIS_HumanDiv_Mark: FST_U_CIS_Light
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		faceType="Man_A3";
		backpack="FST_HumDivBack_Mark";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopeCurator=2;
		displayName="[41st] CIS Human Division (Marksman)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_CIS_Light_Armor_Veteran";
		role="Rifleman";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_HumanDiv";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\FST_Armor_HumDiv_Veteran.paa"
		};
		weapons[]=
		{
			"FST_E5S",
			"FST_SE14R_Opticed",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_50",
			"JLTS_intel_datapad_civ",
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"FST_CIS_HolsterVest",
			"3AS_G_Marksman_3_F",
			"JLTS_droid_comlink",
			"ls_cloneNVG_commando_visor_mpStealth",
			"3AS_CIS_Light_helmet"
		};
		magazines[]=
		{
			"FST_Droid_blaster_cell_Overcharged_Red",
			"FST_blaster_cell_low_Red"
		};
		class EventHandlers
		{
			init= "private _u = _this select 0; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'IDA_VibroKnife'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Human Division Marksman'; [_unit, 0.2, 'body', 'stab'] call ace_medical_fnc_addDamageToUnit;}; _u setSkill ['aimingAccuracy',0.85]; _u setSkill ['aimingShake',0.8]; _u setSkill ['aimingSpeed',0.65]; _u setSkill ['spotDistance',0.8]; _u setSkill ['spotTime',0.7]; _u setSkill ['courage',0.75]; _u setSkill ['commanding',0.5]; _u setSkill ['reloadSpeed',0.65]; _u setSkill ['general',0.7];";
		};
	};
	class FST_CIS_HumanDiv_EOD: FST_U_CIS_Light
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		faceType="Man_A3";
		backpack="FST_HumDivBack_EOD";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopeCurator=2;
		displayName="[41st] CIS Human Division (EOD)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_CIS_Light_Armor_Veteran";
		role="Rifleman";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_HumanDiv";
		canDeactivateMines = 1;	
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\FST_Armor_HumDiv_Veteran.paa"
		};
		weapons[]=
		{
			"FST_Maalras_SMG_Standard",
			"FST_SE14R",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_50",
			"JLTS_intel_datapad_civ",
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"FST_CIS_EODVest",
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_2",
			"3AS_CIS_Light_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Red",
			"FST_blaster_cell_low_Red",
		};
		class EventHandlers
		{
			init= "private _u = _this select 0; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'IDA_VibroKnife'; _u addItemToVest 'ACE_M26_Clacker'; _u addItemToVest 'MineDetector'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Human Division EOD'; [_unit, 0.2, 'body', 'stab'] call ace_medical_fnc_addDamageToUnit;};  _u setSkill ['aimingAccuracy',0.5]; _u setSkill ['aimingShake',0.6]; _u setSkill ['aimingSpeed',0.65]; _u setSkill ['spotDistance',0.75]; _u setSkill ['spotTime',0.7]; _u setSkill ['courage',0.85]; _u setSkill ['commanding',0.5]; _u setSkill ['reloadSpeed',0.7]; _u setSkill ['general',0.7];";
		};
	};
	class FST_CIS_HumanDiv_DroneOp: FST_U_CIS_Light
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		faceType="Man_A3";
		backpack="FST_HumDivBack_DroneOp";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopeCurator=2;
		displayName="[41st] CIS Human Division (Droid Operator)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_CIS_Light_Armor_Veteran";
		role="Rifleman";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_HumanDiv";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Droids\Data\Extras\FST_Armor_HumDiv_Veteran.paa"
		};
		weapons[]=
		{
			"FST_ValD_Standard",
			"FST_SE14R",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_50",
			"JLTS_intel_datapad_civ",
			"WBK_HeadLampItem_Narrow",
			"JLTS_droidCaller"
		};
		linkedItems[]=
		{
			"FST_CIS_HolsterVest",
			"442_tech_clone_glass2_44",
			"JLTS_droid_comlink",
			"OPTRE_NVG_UL",
			"3AS_CIS_Light_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Red",
			"FST_blaster_cell_low_Red"
		};
		class EventHandlers
		{
			init= "private _u = _this select 0; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'IDA_VibroKnife'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Human Division Droid Operator'; [_unit, 0.2, 'body', 'stab'] call ace_medical_fnc_addDamageToUnit;}; _u setSkill ['aimingAccuracy',0.55]; _u setSkill ['aimingShake',0.6]; _u setSkill ['aimingSpeed',0.65]; _u setSkill ['spotDistance',0.75]; _u setSkill ['spotTime',0.7]; _u setSkill ['courage',0.75]; _u setSkill ['commanding',0.75]; _u setSkill ['reloadSpeed',0.7]; _u setSkill ['general',0.7];";
		};
	};
	class FST_U_CIS_Medic: FST_U_CIS_Light
	{
		author="Tooka";
		displayName="[41st] CIS Human Division (Medic)";
		scope=1;
		uniformClass="FST_U_CIS_Medic_Armor";
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_CIS_Infantry\data\cis_inf_medic_texture_armour_co.paa"
		};
	};
	class FST_CIS_HumanDiv_Medic: FST_U_CIS_Light
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		faceType="Man_A3";
		backpack="FST_HumDivBack_Medic";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopeCurator=2;
		displayName="[41st] CIS Human Division (Medic)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_CIS_Medic_Armor";
		role="Rifleman";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_HumanDiv";
		attendant = 1;
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_CIS_Infantry\data\cis_inf_medic_texture_armour_co.paa"
		};
		weapons[]=
		{
			"FST_Maalras_SMG_Standard",
			"FST_SE14R",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_50",
			"JLTS_intel_datapad_civ",
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"FST_CIS_HolsterVest_Medic",
			"3AS_G_Medic_5_F",
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_2",
			"3AS_CIS_Medic_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Red",
			"FST_blaster_cell_low_Red",
			"ACE_Chemlight_HiRed",
			"FST_grenade_smoke_orange_mag"
		};
		class EventHandlers
		{
			init= "private _u = _this select 0; _u addItemToVest 'FST_blaster_cell_Red'; _u addItemToVest 'FST_blaster_cell_Red'; _u addItemToVest 'FST_blaster_cell_Red';  _u addItemToVest 'FST_blaster_cell_Red'; _u addItemToVest 'FST_blaster_cell_Red'; _u addItemToVest 'FST_blaster_cell_Red'; _u addItemToVest 'FST_blaster_cell_Red'; _u addItemToVest 'FST_blaster_cell_Red'; _u addItemToVest 'FST_blaster_cell_Red'; _u addItemToVest 'FST_blaster_cell_Red'; _u addItemToVest 'FST_blaster_cell_Red'; _u addItemToVest 'FST_blaster_cell_Red'; _u addItemToVest 'FST_blaster_cell_Red'; _u addItemToVest 'FST_blaster_cell_Red'; _u addItemToVest 'FST_blaster_cell_Red'; _u addItemToVest 'FST_blaster_cell_low_Red'; _u addItemToVest 'FST_blaster_cell_low_Red'; _u addItemToVest 'FST_blaster_cell_low_Red'; _u addItemToVest 'FST_blaster_cell_low_Red'; _u addItemToVest 'FST_blaster_cell_low_Red'; _u addItemToVest 'FST_blaster_cell_low_Red'; _u addItemToVest 'FST_blaster_cell_low_Red'; _u addItemToVest 'FST_blaster_cell_low_Red'; _u addItemToVest 'FST_blaster_cell_low_Red'; _u addItemToVest 'FST_blaster_cell_low_Red'; _u addItemToVest 'FST_blaster_cell_low_Red'; _u addItemToVest 'FST_blaster_cell_low_Red'; _u addItemToVest 'FST_blaster_cell_low_Red'; _u addItemToVest 'FST_blaster_cell_low_Red'; _u addItemToVest 'FST_blaster_cell_low_Red'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Human Division Medic'; [_unit, 0.2, 'body', 'stab'] call ace_medical_fnc_addDamageToUnit;}; _u setSkill ['aimingAccuracy',0.45]; _u setSkill ['aimingShake',0.6]; _u setSkill ['aimingSpeed',0.5]; _u setSkill ['spotDistance',0.7]; _u setSkill ['spotTime',0.7]; _u setSkill ['courage',0.85]; _u setSkill ['commanding',0.5]; _u setSkill ['reloadSpeed',0.7]; _u setSkill ['general',0.7];";
		};
	};
	class FST_U_CIS_Combat_Officer: FST_U_CIS_Light
	{
		author="Tooka";
		displayName="[41st] CIS Human Division (Officer)";
		scope=1;
		uniformClass="FST_U_CIS_Officer_Armor";
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_CIS_Infantry\data\cis_inf_officer_texture_armour_co.paa"
		};
	};
	class FST_CIS_HumanDiv_Officer: FST_U_CIS_Light
	{
		author="Tooka";
		displayName="[41st] CIS Human Division (Officer)";
		scope=2;
		scopeCurator=2;
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		faceType="Man_A3";
		backpack="FST_HumDivBack_Radio";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		uniformClass="FST_U_CIS_Officer_Armor";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		role="Rifleman";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_HumanDiv";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_CIS_Infantry\data\cis_inf_officer_texture_armour_co.paa"
		};
		weapons[]=
		{
			"FST_ValD_Standard",
			"FST_SE14R_Opticed",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_100",
			"JLTS_credits_50",
			"JLTS_intel_datapad_civ",
			"JLTS_intel_datacard",
			"JLTS_intel_datacard",
			"JLTS_intel_datacard",
			"ls_holoprojector_bountyPuck",
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"FST_CIS_HolsterVest",
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_2",
			"FST_CIS_Light_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Red",
			"FST_blaster_cell_low_Red"
		};
		class EventHandlers
		{
			init= "private _u = _this select 0; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'IDA_VibroKnife'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Human Division Commander'; [_unit, 0.2, 'body', 'stab'] call ace_medical_fnc_addDamageToUnit;}; _u setSkill ['aimingAccuracy',0.55]; _u setSkill ['aimingShake',0.6]; _u setSkill ['aimingSpeed',0.65]; _u setSkill ['spotDistance',0.7]; _u setSkill ['spotTime',0.8]; _u setSkill ['courage',0.8]; _u setSkill ['commanding',0.9]; _u setSkill ['reloadSpeed',0.7]; _u setSkill ['general',0.7]; if (local _u && (leader group _u) isEqualTo _u) then {(group _u) setFormation 'DIAMOND';};";
		};
	};
	class JMSLLTE_EmpOfficer_black_F;
	class FST_EmpOfficer_black_Base: JMSLLTE_EmpOfficer_black_F
	{

	};
	class FST_CIS_OfficerUniformBase: FST_EmpOfficer_black_Base
	{
		author="Tooka";
		scope=1;
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
	class FST_HumanDiv_NOfficer: FST_EmpOfficer_black_Base
	{
		author="Tooka";
		displayName="[41st] CIS Naval Officer";
		uniformClass="FST_CIS_OfficerUnifoirm";
		scope=2;
		scopeCurator=2;
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		faceType="Man_A3";
		backpack="FST_HumDivBack_Navy";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		nakedUniform="U_BasicBody";
		role="Rifleman";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_HumanDiv";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\of_body_CIS_co.paa"
		};
		weapons[]=
		{
			"FST_CC_Standard",
			"FST_SE14R",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_100",
			"JLTS_credits_50",
			"JLTS_credits_50",
			"JLTS_intel_datapad_civ",
			"JLTS_credit_card",
			"JLTS_intel_datacard",
			"JLTS_intel_datacard",
			"JLTS_intel_holoProjector",
		};
		linkedItems[]=
		{
			"FST_CIS_NavyHolster",
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_2",
			"FST_P2_Invisible_Helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Red",
			"FST_blaster_cell_low_Red"
		};
		class EventHandlers
		{
			init= "private _u = _this select 0; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'IDA_VibroKnife'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Naval Officer';};  _u setSkill ['aimingAccuracy',0.35]; _u setSkill ['aimingShake',0.6]; _u setSkill ['aimingSpeed',0.65]; _u setSkill ['spotDistance',0.7]; _u setSkill ['spotTime',0.7]; _u setSkill ['courage',0.6]; _u setSkill ['commanding',0.8]; _u setSkill ['reloadSpeed',0.5]; _u setSkill ['general',0.5];";
		};
	};
	class FST_HumanDiv_BComm: FST_EmpOfficer_black_Base
	{
		author="Tooka";
		displayName="[41st] CIS Base Commander";
		uniformClass="FST_CIS_OfficerUniformCommander";
		scope=2;
		scopeCurator=2;
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		faceType="Man_A3";
		backpack="FST_HumDivBack_BComm";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		nakedUniform="U_BasicBody";
		role="Rifleman";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_HumanDiv";
		class HitPoints
		{
			class HitFace
			{
				armor=1;
				material=-1;
				name="face_hub";
				passThrough=0.9;
				radius=0.08;
				explosionShielding=0.1;
				minimalHit=0;
			};
			class HitHead: HitFace
			{
				armor=1;
				material=-1;
				name="head";
				passThrough=0.9;
				radius=0.12;
				explosionShielding=0.5;
				minimalHit=0.002;
				depends="HitFace";
			};
			class HitPelvis
			{
				armor=1;
				material=-1;
				name="pelvis";
				passThrough=0.9;
				radius=0.3;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.005;
			};
			class HitAbdomen
			{
				armor=1;
				material=-1;
				name="spine1";
				passThrough=0.9;
				radius=0.2;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.005;
			};
			class HitDiaphragm
			{
				armor=7;
				material=-1;
				name="spine2";
				passThrough=0.7;
				radius=0.2;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.009;
			};
			class HitChest
			{
				armor=7;
				material=-1;
				name="spine3";
				passThrough=0.7;
				radius=0.18;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.009;
			};
			class HitNeck: HitChest
			{
				armor=7;
				material=-1;
				name="neck";
				passThrough=0.7;
				radius=0.08;
				explosionShielding=0.5;
				minimalHit=0;
			};
			class HitBody
			{
				armor=6;
				material=-1;
				name="body";
				passThrough=0.99;
				radius=0;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0;
				depends="HitDiaphragm max HitChest max HitNeck";
			};
			class HitArms: HitBody
			{
				armor=1;
				material=-1;
				name="arms";
				passThrough=1;
				radius=0;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.009;
				depends="0";
			};
			class HitHands: HitArms
			{
				armor=1;
				material=-1;
				name="hands";
				passThrough=1;
				radius=0;
				explosionShielding=1;
				visual="injury_hands";
				minimalHit=0.009;
				depends="HitArms";
			};
			class HitLegs: HitHands
			{
				armor=1;
				material=-1;
				name="legs";
				passThrough=1;
				radius=0.14;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.009;
				depends="0";
			};
			class HitLeftArm
			{
				armor=1;
				material=-1;
				name="hand_l";
				passThrough=1;
				radius=0;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.009;
			};
			class HitRightArm: HitLeftArm
			{
				name="hand_r";
			};
			class HitLeftLeg
			{
				armor=1;
				material=-1;
				name="leg_l";
				passThrough=1;
				radius=0.06;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.009;
			};
			class HitRightLeg: HitLeftLeg
			{
				name="leg_r";
			};
		};
		armor=5; 
		armorStructural=12;
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\of_body_CIS_co.paa"
		};
		weapons[]=
		{
			"FST_Relbyk25_Pistol",
			"IDA_Electrobinoculars_Rep",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_100",
			"JLTS_credits_100",
			"JLTS_credits_50",
			"JLTS_credits_50",
			"JLTS_credits_500",
			"JLTS_intel_datapad_civ",
			"JLTS_credit_card",
			"JLTS_intel_datacard",
			"JLTS_intel_datacard",
			"JLTS_droidCaller",
			"JLTS_intel_holoProjector",
		};
		linkedItems[]=
		{
			"FST_CIS_OfficerVestL",
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_2",
			"FST_OfficerCap_CIS",
			"ItemMap"
		};
		magazines[]=
		{
			"FST_blaster_cell_low_Red"
		};
		class EventHandlers
		{
			init= "private _u = _this select 0; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'IDA_VibroKnife'; _u addItemToUniform '3AS_RepublicDatapadPistol'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Base Commander';}; _u setSkill ['aimingAccuracy',0.45]; _u setSkill ['aimingShake',0.5]; _u setSkill ['aimingSpeed',0.65]; _u setSkill ['spotDistance',0.8]; _u setSkill ['spotTime',0.7]; _u setSkill ['courage',0.9]; _u setSkill ['commanding',1.0]; _u setSkill ['reloadSpeed',0.7]; _u setSkill ['general',0.7];;";
		};
	};
	class FST_HumanDiv_NCaptain: FST_EmpOfficer_black_Base
	{
		author="Tooka";
		displayName="[41st] CIS Ship Captain";
		uniformClass="FST_CIS_OfficerUnifoirm";
		scope=2;
		scopeCurator=2;
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		faceType="Man_A3";
		backpack="FST_HumDivBack_NCap";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		nakedUniform="U_BasicBody";
		role="Rifleman";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_HumanDiv";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\of_body_CIS_co.paa"
		};
		weapons[]=
		{
			"FST_Relbyk25_Pistol",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_100",
			"JLTS_credits_50",
			"JLTS_credits_50",
			"JLTS_credits_50",
			"JLTS_credits_50",
			"JLTS_credits_500",
			"JLTS_credits_500",
			"JLTS_credits_1000",
			"JLTS_intel_datapad_civ",
			"JLTS_credit_card",
			"JLTS_intel_datacard",
			"JLTS_intel_datacard",
			"JLTS_intel_datacard",
			"JLTS_intel_datacard",
			"JLTS_droidCaller",
			"JLTS_intel_holoProjector",
			"3AS_Intel_DataChip",
			"3AS_Intel_DataChip",
			"3AS_Intel_DataChip",
		};
		linkedItems[]=
		{
			"FST_CIS_CaptainHolster",
			"3AS_G_RTO_1_F",
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_2",
			"FST_OfficerCap_CIS",
		};
		magazines[]=
		{
			"FST_blaster_cell_low_Red"
		};
		class EventHandlers
		{
			init= "private _u = _this select 0; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'IDA_VibroKnife'; _u addItemToUniform '3AS_RepublicDatapadPistol'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Ship Captain';}; _u setSkill ['aimingAccuracy',0.45]; _u setSkill ['aimingShake',0.6]; _u setSkill ['aimingSpeed',0.65]; _u setSkill ['spotDistance',0.7]; _u setSkill ['spotTime',0.7]; _u setSkill ['courage',0.75]; _u setSkill ['commanding',0.95]; _u setSkill ['reloadSpeed',0.5]; _u setSkill ['general',0.65];";
		};
	};
	class FST_CIS_StandardUniformBase: FST_EmpOfficer_black_Base
	{
		author="Tooka";
		scope=1;
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
	class FST_HumanDiv_BStaff: FST_EmpOfficer_black_Base
	{
		author="Tooka";
		displayName="[41st] CIS Base Staff";
		uniformClass="FST_CIS_BaseStaffArmor";
		scope=2;
		scopeCurator=2;
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		faceType="Man_A3";
		backpack="FST_HumDivBack_BStaff";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		nakedUniform="U_BasicBody";
		role="Rifleman";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_HumanDiv";
		class HitPoints
		{
			class HitFace
			{
				armor=1;
				material=-1;
				name="face_hub";
				passThrough=0.9;
				radius=0.08;
				explosionShielding=0.1;
				minimalHit=0;
			};
			class HitHead: HitFace
			{
				armor=6;
				material=-1;
				name="head";
				passThrough=0.5;
				radius=0.12;
				explosionShielding=0.5;
				minimalHit=0.002;
				depends="HitFace";
			};
			class HitPelvis
			{
				armor=1;
				material=-1;
				name="pelvis";
				passThrough=0.9;
				radius=0.3;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.005;
			};
			class HitAbdomen
			{
				armor=1;
				material=-1;
				name="spine1";
				passThrough=0.9;
				radius=0.2;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.005;
			};
			class HitDiaphragm
			{
				armor=7;
				material=-1;
				name="spine2";
				passThrough=0.7;
				radius=0.2;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.009;
			};
			class HitChest
			{
				armor=7;
				material=-1;
				name="spine3";
				passThrough=0.7;
				radius=0.18;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.009;
			};
			class HitNeck: HitChest
			{
				armor=7;
				material=-1;
				name="neck";
				passThrough=0.7;
				radius=0.08;
				explosionShielding=0.5;
				minimalHit=0;
			};
			class HitBody
			{
				armor=6;
				material=-1;
				name="body";
				passThrough=0.99;
				radius=0;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0;
				depends="HitDiaphragm max HitChest max HitNeck";
			};
			class HitArms: HitBody
			{
				armor=1;
				material=-1;
				name="arms";
				passThrough=1;
				radius=0;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.009;
				depends="0";
			};
			class HitHands: HitArms
			{
				armor=1;
				material=-1;
				name="hands";
				passThrough=1;
				radius=0;
				explosionShielding=1;
				visual="injury_hands";
				minimalHit=0.009;
				depends="HitArms";
			};
			class HitLegs: HitHands
			{
				armor=1;
				material=-1;
				name="legs";
				passThrough=1;
				radius=0.14;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.009;
				depends="0";
			};
			class HitLeftArm
			{
				armor=1;
				material=-1;
				name="hand_l";
				passThrough=1;
				radius=0;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.009;
			};
			class HitRightArm: HitLeftArm
			{
				name="hand_r";
			};
			class HitLeftLeg
			{
				armor=1;
				material=-1;
				name="leg_l";
				passThrough=1;
				radius=0.06;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.009;
			};
			class HitRightLeg: HitLeftLeg
			{
				name="leg_r";
			};
		};
		armor=5; 
		armorStructural=12;
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\of_body_CISs_co.paa"
		};
		weapons[]=
		{
			"FST_Maalras_SMG_Standard",
			"FST_SE14R",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_50",
			"JLTS_intel_datapad_civ",
			"JLTS_intel_datacard",
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"FST_CIS_OfficerVestH",
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_2",
			"FST_CIS_StaffHelmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Red",
			"FST_blaster_cell_low_Red"
		};
		class EventHandlers
		{
			init= "private _u = _this select 0; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'IDA_VibroKnife'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Base Staff';}; _u setSkill ['aimingAccuracy',0.5]; _u setSkill ['aimingShake',0.55]; _u setSkill ['aimingSpeed',0.65]; _u setSkill ['spotDistance',0.7]; _u setSkill ['spotTime',0.6]; _u setSkill ['courage',0.75]; _u setSkill ['commanding',0.5]; _u setSkill ['reloadSpeed',0.7]; _u setSkill ['general',0.6];";
		};
	};
	class FST_HumanDiv_NPerson: FST_EmpOfficer_black_Base
	{
		author="Tooka";
		displayName="[41st] CIS Naval Personnel";
		uniformClass="FST_CIS_StandardUniform";
		scope=2;
		scopeCurator=2;
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		faceType="Man_A3";
		backpack="FST_HumDivBack_Navy";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		nakedUniform="U_BasicBody";
		role="Rifleman";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_HumanDiv";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\of_body_CISs_co.paa"
		};
		weapons[]=
		{
			"FST_CC_Standard",
			"FST_SE14R",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_50",
			"JLTS_credits_50",
			"JLTS_intel_datapad_civ",
			"JLTS_credit_card",
			"JLTS_intel_datacard",
		};
		linkedItems[]=
		{
			"FST_CIS_NavyHolster",
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_2",
			"FST_P2_Invisible_Helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Red",
			"FST_blaster_cell_low_Red"
		};
		class EventHandlers
		{
			init= "private _u = _this select 0; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'IDA_VibroKnife'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Naval Personnel';}; _u setSkill ['aimingAccuracy',0.5]; _u setSkill ['aimingShake',0.55]; _u setSkill ['aimingSpeed',0.65]; _u setSkill ['spotDistance',0.7]; _u setSkill ['spotTime',0.6]; _u setSkill ['courage',0.75]; _u setSkill ['commanding',0.5]; _u setSkill ['reloadSpeed',0.7]; _u setSkill ['general',0.6];";
		};
	};
	class FST_HumanDiv_NEngi: FST_EmpOfficer_black_Base
	{
		author="Tooka";
		displayName="[41st] CIS Naval Engineer";
		uniformClass="FST_CIS_StandardUniform";
		scope=2;
		scopeCurator=2;
		engineer=1;
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		faceType="Man_A3";
		backpack="FST_HumDivBack_Engi";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		nakedUniform="U_BasicBody";
		role="Rifleman";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_HumanDiv";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\of_body_CISs_co.paa"
		};
		weapons[]=
		{
			"FST_CC_Standard",
			"FST_SE14R",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_credits_10",
			"JLTS_credits_10",
			"JLTS_credits_100",
			"JLTS_credits_50",
			"JLTS_intel_datapad_civ",
			"JLTS_credit_card",
		};
		linkedItems[]=
		{
			"FST_CIS_NavyHolster",
			"JLTS_droid_comlink",
			"3AS_G_Engineer_7_F",
			"JMSLLTE_NV_MechGlass",
			"FST_P2_Invisible_Helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Red",
			"FST_blaster_cell_low_Red"
		};
		class EventHandlers
		{
			init= "private _u = _this select 0; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BactaBandage'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'IDA_BattleStim'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_splint'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'ACE_tourniquet'; _u addItemToVest 'IDA_VibroKnife'; _this spawn {params ['_unit']; sleep 1; _unit setName 'CIS Naval Engineer';}; _u setSkill ['aimingAccuracy',0.5]; _u setSkill ['aimingShake',0.55]; _u setSkill ['aimingSpeed',0.65]; _u setSkill ['spotDistance',0.65]; _u setSkill ['spotTime',0.7]; _u setSkill ['courage',0.7]; _u setSkill ['commanding',0.5]; _u setSkill ['reloadSpeed',0.5]; _u setSkill ['general',0.6];";
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
			
			class FST_HumanDiv
			{
				name = "Human Division";
				
				class FST_S_HumanDiv_Fireteam
				{
					name="[41st] Human Division Fireteam";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Officer";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Standard";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Auto";
						rank="CORPORAL";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Standard";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_AmmoB";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Gren";
						rank="CORPORAL";
						position[]={0,-2,0};
					};
				};
				class FST_S_HumanDiv_Antiair
				{
					name="[41st] Human Division Antiair Team";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_RTO";
						rank="CORPORAL";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_AA";
						rank="CORPORAL";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_AA";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
				};
				class FST_S_HumanDiv_Markers
				{
					name="[41st] Human Division Marksman Team";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_RTO";
						rank="CORPORAL";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Mark";
						rank="CORPORAL";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Mark";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_DroneOp";
						rank="CORPORAL";
						position[]={0,-1,0};
					};
				};
				class FST_S_HumanDiv_Standard
				{
					name="[41st] Human Division Standard Squad";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Officer";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Standard";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Standard";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_AmmoB";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Auto";
						rank="CORPORAL";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_CQC";
						rank="CORPORAL";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Gren";
						rank="CORPORAL";
						position[]={1,-6,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_RTO";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Standard";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Standard";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_AmmoB";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Auto";
						rank="CORPORAL";
						position[]={0,-4,0};
					};
					class Unit12
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Mark";
						rank="CORPORAL";
						position[]={0,-5,0};
					};
					class Unit13
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Medic";
						rank="CORPORAL";
						position[]={0,-6,0};
					};
				};
				class FST_S_HumanDiv_ExlpoSquad
				{
					name="[41st] Human Division Explosives Squad";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Officer";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Standard";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Standard";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_AmmoB";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Auto";
						rank="CORPORAL";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_EOD";
						rank="CORPORAL";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Gren";
						rank="CORPORAL";
						position[]={1,-6,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_RTO";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Standard";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Standard";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_AmmoB";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Auto";
						rank="CORPORAL";
						position[]={0,-4,0};
					};
					class Unit12
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_AT";
						rank="CORPORAL";
						position[]={0,-5,0};
					};
					class Unit13
					{
						side=0;
						vehicle="FST_CIS_HumanDiv_Medic";
						rank="CORPORAL";
						position[]={0,-6,0};
					};
				};
				class FST_S_HumanDiv_BaseStaff
				{
					name="[41st] Human Division Base Staff";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_HumanDiv_BStaff";
						rank="PRIVATE";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_HumanDiv_BStaff";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_HumanDiv_BStaff";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_HumanDiv_BStaff";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_HumanDiv_BStaff";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_HumanDiv_BStaff";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_HumanDiv_BStaff";
						rank="PRIVATE";
						position[]={1,-6,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_HumanDiv_BStaff";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_HumanDiv_BStaff";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_HumanDiv_BStaff";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_HumanDiv_BStaff";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_HumanDiv_BStaff";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit12
					{
						side=0;
						vehicle="FST_HumanDiv_BStaff";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
					class Unit13
					{
						side=0;
						vehicle="FST_HumanDiv_BStaff";
						rank="PRIVATE";
						position[]={0,-6,0};
					};
				};
				class FST_S_HumanDiv_NavyStaff
				{
					name="[41st] Human Division Navy Staff";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_HumanDiv_NOfficer";
						rank="CORPORAL";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_HumanDiv_NPerson";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_HumanDiv_NPerson";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_HumanDiv_NPerson";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_HumanDiv_NPerson";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_HumanDiv_NEngi";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_HumanDiv_NEngi";
						rank="PRIVATE";
						position[]={1,-6,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_HumanDiv_NPerson";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_HumanDiv_NPerson";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_HumanDiv_NPerson";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_HumanDiv_NPerson";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_HumanDiv_NPerson";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit12
					{
						side=0;
						vehicle="FST_HumanDiv_NEngi";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
					class Unit13
					{
						side=0;
						vehicle="FST_HumanDiv_NEngi";
						rank="PRIVATE";
						position[]={0,-6,0};
					};
				};
				class FST_S_HumanDiv_BridgeStaff
				{
					name="[41st] Human Division Bridge Crew";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_HumanDiv_NCaptain";
						rank="CAPTAIN";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_Droid_B1_Commander";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_Droid_B1_Commander";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_Droid_B1_Commander";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_Droid_B1_Commander";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_Droid_B1_Commander";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_Droid_B1_Commander";
						rank="PRIVATE";
						position[]={1,-6,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_CIS_TS_F";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_HumanDiv_NOfficer";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_HumanDiv_NOfficer";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_HumanDiv_NOfficer";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_HumanDiv_NOfficer";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit12
					{
						side=0;
						vehicle="FST_HumanDiv_NOfficer";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
					class Unit13
					{
						side=0;
						vehicle="FST_HumanDiv_NOfficer";
						rank="PRIVATE";
						position[]={0,-6,0};
					};
				};
			};
		};
	};
};