class CfgPatches
{
	class 41st_CorruptPDF
	{
		requiredAddons[]={"A3_Soft_F"};
		units[]=
		{
			
			"FST_CorruptPDF_Commander",
			"FST_CorruptPDF_RTO",
			"FST_CorruptPDF_Standard",
			"FST_CorruptPDF_Auto",
			"FST_CorruptPDF_Mark",
			"FST_CorruptPDF_CQB",
			"FST_CorruptPDF_Gren",
			"FST_CorruptPDF_AA",
			"FST_CorruptPDF_AT",
			"FST_CorruptPDF_Medic",
			"FST_CorruptPDF_Tanker",
			"FST_CorruptPDFCold_Commander",
			"FST_CorruptPDFCold_RTO",
			"FST_CorruptPDFCold_Standard",
			"FST_CorruptPDFCold_Auto",
			"FST_CorruptPDFCold_Mark",
			"FST_CorruptPDFCold_CQB",
			"FST_CorruptPDFCold_Gren",
			"FST_CorruptPDFCold_AA",
			"FST_CorruptPDFCold_AT",
			"FST_CorruptPDFCold_Medic",
			"FST_CorruptPDF_Pilot",
			"FST_SmugB1_E5",
			"FST_SmugB1_LMG",
		};
		weapons[]={};
	};
	author="Tooka";
};
class CfgFactionClasses
{
	class FST_CorruptPDF_Faction
	{
		displayName="41st Corrupt PDF";
		priority=1;
		side=2;
		icon="";
	};
};
class CfgEditorSubcategories
{
	class FST_CorruptPDF
	{
		displayName = "Corrupt PDF Units"; 
	};
	class FST_CorruptPDFCold
	{
		displayName = "Cold Weather Corrupt PDF Units"; 
	};
	class FST_SmuggledB1s
	{
		displayName = "Smuggled B1 Units"; 
	};
};
class CfgFunctions
{
	class FST_PDFRandomizers
	{
		class FST_RandomPDFScripts
		{
			file="41st_CorruptPDF\Scripts";
			class pdfstandard {};
			class pdfofficer {};
			class pdfrto {};
			class pdfautorifle {};
			class pdfmarksman {};
			class pdfcqb {};
			class pdfgrenadier {};
			class pdfantiair {};
			class pdfantitank {};
			class pdfmedic {};
			class pdftanker {};
			class pdfpilot {};
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
	class U_I_CombatUniform;
	class Uniform_Base;
	class UniformItem;
	class VestItem;
	class Vest_Camo_Base;
	class JMSLLTE_Ofcap_helmet;
    class V_rebreatherB;
	class ItemCore;
	class ItemInfo;
	class JMSLLTE_EmpTrooperArmor_blackS_F_CombatUniform;
	class FST_CorruptPDFUni: JMSLLTE_EmpTrooperArmor_blackS_F_CombatUniform
	{
		author="JMax";
		scope=2;
		displayName="[41st] Totharvis PDF Uniform";
		picture="\JMSLLTE_empire\data\ico\ico_u_trooper_bl.paa";
		nakedUniform="U_BasicBody";
		model="\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_U_CorruptPDF";
			Armor=10;
			modelSides[]={6};
			containerClass="Supply100";
			mass=30;
		};
	};
	class ls_imperialUniform_army_black;
	class FST_CorruptPDFTankerUni: ls_imperialUniform_army_black
	{
		author="Tooka";
		scope=2;
		displayName="[41st] Totharvis PDF Tanker Uniform";
		model="\ls\core\addons\characters_imperial\uniforms\army\ls_uniform_imperial_army.p3d";
		picture="\ls\core\addons\characters_imperial\data\ui\uniform_army_ui_ca.paa";
		class ItemInfo: ItemInfo
		{
			uniformClass="FST_U_CorruptPDFTanker";
			containerClass="Supply100";
			mass=30;
		};
	};
	class JMSLLTE_JinTrooper_suitBlack_F_CombatUniform;
	class FST_CorruptPDFColdUni: JMSLLTE_JinTrooper_suitBlack_F_CombatUniform
	{
		author="Tooka";
		scope=2;
		displayName="[41st] Totharvis PDF Cold Uniform";
		picture="\JMSLLTE_empire\data\ico\ico_u_remS_bl.paa";
		nakedUniform="U_BasicBody";
		model="\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_U_CorruptPDFCold";
			Armor=10;
			modelSides[]={6};
			containerClass="Supply100";
			mass=20;
		};
	};
	class JMSLLTE_ScumPilot_bl_F_CombatUniform;
	class FST_CorruptPDFPilotUni: JMSLLTE_ScumPilot_bl_F_CombatUniform
	{
		author="Tooka";
		scope=2;
		displayName="[41st] Totharvis PDF Pilot Uniform";
		picture="\JMSLLTE_scum\data\ico\Ico_u_pilotBl.paa";
		nakedUniform="U_BasicBody";
		model="\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_U_CorruptPDFPilot";
			Armor=1;
			modelSides[]={6};
			containerClass="Supply100";
			mass=40;
		};
	};
	class FST_Mercenary_DC15S_UGL_Wood;
	class FST_CPDF_UGL15S: FST_Mercenary_DC15S_UGL_Wood
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
};
class UniformSlotInfo
{
	slotType=0;
	linkProxy="-";
};
class CfgVehicles
{
	
