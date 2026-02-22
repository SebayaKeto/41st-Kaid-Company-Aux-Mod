class CfgPatches
{
	class 41st_BaseCustom
	{
		requiredAddons[]={"A3_Soft_F"};
		units[]=
		{
			
			"FST_BaseCustomBlue",
			"FST_BaseCustomRed",
			"FST_BaseCustomGreen",
			"FST_BaseCustomCiv",

		};
	};
	author="Tooka";
};
class CfgFactionClasses
{
    class FST_CustomsGroup
    {
        displayName="41st Elite Corps Customs";
		priority=1;
		side=3;
		icon=""; 
    };
};
class CfgEditorSubcategories
{
	class FST_BaseSub
	{
		displayName = "Base Custom Unit"; 
	};
};
class CfgIdentities
{
    class NPCCBlue
    {
        name="NPC";
        face="WhiteHead_01";
        glasses="None";
        speaker="Male09ENG";
        pitch=1;
    };
};
class CfgVehicles
{
    class C_man_1;
    class O_soldier_base_F;
	class O_Soldier_F: O_soldier_base_F
	{
		class HitPoints;
	};
    class FST_BaseCustomBlue: O_Soldier_F
    {
        author="Tooka";
        scope=2;
        scopeCurator=0;
        side=1;
        uniformClass="FST_Uniform_Bodyglove";
        faction="FST_CustomsGroup";
		editorSubcategory="FST_BaseSub";
        displayName="Custom Friendly Unit";
        Backpack="";
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
    class FST_BaseCustomRed: O_Soldier_F
    {
        author="Tooka";
        scope=2;
        scopeCurator=0;
        side=0;
        uniformClass="FST_Uniform_Bodyglove";
        faction="FST_CustomsGroup";
		editorSubcategory="FST_BaseSub";
        displayName="Custom Enemy Unit";
        Backpack="";
        weapons[]=
        {
            "Throw",
			"Put"
        };
		identityTypes[]={};
        Items[]={};
		respawnItems[]={};
		linkedItems[]={};
		respawnLinkedItems[]={};
		magazines[]={};
		respawnMagazines[]={};
    };
    class FST_BaseCustomGreen: O_Soldier_F
    {
        author="Tooka";
        scope=2;
        scopeCurator=0;
        side=2;
        uniformClass="FST_Uniform_Bodyglove";
        faction="FST_CustomsGroup";
		editorSubcategory="FST_BaseSub";
        displayName="Custom Independant Unit";
        Backpack="";
        weapons[]=
        {
            "Throw",
			"Put"
        };
		identityTypes[]={};
        Items[]={};
		respawnItems[]={};
		linkedItems[]={};
		respawnLinkedItems[]={};
		magazines[]={};
		respawnMagazines[]={};
    };
    class FST_BaseCustomCiv: C_man_1
    {
        author="Tooka";
        scope=2;
        scopeCurator=0;
        uniformClass="FST_Uniform_Bodyglove";
        faction="FST_CustomsGroup";
		editorSubcategory="FST_BaseSub";
        displayName="Custom Civilian Unit";
        Backpack="";
        weapons[]=
        {
            "Throw",
			"Put"
        };
		identityTypes[]={};
        Items[]={};
		respawnItems[]={};
		linkedItems[]={};
		respawnLinkedItems[]={};
		magazines[]={};
		respawnMagazines[]={};
    };
};
