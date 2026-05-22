class CfgPatches
{
	class 41st_CorruptPDF
	{
		requiredAddons[]={"A3_Soft_F"};
		units[]=
		{
			
			"FST_MandoV_Commander",
			"FST_MandoV_Standard",
			"FST_MandoV_RTO",
			"FST_MandoV_Auto",
			"FST_MandoV_CQB",
			"FST_MandoV_Marksman",
			"FST_MandoV_Sniper",
			"FST_MandoV_AT",
			"FST_MandoV_AA",
			"FST_MandoV_EOD",
			"FST_MandoV_Grenadier",
			"FST_MandoV_Flame"

		};
		weapons[]={};
	};
	author="Tooka";
};
class CfgFactionClasses
{
	class FST_Mando_Faction
	{
		displayName="41st Mandalorians";
		priority=1;
		side=2;
		icon="";
	};
};
class CfgEditorSubcategories
{
	class FST_ClanVarad
	{
		displayName = "Clan Varad"; 
	};
	class FST_ClanOrdo
	{
		displayName = "Clan Ordo"; 
	};
};
class CfgFunctions
{
	class FST_MandoRandomizers
	{
		class FST_RandomMandoScripts
		{
			file="41st_Mandos\Scripts";
			class varadleader {};
			class varadsoldier {};
			class varadcoordinator {};
			class varadsuppressor {};
			class varadrusher {};
			class varadhunter {};
			class varadassassin {};
			class varaddestroyer {};
			class varadlauncher {};
			class varadbomber {};
			class varadgrenadier {};
			class varadflamer {};
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
    class V_rebreatherB;
	class ItemCore;
	class ItemInfo;
	class ls_mandalorianUniform;
    class FST_MandoUndersuitUni: ls_mandalorianUniform
	{
		scope=2;
		author="Tooka";
		displayName="[41st] Mandalorian Undersuit";
		picture="\ls\core\addons\characters_mandalorian\data\ui\undersuit_ui_ca.paa";
		class ItemInfo: UniformItem
		{
			uniformClass="FST_U_MandoUndersuit";
			containerClass="Supply150";
			mass=40;
		};
	};
	class FST_Westar_M5;
	class FST_Westar_M5_Scoped: FST_Westar_M5
	{
		scope=1;
		class linkedItems
		{
			class Optic
			{
				slot="CowsSlot";
				item="FST_Scope_Westar_M5";
			};
		};
	};
	class FST_Westar35_SA_Pistol;
	class FST_WestarPistol_Light: FST_Westar35_SA_Pistol
	{
		scope=1;
		class linkedItems
		{
			class Pointer
			{
				slot="PointerSlot";
				item="FST_Attachment_Light_Normal_White_pistol";
			};
		};
	};
	class DBA_FlamerThrower_AC;
	class FST_MandoWristFlamer: DBA_FlamerThrower_AC
	{
		author="Tooka";
		scope=1;
		displayname="[41st] Mandalorian Wrist Flamethrower";
		modes[]=
		{
			"FullAuto"
		};
		class FullAuto: Mode_FullAuto
		{
			aiRateOfFireDistance=900;
			aiRateOfFireDispersion=1;
			autoFire=1;
			dispersion="2*0.00087";
			burst="";
			maxRange=100;
			maxRangeProbab=0.3;
			midRange=25;
			midRangeProbab=0.6;
			minRange=5;
			minRangeProbab=1;
			reloadTime=0.21428572;
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
	class FST_Backpack_Jumppack_CQB;
	class FST_MandoJumppack: FST_Backpack_Jumppack_CQB
	{
		author="Tooka";
		scope=2;
		displayname="[41st] Mandalorian Jetpack";
		maximumLoad=200;
		mass=50;
        model="\MRC\JLTS\characters\CloneArmor2\CloneJumppackJT12.p3d";
        picture="\MRC\JLTS\characters\CloneArmor2\data\ui\Clone_jumppack_jt12_ui_ca.paa";
        hiddenSelections[]=
        {
            "camo1"
        };
        hiddenSelectionsTextures[]=
        {
            "\MRC\JLTS\characters\CloneArmor2\data\Clone_PurgeTrooper_jumppack_JT12_co.paa"
        };
	};
	class JMSLLTE_back_stcape;
	class FST_MandoCape: JMSLLTE_back_stcape
	{
		author="Tooka";
		scope=2;
		displayname="[41st] Mandalorian Cape";
		maximumLoad=250;
		mass=10;
	};
	class ls_mandalorianBackpack_heavy;
	class FST_MandoBackpack_Heavy: ls_mandalorianBackpack_heavy
	{
		author="Tooka";
		scope=2;
		displayname="[41st] Mandalorian Backpack (Heavy)";
		maximumLoad=450;
		mass=20;
	};
	class FST_MandoVBack_SC: FST_MandoJumppack
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_FST_grenade_smoke_orange_mag
			{
				name="FST_grenade_smoke_orange_mag";
				count=1;
			};
			class _xx_IDA_grenade_Detonator_mag
			{
				name="IDA_grenade_Detonator_mag";
				count=1;
			};
			class _xx_FST_blaster_cell_Westar_Red
			{
				name="FST_blaster_cell_Westar_Red";
				count=15;
			};
			class _xx_FST_pistol_westar35sa_Mag_Red
			{
				name="FST_pistol_westar35sa_Mag_Red";
				count=15;
			};
		};
	};
	class JMSLLTE_back_stormband_v2;
	class FST_MandoVBack_Gren: JMSLLTE_back_stormband_v2
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_3AS_1UGL_MK54_HE_shell
			{
				name="3AS_1UGL_MK54_HE_shell";
				count=2;
			};
			class _xx_FST_HE_LauncherGrenade
			{
				name="FST_HE_LauncherGrenade";
				count=2;
			};
			class _xx_FST_blaster_cell_Westar_Red
			{
				name="FST_blaster_cell_Westar_Red";
				count=15;
			};
		};
	};
	class 3AS_B_Imperial_Stormtrooper_Backpack_Respirator_F;
	class FST_MandoVBack_Fire: 3AS_B_Imperial_Stormtrooper_Backpack_Respirator_F
	{
		author = "Tooka";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 0;
		class TransportItems
		{
			class _xx_DBA_B2Flamer_Mag
			{
				name="DBA_B2Flamer_Mag";
				count=5;
			};
		};
	};
	class FST_U_CIS_Light;
	class FST_U_MandoUndersuit: FST_U_CIS_Light
	{
		scope=1;
		author="Tooka";
		displayName="[41st] Mandalorian Undersuit";
		model="\A3\Characters_F_Beta\INDEP\ia_soldier_02.p3d";
		uniformClass="FST_MandoUndersuitUni";
		hiddenSelections[]=
		{
			"camo",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\characters_mandalorian\uniforms\undersuit\data\undersuit_co.paa"
		};
		nakedUnifrom="U_BasicBody";
		class HitPoints
		{
			class HitFace
			{
				armor=1;
				material=-1;
				name="face_hub";
				passThrough=0.9;
				radius=0.1;
				explosionShielding=0.1;
				minimalHit=0;
			};
			class HitNeck: HitFace
			{
				armor=1;
				material=-1;
				name="neck";
				passThrough=0.9;
				radius=0.1;
				explosionShielding=0.5;
				minimalHit=0;
			};
			class HitHead: HitNeck
			{
				armor=3;
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
				armor=2;
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
				armor=2;
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
				armor=3;
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
				armor=3;
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
				armor=4;
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
		explosionshielding=45;
	};
	class FST_MandoV_Commander: FST_U_MandoUndersuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_MandoVBack_SC";
		scope=2;
		scopeCurator=2;
        side=0;
		displayName="[41st] Clan Varad Leader";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_MandoUndersuitUni";
		role="Rifleman";
		faction="FST_Mando_Faction";
		editorSubcategory="FST_ClanVarad";
		weapons[]=
		{
			"FST_Westar_M5_Scoped",
			"FST_WestarPistol_Light",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Double"
		};
		linkedItems[]=
		{
			"ls_mandalorianVest_standard",
			"ls_radios_hush98_aurebesh",
			"ls_mandalorian_rangefinder",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"ls_mandalorianHelmet_elite"
		};
		magazines[]=
		{
			"FST_blaster_cell_Westar_Red",
			"FST_pistol_westar35sa_Mag_Red"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_MandoRandomizers_fnc_varadleader;";
		};
	};
	class FST_MandoV_RTO: FST_U_MandoUndersuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
        side=0;
		displayName="[41st] Clan Varad Coordinator";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_MandoUndersuitUni";
		role="Rifleman";
		faction="FST_Mando_Faction";
		editorSubcategory="FST_ClanVarad";
		weapons[]=
		{
			"FST_Westar_M5_Scoped",
			"FST_WestarPistol_Light",
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_MandoRandomizers_fnc_varadcoordinator;";
		};
	};
	class FST_MandoV_Standard: FST_U_MandoUndersuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
        side=0;
		displayName="[41st] Clan Varad Soldier";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_MandoUndersuitUni";
		role="Rifleman";
		faction="FST_Mando_Faction";
		editorSubcategory="FST_ClanVarad";
		weapons[]=
		{
			"FST_Westar_M5_Scoped",
			"FST_WestarPistol_Light",
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_MandoRandomizers_fnc_varadsoldier;";
		};
	};
	class FST_MandoV_Auto: FST_U_MandoUndersuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
        side=0;
		displayName="[41st] Clan Varad Suppressor";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_MandoUndersuitUni";
		role="Rifleman";
		faction="FST_Mando_Faction";
		editorSubcategory="FST_ClanVarad";
		weapons[]=
		{
			"FST_Westar_M5_Scoped",
			"FST_WestarPistol_Light",
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_MandoRandomizers_fnc_varadsuppressor;";
		};
	};
	class FST_MandoV_CQB: FST_U_MandoUndersuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
        side=0;
		displayName="[41st] Clan Varad Rusher";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_MandoUndersuitUni";
		role="Rifleman";
		faction="FST_Mando_Faction";
		editorSubcategory="FST_ClanVarad";
		weapons[]=
		{
			"FST_Westar_M5_Scoped",
			"FST_WestarPistol_Light",
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_MandoRandomizers_fnc_varadrusher;";
		};
	};
	class FST_MandoV_Marksman: FST_U_MandoUndersuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
        side=0;
		displayName="[41st] Clan Varad Hunter";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_MandoUndersuitUni";
		role="Rifleman";
		faction="FST_Mando_Faction";
		editorSubcategory="FST_ClanVarad";
		weapons[]=
		{
			"FST_Westar_M5_Scoped",
			"FST_WestarPistol_Light",
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_MandoRandomizers_fnc_varadhunter;";
		};
	};
	class FST_MandoV_Sniper: FST_U_MandoUndersuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
        side=0;
		displayName="[41st] Clan Varad Assassin";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_MandoUndersuitUni";
		role="Rifleman";
		faction="FST_Mando_Faction";
		editorSubcategory="FST_ClanVarad";
		weapons[]=
		{
			"FST_Westar_M5_Scoped",
			"FST_WestarPistol_Light",
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_MandoRandomizers_fnc_varadassassin;";
		};
	};
	class FST_MandoV_AT: FST_U_MandoUndersuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
        side=0;
		displayName="[41st] Clan Varad Destroyer";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_MandoUndersuitUni";
		role="Rifleman";
		faction="FST_Mando_Faction";
		editorSubcategory="FST_ClanVarad";
		weapons[]=
		{
			"FST_Westar_M5_Scoped",
			"FST_WestarPistol_Light",
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_MandoRandomizers_fnc_varaddestroyer;";
		};
	};
	class FST_MandoV_AA: FST_U_MandoUndersuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
        side=0;
		displayName="[41st] Clan Varad Launcher";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_MandoUndersuitUni";
		role="Rifleman";
		faction="FST_Mando_Faction";
		editorSubcategory="FST_ClanVarad";
		weapons[]=
		{
			"FST_Westar_M5_Scoped",
			"FST_WestarPistol_Light",
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_MandoRandomizers_fnc_varadlauncher;";
		};
	};
	class FST_MandoV_EOD: FST_U_MandoUndersuit
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		scope=2;
		scopeCurator=2;
        side=0;
		displayName="[41st] Clan Varad Bomber";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_MandoUndersuitUni";
		role="Rifleman";
		faction="FST_Mando_Faction";
		editorSubcategory="FST_ClanVarad";
		weapons[]=
		{
			"FST_Westar_M5_Scoped",
			"FST_WestarPistol_Light",
			"Throw",
			"Put"
		};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_MandoRandomizers_fnc_varadbomber;";
		};
	};
	class FST_MandoV_Grenadier: FST_MandoV_Commander
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_MandoVBack_Gren";
		scope=2;
		scopeCurator=2;
        side=0;
		displayName="[41st] Clan Varad Grenadier";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_MandoUndersuitUni";
		role="Rifleman";
		faction="FST_Mando_Faction";
		editorSubcategory="FST_ClanVarad";
		weapons[]=
		{
			"FST_Westar_M5_UGL",
			"3AS_FE20_GrenadeLauncherPistol",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Double"
		};
		linkedItems[]=
		{
			"ls_mandalorianVest_standard",
			"ls_radios_hush98_aurebesh",
			"ls_mandalorian_rangefinder",
			"ItemWatch",
			"ItemGPS",
			"ItemMap",
			"ls_mandalorianHelmet_elite"
		};
		magazines[]=
		{
			"FST_blaster_cell_Westar_Red",
			"3AS_1UGL_MK54_HE_shell",
			"FST_HE_LauncherGrenade"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_MandoRandomizers_fnc_varadgrenadier;";
		};
	};
	class FST_MandoV_Flame: FST_MandoV_Commander
	{
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO",
		};
		backpack="FST_MandoVBack_Fire";
		scope=2;
		scopeCurator=2;
        side=0;
		displayName="[41st] Clan Varad Flamer";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="U_BasicBody";
		uniformClass="FST_MandoUndersuitUni";
		role="Rifleman";
		faction="FST_Mando_Faction";
		editorSubcategory="FST_ClanVarad";
		weapons[]=
		{
			"FST_MandoWristFlamer",
			"FST_Westar35",
			"Throw",
			"Put"
		};
		Items[]=
		{
			"WBK_HeadLampItem_Double"
		};
		linkedItems[]=
		{
			"ls_mandalorianVest_standard",
			"ls_radios_hush98_aurebesh",
			"ls_mandalorian_rangefinder",
			"ItemGPS",
			"ItemMap",
			"ls_mandalorianHelmet_stalker"
		};
		magazines[]=
		{
			"DBA_B2Flamer_Mag"
		};
		class EventHandlers
		{
			init= "(_this select 0) spawn FST_MandoRandomizers_fnc_varadflamer;";
		};
	};
};
class cfgGroups
{
	class EAST
	{
		name="OPFOR";
		
