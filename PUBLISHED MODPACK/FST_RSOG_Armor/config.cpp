class CfgPatches
{
	class 41st_RSOG_Customs
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
			"JLTS_characters_CloneArmor",
			"3AS_Characters_Commando",
			"3AS_Characters_Clones_Headgear"
		};
    };
};

class CfgWeapons
{
    class UniformItem;
	class ItemCore;
	class HeadgearItem;
	class H_HelmetSpecB;
	class JLTS_CloneHelmetP2;
	class JLTS_CloneHelmetBARC;
	class JLTS_CloneHelmetAB;
	class ls_gar_phase1Pilot_helmet;
	class V_PlateCarrier1_rgr;
	class VestItem;

   class FST_P2_Helmet_Base: JLTS_CloneHelmetP2
	{
		author="Ruby";
		displayName="[41st] P2 Trooper Helmet";
		scope=0;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		model="\MRC\JLTS\characters\CloneArmor\CloneHelmetP2.p3d";
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_Helmet_P2.rvmat";
		};
		hiddenselections[]=
		{
			"camo1",
		};
		hiddenSelectionsTextures[]=
		{
		};
		class Iteminfo: HeadgearItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneHelmetP2.p3d";
			mass=15;
			hiddenselections[]=
			{
				"camo1",
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};

    class FST_P2_Helmet_Baron: FST_P2_Helmet_Base
    {
        author = "Ruby";
        displayname = [41st/RSOG] P2 Trooper Helmet (Baron);
        scope = 2;
        HiddenSelectionsTextures[]=
        {
            "FST_RSOG_Armor\Data\Helmets\RSOG_P2_Baron.paa"
        };
    };
    class FST_P2_Helmet_Apathy: FST_P2_Helmet_Base
    {
        author = "Ruby";
        displayname = [41st/RSOG] P2 Trooper Helmet (Apathy);
        scope = 2;
        HiddenSelectionsTextures[]=
        {
            "FST_RSOG_Armor\Data\Helmets\RSOG_MC_Apathy.paa"
        };
    }
    class FST_P2_Helmet_Bendable: FST_P2_Helmet_Base
    {
        author = "Ruby";
        displayname = [41st/RSOG] P2 Trooper Helmet (Bendable);
        scope = 2;
         HiddenSelectionsTextures[]=
        {
            "FST_RSOG_Armor\Data\Helmets\RSOG_P2_Bendable.paa"
        };
    };
    class FST_P2_Helmet_Freezy: FST_P2_Helmet_Base
    {
        author = "Ruby";
        displayname = [41st/RSOG] P2 Trooper Helmet (Freezy);
        scope = 2;
         HiddenSelectionsTextures[]=
        {
            "FST_RSOG_Armor\Data\Helmets\RSOG_P2_Freezy.paa"
        };
    };
    class FST_P2_Helmet_Phoenixx: FST_P2_Helmet_Base
    {
        author = "Ruby";
        displayname = [41st/RSOG] P2 Trooper Helmet (Phoenix);
        scope = 2;
         HiddenSelectionsTextures[]=
        {
            "FST_RSOG_Armor\Data\Helmets\RSOG_P2_Phoenix.paa"
        };
    };
};