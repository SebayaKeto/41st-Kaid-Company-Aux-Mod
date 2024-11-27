class CfgPatches
{
	class FST_Weapons_Shield
	{
		requiredAddons[]=
		{
			"3AS_Weapons"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_DC15S_Shield",
			"FST_DP23_Shield"
		};
	};
};
class CfgWeapons
{
    class FST_DC15S;
    class FST_DP23;
    class WeaponSlotsInfo;
    class UnderBarrelSlot;
    class FST_DC15S_Shield: FST_DC15S
    {
        baseWeapon="FST_DC15S_Shield";
        scope=2;
        displayName="[41st] DC-15S carbine (Shield)";
        JLTS_isShielded=1;
        JLTS_baseWeapon="FST_DC15S";
        model="\MRC\JLTS\weapons\DC15S\DC15S_shielded.p3d";
        hiddenSelections[]=
        {
            "camo1",
            "camo2"
        };
        hiddenSelectionsTextures[]=
        {
            "\MRC\JLTS\weapons\DC15S\data\DC15S_co.paa",
            "\MRC\JLTS\weapons\Shield\data\shield_co.paa"
        };
        handAnim[]=
        {
            "OFP2_ManSkeleton",
            "\MRC\JLTS\weapons\DC15S\anims\DC15S_shielded_handanim.rtm"
        };
        reloadAction="GestureReload";
        inertia=0.80000001;
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=110;
            class UnderBarrelSlot: UnderBarrelSlot
            {
                compatibleItems[]=
                {
                    "JLTS_riot_shield_attachment",
                    "JLTS_riot_shield_212_attachment",
                    "JLTS_riot_shield_501_attachment",
                    "JLTS_riot_shield_101_attachment",
                    "JLTS_riot_shield_CG_attachment",
                    "JLTS_riot_shield_GD_attachment",
                    "JLTS_riot_shield_droid_attachment"
                };
            };
        };
    };
    class FST_DP23_Shield: FST_DP23
    {
		displayName="[41st] DP-23 Scatterblaster (Shield)";
        baseWeapon="FST_DP23_Shield";
        scope=2;
        JLTS_isShielded=1;
        JLTS_baseWeapon="FST_DP23";
        model="\MRC\JLTS\weapons\DP23\DP23_shielded.p3d";
        hiddenSelections[]=
        {
            "camo1",
            "camo2"
        };
        hiddenSelectionsTextures[]=
        {
            "\MRC\JLTS\weapons\DP23\data\DP23_co.paa",
            "\MRC\JLTS\weapons\Shield\data\shield_co.paa"
        };
        handAnim[]=
        {
            "OFP2_ManSkeleton",
            "\MRC\JLTS\weapons\DP23\anims\DP23_shielded_handanim.rtm"
        };
        inertia=0.80000001;
        recoil="recoil_pdw";
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=110;
            class UnderBarrelSlot: UnderBarrelSlot
            {
                compatibleItems[]=
                {
                    "JLTS_riot_shield_attachment",
                    "JLTS_riot_shield_212_attachment",
                    "JLTS_riot_shield_501_attachment",
                    "JLTS_riot_shield_101_attachment",
                    "JLTS_riot_shield_CG_attachment",
                    "JLTS_riot_shield_GD_attachment",
                    "JLTS_riot_shield_droid_attachment"
                };
            };
        };
    };
};
