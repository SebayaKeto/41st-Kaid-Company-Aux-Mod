class CfgPatches
{
	class 41st_CorruptPDF
	{
		requiredAddons[]={"A3_Soft_F"};
		units[]=
		{
			"FST_UmbaranInf_SL",
			"FST_UmbaranInf_Standard",
			"FST_UmbaranInf_Autorifle",
			"FST_UmbaranInf_RTO",
			"FST_UmbaranInf_Medic",
			"FST_UmbaranInf_Marksman",
			"FST_UmbaranInf_EOD",
			"FST_UmbaranInf_AT",
			"FST_UmbaranInf_AA",
			"FST_UmbaranInf_Comm",
			"FST_UmbaranInf_SO"
		};
		weapons[]={};
	};
	author="Tooka";
};
class CfgFactionClasses
{
	class FST_Umbaran_Faction
	{
		displayName="41st Umbaran Units";
		priority=1;
		side=2;
		icon="";
	};
};
class CfgEditorSubcategories
{
	class FST_Umbaran
	{
		displayName = "Umbaran Infantry"; 
	};
};
class CfgFunctions
{
	class FST_UmbaranRandomizers
	{
		class FST_RandomUmbaranScripts
		{
			file="41st_UmbaranUnits\Scripts";
			class umstandard {};
			class umsl {};
			class umrto {};
			class umauto {};
			class ummm {};
			class umeod {};
			class umaa {};
			class umat {};
			class ummedic {};
			class umcommander {};
			class umso {};
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
	class FST_Uniform_Bodyglove;
	class FST_UmbaranBodysuit: FST_Uniform_Bodyglove
	{
		author="Tooka";
		scope=2;
		displayName="[41st] Umbaran Bodysuit";
		nakedUniform="U_BasicBody";
		class ItemInfo: UniformItem
		{
			uniformClass="FST_U_UmbaranBodysuit";
			Armor=10;
			containerClass="Supply100";
			mass=20;
		};
	};
	class FST_UmbaranBodysuit_SO: FST_UmbaranBodysuit
	{
		author="Tooka";
		scope=1;
		displayName="[41st] Umbaran Bodysuit (SpecialOps)";
		nakedUniform="U_BasicBody";
		class ItemInfo: UniformItem
		{
			uniformClass="FST_U_UmbaranBodysuit_SO";
			Armor=10;
			containerClass="Supply100";
			mass=20;
		};
	};
	class ls_imperialVest_isb_heavy_h;
	class FST_UmbaranVest_BASE: ls_imperialVest_isb_heavy_h
	{
		author="Tooka";
		scope=2;
		displayName="[41st] Umbaran Vest (Standard)";
		model="\ls\core\addons\characters_imperial\vests\army\ls_vest_imperial_army_heavy_h.p3d";
		hiddenSelections[]=
		{
			"camo",
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\characters_imperial\vests\army\data\camo_ISB_co.paa",
			"\ls\core\addons\characters_imperial\vests\tacBelt\data\camo1_isb_co.paa",
			"\ls\core\addons\characters_imperial\vests\army\data\tacExtras_co.paa"
		};
		class ItemInfo: VestItem
		{
			uniformModel="\ls\core\addons\characters_imperial\vests\army\ls_vest_imperial_army_heavy_h.p3d";
			hiddenSelections[]=
			{
				"camo",
				"camo1",
				"camo2"
			};
			containerClass="Supply150";
			mass=10;
		};
	};
	class FST_UmbaranVest_Inf: FST_UmbaranVest_BASE
	{
		author="Tooka";
		scope=2;
		displayName="[41st] Umbaran Vest (Infantry)";
		hiddenSelections[]=
		{
			"camo",
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_UmbaranUnits\Data\umbara_vest_infantry.paa",
			"\ls\core\addons\characters_imperial\vests\tacBelt\data\camo1_isb_co.paa",
			"\41st_UmbaranUnits\Data\umbara_vest_extras_infantry.paa"
		};
	};
	class FST_UmbaranVest_Med: FST_UmbaranVest_BASE
	{
		author="Tooka";
		scope=2;
		displayName="[41st] Umbaran Vest (Medic)";
		hiddenSelections[]=
		{
			"camo",
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_UmbaranUnits\Data\umbara_vest_red.paa",
			"\ls\core\addons\characters_imperial\vests\tacBelt\data\camo1_isb_co.paa",
			"\41st_UmbaranUnits\Data\umbara_vest_extras_red.paa"
		};
	};
	class FST_UmbaranVest_Off: FST_UmbaranVest_BASE
	{
		author="Tooka";
		scope=2;
		displayName="[41st] Umbaran Vest (Officer)";
		hiddenSelections[]=
		{
			"camo",
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_UmbaranUnits\Data\umbara_vest_officer.paa",
			"\ls\core\addons\characters_imperial\vests\tacBelt\data\camo1_isb_co.paa",
			"\41st_UmbaranUnits\Data\umbara_vest_extras_officer.paa"
		};
	};
	class FST_UmbaranVest_Comm: FST_UmbaranVest_BASE
	{
		author="Tooka";
		scope=2;
		displayName="[41st] Umbaran Vest (Commander)";
		hiddenSelections[]=
		{
			"camo",
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_UmbaranUnits\Data\umbara_vest_commander.paa",
			"\ls\core\addons\characters_imperial\vests\tacBelt\data\camo1_isb_co.paa",
			"\41st_UmbaranUnits\Data\umbara_vest_extras_commander.paa"
		};
	};
	class FST_UmbaranVest_SO: FST_UmbaranVest_BASE
	{
		author="Tooka";
		scope=2;
		displayName="[41st] Umbaran Vest (Operative)";
		hiddenSelections[]=
		{
			"camo",
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_UmbaranUnits\Data\umbara_vest_specops.paa",
			"\ls\core\addons\characters_imperial\vests\tacBelt\data\camo1_isb_co.paa",
			"\41st_UmbaranUnits\Data\umbara_vest_extras_specops.paa"
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
	class JMSLLTE_back_snowpack_med;
	class FST_Umbaran_Medicpack: JMSLLTE_back_snowpack_med
	{
		author="Tooka";
		scope=2;
		displayName="[41st] Umbaran Medical Pack";
		maximumLoad=250;
		mass=5;
	};
	class FST_bodyGlove;
	class FST_U_UmbaranBodysuit: FST_bodyGlove
	{
		author="Tooka";
		side=0;
		scope=1;
		displayName="[41st] Umbaran Infantry Bodysuit";
		uniformClass="FST_UmbaranBodysuit";
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
				armor=7;
				material=-1;
				name="face_hub";
				passThrough=0.9;
				radius=0.1;
				explosionShielding=0.1;
				minimalHit=0;
			};
			class HitNeck: HitFace
			{
				armor=7;
				material=-1;
				name="neck";
				passThrough=0.9;
				radius=0.1;
				explosionShielding=0.5;
				minimalHit=0;
			};
			class HitHead: HitNeck
			{
				armor=7;
				material=-1;
				name="head";
				passThrough=0.5;
				radius=0.14;
				explosionShielding=0.5;
				minimalHit=0.002;
				depends="HitFace max HitNeck";
			};
			class HitPelvis
			{
				armor=7;
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
				armor=10;
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
				armor=10;
				material=-1;
				name="spine3";
				passThrough=0.7;
				radius=0.18;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.009;
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
			class HitBody
			{
				armor=13;
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
				radius=0.14;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.009;
				depends="0";
			};
		};
		explosionshielding=45;
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
		weapons[]=
		{
            "Throw",
			"Put"
        };
		Items[]={};
		respawnItems[]={};
		linkedItems[]=
		{
			"G_JMSLLTE_None"
		};
		respawnLinkedItems[]={};
		magazines[]={};
		respawnMagazines[]={};
	};
	class FST_UmbaranInf_SL: FST_U_UmbaranBodysuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
		displayName="[41st] Umbaran Infantry (Squad Leader)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		role="Rifleman";
		faction="FST_Umbaran_Faction";
		editorSubcategory="FST_Umbaran";
		weapons[]=
		{
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_UmbaranRandomizers_fnc_umsl;";
		};
	};
	class FST_UmbaranInf_RTO: FST_U_UmbaranBodysuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
		displayName="[41st] Umbaran Infantry (RTO)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		role="Rifleman";
		faction="FST_Umbaran_Faction";
		editorSubcategory="FST_Umbaran";
		weapons[]=
		{
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_UmbaranRandomizers_fnc_umrto;";
		};
	};
	class FST_UmbaranInf_Standard: FST_U_UmbaranBodysuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
		displayName="[41st] Umbaran Infantry (Standard)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		role="Rifleman";
		faction="FST_Umbaran_Faction";
		editorSubcategory="FST_Umbaran";
		weapons[]=
		{
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_UmbaranRandomizers_fnc_umstandard;";
		};
	};
	class FST_UmbaranInf_Autorifle: FST_U_UmbaranBodysuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
		displayName="[41st] Umbaran Infantry (Autorifle)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		role="Rifleman";
		faction="FST_Umbaran_Faction";
		editorSubcategory="FST_Umbaran";
		weapons[]=
		{
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_UmbaranRandomizers_fnc_umauto;";
		};
	};
	class FST_UmbaranInf_Medic: FST_U_UmbaranBodysuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
		displayName="[41st] Umbaran Infantry (Medic)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		role="Rifleman";
		faction="FST_Umbaran_Faction";
		editorSubcategory="FST_Umbaran";
		weapons[]=
		{
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_UmbaranRandomizers_fnc_ummedic;";
		};
	};
	class FST_UmbaranInf_Marksman: FST_U_UmbaranBodysuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
		displayName="[41st] Umbaran Infantry (Marksman)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		role="Rifleman";
		faction="FST_Umbaran_Faction";
		editorSubcategory="FST_Umbaran";
		weapons[]=
		{
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_UmbaranRandomizers_fnc_ummm;";
		};
	};
	class FST_UmbaranInf_EOD: FST_U_UmbaranBodysuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
		displayName="[41st] Umbaran Infantry (EOD)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		role="Rifleman";
		faction="FST_Umbaran_Faction";
		editorSubcategory="FST_Umbaran";
		weapons[]=
		{
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_UmbaranRandomizers_fnc_umeod;";
		};
	};
	class FST_UmbaranInf_AT: FST_U_UmbaranBodysuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
		displayName="[41st] Umbaran Infantry (AT)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		role="Rifleman";
		faction="FST_Umbaran_Faction";
		editorSubcategory="FST_Umbaran";
		weapons[]=
		{
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_UmbaranRandomizers_fnc_umat;";
		};
	};
	class FST_UmbaranInf_AA: FST_U_UmbaranBodysuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
		displayName="[41st] Umbaran Infantry (AA)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		role="Rifleman";
		faction="FST_Umbaran_Faction";
		editorSubcategory="FST_Umbaran";
		weapons[]=
		{
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_UmbaranRandomizers_fnc_umaa;";
		};
	};
	class FST_UmbaranInf_Comm: FST_U_UmbaranBodysuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
		displayName="[41st] Umbaran Infantry (Commander)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		role="Rifleman";
		faction="FST_Umbaran_Faction";
		editorSubcategory="FST_Umbaran";
		weapons[]=
		{
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_UmbaranRandomizers_fnc_umcommander;";
		};
	};
	class FST_U_UmbaranBodysuit_SO: FST_bodyGlove
	{
		author="Tooka";
		side=0;
		scope=1;
		displayName="[41st] Umbaran Infantry Bodysuit";
		uniformClass="FST_UmbaranBodysuit_SO";
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
				armor=20;
				material=-1;
				name="face_hub";
				passThrough=0.9;
				radius=0.1;
				explosionShielding=0.1;
				minimalHit=0;
			};
			class HitNeck: HitFace
			{
				armor=20;
				material=-1;
				name="neck";
				passThrough=0.9;
				radius=0.1;
				explosionShielding=0.5;
				minimalHit=0;
			};
			class HitHead: HitNeck
			{
				armor=20;
				material=-1;
				name="head";
				passThrough=0.5;
				radius=0.14;
				explosionShielding=0.5;
				minimalHit=0.002;
				depends="HitFace max HitNeck";
			};
			class HitPelvis
			{
				armor=20;
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
				armor=20;
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
				armor=24;
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
				armor=24;
				material=-1;
				name="spine3";
				passThrough=0.7;
				radius=0.18;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.009;
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
			class HitBody
			{
				armor=28;
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
				radius=0.14;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.009;
				depends="0";
			};
		};
		explosionshielding=55;
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
		weapons[]=
		{
            "Throw",
			"Put"
        };
		Items[]={};
		respawnItems[]={};
		linkedItems[]=
		{
			"G_JMSLLTE_None"
		};
		respawnLinkedItems[]={};
		magazines[]={};
		respawnMagazines[]={};
	};
	class FST_UmbaranInf_SO: FST_U_UmbaranBodysuit_SO
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
		displayName="[41st] Umbaran Infantry (SpecOP)";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		role="Rifleman";
		faction="FST_Umbaran_Faction";
		editorSubcategory="FST_Umbaran";
		weapons[]=
		{
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_UmbaranRandomizers_fnc_umso;";
		};
	};
};
class cfgGroups
{
	class EAST
	{
		name="OPFOR";
		
