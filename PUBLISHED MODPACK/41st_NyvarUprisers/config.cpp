class CfgPatches
{
	class 41st_NyvarUprisers
	{
		requiredAddons[]={"A3_Soft_F"};
		units[]=
		{
			"FST_Nyvar_B1",
			"FST_Nyvar_Weak",
			"FST_Nyvar_Standard",
			"FST_Nyvar_Trained",
			"FST_Nyvar_Tukata_Transport",
			"FST_PX10_Nyvar"
		};
		weapons[]={};
	};
	author="Tooka";
};
class CfgFactionClasses
{
	class FST_NyvarUpriser_Faction
	{
		displayName="41st Nyvar Uprisers";
		priority=1;
		side=2;
		icon="";
	};
};
class CfgEditorSubcategories
{
	class FST_NyvarUpriser
	{
		displayName = "Upriser Units"; 
	};
};
class CfgFunctions
{
	class FST_NURandomizers
	{
		class FST_RandomNUScripts
		{
			file="41st_NyvarUprisers\Scripts";
			class nyvarweak {};
			class nyvarstandard {};
			class nyvartrained {};
			class nyvarb1 {};
		};
	};
};
class CowsSlot;
class UnderBarrelSlot;
class MuzzleSlot;
class PointerSlot;
class Mode_SemiAuto;
class Mode_FullAuto;
class CfgWeapons
{
	class Uniform_Base;
	class UniformItem;
	class VestItem;
	class ItemCore;
	class ItemInfo;
	class 3AS_CIS_Light_helmet;
	class FST_Nyvar_Light_Helmet: 3AS_CIS_Light_helmet
    {
        author="Tooka";
        displayname="[41st] Nyvar Human Divison Helmet";
        hiddenSelections[]=
        {
            "camo"
        };
        hiddenSelectionsTextures[]=
        {
            "41st_NyvarUprisers\Data\FST_CIS_Infantry_Helmet_Light_co_Neyvar.paa"
        };
    };
	class JMSLLTE_Commando_cloud_helmet;
	class FST_Nyvar_Merc_Helmet: JMSLLTE_Commando_cloud_helmet
	{
		scope=2;
		author="Tooka";
		displayName="[41st] Nyvar Merc Helmet";
		picture="\JMSLLTE_scum\helmets\data\ico\ico_h_com_cl.paa";
		hiddenSelectionsTextures[]=
		{
			"41st_NyvarUprisers\Data\FST_commando_cloud_co.paa"
		};
	};
	class JMSLLTE_Tanktrooper_jin_helmet;
	class FST_Nyvar_Tukata_Helmet: JMSLLTE_Tanktrooper_jin_helmet
	{
		scope=2;
		author="Tooka";
		displayName="[41st] Nyvar Tuk'ata Helmet";
		picture="\JMSLLTE_empire\helmets\data\ico\ico_h_tankJin.paa";
		hiddenSelectionsTextures[]=
		{
			"41st_NyvarUprisers\Data\FST_tanktrooper_helmet_jin_co_neyvar.paa"
		};
	};
	class FST_P2_Helmet;
	class FST_Nyvar_P2_Helmet: FST_P2_Helmet
	{
		author="Tooka";
		scope=2;
		displayName="[41st] Nyvar P2 Helmet";
		hiddenSelectionsTextures[]=
		{
			"41st_NyvarUprisers\Data\FST_P2_Helmet_NeyvarTrooper.paa",
		};
	};
	class FST_Airborne_Helmet;
	class FST_Nyvar_AB_Helmet: FST_Airborne_Helmet
	{
		author="Tooka";
		scope=2;
		displayName="[41st] Nyvar NCO Helmet";
		hiddenSelectionsTextures[]=
		{
			"41st_NyvarUprisers\Data\FST_AB_Helmet_NeyvarNCO.paa",
		};
	};
	class FST_U_CIS_Light_Armor;
	class FST_U_Nyvar_Light_Armor: FST_U_CIS_Light_Armor
	{
		author="Tooka";
		displayName="[41st] Nyvar Human Division Armor";
		scope=2;
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_U_Nyvar_Human";
			containerClass="Supply150";
			mass=100;
		};
	};
	class JMSLLTE_JinTrooper_armor_F_CombatUniform;
	class FST_U_Nyvar_Tukata_Armor: JMSLLTE_JinTrooper_armor_F_CombatUniform
	{
		author="Tooka";
		scope=2;
		displayName="[41st] Nyvar Tuk'ata Armor";
		picture="\JMSLLTE_empire\data\ico\ico_u_jinT.paa";
		nakedUniform="U_BasicBody";
		model="\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_U_Nyvar_Tukata";
			Armor=10;
			modelSides[]={6};
			containerClass="Supply150";
			mass=30;
		};
	};
	class JMSLLTE_BoPilot_blue_F_CombatUniform;
	class FST_U_Nyvar_Merc_Armor: JMSLLTE_BoPilot_blue_F_CombatUniform
	{
		author="Tooka";
		scope=2;
		displayName="[41st] Nyvar Merc Armor";
		picture="\JMSLLTE_merc\data\ico\ico_u_BoPilot.paa";
		nakedUniform="U_BasicBody";
		model="\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_U_Nyvar_Merc";
			Armor=1;
			modelSides[]={6};
			containerClass="Supply150";
			mass=40;
		};
	};
	class FST_Trooper_Uniform;
	class FST_U_Nyvar_CloneTrooper_Armor: FST_Trooper_Uniform
	{
		author="Tooka";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] Nyvar Clone Trooper Armor";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_U_Nyvar_Trooper";
			uniformType="Neopren";
			containerClass="Supply180";
			mass=15;
		};
	};
	class FST_U_Nyvar_CloneNCO_Armor: FST_Trooper_Uniform
	{
		author="Tooka";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] Nyvar Clone NCO Armor";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_U_Nyvar_NCO";
			uniformType="Neopren";
			containerClass="Supply180";
			mass=15;
		};
	};
	class FST_DroidB1;
	class FST_U_Nyvar_B1_Armor: FST_DroidB1
	{
		author="Tooka";
		scope=2;
		displayname="[41st] Nyvar B1 Armor";
		picture="\JMSGD_droids\data\ico\ico_u_B1_guard.paa";
		JLTS_isDroid=1;
		ls_isDroid=1;
        JLTS_hasEMPProtection=0;
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_U_Nyvar_B1";
			containerClass="Supply200";
			uniformType="Neopren";
			modelSides[]={6};
			mass=40;
		};
	};
	class FST_CivFlimsi_Normal;
	class FST_WantTeam_Sly: FST_CivFlimsi_Normal
	{
		author="Tooka";
		scope=1;
		displayName="[41st] Wanted Poster";
		descriptionShort="A wanted poster printed on flimsi for the team that destroyed the moon. This one in particular is for clone 7662 'Sly', wanted dead.";
	};
	class FST_WantTeam_Sigs: FST_CivFlimsi_Normal
	{
		author="Tooka";
		scope=1;
		displayName="[41st] Wanted Poster";
		descriptionShort="A wanted poster printed on flimsi for the team that destroyed the moon. This one in particular is for clone 1362 'Sigs', wanted dead.";
	};
	class FST_WantTeam_Preacher: FST_CivFlimsi_Normal
	{
		author="Tooka";
		scope=1;
		displayName="[41st] Wanted Poster";
		descriptionShort="A wanted poster printed on flimsi for the team that destroyed the moon. This one in particular is for clone 9317 'Preacher', wanted dead.";
	};
	class FST_WantTeam_Ampersand: FST_CivFlimsi_Normal
	{
		author="Tooka";
		scope=1;
		displayName="[41st] Wanted Poster";
		descriptionShort="A wanted poster printed on flimsi for the team that destroyed the moon. This one in particular is for clone 1027 'Ampersand', wanted dead.";
	};
	class FST_WantTeam_Mav: FST_CivFlimsi_Normal
	{
		author="Tooka";
		scope=1;
		displayName="[41st] Wanted Poster";
		descriptionShort="A wanted poster printed on flimsi for the team that destroyed the moon. This one in particular is for clone 1297 'Mav', wanted dead.";
	};
	class FST_WantTeam_Pecan: FST_CivFlimsi_Normal
	{
		author="Tooka";
		scope=1;
		displayName="[41st] Wanted Poster";
		descriptionShort="A wanted poster printed on flimsi for the team that destroyed the moon. This one in particular is for clone 1738 'Pecan', wanted dead.";
	};
	class FST_WantTeam_Buddah: FST_CivFlimsi_Normal
	{
		author="Tooka";
		scope=1;
		displayName="[41st] Wanted Poster";
		descriptionShort="A wanted poster printed on flimsi for the team that destroyed the moon. This one in particular is for clone 0442 'Buddah', wanted dead.";
	};
	class FST_WantTeam_Burns: FST_CivFlimsi_Normal
	{
		author="Tooka";
		scope=1;
		displayName="[41st] Wanted Poster";
		descriptionShort="A wanted poster printed on flimsi for the team that destroyed the moon. This one in particular is for clone 7067 'Burns', wanted dead.";
	};
	class FST_WantTeam_Major: FST_CivFlimsi_Normal
	{
		author="Tooka";
		scope=1;
		displayName="[41st] Wanted Poster";
		descriptionShort="A wanted poster printed on flimsi for the team that destroyed the moon. This one in particular is for clone 2217 'Major', wanted dead.";
	};
	class FST_WantTeam_Gold: FST_CivFlimsi_Normal
	{
		author="Tooka";
		scope=1;
		displayName="[41st] Wanted Poster";
		descriptionShort="A wanted poster printed on flimsi for the team that destroyed the moon. This one in particular is for clone 7445 'Gold', wanted dead.";
	};
};
class CfgVehicles
{
	class FST_Clone_Backpack;
	class FST_Nyvar_Backpack: FST_Clone_Backpack
	{
		author="Tooka";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Nyvar Backpack";
		maximumload=250;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_NyvarUprisers\Data\FST_Clone_backpack_co_Neyvar.paa"
		};
	};
	class FST_U_CIS_Light;
	class FST_U_Nyvar_Human: FST_U_CIS_Light
	{
		author="Tooka";
		displayName="[41st] Nyvar Human Division";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=1;
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_Nyvar_Light_Armor";
		role="Rifleman";
		identityTypes[]={};
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_NyvarUprisers\Data\FST_CIS_Inf_Texture_Armour_co_Neyvar.paa"
		};
	};
	class FST_U_Nyvar_Tukata: FST_U_CIS_Light
	{
		author="Tooka";
		scope=1;
		modelSides[]={6};
		model="\JMSLLTE_empire_m\jin_trooper.p3d";
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_Nyvar_Tukata_Armor";
		hiddenSelections[]=
		{
			"Camo1",
			"Camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_NyvarUprisers\Data\FST_jin_suit_co_Neyvar.paa",
			"41st_NyvarUprisers\Data\FST_jin_armor_co_Neyvar.paa"
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
	};
	class FST_U_Nyvar_Merc: FST_U_CIS_Light
	{
		author="Tooka";
		scope=1;
		modelSides[]={6};
		model="\JMSLLTE_merc_m\bounty_pilot.p3d";
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_Nyvar_Merc_Armor";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"camo3"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_NyvarUprisers\Data\FST_boPilot_torso_base_co.paa",
			"41st_NyvarUprisers\Data\FST_boPilot_legs_base_co.paa",
			"41st_NyvarUprisers\Data\FST_boPilot_glo_base_co.paa"
		};
		class Wounds
		{
			tex[]={};
			mat[]=
			{
				"JMSLLTE_merc\data\body\boPilot_torso.rvmat",
				"JMSLLTE_merc\data\body\boPilot_torso_injury.rvmat",
				"JMSLLTE_merc\data\body\boPilot_torso_injury.rvmat",
				"JMSLLTE_merc\data\body\boPilot_legs.rvmat",
				"JMSLLTE_merc\data\body\boPilot_legs_injury.rvmat",
				"JMSLLTE_merc\data\body\boPilot_legs_injury.rvmat",
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
	};
	class FST_U_Nyvar_Trooper: FST_U_CIS_Light
	{
		author="Tooka";
		displayName="[41st] Nyvar Clone Trooper";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=1;
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_Nyvar_CloneTrooper_Armor";
		role="Rifleman";
		identityTypes[]={};
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_NyvarUprisers\Data\FST_P2_BodyUpper_NeyvarTrooper.paa",
			"41st_NyvarUprisers\Data\FST_P2_BodyLower_NeyvarTrooper.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_Armor_P2_Upper.rvmat",
			"41st_Armor\Data\Other\Clone_Armor_P2_Lower.rvmat",
		};
	};
	class FST_U_Nyvar_NCO: FST_U_CIS_Light
	{
		author="Tooka";
		displayName="[41st] Nyvar Clone NCO";
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=1;
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_Nyvar_CloneNCO_Armor";
		role="Rifleman";
		identityTypes[]={};
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_NyvarUprisers\Data\FST_P2_BodyUpper_NeyvarNCO.paa",
			"41st_NyvarUprisers\Data\FST_P2_BodyLower_NeyvarNCO.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_Armor_P2_Upper.rvmat",
			"41st_Armor\Data\Other\Clone_Armor_P2_Lower.rvmat",
		};
	};
	class FST_Droid_B1_E5;
	class FST_U_Nyvar_B1: FST_Droid_B1_E5
	{
		author="Tooka";
		scope=1;
		scopecurator=1;
		modelSides[]={6};
		model="\JMSGD_droids\B1.p3d";
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_Nyvar_B1_Armor";
		hiddenSelections[]=
		{
			"Camo1",
			"Camo2",
			"Camo3"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSGD_droids\data\body\b1_torso_guard_co.paa",
			"JMSGD_droids\data\body\b1_limbs_guard_co.paa",
			"JMSGD_droids\data\body\b1_head_guard_co.paa"
		};
		class Wounds
		{
			tex[]={};
			mat[]=
			{
				"JMSGD_droids\data\body\b1_torso.rvmat",
				"JMSGD_droids\data\body\b1_torso_injury.rvmat",
				"JMSGD_droids\data\body\b1_torso_injury.rvmat",
				"JMSGD_droids\data\body\b1_limbs.rvmat",
				"JMSGD_droids\data\body\b1_limbs_injury.rvmat",
				"JMSGD_droids\data\body\b1_limbs_injury.rvmat",
				"JMSGD_droids\data\body\b1_head.rvmat",
				"JMSGD_droids\data\body\b1_head_injury.rvmat",
				"JMSGD_droids\data\body\b1_head_injury.rvmat"
			};
		};
	};
	class FST_Nyvar_B1: FST_U_Nyvar_B1
	{
		author="Tooka";
		scope=2;
		scopecurator=2;
		displayName="[41st] Nyvar Reprogrammed B1 Battledroid";
		nakedUniform="U_BasicBody";
		uniformClass="FST_U_Nyvar_B1_Armor";
		role="Rifleman";
		faction="FST_NyvarUpriser_Faction";
		editorSubcategory="FST_NyvarUpriser";
		weapons[]=
		{
			"FST_E5",
			"Throw",
			"Put"
		};
		respawnWeapons[]={};
		Items[]={};
		respawnItems[]={};
		linkedItems[]=
		{
			"ItemMap",
			"JLTS_droid_comlink",
			"ItemCompass",
			"JLTS_NVG_droid_chip_1"
		};
		respawnLinkedItems[]={};
		magazines[]=
		{
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red",
			"FST_Droid_blaster_cell_red"
		};
		respawnMagazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_NURandomizers_fnc_nyvarb1;";
		};
	};
	class FST_Nyvar_Weak: FST_U_CIS_Light
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Nyvar Insurgent (Weak)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="JMSLLTE_PirShirt_red_F_CombatUniform";
		role="Rifleman";
		faction="FST_NyvarUpriser_Faction";
		editorSubcategory="FST_NyvarUpriser";
		weapons[]=
		{
			"FST_ValD_Standard",
			"FST_SE14R",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"FST_CIS_HolsterVest",
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_2"
		};
		magazines[]=
		{
			"FST_blaster_cell_Red",
			"FST_blaster_cell_low_Red"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_NURandomizers_fnc_nyvarweak;";
		};
	};
	class FST_Nyvar_Standard: FST_U_CIS_Light
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Nyvar Insurgent (Standard)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="JMSLLTE_PirShirt_red_F_CombatUniform";
		role="Rifleman";
		faction="FST_NyvarUpriser_Faction";
		editorSubcategory="FST_NyvarUpriser";
		weapons[]=
		{
			"FST_ValD_Standard",
			"FST_SE14R",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"FST_CIS_HolsterVest",
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_2"
		};
		magazines[]=
		{
			"FST_blaster_cell_Red",
			"FST_blaster_cell_low_Red"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_NURandomizers_fnc_nyvarstandard;";
		};
	};
	class FST_Nyvar_Trained: FST_U_CIS_Light
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Soldier_F.jpg";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Nyvar Insurgent (Trained)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="JMSLLTE_PirShirt_red_F_CombatUniform";
		role="Rifleman";
		faction="FST_NyvarUpriser_Faction";
		editorSubcategory="FST_NyvarUpriser";
		weapons[]=
		{
			"FST_ValD_Standard",
			"FST_SE14R",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"FST_CIS_HolsterVest",
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_2"
		};
		magazines[]=
		{
			"FST_blaster_cell_Red",
			"FST_blaster_cell_low_Red"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_NURandomizers_fnc_nyvartrained;";
		};
	};
	class FST_JMSLLTE_veh_ITT_base;
	class FST_Nyvar_Tukata_Transport: FST_JMSLLTE_veh_ITT_base
	{
		author="Tooka";
		scope=2;
		scopeCurator=2;
		_generalMacro="JMSLLTE_B_veh_ITT_jinata_F";
		side=0;
		displayName="K79-S80 Tukata Troop Transport";
		faction="FST_NyvarUpriser_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Nyvar_Standard";
		typicalCargo[]=
		{
			"FST_Nyvar_Standard"
		};
		textureList[]=
		{
			"Tex_ITT_jinata",
			1
		};
	};
	class FST_PX10_Tukata;
	class FST_PX10_Nyvar: FST_PX10_Tukata
	{
		displayName = "PX-10 Nyvar";
		author = "Tooka";
		faction = "FST_NyvarUpriser_Faction";
		editorSubcategory = "FST_Ground_Vehicle";
		side = 0;
		crew="FST_Nyvar_Standard";
		typicalCargo[] = { "FST_Nyvar_Standard" };
	};
};
class cfgGroups
{
	class EAST
	{
		name="OPFOR";
		
		class FST_NyvarUpriser_Faction
		{
			name="41st Nyvar Uprisers";
			
			class FST_NyvarUpriser
			{
				name = "Upriser Squads";
				
				class FST_S_Nyvar_Weak
				{
					name="[41st] Nyvar Insurgents Recruit Squad";
					faction="FST_NyvarUpriser_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_Nyvar_Standard";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_Nyvar_Weak";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_Nyvar_Weak";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_Nyvar_Weak";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_Nyvar_Weak";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_Nyvar_Weak";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_Nyvar_Standard";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_Nyvar_Weak";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_Nyvar_B1";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_Nyvar_B1";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_Nyvar_B1";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_Nyvar_B1";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
			};
		};
	};
};