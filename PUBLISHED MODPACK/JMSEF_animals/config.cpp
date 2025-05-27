class CfgPatches
{
	class JMSEF_animals_mod
	{
		author="JMax";
		units[]=
		{
			"JMSEF_animals_varren_o",
			"JMSEF_animals_var_bers_o",
			"JMSEF_animals_var_alpha_o",
			"FST_41st_Walker",
			"FST_41st_Crawler",
			"FST_41st_Runner",
			"FST_41st_Shooter",
			"FST_41st_Shambler"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"dev_common",
		};
	};
};
class CfgSounds
{
	class JMSEF_animals_varren_attack
	{
		name="JMSEF_animals_varren_attack";
		sound[]=
		{
			"dev_mutant_form939\snd\attack.ogg",
			4,
			1,
			100
		};
		titles[]=
		{
			0,
			""
		};
	};
	class JMSEF_animals_varren_spawn: JMSEF_animals_varren_attack
	{
		name="JMSEF_animals_varren_spawn";
		sound[]=
		{
			"dev_mutant_form939\snd\spawn.ogg",
			4,
			1
		};
	};
	class JMSEF_animals_varren_stalk: JMSEF_animals_varren_attack
	{
		name="JMSEF_animals_varren_stalk";
		sound[]=
		{
			"dev_mutant_form939\snd\stalk.ogg",
			4,
			1
		};
	};
};
class CfgFunctions
{
	class JMSEF_animals_varren
	{
		class functions
		{
			class functions
			{
				file="\JMSEF_animals\functions.sqf";
				preInit=1;
			};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class JMSEF_animals_varren
	{
		init="call compile preProcessFileLineNumbers '\JMSEF_animals\cba.sqf'";
	};
};
class CfgVehicles
{
	class CAManBase;
	class Zombie_O_Walker_CSAT;
	class Zombie_O_RunnerAngry_CSAT;
	class Zombie_O_Crawler_CSAT;
	class Zombie_O_Shooter_CSAT;
	class Zombie_O_Shambler_CSAT;
	class dev_mutant_base: CAManBase
	{
		class EventHandlers;
	};
	class JMSEF_animals_varren_o: dev_mutant_base
	{
		side=0;
		scope=2;
		scopecurator=2;
		displayName="[41st] Gulanthar";
		editorPreview="";
		model="\JMSEF_animals\varren.p3d";
		moves="CfgMovesForm939";
		movesFatigue="CfgMovesForm939";
		gestures="CfgGesturesForm939";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Creatures_Subfaction";
		armor=100;
		armorStructural=10;
		class HitPoints
		{
			class Head
			{
				name="head";
				depends="0";
				armor=1;
				explosionShielding=0;
				material=-1;
				minimalHit=0.0099999998;
				passThrough=0.1;
				radius=0.2;
			};
			class Torso: Head
			{
				armor=2;
				name="torso";
			};
			class Extremities: Head
			{
				armor=3;
				name="extremities";
			};
		};
		class Wounds
		{
			tex[]={};
			mat[]={};
		};
		class EventHandlers: EventHandlers
		{
			class dev_behave
			{
				init="[_this#0] spawn dev_fnc_varren_behave";
			};
		};
	};
	class FST_41st_Walker: Zombie_O_Walker_CSAT 
    {
        author=Ruby;
        displayName = "[41st] Clone Trooper Walker Zombie";
        scope = 2;
        scopeCurator = 2;
        faction="FST_Zombies_Faction";
        editorSubcategory="FST_Zombies_Subfaction";
        identityTypes[] = {""};
        uniformClass = "FST_Trooper_SERE";
        model = "\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
        hiddenSelections[] = {"camo1", "camo2", "insignia"};
        hiddenSelectionsTextures[] = 
        {
        "41st_Armor\Data\Uniforms\FST_P2_BodyUpper_SERE.paa",
        "41st_Armor\Data\Uniforms\FST_P2_BodyLower_SERE.paa",
        };
        WBK_ZombiesOriginalFactionClass = "";
        linkedItems[]=
        {
            "FST_P2_Helmet_Sere",
        };
        respawnLinkedItems[]=
        {
            "FST_P2_Helmet_Sere",
        };
    };
	class FST_41st_Runner: Zombie_O_RunnerAngry_CSAT 
    {
        author=Ruby;
        displayName = "[41st] Clone Trooper Runner Zombie";
        scope = 2;
        scopeCurator = 2;
        faction="FST_Zombies_Faction";
        editorSubcategory="FST_Zombies_Subfaction";
        identityTypes[] = {""};
        uniformClass = "FST_Trooper_SERE";
        model = "\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
        hiddenSelections[] = {"camo1", "camo2", "insignia"};
        hiddenSelectionsTextures[] = 
        {
        "41st_Armor\Data\Uniforms\FST_P2_BodyUpper_SERE.paa",
        "41st_Armor\Data\Uniforms\FST_P2_BodyLower_SERE.paa",
        };
        WBK_ZombiesOriginalFactionClass = "";
        linkedItems[]=
        {
            "FST_P2_Helmet_Sere",
        };
        respawnLinkedItems[]=
        {
            "FST_P2_Helmet_Sere",
        };
    };
	class FST_41st_Crawler: Zombie_O_Crawler_CSAT 
    {
        author=Ruby;
        displayName = "[41st] Clone Trooper Crawler Zombie";
        scope = 2;
        scopeCurator = 2;
		faction="FST_Zombies_Faction";
        editorSubcategory="FST_Zombies_Subfaction";
        identityTypes[] = {""};
        uniformClass = "FST_Trooper_SERE";
        model = "\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
        hiddenSelections[] = {"camo1", "camo2", "insignia"};
        hiddenSelectionsTextures[] = 
        {
        "41st_Armor\Data\Uniforms\FST_P2_BodyUpper_SERE.paa",
        "41st_Armor\Data\Uniforms\FST_P2_BodyLower_SERE.paa",
        };
        WBK_ZombiesOriginalFactionClass = "";
        linkedItems[]=
        {
            "FST_P2_Helmet_Sere",
        };
        respawnLinkedItems[]=
        {
            "FST_P2_Helmet_Sere",
        };
    };
	class FST_41st_Shooter: Zombie_O_Shooter_CSAT 
    {
        author=Ruby;
        displayName = "[41st] Clone Trooper Shooter Zombie";
        scope = 2;
        scopeCurator = 2;
		faction="FST_Zombies_Faction";
        editorSubcategory="FST_Zombies_Subfaction";
        identityTypes[] = {""};
        uniformClass = "FST_Trooper_SERE";
        model = "\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
        hiddenSelections[] = {"camo1", "camo2", "insignia"};
        hiddenSelectionsTextures[] = 
        {
        "41st_Armor\Data\Uniforms\FST_P2_BodyUpper_SERE.paa",
        "41st_Armor\Data\Uniforms\FST_P2_BodyLower_SERE.paa",
        };
        WBK_ZombiesOriginalFactionClass = "";
        linkedItems[]=
        {
            "FST_P2_Helmet_Sere",
        };
        respawnLinkedItems[]=
        {
            "FST_P2_Helmet_Sere",
        };
    };
	class FST_41st_Shambler: Zombie_O_Shambler_CSAT 
    {
        author=Ruby;
        displayName = "[41st] Clone Trooper Shambler Zombie";
        scope = 2;
        scopeCurator = 2;
        faction="FST_Zombies_Faction";
        editorSubcategory="FST_Zombies_Subfaction";
        identityTypes[] = {""};
        uniformClass = "FST_Trooper_SERE";
        model = "\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
        hiddenSelections[] = {"camo1", "camo2", "insignia"};
        hiddenSelectionsTextures[] = 
        {
        "41st_Armor\Data\Uniforms\FST_P2_BodyUpper_SERE.paa",
        "41st_Armor\Data\Uniforms\FST_P2_BodyLower_SERE.paa",
        };
        WBK_ZombiesOriginalFactionClass = "";
        linkedItems[]=
        {
            "FST_P2_Helmet_Sere",
        };
        respawnLinkedItems[]=
        {
            "FST_P2_Helmet_Sere",
        };
    };
	class JMSEF_animals_var_bers_o: JMSEF_animals_varren_o
	{
		side=0;
		scope=2;
		scopecurator=2;
		displayName="[41st] Gulanthar Berserker";
		editorPreview="";
		model="\JMSEF_animals\varren_bers.p3d";
		moves="CfgMovesForm939";
		movesFatigue="CfgMovesForm939";
		gestures="CfgGesturesForm939";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Creatures_Subfaction";
		armor=120;
		armorStructural=30;
		class HitPoints
		{
			class Head
			{
				name="head";
				depends="0";
				armor=1;
				explosionShielding=0;
				material=-1;
				minimalHit=0.0099999998;
				passThrough=0.1;
				radius=0.2;
			};
			class Torso: Head
			{
				armor=2;
				name="torso";
			};
			class Extremities: Head
			{
				armor=3;
				name="extremities";
			};
		};
	};
	class JMSEF_animals_var_alpha_o: JMSEF_animals_varren_o
	{
		side=0;
		scope=2;
		scopecurator=2;
		displayName="[41st] Gulanthar Alpha";
		editorPreview="";
		model="\JMSEF_animals\varren_scar.p3d";
		moves="CfgMovesForm939";
		movesFatigue="CfgMovesForm939";
		gestures="CfgGesturesForm939";
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Creatures_Subfaction";
		armor=150;
		armorStructural=30;
		class HitPoints
		{
			class Head
			{
				name="head";
				depends="0";
				armor=1;
				explosionShielding=0;
				material=-1;
				minimalHit=0.0099999998;
				passThrough=0.1;
				radius=0.2;
			};
			class Torso: Head
			{
				armor=2;
				name="torso";
			};
			class Extremities: Head
			{
				armor=2;
				name="extremities";
			};
		};
	};
};
class cfgGroups
{
	class EAST
	{
		name="OPFOR";
		