		class FST_Mando_Faction
		{
			name="41st Mandalorians";
			
			class FST_ClanVarad
			{
				name = "Clan Varad";
				
				class FST_S_MandoV_Assault
				{
					name="[41st] Clan Varad Assault Squad";
					faction="FST_Mando_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_MandoV_Commander";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_MandoV_Standard";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_MandoV_Standard";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_MandoV_CQB";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_MandoV_Auto";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_MandoV_RTO";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_MandoV_Standard";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_MandoV_Standard";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_MandoV_Auto";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
				};
				class FST_S_MandoV_Guard
				{
					name="[41st] Clan Varad Guard Squad";
					faction="FST_Mando_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_MandoV_Commander";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_MandoV_CQB";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_MandoV_CQB";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_MandoV_Flame";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_MandoV_Auto";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_MandoV_RTO";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_MandoV_Standard";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit7
					{
						side=0;
						vehicle="FST_MandoV_Marksman";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit8
					{
						side=0;
						vehicle="FST_MandoV_AA";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
				};
				class FST_S_MandoV_Suppress
				{
					name="[41st] Clan Varad Suppression Squad";
					faction="FST_Mando_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_MandoV_Commander";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_MandoV_Auto";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_MandoV_Auto";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_MandoV_Auto";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_MandoV_RTO";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_MandoV_Standard";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_MandoV_Standard";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
				};
				class FST_S_MandoV_Explosive
				{
					name="[41st] Clan Varad Explosive Squad";
					faction="FST_Mando_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_MandoV_Commander";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_MandoV_EOD";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_MandoV_AT";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="FST_MandoV_AT";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="FST_MandoV_RTO";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit5
					{
						side=0;
						vehicle="FST_MandoV_Grenadier";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit6
					{
						side=0;
						vehicle="FST_MandoV_CQB";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
				};
				class FST_S_MandoV_Sniper
				{
					name="[41st] Clan Varad Sniper Team";
					faction="FST_Mando_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_MandoV_RTO";
						rank="CORPORAL";
						position[]={0,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_MandoV_Marksman";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="FST_MandoV_Sniper";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
				};
				class FST_S_MandoV_AA
				{
					name="[41st] Clan Varad Antiar Pair";
					faction="FST_Mando_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="FST_MandoV_AA";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="FST_MandoV_AA";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
				};
			};
		};
	};
};