		class FST_Umbaran_Faction
		{
			name="41st Umbaran Units";
			
			class FST_Umbaran
			{
				name = "Umbaran Infantry";
				
				class FST_S_UM_Fireteam
				{
					name="[41st] Umbaran Fireteam";
					faction="FST_Umbaran_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_UmbaranInf_SL";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_UmbaranInf_Standard";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_UmbaranInf_Medic";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_UmbaranInf_RTO";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_UmbaranInf_Autorifle";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_UmbaranInf_EOD";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
				};
				class FST_S_UM_Antiair
				{
					name="[41st] Umbaran Antiair Team";
					faction="FST_Umbaran_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_UmbaranInf_RTO";
						rank="CORPORAL";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_UmbaranInf_AA";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_UmbaranInf_AA";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
				};
				class FST_S_UM_Markers
				{
					name="[41st] Umbaran Marksman Team";
					faction="FST_Umbaran_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_UmbaranInf_RTO";
						rank="CORPORAL";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_UmbaranInf_Marksman";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_UmbaranInf_Marksman";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
				};
				class FST_S_UM_Standard
				{
					name="[41st] Umbaran Standard Squad";
					faction="FST_Umbaran_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_UmbaranInf_SL";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_UmbaranInf_Standard";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_UmbaranInf_Standard";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_UmbaranInf_Standard";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_UmbaranInf_Autorifle";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_UmbaranInf_EOD";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_UmbaranInf_EOD";
						rank="PRIVATE";
						position[]={1,-6,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_UmbaranInf_Medic";
						rank="PRIVATE";
						position[]={1,-7,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_UmbaranInf_RTO";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_UmbaranInf_Standard";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_UmbaranInf_Standard";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_UmbaranInf_Standard";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit12
					{
						side=0;
						vehicle="FST_UmbaranInf_Autorifle";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit13
					{
						side=0;
						vehicle="FST_UmbaranInf_EOD";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
					class Unit14
					{
						side=0;
						vehicle="FST_UmbaranInf_EOD";
						rank="PRIVATE";
						position[]={0,-6,0};
					};
					class Unit15
					{
						side=0;
						vehicle="FST_UmbaranInf_Medic";
						rank="PRIVATE";
						position[]={0,-7,0};
					};
				};
				class FST_S_UM_Antitank
				{
					name="[41st] Umbaran AT Squad";
					faction="FST_Umbaran_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_UmbaranInf_SL";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_UmbaranInf_Standard";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_UmbaranInf_Standard";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_UmbaranInf_AT";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_UmbaranInf_Autorifle";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_UmbaranInf_EOD";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_UmbaranInf_EOD";
						rank="PRIVATE";
						position[]={1,-6,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_UmbaranInf_Medic";
						rank="PRIVATE";
						position[]={1,-7,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_UmbaranInf_RTO";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit9
					{
						side=0;
						vehicle="FST_UmbaranInf_Standard";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit10
					{
						side=0;
						vehicle="FST_UmbaranInf_Standard";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit11
					{
						side=0;
						vehicle="FST_UmbaranInf_AT";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit12
					{
						side=0;
						vehicle="FST_UmbaranInf_Autorifle";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit13
					{
						side=0;
						vehicle="FST_UmbaranInf_EOD";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
					class Unit14
					{
						side=0;
						vehicle="FST_UmbaranInf_EOD";
						rank="PRIVATE";
						position[]={0,-6,0};
					};
					class Unit15
					{
						side=0;
						vehicle="FST_UmbaranInf_Medic";
						rank="PRIVATE";
						position[]={0,-7,0};
					};
				};
				class FST_S_UM_SOPair
				{
					name="[41st] Umbaran SpecOps Pair";
					faction="FST_Umbaran_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_UmbaranInf_SO";
						rank="CORPORAL";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_UmbaranInf_SO";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
				};
				class FST_S_UM_SOTeam
				{
					name="[41st] Umbaran SpecOps Team";
					faction="FST_Umbaran_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_UmbaranInf_SO";
						rank="CORPORAL";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_UmbaranInf_SO";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_UmbaranInf_SO";
						rank="CORPORAL";
						position[]={1,-1,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_UmbaranInf_SO";
						rank="CORPORAL";
						position[]={0,-1,0};
					};
				};
			};
		};
	};
};