	class FST_CIS_Backpack_Invisible;
    class FST_CIS_Medic_Backpack;
	class FST_belt_bag;
	class IDA_Clone_RadioAntenna;
	class ls_orsfBackpack_trooper_radio;
	class ls_jabiimBackpack_nimbusCommando;
	class 3AS_B_Imperial_Stormtrooper_Backpack_Sand_F;
	class JLTS_B1_backpack_prototype;
	class FST_CorPDFBack_SC: IDA_Clone_RadioAntenna
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
				count=2;
			};
			
			class _xx_IDA_grenade_Sonic_mag
			{
				name="IDA_grenade_Sonic_mag";
				count=2;
			};
			class _xx_FST_blaster_cell_High_Yellow
			{
				name="FST_blaster_cell_High_Yellow";
				count=15;
			};
		};
	};
	class FST_CorPDFBack_SCCold: ls_jabiimBackpack_nimbusCommando
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
				count=2;
			};
			
			class _xx_IDA_grenade_Sonic_mag
			{
				name="IDA_grenade_Sonic_mag";
				count=2;
			};
			class _xx_FST_blaster_cell_High_Yellow
			{
				name="FST_blaster_cell_High_Yellow";
				count=15;
			};
		};
	};
	class FST_CorPDFBack_RTO: ls_orsfBackpack_trooper_radio
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_FST_blaster_cell_Yellow
			{
				name="FST_blaster_cell_Yellow";
				count=15;
			};
		};
	};
	class FST_CorPDFBack_Standard: FST_belt_bag
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
				count=2;
			};
			
			class _xx_IDA_grenade_Sonic_mag
			{
				name="IDA_grenade_Sonic_mag";
				count=2;
			};
			class _xx_FST_blaster_cell_Yellow
			{
				name="FST_blaster_cell_Yellow";
				count=15;
			};
		};
	};
	class FST_CorPDFBack_StandardCold: 3AS_B_Imperial_Stormtrooper_Backpack_Sand_F
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
				count=2;
			};
			
			class _xx_IDA_grenade_Sonic_mag
			{
				name="IDA_grenade_Sonic_mag";
				count=2;
			};
			class _xx_FST_blaster_cell_Yellow
			{
				name="FST_blaster_cell_Yellow";
				count=15;
			};
		};
	};
	class FST_CorPDFBack_Auto: FST_belt_bag
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_FST_blaster_battery_Yellow
			{
				name="FST_blaster_battery_Yellow";
				count=7;
			};
		};
	};
	class FST_CorPDFBack_AutoCold: 3AS_B_Imperial_Stormtrooper_Backpack_Sand_F
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_FST_blaster_battery_Yellow
			{
				name="FST_blaster_battery_Yellow";
				count=7;
			};
		};
	};
	class FST_CorPDFBack_Mark: FST_belt_bag
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
				count=2;
			};
			
			class _xx_IDA_grenade_Sonic_mag
			{
				name="IDA_grenade_Sonic_mag";
				count=2;
			};
			class _xx_FST_blaster_cell_High_Yellow
			{
				name="FST_blaster_cell_High_Yellow";
				count=15;
			};
			class _xx_FST_blaster_cell_low_Yellow
			{
				name="FST_blaster_cell_low_Yellow";
				count=10;
			};
		};
	};
	class FST_CorPDFBack_MarkCold: 3AS_B_Imperial_Stormtrooper_Backpack_Sand_F
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
				count=2;
			};
			
			class _xx_IDA_grenade_Sonic_mag
			{
				name="IDA_grenade_Sonic_mag";
				count=2;
			};
			class _xx_FST_blaster_cell_High_Yellow
			{
				name="FST_blaster_cell_High_Yellow";
				count=15;
			};
			class _xx_FST_blaster_cell_low_Yellow
			{
				name="FST_blaster_cell_low_Yellow";
				count=10;
			};
		};
	};
	class FST_CorPDFBack_CQB: FST_belt_bag
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_FST_blaster_scatter_cell_SBB3_Yellow
			{
				name="FST_blaster_scatter_cell_SBB3_Yellow";
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
				count=4;
			};
		};
	};
	class FST_CorPDFBack_CQBCold: 3AS_B_Imperial_Stormtrooper_Backpack_Sand_F
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_FST_blaster_scatter_cell_SBB3_Yellow
			{
				name="FST_blaster_scatter_cell_SBB3_Yellow";
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
				count=4;
			};
		};
	};
	class FST_CorPDFBack_Gren: FST_belt_bag
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
			class _xx_FST_blaster_cell_Yellow
			{
				name="FST_blaster_cell_Yellow";
				count=15;
			};
			class _xx_IDA_HE_LauncherGrenade
			{
				name="IDA_HE_LauncherGrenade";
				count=2;
			};
		};
	};
	class FST_CorPDFBack_GrenCold: 3AS_B_Imperial_Stormtrooper_Backpack_Sand_F
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
			class _xx_FST_blaster_cell_Yellow
			{
				name="FST_blaster_cell_Yellow";
				count=15;
			};
			class _xx_IDA_HE_LauncherGrenade
			{
				name="IDA_HE_LauncherGrenade";
				count=2;
			};
		};
	};
	class FST_CorPDFBack_AA: FST_CIS_Backpack_Invisible
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
			class _xx_FST_blaster_cell_Yellow
			{
				name="FST_blaster_cell_Yellow";
				count=15;
			};
			class _xx_FST_E60R_AA_mag_HD
			{
				name="FST_E60R_AA_mag_HD";
				count=2;
			};
		};
	};
	class FST_CorPDFBack_AACold: 3AS_B_Imperial_Stormtrooper_Backpack_Sand_F
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
			class _xx_FST_blaster_cell_Yellow
			{
				name="FST_blaster_cell_Yellow";
				count=15;
			};
			class _xx_FST_E60R_AA_mag_HD
			{
				name="FST_E60R_AA_mag_HD";
				count=2;
			};
		};
	};
	class FST_CorPDFBack_AT: FST_belt_bag
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
			class _xx_FST_blaster_cell_Yellow
			{
				name="FST_blaster_cell_Yellow";
				count=15;
			};
			class _xx_3AS_MK41_AT
			{
				name="3AS_MK41_AT";
				count=2;
			};
		};
	};
	class FST_CorPDFBack_ATCold: 3AS_B_Imperial_Stormtrooper_Backpack_Sand_F
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
			class _xx_FST_blaster_cell_Yellow
			{
				name="FST_blaster_cell_Yellow";
				count=15;
			};
			class _xx_3AS_MK41_AT
			{
				name="3AS_MK41_AT";
				count=2;
			};
		};
	};
	class FST_CorPDFBack_Medic: FST_CIS_Medic_Backpack
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_IDA_BactaBandage
			{
				name="IDA_BactaBandage";
				count=30;
			};
			class _xx_IDA_BattleStim
			{
				name="IDA_BattleStim";
				count=10;
			};
			class _xx_ACE_splint
			{
				name="ACE_splint";
				count=8;
			};
			class _xx_ACE_tourniquet
			{
				name="ACE_tourniquet";
				count=8;
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
	class FST_CorPDFBack_Tank: FST_belt_bag
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_FST_blaster_cell_low_Yellow
			{
				name="FST_blaster_cell_low_Yellow";
				count=15;
			};
		};
	};
	class FST_CorPDFBack_Pilot: FST_CIS_Backpack_Invisible
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_FST_blaster_cell_low_Yellow
			{
				name="FST_blaster_cell_low_Yellow";
				count=15;
			};
		};
	};
	class FST_SmugB1Back: JLTS_B1_backpack_prototype
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_FST_Droid_blaster_cell_Red
			{
				name="FST_Droid_blaster_cell_Red";
				count=10;
			};
		};
	};
	class FST_SmugB1Back_LMG: JLTS_B1_backpack_prototype
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_FST_Droid_blaster_battery_Red
			{
				name="FST_Droid_blaster_battery_Red";
				count=10;
			};
		};
	};
	class FST_U_CIS_Light;
	class FST_U_CorruptPDF: FST_U_CIS_Light
	{
		author="Tooka";
		scope=1;
		modelSides[]={6};
		model="\JMSLLTE_empire_m\trooper.p3d";
		nakedUniform="U_BasicBody";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\Trooper_body_black_co.paa",
			"JMSLLTE_empire\data\body\Trooper_armor_black_serg_co.paa"
		};
	};
	class FST_CorruptPDF_Commander: FST_U_CorruptPDF
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_SC";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (Squad Commander)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDF";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\Trooper_body_black_co.paa",
			"JMSLLTE_empire\data\body\Trooper_armor_black_serg_co.paa"
		};
		weapons[]=
		{
			"FST_DC15A_Wood",
			"FST_DL18_Pistol",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_intel_holoProjector",
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Ammo_Belt",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"OPTRE_HUD_blk_Glasses",
			"JMSLLTE_EmpOfficerCap2_black_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_High_Yellow"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfofficer;";
		};
	};
	class FST_CorruptPDF_RTO: FST_U_CorruptPDF
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_RTO";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (RTO)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDF";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\Trooper_body_black_co.paa",
			"JMSLLTE_empire\data\body\Trooper_armor_black_serg_co.paa"
		};
		weapons[]=
		{
			"FST_SPA_K15",
			"FST_DL18_Pistol",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Ammo_Belt",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"ls_imperial_earPiece",
			"JMSLLTE_PlastHv_bl_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Yellow"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfrto;";
		};
	};
	class FST_CorruptPDF_Standard: FST_U_CorruptPDF
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_Standard";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (Standard)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDF";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\Trooper_body_black_co.paa",
			"JMSLLTE_empire\data\body\Trooper_armor_black_serg_co.paa"
		};
		weapons[]=
		{
			"FST_SPA_K15",
			"FST_DL18_Pistol",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Ammo_Belt",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"G_JMSLLTE_None",
			"JMSLLTE_PlastHv_bl_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Yellow"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfstandard;";
		};
	};
	class FST_CorruptPDF_Auto: FST_U_CorruptPDF
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_Auto";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (Autorifleman)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDF";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\Trooper_body_black_co.paa",
			"JMSLLTE_empire\data\body\Trooper_armor_black_serg_co.paa"
		};
		weapons[]=
		{
			"FST_M41",
			"FST_DL18_Pistol",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow",
			"ACE_Chemlight_HiRed"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Ammo_Belt",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"G_JMSLLTE_None",
			"JMSLLTE_PlastHv_bl_helmet"
		};
		magazines[]=
		{
			"FST_blaster_battery_Yellow"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfautorifle;";
		};
	};
	class FST_CorruptPDF_Mark: FST_U_CorruptPDF
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_Mark";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (Marksman)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDF";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\Trooper_body_black_co.paa",
			"JMSLLTE_empire\data\body\Trooper_armor_black_serg_co.paa"
		};
		weapons[]=
		{
			"FST_DL63",
			"FST_DL18_Pistol",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Ammo_Belt",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"ls_imperial_earPiece",
			"JMSLLTE_EmpOfficerCap2_black_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_High_Yellow",
			"FST_blaster_cell_low_Yellow"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfmarksman;";
		};
	};
	class FST_CorruptPDF_CQB: FST_U_CorruptPDF
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_CQB";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (CQB)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDF";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\Trooper_body_black_co.paa",
			"JMSLLTE_empire\data\body\Trooper_armor_black_serg_co.paa"
		};
		weapons[]=
		{
			"FST_ACPA",
			"FST_DL18_Pistol",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Ammo_Belt",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"G_JMSLLTE_None",
			"JMSLLTE_PlastHv_bl_helmet"
		};
		magazines[]=
		{
			"FST_blaster_scatter_cell_SBB3_Yellow"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfcqb;";
		};
	};
	class FST_CorruptPDF_Gren: FST_U_CorruptPDF
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_Gren";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (Grenadier)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDF";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\Trooper_body_black_co.paa",
			"JMSLLTE_empire\data\body\Trooper_armor_black_serg_co.paa"
		};
		weapons[]=
		{
			"FST_CPDF_UGL15S",
			"FST_DL18_Pistol",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Bandolier_Ammo",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"G_JMSLLTE_None",
			"JMSLLTE_PlastHv_bl_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Yellow",
			"IDA_HE_LauncherGrenade"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfgrenadier;";
		};
	};
	class FST_CorruptPDF_AA: FST_U_CorruptPDF
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_AA";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (AA)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDF";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\Trooper_body_black_co.paa",
			"JMSLLTE_empire\data\body\Trooper_armor_black_serg_co.paa"
		};
		weapons[]=
		{
			"FST_SPA_K15",
			"FST_DL18_Pistol",
			"FST_E60R_AA_HD",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Ammo_Belt",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"3AS_G_AT_3_F",
			"JMSLLTE_PlastHv_bl_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Yellow",
			"FST_E60R_AA_mag_HD"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfantiair;";
		};
	};
	class FST_CorruptPDF_AT: FST_U_CorruptPDF
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_AT";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (AT)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDF";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\Trooper_body_black_co.paa",
			"JMSLLTE_empire\data\body\Trooper_armor_black_serg_co.paa"
		};
		weapons[]=
		{
			"FST_SPA_K15",
			"FST_DL18_Pistol",
			"3AS_HH12_F",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Ammo_Belt",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"3AS_G_AT_3_F",
			"JMSLLTE_PlastHv_bl_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Yellow",
			"3AS_MK41_AT"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfantitank;";
		};
	};
	class FST_CorruptPDF_Medic: FST_U_CorruptPDF
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_Medic";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (Medic)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDF";
		attendant = 1;
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\Trooper_body_black_co.paa",
			"JMSLLTE_empire\data\body\Trooper_armor_black_serg_co.paa"
		};
		weapons[]=
		{
			"FST_EE4",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Ammo_Belt",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"3AS_G_Medic_5_F",
			"JMSLLTE_EmpOfficerCap2_black_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_low_Yellow_smg"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfmedic;";
		};
	};
	class FST_U_CorruptPDFTanker: FST_U_CIS_Light
	{
		author="Tooka";
		scope=1;
		editorPreview="\ls\core\addons\characters_imperial\data\ui\editorPreviews\ls_imperial_army_black.jpg";
		model="\ls\core\addons\characters_imperial\uniforms\army\ls_uniform_imperial_army.p3d";
		nakedUniform="U_BasicBody";
		hiddenSelections[]=
		{
			"camo",
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\characters_imperial\uniforms\army\data\camo_black_co.paa",
			"\ls\core\addons\characters_imperial\uniforms\army\data\camo1_black_co.paa"
		};
	};
	class FST_CorruptPDF_Tanker: FST_U_CorruptPDFTanker
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_Tank";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (Tanker)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFTankerUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDF";
		hiddenSelections[]=
		{
			"camo",
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\characters_imperial\uniforms\army\data\camo_black_co.paa",
			"\ls\core\addons\characters_imperial\uniforms\army\data\camo1_black_co.paa"
		};
		weapons[]=
		{
			"FST_DL18_Pistol",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"ls_vest_flakJacket",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"G_JMSLLTE_None",
			"JMSLLTE_Desert_1_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_low_Yellow"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdftanker;";
		};
	};
	class FST_U_CorruptPDFCold: FST_U_CIS_Light
	{
		author="Tooka";
		scope=1;
		modelSides[]={6};
		model="\JMSLLTE_empire_m\jin_suit.p3d";
		nakedUniform="U_BasicBody";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\jin_suit_black_co.paa"
		};
	};
	class FST_CorruptPDFCold_Commander: FST_U_CorruptPDFCold
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_SCCold";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (Squad Commander)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFColdUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDFCold";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\jin_suit_black_co.paa"
		};
		weapons[]=
		{
			"FST_DC15A_Wood",
			"FST_DL18_Pistol",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"JLTS_intel_holoProjector",
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Ammo_Belt",
			"ls_radios_hush98_aurebesh",
			"ls_nvg_goggles",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"G_Balaclava_TI_blk_F",
			"JMSLLTE_EmpOfficerCap2_black_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_High_Yellow"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfofficer;";
		};
	};
	class FST_CorruptPDFCold_RTO: FST_U_CorruptPDFCold
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_RTO";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (RTO)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFColdUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDFCold";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\jin_suit_black_co.paa"
		};
		weapons[]=
		{
			"FST_SPA_K15",
			"FST_DL18_Pistol",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Ammo_Belt",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"G_Balaclava_TI_blk_F",
			"JMSLLTE_PlastHv_bl_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Yellow"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfrto;";
		};
	};
	class FST_CorruptPDFCold_Standard: FST_U_CorruptPDFCold
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_StandardCold";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (Standard)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFColdUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDFCold";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\jin_suit_black_co.paa"
		};
		weapons[]=
		{
			"FST_SPA_K15",
			"FST_DL18_Pistol",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Ammo_Belt",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"G_Balaclava_TI_blk_F",
			"JMSLLTE_PlastHv_bl_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Yellow"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfstandard;";
		};
	};
	class FST_CorruptPDFCold_Auto: FST_U_CorruptPDFCold
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_AutoCold";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (Autorifleman)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFColdUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDFCold";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\jin_suit_black_co.paa"
		};
		weapons[]=
		{
			"FST_M41",
			"FST_DL18_Pistol",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow",
			"ACE_Chemlight_HiRed"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Ammo_Belt",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"G_Balaclava_TI_blk_F",
			"JMSLLTE_PlastHv_bl_helmet"
		};
		magazines[]=
		{
			"FST_blaster_battery_Yellow"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfautorifle;";
		};
	};
	class FST_CorruptPDFCold_Mark: FST_U_CorruptPDFCold
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_MarkCold";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (Marksman)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFColdUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDFCold";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\jin_suit_black_co.paa"
		};
		weapons[]=
		{
			"FST_DL63",
			"FST_DL18_Pistol",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Ammo_Belt",
			"ls_radios_hush98_aurebesh",
			"ls_nvg_goggles",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"G_Balaclava_TI_blk_F",
			"JMSLLTE_EmpOfficerCap2_black_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_High_Yellow",
			"FST_blaster_cell_low_Yellow"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfmarksman;";
		};
	};
	class FST_CorruptPDFCold_CQB: FST_U_CorruptPDFCold
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_CQBCold";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (CQB)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFColdUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDFCold";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\jin_suit_black_co.paa"
		};
		weapons[]=
		{
			"FST_ACPA",
			"FST_DL18_Pistol",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Ammo_Belt",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"G_Balaclava_TI_blk_F",
			"JMSLLTE_PlastHv_bl_helmet"
		};
		magazines[]=
		{
			"FST_blaster_scatter_cell_SBB3_Yellow"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfcqb;";
		};
	};
	class FST_CorruptPDFCold_Gren: FST_U_CorruptPDFCold
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_GrenCold";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (Grenadier)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFColdUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDFCold";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\jin_suit_black_co.paa"
		};
		weapons[]=
		{
			"FST_CPDF_UGL15S",
			"FST_DL18_Pistol",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Bandolier_Ammo",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"G_Balaclava_TI_blk_F",
			"JMSLLTE_PlastHv_bl_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Yellow",
			"IDA_HE_LauncherGrenade"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfgrenadier;";
		};
	};
	class FST_CorruptPDFCold_AA: FST_U_CorruptPDFCold
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_AACold";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (AA)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFColdUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDFCold";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\jin_suit_black_co.paa"
		};
		weapons[]=
		{
			"FST_SPA_K15",
			"FST_DL18_Pistol",
			"FST_E60R_AA_HD",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Ammo_Belt",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"G_Balaclava_TI_blk_F",
			"JMSLLTE_PlastHv_bl_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Yellow",
			"FST_E60R_AA_mag_HD"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfantiair;";
		};
	};
	class FST_CorruptPDFCold_AT: FST_U_CorruptPDFCold
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_ATCold";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (AT)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFColdUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDFCold";
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\jin_suit_black_co.paa"
		};
		weapons[]=
		{
			"FST_SPA_K15",
			"FST_DL18_Pistol",
			"3AS_HH12_F",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Ammo_Belt",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"G_Balaclava_TI_blk_F",
			"JMSLLTE_PlastHv_bl_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_Yellow",
			"3AS_MK41_AT"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfantitank;";
		};
	};
	class FST_CorruptPDFCold_Medic: FST_U_CorruptPDFCold
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_Medic";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (Medic)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFColdUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDFCold";
		attendant = 1;
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_empire\data\body\jin_suit_black_co.paa"
		};
		weapons[]=
		{
			"FST_EE4",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"3AS_V_Imperial_Stormtrooper_Ammo_Belt",
			"ls_radios_hush98_aurebesh",
			"ls_nvg_goggles",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"G_Balaclava_TI_blk_F",
			"JMSLLTE_EmpOfficerCap2_black_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_low_Yellow_smg"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfmedic;";
		};
	};
	class JMSLLTE_ScumPilot_orange_F;
	class FST_U_CorruptPDFPilot: JMSLLTE_ScumPilot_orange_F
	{
		author="Tooka";
		scope=1;
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_scum\data\body\pilot_torso_bl_co.paa",
			"JMSLLTE_scum\data\body\pilot_legs_bl_co.paa"
		};
	};
	class FST_CorruptPDF_Pilot: FST_U_CorruptPDFPilot
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_CorPDFBack_Pilot";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Totharvis PDF (Pilot)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_CorruptPDFPilotUni";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_CorruptPDF";
		hiddenSelectionsTextures[]=
		{
			"JMSLLTE_scum\data\body\pilot_torso_bl_co.paa",
			"JMSLLTE_scum\data\body\pilot_legs_bl_co.paa"
		};
		weapons[]=
		{
			"FST_DL18_Pistol",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Narrow"
		};
		linkedItems[]=
		{
			"JMSLLTE_PilotBreather_xwing",
			"ls_radios_hush98_aurebesh",
			"FST_NVG_Invisible_Thermals",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"G_JMSLLTE_None",
			"JMSLLTE_Xwing_zev_helmet"
		};
		magazines[]=
		{
			"FST_blaster_cell_low_Yellow"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_PDFRandomizers_fnc_pdfpilot;";
		};
	};
	class FST_Droid_B1_E5;
	class FST_SmugB1_E5: FST_Droid_B1_E5
	{
		backpack="FST_SmugB1Back";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Smuggled B1";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="JLTS_DroidB1_Prototype";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_SmuggledB1s";
		weapons[]=
		{
			"FST_E5",
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]=
		{
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_1",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
		};
		magazines[]=
		{
			"FST_Droid_blaster_cell_Red"
		};
	};
	class FST_SmugB1_LMG: FST_Droid_B1_E5
	{
		backpack="FST_SmugB1Back_LMG";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Smuggled B1 (LMG)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="JLTS_DroidB1_Prototype";
		role="Rifleman";
		faction="FST_CorruptPDF_Faction";
		editorSubcategory="FST_SmuggledB1s";
		weapons[]=
		{
			"FST_E5C_Stock",
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]=
		{
			"JLTS_droid_comlink",
			"JLTS_NVG_droid_chip_1",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
		};
		magazines[]=
		{
			"FST_Droid_blaster_battery_Red"
		};
	};
};
class cfgGroups
{
	class EAST
	{
		name="OPFOR";
		