		class FST_Creature
		{
			name="41st Creatures";
			
			class FST_Creature_Standard
			{
				name="Infantry";
				
				class FST_Gulanthar_Pack
				{
					name="[41st] Gulanthar Pack";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="JMSEF_animals_var_alpha_o";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="JMSEF_animals_var_bers_o";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="JMSEF_animals_var_bers_o";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="JMSEF_animals_var_bers_o";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=0;
						vehicle="JMSEF_animals_varren_o";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=0;
						vehicle="JMSEF_animals_varren_o";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=0;
						vehicle="JMSEF_animals_varren_o";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=0;
						vehicle="JMSEF_animals_varren_o";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=0;
						vehicle="JMSEF_animals_varren_o";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=0;
						vehicle="JMSEF_animals_varren_o";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=0;
						vehicle="JMSEF_animals_varren_o";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=0;
						vehicle="JMSEF_animals_varren_o";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
				class FST_Gulanthar_Berserker_Group
				{
					name="[41st] Gulanthar Berserker Party";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="JMSEF_animals_var_bers_o";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="JMSEF_animals_var_bers_o";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="JMSEF_animals_var_bers_o";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=0;
						vehicle="JMSEF_animals_var_bers_o";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit4
					{
						side=0;
						vehicle="JMSEF_animals_var_bers_o";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit5
					{
						side=0;
						vehicle="JMSEF_animals_var_bers_o";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
				};
				class FST_Gulanthar_Alpha_Group
				{
					name="[41st] Gulanthar Alpha Party";
					faction="FST_BattleDroids_Faction";
					side=0;
					class Unit0
					{
						side=0;
						vehicle="JMSEF_animals_var_alpha_o";
						rank="SERGEANT";
						position[]={0,-0,0};
					};
					class Unit1
					{
						side=0;
						vehicle="JMSEF_animals_var_alpha_o";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit2
					{
						side=0;
						vehicle="JMSEF_animals_var_alpha_o";
						rank="PRIVATE";
						position[]={1,-0,0};
					};
					class Unit3
					{
						side=0;
						vehicle="JMSEF_animals_var_alpha_o";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
				};
			};
		};
	};
};