		class FST_CorruptPDF_Faction
		{
			name="41st Corrupt PDF";
			
			class FST_CorruptPDF
			{
				name = "Corrupt PDF Units";
				
				class FST_S_CorPDF_Fireteam
				{
					name="[41st] Totharvis PDF Fireteam";
					faction="FST_CorruptPDF_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_CorruptPDF_Commander";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_CorruptPDF_Standard";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_CorruptPDF_Medic";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_CorruptPDF_RTO";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_CorruptPDF_Auto";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_CorruptPDF_CQB";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
				};
				class FST_S_CorPDF_Antiair
				{
					name="[41st] Totharvis PDF Antiair Team";
					faction="FST_CorruptPDF_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_CorruptPDF_RTO";
						rank="CORPORAL";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_CorruptPDF_AA";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_CorruptPDF_AA";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
				};
				class FST_S_CorPDF_Markers
				{
					name="[41st] Totharvis PDF Marksman Team";
					faction="FST_CorruptPDF_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_CorruptPDF_RTO";
						rank="CORPORAL";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_CorruptPDF_Mark";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_CorruptPDF_Mark";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
				};
				class FST_S_CorPDF_Standard
				{
					name="[41st] Totharvis PDF Standard Squad";
					faction="FST_CorruptPDF_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_CorruptPDF_Commander";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_CorruptPDF_Standard";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_CorruptPDF_Standard";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_CorruptPDF_Standard";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_CorruptPDF_Auto";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_CorruptPDF_CQB";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_CorruptPDF_Gren";
						rank="PRIVATE";
						position[]={1,-6,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_CorruptPDF_Medic";
						rank="PRIVATE";
						position[]={1,-7,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_CorruptPDF_RTO";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_CorruptPDF_Standard";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_CorruptPDF_Standard";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_CorruptPDF_Standard";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit12
					{
						side=0;
						vehicle="FST_CorruptPDF_Auto";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit13
					{
						side=0;
						vehicle="FST_CorruptPDF_CQB";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
					class Unit14
					{
						side=0;
						vehicle="FST_CorruptPDF_Gren";
						rank="PRIVATE";
						position[]={0,-6,0};
					};
					class Unit15
					{
						side=0;
						vehicle="FST_CorruptPDF_Medic";
						rank="PRIVATE";
						position[]={0,-7,0};
					};
				};
				class FST_S_CorPDF_Antitank
				{
					name="[41st] Totharvis PDF AT Squad";
					faction="FST_CorruptPDF_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_CorruptPDF_Commander";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_CorruptPDF_Standard";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_CorruptPDF_Standard";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_CorruptPDF_AT";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_CorruptPDF_Auto";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_CorruptPDF_CQB";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_CorruptPDF_Gren";
						rank="PRIVATE";
						position[]={1,-6,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_CorruptPDF_Medic";
						rank="PRIVATE";
						position[]={1,-7,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_CorruptPDF_RTO";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_CorruptPDF_Standard";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_CorruptPDF_Standard";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_CorruptPDF_AT";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit12
					{
						side=0;
						vehicle="FST_CorruptPDF_Auto";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit13
					{
						side=0;
						vehicle="FST_CorruptPDF_CQB";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
					class Unit14
					{
						side=0;
						vehicle="FST_CorruptPDF_Gren";
						rank="PRIVATE";
						position[]={0,-6,0};
					};
					class Unit15
					{
						side=0;
						vehicle="FST_CorruptPDF_Medic";
						rank="PRIVATE";
						position[]={0,-7,0};
					};
				};
			};
			class FST_CorruptPDFCold
			{
				name = "Cold Weather Corrupt PDF Units";
				
				class FST_S_CorPDFCold_Fireteam
				{
					name="[41st] Totharvis PDF Fireteam";
					faction="FST_CorruptPDF_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Commander";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Standard";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Medic";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_CorruptPDFCold_RTO";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Auto";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_CorruptPDFCold_CQB";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
				};
				class FST_S_CorPDFCold_Antiair
				{
					name="[41st] Totharvis PDF Antiair Team";
					faction="FST_CorruptPDF_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_CorruptPDFCold_RTO";
						rank="CORPORAL";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_CorruptPDFCold_AA";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_CorruptPDFCold_AA";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
				};
				class FST_S_CorPDFCold_Markers
				{
					name="[41st] Totharvis PDF Marksman Team";
					faction="FST_CorruptPDF_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_CorruptPDFCold_RTO";
						rank="CORPORAL";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Mark";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Mark";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
				};
				class FST_S_CorPDFCold_Standard
				{
					name="[41st] Totharvis PDF Standard Squad";
					faction="FST_CorruptPDF_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Commander";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Standard";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Standard";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Standard";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Auto";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_CorruptPDFCold_CQB";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Gren";
						rank="PRIVATE";
						position[]={1,-6,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Medic";
						rank="PRIVATE";
						position[]={1,-7,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_CorruptPDFCold_RTO";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Standard";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Standard";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Standard";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit12
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Auto";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit13
					{
						side=0;
						vehicle="FST_CorruptPDFCold_CQB";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
					class Unit14
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Gren";
						rank="PRIVATE";
						position[]={0,-6,0};
					};
					class Unit15
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Medic";
						rank="PRIVATE";
						position[]={0,-7,0};
					};
				};
				class FST_S_CorPDFCold_Antitank
				{
					name="[41st] Totharvis PDF AT Squad";
					faction="FST_CorruptPDF_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Commander";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Standard";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Standard";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_CorruptPDFCold_AT";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Auto";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_CorruptPDFCold_CQB";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Gren";
						rank="PRIVATE";
						position[]={1,-6,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Medic";
						rank="PRIVATE";
						position[]={1,-7,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_CorruptPDFCold_RTO";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Standard";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Standard";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_CorruptPDFCold_AT";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit12
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Auto";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit13
					{
						side=0;
						vehicle="FST_CorruptPDFCold_CQB";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
					class Unit14
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Gren";
						rank="PRIVATE";
						position[]={0,-6,0};
					};
					class Unit15
					{
						side=0;
						vehicle="FST_CorruptPDFCold_Medic";
						rank="PRIVATE";
						position[]={0,-7,0};
					};
				};
			};
			class FST_SmuggledB1s
			{
				name="Smuggled B1 Units";

				class FST_S_SmugB1
				{
					name="[41st] Smuggled B1s";
					faction="FST_CorruptPDF_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_SmugB1_E5";
						rank="PRIVATE";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_SmugB1_E5";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_SmugB1_E5";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_SmugB1_E5";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_SmugB1_E5";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_SmugB1_LMG";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_SmugB1_E5";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_SmugB1_E5";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_SmugB1_E5";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_SmugB1_E5";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_SmugB1_E5";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_SmugB1_LMG";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
			};
		};
	};
};